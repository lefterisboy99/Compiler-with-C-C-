/*definition section*/
%{
    //    MELH OMADAS:
// Andreas Herodotou         csd3698  (csd3698@csd.uoc.gr)
// Mixahl Kontopoulos        csd2788  (kontopoul@csd.uoc.gr)
// Manolis Papadospiridakis  csd3821  (csd3821@csd.uoc.gr)


#include "parser.h"
extern YYSTYPE yylval;

#define INIT_BUF_SIZE       5

unsigned int token_num=0;
%}

%option noyywrap
%option yylineno
    // %option prefix = "alpha"


/*rules section*/
%%
        /*KEYWORDS*/
"if" {
    return IF;
}

"else" {
    return ELSE;
}

"while" {
    return WHILE;
}

"for" {
    return FOR;
}

"function" {
    return FUNCTION;
}

"return" {
    return RETURN;
}

"break" {
    return BREAK;
}

"continue" {
    return CONTINUE;
}

"and" {
    return AND;
}

"not" {
    return NOT;
}

"or" {
    return OR;
}

"local" {
    return LOCAL;
}

"true" {
    return TRUE;
}

"false" {
    return FALSE;
}

"nil" {
    return NIL;
}


    /*Operators*/

"=" {
    return '=';
}

"+" {
    return '+';
}

"-" {
    return '-';
}

"*" {
    return '*';
}

"/" {
    return '/';
}

"%" {
    return '%';
}

"==" {
    return EQ;
}

"!=" {
    return NE;
}

"<" {
    return LT;
}

">" {
    return GT;
}

">=" {
    return GE;
}

"<=" {
    return LE;
}

"++" {
    return PLUSPLUS;
}

"--" {
    return MINUSMINUS;
}

    /*PUNCTUATIONS*/

"{" {
    return '{';
}

"}" {
    return '}';
}

"[" {
    return '[';
}

"]" {
    return ']';
}

"(" {
    return '(';
}

")" {
    return ')';
}

";" {
    return ';';
}

"," {
    return ',';
}

":" {
    return ':';
}

"::" {
    return COLONCOLON;
}

"." {
    return '.';
}

".." {
    return DOTDOT;
}


[ \n\t\r] {}

    /*IDs*/
[a-zA-Z][a-zA-Z_0-9]* {

    yylval.strVal = (char *)malloc( (strlen(yytext) + 1)*sizeof(char) );
    strcpy( yylval.strVal , yytext );
    return ID;
}

    /*INTEGERS*/
[0-9]* {
    yylval.realVal = atof(yytext);
    return INTEGER;
}

    /*REALs*/
[0-9]+\.[0-9]* {
    yylval.realVal = atof(yytext);
    return REAL;
}

    /*STRINGS*/
"\"" {
    char *buffer = (char *)malloc( (INIT_BUF_SIZE) *sizeof(char) );
    char c;
    int i=0 , flag=0 , start=yylineno , realloc_times = 1;

    while ((c = yyinput()) != EOF) 
    {
        if(c == '\\')
        {
            c = yyinput();
            switch( c )
            {
                case 'a' : c='\a'; break;
                case 'b' : c='\b'; break;
                case 'e' : c='\e'; break;
                case 'f' : c='\f'; break;
                case 'n' : c='\n'; break;
                case 'r' : c='\r'; break;
                case 't' : c='\t'; break;
                case 'v' : c='\v'; break;
                case '\\': c='\\'; break;
                case '\'': c='\''; break;
                case '\"': c='\"'; break;
                case '?' : c='\?'; break;
                default: 
                    fprintf( stderr , "Warning: String in line: %d containe illegal character %c\n" , yylineno , c );
                    // unput(c);
                    buffer[i++] = '\\';

                break; 
            }        
        } 
        else if(c=='"')
        {
            flag=1;   
            break;
        }
        
        if( i % INIT_BUF_SIZE == 0 )
        {
            realloc_times++;
            buffer = (char *)realloc( buffer  ,(INIT_BUF_SIZE*realloc_times)*sizeof(char) );
        }
           
        buffer[i++]=c;
    }//end of while

    if(!flag)
    {
        fprintf( stderr , "Line:%d: Error: Non terminating string \n",start);
        return 0;
    }
    buffer[i++]='\0';
    

    yylval.strVal = (char *)malloc( (strlen(buffer) + 1)*sizeof(char) ); 
    strcpy( yylval.strVal  , buffer );

    free(buffer);
    return STRING;
}

    /*SINGLE LINE COMMENTS*/
"//".* {
    //return SINGLE_LINE_COMMENT;
}

    /*MULTI LINE COMMENTS*/
"/*" {
    char c;
    int nested=0;
    char buffer[50]; 
    int start=yylineno;
    int finish=0;
    int inceptions[100];            //represent where nested-i comment start
    int number_non_closed_nested = 0;       //count the nested comment , where start and does not close   

    
    while ((c = yyinput()) != EOF) 
    {
        if (c == '/') {
            if ((c = yyinput()) == '*'){
                inceptions[++nested] = yylineno;
                number_non_closed_nested++;
            }
            else{
                unput(c);
            }
            continue;
        }
        else if(c == '*')
        {
             if ((c = yyinput()) == '/'){
                nested--;
                if(nested==-1)
                    break;
                else{
                    finish=yylineno;
                    sprintf(buffer,"%d-%d", inceptions[nested+1] ,finish);
                    number_non_closed_nested--;
                }
            }
            else
                unput(c);
        }
    }
    int print_all = 0;
    if(nested != -1)
    {
        fprintf( stderr , "Line:%d: Error: Non terminating comment\n",start);
        print_all = 1;
         
    }

    /*insert into list non-nested closed comments*/
    while(number_non_closed_nested > 0)
    {
        fprintf( stderr , "Line:%d: Error: Non terminating comment\n",inceptions[number_non_closed_nested]);  
        // finish=yylineno;
        // sprintf(buffer,"%d-%d", inceptions[number_non_closed_nested] ,finish);
        // insert_node( inceptions[number_non_closed_nested] , ++token_num ,buffer, COMMENT ,"NESTED_COMMENT",ENUMERATED);
        number_non_closed_nested--;
    }
    if(print_all)
        return 0;
    
    finish=yylineno;
    sprintf(buffer,"%d-%d",start,finish);
    // return NESTED_COMMENT;
}

<<EOF>>     return -1;


. {    
    fprintf( stderr , "Undefined input \"%s\" in line: %d \n", yytext , yylineno );
}

%%

