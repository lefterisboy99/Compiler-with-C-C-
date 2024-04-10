%{
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include "parser.h"
/*   #define YY_DECL int alpha_yylex (void* yylval) */
  int token=0;
  int line=0;

/* output struct */
struct alpha_token_t{
         int lineno;
		 int tokenno;
		 char* type;
		 char* value;
         struct alpha_token_t *next;
};
struct alpha_token_t *head=NULL;

/* print of output*/
void PrintTokens(struct alpha_token_t *head)
{
     struct alpha_token_t *tmp=head;
     while (tmp != NULL)
     {
      
	    if(!strcmp(tmp->value," ")){
	      printf("%3d: #%3d \t\t\t\t %s\n",tmp->lineno,tmp->tokenno,tmp->type);
	    }
	    else{
		printf("%3d: #%3d [\"%s\"] \t\t %s\n",tmp->lineno,tmp->tokenno,tmp->value,tmp->type);
	    }
	   tmp = tmp->next;
     }
     printf("\n");
}
    

/* insert of token in struct */
struct alpha_token_t *AddToken(struct alpha_token_t *head, int line, int tokenno,char* type,char* value)
{
     struct alpha_token_t *tmp=head, *newnode;
	 newnode = (struct alpha_token_t *) malloc ( sizeof(struct alpha_token_t) );
	 newnode->lineno=line;
	 newnode->tokenno=tokenno;
	 newnode->type=strdup(type);
	 newnode->value=strdup(value);
	 newnode->next=NULL;
	 if(tmp==NULL){
		return newnode;
	 }
	 while (tmp->next != NULL)
     {
           tmp = tmp->next;
     }
	 tmp->next=newnode;
	 return head;
}



%}

/*Dhlwsh twn token*/

/*Desmeumenes lexeis*/
IF 		"if"
ELSE		"else"
WHILE 		"while"
FOR		"for"
FUNCTION	"function"
RETURN 		"return"
BREAK		"break"
CONTINUE	"continue"
LOCAL		"local"
TRUE		"true"	
FALSE		"false"
NIL		"nil"


/*Telestes*/

ASSIGN		"="
PLUS		"+"
MINUS		"-"
MULTI		"*"
DIV		"/"
MOD		"%"
EQUAL		"=="
NEQUAL		"!="
PPLUS		"++"
MMINUS		"--"
GREATER		">"
LESS		"<"
GREATER_EQUAL	">="
LESS_EQUAL	"<="
NOT		"not"
AND		"and"
OR		"or"

/*Ari8mhtikes sta8eres */

NUMBER		[0-9]+
REALNUM		[0-9]+"."[0-9]+

/*String*/
STRING		\"

/*Shmeia Sti3hs*/
LEFT_CBRACKET	\{
RIGHT_CBRACKET	\}
LEFT_SBRACKET	\[
RIGHT_SBRACKET	\]
LEFT_PARENTHES	\(
RIGHT_PARENTHES	\)
SEMICOLON	\;
COMMA		\,
COLON		\:
DCOLON		\:\:
DOT		\.
DOTS		\.\.

/*Identifier*/
ID		[a-zA-Z][a-zA-Z_0-9]*

/*Comments*/

COMMENT		"//".*
COMMENT2	"/*"
END_COMMENT2	"*/"

/*Others*/

WHITE_SPACES  [\r \t\v]
NEW_LINE	"\n"
OTHER		.


%option noyywrap
%option yylineno
%%

{IF} 			{head=AddToken(head, yylineno,++token,"KEYWORD","if");	return IF;}
				
{ELSE}			{head=AddToken(head, yylineno,++token,"KEYWORD","else");return ELSE;}

{WHILE}			{head=AddToken(head, yylineno,++token,"KEYWORD","while");return WHILE;}

{FOR}			{head=AddToken(head, yylineno,++token,"KEYWORD","for");return FOR;}

{FUNCTION}		{head=AddToken(head, yylineno,++token,"KEYWORD","function");return FUNCTION;}

{RETURN}		{head=AddToken(head, yylineno,++token,"KEYWORD","return");return RETURN;}

{BREAK}			{head=AddToken(head, yylineno,++token,"KEYWORD","break");return BREAK;}

{CONTINUE}		{head=AddToken(head, yylineno,++token,"KEYWORD","continue");return CONTINUE;}

{LOCAL}			{head=AddToken(head, yylineno,++token,"KEYWORD","local");return LOCAL;}

{TRUE}			{head=AddToken(head, yylineno,++token,"KEYWORD","true");return TRUE;}

{FALSE}			{head=AddToken(head, yylineno,++token,"KEYWORD","false");return FALSE;}

{NIL}			{head=AddToken(head, yylineno,++token,"KEYWORD","nil");return NIL;}



{ASSIGN}		{head=AddToken(head, yylineno,++token,"OPERANT","=");	return ASSIGN;}

{PLUS}			{head=AddToken(head, yylineno,++token,"OPERANT","+");	return PLUS;}

{MINUS}			{head=AddToken(head, yylineno,++token,"OPERANT","-");	return MINUS;}

{MULTI}			{head=AddToken(head, yylineno,++token,"OPERANT","*"); return MULTI;}

{DIV}			{head=AddToken(head, yylineno,++token,"OPERANT","/");	return DIV;}

{MOD}			{head=AddToken(head, yylineno,++token,"OPERANT","%");	return MOD;}

{EQUAL}			{head=AddToken(head, yylineno,++token,"OPERANT","==");	return EQUAL;}

{NEQUAL}		{head=AddToken(head, yylineno,++token,"OPERANT","!=");return NEQUAL;}

{PPLUS}			{head=AddToken(head, yylineno,++token,"OPERANT","++"); return PPLUS;}

{MMINUS}		{head=AddToken(head, yylineno,++token,"OPERANT","--"); return MMINUS;}

{GREATER}		{head=AddToken(head, yylineno,++token,"OPERANT",">"); return GREATER;}

{LESS}			{head=AddToken(head, yylineno,++token,"OPERANT","<"); return LESS;}

{GREATER_EQUAL}		{head=AddToken(head, yylineno,++token,"OPERANT",">="); return GREATER_EQUAL;}

{LESS_EQUAL}		{head=AddToken(head, yylineno,++token,"OPERANT","<="); return LESS_EQUAL;}

{NOT}			{head=AddToken(head, yylineno,++token,"OPERANT","!");return NOT;}

{AND}			{head=AddToken(head, yylineno,++token,"OPERANT","&&");return AND;}

{OR}			{head=AddToken(head, yylineno,++token,"OPERANT","||");return OR;}


{NUMBER} 		{
			 head=AddToken(head, yylineno,++token,"INTCONST",yytext); 
			 yylval.intVal = atoi(yytext); 
			 return NUMBER;
			}

{REALNUM}		{
			 head=AddToken(head, yylineno,++token,"FLOATCONST",yytext); 
			 yylval.dbVal= atof(yytext);
			 return REALNUM;
			}

{ID}			{
			 head=AddToken(head, yylineno,++token,"IDENTIFIER",yytext);
			 yylval.strVal =strdup(yytext);
			 return ID;
			}

{STRING} {    
	  char c;
	  int i = 0;
	  int error_flag = 1;
	  char *str=(char *)malloc(sizeof(char));
	  *(str + i++) = '"';
	  //str=(char *)realloc(str, ((++i)+1)*sizeof(char));/*realloc gia ton epomeno xarakthra*/
      while((c=input())!=EOF)
	  {			

	  	while (c == '\\'){/*auth h while voleuei gia ta sunexomena slash
	      			    vlepei pote uparxei slash kai analoga vazei sto string
					ton katallhlo escape character h' petaei warning */

			c = input();

	      	if ( c == 'n'){
				
                    *(str+i) = '\n';
			}
			else if ( c == 't' ){
				
					c = '\t';
					*(str+i) = c; 
			}
            else if ( c == '\\' ){
                                
					*(str+i)='\\';
            }
            else if ( c == '\"' ){
                                
					*(str+i)='"';
            }
			else{
				/*otan vrei kati pou den to anagnwrizei dinei keno xarakthra sto string*/
	                        *(str+i)=' ';
				//printf("WARNING, Unknown character found! a space character was added.\n");
			}
			 str=(char *)realloc(str, ((++i)+1)*sizeof(char));/*realloc gia ton epomeno xarakthra*/
			c = input();
			
	      	}

		if (c == '\"'){			/*an den dei autakia xwris na dei slash to string eftase sto telos tou*/
			error_flag = 0;				/*mhdemismos ths error flag gia na mhn petaksei la8os*/
			
			*(str+i++)='\"';
			
			
			head=AddToken(head, yylineno,++token,"STRING", str);	/*eisagwgh sth lista*/
			yylval.strVal = strdup(str);
			
			return STRING;
		}
		else 	/*alliws sunexizri na vazei xarakthres*/
		{		  
			*(str+i)=c;	
			str=(char *)realloc(str, ((++i)+1)*sizeof(char));
			*(str + i ) = '\0';
		}
          }

	  if(error_flag){	/*an h error flag den mhdenistei pote tote exoume ftasei sto EOF
				  xwris na kleisei to string opote exoume error			*/
	  	head=AddToken(head,yylineno,++token,"STRING","Wrong Form");
		error_flag = 1;		//for next string probably not needed
	  }
}

{LEFT_CBRACKET}		{head=AddToken(head, yylineno,++token,"PUNCTUATION_MARK","{"); return LEFT_CBRACKET;}

{RIGHT_CBRACKET}	{head=AddToken(head, yylineno,++token,"PUNCTUATION_MARK","}");return RIGHT_CBRACKET;} 

{LEFT_SBRACKET}		{head=AddToken(head, yylineno,++token,"PUNCTUATION_MARK","[");return LEFT_SBRACKET;}

{RIGHT_SBRACKET}	{head=AddToken(head, yylineno,++token,"PUNCTUATION_MARK","]");return RIGHT_SBRACKET;}

{LEFT_PARENTHES}	{head=AddToken(head, yylineno,++token,"PUNCTUATION_MARK","(");return LEFT_PARENTHES;}

{RIGHT_PARENTHES}	{head=AddToken(head, yylineno,++token,"PUNCTUATION_MARK",")");return RIGHT_PARENTHES;}

{SEMICOLON}             {head=AddToken(head, yylineno,++token,"PUNCTUATION_MARK",";");return SEMICOLON;}

{COMMA}			{head=AddToken(head, yylineno,++token,"PUNCTUATION_MARK",",");return COMMA;}

{COLON}			{head=AddToken(head, yylineno,++token,"PUNCTUATION_MARK",":");return COLON;}

{DCOLON}		{head=AddToken(head, yylineno,++token,"PUNCTUATION_MARK","::");return DCOLON;}

{DOT}			{head=AddToken(head, yylineno,++token,"PUNCTUATION_MARK",".");return DOT;}

{DOTS}			{head=AddToken(head, yylineno,++token,"PUNCTUATION_MARK","..");return DOTS;}



{COMMENT}		{head=AddToken(head, yylineno,++token,"COMMENT","//");}

{COMMENT2}		{
					char token;
					int commentno=1;/*counter twn comment*/
					while((token=input())!=EOF){
						if(commentno==0){/*otan o counter ginei mhden
								exoume iso ari8mo sxoliwn pou 
								anoigoun me osa kleinoun */
							break;
						}
						if(token=='/'){
							token=input();
							if(token=='*'){/*au3anoume ton counter*/
								commentno++;
							}
							else{/*ftiaxnoume to teleutaio char*/
								unput(token);
							}
						}
						else if(token=='*'){
							token=input();
							if(token=='/'){/*meiwnoume ton counter*/
								commentno--;
							}
							else{/*ftiaxnoume to teleutaio char*/
								unput(token);
							}
						}						
					}
					if(commentno!=0){/*an sto EOF o counter den einai mhden exoume error*/
						head=AddToken(head,yylineno,++token,"COMMENTS","Fail Form");
					}
					else{
						head=AddToken(head,yylineno,++token,"COMMENTS","Right Form");
					}
				}

{WHITE_SPACES}		{head=AddToken(head, yylineno,++token,"WHITE_SPACES"," "); }

{NEW_LINE}		{line++;}

{OTHER}			{head=AddToken(head, yylineno,++token,"OTHER","Non-Supported Type");return OTHER;}


  
%%
/*int main(int argc, char *argv[])
{
  	FILE *fp;
	if(argc==1){
    		printf("Give an input from keyboard .. \n");
	    	yyin=stdin;
   		// yyout=stdout;
  	}
  	else if (argc!=2){
   		printf("Wrong parameters! \n");
    		exit(1);
  	}
  	else{	
    		if(!(fp=fopen(argv[1],"r")))
    		{
      			printf("Cannot open source file !\n");
      			exit(1);
    		}
    	yyin=fp;
	}

	
	//PrintTokens(head);

}*/
