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

program:    stmt program    { cout << "program -> stmt*" << endl; }
	        |               { cout << "program -> " << endl; }
            ;
            

stmt:       expr SEMICOLON
            {
                cout << "stmt -> expr;" << endl;
                lwarning = false;
            }
            |ifstmt { cout << "stmt -> ifstmt" << endl; }
            |whilestmt  { cout << "stmt -> whilestmt" << endl; }
            |forstmt    { cout << "stmt -> forstmt" << endl; }
            |returnstmt { cout << "stmt -> returnstmt" << endl; }
            |BREAK{
                loop_counter--;
                if(loop_counter<0){
                    cout << "\033[1;31m" <<
                        "Can't use break here at line "<< yylineno <<
                        "\033[0m" << endl;
                        loop_counter=0;
                }
            } SEMICOLON { cout << "program -> stmt*" << endl; }
            |CONTINUE{
                if(loop_counter==0){
                    cout << "\033[1;31m" << 
                        "Can't use continue outside of loops at line "<< yylineno <<
                        "\033[0m" << endl;
                }
            } SEMICOLON { cout << "program -> stmt*" << endl; }
            |block  { cout << "stmt -> block" << endl; }
            |funcdef    { cout << "stmt -> funcdef" << endl; }
            |SEMICOLON  { cout << "stmt -> ;" << endl; }
            ;

expr:       assignexpr              { cout << "expr -> assignexpr" << endl; }
            |expr PLUS expr         { cout << "expr -> expr + expr" << endl; }
            |expr MINUS expr        { cout << "expr -> expr - expr" << endl; }
            |expr MULTIPLY expr     { cout << "expr -> expr * expr" << endl; }
            |expr DIV expr          { cout << "expr -> expr / expr" << endl; }
            |expr MOD expr          { cout << "expr -> expr % expr" << endl; }
            |expr BIGGER expr       { cout << "expr -> expr > expr" << endl; }
            |expr BIGGER_EQ expr    { cout << "expr -> expr >= expr" << endl; }
            |expr LESS expr         { cout << "expr -> expr < expr" << endl; }
            |expr LESS_EQ expr      { cout << "expr -> expr <= expr" << endl; }
            |expr EQUAL expr        { cout << "expr -> expr == expr" << endl; }
            |expr DIFFER expr       { cout << "expr -> expr != expr" << endl; }
            |expr AND expr          { cout << "expr -> expr && expr" << endl; }
            |expr OR expr           { cout << "expr -> expr || expr" << endl; }
            |term                   { cout << "expr -> term" << endl; }
            ;

term:       START_PARENTHESIS expr END_PARENTHESIS  { cout << "term -> (expr)" << endl; }
            |primary    {{ cout << "term -> primary" << endl; }}
            |MINUS expr %prec UMINUS    { cout << "term -> -expr" << endl; }
            |PLUSPLUS
            lvalue
            {
                cout << "term -> ++lvalue" << endl;

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
            PLUSPLUS    { cout << "term -> lvalue++" << endl; }
            
            |MINUSMINUS
            lvalue
            {
                cout << "term -> --lvalue" << endl;

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
            MINUSMINUS  { cout << "term -> lvalue--" << endl; }
            |NOT expr   { cout << "term -> !expr" << endl; }
            ;


primary:    lvalue  { cout << "primary -> lvalue" << endl; }
            |call   { cout << "primary -> call" << endl; }
            |objectdef  { cout << "primary -> objectdef" << endl; }
            |START_PARENTHESIS funcdef END_PARENTHESIS  { cout << "primary -> (funcdef)" << endl; }
            |const  { cout << "primary -> const" << endl; }
            ;

lvalue:     ID
            {   
                cout << "lvalue -> id" << endl;

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
                cout << "lvalue -> local id" << endl;

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
                cout << "lvalue -> ::id" << endl;

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
             ASSIGN expr    { cout << "assignexpr -> lvalue = expr" << endl; }
             |call ASSIGN expr{
                 cout << "\033[1;31m" << 
                            "Function used as lvalue at line "<< yylineno <<
                            "\033[0m" << endl;
             }
             ;

member:     lvalue DOT {lwarning = false;} ID       { cout << "member -> lvalue.id" << endl; }
            |lvalue START_BRACKET expr END_BRACKET  { cout << "member -> lvalue[expr]" << endl; }
            |call DOT {lwarning = false;}  ID       { cout << "member -> call.id" << endl; }
            |call START_BRACKET expr END_BRACKET    { cout << "member -> call[expr]" << endl; }
            ;

call:       call START_PARENTHESIS elist END_PARENTHESIS    { cout << "call -> call (elist)" << endl; }
            |lvalue{
                SymbolTableEntry entry = create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH);
                SymbolTableEntry *entry_ptr = Lookup(entry,SCOPE);
                if(!isFunction(*entry_ptr)){
                   /* cout << "\033[1;31m" << 
                            "Can't use variable as func at line "<< yylineno <<
                            "\033[0m" << endl;*/
                }

            } callsuffix    { cout << "call -> lvalue callsuffix" << endl; }
            |START_PARENTHESIS funcdef END_PARENTHESIS START_PARENTHESIS elist END_PARENTHESIS  { cout << "call -> (funcdef)(elist)" << endl; }
            ;

callsuffix: normcall    { cout << "callsuffix -> normcall" << endl; }
            |methodcall { cout << "callsuffix -> methodcall" << endl; }
            ;

normcall:   START_PARENTHESIS elist END_PARENTHESIS { cout << "normcall -> (elist)" << endl; }
            ;

methodcall: DOUBLE_DOT ID START_PARENTHESIS elist END_PARENTHESIS   { cout << "methodcall -> ..id(elist)" << endl; }
            ;

elist:      expr commaexpr  { cout << "elist -> expr commaexpr" << endl; }
            |               { cout << "elist -> " << endl; }
            ;

commaexpr:  COMMA expr commaexpr    { cout << "commaexpr -> ,expr commaexpr" << endl; }
            |                       { cout << "commaexpr -> " << endl; }
            ;

objectdef:  START_BRACKET elist END_BRACKET     { cout << "objectdef -> [elist]" << endl; }
            |START_BRACKET indexed END_BRACKET  { cout << "objectdef -> [indexed]" << endl; }
            ;
                

indexed:            indexedelem commaindexedelem   { cout << "indexed -> indexedelem commaindexedelem" << endl; }
                    ;

commaindexedelem:   COMMA indexedelem commaindexedelem  { cout << "commaindexelem -> ,indexelem commaindexelem" << endl; }
                    |                                   { cout << "commaindexelem -> " << endl; }
                    ;
        
indexedelem:        CURLY_START_BRACKET expr COLON expr CURLY_END_BRACKET   { cout << "indexelem -> {expr:expr}" << endl; }
                    ;

block:              CURLY_START_BRACKET
                    {
                        SCOPE++;
                    }
                    CURLY_END_BRACKET
                    {
                        cout << "block -> {}" << endl;
                        Hide(SCOPE--);
                    }
                    |CURLY_START_BRACKET
                    {
                        SCOPE++;
                    }
                    stmt program
                    CURLY_END_BRACKET
                    {
                        cout << "block -> {stmt program}" << endl;
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
                    block   { cout << "funcdef -> function (idlist) block" << endl; }
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
                    {
                        cout << "funcdef -> function id(idlist) block" << endl;
                        FUNC_DEPTH--;
                    }
                    ;

const:              REAL        { cout << "const -> real" << endl; }
                    |INTEGER    { cout << "const -> integer" << endl; }
                    |STRING     { cout << "const -> string" << endl; }
                    |NIL        { cout << "const -> nil" << endl; }
                    |TRUE       { cout << "const -> true" << endl; }
                    |FALSE      { cout << "const -> false" << endl; }
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
                    commaid     { cout << "idlist -> id commaid" << endl; }
                    |           { cout << "idlist -> " << endl; }
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
                    commaid     { cout << "commaid -> ,id commaid" << endl; }
                    |           { cout << "commaid -> " << endl; }
                    ;

ifstmt:             IF START_PARENTHESIS expr END_PARENTHESIS stmt      { cout << "ifstmt -> if(expr) stmt" << endl; }
                    |IF START_PARENTHESIS expr END_PARENTHESIS stmt ELSE stmt   { cout << "ifstmt -> if(expr) stmt else stmt" << endl; }
                    ;

whilestmt:          WHILE{loop_counter++;} START_PARENTHESIS expr END_PARENTHESIS stmt
                    {
                        cout << "whilestmt -> while(expr) stmt" << endl;

                        loop_counter--;
                        if(loop_counter < 0) loop_counter=0;
                    }
                    ;

forstmt:            FOR {loop_counter++;}START_PARENTHESIS elist SEMICOLON expr SEMICOLON elist END_PARENTHESIS stmt
                    {
                        cout << "forstmt -> for(elist; expr; elist) stmt" << endl;

                        loop_counter--;
                        if(loop_counter < 0) loop_counter=0;
                    }
                    ;

returnstmt:         RETURN{
                        if(FUNC_DEPTH==0){
                            cout << "\033[1;31m" << 
                                    "Return outside of function at line "<< yylineno <<
                                    "\033[0m" << endl;
                        }

                    } expr SEMICOLON    { cout << "returnstmt -> return expr;" << endl; }
                    | RETURN{
                        if(FUNC_DEPTH==0){
                            cout << "\033[1;31m" << 
                                    "Return outside of function at line "<< yylineno <<
                                    "\033[0m" << endl;
                        }
                    } SEMICOLON     { cout << "returnstmt -> return;" << endl; }
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
