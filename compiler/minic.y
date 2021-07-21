%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 999
#define LABELSIZE 32
struct tokenType
{
	int tokenNumber;
	char *tokenValue;
};
typedef struct nodeType {
	struct tokenType token;
	enum {terminal , nonterm } noderep;
	struct nodeType *son;
	struct nodeType *brother;
}Node;

typedef enum{
CONST_TYPE,VAR_TYPE,FUNC_TYPE
}Qualifier;
typedef enum{
INT_TYPE,VOID_TYPE
}Specifier;
typedef struct symbolInfo
{
	char *id;
	Qualifier typeQualifier;
	Specifier typeSpecifier;
	int width;
	int base;
	int offset;
	int initialValue;
}symbolInfo;
symbolInfo symbolTable[MAX];
//Node *parser();
int meaningfulToken(struct tokenType token);
Node *buildNode(struct tokenType token);
Node *buildTree( struct tokenType token, Node* son);
void printNode(FILE *astFile ,Node *pt , int indent);
void appendBro(Node * node, Node *bro);
void printTree(FILE *astFile ,Node *pt, int indent);
struct tokenType makeToken(int tokenNumber , char *tokenValue);
char* TokenToString(char *token);
void semantic(int);
int yylex(void);
void yyerror(char *);

//code gen func start
void processFuncHeader(Node *ptr);
int typeSize();
void codeGen(Node *root);
void processDeclaration(Node *ptr); //decl
void processSimpleVariable(Node *ptr, Specifier typeSpecifier , Qualifier typeQualifier); //simple
void processArrayVariable(Node *ptr, Specifier typeSpecifier , Qualifier typeQualifier);
void processOperator(Node *ptr);
void icg_error(int i);
void emit0(char *opcode);
void emit1(char *opcode ,int op1);
void emit2(char *opcode ,int op1,int op2);
void emit3(char *opcode , int op1, int op2, int op3);
void emitProc(char *funcName , int op1,int op2, int op3); //for proc
void emitJump( char *opcode, char* label);
void emitLabel(char* label);//emit needed
void genLabel(char *label);
int checkPredefined(Node *ptr);
void rv_emit(Node *ptr);
void initSymbolTalble(); // need
//void genSym(int base) //no need
int insert(char *id, Specifier typeSpecifier , Qualifier typeQualifier , int base, int offset , int width,  int initialValue);
void processCondition(Node *ptr);
void initLocalSymbolTable();
int lookup(char *id);// look for the id by the name

//code gen finished
int main(void);
Node * root;
FILE *ucodeFile;
int g_curIndex;
int g_base;
int g_offset;
int g_width;
int flag_returned;
int label_num;
int sym_base;
int max_top;
struct tokenType temp;
struct tokenType temp_2;
enum nodeNumber {
ACTUAL_PARAM , ADD, ADD_ASSIGN , ARRAY_VAR , ASSIGN_OP,
CALL, COMPOUND_ST , CONST_NODE, DCL, DCL_ITEM, DCL_LIST,
DCL_SPEC , DIV, DIV_ASSIGN , EQ, ERROR_NODE , EXP_ST , FORMAL_PARA,
FUNC_DEF , FUNC_HEAD, GE ,GT , IDENT, IF_ELSE_ST , IF_ST,
INDEX, INT_NODE, LE , LOGICAL_AND , LOGICAL_NOT , LOGICAL_OR, LT, MOD,
MOD_ASSIGN , MUL, MUL_ASSIGN , NE ,NUMBER ,PARAM_DCL , POST_DEC ,POST_INC ,
PRE_DEC , PRE_INC , PROGRAM, RETURN_ST , SIMPLE_VAR , STAT_LIST , SUB, 
SUB_ASSIGN,UNARY_MINUS, VOID_NODE, WHILE_ST,TIDENT,TNUMBER
};
char *nodeName[] = 
{
"ACTUAL_PARAM" , "ADD", "ADD_ASSIGN" , "ARRAY_VAR" , "ASSIGN_OP",
"CALL", "COMPOUND_ST", "CONST_NODE", "DCL", "DCL_ITEM", "DCL_LIST",
"DCL_SPEC" , "DIV", "DIV_ASSIGN" , "EQ", "ERROR_NODE" , "EXP_ST" , "FORMAL_PARA",
"FUNC_DEF" , "FUNC_HEAD", "GE" ,"GT" , "IDENT", "IF_ELSE_ST" , "IF_ST",
"INDEX", "INT_NODE", "LE" , "LOGICAL_AND" , "LOGICAL_NOT" , "LOGICAL_OR", "LT", "MOD",
"MOD_ASSIGN" , "MUL", "MUL_ASSIGN" , "NE" ,"NUMBER" ,"PARAM_DCL" , "POST_DEC" ,"POST_INC" ,
"PRE_DEC" , "PRE_INC" , "PROGRAM", "RETURN_ST" , "SIMPLE_VAR" , "STAT_LIST" , "SUB", 
"SUB_ASSIGN", "UNARY_MINUS" ,"VOID_NODE", "WHILE_ST"
};
int ruleName[] ={
0,PROGRAM,0,0,0,
0,FUNC_DEF,FUNC_HEAD,DCL_SPEC,0,
0,0,0,CONST_NODE,INT_NODE,
VOID_NODE,0,FORMAL_PARA,0,0,
0,0,PARAM_DCL,COMPOUND_ST,DCL_LIST,
DCL_LIST,0,0,DCL,0,
0,DCL_ITEM,DCL_LIST,SIMPLE_VAR,ARRAY_VAR,
0,0,STAT_LIST,0,0,
0,0,0,0,0,
0,EXP_ST,0,0,IF_ST,
IF_ELSE_ST,WHILE_ST,RETURN_ST,0,0,
ASSIGN_OP,ADD_ASSIGN,SUB_ASSIGN,MUL_ASSIGN,DIV_ASSIGN,
MOD_ASSIGN,0,LOGICAL_OR,0,LOGICAL_AND,
0,EQ,NE,0,GT,
LT,GE,LE,0,ADD,
SUB,0,MUL,DIV,MOD,
0,UNARY_MINUS,LOGICAL_NOT,PRE_INC,PRE_DEC,
0,INDEX,CALL,POST_INC,POST_DEC,
0,0,ACTUAL_PARAM,0,0,
0,0,0
};

%}
%union {
	struct nodeType *node;
	int value;
	char *string;
}
%token teof tnull tnot tnotequ tmod tmodAssign
tand tlparen trparen tmul tmulAssign tplus tinc taddAssign 
tcomma tminus tdec tsubAssign tdiv tdivAssign tsemicolon
tless tlesse tassign tequal tgreat tgreate tlbracket trbracket
tconst telse tif tint treturn tvoid twhile tlbrace tor trbrace
%token <string> tident tnumber
%type <node> translation_unit external_dcl  function_def function_header compound_st  function_name dcl_specifiers type_qualifier
type_specifier formal_param opt_formal_param param_dcl  declarator opt_dcl_list opt_stat_list declaration_list declaration dcl_spec init_dcl_list init_declarator statement_list opt_number statement expression_st opt_expression expression if_st while_st return_st assignment_exp logical_or_exp unary_exp logical_and_exp equality_exp relational_exp additive_exp multiplicative_exp postfix_exp primary_exp  dcl_specifier formal_param_list
opt_actual_param actual_param actual_param_list 

%nonassoc IFX
%nonassoc telse
%%
mini_c           : translation_unit                       {semantic(1); temp = makeToken(PROGRAM, nodeName[PROGRAM]); root = buildTree(temp,$1);  };
translation_unit : external_dcl				  {semantic(2); $$ = $1;}
                 | translation_unit external_dcl            {semantic(3);appendBro($1,$2); $$ = $1;}; 
external_dcl     : function_def                             {semantic(4); 
$$ = $1;}
                 | declaration                              {semantic(5);$$ = $1;};
function_def     : function_header compound_st             {semantic(6);
appendBro($1 ,$2);
temp = makeToken(FUNC_DEF, nodeName[FUNC_DEF]); $$ = buildTree(temp,$1); };
function_header  : dcl_spec function_name formal_param     {semantic(7);
appendBro($1,$2); appendBro($2,$3);
temp = makeToken(FUNC_HEAD , nodeName[FUNC_HEAD]); $$ = buildTree(temp,$1); };
dcl_spec         : dcl_specifiers                          {semantic(8);
temp = makeToken(DCL_SPEC, nodeName[DCL_SPEC]); $$ = buildTree(temp,$1); };
dcl_specifiers   : dcl_specifier                           {semantic(9); $$ = $1;}
                 | dcl_specifiers dcl_specifier         {semantic(10);appendBro($1,$2); $$ = $1;} ;          
dcl_specifier    : type_qualifier                           {semantic(11); $$ = $1;}
                 | type_specifier                            {semantic(12);$$ = $1;};                           
type_qualifier   : tconst                                {semantic(13);
temp = makeToken(CONST_NODE, nodeName[CONST_NODE]); $$ = buildTree(temp,NULL); };
type_specifier   : tint                                   {semantic(14);
temp = makeToken(INT_NODE, nodeName[INT_NODE]); $$ = buildTree(temp,NULL);}
                 | tvoid                                {semantic(15);
                 temp = makeToken(VOID_NODE, nodeName[VOID_NODE]); $$ = buildTree(temp,NULL);};
function_name    : tident				 {semantic(16);
temp = makeToken(TIDENT, $1); $$ = buildNode(temp);};
formal_param     : tlparen opt_formal_param trparen              {semantic(17);
temp = makeToken(FORMAL_PARA, nodeName[FORMAL_PARA]); $$ = buildTree(temp,$2);};
opt_formal_param : formal_param_list                            {semantic(18); $$ = $1;}
		| 	{semantic(19); $$ = NULL;};
formal_param_list: param_dcl                                     {semantic(20);$$ = $1;}
                 | formal_param_list tcomma param_dcl             {semantic(21);appendBro($1,$3); $$ = $1;};
param_dcl        : dcl_spec declarator                  {semantic(22);
appendBro($1,$2); 
temp = makeToken(PARAM_DCL, nodeName[PARAM_DCL]); $$ = buildTree(temp,$1);} ;

compound_st      : tlbrace opt_dcl_list opt_stat_list trbrace     {semantic(23); appendBro($2,$3);temp = makeToken(COMPOUND_ST, nodeName[COMPOUND_ST]);$$ = buildTree(temp,$2); };
opt_dcl_list     : declaration_list                         {semantic(24);
temp = makeToken(DCL_LIST, nodeName[DCL_LIST]);$$ = buildTree(temp,$1);}
                 |                                      	{semantic(25);temp = makeToken(DCL_LIST, nodeName[DCL_LIST]);$$ = buildTree(temp,NULL);};
declaration_list : declaration                                    {semantic(26);$$ = $1;}
                 | declaration_list declaration                  {semantic(27);appendBro($1,$2); $$ = $1;};
declaration      : dcl_spec init_dcl_list tsemicolon             {semantic(28); appendBro($1,$2);
temp = makeToken(DCL, nodeName[DCL]);$$ = buildTree(temp,$1);}; 
init_dcl_list    : init_declarator                           {semantic(29);$$ = $1;}
                 | init_dcl_list tcomma init_declarator        {semantic(30);appendBro($1,$3); $$ = $1;};
init_declarator  : declarator                                     {semantic(31);
$$ = $1;}
                 | declarator tassign tnumber               {semantic(32); Node *ptr; temp_2 = makeToken(TNUMBER , $3); ptr = buildNode(temp_2);
                 appendBro($1,ptr); $$= $1;};
declarator       : tident                                  {semantic(33);
temp = makeToken(SIMPLE_VAR, nodeName[SIMPLE_VAR]);temp_2 = makeToken(TIDENT, $1); Node* ptr =buildNode(temp_2); Node*ptr2 = buildTree(temp,ptr);
temp = makeToken(DCL_ITEM, nodeName[DCL_ITEM]);
$$ = buildTree(temp,ptr2);}
                 | tident tlbracket opt_number trbracket            {semantic(34);temp = makeToken(ARRAY_VAR, nodeName[ARRAY_VAR]);temp_2 = makeToken(TIDENT, $1); Node* ptr =buildNode(temp_2); appendBro(ptr , $3);  Node*ptr2 = buildTree(temp,ptr); temp = makeToken(DCL_ITEM, nodeName[DCL_ITEM]);
$$ = buildTree(temp,ptr2);};
opt_number       : tnumber			               {semantic(35); temp = makeToken(TNUMBER, $1); $$ = buildNode(temp);}		
                 |                                                {semantic(36);$$ = NULL;};
                 
opt_stat_list    : statement_list                           {semantic(37);temp = makeToken(STAT_LIST ,nodeName[STAT_LIST]); $$ = buildTree(temp,$1);}
                 |                                         {semantic(38); $$ = NULL;};
statement_list   : statement                                 {semantic(39); $$ = $1;}
                 | statement_list statement                    {semantic(40);appendBro($1,$2); $$ = $1;};
statement        : compound_st				       {semantic(41); $$ = $1;}
                 | expression_st                                   {semantic(42);$$ = $1;}
                 | if_st                                          {semantic(43);$$ = $1;}
                 | while_st                                       {semantic(44);$$ = $1;}
                 | return_st                                      {semantic(45);$$ = $1;};  

expression_st    : opt_expression tsemicolon                   {semantic(46);temp = makeToken(EXP_ST ,nodeName[EXP_ST]); $$ = buildTree(temp,$1);} ;
opt_expression   : expression                                 {semantic(47);$$ =$1;}
                 |                                          {semantic(48);$$ = NULL;};
if_st            : tif tlparen expression trparen statement %prec IFX {semantic(49);appendBro($3,$5);temp = makeToken(IF_ST ,nodeName[IF_ST]); $$ = buildTree(temp,$3);}
                 | tif tlparen expression trparen statement telse statement  {semantic(50); appendBro($3, $5); appendBro($5,$7); temp = makeToken(IF_ELSE_ST ,nodeName[IF_ELSE_ST]); $$ = buildTree(temp,$3);};
while_st         : twhile tlparen expression trparen statement   {semantic(51); appendBro($3 ,$5);temp = makeToken(WHILE_ST ,nodeName[WHILE_ST]); $$ = buildTree(temp,$3);};
return_st        : treturn opt_expression tsemicolon            {semantic(52); temp = makeToken(RETURN_ST ,nodeName[RETURN_ST]); $$ = buildTree(temp,$2);};

expression       : assignment_exp                           {semantic(53);$$ = $1;}; 
assignment_exp   : logical_or_exp                          {semantic(54); $$ = $1;}
                 | unary_exp tassign assignment_exp            {semantic(55); appendBro($1,$3);
                 temp = makeToken(ASSIGN_OP ,nodeName[ASSIGN_OP]); $$ = buildTree(temp,$1);}  
                 | unary_exp taddAssign assignment_exp          {semantic(56);appendBro($1,$3);
                 temp = makeToken(ADD_ASSIGN ,nodeName[ADD_ASSIGN]); $$ = buildTree(temp,$1);}
                 | unary_exp tsubAssign assignment_exp           {semantic(57);appendBro($1,$3);
                 temp = makeToken(SUB_ASSIGN ,nodeName[SUB_ASSIGN]); $$ = buildTree(temp,$1);}
                 | unary_exp tmulAssign assignment_exp          {semantic(58);appendBro($1,$3);
                 temp = makeToken(MUL_ASSIGN ,nodeName[MUL_ASSIGN]); $$ = buildTree(temp,$1);}
                 | unary_exp tdivAssign assignment_exp          {semantic(59);appendBro($1,$3);
                 temp = makeToken(DIV_ASSIGN ,nodeName[DIV_ASSIGN]); $$ = buildTree(temp,$1);}
                 | unary_exp tmodAssign assignment_exp         {semantic(60);appendBro($1,$3);
                 temp = makeToken(MOD_ASSIGN ,nodeName[MOD_ASSIGN]); $$ = buildTree(temp,$1);} ;
logical_or_exp   : logical_and_exp				{semantic(61); $$ = $1;}
                 | logical_or_exp tor logical_and_exp    {semantic(62); appendBro($1,$3);
                 temp = makeToken(LOGICAL_OR ,nodeName[LOGICAL_OR]); $$ = buildTree(temp,$1);};
logical_and_exp  : equality_exp					{semantic(63);$$ =$1;}
                 | logical_and_exp tand equality_exp      {semantic(64);appendBro($1,$3);
                 temp = makeToken(LOGICAL_AND ,nodeName[LOGICAL_AND]); $$ = buildTree(temp,$1);};
equality_exp     : relational_exp				 {semantic(65);$$ =$1;}
                 | equality_exp tequal relational_exp          {semantic(66);appendBro($1,$3);
                 temp = makeToken(EQ ,nodeName[EQ]); $$ = buildTree(temp,$1);}
                 | equality_exp tnotequ relational_exp       {semantic(67);appendBro($1,$3);
                 temp = makeToken(NE ,nodeName[NE]); $$ = buildTree(temp,$1);};
relational_exp   : additive_exp					{semantic(68); $$ = $1;}
                 | relational_exp tgreat additive_exp        {semantic(69);appendBro($1,$3);
                 temp = makeToken(GT ,nodeName[GT]); $$ = buildTree(temp,$1);} 
                 | relational_exp tless additive_exp          {semantic(70);appendBro($1,$3);
                 temp = makeToken(LT ,nodeName[LT]); $$ = buildTree(temp,$1);}
                 | relational_exp tgreate additive_exp         {semantic(71);appendBro($1,$3);
                 temp = makeToken(GE ,nodeName[GE]); $$ = buildTree(temp,$1);}
                 | relational_exp tlesse additive_exp           {semantic(72); appendBro($1,$3);
                 temp = makeToken(LE ,nodeName[LE]); $$ = buildTree(temp,$1);};
additive_exp     : multiplicative_exp				{semantic(73); $$ =$1;}
                 | additive_exp tplus multiplicative_exp         {semantic(74); appendBro($1,$3);
                 temp = makeToken(ADD ,nodeName[ADD]); $$ = buildTree(temp,$1);}
                 | additive_exp tminus multiplicative_exp         {semantic(75);appendBro($1,$3);
                 temp = makeToken(SUB ,nodeName[SUB]); $$ = buildTree(temp,$1);};
multiplicative_exp : unary_exp                                      {semantic(76);$$ = $1;}
                   | multiplicative_exp tmul unary_exp        {semantic(77);appendBro($1,$3);
                 temp = makeToken(MUL ,nodeName[MUL]); $$ = buildTree(temp,$1);}
                   | multiplicative_exp tdiv unary_exp           {semantic(78);appendBro($1,$3);
                 temp = makeToken(DIV ,nodeName[DIV]); $$ = buildTree(temp,$1);}
                   | multiplicative_exp tmod unary_exp           {semantic(79);appendBro($1,$3);
                 temp = makeToken(MOD ,nodeName[MOD]); $$ = buildTree(temp,$1);};
unary_exp          : postfix_exp                                    {semantic(80); $$ = $1;}
                   | tminus unary_exp                                  {semantic(81);temp = makeToken(UNARY_MINUS ,nodeName[UNARY_MINUS]); $$ = buildTree(temp,$2);}
                   | tnot unary_exp					{semantic(82);temp = makeToken(LOGICAL_NOT ,nodeName[LOGICAL_NOT]); $$ = buildTree(temp,$2);}
                   | tinc unary_exp					 {semantic(83);temp = makeToken(PRE_INC ,nodeName[PRE_INC]); $$ = buildTree(temp,$2);}
                   | tdec unary_exp                       {semantic(84);
                   temp = makeToken(PRE_DEC ,nodeName[PRE_DEC]); $$ = buildTree(temp,$2);};
postfix_exp        : primary_exp                               {semantic(85);$$ = $1;}
                   | postfix_exp tlbracket expression trbracket         {semantic(86);appendBro($1,$3); temp = makeToken(INDEX ,nodeName[INDEX]); $$ = buildTree(temp,$1);}
                   | postfix_exp tlparen opt_actual_param trparen       {semantic(87);appendBro($1,$3); temp = makeToken(CALL ,nodeName[CALL]); $$ = buildTree(temp,$1);}
                   | postfix_exp tinc                         {semantic(88);temp = makeToken(POST_INC ,nodeName[POST_INC]); $$ = buildTree(temp,$1);}
                   | postfix_exp tdec                          {semantic(89);temp = makeToken(POST_DEC ,nodeName[POST_DEC]); $$ = buildTree(temp,$1);};
opt_actual_param   : actual_param                               {semantic(90);$$ = $1;}
                   |                                              {semantic(91);$$ = NULL;};
actual_param       : actual_param_list                    {semantic(92);temp = makeToken(ACTUAL_PARAM ,nodeName[ACTUAL_PARAM]); $$ = buildTree(temp,$1);};
actual_param_list  : assignment_exp                          {semantic(93);$$ = $1;}
                   | actual_param_list tcomma assignment_exp              {semantic(94);appendBro($1,$3); $$= $1;};
primary_exp        : tident				                    {semantic(95); temp = makeToken(TIDENT ,$1); $$ = buildNode(temp);}	
                   |tnumber					              {semantic(96);temp = makeToken(TNUMBER ,$1); $$ = buildNode(temp);}
                   | tlparen expression trparen                             {semantic(97);$$ = $2;}; 

%%
//#include minic.yy.c
void yyerror(char *s)
{
	printf("%s!!!! \n " , s);
}
void semantic(int n)
{
	printf("reduced rule number = %d\n" , n);
}
/*void main()
{
	printf("Start of MiniC\n");
	enum tsymbol tn;
	int i=0;
	while((tn=yylex()) !=teof)
{
i++;
if(tn == tnumber | tn == tident)
{
printf("%d token : %s saved value %s \n" , i, OpCodeName[tn] , token.value.id);
}
else 
{printf("%d token : %s \n" , i,OpCodeName[tn]);}

}

}*/

char* TokenToString(char *token)
{
	char *string;	
	string  = (char*) malloc(strlen(token)+1);
	strcpy(string,token);
	return string;
}
int meaningfulToken(struct tokenType token)
{
	if ((token.tokenNumber == tident) || (token.tokenNumber == tnumber))
		return 1;
	return 0;
}
Node *buildNode(struct tokenType token)
{
	Node *ptr;
	ptr = (Node *) malloc(sizeof(Node));
	if(!ptr) {printf("node malloc err");	exit(1);}
	ptr -> token = token;
	ptr -> noderep = terminal;
	ptr->son = ptr->brother = NULL;
	return ptr;
}
Node *buildTree(struct tokenType token, Node * son)
{
	Node *ptr;
	ptr = (Node*)malloc(sizeof(Node));
	if(!ptr) {printf("tree malloc err");	exit(1);}
	ptr-> token = token;
	ptr-> noderep = nonterm;
	ptr-> son = son;
	ptr->brother = NULL;

	return ptr;
}
void appendBro(Node * node, Node *bro)
{
	Node *ptr = node;
	while (ptr->brother != NULL){
		ptr = ptr->brother;
	}
	ptr->brother = bro;
	
}
void printNode(FILE *astFile,Node *pt, int indent)
{
	int i;
	//printf("node\n");
	for(i=1;i<=indent;i++) fprintf(astFile , " ");
	if (pt->noderep == terminal)
	{
		fprintf(astFile," Terminal : %s", pt->token.tokenValue);
				
	}
	else
	{
		fprintf(astFile, " Nonterminal : %s" , pt->token.tokenValue);	
	}
	fprintf(astFile , "\n");
}
void printTree(FILE *astFile,Node *pt, int indent)
{
	//printf("tree\n");
	Node *p = pt;
	while(p!=NULL)
	{
		printNode(astFile,p,indent);
		if(p->noderep == nonterm) 
		{
		printTree(astFile,p->son , indent+3);
		}
		p = p->brother;
	}
}
struct tokenType makeToken(int tokenNumber , char *tokenValue)
{
	struct tokenType temp;
	temp.tokenNumber = tokenNumber;
	//printf("%s\n" , tokenValue);
	temp.tokenValue = malloc(sizeof(char) *20);
	strcpy(temp.tokenValue ,tokenValue);
	//printf("%s\n" , temp.tokenValue); 			
	return temp;		
}
//until this ast gen step

//from this code gen step
int lookup(char *id)
{
	//printf("%d \n" , max_top);
	for (int i=1;i<max_top;i++)
	{
 //func
		if(!strcmp(symbolTable[i].id , id))
		{	
			if(symbolTable[i].typeQualifier == FUNC_TYPE || symbolTable[i].base == g_base)
			return i;
		} //sym
	}
	return -1;
}
void emit0(char *opcode)
{
	fprintf(ucodeFile , "           %s\n" , opcode);
}
void emit1(char *opcode ,int op1)
{
	fprintf(ucodeFile , "           %-7s %d\n" , opcode , op1);
}
void emit2(char *opcode ,int op1,int op2)
{
	fprintf(ucodeFile , "           %-7s %-7d %d\n" , opcode , op1 , op2);
}
void emit3(char *opcode , int op1, int op2, int op3)
{
	fprintf(ucodeFile , "           %-7s %-7d %-7d %d\n" , opcode , op1,op2,op3);
}
void emitProc(char *funcName , int op1,int op2, int op3)
{
	fprintf(ucodeFile , "%-10s %-7s %-7d %-7d %d\n" , funcName ,"proc", op1 , op2, op3);
} //for proc
void emitJump( char *opcode, char* label)
{
	fprintf(ucodeFile , "           %-7s %s\n" , opcode , label);
}
void emitLabel(char* label)
{
	fprintf(ucodeFile , "%-10s nop\n" , label);
}//emit needed
void genLabel(char *label)
{
	sprintf(label, "$$%d", label_num++);
}
int checkPredefined(Node *ptr)
{
    Node *p=ptr;
    char *funcName;
    int noArguments;
    int stIndex;

    funcName = p->token.tokenValue;
    if (!strcmp(funcName, "read")) {
        noArguments = 1;

        emit0("ldp");
        p = p->brother->son;
        while (p) {
            if (p->noderep == nonterm) {
                processOperator(p);
            } else {
                stIndex = lookup(p->token.tokenValue);
                if (stIndex == -1) {
                    return 0;
                }
                emit2("lda", symbolTable[stIndex].base, symbolTable[stIndex].offset);
            }
            noArguments--;
            p = p->brother;
        }


        emitJump("call", funcName);
        return 1;
    } else if (strcmp(funcName, "write") == 0) {
        noArguments = 1;

        emit0("ldp");
        p = p->brother->son;
        while (p) {
            if (p->noderep == nonterm) {
                processOperator( p);
            } else {
                stIndex = lookup(p->token.tokenValue);
                if (stIndex == -1) return 0;
                emit2("lod", symbolTable[stIndex].base, symbolTable[stIndex].offset);
            }
            noArguments--;
            p=p->brother;
        }

        emitJump("call", funcName);
        return 1;
    } else if (strcmp(funcName, "lf") == 0) {
        emitJump("call", funcName);
        return 1;
    }

    return 0;


}
int typeSize()
{
	return 1;
}
void processSimpleVariable(Node *ptr , Specifier typeSpecifier, Qualifier typeQualifier)
{
	Node *p = ptr->son;
	Node *q = ptr->brother;
	int stIndex,size,initialValue;
	int sign =1;
	
	if(ptr->token.tokenNumber !=SIMPLE_VAR) printf("err in simple_var\n");
	
	if(typeQualifier == CONST_TYPE){
	if(q == NULL)
	{
		printf("%s is const\n" , ptr->son->token.tokenValue);
	}
	if(q->token.tokenNumber == UNARY_MINUS)
	{
		sign = -1;
		q = q->son;
	}
	initialValue = sign * atoi(q->token.tokenValue);
	stIndex = insert(p->token.tokenValue , typeSpecifier , typeQualifier,0,0,0,initialValue);
	}
	else{
	size = typeSize();
	stIndex = insert(p->token.tokenValue , typeSpecifier , typeQualifier , g_base, g_offset , g_width , 0);
	g_offset +=size;
	
	}

} // this looks good
void processArrayVariable(Node *ptr , Specifier typeSpecifier , Qualifier typeQualifier)
{
	Node *p = ptr->son;
	int stIndex, size;
	
	if(ptr->token.tokenNumber != ARRAY_VAR)
	{
		printf("err in array_var\n");
		return;
	}
	if(p->brother == NULL)
		printf("arr size must be specified\n");
	else size  = atoi(p->brother->token.tokenValue); //can occur error
	
	size *= typeSize();
	
	stIndex = insert(p->token.tokenValue , typeSpecifier , typeQualifier, g_base , g_offset , size , 0);
	g_offset +=size;

} // this looks good
void processOperator(Node *ptr)
{
	int stIndex;
	int lvalue;
	switch(ptr->token.tokenNumber)
	{
		case ASSIGN_OP:
		{
			Node *lhs = ptr->son;
			Node *rhs = ptr->son->brother;
			if (lhs-> noderep == nonterm)
			{
				lvalue =1;
				processOperator(lhs);
				lvalue = 0;
			}
			if(rhs->noderep == nonterm) processOperator(rhs);
			else rv_emit(rhs);
			if(lhs->noderep == terminal) 
			{
			stIndex = lookup(lhs->token.tokenValue);
			if(stIndex == -1)
			{
				printf("undefined err %s \n" , lhs->token.tokenValue);
				return;
			} //err occured
				emit2("str",symbolTable[stIndex].base,symbolTable[stIndex].offset);
			
		}
		else 
			emit0("sti");
		break;
		}
	
		case ADD_ASSIGN : case SUB_ASSIGN: case MUL_ASSIGN:
		case DIV_ASSIGN : case MOD_ASSIGN:
		{
			Node *lhs = ptr->son;
			Node *rhs = ptr->son->brother;
			int nodeNumber = ptr->token.tokenNumber;
			
			if (lhs-> noderep == nonterm)
			{
				lvalue =1;
				processOperator(lhs);
				lvalue = 0;
			}
			ptr->token.tokenNumber = nodeNumber;
			
			if(lhs ->noderep == nonterm)
			{
				processOperator(lhs);
			}
			else
				rv_emit(lhs);
			if(rhs->noderep == nonterm)
				processOperator(rhs);
			else 
				rv_emit(rhs);
			switch(ptr->token.tokenNumber)
			{
				case ADD_ASSIGN: emit0("add"); break;
				case SUB_ASSIGN: emit0("sub"); break;
				case MUL_ASSIGN: emit0("mult"); break;
				case DIV_ASSIGN: emit0("div"); break;
				case MOD_ASSIGN: emit0("mod"); break;
			
			}
			if(lhs->noderep == terminal)
			{
				stIndex = lookup(lhs->token.tokenValue);
				if(stIndex == -1)
				{
					printf("undefined var\n");
					return;
				}
				emit2("str" , symbolTable[stIndex].base , symbolTable[stIndex].offset);
			}
			else
				emit0("sti");
			break;
		}
		case ADD: case SUB: case MUL: case DIV: case MOD:
		case EQ: case NE: case GT: case LT: case GE: case LE:
		case LOGICAL_AND: case LOGICAL_OR:
		{
			Node *lhs = ptr->son;
			Node *rhs = ptr->son->brother;
			
			if(lhs->noderep == nonterm) processOperator(lhs);
			else rv_emit(lhs);
			if(rhs->noderep == nonterm) processOperator(rhs);
			else rv_emit(rhs);
			switch(ptr->token.tokenNumber)
			{
			case ADD: emit0("add"); break;
			case SUB: emit0("sub"); break;
			case MUL: emit0("mul"); break;
			case DIV: emit0("div"); break;
			case MOD: emit0("mod"); break;
			case EQ: emit0("eq"); break;
			case NE: emit0("ne"); break;
			case GT: emit0("gt"); break;
			case LT: emit0("lt"); break;
			case GE: emit0("ge"); break;
			case LE: emit0("le"); break;
			case LOGICAL_AND: emit0("and"); break;
			case LOGICAL_OR: emit0("or"); break;
			}
			break;
		}
		case UNARY_MINUS: case LOGICAL_NOT:
		{
			Node *p = ptr->son;
		
			if(p->noderep == nonterm) processOperator(p);
			else rv_emit(p);
			switch(ptr->token.tokenNumber)
			{
			case UNARY_MINUS: emit0("neg");break;
			
			case LOGICAL_NOT: emit0("not");break;
			}
		
		}
        case INDEX: {
            Node *indexExp = ptr->son->brother;

            if (indexExp->noderep == nonterm) processOperator(indexExp); 		    
	    else rv_emit(indexExp);
            stIndex = lookup(ptr->son->token.tokenValue);
            if (stIndex == -1) {
                printf("undefined var\n");
        
                return;
            }
            emit2("lda", symbolTable[stIndex].base , symbolTable[stIndex].offset);
            emit0("add");
            if (!lvalue)             {
                emit0("ldi");
            }
            break;
        }
        case PRE_INC:    case PRE_DEC:    case POST_INC:    case POST_DEC: {
            Node *p = ptr->son;
            Node *q;
            int stIndex;
            int amount = 1;

            if (p->noderep == nonterm) {
                processOperator(p);
            } else {
                rv_emit(p);
            }

            q = p;
            while (q->noderep != terminal)  {
                q = q->son;
            }

            if (!q || (q->token.tokenNumber != TIDENT)) {
                printf("inc/dec err\n");
                return;
            }
            stIndex = lookup( q->token.tokenValue);
            if (stIndex == -1) {
                return;
            }

            switch(ptr->token.tokenNumber) {
                case PRE_INC:    emit0("inc");    break;
                case PRE_DEC:    emit0("dec");    break;
                case POST_INC:   emit0("inc");    break;
                case POST_DEC:   emit0("dec");    break;
            }

            if (p->noderep == terminal) {
                stIndex = lookup( p->token.tokenValue);
                if (stIndex == -1)  {
                    return;
                }

                emit2("str", symbolTable[stIndex].base, symbolTable[stIndex].offset);
            } else if (p->token.tokenNumber == INDEX) {
                lvalue = 1;
                processOperator(p);
                lvalue = 0;
                emit0("swp");
                emit0("sti");
            } else printf( "inc/dec err\n");
            break;
        }
        case CALL: {
            Node *p = ptr->son;
            char *functionName;
            int stIndex;
            int noArguments;

            if (checkPredefined(p)) {//need
                break;
            }

            functionName = p->token.tokenValue;

            stIndex = lookup(functionName);
      
            if (stIndex == -1) {
                printf("func undefined\n");
                break;
            }
            noArguments = symbolTable[stIndex].width;
      
            emit0("ldp");
            p = p->brother->son;
            while (p)             {
                if (p->noderep == nonterm) {
                    processOperator(p);
                } else {
                    rv_emit(p);
                }
                noArguments--;
                p = p->brother;
            }

            if (noArguments > 0) {
                printf("too many arg\n");
            }

            if (noArguments < 0) {
                printf("too few arg\n");
            }

            emitJump("call", ptr->son->token.tokenValue);
            break;
        }	
	}
}
//gen label & proc & sym 
void processStatement(Node *ptr)
{
    Node *p;
    char label1[LABELSIZE] = {0};
    char label2[LABELSIZE] = {0};
    switch(ptr->token.tokenNumber) {
        case COMPOUND_ST:
            p = ptr->son->brother;
            p = p->son;
            while (p) {
                processStatement(p);
                p = p->brother;
            }
            break;

        case EXP_ST:
            if (ptr->son != NULL) {
                processOperator(ptr->son);
            }
            break;

        case RETURN_ST:
            if (ptr->son != NULL) {
                p = ptr->son;
                if (p->noderep == nonterm) {
                    processOperator( p);
                } else {
                    rv_emit( p);
                }
                emit0("retv");
            } else
                emit0("ret");
            flag_returned=1;
            break;

        case IF_ST:
            genLabel(label1);
            processCondition( ptr->son);
            emitJump("fjp", label1);
            processStatement( ptr->son->brother);
            emitLabel(label1);
        	break;

        case IF_ELSE_ST:
            genLabel(label1);
            genLabel(label2);
            processCondition( ptr->son);
            emitJump("fjp", label1);
            processStatement( ptr->son->brother);
            emitJump("ujp", label2);
            emitLabel(label1);
            processStatement(ptr->son->brother->brother);
            emitLabel(label2);
        	break;

        case WHILE_ST:
            genLabel(label1);
            genLabel(label2);
            emitLabel(label1);
            processCondition(ptr->son);
            emitJump("fjp", label2);

            processStatement(ptr->son->brother);

            emitJump("ujp", label1);
            emitLabel(label2);
	        break;

        default:
            break;
    }
}
void processDeclaration(Node *ptr)
{
	Specifier typeSpecifier ;
	Qualifier typeQualifier;
	Node *p, *q;

	if(ptr->token.tokenNumber != DCL_SPEC) icg_error(4);

	typeSpecifier = INT_TYPE;
	typeQualifier = VAR_TYPE;
	p = ptr->son;
	while(p){
	if(p->token.tokenNumber == INT_NODE)
		typeSpecifier = INT_TYPE;
	else if(p->token.tokenNumber == CONST_NODE)
		typeQualifier = CONST_TYPE;
	else{
		printf("dcl err!!!\n");
		return;
	}
	
	p = p->brother;
	}
	p = ptr->brother;
	if(p->token.tokenNumber != DCL_ITEM) icg_error(5);
	
	while(p){
		q = p->son;
		switch(q->token.tokenNumber){
		case SIMPLE_VAR:
			//printf("till good \n");
			//don't know but can't proceed param_dcl
			processSimpleVariable(q, typeSpecifier,typeQualifier);
			break;
		case ARRAY_VAR:
			processArrayVariable(q , typeSpecifier , typeQualifier);
			break;
		default: printf("err in simple, array %s\n" , q->token.tokenValue);
			break;
		
		}
	
		p = p->brother;
	} // while ended;

} //ok ok
void rv_emit(Node *ptr)
{
	int stIndex;

	if(ptr->token.tokenNumber == TNUMBER)
		emit1("ldc" , atoi(ptr->token.tokenValue));
	else
	{
		stIndex = lookup(ptr->token.tokenValue);
		if(stIndex == -1) return;
		if(symbolTable[stIndex].typeQualifier == CONST_TYPE)
			emit1("ldc" , symbolTable[stIndex].initialValue);
		else if (symbolTable[stIndex].width>1)
			emit2("lda" , symbolTable[stIndex].base , symbolTable[stIndex].offset);
		else
			emit2("lod" , symbolTable[stIndex].base , symbolTable[stIndex].offset);
	
	}
} //looks okay. ok

void icg_error(int i)
{
	printf("err no.%d occured!!!\n" , i);
}
void initLocalSymbolTable()
{
	g_base = ++sym_base;
	g_offset = 1;
	g_width = 1;
	g_curIndex = max_top-1;

}
void initSymbolTable()
{
	//for(int i=0;i<MAX;i++){
		//memset(&symbolTable[i] , 0 , sizeof(symbolInfo));}
	g_base = 1;
	g_offset =1;
	g_width = 1;
	g_curIndex= 0;
	max_top = g_curIndex+1;
}
void processFuncHeader( Node *ptr)
{
    Specifier returnType;
    int noArguments;
    Node *p;

    if (ptr->token.tokenNumber != FUNC_HEAD) {
        printf("err in processFuncHeader!!!\n");
    }

    p = ptr->son->son; //type
    while (p) {
        if (p->token.tokenNumber == INT_NODE) {
            returnType = INT_TYPE;
        } else if (p->token.tokenNumber == VOID_NODE) {
            returnType = VOID_TYPE;
        } else {
            printf("invalid function return type\n");
        }
        p = p->brother;
    }

    p = ptr->son->brother->brother;  // FORMAL_PARA
    p = p->son; 
    noArguments = 0;
    while (p) {
        noArguments++; //used in width
        p = p->brother;
    }
    insert( ptr->son->brother->token.tokenValue, returnType, FUNC_TYPE, 1,0, noArguments, 0); //funcName insert
}
void processFunction(Node *ptr)
{
	//cur FUNC_DEF
	int stIndex;
	char *funcName = (char*)malloc(sizeof(char) *32);
	Node *i;
	//funcheader all in after dcl
	strcpy(funcName ,  ptr->son->son->brother->token.tokenValue);
	//name
	stIndex = lookup(funcName);
	//printf("%d " , stIndex);
	int startingPoint = g_curIndex;
	int endingPoint= 0;
	flag_returned = 0;
	//1 param
	initLocalSymbolTable();
	//g_curIndex = startingPoint;
	if (stIndex == -1)
	{
		printf("finding err!!\n");
		//return -1;
	}
	if(ptr->son->son->brother->brother->son != NULL)
	{	//param exists
		for(i = ptr->son->son->brother->brother->son ; i ; i = i->brother) //PARAM_DCL 
		{
			if(i->token.tokenNumber == PARAM_DCL)
			{
				//printf("till good\n");
				processDeclaration(i->son);	
			}
			else
			{
				printf("err param_dcl!!!\n");
			}
		}
	}
		//2 declaration part
	if(ptr->son->brother->son->son != NULL)
	{
		for (i = ptr->son->brother->son->son; i; i = i->brother) 
		{
			//printf("yes!!\n");
        		if (i->token.tokenNumber == DCL) 
        		{
        		
            			processDeclaration(i->son); 
        		}
        		else
			{
				printf("err dcl!!!\n");
			}
    		}
	
	
	}
	//endingPoint = g_curIndex;
	//printf("%d %d\n" ,startingPoint,max_top);
	emitProc(funcName , symbolTable[max_top-1].offset , g_base ,2);
	//proc , sym
	for(int j= startingPoint+1 ; j<max_top; j++)
	{
		if(g_base == symbolTable[j].base)
		emit3("sym" , symbolTable[j].base , symbolTable[j].offset, symbolTable[j].width);
	}
	
	//3 emit function start code //sym
	//keyPoint
	//4 proc statement
	for(i = ptr->son->brother ; i ;i = i->brother)
	{
		if( i->token.tokenNumber == COMPOUND_ST)
		{
			processStatement(i);
		}
	}
	//5 ret
	if(flag_returned == 0)
	{
		emit0("ret");
	}
	emit0("end");
	//g_base = temp;
	//6 end

}
void processCondition(Node *ptr)
{
	if(ptr->noderep == nonterm) processOperator(ptr);
	else rv_emit(ptr);
	
}
int insert(char *id, Specifier typeSpecifier , Qualifier typeQualifier , int base, int offset, int width,  int initialValue)
{
	g_curIndex+=1;
	
	max_top++;
	//printf("%d %d \n" , g_curIndex , max_top);
	//symbolTable[g_curIndex].id = (char*)malloc(sizeof(char) *32);
	symbolTable[g_curIndex].id = id; 
	symbolTable[g_curIndex].typeSpecifier = typeSpecifier;
	symbolTable[g_curIndex].typeQualifier = typeQualifier;
	symbolTable[g_curIndex].width = width;
	symbolTable[g_curIndex].base = base;
	symbolTable[g_curIndex].offset = offset;
	symbolTable[g_curIndex].initialValue = initialValue;
	
	return g_curIndex;

}
void codeGen(Node *root)
{
	Node *p;
	int globalSize;
	initSymbolTable();
	for(p = root->son;p;p = p->brother){
		if(p->token.tokenNumber == DCL) processDeclaration(p->son);
		else if (p->token.tokenNumber == FUNC_DEF) processFuncHeader(p->son);
		else icg_error(3);
	}
	globalSize = g_offset-1;
	//genSym(base); //?
	for(p = root->son;p;p = p->brother)
	{
		if(p->token.tokenNumber == FUNC_DEF) processFunction(p);
	}
	emit1("bgn" , globalSize);
	emit0("ldp");
	emitJump("call" , "main");
	emit0("end");

}	

int main(void)
{
	sym_base = 1;
	label_num =1;
	FILE* astFile;
	astFile = fopen("minic.ast","w");
	ucodeFile = fopen("minic.uco" , "w");
	if(!astFile)
	{
		fprintf(stderr ,"ast err!!!!\n");
		return -1;
	}
	if(!ucodeFile)
	{
		fprintf(stderr ,"uco err!!!!\n");
		return -1;
	}
	printf("parser started \n");
	yyparse();
	//if(root->son->brother == NULL)
		//printf("yes");
	//printf("%s\n" ,root->son->son->brother->token.tokenValue );
	printTree(astFile,root,0);
	codeGen(root);
	printf("parser ended \n");
	fclose(astFile);
	fclose(ucodeFile);
	return 1;
}
//Node * parser()
//{
	//extern int parsingTable



//}
