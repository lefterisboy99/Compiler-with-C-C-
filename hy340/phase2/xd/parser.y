%{
	#include "Symtable.h"
	
	int yyerror (char* yaccProvidedMessage);
	int yylex (void);
	
	extern int yylineno;
	extern char * yyval;
	extern char * yytext;
	extern FILE * yyin;
	extern FILE * yyout;
	int scope=0, i=0, FunctionFlag = 0, ArrayFlag = 0;
	char dflt_name[3] = "$_ "; //default func name 
	
	SymTable_T *oSymTable;
	SymbolNode *ScopeArray[SCOPE_MAX], *TmpNode;
%}

%start program


%token 	IF
%token	ELSE
%token	WHILE
%token	FOR
%token	FUNCTION
%token	RETURN
%token	BREAK
%token	CONTINUE
%token	LOCAL
%token	TRUE
%token	FALSE
%token 	NIL
%token	NOT
%token	AND 
%token	OR

%token	ASSIGN
%token	PLUS
%token	MINUS
%token	MULTI
%token	DIV 
%token	MOD
%token	EQUAL
%token	NEQUAL
%token	PPLUS
%token	MMINUS
%token	GREATER
%token	LESS
%token	GREATER_EQUAL
%token	LESS_EQUAL

%token  NUMBER
%token  REALNUM
%token  ID 
%token  STRING

%token	LEFT_CBRACKET
%token	RIGHT_CBRACKET
%token	LEFT_SBRACKET
%token	RIGHT_SBRACKET
%token	LEFT_PARENTHES
%token	RIGHT_PARENTHES
%token	SEMICOLON
%token	COMMA
%token	COLON
%token	DCOLON
%token	DOT
%token	DOTS

%token	COMMENT
%token 	COMMENT2

%token	OTHER


%right	ASSIGN

%left	AND OR

%nonassoc	EQUAL NEQUAL

%nonassoc	GREATER GREATER_EQUAL LESS LESS_EQUAL

%left	PLUS MINUS

%left	MULTI DIV MOD

%right	NOT PPLUS MMINUS UMINUS

%left	DOT DOTS

%left	LEFT_SBRANCKET RIGHT_SBRANCKET

%left	LEFT_PARENTHES RIGHT_PARENTHES

%left	LEFT_CBRANCKET RIGHT_CBRANCKET

%nonassoc IF
%nonassoc ELSE

%union
{
	char* strVal;
	int intVal;
	double dbVal;
}

%%

program	:  statements 		{fprintf(yyout," program ==> statements \n");}
		;

statements 	:  stmt statements 	{fprintf(yyout,"statements ==> stmt statements\n");}
			| /*empty*/		{fprintf(yyout,"statements ==> empty \n");}
			;

stmt	: expr SEMICOLON	{fprintf(yyout,"stmt ==> expr; \n");}
		| ifstmt		{fprintf(yyout,"stmt ==> ifstmt \n");}
		| whilestmt		{fprintf(yyout,"stmt ==> whilestmt  \n");}
		| forstmt		{fprintf(yyout,"stmt ==> forstmt \n");}
		| returnstmt		{fprintf(yyout,"stmt ==> returnstmt \n");}
		| BREAK SEMICOLON	{fprintf(yyout,"stmt ==> break; \n");}
		| CONTINUE SEMICOLON	{fprintf(yyout,"stmt ==> continue; \n");}
		| block			{fprintf(yyout,"stmt ==> block \n");}
		| funcdef		{fprintf(yyout,"stmt ==> funcdef \n");}	
		| SEMICOLON		{fprintf(yyout,"stmt ==> ; \n");}
		;

expr 	: assignexpr		{fprintf(yyout,"expr ==> assignexpr  \n");}
		| expr AND expr	{fprintf(yyout,"expr ==>  expr and expr  \n");}
		| expr OR expr	{fprintf(yyout,"expr ==>  expr or expr  \n");}
		| expr PLUS expr	{fprintf(yyout,"expr ==>  expr + expr  \n");}
		| expr MINUS expr	{fprintf(yyout,"expr ==>  expr - expr  \n");}
		| expr MULTI expr	{fprintf(yyout,"expr ==>  expr * expr  \n");}
		| expr DIV expr		{fprintf(yyout,"expr ==>  expr div expr  \n");}
		| expr MOD expr		{fprintf(yyout,"expr ==>  expr mod expr  \n");}
		| expr EQUAL expr	{fprintf(yyout,"expr ==>  expr == expr  \n");}
		| expr NEQUAL expr	{fprintf(yyout,"expr ==>  expr != expr  \n");}
		| expr GREATER expr	{fprintf(yyout,"expr ==>  expr > expr  \n");}
		| expr LESS expr	{fprintf(yyout,"expr ==>  expr < expr \n");}
		| expr GREATER_EQUAL expr 	{fprintf(yyout,"expr ==> expr >= expr  \n");}
		| expr LESS_EQUAL expr		{fprintf(yyout,"expr ==> expr <= expr  \n");}
		| term				{fprintf(yyout,"expr ==> term  \n");}
		;

assignexpr	: lvalue{
				printf("%s is here",yylval.strVal);
						if (!ArrayFlag){
							for (i=scope; i>-1; i--){
								if ( (Scope_NameTypeLookup(ScopeArray, i, scope, yylval.strVal, USERFUNC) )
									||  (Scope_NameTypeLookup(ScopeArray, i, scope, yylval.strVal, LIBFUNC)) )
								{
									printf("Error!!! In Line %d | Can not assign any value to %s\n",yylineno, yylval.strVal);
									break;
								}
							}
						}
						ArrayFlag = 0;
					}
			ASSIGN expr	{fprintf(yyout,"assignexpr ==> lvalue = expr \n");}
			;


term 	: LEFT_PARENTHES expr RIGHT_PARENTHES	{fprintf(yyout,"term ==> (expr) \n");}
		| primary				{fprintf(yyout,"term ==> primary\n");}
		| MINUS expr %prec UMINUS		{fprintf(yyout,"term ==> -expr\n");}
		| PPLUS lvalue{
							for (i=scope; i>-1; i--){
								if ( (Scope_NameTypeLookup(ScopeArray, i, scope, yylval.strVal, USERFUNC) )
									||  (Scope_NameTypeLookup(ScopeArray, i, scope, yylval.strVal, LIBFUNC)) )
								{
									printf("Error!!! In Line %d | Can not assign any value to %s\n",yylineno, yylval.strVal);
									break;
								}
							}
							fprintf(yyout,"term ==> ++lvalue\n");
						}				
		| lvalue {
					for (i=scope; i>-1; i--){
						if ( (Scope_NameTypeLookup(ScopeArray, i, scope, yylval.strVal, USERFUNC) )
							||  (Scope_NameTypeLookup(ScopeArray, i, scope, yylval.strVal, LIBFUNC)) )
						{
							printf("Error!!! In Line %d | Can not assign any value to %s\n",yylineno, yylval.strVal);
							break;
						}
					}
				 }	PPLUS				{fprintf(yyout,"term ==> lvalue++\n");}
		| MMINUS lvalue	{
							for (i=scope; i>-1; i--){
								if ( (Scope_NameTypeLookup(ScopeArray, i, scope, yylval.strVal, USERFUNC) )
									||  (Scope_NameTypeLookup(ScopeArray, i, scope, yylval.strVal, LIBFUNC)) )
								{
									printf("Error!!! In Line %d | Can not assign any value to %s\n",yylineno, yylval.strVal);
									break;
								}
							}
							fprintf(yyout,"term ==> --lvalue\n");
						}
		| lvalue {
					for (i=scope; i>-1; i--){
						if ( (Scope_NameTypeLookup(ScopeArray, i, scope, yylval.strVal, USERFUNC) )
							||  (Scope_NameTypeLookup(ScopeArray, i, scope, yylval.strVal, LIBFUNC)) )
						{
							printf("Error!!! In Line %d | Can not assign any value to %s\n",yylineno, yylval.strVal);
							break;
						}
					}
				 }  MMINUS				{fprintf(yyout,"term ==> lvalue--\n");}
		| NOT expr				{fprintf(yyout,"term ==> !expr\n");}
		;


primary	: lvalue					{fprintf(yyout,"primary ==>  lvalue\n");}
		| call						{fprintf(yyout,"primary ==>  call\n");}
		| objectdef					{fprintf(yyout,"primary ==>  objectdef\n");}
		| LEFT_PARENTHES funcdef RIGHT_PARENTHES	{fprintf(yyout,"primary ==>  (funcdef)\n");}
		| const						{fprintf(yyout,"primary ==>  const\n");}
		;

const	: NUMBER  		{fprintf(yyout,"const ==> number \n");}
		| REALNUM		{fprintf(yyout,"const ==> realnum\n");}
		| STRING		{fprintf(yyout,"const ==> string\n");}
		| TRUE			{fprintf(yyout,"const ==> true\n");}
		| FALSE			{fprintf(yyout,"const ==> false\n");}
		| NIL 			{fprintf(yyout,"const ==> nil\n");}
		;

lvalue	: ID{
				fprintf(yyout,"lvalue ==> ID \n");
				
				for (i=scope; i>-1; i--){
					if ( TmpNode = Scope_NameLookup(ScopeArray, i, yytext) ){
						if ( (i != 0) && (TmpNode->type != USERFUNC) && (TmpNode->type != LIBFUNC) ){
						/*if it not found in scope 0 and it is not a Function */ 
						
							if (FuncSearch(ScopeArray, i, scope-1) )/*if there is a function between*/
								printf("Error!!! In Line %d | Can not access %s\n",yylineno, yylval.strVal);
						}
						break;
					}
				}
				/*if ID was not found*/
				if (i == -1){
					if (scope == 0)
						InsertToSymTable(oSymTable, ScopeArray, yytext, GLOBAL, scope, yylineno); 
					else
						InsertToSymTable(oSymTable, ScopeArray, yytext, LOKAL, scope, yylineno); 
				}
			}
		| LOCAL ID	{
						fprintf(yyout,"lvalue ==> LOCAL ID \n");
						if( Scope_NameTypeLookup(ScopeArray,0, 0, yytext, LIBFUNC) ){
							printf("Error!!! In Line %d | %s Shadows a Library Function!\n",yylineno, yytext);
						}
						else if( Scope_NameLookup(ScopeArray,scope,yytext) == NULL){
							/*don't insert into symtable if local id exists in scope*/
						}
						else{
						
							if(scope==0)	//In Scope 0 Local var becomes global
								InsertToSymTable(oSymTable, ScopeArray, strdup(yytext), GLOBAL, scope, yylineno);
							else
								InsertToSymTable(oSymTable, ScopeArray, strdup(yytext), LOKAL, scope, yylineno);
						}
					}
		| DCOLON ID	{
						fprintf(yyout,"lvalue ==> DCOLON ID \n");
						if(Scope_NameLookup(ScopeArray,0, yytext)== NULL){
							printf("Error!!! In Line %d |  There is no member on global scope with the name %s\n",yylineno, yylval.strVal);
						}
					}
		| member					{fprintf(yyout,"lvalue ==> member \n");}
		;

member	: lvalue DOT ID					{fprintf(yyout,"member ==> lvalue.id \n");}
		| lvalue LEFT_SBRACKET expr RIGHT_SBRACKET	{ArrayFlag = 1; fprintf(yyout,"member ==> lvalue[expr] \n");}
		| call DOT ID					{fprintf(yyout,"member ==> call().id) \n");}
		| call LEFT_SBRACKET expr RIGHT_SBRACKET	{ArrayFlag = 1; fprintf(yyout,"member ==> call()[expr] \n");}
		;
		
call	: call LEFT_PARENTHES elist RIGHT_PARENTHES					{fprintf(yyout,"call ==> call(elist)\n");}
		| lvalue callsuffix								{fprintf(yyout,"call ==> lvalue callsuffix\n");}
		| LEFT_PARENTHES funcdef RIGHT_PARENTHES LEFT_PARENTHES elist RIGHT_PARENTHES	{fprintf(yyout,"call ==> (funcdef)(elist)\n");}
		;

callsuffix	: normcall			{fprintf(yyout,"callsuffix ==> normcall\n");}
			| methodcall			{fprintf(yyout,"callsuffix ==> methodcall \n");}
			;
		
normcall: LEFT_PARENTHES elist RIGHT_PARENTHES		{fprintf(yyout,"normalcall ==> (elist)\n");}
		;
		
methodcall	: DOTS ID LEFT_PARENTHES elist RIGHT_PARENTHES {fprintf(yyout,"methodcall ==> ..id (elist)\n");}
			;
		
elist	: expr cexprs	{fprintf(yyout,"elist ==> expr cexprs\n");}
		|/*empty*/	{fprintf(yyout,"elist ==> empty \n");}
		;

cexprs	:COMMA expr cexprs {fprintf(yyout,"cexprs ==> COMMA expr exprs \n");}
		| /*empty*/	   {fprintf(yyout,"elist ==> empty \n");}	
		;


objectdef	: LEFT_SBRACKET elist RIGHT_SBRACKET	{fprintf(yyout,"objectdef ==> [elist]\n");}
			| LEFT_SBRACKET indexed RIGHT_SBRACKET   {fprintf(yyout,"objectdef ==> [indexed]\n");}
			;

indexed		: indexedelem clindexedelem	{fprintf(yyout,"indexed ==> indexedelem clindexedelem\n");}
			;
		
clindexedelem	: COMMA indexedelem clindexedelem	{fprintf(yyout,"clindexedelem ==> ,indexedelem *\n");}
				| /*empty*/		{fprintf(yyout,"clindexedelem ==> empty\n");}
				;

indexedelem		: LEFT_CBRACKET expr COLON expr RIGHT_CBRACKET		{fprintf(yyout,"indexedelem ==> [expr : expr]\n");}
				;

block			: LEFT_CBRACKET  RIGHT_CBRACKET		{fprintf(yyout,"block ==> {}\n");}
				| LEFT_CBRACKET {scope++;} stmt statements RIGHT_CBRACKET{	
																			fprintf(yyout,"block ==> [stmt*]\n");
																			/*Hide the symbols of this scope*/
																			Scope_Hide(scope, ScopeArray);
																			scope--; 
																		 }
				;

funcdef : FUNCTION {
						FunctionFlag++;
						InsertToSymTable(oSymTable, ScopeArray, dflt_name, USERFUNC, scope, yylineno);
						dflt_name[2] ++;
				   } LEFT_PARENTHES{scope++;} idlist RIGHT_PARENTHES{scope--; } block	{fprintf(yyout,"funcdef ==> FUNCTION (idlist) {}\n");
																						FunctionFlag--;}
					
		| FUNCTION ID{  TmpNode = Scope_NameLookup(ScopeArray, scope, yytext);
						FunctionFlag++;
						/*function exists in same scope*/
						if ( TmpNode ){
							printf("Error!!! In Line %d | Redeclaration of %s.\n",yylineno, TmpNode->name);
						}/*shadowing of library function*/ 
						else if (Scope_NameTypeLookup(ScopeArray, 0, 0,yytext, LIBFUNC)){
							printf("Error!!! In Line %d |  %s Shadows a Library Function!\n",yylineno,yytext);
						}/*al iz vel just insert*/
						else{
							InsertToSymTable(oSymTable, ScopeArray, yytext, USERFUNC, scope, yylineno);
						}
					 }
					 
					 LEFT_PARENTHES{scope++;} idlist RIGHT_PARENTHES{scope--;} block	{fprintf(yyout,"funcdef ==> FUNCTION ID (idlist) {}\n");
																						 FunctionFlag--;}
		;

idlist	: ID {	
				if (FunctionFlag>0)  InsertArgToFunction (oSymTable, ScopeArray, ScopeArray[scope-1] , yytext);
					
				if ( TmpNode = Scope_NameLookup(ScopeArray, scope, yytext) ){/*if it already exists*/
					printf("Error!!!In Line %d |  Formal redefinition of %s !\n",yylineno, yylval.strVal);
				}
				else if (Scope_NameTypeLookup(ScopeArray,0, 0, yytext, LIBFUNC) ){/*if it shadows a lib function*/
					printf("Error!!!In Line %d |  Formal; %s Shadows a Library Function!\n",yylineno, yylval.strVal);
				}
				else{/*insert*/
					InsertToSymTable(oSymTable, ScopeArray, yytext, FORMAL, scope, yylineno); 
				}

				 }cidlist	{fprintf(yyout,"idlist ==> ID cidlist\n");}	
		| /*empty*/	{fprintf(yyout,"idlist ==> empty\n");}
		;
		
cidlist	: COMMA ID{
						
						if (FunctionFlag>0)  InsertArgToFunction (oSymTable, ScopeArray, ScopeArray[scope-1] , yytext);
								
						if ( TmpNode = Scope_NameLookup(ScopeArray, scope, yytext) ){/*if it already exists*/
							printf("Error!!!In Line %d |  Formal redefinition of %s !\n",yylineno, yylval.strVal);
						}
						else if (Scope_NameTypeLookup(ScopeArray, 0, 0, yytext, LIBFUNC) ){/*if it shadows a lib function*/
							printf("Error!!!In Line %d |  Formal %s Shadows a Library Function!\n",yylineno, yylval.strVal);
						}
						else{/*insert*/
							InsertToSymTable(oSymTable, ScopeArray, yytext, FORMAL, scope, yylineno); 
						}
						
		     	  } cidlist {fprintf(yyout,"cidlist ==> , ID cidlist\n");}
		| /*empty*/	{fprintf(yyout,"cidlist ==> empty\n");}
		;

ifstmt	: IF LEFT_PARENTHES expr RIGHT_PARENTHES stmt 	  {fprintf(yyout,"ifstmt ==> if (expr) stmt\n");}
		| IF LEFT_PARENTHES expr RIGHT_PARENTHES stmt ELSE stmt  {fprintf(yyout,"ifstmt ==> if (expr) stmt else stmt\n");}
		;
		
whilestmt	: WHILE LEFT_PARENTHES expr RIGHT_PARENTHES stmt	{fprintf(yyout,"whilestmt ==> while (expr) stmt\n");}
			;
			
forstmt	: FOR LEFT_PARENTHES elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHES stmt	{fprintf(yyout,"forstmt ==> for(elist; expr; elist) stmt\n");}
		;
		
returnstmt	: RETURN expr  SEMICOLON	{fprintf(yyout,"returnstmt ==> return expr ;\n");}
			| RETURN SEMICOLON	{fprintf(yyout,"returnstmt ==> return ;\n");}
			;

%%

int yyerror (char* yaccProvidedMessage)
{
	fprintf(stderr, "%s: at line %d, before token: '%s'\n", yaccProvidedMessage, yylineno, yytext);
}

int main(int argc, char** argv)
{

	if (argc == 3){
		if( !(yyin = fopen(argv[1], "r")) ) {
			fprintf(stderr, "Cannot Open File: %s\n", argv[1]);
			yyin = stdin;
		}
		if(!(yyout = fopen(argv[2], "w")) )
		{
			fprintf(stderr, "Cannot Open File: %s\n", argv[2]);
			yyout = stdout;
		}
	}
	else if (argc == 2){
		if( !(yyin = fopen(argv[1], "r")) ) {
			fprintf(stderr, "Cannot Open File: %s\n", argv[1]);
			yyin = stdin;
		}
	}
	else{
		fprintf(stderr, "WTF...Give mama some arguments ;P \n");
		return 0;
	}
	
	/*memory allocation of sym table*/
	oSymTable = SymTable_new();
	/*init the library functions*/
	InsertToSymTable(oSymTable, ScopeArray,"print", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"input", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"objectmemberkeys", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"objecttotalmembers", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"objectcopy", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"totalarguments", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"argument", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"typeof", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"stronum", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"sqrt", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"cos", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"sin", LIBFUNC , 0, 0);
	
	yyparse();
	
	printf("\n\nActives of Symbol Table!!\n");
	SymTable_Print(oSymTable);
	printf("\n\nEverything of All ScopeLists!!\n");
	PrintAllScopes(ScopeArray);
	
	return 0;
}

