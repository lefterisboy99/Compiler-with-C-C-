#include "vm_def.h"
#include "symbol_table.h"


using namespace std;

extern vector <ioquad_t> quads;//quad table
extern unsigned int programVarOffset;
vector <double> numConsts;
vector <string> strConsts;
vector <string> libFunctions;
vector <userfunc_t> userFuncs;

vector <incomplete_jump_t> incomplete_jump;
vector <instruction_t> instructions_table;

vector<vector<unsigned>> funcStack; //collect the returns statement from functions.On the FUNCEXIT patch this returns-JUMPs 

unsigned currProcessedQuad = 0;


//#################################     functions signatures     ####################################
unsigned int const_newstring( string str);
unsigned int consts_newnumber( double num );
unsigned int libfuncs_newused( string name);
unsigned userfuncs_newfunc( node_t *symbol);
void add_incomplete_jump( unsigned instrNo, unsigned iaddress );
void make_numberoperand (vmarg* arg, double val);
void make_booleoperand (vmarg* arg, unsigned val);
void make_retvaloperand (vmarg* arg);
void patch_incomplete_jumps();
void make_operand(expr* e, vmarg* arg );

void emit_instruction(instruction target_instr);
void generate( vmopcode_e opcode, ioquad_t quad );

void generate_ADD(ioquad_t *quad);
void generate_SUB(ioquad_t *quad);
void generate_MUL(ioquad_t *quad);
void generate_DIV(ioquad_t *quad);
void generate_MOD(ioquad_t *quad);

void generate_NEW_TABLE(ioquad_t *quad);
void generate_TABLE_GET_ELEM(ioquad_t *quad);
void generate_TABLE_SET_ELEM(ioquad_t *quad);
void generate_ASSIGN(ioquad_t *quad);

void generate_JUMP(ioquad_t *quad);
void generate_IF_EQ(ioquad_t *quad);
void generate_IF_NOTEQ(ioquad_t *quad);
void generate_IF_GREATER(ioquad_t *quad);
void generate_IF_GREATEREQ(ioquad_t *quad);
void generate_IF_LESS(ioquad_t *quad);
void generate_IF_LESSEQ(ioquad_t *quad);
void generate_PARAM(ioquad_t *quad);
void generate_CALL(ioquad_t *quad);
void generate_GET_RETVAL(ioquad_t *quad);
void generate_FUNCSTART(ioquad_t *quad);
void generate_RETURN(ioquad_t *quad);

void reset_operand(vmarg_t *operand);
void patch_returns_stmts();
void generate_FUNCEND(ioquad_t *quad);
void generate();

void print_instructions();


void generate_UMINUS( ioquad_t *quad);
void generate_NOT(ioquad_t *quad);
void generate_OR(ioquad_t *quad);
void generate_AND(ioquad_t *quad);

void create_binary();
void read_binary();

unsigned int findUserfunc (string id);

//new to convert UMINUS to MUL

extern expr* newExpr_constNum(double i);
extern expr *newExpr( expr_t type );


//#####################################################################

typedef void (*generator_func_t)(ioquad_t *);


generator_func_t generators[] = {
	generate_ADD ,
	generate_SUB ,
	generate_MUL ,
	generate_DIV ,
	generate_MOD ,
	generate_NEW_TABLE ,
	generate_TABLE_GET_ELEM ,
	generate_TABLE_SET_ELEM ,
	generate_ASSIGN ,
	generate_JUMP ,
	generate_IF_EQ ,
	generate_IF_NOTEQ ,
	generate_IF_GREATER ,
	generate_IF_GREATEREQ ,
	generate_IF_LESS ,
	generate_IF_LESSEQ ,
	generate_NOT ,// not
	generate_OR ,// or
	generate_AND ,//deleteme and
	generate_PARAM ,
	generate_CALL ,
	generate_GET_RETVAL ,
	generate_FUNCSTART ,
	generate_RETURN ,
	generate_FUNCEND,
	generate_UMINUS ,// uminus
	generate_JUMP ,//deleteme jump_B
	generate_JUMP ,//deleteme jump_C
};

unsigned int findUserfunc (string id , int scope){
	for(int i = userFuncs.size()-1;i>=0;--i){
		if(userFuncs[i].id == id && userFuncs[i].scope == scope )
			return i;
	}
	return -1;
}

unsigned int const_newstring( string str){

    for( unsigned int i = 0; i < strConsts.size(); i++ ){
        if(str == strConsts[i]){
            return i;//return offset in strConsts 
        }
    } 
    strConsts.push_back(str);
    return strConsts.size() - 1;
}

unsigned int consts_newnumber( double num ){

    for( unsigned int i = 0; i < numConsts.size(); i++ ){
        if(num == numConsts[i]){
            return i;//return offset in strConsts 
        }
    } 
    numConsts.push_back(num);
    return numConsts.size() - 1;
}

unsigned int libfuncs_newused( string name){

    for( unsigned int i = 0; i < libFunctions.size(); i++ ){
        if(name == libFunctions[i]){
            return i;//return offset in libFunctions 
        }
    } 
    libFunctions.push_back(name);
    return libFunctions.size() - 1;
}

//FIXME: to montara otan einai funcexit na min kanei push_back
unsigned userfuncs_newfunc( node_t *symbol  ){
    userfunc_t user_func ;

    user_func.address = instructions_table.size()/*-1*/;//FIXME:
    user_func.localSize = symbol->total_locals;
    user_func.id = symbol->name;
	user_func.scope = symbol->scope;
	
    userFuncs.push_back(user_func);
    return userFuncs.size() - 1;    
}

void add_incomplete_jump( unsigned instrNo, unsigned iaddress ){
    incomplete_jump_t jump;

    jump.instrNo = instrNo;
    jump.iaddress = iaddress;

    incomplete_jump.push_back(jump);

	//cout << "add_incomplete_jump():  intrNo " << instrNo << "  quad.label: " << iaddress <<endl;
}

void make_numberoperand (vmarg* arg, double val) {
	arg->val = consts_newnumber(val);
	arg->type = NUMBER_A;
}

void make_booleoperand (vmarg* arg, unsigned val){
	arg->val = val; //consts_newnumber(val);
	arg->type = BOOL_A;
}

void make_retvaloperand (vmarg* arg) {
	arg->type = RET_VAL_A;
}

void patch_incomplete_jumps(){
    //FIXME:
    for( unsigned int i = 0; i < incomplete_jump.size(); i++ ){
        if( incomplete_jump[i].iaddress == quads.size() ){
            instructions_table[ incomplete_jump[i].instrNo ].result.val = instructions_table.size();
			//cout << "edo ???" << endl;
        }
        else{
		//	cout << "################################################################" << endl;

		//	cout << "incomplete_jump[i].instrNo:" << incomplete_jump[i].instrNo << endl;
		//	cout << "incomplete_jump[i].iaddress (poio quad na paro) :" << incomplete_jump[i].iaddress << endl; 
		//	cout << "quads[ incomplete_jump[i].iaddress ].taddress (poy na kano jump)" << quads[ incomplete_jump[i].iaddress ].taddress << endl;

            instructions_table[ incomplete_jump[i].instrNo ].result.val = quads[ incomplete_jump[i].iaddress ].taddress;
        
		//	cout << "################################################################" << endl;
		}
    } 
}

void make_operand(expr* e, vmarg* arg ){

	if(e == NULL){
		arg->type = UNUSED;
		return;
	}

	switch (e->type){
		case VAR_E:
		case TABLE_ITEM_E:
		case ARITHM_EXPR_E:
		case BOOL_EXPR_E:
		case NEW_TABLE_E:
		case ASSIGN_EXPR_E: 
		{
			assert (e->sym);
			arg->val = e->sym->offset;
			if(!e->sym->name.empty()) arg->name = e->sym->name;
			switch(e->sym->scope_space) {
				case PROGRAM_VAR:	 arg->type = GLOBAL_A; break;
				case FUNCTION_LOCAL: arg->type = LOCAL_A;  break;
				case FORMAL_ARG:	 arg->type = FORMAL_A; break;
				default:	assert(0);
			}
			break;
        }
		case CONST_BOOL_E: {
			// cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% e->bool_const " << e->bool_const << endl;
			arg->val = e->bool_const;
			arg->type = BOOL_A;
			break;
		}
		case CONST_STRING_E: {
			arg->val = const_newstring(e->str_const);
			arg->name = "\"" + e->str_const + "\"";
			arg->type = STRING_A;
			break;
		}
		
		case CONST_NUM_E: {
			arg->val = consts_newnumber(e->num_const);
			arg->name = to_string(e->num_const);
			arg->type = NUMBER_A;
			break;
		}
		
		case NIL_E:{
            arg->type = NIL_A; 
            break;
        } 
		
		case USER_FUNC_E: {
			arg->type = USER_FUNC_A;
			if( quads[currProcessedQuad].op == FUNCSTART )
				arg->val = userfuncs_newfunc ( e->sym );
			// if ( quads[currProcessedQuad].op == CALL || quads[currProcessedQuad].op == ASSIGN || quads[currProcessedQuad].op == TABLESETELEM )
			else{
				arg->val=findUserfunc(e->sym->name , e->sym->scope );
			}
				
			if(!e->sym->name.empty()) 		
				arg->name = e->sym->name;
			break;
		}
		
		case LIB_FUNC_E: {
			arg->type	= LIB_FUNC_A;
			arg->val 	= libfuncs_newused( e->sym->name);
			if(!e->sym->name.empty()) arg->name = e->sym->name;
			break;
		}
		default:  assert(0);
	}
}

void emit_instruction(instruction t){
	instructions_table.push_back(t);
}


void generate(vmopcode_e opcode, ioquad_t *quad){
	instruction_t t;
	t.opcode = opcode;
	//convert quad operand into target operand
	make_operand( quad->arg1 , &t.arg1 );
	make_operand( quad->arg2 , &t.arg2 );
	make_operand( quad->result , &t.result );
	quad->taddress = instructions_table.size();
	// if(opcode == ASSIGN_V ){
	// 	reset_operand( &t.arg2 );
	// 	cout << "Assign" << endl;
	// }
	// cout << "generate(): quad.taddress : " << quad->taddress << endl;

	emit_instruction(t);
}

void generate_ADD(ioquad_t *quad){
	generate(ADD_V, quad);
}

void generate_SUB(ioquad_t *quad){
	generate(SUB_V, quad);
}

void generate_MUL(ioquad_t *quad){
	generate(MUL_V, quad);
}

void generate_DIV(ioquad_t *quad){
	generate(DIV_V, quad);
}

void generate_MOD(ioquad_t *quad){
	generate(MOD_V, quad);
}

void generate_UMINUS( ioquad_t *quad){
	instruction_t t;
	t.opcode = MUL_V;
	// quad->arg2 = newExpr_constNum(-1);//arg2 from Intermiadiate code is NULL,So we create an expr with -1
	make_operand( quad->arg1 , &t.arg1 );
	// make_operand( quad->arg2 , &t.arg2 , 0 );

	make_numberoperand (&t.arg2, -1);//must call after make_operanc() call for arg2

	make_operand( quad->result , &t.result );
	quad->taddress = instructions_table.size();

	
	emit_instruction(t);
}
void generate_NEW_TABLE(ioquad_t *quad){ 
	generate(NEW_TABLE_V, quad);
}

void generate_TABLE_GET_ELEM(ioquad_t *quad){ 
	generate(TABLE_GET_ELEM_V, quad);
}

void generate_TABLE_SET_ELEM(ioquad_t *quad){ 
	generate(TABLE_SET_ELEM_V, quad);
}

void generate_ASSIGN(ioquad_t *quad){ 
	generate(ASSIGN_V, quad);
}

void generate_relation(vmopcode_e opcode, ioquad_t *quad){
	instruction_t t;
	t.opcode = opcode;
	//convert quad operand into target operand
	make_operand( quad->arg1 , &t.arg1 );
	make_operand( quad->arg2 , &t.arg2 );

	t.result.type = LABEL_A;
	if(quad->label < currProcessedQuad ){
		//cout << "\n-----------------quad.label : " << quad->label << " currProcessedQuad :" << currProcessedQuad << endl;
		t.result.val = quads[quad->label].taddress;
	}
	else{
		//cout << "bazo instructions_table.size()"<< instructions_table.size() << "quad.label " << quad->label << endl;
		add_incomplete_jump(instructions_table.size(), quad->label );
	}

	quad->taddress = instructions_table.size();
	emit_instruction(t);
}

void generate_JUMP(ioquad_t *quad){
	generate_relation(JUMP_V, quad);
}

void generate_IF_EQ(ioquad_t *quad){
	generate_relation(JEQ_V, quad);
}

void generate_IF_NOTEQ(ioquad_t *quad){
	generate_relation(JNE_V, quad);
}

void generate_IF_GREATER(ioquad_t *quad){
	generate_relation(JGT_V ,quad);
}

void generate_IF_GREATEREQ(ioquad_t *quad){
	generate_relation(JQE_V ,quad);
}

void generate_IF_LESS(ioquad_t *quad){
	generate_relation(JLT_V ,quad);
}

void generate_IF_LESSEQ(ioquad_t *quad){
	generate_relation(JLE_V ,quad);
}



/*
1. jeq arg1 false 4      
2. assign result false    
3. jump 5				  
4. assign result true	
5.
*/
void generate_NOT(ioquad_t *quad){
	instruction t;
	quad->taddress = instructions_table.size();

	t.opcode = JEQ_V;
	make_operand(quad->arg1 , &t.arg1);
	make_booleoperand(&t.arg2 , 0);
	t.result.type = LABEL_A;
	t.result.val = instructions_table.size() + 3;
	emit_instruction(t);

	t.opcode = ASSIGN_V;
	make_booleoperand(&t.arg1 , 0);
	reset_operand(&t.arg2);
	make_operand( quad->result , &t.result);
	emit_instruction(t);

	t.opcode =JUMP_V;
	reset_operand(&t.arg1);
	reset_operand(&t.arg2);
	t.result.type = LABEL_A;
	t.result.val = instructions_table.size() + 2;
	emit_instruction(t);


	t.opcode = ASSIGN_V;
	make_booleoperand(&t.arg1 , 1);
	reset_operand(&t.arg2);
	make_operand( quad->result , &t.result );
	emit_instruction(t);
}


/*
1. jeq arg1 true 5      
2. jeq arg2 true 5    
3.assign result false    
4. jump 6				  
5. assign result true	
6.
*/
void generate_OR(ioquad_t *quad){
	instruction t;
	quad->taddress = instructions_table.size();

	t.opcode = JEQ_V;
	make_operand(quad->arg1 , &t.arg1);
	make_booleoperand(&t.arg2 , 1);
	t.result.type = LABEL_A;
	t.result.val = instructions_table.size() + 4;
	emit_instruction(t);

	make_operand(quad->arg2 , &t.arg1);
	t.result.val = instructions_table.size() + 3;
	emit_instruction(t);

	t.opcode = ASSIGN_V;
	make_booleoperand(&t.arg1 , 0);
	reset_operand(&t.arg2);
	make_operand( quad->result , &t.result );
	emit_instruction(t);

	t.opcode =JUMP_V;
	reset_operand(&t.arg1);
	reset_operand(&t.arg2);
	t.result.type = LABEL_A;
	t.result.val = instructions_table.size() + 2;
	emit_instruction(t);


	t.opcode = ASSIGN_V;
	make_booleoperand(&t.arg1 , 1);
	reset_operand(&t.arg2);
	make_operand( quad->result , &t.result );
	emit_instruction(t);
}

/*
1. jeq arg1 false 5      
2. jeq arg2 false 5    
3. assign result true	    
4. jump 6				  
5. assign result false
6.
*/
void generate_AND(ioquad_t *quad){
	instruction t;
	quad->taddress = instructions_table.size();

	t.opcode = JEQ_V;
	make_operand(quad->arg1 , &t.arg1);
	make_booleoperand(&t.arg2 , 0);
	t.result.type = LABEL_A;
	t.result.val = instructions_table.size() + 4;
	emit_instruction(t);

	make_operand(quad->arg2 , &t.arg1);
	t.result.val = instructions_table.size() + 3;
	emit_instruction(t);

	t.opcode = ASSIGN_V;
	make_booleoperand(&t.arg1 , 1);
	reset_operand(&t.arg2);
	make_operand( quad->result , &t.result );
	emit_instruction(t);

	t.opcode =JUMP_V;
	reset_operand(&t.arg1);
	reset_operand(&t.arg2);
	t.result.type = LABEL_A;
	t.result.val = instructions_table.size() + 2;
	emit_instruction(t);


	t.opcode = ASSIGN_V;
	make_booleoperand(&t.arg1 , 0);
	reset_operand(&t.arg2);
	make_operand( quad->result , &t.result );
	emit_instruction(t);
}


void generate_PARAM(ioquad_t *quad){
	
	instruction_t t;
	reset_operand(&t.result);
	reset_operand(&t.arg2);


	quad->taddress = instructions_table.size();
	t.opcode = PUSH_ARG_V;
	make_operand(quad->arg1, &t.arg1);
	
	emit_instruction(t);
}

void generate_CALL(ioquad_t *quad){
	
	instruction_t t;
	reset_operand(&t.result);
	reset_operand(&t.arg2);

	//cout << "eeeeeeeeeeeee:   " << quad->result->type << endl;
	
	quad->taddress = instructions_table.size();
	t.opcode = CALL_V;
	make_operand(quad->result, &t.arg1);

	emit_instruction(t);
}

void generate_GET_RETVAL(ioquad_t *quad){
	instruction_t t;
	reset_operand(&t.arg2);
	
	quad->taddress = instructions_table.size();
	t.opcode = ASSIGN_V;
	make_operand(quad->result, &t.result);
	make_retvaloperand(&t.arg1);

	emit_instruction(t);
}

void reset_operand(vmarg_t *operand){
	operand->type = UNUSED;
}

void generate_FUNCSTART(ioquad_t *quad){
	instruction_t t;
	reset_operand(&t.arg1);
	reset_operand(&t.arg2);

	quad->taddress = instructions_table.size();

	vector<unsigned int> v;
	funcStack.push_back(v);

	t.opcode = FUNC_ENTER_V;
	make_operand(quad->arg1 , &t.result);

	emit_instruction(t);
}

void generate_RETURN(ioquad_t *quad){
	instruction_t t;
	quad->taddress = instructions_table.size();

	if(quad->arg1 != NULL){
		t.opcode = ASSIGN_V;
		make_retvaloperand(&t.result);
		make_operand(quad->arg1, &t.arg1);
		reset_operand(&t.arg2);
		emit_instruction(t);
	}

	funcStack[ funcStack.size()-1 ].push_back( instructions_table.size() );

	t.opcode = JUMP_V;
	reset_operand(&t.arg1);
	reset_operand(&t.arg2);
	t.result.type = LABEL_A;
	emit_instruction(t);
}

void patch_returns_stmts(){
	for(unsigned int i = 0; i < funcStack[ funcStack.size()-1 ].size(); i++){
		instructions_table[ funcStack[ funcStack.size()-1 ].at(i) ].result.val = instructions_table.size();
	}
}

void generate_FUNCEND(ioquad_t *quad){
	instruction_t t;
	reset_operand(&t.arg1);
	reset_operand(&t.arg2);
	
	patch_returns_stmts();
	funcStack.pop_back();

	
	quad->taddress = instructions_table.size();
	t.opcode = FUNC_EXIT_V;
	make_operand(quad->arg1 , &t.result );
	emit_instruction(t);
}

void generate(){//FIXME:
	for( ; currProcessedQuad < quads.size(); currProcessedQuad++ ){
		(*generators[ quads[currProcessedQuad].op ])(&quads[currProcessedQuad]);
	}
	patch_incomplete_jumps();
}

void set_srcLines(){

	for(unsigned int i = 0; i < instructions_table.size(); ++i ){
		instructions_table[i].scrLine = 0;	
	}
	for( unsigned int i= 0; i < quads.size(); ++i){
		instructions_table[  quads[i].taddress  ].scrLine = quads[i].line;
	}
}



void create_binary(){
	ofstream bin;
	unsigned int magicNum = 340200501;
	unsigned int total = 0;
	double tmp = 0;
	string str = "";
	unsigned int str_len = 0;
	char null_terminate = '\0';

	unsigned int address = 0;
	unsigned int localSize = 0;

	bin.open ("avm/binary.abc", ios::out | ios::binary); 
	
	bin.write( (char *) &magicNum , sizeof(unsigned int));//Magic Number

	//#################################   write string array   ################################
	total = strConsts.size();
	bin.write( (char *) &total , sizeof(unsigned int));
	for(unsigned int i = 0; i < strConsts.size(); ++i){

		str_len = strConsts[i].length()+1;

		bin.write( (char *) &str_len , sizeof(unsigned int));
		bin.write( (char *)  strConsts[i].c_str() , str_len-1 );
		bin.write( (char *) &null_terminate , sizeof(char) );
	}

	//#################################   write Number array   ################################
	total = numConsts.size();
	bin.write( (char *) &total , sizeof(unsigned int));
	for(unsigned int i = 0; i < numConsts.size(); ++i){
		tmp = numConsts[i];
		bin.write( (char *) &tmp , sizeof(double));
	}

	//#################################   write user Functions array   ################################
	total = userFuncs.size();
	bin.write( (char *) &total , sizeof(unsigned int));//Total number of user Functions
	for(unsigned int i = 0; i < userFuncs.size(); ++i){
		address = userFuncs[i].address;
		localSize = userFuncs[i].localSize;

		// cout << "Reality Check: address" << userFuncs[i].address << endl;
		// cout << "Reality Check: localsize" << userFuncs[i].localSize << endl;

		str_len = userFuncs[i].id.length()+1;

		bin.write( (char *) &address , sizeof(unsigned int));
		bin.write( (char *) &localSize , sizeof(unsigned int));
		bin.write( (char *) &str_len , sizeof(unsigned int));
		bin.write( (char *) userFuncs[i].id.c_str() , str_len-1 );
		bin.write( (char *) &null_terminate , sizeof(char) );

	}

	//#################################   write lib Functions array   ################################
	total = libFunctions.size();
	bin.write( (char *) &total , sizeof(unsigned int));
	for(unsigned int i = 0; i < libFunctions.size(); ++i){

		str_len = libFunctions[i].length()+1;

		bin.write( (char *) &str_len , sizeof(unsigned int));
		bin.write( (char *) libFunctions[i].c_str() , str_len-1 );
		bin.write( (char *) &null_terminate , sizeof(char) );

	}

	//#################################   write Instruction table array   ################################
	total = instructions_table.size();
	bin.write( (char *) &total , sizeof(unsigned int));

	unsigned tmp_ui = 0;
	for( unsigned int i = 0; i < instructions_table.size(); ++i ){

		tmp_ui = instructions_table[i].opcode;
		bin.write( (char *) &tmp_ui , sizeof(unsigned int));

		tmp_ui = instructions_table[i].result.type;
		bin.write( (char *) &tmp_ui , sizeof(unsigned int));
		tmp_ui = instructions_table[i].result.val;
		bin.write( (char *) &tmp_ui , sizeof(unsigned int));
		//name
		str_len = instructions_table[i].result.name.length()+1;
		bin.write( (char *) &str_len , sizeof(unsigned int));
		bin.write( (char *)  instructions_table[i].result.name.c_str() , str_len-1 );
		bin.write( (char *) &null_terminate , sizeof(char) );


		tmp_ui = instructions_table[i].arg1.type;
		bin.write( (char *) &tmp_ui , sizeof(unsigned int));
		tmp_ui = instructions_table[i].arg1.val;
		bin.write( (char *) &tmp_ui , sizeof(unsigned int));
		//name
		str_len = instructions_table[i].arg1.name.length()+1;
		bin.write( (char *) &str_len , sizeof(unsigned int));
		bin.write( (char *)  instructions_table[i].arg1.name.c_str() , str_len-1 );
		bin.write( (char *) &null_terminate , sizeof(char) );


		tmp_ui = instructions_table[i].arg2.type;
		bin.write( (char *) &tmp_ui , sizeof(unsigned int));
		tmp_ui = instructions_table[i].arg2.val;
		bin.write( (char *) &tmp_ui , sizeof(unsigned int));
		//name
		str_len = instructions_table[i].arg2.name.length()+1;
		bin.write( (char *) &str_len , sizeof(unsigned int));
		bin.write( (char *)  instructions_table[i].arg2.name.c_str() , str_len-1 );
		bin.write( (char *) &null_terminate , sizeof(char) );


		tmp_ui = instructions_table[i].scrLine;
		bin.write( (char *) &tmp_ui , sizeof(unsigned int));
	}

	bin.write( (char *) &programVarOffset , sizeof(unsigned int));

	bin.close();
}



