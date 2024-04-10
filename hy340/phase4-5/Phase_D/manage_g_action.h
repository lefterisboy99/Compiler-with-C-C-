#include "symbol_table.h"

extern int yylineno;
extern unsigned short int scope;
extern unsigned int anon_func;
extern vector <string> statement_stack;



char *Manage_term__pre_post_op_lvalue(node_t *exprNode , string type_of_op );
char *Manage_assignexpr__lvalue_assignment_expr(node_t *exprNode);
expr *Manage_lvalue__ID(char *id);
expr *Manage_lvalue__LOCAL_ID(char *id);
expr *Manage_lvalue__COLONCOLON_ID(char *id);

void Manage__open_block();
void Manage__close_block();

node_t *Manage_ID_OR_NOT__ID(char *id);
node_t *Manage_ID_OR_NOT__Anonymous();
void Manage_idlist__ID(char *id);


void Manage_idlist__idlist_comma_ID(char *id);


/*helpers functions*/
void clear_statement_stack();
void is_correct_break_continue(string instruction);
void is_correct_return();

//#####################################   phase 3    ###########################################
void emit( iopcode op, expr *result, expr *arg1, expr *arg2,  long int label, unsigned long line);
expr *emit_op(iopcode opcode , expr *arg1, expr *arg2 ,  long int label, unsigned long line);
expr *emit_relop(iopcode opcode , expr *arg1, expr *arg2 ,  long int label, unsigned long line);
expr *emit_boolop(iopcode opcode , expr *arg1, expr *arg2 ,  long int label, unsigned long line);


string newTmpName();
void resetTmpVarNameC();
unsigned short int currscope();
node_t* newTmpVarName();
scope_space_t currScopeSpace();
unsigned currScopeOffset();
void incrCurrScopeOffset();
void enterScopeSpace();
void exitScopeSpace();
void resetFormalArgsOffset();
void resetFuncLocalOffset();
void restoreCurrScopeOffset(unsigned num);
void patchLabel(unsigned quadNum , long int label);
expr *lvalueExpr( node_t *sym);

expr *member_item(expr *lvalue , string name);
expr *newExpr( expr_t type );
expr *newExprConstString(string s);
expr *emit_ifTableItem(expr *e);
expr *make_call( expr *lvalue , expr *elist_container );
expr* newExpr_constNum(double i);
expr *newExpr_constBool(int bool_val);
bool is_op_applicable(expr *e);
bool is_boolop_applicable(expr *e);

//##################    BackPatching     ##################
vector<long int> *merge(vector <long int> *l1 , vector <long int> *l2);
void backpatch( vector <long int> *l , long int NQ);
//##################    prints     ##################
void printQuads();
string iopcodeToString(ioquad_t quad); 
string expr_tToString(expr* e); 
void print_const_from_type(expr e );


void DEBUG_PRINTS_OFFSET(string str);