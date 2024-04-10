#include "def.h"

string vmopcodeToString(instruction_t instr){
    switch(instr.opcode){
        case ADD_V             : return "ADD";  break;        
		case SUB_V             : return "SUB";  break;          
		case MUL_V             : return "MUL";  break;           
		case DIV_V             : return "DIV";  break;          
		case MOD_V             : return "MOD";  break;              
		case ASSIGN_V          : return "ASSIGN";  break;           
		case UMINUS_V          : return "UMINUS";	break;
		case AND_V             : return "AND";	break;
		case OR_V              : return "OR";	break;
		case NOT_V             : return "NOT";	break;
		case JEQ_V             : return "JEQ";	break;
		case JNE_V             : return "JNE";	break;
		case JLE_V             : return "JLE";	break;
		case JQE_V             : return "JQE";	break;
		case JLT_V             : return "JLT";	break;
		case JGT_V             : return "JGT";	break;
		case CALL_V            : return "CALL";	break;
		case PUSH_ARG_V        : return "PUSH_ARG";	break;
		case FUNC_ENTER_V      : return "FUNC_ENTER";	break;
		case FUNC_EXIT_V       : return "FUNC_EXIT";	break;
		case NEW_TABLE_V       : return "NEW_TABLE";	break;
		case TABLE_GET_ELEM_V  : return "TABLE_GET_ELEM";	break;
		case TABLE_SET_ELEM_V  : return "TABLE_SET_ELEM";	break;
		case JUMP_V            : return "JUMP";	break;

        default             : return "check me 1";
    }
}

string vmOperandTypeToString(vmarg_t arg){
    switch(arg.type){
        case LABEL_A             : return "label"  ;  break;        
		case GLOBAL_A             : return "global" ;  break;          
		case FORMAL_A             : return "formal";  break;           
		case LOCAL_A             : return "local";  break;          
		case NUMBER_A             : return "number";  break;              
		case STRING_A          : return "string";  break;           
		case BOOL_A          : return "bool";	break;
		case NIL_A             : return "nil";	break;
		case USER_FUNC_A              : return "userfunc";	break;
		case LIB_FUNC_A             : return "libfunc";	break;
		case RET_VAL_A             : return "retval";	break;

        default             : return "check me 2";
    }
}

void print_numConst( vector <double> nums ){
	if(nums.size() <= 0){
		return;
	}
	cout << "\nnumConst Table: ";
	cout << endl <<"---------------------------------------------"<<endl;
	for( unsigned int i = 0; i < nums.size(); i++ ){
		cout << "[" << i << "]" << nums[i] << endl;
	}
	cout<<"---------------------------------------------"<<endl;
}

void print_strConst( vector <string> strs ){
	if(strs.size() <= 0){
		return;
	}
	cout << "\nstrConst Table: ";
	cout << endl <<"---------------------------------------------"<<endl;
	for( unsigned int i = 0; i < strs.size(); i++ ){
		cout << "[" << i << "]" << strs[i] << endl;
	}
	cout<<"---------------------------------------------"<<endl;
}

void print_libFunctions( vector<string> libFuncs ){

	if(libFuncs.size() <= 0){
		return;
	}
	
	cout << "\nlibFunctions Table: ";
	cout << endl <<"---------------------------------------------"<<endl;
	for( unsigned int i = 0; i < libFuncs.size(); i++ ){
		cout << "[" << i << "]" << libFuncs[i] << endl;
	}
	cout<<"---------------------------------------------"<<endl;
}

void print_userFuncs( vector<userfunc_t> userFuncs ){
	
	if(userFuncs.size() <= 0){
		return;
	}
	cout << "\nuserFuncs Table: [address , localSize , name id]";
	cout << endl <<"---------------------------------------------"<<endl;
	for( unsigned int i = 0; i < userFuncs.size(); i++ ){
		cout << "[" << i << "] [" << userFuncs[i].address << "," << userFuncs[i].localSize << "," << userFuncs[i].id << "]" << endl;
	}
	cout<<"---------------------------------------------"<<endl;
}



void print_instructions(vector <instruction_t> instructions_table , vector <double> numConsts , vector <string> strConsts ,vector <string> libFunctions ,vector <userfunc_t> userFuncs ){
	
	string s18 = "                  ";//18 spaces
	string s10 = "          ";//10 spaces
	int flag = 0;
	
	printf( "\x1B[34m""\n########################################     Target code:     ########################################n\n""\x1B[0m"  );
    cout<<"inst#"<< "      "<<"opcode"<<s10<<"result"<<setw(20)<<"arg1"<<setw(25)<<"arg2"<<setw(20) << "line" << endl;
    cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
    for(unsigned int i=0;i<instructions_table.size();i++){
        // bool printLabel=true;
        // if(instructions_table[i].label <= 0 && instructions_table[i].op!= JUMP  && instructions_table[i].op!= JUMP_B   && instructions_table[i].op!= JUMP_C){
        //     printLabel=false;
        // }
		instruction tmp = instructions_table[i];

        cout << i ;
		cout.width(18); 
		cout << right << vmopcodeToString(tmp);

		string s0 = "";
		if(tmp.result.type != UNUSED){
			s0 += to_string(tmp.result.type) +  "(" + vmOperandTypeToString(tmp.result) + "),";

			if(tmp.result.type != RET_VAL_A){//an einai retval kseroyme oti einai o register retval
				s0 += to_string(tmp.result.val) + " :" + tmp.result.name; 
			}
		}
		cout << "     " << s0;

		int j = 20 - s0.size();
		while(j >= 0){
			cout << " ";
			j--;
		}

		flag = 0;

	    string s1 = "";
		if(tmp.arg1.type != UNUSED){
			s1 += to_string(tmp.arg1.type) + "(" + vmOperandTypeToString(tmp.arg1) +  ") ," + to_string(tmp.arg1.val) + " :" + tmp.arg1.name;
			flag++;
		}
		cout << s1;


		string s3 = "" ;
		if(tmp.arg2.type != UNUSED){	
			
			s3 = to_string(tmp.arg2.type) + "(" + vmOperandTypeToString(tmp.arg2) + ") ," + to_string(tmp.arg2.val) + " :" + tmp.arg2.name;
			flag++;
		}

		j = 25 - s3.size();
		while(j >= 0){
			cout << " ";
			j--;
		}
		cout << s3;
		

		

		if(flag == 0)
			cout << "                               ";
		else if(flag == 1){
			cout << "                  ";
		}
		else{
			cout << "                ";
		}
		cout << instructions_table[i].scrLine;

		cout << endl;
    }
	
    cout<<"-------------------------------------------------------------------------------------------------------------"<<endl;
	cout << "numConst table     # elems: " << numConsts.size() << endl;
	cout << "strConsts table    # elems: " << strConsts.size() << endl;
	cout << "libFunctions table # elems: " << libFunctions.size() << endl;
	cout << "userFuncs table    # elems: " << userFuncs.size() << endl; 

	print_numConst(numConsts);
	print_strConst(strConsts);
	print_libFunctions(libFunctions);
	print_userFuncs(userFuncs);


	// for( unsigned int i = 0; i < quads.size(); i++){
	// 	cout << "quads[" << i << "] -> " << quads[i].taddress << " target insruction" << endl;
	// }
    cout<<endl;

	// create_binary();
	//read_binary();
}