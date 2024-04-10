%{
    #include "symbolTable.h"

    int yyerror (string yaccProvidedMessage){ return 0; }
    int yylex(void);

    extern int yylineno;
	extern char * yyval;
	extern char * yytext;
	extern FILE * yyin;
	extern FILE * yyout;

    int SCOPE = 0;
    string GLOBAL_ID;
    vector<SymbolTableEntry> FORMAL_ARGUMENTS; 
%}

%start program

%union {
    int intValue;
    char* stringValue;
    double realValue;
}

%token ASSIGN
%token<stringValue> STRING
%token<intValue> INTEGER
%token<realValue> REAL
%token LOCAL
%token NIL
%token<stringValue> ID
%token BLOCK_COMMENT 
%token LINE_COMMENT
%token ESCAPE_CHARACTERS
%token SPACE
%token IF 
%token ELSE 
%token WHILE 
%token FOR
%token FUNCTION 
%token RETURN
%token BREAK 
%token CONTINUE
%token AND NOT OR
%token TRUE FALSE
%token MINUS
%token EQUAL 
%token DIFFER 
%token BIGGER 
%token LESS 
%token BIGGER_EQ 
%token LESS_EQ
%token MINUSMINUS 
%token PLUSPLUS
%token MOD MULTIPLY 
%token DIV PLUS 
%token CURLY_START_BRACKET 
%token CURLY_END_BRACKET 
%token START_BRACKET 
%token END_BRACKET
%token START_PARENTHESIS 
%token END_PARENTHESIS
%token SEMICOLON 
%token COMMA 
%token COLON DOUBLE_COLON
%token DOT 
%token DOUBLE_DOT
//%token EOF
%token UNDEFINED

%right      ASSIGN
%left       OR
%left       AND
%nonassoc   EQUAL DIFFER
%nonassoc   BIGGER BIGGER_EQ LESS LESS_EQ
%left       PLUS MINUS
%left       MULTIPLY DIV MOD
%right      NOT PLUSPLUS MINUSMINUS UMINUS
%left       DOT DOUBLE_DOT
%left       START_BRACKET END_BRACKET
%left       START_PARENTHESIS END_PARENTHESIS

%%

program:    stmt program
	        |
            ;
            

stmt:       expr SEMICOLON
            {
                lwarning = false;
            }
            |ifstmt
            |whilestmt
            |forstmt
            |returnstmt
            |BREAK{
                loop_counter--;
                if(loop_counter<0){
                    cout << "\033[1;31m" <<
                        "Can't use break here at line "<< yylineno <<
                        "\033[0m" << endl;
                        loop_counter=0;
                }
            } SEMICOLON
            |CONTINUE{
                if(loop_counter==0){
                    cout << "\033[1;31m" << 
                        "Can't use continue outside of loops at line "<< yylineno <<
                        "\033[0m" << endl;
                }
            } SEMICOLON
            |block
            |funcdef
            |SEMICOLON
            ;

expr:       assignexpr
            |expr PLUS expr
            |expr MINUS expr
            |expr MULTIPLY expr
            |expr DIV expr
            |expr MOD expr
            |expr BIGGER expr
            |expr BIGGER_EQ expr
            |expr LESS expr
            |expr LESS_EQ expr
            |expr EQUAL expr
            |expr DIFFER expr
            |expr AND expr
            |expr OR expr
            |term
            ;

term:       START_PARENTHESIS expr END_PARENTHESIS
            |primary
            |MINUS expr %prec UMINUS
            |PLUSPLUS
            lvalue
            {
                SymbolTableEntry *entry_ptr = Lookup(create_entry(GLOBAL_ID,0,0,LLOCAL,FUNC_DEPTH), SCOPE);
                if(isFunction(*entry_ptr)){
                    cout << "\033[1;31m" << 
                        "Function used as lvalue (++function)  at line "<< yylineno <<
                        "\033[0m" << endl;
                }
            }

            |lvalue
            {
                SymbolTableEntry *entry_ptr = Lookup(create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH), SCOPE);
                if(isFunction(*entry_ptr)){
                    cout << "\033[1;31m" << 
                        "Function used as lvalue (function++)  at line "<< yylineno <<
                        "\033[0m" << endl;
                }
            } 
            PLUSPLUS
            
            |MINUSMINUS
            lvalue
            {
                SymbolTableEntry *entry_ptr = Lookup(create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH), SCOPE);
                if(isFunction(*entry_ptr)){
                    cout << "\033[1;31m" << 
                        "Function used as lvalue (--function)  at line "<< yylineno <<
                        "\033[0m" << endl;
                }
            }

            |lvalue
            {
                SymbolTableEntry *entry_ptr = Lookup(create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH), SCOPE);
                if(isFunction(*entry_ptr)){
                    cout << "\033[1;31m" << 
                        "Function used as lvalue (function--)  at line "<< yylineno <<
                        "\033[0m" << endl;
                }
            }
            MINUSMINUS
            |NOT expr
            ;


primary:    lvalue
            |call
            |objectdef
            |START_PARENTHESIS funcdef END_PARENTHESIS
            |const
            ;

lvalue:     ID
            {   
                GLOBAL_ID = $1;

                SymbolTableEntry * entry_ptr = Lookup(create_entry($1,0,0,LLOCAL, FUNC_DEPTH),SCOPE);
                SymbolTableEntry entry=create_entry($1, SCOPE, yylineno, GLOBAL, FUNC_DEPTH);
                if(entry_ptr== NULL ){

                    if(SCOPE==0){
                        Insert(entry);  
                    }
                    else{
                        entry.type=LLOCAL;
                        Insert(entry);
                    }
                } else{
                    if(isFunction(*entry_ptr)) lwarning = true;

                    if(entry_ptr->type!=USERFUNC&&entry_ptr->type!=LIBFUNC&&entry_ptr->value.varVal->scope!=0){
                        if(get_func_depth(*entry_ptr)!=get_func_depth(entry)){
                            cout << "\033[1;31m" << 
                            "Can't access this var at line "<< yylineno <<
                            "\033[0m" << endl;
                        }
                    }  
                }
            }
		    |LOCAL ID
            {
                GLOBAL_ID=$2;
                SymbolTableEntry entry = create_entry($2, SCOPE, yylineno, GLOBAL, FUNC_DEPTH);
                SymbolTableEntry *entry_ptr = Lookup_scope(entry, SCOPE);
                if(entry_ptr==NULL){
                    if(SCOPE==0){
                        Insert_local(entry);
                    }
                    else{
                        entry.type = LLOCAL;
                        Insert_local(entry);
                    }
                }else if(entry_ptr->type == LIBFUNC){
                    cout << "\033[1;31m" << 
                    "Collision with library function at line "<< yylineno <<
                    "\033[0m" << endl;
                }
                else {
                    if(isFunction(*entry_ptr)) lwarning = true;
                }
            }
		    |DOUBLE_COLON ID
            {
                if(!Lookup_scope(create_entry($2,0,0,LLOCAL, FUNC_DEPTH),0)){
                    cout << "\033[1;31m" << 
                    "Global id not found at line "<< yylineno <<
                    "\033[0m" << endl;
                }
            }
		    |member
		    ;

assignexpr:  lvalue
             {  
                SymbolTableEntry entry = create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH);
                SymbolTableEntry *entry_ptr = Lookup(entry,SCOPE);
                if(entry_ptr){      
                    if(isFunction(*entry_ptr) && lwarning){
                            cout << "\033[1;31m" << 
                            "Function used as lvalue at line "<< yylineno <<
                            "\033[0m" << endl;

                            lwarning = false;
                        
                    }
                }
             }
             ASSIGN expr
             |call ASSIGN expr{
                 cout << "\033[1;31m" << 
                            "Function used as lvalue at line "<< yylineno <<
                            "\033[0m" << endl;
             }
             ;

member:     lvalue DOT {lwarning = false;} ID
            |lvalue START_BRACKET expr END_BRACKET
            |call DOT {lwarning = false;}  ID
            |call START_BRACKET expr END_BRACKET
            ;

call:       call START_PARENTHESIS elist END_PARENTHESIS
            |lvalue{
                SymbolTableEntry entry = create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH);
                SymbolTableEntry *entry_ptr = Lookup(entry,SCOPE);
                if(!isFunction(*entry_ptr)){
                   /* cout << "\033[1;31m" << 
                            "Can't use variable as func at line "<< yylineno <<
                            "\033[0m" << endl;*/
                }

            } callsuffix
            |START_PARENTHESIS funcdef END_PARENTHESIS START_PARENTHESIS elist END_PARENTHESIS
            ;

callsuffix: normcall
            |methodcall
            ;

normcall:   START_PARENTHESIS elist END_PARENTHESIS
            ;

methodcall: DOUBLE_DOT ID START_PARENTHESIS elist END_PARENTHESIS
            ;

elist:      expr commaexpr
            |
            ;

commaexpr:  COMMA expr commaexpr
            |
            ;

objectdef:  START_BRACKET elist END_BRACKET
            |START_BRACKET indexed END_BRACKET
            ;
                

indexed:            indexedelem commaindexedelem;

commaindexedelem:   COMMA indexedelem commaindexedelem
                    |
                    ;
        
indexedelem:        CURLY_START_BRACKET expr COLON expr CURLY_END_BRACKET
                    ;

block:              CURLY_START_BRACKET
                    {
                        SCOPE++;
                    }
                    CURLY_END_BRACKET
                    {
                        Hide(SCOPE--);
                    }
                    |CURLY_START_BRACKET
                    {
                        SCOPE++;
                    }
                    stmt program
                    CURLY_END_BRACKET
                    {
                        Hide(SCOPE--);
                    }
                    ;


funcdef:            FUNCTION
                    {
                        SymbolTableEntry entry = create_entry(generate_function_name(),SCOPE,yylineno,USERFUNC, FUNC_DEPTH);
                        Insert(entry);
                        FUNC_DEPTH++;
                    }
                    START_PARENTHESIS
                    {
                        SCOPE++;
                    }
                    idlist 
                    END_PARENTHESIS 
                    {
                        SCOPE--;
                    }
                    block
                    |FUNCTION {fflag = true;}
                    ID
                    {   
                        if(FUNC_DEPTH==0)
                            active_func.clear();
                        SymbolTableEntry entry = create_entry($3, SCOPE, yylineno, USERFUNC, FUNC_DEPTH);
                        SymbolTableEntry *entry_ptr_glb = Lookup(entry, SCOPE);
                        SymbolTableEntry *entry_ptr = Lookup_scope(entry,SCOPE);
                        active_func.push_back($3);
                        if(entry_ptr==NULL){
                            if(entry_ptr_glb==NULL){
                                  Insert(entry);  
                            }else if(entry_ptr_glb->type==LIBFUNC){
                                cout << "\033[1;31m" << 
                            "Lib function redeclaration at line "<< yylineno <<
                            "\033[0m" << endl;
                            }else{
                                Insert(entry);
                            }
                        }else if(entry_ptr->type == LIBFUNC){
                            cout << "\033[1;31m" << 
                            "Lib function redeclaration at line "<< yylineno <<
                            "\033[0m" << endl;
                        }else if(entry_ptr->type == USERFUNC){
                            cout << "\033[1;31m" << 
                            "User function redeclaration at line "<< yylineno <<
                            "\033[0m" << endl;
                        }else if(entry_ptr->type==GLOBAL||entry_ptr->type==LLOCAL||entry_ptr->type==FORMAL){
                            cout << "\033[1;31m" << 
                            "Variable already defined at line "<< yylineno <<
                            "\033[0m" << endl;
                        }
                        FUNC_DEPTH++;
                    }
                    START_PARENTHESIS
                    {
                        SCOPE++;
                    }
                     idlist
                    END_PARENTHESIS
                    {
                        SCOPE--;
                    }
                     block
                     {FUNC_DEPTH--;}
                    ;

const:              REAL
                    |INTEGER
                    |STRING
                    |NIL
                    |TRUE
                    |FALSE
                    ;

idlist:             ID
                    {
                        FORMAL_ARGUMENTS.clear();
                        SymbolTableEntry entry = create_entry($1, SCOPE, yylineno, FORMAL, FUNC_DEPTH);

                        SymbolTableEntry* entry_ptr = Lookup_scope(entry, 0);
                        if(entry_ptr != NULL){
                            if(entry_ptr->type != LIBFUNC){
                                Insert(entry);
                                FORMAL_ARGUMENTS.push_back(entry);
                            }else{
                                cout << "\033[1;31m" << 
                                "Library function as formal argument at line "<< yylineno <<
                                "\033[0m" << endl;
                            }
                        }else{
                            Insert(entry);
                            FORMAL_ARGUMENTS.push_back(entry);
                        }     
                    }
                     commaid
                    |
                    ;

commaid:            COMMA
                    ID
                    {
                        SymbolTableEntry entry = create_entry($2, SCOPE, yylineno, FORMAL, FUNC_DEPTH);

                        SymbolTableEntry* entry_ptr = Lookup_scope(entry, 0);
                        if(entry_ptr != NULL){
                            if(entry_ptr->type != LIBFUNC){
                                Insert(entry);
                                FORMAL_ARGUMENTS.push_back(entry);
                            }else{
                                cout << "\033[1;31m" << 
                                "Library function as formal argument at line "<< yylineno <<
                                "\033[0m" << endl;
                            }
                        }else{
                            for(int i=0; i<FORMAL_ARGUMENTS.size(); i++){
                                if($2 == get_name(FORMAL_ARGUMENTS.at(i))){
                                    cout << "\033[1;31m" << 
                                    "Formal redeclaration at line "<< yylineno <<
                                    "\033[0m" << endl;
                                }else{                
                                    Insert(entry);
                                }
                            }
                        }    
                    }
                    commaid
                    |
                    ;

ifstmt:             IF START_PARENTHESIS expr END_PARENTHESIS stmt 
                    |IF START_PARENTHESIS expr END_PARENTHESIS stmt ELSE stmt
                    ;

whilestmt:          WHILE{loop_counter++;} START_PARENTHESIS expr END_PARENTHESIS stmt{loop_counter--; if(loop_counter < 0) loop_counter=0;};

forstmt:            FOR {loop_counter++;}START_PARENTHESIS elist SEMICOLON expr SEMICOLON elist END_PARENTHESIS stmt{loop_counter--; if(loop_counter < 0) loop_counter=0;}
                    ;

returnstmt:         RETURN{
                        if(FUNC_DEPTH==0){
                            cout << "\033[1;31m" << 
                                    "Return outside of function at line "<< yylineno <<
                                    "\033[0m" << endl;
                        }

                    } expr SEMICOLON
                    | RETURN{
                        if(FUNC_DEPTH==0){
                            cout << "\033[1;31m" << 
                                    "Return outside of function at line "<< yylineno <<
                                    "\033[0m" << endl;
                        }
                    } SEMICOLON
                    ;



%%

int main(int argc, char** argv){

    if(argc>1){
        if(!(yyin=fopen(argv[1],"r"))){
            printf("Cannot open file %s",argv[1]);
            return -1;
        }
    }else
        yyin=stdin;
    
    
    Insert(create_entry("print", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("input", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("objectmemberkeys", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("objecttotalmembers", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("objectcopy", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("totalarguments", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("argument", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("typeof", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("strtonum", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("sqrt", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("cos", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("sin", 0, 0, LIBFUNC,FUNC_DEPTH));
    
    
    yyparse();
    
    print_symbol_table();

    return 0;
}
