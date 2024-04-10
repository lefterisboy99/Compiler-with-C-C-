#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define SIZE 509
#define HASH_MULTIPLIER 65599
#define SCOPE_MAX 10

/*Possible Types of Symbols*/
typedef enum SymbolTableType{
	GLOBAL, LOKAL, FORMAL,
	USERFUNC, LIBFUNC
}Type;

/*Arguments of functions*/
typedef struct Arguments{
        char *name;

        struct Arguments *next;
}FuncArg;

typedef struct emathmeixroiseiavyi{
	unsigned int offset;
	char *ScopeSpace;
	unsigned int FuncVarNum;
	unsigned int FuncAddress;
}Anatoli;

/*Node for any symbol*/
typedef struct SymTableNode{
	const char *name;				//name
	Type type;			    		//type
	FuncArg *Arg;	       				//arguments
	unsigned int scope;				//scope
	unsigned int line;				//line
	int IsActive;					//isActive
	Anatoli *condominass;				//LOL!
	struct SymTableNode *Scopenext;			//look to next scope
	struct SymTableNode *next;  	//next of symbol with same index
}SymbolNode;


/*The Symbol Table*/
typedef struct SymTable
{
	unsigned int length;
	SymbolNode *SymbolArray[SIZE];
}SymTable_T;

SymTable_T *oSymTable;
SymbolNode *ScopeArray[SCOPE_MAX];
int scope=0, ArrayFlag = 0, FunctionFlag = -1;
/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

/*Return the index where the symbol is going */
/*to be inserted based on it's name*/
static unsigned int SymTable_hash(const char *name)
{
    size_t i;
    unsigned int iHash;
    iHash = 0U;
    for (i = 0U; name[i] != '\0'; i++)
    iHash = iHash * HASH_MULTIPLIER + name[i];
    return iHash%SIZE;
}

/*Memory allocate for the whole SymbolTable*/
SymTable_T *SymTable_new(void)
{
	SymTable_T *oSymTable;
	size_t i;
	oSymTable = (SymTable_T*) malloc (sizeof(SymTable_T) );
	oSymTable->length = 0;

	for (i = 0U; i<SIZE; i++)
		oSymTable->SymbolArray[i] = NULL;

	return oSymTable;
}

/*Return the length of the SymbolTable*/
unsigned int SymTable_getLength(SymTable_T *oSymTable)
{
    	assert(oSymTable);
	return oSymTable->length;
}

/*Attach the newnode to the head of the scopelist*/
SymbolNode *AttachToScopeList(SymbolNode *ScopeArray[], SymbolNode *NewNode){

	if (ScopeArray[NewNode->scope] == NULL)
		return NewNode;

	NewNode->Scopenext = ScopeArray[NewNode->scope];
	return NewNode;
}

/*insert a Symbol to the Symbol Table*/
SymbolNode *InsertToSymTable(SymTable_T *oSymTable, SymbolNode *ScopeArray[],  const char *name, Type type, 
		     int scope, int line, int offset, char *ScopeSpace,int funcaddress)
{
	SymbolNode *NewNode, *root;
	Anatoli *Newanal;
	size_t index;

	assert(oSymTable);
    	assert(name);
	/*check if already exists and return 0;*/

	index = SymTable_hash(name);//calculate the index of the new node

	NewNode = ( SymbolNode* ) malloc(sizeof (SymbolNode) );//allocate memory for 1 node

	NewNode->name = strdup(name);//initialize characteristics of node
	NewNode->type = type;
	NewNode->Arg = NULL;
	NewNode->scope = scope;
	NewNode->line = line;
	NewNode->IsActive = 1;
	
	//3hfash
	Newanal= (Anatoli*) malloc(sizeof (Anatoli) );
	Newanal->offset=offset;
	if(ScopeSpace)
	      Newanal->ScopeSpace=strdup(ScopeSpace);
	else
	      Newanal->ScopeSpace=NULL;
	Newanal->FuncVarNum=-1;
	Newanal->FuncAddress=funcaddress;
	
	NewNode->condominass = Newanal;
	//*/
	
	NewNode->Scopenext = NULL;
	NewNode->next = NULL;
		

	ScopeArray[scope] = AttachToScopeList(ScopeArray, NewNode);  //Connect to the scope list

	oSymTable->length++;//raise the number of items in the symtable 

	root = oSymTable->SymbolArray[index];//insert the new node in the table
	if(oSymTable->SymbolArray[index] == NULL)
	{
		oSymTable->SymbolArray[index] = NewNode;
	}
	else
	{
		NewNode->next = root;
		oSymTable->SymbolArray[index] = NewNode;
	}

	return NewNode;
}

/*Inserts an argument to the argument list of a function node
  It is mkay to insert the argument to the node on the head of the hash[index]
  since the insertion happens always on the function that has just been added*/
int InsertArgToFunction (SymTable_T * oSymTable, SymbolNode *ScopeArray[], SymbolNode * FunctionNode, char *Name)
{
	FuncArg *NewNode, *tmp;

	if (FunctionNode == NULL)
		return 0;

	tmp = FunctionNode->Arg;

	NewNode = ( FuncArg* ) malloc(sizeof (FuncArg) );//allocate memory for 1 node
	NewNode->name = strdup(Name);//Initialize the elements
	NewNode->next = NULL;
	
	if (tmp == NULL){//if first add to head cause head is tail
		FunctionNode->Arg = NewNode;
		return 1;
	}
	//if not first add to tail
	while(tmp->next != NULL){
		/*go to tail*/
		tmp = tmp->next;
	}
	tmp->next = NewNode;//insert to tail
	
	return 1;
}

/*Hides Symbols on a specific scope*/
void Scope_Hide(int scope, SymbolNode *ScopeArray[]){
	SymbolNode* tmp= ScopeArray[scope];

	while(tmp!=NULL){
		tmp->IsActive=0;
		tmp=tmp->Scopenext;
	}
}

/*Checks if name exists in a certain scope */
SymbolNode * Scope_NameLookup(SymbolNode *ScopeArray[],int scope, char *name){
	SymbolNode* tmp= ScopeArray[scope];

	while(tmp!=NULL){
		if(tmp->IsActive==1){
			if ( !strcmp(tmp->name,name) ){
			      return tmp; //found!
			}
		}
		tmp=tmp->Scopenext;
	}
	return NULL;//not found  
}

/*Checks if name exists in a certain scope and if it has the Type type */
int Scope_NameTypeLookup(SymbolNode *ScopeArray[],int scope, char *name, Type type){
	SymbolNode* tmp = ScopeArray[scope];

	while(tmp!=NULL){
		if(tmp->IsActive==1){
			if ( !strcmp(tmp->name,name) ){
				if (tmp->type == type){
					return 1;
				}
			}
		}
		tmp=tmp->Scopenext;
	}
	return 0;//not found
}

/*Checks if any User function exist on a scope*/
int Scope_UserFuncLookup(SymbolNode *ScopeArray[], int scope){
	SymbolNode* tmp= ScopeArray[scope];

	while(tmp!=NULL){
		if(tmp->IsActive==1){
			if ( tmp->type == USERFUNC)
				return 1;
		}
		tmp=tmp->Scopenext;
	}
	return 0;
}

/*Checks for any function in a certain range of scopes*/
int FuncSearch(SymbolNode *ScopeArray[], int start, int finish){
	int i;
	for (i=start; i<=finish; i++){
		if (Scope_UserFuncLookup(ScopeArray, i))
			return 1;
	}
	return 0;
}

/*transforms Type to char* */
char *enum_to_str(Type type)
{
  if(type==GLOBAL)
    return "global";
  else if(type==LOKAL)
    return "local";
  else if(type==FORMAL)
    return "formal";
  else if(type==USERFUNC)
    return "userfunc";
  else if(type==LIBFUNC)
    return "libfunc";
  else 
    return "";
}

/*Prints the Symbol Table*/
void SymTable_Print(SymTable_T *oSymTable)
{
	size_t index;
	SymbolNode *tmp;
	FuncArg *tmpArg;

        assert(oSymTable);

	for (index=0U; index < SIZE; index++)
	{
		tmp = oSymTable->SymbolArray[index];

		if (tmp) printf("Symbol Table index: %zu  ", index);

        	while (tmp)
        	{
				if(tmp->IsActive==1){
					printf("\tName: %s, Type: %s, Scope: %d, Line: %d  with arguments:  ", 
							tmp->name, enum_to_str(tmp->type), tmp->scope, tmp->line);
					//phase 3
					if (tmp->condominass->ScopeSpace)
					      printf(", offset: %d, ScopeSpace: %s\n", tmp->condominass->offset, tmp->condominass->ScopeSpace);
					else
					      printf(",Function Vars: %d, Function Address: %d\n", tmp->condominass->FuncVarNum, tmp->condominass->FuncAddress);
					//end
					tmpArg = tmp->Arg;
					while(tmpArg != NULL){
						printf("%s  ",tmpArg->name);
						tmpArg = tmpArg->next;
					}
					printf ("\n");
			}
			tmp = tmp->next;
        	}
	}
	printf("\n");
}

/*Print the Scope Lists*/
void PrintAllScopes(SymbolNode *ScopeHead[]){

        int i;
        SymbolNode *tmp=NULL;

        for(i=0; i<SCOPE_MAX; i++){
                tmp = ScopeHead[i];

		if (tmp) printf("Scope Number %d:\n", i);

                while(tmp){
                        printf("\tName: %s, Type: %s, Scope: %d, Line: %d, IsActive: %d", 
				tmp->name, enum_to_str(tmp->type), tmp->scope, tmp->line, tmp->IsActive);
			 //phase 3
			 if (tmp->condominass->ScopeSpace)
			      printf(", offset: %d, ScopeSpace: %s\n", tmp->condominass->offset, tmp->condominass->ScopeSpace);
			 else
			      printf(",Function Vars: %d, Function Address: %d\n", tmp->condominass->FuncVarNum, tmp->condominass->FuncAddress);
			 //end
			 tmp = tmp->Scopenext;
                }
                printf("\n");
        }
}

//gia na set to offset k kala
void setFuncVarNum(SymbolNode *ScopeArray[], int num, char *FuncName, int currentscope){
      SymbolNode *func=Scope_NameLookup(ScopeArray,currentscope, FuncName);
      if(func){
	    func->condominass->FuncVarNum=num;
      }
}