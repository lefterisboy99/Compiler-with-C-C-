
#include "symbol_table.h"


struct compareobj{
  bool operator() (node_t *i,node_t *j) { return (i->scope<j->scope);}
} compare;

unordered_map<string, node_t> symbol_table;
vector <node_t *> scope_list;

vector <string> lib_funcs_keys;

vector <string> lib_funcs;

vector <string> active_func_name;

extern unsigned currScopeOffset();
extern scope_space_t currScopeSpace();

//create key with path of IDs and scope (use global vars scope and vector active_func_name)
//aytos poy tha me kalesei an einai function tha perasei san orisma to keno string ""
string create_key(string name){
    string key = to_string(scope) + "@";

    for (size_t i=0; i< active_func_name.size(); i++){
       if(  name == "" && active_func_name.size()-1 == i )
            key += active_func_name[i];
        else{
            key += active_func_name[i] + "@";
        }
    }
    key += name;

    // cout << "key:" << key << "     name:[" << name << "]" << endl; 

    return key;
}


void init_SymTable(){
    //       key,                  is_var,  name,                type,  scope,line_num, *args )
    insert( "print"              , false , "print"             , LIB_FUNC , 0   , 0 , NULL );
    insert( "input"              , false , "input"             , LIB_FUNC , 0   , 0 , NULL );
    insert( "objectmemberkeys"   , false , "objectmemberkeys"  , LIB_FUNC , 0   , 0 , NULL );
    insert( "objecttotalmembers" , false , "objecttotalmembers", LIB_FUNC , 0   , 0 , NULL );
    insert( "objectcopy"         , false , "objectcopy"        , LIB_FUNC , 0   , 0 , NULL );
    insert( "totalarguments"     , false , "totalarguments"    , LIB_FUNC , 0   , 0 , NULL );
    insert( "argument"           , false , "argument"          , LIB_FUNC , 0   , 0 , NULL );
    insert( "typeof"             , false , "typeof"            , LIB_FUNC , 0   , 0 , NULL );
    insert( "strtonum"           , false , "strtonum"          , LIB_FUNC , 0   , 0 , NULL );
    insert( "sqrt"               , false , "sqrt"              , LIB_FUNC , 0   , 0 , NULL );
    insert( "cos"                , false , "cos"               , LIB_FUNC , 0   , 0 , NULL );
    insert( "sin"                , false , "sin"               , LIB_FUNC , 0   , 0 , NULL );

    lib_funcs.push_back( "print" );
    lib_funcs.push_back( "input" );
    lib_funcs.push_back( "objectmemberkeys" );
    lib_funcs.push_back( "objecttotalmembers" );
    lib_funcs.push_back( "objectcopy" );
    lib_funcs.push_back( "totalarguments" );
    lib_funcs.push_back( "argument" );
    lib_funcs.push_back( "typeof" );
    lib_funcs.push_back( "strtonum" );
    lib_funcs.push_back( "sqrt" );
    lib_funcs.push_back( "cos" );
    lib_funcs.push_back( "sin" );

    lib_funcs_keys.push_back(create_key("print"));
    lib_funcs_keys.push_back(create_key("input"));
    lib_funcs_keys.push_back(create_key("objectmemberkeys"));
    lib_funcs_keys.push_back(create_key("objecttotalmembers"));
    lib_funcs_keys.push_back(create_key("objectcopy"));
    lib_funcs_keys.push_back(create_key("totalarguments"));
    lib_funcs_keys.push_back(create_key("argument"));
    lib_funcs_keys.push_back(create_key("typeof"));
    lib_funcs_keys.push_back(create_key("strtonum"));
    lib_funcs_keys.push_back(create_key("sqrt"));
    lib_funcs_keys.push_back(create_key("cos"));
    lib_funcs_keys.push_back(create_key("sin"));


}

node_t *look_up(string key) {

    if( symbol_table.find(key) == symbol_table.end() ) {
        return NULL ;
    }
    else {
        return &symbol_table[key];
    }
}


bool is_lib_func( string name ) {

    if ( find( lib_funcs.begin() , lib_funcs.end() , name ) != lib_funcs.end() ){//find it
        cout << "Error: \"" << name << "\" already defined as library function. scope:[" << scope << "]" << endl;
        return true;
    }
    return false;
}

bool is_lib_func_2( string name ){

    if ( find( lib_funcs.begin() , lib_funcs.end() , name ) != lib_funcs.end() ){//find it
        return true;
    }
    return false;
}


node_t *insert(string key, bool is_var, string name, type_t type, short int scope, unsigned long line_num, void *args ) {   
    node_t *new_symbol;
    
    new_symbol = new node_t;
    new_symbol->is_var = is_var;
    new_symbol->name = name;
    new_symbol->type = type;
    new_symbol->scope = scope;
    new_symbol->offset = currScopeOffset();
    new_symbol->scope_space = currScopeSpace();
    new_symbol->line_num = line_num;
    new_symbol->args = args; 
    new_symbol->is_active = true;
    new_symbol->next = NULL;
    symbol_table[key] = *new_symbol;
    traverse_inScope(new_symbol,scope);

    return new_symbol;
}

//First,sorts scopelist and then prints SymbolTable scope by scope
void print_SymTable(){  
    sort(scope_list.begin(), scope_list.end(), compare);
    for (size_t i=0; i < scope_list.size();i++){
        print_Scope(i);
    }
    return;
}

//Traverses Scopes list to insert symbol,if there's already a scope entry,it appends the list
void traverse_inScope(node_t *new_symbol,unsigned short int scope)
{   
    if (scope_list.empty()){
            scope_list.push_back(new_symbol);
            return;
    }
    for (size_t i=0; i < scope_list.size();i++){
        if (scope_list[i]->scope==scope){
            insert_inScope(new_symbol,scope_list[i]);
            return;
        }
    }
    scope_list.push_back(new_symbol);
    return;
}

//Appends new_symbol to head's scope list
void insert_inScope(node_t *new_symbol,node_t *head){
    node_t *ptr=head;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next=new_symbol;
    return;
}

//LookUp in particular scope
node_t* LookUp_Scope(string name,int scope){
    for (size_t i=0; i < scope_list.size();i++){
        // cout << "look_up_scope"<< scope_list.size() << endl;
        if (scope_list[i]->scope==scope){
            return LookUp_Scope_helper(scope_list[i],name);
        }
    }
    return NULL;
}
//Traverses through a scope looking for a name
node_t* LookUp_Scope_helper(node_t *head,string name){
    node_t *ptr=head;
    while(ptr != NULL){
        if(ptr->name==name && ptr->is_active == true){
            return ptr;
        }
            
        ptr = ptr->next;
    }
    return NULL;
}
//hide function : set is_active into false or true depends the argument
//NON-TESTED
void set_is_active(unsigned short int scope , bool is_active ){
    node_t *ptr = NULL;
    
    for (size_t i=1; i < scope_list.size();i++){
        if (scope_list[i]->scope==scope){
            ptr=scope_list[i];
           break;
        }
    }
    while(ptr != NULL){
        ptr->is_active = is_active;
        ptr = ptr->next;
    }
    return;
}

void print_spaces(size_t length)
{
    int i = 30 - length;
    while(i > 0){
        cout << " ";
        i--;
    }
}

//Prints scope's content
void print_Scope(unsigned short int scope){
    node_t *ptr=scope_list[scope];
    printf("----------------------------------\tScope:#%d\t----------------------------------\n",ptr->scope);
    while(ptr != NULL){
        cout << "\"" << ptr->name << "\"";
        print_spaces(ptr->name.length());
        printf("%s \t(line %lu)\t (scope %d)\n", getEnum(ptr->type),ptr->line_num,ptr->scope);
        ptr = ptr->next;
    }
    cout << endl;
    return ;
}

//Enum to string
const char* getEnum(type_t type) {
   switch (type) 
   {
      case GLOBAL_VAR: return "[Global Variable ]";
      case FUNC_ARG: return   "[Formal Argument ]";
      case LOCAL_VAR: return  "[Local Variable  ]";
      case USER_FUNC: return  "[User Function   ]";
      case LIB_FUNC: return   "[Library Function]";
   }

   return "getNum()\n";
}