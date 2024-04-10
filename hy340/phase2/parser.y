%{
    #include<iostream>
    #include <cstdio>
    #include<string>
    int yyerror (char* yaccProvidedMessage);
    int yylex(void);

    extern int yylineno;
	extern char * yyval;
	extern char * yytext;
	extern FILE * yyin;
	extern FILE * yyout;
%}

%start program

%union {
    int intValue;
    char* stringValue;
    double realValue;
}

%token STRING
%token INTEGER
%token REAL
%token LOCAL
%token NIL
%token ID
%token BLOCK_COMMENT 
%token LINE_COMMENT
%token ESCAPE_CHARACTERS
%token SPACE
%token IF 
%token ELSE 
%token WHILE 
%token FOR
%token FUNCTION 
%token RETURN
%token BREAK 
%token CONTINUE
%token AND NOT OR
%token TRUE FALSE
%token EQUAL 
%token MINUS 
%token EQUALEQUAL 
%token DIFFER 
%token BIGGER 
%token LESS 
%token BIGGER_EQ 
%token LESS_EQ
%token MINUSMINUS 
%token PLUSPLUS
%token MOD MULTIPLY 
%token DIV PLUS 
%token CURLY_START_BRACKET 
%token CURLY_END_BRACKET 
%token START_BRACKET 
%token END_BRACKET
%token START_PARENTHESIS 
%token END_PARENTHESIS
%token SEMICOLON 
%token COMMA 
%token COLON DOUBLE_COLON
%token DOT 
%token DOUBLE_DOT
%token EOF 
%token UNDEFINED

%left       START_PARENTHESIS END_PARENTHESIS
%left       START_BRACKET END_BRACKET
%left       DOT DOUBLE_DOT
%right      NOT PLUSPLUS MINUSMINUS UMINUS
%left       MULTIPLY DIV MOD
%left       PLUS MINUS
%nonassoc   BIGGER BIGGER_EQ LESS LESS_EQ
%nonassoc   DIFFER EQUALEQUAL
%left       AND
%left       OR
%right      EQUAL
%nonassoc   IF
%nonassoc   ELSE

%%

program:    stmt program
	    |
            ;

stmt:       expr SEMICOLON
            |ifstmt
            |whilestmt
            |forstmt
            |returnstmt
            |BREAK SEMICOLON
            |CONTINUE SEMICOLON
            |block
            |funcdef
            |SEMICOLON
            ;

expr:       assignexpr
            |expr PLUS expr
            |expr MINUS expr
            |expr MULTIPLY expr
            |expr DIV expr
            |expr MOD expr
            |expr BIGGER expr
            |expr BIGGER_EQ expr
            |expr LESS expr
            |expr LESS_EQ expr
            |expr EQUAL expr
            |expr DIFFER expr
            |expr AND expr
            |expr OR expr
            |term
            ;

term:       START_PARENTHESIS expr END_PARENTHESIS
            |primary
            |MINUS expr %prec UMINUS
            |PLUSPLUS lvalue
            |lvalue PLUSPLUS
            |MINUSMINUS lvalue
            |lvalue MINUSMINUS
            |NOT expr
            ;


primary:    lvalue
            |call
            |objectdef
            |START_PARENTHESIS funcdef END_PARENTHESIS
            |const
            ;

lvalue:     ID
		    |LOCAL ID
		    |DOUBLE_COLON ID
		    |member
		;

assignexpr:  lvalue EQUALEQUAL expr;

member:     lvalue DOT ID
            |lvalue START_BRACKET expr END_BRACKET
            |call DOT ID
            |call START_BRACKET expr END_BRACKET
            ;

call:       call START_PARENTHESIS elist END_PARENTHESIS
            |lvalue callsuffix
            |START_PARENTHESIS funcdef END_PARENTHESIS START_PARENTHESIS elist END_PARENTHESIS
            ;

callsuffix: normcall
            |methodcall
            ;

normcall:   START_PARENTHESIS elist END_PARENTHESIS
            ;

methodcall: DOUBLE_DOT ID START_PARENTHESIS elist END_PARENTHESIS
            ;

elist:      expr commaexpr
            |
            ;

commaexpr:  COMMA expr commaexpr
            |
            ;

objectdef:  START_BRACKET elist END_BRACKET
            |START_BRACKET indexed END_BRACKET
            ;
                

indexed:            indexedelem commaindexedelem;

commaindexedelem:   COMMA indexedelem commaindexedelem
                    |
                    ;
        
indexedelem:        CURLY_START_BRACKET expr COLON expr CURLY_END_BRACKET
                    ;

block:              CURLY_START_BRACKET CURLY_END_BRACKET
                    |CURLY_START_BRACKET stmt program CURLY_END_BRACKET
                    ;


funcdef:            FUNCTION START_PARENTHESIS idlist END_PARENTHESIS block
                    |FUNCTION ID START_PARENTHESIS idlist END_PARENTHESIS block
                    ;

const:              REAL
                    |INTEGER
                    |STRING
                    |NIL
                    |TRUE
                    |FALSE
                    ;

idlist:             ID commaid
                    |
                    ;

commaid:            COMMA ID commaid
                    |
                    ;

ifstmt:             IF START_PARENTHESIS expr END_PARENTHESIS stmt 
                    |IF START_PARENTHESIS expr END_PARENTHESIS stmt ELSE stmt
                    ;

whilestmt:          WHILE START_PARENTHESIS expr END_PARENTHESIS stmt;

forstmt:            FOR START_PARENTHESIS elist SEMICOLON expr SEMICOLON elist END_PARENTHESIS stmt
                    ;

returnstmt:         RETURN expr SEMICOLON
                    | RETURN SEMICOLON
                    ;



%%

int main(){
    return 0;
}

