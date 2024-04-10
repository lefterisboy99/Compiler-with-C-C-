#include "../utilities/def.h"
#include <string.h>
#include <unordered_map>
#include <assert.h>
#include <stdlib.h>
#include <math.h>  

#define AVM_STACKSIZE 400
#define AVM_WIPEOUT(m) memset( &(m) , 0 , sizeof(m) )

#define AVM_TABLE_HASHSIZE 211

#define AVM_STACK_ENV_SIZE 4

#define AVM_MAX_INSTRUCTIONS (unsigned int) JUMP_V + 1 //nop "kai kala"
#define AVM_ENDING_PC instructions_table.size()

#define AVM_NUM_ACTUALS_OFFSET 4
#define AVM_SAVED_PC_OFFSET 3
#define AVM_SAVED_TOP_OFFSET 2
#define AVM_SAVED_TOPSP_OFFSET 1




typedef enum avm_memcell_type{
    NUMBER_M    = 0,
    STRING_M    = 1,
    BOOL_M      = 2 ,
    TABLE_M     = 3,
    USER_FUNC_M = 4,
    LIB_FUNC_M  = 5,
    NIL_M       = 6 ,
    UNDEF_M     = 7
}avm_memcell_type_e;

struct avm_table;

typedef struct avm_memcell{
    avm_memcell_type_e type;
    union{
        double numVal;
        char *strVal;
        unsigned int boolVal;
        avm_table *tableVal;
        unsigned int funcVal;
        unsigned int libFuncVal;
    }data;


}avm_memcell_t;

typedef void (*library_func_t)(void);
typedef char* (*tostring_func_t)(avm_memcell_t *);

typedef struct lib_func_entry{
    string id;
    library_func_t real_address;
}lib_func_entry_t;


typedef void (*execute_func_t)(instruction_t *);

void load_binary();
static void avm_initStack();
void init_register();
avm_memcell_t *avm_translate_operand(vmarg_t *arg , avm_memcell_t *reg);
void init_stack_ptrs();
void execute_cycle();




/*TABLES*/
typedef struct avm_table_bucket{
    avm_memcell_t       key;
    avm_memcell_t       value;
    avm_table_bucket    *next;
}avm_table_bucket_t;

typedef struct avm_table{
    unsigned refCounter;
    avm_table_bucket_t *strIndexed[AVM_TABLE_HASHSIZE];
    avm_table_bucket_t *numIndexed[AVM_TABLE_HASHSIZE];
    avm_table_bucket_t *boolIndexed[AVM_TABLE_HASHSIZE];
    avm_table_bucket_t *userFuncIndexed[AVM_TABLE_HASHSIZE];
    avm_table_bucket_t *libFuncIndexed[AVM_TABLE_HASHSIZE];
    avm_table_bucket_t *tableIndexed[AVM_TABLE_HASHSIZE];
    unsigned total;
    int hash_table_number;
}avm_table_t;

int hash_function( avm_memcell_t *key );
void set_memcell_num(avm_memcell_t *cell , double num);
void set_memcell_str(avm_memcell_t *cell , char *str);
void set_memcell_bool(avm_memcell_t *cell , double num);
void avm_tableSetElem(avm_memcell_t *key , avm_memcell_t *value , avm_table_t *table);
avm_memcell *avm_tableGetElem( avm_memcell_t *key , avm_table_t *table);
void avm_tableIncRefCounter(avm_table_t *t);
void avm_tableDecRefCounter(avm_table_t *t);
void avm_tableBucketsInit(avm_table_bucket_t **p);
avm_table_t *avm_tableNew();
void avm_tableBucketsDestroy(avm_table_bucket_t **p);
void avm_tableDestroy( avm_table_t *t );



void memclear_table(avm_memcell_t *m);
void memclear_string(avm_memcell_t *m);
void avm_memcellClear(avm_memcell_t *m);

/*Execute functions*/
void execute_assign(instruction_t *instr);
void avm_assign( avm_memcell_t *lv , avm_memcell_t *rv );
void execute_call( instruction_t *instr);

void avm_dec_top();
void avm_push_env_value( unsigned int val);
void avm_callSaveEnviroment();
void execute_funcenter( instruction_t *instr );
unsigned int avm_get_env_value(unsigned int i);
void  execute_funcexit(instruction_t *unused);
library_func_t avm_get_libraryfunc( char *id );
void avm_call_libfunc( char *id);
unsigned int avm_totalActuals();
avm_memcell *avm_getActuals(unsigned int i);
void libfunc_print();
void avm_register_libfunc( const char *id, library_func_t address);
void execute_pusharg( instruction_t *instr);
char *number_tostring( avm_memcell_t *cell);
char *string_tostring( avm_memcell_t *cell);
char *bool_tostring( avm_memcell_t *cell);
char *table_tostring( avm_memcell_t *cell);
char *userfunc_tostring( avm_memcell_t *cell);
char *libfunc_tostring( avm_memcell_t *cell);
char *nil_tostring( avm_memcell_t *cell);
char *undef_tostring( avm_memcell_t *cell);
char *avm_tostring(avm_memcell_t *m);



typedef double (*arithmetic_func_t)( double x, double y);
void execute_aritmhetic(instruction_t *instr);
double add_impl(double x , double y);
double sub_impl(double x , double y);
double mul_impl(double x , double y);
double div_impl(double x , double y);
double mod_impl(double x , double y);


typedef bool (*cmp_func_t)( double x, double y);
void execute_relational(instruction_t *instr);
bool lessEqual_impl(double x , double y);
bool qreaterEqual_impl(double x , double y);
bool lessThan_impl(double x , double y);
bool greaterThan_impl(double x , double y);


#define execute_add execute_aritmhetic
#define execute_sub execute_aritmhetic
#define execute_mul execute_aritmhetic
#define execute_div execute_aritmhetic
#define execute_mod execute_aritmhetic

#define execute_JLE execute_relational
#define execute_JQE execute_relational
#define execute_JLT execute_relational
#define execute_JGT execute_relational


typedef unsigned int (*tobool_func_t)(avm_memcell_t *);
unsigned int number_tobool( avm_memcell_t *m);
unsigned int string_tobool( avm_memcell_t *m);
unsigned int bool_tobool( avm_memcell_t *m);
unsigned int table_tobool( avm_memcell_t *m);
unsigned int userfunc_tobool( avm_memcell_t *m);
unsigned int libfunc_tobool( avm_memcell_t *m);
unsigned int nil_tobool( avm_memcell_t *m);
unsigned int undef_tobool( avm_memcell_t *m);
unsigned int avm_tobool(avm_memcell_t *m);


void execute_JEQ( instruction_t *instr);
void execute_JNE(instruction_t *instr);
void execute_newtable( instruction_t *instr);
void execute_tablegetelem(instruction_t *instr);
void  execute_jump(instruction_t *instr);
void execute_tablesetelem(instruction_t *instr);
void register_libraryFunctions();

void libfunc_print(void);
void libfunc_input(void);
void libfunc_objectmemberkeys(void);
void libfunc_objecttotalmembers(void);
void libfunc_objectcopy(void);
void libfunc_totalarguments(void);
void libfunc_argument(void);
void libfunc_typeof(void);
void libfunc_strtonum(void);
void libfunc_sqrt(void);
void libfunc_cos(void);
void libfunc_sin(void);