#include "avm.h"

int main(int argc, char** argv){ 
    if(argc!=2) exit(-1);
    
    unsigned length = strlen(argv[1]);
    if(argv[1][length-1] != 'c' || argv[1][length-2] != 'b' || argv[1][length-3] != 'a' ||argv[1][length-4] != '.')
        exit(-1);

    FILE* rf = fopen("binary.abc", "rb");

    unsigned magicNumber;
    fread(&magicNumber, sizeof(unsigned int), 1, rf);
    if(magicNumber != 340200501) {
        cerr << "False magic number. Exiting..." << endl;
        exit(-1);
    }

    unsigned int table_size;
    unsigned int string_size;

    char buffer[1000];
    double number;
    unsigned int locals;
    unsigned int address;
    unsigned int opcode;
    unsigned int type;
    unsigned int value;


    //!string table
    fread(&table_size, sizeof(unsigned long), 1, rf);
    for (int i=0; i<table_size; i++){

        fread(&string_size, sizeof(unsigned long), 1, rf);
        fread(buffer, sizeof(char) * string_size, 1, rf);
        string_table.push_back(buffer);
    }

    //!number table
    fread(&table_size, sizeof(unsigned long), 1, rf);
    for (int i=0; i<table_size; i++){

        fread(&number, sizeof(double), 1, rf);
        number_table.push_back(number);
    }

    //!userfunc table
    fread(&table_size, sizeof(unsigned long), 1, rf);
    for (int i=0; i<table_size; i++){

        fread(&string_size, sizeof(unsigned long), 1, rf);
        fread(buffer, sizeof(char) * string_size, 1, rf);

        fread(&locals, sizeof(unsigned int), 1, rf);

        fread(&address, sizeof(unsigned int), 1, rf);

        userfunc element;
        element.id = buffer;
        element.locals = locals;
        element.address = address;
        userfunc_table.push_back(element);
    }

    //!libfunc table
    fread(&table_size, sizeof(unsigned long), 1, rf);
    for (int i=0; i<table_size; i++){

        fread(&string_size, sizeof(unsigned long), 1, rf);
        fread(buffer, sizeof(char) * string_size, 1, rf);
        libfunc_table.push_back(buffer);
    }

    //!instructions
    fread(&table_size, sizeof(unsigned int), 1, rf);
    for(int i=0; i<table_size; i++) {
        
        instruction t;
        vmarg arg1;
        vmarg arg2;
        vmarg result;

        fread(&opcode, sizeof(unsigned int), 1, rf);
        t.opcode = static_cast<vmopcode>(opcode);

        fread(&type, sizeof(unsigned int), 1, rf);
        fread(&value, sizeof(unsigned int), 1, rf);
        arg1.type = static_cast<vmarg_t>(type);
        arg1.val = value;
        t.arg1 = arg1;

        fread(&type, sizeof(unsigned int), 1, rf);
        fread(&value, sizeof(unsigned int), 1, rf);
        arg2.type = static_cast<vmarg_t>(type);
        arg2.val = value;
        t.arg2 = arg2;
        
        fread(&type, sizeof(unsigned int), 1, rf);
        fread(&value, sizeof(unsigned int), 1, rf);
        result.type = static_cast<vmarg_t>(type);
        result.val = value;
        t.result = result;

        instructions.push_back(t);
    }

    //!instructions
    fread(&totalGlobals, sizeof(unsigned int), 1, rf);

    fclose(rf);

    print_instructions();

    //!initialize stack
    for (int i=0; i<4096; i++)
        stack.at(i).type = undef_m;

    top =AVM_STACKSIZE - (1 + totalGlobals);
    topsp = AVM_STACKSIZE - (1 + totalGlobals);
    codeSize = instructions.size();
    code = &instructions.at(0);
    executionFinished = 0;
    pc = 0;
    currLine = 0;

    avm_registerlibfunc("print", libfunc_print);
    avm_registerlibfunc("typeof", libfunc_typeof);
    avm_registerlibfunc("totalarguments", libfunc_totalarguments);
    avm_registerlibfunc("sqrt", libfunc_sqrt);

    //!initialize

    while (execute_cycle());

    //print_stack();
}