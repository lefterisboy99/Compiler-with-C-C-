#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <assert.h>
#include <string.h>
#include <map>
#include <algorithm>

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
    unsigned    taddress;

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
    bool                istemp=false;
    unsigned            inststart;
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
    unsigned        offset = 11111;
    unsigned        taddress;
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

            cout << " (" << quads.at(i).line << ") "; 
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

                    if(op != "TABLE_SET_ELEM") 
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

    SymbolTableEntry* symret = Lookup_scope(entry,scope);
    if(!symret) {
        entry.space  = currscopespace();
        entry.offset = currscopeoffset();
        inccurentscopeoffset();
        Insert(entry);
    }else{
        entry.space  = symret->space;
        entry.offset = symret->offset;
    }
        
    SymbolTableEntry *sym = new SymbolTableEntry;
    memcpy(sym, update_entry(entry), sizeof(entry));

    return sym;
}

SymbolTableEntry* newtemp_nolookup ( int scope, unsigned int line, unsigned int func_depth) {

    string temp_name = "_t";
    temp_name += to_string(tempcounter++);

    SymbolTableEntry entry = create_entry(temp_name, scope, line, LLOCAL, func_depth); 
    entry.space  = currscopespace();
    entry.offset = currscopeoffset();
    inccurentscopeoffset();
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
    result->sym = newtemp_nolookup(scope, line, func_depth);
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
    if(func->istemp==false){
        result->istemp=1;
        result->next=func;
        
        
    }else{
        result->istemp=1;
        result->next=func->next;
        
    }

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

    exit(-1);
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
        os << endl;
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
        os << " (line " << entry.value.funVal->line << ')' << "\t{ " << "offset : " << entry.offset << " }" << endl;
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

void print_stack(vector <SymbolTableEntry*> STACK) {
    int i;
    for (i=0; i<STACK.size(); i++) cout << STACK.at(i)->value.varVal->name << endl;
}

union value {
    int    Integer;
    double Real;
    char*  String; 
    bool   Boolean;
};

/*
================================================================
================================================================
================================================================
================================================================
================================================================
================================================================
================================================================
================================================================
================================================================
================================================================
================================================================
================================================================
*/

unsigned currprocessedquad = 0;

enum vmarg_t {

    label_a,//0
    retval_a,//1

    userfunc_a,//2
    libfunc_a,//3

    num_a,//4
    bool_a,//5
    string_a,//6

    global_a,//7
    local_a,//8
    formal_a,//9

    nil_a//10
};

enum vmopcode {
    assign_v,       add_v,          sub_v,
    mul_v,          div_v,          mod_v,
    uminus_v,       and_v,          or_v,
    not_v,          jeq_v,          jne_v,
    jle_v,          jge_v,          jlt_v,
    jgt_v,          call_v,         pusharg_v,
    funcenter_v,    funcexit_v,     newtable_v,
    tablegetelem_v,  tablesetelem_v, nop_v,jump_v
};

struct vmarg { 
    vmarg_t type; 
    unsigned val; 
};

struct instruction {
    vmopcode    opcode;
    vmarg       result;
    vmarg       arg1;
    vmarg       arg2;
    unsigned    srcLine;
};

vector <instruction> instructions;
void iemit (instruction i) {instructions.push_back(i);}

struct userfunc {

    unsigned int scope;
    unsigned int address;
    unsigned int locals;
    string id;  
};

struct incomplete_jump {

    unsigned    instrNo;
    unsigned    iaddress;
};
vector <incomplete_jump> incomplete_jumps;
vector <unsigned>        funcexit_labels;
multimap <int, int>      return_map;
map <unsigned, unsigned> funcenter_jump;

void add_incomplete_jump (unsigned iaddress, unsigned instrNo) {
    incomplete_jump ij;
    ij.iaddress = iaddress;
    ij.instrNo = instrNo;

    incomplete_jumps.push_back(ij);
}

#define currInstruction instructions.size();
unsigned nextinstructionlabel() {
    return currInstruction;
}


void patch_incomplete_jumps(){

    for(int i=0;i<incomplete_jumps.size();i++){

        if(incomplete_jumps.at(i).iaddress > quads.size()){

            instructions.at(incomplete_jumps.at(i).instrNo).result.val = instructions.size() + 1;
            // if jump label > quads
        }
        else if(incomplete_jumps.at(i).iaddress == quads.size()){
            instructions.at(incomplete_jumps.at(i).instrNo).result.val = instructions.size();
        }
        else{
            if(quads.at(incomplete_jumps.at(i).iaddress-1).code == ret)
                instructions.at(incomplete_jumps.at(i).instrNo).result.val = quads.at(incomplete_jumps.at(i).iaddress).taddress - 1;
            else
                instructions.at(incomplete_jumps.at(i).instrNo).result.val = quads.at(incomplete_jumps.at(i).iaddress).taddress;

            //?STUPID SOLUTION ?????
            if (instructions.at(instructions.at(incomplete_jumps.at(i).instrNo).result.val - 1).opcode == funcenter_v)
                instructions.at(incomplete_jumps.at(i).instrNo).result.val--;
        }
    }
}

vector <string>                 string_table;
vector <double>                 number_table;
vector <userfunc>               userfunc_table;
vector <string>                 libfunc_table;

unsigned consts_newstring (string s) {
    for (int i=0; i<string_table.size(); i++) {

        if (s == string_table.at(i) )
            return i;
    }

    assert(0);
}
unsigned consts_newnumber (double n) {
    for (int i=0; i<number_table.size(); i++) {
        
        if (n == number_table.at(i) )
            return i;
    }
    assert(0);
}
unsigned userfunc_newused (SymbolTableEntry* sym) {
    for (int i=0; i<userfunc_table.size(); i++) { 
        
        if 
        (
            sym->value.funVal->name == userfunc_table.at(i).id &&
            userfunc_table.at(i).scope==sym->value.funVal->scope &&
            userfunc_table.at(i).locals==sym->value.funVal->totalLocals
        )
        {
            return i;
        }
    }

    assert(0);
}

void addInFunc (SymbolTableEntry* sym) {
    userfunc f;
    f.address = nextinstructionlabel()+1;
    f.id = sym->value.funVal->name;
    f.locals = sym->value.funVal->totalLocals;
    f.scope = sym->value.funVal->scope;
    //cout<<"put"<<f.address<<" "<<f.scope<<endl;
    userfunc_table.push_back(f);
    
    
}


unsigned libfuncs_newused (string s) {
    for (int i=0; i<libfunc_table.size(); i++) {
        
        if (s == libfunc_table.at(i))
            return i;
    }

    assert(0);
}

unsigned totalGlobals = 0;
void make_operand (expr* e, vmarg* arg) {
    if(!e) e = new_expr(nil_e);
    //! variable for storage
    //cout<<"here"<<currprocessedquad<<endl;
    switch (e->type)
    {
        case var_e:
        case tableitem_e:
        case arithexpr_e:
        case assignexpr_e:
        case boolexpr_e:  {

            arg->val = e->sym->offset;
            
            switch (e->sym->space)
            {
                
                case programvar     : arg->type = global_a; break;
                case functionlocal  : arg->type = local_a; break;
                case formalarg      : arg->type = formal_a; break;

                default : assert(0);
            }
            break;
        }

        //!constants
        case constbool_e : {
            arg->val = e->boolConst;
            arg->type = bool_a;
            break;
        }

        case conststring_e : {
            arg->val = consts_newstring(e->strConst);
            arg->type = string_a;
            break;
        }

        case constnum_e : {
            arg->val = consts_newnumber(e->numConst);
            arg->type = num_a;
            break;
        }

        case nil_e : {
            arg->type = nil_a;
            break;
        }

        //!functions

        //todo CHECK WHAT IADRRESS NEEDS TO BE
        case programfunc_e : {
            arg->type = userfunc_a;
            //cout<<"here"<<currprocessedquad<<endl;
            if( quads.at(currprocessedquad).code == funcstart ){
                arg->val  = nextinstructionlabel()+1;
                addInFunc(e->sym);
            }else{
                arg->val=userfunc_table.at(userfunc_newused(e->sym)).address;
                //cout<<arg->val<<endl;
            }
            break;
        }

        case libraryfunc_e : {
            arg->type = libfunc_a;
            arg->val  = libfuncs_newused(e->sym->value.funVal->name);
            break;
        }

        default : assert(0);
    }
}

void make_numberoperand (vmarg* arg, double val) {

    arg->val = consts_newnumber(val);
    arg->type = num_a;
}

void make_booloperand (vmarg* arg, double val) {

    arg->val = consts_newnumber(val);
    arg->type = bool_a;
}

void make_retvaloperand (vmarg* arg) {

    arg->type = retval_a;
}

void reset_operand (vmarg* arg) {
    arg = nullptr;
}

void generate (vmopcode op, quad* q)
{
    instruction t;
    t.opcode = op;
    make_operand(q->arg1, &t.arg1);
    make_operand(q->arg2, &t.arg2);
    make_operand(q->result, &t.result);
    q->taddress = nextinstructionlabel();

    t.srcLine = q->line;

    iemit(t);

    switch (op)
    {
        case add_v :
        {
            if (q->arg1->type == constnum_e && q->arg2->type == constnum_e)
                number_table.push_back(q->arg1->numConst + q->arg2->numConst);
            break;
        }

        case sub_v :
        {
            if (q->arg1->type == constnum_e && q->arg2->type == constnum_e)
                number_table.push_back(q->arg1->numConst - q->arg2->numConst);
            break;
        }

        case mul_v :
        {
            if (q->arg1->type == constnum_e && q->arg2->type == constnum_e)
                number_table.push_back(q->arg1->numConst * q->arg2->numConst);
            break;
        }

        case div_v :
        {
            if (q->arg1->type == constnum_e && q->arg2->type == constnum_e && q->arg2->numConst != 0) {    
                number_table.push_back(q->arg1->numConst / q->arg2->numConst);
            break;
        }

        case mod_v :
        {
            if (q->arg1->type == constnum_e && q->arg2->type == constnum_e && q->arg2->numConst != 0)
                number_table.push_back((int)q->arg1->numConst % (int)q->arg2->numConst);
            break;
        }
    }

    }
    
}

void generate_relational (vmopcode op, quad* q)
{
    instruction t;
    t.opcode = op;
    make_operand(q->arg1, &t.arg1);
    make_operand(q->arg2, &t.arg2);
    t.result.type = label_a;

    t.srcLine = q->line;
    
    if (q->label < currprocessedquad){        
        t.result.val = quads.at(q->label).taddress;
    }else{
        add_incomplete_jump(q->label,nextinstructionlabel());
    }
    q->taddress = nextinstructionlabel();
    iemit(t);

    
}

void generate_ADD (quad* q)              { generate(add_v, q); }
void generate_SUB (quad* q)              { generate(sub_v, q); }
void generate_MUL (quad* q)              { generate(mul_v, q); }
void generate_DIV (quad* q)              { generate(div_v, q); }
void generate_MOD (quad* q)              { generate(mod_v, q); }


void generate_NEWTABLE (quad* q)         { generate(newtable_v, q); }
void generate_TABLEGETELEM (quad* q)     { generate(tablegetelem_v, q); }
void generate_TABLESETELEM (quad* q)     { generate(tablesetelem_v, q); }
void generate_ASSIGN (quad* q)           { generate(assign_v, q); }
void generate_NOP (quad* q)              { instruction t; t.opcode = nop_v; iemit(t); }


void generate_IF_EQ (quad* q)            { generate_relational(jeq_v, q); }
void generate_IF_NOTEQ (quad* q )        { generate_relational(jne_v, q); }
void generate_IF_GREATER (quad* q)       { generate_relational(jgt_v, q); }
void generate_IF_GREATEREQ (quad* q)     { generate_relational(jge_v, q); }
void generate_IF_LESS (quad* q)          { generate_relational(jlt_v, q); }
void generate_IF_LESSEQ (quad* q)        { generate_relational(jle_v, q); }
void generate_JUMP (quad* q)             { generate_relational(jump_v, q);}

void generate_NOT (quad* q) {

    q->taddress = nextinstructionlabel();
    instruction t;

    t.opcode = jeq_v;
    make_operand(q->arg1, &t.arg1);
    make_booloperand(&t.arg2, false);
    t.result.type = label_a;
    t.result.val = nextinstructionlabel()+3;
    iemit(t);

    t.opcode = assign_v;
    make_booloperand(&t.arg1, false);
    reset_operand(&t.arg2);
    make_operand(q->result, &t.result);
    iemit(t);

    t.opcode = jump_v;
    reset_operand (&t.arg1);
    reset_operand(&t.arg2);
    t.result.type = label_a;
    t.result.val = nextinstructionlabel()+2;
    iemit(t);

    t.opcode = assign_v;
    make_booloperand(&t.arg1, true);
    reset_operand(&t.arg2);
    make_operand(q->result, &t.result);
    iemit(t);
}

void generate_OR (quad* q) {
    q->taddress = nextinstructionlabel();
    instruction t;

    t.opcode = jeq_v;
    make_operand(q->arg1, &t.arg1);
    make_booloperand(&t.arg2, true);
    t.result.type = label_a;
    t.result.val = nextinstructionlabel()+4;
    iemit(t);

    make_operand(q->arg2, &t.arg1);
    t.result.val = nextinstructionlabel()+3;
    iemit(t);

    t.opcode = assign_v;
    make_booloperand(&t.arg1, false);
    reset_operand(&t.arg2);
    make_operand(q->result, &t.result);
    iemit(t);

    t.opcode = jump_v;
    reset_operand (&t.arg1);
    reset_operand(&t.arg2);
    t.result.type = label_a;
    t.result.val = nextinstructionlabel()+2;
    iemit(t);

    t.opcode = assign_v;
    make_booloperand(&t.arg1, true);
    reset_operand(&t.arg2);
    make_operand(q->result, &t.result);
    iemit(t);
}

void generate_AND (quad* q) {

    q->taddress = nextinstructionlabel();
    instruction t;

    t.opcode = jeq_v;
    make_operand(q->arg1, &t.arg1);
    make_booloperand(&t.arg2, true);
    t.result.type = label_a;
    t.result.val = nextinstructionlabel()+4;
    iemit(t);

    make_operand(q->arg2, &t.arg1);
    t.result.val = nextinstructionlabel()+3;
    iemit(t);

    t.opcode = assign_v;
    make_booloperand(&t.arg1, false);
    reset_operand(&t.arg2);
    make_operand(q->result, &t.result);
    iemit(t);

    t.opcode = jump_v;
    reset_operand (&t.arg1);
    reset_operand(&t.arg2);
    t.result.type = label_a;
    t.result.val = nextinstructionlabel()+2;
    iemit(t);

    t.opcode = assign_v;
    make_booloperand(&t.arg1, true);
    reset_operand(&t.arg2);
    make_operand(q->result, &t.result);
    iemit(t);
}

void generate_PARAM (quad* q) {
    q->taddress = nextinstructionlabel();
    instruction t;
    t.opcode = pusharg_v;
    
    make_operand(q->result, &t.result);

    t.srcLine = q->line;
    
    iemit(t);
}

void generate_CALL (quad* q) {

    map <unsigned, unsigned> :: iterator it = funcenter_jump.find(q->result->sym->value.funVal->iaddress);
    if (it != funcenter_jump.end()) {
        q->result->sym->taddress = it->second;
    }

    q->taddress = nextinstructionlabel();
    instruction t;
    t.opcode = call_v;
    make_operand(q->result, &t.result);

    t.srcLine = q->line;
        
    iemit(t);
}

instruction retval;

void generate_GETRETVAL (quad* q) {
    q->taddress = nextinstructionlabel();
    instruction t;
    t.opcode = assign_v;
    make_operand(q->result, &t.result);
    make_retvaloperand(&t.arg1);

    t.srcLine = q->line;

    iemit(t);
}

void generate_FUNCSTART (quad* q) {
    SymbolTableEntry* fsym=q->result->sym;
    fsym->taddress=nextinstructionlabel()+2;
    q->taddress=nextinstructionlabel();
    instruction _t;
    _t.opcode = jump_v;
    funcexit_labels.push_back(nextinstructionlabel());

    _t.srcLine = q->line;
    iemit(_t);

    instruction t;
    t.opcode = funcenter_v;
    make_operand(q->result, &t.result);

    t.srcLine = q->line;
    iemit(t);

    

    funcenter_jump.insert(pair<unsigned, unsigned>(q->result->sym->value.funVal->iaddress, nextinstructionlabel()));
}

void generate_RETURN (quad* q) {
    q->taddress = nextinstructionlabel();
    instruction t;
    t.opcode = assign_v;
    make_retvaloperand(&t.result);
    //cout<<"here is return";
    make_operand(q->result,&t.arg1);
    t.srcLine = q->line;
    iemit(t);

    return_map.insert(pair<int, int>(funcexit_labels.back(), nextinstructionlabel()));
    //cout<<"this is val"<<t.arg1.val<<endl;
    t.opcode = jump_v;
    reset_operand(&t.arg1);
    reset_operand(&t.arg2);
    t.result.type = label_a;

    t.srcLine = q->line;
    iemit(t);
}

void generate_FUNCEND (quad* q) {
    //todo pop/backpach funcstack

    q->taddress = nextinstructionlabel();
    instruction t;
    t.opcode = funcexit_v;
    make_operand(q->result, &t.result);

    t.srcLine = q->line;
    iemit(t);

    instructions.at(funcexit_labels.back()).result.val = nextinstructionlabel() + 1;
    
    map <int, int> :: iterator it = return_map.find(funcexit_labels.back());
    while((it != return_map.end()) && (it->first == funcexit_labels.back())) {
        instructions.at(it->second).result.val = nextinstructionlabel();
        return_map.erase(it);
        it = return_map.find(funcexit_labels.back());
    }
    funcexit_labels.pop_back();
}

void generate_UMINUS (quad* q) {
    expr* e = new_expr(constnum_e);
    e->numConst = -1;
    number_table.push_back(e->numConst);
    number_table.push_back(-1*q->arg1->numConst);

    instruction t;
    t.opcode = mul_v;
    make_operand(q->arg1, &t.arg1);
    make_operand(q->result, &t.result);
    make_operand(e,&t.arg2);

    t.srcLine = q->line;
    iemit(t);
}

typedef void (*generator_func_t)(quad*);
generator_func_t generators[] = {

	generate_ASSIGN,
	generate_ADD,
	generate_SUB,
	generate_MUL,
	generate_DIV,
	generate_MOD,
	generate_UMINUS,
	generate_AND,
	generate_OR,
	generate_NOT,
	generate_IF_EQ,
	generate_IF_NOTEQ,
	generate_IF_LESSEQ,
	generate_IF_GREATEREQ,
	generate_IF_LESS,
	generate_IF_GREATER,
    generate_CALL,
	generate_PARAM,
	generate_RETURN,
	generate_GETRETVAL,
	generate_FUNCSTART,
	generate_FUNCEND,
	generate_NEWTABLE,
    generate_JUMP,
	generate_TABLEGETELEM,
	generate_TABLESETELEM
};

void run_generate (void) {
    for (currprocessedquad = 0; currprocessedquad<quads.size(); currprocessedquad++){
        
        if(quads.at(currprocessedquad).result==nullptr){
            quads.at(currprocessedquad).result=new_expr(nil_e);
        }
        if(quads.at(currprocessedquad).arg1==nullptr){
            quads.at(currprocessedquad).arg1=new_expr(nil_e);
        }
        if(quads.at(currprocessedquad).arg2==nullptr){
            quads.at(currprocessedquad).arg2=new_expr(nil_e);
        }
        (*generators[quads.at(currprocessedquad).code])(&quads.at(currprocessedquad));
    }
    patch_incomplete_jumps();
}


void print_instructions(){
    //Basic laels
    cout << "instructions#\t\topcode\t\t\tresult\t\targ1\t\targ2\t\tlabel" << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    
    for(int i=0; i<instructions.size(); i++){
        string op;
        switch (instructions.at(i).opcode)
        {
        case add_v: op = "ADD";
            break;
        case assign_v: op = "ASSIGN";
            break;
        case sub_v: op = "SUB";
            break;
        case mul_v: op = "MUL";
            break;
        case div_v: op = "DIV";
            break;
        case mod_v: op = "MOD";
            break;
        case uminus_v: op = "UMINUS";
            break;
        case and_v: op = "AND";
            break;
        case or_v: op = "OR";
            break;
        case not_v: op = "NOT";
            break;
        case nop_v: op = "NOP";
            break;
        case call_v: op = "CALL";
            break;
        case pusharg_v: op = "PUSHARG";
            break;
        case funcenter_v: op = "FUNC_ENTER";
            break;
        case funcexit_v: op = "FUNC_EXIT";
            break;
        case newtable_v: op = "NEW_TABLE";
            break;
        case tablegetelem_v: op = "TABLE_GET_ELEM";
            break;
        case tablesetelem_v: op = "TABLE_SET_ELEM";
            break;
        case jump_v: op = "JUMP";
            break;
        case jle_v: op = "JLE";
            break;
        case jeq_v: op = "JEQ";
            break;
        case jne_v: op = "JNE";
            break;
        case jge_v: op = "JGE";
            break;
        case jlt_v: op = "JLT";
            break;
        case jgt_v: op = "JGT";
            break;
        
        default:
            assert(0);
        }

        cout << i+1 << ":\t" << 
        op;

        //=====================
            if(op == "TABLE_GET_ELEM" || op == "TABLE_SET_ELEM"  || op == "FUNC_ENTER" || op == "FUNC_EXIT"  )
            {
                cout << "\t\t";
            }
            else if(op == "JUMP" || op == "JLE"  || op == "JEQ" || op == "JNE" || op == "JGE" || op == "JLT" || op=="JGT")
            {
                cout << "\t\t\t";
            }
            else
            {
                cout << "\t\t\t";
            }
        //=====================
        string result_type,arg1_type,arg2_type;
        
        switch (instructions.at(i).result.type)
        {
            case 0: result_type = "label_a";
                break;
            case 1: result_type = "retval_a";
                break;
            case 2: result_type = "userfunc_a";
                break;
            case 3: result_type = "libfunc_a";
                break;
            case 4: result_type = "num_a";
                break;
            case 5: result_type = "bool_a";
                break;
            case 6: result_type = "string_a";
                break;
            case 7: result_type = "global_a";
                break;
            case 8: result_type = "local_a";
                break;
            case 9: result_type = "formal_a";
                break;
            case 10: result_type = "nil_a";
                break;
            default:
                result_type="";
            
        }
        
        switch (instructions.at(i).arg1.type)
        {
            case 0: arg1_type = "label_a";
                break;
            case 1: arg1_type = "retval_a";
                break;
            case 2: arg1_type = "userfunc_a";
                break;
            case 3: arg1_type = "libfunc_a";
                break;
            case 4: arg1_type = "num_a";
                break;
            case 5: arg1_type = "bool_a";
                break;
            case 6: arg1_type = "string_a";
                break;
            case 7: arg1_type = "global_a";
                break;
            case 8: arg1_type = "local_a";
                break;
            case 9: arg1_type = "formal_a";
                break;
            case 10: arg1_type = "nil_a";
                break;
            default:
                arg1_type="";
        }

        switch (instructions.at(i).arg2.type)
        {
            case 0: arg2_type = "label_a";
                break;
            case 1: arg2_type = "retval_a";
                break;
            case 2: arg2_type = "userfunc_a";
                break;
            case 3: arg2_type = "libfunc_a";
                break;
            case 4: arg2_type = "num_a";
                break;
            case 5: arg2_type = "bool_a";
                break;
            case 6: arg2_type = "string_a";
                break;
            case 7: arg2_type = "global_a";
                break;
            case 8: arg2_type = "local_a";
                break;
            case 9: arg2_type = "formal_a";
                break;
            case 10: arg2_type = "nil_a";
                break;
            default:
                arg2_type="";
        }
        cout << instructions.at(i).result.type << "||" << instructions.at(i).result.val << "\t\t";
        cout << instructions.at(i).arg1.type << "||" << instructions.at(i).arg1.val << "\t\t";
        cout << instructions.at(i).arg2.type << "||" << instructions.at(i).arg2.val << "\t\t";
        cout << endl;
    }
}

void print_number_table(){
    for (int i=0; i<number_table.size(); i++){
        cout << i << " : " << number_table.at(i) << endl;
    }
}

void print_string_table(){
    for (int i=0; i<string_table.size(); i++){
        cout << i << " : " << string_table.at(i) << endl;
    }
}

void print_libfunc_table(){
    for (int i=0; i<libfunc_table.size(); i++){
        cout << i << " : " << libfunc_table.at(i) << endl;
    }
}

void print_userfunc_table(){
    for (int i=0; i<userfunc_table.size(); i++){
        cout << i << " : Name-> "<< userfunc_table.at(i).id <<", ";
        cout << "No Locals->" << userfunc_table.at(i).locals << ", ";
        cout << "Address->" << userfunc_table.at(i).address << endl;
    }
}

unsigned update_max_length(unsigned old, unsigned new_) {
    return (new_ > old) ? new_ : old;
}

void create_binary(){
    unsigned long max_length = 0;

    FILE* wf = fopen("binary.abc", "wb");

    //! save magic number
    unsigned int magic = 340200501;
    fwrite(&magic, sizeof(unsigned int), 1, wf);

    //! save string table
    unsigned long string_table_size = string_table.size();
    fwrite(&string_table_size, sizeof(unsigned long), 1, wf);
    for (int i=0; i<string_table.size(); i++) {
        unsigned long size = string_table.at(i).length() + 1;
        max_length = update_max_length(max_length, size);

        fwrite(&size, sizeof(unsigned long), 1, wf);
        fwrite(string_table.at(i).c_str(), sizeof(char)*size, 1, wf);
    }
    //! save number table
    unsigned long number_table_size = number_table.size();
    fwrite(&number_table_size, sizeof(unsigned long), 1, wf);
    for (int i=0; i<number_table.size(); i++) {

        fwrite(&number_table.at(i), sizeof(double), 1, wf);
    }

    //!save userfunc table
    unsigned long userfunc_table_size = userfunc_table.size();
    fwrite(&userfunc_table_size, sizeof(unsigned long), 1, wf);
    for (int i=0; i<userfunc_table.size(); i++) {
        unsigned long size = userfunc_table.at(i).id.length() + 1;
        max_length = update_max_length(max_length, size);

        fwrite(&size, sizeof(unsigned long), 1, wf);
        fwrite(userfunc_table.at(i).id.c_str(), sizeof(char)*size, 1, wf);

        fwrite(&userfunc_table.at(i).locals, sizeof(unsigned int), 1, wf);
        
        fwrite(&userfunc_table.at(i).address, sizeof(unsigned int), 1, wf);
    }

    //! save libfunc table
    unsigned long libfunc_table_size = libfunc_table.size();
    fwrite(&libfunc_table_size, sizeof(unsigned long), 1, wf);
    for (int i=0; i<libfunc_table.size(); i++) {
        unsigned long size = libfunc_table.at(i).length() + 1;
        max_length = update_max_length(max_length, size);

        fwrite(&size, sizeof(unsigned long), 1, wf);
        fwrite(libfunc_table.at(i).c_str(), sizeof(char)*size, 1, wf);
    }

    //! save instructions
    unsigned int value;
    unsigned int type;
    unsigned int opcode;
    unsigned int total_instructions = instructions.size();
    fwrite(&total_instructions, sizeof(unsigned int), 1, wf);
    for(int i=0; i<total_instructions; i++) {
        opcode = instructions.at(i).opcode;
        fwrite(&opcode, sizeof(unsigned int), 1, wf);

        type = instructions.at(i).arg1.type;
        value = instructions.at(i).arg1.val;
        fwrite(&type, sizeof(unsigned int), 1, wf);
        fwrite(&value, sizeof(unsigned int), 1, wf);

        type = instructions.at(i).arg2.type;
        value = instructions.at(i).arg2.val;
        fwrite(&type, sizeof(unsigned int), 1, wf);
        fwrite(&value, sizeof(unsigned int), 1, wf);

        type = instructions.at(i).result.type;
        value = instructions.at(i).result.val;
        fwrite(&type, sizeof(unsigned int), 1, wf);
        fwrite(&value, sizeof(unsigned int), 1, wf);

        unsigned line = instructions.at(i).srcLine;
        fwrite(&line, sizeof(unsigned), 1, wf);
    }

    //!save total globals
    unsigned int totalGlobals = 0;
    for(int i=0; i<SCOPE_LISTS.size(); i++){
        if(SCOPE_LISTS.at(i).size() != 0)
        for(int j=0; j<SCOPE_LISTS.at(i).size(); j++)
            if (!isFunction(SCOPE_LISTS.at(i).at(j)) && SCOPE_LISTS.at(i).at(j).space == programvar)
                ++totalGlobals;
    }
    fwrite(&totalGlobals, sizeof(unsigned int), 1, wf);
    
    fclose(wf);
    /*
    FILE* rf = fopen("binary.abc", "rb");
    unsigned long size;
    char test[max_length];
    double tes;
    char id[max_length];
    unsigned int locals;
    unsigned int address;
    char lib[max_length];

    //! print magic number
    fread(&magic, sizeof(unsigned int), 1, rf);
    cout << magic << endl;

    cout << endl;
    //! print string table
    fread(&string_table_size, sizeof(unsigned long), 1, rf);
    for (int i=0; i<string_table_size; i++){

        fread(&size, sizeof(unsigned long), 1, rf);
        fread(test, sizeof(char) * size, 1, rf);
        cout << test << endl;
    }
    cout << endl;

    //! print number table
    fread(&number_table_size, sizeof(unsigned long), 1, rf);
    for (int i=0; i<number_table_size; i++){

        fread(&tes, sizeof(double), 1, rf);
        cout << tes << endl;
    }
    cout << endl;

    //! print userfunc table
    fread(&userfunc_table_size, sizeof(unsigned long), 1, rf);
    for (int i=0; i<userfunc_table_size; i++){

        fread(&size, sizeof(unsigned long), 1, rf);
        fread(id, sizeof(char) * size, 1, rf);

        fread(&locals, sizeof(unsigned int), 1, rf);

        fread(&address, sizeof(unsigned int), 1, rf);

        cout << id << " -> locals: " << locals << " -> address: " << address << endl;
    }
    cout << endl;
    
    //! print libfunc table
    fread(&libfunc_table_size, sizeof(unsigned long), 1, rf);
    for (int i=0; i<libfunc_table_size; i++){

        fread(&size, sizeof(unsigned long), 1, rf);
        fread(lib, sizeof(char) * size, 1, rf);
        cout << lib << endl;
    }
    cout << endl;
    

    //! print instructions
    fread(&total_instructions, sizeof(unsigned int), 1, rf);
    for(int i=0; i<total_instructions; i++) {
        fread(&opcode, sizeof(unsigned int), 1, rf);
        cout << opcode << "\t";

        fread(&type, sizeof(unsigned int), 1, rf);
        fread(&value, sizeof(unsigned int), 1, rf);
        cout << type << "||" << value << "\t\t";

        fread(&type, sizeof(unsigned int), 1, rf);
        fread(&value, sizeof(unsigned int), 1, rf);
        cout << type << "||" << value << "\t\t";
        
        fread(&type, sizeof(unsigned int), 1, rf);
        fread(&value, sizeof(unsigned int), 1, rf);
        cout << type << "||" << value << endl;
    }

    */
    /*
        MAGIC NUMBER
        STRING TABLE SIZE
        ->INDEX ELEMENT SIZE
        ->INDEX VALUE (STRING)
        ->...
        NUMBER TABLE SIZE
        ->INDEX VALUE (DOUBLE)
        ->...
        USERFUNC TABLE SIZE
        ->INDEX ID ELEMENT SIZE
        ->INDEX ID VALUE(STRING)
        ->INDEX LOCALS VALUE(UNSIGNED INT)
        ->INDEX ADDRESS VALUE(UNSIGNED INT)
        ->...
        LIBFUNC TABLE SIZE
        ->INDEX ELEMENT SIZE
        ->INDEX VALUE (STRING)
        ->...
        TOTAL INSTRUCTION NUMBER
        ->OPCODE
        ->ARG1 VALUE
        ->ARG1 TYPE
        ->ARG2 VALUE
        ->ARG2 TYPE
        ->RESULT VALUE
        ->RESULT TYPE
        ->...
        TOTAL GLOBALS
    */
}