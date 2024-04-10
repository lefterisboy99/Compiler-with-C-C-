#include "manage_g_action.h"

extern int is_member_call;
extern vector <bool> isBlock;
extern int is_func_rule;

unsigned int tmp_var_counter     = 0;
unsigned int programVarOffset    = 0;
unsigned int functionLocalOffset = 0;
unsigned int formalArgOffset     = 0;
unsigned int scopeSpaceCounter   = 1;

extern vector <ioquad_t> quads;//quad table
extern vector <unsigned int> functionLocalStack;

char *Manage_term__pre_post_op_lvalue(struct node *exprNode , string op ){
    if( exprNode  != NULL){
    if ( is_lib_func(exprNode->name) == true ){
        cout << "Error: Function operation: "<< op << " prohibited.(cannot change value)" << " scope[" << scope << "]." << "in line[" << yylineno << "]."  << endl;
    }
    }

    node_t *symbol = look_up( create_key( exprNode->name) ); 
    if( symbol != NULL && ( (symbol->type == USER_FUNC) || (symbol->type == LIB_FUNC) ) ){
    cout << "Error: Function operation: "<< op << " prohibited." << " scope[" << scope << "]." << "in line[" << yylineno << "]."  << endl;
    } 

    return NULL;
}


char *Manage_assignexpr__lvalue_assignment_expr(struct node *exprNode){

    if(is_member_call == 0 ){
        if( exprNode != NULL){
            node_t *symbol = look_up( create_key( exprNode->name ) ); 
            if( symbol != NULL && ( (symbol->type == USER_FUNC) || (symbol->type == LIB_FUNC) ) ){
                cout << "Error: Function assignment operation: \"" << exprNode->name << "\" prohibited." << " scope[" << scope << "]." << "in line[" << yylineno << "]."  << endl;
            } 

                if ( is_lib_func(exprNode->name) == true ){
                    cout << "Error: Function assignment operation: \"" << exprNode->name << "\" prohibited." << " scope[" << scope << "]." << "in line[" << yylineno << "]."  << endl;
            }
        }else{}//TODO:An gurnaei to lvalue apo COLONCOLON ID tote to $1 einai NULL kai g@miet@i
    }else{
        is_member_call--;
    }
    return NULL;
}

expr *Manage_lvalue__ID(char *id){   
    node_t *symbol = NULL;
    int i,j;
    bool error=false;
    for ( i = scope; i >= 0; i-- ){ 
        if ( (symbol=LookUp_Scope( id , i )) != NULL ){//to brika
            //cout << "test ..... name" << id << " Type....." << symbol->type << endl;
            break;
        }
    }
    
    if (symbol){
        if( scope > symbol->scope && symbol->scope!=0 && symbol->type!=USER_FUNC){
            for(j=symbol->scope;j<scope;j++){
                if(!isBlock[j]){
                    error=true;
                    break;
                }
            }
            if(error){
                cout << "Error: Cannot access : \"" << id << "\"." << " scope[" << scope << "]." << "in line[" << yylineno << "]."  << 
                "Already defined here: " << symbol->name << " line: " << symbol->line_num << " scope " << symbol->scope << endl;
                error=false;
            }
        }else{
            if(symbol->scope == 0 || symbol->scope == scope || symbol->type==USER_FUNC || symbol->type==FUNC_ARG){
                if(symbol->type==LIB_FUNC){//phase 5
                    symbol->type_s = LIB_FUNC_S;
                   // cout << "test new if check ..... name" << id << " Type....." << symbol->type << endl;
                }

                //cout << "test 2 ..... name" << id << " Type....." << symbol->type << endl;
            } /*cout<< "Referencing to a global//us_f//func_arg " << symbol->name <<endl;*/
            else{
                insert(create_key(id ) , true, id, (scope > 0 ? LOCAL_VAR : GLOBAL_VAR) , scope ,  yylineno , NULL );
            }
        }
        
    }
    else{
        symbol = insert(create_key(id) , true, id , (scope > 0 ? LOCAL_VAR : GLOBAL_VAR) , scope ,  yylineno , NULL );
        symbol->scope_space = currScopeSpace();
        symbol->offset = currScopeOffset();
        symbol->type_s = VAR_S;
        incrCurrScopeOffset(); 
    }
    return lvalueExpr( symbol);
}

//todo remove  returns
expr *Manage_lvalue__LOCAL_ID(char *id){
    node_t *symbol = LookUp_Scope( id , scope );
        
    if ( (symbol == NULL ) && (is_lib_func(id)==false) ){//den to brika kai den einai libfunc (elenxoyme gia lib fun epeidh kanoyme look_up sto scope)
        symbol = insert(create_key(id ) , true, id, (scope > 0 ? LOCAL_VAR : GLOBAL_VAR) , scope ,  yylineno , NULL );
        
        symbol->scope_space = currScopeSpace();
        symbol->offset = currScopeOffset();
        symbol->type_s = VAR_S; 
        incrCurrScopeOffset();
    }
    else{//den einai NULL
        if( (is_lib_func(id)==true) || symbol->type == USER_FUNC ){
            cout << "Error: Fucntion already exist \"" << id << "\"" << " scope[" << scope << "]." << "in line[" << yylineno << "]."  << endl;
        }
        
    }
    return lvalueExpr( symbol);
}

expr *Manage_lvalue__COLONCOLON_ID(char *id){
    node_t *symbol;
    if ( (symbol=LookUp_Scope( id , 0 )) == NULL ){//den to brika  
        cout << "Error: Not found: \"" << id << "\" in global scope." << " scope[" << scope << "]." << "in line[" << yylineno << "]."  << endl;
        return lvalueExpr( symbol);
    }
    else{
        return lvalueExpr( symbol);//TODO
    }
}

void Manage__open_block(){
    scope++;
    if(  isBlock.size() < scope ){
            isBlock.push_back(true);
    }
}

void Manage__close_block(){
    if(  is_func_rule > 0 ){
        is_func_rule--;
        active_func_name.pop_back();
    }
        
    set_is_active(scope , false );
    isBlock.pop_back();
    scope--;
}

node_t *Manage_ID_OR_NOT__ID(char *id){
    active_func_name.push_back(id);
    node_t *symbol = LookUp_Scope(id , scope);
   
    if( symbol != NULL ){//brhka func h var me to idio ID(onoma)
        cout << "Error: Function name: \"" << id << "\" exists!" << " scope[" << scope << "]." << "in line[" << yylineno << "]."  << endl;
    }
    else if ( is_lib_func( id ) == false ){
       symbol =  insert(create_key("") , true, id, USER_FUNC , scope ,  yylineno , NULL );
       symbol->type_s = USER_FUNC_S;
    }     
    return symbol;
}

node_t *Manage_ID_OR_NOT__Anonymous(){
    node_t *symbol;
    anon_func++; 
    active_func_name.push_back("$" + to_string(anon_func));
    symbol = insert(create_key("") , true, "$" + to_string(anon_func), USER_FUNC , scope ,  yylineno , NULL );
    symbol->type_s = USER_FUNC_S;

    return symbol;
}

void Manage_idlist__ID(char *id){
    node_t *symbol = LookUp_Scope(id , scope);
    if( symbol != NULL ){//brhka func h var me to idio ID(onoma)
        cout << "Error: Argument name: \"" << id << "\" exists!" << " scope[" << scope << "]." << "in line[" << symbol->line_num << "]."  << endl;
        goto END1;
    }

    if ( is_lib_func( id ) == false ){
        insert(create_key(id ) , true, id, FUNC_ARG , scope ,  yylineno , NULL );
    }

END1: ;                
}

void Manage_idlist__idlist_comma_ID(char *id){
     node_t *symbol = LookUp_Scope(id , scope);
    if( symbol != NULL ){//brhka func h var me to idio ID(onoma)
        cout << "Error: Argument name: \"" << id << "\" exists!" << " scope[" << scope << "]." << "in line[" << symbol->line_num << "]."  << endl;
        goto END2;
        
    }

    if ( is_lib_func( id ) == false ){
        insert(create_key(id ) , true, id, FUNC_ARG , scope ,  yylineno , NULL );
    }
    
END2: ;  
}

void clear_statement_stack(){
    if( statement_stack.size() > 0 ){

        statement_stack.pop_back();
        //cout << "close block" << endl;

        if( statement_stack.size() > 0 ){
            if( statement_stack.back() != "block" ){
                // cout << "remove "  <<  statement_stack.back() << endl;
                statement_stack.pop_back();
            }
            else{
                // cout << "Second time : Cannot remove because is block " << endl;
            }
        }
    }
}

void is_correct_break_continue(string instruction){
    bool correct_return = false;
    int i = statement_stack.size()-1;
    while( i >= 0 ){
        if( statement_stack[i] == "funcdef" ){
            break; 
        }
        
        if( statement_stack[i] == "for" || statement_stack[i] == "while" ){
            correct_return = true;
            break;
        }
        i--;
    }

    if(correct_return == false){
        cout <<"Error: \"" << instruction << "\" does not match with \"while\" or \"for\" in line: [" << yylineno << "]"<<endl;
    }
}

void is_correct_return(){
    bool correct_return = false;
    int i = statement_stack.size()-1;
    while( i >= 0 ){
        if( statement_stack[i] == "funcdef" ){
            correct_return = true;
            break; 
        }
        i--;
    }
    if(correct_return == false){
        cout << "Error: \"return\" does not matchunsignedwith function in line: [" << yylineno << "]" << endl;
    }
}

void emit( iopcode op, expr *result, expr *arg1, expr *arg2, long int label, unsigned long line){
    ioquad_t quad;//new quad

    quad.op = op;
    quad.result = result;
    quad.arg1 = arg1;
    quad.arg2 = arg2;
    quad.label = label;
    quad.line = line;

    quads.push_back(quad);
    
}

expr *emit_op(iopcode opcode , expr *arg1, expr *arg2 , long int label, unsigned long line){
    expr *e = newExpr(ARITHM_EXPR_E);
    e->sym = newTmpVarName();

    if( arg1->type == CONST_NUM_E && arg2->type == CONST_NUM_E ){
        switch(opcode)
        {
            case ADD:
                e->num_const = arg1->num_const + arg2->num_const; 
                break;
            case SUB:
                e->num_const = arg1->num_const - arg2->num_const;
                break;
            case MUL:
                e->num_const = arg1->num_const * arg2->num_const;
                break;
            
            case DIV:
                e->num_const = arg1->num_const / arg2->num_const;
                break;

            case MOD:
                e->num_const = ((int)arg1->num_const) % ((int)arg2->num_const);
                break;

            default:
                break;
        }
    }

    emit(opcode , e , arg1 , arg2 , label , line );

    return e;
}



expr *emit_relop(iopcode opcode , expr *arg1, expr *arg2 , long int label, unsigned long line){
    expr *e = newExpr(BOOL_EXPR_E);
    e->sym = newTmpVarName();

    if( arg1->type == CONST_NUM_E && arg2->type == CONST_NUM_E ){
        switch(opcode)
        {
            case IF_GREATER:
                e->bool_const = arg1->num_const > arg2->num_const; 
                break;
            case IF_GREATEREQ:
                e->bool_const = arg1->num_const >= arg2->num_const;
                break;
            case IF_LESS:
                e->bool_const = arg1->num_const < arg2->num_const;
                break;
            
            case IF_LESSEQ:
                e->bool_const = arg1->num_const <= arg2->num_const;
                break;

            case IF_EQ:
                e->bool_const = arg1->num_const == arg2->num_const;
                break;
            case IF_NOTEQ:
                e->bool_const = arg1->num_const != arg2->num_const;
                break;
            default:
                assert(0);
        }
    }

    // cout << "compare: " << e->bool_const << endl;

    emit(opcode , NULL , arg1 , arg2 , quads.size()+3 , line );//TODO: check if result must be NULL
    emit(ASSIGN , e , newExpr_constBool(0) , NULL , 0 , yylineno );
    emit(JUMP , NULL, NULL, NULL , quads.size()+2  , yylineno );
    emit(ASSIGN , e , newExpr_constBool(1) , NULL , 0 , yylineno );

    return e;
}

expr *emit_boolop(iopcode opcode , expr *arg1, expr *arg2 , long int label, unsigned long line){
    expr *e=NULL;
    if(!is_boolop_applicable(arg1) && !is_boolop_applicable(arg2))
       cout << "not applicable bool op line: " << yylineno << endl;
    e = newExpr(BOOL_EXPR_E); //FIXME: check the type const
    e->sym = newTmpVarName();
    emit(opcode , e , arg1 , arg2 , 0 , line );
    return e;
    
}

// vector<long int> *merge(vector <long int> *l1 , vector <long int> *l2){
//     vector<long int> *ml = new vector<long int>();
//     ml->reserve( l1->size() + l2->size() );
//     ml->insert( ml->end() , l1->begin() , l1->end() );
//     ml->insert( ml->end() , l2->begin() , l2->end() );

//     return ml;
// }

// void backpatch( vector <long int> *l , long int NQ ){
//     for( unsigned int i = 0; i < l->size(); i++ ){
//         l->at(i) = NQ;
//     }   
// }


// bool get_bool_value(expr *arg){
    
//     expr_t t = arg->type;

//     if( t == USER_FUNC_E || t == LIB_FUNC_E || TABLE_ITEM_E ){        
//         return true;
//     }
    
//     if( t == NIL_E ){
//         return false; 
//     }
    
//     if( t == CONST_NUM_E && arg->num_const != 0 ){
//         return true;
//     }
    
//     if( t == CONST_STRING_E && arg->str_const != "" ){
//         return true;
//     }

//     return false;
// }

string newTmpName(){
    return "^" + to_string(tmp_var_counter++);

}

void resetTmpVarNameC(){
    tmp_var_counter = 0;
}

unsigned short int currscope(){
    return scope;
}

node_t* newTmpVarName(){
    string name = newTmpName();
    node_t* sym = LookUp_Scope( name, currscope() ); //skeftomaste an kitazoume mono sto trexon scope gia na vroume tin krifi metavliti
    if(sym == NULL){
        // cout << "---------------curr-------------------"<< currScopeOffset() << endl;
        sym = insert(create_key(name) , true, name , (scope > 0 ? LOCAL_VAR : GLOBAL_VAR) , scope ,  yylineno , NULL ); 
        incrCurrScopeOffset();
    }
    return sym;
}

scope_space_t currScopeSpace(){
    if(scopeSpaceCounter == 1){
        return PROGRAM_VAR;
    }else if(scopeSpaceCounter % 2 == 0){
        return FORMAL_ARG;
    }else{
        return FUNCTION_LOCAL;
    }

}

unsigned currScopeOffset(){
    switch(currScopeSpace()){
        case PROGRAM_VAR   : return programVarOffset;
        case FUNCTION_LOCAL  : return functionLocalOffset;
        case FORMAL_ARG  : return formalArgOffset;
        default : assert(0);
    }
}

void incrCurrScopeOffset(){
    switch(currScopeSpace()){
        case PROGRAM_VAR   : ++programVarOffset; break;
        case FUNCTION_LOCAL  :  ++functionLocalOffset; break;
        case FORMAL_ARG  :  ++formalArgOffset; break;
        default : assert(0);
    }
}

void enterScopeSpace(){
    ++scopeSpaceCounter;
}

void exitScopeSpace(){
    assert(scopeSpaceCounter > 1);
    --scopeSpaceCounter;
}

void resetFormalArgsOffset(){
    formalArgOffset = 0;
}

void resetFuncLocalOffset(){
    functionLocalOffset = 0;
}

void restoreCurrScopeOffset(unsigned int num){
     switch(currScopeSpace()){
        case PROGRAM_VAR     : programVarOffset = num; break; 
        case FUNCTION_LOCAL  : functionLocalOffset = num ; break;
        case FORMAL_ARG      : formalArgOffset = num ; break;
        default : assert(0);
    }
}

void patchLabel(unsigned quadNum , long int label){
    // assert( quadNum < quads.size()-1 );
    // cout << "quadNum: " << quadNum << "label: " << label << endl;

    quads[quadNum].label = label;

    // cout << "quads[quadNum].label: " << quads[quadNum].label << endl;
   
}

expr *lvalueExpr( node_t *sym){
    assert(sym);

    expr *e = new expr();

    // e->next = NULL;
    e->sym = sym;

    switch(sym->type_s){
        case VAR_S : e->type = VAR_E; break;
        case USER_FUNC_S : e->type = USER_FUNC_E; break;
        case LIB_FUNC_S : e->type = LIB_FUNC_E; /*cout << "test lvalueExpr(_)...switch  ..... name" << sym->name << " Type....." << sym->type << endl;*/  break;
        default: /*assert(0)*/; //FIX ME!!         
    }
    //cout << "test lvalueExpr(_)  ..... name" << sym->name << " Type....." << sym->type << endl;
    return e;
}


void DEBUG_PRINTS_OFFSET(string str){
    // cout << "######################################################" << endl;
    // cout << "rule: " << str << endl;
    // cout << "programVarOffset: " << programVarOffset << endl;
    // cout << "functionLocalOffset: " << functionLocalOffset << endl;
    // cout << "formalArgOffset: " << formalArgOffset << endl;
    // cout << "scopeSpaceCounter: " << scopeSpaceCounter << endl;
}

expr *member_item(expr *lvalue , string name){

    lvalue = emit_ifTableItem(lvalue);//lvalue = result h lvalue = lvalue
    expr *item = newExpr( TABLE_ITEM_E );
    item->sym = lvalue->sym;
    item->index = newExprConstString(name);

    return item;
}

expr *newExpr( expr_t type ){
    expr *e = new expr();
    e->type = type;

    return e;
}

expr *newExprConstString(string s){
    expr *e = newExpr(CONST_STRING_E);
    e->str_const = s;
    
    return e;
}

expr *emit_ifTableItem(expr *e){

    if( e->type != TABLE_ITEM_E ){
        return e;
    }

    expr *result = newExpr( VAR_E );
    result->sym = newTmpVarName();

    emit(TABLEGETELEM , result , e , e->index , 0 , yylineno );

    return result;//apotelesma thesis pinaka
}


expr *make_call( expr *lvalue , expr *elist_container ){

    int elist_s = 0 , i;
    expr *func = emit_ifTableItem(lvalue) , *result;
    
    if(elist_container->elist==NULL){
        // cout<<"ERROR: to elist einai NULL"<<endl;
    }else{
        elist_s = elist_container->elist->size();
        // cout << "elist_container->elist->size() :" << elist_s << endl; 
    }
    for( i = elist_s -1; i >= 0 ; i-- ){
        emit(PARAM , NULL , &(elist_container->elist->at(i)) , NULL , 0 , yylineno);

        // print_const_from_type(  elist_container->elist->at(i) );
    }
    
    emit( CALL , func , NULL ,NULL , 0 , yylineno );
    result = newExpr( VAR_E );
    result->sym = newTmpVarName();
    emit( GETRETVAL , result , NULL , NULL , 0 , yylineno ); //TODO: check poy mpainei to result

    return result;
}

expr* newExpr_constNum(double i){
    expr* e = newExpr(CONST_NUM_E);
    e->num_const = i;
    return e;
}

expr *newExpr_constBool(int bool_val){
    expr* e = newExpr(CONST_BOOL_E);
    e->bool_const = bool_val;
    return e;
}

bool is_op_applicable(expr *e){

   
    assert(e);
    // cout << e->type << endl;fflush(stdout);

    if(
        e->type == CONST_BOOL_E   ||
        e->type == CONST_STRING_E ||
        e->type == NIL_E          ||
        e->type == NEW_TABLE_E    ||
        e->type == USER_FUNC_E    ||
        e->type == LIB_FUNC_E     ||
        e->type == BOOL_EXPR_E
    ){
        return false;
    }
    return true;
}

bool is_boolop_applicable (expr *e){
     assert(e);

    if(
        e->type == CONST_NUM_E     ||
        e->type == USER_FUNC_E     ||
        e->type == LIB_FUNC_E      ||
        e->type == NEW_TABLE_E
    ){
        return false;
    }
    return true;
}





void print_const_from_type(expr e ){
    switch(e.type){
        case CONST_NUM_E    : cout << "CONST_NUM_E is: " <<  e.num_const << endl;fflush(stdout); break;
        case CONST_BOOL_E   : cout << "CONST_BOOL_E is: " <<  e.bool_const << endl;fflush(stdout); break;
        case CONST_STRING_E : cout << "CONST_STRING_E is: " <<  e.str_const << endl;fflush(stdout); break;
        case NIL_E          : cout << "NIL_E is: " <<  "NIL"  << endl;fflush(stdout); break;
        default: ;
    }
}


void printQuads(){

    printf( "\x1B[34m""\n########################################     Intermediate code:     ########################################n\n""\x1B[0m"  );
    cout<<"quad#"<<setw(20)<<"opcode"<<setw(20)<<"result"<<setw(20)<<"arg1"<<setw(20)<<"arg2"<<setw(10)<<"label"<< setw(7) << "line" << endl;
    cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
    for(unsigned int i=0;i<quads.size();i++){
        bool printLabel=true;
        if(quads[i].label<=0 && quads[i].op!= JUMP  && quads[i].op!= JUMP_B   && quads[i].op!= JUMP_C){
            printLabel=false;
        }

        cout<< i/*+1*/ <<setw(20)<<iopcodeToString(quads[i])<<setw(20)<<expr_tToString(quads[i].result)<<setw(20)<<expr_tToString(quads[i].arg1);
        cout<<setw(20)<<expr_tToString(quads[i].arg2)<<setw(10)<< ((printLabel)? to_string(quads[i].label/*+1*/) : "" ) << setw(10) << quads[i].line << endl;
    }

    cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
}

string iopcodeToString(ioquad_t quad){
    
    
    switch(quad.op){
        case ASSIGN         : return "ASSIGN"; 
        case ADD            : return "ADD";
        case SUB            : return "SUB";
        case MUL            : return "MUL";
        case DIV            : return "DIV";
        case MOD            : return "MOD";
        case IO_UMINUS      : return "UMINUS";
        case IO_AND         : return "AND";
        case IO_NOT         : return "NOT";
        case IO_OR          : return "OR";
        case IF_EQ          : return "IF_EQ";
        case IF_NOTEQ       : return "IF_NOTEQ";
        case IF_LESSEQ      : return "IF_LESSEQ";
        case IF_GREATEREQ   : return "IF_GREATEREQ";
        case IF_LESS        : return "IF_LESS";
        case IF_GREATER     : return "IF_GREATER";
        case CALL           : return "CALL";
        case PARAM          : return "PARAM";
        case RET            : return "RET";
        case GETRETVAL      : return "GETRETVAL";
        case FUNCSTART      : return "FUNCSTART";
        case FUNCEND        : return "FUNCEND";
        case TABLECREATE    : return "TABLECREATE";
        case TABLEGETELEM   : return "TABLEGETELEM";
        case TABLESETELEM   : return "TABLESETELEM";
        case JUMP           : return "JUMP";
        case JUMP_B           : return "JUMP_B";
        case JUMP_C           : return "JUMP_C";

        default             : return "";
    }
}

string expr_tToString(expr* e){
    
    if(e == NULL){
        // cout << "expr is NULL" << endl; 
        // fflush(stdout);
        return "";
    }

    switch(e->type){
        case VAR_E          : return (e->sym==NULL)?    "-"    :    e->sym->name;
        case TABLE_ITEM_E   : return (e->sym==NULL)?    "-"    :    e->sym->name;   
        case USER_FUNC_E    : return (e->sym==NULL)?    "-"    :    e->sym->name;
        case LIB_FUNC_E     : return (e->sym==NULL)?    "-"    :    e->sym->name;
        case ARITHM_EXPR_E  : return (e->sym==NULL)?    "-"    :    e->sym->name; 
        case BOOL_EXPR_E    : return (e->sym==NULL)?    "-"    :    e->sym->name;
        case ASSIGN_EXPR_E  : return (e->sym==NULL)?    "-"    :    e->sym->name;
        case NEW_TABLE_E    : return (e->sym==NULL)?    "-"    :    e->sym->name;
        case CONST_NUM_E    : return to_string(e->num_const);
        case CONST_BOOL_E   : return (e->bool_const)?   "true" :    "false";
        case CONST_STRING_E : return (e->str_const);
        case NIL_E          : return "nil";

        default             : return "--";
    }
}