%{
    #include "manage_g_action.h"
    #include "vm_def.h"

    void yyerror (char const *s);
    int yylex(void);

    unsigned short int scope = 0;

    extern FILE* yyin;
    extern char yytext[];
    extern int yylineno;

    vector <bool> isBlock;
    
    vector <string> str_statements = { "if" , "else", "while" , "for" , "funcdef" , "block"  };
    vector <string> statement_stack;

    int is_func_rule = 0; //an o kanonas poy ekteleitai einai funcution definition
    unsigned int anon_func = 0; //metraei poses anonimes synarthseis yparxoyn
    int is_member_call = 0;

    vector <ioquad_t> quads;//quad table
    vector <unsigned int> functionLocalStack;

    vector <vector<unsigned long int>> break_list;
    vector <vector<unsigned long int>> cont_list;

    // vector <vector<unsigned long int>> func_ret_list;

    extern void generate();
    extern void print_instructions();
    extern void create_binary();
    extern void print_instructions();
    extern void set_srcLines();

    extern void read_binary();

    extern vector <double> numConsts;
    extern vector <string> strConsts;
    extern vector <string> libFunctions;
    extern vector <userfunc_t> userFuncs;
    extern vector <instruction_t> instructions_table;

    int ultrex = 0;
%}
 %union{
    unsigned long unsigned_label;
    unsigned int locals_size;
    char *strVal;
    double realVal;
    struct expr *exprNode;
    struct node *symbol;
    struct type_of_call *typeOfCall;
    struct forNode *forNode;
}

%start program

/*KEYWORDS*/
%token IF ELSE WHILE FOR FUNCTION RETURN BREAK CONTINUE
%token AND NOT OR LOCAL TRUE FALSE NIL

%token '=' '+' '-' '*' '/' '%'  
%token EQ NE LT GT GE LE PLUSPLUS MINUSMINUS 
%token '{' '}' '[' ']' '(' ')' ';' ',' ':' '.'
%token COLONCOLON DOTDOT
%token SINGLE_LINE_COMMENT NESTED_COMMENT


%type <strVal> member  
%type <symbol> funcname funcprefix funcdef 
%type <typeOfCall> normcall methodcall callsuffix

%type <unsigned_label> ifprefix elseprefix whilestart whilecond N M D FUNCTION returnstmt 

%type <locals_size> funcbody

%type <exprNode> elist stmt expr term primary const call lvalue objectdef indexedelem indexed assignexpr 

%type <forNode> forprefix


%token <strVal> ID STRING
%token <realVal> INTEGER REAL 

%token number

%right '='
%left OR 
%left AND
%nonassoc EQ NE
%nonassoc GT GE LT LE
%left '+' '-'
%left '*' '/' '%'
%right NOT PLUSPLUS MINUSMINUS UMINUS
%left '.' DOTDOT
%left '[' ']'
%left '(' ')'


%%
program: stmts
        ;

stmts: stmts stmt  { 
    if( ultrex == 0 )
        resetTmpVarNameC();
    
}
       | /*empty*/
       ;


stmt:   expr ';' { $$ = $1;} 
        | ifstmt  {}
        | whilestmt {break_list.pop_back();
                cont_list.pop_back();
        }
        | forstmt {break_list.pop_back();
                cont_list.pop_back();}
        | returnstmt {
            is_correct_return();
        } 
        | BREAK ';' 
        {  
            
            is_correct_break_continue("break");
            break_list[break_list.size()-1].push_back( quads.size() );
            emit(JUMP_B , NULL, NULL, NULL , 0, yylineno);

        }
        | CONTINUE';' 
        { 
            is_correct_break_continue("continue");
            cont_list[cont_list.size()-1].push_back( quads.size() );
            emit(JUMP_C , NULL, NULL, NULL , 0, yylineno);
        }
        | block {}
        | funcdef {}
        | ';' {}
        ;

expr: assignexpr { $$ = $1;}
    | 
    expr '+' expr { 
        if ( !is_op_applicable($1) || !is_op_applicable($3) )
            cout << "Illegal expr + expr on line: " << yylineno << endl; 
        
        $$ = emit_op(ADD, $1 , $3, 0 , yylineno); 
    }
    | 
    expr '-' expr { 
        if ( !is_op_applicable($1) || !is_op_applicable($3) )
            cout << "Illegal expr - expr on line: " << yylineno << endl; 

        $$ = emit_op(SUB, $1 , $3, 0 , yylineno);
    }
    | 
    expr '*' expr { 
        if ( !is_op_applicable($1) || !is_op_applicable($3) )
            cout << "Illegal expr * expr on line: " << yylineno << endl; 
            
        $$ = emit_op(MUL, $1 , $3, 0 , yylineno);     
    }
    | 
    expr '/' expr { 
        if ( !is_op_applicable($1) || !is_op_applicable($3) )
            cout << "Illegal expr / expr on line: " << yylineno << endl; 

        $$ = emit_op(DIV, $1 , $3, 0 , yylineno); 
    }
    | expr '%' expr { 
        if ( !is_op_applicable($1) || !is_op_applicable($3) )
            cout << "Illegal expr \% expr on line: " << yylineno << endl; 

        $$ = emit_op(MOD, $1 , $3, 0 , yylineno); 
    }
    | expr GT expr {
        $$ = emit_relop(IF_GREATER ,$1 , $3, 0 , yylineno);
    }
    | expr GE expr {
        $$ = emit_relop(IF_GREATEREQ ,$1 , $3, 0 , yylineno);
    }
    | expr LT expr {
        $$ = emit_relop(IF_LESS ,$1 , $3, 0 , yylineno);
    }
    | expr LE expr {
        $$ = emit_relop(IF_LESSEQ ,$1 , $3, 0 , yylineno);
    }
    | expr EQ expr {
        $$ = emit_relop(IF_EQ ,$1 , $3, 0 , yylineno);
    }
    | expr NE expr {
        $$ = emit_relop(IF_NOTEQ ,$1 , $3, 0 , yylineno);
    }
    | expr OR D expr {
        $$ = emit_boolop(IO_OR ,$1 , $4, 0 , yylineno);
    }
    | expr AND D expr {
        $$ = emit_boolop(IO_AND ,$1 , $4, 0 , yylineno);
    }
    | term {$$ = $1;}
    ;

D: { $$ = quads.size(); }
;

term: '(' expr ')' { $$ = $2;}
    | 
    '-'expr %prec UMINUS { 
            if ( is_op_applicable($2) == false ){
                cout << "Illegal  unary minus on expr on line: " << yylineno << endl; 
            }
            $$ = newExpr(ARITHM_EXPR_E);
            $$->sym = newTmpVarName();
            emit(IO_UMINUS , $$ , $2 , NULL , 0 , yylineno);

    }
    | NOT expr {
        $$ = newExpr(BOOL_EXPR_E);
        $$->sym = newTmpVarName();
        emit(IO_NOT, $$, $2, NULL, 0, yylineno);
    }
    | 
    PLUSPLUS lvalue  {
            Manage_term__pre_post_op_lvalue( $<exprNode>2->sym , "\"++\"" + $<exprNode>2->sym->name ); 
            if($2->type == TABLE_ITEM_E ){
                $$ = emit_ifTableItem($2);
                emit(ADD, $$ , $$ , newExpr_constNum(1), 0, yylineno);
			    emit( TABLESETELEM, $2 , $2->index, $$, 0, yylineno);
            }
            else {
                emit(ADD, $2, $2 , newExpr_constNum(1), 0, yylineno);
                $$ = newExpr(ARITHM_EXPR_E);
                $$->sym = newTmpVarName();
                emit(ASSIGN, $$, $2 , NULL , 0 ,yylineno);
            }
        }
    | 
    lvalue PLUSPLUS  { 
        Manage_term__pre_post_op_lvalue( $<exprNode>1->sym , $<exprNode>1->sym->name + "\"++\"" );
        $$ = newExpr(VAR_E);
		$$->sym = newTmpVarName();
        if( $1->type == TABLE_ITEM_E ){
			expr *value = emit_ifTableItem($1);
			emit(ASSIGN, $$, value , NULL , 0 ,yylineno);
			emit(ADD, value, value , newExpr_constNum(1), 0, yylineno);
			emit( TABLESETELEM, $1, $1->index, value,  0, yylineno);
		}
		else {
			emit(ASSIGN , $$, $1 , NULL, 0, yylineno);
			emit(ADD, $1, $1 , newExpr_constNum(1), 0, yylineno);
		}

    }
    | 
    MINUSMINUS lvalue{ 
        Manage_term__pre_post_op_lvalue( $<exprNode>2->sym , "\"--\"" + $<exprNode>2->sym->name ); 
        if($2->type == TABLE_ITEM_E ){
                $$ = emit_ifTableItem($2);
                emit(SUB, $$ , $$ , newExpr_constNum(1), 0, yylineno);
			    emit( TABLESETELEM, $2, $2->index, $$, 0, yylineno);
        }
        else {
            emit(SUB, $2, $2 , newExpr_constNum(1), 0, yylineno);
            $$ = newExpr(ARITHM_EXPR_E);
            $$->sym = newTmpVarName();
            emit(ASSIGN, $$, $2 , NULL , 0 ,yylineno);
        }
    
    }
    | 
    lvalue MINUSMINUS{ 
        Manage_term__pre_post_op_lvalue( $<exprNode>1->sym , $<exprNode>1->sym->name + "\"--\"" );
        $$ = newExpr(VAR_E);
		$$->sym = newTmpVarName();
        if( $1->type == TABLE_ITEM_E ){
			expr *value = emit_ifTableItem($1);
			emit(ASSIGN, $$, value , NULL , 0 ,yylineno);
			emit(SUB, value, value , newExpr_constNum(1), 0, yylineno);
			emit( TABLESETELEM, $1, $1->index, value, 0, yylineno);
		}
		else {
			emit(ASSIGN , $$, $1 , NULL, 0, yylineno);
			emit(SUB, $1, $1 , newExpr_constNum(1), 0, yylineno);
		}
    
    }
    | primary { $$ = $1;}
    ;

assignexpr: lvalue '=' expr { 
                
                Manage_assignexpr__lvalue_assignment_expr($<exprNode>1->sym);
                if( $<exprNode>1->type == TABLE_ITEM_E ){
                    emit(TABLESETELEM , $<exprNode>1, $<exprNode>1->index, $<exprNode>3, 0 , yylineno );
                    $<exprNode>$ = emit_ifTableItem($<exprNode>1);
                    $<exprNode>$->type = ASSIGN_EXPR_E;
                }
                else{
                    emit(ASSIGN , $<exprNode>1 , $<exprNode>3 , NULL , 0 , yylineno );
                    $<exprNode>$ =  newExpr(ASSIGN_EXPR_E);

                    $<exprNode>$->sym = newTmpVarName();
                    emit( ASSIGN ,  $<exprNode>$ , $<exprNode>1 , NULL , 0 , yylineno );  
                }
            }
          ;

 
primary: lvalue { $$ = emit_ifTableItem($<exprNode>1);  }
        | call {}
        | objectdef {}
        | 
        '(' funcdef ')' {
            $$ = lvalueExpr($2);
        }
        | const {   $$ = $1; 
                    // print_const_from_type( *($$) );
                }
        ;

lvalue:   ID            { $<exprNode>$ = Manage_lvalue__ID($1); DEBUG_PRINTS_OFFSET("lvalue->ID");} 
        | LOCAL ID      { $<exprNode>$ = Manage_lvalue__LOCAL_ID($2);  DEBUG_PRINTS_OFFSET("lvalue -> local id");}
        | COLONCOLON ID { $<exprNode>$ = Manage_lvalue__COLONCOLON_ID($2); }
        | member   {}
        ;

member: lvalue'.'ID {// To ID einai strVal
            $<exprNode>$ = member_item( $<exprNode>1 , $3 );
        }
        | lvalue '[' expr ']' {

            $<exprNode>1 = emit_ifTableItem($<exprNode>1);
            $<exprNode>$ = newExpr(TABLE_ITEM_E);
            $<exprNode>$->sym = $<exprNode>1->sym;
            $<exprNode>$->index = $<exprNode>3; // The index is the expression.
        
        }
        | call'.'ID {is_member_call++;}
        | call '[' expr ']' {}
        ;

call: call '(' elist ')' {
            $$ = make_call( $1 , $3 );
        }
        | 
        lvalue callsuffix {

            if( $2->is_method == true ){
                expr *self = $1;
                $1 = emit_ifTableItem( member_item( self , $2->name ) );
                $2->elist->insert( $2->elist->begin() , *self ); 
            }
            expr *tmp = newExpr(VAR_E);//wrap type_of_call_type_to expr to call make_call with second arg expr
        
            tmp->elist = $2->elist;

            $$ = make_call($1 , tmp );

            if( is_lib_func_2($1->sym->name) == true ){
                $1->type = LIB_FUNC_E;
            }
        }
        | 
        '(' funcdef ')' '(' elist ')' {
            expr *func = newExpr(USER_FUNC_E);
            func->sym = $2;
            $$ = make_call(func , $5 );
        }
        ;
 
callsuffix: normcall {
                $$ = $1;
            }
            | methodcall {
                $$ = $1;
            }
            ;

normcall: '(' elist ')' {
    type_of_call_t* typeOfCall=new type_of_call_t;
    if($2->elist==NULL){
        typeOfCall->elist=new vector<expr>();
    }else{
        typeOfCall->elist = $2->elist;
    }
    
    typeOfCall->is_method = false;
    typeOfCall->name = NULL;
    $$=typeOfCall;
}
        ;

methodcall: DOTDOT ID '(' elist ')' {/*equivalent to lvalue.id(lvalue, elist)*/ 
    // cout << "Debug:methodCall -> ID (edo): " << $2 << endl; 
    
    if( $$ == NULL)
        $$ = new type_of_call_t;

    $$->elist = new vector<expr>();
    if( $4->elist != NULL ){
        $$->elist = $4->elist;
    }
    $$->is_method = true;
    $$->name = strdup($2);
    
    // for( size_t i = 0; i < ($$)->elist->size() ; i++ ){
    //     cout << "\tmethod call [ " << i  << "] " <<  ($$)->elist->at(i).num_const << endl;
    // }
} 
            ;

elist:      expr  {
                // cout << "elist->expr: " << $1->num_const << endl;
                $$->elist = new vector<expr>();
                $$->elist->push_back(*$1);

                // cout << "elist 2 : " << ($$)->elist->size() "elist 3 : " << ($$)->elist->at(0).num_const << endl;
            }
            | elist ',' expr{
                $1->elist->push_back(*$3);
            }
            | {
                $$ = newExpr(NEW_TABLE_E);
                $$->elist = NULL;
            }
            ;

objectdef:  '['{ultrex++;} elist ']' {
                ultrex--;
               expr *table = newExpr(NEW_TABLE_E);
                table->sym = newTmpVarName();
                emit(TABLECREATE , table , NULL  , NULL , 0 , yylineno );
                
                if( ($3)->elist != NULL  ){
                    for( unsigned i = 0; i < ($3)->elist->size(); i++ ){
                        emit( TABLESETELEM , table , newExpr_constNum(i) , &($3->elist->at(i)) , 0 , yylineno );
                    }
                }

                $$ = table;
               
            }
            |
            '[' indexed ']' {
                expr *t = newExpr(NEW_TABLE_E);
                t->sym = newTmpVarName();
                emit(TABLECREATE , t , NULL , NULL , 0 , yylineno );

                for( unsigned i = 0; i < $2->ilist->size(); ++i ){
                    emit(TABLESETELEM , t , &($2->ilist->at(i).first) , &($2->ilist->at(i).second), 0 , yylineno );//TODO: check
                }

                $$ = t;
            } 
            ;

indexed:    indexedelem {
                // ultrex = 1;
                expr *e = newExpr(TMP_E);//tmp
                e->ilist = new vector<pair<expr,expr>>();
                e->ilist->push_back( *($1->ipair) );
                
                $$ = e;
            }
            | indexed ',' indexedelem{
                // ultrex = 1;
                $1->ilist->push_back( *($3->ipair) );    
                // for ( unsigned i =0; i < $1->ilist->size(); ++i ){
                //     cout << "\t indexed: [" << i << "]: " <<  ($1)->ilist->at(i).first.str_const << endl;
                //     cout << "\t indexed: [" << i << "] " << ($1)->ilist->at(i).second.num_const << endl;
                // }
            }
            ;



indexedelem: '{'{ultrex++;} expr ':' expr '}'{
    expr *e = newExpr(TMP_E);//tmp
    e->ipair = new pair<expr,expr>();
    e->ipair->first = *$3;
    e->ipair->second = *$5;
    // cout << "indexedelem $2: " <<  (*(e->ipair)).first.str_const <<  (*(e->ipair)).second.num_const << endl;
    $$ = e;
    ultrex--;
}
            ;

block:      '{'{    Manage__open_block(); 
                    // cout << "~~~~~~~~~~~" << currScopeOffset() << endl;
               } 
            stmts 
            '}'{ Manage__close_block(); 

            } 
            ;

funcname: ID { 
                node_t *symbol = Manage_ID_OR_NOT__ID($1); 
                if(symbol == NULL ){
                    cout << "lib func check me!" << endl;
                }
                else{
                    $$ = symbol;
                }

                DEBUG_PRINTS_OFFSET("funcname -> id");
            } 
            |  { $$ = Manage_ID_OR_NOT__Anonymous();
                DEBUG_PRINTS_OFFSET("funcname -> anon");
             }
          ;

funcprefix: FUNCTION funcname {  
                is_func_rule++; 
                isBlock.push_back(false);
                statement_stack.push_back("funcdef");
                statement_stack.push_back("block");   

                $$ = $2;
                $$->iaddress = quads.size();
                $$->func_j = quads.size(); 
                emit(JUMP , NULL , NULL ,NULL , 0 , yylineno);
                emit( FUNCSTART , NULL , lvalueExpr($$) , NULL , 0 , yylineno );
                functionLocalStack.push_back(currScopeOffset());
                DEBUG_PRINTS_OFFSET("funcname -> funcpprefix 1");
                enterScopeSpace();
                resetFormalArgsOffset();
                
                // func_ret_list.push_back(vector<unsigned long int>());


                DEBUG_PRINTS_OFFSET("funcname -> funcpprefix 2");
            } 
           ;

funcargs: '(' {scope++; } idlist ')'{scope--; restoreCurrScopeOffset(0);}
            {   
                enterScopeSpace();
                resetFuncLocalOffset();
                
                DEBUG_PRINTS_OFFSET("funcname -> funcargs");
            }
        ;

funcbody: block {
                // cout << "~~~~OUTSIDE BLOCK~~~~" << currScopeOffset() << endl;
                $$ = currScopeOffset();
                clear_statement_stack();
                exitScopeSpace();
                DEBUG_PRINTS_OFFSET("funcname -> funcbody");
            }
        ;

funcdef: funcprefix funcargs funcbody {
            exitScopeSpace();
            $1->total_locals = $3;
            // cout <<"~~~~~~~~~~~" << $1->total_locals << endl;
            restoreCurrScopeOffset(functionLocalStack.back() );
            functionLocalStack.pop_back();
            $$ = $1;
            emit( FUNCEND , NULL , lvalueExpr($1) , NULL , 0 , yylineno );

            DEBUG_PRINTS_OFFSET("funcname ->  funcdef end.");

            patchLabel( $1->func_j , quads.size() );

            // for( unsigned int i = 0; i < func_ret_list[func_ret_list.size()-1].size(); ++i ){
            //     quads[ func_ret_list[func_ret_list.size()-1].at(i) ].label =  quads.size()-1;
            // }

            // func_ret_list.pop_back();

        }
       ;


const:      INTEGER {
                expr *expr =  newExpr( CONST_NUM_E );   
                expr->num_const = $1;
                $$ = expr;    
            }
            
            |STRING {   
                expr *expr =  newExpr( CONST_STRING_E );   
                expr->str_const = strdup($1);
                $$ = expr;  
                // cout << "test for lib funcs:::::::    " << expr->str_const << endl;
            } 
            |NIL {
                expr *expr =  newExpr( NIL_E ); 
                $$ = expr;  

            } 
            | TRUE {
                expr *expr =  newExpr( CONST_BOOL_E );
                expr->bool_const = 1;
                $$ = expr; 
            } 
            | FALSE{
                expr *expr =  newExpr( CONST_BOOL_E );
                expr->bool_const = 0;
                $$ = expr; 
            }
            | REAL{
                expr *expr =  newExpr( CONST_NUM_E );   
                expr->num_const = $1;
                $$ = expr;
            }
            ;

idlist:     ID  {Manage_idlist__ID($1); incrCurrScopeOffset(); DEBUG_PRINTS_OFFSET("idlist -> id");}
            | idlist ',' ID { Manage_idlist__idlist_comma_ID($3); incrCurrScopeOffset(); DEBUG_PRINTS_OFFSET("idlist -> id , [id]"); }
            |
            ;



ifprefix: IF { statement_stack.push_back("if");
               statement_stack.push_back("block");}
                        '(' expr ')' 
                        {
                            emit( IF_EQ, NULL , $4 , newExpr_constBool(1), quads.size()+2 , yylineno );//TODO:check if result must be NULL
                            $$ = quads.size();
                            emit(JUMP , NULL, NULL, NULL , 0, yylineno);
                        }
        ;

elseprefix: ELSE { statement_stack.push_back("else"); 
                statement_stack.push_back("block");
                $$=quads.size();
                emit(JUMP , NULL, NULL, NULL , 0, yylineno);
            }
        ;

ifstmt: ifprefix stmt { 
    // printf(" ifprefix stmt %d \n",yylineno); 
            
            patchLabel($1,quads.size());
        }
        
        | ifprefix stmt elseprefix stmt {clear_statement_stack();}
            { 
              patchLabel($1,$3 + 1);
              patchLabel($3,quads.size());
            }
        
        ;



whilestmt: whilestart whilecond stmt{
        
        clear_statement_stack();
        
        emit(JUMP , NULL, NULL, NULL , $1 , yylineno); 
        patchLabel( $2 , quads.size() );
        

        // patch break_"jumps"
        unsigned long int index = break_list.size()-1;
        for( unsigned long int i = 0 ; i < break_list[index].size(); ++i ){
            patchLabel( break_list[index][i] , quads.size() );
        }

        // patch cont_"jumps"
        index = cont_list.size()-1;
        for( unsigned long int i = 0 ; i < cont_list[index].size(); ++i ){
            patchLabel( cont_list[index][i] , $1 );
        }

}
;

whilestart: WHILE {
                statement_stack.push_back("while");
                statement_stack.push_back("block");

                break_list.push_back( vector<unsigned long int>() );
                cont_list.push_back( vector<unsigned long int>() );               
                $$ = quads.size();

            }
;

whilecond: '(' expr ')'{
            emit( IF_EQ, NULL , $2 , newExpr_constBool(1), quads.size()+2 , yylineno );
            $$ = quads.size();
            emit(JUMP , NULL, NULL, NULL , 0 , yylineno);
            
        }
;


N: {$$ = quads.size(); emit(JUMP , NULL, NULL, NULL , 0 , yylineno);}

M: {$$ = quads.size();}

forprefix: FOR  { 
                 statement_stack.push_back("for");
                 statement_stack.push_back("block");
                 break_list.push_back( vector<unsigned long int>() );
                 cont_list.push_back( vector<unsigned long int>() );
                }
                '(' elist ';' M expr ';' {
                    forNode *e = new forNode();
                    e->test = $6;
                    e->enter = quads.size();
                    
                    emit( IF_EQ, NULL , $7 , newExpr_constBool(1), 0 , yylineno );
                    $$=e;
                }

forstmt:    forprefix N elist ')' N stmt {clear_statement_stack();} N {
                patchLabel($1->enter,$5+1);
                patchLabel($2,quads.size());
                patchLabel($5,$1->test);
                patchLabel($8,$2+1);
                

                unsigned long int index = break_list.size()-1;
                for( unsigned long int i = 0 ; i < break_list[index].size(); ++i ){
                    patchLabel( break_list[index][i] , quads.size() );
                }

                // patch cont_"jumps"
                index = cont_list.size()-1;
                for( unsigned long int i = 0 ; i < cont_list[index].size(); ++i ){
                    patchLabel( cont_list[index][i] , $2+1 );
                }
              
            }   

returnstmt: RETURN expr ';' { 
                emit( RET , NULL , $2 , NULL, 0 , yylineno);
                //func_ret_list[func_ret_list.size()-1].push_back(quads.size());
               // emit( JUMP , NULL , NULL , NULL, 0 , yylineno);


            }
            | RETURN ';'    { 
                emit( RET , NULL , NULL , NULL, 0 , yylineno);
               // func_ret_list[func_ret_list.size()-1].push_back(quads.size());
                //emit( JUMP , NULL , NULL , NULL, 0 , yylineno);
            }
            ;

%%

void yyerror(char const *s)
{
	fflush(stdout);
	fprintf(stderr , "yyerror! line:[%d] [%s]\n" ,yylineno, s );
}

extern unsigned int programVarOffset;

int main(int argc, char *argv[])
{
    if(argc>1){
        if(!(yyin=fopen(argv[1],"r"))){
            fprintf(stderr, "Cannot read file : %s\n",argv[1]);
            return 1;            
        }
    }
    else{
        yyin = stdin;
    }
    init_SymTable();
    yyparse();          
    printf( "\x1B[34m""\n###########################################     Symbol table:     ###########################################\n\n""\x1B[0m"  );
    print_SymTable();
    printQuads();

    generate();
    set_srcLines();
    print_instructions( instructions_table ,numConsts, strConsts , libFunctions , userFuncs);
    create_binary();

    // read_binary(); 
    return 0;
}