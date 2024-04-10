#include "avm.h"

avm_memcell_t stack[AVM_STACKSIZE];
avm_memcell_t ax, bx, cx;
avm_memcell_t retval;
unsigned int top = 0 , topsp = 0;
unsigned totalActuals = 0;

unsigned int executionFinished = 0;
unsigned int pc = 0;
unsigned int currLine = 0;
unsigned int codeSize = 0;
//instruction_t *code = NULL;


vector <double> numConsts;
vector <string> strConsts;
vector <string> libFunctions;
vector <userfunc_t> userFuncs;
vector <instruction_t> instructions_table;
unsigned int programVarOffset = 0;

vector<lib_func_entry_t> lib_funcs_log;

unsigned long int totalStacksFrames = 0;
int total_tables = 0;
int functor_flag = 0;
vector <avm_memcell_t *> functor_args;
unsigned int functorReturnPC = 0;

execute_func_t executeFuncs[]= {
execute_add,			// ADD_V , 						
execute_sub,			// SUB_V, 
execute_mul,			// MUL_V , 
execute_div,			// DIV_V, 
execute_mod,			// MOD_V,
execute_assign,			// ASSIGN_V , 
NULL,					// UMINUS_V,
NULL,					// AND_V,  
NULL,					// OR_V, 
NULL,					// NOT_V, 
execute_JEQ,			// JEQ_V,
execute_JNE,			// JNE_V,  
execute_JLE,			// JLE_V,
execute_JQE,			// JQE_V, 
execute_JLT,			// JLT_V, 
execute_JGT,			// JGT_V,
execute_call,			// CALL_V, 
execute_pusharg,		// PUSH_ARG_V,
execute_funcenter,		// FUNC_ENTER_V,
execute_funcexit,		// FUNC_EXIT_V, 
execute_newtable,		// NEW_TABLE_V, 
execute_tablegetelem,	// TABLE_GET_ELEM_V,
execute_tablesetelem,	// TABLE_SET_ELEM_V, 
execute_jump			// JUMP_V 
};
  
typedef void (*memclear_func_t)(avm_memcell_t *);
memclear_func_t memclearFuncs[]{
	NULL,
	memclear_string,
	NULL,
	memclear_table,
	NULL,
	NULL,
	NULL,
	NULL
};

int main(){ 
    cout << "avm starting..." << endl;
    load_binary();
	//print_instructions( instructions_table ,numConsts, strConsts , libFunctions , userFuncs );

	//prepare for execution
	avm_initStack();//unitialize stack
	init_register();//clear resisters
	init_stack_ptrs();// get space for global vars

	register_libraryFunctions();

	while( executionFinished == 0){
		execute_cycle();
	}
	
    cout << "avm exiting successfully..." << endl;
    return 0;
}

/*#####################################         #####################################*/
void register_libraryFunctions(){

	avm_register_libfunc( "print", libfunc_print);
	avm_register_libfunc( "input", libfunc_input);
	avm_register_libfunc( "objectmemberkeys", libfunc_objectmemberkeys);
	avm_register_libfunc( "objecttotalmembers", libfunc_objecttotalmembers);
	avm_register_libfunc( "objectcopy", libfunc_objectcopy);
	avm_register_libfunc( "totalarguments", libfunc_totalarguments);
	avm_register_libfunc( "argument", libfunc_argument);
	avm_register_libfunc( "typeof", libfunc_typeof);
	avm_register_libfunc( "strtonum", libfunc_strtonum);
	avm_register_libfunc( "sqrt", libfunc_sqrt);
	avm_register_libfunc( "cos", libfunc_cos);
	avm_register_libfunc( "sin", libfunc_sin);
}
/*#####################################     ARITHMETIC     #####################################*/

arithmetic_func_t arithmeticFuncs[]{
	add_impl,
	sub_impl,
	mul_impl,
	div_impl,
	mod_impl
};

int aritmetic_error(){
	cout << "Error! division by zero." << endl;
	cout << "Floating point exception (core dumped)" << endl;
	exit(0);
}

double add_impl(double x , double y){return x+y;}
double sub_impl(double x , double y){return x-y;}
double mul_impl(double x , double y){return x*y;}
double div_impl(double x , double y){ return (y == 0 ? aritmetic_error() : x / y);}
double mod_impl(double x , double y){ return (y == 0 ? aritmetic_error() : (int)x % (int)y);}

void execute_aritmhetic(instruction_t *instr){
	avm_memcell_t *lv = avm_translate_operand ( &instr->result, NULL );
	avm_memcell_t *rv1 = avm_translate_operand( &instr->arg1, &ax );
	avm_memcell_t *rv2 = avm_translate_operand( &instr->arg2, &bx );

	assert( lv != NULL && ((&stack[0] <= lv && &stack[AVM_STACKSIZE] > lv ) || (lv == &retval)) );
	assert(rv1 != NULL && rv2 != NULL);

	if( rv1->type != NUMBER_M || rv2->type != NUMBER_M ){
		cout << "Error. Not a number in arithmetic in line " << instr->scrLine << endl;
		executionFinished = 1;
	}
	else{
		arithmetic_func_t op = arithmeticFuncs[instr->opcode - ADD_V];
		avm_memcellClear(lv);
		lv->type = NUMBER_M;
		lv->data.numVal = (*op)(rv1->data.numVal , rv2->data.numVal);
	}
}
/*#####################################     ARITHMETIC     #####################################*/

/*#####################################     Relational operators(>= , > , <= , <)     #####################################*/

// typedef bool (*cmp_func_t)( double x, double y);
cmp_func_t comparisonFuncs[]{
	lessEqual_impl,
	qreaterEqual_impl,
	lessThan_impl,
	greaterThan_impl
};

bool lessEqual_impl(double x , double y){return x <= y;}
bool qreaterEqual_impl(double x , double y){return x >= y;}
bool lessThan_impl(double x , double y){return x < y;}
bool greaterThan_impl(double x , double y){ return x > y;}


void execute_relational(instruction_t *instr){
	avm_memcell_t *rv1 = avm_translate_operand( &instr->arg1, &ax );
	avm_memcell_t *rv2 = avm_translate_operand( &instr->arg2, &bx );

	assert(rv1 != NULL && rv2 != NULL);

	if( rv1->type != NUMBER_M || rv2->type != NUMBER_M ){
		cout << "Error. Not a number in Relational operators in line " << instr->scrLine << endl;
		executionFinished = 1;
	}
	else{
		cmp_func_t op = comparisonFuncs[instr->opcode - JLE_V];
		int relational = (*op)(rv1->data.numVal , rv2->data.numVal);
		if( relational > 0 ){
			pc = instr->result.val;
		}
	}
}
/*#####################################     >= , > , <= , <     #####################################*/



/*#####################################     Equality operators operators(== , !=)     #####################################*/
//typedef unsigned int (*tobool_func_t)(avm_memcell_t *);

unsigned int number_tobool( avm_memcell_t *m){return m->data.numVal != 0;}
unsigned int string_tobool( avm_memcell_t *m){ return strlen(m->data.strVal);}
unsigned int bool_tobool( avm_memcell_t *m){return m->data.boolVal;}
unsigned int table_tobool( avm_memcell_t *m){return 1;}
unsigned int userfunc_tobool( avm_memcell_t *m){return 1;}
unsigned int libfunc_tobool( avm_memcell_t *m){return 1;}
unsigned int nil_tobool( avm_memcell_t *m){return 0;}
unsigned int undef_tobool( avm_memcell_t *m){return 0;}

tobool_func_t toboolFuncs[]={
	number_tobool,
	string_tobool,
	bool_tobool,
	table_tobool,
	userfunc_tobool,
	libfunc_tobool,
	nil_tobool,
	undef_tobool
};

unsigned int avm_tobool(avm_memcell_t *m){
	assert( m->type >= NUMBER_M && m->type <= UNDEF_M);
	return (toboolFuncs[m->type](m));
}

char const *typeStrings[] = {
	"number",
	"string",
	"bool",
	"table",
	"userfunc",
	"libfunc",
	"nil",
	"undef"
};

typedef int (*cmp_types)( avm_memcell_t *rv1 , avm_memcell_t *rv2 );
int cmp_integers(avm_memcell_t *rv1 , avm_memcell_t *rv2){ 
	return (rv1->data.numVal == rv2->data.numVal);
}
int cmp_strings(avm_memcell_t *rv1 , avm_memcell_t *rv2){ 
	if( strcmp(rv1->data.strVal , rv2->data.strVal) == 0 )
		return 1;
	return 0;
}
int cmp_bools(avm_memcell_t *rv1 , avm_memcell_t *rv2){ 
	return (rv1->data.boolVal == rv2->data.boolVal);
}

int cmp_tables(avm_memcell_t *rv1 , avm_memcell_t *rv2){ 
	return (rv1->data.tableVal == rv2->data.tableVal);
}

int cmp_userFuncs(avm_memcell_t *rv1 , avm_memcell_t *rv2){ 
	return (rv1->data.funcVal == rv2->data.funcVal);
}

int cmp_libFuncs(avm_memcell_t *rv1 , avm_memcell_t *rv2){ 
	return (rv1->data.libFuncVal == rv2->data.libFuncVal);
}

int cmp_nils(avm_memcell_t *rv1 , avm_memcell_t *rv2){ 
	return 1;
}

int cmp_undefs(avm_memcell_t *rv1 , avm_memcell_t *rv2){ 
	return 1;
}

cmp_types cmpTypesFuncs[]{
	cmp_integers,
	cmp_strings,
	cmp_bools,
	cmp_tables,
	cmp_userFuncs,
	cmp_libFuncs,
	cmp_nils,
	cmp_undefs
};


void execute_JEQ( instruction_t *instr){

	assert(instr->result.type == LABEL_A);

	avm_memcell_t *rv1 = avm_translate_operand( &instr->arg1 , &ax );
	avm_memcell_t *rv2 = avm_translate_operand( &instr->arg2 , &bx );

	unsigned int result = 0;

	if(rv1->type == UNDEF_M || rv2->type == UNDEF_M){
		cout << "Error! 'undef' innolved in equality!" << endl;
		executionFinished = 1;
	}
	else if( rv1->type == BOOL_M || rv2->type == BOOL_M ){
		result = ( avm_tobool(rv1) == avm_tobool(rv2) );
	}
	else if( rv1->type == NIL_M || rv2->type == NIL_M){
		result = ( rv1->type == NIL_M && rv2->type == NIL_M);
	}
	else if ( rv1->type != rv2->type ){
		cout << "Error! " << typeStrings[rv1->type] << " == " << typeStrings[rv1->type] << " is illegal!" << endl;  
		executionFinished = 1;
	}
	else{
		result = cmpTypesFuncs[rv1->type](rv1 , rv2);
	}

	if(executionFinished == 0 && result == 1){
		pc = instr->result.val;
	}
}

void execute_JNE(instruction_t *instr){//TODO

	assert(instr->result.type == LABEL_A);

	avm_memcell_t *rv1 = avm_translate_operand( &instr->arg1 , &ax );
	avm_memcell_t *rv2 = avm_translate_operand( &instr->arg2 , &bx );

	unsigned int result = 0;

	if(rv1->type == UNDEF_M || rv2->type == UNDEF_M){
		cout << "Error! 'undef' innolved in equality!" << endl;
		executionFinished = 1;
	}
	else if( rv1->type == BOOL_M || rv2->type == BOOL_M ){
		result = ( avm_tobool(rv1) == avm_tobool(rv2) );
	}
	else if( rv1->type == NIL_M || rv2->type == NIL_M){
		result = ( rv1->type == NIL_M && rv2->type == NIL_M);
	}
	else if ( rv1->type != rv2->type ){
		cout << "Error! " << typeStrings[rv1->type] << " == " << typeStrings[rv1->type] << " is illegal!" << endl;  
		executionFinished = 1;
	}
	else{
		result = cmpTypesFuncs[rv1->type](rv1 , rv2);
	}

	//apla antisterfo
	if ( result == 0 ){
		result = 1;
	}
	else {//result == 1
		result = 0; 
	}
	
	if(executionFinished == 0 && result == 1){
		pc = instr->result.val;
	}
}
/*#####################################     Equality operators operators(== , !=)     #####################################*/


/*#####################################     NEW-SET-GET tables START     #####################################*/
void execute_newtable( instruction_t *instr){
	avm_memcell_t *lv = avm_translate_operand( &instr->result , (avm_memcell_t *)0 );
	assert( lv != NULL && ((&stack[0] <= lv && &stack[AVM_STACKSIZE] > lv ) || (lv == &retval)) );

	avm_memcellClear( lv );

	lv->type = TABLE_M;
	lv->data.tableVal = avm_tableNew();
	avm_tableIncRefCounter(lv->data.tableVal);
}

void execute_tablegetelem(instruction_t *instr){
	avm_memcell_t *lv = avm_translate_operand( &instr->result , (avm_memcell_t *)0 );
	avm_memcell_t *t = avm_translate_operand( &instr->arg1 , (avm_memcell_t *)0 );
	avm_memcell_t *i = avm_translate_operand( &instr->arg2 , &ax );

	assert( lv != NULL && ((&stack[0] <= lv && &stack[AVM_STACKSIZE] > lv ) || (lv == &retval)) );
	assert( t != NULL && (&stack[0] <= t && &stack[AVM_STACKSIZE] > t ));
	assert( i >= 0 );

	avm_memcellClear(lv);
	lv->type = NIL_M;//default value if avm_tablegetelem does not find the value with this key we return NIL

	if( t->type != TABLE_M){
		cout << "Error! illegal use of type " << typeStrings[t->type] << " as table! in line: " << instr->scrLine << endl;
		executionFinished = 0;
	}
	else{
		avm_memcell_t *content = avm_tableGetElem(i , t->data.tableVal );
		if( content != NULL ){
			avm_assign(lv , content);
		}
			
		else{
			//char *ts = avm_tostring(t);
			char *is = avm_tostring(i);
			cout << "Warning! key " << "[ " << is  << " ] not found!" << endl;
			//free(ts);
			free(is);
		}
	
	}
}

void execute_tablesetelem(instruction_t *instr){
	avm_memcell_t *t = avm_translate_operand( &instr->result , (avm_memcell_t *)0 );
	avm_memcell_t *i = avm_translate_operand( &instr->arg1 , &ax );
	avm_memcell_t *c = avm_translate_operand( &instr->arg2 , &bx );

	assert( t != NULL && (&stack[0] <= t  && &stack[top] < t) );
	assert( i != NULL && c != NULL);

	if(t->type != TABLE_M){
		cout << "Error! illegal use of type " << typeStrings[t->type] << " as table!" << endl;
		executionFinished = 1;
	}
	else{
		avm_tableSetElem( i , c , t->data.tableVal  );
	}
}

/*#####################################     NEW-SET-GET tables END    #####################################*/













void avm_memcellClear(avm_memcell_t *m){
	if(m->type != UNDEF_M){
		memclear_func_t f = memclearFuncs[m->type];

		if( f != NULL )
			(*f)(m);

		m->type = UNDEF_M;
	}
}

void execute_assign(instruction_t *instr){
	avm_memcell_t *lv = avm_translate_operand( &instr->result , NULL );
	avm_memcell_t *rv = avm_translate_operand( &instr->arg1   , &ax  );

	assert( lv != NULL && ((&stack[0] <= lv && &stack[AVM_STACKSIZE] > lv ) || (lv == &retval)) );
	assert(rv);

	avm_assign(lv,rv);
}

void avm_assign( avm_memcell_t *lv , avm_memcell_t *rv ){
	
	if( lv == rv )
		return;

	if( lv->type == TABLE_M && rv->type == TABLE_M && lv->data.tableVal == rv->data.tableVal )
		return;

	if( rv->type == UNDEF_M ){
		if(rv!=&retval)
			cout << "Warning: Assigning from 'undef' content!" << endl;
	}
		
	
	avm_memcellClear(lv);

	memcpy( lv , rv , sizeof(avm_memcell_t));

	if( lv->type == STRING_M)
		lv->data.strVal = strdup(rv->data.strVal);
	else if( lv->type == TABLE_M ){
		avm_tableIncRefCounter(lv->data.tableVal);
	}
}

void execute_call( instruction_t *instr){
	avm_memcell_t *func = avm_translate_operand( &instr->arg1 , &ax );
	assert(func != NULL );
	//avm_callSaveEnviroment();
	totalStacksFrames++;
	switch( func->type ){
		case USER_FUNC_M:{
			avm_callSaveEnviroment();
			pc = userFuncs[func->data.funcVal].address;
			assert(pc < AVM_ENDING_PC);
			assert( instructions_table[pc].opcode == FUNC_ENTER_V );
			break;
		}

		case STRING_M   : avm_callSaveEnviroment(); avm_call_libfunc( func->data.strVal ); 	 break;
		case LIB_FUNC_M : avm_callSaveEnviroment(); avm_call_libfunc( (char *)libFunctions[func->data.libFuncVal].c_str() ); break;
		case TABLE_M    : {
			cout << "FUNCTOR 2" << endl;
			avm_memcell_t *functor_key = (avm_memcell_t *)malloc(sizeof(avm_memcell_t ));
			functor_key->type = STRING_M;
			functor_key->data.strVal = strdup("()");
			avm_memcell_t *functor = avm_tableGetElem(functor_key, func->data.tableVal );

			cout << "functor func to call " << functor->data.funcVal << endl;	

			functorReturnPC = pc+1;
			pc = userFuncs[functor->data.funcVal ].address;
			functor_flag = 1;
			functor_args.push_back(func);
			break;

		}
		/*
			library_func_t f = avm_get_libraryfunc(id);
			if( f == NULL ){
				cout << "Unsopported lib func '" << id << "'" << endl;
				executionFinished = 1; 
			}
			else{
				topsp = top;
				totalActuals = 0;
				(*f)();
				if( executionFinished == 0 ){
					execute_funcexit(NULL);
				}
			}
		*/
		

		default: {
			if( instr->arg1.type == GLOBAL_A || instr->arg1.type == LOCAL_A  ){
				cout << "functor!!!"<< endl;
			
			}
			char *s  = avm_tostring(func);
			cout << "Runtime error! Call: cannot bind " << s << " to function!" << endl;
			free(s);
			executionFinished = 1;
		} 
	}
}

void avm_dec_top(){
	if( top == 0 ){
		cout << "Error! Stack overflow!" << endl;
		executionFinished = 1;
		exit(0);
	}
	else{
		--top;
	}

}

void avm_push_env_value( unsigned int val){
	stack[top].type = NUMBER_M;
	stack[top].data.numVal = val;
	avm_dec_top();
}

void avm_callSaveEnviroment(){
	avm_push_env_value(totalActuals);
	avm_push_env_value(pc+1);
	avm_push_env_value(top+ totalActuals + 2);
	avm_push_env_value(topsp);
}

void execute_funcenter( instruction_t *instr ){
	avm_memcell_t *func = avm_translate_operand( &instr->result , &ax );
	assert( func != NULL );
	assert( pc == userFuncs[func->data.funcVal].address );

	if( functor_flag == 1){
		avm_assign( &stack[top] , functor_args[0] );
		++totalActuals;
		avm_dec_top();
		functor_flag = 0;
		avm_callSaveEnviroment();
		stack[top+AVM_SAVED_PC_OFFSET].data.numVal = functorReturnPC; 
	}

	totalActuals = 0;
	topsp = top;
	top = top - userFuncs[func->data.funcVal].localSize;
}

unsigned int avm_get_env_value(unsigned int i){
	//assert( stack[i].type == NUMBER_M);
	unsigned int val = (unsigned)stack[i].data.numVal;
	//assert( stack[i].data.numVal == (double)val );
	return val;
}

void  execute_funcexit(instruction_t *unused){
	unsigned int oldTop = top;
	top   = avm_get_env_value( topsp + AVM_SAVED_TOP_OFFSET   );
	pc    = avm_get_env_value( topsp + AVM_SAVED_PC_OFFSET    );
	topsp = avm_get_env_value( topsp + AVM_SAVED_TOPSP_OFFSET );

	while( ++oldTop <= top ){//FIXME: check pre/post increase
		avm_memcellClear(&stack[oldTop]);
	}
	totalStacksFrames--;
}

void  execute_jump(instruction_t *instr){
	assert( instr->result.type == LABEL_A);
	pc = instr->result.val;
}

/*########################################################################################*/

// void avm_register_libfunc( char *id, library_func_t address)
library_func_t avm_get_libraryfunc( char *id ){
	for(unsigned int i = 0; i < lib_funcs_log.size(); ++i){
		if( strcmp(id , lib_funcs_log[i].id.c_str()) == 0 ){
			return lib_funcs_log[i].real_address;
		}
	}
	return NULL;
}

void avm_call_libfunc( char *id){
	library_func_t f = avm_get_libraryfunc(id);
	if( f == NULL ){
		cout << "Unsopported lib func '" << id << "'" << endl;
		executionFinished = 1; 
	}
	else{
		topsp = top;
		totalActuals = 0;
		(*f)();
		if( executionFinished == 0 ){
			execute_funcexit(NULL);
		}
	}
}

unsigned int avm_totalActuals(){
	return avm_get_env_value(topsp + AVM_NUM_ACTUALS_OFFSET);
}

avm_memcell *avm_getActuals(unsigned int i){
	// assert( i < avm_totalActuals() );
	return &stack[topsp + AVM_STACK_ENV_SIZE + 1 + i];
}


//create a new collection for library functions
void avm_register_libfunc( const char *id, library_func_t address){
	lib_func_entry e;
	e.id = id;
	e.real_address = address;

	lib_funcs_log.push_back(e);
}

void execute_pusharg( instruction_t *instr){
	avm_memcell_t *arg = avm_translate_operand( &instr->arg1 , &ax);
	assert( arg != NULL );

	avm_assign( &stack[top] , arg );
	++totalActuals;
	avm_dec_top();
}

char *number_tostring( avm_memcell_t *cell){
	string str = to_string(cell->data.numVal);
	return strdup(str.c_str());
}

char *string_tostring( avm_memcell_t *cell){
	return strdup(cell->data.strVal);
}

char *bool_tostring( avm_memcell_t *cell){
	string str = to_string(cell->data.boolVal);
	return strdup(str.c_str());
}


char *table_tostring( avm_memcell_t *cell){
	 
	avm_table_bucket_t **int_hash = cell->data.tableVal->numIndexed;
	avm_table_bucket_t **str_hash = cell->data.tableVal->strIndexed;
	avm_table_bucket_t **bool_hash = cell->data.tableVal->boolIndexed;
	avm_table_bucket_t **userFunc_hash = cell->data.tableVal->userFuncIndexed;
	avm_table_bucket_t **libFunc_hash = cell->data.tableVal->libFuncIndexed;
	avm_table_bucket_t **table_hash = cell->data.tableVal->tableIndexed;
	
	avm_table_bucket_t *bucket = NULL;
	string str = "[ ";

	for( unsigned int i = 0; i < AVM_TABLE_HASHSIZE; ++i){
		bucket =int_hash[i];
		while( bucket != NULL ){
			string s = "";
			if( bucket->value.data.tableVal != cell->data.tableVal )
				s = avm_tostring( &bucket->value );
			else{
				cout << "Warning! Circular Dependency" << endl;
				s = "[...Self Reference...]";
			}
			
			str += "{" + to_string(bucket->key.data.numVal) + " , " + s + "} "; 
			bucket = bucket->next;
		}
	}
	
	for( unsigned int j = 0; j < AVM_TABLE_HASHSIZE; j = j+1){
		
		bucket = str_hash[j];
		while( bucket != NULL ){
			string s = "";	

			if( bucket->value.data.tableVal != cell->data.tableVal )
				s = avm_tostring( &bucket->value );
			else{
				cout << "Warning! Circular Dependency" << endl;
				s = "[...Self Reference...]";
			}
							
			string int_str = bucket->key.data.strVal;
			str += "{ " +  int_str + " , " + s + " } "; 
			bucket = bucket->next;
		}
	}
	for( unsigned int i = 0; i < AVM_TABLE_HASHSIZE; ++i){
		bucket =bool_hash[i];
		while( bucket != NULL ){
			string s = "";
			if( bucket->value.data.tableVal != cell->data.tableVal )
				s = avm_tostring( &bucket->value );
			else{
				cout << "Warning! Circular Dependency" << endl;
				s = "[...Self Reference...]";
			}
			
			
			str += "{" + to_string(bucket->key.data.boolVal) + " , " + s + "} "; 
			bucket = bucket->next;
		}
	}	
	for( unsigned int i = 0; i < AVM_TABLE_HASHSIZE; ++i){
		bucket =userFunc_hash[i];
		while( bucket != NULL ){
			string s = "";
			if( bucket->value.data.tableVal != cell->data.tableVal )
				s = avm_tostring( &bucket->value );
			else{
				cout << "Warning! Circular Dependency" << endl;
				s = "[...Self Reference...]";
			}
			
			
			str += "{" + to_string(bucket->key.data.funcVal) + " , " + s + "} "; 
			bucket = bucket->next;
		}
	}
	for( unsigned int i = 0; i < AVM_TABLE_HASHSIZE; ++i){
		bucket =libFunc_hash[i];
		while( bucket != NULL ){
			string s = "";
			if( bucket->value.data.tableVal != cell->data.tableVal )
				s = avm_tostring( &bucket->value );
			else{
				cout << "Warning! Circular Dependency" << endl;
				s = "[...Self Reference...]";
			}
			
			
			str += "{" + to_string(bucket->key.data.libFuncVal) + " , " + s + "} "; 
			bucket = bucket->next;
		}
	}
	for( unsigned int i = 0; i < AVM_TABLE_HASHSIZE; ++i){
		bucket =table_hash[i];
		while( bucket != NULL ){
			string s = "";
			if( bucket->value.data.tableVal != cell->data.tableVal )
				s = avm_tostring( &bucket->value );
			else{
				cout << "Warning! Circular Dependency" << endl;
				s = "[...Self Reference...]";
			}
			
			str += "{ ...table... , " + s + " } "; 
			bucket = bucket->next;
		}
	}
	
	str += " ]";
	char *table_content = (char *)malloc(sizeof(char)*(str.length()+1));
	strcpy( table_content , str.c_str() );
	return table_content;
}

char *userfunc_tostring( avm_memcell_t *cell){
	string str = userFuncs[cell->data.funcVal].id;
	return strdup(str.c_str());
}

char *libfunc_tostring( avm_memcell_t *cell){
	return strdup( libFunctions[cell->data.libFuncVal].c_str() );
}

char *nil_tostring( avm_memcell_t *cell){
	return strdup("nil");
}

char *undef_tostring( avm_memcell_t *cell){
	return strdup("undef");
}

tostring_func_t tostringFuncs[]{
	number_tostring	,
	string_tostring,
	bool_tostring,
	table_tostring,
	userfunc_tostring,
	libfunc_tostring,
	nil_tostring,
	undef_tostring
};

char *avm_tostring(avm_memcell_t *m){
	assert( m->type >= NUMBER_M && m->type <= UNDEF_M );
	return tostringFuncs[m->type](m);
}


/*########################################################################################*/


void memclear_string(avm_memcell_t *m){
	assert(m->data.strVal != NULL );
	free(m->data.strVal);
}

void memclear_table(avm_memcell_t *m){
	assert(m->data.tableVal != NULL );
	avm_tableDecRefCounter(m->data.tableVal);
}


void execute_cycle(){

	if( executionFinished == 1 ){
		return;
	}
	else if(pc == AVM_ENDING_PC){
		executionFinished = 1;
		return;
	}
	else{
		assert( pc < AVM_ENDING_PC );
		instruction_t *instr = &instructions_table[pc];
		assert( instr->opcode >= 0 && instr->opcode < AVM_MAX_INSTRUCTIONS );

		if(instr->scrLine > 0)
			currLine = instr->scrLine;
		unsigned int oldPC = pc;
		(*executeFuncs[instr->opcode])(instr);
		if(pc == oldPC)
			++pc;
	}
}

avm_memcell_t *avm_translate_operand(vmarg_t *arg , avm_memcell_t *reg){

	switch(arg->type){
		case GLOBAL_A	: return &stack[ AVM_STACKSIZE -1 - arg->val ];
		case LOCAL_A  	: return &stack[ topsp - arg->val ];
		case FORMAL_A	: {
			if( arg->val >= avm_totalActuals()){
				cout << "Runtime Error! Unrecognized actuals arg!" << endl;
				exit(0);
			}
			return &stack[ topsp + AVM_STACK_ENV_SIZE + 1 + arg->val ];
		}
		case RET_VAL_A	: return &retval;

		case NUMBER_A   : {
			reg->type = NUMBER_M;
			reg->data.numVal = numConsts[arg->val];
			return reg;
		}

		case STRING_A	:{
			reg->type = STRING_M;
			reg->data.strVal = strdup( strConsts[arg->val].c_str() );
			return reg;
		}

		case BOOL_A		:{
			reg->type = BOOL_M;
			reg->data.boolVal = arg->val;
			return reg;
		}

		case NIL_A		:{
			reg->type = NIL_M;
			return reg;
		}

		case USER_FUNC_A:{
			reg->type = USER_FUNC_M;
			reg->data.funcVal = arg->val;//possition into vector
			return reg;
		}

		case LIB_FUNC_A:{
			reg->type = LIB_FUNC_M;
			reg->data.libFuncVal = arg->val;//possition into vector
			return reg;
		}
		case UNUSED : ;

		default: assert(0);
	}
}








static void avm_initStack(){
	for(unsigned int i = 0; i < AVM_STACKSIZE; ++i){
		AVM_WIPEOUT(stack[i]);
		stack[i].type = UNDEF_M;
	}
}

void init_stack_ptrs(){
	top = AVM_STACKSIZE - programVarOffset -1;
	topsp = AVM_STACKSIZE - programVarOffset -1;
}

void init_register(){
	AVM_WIPEOUT(ax);
	AVM_WIPEOUT(bx);
	AVM_WIPEOUT(cx);
	AVM_WIPEOUT(retval);

	ax.type = UNDEF_M;
	bx.type = UNDEF_M;
	cx.type = UNDEF_M;
	retval.type = UNDEF_M;
}

void load_binary(){
	ifstream bin;
	
	bin.open ("binary.abc", ios::in | ios::binary); 	
	
	double tmp = 0;
	unsigned int magicNum = 340200501 , checkMagicNum = 0 , total = 0 , str_len = 0; 
	char *str = NULL;
	
    userfunc_t userfunc;
    instruction_t instr;

	cout << "Load binary start..." << endl;

	bin.read( (char *) &checkMagicNum , sizeof(unsigned int));//Magic Number
	if( checkMagicNum != magicNum ){
		cout << "Can not load the binary file." << endl;
		exit(0);
	}

	//#################################   read string array   ################################
	bin.read( (char *) &total , sizeof(unsigned int));//Total number of strings
	for(unsigned int i = 0; i < total; ++i){
		
		bin.read( (char *) &str_len , sizeof(unsigned int));
		str  = new char[str_len];
		bin.read( str , str_len );

        strConsts.push_back( str );

		delete str;
	}

	//#################################   read Number array   ################################
	bin.read( (char *) &total , sizeof(unsigned int));
	for(unsigned int i = 0; i < total; ++i){
		bin.read( (char *) &tmp , sizeof(double));
        numConsts.push_back(tmp);
	}

	//#################################   read user Functions array   ################################
	bin.read( (char *) &total , sizeof(unsigned int));//Total number of user Functions
	for(unsigned int i = 0; i < total; ++i){
		
		bin.read( (char *) &userfunc.address , sizeof(unsigned int));
		bin.read( (char *) &userfunc.localSize , sizeof(unsigned int));

		bin.read( (char *) &str_len , sizeof(unsigned int));
		str  = new char[str_len];
		bin.read( str , str_len );
        userfunc.id = str;

        userFuncs.push_back(userfunc);

		delete str;
	}

	//#################################   read lib Functions array   ################################
	bin.read( (char *) &total , sizeof(unsigned int));
	for(unsigned int i = 0; i < total; ++i){

        bin.read( (char *) &str_len , sizeof(unsigned int));
		str  = new char[str_len];
		bin.read( (char *) str , str_len );

		libFunctions.push_back(str);
		delete str;
	}

	//#################################   read Instruction table array   ################################	
	bin.read( (char *) &total , sizeof(unsigned int));
	for( unsigned int i = 0; i < total; ++i ){

		bin.read( (char *) &instr.opcode , sizeof(unsigned int));//opcode
		
		bin.read( (char *) &instr.result.type , sizeof(unsigned int));//result type
		bin.read( (char *) &instr.result.val , sizeof(unsigned int));//result val
		//name
		bin.read( (char *) &str_len , sizeof(unsigned int));
		str  = new char[str_len];
		bin.read( str , str_len );
		instr.result.name = str;
		delete str;


		bin.read( (char *) &instr.arg1.type , sizeof(unsigned int));//arg1 type
		bin.read( (char *) &instr.arg1.val , sizeof(unsigned int));//arg1 val
		//name
		bin.read( (char *) &str_len , sizeof(unsigned int));
		str  = new char[str_len];
		bin.read( str , str_len );
		instr.arg1.name = str;
		delete str;

		
		bin.read( (char *) &instr.arg2.type , sizeof(unsigned int));//arg2 type
		bin.read( (char *) &instr.arg2.val , sizeof(unsigned int));//arg2 val
		//name
		bin.read( (char *) &str_len , sizeof(unsigned int));
		str  = new char[str_len];
		bin.read( str , str_len );
		instr.arg2.name = str;
		delete str;

		bin.read( (char *) &instr.scrLine , sizeof(unsigned int));

		// instr.result.name = "";
		// instr.arg1.name = "";
		// instr.arg2.name = "";
		instructions_table.push_back(instr);

	}
	bin.read( (char *) &programVarOffset , sizeof(unsigned int));

	cout << "Load binary end..." << endl;
 	bin.close();
}









/*#####################################     TABLES START     #####################################*/
//TODO: EDO
int hash_function( avm_memcell_t *key ){
   int sum = 0;
   switch( key->type ){
	   case NUMBER_M	: return (unsigned int)key->data.numVal % AVM_TABLE_HASHSIZE;
	   case BOOL_M  	: return (unsigned int)key->data.boolVal % AVM_TABLE_HASHSIZE;
	   case USER_FUNC_M : return (unsigned int)key->data.funcVal % AVM_TABLE_HASHSIZE;
	   case LIB_FUNC_M	: return (unsigned int)key->data.libFuncVal % AVM_TABLE_HASHSIZE;
	   case STRING_M	: {
			for( unsigned int i = 0; i < strlen(key->data.strVal); ++i ){
				sum += key->data.strVal[i];
			}
			return sum % AVM_TABLE_HASHSIZE;
   	   	}
		case TABLE_M	: return (unsigned int)key->data.tableVal->hash_table_number % AVM_TABLE_HASHSIZE;
		default			: ;/*assert(0);*/		
   }
    return 0;
}

void removeFromList( avm_table_bucket_t **list , avm_table_bucket_t *bucket ){

	avm_table_bucket_t *curr = *list;
	avm_table_bucket_t *prev = NULL;
	if( curr->next == NULL ){//1 toixeio stin lista
		free(bucket);
		*list = NULL;
		return;
	}
	if( curr == bucket ){
		*list = bucket->next;
		free(bucket);
		return;
	}
	while( curr != bucket ){
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	free(curr);
}
//TODO: EDO
void remove_bucket(avm_table_t *table , avm_memcell_t *key ){
	avm_table_bucket_t *curr = NULL;
	int index = hash_function( key );
    
    if( key->type == NUMBER_M ){
        curr = table->numIndexed[index];
        while( curr != NULL ){
            if( key->data.numVal == curr->key.data.numVal ){
                avm_memcellClear(&curr->key);
				avm_memcellClear(&curr->value);
				removeFromList(&table->strIndexed[index] , curr );
				return;
            }
            curr = curr->next;
        }
    }
    else if( key->type == STRING_M ){
        curr = table->strIndexed[index];
        while( curr != NULL ){
            if( strcmp( key->data.strVal , curr->key.data.strVal) == 0 ){
               	avm_memcellClear(&curr->key);
				avm_memcellClear(&curr->value);
				removeFromList(&table->strIndexed[index] , curr );
				return;
            }
            curr = curr->next;
        }
    }
	else if( key->type == BOOL_M ){
        curr = table->boolIndexed[index];
        while( curr != NULL ){
            if( key->data.boolVal == curr->key.data.boolVal ){
               	avm_memcellClear(&curr->key);
				avm_memcellClear(&curr->value);
				removeFromList(&table->boolIndexed[index] , curr );
				return;
            }
            curr = curr->next;
        }
    }
	else if( key->type == USER_FUNC_M ){
        curr = table->userFuncIndexed[index];
        while( curr != NULL ){
            if( key->data.funcVal == curr->key.data.funcVal ){
               	avm_memcellClear(&curr->key);
				avm_memcellClear(&curr->value);
				removeFromList(&table->userFuncIndexed[index] , curr );
				return;
            }
            curr = curr->next;
        }
    }
	else if( key->type == LIB_FUNC_M ){
        curr = table->libFuncIndexed[index];
        while( curr != NULL ){
            if( key->data.libFuncVal == curr->key.data.libFuncVal ){
               	avm_memcellClear(&curr->key);
				avm_memcellClear(&curr->value);
				removeFromList(&table->libFuncIndexed[index] , curr );
				return;
            }
            curr = curr->next;
        }
    }
	else if( key->type == TABLE_M ){
        curr = table->tableIndexed[index];
        while( curr != NULL ){
            if( key->data.tableVal == curr->key.data.tableVal ){
               	avm_memcellClear(&curr->key);
				avm_memcellClear(&curr->value);
				removeFromList(&table->tableIndexed[index] , curr );
				return;
            }
            curr = curr->next;
        }
    }

	table->total--;	
}


//TODO: EDO
void avm_tableSetElem(avm_memcell_t *key , avm_memcell_t *value , avm_table_t *table){

	if( key->type == UNDEF_M ){
		cout << "Error! Unsupported assignement(elemnent to table). " << endl;
	}

    avm_memcell *cell = avm_tableGetElem(key ,table);
    if ( cell != NULL ){//if bucket exists (same key)
		if( value->type == NIL_M ){//if value == NULL remove bucket
			remove_bucket(table , key );
			return;
		}
		avm_assign(cell , value);//else update the value
        return;
    }

    int index = hash_function( key );
    avm_table_bucket_t *bucket = ( avm_table_bucket_t *)malloc(sizeof( avm_table_bucket_t ));

	bucket->key.type = UNDEF_M;
	avm_assign(&bucket->key , key);
    if(key->type == NUMBER_M ){
        bucket->next = table->numIndexed[index];
        table->numIndexed[index] = bucket;
    }
    else if( key->type == STRING_M ){
        bucket->next = table->strIndexed[index];
        table->strIndexed[index] = bucket;
    }
	else if(key->type == BOOL_M ){
        bucket->next = table->boolIndexed[index];
        table->boolIndexed[index] = bucket;
    }
	else if(key->type == USER_FUNC_M ){
        bucket->next = table->userFuncIndexed[index];
        table->userFuncIndexed[index] = bucket;
    }
	else if(key->type == LIB_FUNC_M ){
        bucket->next = table->libFuncIndexed[index];
        table->libFuncIndexed[index] = bucket;
    }
	else if(key->type == TABLE_M ){
        bucket->next = table->tableIndexed[index];
        table->tableIndexed[index] = bucket;
    }

	table->total++;
	
	bucket->value.type = UNDEF_M;
	avm_assign(&bucket->value , value);
	
}
//TODO: EDO
avm_memcell *avm_tableGetElem( avm_memcell_t *key , avm_table_t *table){
    int index = hash_function( key );

    avm_table_bucket_t *curr = NULL;
    if( key->type == NUMBER_M ){
        curr = table->numIndexed[index];
        while( curr != NULL ){
            if( key->data.numVal == curr->key.data.numVal ){
                return &curr->value;
            }
            curr = curr->next;
        }
    }
    else if( key->type == STRING_M ){
        curr = table->strIndexed[index];
        while( curr != NULL ){
            if( strcmp( key->data.strVal , curr->key.data.strVal) == 0 ){
                return &curr->value;
            }
            curr = curr->next;
        }
    }
	else if( key->type == BOOL_M ){
        curr = table->boolIndexed[index];
        while( curr != NULL ){
            if( key->data.boolVal == curr->key.data.boolVal ){
                return &curr->value;
            }
            curr = curr->next;
        }
    }
	else if( key->type == USER_FUNC_M ){
        curr = table->userFuncIndexed[index];
        while( curr != NULL ){
            if( key->data.funcVal == curr->key.data.funcVal ){
                return &curr->value;
            }
            curr = curr->next;
        }
    }
	else if( key->type == LIB_FUNC_M ){
        curr = table->libFuncIndexed[index];
        while( curr != NULL ){
            if( key->data.libFuncVal == curr->key.data.libFuncVal ){
                return &curr->value;
            }
            curr = curr->next;
        }
    }
	else if( key->type == TABLE_M ){
        curr = table->tableIndexed[index];
        while( curr != NULL ){
            if( key->data.tableVal == curr->key.data.tableVal ){
                return &curr->value;
            }
            curr = curr->next;
        }
    }
    return NULL;
}


void avm_tableIncRefCounter(avm_table_t *t){
    ++t->refCounter;
}

void avm_tableDecRefCounter(avm_table_t *t){
    assert( t->refCounter > 0);
    --t->refCounter;
    if( t-> refCounter == 0 ){
        avm_tableDestroy(t);
    }
}

void avm_tableBucketsInit(avm_table_bucket_t **p){
    for(unsigned int i = 0; i< AVM_TABLE_HASHSIZE; ++i){
        p[i] = NULL;
    }
}

//TODO: EDO
avm_table_t *avm_tableNew(){
    avm_table_t *t = (avm_table_t *)malloc(sizeof(avm_table_t));
    // AVM_WIPEOUT(*t);//TODO:CHECKME!!!!

    t->refCounter = 0;
    t->total = 0;
	t->hash_table_number = ++total_tables;

    avm_tableBucketsInit(t->numIndexed);
    avm_tableBucketsInit(t->strIndexed);
	avm_tableBucketsInit(t->boolIndexed);
	avm_tableBucketsInit(t->userFuncIndexed);
	avm_tableBucketsInit(t->libFuncIndexed);
	avm_tableBucketsInit(t->tableIndexed);


    return t;
}

void avm_tableBucketsDestroy(avm_table_bucket_t **p){
    for(unsigned int i = 0; i < AVM_TABLE_HASHSIZE; ++i){
        for(avm_table_bucket_t *b = *p; b; ){
            avm_table_bucket_t *del = b;
            b = b->next;
            avm_memcellClear(&del->key);
            avm_memcellClear(&del->value);
            free(del);
        }
        p[i] = NULL;
    }
} 

//TODO: EDO
void avm_tableDestroy( avm_table_t *t){
    avm_tableBucketsDestroy(t->strIndexed);
    avm_tableBucketsDestroy(t->numIndexed);
	avm_tableBucketsDestroy(t->boolIndexed);
	avm_tableBucketsDestroy(t->userFuncIndexed);
	avm_tableBucketsDestroy(t->libFuncIndexed);
	avm_tableBucketsDestroy(t->tableIndexed);

    free(t);
}
/*#####################################     TABLES END    #####################################*/




/*#####################################     LIBFUNCS  START    #####################################*/
void libfunc_print(void){
	unsigned int n = avm_totalActuals();
	for(unsigned int i =  0; i < n; ++i){
		if( avm_getActuals(i)->type==UNDEF_M){
			cout << "Printing 'UNDEF' contents";
		}
		else{
			char *s = avm_tostring( avm_getActuals(i) );

			cout << s ;
			free(s);
		}
	}
	avm_memcellClear(&retval);
	retval.type = UNDEF_M;

}

void libfunc_input(void){
	string inputStr;
	getline (cin,inputStr); 
	
	avm_memcellClear(&retval);
	
	string::size_type sz; // alias of size_t
	try{
		double result = stod(inputStr, &sz);
		retval.type = NUMBER_M;
		retval.data.numVal = result;
	}
	catch (...){}

	if( inputStr == "true" ){
		retval.type = BOOL_M;
		retval.data.boolVal = 1;
	}
	else if( inputStr == "false" ){
		retval.type = BOOL_M;
		retval.data.boolVal = 0;
	}
	else if( inputStr == "nil" ){
		retval.type = NIL_M;
	}
	else{
		retval.type = STRING_M;
		retval.data.strVal = strdup(inputStr.c_str());
	}
}


void copyTable_KEYS( avm_table_t *dest, avm_table_bucket_t **src ){
	
	avm_table_bucket_t *bucket = NULL;
	avm_memcell_t key;
	key.type = NUMBER_M;
	
	for( unsigned int i = 0; i < AVM_TABLE_HASHSIZE; ++i){
		bucket = src[i];
		while( bucket != NULL ){
			key.data.numVal = i;
			avm_tableSetElem( &key , &bucket->key , dest );
			bucket = bucket->next;
		}
	}
}
//TODO: edo
void libfunc_objectmemberkeys(void){
	unsigned int n = avm_totalActuals();

	if( n != 1){
		cout << "Error! one argument (not " << n << " ) expected in 'objectmemberkeys()'!" << endl; 
		executionFinished = 1;
		return;
	}
	if( avm_getActuals(0)->type != TABLE_M ){
		cout << "Error! 'objectmemberkeys()' expects table and not " << typeStrings[avm_getActuals(0)->type] << endl;
		executionFinished = 1;  
		return;
	}
	
	avm_memcellClear(&retval);
	retval.type = TABLE_M;
	retval.data.tableVal = avm_tableNew();
	copyTable_KEYS( retval.data.tableVal ,  avm_getActuals(0)->data.tableVal->numIndexed );
	copyTable_KEYS( retval.data.tableVal ,  avm_getActuals(0)->data.tableVal->strIndexed );
	copyTable_KEYS( retval.data.tableVal ,  avm_getActuals(0)->data.tableVal->boolIndexed);
	copyTable_KEYS( retval.data.tableVal ,  avm_getActuals(0)->data.tableVal->userFuncIndexed );
	copyTable_KEYS( retval.data.tableVal ,  avm_getActuals(0)->data.tableVal->libFuncIndexed );
	copyTable_KEYS( retval.data.tableVal ,  avm_getActuals(0)->data.tableVal->tableIndexed );
}

void libfunc_objecttotalmembers(void){
	unsigned int n = avm_totalActuals();

	if( n != 1){
		cout << "Error! one argument (not " << n << " ) expected in 'objecttotalmembers()'!" << endl; 
		executionFinished = 1;
		return;
	}
	if( avm_getActuals(0)->type != TABLE_M ){
		cout << "Error! 'objecttotalmembers()' expects table and not " << typeStrings[avm_getActuals(0)->type] << endl;
		executionFinished = 1;  
		return;
	}

	avm_memcellClear(&retval);
	retval.type = NUMBER_M;
	retval.data.numVal = avm_getActuals(0)->data.tableVal->total;
}

void copyTable(avm_table_t *dest ,avm_table_bucket_t **src ){
	avm_table_bucket_t *bucket = NULL;
	
	for( unsigned int i = 0; i < AVM_TABLE_HASHSIZE; ++i){
		bucket = src[i];
		while( bucket != NULL ){
			avm_tableSetElem( &bucket->key , &bucket->value , dest );
			bucket = bucket->next;
		}
	}
}


//TODO: edo
void libfunc_objectcopy(void){
	unsigned int n = avm_totalActuals();

	if( n != 1){
		cout << "Error! one argument (not " << n << " ) expected in 'objecttotalmembers()'!" << endl; 
		executionFinished = 1;
		return;
	}
	if( avm_getActuals(0)->type != TABLE_M ){
		cout << "Error! 'objecttotalmembers()' expects table and not " << typeStrings[avm_getActuals(0)->type] << endl;
		executionFinished = 1;  
		return;
	}

	avm_memcellClear(&retval);
	retval.type = TABLE_M;
	retval.data.tableVal = avm_tableNew();

	copyTable(retval.data.tableVal , avm_getActuals(0)->data.tableVal->numIndexed );
	copyTable(retval.data.tableVal , avm_getActuals(0)->data.tableVal->strIndexed );
	copyTable(retval.data.tableVal , avm_getActuals(0)->data.tableVal->boolIndexed );
	copyTable(retval.data.tableVal , avm_getActuals(0)->data.tableVal->userFuncIndexed );
	copyTable(retval.data.tableVal , avm_getActuals(0)->data.tableVal->libFuncIndexed );
	copyTable(retval.data.tableVal , avm_getActuals(0)->data.tableVal->tableIndexed );

}

void libfunc_totalarguments(void){
	unsigned int prev_topsp = avm_get_env_value( topsp + AVM_SAVED_TOPSP_OFFSET );
	avm_memcellClear(&retval);

	if( totalStacksFrames <= 1 ){
		cout << "'totalarguments' called outside a function!" << endl;
		retval.type = NIL_M;
	}
	else{
		retval.type = NUMBER_M;
		retval.data.numVal = avm_get_env_value( prev_topsp + AVM_NUM_ACTUALS_OFFSET );
	}
}

avm_memcell *avm_getCallerActuals( unsigned int prev_topsp , unsigned int i){
	return &stack[prev_topsp + AVM_STACK_ENV_SIZE + 1 + i];
}


void libfunc_argument(void){
	
	unsigned int n = avm_totalActuals();
	if( n != 1){
		cout << "Error! one argument (not " << n << " ) expected in 'argument'!" << endl; 
		executionFinished = 1;
		return;
	}

	if( totalStacksFrames <= 1 ){
		cout << "'totalarguments' called outside a function!" << endl;
		avm_memcellClear(&retval);
		retval.type = NIL_M;
		return;
	}

	if( avm_getActuals(0)->type != NUMBER_M ){
		cout << "Error! 'argument' expect number and not a " << typeStrings[ avm_getActuals(0)->type] << " argument"  << endl; 
		executionFinished = 1;
		return;
	}
	
	unsigned int prev_topsp = avm_get_env_value( topsp + AVM_SAVED_TOPSP_OFFSET );
	unsigned int callerActualNum = avm_get_env_value(prev_topsp + AVM_NUM_ACTUALS_OFFSET);
	if( avm_getActuals(0)->data.numVal >= callerActualNum ){
		cout << "Error! function that call 'argument()' has only " << callerActualNum << " arguments." << endl; 
		executionFinished = 1;
		return;
	}
	avm_assign(&retval , avm_getCallerActuals(prev_topsp , avm_getActuals(0)->data.numVal ) );	
}

void libfunc_typeof(void){
	unsigned int n = avm_totalActuals();

	if( n != 1){
		cout << "Error! one argument (not " << n << " ) expected in 'typeof'!" << endl; 
		executionFinished = 1;
	}
	else{
		avm_memcellClear(&retval);
		retval.type = STRING_M;
		retval.data.strVal = strdup( typeStrings[avm_getActuals(0)->type] );
	}
}

void libfunc_strtonum(void){
	unsigned int n = avm_totalActuals();

	if( n != 1){
		cout << "Error! one argument (not " << n << " ) expected in 'strtonum'!" << endl; 
		executionFinished = 1;
	}
	
	if( avm_getActuals(0)->type == NUMBER_M ){
		cout << "Warning. The argument of strtonum is already number." << endl;
	}
	else if( avm_getActuals(0)->type != STRING_M ){
		cout << "Error! 'strtonum' expect string and not " << typeStrings[avm_getActuals(0)->type] << endl;
		executionFinished = 1;  
	}
	avm_memcellClear(&retval);
	if(executionFinished == 0 ){
		string s = avm_getActuals(0)->data.strVal;
		for(unsigned int i = 0; i < s.length(); ++i ){
			if (isalpha( s.c_str()[i] )) {
				cout << "Warning. The argument of strtonum cannot convert into number." << endl;
				retval.type = NIL_M;
				return;
			}
		}
		string::size_type sz; // alias of size_t
		try{
			double result = stod(s, &sz);
			retval.type = NUMBER_M;
			retval.data.numVal = result;
		}
		catch (...){
			cout << "Warning. The argument of strtonum cannot convert into number." << endl;
			retval.type = NIL_M;
		}
	}
}


void libfunc_sqrt(void){
	unsigned int n = avm_totalActuals();

	if( n != 1){
		cout << "Error! one argument (not " << n << " ) expected in 'sin'!" << endl; 
		executionFinished = 1;
	}
	
	if( avm_getActuals(0)->type != NUMBER_M ){
		cout << "Error! 'sin' expect number and not " << typeStrings[avm_getActuals(0)->type] << endl;
		executionFinished = 1;  
	}

	if(executionFinished == 0 ){
		avm_memcellClear(&retval);
		errno = 0;
		double result = sqrt(avm_getActuals(0)->data.numVal);
		if( errno == EDOM){//if error occur
			retval.type = NIL_M;
		}
		else{
			retval.type = NUMBER_M;
			retval.data.numVal = result;
		}
	}
}

void libfunc_cos(void){
	unsigned int n = avm_totalActuals();

	if( n != 1){
		cout << "Error! one argument (not " << n << " ) expected in 'cos'!" << endl; 
		executionFinished = 1;
	}
	
	if( avm_getActuals(0)->type != NUMBER_M ){
		cout << "Error! 'cos' expect number and not " << typeStrings[avm_getActuals(0)->type] << endl;
		executionFinished = 1;  
	}

	if(executionFinished == 0 ){
		avm_memcellClear(&retval);
		retval.type = NUMBER_M;
		retval.data.numVal = cos( avm_getActuals(0)->data.numVal );
	}
}

void libfunc_sin(void){
	unsigned int n = avm_totalActuals();

	if( n != 1){
		cout << "Error! one argument (not " << n << " ) expected in 'sin'!" << endl; 
		executionFinished = 1;
	}
	
	if( avm_getActuals(0)->type != NUMBER_M ){
		cout << "Error! 'sin' expect number and not " << typeStrings[avm_getActuals(0)->type] << endl;
		executionFinished = 1;  
	}

	if(executionFinished == 0 ){
		avm_memcellClear(&retval);
		retval.type = NUMBER_M;
		retval.data.numVal = sin( avm_getActuals(0)->data.numVal );
	}
}
/*#####################################     LIBFUNCS END    #####################################*/
