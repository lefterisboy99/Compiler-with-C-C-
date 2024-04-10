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
#include <math.h>
using namespace std;

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

struct userfunc {

    string id;
    unsigned int locals;
    unsigned int address;
};

vector <string>      string_table;
vector <double>      number_table;
vector <userfunc>    userfunc_table;
vector <string>      libfunc_table;
vector <instruction> instructions;

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
        cout << instructions.at(i).result.type  << "||" << instructions.at(i).result.val << "\t\t";
        cout << instructions.at(i).arg1.type    << "||" << instructions.at(i).arg1.val << "\t\t";
        cout << instructions.at(i).arg2.type    << "||" << instructions.at(i).arg2.val << "\t\t";
        cout << endl;
    }
}

/*
    AVM STUFF
*/

enum avm_memcell_t {
    
    number_m,
    string_m,
    bool_m,
    table_m,
    userfunc_m,
    libfunc_m,
    nil_m,
    undef_m
};

struct avm_table;
struct avm_memcell {
    avm_memcell_t type;
    union data {
        double      numVal;
        char*       stringVal;
        bool        boolVal;
        avm_table*  tableVal;
        unsigned    funcVal;
        char*       libfuncVal;

        data(){}
        ~data(){};

    } data;
};
vector <avm_memcell> stack(4096);
string typetostring(avm_memcell_t type) {
    switch (type)
    {
        case number_m : return "number";
        break;
        case string_m : return "string";
        break;
        case bool_m : return "bool";
        break;
        case table_m : return "table";
        break;
        case userfunc_m : return "userfunc";
        break;
        case libfunc_m : return "libfunc";
        break;
        case nil_m : return "nil";
        break;
        case undef_m : return "undef";
        break;
    }
}
void print_stack() {
    for (int i = stack.size() - 1; i>=0; i--) {
        if (stack.at(i).type == undef_m) {continue;}

        cout << typetostring(stack.at(i).type) << " : ";
        switch (stack.at(i).type)
        {
            case number_m : cout << stack.at(i).data.numVal << endl;
            break;
            case string_m : cout  << stack.at(i).data.stringVal << endl;
            break;
            case bool_m : cout  << stack.at(i).data.boolVal << endl;
            break;
            case table_m : cout  << stack.at(i).data.tableVal << endl;
            break;
            case userfunc_m : cout  << stack.at(i).data.funcVal << endl;
            break;
            case libfunc_m : cout << stack.at(i).data.libfuncVal << endl;
            break;
            case nil_m : cout  << stack.at(i).data.numVal << endl;
            break;
        }
    }
    cout << "========================" << endl;
}

void avm_memcellclear (avm_memcell* m) {

    m->type = undef_m;

    //todo tables !!!!!!!!!!!!!!!!!1
}

#define AVM_STACKENV_SIZE 4
#define AVM_STACKSIZE stack.size()
avm_memcell ax, bx, cx;
avm_memcell retval;
unsigned int totalGlobals;
unsigned top;
unsigned topsp;
unsigned char executionFinished;
unsigned        pc;
unsigned        currLine;
unsigned        codeSize;
instruction*    code = nullptr;
#define AVM_ENDING_PC codeSize

double consts_getnumber (unsigned index) {
    return number_table.at(index);
}
string consts_getstring (unsigned index) {
    return string_table.at(index);
}
string libfuncs_getused (unsigned index) {
    return libfunc_table.at(index);
}

avm_memcell* avm_translate_operand (vmarg* arg, avm_memcell* reg) {
    
    
    switch (arg->type)
    {
        case global_a:  return &stack.at(AVM_STACKSIZE - 1 - arg->val);
        case local_a:   return &stack.at(topsp - arg->val);
        case formal_a:  return &stack.at(topsp + AVM_STACKENV_SIZE + 1 + arg->val);

        case retval_a:  return &retval;

        case num_a: {
            reg->type = number_m;
            reg->data.numVal = consts_getnumber(arg->val);
            return reg;
        }
        case string_a: {
            reg->type = string_m;
            reg->data.stringVal = strdup((char*)consts_getstring(arg->val).c_str());
            return reg;
        }
        case bool_a: {
            reg->type = bool_m;
            reg->data.boolVal = arg->val;
            return reg;
        }
        case nil_a: {
            reg->type = nil_m;
            return reg;
        }
        case userfunc_a: {
            reg->type = userfunc_m;
            reg->data.funcVal = arg->val;
            return reg;
        }
        case libfunc_a: {
            reg->type = libfunc_m;
            reg->data.libfuncVal = strdup((char*)libfuncs_getused(arg->val).c_str());
            return reg;
        }

        default: assert(0);
    }
    
}

typedef void (*execute_func_t)(instruction*);
#define AVM_MAX_INSTRUCTIONS (unsigned) jump_v

void avm_warning (string format) {
    cout 
    << "\033[1m\033[1;33m" << 
        format <<
    "\033[0m" << endl;
}

void avm_error (string format) {
    cout 
    << "\033[1;31m" << 
        format <<
    "\033[0m" << endl;

    executionFinished = 1;
}

/*
    !TO BOOL
*/
typedef bool (*tobool_func_t)(avm_memcell*);

bool number_tobool(avm_memcell* m)   { return m->data.numVal != 0; }
bool string_tobool(avm_memcell* m)   { return m->data.stringVal[0] != 0; }
bool bool_tobool(avm_memcell* m)     { return m->data.boolVal;}
bool table_tobool(avm_memcell* m)    { return true;}
bool libfunc_tobool(avm_memcell* m)  { return true;}
bool userfunc_tobool(avm_memcell* m) { return true;}
bool nil_tobool(avm_memcell* m)      { return false;}
bool undef_tobool(avm_memcell* m)    { assert(0); return false;}

tobool_func_t toboolFuncs[] = {
    number_tobool,
    string_tobool,
    bool_tobool,
    table_tobool,
    userfunc_tobool,
    libfunc_tobool,
    nil_tobool,
    undef_tobool
};

bool avm_tobool (avm_memcell* m) {
    assert(m->type>=0 && m->type < undef_m);
    return (*toboolFuncs[m->type])(m);
}

bool comparison_eq (avm_memcell* m1, avm_memcell* m2) {
    switch (m1->type)
    {
        case 0 : 
        return (m1->data.numVal == m2->data.numVal);

        case 1:
        return (!strcmp(m1->data.stringVal, m2->data.stringVal));

        case 2:
        return (m1->data.boolVal == m2->data.boolVal);

        case 3:
        return (m1->data.tableVal == m2->data.tableVal);

        case 4:
        return (m1->data.funcVal == m2->data.funcVal);

        case 5:
        return (m1->data.libfuncVal == m2->data.libfuncVal);

        default : assert(0);
    }
}
bool comparison_nq (avm_memcell* m1, avm_memcell* m2) {
    switch (m1->type)
    {
        case 0 : 
        return (m1->data.numVal != m2->data.numVal);

        case 1:
        return (strcmp(m1->data.stringVal, m2->data.stringVal));

        case 2:
        return (m1->data.boolVal != m2->data.boolVal);

        case 3:
        return (m1->data.tableVal != m2->data.tableVal);

        case 4:
        return (m1->data.funcVal != m2->data.funcVal);

        case 5:
        return (m1->data.libfuncVal != m2->data.libfuncVal);

        default : assert(0);
    }
}
bool comparison_gq (avm_memcell* m1, avm_memcell* m2) {
    if(m1->type != number_m) assert(0);
    
    return (m1->data.numVal >= m2->data.numVal);
}
bool comparison_gt (avm_memcell* m1, avm_memcell* m2) {
    if(m1->type != number_m) assert(0);
    
    return (m1->data.numVal > m2->data.numVal);
}
bool comparison_lq (avm_memcell* m1, avm_memcell* m2) {
    if(m1->type != number_m) assert(0);
    
    return (m1->data.numVal <= m2->data.numVal);
}
bool comparison_lt (avm_memcell* m1, avm_memcell* m2) {
    if(m1->type != number_m) assert(0);
    
    return (m1->data.numVal < m2->data.numVal);
}

/*
    !function helper functions
*/

unsigned totalActuals = 0;
typedef void (*library_func_t)(void);

void avm_dec_top (void) {
    if (!top) {
        avm_error("stack overflow");
        executionFinished = 1;
    }
    else
        top--;
}

void avm_push_envvalue (unsigned val) {

    stack[top].type = number_m;
    stack[top].data.numVal = val;
    avm_dec_top();
}

void avm_callsaveenviroment (void) {

    avm_push_envvalue(totalActuals);
    avm_push_envvalue(pc + 1);
    avm_push_envvalue(top + totalActuals + 2);
    avm_push_envvalue(topsp);
}

userfunc* avm_getfuncinfo (unsigned address) {
    for (int i=0; i<userfunc_table.size(); i++) {
        
        if (address == userfunc_table.at(i).address)
            return &userfunc_table.at(i);
    }

    assert(0);
}

unsigned avm_getenvvalue (unsigned i) {

    assert(stack[i].type == number_m);
    unsigned val = (unsigned) stack[i].data.numVal;
    assert(stack[i].data.numVal == (double)val);
    return val;
}

typedef string (*tostring_func_t) (avm_memcell*);

string number_tostring (avm_memcell* m) {
    return to_string(m->data.numVal);
}
string string_tostring (avm_memcell* m ) {
    return m->data.stringVal;
}
string bool_tostring (avm_memcell* m) {
    return to_string(m->data.boolVal);
}
string table_tostring (avm_memcell* m) {
    return "A table";
}
string userfunc_tostring (avm_memcell* m) {
    return to_string(m->data.funcVal);
}
string libfunc_tostring (avm_memcell* m) {
    return m->data.libfuncVal;
}
string nil_tostring (avm_memcell* m) {
    return "nil";
}

string undef_tostring (avm_memcell* m) {
    return "undef";
}

tostring_func_t tostringFuncs[] = {
    number_tostring,
    string_tostring,
    bool_tostring,
    table_tostring,
    userfunc_tostring,
    libfunc_tostring,
    nil_tostring,
    undef_tostring
};

string avm_tostring (avm_memcell* m) {
    assert(m->type >=0 && m->type < undef_m);
    return (*tostringFuncs[m->type])(m);
}

map <string, library_func_t> libfuncs;

void avm_registerlibfunc(string id, library_func_t address) {
    libfuncs.insert(pair<string, library_func_t> (id, address));
}

library_func_t avm_getlibraryfunc (string id) {
    return libfuncs.at(id);
}

#define AVM_NUMACTUALS_OFFSET +4
#define AVM_SAVEDPC_OFFSET    +3
#define AVM_SAVEDTOP_OFFSET   +2
#define AVM_SAVEDTOPSP_OFFSET +1

void avm_calllibfunc (string id);

/*

!PINAKES!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

*/

#define AVM_TABLE_HASHSIZE 211
#define HASH_NUM 48000

struct avm_table_bucket {

    avm_memcell         key;
    avm_memcell         value;
    avm_table_bucket*   next;
};

struct avm_table {

    unsigned            refCounter;
    avm_table_bucket*   strIndexed[AVM_TABLE_HASHSIZE];
    avm_table_bucket*   numIndexed[AVM_TABLE_HASHSIZE];
    unsigned            total;
};

unsigned int hash_function(string name){
    unsigned int i, uiHASH ;
    for(i=0; i<name.size(); i++)
        uiHASH = uiHASH * HASH_NUM + name.at(i);

    return uiHASH % AVM_TABLE_HASHSIZE;
}

void avm_tablebucketdestroy (avm_table_bucket** p) {

    for (unsigned i=0; i<AVM_TABLE_HASHSIZE; i++, p++) {

        for (avm_table_bucket* b=*p; b;) {
            
            avm_table_bucket* del = b;
            b = b->next;
            avm_memcellclear(&del->key);
            avm_memcellclear(&del->value);
            free(del);
        }
        p[i] = nullptr;
    }
}

void avm_tabledestroy (avm_table* t) {
    avm_tablebucketdestroy(t->strIndexed);
    avm_tablebucketdestroy(t->numIndexed);
    free(t);
}

void avm_tableincrefcounter (avm_table* t) {
    ++t->refCounter;
}

void avm_tabledecrefcounter (avm_table* t) {
    assert(t->refCounter > 0);
    if (!--t->refCounter)
        avm_tabledestroy(t);
}

void avm_tablebucketsinit (avm_table_bucket** p) {
    for (unsigned i=0; i<AVM_TABLE_HASHSIZE;i++) {
        p[i] = nullptr;
    }
}

avm_table* avm_tablenew (void) {
    avm_table* t = new avm_table();
    memset(t, 0, sizeof(t));

    t->refCounter = t->total = 0;
    avm_tablebucketsinit(t->numIndexed);
    avm_tablebucketsinit(t->strIndexed);

    return t;
}

avm_memcell* avm_tablesetelem (avm_table* table, avm_memcell* index, avm_memcell* content) {
    assert(table && index && content);

    switch (index->type)
    {
        case string_m :
        {
            unsigned i = hash_function(avm_tostring(index));
            bool f = false;

            avm_table_bucket* tmp = table->strIndexed[i];
            avm_table_bucket* prev = new avm_table_bucket();
            while (tmp) {
                f = true;
                
                if (!strcmp(tmp->key.data.stringVal,index->data.stringVal))
                    break;
                
                prev = tmp;
                tmp = tmp->next;
            }

            if (!table->strIndexed[i]){
                table->strIndexed[i] = new avm_table_bucket();
                tmp = table->strIndexed[i];
            }  

            if (tmp && f) {
                tmp->value = *content;
            }else {
                if(f) tmp = new avm_table_bucket();

                tmp->value = *content;
                tmp->key.data.stringVal = strdup(index->data.stringVal);
                prev->next = tmp;
            }    
        }
        break;

        case number_m :
        {
            unsigned i = hash_function(avm_tostring(index));
            bool f = false;

            avm_table_bucket* tmp = table->numIndexed[i];
            avm_table_bucket* prev = new avm_table_bucket();
            while (tmp) {
                f = true;
                
                if (tmp->key.data.numVal == index->data.numVal)
                    break;
                
                prev = tmp;
                tmp = tmp->next;
            }

            if (!table->numIndexed[i]){
                table->numIndexed[i] = new avm_table_bucket();
                tmp = table->numIndexed[i];
            }  

            if (tmp && f) {
                tmp->value = *content;
            }else {
                if(f) tmp = new avm_table_bucket();

                tmp->value = *content;
                tmp->key.data.numVal = index->data.numVal;
                prev->next = tmp;
            } 
        }
        break;

        avm_error(typetostring(index->type) + " is not supported as index");
    }
}

avm_memcell* avm_tablegetelem (avm_table* table, avm_memcell* index) {

    switch (index->type)
    {
        case string_m :
        {
            unsigned i = hash_function(avm_tostring(index));
            avm_table_bucket* tmp = table->strIndexed[i];
            while (tmp) {
                if (!strcmp(tmp->key.data.stringVal,index->data.stringVal)){
                    return &tmp->value;
                }
                
                tmp = tmp->next;
            }
            return nullptr;
        }
        break;

        case number_m :
        {
            unsigned i = hash_function(avm_tostring(index));
            avm_table_bucket* tmp = table->numIndexed[i];
            while (tmp) {
                if (tmp->key.data.numVal == index->data.numVal){
                    return &tmp->value;
                }
                
                tmp = tmp->next;
            }
            return nullptr;
        }
        break;
    }
}

/*
    !EXECUTE INSTRUCTIONS
*/

void avm_assign  (avm_memcell* lv, avm_memcell* rv) {

    if (lv == rv)
        return;
    
    if (lv->type == table_m && 
        rv->type == table_m &&
        lv->data.tableVal == rv->data.tableVal)
        return ;

    if (rv->type == undef_m)
        avm_warning("assign from 'undef' content");

    memcpy(lv, rv, sizeof(avm_memcell));

    if (lv->type == string_m)
        lv->data.stringVal = rv->data.stringVal;
    else
    if (lv->type == table_m){}
        //avm_tabledecrefcounter(lv->data.tableVal);
}

void execute_assign (instruction* instr) {
    
    avm_memcell* lv = avm_translate_operand(&instr->result, nullptr);
    avm_memcell* rv = avm_translate_operand(&instr->arg1, &ax);
    //cout<<typetostring(lv->type)<<" "<<typetostring(rv->type)<<endl;
    assert(lv && (&stack[AVM_STACKSIZE - 1] >= lv && lv > &stack[top]) || lv == &retval);
    assert(rv);

    avm_assign(lv, rv);
    //cout<<typetostring(lv->type)<<" "<<typetostring(rv->type)<<endl;
}

#define execute_add execute_arithmetic
#define execute_sub execute_arithmetic
#define execute_mul execute_arithmetic
#define execute_div execute_arithmetic
#define execute_mod execute_arithmetic
double add_impl (double x, double y) { return x + y; }
double sub_impl (double x, double y) { return x - y; }
double mul_impl (double x, double y) { return x * y; }
double div_impl (double x, double y) { if (y==0) avm_error("division with zero"); return x / y; }
double mod_impl (double x, double y) { if (y==0) avm_error("division with zero"); return (unsigned)x % (unsigned)y; }
typedef double (*arithmetic_func_t)(double x, double y);
arithmetic_func_t arithmeticFuncs[] = {
    add_impl,
    sub_impl,
    mul_impl,
    div_impl,
    mod_impl
};
void execute_arithmetic (instruction* instr) {

    avm_memcell* lv = avm_translate_operand(&instr->result, nullptr);
    avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);
    avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &bx);

    assert(lv && (&stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top]));
    assert(rv1 && rv2);

    if (rv1->type != number_m || rv1->type != number_m) {
        avm_error("not a number in arithmetic");
        executionFinished = 1;
    }
    else {
        arithmetic_func_t op = arithmeticFuncs[instr->opcode - add_v];
        avm_memcellclear(lv);
        lv->type        =   number_m;
        lv->data.numVal =   (*op) (rv1->data.numVal, rv2->data.numVal);
    }
}

void execute_jump   (instruction* instr) { pc = instr->result.val - 1; }
void execute_jeq    (instruction* instr) {

    assert(instr->result.type == label_a);

    avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);
    avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &bx);

    bool result = false;

    if (rv1->type == undef_m || rv2->type == undef_m)
        avm_error("undef involved in equality");
    else
    if (rv1->type == nil_m || rv2->type == nil_m)
        result = rv1->type == nil_m && rv2->type == nil_m;
        
    else
    if (rv1->type == bool_m || rv2->type == bool_m)
        result = (avm_tobool(rv1) == avm_tobool(rv2));
    else
    if (rv1->type != rv2->type)
        avm_error(
            typetostring(rv1->type) + " == " + typetostring(rv2->type) + " is illegal"
        );
    else
        result = comparison_eq(rv1, rv2);

    if (!executionFinished && result){
        pc = instr->result.val - 1;
    }
        
}
void execute_jne    (instruction* instr) {

    assert(instr->result.type == label_a);

    avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);
    avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &bx);

    bool result = false;

    if (rv1->type == undef_m || rv2->type == undef_m)
        avm_error("undef involved in equality");
    else
    if (rv1->type == nil_m || rv2->type == nil_m)
        result = rv1->type == nil_m && rv2->type == nil_m;
    else
    if (rv1->type == bool_m || rv2->type == bool_m)
        result = (avm_tobool(rv1) == avm_tobool(rv2));
    else
    if (rv1->type != rv2->type)
        avm_error(
            typetostring(rv1->type) + " != " + typetostring(rv2->type) + " is illegal"
        );
    else
        result = comparison_nq(rv1, rv2);

    if (!executionFinished && result)
        pc = instr->result.val - 1;
}
void execute_jle    (instruction* instr) {

    assert(instr->result.type == label_a);

    avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);
    avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &bx);

    bool result = false;

    if (rv1->type == undef_m || rv2->type == undef_m)
        avm_error("undef involved in equality");
    else
    if (rv1->type == nil_m || rv2->type == nil_m)
        avm_error("error at opearation because of nil");
    else
    if (rv1->type != number_m || rv2->type != number_m)
        avm_error("error at opearation because of non number values");
    else
        result = comparison_lq(rv1, rv2);

    if (!executionFinished && result)
        pc = instr->result.val - 1;
}
void execute_jge    (instruction* instr) {

    assert(instr->result.type == label_a);

    avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);
    avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &bx);

    bool result = false;

    if (rv1->type == undef_m || rv2->type == undef_m)
        avm_error("undef involved in equality");
    else
    if (rv1->type == nil_m || rv2->type == nil_m)
        avm_error("error at opearation because of nil");
    else
    if (rv1->type != number_m || rv2->type != number_m)
        avm_error("error at opearation because of non number values");
    else
        result = comparison_gq(rv1, rv2);

    if (!executionFinished && result)
        pc = instr->result.val - 1;
}
void execute_jlt    (instruction* instr) {

    assert(instr->result.type == label_a);

    avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);
    avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &bx);

    bool result = false;

    if (rv1->type == undef_m || rv2->type == undef_m)
        avm_error("undef involved in equality");
    else
    if (rv1->type == nil_m || rv2->type == nil_m)
        avm_error("error at opearation because of nil");
    else
    if (rv1->type != number_m || rv2->type != number_m)
        avm_error("error at opearation because of non number values");
    else
        result = comparison_lt(rv1, rv2);

    if (!executionFinished && result)
        pc = instr->result.val - 1;
}
void execute_jgt    (instruction* instr) {

    assert(instr->result.type == label_a);

    avm_memcell* rv1 = avm_translate_operand(&instr->arg1, &ax);
    avm_memcell* rv2 = avm_translate_operand(&instr->arg2, &bx);

    bool result = false;

    if (rv1->type == undef_m || rv2->type == undef_m)
        avm_error("undef involved in equality");
    else
    if (rv1->type == nil_m || rv2->type == nil_m)
        avm_error("error at opearation because of nil");
    else
    if (rv1->type != number_m || rv2->type != number_m)
        avm_error("error at opearation because of non number values");
    else
        result = comparison_gt(rv1, rv2);

    if (!executionFinished && result)
        pc = instr->result.val - 1;
}

void execute_call   (instruction* instr) {
    //if(instr->result.type!=libfunc_a)  instr->result.type=userfunc_a;

    //cout<<"rggerr"<<instr->result.type<<endl;
    avm_memcell* func = avm_translate_operand(&instr->result, &ax);
    
    assert(func);
    avm_callsaveenviroment();
    assert(func->type);
    //cout<<typetostring(func->type)<<endl;
    switch (func->type)
    {
        case userfunc_m : {
            pc = func->data.funcVal - 1;
            assert(pc < AVM_ENDING_PC);
            assert(code[pc].opcode == funcenter_v);
            break;
        }

        case string_m : avm_calllibfunc(func->data.stringVal); break;
        case libfunc_m : avm_calllibfunc(func->data.libfuncVal); break;

        default : {
            string s = avm_tostring(func);
            avm_error("call cannot bind " + s + "to function");
            executionFinished = 1;
        }
    }
    
}
void execute_pusharg        (instruction* instr) {
    avm_memcell* arg = avm_translate_operand(&instr->result, &ax);
    assert(arg);

    avm_assign(&stack[top], arg);
    ++totalActuals;
    avm_dec_top();
}
void execute_funcenter      (instruction* instr) {

    avm_memcell* func = avm_translate_operand(&instr->result, &ax);
    assert(func);
    assert(pc == func->data.funcVal - 1);

    totalActuals = 0;
    userfunc* funcinfo = avm_getfuncinfo(pc + 1);
    topsp = top;
    top = top - funcinfo->locals;
}
void execute_funcexit       (instruction* instr) {
    unsigned oldTop = top;
    
    top     = avm_getenvvalue(topsp + AVM_SAVEDTOP_OFFSET);
    pc      = avm_getenvvalue(topsp + AVM_SAVEDPC_OFFSET);
    topsp   = avm_getenvvalue(topsp + AVM_SAVEDTOPSP_OFFSET);

    while (++oldTop <= top)
        avm_memcellclear(&stack[oldTop]);
}

void execute_newtable       (instruction* instr) {
    avm_memcell* lv = avm_translate_operand(&instr->result, nullptr);
    assert(lv && ( &stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top] || lv==&retval));

    avm_memcellclear(lv);

    lv->type = table_m;
    lv->data.tableVal = avm_tablenew();
    avm_tableincrefcounter(lv->data.tableVal);
}
void execute_tablegetelem   (instruction* instr) {

    avm_memcell* lv = avm_translate_operand(&instr->result, nullptr);
    avm_memcell* t  = avm_translate_operand(&instr->arg1, nullptr);
    avm_memcell* i  = avm_translate_operand(&instr->arg2, &ax);

    assert(lv && &stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top] || lv == &retval);
    assert(t && &stack[AVM_STACKSIZE-1] >= t && t > &stack[top]);
    assert(i);
    
    avm_memcellclear(lv);
    lv->type = nil_m;

    if (t->type != table_m)
        avm_error("illegal use of type " + typetostring(t->type) + " as table" );
    else
    {
        avm_memcell* content = avm_tablegetelem(t->data.tableVal, i);
        if (content)
            avm_assign(lv, content);
        else {
            string ts = avm_tostring(t);
            string is = avm_tostring(i);
            avm_warning(ts + "[" + is + "] not found");
        }
    }
}
void execute_tablesetelem   (instruction* instr) {
    avm_memcell* t =    avm_translate_operand(&instr->result, nullptr);
    avm_memcell* i =    avm_translate_operand(&instr->arg1, &ax);
    avm_memcell* c =    avm_translate_operand(&instr->arg2, &bx);

    assert(t && &stack[AVM_STACKSIZE-1] >= t && t > &stack[top]);
    assert(i && c);

    if (t->type != table_m)
        avm_error("illegal use of type " + typetostring(t->type) + " as table" );
    else{}
        avm_tablesetelem(t->data.tableVal, i, c);
}

void execute_nop     (instruction*) {}

void execute_uminus  (instruction*) { /*not used*/ }
void execute_and     (instruction*) { /*not used*/ }
void execute_or      (instruction*) { /*not used*/ }
void execute_not     (instruction*) { /*not used*/ }

execute_func_t executeFuncs[] = {
    
    execute_assign,
	execute_add,
	execute_sub,
	execute_mul,
	execute_div,
	execute_mod,
	execute_uminus,
	execute_and,
	execute_or,
	execute_not,
	execute_jeq,
	execute_jne,
	execute_jle,
	execute_jge,
	execute_jlt,
	execute_jgt,
    execute_call,
	execute_pusharg,
	execute_funcenter,
	execute_funcexit,
	execute_newtable,
    execute_tablegetelem,
	execute_tablesetelem,
	execute_nop,
    execute_jump
};

void avm_calllibfunc (string id) {
    library_func_t f = avm_getlibraryfunc(id);
    if (!f) {
        avm_error("unsupported lib func " + id + "is called");
        executionFinished = 1;
    }
    else {
        topsp = top;
        totalActuals = 0;
        (*f)();
        if (!executionFinished)
            execute_funcexit(nullptr);
    }
}

bool execute_cycle (void) {
    if (executionFinished)
        return false;
    else
    if  (pc == AVM_ENDING_PC) {
        executionFinished = 1;
        return false;
    }
    else {
        assert(pc < AVM_ENDING_PC);
        instruction* instr = code + pc;
        assert (
            instr->opcode >= 0 &&
            instr->opcode <= AVM_MAX_INSTRUCTIONS
        );
        if (instr->srcLine)
            currLine = instr->srcLine;
        unsigned oldPc = pc;
        (*executeFuncs[instr->opcode])(instr);
        if (pc == oldPc)
            ++pc;
    }
    return true;
}


/*



!LIBRARY FUNCTIONS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



*/

//!prepare for library functions
unsigned avm_totalactuals (void) {
    return avm_getenvvalue(topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell* avm_getactual (unsigned i) {
    assert(i < avm_totalactuals());
    return &stack[topsp + AVM_STACKENV_SIZE + 1 + i];
}

void libfunc_print (void) {

    unsigned n = avm_totalactuals();
    for (unsigned i=0; i<n; ++i) {
        string s = avm_tostring(avm_getactual(i));
        cout << s;
    }
}
void libfunc_typeof (void) {

    unsigned n = avm_totalactuals();

    if (n!=1)
        avm_error("one argument expected in typeof not " + n);
    else
    {
        avm_memcellclear(&retval);
        retval.type = string_m;
        retval.data.stringVal = strdup(typetostring(avm_getactual(0)->type).c_str());
    }
}
//todo OUTSIDE OF CLASS --- ASSERT INSTEAD OF ERROR ---
void libfunc_totalarguments (void) {

    unsigned p_topsp = avm_getenvvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
    avm_memcellclear (&retval);

    if (!p_topsp) {
        avm_error("'totalarguments' called outside a function");
        retval.type = nil_m;
    }else
    {
        retval.type = number_m;
        retval.data.numVal = avm_getenvvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
    }
}
void libfunc_sqrt (void) {

    unsigned n = avm_totalactuals();

    if (n!=1)
        avm_error("one argument expected in sqrt");
    else
    if (avm_getactual(0)->type != number_m)
        avm_error("number as argument expected in sqrt not " + typetostring(avm_getactual(0)->type));
    else
    {
        avm_memcellclear(&retval);
        retval.type = number_m;
        retval.data.numVal = sqrt(avm_getactual(0)->data.numVal);
    }
}