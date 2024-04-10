%{     

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YY_DECL int yylex(void* yval)


%} 
  

%option noyywrap
%option yylineno
%option outfile = "al.cpp"


ID                      [a-zA-Z][a-zA-Z_0-9]*
INTEGER                 [0-9]*
REAL                    [0-9]*\.[0-9]+
SPACE                   [\r\n \t\v]
COMMENT1                \/\/.*
COMMENT2                /*
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
EQUAL                   =
MINUS                   -
PLUS                    +
MULTIPLY                *
DIV                     /
MOD                     %
DB_EQUAL                ==
DIFFER                  !=
PLUSPLUS                ++
MINUSMINUS              --
BIGGER                  >
LESS                    <
BIGGER_EQ               >=
LESS_EQ                 <=
CURLY_START_BRACKET     {
CURLY_END_BRACKET       }
START_BRACKET           [
END_BRACKET             ]
START_PARENTHESIS       (
END_PARENTHESIS         )
SEMICOLON               ;
COMMA                   ,
COLON                   :
DOUBLE_COLON            ::
DOT                     .
DOUBLE_DOT              ..
EOF                     <<EOF>>

%%
{ID}        {      printf("id");     }
%% 
  

int main(int argc,char**argv){ 
      if(argc>1){
            if(!(yyin=fopen(argv[1],"r"))){
                  printf("Cannot open file %s",argv[1]);
                  return -1;
                  }
      }else
            yyin=stdin;
      
yylex(NULL); 

return 0; 
} 