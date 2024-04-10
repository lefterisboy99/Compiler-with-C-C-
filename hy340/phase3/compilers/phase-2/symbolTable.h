#include <string>
#include <list>
#include <vector>
#include<iostream>
#include <cstdio>

#define BUCKET_NUM 256
#define HASH_NUM 48000

using namespace std;

bool lwarning = false;
bool fflag = false;
int FUNC_DEPTH = 0;
int loop_counter=0;
vector <string> active_func;

enum SymbolType {
    GLOBAL, LLOCAL, FORMAL , USERFUNC, LIBFUNC
};

unsigned int func_counter = 0;
string generate_function_name(){
    string func_name = "_f";
    func_name += to_string(func_counter++);
    return func_name;
}

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
} Function;

typedef struct SymbolTableEntry {
    bool isActive = true;
    union {
        Variable *varVal;
        Function *funVal;
    } value;
    enum SymbolType type;
} SymbolTableEntry;

vector <SymbolTableEntry> BUCKETS[BUCKET_NUM];
vector <vector<SymbolTableEntry> > SCOPE_LISTS;

//Functions

bool isFunction(SymbolTableEntry entry){
    if(entry.type == LIBFUNC || entry.type == USERFUNC)
        return true;
    return false;
}

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

string get_name(SymbolTableEntry entry){

    string name;

    if(entry.type == USERFUNC || entry.type == LIBFUNC)
        name = entry.value.funVal->name;
    else
        name = entry.value.varVal->name;

    return name;
}

unsigned int hash_function(string name){
    unsigned int i, uiHASH ;
    for(i=0; i<name.size(); i++)
        uiHASH = uiHASH * HASH_NUM + name.at(i);

    return uiHASH % BUCKET_NUM;
}

SymbolTableEntry *Lookup_scope(SymbolTableEntry entry,int scope){

    int i;
    if(SCOPE_LISTS.size() <= scope)
            SCOPE_LISTS.resize(scope + 1);
            

    for(int i=0; i<SCOPE_LISTS.at(scope).size(); i++)
        if(get_name(SCOPE_LISTS.at(scope).at(i)) == get_name(entry))
            if(SCOPE_LISTS.at(scope).at(i).isActive)
                return &SCOPE_LISTS.at(scope).at(i);

    return NULL;
}

SymbolTableEntry *Lookup(SymbolTableEntry entry, int scope){
    if(SCOPE_LISTS.size() <= scope)
            SCOPE_LISTS.resize(scope + 1);

      SymbolTableEntry *entry_ptr;  

    while(scope>=0){
        entry_ptr = Lookup_scope(entry,scope);
        if(entry_ptr != NULL)
            return entry_ptr;
        --scope;
    }
    return NULL;
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
            os << "[user function]";
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