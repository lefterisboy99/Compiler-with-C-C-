%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <list>
#include <assert.h>

#include "parser.hpp"

using std::vector;
using std::list;

//#define YY_DECL   int yylex(void)
#define PRINT     printf("%d: ", yylineno); \
                  printf("#%d   ", ++numToken); \
                  printf("\"%s\"   ", yytext)

int numToken = 0;
char*c;
struct alpha_token_t
{
      unsigned int            numline;
      unsigned int            numToken;
      const char*             content;
      const char*             type;
};

vector<alpha_token_t> ALPHA_TOKEN_LIST;

void add_token(int line_num, int token_num, const char *content, const char *type) {
      alpha_token_t token;
      token.numline = line_num;
      token.numToken = token_num;
      token.content = strdup(content);
      token.type = strdup(type);
      ALPHA_TOKEN_LIST.push_back(token);
}

%} 

%option noyywrap
%option yylineno
%option outfile = "al.cpp"

STRING                  \"
ID                      [a-zA-Z][a-zA-Z_0-9]*
BLOCK_COMMENT           \/\*
INTEGER                 [0-9]+
ESCAPE_CHARACTERS       [\n\t ]
REAL                    [0-9]+\.[0-9]+
SPACE                   [\r\n \t\v]
IF                      if
ELSE                    else
WHILE                   while
FOR                     for
FUNCTION                function
RETURN                  return
BREAK                   break
CONTINUE                continue
AND                     and
NOT                     not
OR                      or
LOCAL                   local
TRUE                    true
FALSE                   false
NIL                     nil
ASSIGN                   =
MINUS                    -
EQUAL                   ==
DIFFER                  !=
BIGGER                  >
LESS                    <
BIGGER_EQ               >=
LESS_EQ                 <=
MINUSMINUS              --
MOD                     %
MULTIPLY                \*
DIV                     \/
PLUS                    \+
PLUSPLUS                \+\+
CURLY_START_BRACKET     \{
CURLY_END_BRACKET       \}
START_BRACKET           \[
END_BRACKET             \]
START_PARENTHESIS       \(
END_PARENTHESIS         \)
SEMICOLON               ;
COMMA                   \,
COLON                   :
DOUBLE_COLON            ::
DOT                     \.
DOUBLE_DOT              \.\.
LINE_COMMENT            \/\/.*

EOF                     <<EOF>>
UNDEFINED               .


%%

{ESCAPE_CHARACTERS} {}
{SPACE} {}

{CURLY_START_BRACKET} {         
                  // PRINT;printf("PUNCTUATION   CURLY_START_BRACKET   <-enumerated\n");
                  // add_token(yylineno, numToken, "CURLY_START_BRACKET", "PUNCTUATION");
                  return CURLY_START_BRACKET;
                  }
{CURLY_END_BRACKET} {         
                  // PRINT;printf("PUNCTUATION   CURLY_END_BRACKET   <-enumerated\n");
                  // add_token(yylineno, numToken, "CURLY_END_BRACKET", "PUNCTUATION");
                  return CURLY_END_BRACKET;
                  }
{START_BRACKET} {         
                  // PRINT;printf("PUNCTUATION   START_BRACKET   <-enumerated\n");
                  // add_token(yylineno, numToken, "START_BRACKET", "PUNCTUATION");
                  return START_BRACKET;
                  }
{END_BRACKET} {         
                  // PRINT;printf("PUNCTUATION   END_BRACKET   <-enumerated\n");
                  // add_token(yylineno, numToken, "END_BRACKET", "PUNCTUATION");
                  return END_BRACKET;
                  }
{START_PARENTHESIS} {         
                  // PRINT;printf("PUNCTUATION   START_PARENTHESIS   <-enumerated\n");
                  // add_token(yylineno, numToken, "START_PARENTHESIS", "PUNCTUATION");
                  return START_PARENTHESIS;
                  }
{END_PARENTHESIS} {         
                  // PRINT;printf("PUNCTUATION   END_PARENTHESIS   <-enumerated\n");
                  // add_token(yylineno, numToken, "END_PARENTHESIS", "PUNCTUATION");
                  return END_PARENTHESIS;
                  }

{SEMICOLON} {     
      // PRINT;printf("PUNCTUATION   SEMICOLON   <-enumerated\n");
      // add_token(yylineno, numToken, "SEMICOLON", "PUNCTUATION");
      return SEMICOLON;
      }

{COMMA} {         
      // PRINT;printf("PUNCTUATION   COMMA   <-enumerated\n");
      // add_token(yylineno, numToken, "COMMA", "PUNCTUATION");
      return COMMA;
      }

{COLON} {         
      // PRINT;printf("PUNCTUATION   COLON   <-enumerated\n");
      // add_token(yylineno, numToken, "COLON", "PUNCTUATION");
      return COLON;
      }

{DOUBLE_COLON} {  
      // PRINT;printf("PUNCTUATION   DOUBLE_COLON   <-enumerated\n");
      // add_token(yylineno, numToken, "DOUBLE_COLON", "PUNCTUATION");
      return DOUBLE_COLON;
      }

{DOT} {           
      // PRINT;printf("PUNCTUATION   DOT   <-enumerated\n");
      // add_token(yylineno, numToken, "DOT", "PUNCTUATION");
      return DOT;
      }

{DOUBLE_DOT} {    
      // PRINT;printf("PUNCTUATION   DOUBLE_DOT   <-enumerated\n");
      // add_token(yylineno, numToken, "DOUBLE_DOT", "PUNCTUATION");
      return DOUBLE_DOT;
      }

{WHILE} {         
      // PRINT;printf("KEYWORD   WHILE   <-enumerated\n");
      // add_token(yylineno, numToken, "WHILE", "KEYWORD");
      return WHILE;
      }

{ELSE} {          
      // PRINT;printf("KEYWORD   ELSE   <-enumerated\n");
      // add_token(yylineno, numToken, "ELSE", "KEYWORD");
      return ELSE;
      }

{IF} {            
      // PRINT;printf("KEYWORD   IF   <-enumerated\n");
      // add_token(yylineno, numToken, "IF", "KEYWORD");
      return IF;
      }

{FOR} {           
      // PRINT;printf("KEYWORD   FOR   <-enumerated\n");
      // add_token(yylineno, numToken, "FOR", "KEYWORD");
      return FOR;
      }

{FUNCTION} {      
      // PRINT;printf("KEYWORD   FUNCTION   <-enumerated\n");
      // add_token(yylineno, numToken, "FUNCTION", "KEYWORD");
      return FUNCTION;
      }

{RETURN} {        
      // PRINT;printf("KEYWORD   RETURN   <-enumerated\n");
      // add_token(yylineno, numToken, "RETURN", "KEYWORD");
      return RETURN;
      }

{BREAK} {         
      // PRINT;printf("KEYWORD   BREAK   <-enumerated\n");
      // add_token(yylineno, numToken, "BREAK", "KEYWORD");
      return BREAK;
      }

{CONTINUE} {      
            // PRINT;printf("KEYWORD   CONTINUE   <-enumerated\n");
            // add_token(yylineno, numToken, "CONTINUE", "KEYWORD");
            return CONTINUE;
            }

{AND} {           
      // PRINT;printf("KEYWORD   AND   <-enumerated\n");
      // add_token(yylineno, numToken, "AND", "KEYWORD");
      return AND;
      }

{NOT} {           
      //PRINT;printf("KEYWORD   NOT   <-enumerated\n");
      //add_token(yylineno, numToken, "NOT", "KEYWORD");
      return NOT;
      }

{OR} {            
      // PRINT;printf("KEYWORD   OR   <-enumerated\n");
      // add_token(yylineno, numToken, "OR", "KEYWORD");
      return OR;
      }

{LOCAL} {         
      // PRINT;printf("KEYWORD   LOCAL   <-enumerated\n");
      // add_token(yylineno, numToken, "LOCAL", "KEYWORD");
      return LOCAL;
      }

{FALSE} {         
      // PRINT;printf("KEYWORD   FALSE   <-enumerated\n");
      // add_token(yylineno, numToken, "FALSE", "KEYWORD");
      return FALSE;
      }

{TRUE} {          
      // PRINT;printf("KEYWORD   TRUE   <-enumerated\n");
      // add_token(yylineno, numToken, "TRUE", "KEYWORD");
      return TRUE;
      }

{NIL} {           
      // PRINT;printf("KEYWORD   NIL   <-enumerated\n");
      // add_token(yylineno, numToken, "NIL", "KEYWORD");
      return NIL;
      }

{INTEGER} {       
      // PRINT;printf("INTEGER   %s   <-int\n", yytext);
      // add_token(yylineno, numToken, yytext, "INTEGER");
      yylval.intValue = atoi(yytext);
      return INTEGER;
      }

{REAL} {          
      // PRINT;printf("REAL      %s   <-real\n", yytext);
      // add_token(yylineno, numToken, yytext, "REAL");
      yylval.realValue = atof(yytext);
      return REAL;
      }

{ASSIGN} {         
      // PRINT;printf("OPERATOR   EQUAL   <-enumerated\n");
      // add_token(yylineno, numToken, "EQUAL", "OPERATOR");
      return ASSIGN;
      }

{MINUS} {         
      // PRINT;printf("OPERATOR   MINUS   <-enumerated\n");
      // add_token(yylineno, numToken, "MINUS", "OPERATOR");
      return MINUS;
      }

{MINUSMINUS} {    
      // PRINT;printf("OPERATOR   MINUSMINUS   <-enumerated\n");
      // add_token(yylineno, numToken, "MINUSMINUS", "OPERATOR");
      return MINUSMINUS;
      }

{EQUAL} {    
      // PRINT;printf("OPERATOR   EQUALEQUAL   <-enumerated\n");
      // add_token(yylineno, numToken, "EQUALEQUAL", "OPERATOR");
      return EQUAL;
      }

{DIFFER} {        
      // PRINT;printf("OPERATOR   DIFFER   <-enumerated\n");
      // add_token(yylineno, numToken, "DIFFER", "OPERATOR");
      return DIFFER;
      }

{BIGGER} {        
      //PRINT;printf("OPERATOR   BIGGER   <-enumerated\n");
      //add_token(yylineno, numToken, "BIGGER", "OPERATOR");
      return BIGGER;
      }

{LESS} {          
      // PRINT;printf("OPERATOR   LESS   <-enumerated\n");
      // add_token(yylineno, numToken, "LESS", "OPERATOR");
      return LESS;
      }

{BIGGER_EQ} {     
      // PRINT;printf("OPERATOR   BIGGER_EQ   <-enumerated\n");
      // add_token(yylineno, numToken, "BIGGER_EQ", "OPERATOR");
      return BIGGER_EQ;
      }

{LESS_EQ} {       
      // PRINT;printf("OPERATOR   LESS_EQ   <-enumerated\n");
      // add_token(yylineno, numToken, "LESS_EQ", "OPERATOR");
      return LESS_EQ;
      }

{MOD} {           
      // PRINT;printf("OPERATOR   MOD   <-enumerated\n");
      // add_token(yylineno, numToken, "MOD", "OPERATOR");
      return MOD;
      }

{MULTIPLY} {      
      // PRINT;printf("OPERATOR   MULTIPLY   <-enumerated\n");
      // add_token(yylineno, numToken, "MULTIPLY", "OPERATOR");
      return MULTIPLY;
      }

{DIV} {           
      // PRINT;printf("OPERATOR   DIV   <-enumerated\n");
      // add_token(yylineno, numToken, "DIV", "OPERATOR");
      return DIV;
      }

{PLUS} {          
      // PRINT;printf("OPERATOR   PLUS   <-enumerated\n");
      // add_token(yylineno, numToken, "PLUS", "OPERATOR");
      return PLUS;
      }

{PLUSPLUS} {      
      // PRINT;printf("OPERATOR   PLUSPLUS   <-enumerated\n");
      // add_token(yylineno, numToken, "PLUSPLUS", "OPERATOR");
      return PLUSPLUS;
      }

{STRING} {

      int lineerr = yylineno;
      char*all_str;
      int c;
      vector<char>buf,prototype;
      c=yyinput();
      while(c!='"' && c!=EOF){
            if(c=='\\'){
                  c=yyinput();
                  if(c=='n'){
                              buf.push_back('\n');
                              prototype.push_back('\\');
                              prototype.push_back(c);
                  }else if(c=='t'){
                               buf.push_back('\t');
                               prototype.push_back('\\');
                               prototype.push_back(c);
                  }else if(c=='\\'){
                              buf.push_back('\\');
                              prototype.push_back('\\');
                              prototype.push_back(c);
                  }else if(c=='"'){
                              buf.push_back('\"');
                              prototype.push_back('\\');
                              prototype.push_back(c);
                  }else{
                             printf("ERROR: unknown escape sequence(\\%c) at line %d\n",c,yylineno);
                             exit(-1);
                  }
            }else {
                  buf.push_back(c);
                  prototype.push_back(c);
            }
            c=yyinput();
      }

      if(c!='"')
      {
            fprintf(stderr,
            "ERROR: String in line %d has not been initialized with closing \"\"\n",lineerr);
            return -1;
      }
      
      // int i;
      // printf("%d: ", yylineno);
      // printf("#%d   ", ++numToken);
      // printf("\"");
      // for(i=0; i<prototype.size(); ++i){
      //       printf("%c", prototype.at(i));
      // }
      // printf("\"");
      // printf("   STRING   ");
      // for(i=0; i<buf.size(); ++i){
      //       printf("%c", buf.at(i));
      // }
      // printf("   <-char*\n");
      buf.push_back('\0');
      all_str=&buf[0];
      char*newstr;
      newstr=(char*)malloc(sizeof(char) *(strlen(all_str)+1));
      strcpy (newstr,all_str);
      add_token(yylineno, numToken, newstr, "STRING");
      yylval.stringValue = strdup(newstr);
      return STRING;
}

{ID}  {
      // PRINT; printf("ID   \"%s\"   <-char*\n", yytext);
      // add_token(yylineno, numToken, yytext, "ID");
      yylval.stringValue = strdup(yytext);
      return ID;
      }

{BLOCK_COMMENT} {

      vector<int> s_lines, f_lines;
      s_lines.push_back(yylineno);

      int counter = 1, flag = 1, f_nested_counter = 0, s_nested_counter = 0;
      int lineerr = yylineno;
      int c;
      c=yyinput();
      while( counter != 0 && c!=EOF){   
            
            if(c == '*' ){
                  c=yyinput();
                  if(c=='/') {
                        f_nested_counter = s_nested_counter;
                        if(flag == 0) {
                              while(f_lines.at(f_nested_counter) != 0) {
                                    f_nested_counter--;
                              }
                        }
                        flag = 0;
                        counter--;
                        if(f_nested_counter >= f_lines.size())
                              f_lines.resize(f_nested_counter+1);
                        f_lines.at(f_nested_counter) = yylineno;
                  }
                  else
                        unput(c);
            }
            else if(c == '/'){
                  c=yyinput();
                  if(c=='*'){
                        flag = 1;
                        counter++;
                        s_nested_counter++;
                        s_lines.push_back(yylineno);
                  }else
                        unput(c);             
            }
            
            c=yyinput();
      }

      if(counter)
      {
            fprintf(stderr,
            "ERROR: Comment in line %d has not been closed \n",lineerr);
            return -1;
      }

      // int i;
      // for(i=0; i<s_lines.size(); ++i) {
      //       printf("%d: ", s_lines.at(0));
      //       printf("#%d   ", ++numToken);
      //       printf("\"%d - %d\"   ", s_lines.at(i), f_lines.at(i));
      //       printf("COMMENT   ");
      //       if(i==0)
      //             printf("BLOCK_COMMENT   <-enumerated\n");
      //       else
      //            printf("NESTED_COMMENT   <-enumerated\n");
      // }
}

{LINE_COMMENT} { 
            // printf("%d: ", yylineno);
            // printf("#%d   ", ++numToken);
            // printf("COMMENT   LINE_COMMENT   <-enumerated\n");
            }

{UNDEFINED} { printf("ERROR: Undefined character in line %d\n", yylineno); return -1; }
      
%% 

// int main(int argc,char* argv[]){

//       if(argc>1){
//             if(!(yyin=fopen(argv[1],"r"))){
//                   printf("Cannot open file %s",argv[1]);
//                   return -1;
//             }
//       }else
//             yyin=stdin;
      
//       alpha_yylex(NULL);
      
//       /*
//             int i=0;
//             printf("LIST VALUES BELLOW\n\n");
//             for(i=0;i<ALPHA_TOKEN_LIST.size();i++){
//                   printf("%d %d %s %s\n",ALPHA_TOKEN_LIST.at(i).numline,ALPHA_TOKEN_LIST.at(i).numToken,
//                                     ALPHA_TOKEN_LIST.at(i).content,ALPHA_TOKEN_LIST.at(i).type);
//             }
//       */

//       return 0; 
// } 