%{
	#include "quad.h"
	
	int yyerror (char* yaccProvidedMessage);
	int yylex (void);
	
	extern int yylineno;
	extern char * yyval;
	extern char * yytext;
	extern FILE * yyin;
	extern FILE * yyout;
	
	
	
	quad *tmpquad[100], *fortmpquad=NULL;
	expr *tmpCall=NULL;
	int i=0, normCall= 0, paramCounter=0, LogicFlag =0, Balls=0, ErrorFlag = 0;
	int loopstart[100],loopindex=0, Qindex=0, forstart=0;
	SymbolNode  *TmpNode;
	intlist *tmp = NULL;
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
%type <expression>      assignexpr
%type <expression>      expr
%type <expression>      term
%type <expression>      primary
%type <expression>      objectdef
%type <expression>      funcdef
%type <expression>      const
%type <expression>      lvalue
%type <expression>      member
%type <expression>      call
%type <expression>      callsuffix
%type <expression>      normcall
%type <expression>      methodcall
%type <expression>      elist
%type <expression>      cexprs
%type <expression>      indexed
%type <expression>      clindexedelem
%type <expression>      indexedelem
%type <expression>		block
%type <expression>	ifstmt
%type <expression>	whilestmt
%type <expression>	forstmt
%type <expression>	returnstmt
%type <expression> 	stmt
%type <expression>  statements

%union
{
	char* strVal;
	int intVal;
	double dbVal;
	struct expr *expression;
	struct stmt *statement;
	struct quad *quad;
}

%%

program	:  statements 		{fprintf(yyout," program ==> statements \n");}
		;

statements 	:  stmt statements 	{
									fprintf(yyout,"statements ==> stmt statements\n");
								}
			| /*empty*/		{fprintf(yyout,"statements ==> empty \n");}
			;

stmt	: expr SEMICOLON{
							if (LogicFlag){
								backpatch(Truehead, currQuad);
								backpatch(Falsehead, currQuad+2);
								
								/*fix last JUMP*/
								tmpquad[98] = quads+currQuad-1;
								tmpquad[98]->label = currQuad+2;
								/*Threeway*/
								$$ = insertExpr(assign, ConstBool_exp(1), NULL, currQuad, boolexpr_e);
								insertQuad(jump,NULL,NULL,NULL,currQuad+2,currQuad);								
								insertQuad(assign, $$, ConstBool_exp(0), NULL, -1, boolexpr_e);
							
								insertQuad(assign,$1, $$,NULL,-1,currQuad);
								LogicFlag = 0;
							}
							
							
							//$$=NULL;
							strcpy(dflt_tmpname ,"_tmp00");
							fprintf(yyout,"stmt ==> expr; \n");
						}
		| ifstmt		{
							$$=$1;
							LogicFlag = 0;
							fprintf(yyout,"stmt ==> ifstmt \n");}
		| whilestmt		{
							$$=NULL;
							LogicFlag = 0;
							fprintf(yyout,"stmt ==> whilestmt  \n");}
		| forstmt		{
							$$=NULL;
							LogicFlag = 0;
							fprintf(yyout,"stmt ==> forstmt \n");}
		| returnstmt	{
							$$=NULL;
							fprintf(yyout,"stmt ==> returnstmt \n");}
		| BREAK SEMICOLON	{
								if (loopindex>0){
									BreakHead=CreateIntList(currQuad,BreakHead);
									insertQuad(jump, NULL, NULL, NULL, -1, currQuad);
								}
								else{
									printf("Error!!! In Line %d | Break statement found. Not in loop.\n",yylineno);
									ErrorFlag = 1;
								}
								fprintf(yyout,"stmt ==> break; \n");
							}
		| CONTINUE SEMICOLON{
								if (loopindex>0){
									ContinueHead=CreateIntList(currQuad,ContinueHead);
									insertQuad(jump, NULL, NULL, NULL, -1, currQuad);
								}
								else{
									printf("Error!!! In Line %d | Continue statement found. Not in loop.\n",yylineno);
									ErrorFlag = 1;
								}
								fprintf(yyout,"stmt ==> continue; \n");
							}
		| block			{
							$$=$1;
							fprintf(yyout,"stmt ==> block \n");}
		| funcdef		{
							$$=$1;
							fprintf(yyout,"stmt ==> funcdef \n");}	
		| SEMICOLON		{	
							$$=NULL;
							fprintf(yyout,"stmt ==> ; \n"); 
							strcpy(dflt_tmpname ,"_tmp00");
						}
		;
		
expr 	:assignexpr	{	
						$$=$1;
						$$->type=assgnexpr_e;						
						Balls=1;
						fprintf(yyout,"expr ==> assignexpr  \n");
					}
		| expr PLUS expr	{ 	$$=insertExpr(add,$1,$3, currQuad,arithexpr_e);
								fprintf(yyout,"expr ==>  expr + expr  \n");}
		| expr MINUS expr	{ 	$$=insertExpr(sub,$1,$3, currQuad,arithexpr_e);
								fprintf(yyout,"expr ==>  expr - expr  \n");}
		| expr MULTI expr	{ 	$$=insertExpr(mul,$1,$3, currQuad,arithexpr_e);
								fprintf(yyout,"expr ==>  expr * expr  \n");}
		| expr DIV expr		{ 	$$=insertExpr(divv,$1,$3, currQuad,arithexpr_e);
								fprintf(yyout,"expr ==>  expr div expr  \n");}
		| expr MOD expr		{ 	$$=insertExpr(mod,$1,$3, currQuad,arithexpr_e);
								fprintf(yyout,"expr ==>  expr mod expr  \n");}
		| expr AND 
						expr{	
								/*an to $1 (to if )paei sto true fix it*/
								tmp = (intlist*) malloc (sizeof(intlist) );
								tmp->currentquad = currQuad -4;
								backpatch(tmp, currQuad-2);
								/*Delete apo thn true list gia na mhn to pathsei */
								Truehead = DeleteIntList(currQuad-4, Truehead);
								//free(tmp);
								tmp = NULL;
								
								Falsehead=CreateIntList(currQuad-1,Falsehead);/*$3 jump*/
								Falsehead=CreateIntList(currQuad-3,Falsehead);/*$1 jump*/

								LogicFlag =1;
								fprintf(yyout,"expr ==>  expr and expr  \n");
							}
		| expr OR expr{			
								tmp = (intlist*) malloc (sizeof(intlist) );

								/*an to $1 (to jump)paei sto false fix it*/
								/*normal*/
								tmp->currentquad = currQuad -3;
								backpatch(tmp, currQuad-2);	
								/*Delete apo thn false list gia na mhn to pathsei */
								Falsehead = DeleteIntList(currQuad-3, Falsehead);
								Truehead = CreateIntList(currQuad-4,Truehead);/*$4 if*/
								//free(tmp);
								tmp = NULL;										
								
								Truehead = CreateIntList(currQuad-2,Truehead);/*$1 if*/
								
								LogicFlag =1;
								fprintf(yyout,"expr ==>  expr or expr  \n");
							}
		| expr EQUAL expr	{ /*initialize the expression's if and jump with the right labels*/
							  /*ifshit*/
							  insertQuad(if_eq,$1, $3, NULL, currQuad+2,currQuad);
							  /*jump*/
							  insertQuad(jump,NULL,NULL,NULL, currQuad+1,currQuad);							 						
							  
							  LogicFlag =1;
							  Balls=1;
							  fprintf(yyout,"expr ==>  expr == expr  \n");							  
							}
		| expr NEQUAL expr	{ /*initialize the expression's if and jump with the right labels*/
							  /*ifshit*/
							  insertQuad(if_noteq,$1, $3, NULL, currQuad+2,currQuad);
							  /*jump*/
							  insertQuad(jump,NULL,NULL,NULL, currQuad+1,currQuad);							 						
							  
							  Balls=1;
							  LogicFlag =1;
							  fprintf(yyout,"expr ==>  expr != expr  \n");
							}
		| expr GREATER expr	{ /*initialize the expression's if and jump with the right labels*/
							  /*ifshit*/
							  insertQuad(if_greater,$1, $3, NULL, currQuad+2,currQuad);
							  /*jump*/
							  insertQuad(jump,NULL,NULL,NULL, currQuad+1,currQuad);							 						
							  
							  Balls=1;
							  LogicFlag =1;
							  fprintf(yyout,"expr ==>  expr > expr  \n");
							}
		| expr LESS expr	{ /*initialize the expression's if and jump with the right labels*/
							  /*ifshit*/
							  insertQuad(if_less,$1, $3, NULL, currQuad+2,currQuad);
							  /*jump*/
							  insertQuad(jump,NULL,NULL,NULL, currQuad+1,currQuad);							 						
							  
							  Balls=1;
							  LogicFlag =1;
							  fprintf(yyout,"expr ==>  expr < expr \n");
							}
		| expr GREATER_EQUAL expr 	{  	/*initialize the expression's if and jump with the right labels*/
										/*ifshit*/
										insertQuad(if_geatereq,$1, $3, NULL, currQuad+2,currQuad);
										/*jump*/
										insertQuad(jump,NULL,NULL,NULL, currQuad+1,currQuad);							 						
										
										Balls=1;
										LogicFlag =1;
										fprintf(yyout,"expr ==> expr >= expr  \n");
									}
		| expr LESS_EQUAL expr		{   /*initialize the expression's if and jump with the right labels*/
										/*ifshit*/
										insertQuad(if_lesseq,$1, $3, NULL, currQuad+2,currQuad);
										/*jump*/
										insertQuad(jump,NULL,NULL,NULL, currQuad+1,currQuad);							 						
										
										Balls=1;
										LogicFlag =1;
										fprintf(yyout,"expr ==> expr <= expr  \n");
									}
		| term			{
		
							$$ = $1;
							fprintf(yyout,"expr ==> term  \n");
						}
		;

assignexpr	: 	lvalue{
						if (!ArrayFlag){
							for (i=scope; i>-1; i--){
								if ( (Scope_NameTypeLookup(ScopeArray, i, yylval.strVal, USERFUNC) )
									||  (Scope_NameTypeLookup(ScopeArray, i, yylval.strVal, LIBFUNC)) )
								{
									printf("Error!!! In Line %d | Can not assign any value to %s\n",yylineno, yylval.strVal);
									ErrorFlag = 1;
									break;
								}
							}
						}
						ArrayFlag = 0;
						if ($1->type == tableitem_e){
							tmpquad[99] = quads+(currQuad-1);
							tmpquad[99]->op = tablesetelem;
						}
					}
			ASSIGN expr	{
							if (!LogicFlag)
								insertQuad(assign,$1, $4,NULL,-1,currQuad);
								
							fprintf(yyout,"assignexpr ==> lvalue = expr \n");
						}	
			;

term 	: LEFT_PARENTHES expr RIGHT_PARENTHES		
							{ $$=$2;
								fprintf(yyout,"term ==> (expr) \n");
							}
		| primary			{ $$=$1; 
							  fprintf(yyout,"term ==> primary\n");
							}
		| MINUS expr %prec UMINUS{
									insertQuad(uminus,$2,NULL, NULL, -1, currQuad);
									if ($2->type == tableitem_e){
										tmpquad[99] = quads+(currQuad-1);
										tmpquad[99]->op = tablesetelem;
									}
									fprintf(yyout,"term ==> -expr\n");
								}
		| PPLUS lvalue		{
								$$=$2;
								
								insertQuad(add,$2, $2, ConstInt_exp(1),-1,currQuad);
								if ($2->type == tableitem_e){
									tmpquad[99] = quads+(currQuad-1);
									tmpquad[99]->op = tablesetelem;
								}
								
								for (i=scope; i>-1; i--){
								if ( (Scope_NameTypeLookup(ScopeArray, i, yylval.strVal, USERFUNC) )
									||  (Scope_NameTypeLookup(ScopeArray, i, yylval.strVal, LIBFUNC)) )
								{
									printf("Error!!! In Line %d | Can not assign any value to %s\n",yylineno, yylval.strVal);
									ErrorFlag = 1;
									break;
								}
							}
							fprintf(yyout,"term ==> ++lvalue\n");
						}				
		| lvalue {
					for (i=scope; i>-1; i--){
						if ( (Scope_NameTypeLookup(ScopeArray, i, yylval.strVal, USERFUNC) )
							||  (Scope_NameTypeLookup(ScopeArray, i, yylval.strVal, LIBFUNC)) )
						{
							printf("Error!!! In Line %d | Can not assign any value to %s\n",yylineno, yylval.strVal);
							ErrorFlag = 1;
							break;
						}
					}
				 }	PPLUS{ 
							insertQuad(add,$1,$1,ConstInt_exp(1),-1,currQuad);
							if ($1->type == tableitem_e){
									tmpquad[99] = quads+(currQuad-1);
									tmpquad[99]->op = tablesetelem;
							}
							
				 			fprintf(yyout,"term ==> lvalue++\n");
						 }
		| MMINUS lvalue	{
							$$=$2;
							
							insertQuad(sub,$2, $2, ConstInt_exp(1),-1,currQuad);
							if ($2->type == tableitem_e){
									tmpquad[99] = quads+(currQuad-1);
									tmpquad[99]->op = tablesetelem;
								}
								
							for (i=scope; i>-1; i--){
								if ( (Scope_NameTypeLookup(ScopeArray, i, yylval.strVal, USERFUNC) )
									||  (Scope_NameTypeLookup(ScopeArray, i, yylval.strVal, LIBFUNC)) )
								{
									printf("Error!!! In Line %d | Can not assign any value to %s\n",yylineno, yylval.strVal);
									ErrorFlag = 1;
									break;
								}
							}						        
							fprintf(yyout,"term ==> --lvalue\n");
						}
		| lvalue {
					for (i=scope; i>-1; i--){
						if ( (Scope_NameTypeLookup(ScopeArray, i, yylval.strVal, USERFUNC) )
							||  (Scope_NameTypeLookup(ScopeArray, i, yylval.strVal, LIBFUNC)) )
						{
							printf("Error!!! In Line %d | Can not assign any value to %s\n",yylineno, yylval.strVal);
							ErrorFlag = 1;
							break;
						}
					}
				 }  MMINUS{ 
							$$=$1;
							
							insertQuad(sub,$1,$1,ConstInt_exp(1),-1,currQuad);
							if ($1->type == tableitem_e){
									tmpquad[99] = quads+(currQuad-1);
									tmpquad[99]->op = tablesetelem;
							}
							
							fprintf(yyout,"term ==> lvalue--\n");
						  }
		| NOT expr	{
						//$$ = insertExpr(not,$2,NULL,currQuad,boolexpr_e);
						/*initialize the expression's if and jump with the right labels*/
						/*ifshit*/
						insertQuad(if_eq, $2, ConstBool_exp(0), NULL, currQuad+2,currQuad);
						/*jump*/
						insertQuad(jump,NULL,NULL,NULL, currQuad+1,currQuad);							 						
							  
						LogicFlag =1;
						
						if ($2->type == tableitem_e){
									tmpquad[99] = quads+(currQuad-1);
									tmpquad[99]->op = tablesetelem;
						}
						
						fprintf(yyout,"term ==> !expr\n");
					}
		;


primary	: lvalue					{fprintf(yyout,"primary ==>  lvalue\n");}
		| call						{
										$$=$1;
										fprintf(yyout,"primary ==>  call\n");}
		| objectdef					{
										$$=$1;
										fprintf(yyout,"primary ==>  objectdef\n");}
		| LEFT_PARENTHES funcdef RIGHT_PARENTHES	{
														$$=$2;
														fprintf(yyout,"primary ==>  (funcdef)\n");}
		| const						{ 
										$$=$1;
										fprintf(yyout,"primary ==>  const\n");}
		;

const	: NUMBER  		{
					 $$=ConstInt_exp(yylval.intVal);
					 fprintf(yyout,"const ==> number \n");}
		| REALNUM		{
					 $$=ConstDouble_exp(yylval.dbVal);
					 fprintf(yyout,"const ==> realnum\n");}
		| STRING		{
					 $$= ConstString_exp(yylval.strVal);
					 fprintf(yyout,"const ==> string\n");}
		| TRUE			{
					 $$=ConstBool_exp(1);
					 fprintf(yyout,"const ==> true\n");}
		| FALSE			{
					 $$=ConstBool_exp(0);
					 fprintf(yyout,"const ==> false\n");}
		| NIL 			{
					 $$=ConstNil_exp();
					 fprintf(yyout,"const ==> nil\n");}
		;

lvalue	: ID{
				fprintf(yyout,"lvalue ==> ID \n");
				
				for (i=scope; i>-1; i--){
					if ( TmpNode = Scope_NameLookup(ScopeArray, i, yytext) ){
						$$=lvalue_expr(TmpNode);
						if ( (i != 0) && (TmpNode->type != USERFUNC) && (TmpNode->type != LIBFUNC) ){
						/*if it not found in scope 0 and it is not a Function */ 
						
							if (FuncSearch(ScopeArray, i, scope-1) ){/*if there is a function between*/
								printf("Error!!! In Line %d | Can not access %s\n",yylineno, yylval.strVal);
								ErrorFlag = 1;
							}
						}
						break;
					}
				}
				/*if ID was not found*/
				if (i == -1){
					
					if (scope == 0){
						offset++;
						ScopeSpace=strdup("Programm Variables");
						$$=lvalue_expr(InsertToSymTable(oSymTable, ScopeArray, yytext, GLOBAL, scope, yylineno,offset,ScopeSpace,-1)); 
					}
					else{
						if (FunctionFlag>=0){
						    ScopeSpace=strdup("Function Local");
						    functionoffsets[FunctionFlag]++;
						    $$=lvalue_expr(InsertToSymTable(oSymTable, ScopeArray, yytext, LOKAL, scope, yylineno,functionoffsets[FunctionFlag],ScopeSpace,-1));
						}
						else{
						    offset++;
						    ScopeSpace=strdup("Programm Variables");
						    $$=lvalue_expr(InsertToSymTable(oSymTable, ScopeArray, yytext, LOKAL, scope, yylineno,offset,ScopeSpace,-1));
						}
					}
				}
			}
		| LOCAL ID	{
						fprintf(yyout,"lvalue ==> LOCAL ID \n");
						if( !(TmpNode=Scope_NameLookup(ScopeArray,scope,yytext)) ){
							
							if( Scope_NameTypeLookup(ScopeArray,0, yytext, LIBFUNC) ){
								printf("Error!!! In Line %d | %s Shadows a Library Function!\n",yylineno, yytext);
								ErrorFlag = 1;
							}
							else{
								
							
								if(scope==0){	//In Scope 0 Local var becomes global
									offset++;
									ScopeSpace=strdup("Programm Variables");
									$$=lvalue_expr(InsertToSymTable(oSymTable, ScopeArray, strdup(yytext), GLOBAL, scope, yylineno,offset,ScopeSpace,-1));
								}
								else{
								
									if (FunctionFlag>=0){
									    ScopeSpace=strdup("Function Local");
									    functionoffsets[FunctionFlag]++;									    
									    $$=lvalue_expr(InsertToSymTable(oSymTable, ScopeArray, yytext, LOKAL, scope, yylineno,functionoffsets[FunctionFlag],ScopeSpace,-1)); 
									}
									else{
									    offset++;
									    ScopeSpace=strdup("Programm Variables");
									    $$=lvalue_expr(InsertToSymTable(oSymTable, ScopeArray, yytext, LOKAL, scope, yylineno,offset,ScopeSpace,-1));
									}
								}
							}
						}
						else{
							$$=lvalue_expr(TmpNode);
						}
					}
		| DCOLON ID	{
						fprintf(yyout,"lvalue ==> DCOLON ID \n");
						if(!(TmpNode=Scope_NameLookup(ScopeArray,0, yytext)) ){
							$$=lvalue_expr(TmpNode);
							printf("Error!!! In Line %d |  There is no member on global scope with the name %s\n",yylineno, yylval.strVal);
							ErrorFlag = 1;
						}
					}
		| member					{
										$$=$1;
										fprintf(yyout,"lvalue ==> member \n");}
		;

member	: lvalue DOT ID	{
							$$ = insertExpr(tablegetelem, $1, ConstString_exp(yylval.strVal), currQuad, tableitem_e);
							fprintf(yyout,"member ==> lvalue.id \n");
						}
		| lvalue LEFT_SBRACKET expr RIGHT_SBRACKET	
						{
							ArrayFlag = 1;
							$$ = insertExpr(tablegetelem, $1, $3, currQuad, tableitem_e);
							fprintf(yyout,"member ==> lvalue[expr] \n");
						}
		| call DOT ID	{	//NOT TESTED
							$$ = insertExpr(tablegetelem, $1, ConstString_exp(yylval.strVal), currQuad, tableitem_e);
							fprintf(yyout,"member ==> call().id) \n");
						}
		| call LEFT_SBRACKET expr RIGHT_SBRACKET	{ArrayFlag = 1; fprintf(yyout,"member ==> call()[expr] \n");}
		;
		
call	: call LEFT_PARENTHES elist RIGHT_PARENTHES	{
								  expr *parametr=$3;
								  while(parametr!=NULL){
									insertQuad(param, NULL,parametr,NULL, -1, currQuad);
									parametr=parametr->next;
								  }
								  expr* tmpexpr=lvalue_expr(InsertToSymTable(oSymTable,ScopeArray,GenerateTmpName(),GLOBAL,scope, yylineno,offset, "Programm Variables",-1));
								  insertQuad(call,$1,NULL,NULL,-1,currQuad);
								  insertQuad(getretval,tmpexpr,NULL,NULL,-1,currQuad);
								  $$=tmpexpr;
								  fprintf(yyout,"call ==> call(elist)\n");
								  }
		| lvalue callsuffix	{
						if (normCall){
							insertQuad(call,$1,NULL,NULL,-1,currQuad);	
						}
						else{
							tmpquad[99] = quads+currQuad-(paramCounter+1);
							tmpquad[99]->arg1 = $1;
							insertQuad(param, NULL, $1, NULL, -1, currQuad);
							insertQuad(call,tmpCall,NULL,NULL,-1,currQuad);
						}
						tmpCall=lvalue_expr(InsertToSymTable(oSymTable,ScopeArray,GenerateTmpName(),GLOBAL,scope, yylineno,offset, "Programm Variables",-1));
						insertQuad(getretval,tmpCall,NULL,NULL,-1,currQuad);
						$$=tmpCall;
					  fprintf(yyout,"call ==> lvalue callsuffix\n");
					  }
		| LEFT_PARENTHES funcdef RIGHT_PARENTHES LEFT_PARENTHES elist RIGHT_PARENTHES	{
												expr *parametr=$5;
												while(parametr!=NULL){
												      insertQuad(param, NULL,parametr,NULL, -1, currQuad);
												      parametr=parametr->next;
												}
												insertQuad(call,$2,NULL,NULL,-1,currQuad);
												insertQuad(getretval,lvalue_expr(InsertToSymTable(oSymTable,ScopeArray,GenerateTmpName(),GLOBAL,scope, yylineno,offset, "Programm Variables",-1)),NULL,NULL,-1,currQuad);
												fprintf(yyout,"call ==> (funcdef)(elist)\n");
												}
		;

callsuffix	: normcall			{fprintf(yyout,"callsuffix ==> normcall\n");}
			| methodcall			{fprintf(yyout,"callsuffix ==> methodcall \n");}
			;
		 
normcall: LEFT_PARENTHES elist RIGHT_PARENTHES		{
							  expr *parametr=$2;
							  while(parametr!=NULL){
								insertQuad(param, NULL,parametr,NULL, -1, currQuad);
								parametr=parametr->next;
							  }
							  normCall = 1;
							  fprintf(yyout,"normalcall ==> (elist)\n");
							  }
		;
		
methodcall	: DOTS ID {
						tmpCall = insertExpr(tablegetelem, NULL, ConstString_exp(yylval.strVal), currQuad, tableitem_e);
					  }
					  LEFT_PARENTHES elist RIGHT_PARENTHES {
										
										expr *parametr=$5;
										paramCounter=0;
										while(parametr!=NULL){
											insertQuad(param, NULL,parametr,NULL, -1, currQuad);
											parametr=parametr->next;
											paramCounter++;
										}
										normCall = 0;
										fprintf(yyout,"methodcall ==> ..id (elist)\n");
									   }
			;
		
elist	: expr cexprs	{
			  $$=$1;
			  $$->next=$2;
			  fprintf(yyout,"elist ==> expr cexprs\n");
			  }
		|/*empty*/	{
				  $$=NULL;
				  fprintf(yyout,"elist ==> empty \n");
				  }
		;

cexprs	:COMMA expr cexprs {
			      $$=$2;
			      $$->next=$3;
			      fprintf(yyout,"cexprs ==> COMMA expr exprs \n");
			      }
		| /*empty*/	   {
				    $$=NULL;
				    fprintf(yyout,"elist ==> empty \n");
				    }	
		;


objectdef	: LEFT_SBRACKET elist RIGHT_SBRACKET	{
														$$=insert_tableelist($2,currQuad);
														fprintf(yyout,"objectdef ==> [elist]\n");
													}
			| LEFT_SBRACKET indexed RIGHT_SBRACKET  {
														$$ = $2;
														fprintf(yyout,"objectdef ==> [indexed]\n");
													}
			;

indexed		: indexedelem clindexedelem	{
											$$=$1;
											fprintf(yyout,"indexed ==> indexedelem clindexedelem\n");}
			;
		
clindexedelem	: COMMA indexedelem clindexedelem	{fprintf(yyout,"clindexedelem ==> ,indexedelem *\n");}
				| /*empty*/		{fprintf(yyout,"clindexedelem ==> empty\n");}
				;

indexedelem		: LEFT_CBRACKET expr COLON expr RIGHT_CBRACKET		{
																		$$=$4;
																		fprintf(yyout,"indexedelem ==> [expr : expr]\n");}
				;

block			: LEFT_CBRACKET  RIGHT_CBRACKET		{fprintf(yyout,"block ==> {}\n");}
				| LEFT_CBRACKET {scope++;} stmt statements RIGHT_CBRACKET{	
																			$$=$3;
																			fprintf(yyout,"block ==> [stmt*]\n");
																			/*Hide the symbols of this scope*/
																			Scope_Hide(scope, ScopeArray);
																			scope--; 
																		 }
				;

funcdef : FUNCTION {				
						FunctionFlag++;
						functionNames[FunctionFlag]=strdup(GenerateTmpName());
						InsertToSymTable(oSymTable, ScopeArray,functionNames[FunctionFlag], USERFUNC, scope, yylineno,-1,NULL,currQuad);
						insertQuad(funcstart, ConstString_exp(functionNames[FunctionFlag]), NULL, NULL, -1, currQuad);
						
				   } 
				   LEFT_PARENTHES{
									scope++;
					    		 } idlist RIGHT_PARENTHES{
														scope--; 
														Argoffset=0;
														 } 
														block	
													    {	 
													      $$=ConstString_exp(functionNames[FunctionFlag]);
													      insertQuad(funcend, ConstString_exp(functionNames[FunctionFlag]), NULL, NULL, -1, currQuad);
													      setFuncVarNum(ScopeArray,functionoffsets[FunctionFlag], functionNames[FunctionFlag], scope);
													      functionoffsets[FunctionFlag]=0;
													      FunctionFlag--;
												   	      fprintf(yyout,"funcdef ==> FUNCTION (idlist) {}\n");
												   	    }
		| FUNCTION ID{  
						TmpNode = Scope_NameLookup(ScopeArray, scope, yytext);
				
						/*function exists in same scope*/
						if ( TmpNode ){
							printf("Error!!! In Line %d | Redeclaration of %s.\n",yylineno, TmpNode->name);
							ErrorFlag = 1;
							
						}/*shadowing of library function*/ 
						else if (Scope_NameTypeLookup(ScopeArray,0, yytext, LIBFUNC)){
							printf("Error!!! In Line %d |  %s Shadows a Library Function!\n",yylineno,yytext);
							ErrorFlag = 1;
							
						}/*al iz vel just insert*/
						else{
							InsertToSymTable(oSymTable, ScopeArray, yytext, USERFUNC, scope, yylineno,-1,NULL,currQuad);
							FunctionFlag++;
							functionNames[FunctionFlag]=strdup(yytext);
							insertQuad(funcstart, ConstString_exp(functionNames[FunctionFlag]), NULL, NULL, -1, currQuad);
							
						}
					 }
					 
					 LEFT_PARENTHES{scope++;} idlist RIGHT_PARENTHES{scope--; Argoffset=0;} 
													block	
														{
														  $$=ConstString_exp(functionNames[FunctionFlag]);
														  insertQuad(funcend, ConstString_exp(functionNames[FunctionFlag]), NULL, NULL, -1, currQuad);
														  setFuncVarNum(ScopeArray,functionoffsets[FunctionFlag], functionNames[FunctionFlag], scope);																  
														  functionoffsets[FunctionFlag]=0; 
														  FunctionFlag--;
														  fprintf(yyout,"funcdef ==> FUNCTION ID (idlist) {}\n");
														}
		;

idlist	: ID {	
				if (FunctionFlag>=0)
				      InsertArgToFunction (oSymTable, ScopeArray, ScopeArray[scope-1] , yytext);
				
				
				if ( TmpNode = Scope_NameLookup(ScopeArray, scope, yytext) ){/*if it already exists*/
					printf("Error!!!In Line %d |  Formal redefinition of %s !\n",yylineno, yylval.strVal);
					ErrorFlag = 1;
				}
				else if (Scope_NameTypeLookup(ScopeArray,0, yytext, LIBFUNC) ){/*if it shadows a lib function*/
					printf("Error!!!In Line %d |  Formal; %s Shadows a Library Function!\n",yylineno, yylval.strVal);
					ErrorFlag = 1;
				}
				else{/*insert*/
					ScopeSpace = strdup("Formal Argument");
					InsertToSymTable(oSymTable, ScopeArray, yytext, FORMAL, scope, yylineno, Argoffset, ScopeSpace,-1); 
					Argoffset++;
				}

				 }cidlist	{fprintf(yyout,"idlist ==> ID cidlist\n");}	
		| /*empty*/	{fprintf(yyout,"idlist ==> empty\n");}
		;
		
cidlist	: COMMA ID{
						
						if (FunctionFlag>=0)  InsertArgToFunction (oSymTable, ScopeArray, ScopeArray[scope-1] , yytext);
								
						if ( TmpNode = Scope_NameLookup(ScopeArray, scope, yytext) ){/*if it already exists*/
							printf("Error!!!In Line %d |  Formal redefinition of %s !\n",yylineno, yylval.strVal);
							ErrorFlag = 1;
						}
						else if (Scope_NameTypeLookup(ScopeArray,0, yytext, LIBFUNC) ){/*if it shadows a lib function*/
							printf("Error!!!In Line %d |  Formal %s Shadows a Library Function!\n",yylineno, yylval.strVal);
							ErrorFlag = 1;
						}
						else{/*insert*/
							ScopeSpace = strdup("Formal Argument");
							InsertToSymTable(oSymTable, ScopeArray, yytext, FORMAL, scope, yylineno, Argoffset, ScopeSpace,-1); 
							Argoffset++; 
						}
						
		     	  } cidlist {fprintf(yyout,"cidlist ==> , ID cidlist\n");}
		| /*empty*/	{fprintf(yyout,"cidlist ==> empty\n");}
		;
		
ifstmt	: ifstart stmt{
			fprintf(yyout,"ifstmt ==> if (expr) stmt\n");
			tmpquad[--Qindex]->label=currQuad;
			}
	| ifstart stmt ELSE{
			    tmpquad[--Qindex]->label=currQuad+1;
			    tmpquad[Qindex++] = insertQuad(jump,NULL,NULL,NULL,-1,currQuad);
			   }stmt{
				  fprintf(yyout,"ifstmt ==> if (expr) stmt else stmt\n");
				  tmpquad[--Qindex]->label=currQuad;
				}
		  ;
		
ifstart	:	IF LEFT_PARENTHES{
							LogicFlag = 1;
							} expr RIGHT_PARENTHES{
														if (!Balls){
															/*initialize the expression's if and jump with the right labels*/
															/*ifshit*/
															insertQuad(if_eq,$4, ConstBool_exp(1), NULL, currQuad+2,currQuad);
															/*jump*/
															insertQuad(jump,NULL,NULL,NULL, currQuad+1,currQuad);	
														}
														
														backpatch(Truehead, currQuad);
														backpatch(Falsehead, currQuad+2);
														/*fix last JUMP*/
														tmpquad[98] = quads+currQuad-1;
														tmpquad[98]->label = currQuad+2;
														/*Threeway*/
														$4 = insertExpr(assign, ConstBool_exp(1), NULL, currQuad, boolexpr_e);
														insertQuad(jump,NULL,NULL,NULL,currQuad+2,currQuad);								
														insertQuad(assign, $4, ConstBool_exp(0), NULL, -1, boolexpr_e);
														
														LogicFlag = 0;
														Balls=0;
														
														insertQuad(if_eq,NULL,$4,ConstBool_exp(1), currQuad+2, currQuad);
														tmpquad[Qindex++] = insertQuad(jump,NULL,NULL,NULL,-1,currQuad);
												};
							
							  
whilestmt	: WHILE LEFT_PARENTHES
					{loopstart[loopindex++]=currQuad;
					LogicFlag = 1;
					}
					expr RIGHT_PARENTHES
							     {
									if (!Balls){
															/*initialize the expression's if and jump with the right labels*/
															/*ifshit*/
															insertQuad(if_eq,$4, ConstBool_exp(1), NULL, currQuad+2,currQuad);
															/*jump*/
															insertQuad(jump,NULL,NULL,NULL, currQuad+1,currQuad);	
									}
								 
									backpatch(Truehead, currQuad);
									backpatch(Falsehead, currQuad+2);
									/*fix last JUMP*/
									tmpquad[98] = quads+currQuad-1;
									tmpquad[98]->label = currQuad+2;
									/*Threeway*/
									$4 = insertExpr(assign, ConstBool_exp(1), NULL, currQuad, boolexpr_e);
									insertQuad(jump,NULL,NULL,NULL,currQuad+2,currQuad);								
									insertQuad(assign, $4, ConstBool_exp(0), NULL, -1, boolexpr_e);
								
									LogicFlag = 0;
									Balls=0;
								 		 
									insertQuad(if_eq,NULL,$4,ConstBool_exp(1), currQuad+2, currQuad);
									tmpquad[Qindex++]=insertQuad(jump,NULL,NULL,NULL,-1,currQuad);							      
							     }stmt
									{
										insertQuad(jump,NULL,NULL,NULL,loopstart[--loopindex],currQuad);
										tmpquad[--Qindex]->label=currQuad;
										backpatch(BreakHead, currQuad);
										backpatch(ContinueHead, loopstart[loopindex]);
										BreakHead=CreateIntList(-666,BreakHead);
										ContinueHead=CreateIntList(-666,ContinueHead);
										
										$$ = $4;
										fprintf(yyout,"whilestmt ==> while (expr) stmt\n");
								    }	    
			;
			
forstmt	: FOR LEFT_PARENTHES elist SEMICOLON  {  LogicFlag = 1;
												forstart=currQuad; } 
						 expr SEMICOLON
							        {
									
										if (!Balls){
															/*initialize the expression's if and jump with the right labels*/
															/*ifshit*/
															insertQuad(if_eq,$6, ConstBool_exp(1), NULL, currQuad+2,currQuad);
															/*jump*/
															insertQuad(jump,NULL,NULL,NULL, currQuad+1,currQuad);	
										}
								
										backpatch(Truehead, currQuad);
										backpatch(Falsehead, currQuad+2);
										
										/*fix last JUMP*/
										tmpquad[98] = quads+currQuad-1;
										tmpquad[98]->label = currQuad+2;
										/*Threeway*/
										$6 = insertExpr(assign, ConstBool_exp(1), NULL, currQuad, boolexpr_e);
										insertQuad(jump,NULL,NULL,NULL,currQuad+2,currQuad);																			
										insertQuad(assign, $6, ConstBool_exp(0), NULL, -1, boolexpr_e);
								
										LogicFlag = 0;
										Balls=0;
										fortmpquad=insertQuad(if_eq,NULL,$6,ConstBool_exp(1), -1, currQuad); 
										tmpquad[Qindex++]=insertQuad(jump,NULL,NULL,NULL,-1,currQuad);
										loopstart[loopindex++]=currQuad;
									}									
								  elist RIGHT_PARENTHES	{insertQuad(jump,NULL,NULL,NULL,forstart,currQuad);
											 fortmpquad->label=currQuad;
											} 
										    stmt{
											  insertQuad(jump,NULL,NULL,NULL,loopstart[--loopindex],currQuad);
											  tmpquad[--Qindex]->label=currQuad;
											  backpatch(BreakHead, currQuad);
											  backpatch(ContinueHead, loopstart[loopindex]);
											  BreakHead=CreateIntList(-666,BreakHead);
											  ContinueHead=CreateIntList(-666,ContinueHead);
											  
											  $$ = $6;
											  fprintf(yyout,"forstmt ==> for(elist; expr; elist) stmt\n");
											}
		;
		
returnstmt	: RETURN expr  SEMICOLON{ 
										insertQuad(ret,$2,NULL,NULL,-1,currQuad);
										fprintf(yyout,"returnstmt ==> return expr ;\n");
									}
			| RETURN SEMICOLON{
								insertQuad(ret,NULL,NULL,NULL,-1,currQuad);
								fprintf(yyout,"returnstmt ==> return ;\n");
							  }
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
	InsertToSymTable(oSymTable, ScopeArray,"print", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"input", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"objectmemberkeys", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"objecttotalmembers", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"objectcopy", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"totalarguments", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"argument", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"typeof", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"stronum", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"sqrt", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"cos", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"sin", LIBFUNC , 0, 0,-1,NULL,-1);
	
	yyparse();
	
	printf("\n\nActives of Symbol Table!!\n");
	
	SymTable_Print(oSymTable);
	
	//printf("\n\nEverything of All ScopeLists!!\n");
	
	//PrintAllScopes(ScopeArray);
	
	printf("\n\n\n\n\n");
	
	if(!ErrorFlag)
	    PrintQuads();
	return 0;
}
