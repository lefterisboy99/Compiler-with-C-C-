%{
    #include "symbolTable.h"

    int yyerror (string yaccProvidedMessage){ return 0; }
    int yylex(void);

    extern int yylineno;
	extern char * yyval;
	extern char * yytext;
	extern FILE * yyin;
	extern FILE * yyout;

    vector <int> break_vector;
    vector <int> continue_vector;

    int break_counter = 0;
    int continue_counter = 0;

    unsigned char loop_intersect = 0 ;
    unsigned char break_intersect = 1 ;
    vector <int>  valid_jumps;
    vector <int>  false_jumps;
    vector <vector<int>> repach;
    vector <vector <int>> continue_quads;
    vector <vector <int>>  break_quads;
    vector <int>  loop_start;
    vector <int>  loop_end;
    vector <int>  false_quads;
    vector <int>  operation_list;


    int SCOPE = 0;
    string GLOBAL_ID;
    bool isLogic = 0;
    bool isrelop = 0;
    bool isAnd   = 0;
    bool isnt    = 0;

    vector <vector <int>> backup_truelists;
    vector <vector <int>> backup_falselists;


    vector<SymbolTableEntry> FORMAL_ARGUMENTS; 
%}

%start program

%union {
    int                         intValue;
    char*                       stringValue;
    double                      realValue;
    bool                        boolValue;
    void*                       nilValue;
    struct expr*                exprValue;
    struct call*                callValue;
    struct SymbolTableEntry*    symbValue;
    unsigned                    unsdValue;
    struct forJump*             forjValue;
    
}

%token ASSIGN
%token <stringValue> STRING
%token <intValue> INTEGER
%token <realValue> REAL
%token LOCAL
%token <nilValue> NIL
%token <stringValue> ID
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
%token <boolValue> TRUE FALSE
%token MINUS
%token EQUAL 
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
%token UNDEFINED

%type <exprValue> lvalue
%type <exprValue> member
%type <exprValue> const
%type <exprValue> expr
%type <exprValue> term
%type <exprValue> assignexpr
%type <callValue> callsuffix
%type <callValue> normcall
%type <callValue> methodcall
%type <exprValue> call
%type <symbValue> funcdef
%type <exprValue> elist
%type <exprValue> commaexpr
%type <exprValue> objectdef
%type <exprValue> indexed
%type <exprValue> indexedelem
%type <exprValue> commaindexedelem
%type <exprValue> primary
%type <unsdValue> ifprefix
%type <unsdValue> elseprefix
%type <unsdValue> whilecond
%type <unsdValue> whilestart
%type <forjValue> forprefix
%type <unsdValue> M
%type <unsdValue> N
%type <unsdValue> Q
%type <exprValue> stmt
%type <exprValue> stmts
%type <exprValue> program

%right      ASSIGN
%left       OR
%left       AND
%nonassoc   EQUAL DIFFER
%nonassoc   BIGGER BIGGER_EQ LESS LESS_EQ
%left       PLUS MINUS
%left       MULTIPLY DIV MOD
%right      NOT PLUSPLUS MINUSMINUS UMINUS
%left       DOT DOUBLE_DOT
%left       START_BRACKET END_BRACKET
%left       START_PARENTHESIS END_PARENTHESIS

%%

program:    stmts
            {
                cout << "program -> stmt*" << endl;
            }
            ;

stmts:      stmt stmts
            {
                cout << "stmts -> stmt stmts" << endl;
            }
            |
            {
                cout << "stmts -> " << endl;
                

                /*
                //correct repeated jumps
                if(loop_counter == 0){

                    int empty_while = 0;
                    for(int i=0; i<false_jumps.size(); i++){
                        if(!false_jumps.at(i))
                            empty_while++;
                    }
                    empty_while = (empty_while%2) ? 0 : 1;

                    vector<vector<int>> repach;
                    for(int i=0; i<false_jumps.size(); i++){
                        
                        if(!false_jumps.at(i)){
                            vector<int> v;
                            repach.push_back(v);
                        }else{
                            repach.back().push_back(false_jumps.at(i));
                        }
                    }
                    for(int i=0; i<repach.size() - empty_while; i++){
                        cout << endl << valid_jumps.at(i) << " : ";
                        for(int j=0; j<repach.at(i).size(); j++){

                            quads.at(repach.at(i).at(j) - 1).label = quads.at(valid_jumps.at(i)-1).label;
                        }
                    }

                    cout << endl;
                }*/
            }
            ;

stmt:       expr SEMICOLON
            {
                cout << "stmt -> expr;" << endl;

                lwarning = false;
                isnt     = false;

                if(isLogic) {

                    $expr->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);

                    isLogic = false;
                    struct expr* e = new_expr(constbool_e);
                    e->boolConst = 1;
                    emit(assign, e, nullptr, $expr, 0, yylineno);

                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                    e = new_expr(constbool_e);
                    e->boolConst = 0;
                    emit(assign, e, nullptr, $expr, 0, yylineno);

                    backpatch($expr->truelist, nextquadlabel() - 3);
                    backpatch($expr->falselist, nextquadlabel() - 1);
                
                }
                tempcounter = 0;
            }
            |ifstmt { 
                cout << "stmt -> ifstmt" << endl; 
            }
            |whilestmt  { cout << "stmt -> whilestmt" << endl; }
            |forstmt    { cout << "stmt -> forstmt" << endl; }
            |returnstmt { cout << "stmt -> returnstmt" << endl; }
            |BREAK
            {
                cout << "stmt -> break" << endl;
                if(break_quads.size()>0)
                    break_quads.at(break_quads.size()-1).push_back(nextquadlabel());
                break_counter++;

                //loop_counter--;
                if(loop_counter <= 0){
                    cout << "\033[1;31m" <<
                        "Can't use break here at line "<< yylineno <<
                        "\033[0m" << endl;
                        loop_counter=0;
                }

                
                
                emit(jump,nullptr, nullptr, nullptr, 0, yylineno);

            } 
            SEMICOLON
            { 
                if(loop_intersect){
                    loop_intersect = 0;
                    false_jumps.push_back(0);
                    
                }
                false_jumps.push_back(nextquadlabel() - 1);
                break_vector.push_back(nextquadlabel() - 2);
            }
            |CONTINUE
            {
                cout << "stmt -> continue" << endl;
                if(continue_quads.size()>0)
                    continue_quads.at(continue_quads.size()-1).push_back(nextquadlabel());
                continue_counter++;

                if(loop_counter == 0){
                    cout << "\033[1;31m" << 
                        "Can't use continue outside of loops at line "<< yylineno <<
                        "\033[0m" << endl;
                }

                
                
                emit(jump,nullptr, nullptr, nullptr, 0, yylineno);
                
            } 
            SEMICOLON 
            { 
                cout << "program -> stmt*" << endl;

                continue_vector.push_back(nextquadlabel() - 2);
            }
            |block  { cout << "stmt -> block" << endl; }
            |funcdef    { cout << "stmt -> funcdef" << endl; }
            |SEMICOLON  { cout << "stmt -> ;" << endl; }
            ;

expr:       assignexpr  
            { 
                cout << "expr -> assignexpr" << endl;
                $$ = $1;
                
            }
            |expr PLUS expr         
            { 
                cout << "expr -> expr + expr" << endl;
                $$ = new_expr(arithexpr_e);
                $$->sym = assign_temp($1,$3, SCOPE, yylineno, FUNC_DEPTH);

                if($1->type == constnum_e && $3->type == constnum_e){
                        $$->type = constnum_e;
                }
        
                operation_list.push_back(nextquadlabel());
                emit(add, $1, $3, $$, 0 ,yylineno);
            }
            |expr MINUS expr
            {
                cout << "expr -> expr - expr" << endl;
                $$ = new_expr(arithexpr_e);
                $$->sym = assign_temp($1,$3, SCOPE, yylineno, FUNC_DEPTH);

                if($1->type == constnum_e && $3->type == constnum_e){
                        $$->type = constnum_e;
                }
                emit(sub, $1, $3, $$, 0 ,yylineno);
            }
            |expr MULTIPLY expr     
            {
                cout << "expr -> expr * expr" << endl;
                $$ = new_expr(arithexpr_e);
                $$->sym = assign_temp($1,$3, SCOPE, yylineno, FUNC_DEPTH);

                if($1->type == constnum_e && $3->type == constnum_e){
                        $$->type = constnum_e;
                }
                emit(mul, $1, $3, $$, 0 ,yylineno);
            }
            |expr DIV expr
            {
                cout << "expr -> expr / expr" << endl;
                $$ = new_expr(arithexpr_e);
                $$->sym = assign_temp($1,$3, SCOPE, yylineno, FUNC_DEPTH);

                if($1->type == constnum_e && $3->type == constnum_e){
                        $$->type = constnum_e;
                }
                emit(_div, $1, $3, $$, 0 ,yylineno);
            }
            |expr MOD expr
            { 
                cout << "expr -> expr % expr" << endl;
                $$ = new_expr(arithexpr_e);
                $$->sym = assign_temp($1,$3, SCOPE, yylineno, FUNC_DEPTH);

                if($1->type == constnum_e && $3->type == constnum_e){
                        $$->type = constnum_e;
                }
                emit(mod, $1, $3, $$, 0 ,yylineno);
            }
            |expr BIGGER expr 
            {
                cout << "expr -> expr > expr" << endl;

                if(isnt) {
                    expr *e = new_expr(constbool_e);
                    e->boolConst = 1;
                    emit(assign, e, nullptr, $$, 0, yylineno);

                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                    e = new_expr(constbool_e);
                    e->boolConst = 0;
                    emit(assign, e, nullptr, $$, 0, yylineno);
                    backpatch($1->truelist, nextquadlabel() - 3);
                    backpatch($1->falselist, nextquadlabel() - 1);

                    isnt = false;
                }

                isLogic = true;
                isrelop = true;


                $$ = new_expr(boolexpr_e);
                //$$->sym = assign_temp($1, $3, SCOPE, yylineno, FUNC_DEPTH);

                if($1->type == constnum_e && $3->type == constnum_e){
                    $$->type = constbool_e;
                }

                $$->truelist.push_back(nextquadlabel());
                $$->falselist.push_back(nextquadlabel()+1);
                emit(if_greater, $1 , $3, nullptr, nextquadlabel() + 2, yylineno);  
                emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 3, yylineno);

            }
            |expr BIGGER_EQ expr
            { 
                cout << "expr -> expr >= expr" << endl;

                if(isnt) {
                    expr *e = new_expr(constbool_e);
                    e->boolConst = 1;
                    emit(assign, e, nullptr, $$, 0, yylineno);

                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                    e = new_expr(constbool_e);
                    e->boolConst = 0;
                    emit(assign, e, nullptr, $$, 0, yylineno);
                    backpatch($1->truelist, nextquadlabel() - 3);
                    backpatch($1->falselist, nextquadlabel() - 1);

                    isnt = false;
                }

                $$ = new_expr(boolexpr_e);
                //$$->sym = assign_temp($1, $3, SCOPE, yylineno, FUNC_DEPTH);
                isLogic = true;               
                isrelop = true;
                

                if($1->type == constnum_e && $3->type == constnum_e){
                    $$->type = constbool_e;
                }
                
                $$->truelist.push_back(nextquadlabel());
                emit(if_greatereq, $1 , $3, nullptr, nextquadlabel() + 2, yylineno);
                
                $$->falselist.push_back(nextquadlabel());
                emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 3, yylineno);
            }
            |expr LESS expr
            {
                cout << "expr -> expr < expr" << endl; 

                if(isnt) {
                    expr *e = new_expr(constbool_e);
                    e->boolConst = 1;
                    emit(assign, e, nullptr, $$, 0, yylineno);

                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                    e = new_expr(constbool_e);
                    e->boolConst = 0;
                    emit(assign, e, nullptr, $$, 0, yylineno);
                    backpatch($1->truelist, nextquadlabel() - 3);
                    backpatch($1->falselist, nextquadlabel() - 1);

                    isnt = false;
                }

                $$ = new_expr(boolexpr_e);
                //$$->sym = assign_temp($1, $3, SCOPE, yylineno, FUNC_DEPTH);
                isLogic = true;
                isrelop = true;

                if($1->type == constnum_e && $3->type == constnum_e){
                    $$->type = constbool_e;
                }
                
                $$->truelist.push_back(nextquadlabel());
                emit(if_less, $1 , $3, nullptr, nextquadlabel() + 2, yylineno);
                
                $$->falselist.push_back(nextquadlabel());
                emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 3, yylineno);
            }
            |expr LESS_EQ expr
            {
                cout << "expr -> expr <= expr" << endl; 

                if(isnt) {

                    expr *e = new_expr(constbool_e);
                    e->boolConst = 1;
                    emit(assign, e, nullptr, $$, 0, yylineno);

                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                    e = new_expr(constbool_e);
                    e->boolConst = 0;
                    emit(assign, e, nullptr, $$, 0, yylineno);
                    backpatch($1->truelist, nextquadlabel() - 3);
                    backpatch($1->falselist, nextquadlabel() - 1);

                    isnt = false;
                }

                $$ = new_expr(boolexpr_e);
                //$$->sym = assign_temp($1, $3, SCOPE, yylineno, FUNC_DEPTH);
                isLogic = true;
                isrelop = true;
               
                if($1->type == constnum_e && $3->type == constnum_e){
                    $$->type = constbool_e;
                }
                
                $$->truelist.push_back(nextquadlabel());
                emit(if_lesseq, $1 , $3, nullptr, nextquadlabel() + 2, yylineno);
                
                $$->falselist.push_back(nextquadlabel());
                emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 3, yylineno);

            }
            |expr EQUAL expr
            {
                cout << "expr -> expr == expr" << endl;

                if(isnt) {
                    expr *e = new_expr(constbool_e);
                    e->boolConst = 1;
                    emit(assign, e, nullptr, $$, 0, yylineno);

                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                    e = new_expr(constbool_e);
                    e->boolConst = 0;
                    emit(assign, e, nullptr, $$, 0, yylineno);
                    backpatch($1->truelist, nextquadlabel() - 3);
                    backpatch($1->falselist, nextquadlabel() - 1);

                    isnt = false;
                }

                $$ = new_expr(boolexpr_e);
                //$$->sym = assign_temp($1, $3, SCOPE, yylineno, FUNC_DEPTH);
                isLogic = true;
                isrelop = true;
                
                if($1->type == $3->type){
                    $$->type = constbool_e;
                }
                
                $$->truelist.push_back(nextquadlabel());
                emit(if_eq, $1 , $3, nullptr, nextquadlabel() + 2, yylineno);
                
                $$->falselist.push_back(nextquadlabel());
                emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 3, yylineno);
            }
            |expr DIFFER expr
            { 
                cout << "expr -> expr != expr" << endl; 

                if(isnt) {

                    expr *e = new_expr(constbool_e);
                    e->boolConst = 1;
                    emit(assign, e, nullptr, $$, 0, yylineno);

                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                    e = new_expr(constbool_e);
                    e->boolConst = 0;
                    emit(assign, e, nullptr, $$, 0, yylineno);
                    backpatch($1->truelist, nextquadlabel() - 3);
                    backpatch($1->falselist, nextquadlabel() - 1);

                    isnt = false;
                }

                $$ = new_expr(boolexpr_e);
                //$$->sym = assign_temp($1, $3, SCOPE, yylineno, FUNC_DEPTH);
                isLogic = true;
                isrelop=true;

                if($1->type == $3->type){
                    $$->type = constbool_e;
                }
                
                $$->truelist.push_back(nextquadlabel());
                emit(if_noteq, $1 , $3, nullptr, nextquadlabel() + 2, yylineno);
                
                $$->falselist.push_back(nextquadlabel());
                emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 3, yylineno);
            }
            |expr AND{
                if($1->truelist.empty()){
                    $1->truelist.push_back(nextquadlabel());
                    expr* e=new_expr(constbool_e);
                    e->boolConst=1;
                    emit(if_eq, $1, e,nullptr, nextquadlabel() + 2, yylineno);
                    $1->falselist.push_back(nextquadlabel());
                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);
                }
            } Q expr
            { 
                cout << "expr -> expr && expr" << endl; 
                $$ = new_expr(boolexpr_e);
                isLogic = true;
                $$->sym = assign_temp($1,$5, SCOPE, yylineno, FUNC_DEPTH);
                if($1->type == constbool_e && $5->type == constbool_e){
                    $$->type = constbool_e;
                }

                if ($5->truelist.empty()) {
                    $5->truelist.push_back(nextquadlabel());
                    expr* e=new_expr(constbool_e);
                    e->boolConst=1;
                    emit(if_eq, $5, e,nullptr, nextquadlabel() + 2, yylineno);
                    $5->falselist.push_back(nextquadlabel());
                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);
                }

                
                backpatch($1->truelist, $Q);
                
                for(int i=0; i<$1->falselist.size(); i++){
                    $$->falselist.push_back($1->falselist.at(i));
                }
                for(int i=0; i<$5->falselist.size(); i++){
                    $$->falselist.push_back($5->falselist.at(i));
                }

                $$->truelist = $5->truelist;
            }
            |expr OR{
                if($1->truelist.empty()){
                    $1->truelist.push_back(nextquadlabel());
                    expr* e=new_expr(constbool_e);
                    e->boolConst=1;
                    emit(if_eq, $1, e,nullptr, nextquadlabel() + 2, yylineno);
                    $1->falselist.push_back(nextquadlabel());
                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);
                }
            } Q expr
            { 
                cout << "expr -> expr || expr" << endl;
                $$ = new_expr(boolexpr_e);
                $$->sym = assign_temp($1,$5, SCOPE, yylineno, FUNC_DEPTH);
                isLogic=true;
                if($1->type == constbool_e && $5->type == constbool_e){
                    $$->type = constbool_e;
                }

                if ($5->truelist.empty()) {
                    $5->truelist.push_back(nextquadlabel());
                    expr* e=new_expr(constbool_e);
                    e->boolConst=1;
                    emit(if_eq, $5, e,nullptr, nextquadlabel() + 2, yylineno);
                    $5->falselist.push_back(nextquadlabel());
                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);
                }

                

                backpatch($1->falselist, $Q);

                
                for(int i=0; i<$1->truelist.size(); i++){
                    $$->truelist.push_back($1->truelist.at(i));
                }
                for(int i=0; i<$5->truelist.size(); i++){
                    $$->truelist.push_back($5->truelist.at(i));
                }

                $$->falselist = $5->falselist;
 
            }
            |term
            {
                cout << "expr -> term" << endl; 
                $expr = $term;
            }
            ;

Q:          
            {
                $Q = nextquadlabel();
            };

term:       START_PARENTHESIS expr END_PARENTHESIS  
            {
                cout << "term -> (expr)" << endl;
                $term = $expr;
            }
            |primary    
            {
                cout << "term -> primary" << endl; 
                $term = $primary;
            }
            |MINUS expr %prec UMINUS    
            {
                cout << "term -> -expr" << endl; 

                check_arith($expr, "Cannot use uminus operator to a not aritmentic expression ", yylineno);
                $term = new_expr(arithexpr_e);
                $term->sym = istempexpr($expr) ? $expr->sym : newtemp(SCOPE, yylineno, FUNC_DEPTH);
                emit(uminus,$expr, nullptr, $term, 0, yylineno);
            }
            |PLUSPLUS
            lvalue
            {
                cout << "term -> ++lvalue" << endl;

                SymbolTableEntry *entry_ptr = Lookup(create_entry(GLOBAL_ID,0,0,LLOCAL,FUNC_DEPTH), SCOPE);
                if(isFunction(*entry_ptr)){
                    cout << "\033[1;31m" << 
                        "Function used as lvalue (++function)  at line "<< yylineno <<
                        "\033[0m" << endl;
                }

                check_arith($lvalue, "Cannot use pre increment operator to a not aritmentic expression ", yylineno);
                if ($lvalue->type == tableitem_e) {

                    $term = emit_iftableitem($lvalue, SCOPE, yylineno, FUNC_DEPTH);

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(add, $term, e, $term, 0, yylineno);
                    emit(tablesetelem, $lvalue, $lvalue->index, $term, 0, yylineno);
                }
                else {

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(add, $lvalue, e, $lvalue, 0, yylineno);
                    $term = new_expr(arithexpr_e);
                    $term->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                    emit(assign, $lvalue, nullptr, $term, 0, yylineno);
                }
            }

            |lvalue
            {
                SymbolTableEntry *entry_ptr = Lookup(create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH), SCOPE);
                if(isFunction(*entry_ptr)){
                    cout << "\033[1;31m" << 
                        "Function used as lvalue (function++)  at line "<< yylineno <<
                        "\033[0m" << endl;
                }
            } 
            PLUSPLUS    
            {
                cout << "term -> lvalue++" << endl;

                check_arith($lvalue, "Cannot use post increment operator to a not aritmentic expression ", yylineno);
                $term = new_expr(var_e);
                $term->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);

                if ($lvalue->type == tableitem_e) {

                    expr* val = emit_iftableitem($lvalue, SCOPE, yylineno, FUNC_DEPTH);
                    emit(assign, val, NULL, $term, 0, yylineno);

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(add, val, e, val,  0, yylineno);
                    emit(tablesetelem, $lvalue, $lvalue->index, val, 0, yylineno);
                }
                else {
                    emit(assign, $lvalue, nullptr, $term, 0, yylineno);

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(add, $lvalue, e, $lvalue, 0, yylineno);
                }
            }
            
            |MINUSMINUS
            lvalue
            {
                cout << "term -> --lvalue" << endl;

                SymbolTableEntry *entry_ptr = Lookup(create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH), SCOPE);
                if(isFunction(*entry_ptr)){
                    cout << "\033[1;31m" << 
                        "Function used as lvalue (--function)  at line "<< yylineno <<
                        "\033[0m" << endl;
                }

                check_arith($lvalue, "Cannot use pre decrement operator to a not aritmentic expression ", yylineno);
                if ($lvalue->type == tableitem_e) {

                    $term = emit_iftableitem($lvalue, SCOPE, yylineno, FUNC_DEPTH);

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(sub, $term, e, $term, 0, yylineno);
                    emit(tablesetelem, $lvalue, $lvalue->index, $term, 0, yylineno);
                }
                else {

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(sub, $lvalue, e, $lvalue, 0, yylineno);
                    $term = new_expr(arithexpr_e);
                    $term->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                    emit(assign, $lvalue, nullptr, $term, 0, yylineno);
                }
            }

            |lvalue
            {
                SymbolTableEntry *entry_ptr = Lookup(create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH), SCOPE);
                if(isFunction(*entry_ptr)){
                    cout << "\033[1;31m" << 
                        "Function used as lvalue (function--)  at line "<< yylineno <<
                        "\033[0m" << endl;
                }
            }
            MINUSMINUS  
            {
                cout << "term -> lvalue--" << endl;

                check_arith($lvalue, "Cannot use post decrement operator to a not aritmentic expression ", yylineno);
                $term = new_expr(var_e);
                $term->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);

                if ($lvalue->type == tableitem_e) {

                    expr* val = emit_iftableitem($lvalue, SCOPE, yylineno, FUNC_DEPTH);
                    emit(assign, val, NULL, $term, 0, yylineno);

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(sub, val, e, val,  0, yylineno);
                    emit(tablesetelem, $lvalue, $lvalue->index, val, 0, yylineno);
                }
                else {
                    emit(assign, $lvalue, nullptr, $term, 0, yylineno);

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(sub, $lvalue, e, $lvalue, 0, yylineno);
                }
            }
            |NOT expr   
            {
                cout << "term -> !expr" << endl;

                isLogic = true;
                isnt    = true;
               

                $term = new_expr(boolexpr_e);
                $term->sym = istempexpr($expr) ? $expr->sym : newtemp(SCOPE, yylineno, FUNC_DEPTH);

                if ($2->truelist.empty()) {
                   // isLogic = false;
                   /* $2->truelist.push_back(nextquadlabel());
                    emit(if_eq, $2, $2,nullptr, nextquadlabel() + 2, yylineno);
                    $2->falselist.push_back(nextquadlabel());
                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 1, yylineno);*/

                    $2->truelist.push_back(nextquadlabel());
                    expr* e=new_expr(constbool_e);
                    e->boolConst=1;
                    emit(if_eq, $2 , e, nullptr, nextquadlabel() + 2, yylineno);
                
                    $2->falselist.push_back(nextquadlabel());
                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 3, yylineno);

                    $term->falselist = $expr->truelist;
                    $term->truelist =  $expr->falselist;                        

                }  else {
                    $term->falselist = $expr->truelist;
                    $term->truelist =  $expr->falselist;
                }              
            }
            ;


primary:    lvalue  {
                        cout << "primary -> lvalue" << endl;

                        $lvalue   = emit_iftableitem($lvalue, SCOPE, yylineno, FUNC_DEPTH);
                    }
            |call   
            {
                cout << "primary -> call" << endl;
            }
            |objectdef  
            {
                cout << "primary -> objectdef" << endl;
            }
            |START_PARENTHESIS funcdef END_PARENTHESIS  
            {
                cout << "primary -> (funcdef)" << endl;

                $primary = new_expr(programfunc_e);
                $primary->sym = $funcdef; 
            }
            |const  { cout << "primary -> const" << endl; }
            ;

lvalue:     ID
            {   
                cout << "lvalue -> id" << endl;

                GLOBAL_ID = $1;

                SymbolTableEntry * entry_ptr = Lookup(create_entry($1,0,0,LLOCAL, FUNC_DEPTH),SCOPE);
                SymbolTableEntry entry=create_entry($1, SCOPE, yylineno, GLOBAL, FUNC_DEPTH);
                if(entry_ptr== NULL ){

                    if(SCOPE==0){
                        Insert(entry);
                        $lvalue = lvalue_expr(update_entry(entry));             
                    }
                    else{
                        entry.type=LLOCAL;
                        Insert(entry);
                        $lvalue = lvalue_expr(update_entry(entry));

                    }
                } else{
                    if(isFunction(*entry_ptr)) lwarning = true;

                    if(entry_ptr->type!=USERFUNC&&entry_ptr->type!=LIBFUNC&&entry_ptr->value.varVal->scope!=0){
                        if(get_func_depth(*entry_ptr)!=get_func_depth(entry)){
                            cout << "\033[1;31m" << 
                            "Can't access this var at line "<< yylineno <<
                            "\033[0m" << endl;
                        }
                    }
                    $lvalue = lvalue_expr(update_entry(*entry_ptr));
                }
            }
		    |LOCAL ID
            {
                cout << "lvalue -> local id" << endl;

                GLOBAL_ID=$2;
                SymbolTableEntry entry = create_entry($2, SCOPE, yylineno, GLOBAL, FUNC_DEPTH);
                SymbolTableEntry *entry_ptr = Lookup_scope(entry, SCOPE);
                if(entry_ptr==NULL){

                    if(SCOPE==0){
                        Insert_local(entry);
                        $lvalue = lvalue_expr(update_entry(entry));
                    }
                    else{
                        entry.type = LLOCAL;
                        Insert_local(entry);
                        $lvalue = lvalue_expr(update_entry(entry));
                    }
                }else if(entry_ptr->type == LIBFUNC){
                    cout << "\033[1;31m" << 
                    "Collision with library function at line "<< yylineno <<
                    "\033[0m" << endl;
                }
                else {
                    if(isFunction(*entry_ptr)) lwarning = true;
                    $lvalue = lvalue_expr(update_entry(*entry_ptr));
                }
            }
		    |DOUBLE_COLON ID
            {
                cout << "lvalue -> ::id" << endl;

                if(!Lookup_scope(create_entry($2,0,0,LLOCAL, FUNC_DEPTH),0)){
                    cout << "\033[1;31m" << 
                    "Global id not found at line "<< yylineno <<
                    "\033[0m" << endl;
                }else
                    $lvalue = lvalue_expr(update_entry(*Lookup_scope(create_entry($2,0,0,LLOCAL, FUNC_DEPTH),0)  ));
            }
		    |member
            {
                cout << "lvalue -> member" << endl;
                $lvalue = $member;
            }
		    ;

assignexpr:  lvalue
             {  
                SymbolTableEntry entry = create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH);
                SymbolTableEntry *entry_ptr = Lookup(entry,SCOPE);
                if(entry_ptr){      
                    if(isFunction(*entry_ptr) && lwarning){
                            cout << "\033[1;31m" << 
                            "Function used as lvalue at line "<< yylineno <<
                            "\033[0m" << endl;

                            lwarning = false;
                        
                    }
                }
             }
            ASSIGN expr
            {
                cout << "assignexpr -> lvalue = expr" << endl;

                
                if($lvalue->type != tableitem_e)
                {
                    if(!$expr->truelist.empty()) {

                        $expr->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);

                        struct expr* e = new_expr(constbool_e);
                        e->boolConst = 1;
                        emit(assign, e, nullptr, $expr, 0, yylineno);

                        emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                        e = new_expr(constbool_e);
                        e->boolConst = 0;
                        emit(assign, e, nullptr, $expr, 0, yylineno);
                        
                        backpatch($expr->truelist, nextquadlabel() - 3);
                        backpatch($expr->falselist, nextquadlabel() - 1);
                        isLogic=false;

                        emit(assign, $expr, nullptr, $lvalue, 0, yylineno);
                        $assignexpr = new_expr(assignexpr_e);
                        $assignexpr->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);

                        emit(assign, $lvalue, nullptr, $assignexpr, 0, yylineno);
                        
                    }else{
                        
                        emit(assign, $expr, nullptr, $lvalue, 0, yylineno);
                        $assignexpr = new_expr(assignexpr_e);
                        $assignexpr->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);

                        emit(assign, $lvalue, nullptr, $assignexpr, 0, yylineno);
                    }
                }
                else
                {
                    emit(tablesetelem, $lvalue, $lvalue->index, $expr, 0, yylineno);
                    $assignexpr = emit_iftableitem($lvalue, SCOPE, yylineno, FUNC_DEPTH);
                    $assignexpr->type = assignexpr_e;
                }
               
            }
            |call ASSIGN expr{
                cout << "\033[1;31m" << 
                        "Function used as lvalue at line "<< yylineno <<
                        "\033[0m" << endl;
            }
            ;

member:     lvalue DOT {lwarning = false;} ID
            {
                cout << "member -> lvalue.id" << endl;
                
                $lvalue   = emit_iftableitem($lvalue, SCOPE, yylineno, FUNC_DEPTH);
                
                expr* ti  = new_expr(tableitem_e); 
                ti->sym   = $lvalue->sym;
                
                ti->index = new_expr(conststring_e);
                
                
                ti->index->strConst = strdup($ID);
                

                $member =  ti;

            }
            |lvalue START_BRACKET expr END_BRACKET
                                            { 
                                                cout << "member -> lvalue[expr]" << endl;
                                                $lvalue   = emit_iftableitem($lvalue, SCOPE, yylineno, FUNC_DEPTH);
                                                expr* ti  = new_expr(tableitem_e); 
                                                ti->sym   = $lvalue->sym;

                                                ti->index = $expr;

                                                $member =  ti;
                                            }
            |call DOT {lwarning = false;}  ID
                                            { 
                                                cout << "member -> call.id" << endl; 
                                            }
            |call START_BRACKET expr END_BRACKET
                                            { 
                                                cout << "member -> call[expr]" << endl;

                                                $call   = emit_iftableitem($call, SCOPE, yylineno, FUNC_DEPTH);
                                                expr* ti  = new_expr(tableitem_e); 
                                                ti->sym   = $call->sym;

                                                ti->index = $expr;

                                                $member =  ti;
                                            }
            ;

call:       call START_PARENTHESIS elist END_PARENTHESIS    
            {
                cout << "call -> call (elist)" << endl;

                vector <expr*> reversed_elist;
                expr* temp = $elist;
                while (temp) {
                    reversed_elist.push_back(temp);
                    temp = temp->next;
                }

                $$ = make_call($1, reversed_elist, SCOPE, yylineno, FUNC_DEPTH);
            }
            |lvalue callsuffix    
            { 
                cout << "call -> lvalue callsuffix" << endl; 

                vector <expr*> reversed_elist;
                expr* temp = $callsuffix->elist;
                while (temp) {
                    reversed_elist.push_back(temp);
                    temp = temp->next;
                }

                $lvalue = emit_iftableitem($lvalue, SCOPE, yylineno, FUNC_DEPTH);
                if ($callsuffix->method ){
                    expr* t = $lvalue;
                    $lvalue = emit_iftableitem(member_item(t, $callsuffix->name, SCOPE, yylineno, FUNC_DEPTH),
                                                                                 SCOPE, yylineno, FUNC_DEPTH);
                    
                    $callsuffix->elist->next = t ;
                    reversed_elist.insert(reversed_elist.begin(), 1, t);
                }
                $call = make_call($lvalue, reversed_elist, SCOPE, yylineno, FUNC_DEPTH);
            }
            |START_PARENTHESIS funcdef END_PARENTHESIS START_PARENTHESIS elist END_PARENTHESIS  
            { 
                cout << "call -> (funcdef)(elist)" << endl; 

                expr* func = new_expr(programfunc_e);
                func->sym = $funcdef;

                vector <expr*> reversed_elist;
                expr* temp = $elist;
                while (temp) {
                    reversed_elist.push_back(temp);
                    temp = temp->next;
                }
                
                $call = make_call(func, reversed_elist, SCOPE, yylineno, FUNC_DEPTH);
            }
            ;

callsuffix: normcall    
            {
                cout << "callsuffix -> normcall" << endl; 

                $callsuffix = $normcall;
            }
            |methodcall 
            {
                cout << "callsuffix -> methodcall" << endl; 

                $callsuffix = $methodcall;
            }
            ;

normcall:   START_PARENTHESIS elist END_PARENTHESIS 
            { 
                cout << "normcall -> (elist)" << endl;

                $normcall = new struct call;
        
                $normcall->elist = $elist;
                $normcall->method = 0;
                $normcall->name = nullptr;
            }
            ;

methodcall: DOUBLE_DOT ID START_PARENTHESIS elist END_PARENTHESIS
            { 
                cout << "methodcall -> ..id(elist)" << endl;

                $methodcall = new struct call;

                $methodcall->elist = $elist;
                $methodcall->method = 1;
                $methodcall->name = $ID;
            }
            ;

elist:      expr
            {
                if(isLogic) {

                    $expr->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);

                    isLogic = false;
                    struct expr* e = new_expr(constbool_e);
                    e->boolConst = 1;
                    emit(assign, e, nullptr, $expr, 0, yylineno);

                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                    e = new_expr(constbool_e);
                    e->boolConst = 0;
                    emit(assign, e, nullptr, $expr, 0, yylineno);

                    backpatch($expr->truelist, nextquadlabel() - 3);
                    backpatch($expr->falselist, nextquadlabel() - 1);
                
                }
                isnt = false;
            }
            commaexpr  
            {
                cout << "elist -> expr commaexpr" << endl; 

                $elist->next  = $commaexpr;
            }
            |
            { 
                cout << "elist -> " << endl;

                $$ = nullptr;
            }
            ;

commaexpr:  COMMA 
            expr
            {
                if(isLogic) {

                    $expr->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);

                    isLogic = false;
                    struct expr* e = new_expr(constbool_e);
                    e->boolConst = 1;
                    emit(assign, e, nullptr, $expr, 0, yylineno);

                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                    e = new_expr(constbool_e);
                    e->boolConst = 0;
                    emit(assign, e, nullptr, $expr, 0, yylineno);

                    backpatch($expr->truelist, nextquadlabel() - 3);
                    backpatch($expr->falselist, nextquadlabel() - 1);
                
                }
                isnt = false;
            } 
            commaexpr    
            { 
                cout << "commaexpr -> ,expr commaexpr" << endl; 
                $$ = $expr;
                $$->next = $4;
            }
            |                      
            { 
                cout << "commaexpr -> " << endl; 

                $$ = nullptr;
            }
            ;

objectdef:  START_BRACKET elist END_BRACKET     { 
                                                    cout << "objectdef -> [elist]" << endl; 

                                                    expr* t = new_expr(tableitem_e);
                                                    t->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                                                    emit(tablecreate, nullptr, nullptr, t, 0, yylineno);

                                                    for (int i = 0; $elist; $elist = $elist->next){
                                                        
                                                        expr* e = new_expr(constnum_e);
                                                        e->numConst = i++;
                                                        emit(tablesetelem, e, $elist, t, 0, yylineno);
                                                    } 
                                                    
                                                    $objectdef = t;
                                                }
            |START_BRACKET indexed END_BRACKET  
                                                { 
                                                    cout << "objectdef -> [indexed]" << endl;

                                                    expr* t = new_expr(tableitem_e);
                                                    t->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                                                    emit(tablecreate, nullptr, nullptr, t, 0, yylineno);

                                                    expr* temp = $indexed;
                                                    while(temp) {
                                                        emit(tablesetelem, temp->index, temp, t, 0 , yylineno);
                                                        temp = temp->next;
                                                    }

                                                    $objectdef = t;
                                                }
            ;
                

indexed:            indexedelem commaindexedelem    {
                                                        cout << "indexed -> indexedelem commaindexedelem" << endl;

                                                        $$->next = $commaindexedelem;
                                                    }
                    ;

commaindexedelem:   COMMA indexedelem commaindexedelem  {
                                                            cout << "commaindexelem -> ,indexelem commaindexelem" << endl;

                                                            $$ = $indexedelem;
                                                            $$->next = $3;
                                                        }
                    |                                   {
                                                            cout << "commaindexelem -> " << endl;

                                                            $$ = nullptr;
                                                        }
                    ;
        
indexedelem:        CURLY_START_BRACKET expr COLON expr CURLY_END_BRACKET   
                    {
                        cout << "indexelem -> {expr:expr}" << endl;
                        if($4->type == constnum_e){
                            $indexedelem = new_expr(constnum_e);
                            $indexedelem->numConst = $4->numConst;
                        }
                        if($4->type == constbool_e){
                            $indexedelem = new_expr(constbool_e);
                            $indexedelem->boolConst = $4->boolConst;
                        }
                        if($4->type == conststring_e){
                            $indexedelem = new_expr(conststring_e);
                            $indexedelem->strConst = $4->strConst;
                        }
                        if($4->type == arithexpr_e){
                            $indexedelem = new_expr(arithexpr_e);
                            $indexedelem->sym = $4->sym;
                        }
                        if($4->type == boolexpr_e){
                            $indexedelem = new_expr(boolexpr_e);
                            $indexedelem->sym = $4->sym;
                        }
                        if($4->type == var_e){
                            $indexedelem = new_expr(var_e);
                            $indexedelem->sym = $4->sym;

                        }if($4->type == tableitem_e){
                            $indexedelem = new_expr(tableitem_e);
                            $indexedelem->sym = $4->sym;

                        }if($4->type == libraryfunc_e){
                            $indexedelem = new_expr(libraryfunc_e);
                            $indexedelem->sym = $4->sym;

                        }if($4->type == assignexpr_e){
                            $indexedelem = new_expr(assignexpr_e);
                            $indexedelem->sym = $4->sym;
                        }
                        if($4->type == nil_e){
                            $indexedelem = new_expr(nil_e);
                            $indexedelem->sym = $4->sym;
                        }
                        if($4->type == programfunc_e){
                            $indexedelem = new_expr(programfunc_e);
                            $indexedelem->sym = $4->sym;
                        }
                        $indexedelem->index = $2;
                    }
                    ;

block:              CURLY_START_BRACKET
                    {
                        SCOPE++;
                    }
                    CURLY_END_BRACKET
                    {
                        cout << "block -> {}" << endl;
                        Hide(SCOPE--);
                    }
                    |CURLY_START_BRACKET
                    {
                        SCOPE++;
                    }
                    stmt program
                    CURLY_END_BRACKET
                    {
                        cout << "block -> {stmt program}" << endl;
                        Hide(SCOPE--);
                    }
                    ;


funcdef:            FUNCTION
                    {
                        SymbolTableEntry entry = create_entry(generate_function_name(),SCOPE,yylineno,USERFUNC, FUNC_DEPTH);
                        Insert(entry);
                        FUNC_DEPTH++;
                        
                        if(!scopeoffsetStack.empty())
                            scopeoffsetStack.back()->sym->value.funVal->totalLocals = currscopeoffset();

                        expr *expr = new_expr(programfunc_e);
                        expr->sym = update_entry(entry);
                        expr->sym->value.funVal->iaddress = nextquadlabel();
                        
                        emit(funcstart, nullptr, nullptr, expr, 0, yylineno);

                        scopeoffsetStack.push_back(expr);
                        enterscopespace();
                        resetformalargsoffset();
                    }
                    START_PARENTHESIS
                    {
                        SCOPE++;
                        enterscopespace();
                    }
                    idlist 
                    END_PARENTHESIS 
                    {
                        SCOPE--;
                        resetfunctionlocalsoffset();
                        enterscopespace();
                    }
                    block   
                    {
                        cout << "funcdef -> function (idlist) block" << endl;
                        exitscopespace();
                        exitscopespace();

                        emit(funcend, nullptr, nullptr, scopeoffsetStack.back(), 0, yylineno);

                        scopeoffsetStack.back()->sym->value.funVal->totalLocals = currscopeoffset();
                        $funcdef = scopeoffsetStack.back()->sym;
                        scopeoffsetStack.pop_back();
                        

                        if(!scopeoffsetStack.empty()){
                            inccurentscopeoffset(scopeoffsetStack.back()->sym->value.funVal->totalLocals);
                        }
                    }
                    |FUNCTION {fflag = true;}
                    ID
                    {   
                        
                        SymbolTableEntry entry = create_entry($3, SCOPE, yylineno, USERFUNC, FUNC_DEPTH);
                        SymbolTableEntry *entry_ptr_glb = Lookup(entry, SCOPE);
                        SymbolTableEntry *entry_ptr = Lookup_scope(entry,SCOPE);
                        if(entry_ptr==NULL){
                            if(entry_ptr_glb==NULL){
                                Insert(entry);
                            }else if(entry_ptr_glb->type==LIBFUNC){
                                cout << "\033[1;31m" << 
                            "Lib function redeclaration at line "<< yylineno <<
                            "\033[0m" << endl;
                            }else{
                                Insert(entry);
                            }
                        }else if(entry_ptr->type == LIBFUNC){
                            cout << "\033[1;31m" << 
                            "Lib function redeclaration at line "<< yylineno <<
                            "\033[0m" << endl;
                        }else if(entry_ptr->type == USERFUNC){
                            cout << "\033[1;31m" << 
                            "User function redeclaration at line "<< yylineno <<
                            "\033[0m" << endl;
                        }else if(entry_ptr->type==GLOBAL||entry_ptr->type==LLOCAL||entry_ptr->type==FORMAL){
                            cout << "\033[1;31m" << 
                            "Variable already defined at line "<< yylineno <<
                            "\033[0m" << endl;
                        }
                        FUNC_DEPTH++;
                        if(!scopeoffsetStack.empty())
                            scopeoffsetStack.back()->sym->value.funVal->totalLocals = currscopeoffset();

                        expr *expr = new_expr(programfunc_e);
                        expr->sym = update_entry(entry);
                        expr->sym->value.funVal->iaddress = nextquadlabel();
                        
                        emit(funcstart, nullptr, nullptr, expr, 0, yylineno);

                        scopeoffsetStack.push_back(expr);
                        enterscopespace();
                        resetformalargsoffset();
                    }
                    START_PARENTHESIS
                    {
                        SCOPE++;
                        enterscopespace();
                    }
                    idlist
                    END_PARENTHESIS
                    {
                        SCOPE--;
                        enterscopespace();
                        resetfunctionlocalsoffset();
                    }
                    block
                    {
                        cout << "funcdef -> function id(idlist) block" << endl;
                        FUNC_DEPTH--;
                        exitscopespace();
                        exitscopespace();

                        emit(funcend, nullptr, nullptr, scopeoffsetStack.back(), 0, yylineno);

                        scopeoffsetStack.back()->sym->value.funVal->totalLocals = currscopeoffset();
                        $funcdef = scopeoffsetStack.back()->sym;
                        scopeoffsetStack.pop_back();

                        if(!scopeoffsetStack.empty()){
                            inccurentscopeoffset(scopeoffsetStack.back()->sym->value.funVal->totalLocals);
                        }
                    }
                    ;

const:              REAL        { 
                                    cout << "const -> real" << endl;
                                    $const = new_expr(constnum_e);
                                    $const->numConst = $REAL;
                                }
                    |INTEGER    { 
                                    cout << "const -> integer" << endl; 
                                    $const = new_expr(constnum_e);
                                    $const->numConst = $INTEGER;
                                }
                    |STRING     {
                                    cout << "const -> string" << endl; 
                                    $const = new_expr(conststring_e);
                                    $const->strConst = $STRING;
                                }
                    |NIL        { 
                                    cout << "const -> nil" << endl;
                                    $const = new_expr(nil_e);
                                    //! NIL == empty string
                                    //$const->strConst = nullptr;
                                }
                    |TRUE       { 
                                    cout << "const -> true" << endl;
                                    $const = new_expr(constbool_e);
                                    $const->boolConst = true;
                                }
                    |FALSE      { 
                                    cout << "const -> false" << endl;
                                    $const = new_expr(constbool_e);
                                    $const->boolConst = false; 
                                }
                    ;

idlist:             ID
                    {
                        FORMAL_ARGUMENTS.clear();
                        SymbolTableEntry entry = create_entry($1, SCOPE, yylineno, FORMAL, FUNC_DEPTH);

                        SymbolTableEntry* entry_ptr = Lookup_scope(entry, 0);
                        if(entry_ptr != NULL){
                            if(entry_ptr->type != LIBFUNC){
                                Insert(entry);
                                FORMAL_ARGUMENTS.push_back(entry);
                            }else{
                                cout << "\033[1;31m" << 
                                "Library function as formal argument at line "<< yylineno <<
                                "\033[0m" << endl;
                            }
                        }else{
                            Insert(entry);
                            FORMAL_ARGUMENTS.push_back(entry);
                        }     
                    }
                    commaid     { cout << "idlist -> id commaid" << endl; }
                    |           { cout << "idlist -> " << endl; }
                    ;

commaid:            COMMA
                    ID
                    {
                        SymbolTableEntry entry = create_entry($2, SCOPE, yylineno, FORMAL, FUNC_DEPTH);

                        SymbolTableEntry* entry_ptr = Lookup_scope(entry, 0);
                        if(entry_ptr != NULL){
                            if(entry_ptr->type != LIBFUNC){
                                Insert(entry);
                                FORMAL_ARGUMENTS.push_back(entry);
                            }else{
                                cout << "\033[1;31m" << 
                                "Library function as formal argument at line "<< yylineno <<
                                "\033[0m" << endl;
                            }
                        }else{
                            for(int i=0; i<FORMAL_ARGUMENTS.size(); i++){
                                if($2 == get_name(FORMAL_ARGUMENTS.at(i))){
                                    cout << "\033[1;31m" << 
                                    "Formal redeclaration at line "<< yylineno <<
                                    "\033[0m" << endl;
                                }else{                
                                    Insert(entry);
                                }
                            }
                        }    
                    }
                    commaid     { cout << "commaid -> ,id commaid" << endl; }
                    |           { cout << "commaid -> " << endl; }
                    ;

ifprefix:           IF START_PARENTHESIS expr END_PARENTHESIS
                    {
                        cout << "ifprefix -> if(expr)" << endl;

                        expr *e = new_expr(constbool_e);
                        e->boolConst = 1;
                        if(isLogic) {
                            isLogic = false;
                            struct expr* e = new_expr(constbool_e);
                            e->boolConst = 1;
                            emit(assign, e, nullptr, $expr, 0, yylineno);

                            emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                            e = new_expr(constbool_e);
                            e->boolConst = 0;
                            emit(assign, e, nullptr, $expr, 0, yylineno);
                            backpatch($expr->truelist, nextquadlabel() -3);
                            backpatch($expr->falselist, nextquadlabel() - 1);
                            
                        
                        }
                        emit(if_eq, e, nullptr, $expr, nextquadlabel() + 2, yylineno);

                        $ifprefix = nextquadlabel();
                        emit(jump, nullptr, nullptr, nullptr, 0, yylineno);
                        
                    }
                    ;

ifstmt:             ifprefix stmt      
                    {
                        cout << "ifstmt -> ifprefix stmt" << endl;

                        patchlabel($ifprefix, nextquadlabel());
                        
                    }
                    |ifprefix stmt elseprefix stmt   
                    { 
                        cout << "ifstmt -> ifprefix stmt elseprefix stmt" << endl;

                        patchlabel($ifprefix, $elseprefix + 1);
                        patchlabel($elseprefix, nextquadlabel());
                    }
                    ;

elseprefix:         ELSE    
                    {
                        cout << "ifstmt -> elseprefix" << endl;

                        $elseprefix = nextquadlabel();
                        emit(jump, nullptr, nullptr, nullptr, 0, yylineno);
                    }
                    ;

whilestart:         WHILE
                    {
                        cout << "whilestart -> WHILE" << endl;
                        loop_counter++;
                        loop_intersect = 1;

                        $whilestart = nextquadlabel();
                        loop_start.push_back(nextquadlabel());
                        if(break_intersect){
                            valid_jumps.push_back(nextquadlabel() + 1);
                            break_intersect = 0;
                        }
                        vector<int> v;
                        continue_quads.push_back(v);
                        break_quads.push_back(v);
                    }
                    ;

whilecond:          START_PARENTHESIS expr END_PARENTHESIS
                    {
                        cout << "whilecond -> (expr)" << endl;

                        expr* e = new_expr(constbool_e);
                        e->boolConst = 1;
                        if(isLogic) {
                            isLogic = false;
                            struct expr* e = new_expr(constbool_e);
                            e->boolConst = 1;
                            emit(assign, e, nullptr, $expr, 0, yylineno);

                            emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                            e = new_expr(constbool_e);
                            e->boolConst = 0;
                            emit(assign, e, nullptr, $expr, 0, yylineno);
                            backpatch($expr->truelist, nextquadlabel() -3);
                            backpatch($expr->falselist, nextquadlabel() - 1);
                            
                        
                        }
                        emit(if_eq,nullptr, e, $expr, nextquadlabel() + 2, yylineno);

                        $whilecond = nextquadlabel();
                        
                        emit(jump, nullptr, nullptr, nullptr, 0, yylineno);
                    }
                    ;

whilestmt:          whilestart whilecond stmt
                    {
                        cout << "whilestmt -> whilestart whilecond stmt" << endl;

                        emit(jump, nullptr, nullptr, nullptr, $whilestart, yylineno);
                        patchlabel($whilecond, nextquadlabel());
                        loop_end.push_back(nextquadlabel());                                               

                        if(continue_quads.size()>0)
                            for(int j=0;j<continue_quads.at(continue_quads.size()-1).size();j++){
                                
                                patchlabel(continue_quads.at(continue_quads.size()-1).at(j), loop_start.at(loop_start.size()-1));
                            }
                        if(break_quads.size()>0)
                            for(int j=0;j<break_quads.at(break_quads.size()-1).size();j++){
                                patchlabel(break_quads.at(break_quads.size()-1).at(j), loop_end.at(loop_end.size()-1));
                            }
                        
                        
                        loop_start.pop_back();
                        loop_end.pop_back();
                        if(continue_quads.size()>0)
                            continue_quads.pop_back();
                        if(break_quads.size()>0)
                            break_quads.pop_back();

                        loop_counter--;
                        if(loop_counter < 0) loop_counter=0;
                    }
                    ;

N:                  { 
                        $N = nextquadlabel(); 
                        emit(jump,nullptr,nullptr, nullptr, 0, yylineno); 
                    }
                    ;

M:                  {
                        $M = nextquadlabel(); 
                    }
                    ;

forprefix:          FOR {loop_counter++;}START_PARENTHESIS elist SEMICOLON M expr SEMICOLON
                    {
                        cout << "forprefix -> for(elist;expr;" << endl;

                        $forprefix = new struct forJump;
                        $forprefix->test = $M;
                        
                        expr *e = new_expr(constbool_e);
                        e->boolConst = 1;
                        if(isLogic) {
                            isLogic = false;
                            struct expr* e = new_expr(constbool_e);
                            e->boolConst = 1;
                            emit(assign, e, nullptr, $expr, 0, yylineno);

                            emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                            e = new_expr(constbool_e);
                            e->boolConst = 0;
                            emit(assign, e, nullptr, $expr, 0, yylineno);
                            backpatch($expr->truelist, nextquadlabel() -3);
                            backpatch($expr->falselist, nextquadlabel() - 1);
                            
                        
                        }
                        $forprefix->enter = nextquadlabel();
                        emit(if_eq, e, nullptr, $expr, 0, yylineno);
                        vector<int> v;
                        continue_quads.push_back(v);
                        break_quads.push_back(v);
                    }
                    

forstmt:            forprefix N elist END_PARENTHESIS N stmt N
                    {
                        cout << "forstmt -> elist) stmt" << endl;

                        patchlabel($forprefix->enter, $5 + 1);
                        patchlabel($2 , nextquadlabel());
                        patchlabel($5 , $forprefix->test);
                        patchlabel($7 , $2 + 1);
                        loop_start.push_back($2 + 1);
                        loop_end.push_back(nextquadlabel());
                        

                        if(continue_quads.size()>0)
                            for(int j=0;j<continue_quads.at(continue_quads.size()-1).size();j++){
                                patchlabel(continue_quads.at(continue_quads.size()-1).at(j), loop_start.at(loop_start.size()-1));
                            }
                        if(break_quads.size()>0)
                            for(int j=0;j<break_quads.at(break_quads.size()-1).size();j++){
                                patchlabel(break_quads.at(break_quads.size()-1).at(j), loop_end.at(loop_end.size()-1));
                            }


                        loop_start.pop_back();
                        loop_end.pop_back();
                        if(continue_quads.size()>0)
                            continue_quads.pop_back();
                        if(break_quads.size()>0)
                            break_quads.pop_back();
                        loop_counter--;
                        if(loop_counter < 0) loop_counter=0;
                    }
                    ;

returnstmt:         RETURN{
                        if(FUNC_DEPTH==0){
                            cout << "\033[1;31m" << 
                                    "Return outside of function at line "<< yylineno <<
                                    "\033[0m" << endl;
                        }

                    } 
                    expr SEMICOLON
                    { 
                        cout << "returnstmt -> return expr;" << endl;

                        emit(ret, nullptr, nullptr, $expr, 0, yylineno);
                    }
                    | RETURN{
                        if(FUNC_DEPTH==0){
                            cout << "\033[1;31m" << 
                                    "Return outside of function at line "<< yylineno <<
                                    "\033[0m" << endl;
                        }
                    } SEMICOLON
                    { 
                        cout << "returnstmt -> return;" << endl; 

                        emit(ret, nullptr, nullptr, nullptr, 0, yylineno);
                    }
                    ;



%%

int main(int argc, char** argv){

    if(argc>1){
        if(!(yyin=fopen(argv[1],"r"))){
            printf("Cannot open file %s",argv[1]);
            return -1;
        }
    }else
        yyin=stdin;
    
    
    Insert(create_entry("print", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("input", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("objectmemberkeys", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("objecttotalmembers", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("objectcopy", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("totalarguments", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("argument", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("typeof", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("strtonum", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("sqrt", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("cos", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("sin", 0, 0, LIBFUNC,FUNC_DEPTH));
    
    
    yyparse();
    
    print_symbol_table();
    print_quads();

    return 0;
}
