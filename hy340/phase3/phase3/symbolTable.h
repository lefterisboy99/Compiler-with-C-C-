#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <cstdio>
#include <assert.h>
#include <string.h>
#include <map>

#define BUCKET_NUM 256
#define HASH_NUM 48000

using namespace std;
#define currQuad quads.size() + 1

struct expr;
struct SymbolTableEntry;


unsigned programVarOffset    = 0;
unsigned functionLocalOffset = 0;
unsigned formalArgOffset     = 0;
unsigned scopeSpaceCounter   = 1;


bool lwarning = false;
bool fflag = false;
int FUNC_DEPTH = 0;
int loop_counter=0;
vector <SymbolTableEntry> BUCKETS[BUCKET_NUM];
vector <vector<SymbolTableEntry> > SCOPE_LISTS;


enum iopcode {
    assign,         add,            sub,
    mul,            _div,            mod,
    uminus,         _and,           _or,
    _not,           if_eq,          if_noteq,
    if_lesseq,      if_greatereq,   if_less,
    if_greater,     call,           param,
    ret,            getretval,      funcstart,
    funcend,        tablecreate,    jump,
    tablegetelem,   tablesetelem    
};

enum expr_t {

    var_e,
    tableitem_e,

    programfunc_e,
    libraryfunc_e,

    arithexpr_e,
    boolexpr_e,
    assignexpr_e,

    constnum_e,
    constbool_e,
    conststring_e,

    nil_e
};

enum SymbolType {
    GLOBAL, LLOCAL, FORMAL , USERFUNC, LIBFUNC
};

enum symbol_t {
    var_s,
    programfunc_s,
    libraryfunc_s
};


struct quad {
    iopcode     code;
    expr*       result;
    expr*       arg1;
    expr*       arg2;
    unsigned    label;
    unsigned    line;
};

vector <quad> quads;


enum scopespace_t {
    programvar,
    functionlocal,
    formalarg
};

struct expr {
    expr_t              type;
    SymbolTableEntry*   sym;
    expr*               index;
    double              numConst;
    char*               strConst;
    bool                boolConst;
    expr*               next;

    vector <int> truelist;
    vector <int> falselist;
};

typedef struct Variable{
    string name;
    unsigned int scope;
    unsigned int line;
    unsigned int func_depth;
} Variable;

typedef struct Function {
    string name;
    //List of argumends
    unsigned int scope;
    unsigned int line;
    unsigned int func_depth;
    unsigned int iaddress;
    unsigned int totalLocals;
} Function;


typedef struct SymbolTableEntry {
    bool isActive = true;
    union {
        Variable *varVal;
        Function *funVal;
    } value;
    enum SymbolType type;
    symbol_t        type_s;
    scopespace_t    space;
    unsigned        offset;
} SymbolTableEntry;


void emit (
    iopcode     op,
    expr*       arg1,
    expr*       arg2,
    expr*       result,
    unsigned    label,
    unsigned    line

)   {
    quad* q = new quad;
    q->code   =     op;
    q->arg1   =     arg1;
    q->arg2   =     arg2;
    q->result =     result;
    q->label  =     label;
    q->line   =     line;
    quads.push_back(*q);
}


string get_name(SymbolTableEntry entry){

    string name;

    if(entry.type == USERFUNC || entry.type == LIBFUNC)
        name = entry.value.funVal->name;
    else
        name = entry.value.varVal->name;

    return name;
}

bool isFunction(SymbolTableEntry entry){
    if(entry.type == LIBFUNC || entry.type == USERFUNC)
        return true;
    return false;
}


/*
struct symbol{
    symbol_t        type;
    string          name;
    scopespace_t    space;
    unsigned        offset;
    unsigned        scope;
    unsigned        line;
    unsigned        iaddress;
    unsigned        totalLocals;
};*/

//! C overload...
void print_quads(){
    //Basic laels
    cout << "quad#\topcode\t\t\tresult\t\targ1\t\targ2\t\tlabel" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
    
    for(int i=0; i<quads.size(); i++){
        string op;
        switch (quads.at(i).code)
        {
        case add: op = "ADD";
            break;
        case assign: op = "ASSIGN";
            break;
        case sub: op = "SUB";
            break;
        case mul: op = "MUL";
            break;
        case _div: op = "DIV";
            break;
        case mod: op = "MOD";
            break;
        case uminus: op = "UMINUS";
            break;
        case _and: op = "AND";
            break;
        case _or: op = "OR";
            break;
        case _not: op = "NOT";
            break;
        case if_eq: op = "IF_EQUAL";
            break;
        case if_noteq: op = "IF_NOT_EQUAL";
            break;
        case if_lesseq: op = "IF_LESS_EQ";
            break;
        case if_greatereq: op = "IF_GREATER_EQ";
            break;
        case if_less: op = "IF_LESS";
            break;
        case if_greater: op = "IF_GREATER";
            break;
        case call: op = "CALL";
            break;
        case param: op = "PARAM";
            break;
        case ret: op = "RETURN";
            break;
        case getretval: op = "GET_RET_VAL";
            break;
        case funcstart: op = "FUNC_START";
            break;
        case funcend: op = "FUNC_END";
            break;
        case tablecreate: op = "TABLE_CREATE";
            break;
        case tablegetelem: op = "TABLE_GET_ELEM";
            break;
        case tablesetelem: op = "TABLE_SET_ELEM";
            break;
        case jump: op = "JUMP";
            break;
        
        default:
            assert(0);
        }

        cout << i+1 << ":\t" << 
        op;

        //=====================
            if(op == "TABLE_GET_ELEM" || op == "TABLE_SET_ELEM"  || op == "FUNC_END" || op == "GET_RET_VAL" || op == "TABLE_CREATE"||
               op == "FUNC_START" || op == "IF_GREATER" || op == "IF_GREATER_EQ" || op == "IF_EQUAL" || op == "IF_NOT_EQUAL" ||
               op == "IF_LESS_EQ" )
            {
                cout << "\t\t";
            }
            else if(op == "JUMP")
            {
                cout << "\t\t\t\t\t\t\t";
            }
            else
            {
                cout << "\t\t\t";
            }
        //=====================

        if(quads.at(i).result != nullptr)
            if(quads.at(i).result->sym != nullptr){
               if(isFunction(*quads.at(i).result->sym)){
                   cout<<quads.at(i).result->sym->value.varVal->name;
               }else {
                    
                    cout<<quads.at(i).result->sym->value.funVal->name;
               }
            }else
            {
                if(quads.at(i).result->type == constnum_e)
                    cout << quads.at(i).result->numConst << ' ';
                else
                if(quads.at(i).result->type == constbool_e)
                    cout << ((quads.at(i).result->boolConst) ? "true" : "false") << ' ';
                else
                if(quads.at(i).result->type == conststring_e)
                    cout << "\"" <<  quads.at(i).result->strConst << "\""  << ' ';
                else
                if(op != "IF_GREATER" && op != "IF_GREATER_EQ" && op != "IF_EQUAL"  &&
                    op != "IF_LESS" && op != "IF_LESS_EQ" && op != "IF_NOT_EQUAL")
                {
                    cout << "nil" << ' ';
                }
            }

            if(quads.at(i).arg1 != nullptr)
                if(quads.at(i).arg1->sym != nullptr)
                    if(isFunction(*quads.at(i).arg1->sym)){
                        cout<< "\t\t" <<quads.at(i).arg1->sym->value.varVal->name;
                    }else {                       
                        cout<< "\t\t" <<quads.at(i).arg1->sym->value.funVal->name;
                 }
               else
                {
                    if(quads.at(i).arg1->type == constnum_e)
                        cout << "\t\t" << quads.at(i).arg1->numConst << ' ';
                    else
                    if(quads.at(i).arg1->type == constbool_e)
                        cout << "\t\t" << ((quads.at(i).arg1->boolConst) ? "true" : "false") << ' ';
                    else
                    if(quads.at(i).arg1->type == conststring_e)
                        cout<< "\t\t" << "\""  << quads.at(i).arg1->strConst << "\""  << ' ';

                          
                        cout << "\t\t";
                }

            if(quads.at(i).arg2 != nullptr)
                if(quads.at(i).arg2->sym != nullptr)
                    if(isFunction(*quads.at(i).arg2->sym)){
                        cout<< "\t\t" <<quads.at(i).arg2->sym->value.funVal->name;
                    }else {                          
                        cout<< "\t\t" <<quads.at(i).arg2->sym->value.funVal->name;
                
               }
                else
                {
                    if(quads.at(i).arg2->type == constnum_e)
                        cout << "\t\t" << quads.at(i).arg2->numConst << ' ';
                    else
                    if(quads.at(i).arg2->type == constbool_e)
                        cout << "\t\t" << ((quads.at(i).arg2->boolConst) ? "true" : "false") << ' ';
                    else
                    if(quads.at(i).arg2->type == conststring_e)
                        cout<< "\t\t"  << "\""  << quads.at(i).arg2->strConst << "\""  << ' ';

                    if(quads.at(i).arg2->type == constbool_e){}
                    else
                    if(op!="IF_LESS")  
                        cout << "\t\t";
                }
            
            if(quads.at(i).label != 0){
                cout << "\t\t";

                cout << quads.at(i).label;
            }

        cout << endl;
    }
}

expr* lvalue_expr (SymbolTableEntry* sym) {
    assert(sym);
    expr* e = new expr;
    memset(e, 0, sizeof(expr));

    e->next = nullptr;
    e->sym = sym;
    
    switch (sym->type_s)
    {
        case var_s          : e->type = var_e;          break;
        case programfunc_s  : e->type = programfunc_e;  break;
        case libraryfunc_s  : e->type = libraryfunc_e;  break;
        default             : assert(0);
    }
    return e;
}

expr* new_expr (expr_t t) {
    expr* e = new expr();
    memset(e, 0, sizeof(expr));
    e->type = t;

    return e;
}


unsigned int hash_function(string name){
    unsigned int i, uiHASH ;
    for(i=0; i<name.size(); i++)
        uiHASH = uiHASH * HASH_NUM + name.at(i);

    return uiHASH % BUCKET_NUM;
}


scopespace_t currscopespace(void) {
    if(scopeSpaceCounter == 1)
        return programvar;
    else
    if(scopeSpaceCounter % 2 == 0)
        return formalarg;
    else
        return functionlocal;
}

unsigned int currscopeoffset(void) {
    switch (currscopespace())
    {
        case programvar     : return programVarOffset;
        case functionlocal  : return functionLocalOffset;
        case formalarg      : return formalArgOffset;
        default             : assert(0);
    }
}


void inccurentscopeoffset(void) {
    switch (currscopespace())
    {
        case programvar     : ++programVarOffset; break;
        case functionlocal  : ++functionLocalOffset; break;
        case formalarg      : ++formalArgOffset; break;
        default             : assert(0);
    }
}

void inccurentscopeoffset(unsigned n) {
    switch (currscopespace())
    {
        case programvar     : programVarOffset = n; break;
        case functionlocal  : functionLocalOffset = n; break;
        case formalarg      : formalArgOffset = n; break;
        default             : assert(0);
    }
}

void check_arith (expr* e, const string context, int line) {
    if (e->type == constbool_e    ||
        e->type == conststring_e  ||
        e->type == nil_e          ||
        e->type == tableitem_e    ||
        e->type == programfunc_e  ||
        e->type == libraryfunc_e  ||
        e->type == boolexpr_e )

    cout << "\033[1;31m" <<          
    context << line <<
    " \033[0m" << endl;
}

SymbolTableEntry* update_entry(SymbolTableEntry entry) {

    if(isFunction(entry)){
        if(entry.type == LIBFUNC)
            entry.type_s = libraryfunc_s;
        else
            entry.type_s = programfunc_s;
    }else{
        entry.type_s    = var_s;
    }

    entry.space  = currscopespace();
    entry.offset = currscopeoffset();
    inccurentscopeoffset();

    SymbolTableEntry *sym = new SymbolTableEntry;
    memcpy(sym, &entry, sizeof(entry));

    return sym;
}

SymbolTableEntry *Lookup_scope(SymbolTableEntry entry,int scope){

    int i;
    if(SCOPE_LISTS.size() <= scope)
            SCOPE_LISTS.resize(scope + 1);
            

    for(int i=0; i<SCOPE_LISTS.at(scope).size(); i++)
        if(get_name(SCOPE_LISTS.at(scope).at(i)) == get_name(entry))
            if(SCOPE_LISTS.at(scope).at(i).isActive)
                return &SCOPE_LISTS.at(scope).at(i);

    return nullptr;
}

SymbolTableEntry *Lookup(SymbolTableEntry entry, int scope){
    if(SCOPE_LISTS.size() <= scope)
            SCOPE_LISTS.resize(scope + 1);

      SymbolTableEntry *entry_ptr;  

    while(scope>=0){
        entry_ptr = Lookup_scope(entry,scope);
        if(entry_ptr != nullptr)
            return entry_ptr;
        --scope;
    }
    return nullptr;
}

void Insert(SymbolTableEntry entry){
    int scope;
    if(isFunction(entry))
        scope = entry.value.funVal->scope;
    else
        scope = entry.value.varVal->scope;

    //! exception handling
    SymbolTableEntry *entry_ptr = Lookup(entry, scope);
    SymbolTableEntry *entry_ptr_glb=Lookup_scope(entry,0);
    
    
    //! inertion
    unsigned int index = hash_function(get_name(entry));
    BUCKETS[index].push_back(entry);


    SCOPE_LISTS.at(scope).push_back(entry);
    return; 
}

void Insert_local(SymbolTableEntry entry){
    int scope;
    if(isFunction(entry))
        scope = entry.value.funVal->scope;
    else
        scope = entry.value.varVal->scope;

    //! exception handling
    SymbolTableEntry *entry_ptr = Lookup(entry, 0);
    if(entry_ptr){
        if(entry_ptr->type == LIBFUNC){
            cout << "\033[1;31m" << 
                "Trying to shadow library function at line "<< entry.value.funVal->line <<
                "\033[0m" << endl;

            return;
        }
    }
    
    //! inertion
    unsigned int index = hash_function(get_name(entry));
    BUCKETS[index].push_back(entry);


    SCOPE_LISTS.at(scope).push_back(entry);
    return; 
}


SymbolTableEntry create_entry(string name, int scope, unsigned int line, SymbolType type, unsigned int func_depth){
    SymbolTableEntry entry;
    entry.type = type;

    if(isFunction(entry)){
        entry.value.funVal = new Function();
        entry.value.funVal->line = line;
        entry.value.funVal->name = name;
        entry.value.funVal->scope = scope;
        entry.value.funVal->func_depth = func_depth;
    }else{
        entry.value.varVal = new Variable();
        entry.value.varVal->line = line;
        entry.value.varVal->name = name;
        entry.value.varVal->scope = scope;
        entry.value.varVal->func_depth = func_depth;
    }
    
    return entry;   
}

unsigned int tempcounter = 0;
SymbolTableEntry* newtemp ( int scope, unsigned int line, unsigned int func_depth) {

    string temp_name = "_t";
    temp_name += to_string(tempcounter++);

    SymbolTableEntry entry = create_entry(temp_name, scope, line, LLOCAL, func_depth);

    if(!Lookup_scope(entry,scope))
        Insert(entry);
        
    SymbolTableEntry *sym = new SymbolTableEntry;
    memcpy(sym, update_entry(entry), sizeof(entry));

    return sym;
}



expr* emit_iftableitem(expr* e, int scope, unsigned int line, unsigned int func_depth) {
    if(!e) return e;

    if(e->type != tableitem_e)
        return e;

    expr* result = new_expr(var_e);
    result->sym = newtemp(scope, line, func_depth);
    emit(tablegetelem, e, e->index, result, 0, line);

    return result;
}

expr* member_item (expr* lv, char* name, int scope, unsigned int line, unsigned int func_depth) {
    lv = emit_iftableitem(lv, scope, line, func_depth); // Emit code if r-value use of table item
    expr* ti = new_expr(tableitem_e); // Make a new expression

    ti->sym = lv->sym;
    ti->index = new_expr(conststring_e); // Const string index
    ti->index->strConst = name;

    return ti;
}

vector <expr*> scopeoffsetStack;

void enterscopespace(void) {
    ++scopeSpaceCounter;
}

void exitscopespace(void) {
    assert(scopeSpaceCounter>1);
    --scopeSpaceCounter;
}

void resetformalargsoffset(void){
    formalArgOffset = 0;
}

void resetfunctionlocalsoffset(void){
    functionLocalOffset = 0;
}



unsigned nextquadlabel(void) {
    return currQuad;
}

void patchlabel (unsigned quadNo, unsigned label) {
    assert(quadNo < currQuad);
    quads.at(quadNo - 1).label = label;
}

expr* make_call (expr* lv, vector <expr*> reversed_elist, int scope, unsigned int line, unsigned int func_depth) {
    expr* func = emit_iftableitem(lv, scope, line, func_depth);

    while (!reversed_elist.empty()) {
        emit(param, nullptr, nullptr, reversed_elist.back(), 0, line);
        reversed_elist.pop_back();
    }

    emit(call ,nullptr, nullptr, func, 0, line);
    expr* result = new_expr(var_e);
    result->sym = newtemp(scope, line, func_depth);
    emit(getretval, nullptr, nullptr, result, 0, line);
    
    return result;
}

struct call {
    expr*           elist;
    unsigned char   method;
    char*           name;
};

struct forJump {
    unsigned int enter;
    unsigned int test;
};

struct stmt_t {
    int breakList, contList;
};

void make_stmt (stmt_t* s){
    s->breakList = s->contList = 0; 
}

int newlist (int i) { 
    quads.at(i).label = 0; return i; 
}

int mergelist (int l1, int l2) {
    if (!l1)
        return l2;
    else
        if (!l2)
            return l1;
    else {
        int i = l1;
        while (quads.at(i).label)
            i = quads.at(i).label;

        quads.at(i).label = l2;
        return l1;
    }
}

void patchlist (int list, int label) {
    while (list && quads.size() > list) {
        int next = quads.at(list).label;
        quads.at(list).label = label;
        list = next;
    }
}

unsigned int istempname (string s) {
    return s[0] == '_';
}

unsigned int istempexpr (expr* e) {
    return e->sym && e->sym->value.varVal && istempname(e->sym->value.varVal->name);
}

unsigned char op_isValid(expr* arg1, expr* arg2, int line, expr_t type1, expr_t type2) {
    if(arg1->type == arg2->type && arg1->type != type1 && arg1->type != type2) return true;

    cout << "\033[1;31m" <<          
    "Constant type error at line " << line <<
    " \033[0m" << endl;

    return false;
}

void backpatch(vector <int> list, int quadLabel) {

    for(int i=0; i<list.size(); i++){
        quads.at(list.at(i) - 1).label = quadLabel;
    }
}

bool truetest(expr* expr) {

    switch (expr->type)
    {
    case constnum_e :
        return expr->numConst != 0;

    case libraryfunc_e :
        return true;

    case programfunc_e :
        return true;

    case tableitem_e :
        return true;

    case nil_e :
        return false;
    
    case conststring_e :
        return expr->strConst != "";

    default:
        break;
    }
}

/////////////////////////////////

SymbolTableEntry* assign_temp(expr* arg1, expr* arg2, int SCOPE, int yylineno, int FUNC_DEPTH ) {

    if(istempexpr(arg1))
        return arg1->sym;
    else
    if(istempexpr(arg2))
        return arg2->sym;
    else
        return newtemp(SCOPE, yylineno, FUNC_DEPTH);
}


unsigned int func_counter = 0;
string generate_function_name(){
    string func_name = "_f";
    func_name += to_string(func_counter++);
    return func_name;
}


//Functions

unsigned int get_scope(SymbolTableEntry entry){
    if(entry.type == LIBFUNC || entry.type == USERFUNC)
        return entry.value.funVal->scope;
    return entry.value.varVal->scope;
}

unsigned int get_func_depth(SymbolTableEntry entry){
    if(entry.type == LIBFUNC || entry.type == USERFUNC)
        return entry.value.funVal->func_depth;
    return entry.value.varVal->func_depth;
}



void Hide(unsigned int scope){
    if(SCOPE_LISTS.size() <= scope)
            SCOPE_LISTS.resize(scope + 1);

    for(int i=0; i<SCOPE_LISTS.at(scope).size(); i++)
        SCOPE_LISTS.at(scope).at(i).isActive = false;
}

void Show(unsigned int scope){
    for(int i=0; i<SCOPE_LISTS.at(scope).size(); i++)
        SCOPE_LISTS.at(scope).at(i).isActive = true;
}



ostream& operator<<(ostream& os, const SymbolTableEntry entry)
{
    if(entry.type == 3 || entry.type == 4){
        os << "\"" << entry.value.funVal->name << "\" ";
        if(entry.type == 0)
            os << "[global variable]";
        if(entry.type == 1)
            os << "[local variable]";
        if(entry.type == 2)
            os << "[formal argument]";
        if(entry.type == 3)
            os << "[user function] local vars: " << entry.value.funVal->totalLocals << endl;
        if(entry.type == 4)
            os << "[library function]";
        os << " (line " << entry.value.funVal->line << ')' << endl;
    }else{
        os << "\"" << entry.value.varVal->name << "\" ";
        if(entry.type == 0)
            os << "[global variable]";
        if(entry.type == 1)
            os << "[local variable]";
        if(entry.type == 2)
            os << "[formal argument]";
        if(entry.type == 3)
            os << "[user function]";
        if(entry.type == 4)
            os << "[library function]";
        os << " (line " << entry.value.varVal->line << ')' << endl;
    }

    return os;
}

void print_symbol_table()
{
    int i,j;
    for(i=0; i<SCOPE_LISTS.size(); i++){
        if(SCOPE_LISTS.at(i).size() != 0)
            cout << endl <<  "----------        Scope #" << i << "       ----------" << endl << endl;
        for(j=0; j<SCOPE_LISTS.at(i).size(); j++)
            cout << SCOPE_LISTS.at(i).at(j);
    }
    cout << endl ;
}