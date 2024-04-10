#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;


typedef enum vmopcode{
    ADD_V , 
	SUB_V, 
    MUL_V , 
	DIV_V, 
	MOD_V,
	ASSIGN_V , 
	UMINUS_V,
	AND_V,  
	OR_V, 
	NOT_V, 
    
	JEQ_V,
	JNE_V,  
	JLE_V,
    JQE_V, 
	JLT_V, 
	JGT_V,

    CALL_V, 
	PUSH_ARG_V,
	FUNC_ENTER_V,
    FUNC_EXIT_V, 
	NEW_TABLE_V, 
	TABLE_GET_ELEM_V,
    TABLE_SET_ELEM_V, 
	JUMP_V 
}vmopcode_e;

typedef enum vmarg_type{
	LABEL_A    		= 0,
	GLOBAL_A   		= 1,
	FORMAL_A   		= 2,
	LOCAL_A    		= 3,
	NUMBER_A   		= 4,
	STRING_A   		= 5,
	BOOL_A     		= 6,
	NIL_A      	    = 7,
	USER_FUNC_A 	= 8,
	LIB_FUNC_A  	= 9 ,
	RET_VAL_A   	= 10,
	UNUSED           = 11
}vmarg_type;

typedef struct vmarg{
	vmarg_type type;
	unsigned val;
	string name;
	// int scope;
}vmarg_t;

typedef struct instruction{
	vmopcode_e opcode;
	vmarg_t	result;
	vmarg_t	arg1;
	vmarg_t	arg2;
	unsigned scrLine;
}instruction_t;

typedef struct userfunc{
	unsigned address;
	unsigned localSize;
	string id;
	int scope;
}userfunc_t;

void print_numConst( vector <double> nums );
void print_strConst( vector <string> strs );
void print_libFunctions( vector<string> libFuncs );
void print_userFuncs( vector<userfunc_t> userFuncs );
string vmopcodeToString(instruction_t instr);
string vmOperandTypeToString(vmarg_t arg);
void print_instructions(vector <instruction_t> instructions_table , vector <double> numConsts , vector <string> strConsts ,vector <string> libFunctions ,vector <userfunc_t> userFuncs );