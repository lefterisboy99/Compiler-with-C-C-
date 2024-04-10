#include <iostream>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <stdbool.h>
#include <assert.h>
#include <iomanip>
#include <string.h> 
#include <utility>
#include <algorithm>


using namespace std;

typedef enum type
{
    GLOBAL_VAR,
    FUNC_ARG,
    LOCAL_VAR,
    USER_FUNC,
    LIB_FUNC,
} type_t;

typedef enum scope_space{
    PROGRAM_VAR,
    FUNCTION_LOCAL,
    FORMAL_ARG    
}scope_space_t;

typedef  enum symbol{
    VAR_S,
    USER_FUNC_S,
    LIB_FUNC_S
}symbol_t;

typedef enum expr_t{
    VAR_E ,
    TABLE_ITEM_E,

    USER_FUNC_E,
    LIB_FUNC_E,

    ARITHM_EXPR_E,
    BOOL_EXPR_E ,
    ASSIGN_EXPR_E,
    NEW_TABLE_E,

    CONST_NUM_E,
    CONST_BOOL_E,
    CONST_STRING_E,

    NIL_E,
    TMP_E
      
}expr_t;

typedef enum iopcode{
    ADD          = 0 ,
    SUB          = 1, 
    MUL          = 2,
    DIV          = 3,
    MOD          = 4 ,
    TABLECREATE  = 5,
    TABLEGETELEM = 6 ,
    TABLESETELEM = 7,
    ASSIGN       = 8,
    JUMP         = 9 ,
    IF_EQ        = 10 ,
    IF_NOTEQ     = 11,
    IF_GREATER   = 12, 
    IF_GREATEREQ = 13,
    IF_LESS      = 14,
    IF_LESSEQ    = 15,
    IO_NOT       = 16,
    IO_OR        = 17,
    IO_AND       = 18,
    PARAM        = 19,
    CALL         = 20, 
    GETRETVAL    = 21,
    FUNCSTART    = 22,
    RET          = 23,
    FUNCEND      = 24,
    IO_UMINUS    = 25,
    JUMP_B       = 26,     
    JUMP_C       = 27 
}iopcode;

typedef struct node
{
    symbol_t type_s;
    scope_space_t scope_space;//program , local or argument (var)
    unsigned long int offset;
    unsigned int iaddress;
    int total_locals;
    
    bool is_var;
    string name;
    type_t type;  //symbol type
    unsigned short int scope;
    unsigned long line_num;
    void *args;
    bool is_active;
    long int func_j; 
    struct node *next;
} node_t;

typedef struct expr{
    expr_t type;
    node_t *sym;//symbol
    expr *index;
    double num_const;
    string str_const;
    int bool_const;
    vector <expr> *elist;
    pair<expr,expr> *ipair; 
    vector<pair<expr,expr>> *ilist;
    vector <long int> *truelist;
    vector <long int> *falselist;    
}expr;

typedef struct quad {
    iopcode op;
    expr *result;
    expr *arg1;
    expr *arg2;
    long int label;
    unsigned long line;
    unsigned taddress;
}ioquad_t;

typedef struct type_of_call{
    vector <expr> *elist;
    bool is_method;
    char *name;
}type_of_call_t;

typedef struct forNode{
	unsigned long enter;
	unsigned long test;
}forNode_t;


extern unsigned short int scope;
extern vector <string> active_func_name;


node_t *look_up(string key);
node_t *LookUp_Scope(string name,int scope);
node_t *LookUp_Scope_helper(node_t *head,string name);
node_t * insert(string key, bool is_var, string name, type_t type, short int scope, unsigned long line_num, void *args );
void print_SymTable();
void init_SymTable();
void traverse_inScope(node_t *new_symbol,unsigned short int scope);
void insert_inScope(node_t *new_symbol,node_t *head);
void print_Scope(unsigned short int scope);
const char* getEnum(type_t type);

void print_spaces(size_t length);
void set_is_active(unsigned short int scope , bool is_active );
bool is_lib_func( string name  );
bool is_lib_func_2( string name );
string create_key(string name);


