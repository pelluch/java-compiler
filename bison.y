%{


#include <stdio.h>
#include "Error.cpp"
#include "Node.cpp"
#include "numNode.cpp"
#include "ScopeNode.cpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <vector> 
#include "SymbolTable.cpp"
#include <algorithm>
#include <fstream>
#include <stack>

#define relationLabel "REL"

using namespace std;
string insertTabs(ScopeNode * scopeNode);
Symbol * findSymbolDFS(Node *node, ScopeNode *scopeNode, char* type);
string getExpressionType(Node *node, ScopeNode *scopeNode);
ScopeNode * getScopeByNum(int numScope, ScopeNode* actual);
ScopeNode *getSymbolScope(Node *node);
void analyzeCastExpr(Node *node, ScopeNode *scopeNode);
void addInheritance();
void writeConstructorCil(Node *node);
void writeClassCil(Node *node);
void writeFieldCil(Node *node);
void markErrorsDFS(Node *node);
void addDefaultConstructors();
void writeMethodCil(Node *node);
bool isArrayType(Node *node);
void writeParamCil(Node *node);
vector<string> splitStr(string toSplit, string splitStr);
vector<string> splitStr(string toSplit);
string concatStr(vector<string> toConcat);

void AddParameterTypes(Node * node);
ClassSymbol * getExpressionClass(Node *node, ScopeNode *scopeNode, int depth);
Symbol * findSymbolDFS(char * token, int scopeNum, char * type);

ClassSymbol * getExpressionClass(Node *node, ScopeNode *scopeNode, int depth);
Symbol * findSymbolDFS(char * token, int scopeNum, char * type);

void loadCilVariableFields(Node *node, ScopeNode *scopeNode, ClassSymbol * classSymbol, bool store);
ClassSymbol* analyzeFieldAcess(Node * node, ScopeNode * scopeNode, bool);
int lastScope;
int nowScope;
char * getVariableType(Symbol *symbol, char * type, bool strict);
void analyzeRelationalExpr(Node * node, ScopeNode* scopeNode);
bool storing = false;
bool analyzeLiteral(Node * node, ScopeNode *scopeNode);
void markVisitedDFS(Node *node);
void checkBFS();
void cutTree(Node * root, Node * last);
void analyzeTree(Node *actual);
ClassSymbol* analyzeQualifiedName(Node*, ScopeNode*, bool);
void createSymbolTable();
int yylex(void);
void analyzeBFS(Node *node, ScopeNode *scopeNode, int depth);
void yyerror(const char* error);
void print(Node * node, string pre, int depth);
void 
createScopeTree(Node* node, ScopeNode * scopeNode, int depth);
void printScope(ScopeNode * scopeNode);
void printChild(ScopeNode * scopeNode);
void printSymbols(ScopeNode *scopeNode);
void analyzeAttrSymbol(Node * attr, ScopeNode *scope);
void  analyzeParameterSymbol(Node * param, ScopeNode *scopeNode);
void analyzeLocalVarDeclarationSymbol(Node * varDeclarators, ScopeNode *scopeNode);
int mierror = -1;
string analyzeFormalParameters(Node *node, ScopeNode *scopeNode);
bool existsSymbolDFS(Node *node, ScopeNode *scopeNode, bool checkType);
bool localVarDeclared(Node *node, ScopeNode *scopeNode);
int numErrors = 0;
int numWarnings = 0;
bool codigo_sin_errores = true;
bool debug = true; //Lo cambiamos nosotros de manera manual para imprimir mensajes extras
Node* root;
ScopeNode* scopeInic;
ScopeNode* scopeTemp;
int numScope = 0;
void analizeClassSymbol(Node *classNode, ScopeNode *scope);
char * getType(Node * node);
char * getPrimitiveType(Node* node);
int countVariablesDeclared(Node* node);
char * getName(Node* node) ;
char* getAssignmentExpr(Node * assExpr);
Node* getVariableDeclaratorId(Node* node);
char* getArrayAccess (Node * aAcc);
char* getFieldAccess (Node* fAcc);
char* getPrimaryNoNewArray(Node* node);
char * getPrimary(Node* primary);
char* getExpr(Node* expr);
char* getArrayCreationExpr(Node * arrayCrEx);
char* getLeftHandSide(Node* left);
char* getVariableInitializer(Node* node);
void printSymbolsDetail (ScopeNode *scopeNode);
void printSymbolTree (ScopeNode *scopeNode);
void prints(char * descripcion, char * valor);
void printi(char* descripcion, int valor);
void checkCorrectFormat(char* type, char* valueType, int line, char* id);
char* defaultValue (char* type);
void AddInitMethod (char* returnType, char* id);
Visibility getModifier(Node * modifiers);
int line_number = 1;
Node * root2;
ClassSymbol *currentClass;
Method *currentMethod;
class SymbolTable* symbolTable;
ScopeNode* incrementScope (ScopeNode* scopeNode);
bool aumentadoScopeMethod = false;
bool aumentoEnDeclaration = false; //Para evitar aumentar cuando aparece una llave.
vector<class Error*> errors;
bool mainFound = false;
bool expectingReturn = false;
ofstream cil; //Archivo donde se guarda el codigo intermedio
char* getVis(int num);
bool mainInstructionsAdded = false;
int parametersToAnalyze = 0;
stringstream methodCil;
stringstream currentExpression;
stringstream postPend;
stringstream localVars;
int currentClassScope = 0;
void analyzeExpr(Node *node, ScopeNode *scopeNode);
stack<string> postStrings;
void loadCilVariable(Node * varName, ScopeNode *scopeNode, bool store);
Symbol* findSymbolDFS(Node *node, ScopeNode *scopeNode);
bool relationalExprToCil(Node * node, ScopeNode* scopeNode);
void ifThenToCil(Node *node, ScopeNode *scopeNode);
void whileToCil(Node *node, ScopeNode *scopeNode);
void forToCil(Node *node, ScopeNode *scopeNode);
void ifThenElseToCil(Node *node, ScopeNode *scopeNode);
void loadCilValue(Node *node, ScopeNode *scopeNode);
void switchToCil(Node *node, ScopeNode *scopeNode);
void caseToCil(Node *node, Node *swNode, ScopeNode *scopeNode);
void continueToCil(Node* node, ScopeNode * scopeNode);
void breakToCil(Node* breakNode, ScopeNode * scopeNode);

//CONTADORES PARA CONTROL DE FLUJO////
int ifCount = -1;
int elseCount = 0; //comienza en 0 porque se usa en el if antes de q aumente en el else
int whileCount = -1;
int forCount = -1;
int doCount = -1;
int caseCount = -1;
int switchCount = -1;
bool bloque = false; //indica si se esta dentro de un bloque
bool semanticErrors = false;
bool writeExplicitRet = false;
/////////////////////////////////////
numNode* ifNode;
numNode* elseNode;
numNode* whileNode;
numNode* forNode;
numNode* doNode;
numNode* switchNode;
numNode* caseNode;
numNode* ordenFlujo;
int relationCounter = 0;
stringstream relationString;
////////////////////////////


%}

%error-verbose


%start Start

%token END 0 "end of file"

%union {	
	char* str;
	class Node* node;
}



%token <str> Identifier <str> StringLiteral <str> FloatingPointLiteral <str> CharLiteral <str> IntegerLiteral <str> DoubleQuote <str> Underscore <str> Letter <str> SingleQuote <str> Error <str> TrueOrFalse <str> Boolean <str> Float <str> Int <str> Char <str> Corchete <str> punto <str> Class <str> Extends <str> OpenLlave <str> CloseLlave <str> Coma <str> PuntoComa <str> variableDeclarator <str> Void <str> OpenParentesis <str> This <str> If <str> Else <str> Switch <str> Case <str> Default <str> DosPtos <str> While <str> Do <str> For <str> Break <str> Continue <str> Return <str> New <str> AddOp <str> Not <str> MultOp <str> And <str> Or <str> Tongo <str> OpenCorchete <str> CloseCorchete <str> super <str> modifier <str> CloseParentesis <str> Equals <str> Relacion <str> Igualdad <str> OrOr <str> AndAnd <str> PlusPlus <str> MinusMinus

%type <str> error
%type <node> Start
%type <node> CompilationUnit
%type <node> Literal
%type <node> Type
%type <node> PrimitiveType
%type <node> NumericType
%type <node> IntegralType
%type <node> ReferenceType
%type <node> ClassType
%type <node> ArrayType
%type <node> Name
%type <node> QualifiedName
%type <node> TypeDeclarations
%type <node> TypeDeclaration
%type <node> Modifiers
%type <node> Modifier
%type <node> ClassDeclaration
%type <node> Super
%type <node> ClassBody
%type <node> ClassBodyDeclarations
%type <node> ClassBodyDeclaration
%type <node> ClassMemberDeclaration
%type <node> FieldDeclaration
%type <node> VariableDeclarators
%type <node> VariableDeclarator
%type <node> VariableDeclaratorId
%type <node> VariableInitializer
%type <node> MethodDeclaration
%type <node> MethodHeader
%type <node> MethodDeclarator
%type <node> FormalParameterList
%type <node> FormalParameter
%type <node> MethodBody
%type <node> ConstructorDeclaration
%type <node> ConstructorDeclarator
%type <node> ConstructorBody
%type <node> ExplicitConstructorInvocation
%type <node> Block
%type <node> BlockStmts
%type <node> BlockStmt
%type <node> LocalVariableDeclarationStmt
%type <node> LocalVariableDeclaration
%type <node> Stmt
%type <node> StmtNoShortIf
%type <node> StmtNoTrailingSubstatement
%type <node> EmptyStmt
%type <node> ExprStmt
%type <node> StmtExpr
%type <node> IfThenStmt
%type <node> IfThenElseStmt
%type <node> IfThenElseStmtNoShortIf
%type <node> SwitchStmt
%type <node> SwitchBlock
%type <node> SwitchBlockStmtGroups
%type <node> SwitchBlockStmtGroup
%type <node> SwitchLabels
%type <node> SwitchLabel
%type <node> WhileStmt
%type <node> WhileStmtNoShortIf
%type <node> DoStmt
%type <node> ForStmt
%type <node> ForStmtNoShortIf
%type <node> ForInit
%type <node> ForUpdate
%type <node> StmtExprList
%type <node> BreakStmt
%type <node> ContinueStmt
%type <node> ReturnStmt
%type <node> Primary
%type <node> PrimaryNoNewArray
%type <node> ClassInstanceCreationExpr
%type <node> ArgumentList
%type <node> ArrayCreationExpr
%type <node> DimExprs
%type <node> DimExpr
%type <node> Dims
%type <node> FieldAccess
%type <node> MethodInvocation
%type <node> ArrayAccess
%type <node> PostfixExpr
%type <node> PostIncrementExpr
%type <node> PostDecrementExpr
%type <node> UnaryExpr
%type <node> PreIncrementExpr
%type <node> PreDecrementExpr
%type <node> UnaryExprNotPlusMinus
%type <node> CastExpr
%type <node> MultiplicativeExpr
%type <node> AdditiveExpr
%type <node> RelationalExpr
%type <node> EqualityExpr
%type <node> AndExpr
%type <node> ExclusiveOrExpr
%type <node> InclusiveOrExpr
%type <node> ConditionalAndExpr
%type <node> ConditionalOrExpr
%type <node> ConditionalExpr
%type <node> AssignmentExpr
%type <node> Assignment
%type <node> LeftHandSide
%type <node> AssignmentOperator
%type <node> Expr
%type <node> ConstantExpr

%left AddOp
%left MultOp
%left Prec1

%%
/* REGLAS DE TRADUCCION */
Start : CompilationUnit {
	root = $1;
};
CompilationUnit : { }
| TypeDeclarations
{
	$$ = new Node ("Compilation Unit", 1);
	$$ -> AddChild($1);
};

Literal: IntegerLiteral {
		$$ = new Node ("Literal",1); 		
		$$->AddChild(new Node("IntegerLiteral", new Node($1, 0), @1.first_line));
		}
	| FloatingPointLiteral {
		$$ = new Node ("Literal",1); 
		$$->AddChild(new Node("FloatingPointLiteral", new Node($1, 0), @1.first_line)); }
	| CharLiteral {
		$$ = new Node ("Literal",1); 
		$$->AddChild(new Node("CharLiteral", new Node($1, 0), @1.first_line)); }
	| StringLiteral {
		$$ = new Node ("Literal",1); 
		$$->AddChild(new Node("StringLiteral", new Node($1, 0), @1.first_line)); }
	| TrueOrFalse {
		$$ = new Node ("Literal",1); 
		$$->AddChild(new Node("TrueOrFalse", new Node($1, 0), @1.first_line)); }
	;
Type: PrimitiveType{
		$$ = new Node ("Type",1); 
		$$ -> AddChild ($1); }
	| ReferenceType{
		$$ = new Node ("Type",1); 
		$$ -> AddChild ($1); }
	;
PrimitiveType: NumericType{
		$$ = new Node ("PrimitiveType",1); 
		$$ -> AddChild ($1); }
	| Boolean{
		$$ = new Node ("PrimitiveType",1); 
		$$->AddChild(new Node($1, 0)); }
	;
NumericType: IntegralType{
		$$ = new Node ("NumericType",1); 
		$$ -> AddChild ($1); }
	| Float{
		$$ = new Node ("NumericType",1); 
		$$->AddChild(new Node($1, 0)); }
	;
IntegralType: Int{
		$$ = new Node ("IntegralType",1); 
		$$ -> AddChild (new Node($1, 0)); }
	| Char{
		$$ = new Node ("IntegralType", 1); 
		$$ -> AddChild (new Node($1, 0)); }
	| error PuntoComa { 
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: IntegralType (char, int) expected \n",mierror);
		yyerrok ;}
	;
ReferenceType: ClassType{
		$$ = new Node ("ReferenceType",1); 
		$$ -> AddChild ($1); }
	| ArrayType{
		$$ = new Node ("ReferenceType",1); 
		$$ -> AddChild ($1); }
	;
ClassType: Name{
		$$ = new Node ("ClassType",1); 
		$$ -> AddChild ($1); }
	;
ArrayType: PrimitiveType OpenCorchete CloseCorchete {
		$$ = new Node ("ArrayType",3); 
		$$ -> AddChild ($1); 
		$$ -> AddChild(new Node($2, 0));
		$$ -> AddChild(new Node($3, 0));}
	| Name OpenCorchete CloseCorchete{
		$$ = new Node ("ArrayType",3); 
		$$ -> AddChild ($1); 
		$$ -> AddChild(new Node($2, 0));
		$$ -> AddChild(new Node($3, 0));}
	/*errores*/
	| error OpenCorchete CloseCorchete { 
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: PrimitiveType expected\n",mierror);
		yyerrok ;}
	| Name error CloseCorchete { 
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Opening bracket expected after Name\n",mierror);
		yyerrok ;}
	| PrimitiveType error CloseCorchete { 
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Opening bracket expected after PrimitiveType\n",mierror);
		yyerrok ;}
	| Name OpenCorchete error PuntoComa{ 
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Closing bracket expected after Name \n");
		yyerrok ;}
	| PrimitiveType OpenCorchete error PuntoComa{ 
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Closing bracket expected after PrimitiveType\n");
		yyerrok ;}
	;
Name: Identifier{
		$$ = new Node ("Name",1); 
		$$->AddChild(new Node("Identifier", new Node($1, 0), @1.first_line)); }
	| QualifiedName{
		$$ = new Node ("Name",1); 
		$$ -> AddChild ($1, @1.first_line); }
	;
QualifiedName: Name punto Identifier {
		$$ = new Node ("QualifiedName",3);
		$$ -> AddChild($1); 
		$$ -> AddChild(new Node(".", 0));		
		$$->AddChild(new Node("Identifier", new Node($3, 0), @3.first_line)); }
		| Name punto error PuntoComa
		{
			mierror = @3.first_line;
			printf("Line %d: invalid name for method call\n", mierror);
		}
	;
TypeDeclarations: TypeDeclaration{
		$$ = new Node ("TypeDeclarations",1); 
		$$ -> AddChild ($1); }
	| TypeDeclarations TypeDeclaration{
		$$ = new Node ("TypeDeclarations",2); 
		$$ -> AddChild ($1); 
		$$ -> AddChild($2); }
	;
TypeDeclaration: ClassDeclaration{
		$$ = new Node ("TypeDeclaration",1); 
		$$ -> AddChild ($1);}
	| PuntoComa {
		$$ = new Node ("TypeDeclaration",1); 
		$$ -> AddChild (new Node(";", 0)); }
	;
Modifiers: Modifier {
		$$ = new Node ("Modifiers",1); 
		$$ -> AddChild ($1); }
	| Modifiers Modifier{
		$$ = new Node ("Modifiers",2); 
		$$ -> AddChild ($1);
		$$ -> AddChild($2); }
	/*tira segfault*/
	/*| error { 
		codigo_sin_errores = false;
		if(debug) printf("Error en modifiers\n");
		yyerrok ;}*/
	;
Modifier: modifier {
		$$ = new Node ("Modifier",1); 
		$$ -> AddChild(new Node($1, 0)); }
	/*tira segfault*/
	/*| error { 
		codigo_sin_errores = false;
		if(debug) printf("Error en modifier\n");
		yyerrok ;}*/
	;
ClassDeclaration: Modifiers Class Identifier Super ClassBody{
		$$ = new Node ("ClassDeclaration",5); 
		$$ -> AddChild ($1); 
		$$ -> AddChild (new Node("class", 0));
		$$->AddChild(new Node("Identifier", new Node($3, 0), @3.first_line));
		$$ -> AddChild ($4);
		$$ -> AddChild ($5);

			}
	| Modifiers Class Identifier ClassBody{
		$$ = new Node ("ClassDeclaration",4); 
		$$ -> AddChild ($1);		
		$$ -> AddChild (new Node($2, 0));
		$$->AddChild(new Node("Identifier", new Node($3, 0), @3.first_line));
		$$ -> AddChild ($4);
		}
	/*errores*/
	
	| Modifiers error Identifier ClassBody { 
	
		codigo_sin_errores = false;		
		mierror = @2.first_line;							
		printf("Line %d: class keyword Expected\n", mierror);
		yyerrok ;}
	| Modifiers Class error ClassBody { 
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Class name expected\n", mierror);	
		yyerrok ;}
	| error Class Identifier ClassBody{
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: Modifier (public, private...) expected\n", mierror);		
		yyerrok ;}
	| Modifiers error Identifier Super ClassBody { 
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: class keyword expected\n", mierror);
		yyerrok ;}
	| Modifiers Class error Super ClassBody { 
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: Class name expected\n", mierror);
		yyerrok ;}
	| error Class Identifier Super ClassBody{
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: Modifier (public, private...) expected\n", mierror);	
		yyerrok ;}
	| Modifiers Class Identifier error ClassBody{
		codigo_sin_errores = false;
		mierror = @3.first_line;
		if(debug) printf("Line %d: en extends Superclass.Classname\n", mierror);
		yyerrok ;}
	| Modifiers Identifier Identifier ClassBody {
		codigo_sin_errores = false;
		mierror = @2.first_line;
		yyerror("sintax error, unexpected Identifier, expected Class");
		printf("Line %d: unexpected Identifier, expected 'class'\n", mierror);
		yyerrok;
	}
	
	;
Super: Extends ClassType{
		$$ = new Node ("Super",2); 
		$$->line = @1.first_line;
		$$ -> AddChild (new Node($1, 0));
		$$ -> AddChild ($2); }
	;
ClassBody: OpenLlave ClassBodyDeclarations CloseLlave{
		$$ = new Node ("ClassBody",3);
		$$ -> AddChild(new Node("{", 0)); 
		$$ -> AddChild ($2); 
		$$ -> AddChild(new Node("}", 0));}
		
	| OpenLlave ClassBodyDeclarations error END {
		codigo_sin_errores = false;
		if(debug) printf("Ending bracket '}' missing\n");
		yyerrok ;}
	
	| ClassBodyDeclarations CloseLlave {
		mierror = @1.first_line;
		codigo_sin_errores = false;
		$$ = new Node ("ClassBody",2);
		$$ -> AddChild ($1); 
		$$ -> AddChild (new Node($2, 0)); 
		yyerror("syntax error: unexpected ClassBodyDeclarations, expected OpenLlave");
		printf("Line %d: Missing opening bracket {\n", mierror);
		yyerrok ;
	}
		
	;
ClassBodyDeclarations: ClassBodyDeclaration {
		$$ = new Node ("ClassBodyDeclarations",1); 
		$$ -> AddChild ($1); }
	| ClassBodyDeclarations ClassBodyDeclaration {
		$$ = new Node ("ClassBodyDeclarations",2); 
		$$ -> AddChild ($1); 
		$$ -> AddChild ($2);}
	;
ClassBodyDeclaration: ClassMemberDeclaration {
		$$ = new Node ("ClassBodyDeclaration",1); 
		$$ -> AddChild ($1); }
	| ConstructorDeclaration{
		$$ = new Node ("ClassBodyDeclaration",1); 
		$$ -> AddChild ($1); }
	;
ClassMemberDeclaration: FieldDeclaration {
		$$ = new Node ("ClassMemberDeclaration",1); 
		$$ -> AddChild ($1, @1.first_line); }
	| MethodDeclaration {
		$$ = new Node ("ClassMemberDeclaration",1); 
		$$ -> AddChild ($1, @1.first_line); }
	;
FieldDeclaration: Modifiers Type VariableDeclarators PuntoComa {
		$$ = new Node ("FieldDeclaration",4); 
		$$ -> AddChild ($1); 
		$$ -> AddChild ($2);
		$$ -> AddChild ($3);
		$$ -> AddChild (new Node(";", 0));}
	| Type VariableDeclarators PuntoComa {
		$$ = new Node ("FieldDeclaration",3); 
		$$ -> AddChild ($1); 
		$$ -> AddChild ($2); 
		$$ -> AddChild (new Node(";", 0));}
	| Modifiers Type PuntoComa{
		codigo_sin_errores = false;
		mierror = @3.first_line;
		yyerror("syntax error, unexpected PuntoComa, expected VariableDeclarators");
		printf("Line %d: VariableDeclarators expected.\n", mierror);
		yyerrok;
	}
;
VariableDeclarators: VariableDeclarator{
		$$ = new Node ("VariableDeclarators",1); 
		$$ -> AddChild ($1, @1.first_line); }
	| VariableDeclarators Coma VariableDeclarator{
		$$ = new Node ("VariableDeclarators",3); 
		$$ -> AddChild ($1, @1.first_line); 
		$$ -> AddChild (new Node($2, 0), @2.first_line);
		$$ -> AddChild ($3, @3.first_line); }
	/*tira shiftreduce| error PuntoComa  {
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: VariableDeclarator expected.\n", mierror);
		yyerrok; }
	;*/
VariableDeclarator: VariableDeclaratorId{
		$$ = new Node ("VariableDeclarator",1); 
		$$ -> AddChild ($1); }
	| VariableDeclaratorId Equals VariableInitializer{
		$$ = new Node ("VariableDeclarator",3); 
		$$ -> AddChild ($1); 
		$$ -> AddChild (new Node($2, 0));
		$$ -> AddChild ($3); }
	| VariableDeclaratorId error VariableInitializer {
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: '=' token likely missing.\n", mierror);
		yyerrok;
	}
	/*tira 3 errores shift/reduce
	| error PuntoComa {
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: VariableDeclarator expected.\n", mierror);
		yyerrok;
	}*/
	
	;
VariableDeclaratorId: Identifier{
		$$ = new Node ("VariableDeclaratorId",1); 
		$$->AddChild(new Node("Identifier", new Node($1, 0), @1.first_line)); 
		//printf("Encontrada variable %s en linea %d\n", $1, @1.first_line);
		}
	| VariableDeclaratorId OpenCorchete CloseCorchete {
		$$ = new Node ("VariableDeclaratorId",3); 
		$$ -> AddChild ($1); 
		$$ -> AddChild (new Node("[", 0));
		$$ -> AddChild (new Node("]", 0));}
	 /*3 errores shift/reduce
	| error OpenCorchete CloseCorchete  {
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d:  VariableDeclaratorId expected.\n", mierror);
		yyerrok; }*/
	| VariableDeclaratorId CloseCorchete
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		yyerror("syntax error: unexpected CloseCorchete, expecting OpenCorchete");
		printf("Line %d: Close Bracket ']' expected.\n", mierror);
		yyerrok;
	}
	| VariableDeclaratorId OpenCorchete error PuntoComa
	{
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: Open Bracket '[' expected.\n", mierror);
		yyerrok;
	}
	;
VariableInitializer: Expr {
		$$ = new Node ("VariableInitializer",1); 
		$$ -> AddChild ($1); }
	;
MethodDeclaration: MethodHeader MethodBody{
		$$ = new Node ("MethodDeclaration",2); 
		$$ -> AddChild ($1); 
		$$ -> AddChild ($2);}
	;
MethodHeader: Modifiers Type MethodDeclarator{
		$$ = new Node ("MethodHeader",3); 
		$$ -> AddChild ($1);
		$$ -> AddChild ($2);
		$$ -> AddChild ($3); }
	| Type MethodDeclarator{
		$$ = new Node ("MethodHeader",2); 
		$$ -> AddChild ($1);
		$$ -> AddChild ($2); }
	| Modifiers Void MethodDeclarator{
		$$ = new Node ("MethodHeader",3); 
		$$ -> AddChild ($1);
		$$ -> AddChild (new Node($2, 0));
		$$ -> AddChild ($3); }
	| Void MethodDeclarator{
		$$ = new Node ("MethodHeader",2); 
		$$ -> AddChild (new Node($1, 0)); 
		$$ -> AddChild ($2);}
	;
MethodDeclarator: Identifier OpenParentesis FormalParameterList CloseParentesis{
		$$ = new Node ("MethodDeclarator",4); 
		$$->AddChild(new Node("Identifier", new Node($1, 0), @1.first_line));
		$$ -> AddChild (new Node("(", 0));
		$$ -> AddChild ($3);
		$$ -> AddChild (new Node(")", 0));}
	| Identifier OpenParentesis CloseParentesis{
		$$ = new Node ("MethodDeclarator",3); 
		$$->AddChild(new Node("Identifier", new Node($1, 0), @1.first_line));
		$$ -> AddChild (new Node("(", 0));
		$$ -> AddChild( new Node(")", 0));}
	| MethodDeclarator OpenCorchete CloseCorchete {
		$$ = new Node ("MethodDeclarator",3); 
		$$ -> AddChild ($1); 
		$$ -> AddChild (new Node("[", 0));
		$$ -> AddChild (new Node("]", 0));}	
	;
FormalParameterList: FormalParameter{
		$$ = new Node ("FormalParameterList",1); 
		$$ -> AddChild ($1); }
	| FormalParameterList Coma FormalParameter{
		$$ = new Node ("FormalParameterList",3); 
		$$ -> AddChild ($1);
		$$ -> AddChild (new Node(",", 0)); 
		$$ -> AddChild ($3);}
	| FormalParameterList error FormalParameter {
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Comma ',' expected.\n", mierror);
		yyerrok;
	}
	/* tira error shiftReduce
	| error Coma FormalParameter {
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: Error in ParameterList befor ','.\n", mierror);
		yyerrok;
}*/
	;
FormalParameter: Type VariableDeclaratorId{
		$$ = new Node ("FormalParameter",2); 
		$$ -> AddChild ($1);
		$$ -> AddChild ($2); }
	;
MethodBody: Block {
		$$ = new Node ("MethodBody",1); 
		$$ -> AddChild ($1); }
	| PuntoComa{
		$$ = new Node ("MethodBody",1); 
		$$ -> AddChild (new Node(";", 0)); }
	;
ConstructorDeclaration: Modifiers ConstructorDeclarator ConstructorBody{
		$$ = new Node ("ConstructorDeclaration",3); 
		$$ -> AddChild ($1); 
		$$ -> AddChild ($2); 
		$$ -> AddChild ($3); }
	| ConstructorDeclarator ConstructorBody{
		$$ = new Node ("ConstructorDeclaration",2); 
		$$ -> AddChild ($1);
		$$ -> AddChild ($2);  }
	/*tira error shiftreduce
	| error ConstructorDeclarator ConstructorBody {
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: Modifier expected.\n", mierror);
		yyerrok;
        }*/
	/*tira error shiftreduce
	| error ConstructorBody  {
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: ConstructorDeclarator expected.\n", mierror);
		yyerrok;
        }*/
	/*tira error shiftreduce
	| Modifier error ConstructorBody  {
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: ConstructorDeclarator expected.\n", mierror);
		yyerrok;
        }
*/
	;
ConstructorDeclarator: Identifier OpenParentesis FormalParameterList CloseParentesis{
		$$ = new Node ("ConstructorDeclarator",4); 
		$$->AddChild(new Node("Identifier", new Node($1, 0), @1.first_line));
		$$ -> AddChild (new Node("(", 0));
		$$ -> AddChild ($3); 
		$$ -> AddChild (new Node(")", 0));}
	| Identifier OpenParentesis CloseParentesis{
		$$ = new Node ("ConstructorDeclarator",3); 
		$$->AddChild(new Node("Identifier", new Node($1, 0), @1.first_line));
		$$ -> AddChild (new Node("(", 0));
		$$ -> AddChild (new Node(")", 0));}
	| error OpenParentesis FormalParameterList CloseParentesis  {
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: Identifier expected in ConstructorDeclarator.\n", mierror);
		yyerrok;
	}
/*tira shiftreduce
	| Identifier error FormalParameterList CloseParentesis  {
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: Open parenthesis ( expected in ConstructorDeclarator.\n", mierror);
		yyerrok;
        }*/
	| Identifier OpenParentesis FormalParameterList error OpenLlave {
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: Close parenthesis ')' expected.\n", mierror);
		yyerrok;
	}
	| Identifier CloseParentesis{
	codigo_sin_errores = false;
	mierror = @1.first_line;
	yyerror("syntax error, unexpected CloseParentesis, expecting OpenParentesis");
	printf("Line %d: Open parenthesis '(' expected in ConstructorDeclarator.\n", mierror);
	yyerrok;
        }
	;
ConstructorBody : 
	OpenLlave ExplicitConstructorInvocation BlockStmts CloseLlave {
		$$ = new Node ("ConstructorBody",4); 
		$$ -> AddChild (new Node("{", 0));
		$$ -> AddChild ($2); 
		$$ -> AddChild ($3); 
		$$ -> AddChild (new Node("}", 0));}
	| OpenLlave ExplicitConstructorInvocation CloseLlave {
		$$ = new Node ("ConstructorBody",3); 
		$$ -> AddChild (new Node("{", 0));
		$$ -> AddChild ($2); 
		$$ -> AddChild (new Node("}", 0));}
	| OpenLlave BlockStmts CloseLlave{
		$$ = new Node ("ConstructorBody",3); 
		$$ -> AddChild (new Node("{", 0));
		$$ -> AddChild ($2); 
		$$ -> AddChild (new Node("}", 0));}
	| OpenLlave CloseLlave{
		$$ = new Node ("ConstructorBody",2); 
		$$ -> AddChild (new Node("{", 0));
		$$ -> AddChild (new Node("}", 0)); }
	| error CloseLlave  {
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: Open bracket { expected.\n", mierror);
		yyerrok;
	}	
	| error ExplicitConstructorInvocation CloseLlave  {
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: Open bracket { expected.\n", mierror);
		yyerrok;
	}
	| error BlockStmts CloseLlave  {
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: Open bracket { expected.\n", mierror);
		yyerrok;
	}
	| error ExplicitConstructorInvocation BlockStmts CloseLlave  {
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: Open bracket { expected.\n", mierror);
		yyerrok;
	}
	| OpenLlave error END  {
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: Close bracket } expected.\n", mierror);
		yyerrok;
	}

	| OpenLlave ExplicitConstructorInvocation error END  {
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: Close bracket } expected.\n", mierror);
		yyerrok;
	}
	| OpenLlave BlockStmts error END  {
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: Close bracket } expected.\n", mierror);
		yyerrok;
	}
	| OpenLlave ExplicitConstructorInvocation BlockStmts error END  {
		codigo_sin_errores = false;
		mierror = @4.first_line;
		printf("Line %d: Close bracket } expected.\n", mierror);
		yyerrok;
	}
	;
ExplicitConstructorInvocation: This OpenParentesis ArgumentList CloseParentesis PuntoComa{
		$$ = new Node ("ExplicitConstructorInvocation",5); 
		$$ -> AddChild (new Node("this", 0));
		$$ -> AddChild (new Node("(", 0)); 
		$$ -> AddChild ($3); 
		$$ -> AddChild (new Node(")", 0));
		$$ -> AddChild (new Node(";", 0)); }
	| This OpenParentesis CloseParentesis PuntoComa{
		$$ = new Node ("ExplicitConstructorInvocation",4); 
		$$ -> AddChild (new Node("this", 0));
		$$ -> AddChild (new Node("(", 0)); 
		$$ -> AddChild (new Node(")", 0));
		$$ -> AddChild (new Node(";", 0)); }
	| super OpenParentesis ArgumentList CloseParentesis PuntoComa{
		$$ = new Node ("ExplicitConstructorInvocation",5); 
		$$ -> AddChild (new Node("super", 0));
		$$ -> AddChild (new Node("(", 0)); 
		$$ -> AddChild ($3); 
		$$ -> AddChild (new Node(")", 0));
		$$ -> AddChild (new Node(";", 0)); }
	| super OpenParentesis CloseParentesis PuntoComa {
		$$ = new Node("ExplicitConstructorInvocation",4); 
		$$ -> AddChild (new Node("super", 0));
		$$ -> AddChild (new Node("(", 0)); 
		$$ -> AddChild (new Node(")", 0));
		$$ -> AddChild (new Node(";", 0)); }
	| super error CloseParentesis PuntoComa  {
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open Parenthesis '(' expected after super.\n", mierror);
		yyerrok;
	}
	| super OpenParentesis error PuntoComa  {
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: Close Parenthesis ')' expected.\n", mierror);
		yyerrok;
	}
	| super error ArgumentList CloseParentesis PuntoComa  {
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open Parenthesis '(' expected after super.\n", mierror);
		yyerrok;
	}
	| super OpenParentesis ArgumentList error PuntoComa  {
		codigo_sin_errores = false;
		mierror = @4.first_line;
		printf("Line %d: Close Parenthesis ')' expected.\n", mierror);
		yyerrok;
	}
	| super OpenParentesis ArgumentList CloseParentesis error CloseLlave  {
		codigo_sin_errores = false;
		mierror = @5.first_line;
		printf("Line %d: Semicolon ';' expected.\n", mierror);
		yyerrok;
	}
	| super OpenParentesis CloseParentesis error CloseLlave  {
		codigo_sin_errores = false;
		mierror = @4.first_line;
		printf("Line %d: Semicolon ';' expected.\n", mierror);
		yyerrok;
	}
	| This error CloseParentesis PuntoComa  {
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open Parenthesis '(' expected after super.\n", mierror);
		yyerrok;
	}
	| This OpenParentesis error PuntoComa  {
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: Close Parenthesis ')' expected.\n", mierror);
		yyerrok;
	}
	| This error ArgumentList CloseParentesis PuntoComa  {
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open Parenthesis '(' expected after super.\n", mierror);
		yyerrok;
	}
	| This OpenParentesis ArgumentList error PuntoComa  {
		codigo_sin_errores = false;
		mierror = @4.first_line;
		printf("Line %d: Close Parenthesis ')' expected.\n", mierror);
		yyerrok;
	}
	| This OpenParentesis ArgumentList CloseParentesis error CloseLlave  {
		codigo_sin_errores = false;
		mierror = @5.first_line;
		printf("Line %d: Semicolon ';' expected.\n", mierror);
		yyerrok;
	}
	| This OpenParentesis CloseParentesis error CloseLlave  {
		codigo_sin_errores = false;
		mierror = @4.first_line;
		printf("Line %d: Semicolon ';' expected.\n", mierror);
		yyerrok;
	}
	;

//No se llaman nunca
/*ConstantDeclaration: FieldDeclaration {
		$$ = new Node ("ConstantDeclaration",1); 
		$$ -> AddChild ($1); }
	;
AbstractMethodDeclaration: MethodHeader PuntoComa {
		$$ = new Node ("AbstractMethodDeclaration",2); 
		$$ -> AddChild ($1); 
		$$ -> AddChild (new Node(";", 0));}
	;
VariableInitializers: VariableInitializer {
		$$ = new Node ("VariableInitializers",1); 
		$$ -> AddChild ($1); }
	|VariableInitializer Coma VariableInitializer{
		$$ = new Node ("VariableInitializers",1); 
		$$ -> AddChild ($1);
		$$ -> AddChild(new Node(",", 0));
		$$ -> AddChild($3); }
	;*/
Block: OpenLlave BlockStmts CloseLlave{
		$$ = new Node ("Block",3); 
		$$ -> AddChild (new Node("{", 0)); 
		$$ -> AddChild ($2); 
		$$ -> AddChild (new Node("}", 0)); }
	| OpenLlave CloseLlave {
		$$ = new Node ("Block",2); 
		$$ -> AddChild (new Node("{", 0)); 
		$$ -> AddChild (new Node("}", 0)); }
	/* shifreduce
	| error BlockStmts CloseLlave {
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: Open bracket '{' expected.\n", mierror);
		yyerrok;
	}*/
	/*mil shifreduce
	| BlockStmts CloseLlave {
		codigo_sin_errores = false;
		mierror = @1.first_line;
		yyerror("syntax error, OpenLlave expected");
		printf("Line %d: Open bracket '{' expected.\n", 	mierror);
		yyerrok;
	}*/
	| error CloseLlave {
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: Open bracket '{' expected.\n", mierror);
		yyerrok;
	}
	| OpenLlave BlockStmts error END {
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: Close bracket '}' expected.\n", mierror);
		yyerrok;
	}
	| OpenLlave error END {
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Close bracket '}' expected.\n", mierror);
		yyerrok;
	}
	;
BlockStmts: BlockStmt{
		$$ = new Node ("BlockStmts",1); 
		$$ -> AddChild ($1); }
	| BlockStmts BlockStmt{
		$$ = new Node ("BlockStmts",2); 
		$$ -> AddChild ($1); 
		$$ -> AddChild ($2); }
	;
BlockStmt: LocalVariableDeclarationStmt {
		$$ = new Node ("BlockStmt",1); 
		$$ -> AddChild ($1); }
	| Stmt {
		$$ = new Node ("BlockStmt",1); 
		$$ -> AddChild ($1); }
	/*reglas de errores producen shiftreduce aqui*/
	;
LocalVariableDeclarationStmt: LocalVariableDeclaration PuntoComa{
		$$ = new Node ("LocalVariableDeclarationStmt",2); 
		$$ -> AddChild ($1, @1.first_line);
		$$ -> AddChild(new Node(";", 0)); }
	/*shiftreduce 
	| LocalVariableDeclaration error END
	{
		codigo_sin_errores = false;
		mierror = @1.first_line;
		yyerror("syntax error, expecting PuntoComa");
		printf("Line %d: Semicolon ';' expected.\n", mierror);
		yyerrok;
	}*/
	
	;
LocalVariableDeclaration: Type VariableDeclarators {
		$$ = new Node ("LocalVariableDeclaration",2); 
		$$ -> AddChild ($1);
		$$ -> AddChild ($2);  }
	;
Stmt: StmtNoTrailingSubstatement {
		$$ = new Node ("Stmt",1); 
		$$ -> AddChild ($1); }
	| IfThenStmt {
		$$ = new Node ("Stmt",1); 
		$$ -> AddChild ($1); }
	| IfThenElseStmt {
		$$ = new Node ("Stmt",1); 
		$$ -> AddChild ($1); }
	| WhileStmt{
		$$ = new Node ("Stmt",1); 
		$$ -> AddChild ($1); }
	|ForStmt{
		$$ = new Node ("Stmt",1); 
		$$ -> AddChild ($1); }
	;
StmtNoShortIf: StmtNoTrailingSubstatement {
		$$ = new Node ("StmtNoShortIf",1); 
		$$ -> AddChild ($1); }
	| IfThenElseStmtNoShortIf{
		$$ = new Node ("StmtNoShortIf",1); 
		$$ -> AddChild ($1); }
	| WhileStmtNoShortIf{
		$$ = new Node ("StmtNoShortIf",1); 
		$$ -> AddChild ($1); }
	|ForStmtNoShortIf{
		$$ = new Node ("StmtNoShortIf",1); 
		$$ -> AddChild ($1); }
	;
StmtNoTrailingSubstatement: 
	Block {
		$$ = new Node ("StmtNoTrailingSubstatement",1); 
		$$ -> AddChild ($1); }
	| EmptyStmt {
		$$ = new Node ("StmtNoTrailingSubstatement",1); 
		$$ -> AddChild ($1); }
	| ExprStmt {
		$$ = new Node ("StmtNoTrailingSubstatement",1); 
		$$ -> AddChild ($1); }
	| SwitchStmt{
		$$ = new Node ("StmtNoTrailingSubstatement",1); 
		$$ -> AddChild ($1, @1.first_line); }
	| DoStmt{
		$$ = new Node ("StmtNoTrailingSubstatement",1); 
		$$ -> AddChild ($1); }
	| BreakStmt {
		$$ = new Node ("StmtNoTrailingSubstatement",1); 
		$$ -> AddChild ($1); }
	| ContinueStmt {
		$$ = new Node ("StmtNoTrailingSubstatement",1); 
		$$ -> AddChild ($1); }
	| ReturnStmt {
		$$ = new Node ("StmtNoTrailingSubstatement",1); 
		$$ -> AddChild ($1); }
	;
EmptyStmt: PuntoComa{
		$$ = new Node ("EmptyStmt",1); 
		$$ -> AddChild (new Node(";",0)); }
	;
ExprStmt: StmtExpr PuntoComa {
		$$ = new Node ("ExprStmt",2); 
		$$ -> AddChild($1);
		$$ -> AddChild (new Node(";", 0)); }
	| StmtExpr error {
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: expected ;\n", mierror);
		yyerrok;
	}
	;
StmtExpr: Assignment {
		$$ = new Node ("StmtExpr",1); 
		$$ -> AddChild ($1, @1.first_line); }
	| PreIncrementExpr {
		$$ = new Node ("StmtExpr",1); 
		$$ -> AddChild ($1, @1.first_line); }
	| PreDecrementExpr {
		$$ = new Node ("StmtExpr",1); 
		$$ -> AddChild ($1, @1.first_line); }
	| PostIncrementExpr {
		$$ = new Node ("StmtExpr",1); 
		$$ -> AddChild ($1, @1.first_line); }
	| PostDecrementExpr {
		$$ = new Node ("StmtExpr",1); 
		$$ -> AddChild ($1, @1.first_line); }
	| MethodInvocation {
		$$ = new Node ("StmtExpr",1); 
		$$ -> AddChild ($1, @1.first_line); }
	| ClassInstanceCreationExpr {
		$$ = new Node ("StmtExpr",1); 
		$$ -> AddChild ($1, @1.first_line); }
	;
IfThenStmt: If OpenParentesis Expr CloseParentesis Stmt {
		$$ = new Node ("IfThenStmt",5); 
		$$ -> AddChild (new Node("if",0)); 
		$$ -> AddChild (new Node("(",0)); 
		$$ -> AddChild ($3); 
		$$ -> AddChild (new Node(")",0)); 
		$$ -> AddChild ($5); }
	| If error Expr CloseParentesis Stmt
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open parenthesis '(' expected.\n", mierror);
		yyerrok;
	}
	| If OpenParentesis Expr error Stmt
	{
		codigo_sin_errores = false;
		mierror = @4.first_line;
		printf("Line %d: Close parenthesis ')' expected.\n", mierror);
		yyerrok;
	}
	| If OpenParentesis error CloseParentesis Stmt
	{
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: Error in if expression expected.\n", mierror);
		yyerrok;
	}
	| If error CloseParentesis Stmt
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open parenthesis '(' and expression expected.\n", mierror);
		yyerrok;
	}
	/*reducereduce
	| If error Stmt
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open parenthesis '(', expression and close parenthesis ')' expected.\n", mierror);
		yyerrok;
	}*/
	/*shifreduce	
	| If OpenParentesis Expr CloseParentesis error
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: If's parenthesis and expression expected.\n", mierror);
		yyerrok;
	}*/
	;
IfThenElseStmt: If OpenParentesis Expr CloseParentesis StmtNoShortIf Else Stmt {
		$$ = new Node ("IfThenElseStmt",7); 
		$$ -> AddChild (new Node("if",0)); 
		$$ -> AddChild (new Node("(",0)); 
		$$ -> AddChild ($3); 
		$$ -> AddChild (new Node(")",0)); 
		$$ -> AddChild ($5); 
		$$ -> AddChild (new Node("else",0)); 
		$$ -> AddChild ($7); }
	| If error Expr CloseParentesis StmtNoShortIf Else Stmt
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open parenthesis '(' expected.\n", mierror);
		yyerrok;
	}
	| If OpenParentesis Expr error StmtNoShortIf Else Stmt
	{
		codigo_sin_errores = false;
		mierror = @4.first_line;
		printf("Line %d: Close parenthesis ')' expected.\n", mierror);
		yyerrok;
	}
	| If OpenParentesis error CloseParentesis StmtNoShortIf Else Stmt
	{
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: Error in if expression expected.\n", mierror);
		yyerrok;
	}
	/*para cuando falta '(' y/o la expresion*/
	| If error CloseParentesis StmtNoShortIf Else Stmt
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open parenthesis '(' and expression expected.\n", mierror);
		yyerrok;
	}
	| If error Else Stmt
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open parenthesis '(', expression and Close parenthesis ')' expected.\n", mierror);
		yyerrok;
	}
	
	/*shifreduce
	| If OpenParentesis Expr CloseParentesis StmtNoShortIf error Stmt
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: 'else' expected.\n", mierror);
		yyerrok;
	}*/
	;
IfThenElseStmtNoShortIf: If OpenParentesis Expr CloseParentesis StmtNoShortIf Else StmtNoShortIf{
		$$ = new Node ("IfThenElseStmtNoShortIf",7); 
		$$ -> AddChild (new Node("if",0)); 
		$$ -> AddChild (new Node("(",0)); 
		$$ -> AddChild ($3); 
		$$ -> AddChild (new Node(")",0)); 
		$$ -> AddChild ($5); 
		$$ -> AddChild (new Node("else",0)); 
		$$ -> AddChild ($7); }
	| If error Expr CloseParentesis StmtNoShortIf Else StmtNoShortIf
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open parenthesis '(' expected.\n", mierror);
		yyerrok;
	}
	| If OpenParentesis Expr error StmtNoShortIf Else StmtNoShortIf
	{
		codigo_sin_errores = false;
		mierror = @4.first_line;
		printf("Line %d: Close parenthesis ')' expected.\n", mierror);
		yyerrok;
	}
	| If OpenParentesis error CloseParentesis StmtNoShortIf Else StmtNoShortIf
	{
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: Error in if expression expected.\n", mierror);
		yyerrok;
	}
	| If error CloseParentesis StmtNoShortIf Else StmtNoShortIf
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open parenthesis '(' and expression expected.\n", mierror);
		yyerrok;
	}
	/*shiftreduce
	| If error StmtNoShortIf Else StmtNoShortIf
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open parenthesis '(' and expression expected.\n", mierror);
		yyerrok;
	}*/
	;
SwitchStmt: Switch OpenParentesis Expr CloseParentesis SwitchBlock{
		$$ = new Node ("SwitchStmt",5); 
		$$ -> AddChild (new Node("switch",0), @1.first_line); 
		$$ -> AddChild (new Node("(",0)); 
		$$ -> AddChild ($3); 
		$$ -> AddChild (new Node(")",0)); 
		$$ -> AddChild ($5);  }
	| Switch error Expr CloseParentesis SwitchBlock
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open parenthesis '(' expected.\n", mierror);
		yyerrok;
	}
	| Switch OpenParentesis Expr error SwitchBlock
	{
		codigo_sin_errores = false;
		mierror = @4.first_line;
		printf("Line %d: Close parenthesis ')' expected.\n", mierror);
		yyerrok;
	}
	| Switch OpenParentesis error CloseParentesis SwitchBlock
	{
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: Error in if expression expected.\n", mierror);
		yyerrok;
	}
	| Switch error CloseParentesis SwitchBlock
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open parenthesis '(' and expression expected.\n", mierror);
		yyerrok;
	}
	| Switch error SwitchBlock
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open parenthesis '(', expression and Close parenthesis ')' expected.\n", mierror);
		yyerrok;
	}
	;
SwitchBlock: OpenLlave SwitchBlockStmtGroups SwitchLabels CloseLlave{
		$$ = new Node ("SwitchBlock",4); 
		$$ -> AddChild (new Node("{",0)); 
		$$ -> AddChild ($2, @2.first_line); 
		$$ -> AddChild ($3, @3.first_line);
		$$ -> AddChild (new Node("}",0));}
	| OpenLlave SwitchBlockStmtGroups CloseLlave{
		$$ = new Node ("SwitchBlock",3); 
		$$ -> AddChild (new Node("{",0)); 
		$$ -> AddChild ($2, @2.first_line); 
		$$ -> AddChild (new Node("}",0)); }
	| OpenLlave SwitchLabels CloseLlave{
		$$ = new Node ("SwitchBlock",3); 
		$$ -> AddChild (new Node("{",0)); 
		$$ -> AddChild ($2, @2.first_line); 
		$$ -> AddChild (new Node("}",0));}
	| OpenLlave CloseLlave{
		$$ = new Node ("SwitchBlock",2); 
		$$ -> AddChild (new Node("{",0)); 
		$$ -> AddChild (new Node("}",0)); }
	| error SwitchBlockStmtGroups SwitchLabels CloseLlave{
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: Open bracket '{'.\n", mierror);
		yyerrok;
	}
	| error SwitchBlockStmtGroups CloseLlave{
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: Open bracket '{'.\n", mierror);
		yyerrok;
	}
	| error SwitchLabels CloseLlave{
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: Open bracket '{'.\n", mierror);
		yyerrok;
	}
	| error CloseLlave{
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: Open bracket '{'.\n", mierror);
		yyerrok;
	}
	| OpenLlave SwitchBlockStmtGroups SwitchLabels error END{
		codigo_sin_errores = false;
		mierror = @4.first_line;
		printf("Line %d: Close bracket '}'.\n", mierror);
		yyerrok;
	}
	/*shift reduce
	| OpenLlave SwitchBlockStmtGroups error END{
		codigo_sin_errores = false;
		mierror = @1.first_line;
		printf("Line %d: Open bracket '{'.\n", mierror);
		yyerrok;
	}*/
	| OpenLlave SwitchLabels error END{
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: Close bracket '}'.\n", mierror);
		yyerrok;
	}
	| OpenLlave error END {
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Close bracket '}'.\n", mierror);
		yyerrok;
	}
	| OpenLlave error CloseLlave {
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Errors in Statements or Labels\n", mierror);
		yyerrok;
	}
	;
SwitchBlockStmtGroups: SwitchBlockStmtGroup{
		$$ = new Node ("SwitchBlockStmtGroups",1); 
		$$ -> AddChild ($1, @1.first_line); }
	| SwitchBlockStmtGroups SwitchBlockStmtGroup{
		$$ = new Node ("SwitchBlockStmtGroups",2); 
		$$ -> AddChild ($1, @1.first_line); 
		$$ -> AddChild ($2, @2.first_line);}
	;
SwitchBlockStmtGroup: SwitchLabels BlockStmts{
		$$ = new Node ("SwitchBlockStmtGroup",2); 
		$$ -> AddChild ($1, @1.first_line); 
		$$ -> AddChild ($2, @2.first_line);}
	;
SwitchLabels: SwitchLabel {
		$$ = new Node ("SwitchLabels",1); 
		$$ -> AddChild ($1, @1.first_line); }
	| SwitchLabels SwitchLabel{
		$$ = new Node ("SwitchLabels",2); 
		$$ -> AddChild ($1, @1.first_line); 
		$$ -> AddChild ($2, @2.first_line);}
	;
SwitchLabel: Case ConstantExpr DosPtos {
		$$ = new Node ("SwitchLabel",3); 
		$$ -> AddChild (new Node("case",0), @1.first_line); 		
		$$ -> AddChild ($2); 
		$$ -> AddChild (new Node(":",0)); }
	| Default DosPtos{
		$$ = new Node ("SwitchLabel",2); 
		$$ -> AddChild (new Node("default",0), @1.first_line); 		
		$$ -> AddChild (new Node(":",0)); }
	| Default error PuntoComa {
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Colon ':' expected \n", mierror);
		yyerrok;
	}
	| Case error DosPtos{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Errors in ConstantExpresion\n", mierror);
		yyerrok;
	}
	| Case ConstantExpr error PuntoComa{
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: Colon ':' expected\n", mierror);
		yyerrok;
	}
	;
WhileStmt: While OpenParentesis Expr CloseParentesis Stmt {
		$$ = new Node ("WhileStmt",5); 
		$$ -> AddChild (new Node("while",0)); 	
		$$ -> AddChild (new Node("(",0)); 		
		$$ -> AddChild ($3); 
		$$ -> AddChild (new Node(")",0));
		$$ -> AddChild ($5); }
| While error Expr CloseParentesis Stmt
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open parenthesis '(' expected.\n", mierror);
		yyerrok;
	}
	| While OpenParentesis Expr error Stmt
	{
		codigo_sin_errores = false;
		mierror = @4.first_line;
		printf("Line %d: Close parenthesis ')' expected.\n", mierror);
		yyerrok;
	}
	| While OpenParentesis error CloseParentesis Stmt
	{
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: Error in while, expression expected.\n", mierror);
		yyerrok;
	}
	| While error CloseParentesis Stmt
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open parenthesis '(' and expression expected.\n", mierror);
		yyerrok;
	}
	;
WhileStmtNoShortIf: While OpenParentesis Expr CloseParentesis StmtNoShortIf{
		$$ = new Node ("WhileStmtNoShortIf",5); 
		$$ -> AddChild (new Node("while",0)); 	
		$$ -> AddChild (new Node("(",0)); 		
		$$ -> AddChild ($3); 
		$$ -> AddChild (new Node(")",0));
		$$ -> AddChild ($5); }
	| While error Expr CloseParentesis StmtNoShortIf
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open parenthesis '(' expected.\n", mierror);
		yyerrok;
	}
	| While OpenParentesis Expr error StmtNoShortIf
	{
		codigo_sin_errores = false;
		mierror = @4.first_line;
		printf("Line %d: Close parenthesis ')' expected.\n", mierror);
		yyerrok;
	}
	| While OpenParentesis error CloseParentesis StmtNoShortIf
	{
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: Error in while, expression expected.\n", mierror);
		yyerrok;
	}
	| While error CloseParentesis StmtNoShortIf
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open parenthesis '(' and expression expected.\n", mierror);
		yyerrok;
	}
	/*shiftreduce
	| While error StmtNoShortIf
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Open parenthesis '(' and expression expected.\n", mierror);
		yyerrok;
	}*/
	;
DoStmt: Do Stmt While OpenParentesis Expr CloseParentesis PuntoComa{
		$$ = new Node ("DoStmt",7); 
		$$ -> AddChild (new Node("do",0)); 			
		$$ -> AddChild ($2); 
		$$ -> AddChild (new Node("while",0)); 
		$$ -> AddChild (new Node("(",0)); 
		$$ -> AddChild ($5); 
		$$ -> AddChild (new Node(")",0));
		$$ -> AddChild (new Node(";",0));}
	| Do Stmt While error Expr CloseParentesis PuntoComa
	{
		codigo_sin_errores = false;
		mierror = @4.first_line;
		printf("Line %d: Open parenthesis '(' expected.\n", mierror);
		yyerrok;
	}
	| Do Stmt While OpenParentesis Expr error PuntoComa
	{
		codigo_sin_errores = false;
		mierror = @6.first_line;
		printf("Line %d: Close parenthesis ')' expected.\n", mierror);
		yyerrok;
	}
	| Do Stmt While OpenParentesis error CloseParentesis PuntoComa
	{
		codigo_sin_errores = false;
		mierror = @5.first_line;
		printf("Line %d: expression expected after '('.\n", mierror);
		yyerrok;
	}
	| Do Stmt While error CloseParentesis PuntoComa
	{
		codigo_sin_errores = false;
		mierror = @4.first_line;
		printf("Line %d: Open parenthesis '(' and expression expected after 'while'.\n", mierror);
		yyerrok;
	}

| Do error While OpenParentesis Expr CloseParentesis PuntoComa
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Statement expected after 'Do'.\n", mierror);
		yyerrok;
	}
	| Do Stmt error OpenParentesis Expr CloseParentesis PuntoComa
	{
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: 'while' expected.\n", mierror);
		yyerrok;
	}
	| Do Stmt While OpenParentesis Expr CloseParentesis error OpenLlave
	{
		codigo_sin_errores = false;
		mierror = @7.first_line;
		printf("Line %d: SemiColon ';' expected.\n", mierror);
		yyerrok;
	}
	| Do Stmt error Expr CloseParentesis PuntoComa
	{
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: 'while (' expected.\n", mierror);
		yyerrok;
	}
	| Do error PuntoComa
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		printf("Line %d: Error after 'Do', check statement and expressions.\n", mierror);
		yyerrok;
	}
	;
ForStmt: For OpenParentesis ForInit PuntoComa Expr PuntoComa ForUpdate CloseParentesis Stmt {
		$$ = new Node ("ForStmt",9); 
		$$ -> AddChild (new Node("for",0)); 
		$$ -> AddChild (new Node("(",0)); 			
		$$ -> AddChild ($3); 
		$$ -> AddChild (new Node(";",0)); 
		$$ -> AddChild ($5); 
		$$ -> AddChild (new Node(";",0));
		$$ -> AddChild ($7); 
		$$ -> AddChild (new Node(")",0));
		$$ -> AddChild ($9);  }
	| For OpenParentesis ForInit PuntoComa Expr PuntoComa CloseParentesis Stmt {
		$$ = new Node ("ForStmt",8); 
		$$ -> AddChild (new Node("for",0)); 
		$$ -> AddChild (new Node("(",0)); 			
		$$ -> AddChild ($3); 
		$$ -> AddChild (new Node(";",0)); 
		$$ -> AddChild ($5); 
		$$ -> AddChild (new Node(";",0));
		$$ -> AddChild (new Node(")",0));
		$$ -> AddChild ($8);   }
	| For OpenParentesis ForInit PuntoComa PuntoComa ForUpdate CloseParentesis Stmt{
		$$ = new Node ("ForStmt",8); 
		$$ -> AddChild (new Node("for",0)); 
		$$ -> AddChild (new Node("(",0)); 			
		$$ -> AddChild ($3); 
		$$ -> AddChild (new Node(";",0)); 
		$$ -> AddChild (new Node(";",0));
		$$ -> AddChild ($6); 
		$$ -> AddChild (new Node(")",0));
		$$ -> AddChild ($8);   }
		//for(forinit;;) stmt
	| For OpenParentesis ForInit PuntoComa PuntoComa CloseParentesis Stmt{
		$$ = new Node ("ForStmt",7); 
		$$ -> AddChild (new Node("for",0)); 
		$$ -> AddChild (new Node("(",0)); 			
		$$ -> AddChild ($3); 
		$$ -> AddChild (new Node(";",0)); 
		$$ -> AddChild (new Node(";",0));
		$$ -> AddChild (new Node(")",0));
		$$ -> AddChild ($7);  }
		//for(;exrp;forup) stmt
	| For OpenParentesis PuntoComa Expr PuntoComa ForUpdate CloseParentesis Stmt{
		$$ = new Node ("ForStmt",8); 
		$$ -> AddChild (new Node("for",0)); 
		$$ -> AddChild (new Node("(",0)); 			
		$$ -> AddChild (new Node(";",0)); 
		$$ -> AddChild ($4); 
		$$ -> AddChild (new Node(";",0));
		$$ -> AddChild ($6); 
		$$ -> AddChild (new Node(")",0));
		$$ -> AddChild ($8);  }
		//for(; expr ; ) stmt
	| For OpenParentesis PuntoComa Expr PuntoComa CloseParentesis Stmt {
		$$ = new Node ("ForStmt",7); 
		$$ -> AddChild (new Node("for",0)); 
		$$ -> AddChild (new Node("(",0)); 			
		$$ -> AddChild (new Node(";",0)); 
		$$ -> AddChild ($4); 
		$$ -> AddChild (new Node(";",0));
		$$ -> AddChild (new Node(")",0));
		$$ -> AddChild ($7);   }
		//for(;; forup) stmt
	| For OpenParentesis PuntoComa PuntoComa ForUpdate CloseParentesis Stmt{
		$$ = new Node ("ForStmt",7); 
		$$ -> AddChild (new Node("for",0)); 
		$$ -> AddChild (new Node("(",0)); 			
		$$ -> AddChild (new Node(";",0)); 
		$$ -> AddChild (new Node(";",0));
		$$ -> AddChild ($5); 
		$$ -> AddChild (new Node(")",0));
		$$ -> AddChild ($7);   }
		//for(;;) stmt
	| For OpenParentesis PuntoComa PuntoComa CloseParentesis Stmt{
		$$ = new Node ("ForStmt",6); 
		$$ -> AddChild (new Node("for",0)); 
		$$ -> AddChild (new Node("(",0)); 			
		$$ -> AddChild (new Node(";",0)); 
		$$ -> AddChild (new Node(";",0));
		$$ -> AddChild (new Node(")",0));
		$$ -> AddChild ($6);   }
		/*Producciones de error*/ /*for(;;) stmt*/
	| For OpenParentesis PuntoComa error CloseParentesis Stmt{
		codigo_sin_errores = false;
		mierror = @4.first_line;
		$$ = new Node ("ForStmt",6); 
		$$ -> AddChild (new Node("for",0)); 
		$$ -> AddChild (new Node("(",0)); 			
		$$ -> AddChild (new Node(";",0)); 
		$$ -> AddChild (new Node("error",0));
		$$ -> AddChild (new Node(")",0));
		$$ -> AddChild ($6);
		printf("Line %d: Error in for statement, likely ; missing\n", mierror);
		yyerrok;
		   } //error : for(;; error) stmt
	| For OpenParentesis PuntoComa PuntoComa error CloseParentesis Stmt{
		codigo_sin_errores = false;
		mierror = @5.first_line;
		$$ = new Node ("ForStmt",7); 
		$$ -> AddChild (new Node("for",0)); 
		$$ -> AddChild (new Node("(",0)); 			
		$$ -> AddChild (new Node(";",0)); 
		$$ -> AddChild (new Node(";",0));
		$$ -> AddChild (new Node("error", 0)); 
		$$ -> AddChild (new Node(")",0));
		$$ -> AddChild ($7);  
		printf("Line %d: Error in for statement after the second ;, in update phase\n", mierror);
		 }
	//error for(; error ; ) stmt
	| For OpenParentesis PuntoComa error PuntoComa CloseParentesis Stmt {
		codigo_sin_errores = false;
		mierror = @4.first_line;
		$$ = new Node ("ForStmt",7); 
		$$ -> AddChild (new Node("for",0)); 
		$$ -> AddChild (new Node("(",0)); 			
		$$ -> AddChild (new Node(";",0)); 
		$$ -> AddChild (new Node("error", 0)); 
		$$ -> AddChild (new Node(";",0));
		$$ -> AddChild (new Node(")",0));
		$$ -> AddChild ($7);   
		printf("Line %d: Error found after first ; in for statement\n", mierror);
		yyerrok;
		 }
		 
	//for(error;;) stmt
	| For OpenParentesis error PuntoComa PuntoComa CloseParentesis Stmt{
		codigo_sin_errores = false;
		mierror = @3.first_line;
		$$ = new Node ("ForStmt",7); 
		$$ -> AddChild (new Node("for",0)); 
		$$ -> AddChild (new Node("(",0)); 			
		$$ -> AddChild (new Node("error", 0)); 
		$$ -> AddChild (new Node(";",0)); 
		$$ -> AddChild (new Node(";",0));
		$$ -> AddChild (new Node(")",0));
		$$ -> AddChild ($7); 
		printf("Line %d: Error found in for initializer.\n", mierror);
		yyerrok; }
	;
ForStmtNoShortIf: For OpenParentesis ForInit PuntoComa Expr PuntoComa ForUpdate CloseParentesis StmtNoShortIf{
		$$ = new Node ("ForStmtNoShortIf",9); 
		$$ -> AddChild(new Node("for", 0));
		$$ -> AddChild(new Node("(", 0));
		$$ -> AddChild($3);
		$$ -> AddChild(new Node(";", 0));
		$$ -> AddChild($5);
		$$ -> AddChild(new Node(";", 0));
		$$ -> AddChild($7);
		$$ -> AddChild(new Node(")", 0));
		$$ -> AddChild($9);	 }
	| For OpenParentesis ForInit PuntoComa Expr PuntoComa CloseParentesis StmtNoShortIf{
		$$ = new Node ("ForStmtNoShortIf",8); 
		$$ -> AddChild(new Node("for", 0)); 
		$$ -> AddChild(new Node("(", 0));
		$$ -> AddChild($3);
		$$ -> AddChild(new Node(";", 0));
		$$ -> AddChild($5);
		$$ -> AddChild(new Node(";", 0));
		$$ -> AddChild(new Node(")", 0));
		$$ -> AddChild($8);	}
	| For OpenParentesis ForInit PuntoComa PuntoComa ForUpdate CloseParentesis StmtNoShortIf{
		$$ = new Node ("ForStmtNoShortIf",8); 
		$$ -> AddChild(new Node("for", 0)); 
		$$ -> AddChild(new Node("(", 0));
		$$ -> AddChild($3);
		$$ -> AddChild(new Node(";", 0));
		$$ -> AddChild(new Node(";", 0));
		$$ -> AddChild($6);
		$$ -> AddChild(new Node(")", 0));
		$$ -> AddChild($8);	}
	| For OpenParentesis ForInit PuntoComa PuntoComa CloseParentesis StmtNoShortIf{
		$$ = new Node ("ForStmtNoShortIf",7); 
		$$ -> AddChild(new Node("for", 0)); 
		$$ -> AddChild(new Node("(", 0)); 
		$$ -> AddChild($3);
		$$ -> AddChild(new Node(";", 0));
		$$ -> AddChild(new Node(";", 0));
		$$ -> AddChild(new Node(")", 0));
		$$ -> AddChild($7);	}
	| For OpenParentesis PuntoComa Expr PuntoComa ForUpdate CloseParentesis StmtNoShortIf {
		$$ = new Node ("ForStmtNoShortIf",8); 
		$$ -> AddChild(new Node("for", 0)); 
		$$ -> AddChild(new Node("(", 0)); 
		$$ -> AddChild(new Node(";", 0));
		$$ -> AddChild($4);
		$$ -> AddChild(new Node(";", 0));
		$$ -> AddChild($6);
		$$ -> AddChild(new Node(")", 0));
		$$ -> AddChild($8);	 }
	| For OpenParentesis PuntoComa Expr PuntoComa CloseParentesis StmtNoShortIf{
		$$ = new Node ("ForStmtNoShortIf",7);  
		$$ -> AddChild(new Node("for", 0)); 
		$$ -> AddChild(new Node("(", 0)); 
		$$ -> AddChild(new Node(";", 0));
		$$ -> AddChild($4);
		$$ -> AddChild(new Node(";", 0));
		$$ -> AddChild(new Node(")", 0));
		$$ -> AddChild($7);	}
	| For OpenParentesis PuntoComa PuntoComa ForUpdate CloseParentesis StmtNoShortIf{
		$$ = new Node ("ForStmtNoShortIf",7); 
		$$ -> AddChild(new Node("for", 0)); 
		$$ -> AddChild(new Node("(", 0)); 
		$$ -> AddChild(new Node(";", 0));
		$$ -> AddChild(new Node(";", 0));
		$$ -> AddChild($5);
		$$ -> AddChild(new Node(")", 0));
		$$ -> AddChild($7);	}
	| For OpenParentesis PuntoComa PuntoComa CloseParentesis StmtNoShortIf{
		$$ = new Node ("ForStmtNoShortIf",6); 
		$$ -> AddChild(new Node("for", 0)); 
		$$ -> AddChild(new Node("(", 0)); 
		$$ -> AddChild(new Node(";", 0));
		$$ -> AddChild(new Node(";", 0));
		$$ -> AddChild(new Node(")", 0));
		$$ -> AddChild($6); }
			/*Producciones de error*/ /*for(;;) stmt*/
	| For OpenParentesis PuntoComa error CloseParentesis StmtNoShortIf{
		codigo_sin_errores = false;
		mierror = @4.first_line;
		$$ = new Node ("ForStmt",6); 
		$$ -> AddChild (new Node("for",0)); 
		$$ -> AddChild (new Node("(",0)); 			
		$$ -> AddChild (new Node(";",0)); 
		$$ -> AddChild (new Node("error",0));
		$$ -> AddChild (new Node(")",0));
		$$ -> AddChild ($6);
		printf("Line %d: Error in for statement, likely ; missing\n", mierror);
		yyerrok;
		   } //error : for(;; error) stmt
	| For OpenParentesis PuntoComa PuntoComa error CloseParentesis StmtNoShortIf{
		codigo_sin_errores = false;
		mierror = @5.first_line;
		$$ = new Node ("ForStmt",7); 
		$$ -> AddChild (new Node("for",0)); 
		$$ -> AddChild (new Node("(",0)); 			
		$$ -> AddChild (new Node(";",0)); 
		$$ -> AddChild (new Node(";",0));
		$$ -> AddChild (new Node("error", 0)); 
		$$ -> AddChild (new Node(")",0));
		$$ -> AddChild ($7);  
		printf("Line %d: Error in for statement after the second ;, in update phase\n", mierror);
		 }
	//error for(; error ; ) stmt
	| For OpenParentesis PuntoComa error PuntoComa CloseParentesis StmtNoShortIf {
		codigo_sin_errores = false;
		mierror = @4.first_line;
		$$ = new Node ("ForStmt",7); 
		$$ -> AddChild (new Node("for",0)); 
		$$ -> AddChild (new Node("(",0)); 			
		$$ -> AddChild (new Node(";",0)); 
		$$ -> AddChild (new Node("error", 0)); 
		$$ -> AddChild (new Node(";",0));
		$$ -> AddChild (new Node(")",0));
		$$ -> AddChild ($7);   
		printf("Line %d: Error found after first ; in for statement\n", mierror);
		yyerrok;
		 }
		 
	//for(error;;) stmt
	| For OpenParentesis error PuntoComa PuntoComa CloseParentesis StmtNoShortIf{
		codigo_sin_errores = false;
		mierror = @3.first_line;
		$$ = new Node ("ForStmt",7); 
		$$ -> AddChild (new Node("for",0)); 
		$$ -> AddChild (new Node("(",0)); 			
		$$ -> AddChild (new Node("error", 0)); 
		$$ -> AddChild (new Node(";",0)); 
		$$ -> AddChild (new Node(";",0));
		$$ -> AddChild (new Node(")",0));
		$$ -> AddChild ($7); 
		printf("Line %d: Error found in for initializer.\n", mierror);
		yyerrok; }
;
ForInit: StmtExprList{
		$$ = new Node ("ForInit",1); 
		$$ -> AddChild ($1); }
	| LocalVariableDeclaration{
		$$ = new Node ("ForInit",1); 
		$$ -> AddChild ($1, @1.first_line); }
	;
ForUpdate: StmtExprList{
		$$ = new Node ("ForUpdate",1); 
		$$ -> AddChild ($1); }
	;
StmtExprList: StmtExpr{
		$$ = new Node ("StmtExprList",1); 
		$$ -> AddChild ($1); }
	| StmtExprList Coma StmtExpr {
		$$ = new Node ("StmtExprList",3); 
		$$ -> AddChild ($1);
		$$ -> AddChild(new Node(",", 0));
		$$ -> AddChild($3);
		 }
	;
BreakStmt: Break PuntoComa {
		int line  = @1.first_line;
		$$ = new Node ("BreakStmt",2); 
		$$ -> AddChild(new Node("break", 0), line);
		$$ -> AddChild(new Node(";", 0)); }
		
		BreakStmt: Break error CloseLlave {
		
		mierror = @2.first_line;
		$$ = new Node ("BreakStmt",2); 
		$$ -> AddChild(new Node("break", 0));
		$$ -> AddChild(new Node("error", 0)); 
		$$ -> AddChild(new Node("}", 0)); 
		printf("Line %d: ; missing after break keyword.\n", mierror);
		yyerrok;
		}
		
	;
ContinueStmt: Continue PuntoComa {
		$$ = new Node ("ContinueStmt",2); 
		$$ -> AddChild(new Node("continue", 0), @1.first_line);
		$$ -> AddChild(new Node(";", 0)); }
	;
ReturnStmt: Return Expr PuntoComa {
		$$ = new Node ("ReturnStmt",3); 
	
		$$ -> AddChild(new Node("return", 0));
		$$->children[0]->line = @1.first_line;
		$$ -> AddChild ($2); 
		$$ -> AddChild(new Node(";", 0)); }
	| Return PuntoComa {
		$$ = new Node ("ReturnStmt",2);
	
		$$ -> AddChild(new Node("return", 0));
		$$->children[0]->line = @1.first_line;
		$$ -> AddChild(new Node(";", 0)); }
	;
Primary: PrimaryNoNewArray {
		$$ = new Node ("Primary",1); 
		$$ -> AddChild ($1); }
	| ArrayCreationExpr {
		$$ = new Node ("Primary",1); 
		$$ -> AddChild ($1); }
		
	;
PrimaryNoNewArray: Literal {
		$$ = new Node ("PrimaryNoNewArray",1); 
		$$ -> AddChild ($1, @1.first_line); }
	| This {
		$$ = new Node ("PrimaryNoNewArray",1); 
		$$ -> AddChild(new Node("this", 0)); }
	| OpenParentesis Expr CloseParentesis {
		$$ = new Node ("PrimaryNoNewArray",3); 
		$$ -> AddChild(new Node("(", 0));
		$$ -> AddChild($2, @2.first_line);
		$$ -> AddChild(new Node(")", 0)); }
	| ClassInstanceCreationExpr {
		$$ = new Node ("PrimaryNoNewArray",1); 
		$$ -> AddChild ($1, @1.first_line); }
	|FieldAccess {
		$$ = new Node ("PrimaryNoNewArray",1); 
		$$ -> AddChild ($1, @1.first_line); }
	| MethodInvocation {
		$$ = new Node ("PrimaryNoNewArray",1); 
		$$ -> AddChild ($1, @1.first_line); }
	| ArrayAccess {
		$$ = new Node ("PrimaryNoNewArray",1); 
		$$ -> AddChild ($1, @1.first_line); }
	;
ClassInstanceCreationExpr: New ClassType OpenParentesis ArgumentList CloseParentesis{
		$$ = new Node ("ClassInstanceCreationExpr",5); 
		$$ -> AddChild(new Node("new", 0));
		$$ -> AddChild($2);
		$$ -> AddChild(new Node("(", 0));
		$$ -> AddChild($4);
		$$ -> AddChild(new Node(")", 0));}
	| New ClassType OpenParentesis CloseParentesis{
		$$ = new Node ("ClassInstanceCreationExpr",4); 
		$$ -> AddChild(new Node("new", 0));
		$$ -> AddChild($2);
		$$ -> AddChild(new Node("(", 0));
		$$ -> AddChild(new Node(")", 0));}
	/*| 
	New ClassType OpenParentesis error CloseParentesis{
		$$ = new Node ("ClassInstanceCreationExpr",1); 
		$$ -> AddChild(new Node("new", 0));
		$$ -> AddChild($2);
		$$ -> AddChild(new Node("(", 0));
		$$ -> AddChild(new Node("error", 0));
		$$ -> AddChild(new Node(")", 0));}
	*/
	;
ArgumentList: Expr {
		$$ = new Node ("ArgumentList",1); 
		$$ -> AddChild ($1); }
	| ArgumentList Coma Expr {
		$$ = new Node ("ArgumentList",3); 
		$$ -> AddChild ($1);
		$$ -> AddChild(new Node(",", 0));
		$$ -> AddChild($3);	}
	| error Coma Expr {
		codigo_sin_errores = false;
		mierror = @1.first_line;
		$$ = new Node("ArgumentList", 3);
		$$ -> AddChild(new Node("error", 0));
		$$ -> AddChild(new Node(",", 0));
		$$ -> AddChild($3);
		printf("Line %d: Error in argument list before ','\n", mierror);
		yyerrok;
		}
	| ArgumentList error Expr {
		codigo_sin_errores = false;
		mierror = @2.first_line;
		$$ = new Node("ArgumentList", 3);
		$$ -> AddChild($1);
		$$ -> AddChild(new Node("error", 0));
		$$ -> AddChild($3);
		printf("Line %d: Error in argument list, expecting ',' or valid parameter\n", mierror);
		yyerrok;
	}
	;
ArrayCreationExpr: New PrimitiveType DimExprs Dims {
		$$ = new Node ("ArrayCreationExpr",4); 
		$$ -> AddChild (new Node("new", 0));
		$$ -> AddChild ($2);
		$$ -> AddChild ($3); 
		$$ -> AddChild ($4);}
	| New PrimitiveType DimExprs{
		$$ = new Node ("ArrayCreationExpr",3); 
		$$ -> AddChild(new Node("new", 0));
		$$ -> AddChild ($2);
		$$ -> AddChild ($3); }
	| New ClassType DimExprs Dims {
		$$ = new Node ("ArrayCreationExpr",4); 
		$$ -> AddChild(new Node("new", 0));
		$$ -> AddChild ($2);
		$$ -> AddChild ($3);
		$$ -> AddChild ($4); }
	| New ClassType DimExprs{
		$$ = new Node ("ArrayCreationExpr",3); 
		$$ -> AddChild(new Node("new", 0));
		$$ -> AddChild ($2);
		$$ -> AddChild ($3); }
	
	| New PrimitiveType error 
	{
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: Error with dimensions\n", mierror);
		yyerrok;
	}
	| New ClassType error
	{
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: Error with dimensions in array creation\n", mierror);
		yyerrok;
	}
	| New error DimExprs 
	{
		codigo_sin_errores = false;
		mierror = @3.first_line;
		printf("Line %d: Error in array declaration: Expecting primitive type or ClassType.\n", mierror);
		yyerrok;
	}
	;
DimExprs: DimExpr {
		$$ = new Node ("DimExprs",1); 
		$$ -> AddChild ($1); }
	| DimExprs DimExpr{
		$$ = new Node ("DimExprs",2); 
		$$ -> AddChild($1);
		$$ -> AddChild($2); }
	;
DimExpr: OpenCorchete Expr CloseCorchete {
		$$ = new Node ("DimExpr",3); 
		$$ -> AddChild(new Node("[", 0));
		$$ -> AddChild ($2);
		$$ -> AddChild(new Node("]", 0)); }
		| OpenCorchete error CloseCorchete
	{
		codigo_sin_errores = false;
		mierror = @2.first_line;
		$$ = new Node("DimExpr", 3);
		$$ -> AddChild(new Node("[", 0));
		$$ -> AddChild(new Node("error", 0));
		$$ -> AddChild(new Node("]", 0));
		printf("Line %d: Error in expression within []\n", mierror);
		yyerrok;	
	}
	;
Dims: OpenCorchete CloseCorchete{
		$$ = new Node ("Dims",2); 
		$$ -> AddChild(new Node("[", 0));
		$$ -> AddChild(new Node("]", 0)); }
	| Dims OpenCorchete CloseCorchete {
		$$ = new Node ("Dims",3); 
		$$ -> AddChild ($1);
		$$ -> AddChild(new Node("[", 0));
		$$ -> AddChild(new Node("]", 0)); }
	;
FieldAccess: Primary punto Identifier {
		$$ = new Node ("FieldAccess",3); 
		$$ -> AddChild ($1);
		$$ -> AddChild(new Node(".", 0)); 
		$$->AddChild(new Node("Identifier", new Node($3, 0), @3.first_line));}
	| super punto Identifier{
		$$ = new Node ("FieldAccess",3); 
		$$ -> AddChild(new Node("super", 0));
		$$ -> AddChild(new Node(".", 0));
		$$->AddChild(new Node("Identifier", new Node($3, 0), @3.first_line)); }
	
	;
MethodInvocation: Name OpenParentesis ArgumentList CloseParentesis {
		$$ = new Node ("MethodInvocation",4); 
		$$ -> AddChild ($1);
		$$ -> AddChild(new Node("(", 0));
		$$ -> AddChild($3); 
		$$ -> AddChild(new Node(")", 0));}
	| Name OpenParentesis CloseParentesis {
		$$ = new Node ("MethodInvocation",3); 
		$$ -> AddChild ($1);
		$$ -> AddChild(new Node("(", 0));
		$$ -> AddChild(new Node(")", 0)); }
	| Primary punto Identifier OpenParentesis ArgumentList CloseParentesis {
		$$ = new Node ("MethodInvocation",6); 
		$$ -> AddChild ($1);
		$$ -> AddChild(new Node(".", 0));
		$$->AddChild(new Node("Identifier", new Node($3, 0), @3.first_line));
		$$ -> AddChild(new Node("(", 0));
		$$ -> AddChild($5);
		$$ -> AddChild(new Node(")", 0)); }
	| Primary punto Identifier OpenParentesis CloseParentesis{
		$$ = new Node ("MethodInvocation",5); 
		$$ -> AddChild ($1);
		$$ -> AddChild(new Node(".", 0));
		$$->AddChild(new Node("Identifier", new Node($3, 0), @3.first_line));
		$$ -> AddChild(new Node("(", 0));
		$$ -> AddChild(new Node(")", 0)); }
	| super punto Identifier OpenParentesis ArgumentList CloseParentesis{
		$$ = new Node ("MethodInvocation",6); 
		$$ -> AddChild(new Node("super", 0));
		$$ -> AddChild(new Node(".", 0));
		$$->AddChild(new Node("Identifier", new Node($3, 0), @3.first_line));
		$$ -> AddChild(new Node("(", 0));
		$$ -> AddChild($5);
		$$ -> AddChild(new Node(")", 0)); }
	| super punto Identifier OpenParentesis CloseParentesis{
		$$ = new Node ("MethodInvocation",5); 
		$$ -> AddChild(new Node("super", 0));
		$$ -> AddChild(new Node(".", 0));
		$$->AddChild(new Node("Identifier", new Node($3, 0), @3.first_line));
		$$ -> AddChild(new Node("(", 0));
		$$ -> AddChild(new Node(")", 0)); }
	| Primary punto error CloseParentesis
	{
		codigo_sin_errores = false;
		mierror = @3.first_line;
		$$ = new Node("MethodInvocation", 4);
		$$ -> AddChild($1);
		$$ -> AddChild(new Node($2, 0));
		$$ -> AddChild(new Node("error", 0));
		$$ -> AddChild(new Node($4, 0));
		printf("Line %d: Error in method call, expected (\n", mierror);
		yyerrok;
	}
	;
ArrayAccess: Name OpenCorchete Expr CloseCorchete {
		$$ = new Node ("ArrayAccess",4); 
		$$ -> AddChild($1);
		$$ -> AddChild(new Node("[", 0));
		$$ -> AddChild ($3);
		$$ -> AddChild(new Node("]", 0)); }
	| PrimaryNoNewArray OpenCorchete Expr CloseCorchete{
		$$ = new Node ("ArrayAccess",4); 
		$$ -> AddChild ($1);
		$$ -> AddChild(new Node("[", 0));
		$$ -> AddChild($3);
		$$ -> AddChild(new Node("]", 0)); }
	;
PostfixExpr: Primary {
		$$ = new Node ("PostfixExpr",1); 
		$$ -> AddChild ($1); }
	| Name {
		$$ = new Node ("PostfixExpr",1); 
		$$ -> AddChild ($1); }
	| PostIncrementExpr {
		$$ = new Node ("PostfixExpr",1); 
		$$ -> AddChild ($1); }
	| PostDecrementExpr {
		$$ = new Node ("PostfixExpr",1); 
		$$ -> AddChild ($1); }
	;
PostIncrementExpr: PostfixExpr PlusPlus {
		$$ = new Node ("PostIncrementExpr",2); 
		$$->line = @1.first_line;
		$$ -> AddChild ($1); 
		$$ -> AddChild(new Node("++", 0));}
	;
PostDecrementExpr: PostfixExpr MinusMinus{
		$$ = new Node ("PostDecrementExpr",2); 
		$$->line = @1.first_line;
		$$ -> AddChild ($1);
		$$ -> AddChild(new Node("--", 0)); }
	;
UnaryExpr: PreIncrementExpr {
		$$ = new Node ("UnaryExpr",1); 
		$$ -> AddChild ($1); }
	| PreDecrementExpr {
		$$ = new Node ("UnaryExpr",1); 
		$$ -> AddChild ($1); }
	| AddOp UnaryExpr {
		$$ = new Node ("UnaryExpr",2); 
		$$->AddChild(new Node("AddOp", new Node($1, 0), @1.first_line));
		$$ -> AddChild ($2); }
	| UnaryExprNotPlusMinus{
		$$ = new Node ("UnaryExpr",1); 
		$$ -> AddChild ($1); }
	;
PreIncrementExpr: PlusPlus UnaryExpr{
		$$ = new Node ("PreIncrementExpr",2); 
		$$->line = @2.first_line;
		$$ -> AddChild(new Node("++", 0));
		$$ -> AddChild ($2); }
	;
PreDecrementExpr: MinusMinus UnaryExpr{
		$$->line = @2.first_line;
		$$ = new Node ("PreDecrementExpr",2); 
		$$ -> AddChild(new Node("--", 0));
		$$ -> AddChild ($2); }
	;
UnaryExprNotPlusMinus: PostfixExpr {
		$$ = new Node ("UnaryExprNotPlusMinus",1); 
		$$ -> AddChild ($1); }
	| Not UnaryExpr{
		$$ = new Node ("UnaryExprNotPlusMinus",2); 
		$$ -> AddChild(new Node($1, 0));
		$$ -> AddChild ($2); }
	| CastExpr{
		$$ = new Node ("UnaryExprNotPlusMinus",1); 
		$$ -> AddChild ($1); }
	;
CastExpr: OpenParentesis PrimitiveType Dims CloseParentesis UnaryExpr {
		$$ = new Node ("CastExpr",5); 
		$$ -> AddChild(new Node("(", 0));
		$$ -> AddChild ($2);
		$$ -> AddChild($3);
		$$ -> AddChild(new Node(")", 0));
		$$ -> AddChild($5); }
	| OpenParentesis PrimitiveType CloseParentesis UnaryExpr{
		$$ = new Node ("CastExpr",4); 
		$$ -> AddChild(new Node("(", 0));
		$$ -> AddChild ($2); 
		$$ -> AddChild(new Node(")", 0));
		$$ -> AddChild($4);}
	| OpenParentesis Expr CloseParentesis UnaryExprNotPlusMinus{
		$$ = new Node ("CastExpr",4); 
		$$ -> AddChild(new Node("(", 0));
		$$ -> AddChild ($2); 
		$$ -> AddChild(new Node(")", 0));
		$$ -> AddChild($4);}
	| OpenParentesis Name Dims CloseParentesis UnaryExprNotPlusMinus{
		$$ = new Node ("CastExpr",5); 
		$$ -> AddChild(new Node("(", 0));
		$$ -> AddChild ($2);
		$$ -> AddChild($3);
		$$ -> AddChild(new Node(")", 0));
		$$ -> AddChild($5); }
	| OpenParentesis PrimitiveType Dims error UnaryExpr
	 {
	 	mierror = @4.first_line;
	 	printf("Line %d: Missing )\n", mierror);
	 	yyerrok;
	 }
	 | OpenParentesis PrimitiveType error UnaryExpr
	 {
	 	mierror = @3.first_line;
	 	printf("Line %d: Missing )\n", mierror);
	 	yyerrok;	
	 }
;
MultiplicativeExpr: UnaryExpr{
		$$ = new Node ("MultiplicativeExpr",1); 
		$$ -> AddChild ($1); }
	| MultiplicativeExpr MultOp UnaryExpr{
		$$ = new Node ("MultiplicativeExpr",3); 
		$$ -> AddChild ($1);
		$$->AddChild(new Node("MultOp", new Node($2, 0), @2.first_line));
		$$ -> AddChild($3); }
	;
AdditiveExpr: MultiplicativeExpr{
		$$ = new Node ("AdditiveExpr",1); 
		$$ -> AddChild ($1); }
	| AdditiveExpr AddOp MultiplicativeExpr {
		$$ = new Node ("AdditiveExpr",3); 
		$$ -> AddChild ($1);
		$$->AddChild(new Node("AddOp", new Node($2, 0), @2.first_line));
		$$ -> AddChild($3);	}
	;
RelationalExpr: AdditiveExpr{
		$$ = new Node ("RelationalExpr",1); 
		$$ -> AddChild ($1); }
	| RelationalExpr Relacion AdditiveExpr{
		$$ = new Node ("RelationalExpr",3); 
		$$ -> AddChild ($1);
		$$->AddChild(new Node("Relacion", new Node($2, 0), @2.first_line));
		$$ -> AddChild($3); }
	;
EqualityExpr: RelationalExpr{
		$$ = new Node ("EqualityExpr",1); 
		$$ -> AddChild ($1); }
	| EqualityExpr Igualdad RelationalExpr{
		$$ = new Node ("EqualityExpr",3); 
		$$ -> AddChild ($1);
		$$->AddChild(new Node("Igualdad", new Node($2, 0), @2.first_line));
		$$ -> AddChild($3);  }
		
	;
AndExpr: EqualityExpr{
		$$ = new Node ("AndExpr",1); 
		$$ -> AddChild ($1); }
	| AndExpr And EqualityExpr{
		$$ = new Node ("AndExpr",3); 
		$$ -> AddChild ($1);
		$$ -> AddChild(new Node("&", 0));
		$$ -> AddChild($3); }
	;
ExclusiveOrExpr: AndExpr{
		$$ = new Node ("ExclusiveOrExpr",1); 
		$$ -> AddChild ($1); }
	| ExclusiveOrExpr Tongo AndExpr{
		$$ = new Node ("ExclusiveOrExpr",3); 
		$$ -> AddChild ($1);
		$$ -> AddChild(new Node("^", 0));
		$$ -> AddChild($3); }
	;
InclusiveOrExpr: ExclusiveOrExpr{
		$$ = new Node ("InclusiveOrExpr",1); 
		$$ -> AddChild ($1); }
	| InclusiveOrExpr Or ExclusiveOrExpr {
		$$ = new Node ("InclusiveOrExpr",3); 
		$$ -> AddChild ($1);
		$$ -> AddChild(new Node("|", 0));
		$$ -> AddChild($3); }
	;
ConditionalAndExpr: InclusiveOrExpr{
		$$ = new Node ("ConditionalAndExpr",1); 
		$$ -> AddChild ($1); }
	| ConditionalAndExpr AndAnd InclusiveOrExpr{
		$$ = new Node ("ConditionalAndExpr",3); 
		$$ -> AddChild ($1);
		$$ -> AddChild(new Node("&&", 0));
		$$ -> AddChild($3); }
	;
ConditionalOrExpr: ConditionalAndExpr{
		$$ = new Node ("ConditionalOrExpr",1); 
		$$ -> AddChild ($1); }
	| ConditionalOrExpr OrOr ConditionalAndExpr{
		$$ = new Node ("ConditionalOrExpr",3); 
		$$ -> AddChild ($1);
		$$ -> AddChild(new Node("||", 0));
		$$ -> AddChild($3); }
	;
ConditionalExpr: ConditionalOrExpr{
		$$ = new Node ("ConditionalExpr",1); 
		$$ -> AddChild ($1); }
	;
AssignmentExpr: ConditionalExpr{
		$$ = new Node ("AssignmentExpr",1); 
		$$ -> AddChild ($1); }
	| Assignment{
		$$ = new Node ("AssignmentExpr",1); 
		$$ -> AddChild ($1); }
	;
Assignment: LeftHandSide AssignmentOperator AssignmentExpr {
		$$ = new Node ("Assignment",3); 
		$$ -> AddChild ($1);
		$$ -> AddChild ($2);
		$$ -> AddChild ($3); }	
	;
LeftHandSide: Name{
		$$ = new Node ("LeftHandSide",1); 
		$$ -> AddChild ($1); }
	| FieldAccess{
		$$ = new Node ("LeftHandSide",1); 
		$$ -> AddChild ($1); }
	| ArrayAccess{
		$$ = new Node ("LeftHandSide",1); 
		$$ -> AddChild ($1); }
	;
AssignmentOperator: Equals{
		$$ = new Node ("AssignmentOperator",1); 
		$$ -> AddChild (new Node("=", 0)); }
	| variableDeclarator {
		$$ = new Node ("AssignmentOperator",1); 
		$$->AddChild(new Node($1, 0), @1.first_line); }
	;
Expr: AssignmentExpr{
		$$ = new Node ("Expr",1); 
		$$ -> AddChild ($1); }
	;
ConstantExpr: Expr {
		$$ = new Node ("ConstantExpr",1); 
		$$ -> AddChild ($1); }
	;
%%

/*#define YYERROR_VERBOSE

char *printableChar="@ABCDEFGHKLMNOPQRSTUVWXYZ[\\]^_";
char printableBuffer[5];
char *printable(unsigned int c)
{
    if (c<32) {
        printableBuffer[0]='^';
        printableBuffer[1]=printableChar[c];
        printableBuffer[2]='\n';
    }
    else if (c<127) {
        printableBuffer[0]=c;
        printableBuffer[1]='\n';
    }
    else if (c==127) {
        strcpy(printableBuffer, "DEL");
    }
    else {
        sprintf(printableBuffer, "0x%2x", c&0xff);
    }
    return printableBuffer;
}


void yyerror(const char *msg)
{
    if (strstr(msg, "Invalid input character")) {
        printf("WARNING(%d): %s: %s.  Character ignored.\n", 
               line, 
               msg, 
	       printable((unsigned int)*lastToken));
	printf("WARNING(%d): %s", numWarnings, msg);
        numWarnings++;
    }
    else {
        char *unex1;
        unex1 = (char*)strstr(msg, "unexpected ")+strlen("unexpected ");
        if ((*unex1 != '\'') && 
            ((strstr(unex1, "ID")==unex1) || 
             (strstr(unex1, "NUM")==unex1))
            ) {
		printf("ERROR(%d) num bla %s",numErrors,  msg+1);
            //printf("ERROR(%d): S%s but got the string \"%s\"\n", line, msg+1, lastToken);
        }
        else {
	printf("ERROR(%i): S%s\n", numErrors, msg+1);
            //printf("ERROR(%d): S%s\n", line, msg+1);
        }
        numErrors++;
    }
}*/

string javaTypeToCil(char * javaType)
{
	stringstream ss;
	string toReturn;
	
	
	
	if(!strcmp(javaType, "int"))
	{
		return "int32";
	}
	else if(!strcmp(javaType, "float"))
	{
		return "float32";
	}
	else if(!strcmp(javaType, "boolean"))
	{
		return "bool";
	}
	else if(!strcmp(javaType, "void"))
	{
		return "void";
	}
	else if(!strcmp(javaType, "char"))
	{
		return "char";
	}
	else if(!strcmp(javaType, "float[]"))
	{
		return "float32[]";
	}
	else if(!strcmp(javaType, "int[]"))
	{
		return "int32[]";
	}
	else if(!strcmp(javaType, "boolean[]"))
	{
		return "bool[]";
	}
	else if(!strcmp(javaType, "char[]"))
	{
		return "char[]";
	}
	else 
	{	
		ss << "class " << javaType;
		toReturn = ss.str();
		ss.str() = "";
		ss.str("");
		return toReturn;
		
	}
}

void meetParents(Node *node)
{
	for(int i = 0; i < node->numChildren; i++)
	{
		node->children[i]->parent = node;
		meetParents(node->children[i]);
	}
}

void yyerror(char const* error)
{
	codigo_sin_errores = false;
	printf("%s\n", error);
}

bool sortFunction (class Error * e1, class Error * e2)
{
	
	if(e1 == NULL || e2 == NULL) printf("null\n");
	return e1->numLine < e2->numLine;
}

void printErrors()
{
	printf("Number of semantic Errors: %d\n\n", errors.size());
	
	vector<class Error*>::iterator it;
	sort (errors.begin(), errors.end(), sortFunction);
	//printf("Llega aqui\n");
	
	for(it = errors.begin(); it != errors.end(); it++)
		cout << (*it)->message;
	
	cout << endl;
}


/* CODIGO QUE USA EL PARSER */
int main () {

try
{
	printf("\n\nCOMPILANDO...\n\n");

	symbolTable = new SymbolTable();
	cil.open ("cil.il");
	cil << ".assembly extern mscorlib {}" << endl;
	cil << ".assembly test {}" << endl << endl;
	
	yyparse(); 
	//print(root, "");
	//printf("Llega aqui\n");
	//print(root, "", 0);
	cutTree(root, NULL);
	
	//printf("llega aqui\n");
	if(codigo_sin_errores)
	{
		print(root, "", 0);
		printf("No se encontraron errores sintácticos.\n\n");
	
	meetParents(root);

	//Para el codigo cil:
	ifNode = new numNode(ifCount);
	elseNode = new numNode(elseCount);
	whileNode = new numNode(whileCount);
	forNode = new numNode(forCount);
	doNode = new numNode(doCount);
	switchNode = new numNode(switchCount);
	caseNode = new numNode(caseCount); 
	ordenFlujo = new numNode(-1);

	//printf("llega aqui\n");
	//Scope related
	scopeInic = new ScopeNode(numScope, NULL);	
	analyzeBFS(root, scopeInic, 0);
	addInheritance();
	addDefaultConstructors();
	printf("PRINTING SCOPES AFTER BFS ANALYSIS\n");
	printChild(scopeInic);
	printSymbols(scopeInic);
	printScope(scopeInic);
	
	
	createScopeTree(root, scopeInic, 0);
	
	checkBFS();
	
	if(!mainFound)
	{
		semanticErrors = true;
		string str = "Line 0: no main method found.\n";
		errors.push_back(new class Error(str, 0));
	}

	AddInitMethod((char*)"void", (char*)"System.out.print");
	AddInitMethod((char*)"void*", (char*)"System.in.read"); //CAMBIAR TIPO DE RETORNO
	AddInitMethod((char*)"void", (char*)"System.out.println");

	printf("\n-------START PRINTING SCOPES---------\n\n");	
	printChild(scopeInic);
	printSymbols(scopeInic);
	printScope(scopeInic);
	printf("\n--------END PRINTING SCOPES----------\n");

	printf("\n-----START PRINTING SYMBOL TABLE------\n\n");	
	printSymbolTree(scopeInic);
	printf("\n------END PRINTING SYMBOL TABLE-------\n");
	
	printErrors();
}
else
	printf("\nSe encontraron errores sintácticos.\n\n");
	//createSymbolTable();
	symbolTable->print();
	cil.close();
}
catch( ...) {
      cout << "Exception raised: "  << '\n';
}
	return 0;
}

void addInheritance()
{
	for(int i = 0; i < scopeInic->numSymbols; i++)
	{
		ClassSymbol * classSymbol = (ClassSymbol*)scopeInic->symbols[i];
		if(classSymbol->hasBase)
		{
			cout << "Checking validity of inheritance for " << classSymbol->id << endl;
			Symbol * sym = symbolTable->Find(classSymbol->base, scopeInic->scopeNum);
			if(sym == NULL)
			{
				stringstream ss;
				ss << "$Error(" << classSymbol->numLine << "): Attempting to inherit from non-declared class " << classSymbol->base << ".\n";
				errors.push_back(new class Error(ss.str(), classSymbol->numLine));
				classSymbol->hasBase = false;
				classSymbol->baseClass = NULL;
			}
			else
			{
				
				classSymbol->hasBase = true;
				classSymbol->baseClass = (ClassSymbol*)sym;
			}
		
		}
	}
}

void AddInitMethod (char* returnType, char* id)
{
	Method * methodSymbol = new Method();
	methodSymbol->methodType = METHOD;
	methodSymbol->visibility = PUBLIC;			
	methodSymbol->id = id;
	methodSymbol->returnType = returnType;
	methodSymbol->scope = scopeInic->scopeNum;		
	methodSymbol->type = (char*)"PREDEFINED";
	scopeInic->AddSymbol(methodSymbol);
	
	symbolTable->Insert(methodSymbol); // Insertamos el símbolo en la tabla de hash
}
/*ScopeNode * scopeNode
void createSymbolTable()
{
	if(root == NULL)
	{
		printf("Error: root NULL.\n");
		return;
	}
	analyzeTree(root);	
}*/

void analyzeAttrSymbol(Node *classNode, ScopeNode* scopeNode)
{	
	Attribute * attrSymbol;
	Node ** children = classNode->children;
	char* variableType;
	int numDimensions = 0;
	enum Visibility vis;
	vector<Node*> attr;
	int numAttr;
	int line; //Linea en la que se encuentra el atributo, se utiliza para los errores.
	int idLocation = 1; //Nos indica dónde está la parte sin modifier ni type
	
	//Las estructuras que puede tener un FieldDeclaration son:
	//<Identifier>;
	//Modifier <Type> <Identifier>;
	//Modifier <Type> <VariableDeclarator>	-> se hace una asignación
	//Modifier <Type> <VariableDeclarators>	-> multiples declaraciones, algunas pueden o no tener una asignacion
	
	//VariableDeclarator, a su vez, puede ser:
	//<Identifier> = <Expr> O BIEN <VariableDeclaratorId> = Expr para declarar un arreglo.
	
	
	if(!strcmp(children[0]->token, "Modifiers") || !strcmp(children[0]->token, "Modifier")) //Then it has a modifier
	{
		vis = getModifier(children[0]);
		variableType = getType(children[1]); //children[1] == <type>
		if(isArrayType(children[1]))
		{
			numDimensions = 1;
		}
		numAttr = countVariablesDeclared(children[2]);
		idLocation = 2;
	}
	else
	{
		vis = DEFAULT;
		variableType = getType(children[0]); //children[0] == <type>
		if(isArrayType(children[0]))
		{
			numDimensions = 1;
		}
		numAttr = countVariablesDeclared(children[1]);
	}
	
		int length = strlen(variableType)+4;
		//REVISAR: CUIDADO CON LOS DUMP...
		char * type2 = new char[length];
		type2[length-1] = '\0';
	
		
	
		if(numDimensions == 1) 
		{
			sprintf(type2, "%s%s", variableType, "[]");
			variableType = type2;
		}	

	Node * declarators = children[idLocation];
	numAttr = 1; //Si estamos aquí hay al menos un atributo
	while(!strcmp(declarators->token, "VariableDeclarators"))
	{
		attr.push_back(declarators->children[2]); //Esto puede ser un Id o VariableDeclarator
		declarators = declarators->children[0];	//Esto puede ser un Id, variableDeclarators o VariableDeclarator
		numAttr++;
	}
	attr.push_back(declarators);	//El nodo faltante. Attrs queda con puros id o variableDeclarator.
		
	for (int i = 0; i < numAttr; i++)
	{
		attrSymbol = new Attribute();
		attrSymbol->variableType = variableType;
		attrSymbol->numDimensions = numDimensions;
		
		if(!strcmp(attr[i]->token, "Identifier")) //Un id, no es inicializado.
		{
			attrSymbol->id = attr[i]->leafValue();
		}
		else if(!strcmp(attr[i]->token, "VariableDeclarator")) //Es inicializado...
		{
			if(!strcmp(attr[i]->children[0]->token, "Identifier"))	//Y no es un arreglo.
				attrSymbol->id = attr[i]->children[0]->leafValue();
			else	//Caso <VariableDeclaratorId> ==> <Id> [];
			{
				attrSymbol->numDimensions = 1;
				attrSymbol->id = attr[i]->children[0]->children[0]->leafValue();
			}				
			attrSymbol->initializerCode = attr[i]->children[2];
		}
		else if(!strcmp(attr[i]->token, "VariableDeclaratorId"))
		{
			attrSymbol->id = attr[i]->children[0]->leafValue();
			attrSymbol->numDimensions = 1;
		}
		
		
		if(symbolTable->exists(attrSymbol->id, scopeNode->scopeNum))
		{
			semanticErrors = true;	
			stringstream ss;
			ss << "Line " << attr[i]->getLine() << ": Attribute " << attrSymbol->id << " has been previously declared.\n";
			errors.push_back(new class Error(ss.str(), attr[i]->getLine()));
		}
	
		//Para ver si el tipo asignado corresponde al tipo de la variable
//		int index = 0;
//		while(attr[i]->children[index] != NULL && strcmp(attr[i]->children[index]->token,"="))
//		{
//			index++;
//		}

//		index++;

//		if(attr[i]->children[index] != NULL && (
//			getExpressionType(attr[i]->children[index], scopeNode) != "int32" && !strcmp(variableType, "int")||
//			getExpressionType(attr[i]->children[index], scopeNode) != "char" && !strcmp(variableType, "char")||
//			getExpressionType(attr[i]->children[index], scopeNode) != "float32" && !strcmp(variableType, "float")||
//			getExpressionType(attr[i]->children[index], scopeNode) != "bool" && !strcmp(variableType, "boolean")
//			))
//		{
//			semanticErrors = true;
//			stringstream ss;
//			ss << "Line " << attr[i]->getLine() << ": Type mismatch at declaration.\n";	
//			errors.push_back(new class Error(ss.str(), attr[i]->getLine()));
//			continue;
//		}
		//fin revision error de tipo			


		attrSymbol->visibility = vis;
		attrSymbol->scope = scopeNode->scopeNum;
		attrSymbol->type = (char*)"ATTRIBUTE";
		attrSymbol->value = (char*)"NULL";	
		scopeNode->AddSymbol(attrSymbol);
		symbolTable->Insert(attrSymbol);
		currentClass->attributes.push_back(attrSymbol);
		classNode->symbols.push_back(attrSymbol);
		
	}
}

void writeFieldCil(Node *node)
{
	for(int i = 0; i < node->symbols.size(); i++)
	{
		Attribute * attrSymbol = (Attribute*) node->symbols[i];
		
		cil << insertTabs(getScopeByNum(attrSymbol->scope, scopeInic)) << ".field " << getVis(attrSymbol->visibility) << javaTypeToCil(attrSymbol->variableType);
		
		cil << " ";
		cil << 	attrSymbol->id << endl;
	}
}

bool isPrimitiveType(Node *node)
{
	if(!strcmp(node->token, "PrimitiveType") || !strcmp(node->token, "NumericType") || !strcmp(node->token, "IntegralType"))
	{
		return true;
	}
	else return false;
}

bool isArrayType(Node *node)
{
	if(!strcmp(node->token, "ArrayType"))
		return true;
	else
		return false;
}

//Recibe un nodo cuyo token es <Type>, "void" o <ArrayType>
char * getType(Node * node)
{
	if(!strcmp(node->token, "ArrayType"))
	{
		if(isPrimitiveType(node->children[0]))
		{
			stringstream ss;
			return node->children[0]->leafValue();
		}
		else
		{
			//REVISAR: NUMERO DE LINEA
			stringstream ss;
			ss << "$Error(" << node->children[0]->getLine() << ")" << ": Arrays may only be of primitive type.\n" << endl;
			errors.push_back(new class Error(ss.str(), node->children[0]->getLine()));
		}
	}
	else
	{
		if(!strcmp(node->token, "void"))
			return node->token;
		node = node->children[0];
		
		return node->token;
	}
	
}

//Recibe un nodo cuyo token es un <Name>
char * getName(Node* node) 
{
	if(!strcmp(node->children[0]->token, "QualifiedName"))
	{
		//<name>.identifier
		return strcat(strcat(getName(node->children[0]->children[0]), node->children[0]->children[1]->token), node->children[0]->children[2]->token);
	}
	else //name solo tiif(!strcmp(children[0]->token, "Modifiers")) //Then it has a modifier
	{
		return node->children[0]->token;
	}
}

//Recibe un nodo cuyo token es un <PrimitiveType>
char * getPrimitiveType(Node* node)
{
	if(!strcmp(node->children[0]->token, "NumericType"))
	{
		if(!strcmp(node->children[0]->children[0]->token, "IntegralType")) 
			return node->children[0]->children[0]->children[0]->token; //int o char
		else //float
			return node->children[0]->children[0]->token;
	}
	else //boolean
		return node->children[0]->token;
}

//Cuenta la cantidad de variables que se estan declarando al mismo tiemp
//ej: int a, b, c;
int countVariablesDeclared(Node* node)
{
	int num = 1; //At least one VariableDeclarator.

	while(!strcmp(node->children[0]->token, "VariableDeclarators")) //Checks if there are more 
	{
		num++; //For each variableDeclarators we have at least one VariableDeclarator
		node = node->children[0];
		if(!strcmp(node->children[0]->token, "Identifier"))
			num++;
	}
	if(!strcmp(node->children[0]->token, "VariableDeclarator"))
	{
		int i = node->children[0]->children[0]->numChildren;
		num += i/3 + 1;
	}

	//printf(" al inicio count:: node->token %s node->children[0]->token %s\n", node->token, node->children[0]->token);
	/*Node* temp = node->children[0];
	if(!strcmp(node->token, "VariableDeclarators") && !strcmp(temp->token, "VariableDeclarator"))
	{
		int i = node->numChildren;
		num += i - i/3 -1;
		
	}
	else if(!strcmp(node->token, "VariableDeclarators") && !strcmp(temp->token, "Identifier"))
	{
		num++;
	}
	else{

	while(!strcmp(node->children[0]->token, "VariableDeclarators")) //Checks if there are more 
	{
		//num++;
		printf("en el while: node->token %s node->children[0]->token %s \n      node->children[0]->children[0]->token %s\n", node->token, node->children[0]->token, node->children[0]->children[0]->token);		
		if(!strcmp(node->children[0]->children[0]->token, "Identifier") && node->children[0]->numChildren == 3 )
		{
			printf("sumo aqui1\n");
			num+=2; 
		}
		

		node = node->children[0];
		if(!strcmp(node->children[0]->token, "Identifier") && node->parent->numChildren == 1)
		{
			printf("sumo aqui3\n");
			num++;
		}
		else if(!strcmp(node->children[0]->token, "VariableDeclarators"))
		{
			printf("sumo aqui4\n");
			num++;
		}
		else if(!strcmp(node->children[0]->token, "VariableDeclarator"))
		{
			printf("sumo aqui5\n");
			num++;
		}
		if(!strcmp(node->children[0]->token, "VariableDeclarator") && node->children[0]->numChildren > 1 && !strcmp(node->children[2]->token, "VariableDeclarator")) //Para cuando las variables se inicializan entremedio int a =2, f=3;
		{
			printf("sumo aqui2\n");
			num++;
		}

	}

printf("node->token %s node->children[2]->token %s\n", node->token, node->children[2]->token);

	if(!strcmp(node->token, "LocalVariableDeclaration") && !strcmp(node->children[2]->token, "VariableDeclarator"))
	{
		//printf("entro en aqui 123\n");
		int numChildren = node->numChildren;
		num += numChildren-1; ///-1 porque ya contamos unos al principio
	}*/
//}
	return num;
}


string insertTabs(ScopeNode *currentScope)
{	
	string str;
	while(currentScope->scopeNum != scopeInic->scopeNum)
	{
		currentScope = currentScope->dad;
		str = str + "\t";
	}
	
	return str;
}

//Recibe un nodo cuyo token es un VariableDeclarators
//Retorna un arreglo de nodos VariableDeclarators.

bool existsClass(char * classId, int numScope)
{
	if(symbolTable->exists(classId, numScope))
		return true;
	else return false;
}

void AddModifiersError(int numLine)
{
	semanticErrors = true;	
	stringstream ss;
	ss << "Line " << numLine << ": Use of multiple modifiers is not allowed.\n";
	errors.push_back(new class Error(ss.str(), numLine));
}

void analizeClassSymbol(Node *classNode, ScopeNode * scopeNode)
{	
	ClassSymbol * classSymbol = new ClassSymbol();
	classNode->symbol = classSymbol;
	currentClass = classSymbol;
	Node ** children = classNode->children;
	Node * modifiers = children[0];
	Node * classIdentifier = children[2];
	Node * super = NULL;
	Node * classBody = NULL;
	
	//cout << "Node : " << classIdentifier->token << endl;
	if(existsClass(classIdentifier->leafValue(), scopeInic->scopeNum))
	{
		semanticErrors = true;	
		stringstream ss;
		ss << "$Error(" << classIdentifier->children[0]->getLine() << ")" << ": Class " << classIdentifier->leafValue() << " has been previously declared. Inside code will be ignored.\n";
		errors.push_back(new class Error(ss.str(), classIdentifier->children[0]->getLine()));
		currentClass = NULL;
		
		return;
	}
	
	classSymbol->numLine = classIdentifier->children[0]->getLine();
	
	if(modifiers->numChildren != 1) //Tiene más de un modifier
	{
		AddModifiersError(classIdentifier->children[0]->getLine());
	}
	
	if(classNode->numChildren == 4) //No extiende de otras, ergo no tiene super como hijo
		classBody = children[3];
	else if(classNode->numChildren == 5) //Si extiende de otras clases.
	{
		super = children[3];
	
		if(!strcmp(super->children[1]->token, "Identifier"))
		{
			classSymbol->base = super->children[1]->leafValue();
			classSymbol->hasBase = true;
		}
		else
		{
			stringstream ss;
			ss << "$Error(" << super->line << "): Qualified names are not allowed for class inheritance.\n";
			errors.push_back(new class Error(ss.str(), super->line));
			currentClass = NULL;
			markErrorsDFS(classNode);
			return;
		}
		classBody = children[4];
	}
	
	//Extracción del class Modifiers
	enum Visibility vis = getModifier(modifiers);
	
	//printf("Llega aqui\n");
	classSymbol->visibility = vis;
	classSymbol->id = classIdentifier->leafValue();
	classSymbol->scope = scopeNode->scopeNum;
	classSymbol->type = (char*)"CLASS";
	classSymbol->englobingScope = numScope+1;
	scopeNode->AddSymbol(classSymbol);
	symbolTable->Insert(classSymbol); // Insertamos el símbolo en la tabla de hash
	
}

void writeClassCil(Node *node)
{
	ClassSymbol * classSymbol = (ClassSymbol*) node->symbol;
	currentClass = classSymbol;
	cil << ".class ";
	cil << getVis(classSymbol->visibility);

	cil << classSymbol->id;
	if(classSymbol->hasBase)
	{
		cil << " extends " << classSymbol->base;
	}
	cil << endl;
	currentClassScope = classSymbol->englobingScope;
}

int countParameters(Node *node)
{
	int numParams = 1;
	while(!strcmp(node->token, "FormalParameterList"))
	{
		numParams++;
		node = node->children[0];
	}
	return numParams;
}


void analizeMethodSymbol(Node *methodNode, ScopeNode * scopeNode)
{
	Method * methodSymbol = new Method();
	methodNode->symbol = methodSymbol;
	
	currentClass->AddMethod(methodSymbol);
	
	currentMethod = methodSymbol;
	methodSymbol->methodType = METHOD;
	Node ** children = methodNode->children;	//Deberían siempre ser <MethodHeader><MethodBody>
	Node * methodHeader = children[0];	//<MethodHeader>
	Node * modifier;
	Node * methodIdentifier;
	Node * returnType;
	Node * methodDeclarator;
	Node * formalParameters;
	bool usoIndiscriminadoModifiers = false;
	ScopeNode * methodScope = scopeNode;
	bool isMain = false;
	
	if(methodHeader->numChildren == 2) //TipoRetorno, MethodDeclarator
	{			
		returnType = methodHeader->children[0];	
		methodDeclarator = methodHeader->children[1];
		modifier = NULL;
	}
	else if(methodHeader->numChildren == 3)	//Modifier, TipoRetorno, MethodDeclarator
	{
		if(!strcmp(methodHeader->children[0]->token,"Modifiers")) //Uso indiscriminado de modifiers
		{
			usoIndiscriminadoModifiers = true;
			modifier = methodHeader->children[0]->children[0];
		}
		else
			modifier = methodHeader->children[0];	//<Modifier>

		returnType = methodHeader->children[1];	
		methodDeclarator = methodHeader->children[2];
	}	
	
	
	methodSymbol->visibility = getModifier(modifier);		
	//printf("Visibility: %d\n", methodSymbol->visibility);
	int bracketCount = 0;
	//Vemos el número de brackets.
	
	
	while(!strcmp(methodDeclarator->children[0]->token, "MethodDeclarator"))
	{
		methodDeclarator = methodDeclarator->children[0];
		bracketCount++;
	}

	
	methodIdentifier = methodDeclarator->children[0];
	methodSymbol->id = methodIdentifier->leafValue();
	currentMethod->line = methodIdentifier->children[0]->getLine();
	
	if(usoIndiscriminadoModifiers)
	{
		semanticErrors = true;	
		stringstream ss;
		ss << "Line " << methodIdentifier->children[0]->getLine() << ": Method " << methodSymbol->id << " has too many modifiers.\n";	
		errors.push_back(new class Error(ss.str(), methodIdentifier->children[0]->getLine()));
	}

	//Revisamos si ya hay un método main.
	if(!strcmp(methodSymbol->id, "main"))
	{
		if(mainFound)
		{
			semanticErrors = true;	
			stringstream ss;
			ss << "Line " << methodIdentifier->children[0]->getLine() << ": Method main has already been declared.\n";	
			errors.push_back(new class Error(ss.str(), methodIdentifier->children[0]->getLine()));
		}
		else
		{
			if(methodSymbol->visibility == PUBLIC && returnType->numChildren == 0 && methodDeclarator->numChildren == 3)
			{				
				mainFound = true;
				methodSymbol->isMain = true;
			}
			else
			{
				semanticErrors = true;	
				stringstream ss;
				ss << "Line " << methodIdentifier->children[0]->getLine() << ": Method main must be of visibility public, return type void and have no parameters.\n";	
			errors.push_back(new class Error(ss.str(), methodIdentifier->children[0]->getLine()));
		}
			
		}
		
	}

	methodSymbol->returnType = getType(returnType);
	if(isArrayType(returnType))
	{
		int length = strlen(methodSymbol->returnType)+4;
		char * type2 = new char[length];
		type2[length-1] = '\0';
		sprintf(type2, "%s%s", methodSymbol->returnType, "[]");
		methodSymbol->returnType = type2;
	}
	
	//cout << "Return type of method " << methodSymbol->id << ": " << methodSymbol->returnType << endl;
	
	
	//Procesamiento de scopes
	methodSymbol->scope = scopeNode->dad->scopeNum;	
	methodSymbol->englobingScope = numScope;
	scopeNode->dad->AddSymbol(methodSymbol);
				
	methodSymbol->type = (char*)"METHOD";
	
	
	if(methodDeclarator->numChildren == 3)
	{
		parametersToAnalyze = 0;
		methodSymbol->numParams = 0;
	}
	else
	{		

		parametersToAnalyze = countParameters(methodDeclarator->children[2]);
		methodSymbol->numParams = parametersToAnalyze;
		//AddParameterTypes(methodDeclarator->children[2]);


	}	
	
	if(symbolTable->exists(methodSymbol->id, methodSymbol->scope))
	{		
		Method * otherMethod = (Method *)symbolTable->Find(methodSymbol->id, methodSymbol->scope);
//		if(!strcmp(otherMethod->returnType, methodSymbol->returnType))
		cout << "Se detecta otro método con el mismo nombre: " << methodSymbol->id << endl;
		if(!otherMethod->AddOverload(methodSymbol))
		{
			semanticErrors = true;	
			stringstream ss;

			ss << "$Error(" << methodIdentifier->children[0]->getLine() << "): There is already a method with name " << methodIdentifier->leafValue() << " with same parameter types.\n";

			errors.push_back(new class Error(ss.str(), methodIdentifier->children[0]->getLine()));
		}
//		}
//		else
//		{
//			semanticErrors = true;	
//			stringstream ss;
//			ss << "Line " << methodIdentifier->children[0]->getLine() << ": overload of method " << methodIdentifier->leafValue() << " must be of same return type as original method.\n";
//			errors.push_back(new class Error(ss.str(), methodIdentifier->children[0]->getLine()));
//		}
		
	}
	else
	{	
		symbolTable->Insert(methodSymbol); // Insertamos el símbolo en la tabla de hash
	}
	
	
	
	
}

void writeMethodCil(Node * node)
{
	
	Method * methodSymbol = (Method*) node->symbol;
	ScopeNode *scopeNode = getScopeByNum(methodSymbol->scope, scopeInic);
	currentMethod = methodSymbol;
	if(methodSymbol->isMain)
	{	
		cil << insertTabs(scopeNode) << ".method static public void main() cil managed" << endl;
		//cil << insertTabs(methodScope) << ".entrypoint"
		
		
		cil<< insertTabs(scopeNode)  << "{"<< endl;	
		
		if(mainFound && !mainInstructionsAdded)
		{
			mainInstructionsAdded = true;
			cil << insertTabs(scopeNode->children[0]) << ".entrypoint" << endl;
			cil <<  insertTabs(scopeNode->children[0]) << ".maxstack 10" << endl;
		}	
		
	}
	else
	{
			//Agregamos el codigo al archivo cil.
		cil << insertTabs(scopeNode) << ".method ";
		cil << getVis(methodSymbol->visibility); //visibilidad
		cil << "instance ";  //porque no hay metodos estaticos
		cil << javaTypeToCil(methodSymbol->returnType); //retorno
		cil << " ";
		cil << methodSymbol->id; //nombre
		cil << "(";
		parametersToAnalyze = methodSymbol->numParams;
		if(parametersToAnalyze == 0)
		{
			cil << ") cil managed" << endl;
			
			cil << insertTabs(scopeNode)  << "{"<< endl;	
		}	
		if(strcmp(methodSymbol->returnType, "void"))
		{
			expectingReturn = true;
		}
		else
		{
			writeExplicitRet = true;
		}
		
	
		
	}
			


}

void AddParameterTypes(Node * node)
{	
	while(!strcmp(node->token, "FormalParameterList"))
	{
		currentMethod->paramInfo.push_back(node->children[2]->children[0]->leafValue());
		node = node->children[0];
	}
	
	currentMethod->paramInfo.push_back(node->children[0]->leafValue());	
}		


//Recibe un <ConstructorDeclaration>
void analyzeConstructorSymbol(Node * consNode, ScopeNode *scopeNode)
{	
	ScopeNode *conScope = scopeNode;
	Method * conSymbol = new Method();
	consNode->symbol = conSymbol;
	conSymbol->methodType = CONSTRUCTOR;
	conSymbol->returnType = (char*)"void";
	currentClass->AddConstructor(conSymbol);
	currentMethod = conSymbol;
	Node ** children = consNode->children;	
	Node * modifier;
	Node * constructorDeclarator;
	Node * formalParameters;
	bool usoIndiscriminadoModifiers = false;
	Node * consBody;
	
	conSymbol -> returnType = (char*)"void";
	if(consNode->numChildren == 2)
	{
		modifier = NULL;
		constructorDeclarator = children[0];
		consBody = consNode->children[1];
		
	}
	else
	{
		if(!strcmp(children[0]->token,"Modifiers")) //Uso indiscriminado de modifiers
		{
			usoIndiscriminadoModifiers = true;
			modifier = children[0]->children[0];
		}
		else
			modifier = children[0];	//<Modifier>

		consBody = consNode->children[2];
		constructorDeclarator = children[1];
	}
	
	int line = constructorDeclarator->children[0]->children[0]->getLine();
	conSymbol->id = constructorDeclarator->children[0]->leafValue();
	conSymbol->line = constructorDeclarator->children[0]->children[0]->getLine();
	if(strcmp(conSymbol->id, currentClass->id))
	{
		semanticErrors = true;	
		int line = constructorDeclarator->children[0]->children[0]->getLine();
		stringstream ss;
		ss << "Line " << line << ": Constructor name must be the same as Class name: " << currentClass->id << ".\n";
		
		//ss << currentClass->id << ".\n";
		//printf("Line %d: Constructor name must be the same as Class name: %s.\n",
		errors.push_back(new class Error(ss.str(), line));
	}

	if(usoIndiscriminadoModifiers)
	{
		semanticErrors = true;	
		stringstream ss;
		ss << "Line " << line<< ": Method " << conSymbol->id << " has too many modifiers.\n";	
		errors.push_back(new class Error(ss.str(), line));
	}
	
	conSymbol->visibility = getModifier(modifier);
	//Visibilidad del constructor:
	//printf("\n\nVisibilidad constructor: %d\n\n", (int)conSymbol->visibility);	
	int* asdf = 0;
	vector<Parameter *> params;
	int numParams;
	
	//Procesamiento de scopes
	conSymbol->scope = scopeNode->dad->scopeNum;	
	conSymbol->englobingScope = numScope;
	scopeNode->dad->AddSymbol(conSymbol);
	
	conSymbol->type = (char*)"CONSTRUCTOR";
	//symbolTable->Insert(conSymbol); // Insertamos el símbolo en la tabla de hash
	
	
	//Hacemos análisis de parámetros.
	if(constructorDeclarator->numChildren == 3)
	{
		conSymbol->numParams = 0;
		parametersToAnalyze = 0;
	}
	else
	{	
		parametersToAnalyze = countParameters(constructorDeclarator->children[2]);
		conSymbol->numParams = countParameters(constructorDeclarator->children[2]);	
	
	}	
	
	
	if(symbolTable->exists(conSymbol->id, conSymbol->scope))
	{		
		Method * otherCon = (Method *)symbolTable->Find(conSymbol->id, conSymbol->scope);
//		if(!strcmp(otherCon->returnType, conSymbol->returnType))
//		{	
			if(!otherCon->AddOverload(conSymbol))
			{
				semanticErrors = true;	
				stringstream ss;
				ss << "$Error(" << line << "): There is already a constructor with name " << conSymbol->id << " with same parameter types.\n";
				errors.push_back(new class Error(ss.str(), line));
			}
//		}
//		else
//		{
//			semanticErrors = true;	
//			stringstream ss;
//			ss << "Line " << line << ": overload of constructor " << conSymbol->id << " must be of same return type as original method.\n";
//			errors.push_back(new class Error(ss.str(), line));
//		}
		
	}
	else
	{
		symbolTable->Insert(conSymbol); // Insertamos el símbolo en la tabla de hash
	}
	
	//Al setear este flag NO se escribirá el constructor por defecto.
	currentClass->hasExplicitConstructor = true;
	
	//Vemos, ahora, si se llama explícitamente a otro constructor adentro.
	if(consBody->numChildren == 3) // { <ExplicitConstructorInvocation> } | { <BlockStmts> }
	{
		if(!strcmp(consBody->children[1]->token, "ExplicitConstructorInvocation"))
		{
			conSymbol -> hasExplicitConInv = true;
			
		}
	}
	else if(consBody->numChildren == 4)	// { <ExplicitConstructorInvocation> < BlockStmts > }
	{

		conSymbol->hasExplicitConInv = true;
		
	}
	
}

ScopeNode * getScopeByNum(int numScope, ScopeNode* actual)
{

	if(actual->scopeNum == numScope) 
	{	
		return actual;
	}
	ScopeNode * found = NULL;
	//printf("Scope %d has %d children\n", actual->scopeNum, actual->numChildren);
	for(int i = 0; i < actual->numChildren; i++)
	{
		//printf("Getting child %d of scope %d\n", i, actual->scopeNum);
		found = getScopeByNum(numScope, actual->children[i]);
		if(found != NULL) return found;
	}
	return NULL;
}

void writeConstructorCil(Node *node)
{
	Method * conSymbol = (Method*) node->symbol;
	currentMethod = conSymbol;
	cil << insertTabs(getScopeByNum(conSymbol->scope, scopeInic));
	cil << ".method " << getVis(conSymbol->visibility) << "instance void .ctor(";
	parametersToAnalyze = conSymbol->numParams;
	if(parametersToAnalyze == 0)
		cil << ") cil managed" << endl;
}

bool isClass(char * type)
{
	if(!strcmp(type, "int") || !strcmp(type, "float") || !strcmp(type, "char") || !strcmp(type, "boolean")
	 || !strcmp(type, "int[]") || !strcmp(type, "float[]") || !strcmp(type, "char[]") || !strcmp(type, "boolean[]")
	)
		return false;
	else return true;
}

//Recibe un nodo cuyo token es <FormalParameter>
void  analyzeParameterSymbol(Node * paramNode, ScopeNode *scopeNode)
{
	
	//printf("Se recibio un: %s\n", paramNode->token);
	Parameter * paramSymbol = new Parameter();
	paramNode->symbol = paramSymbol;
	
	paramSymbol->paramType = getType(paramNode->children[0]); //Extraemos el tipo
	
	//printf("Tipo de parametro: %s\n", paramSymbol->paramType);
	
	Node * variableDeclaratorId = paramNode->children[1];
	int numDimensions = 0;
	if(isArrayType(paramNode->children[0]))
	{
		numDimensions = 1;
		int length = strlen(paramSymbol->paramType) + 4;
		char * type2 = new char[length];
		type2[length-1] = '\0';
		sprintf(type2, "%s%s", paramSymbol->paramType, "[]");
		paramSymbol->paramType = type2;
	}
	
	
//	while(!strcmp(variableDeclaratorId->token, "VariableDeclaratorId"))
//	{
//		variableDeclaratorId = variableDeclaratorId->children[0];
//		numDimensions++;
//	}
	
	
	//Posible error: los arreglos solo pueden ser int, float, char o boolean
	if(numDimensions > 0 && strcmp(paramSymbol->paramType, "int32") && strcmp(paramSymbol->paramType, "float32") && strcmp(paramSymbol->paramType, "char") && strcmp(paramSymbol->paramType, "bool"))
	{
		semanticErrors = true;	
		int line = variableDeclaratorId->children[0]->getLine();
		stringstream ss; //REVISAR
//		ss << "Line " << line << ": Check type of array named '" << variableDeclaratorId->leafValue() 
//		<< "', arrays may only be of type int, float, char or boolean. Array declared was of type " << paramSymbol->paramType << "\n";
//		errors.push_back(new class Error(ss.str(), line));
		//printf("Line %d: Revisa el tipo de '%s', los arreglos solo pueden ser de tipo int, float, char o boolean\n", variableDeclaratorId->children[0]->getLine(), variableDeclaratorId->leafValue());
	}

	//La única posibilidad es que haya otro parémetro en el MISMO método
	if(symbolTable->Find(variableDeclaratorId->leafValue(), scopeNode->scopeNum) != NULL)
	{
		stringstream ss;
		ss << "$Error(" << variableDeclaratorId->children[0]->line << "): Parameter " << variableDeclaratorId->leafValue() << " has already been declared." << endl;
		errors.push_back(new class Error(ss.str(), variableDeclaratorId->children[0]->line));
		return;
	}

	paramSymbol->id = variableDeclaratorId->leafValue();
	paramSymbol->numDimensions = numDimensions;
	paramSymbol->type = (char*)"PARAMETER";
	paramSymbol->scope = scopeNode->scopeNum;
	scopeNode->AddSymbol(paramSymbol);
	currentMethod->AddParameter(paramSymbol);
	symbolTable->Insert(paramSymbol); // Insertamos el símbolo en la tabla de hash
	
}

void writeParamCil(Node *node)
{

	Parameter * paramSymbol = (Parameter*) node->symbol;
	//ya está :method.... ( , falta completar el resto
//	if(isClass(paramSymbol->paramType))
//		methodCil << "class ";
	methodCil << javaTypeToCil(paramSymbol->paramType);
	parametersToAnalyze--;
	methodCil << " " << paramSymbol->id;

	if(parametersToAnalyze != 0)
		methodCil << ", ";
	else
	{
		methodCil << ") cil managed" << endl;
		cil << methodCil.str();
		if(!strcmp(currentMethod->type, "METHOD"))
			cil << insertTabs(getScopeByNum(currentMethod->scope, scopeInic)) << "{" << endl;
		methodCil.str("");
		
		
	}
}

bool isLocalVarDeclared(Node *node, ScopeNode *scopeNode)
{
	Symbol *sym = findSymbolDFS(node, scopeNode);
	if(sym != NULL)
	{
		if(!strcmp(sym->type, "VARIABLE") || !strcmp(sym->type, "PARAMETER"))
		{
			return true;
		}
	}
	return false;
}

void markErrorsDFS(Node *node)
{
	node->skipAnalysis = true;
	
	for(int i = 0; i < node->numChildren; i++)
	{
		markErrorsDFS(node->children[i]);
	}
}

//Recibe un <LocalVariableDeclaration>
void analyzeLocalVarDeclarationSymbol(Node * localVarDeclaration, ScopeNode *scopeNode)
{	
	//Hay al menos una variable.
	int numVariables = 1;
	

	//<LocalVariableDeclaration> => <Type> <LocalVariableDeclarators>
	Node * typeNode = localVarDeclaration -> children[0]; 	
	Node *tmp = localVarDeclaration->children[1];

	if(strcmp(typeNode->children[0]->token, "int") &&
strcmp(typeNode->children[0]->token, "IntegralType") &&
strcmp(typeNode->children[0]->token, "char") &&
strcmp(typeNode->children[0]->token, "CharLiteral") &&
strcmp(typeNode->children[0]->token, "float") &&
strcmp(typeNode->children[0]->token, "FloatingPointLiteral") &&
strcmp(typeNode->children[0]->token, "NumericType") &&
strcmp(typeNode->children[0]->token, "boolean") &&
strcmp(typeNode->children[0]->token, "TrueOrFalse") &&
symbolTable->Find(typeNode->children[0]->token, scopeInic->scopeNum) == NULL)
	{
		semanticErrors = true;
		stringstream ss;
		ss << "Line " << localVarDeclaration->getLine() << ": '"<< typeNode->children[0]->token  <<"' cannot be resolved to a type, try declaring it as a class.\n";	
		errors.push_back(new class Error(ss.str(), localVarDeclaration->getLine()));
 
	}
	char * type = getType(typeNode); //Obtenemos el tipo de la variable.
	int length = strlen(type)+4;
	
	
	//REVISAR: CUIDADO CON LOS DUMP...
	char * type2 = new char[length];
	type2[length-1] = '\0';
	
	bool isArray = isArrayType(typeNode);
	
	if(isArray) 
	{
		sprintf(type2, "%s%s", type, "[]");
//		for(int i = 0; i < length; i++)
//		{	
//			cout << type2[i] << " ";
//		}
//		cout << " length " << length << endl;
		type = type2;
	}

	int numDimensions;
	
	if(isArray)
		numDimensions = 1;
	else
		numDimensions = 0;

	while(!strcmp(tmp->token, "VariableDeclarators"))
	{
		numVariables++;			
		Node* otherChild = tmp->children[2];
		
		//Si hay un variableDeclator, entonces hay un "algo = algomas"
		if(!strcmp(otherChild->token, "VariableDeclarator"))
		{				
			Variable * varSymbol = new Variable();
			
//			Node * declaratorId = otherChild->children[0];
//			int numDimensions = 0;
//			while(!strcmp(declaratorId->token, "VariableDeclaratorId"))
//			{	
//				declaratorId = declaratorId->children[0];
//				numDimensions++;
//			}				
//			

			
			if(isLocalVarDeclared(otherChild->children[0]->children[0], scopeNode))
			{
				markErrorsDFS(otherChild);
				stringstream ss;
				ss << "$Error(" << otherChild->children[0]->children[0]->getLine() << "): Redeclaration of local variable " << otherChild->children[0]->leafValue() << endl;
				errors.push_back(new class Error(ss.str(), otherChild->children[0]->children[0]->getLine()));
				tmp = tmp->children[0];
				continue;
			}
				
			//Para ver si el tipo asignado corresponde al tipo de la variable
			int index = 0;
			while(otherChild->children[index] != NULL && otherChild->children[index]->token != "=")
			{
				index++;
			}
			index++;

			if(otherChild->children[index] != NULL && !strcmp(otherChild->children[index]->token, "Identifier") && findSymbolDFS(otherChild->children[index], scopeNode) == NULL)
		{
			semanticErrors = true;
			stringstream ss;
			ss << "Line " << otherChild->getLine() << ": '" << otherChild->children[index]->children[0]->token << "' cannot be resolved, try declaring it.\n";	
			errors.push_back(new class Error(ss.str(), otherChild->getLine()));
			return;
		}
		else if(otherChild->children[index] != NULL && strcmp(tmp->children[index]->token, "Identifier") &&  (
getExpressionType(otherChild->children[index], scopeNode) != "int32" && !strcmp(type, "int")||
getExpressionType(otherChild->children[index], scopeNode) != "char" && !strcmp(type, "char")||
getExpressionType(otherChild->children[index], scopeNode) != "float32" && !strcmp(type, "float")||
getExpressionType(otherChild->children[index], scopeNode) != "bool" && !strcmp(type, "boolean")
))
			if(typeNode->token != otherChild->children[index]->token)
			{
				semanticErrors = true;
				stringstream ss;
				ss << "Line " << otherChild->getLine() << ": Type mismatch at declaration.\n";	
				errors.push_back(new class Error(ss.str(), otherChild->getLine()));
				tmp = tmp->children[0];
				continue;
			}
			//fin revision error de tipo
				
			varSymbol->id = otherChild->children[0]->leafValue();
			varSymbol->scope = scopeNode->scopeNum;
	
			varSymbol->type = (char*)"VARIABLE";
			varSymbol->variableType = type;
							
			varSymbol->numDimensions = numDimensions;
			varSymbol->value = (char*)"NULL";		
			scopeNode->AddSymbol(varSymbol);
			symbolTable->Insert(varSymbol); // Insertamos el símbolo en la tabla de hash
		
			cil << insertTabs(scopeNode) << ".locals init (" << javaTypeToCil(varSymbol->variableType);
				
			cil <<" "<< varSymbol->id << ")\n";
				

			analyzeExpr(otherChild->children[2], scopeNode);
			storing = true;
			loadCilVariable(otherChild->children[0], scopeNode, true);
			storing = false;
			cil << postStrings.top();
			postStrings.pop();
		}
		else
		{
			//printf("Llega aqui\n");
			Variable * varSymbol = new Variable();
			
//			Node * declaratorId = otherChild;
//			int numDimensions = 0;
//			while(!strcmp(declaratorId->token, "VariableDeclaratorId"))
//			{	
//				declaratorId = declaratorId->children[0];
//				numDimensions++;
//			}		
				


	
			if(isLocalVarDeclared(otherChild->children[0], scopeNode))
			{
				markErrorsDFS(otherChild);
				stringstream ss;
				ss << "$Error(" << otherChild->children[0]->getLine() << "): Redeclaration of local variable " << otherChild->leafValue() << endl;
				errors.push_back(new class Error(ss.str(), otherChild->children[0]->getLine()));
				tmp = tmp->children[0];
				continue;
			}
				
			//Para ver si el tipo asignado corresponde al tipo de la variable
			int index = 0;
			while(otherChild->children[index] != NULL && otherChild->children[index]->token != "=")
			{
				index++;
			}
			index++;

			if(otherChild->children[index] != NULL && !strcmp(otherChild->children[index]->token, "Identifier") && findSymbolDFS(otherChild->children[index], scopeNode) == NULL)
		{
			semanticErrors = true;
			stringstream ss;
			ss << "Line " << otherChild->getLine() << ": '" << otherChild->children[index]->children[0]->token << "' cannot be resolved, try declaring it.\n";	
			errors.push_back(new class Error(ss.str(), otherChild->getLine()));
			return;
		}
		else if(otherChild->children[index] != NULL && strcmp(tmp->children[index]->token, "Identifier") && (
getExpressionType(otherChild->children[index], scopeNode) != "int32" && !strcmp(type, "int")||
getExpressionType(otherChild->children[index], scopeNode) != "char" && !strcmp(type, "char")||
getExpressionType(otherChild->children[index], scopeNode) != "float32" && !strcmp(type, "float")||
getExpressionType(otherChild->children[index], scopeNode) != "bool" && !strcmp(type, "boolean")
))
			{
				semanticErrors = true;
				stringstream ss;
				ss << "Line " << otherChild->children[index]->getLine() << ": Type mismatch at declaration.\n";	
				errors.push_back(new class Error(ss.str(), otherChild->children[index]->getLine()));
				tmp = tmp->children[0];
				continue;
			}
			//fin revision error de tipo

			varSymbol->id = otherChild->leafValue();
			varSymbol->scope = scopeNode->scopeNum;
	
			varSymbol->type = (char*)"VARIABLE";
			varSymbol->variableType = type;
			varSymbol->value = (char*)"NULL";
			varSymbol->numDimensions = numDimensions;
			scopeNode->AddSymbol(varSymbol);
			symbolTable->Insert(varSymbol); // Insertamos el símbolo en la tabla de hash
			cil << insertTabs(scopeNode) << ".locals init (" << javaTypeToCil(varSymbol->variableType);
			
			cil <<" "<< varSymbol->id << ")\n";

				
		}
		tmp = tmp->children[0];
			
	}
	
	if(!strcmp(tmp->token, "VariableDeclarator"))
	{
		Variable * varSymbol = new Variable();

//		Node * declaratorId = tmp->children[0];
//		int numDimensions = 0;
//		while(!strcmp(declaratorId->token, "VariableDeclaratorId"))
//		{	
//			declaratorId = declaratorId->children[0];
//			numDimensions++;
//		}				

		
		if(isLocalVarDeclared(tmp->children[0]->children[0], scopeNode))
		{
			markErrorsDFS(tmp);
			stringstream ss;
			ss << "$Error(" << tmp->children[0]->children[0]->getLine() 
			<< "): Redeclaration of local variable " << tmp->children[0]->leafValue() << endl;
			errors.push_back(new class Error(ss.str(), tmp->children[0]->children[0]->getLine()));
			return;
		}		

		//Para ver si el tipo asignado corresponde al tipo de la variable
		int index = 0;
		while(tmp->children[index] != NULL && strcmp(tmp->children[index]->token,"="))
		{
			index++;
		}

		index++;

		if(tmp->children[index] != NULL && !strcmp(tmp->children[index]->token, "Identifier") && findSymbolDFS(tmp->children[index], scopeNode) == NULL)
		{
			semanticErrors = true;
			stringstream ss;
			ss << "Line " << tmp->getLine() << ": '" << tmp->children[index]->children[0]->token << "' cannot be resolved, try declaring it.\n";	
			errors.push_back(new class Error(ss.str(), tmp->getLine()));
			return;
		}
		else if(tmp->children[index] != NULL && strcmp(tmp->children[index]->token, "Identifier") && (
getExpressionType(tmp->children[index], scopeNode) != "int32" && !strcmp(type, "int")||
getExpressionType(tmp->children[index], scopeNode) != "char" && !strcmp(type, "char")||
getExpressionType(tmp->children[index], scopeNode) != "float32" && !strcmp(type, "float")||
getExpressionType(tmp->children[index], scopeNode) != "bool" && !strcmp(type, "boolean")
))
		{
			semanticErrors = true;
			stringstream ss;
			ss << "Line " << tmp->getLine() << ": Type mismatch at declaration.\n";	
			errors.push_back(new class Error(ss.str(), tmp->getLine()));
			return;
		}
		//fin revision error de tipo			
cout << tmp->children[2]->token << " asda2" << endl;
		varSymbol->id = tmp->children[0] -> leafValue();
		varSymbol->scope = scopeNode->scopeNum;
		varSymbol->type = (char*)"VARIABLE";
		varSymbol->variableType = type;
		varSymbol->numDimensions = numDimensions;
				
		varSymbol->value = (char*)"NULL";		
		scopeNode->AddSymbol(varSymbol);
		symbolTable->Insert(varSymbol); // Insertamos el símbolo en la tabla de hash
			
		cil << insertTabs(scopeNode) << ".locals init (" << javaTypeToCil(varSymbol->variableType);
				
		cil <<" "<< varSymbol->id << ")\n";
				
			
		/*if(strcmp(tmp->children[2]->token, "PostIncrementExpr") && strcmp(tmp->children[2]->token, "PostDecrementExpr"))*/
cout << tmp->children[2]->token << " asda" << endl;
		analyzeExpr(tmp->children[2], scopeNode);
		/*else //Solo cargamos la variable
			analyzeExpr(tmp->children[2]->children[0], scopeNode);*/
			
		storing = true;
		loadCilVariable(tmp->children[0], scopeNode, true);
		storing = false;
		cil << postStrings.top();
		postStrings.pop();

		/*if(!strcmp(tmp->children[2]->token, "PostIncrementExpr") || !strcmp(tmp->children[2]->token, "PostDecrementExpr"))
				analyzeExpr(tmp->children[2], scopeNode);*/
	}
	else
	{
		Variable * varSymbol = new Variable();
//			Node * declaratorId = tmp;
//			int numDimensions = 0;
//			while(!strcmp(declaratorId->token, "VariableDeclaratorId"))
//			{	
//				declaratorId = declaratorId->children[0];
//				numDimensions++;
//			}				

		if(isLocalVarDeclared(tmp->children[0], scopeNode))
		{
			markErrorsDFS(tmp);
			stringstream ss;
			ss << "$Error(" << tmp->children[0]->getLine() << "): Redeclaration of local variable " << tmp->leafValue() << endl;
			errors.push_back(new class Error(ss.str(), tmp->children[0]->getLine()));
			return;
		}	
		
		varSymbol->id = tmp->leafValue();
		varSymbol->scope = scopeNode->scopeNum;

		varSymbol->type = (char*)"VARIABLE";
		varSymbol->variableType = type;
		varSymbol->numDimensions = numDimensions;
		varSymbol->value = (char*)"NULL";
		scopeNode->AddSymbol(varSymbol);
		symbolTable->Insert(varSymbol); // Insertamos el símbolo en la tabla de hash
			
		cil << insertTabs(scopeNode) << ".locals init (" << javaTypeToCil(varSymbol->variableType);
			
		cil <<" "<< varSymbol->id << ")\n";
				
			
	}

	
	
		
//		if(localVarDeclared(var, scopeNode))
//		{	
//			int line;
//				line = var->getLine();
//				
//							
//			stringstream ss;
//			ss << "Line " << line << ": There is already a local variable with id " << var->token << " declared.\n";
//			errors.push_back(new class Error(ss.str(), line));
//			continue;
//		}
//		
		

//		//Posible error: los arreglos solo pueden ser int, float, char o boolean
//		if(varSymbol->numDimensions > 0 && strcmp(varSymbol->variableType, "int") && strcmp(varSymbol->variableType, "float") && strcmp(varSymbol->variableType, "char") && strcmp(varSymbol->variableType, "boolean"))
//		{
//			stringstream ss;
//			int line = var->getLine();
//			ss << "Line " << line << ": Check type of array named '" << varSymbol->id << "', arrays may only be of type int, float, char or boolean.\n";
//			errors.push_back(new class Error(ss.str(), line));
//			//printf("Line %d: Revisa el tipo de '%s', los arreglos solo pueden ser de tipo int, float, char o boolean\n", var->getLine(), varSymbol->id);
//		}
//		
		//printf("variable: %s, parent: %s\n", var->token, var->parent->token);

//		if(var->numChildren > 0)
//		//if(!strcmp(var->parent->parent->token, "VariableDeclarator"))
//		{
//			

//			varSymbol->value = var->children[0]->token;
//			
//			
//		}
//		else
//		{	
//			//printf("La variable no esta inicializada, asignando valor por defecto\n");
//			if(varSymbol->numDimensions == 0)
//			{
//				varSymbol->value = defaultValue(varSymbol->variableType);
//				inicializado = false;
//			}
//			else
//				varSymbol->value = (char*)"NULL";
//		}

		


//		if(inicializado && !strcmp(varSymbol->variableType, "int"))
//		{
//			cil << insertTabs(scopeNode) << "ldc.i4 " << varSymbol->value << "\n";
//			cil << insertTabs(scopeNode) << "stloc " << varSymbol->id <<  "\n";
//		}
//		else if(inicializado && !strcmp(varSymbol->variableType, "float"))
//		{
//			cil << insertTabs(scopeNode) << "ldc.r4 " << varSymbol->value << "\n";
//			cil << insertTabs(scopeNode) << "stloc " << varSymbol->id <<  "\n";
//		}
//		else if(inicializado && !strcmp(varSymbol->variableType, "char"))
//		{
//			cil << insertTabs(scopeNode) << "ldc.i4 " << (int)varSymbol->value[1] << "\n";
//			cil << insertTabs(scopeNode) << "stloc " << varSymbol->id <<  "\n";
//		}
//		else if(inicializado && !strcmp(varSymbol->variableType, "boolean"))
//		{
//			if(!strcmp(varSymbol->value, "true"))
//				cil << insertTabs(scopeNode) << "ldc.i4 1\n";
//			else
//				cil << insertTabs(scopeNode) << "ldc.i4 0\n";
//			cil << insertTabs(scopeNode) << "stloc " << varSymbol->id <<  "\n";
//		}
			
	

 //printf("llego al final de localvardec\n");

}

void checkCorrectFormat(char* type, char* valueType, int line, char* id)
{

//printf("type: %s, valueType: %s, line: %i, id: %s\n", type, valueType, line, id);

	bool rightType = false;

	if(!strcmp(type, "int"))
	{
		if(!strcmp(valueType, "IntegerLiteral"))
			rightType = true;		
	}
	else if(!strcmp(type, "float"))
	{
		if(!strcmp(valueType, "Float"))
			rightType = true;		
	}
	else if(!strcmp(type, "char"))
	{
		if(!strcmp(valueType, "CharLiteral"))
			rightType = true;		
	}
	else if(!strcmp(type, "boolean"))
	{
		if(!strcmp(valueType, "Boolean"))
			rightType = true;		
	}
	else
		return;
	
	if(!rightType)
	{
		semanticErrors = true;	
		stringstream ss;
		ss << "Line " << line << ": Check the assigned value of '" << id << "', the current value does not match its type.\n";
		errors.push_back(new class Error(ss.str(), line));
	}
}

char* defaultValue (char* type)
{
	if(!strcmp(type, "int"))
		return (char*)"0";
	else if(!strcmp(type, "float"))
		return (char*)"0.0";
	else if(!strcmp(type, "char"))
		return (char*)"'0'";
	else if(!strcmp(type, "boolean"))
		return (char*)"false";
	else
		return (char*) "NULL";
}

//Recibe un nodo cuyo token es un modifier
Visibility getModifier(Node * mod)
{
		
		if(mod == NULL) return PROTECTED; //Por defecto...
		char * modifierString;
		
		if(!strcmp(mod->token, "Modifiers"))	//Si recibimos un <Modifiers>...
		{
			if(mod->children[0]->numChildren != 1)	//<Modifiers> => <Modifiers><Modifier>, no es lógico
			{
				printf("Error, multiple modifiers found. Protected by default\n");
				modifierString = (char*)"protected";
			}				
			else 	//<Modifiers>=><Modifier>=>valor->token
			{
				modifierString = mod->children[0]->children[0]->leafValue();
			}
		}
		else	//Recibimos un <Modifier>
		{
			modifierString = mod->children[0]->token; //<modifier>->hijo->token
		}	
		
		if(!strcmp(modifierString, "public"))
			return PUBLIC;
		else if(!strcmp(modifierString, "protected"))
			return PROTECTED;
		else 
			return PRIVATE;
}



/*
void analyzeTree(Node *actual)
{
	if(actual == NULL) return;
	char* token = actual->token;
	//printf("Token: %s\n", token);
	if(!strcmp(token, "ClassDeclaration"))
	{
		analizeClassSymbol(actual);
		return;
	}
	
	for(int i = 0; i < actual->numChildren; i++)
	{
		analyzeTree(actual->children[i]);
	}
	
}
*/
void print(Node * node, string pre, int depth)
{
	if(node == NULL) return;
	int i;
	stringstream ss;
	ss << pre << node-> token;
	string s = ss.str();
	//<<  " - " << node -> numChildren
	cout << s  << endl;
	if(node->numChildren == 0) return;
	
	for(i = 0; i < node->numChildren; i++)
	{
		Node* child = node->children[i];
		if(child != NULL)
		{
			print(child, pre + "   ", depth+1);
		}
	}
}
/*
Node ** getExprIdentifiers(Node *exprStmt, ScopeNode *scopeNode)
{
}*/

//Revisa si el Símbolo con id node->token existe en el scope actual o alguno de sus padres.
bool existsSymbolDFS(Node *node, ScopeNode *scopeNode, bool checkType)
{
	while(scopeNode->dad != NULL)
	{
		if(symbolTable->exists(node->token, scopeNode->scopeNum))
			return true;
		scopeNode = scopeNode->dad;
	}
	
	//printf("Line %d: La variable '%s' ha sido usada pero no ha sido declarada previamente.\n", node->getLine(), node->token);
	if(strcmp(node->parent->parent->token, "QualifiedName"))
{
	semanticErrors = true;	
	int line = node->getLine();
	stringstream ss;
	ss << "Line " << line << ": Variable '" << node->token << "' has been used but has not been previously declared.\n";
	errors.push_back(new class Error(ss.str(), line));
		}
	return false;
}

bool localVarDeclared(Node *node, ScopeNode *scopeNode)
{
	
	while(scopeNode->dad != NULL)
	{
		//printf("Checking if local var %s exists in scope %d\n", node->token, scopeNode->scopeNum);
		if(symbolTable->exists(node->token, scopeNode->scopeNum))
		{
			Symbol* sym = symbolTable->Find(node->token, scopeNode->scopeNum);
			if(!strcmp(sym->type, "VARIABLE"))
			{
				return true;
			}
		}
		scopeNode = scopeNode->dad;
	}
	return false;
}

ClassSymbol * getScopeClass(ScopeNode * scopeNode)
{
	
	if(scopeNode != NULL)
	{		
		while(scopeNode->dad != NULL)
		{
			
			//Es el caso en que estoy en el scope de una clase.
			if(scopeNode->dad->scopeNum == scopeInic->scopeNum)
			{
			
				
				for(int i = 0; i < scopeInic->numSymbols; i++)
				{
					//Veo a cuál clase corresponde ese scope.
					if(scopeInic->children[i]->scopeNum == scopeNode->scopeNum)
					{						
						ClassSymbol * foundClass = (ClassSymbol*)scopeInic->symbols[i];
						
						return foundClass;
					}
				}
			}
			scopeNode = scopeNode->dad;
		}
		return NULL;
	}
	return NULL;
}

Symbol * findSymbolDFS(char * token, int scopeNum, char * type)
{
	ScopeNode * scopeNode = getScopeByNum(scopeNum, scopeInic);
	ScopeNode * tmp = scopeNode;
	
	while(scopeNode->dad != NULL)
	{
		if(symbolTable->exists(token,scopeNum))
		{
			Symbol *sym = symbolTable->Find(token, scopeNode->scopeNum);
			if(!strcmp(sym->type, type))			
				return symbolTable->Find(token, scopeNode->scopeNum);
		}
		scopeNode = scopeNode->dad;
	}
	ClassSymbol * scopeClass = getScopeClass(tmp);
	while(scopeClass != NULL)
	{	
		Symbol *sym = symbolTable->Find(token, scopeClass->englobingScope);	
		
		if(sym != NULL && !strcmp(sym->type, type) )
		{
			return sym;
		}
		if(scopeClass->hasBase)
			scopeClass = scopeClass->baseClass;
		else
			break;
	}
	return NULL;
}

Symbol * findSymbolDFS(Node *node, ScopeNode *scopeNode, char* type)
{
	ScopeNode * tmp = scopeNode;
	
	while(scopeNode->dad != NULL)
	{
		if(symbolTable->exists(node->token, scopeNode->scopeNum))
		{
			Symbol *sym = symbolTable->Find(node->token, scopeNode->scopeNum);
			if(!strcmp(sym->type, type))			
				return symbolTable->Find(node->token, scopeNode->scopeNum);
		}
		scopeNode = scopeNode->dad;
	}
	ClassSymbol * scopeClass = getScopeClass(tmp);
	while(scopeClass != NULL)
	{	
		Symbol *sym = symbolTable->Find(node->token, scopeClass->englobingScope);	
		
		if(sym != NULL && !strcmp(sym->type, type) )
		{
			return sym;
		}
		if(scopeClass->hasBase)
			scopeClass = scopeClass->baseClass;
		else
			break;
	}
	return NULL;
}
//Revisa si el Símbolo con id node->token existe en el scope actual o alguno de sus padres.
Symbol* findSymbolDFS(Node *node, ScopeNode *scopeNode)
{
	ScopeNode * tmp = scopeNode;
	//cout << "Attempting to find node " << node->token << " in scope " << scopeNode->scopeNum << endl;
	while(scopeNode->dad != NULL)
	{
		if(symbolTable->exists(node->token, scopeNode->scopeNum))
			return symbolTable->Find(node->token, scopeNode->scopeNum);
		scopeNode = scopeNode->dad;
	}
	
	ClassSymbol * scopeClass = getScopeClass(tmp);
	
	while(scopeClass != NULL && scopeClass->hasBase)
	{	
		Symbol *sym = symbolTable->Find(node->token, scopeClass->englobingScope);		
		if(sym != NULL)
			return sym;
	
		if(scopeClass->hasBase)
			scopeClass = scopeClass->baseClass;
		else
			break;
	}
	return NULL;
}

//Revisa si todos los Id que derivan de node están previamente declarados (DFS!!)
bool checkIdentifierDecl(Node *node, ScopeNode *scopeNode)
{
	bool success = true;
	//printf("checking %s\n", node->token);
	if(!strcmp(node->token, "MethodInvocation"))
		return success;
	if(!strcmp(node->token, "Identifier"))	//Encontramos <Identifier>
	{
		
		if(!existsSymbolDFS(node->children[0], scopeNode, false))
			success = false;	
	}
	for(int i = 0; i < node->numChildren; i++)
	{
		if(!checkIdentifierDecl(node->children[i], scopeNode)) success = false;
	}
	return success;
}

//Escribe la condicion del if en CIL
void ifThenToCil(Node *node, ScopeNode *scopeNode)
{
	//printf("ENTRO AL IFTHENTOCIL\n");
	if(!strcmp(node->children[2]->token, "RelationalExpr") | !strcmp(node->children[2]->token, "EqualityExpr"))
	{
		node = node->children[2];
		bool cmp = relationalExprToCil(node, scopeNode); //Ahora es un relationalExpr
		if(cmp)
			cil << insertTabs(scopeNode) << "brfalse END_IF_"<< ifCount << endl;
		else
			cil << "END_IF_"<< ifCount << endl;
	}
	else if(!strcmp(node->children[2]->token, "Identifier"))
	{
		Node * child = node->children[2];
		loadCilVariable(child, scopeNode, false);
		cil << insertTabs(scopeNode) << "brfalse END_IF_"<< ifCount << endl;
	}

	else
	{
		analyzeExpr(node->children[2], scopeNode);//cil << "ALGO ANDUVO MAL EN EL IFTHENTOCIL" << node->children[2]->token ;
		cil << insertTabs(scopeNode) << "brfalse END_IF_"<< ifCount << endl;
	}
}

//Escribe la condicion del if en CIL
void ifThenElseToCil(Node *node, ScopeNode *scopeNode)
{
	//printf("ENTRO AL IFTHENELSETOCIL\n");
	if(!strcmp(node->children[2]->token, "RelationalExpr") | !strcmp(node->children[2]->token, "EqualityExpr"))
	{
		node = node->children[2];
		bool cmp = relationalExprToCil(node, scopeNode); //Ahora es un relationalExpr
		if(cmp)
			cil << insertTabs(scopeNode) << "brfalse ELSE_BODY_"<< elseCount << endl;
		else
			cil << "ELSE_BODY_"<< elseCount << endl;
	}
	else if(!strcmp(node->children[2]->token, "Identifier"))
	{
		Node * child = node->children[2];
		loadCilVariable(child, scopeNode, false);
		cil << insertTabs(scopeNode) << "brtrue ELSE_BODY_"<< elseCount << endl;
	}
	else
	{
//cil << node->token << " hijo: " << node->children[0]->token << endl;
		analyzeExpr(node->children[2], scopeNode);//cil << "ALGO ANDUVO MAL EN EL IFTHENELSETOCIL";
		cil << insertTabs(scopeNode) << "brfalse ELSE_BODY_"<< elseCount << endl;
	}
}

string generateRelLabel()
{
	stringstream ss;
	ss << relationLabel << relationCounter;
	relationCounter++;
	return ss.str();
}
void whileToCil(Node *node, ScopeNode *scopeNode)
{
	cil << endl << insertTabs(scopeNode->dad) << "WHILE_CONDITION_" << whileCount <<":" << endl;
	if(!strcmp(node->children[2]->token, "RelationalExpr") | !strcmp(node->children[2]->token, "EqualityExpr"))
	{
		node = node->children[2];
		bool cmp = relationalExprToCil(node, scopeNode); //Ahora es un relationalExpr
		if(cmp)
			cil << insertTabs(scopeNode) << "brfalse END_WHILE_"<< whileCount << endl;
		else
			cil << "END_WHILE_"<< whileCount << endl;
	}
	else if(!strcmp(node->children[2]->token, "Identifier"))
	{
		Node * child = node->children[2];
		loadCilVariable(child, scopeNode, false);
		cil << insertTabs(scopeNode) << "brfalse END_WHILE_"<< whileCount << endl;
	}
	else
	{
		
		analyzeExpr(node->children[2], scopeNode);//cil << "ALGO ANDUVO MAL EN EL WHILETOCIL";
		cil << insertTabs(scopeNode) << "brfalse END_WHILE_"<< whileCount << endl;
	}
}

void forToCil(Node *node, ScopeNode *scopeNode)
{
	bool condition = false;
	int numPuntoComa = 0; //Cuenta cuantos punto y coma se han encontrado
	for(int i =0; i < node->numChildren; i++)
	{
		Node * child = node->children[i];
		char* token = child->token;

		if(!strcmp(token, ")")) //se termina de hacer el update
		{
			cil << insertTabs(scopeNode) << "br FOR_CONDITION_" << forCount << endl;
			cil << insertTabs(scopeNode) << "FOR_BODY_" << forCount << ":" <<endl;
			return;
		}
		else if(!strcmp(token, "RelationalExpr") | !strcmp(token, "EqualityExpr"))
		{	
			bool cmp = relationalExprToCil(child, scopeNode); //Ahora es un relationalExpr
			if(cmp)
				cil << insertTabs(scopeNode) << "brfalse END_FOR_"<< forCount << endl;
			else
				cil << "END_FOR_"<< forCount << endl;
		}
		else if(numPuntoComa == 1 && !strcmp(token, "ConditionalOrExpr"))
		{	
			analyzeExpr(child, scopeNode);
			cil << insertTabs(scopeNode) << "brfalse END_FOR_"<< forCount << endl;
		}
		else if(!strcmp(token, "LocalVariableDeclaration")) 
		{
			analyzeLocalVarDeclarationSymbol(child, scopeNode);
		}
		else if(!strcmp(token, ";") && numPuntoComa == 0) //Corresponde a la declaracion o asignacion del "indice" del for
		{
			numPuntoComa++;
			if(!condition)
			{
				cil << insertTabs(scopeNode) << "FOR_CONDITION_" << forCount << ":" << endl;
				condition = true;
			}
		}
		else if(!strcmp(token, ";") && numPuntoComa == 1) //Corresponde a la declaracion o asignacion del "indice" del for
		{
			numPuntoComa++;
			//cil << insertTabs(scopeNode) << "brfalse END_FOR_"<< forCount << endl;
			cil << insertTabs(scopeNode) << "br FOR_BODY_" << forCount << endl;
			cil << insertTabs(scopeNode) << "FOR_UPDATE_" << forCount << ":" <<endl;
		}
		else if (strcmp(token,"for") && strcmp(token, "(") && strcmp(token, ";"))
		{
			 analyzeExpr(child, scopeNode);
		}
		else if  (strcmp(token,"for") && strcmp(token, "("))
		{
			cil << "ALGO ANDUVO MAL EN EL FORTOCIL, token: " << token << endl;
		}
	}
}

//Se le entrega el nodo que contiene el token while, su HERMANO es un openParentesis y su siguiente HERMANO es la condicion que hay dentro del while.
void doToCil(Node * node, ScopeNode* scopeNode)
{
	//Al colocar esto al cierre del DO-WHILE se DEBE usar doNode->getNum() en lugar de doCount

	node = node->parent;
	for(int i = 0; i < node->numChildren; i++)
	{
		Node* child = node->children[i];
		if(!strcmp(child->token, "while"))
			node = node->children[i+2];
	}
	//Ahora node es el nodo que contiene la condicion del while

	cil << endl << insertTabs(scopeNode->dad) << "DO_CONDITION_" << doNode->getNum() <<":" << endl;
	if(!strcmp(node->token, "RelationalExpr") | !strcmp(node->token, "EqualityExpr"))
	{
		bool cmp = relationalExprToCil(node, scopeNode);
		if(cmp)
			cil << insertTabs(scopeNode) << "brfalse END_DO_"<< doNode->getNum() << endl;
		else
			cil << "END_FOR_"<< doNode->getNum() << endl;
		
		cil << insertTabs(scopeNode) << "br DO_" << doNode->getNum() << endl;
		//cil << insertTabs(scopeNode->dad) << "END_DO_" << doNode->getNum() << ":" <<endl;
	}
	else if(!strcmp(node->token, "Identifier"))
	{
		//Node * child = node->children[2];
		loadCilVariable(node, scopeNode, false);
		cil << insertTabs(scopeNode) << "brfalse END_DO_"<< doNode->getNum() << endl;
		cil << insertTabs(scopeNode) << "br DO_" << doNode->getNum() << endl;
		
	}
	else
	{
		analyzeExpr(node, scopeNode);
		cil << insertTabs(scopeNode) << "brfalse END_DO_"<< doNode->getNum() << endl;
		cil << insertTabs(scopeNode) << "br DO_" << doNode->getNum() << endl;
		
		//cil << "ALGO ANDUVO MAL EN EL DOTOCIL" << node->token <<endl;
	}

}
void switchToCil(Node *node, ScopeNode *scopeNode)
{
	//cil << endl << insertTabs(scopeNode->dad) << "WHILE_CONDITION_" << whileCount <<":" << endl;
	/*if(!strcmp(node->children[2]->token, "RelationalExpr") | !strcmp(node->children[2]->token, "EqualityExpr"))
	{
		node = node->children[2];
		bool cmp = relationalExprToCil(node, scopeNode); //Ahora es un relationalExpr
		if(cmp)
			cil << insertTabs(scopeNode) << "brfalse END_WHILE_"<< whileCount << endl;
		else
			cil << "END_WHILE_"<< whileCount << endl;
	}
	else */if(!strcmp(node->children[2]->token, "Identifier") | !strcmp(node->children[1]->token, "IntegerLiteral") | !strcmp(node->children[1]->token, "CharLiteral") | !strcmp(node->children[1]->token, "TrueOrFalse") |  !strcmp(node->children[1]->token, "FloatingPointLiteral"))
	{
		Node * child = node->children[2];
		loadCilVariable(child, scopeNode, false);
	}
	else if(!strcmp(node->children[2]->token, "Assignment"))
	{

		Node * child = node->children[2];
		child->visited = false;
		for(int i = 0; i < child->numChildren; i++)
			child->children[i]->visited = false;

		analyzeExpr(child, scopeNode);
	}
	else
	{
		analyzeExpr(node, scopeNode);
		//cil << "ALGO ANDUVO MAL EN EL SWITCHTOCIL "<<node->token<< endl;
	}
}

void caseToCil(Node *node, Node *swNode, ScopeNode *scopeNode)
{
//cil << swNode->token <<endl;
	switchToCil(swNode, scopeNode);
	if(!strcmp(node->children[1]->token, "Identifier"))
	{
		Node * child = node->children[1];
		loadCilVariable(child, scopeNode, false);
	}
	else if(!strcmp(node->children[1]->token, "Assignment"))
	{
		Node * child = node->children[1];
		analyzeExpr(child, scopeNode);
	}
	else if(!strcmp(node->children[1]->token, "IntegerLiteral") | !strcmp(node->children[1]->token, "CharLiteral") | !strcmp(node->children[1]->token, "TrueOrFalse") |  !strcmp(node->children[1]->token, "FloatingPointLiteral"))
	{
		loadCilValue(node->children[1], scopeNode);
	}
	else
	{
		analyzeExpr(node, scopeNode);
		//cil << "ALGO ANDUVO MAL EN EL CASETOCIL " << node->children[1]->token <<endl;
	}

	cil<< insertTabs(scopeNode) <<  "ceq" <<endl;
	cil << insertTabs(scopeNode) << "brfalse END_SWITCH_" << switchNode->getNum() << "_CASE_" << caseNode->getNum() << endl;
	
}

void analyzeRelationalExpr(Node * node, ScopeNode* scopeNode)
{
	//printf("ENTRO AL RelationalExpr, node: %s\n", node->token);
	analyzeExpr(node->children[0], scopeNode);
	analyzeExpr(node->children[2], scopeNode);

char * token = node->children[1]->leafValue(); //Relacion->token

	if(!strcmp(token, ">"))
		cil<< insertTabs(scopeNode) <<  "cgt";
	else if(!strcmp(token, "<"))
		cil<< insertTabs(scopeNode) <<  "clt";
	else if(!strcmp(token, "=="))
		cil<< insertTabs(scopeNode) <<  "ceq";
	else if(!strcmp(token, "!="))
	{
		string label = generateRelLabel();
		string end = generateRelLabel();
		
		cil << insertTabs(scopeNode) << "beq " << label << endl;		
		cil << insertTabs(scopeNode) << "ldc.i4 " << "1" << endl;
		cil << insertTabs(scopeNode) << "br " << end << endl;
		cil << insertTabs(scopeNode) << label << ":" << endl;
		cil << insertTabs(scopeNode) << "ldc.i4 " << "0" << endl;
		cil << insertTabs(scopeNode) << end << ":" << endl;
	}
	else if(!strcmp(token, ">="))
	{		
		string label = generateRelLabel();
		string end = generateRelLabel();
		
		cil << insertTabs(scopeNode) << "bge " << label << endl;		
		cil << insertTabs(scopeNode) << "ldc.i4 " << "0" << endl;
		cil << insertTabs(scopeNode) << "br " << end << endl;
		cil << insertTabs(scopeNode) << label << ":" << endl;
		cil << insertTabs(scopeNode) << "ldc.i4 " << "1" << endl;
		cil << insertTabs(scopeNode) << end << ":" << endl;
		
		//cil<< insertTabs(scopeNode) <<  "clt" << endl; //branch if less than
		//cil << insertTabs(scopeNode) << "neg" << endl;
	}
	else if(!strcmp(token, "<="))
	{
	
		string label = generateRelLabel();
		string end = generateRelLabel();
		
		cil << insertTabs(scopeNode) << "ble " << label << endl;		
		cil << insertTabs(scopeNode) << "ldc.i4 " << "0" << endl;
		cil << insertTabs(scopeNode) << "br " << end << endl;
		cil << insertTabs(scopeNode) << label << ":" << endl;
		cil << insertTabs(scopeNode) << "ldc.i4 " << "1" << endl;
		cil << insertTabs(scopeNode) << end << ":" << endl;
		//cil<< insertTabs(scopeNode) <<  "cgt" << endl; //branch if greater than
		//cil << insertTabs(scopeNode) << "neg" << endl;
	}
	else
		cil << "ALGO ANDUVO MAL EN LA COMPARACION";

	cil<< endl;
}

bool relationalExprToCil(Node * node, ScopeNode* scopeNode)
{
	//printf("ENTRO AL RelationalExpr, node: %s\n", node->token);
	for(int i = 0; i < 3; i = i+2)
	{
		Node * child = node->children[i];
		if(!strcmp(child->token, "Identifier"))
		{
			loadCilVariable(child, scopeNode, false);			
		}
		else  //Es un valor a comparar
			loadCilValue(child, scopeNode);
			
	}

	Node * child = node->children[1]->children[0]; //Relacion->token

	if(!strcmp(child->token, ">"))
		cil<< insertTabs(scopeNode) <<  "cgt ";
	else if(!strcmp(child->token, "<"))
		cil<< insertTabs(scopeNode) <<  "clt ";
	else if(!strcmp(child->token, "=="))
		cil<< insertTabs(scopeNode) <<  "ceq ";
	else if(!strcmp(child->token, "!="))
	{
		cil<< insertTabs(scopeNode) <<  "beq ";
		return false;
	}
	else if(!strcmp(child->token, ">="))
	{
		cil<< insertTabs(scopeNode) <<  "blt "; //branch if less than, needs a label to branch to
		return false;
	}
	else if(!strcmp(child->token, "<="))
	{
		cil<< insertTabs(scopeNode) <<  "bgt "; //branch if greater than, needs a label to branch to
		return false;
	}
	else
		cil << "ALGO ANDUVO MAL EN LA COMPARACION";

	cil<< endl;
	return true;


}
//Recibe un <ExprStmt> como parámetro
void analyzeExprStmt(Node *node, ScopeNode *scopeNode)
{
	checkIdentifierDecl(node, scopeNode);
if(!strcmp( node->children[0]->token, "Assignment"))
{
	Node *exprType = node->children[0]; //assignment
	if(exprType->children[0] != NULL)  //identifier
		exprType = exprType->children[0];
	if(exprType->children[0] != NULL && !strcmp(exprType->children[0]->token, "QualifiedName") )  //el obj
		exprType = exprType->children[0]->children[0];
	else if(exprType->children[0] != NULL  )  //el obj
		exprType = exprType->children[0];

	//Revisamos que los identifiers usados hayan sido previamente declarados.
	if(findSymbolDFS(exprType, scopeNode) == NULL && strcmp(exprType->children[0]->token, "this") && strcmp(exprType->parent->token, "QualifiedName"))
	{
		semanticErrors = true;
		stringstream ss;
		ss << "Line " << exprType->children[0]->getLine() << ": '" << exprType->children[0]->token << "' cannot be resolved, try declaring it as a variable.\n";	
		errors.push_back(new class Error(ss.str(), exprType->getLine()));
	}
}
	
}

//Hace los chequeos BFS: Esto es, uso y declaración de métodos
//y clases
void checkBFS()
{
	//primero revisaremos las herencias de las clases. Sabemos que si hay clases,
	//están en el scope 0.
	for(int i = 0; i < scopeInic->numSymbols; i++)
	{
		ClassSymbol * classSymbol = (ClassSymbol*)scopeInic->symbols[i];
		if(classSymbol->hasBase)
		{
			if(!symbolTable->exists(classSymbol->base, scopeInic->scopeNum))
			{
				int line = classSymbol->numLine;
				stringstream ss;
				ss << "Line " << line << ": Class '" << classSymbol->id << "' inherits from non-declared class '" << classSymbol->base << "'.\n";
				semanticErrors = true;	
				errors.push_back(new class Error(ss.str(), line));
				//printf("Line %d: clase %s hereda de clase no declarada %s.\n", classSymbol->numLine, classSymbol->id, classSymbol->base);
			}
		}
	}
	
}
//Recibe un <MethodInvocation> como parámetro, y revisa si los Id entregados han sido declarados.
void analyzeInvocationDFS(Node *node, ScopeNode *scopeNode)
{
		
}

bool analyzeSystemCalls(Node *node, ScopeNode * scopeNode)
{
	
	
	Node* child0 = node->children[0];
	int numIdentifiers = 1;
	string str;
	
	//Si lo recibido no es un qualifiedname no puede ser un systemcall.
	if(strcmp(child0->token, "QualifiedName"))
	{
		return false;
	}
	while(!strcmp(child0->token, "QualifiedName"))
	{
		numIdentifiers++;
		str += child0->children[2]->leafValue();
		str += ".";
		child0 = child0->children[0];
	}
	
	str += child0->leafValue();
	//cout << str << endl;

	//Codigo CIL
	if( "println.out.System" == str)
	{	
		
		analyzeExpr(node->children[2], scopeNode);		
		
		string type = getExpressionType(node->children[2], scopeNode);
		cil<< insertTabs(scopeNode) << "call void [mscorlib]System.Console::WriteLine(" << type << ") \n";
		return true;

	}
	else if("print.out.System" == str)
	{
	
		analyzeExpr(node->children[2], scopeNode);	
		
		string type = getExpressionType(node->children[2], scopeNode);
		cil<< insertTabs(scopeNode) << "call void [mscorlib]System.Console::Write(" << type << ") \n";
		
		return true;
	}
	else if("read.in.System" == str)
	{
		//Si no utilizamos el valor...
		if(!strcmp(node->parent->token, "ExprStmt"))
		{

			return true;
		}
		
		cil<< insertTabs(scopeNode) << "call string [mscorlib]System.Console::ReadLine() \n";
		string varType = getExpressionType(node->parent, scopeNode);
		//cout << "varType 2: " << varType;
		if(varType == "int32")
		{
			cil << insertTabs(scopeNode)<< "call " <<  "int32" << " [mscorlib]System."<< "Int32" << "::Parse(string)\n";
		}
		else if(varType == "char")
		{
			cil << insertTabs(scopeNode)<< "call " <<  "char" << " [mscorlib]System."<< "Char" << "::Parse(string)\n";
		}
	
		
		return true;
	}
	
	return false;
}

ClassSymbol * analyzeMethodInvocation(Node * node, ScopeNode *scopeNode)
{
	if(!analyzeSystemCalls(node, scopeNode))
	{
		string params;
		params = "";
		vector<Node *> paramVector;
		char* methodName;
		Node *methodHolder;
		ClassSymbol * classHolder;		
			
		//Si lo primero es un qualifiedName...
		if(!strcmp(node->children[0]->token, "QualifiedName"))
		{			
		
			classHolder = analyzeQualifiedName(node->children[0], scopeNode, true);	
			methodName = node->children[0]->children[2]->leafValue();
			methodHolder = node->children[0]->children[2]->children[0];
		}
		//Es una llamada simple tipo holi();
		else if(!strcmp(node->children[0]->token, "Identifier"))
		{		

			cil << insertTabs(scopeNode) << "ldarg.0" << endl;
			//loadCilVariable(node->children[0]->children[0], scopeNode, false);
		
			methodName = node->children[0]->leafValue();
			methodHolder = node->children[0]->children[0];
			classHolder = currentClass;
		
		}
		else if(!strcmp(node->children[0]->token, "FieldAccess"))	//Puede ser un FieldAccess u otro.
		{
			//TODO: Double check on that bool...
			classHolder = analyzeFieldAcess(node->children[0], scopeNode, true);
			methodName = node->children[2]->leafValue();
			methodHolder = node->children[2]->children[0];
		
		}		
		else if(!strcmp(node->children[0]->token, "MethodInvocation"))
		{
			bool isStoring = storing;
			storing = false;
			classHolder = analyzeMethodInvocation(node->children[0], scopeNode);
			node->children[0]->visited = true;
			storing = isStoring;
			methodName = node->children[2]->leafValue();
			methodHolder = node->children[2]->children[0];
		}
		else if(!strcmp(node->children[0]->token, "ClassInstanceCreationExpr"))
		{
			analyzeExpr(node->children[0], scopeNode);
			classHolder = (ClassSymbol*)symbolTable->Find(node->children[0]->children[1]->leafValue(), scopeInic->scopeNum);			
			methodName = node->children[2]->leafValue();
			methodHolder = node->children[2]->children[0];
		}
		else if(!strcmp(node->children[0]->token, "PrimaryNoNewArray"))
		{
			//this
			if(node->children[0]->numChildren == 1)
			{
				classHolder = currentClass;
				cil << insertTabs(scopeNode) << "ldarg.0" << endl;
				methodName = node->children[2]->leafValue();
				methodHolder = node->children[2]->children[0];
			}
			//(Expr)
			else
			{
				analyzeExpr(node->children[0]->children[1], scopeNode);
				classHolder = getExpressionClass(node->children[0]->children[1], scopeNode, 0);
				methodName = node->children[2]->leafValue();
				methodHolder = node->children[2]->children[0];
			}
		}
		else if(!strcmp(node->children[0]->token, "super"))
		{
			if(currentClass->hasBase)
				classHolder = currentClass->baseClass;
			else
			{
				//REVISAR: ERROR.
			}
			cil << insertTabs(scopeNode) << "ldarg.0" << endl;
			methodName = node->children[2]->leafValue();
			methodHolder = node->children[2]->children[0];			
			Symbol * methodSym = findSymbolDFS(methodName, classHolder->englobingScope, (char*)"METHOD");
			
			while(classHolder->hasBase && methodSym == NULL)
			{
				classHolder = classHolder->baseClass;
				methodSym = findSymbolDFS(methodName, classHolder->englobingScope, (char*)"METHOD");
			}
			
		}
		
		string returnType = "void";
		Method * m = (Method*)(findSymbolDFS(methodName, classHolder->englobingScope, (char*)"METHOD"));
		if(m != NULL)
		{	
			returnType = javaTypeToCil(m->returnType);		
		}
		else
		{
			
			cout << "ERROR: METHOD TO CALL NOT FOUND: " << methodName << " in class " << classHolder->id <<  endl;
		}
		
		int argPosition;
		if(node->numChildren == 6)
			argPosition = 4;
		else if(node->numChildren == 4)
			argPosition = 2;
			
		
		if(node->numChildren == 4 || node->numChildren == 6)
		{
			Node * tmp = node->children[argPosition];
			params = analyzeFormalParameters(tmp, scopeNode);	
			
			cil << insertTabs(scopeNode) << "call instance " << returnType << " " << classHolder->id << "::" << 			methodName << "(";
			cil << params;
			
			cil << ")" << endl;
			if(returnType != "void" && node->parent->numChildren <= 2)
			{
				cil << insertTabs(scopeNode) << "pop" << endl;
			}		
		}		
		else 
		{
			cil << insertTabs(scopeNode) << "call instance " << returnType << " " << classHolder->id << "::" << methodName << "(";
			cil << ")" << endl;
			params = "";
			if(returnType != "void" && node->parent->numChildren <= 2)
			{
				cil << insertTabs(scopeNode) << "pop" << endl;			
			}
		}
		
//		Debemos revisar si el método en particular existe.
//		for(int i = 0; i < m->params.size(); i++)
//		{
//			cout << "Param " << i << ": " << m->params[i]->paramType << endl;
//			cout << "vector<param> " << i << ": " << params << endl;
//		}
	
		vector<string> splitParams = splitStr(params, " ");
//		for(int i = 0; i < splitParams.size(); i++)
//		{
//			splitParams[i] = javaTypeToCil((char*)splitParams[i].c_str());
//		}ana
//		v
		vector<string> newParams;
		for(int i = 0; i < splitParams.size(); i++)
		{
			if(splitParams[i] != "class")
			{
				if(splitParams[i].find("32") != string::npos)
				{
					newParams.push_back(splitParams[i].substr(0, splitParams[i].find("32")));
				}
				else
					newParams.push_back(splitParams[i]);
			}			
		}
		
		bool exists = m->ExistsOverload(newParams);
		if(exists)
		{
			if(returnType.find("class") != string::npos)
			{
				string className = returnType.substr(6);
				classHolder = (ClassSymbol*)symbolTable->Find((char*)className.c_str(), scopeInic->scopeNum);
			}
			return classHolder;
		}
		else
		{
			stringstream ss;
			ss << "$Error(" << methodHolder->line << "): Method with name " << methodName << " and parameters " << params << " does not exist." << endl;
			errors.push_back(new class Error(ss.str(), methodHolder->line));
			return NULL;
		}
	}

	return NULL;
}


string analyzeFormalParameters(Node *tmp, ScopeNode *scopeNode)
{
	vector <Node*> paramVector;
	string params;
	while(!strcmp(tmp->token, "ArgumentList"))
			{		
			
				if(params == "")
					params = params + getExpressionType(tmp->children[2], scopeNode);
				else
					params = getExpressionType(tmp->children[2], scopeNode) + ", " + params;
				
				paramVector.push_back(tmp->children[2]);	
				tmp = tmp->children[0];	
			
			}
		
			if(params == "")
				params = getExpressionType(tmp, scopeNode);
			else
				params = getExpressionType(tmp, scopeNode) + ", " + params;
		
			paramVector.push_back(tmp);
		
			//analyzeExpr(tmp, scopeNode);
		
			
			for(int i = paramVector.size() -1; i >= 0; i--)
			{
				analyzeExpr(paramVector[i], scopeNode);
			}
			
			return params;		
}

void analyzeUnaryExprNotPlusMinus(Node *node, ScopeNode *scopeNode)
{	
	//Hay una negación bitwise o lógica
	if(node->numChildren == 2)
	{
		Node *sign = node->children[0];
		if(!strcmp(sign->token, "!"))
		{
			string label = generateRelLabel();
			string end = generateRelLabel();
			analyzeExpr(node->children[1], scopeNode);
			cil << insertTabs(scopeNode) << "brtrue " << label << endl;
			cil << insertTabs(scopeNode) << "ldc.i4 1" << endl;
			cil << insertTabs(scopeNode) << "br " << end << endl;
			cil << insertTabs(scopeNode) << label << ":" << endl;
			cil << insertTabs(scopeNode) << "ldc.i4 0" << endl;
			cil << insertTabs(scopeNode) << end << ":" << endl; 
		}
		else if(!strcmp(sign->token, "~"))
		{			
			analyzeExpr(node->children[1], scopeNode);
			cil << insertTabs(scopeNode) << "not" << endl;
		}
	}	
}

void markVisitedDFS(Node *node)
{
	node->visited = true;
	for(int i = 0; i < node->numChildren; i++)
	{
		markVisitedDFS(node->children[i]);
	}
}

//Recibe un nodo el cual es el valor a asignar a una variable, ej> a = 3, es el nodo que contiene al 3
void loadCilValue(Node *node, ScopeNode *scopeNode)
{
	
	bool isAss = false;

	if(!strcmp("StringLiteral", node->token))
	{
cil<< insertTabs(scopeNode);
		cil << "ldstr " ;
	}
	else if(!strcmp("IntegerLiteral", node->token))
	{cil<< insertTabs(scopeNode);
		cil<< "ldc.i4 ";
	}
	else if(!strcmp("FloatingPointLiteral", node->token))
	{cil<< insertTabs(scopeNode);
		cil << "ldc.r4 "; 
	}
	else if(!strcmp("CharLiteral", node->token))
	{cil<< insertTabs(scopeNode);
		cil << "ldc.i4 " << (int)node->children[0]->token[1] << "\n";
		isAss = true;
	}
	else if(!strcmp("TrueOrFalse", node->token))
	{cil<< insertTabs(scopeNode);
		cil << "ldc.i4 "; 
		if(!strcmp(node->children[0]->token, "true"))
				cil <<"1" << endl;
		else
				cil <<"0" << endl;

		isAss = true;
	}
	else
	{

		//cil << "ALGO RARO EN LOADCILVALUE: "<< node->token <<endl;	
		analyzeExpr(node, scopeNode);
		isAss = true;
	}


	if(!isAss)
	{
		cil << node->children[0]->token << endl;
	}
}

//Esto siempre será un ldarg.
void loadCilVariableFields(Node *node, ScopeNode *scopeNode, ClassSymbol * classSymbol, bool store)
{
		Symbol * sym = findSymbolDFS(node->children[0], getScopeByNum(classSymbol->englobingScope, scopeInic), (char*)"ATTRIBUTE");
		if(sym == NULL)
		{
			printf("ERROR. Attempting to load variable field that does not exist: %s in %s\n", node->children[0]->token, classSymbol->id);
			return;
		}
		Attribute *attr = (Attribute *)sym;
		
		if(storing)
		{			
			postPend << insertTabs(scopeNode) << "stfld " << javaTypeToCil(attr->variableType) << " " << classSymbol->id <<"::" << attr->id << endl;
			postStrings.push(postPend.str());
			postPend.str("");
		}
		else //Mari
		{
			cil << insertTabs(scopeNode) << "ldfld " << javaTypeToCil(attr->variableType) << " " << classSymbol->id <<"::" << attr->id << endl;
		}	
}

//Recibe un nodo cuyo token es la variable, y carga el valor según lo que sea.
void loadCilVariable(Node *node, ScopeNode *scopeNode, bool store)
{

	//cil << "En load cilVariable: "<<node->token<<endl;
	//Es una variable local o atributo de esta clase
	if(!strcmp(node->token, "Identifier"))
	{
	//printf("Loading %s\n", node->leafValue());
	
		Symbol * sym =findSymbolDFS(node->children[0], scopeNode);
		
		if(sym != NULL)
		{
		  	
			if(!strcmp(sym->type, "ATTRIBUTE"))
			{
				Attribute * attr = (Attribute *) sym;
				cil << insertTabs(scopeNode) << "ldarg.0" << endl;
				if(storing | store)
				{
					postPend << insertTabs(scopeNode) << "stfld " << javaTypeToCil(attr->variableType) << " " << currentClass->id <<"::" << attr->id << endl;
					postStrings.push(postPend.str());
					postPend.str("");
				}
				else 
				{
					cil << insertTabs(scopeNode) << "ldfld " << javaTypeToCil(attr->variableType) << " " << currentClass->id <<"::" << attr->id << endl;
				}			
			}
			else if(!strcmp(sym->type, "VARIABLE"))
			{
				
				Variable *var = (Variable *) sym;
				if(storing | store)
				{
					
					postPend << insertTabs(scopeNode) << "stloc " << var->id << endl;
					
					postStrings.push(postPend.str());
					//cout << "PUSHING " << postStrings.top() << endl;
					postPend.str("");
				}
				else
				{
					if(storing) printf("SHould NOT store!!\n");
					cil << insertTabs(scopeNode) << "ldloc " << var->id << endl;
				}
			}
			else if(!strcmp(sym->type, "PARAMETER"))
			{
				//printf("It is a parameter, but it doesn't wanna load?\n");
				Parameter *param = (Parameter *) sym;
				if(storing | store)
				{
					postPend << insertTabs(scopeNode) << "starg " << param->id << endl;					
					postStrings.push(postPend.str());
					postPend.str("");
				}
				else
				{
					cil << insertTabs(scopeNode) << "ldarg " << param->id << endl;
				}
			}
			else
				printf("Error in loadCilVar: Symbol type not found, %s\n", node->leafValue());
		}
		else
		{
			semanticErrors = true;
			//El string del error se esta escribiendo en otra parte
			/*stringstream ss;
			ss << "Line " << node->getLine() << ": " << node->leafValue() << Cannot be resolved. Try declaring it in this scope.\n";	
			errors.push_back(new class Error(ss.str(), node->getLine()));*/
 
			postPend << insertTabs(scopeNode) << "there was a semantic error on your code" << endl;					
					postStrings.push(postPend.str());
					postPend.str("");
			printf("Error in loadCilVar: Symbol not found, %s, in scope %d\n", node->leafValue(), scopeNode->scopeNum);
		}
	}
	else if(!strcmp(node->token, "QualifiedName"))
	{
		
		ClassSymbol * tmpClass = currentClass;
		Node *tmp = node;
		vector<Node *> ids;
		//Si tenemos a.b.c.d...
		//entonces ids = [d, c, b, a]
		while(!strcmp(tmp->token, "QualifiedName"))
		{
			ids.push_back(tmp->children[2]);
			tmp = tmp->children[0];
		}
		ids.push_back(tmp);
					
		for(int i = ids.size()-1; i >= 0; i--)
		{
			loadCilVariable(ids[ids.size()-1], scopeNode, false); //Cargamos la primera letra en la secuencia
			tmpClass = (ClassSymbol*)(symbolTable->Find(ids[ids.size()-1]->token, scopeInic->scopeNum));			
		}
		
	}
	else
	{
		printf("Error, method loadCilVariable receive unexpected node with token %s\n", node->token);
		return;
	}	
}

char * getVariableType(Symbol *sym, char* type, bool strict)
{

	if(sym != NULL && strcmp(sym->type, "CLASS") && strcmp(sym->type, "METHOD") && strcmp(sym->type, "CONSTRUCTOR"))
	{		
		if(!strcmp(sym->type, "VARIABLE") && ( (strict && !strcmp(type, "VARIABLE")) || !strict)  )
		{
			Variable * var = (Variable *) sym;
			return var->variableType;
		}
		else if(!strcmp(sym->type, "PARAMETER") && ( (strict && !strcmp(type, "PARAMETER")) || !strict))
		{
			Parameter * var = (Parameter *) sym;
			return var->paramType;
		}
		else if(!strcmp(sym->type, "ATTRIBUTE") && ( (strict && !strcmp(type, "ATTRIBUTE")) || !strict))
		{
			Attribute * var = (Attribute *) sym;
			return var->variableType;
		}
	}
	else
	{
		cout << "ERROR: Must pass proper variable to getVariableType" << endl;
		return (char*)"";
	}
}

//Retorna la clase CORRESPONDIENTE al ÚLTIMO símbolo de getExpressionClass. Por ejemplo,
//Si se recibe un QualifiedName, el cual corresponde a
//a.b.c.d entonces retorna la clase a la que PERTENECE d (si d es tipo persona, etc etc).
//Si se recibe un método, se retorna la clase que RETORNA este método.
ClassSymbol * getExpressionClass(Node *node, ScopeNode *scopeNode, int depth)
{
	//Si recibimos un FieldAccess = <Algo>.id
	//Entonces primero vemos a qué tipo corresponde "Algo", luego buscamos analizamos el id.
	if(!strcmp(node->token, "FieldAccess"))
	{		
		ClassSymbol *tmp = getExpressionClass(node->children[0], scopeNode, depth+1); //Vemos la clase de <Algo>
		Symbol *tmpSymbol = findSymbolDFS(node->children[2]->leafValue(), tmp->englobingScope, (char*)"ATTRIBUTE");	//Obtenemos el símbolo correspondeinte a id.
		tmp = (ClassSymbol*)symbolTable->Find(getVariableType(tmpSymbol, NULL, false), scopeInic->scopeNum); //Obtenemos la clase referida por id.
		return tmp;	//La retornamos.
	}
	//Retorna el retorno del método =P
	else if(!strcmp(node->token, "MethodInvocation"))
	{
		ClassSymbol *methodHolder = NULL;
		char * methodName;
		
		//El Identifier es el nombre del método.
		if(!strcmp(node->children[0]->token, "Identifier"))
		{		
			methodHolder = currentClass;	//La clase que contiene al método es la clase actual.
			methodName = node->children[0]->leafValue();	//El nombre del método, en tanto, se obtiene del identifier.
		}
		else if(!strcmp(node->children[0]->token, "QualifiedName"))
		{
			
			methodHolder = getExpressionClass(node->children[0]->children[0], scopeNode, depth+1); //Obtenemos la clase que contiene el método.
			methodName = node->children[0]->children[2]->leafValue();	//Obtenemos el nombre del método.
			
			
		}
		else if(!strcmp(node->children[0]->token, "FieldAccess"))
		{
			methodHolder = getExpressionClass(node->children[0], scopeNode, depth+1);	//Obtenemos la clase que contiene el método.
			methodHolder = (ClassSymbol*)getVariableType(findSymbolDFS(node->children[2]->leafValue(), methodHolder->englobingScope, (char*)"ATTRIBUTE"), NULL, false);	//Obtenemos el nombre del método.
			methodName = node->children[2]->leafValue();
			
		}
		else if(!strcmp(node->children[0]->token, "ClassInstanceCreationExpr"))
		{
			methodHolder = (ClassSymbol*)symbolTable->Find(node->children[0]->children[1]->leafValue(), scopeInic->scopeNum);
			methodName = node->children[2]->leafValue();
		}
		else if(!strcmp(node->children[0]->token, "PrimaryNoNewArray"))
		{
			methodHolder = getExpressionClass(node->children[0]->children[1], scopeNode, 0);
			methodName = node->children[2]->leafValue();
		}
		else if(!strcmp(node->children[0]->token, "this"))
		{
			methodHolder = currentClass;
			methodName = node->children[2]->leafValue();
		}
		
		//Obtenemos el método dado su nombre y la clase que lo contiene.
		Method *m = (Method*)findSymbolDFS(methodName, methodHolder->englobingScope, (char*)"METHOD");
		char* returnType = m->returnType;	//Obtenemos el retorno del método.
		return (ClassSymbol*)symbolTable->Find(returnType, scopeInic->scopeNum); //Si es una clase, retornamos el símbolo correspondiente.

		//return currentClass;
	}
	else if(!strcmp(node->token, "PrimaryNoNewArray"))	//2 posibilidades:
	{
		if(!strcmp(node->children[0]->token, "this"))	//Si es this, se refiere a la clase actual.
		{	
				return currentClass;
		}
		else	//Caso contrario, es un (Expr), necesariamente.
		{
			string exprType = getExpressionType(node->children[1], scopeNode); //Obtenemos el tipo de Expr.
			if(exprType.find("class") != string::npos)	//Si no es un tipo de clase, entonces la llamada a este método es errónea.
			{
				string className = exprType.substr(6);	//Obtenemos el string sin el "class".
				return (ClassSymbol*)symbolTable->Find((char*)className.c_str(), scopeInic->scopeNum);
			}
			else
			{
				cout << "ERROR in PrimaryNoNewArray in getExpression class: Node " << node->children[0]->token << "\n";
			}
		}
	}
	else if(!strcmp(node->token, "QualifiedName"))	//Caso análogo a FieldAccess.
	{

		ClassSymbol *tmp = getExpressionClass(node->children[0], scopeNode, depth+1);	
		cout << "Attempting to find symbol " << node->children[2]->leafValue() << "in class " << tmp->id << endl;		
		Symbol *tmpSymbol = findSymbolDFS(node->children[2]->leafValue(), tmp->englobingScope, (char*)"ATTRIBUTE");	
		cout << "Tmp es " << tmpSymbol->id << endl;
		tmp = (ClassSymbol*)symbolTable->Find(getVariableType(tmpSymbol, NULL, false), scopeInic->scopeNum);
		return tmp;
	
	}
	else if(!strcmp(node->token, "Identifier"))
	{
		//cout << "Attempting to find node " << node->leafValue() << " in scope " << scopeNode->scopeNum << endl;
		Symbol *tmpSymbol = findSymbolDFS(node->children[0], scopeNode);		
		ClassSymbol * tmp = (ClassSymbol*)symbolTable->Find(getVariableType(tmpSymbol, NULL, false), scopeInic->scopeNum);
		cout << "Var type: " << tmp->id << endl;
		return tmp;
	}
	else if(!strcmp(node->token, "ClassInstanceCreationExpr"))
	{
		Node * nameNode = node->children[1];
		ClassSymbol * classSymbol = (ClassSymbol*)symbolTable->Find(nameNode->leafValue(), scopeInic->scopeNum);
		return classSymbol;
	}
}

//Retorna el tipo de la expresión entregada.
string getExpressionType(Node *node, ScopeNode *scopeNode)
{
	string toReturn = "";
	stringstream ss;
	//Si es un literal, correspond directamente al tipo del literal.
	if(!strcmp(node->token, "FloatingPointLiteral"))
	{
		return "float32";
	}	
	else if(!strcmp(node->token, "CharLiteral"))
	{
		return "char";
	}	
	else if(!strcmp(node->token, "StringLiteral"))
	{
		return "string";
	}
	else if(!strcmp(node->token, "IntegerLiteral"))
	{
		return "int32";
	}
	else if(!strcmp(node->token, "TrueOrFalse"))
	{
		printf("Returning bool.\n");
		return "bool";
	}
	else if(!strcmp(node->token, "PrimaryNoNewArray"))
	{
		if(node->numChildren == 3)
		{
			return getExpressionType(node->children[1], scopeNode);
		}
		else if(node->numChildren == 1)
		{
			stringstream ss;
			ss <<  "class " << currentClass->id;
			return ss.str();
		}
	}
	else if(!strcmp(node->token, "ConditionalOrExpr") || !strcmp(node->token, "ConditionalAndExpr") || !strcmp(node->token, "EqualityExpr") || !strcmp(node->token, "RelationalExpr"))
	{
		return "bool";
	}
	else if(!strcmp(node->token, "AndExpr") || !strcmp(node->token, "ExclusiveOrExpr") || !strcmp(node->token, "InclusiveOrExpr"))
	{
		return "int32";
	}
	
	//Si es un MethodInvocation...
	else if(!strcmp(node->token, "MethodInvocation"))
	{
		
		string returnType;
		//Si el MI tiene sólo un ID como hijo, sabemos que está en la clase actual.
		if(!strcmp(node->children[0]->token, "Identifier"))
		{
			//Buscamos el símbolo del método en el scope de la clase actual.
			Method * m = (Method*)(findSymbolDFS(node->children[0]->children[0], getScopeByNum(currentClass->englobingScope, scopeInic)), (char*)"METHOD");
			if(m != NULL)
			{				
				//El tipo de la expresión corresponde al retorno del método.
				return javaTypeToCil(m->returnType);		
			}
		}
		else if(!strcmp(node->children[0]->token, "FieldAccess"))
		{			
			ClassSymbol *tmpClass = getExpressionClass(node->children[0]->children[0], scopeNode, 0);
			Symbol * attr = findSymbolDFS(node->children[0]->children[2]->leafValue(), tmpClass->englobingScope, (char*)"ATTRIBUTE");
			tmpClass = (ClassSymbol*)symbolTable->Find(getVariableType(attr, NULL, false), scopeInic->scopeNum);
			
			Method * m = (Method*)(findSymbolDFS(node->children[2]->leafValue(), tmpClass->englobingScope, (char*)"METHOD"));
			
			if(m != NULL)
			{				
				returnType = javaTypeToCil(m->returnType);		
				return returnType;
			}
		}
		//Si es un qualifiedName, por el otro lado, es análogo al anterior.
		else if(!strcmp(node->children[0]->token, "QualifiedName"))
		{
			stringstream ss;
		
			//Chequeamos si es un System call.
			Node * tmp = node->children[0];
			while(!strcmp(tmp->token, "QualifiedName"))
			{
				ss << tmp->children[2]->leafValue();
				ss << ".";
				tmp = tmp->children[0];
			}
			ss << tmp->leafValue();
			string str = ss.str();
			if(str == "println.out.System")
			{
				return "void";
			}
			else if(str == "print.out.System")
			{
				return "void";
			}
			else if(str == "read.in.System")
			{
				//REVISAR: Como funciona esto con multiples assignment :P.
				stringstream ss;
				ss << node->parent->token;
				string parentToken = ss.str();
				
				//Para que esto ocurra, se tiene que llamar a un método después que se invoca el class...
//				if(parentToken == "ClassInstanceCreationExpr")
//				{
//					string varType = getExpressionType(node->parent->children[, scopeNode);
//				}
//			A	
				if(parentToken != "ExprStmt")
				{
					string varType = getExpressionType(node->parent, scopeNode);
					//cout << "Vartype is " << varType << endl;
					if(varType != "void")
						return varType;
					else return "string";
				}
//				
//				if(strcmp(node->parent->token, "ExprStmt"))
//				{
//					
//				}
			}
			
			ClassSymbol *tmpClass = getExpressionClass(node->children[0]->children[0], scopeNode, 0);		
			
			Method * m = (Method*)(findSymbolDFS(node->children[0]->children[2]->leafValue(), tmpClass->englobingScope, (char*)"METHOD"));			
			
			if(m != NULL)
			{				
				returnType = javaTypeToCil(m->returnType);		
				return returnType;
			}
		}
		else if(!strcmp(node->children[0]->token, "MethodInvocation"))
		{
			ClassSymbol *tmpClass = getExpressionClass(node->children[0], scopeNode, 0);					
			Method * m = (Method*)(findSymbolDFS(node->children[2]->leafValue(), tmpClass->englobingScope, (char*)"METHOD"));			
			
			if(m != NULL)
			{				
				returnType = javaTypeToCil(m->returnType);		
				return returnType;
			}
		}
		else if(!strcmp(node->children[0]->token, "ClassInstanceCreationExpr"))
		{
			ClassSymbol *tmpClass = getExpressionClass(node->children[0], scopeNode, 0);					
			Method * m = (Method*)(findSymbolDFS(node->children[2]->leafValue(), tmpClass->englobingScope, (char*)"METHOD"));			
			
			if(m != NULL)
			{				
				returnType = javaTypeToCil(m->returnType);		
				return returnType;
			}
		}
		else if(!strcmp(node->children[0]->token, "PrimaryNoNewArray"))
		{
			//this
			if(node->children[0]->numChildren == 1)
			{
				//Buscamos el símbolo del método en el scope de la clase actual.
				Method * m = (Method*)(findSymbolDFS(node->children[2]->children[0],
				 getScopeByNum(currentClass->englobingScope, scopeInic)), (char*)"METHOD");
				if(m != NULL)
				{				
					//El tipo de la expresión corresponde al retorno del método.
					return javaTypeToCil(m->returnType);		
				}
				//REVISAR: TIRAR ERROR AQUI.
			}
			//<Expr>
			else
			{
				ClassSymbol * tmpClass = getExpressionClass(node->children[0]->children[1], scopeNode, 0);
				Method * m = (Method*)(findSymbolDFS(node->children[2]->leafValue(), 
				tmpClass->englobingScope, (char*)"METHOD"));			
			
				if(m != NULL)
				{				
					returnType = javaTypeToCil(m->returnType);		
					return returnType;
				}
			}
		}
		else if(!strcmp(node->children[0]->token, "super"))
		{
			ClassSymbol *tmpClass = currentClass;
			Method *m = NULL;				

			while(m == NULL && tmpClass->hasBase)
			{				
				tmpClass = tmpClass->baseClass;
				 m = (Method*)(findSymbolDFS(node->children[2]->leafValue(), tmpClass->englobingScope, (char*)"METHOD"));	
			}
			if(m != NULL)
			{
				returnType = javaTypeToCil(m->returnType);		
				return returnType;
			}
			else 
			{
				//REVISAR
				cout << "ERROR!!\n";
			}
		}
		else
		{
			//REVISAR
			return "";
		}
		
	}
	else if(!strcmp(node->token, "ArrayCreationExpr"))
	{
		if(node->numChildren == 3 && isPrimitiveType(node->children[1]))
		{
			return javaTypeToCil(getType(node->children[1])) + "[]";
		}
		else
		{
			//REVISAR: Debe tirar error aquí.
		}
	}
	else if(!strcmp(node->token, "ArrayAccess"))
	{
		Symbol *arrSymbol;
		//Tenemos Identifier.algo
		if(node->children[0]->numChildren == 1)
		{
			arrSymbol = findSymbolDFS(node->children[0]->children[0], scopeNode);
		}
		else
		{
			//Esto debería darnos la clase en que está el arreglo.
			ClassSymbol * classHolder = getExpressionClass(node->children[0]->children[0], scopeNode, 0);
			cout << "Class holder is " << classHolder->id << endl;
			arrSymbol = findSymbolDFS(node->children[0]->children[2]->leafValue(), classHolder->englobingScope, (char*)"ATTRIBUTE");
		}
		
		string type = javaTypeToCil(getVariableType(arrSymbol, NULL, 0));
		int pos = type.find("[]");
		return type.substr(0, pos);
	}
	else if(!strcmp(node->token, "ClassInstanceCreationExpr"))
	{
		
		ss << "class " << node->children[1]->leafValue();
		toReturn = ss.str();
		return ss.str();
		ss.str("");
		ss.str() = "";
		//new <ClassType>...  se asume que ClassType es un ID por ahora.
	}
	else if(!strcmp(node->token, "CastExpr"))
	{	
		//Se asume que la única regla válida es (<PrimitiveType>) <UnaryExpr>...
		return javaTypeToCil(node->children[1]->leafValue());
	}
	else if(!strcmp(node->token, "QualifiedName"))
	{
		
		ClassSymbol *tmpClass = getExpressionClass(node->children[0], scopeNode, 0);
		//cout << "Finding " << node->children[2]->leafValue()
		Symbol * attr = findSymbolDFS(node->children[2]->children[0], getScopeByNum(tmpClass->englobingScope, scopeInic), (char*)"ATTRIBUTE");
		
		return javaTypeToCil(getVariableType(attr, NULL, false));
	}
	else if(!strcmp(node->token, "FieldAccess"))
	{
		ClassSymbol *tmpClass = getExpressionClass(node->children[0], scopeNode, 0);
		Symbol * attr = findSymbolDFS(node->children[2]->leafValue(), tmpClass->englobingScope, (char*)"ATTRIBUTE");
		return javaTypeToCil(getVariableType(attr, NULL, false));
	}
	else if(!strcmp(node->token, "Identifier"))
	{
		Symbol *s = findSymbolDFS(node->children[0], scopeNode);
		if(!strcmp(s->type, "VARIABLE"))
		{	
			
			Variable * var = (Variable*) s;
			return javaTypeToCil(var->variableType);
		}
		else if(!strcmp(s->type, "ATTRIBUTE"))
		{
			return javaTypeToCil(((Attribute *)s)->variableType);
		}
		else if(!strcmp(s->type, "PARAMETER"))
		{
			return javaTypeToCil(((Parameter *)s)->paramType);
		}
	}
	for(int i = 0; i < node->numChildren; i++)
	{
		string tmp = "";
		tmp = getExpressionType(node->children[i], scopeNode);
		if(tmp != "") return tmp;
	}
	
	return "";
	
}
void analyzeAssignment(Node *node, ScopeNode *scopeNode)
{

	
	Node * op = node->children[1]->children[0]; //Si es =, !=, &=, etc...
	
	char* opToken = op->token;	
	bool extraOpp = false;	//Asumimos en un comienzo que tenemos un =.
		
	storing = true; //Indicamos que vamos a guardar el resultado de la asignación.
	
	analyzeExpr(node->children[0], scopeNode);	//Analizamos la expresión del lado izquierdo. Guardamos en el stack postStrings
												//el stfld que se hará después.
	storing = false;							//Se setea en false pues el lado derecho se carga, no se guarda.
	

	//Si NO tenemos un =, tenemos que hacer una operación extra, correspondiente a cargar lo del lado izquierdo para hacer la operación.
	//a += b => a = a + b
	if(strcmp(opToken, "="))
	{
		//Do nothing	
		extraOpp = true;	//Cargamos lo del lado izquierdo para la operación extra y lo analziamos.
		analyzeExpr(node->children[0], scopeNode);		
	}	
	analyzeExpr(node->children[2], scopeNode);

	//Debemos ver el caso a = b = c;
	//En este caso, children[2] es "b = c". Deberíamos hacer ldloc a b!
	if(!strcmp(node->children[2]->token, "Assignment"))
	{
		//Esta parte hace análisis a "b" para cargarlo.
		//TODO: Podría ser más eficiente cargar un valor no más para todos los iguales.
		analyzeExpr(node->children[2]->children[0], scopeNode);
	}
	
	if(extraOpp)	//Si hay una operación extra, cargamos en el cil la operación correspondiente.
	{		
		if(!strcmp(opToken, "*="))
		{
			cil << insertTabs(scopeNode) << "mul" << endl;
		}
		else if(!strcmp(opToken, "/="))
		{
			cil << insertTabs(scopeNode) << "div" << endl;
		}
		else if(!strcmp(opToken, "%="))
		{
			cil << insertTabs(scopeNode) << "rem" << endl;
		}
		else if(!strcmp(opToken, "+="))
		{
			cil << insertTabs(scopeNode) << "add" << endl;
		}
		else if(!strcmp(opToken, "-="))
		{
			cil << insertTabs(scopeNode) << "sub" << endl;
		}
		else if(!strcmp(opToken, "&="))
		{
			cil << insertTabs(scopeNode) << "and" << endl;
		}
		else if(!strcmp(opToken, "^="))
		{
			cil << insertTabs(scopeNode) << "xor" << endl;
		}
		else if(!strcmp(opToken, "|="))
		{
			cil << insertTabs(scopeNode) << "or" << endl;
		}
	}
	//Sacamos del tope del stack postStrings el código que sirve para hacer el stfld correspondiente.
	cil << postStrings.top();
	postStrings.pop();	

	if(strcmp(node->parent->token, "ExprStmt") && strcmp(node->parent->token, "Assignment"))
	{
		analyzeExpr(node->children[0], scopeNode);
	}
		
}

//Vemos si el nodo encontrado es un literal. En tal caso, simplemetne insertamos un ldloc correspondiente en el archivo cil.
bool analyzeLiteral(Node *node, ScopeNode *scopeNode)
{
	//Si es un literal simplemetne conseguimos su valor.
	if(!strcmp(node->token, "IntegerLiteral"))
	{
		cil << insertTabs(scopeNode) << "ldc.i4 " << node->leafValue() << endl;
		return true;	
	}
	else if(!strcmp(node->token, "FloatingPointLiteral"))
	{
		cil << insertTabs(scopeNode) << "ldc.r4 " << node->leafValue() << endl;
		return true;	
	}
	else if(!strcmp(node->token, "CharLiteral"))
	{
		
		char * tmp = node->leafValue();
		cil << insertTabs(scopeNode) << "ldc.i4 " << (int)tmp[1] << endl;
		return true;
	}
	else if(!strcmp(node->token, "StringLiteral"))
	{
		cil << insertTabs(scopeNode) << "ldstr " << node->leafValue() << endl;
		return true;
	}
	else if(!strcmp(node->token, "TrueOrFalse"))
	{
		cil << insertTabs(scopeNode) << "ldc.i4 ";
		
		if(!strcmp(node->leafValue(), "true"))
		{
			cil << "1" << endl;
		}
		else
		{
			cil << "0" << endl;
		}
		return true;
	}
	return false;
}

void analyzeConditionalExpr(Node * node, ScopeNode * scopeNode)
{
	//<Expresion> && / || <Expresion>
	char * op = node->children[1]->token;
	if(!strcmp(op, "&&"))
	{
		string label1 = generateRelLabel();
		string label2 = generateRelLabel();
		string end = generateRelLabel();
		
		analyzeExpr(node->children[0], scopeNode);
		cil << insertTabs(scopeNode) << "brtrue " << label1 << endl;
		cil << insertTabs(scopeNode) << "ldc.i4 0" << endl;
		cil << insertTabs(scopeNode) << "br " << end << endl;
		cil << insertTabs(scopeNode) << label1 << ":" << endl;
		analyzeExpr(node->children[2], scopeNode);
		cil << insertTabs(scopeNode) << "brtrue " << label2 << endl;
		cil << insertTabs(scopeNode) << "ldc.i4 0" << endl;
		cil << insertTabs(scopeNode) << "br " << end << endl;
		cil << insertTabs(scopeNode) << label2 << ":" << endl;
		cil << insertTabs(scopeNode) << "ldc.i4 1" << endl;
		cil << insertTabs(scopeNode) << end << ":" << endl;
		
	}
	else if(!strcmp(op, "||"))		//a || b
	{
		string label = generateRelLabel();
		string end = generateRelLabel();
		
		analyzeExpr(node->children[0], scopeNode);
		cil << insertTabs(scopeNode) << "brtrue " << label << endl; //Si a == true a || b == true
		analyzeExpr(node->children[2], scopeNode);	
		cil << insertTabs(scopeNode) << "brtrue " << label << endl;	//Idem para b
		cil << insertTabs(scopeNode) << "ldc.i4 0" << endl;	//Si ninguno es true, a || b == false
		cil << insertTabs(scopeNode) << "br " << end << endl;
		cil << insertTabs(scopeNode) << label << ":" << endl;
		cil << insertTabs(scopeNode) << "ldc.i4 1" << endl;
		cil << insertTabs(scopeNode) << end << ":" << endl;
		
		
	}
}

//Cuidado: Aquí las clases podrían llegar a tener herencia.
void analyzeClassCreation(Node *node, ScopeNode *scopeNode)
{
	string params("");
	
	vector<Node *> paramVector;
	
	if(node->numChildren == 5)
	{
		Node * tmp = node->children[3];
		while(!strcmp(tmp->token, "ArgumentList"))
		{				
			
			
			if(params == "")
			{				
				
				params = getExpressionType(tmp->children[2], scopeNode);
				
			}
			else
				params = getExpressionType(tmp->children[2], scopeNode) + ", " + params;
				
			paramVector.push_back(tmp->children[2]);	
			tmp = tmp->children[0];		
		}
		
		if(params == "")
			params = getExpressionType(tmp, scopeNode);
		else
		{			
			
			params =  getExpressionType(tmp, scopeNode) + ", " + params;
		}		
		paramVector.push_back(tmp);
		
		
		
		//analyzeExpr(tmp, scopeNode);
		//cout << "Argumentos son: " << params << endl;
		for(int i = paramVector.size() -1; i >= 0; i--)
		{
			analyzeExpr(paramVector[i], scopeNode);
		}
	}
	
	if(strcmp(node->children[1]->token, "Identifier"))
	{
		stringstream ss;
		int line = node->children[1]->children[2]->children[0]->line;
		ss << "$Error(" << line << "): Qualified names may not be used as class types." << endl;
		errors.push_back(new class Error(ss.str(), line));
		return;
		
		//printf("<ClassType> no es un Identifier; Para esta entrega sólo se consideran identifiers!\n");
	}
	else
		cil << insertTabs(scopeNode) << "newobj instance void " << node->children[1]->leafValue() << "::.ctor(" << params << ")" << endl;
}


ClassSymbol * analyzeFieldAcess(Node * node, ScopeNode * scopeNode, bool isInvocation)
{
	Node * tmp = node;
	vector<Node*> ids;
	
	//Debemos saber, en todo momento, a qué clase pertenece a, b, c, d, etc... En un comienzo estamos en la clase
	//Que está haciendo la asignación.
	ClassSymbol * tmpClass = currentClass;	
	while(!strcmp(tmp->token, "FieldAccess"))	{
		
		//Esto es un id, siempre.
		ids.push_back(tmp->children[2]);
		//Esto puede ser cualquier cosa xD.
		tmp = tmp->children[0];
	}


	bool isStoring = storing;
	bool hasThis = false;
	storing = false;
	
	//2 posibilidades -> (Exp) o this./	
	if(!strcmp(tmp->token, "PrimaryNoNewArray"))
	{
		//Si no tiene un this, cargamos la expresión asociada.
		if(strcmp(tmp->children[0]->token, "this"))
		{			
			analyzeExpr(tmp->children[1], scopeNode);				
		}
		else	//En caso contrario....
		{
			//Siempre se cargará lo primero como argumento.
			cil << insertTabs(scopeNode) << "ldarg.0" << endl;				
		}
		
			Symbol *sym = NULL;
			tmpClass = currentClass;
			string type = "";
			
			
			for(int i = ids.size()-1; i > 0; i--)
			{
				
				sym = findSymbolDFS(ids[i]->children[0], getScopeByNum(tmpClass->englobingScope, scopeInic), (char*)"ATTRIBUTE");				
				type = getVariableType(sym, (char*)"", false);
				
				loadCilVariableFields(ids[i], scopeNode, tmpClass, false);	
				
				tmpClass = (ClassSymbol*) symbolTable->Find((char*)type.c_str(), scopeInic->scopeNum);		
							
			
			}
			
		storing = isStoring;
		loadCilVariableFields(ids[0], scopeNode, tmpClass, false);
		storing = false;
		return tmpClass;
	}
	else if(!strcmp(tmp->token, "MethodInvocation"))
	{
		ClassSymbol * methodClass = analyzeMethodInvocation(tmp, scopeNode);
		tmp->visited = true;
		storing = isStoring;
		loadCilVariableFields(ids[0], scopeNode, methodClass, false);	
		
		Symbol *sym  = symbolTable->Find(ids[0]->leafValue(), methodClass->englobingScope);
		string s = getVariableType(sym, NULL, false);
		methodClass = (ClassSymbol*)symbolTable->Find((char*)s.c_str(), scopeInic->scopeNum);
		
		return methodClass;
	}
	else
	{
		analyzeExpr(tmp, scopeNode);

		storing = isStoring;
		loadCilVariableFields(ids[0], scopeNode, getExpressionClass(tmp, scopeNode, 0), false);	//Esto DEBE ir al final de todo. Lo más complicado es tener el ldc.i4 1 entre medio.
		return tmpClass;
	}
}

//Analiza un qualified name. Retorna la clase a la que pertenece el último atributo de la lista.
//Ej: En a.b.c.d, retorna la clase correspondiente a C.
ClassSymbol* analyzeQualifiedName(Node *node, ScopeNode *scopeNode, bool isInvocation)
{

	bool fieldAccess = !strcmp(node->token, "FieldAccess");
	//a.b.c.d = ....
	if(!strcmp(node->token, "QualifiedName"))
	{
		bool isStoring = storing;
		//Sólo queremos guardar lo penúltimo. Por ende para los otros storing = false.
		//Guardamos el valor original de storing en un temporario.
		
		Node * tmp = node;
		vector<Node *> ids;	
		
		//si QF = a.b.c.d.e... ids debería ser [e, d, c, b, a]
		while(!strcmp(tmp->token, "QualifiedName"))
		{
			ids.push_back(tmp->children[2]);
			tmp = tmp->children[0];		
		}		
		ids.push_back(tmp);

//		
//		for(int i = 0; i < ids.size(); i ++)
//		{
//			cout << ids[i]->leafValue() << endl;
//		}
		
		storing = false;	//Cargaremos más adelante ;).
		
		//Debemos saber, en todo momento, a qué clase pertenece a, b, c, d, etc... En un comienzo estamos en la clase
		//Que está haciendo la asignación.
		ClassSymbol * tmpClass = currentClass;	
		
		//La última variable es lo que cargaremos. La penúltima es a lo que haremos stfld.
		//Cargamos, entonces, lo que está entre MEDIO. Si tenemos this.a.b.c = 1, haremos 		
		
		loadCilVariable(ids[ids.size()-1], scopeNode, false);	//Cargamos la PRIMERA variable, en este caso, a.
																//Caso especial pues puede ser variable local.
		Symbol *sym = findSymbolDFS(ids[ids.size()-1]->children[0], scopeNode);
		
		
		char * symbolType = (char*)"";
		string type = getVariableType(sym, symbolType, false);													
		//cout << "TYPE FOUND TO BE " << type << endl;		
		Symbol * tmpSymbol = symbolTable->Find((char*)type.c_str(), scopeInic->scopeNum);
		
		if(tmpSymbol == NULL)
		{
			cout << "ERROR: INVALID CLASS TYPE." << endl;
			return NULL;
		}

			

		for(int i = ids.size()-2; i > 0; i--)
		{				
			tmpClass = (ClassSymbol*) tmpSymbol;
			loadCilVariableFields(ids[i], scopeNode, tmpClass, false);
			
			sym = findSymbolDFS(ids[i]->children[0], getScopeByNum(tmpClass->englobingScope, scopeInic));
			
			//cout << "In qualified name: Attempting to find symbol type of " << sym->id << " in scope " <<  tmpClass->englobingScope << endl;
			
			symbolType = (char*)"";
			type = getVariableType(sym, symbolType, false);													
			//cout << "TYPE FOUND TO BE " << type << endl;
		
			tmpSymbol = symbolTable->Find((char*)type.c_str(), scopeInic->scopeNum);
			
			
			if(tmpSymbol == NULL)
			{
				cout << "ERROR: INVALID CLASS TYPE." << endl;
				return NULL;
			}				
		}
		
		
		//cout << "loading variable " << sym->id << "in order to find class type." << endl;
		if(isInvocation)
		{
			//cout << "Tmp class: " << tmpClass->id << " symbol : " << sym->id << endl;
			type = getVariableType(sym, symbolType, false);	
			//cout << "Attempting to get class type of " << sym->id << " with type " << type <<  endl;
			tmpSymbol = symbolTable->Find((char*)type.c_str(), scopeInic->scopeNum);
			
			if(tmpSymbol == NULL)
			{
				cout << "ERROR: INVALID CLASS TYPE." << endl;
				return NULL;
			}	
			
			//cout << "Returning class " << tmpSymbol->id << endl;
			return (ClassSymbol*)tmpSymbol;
		}
		else
		{
			tmpClass = (ClassSymbol*) tmpSymbol;
				
			//TODO: Aquí, en algún momento, se TIENE que haber cargado el 1!!
			storing = isStoring;
			loadCilVariableFields(ids[0], scopeNode, tmpClass, false);	//Esto DEBE ir al final de todo. Lo más complicado es tener el ldc.i4 1 entre medio.
			storing = false;
		
		
		}
		
		return tmpClass;
	}
	return NULL;
}

//Esto es TODO lo que podría venir en la parte derecha de un signo igual. Se hacen los ldloc que sean necesarios en cada caso.
void analyzeExpr(Node *node, ScopeNode *scopeNode)
{	
	
	//if(node->visited) return;
	//cil << "entro a analyExpr " << node->token << endl;
	node->visited = true;
	char * token = node->token;
	
	
	if(!strcmp(token, "Assignment"))
	{
		analyzeAssignment(node, scopeNode);
	}
	else if(!strcmp(token, "ConditionalOrExpr"))	//Tiene un || entre medio
	{
		analyzeConditionalExpr(node, scopeNode);
	}
	else if(!strcmp(token, "ConditionalAndExpr"))	//Tiene un && entre medio
	{
		analyzeConditionalExpr(node, scopeNode);
	}
	else if(!strcmp(token, "InclusiveOrExpr"))	//Un | entre medio
	{
		analyzeExpr(node->children[0], scopeNode);
		analyzeExpr(node->children[2], scopeNode);

		cil << insertTabs(scopeNode) << "or" << endl;		
		cil << endl;
	}
	else if(!strcmp(token, "ExclusiveOrExpr")) // un ^ entre medio
	{
		analyzeExpr(node->children[0], scopeNode);
		analyzeExpr(node->children[2], scopeNode);

		cil << insertTabs(scopeNode) << "xor" << endl;		
		cil << endl;
	}
	else if(!strcmp(token, "AndExpr")) //Un & entre medio
	{
		analyzeExpr(node->children[0], scopeNode);
		analyzeExpr(node->children[2], scopeNode);

		cil << insertTabs(scopeNode) << "and" << endl;		
		cil << endl;
	
	}
	else if(!strcmp(token, "EqualityExpr")) //Un == o !=
	{
		analyzeRelationalExpr(node, scopeNode);
	}
	else if(!strcmp(token, "RelationalExpr")) //<, >, <=, >=
	{
		analyzeRelationalExpr(node, scopeNode);
	}
	else if(!strcmp(token, "AdditiveExpr")) // + ó -
	{
		analyzeExpr(node->children[0], scopeNode);
		analyzeExpr(node->children[2], scopeNode);
		
		Node *op = node->children[1];
		if(!strcmp(op->leafValue(), "+"))
		{
			cil << insertTabs(scopeNode) << "add" << endl;
		}
		else
		{
			cil << insertTabs(scopeNode) << "sub" << endl;
		}
		cil << endl;
	}
	else if(!strcmp(token, "MultiplicativeExpr")) //*, /, %
	{		
		analyzeExpr(node->children[0], scopeNode);
		analyzeExpr(node->children[2], scopeNode);
		
		Node *op = node->children[1];
		if(!strcmp(op->leafValue(), "*"))
		{
			cil << insertTabs(scopeNode) << "mul" << endl;
		}
		else if(!strcmp(op->leafValue(), "/"))
		{
			cil << insertTabs(scopeNode) << "div" << endl;
		}
		else if(!strcmp(op->leafValue(), "%"))
		{
			cil << insertTabs(scopeNode) << "rem" << endl;
		}
		cil << endl;
	}
	else if(!strcmp(token, "UnaryExprNotPlusMinus"))
	{
		analyzeUnaryExprNotPlusMinus(node, scopeNode);		
	}
	else if(analyzeLiteral(node, scopeNode)) //Esto YA carga el literal
	{
		
	}
	else if(!strcmp(node->token, "Identifier"))
	{			
		loadCilVariable(node, scopeNode, false);
	}
	else if(!strcmp(node->token, "PrimaryNoNewArray"))
	{
		//Set de paréntesis.
		if(node->numChildren == 3)
		{
			analyzeExpr(node->children[1], scopeNode);
		}
		//this
		else if(node->numChildren == 1)
		{
			cil << insertTabs(scopeNode) << "ldarg.0" << endl;
		}
	}
	else if(!strcmp(node->token, "ClassInstanceCreationExpr"))
	{
		analyzeClassCreation(node, scopeNode);
	}
	else if(!strcmp(node->token, "MethodInvocation"))
	{
		analyzeMethodInvocation(node, scopeNode);
	}
	else if(!strcmp(node->token, "QualifiedName"))
	{
		analyzeQualifiedName(node, scopeNode, false);
	}
	else if( !strcmp(node->token, "PostIncrementExpr"))
	{
	
		if(strcmp(node->parent->token, "ExprStmt")) //Necesitamos cargar la variable de nuevo para ser usada después
		{
			analyzeExpr(node->children[0], scopeNode);
		}
			
		storing = true;
		analyzeExpr(node->children[0], scopeNode);
		storing = false;		

		analyzeExpr(node->children[0], scopeNode);
		string type = getExpressionType(node->children[0], scopeNode);
		
		if(type == "int32" || type == "char")
			cil << insertTabs(scopeNode) << "ldc.i4 1" <<endl;
		else if(type == "float32")
			cil << insertTabs(scopeNode) << "ldc.r4 1" <<endl;
		else
		{
			stringstream ss;
			ss << "$Error(" << node->line << "): PostIncrementExpr applied to invalid variable type: " << type << endl;
			errors.push_back(new class Error(ss.str(), node->line));
		}
		
		
		cil << insertTabs(scopeNode) << "add" <<endl;		
		
		cil << postStrings.top();
		postStrings.pop();

	}
	else if(!strcmp(node->token, "PreIncrementExpr") )
	{	
		storing = true;
		analyzeExpr(node->children[1], scopeNode);
		storing = false;
		
		analyzeExpr(node->children[1], scopeNode);
		
		string type = getExpressionType(node->children[1], scopeNode);
		
		if(type == "int32" || type == "char")
			cil << insertTabs(scopeNode) << "ldc.i4 1" <<endl;
		else if(type == "float32")
			cil << insertTabs(scopeNode) << "ldc.r4 1" <<endl;
		else
		{
			//REVISAR
			cout << "Error: Pre incr con tipo no válido.\n";
			stringstream ss;
			ss << "$Error(" << node->line << "): PreIncrementExpr applied to invalid variable type: " << type << endl;
			errors.push_back(new class Error(ss.str(), node->line));
		}
		
	
		cil << insertTabs(scopeNode) << "add" <<endl;		

		cil << postStrings.top();
		postStrings.pop();

		if(strcmp(node->parent->token, "ExprStmt")) //Necesitamos cargar la variable de nuevo
			analyzeExpr(node->children[1], scopeNode);
	}
	else if(!strcmp(node->token, "UnaryExpr"))
	{
		
		char* opToken = node->children[0]->leafValue();
		if(!strcmp(opToken, "-"))
		{
			
			analyzeExpr(node->children[1], scopeNode);
			cil << insertTabs(scopeNode) << "neg" << endl;
		}
	}
	else if(!strcmp(node->token, "PostDecrementExpr"))
	{
		if(strcmp(node->parent->token, "ExprStmt")) //Necesitamos cargar la variable de nuevo para ser usada después
		analyzeExpr(node->children[0], scopeNode);
			
		storing = true;
		analyzeExpr(node->children[0], scopeNode);
		storing = false;		

		analyzeExpr(node->children[0], scopeNode);
		string type = getExpressionType(node->children[0], scopeNode);
		
		if(type == "int32" || type == "bool" || type == "char")
			cil << insertTabs(scopeNode) << "ldc.i4 1" <<endl;
		else if(type == "float32")
			cil << insertTabs(scopeNode) << "ldc.r4 1" <<endl;
		else
		{
			//REVISAR
			cout << "Error: Post decr con tipo no válido.\n";
			stringstream ss;
			ss << "$Error(" << node->line << "): PostDecrementExpr applied to invalid variable type: " << type << endl;
			errors.push_back(new class Error(ss.str(), node->line));
		}
		
		cil << insertTabs(scopeNode) << "sub" <<endl;		
		
		cil << postStrings.top();
		postStrings.pop();

	}
	else if(!strcmp(node->token, "PreDecrementExpr"))
	{
		storing = true;
		analyzeExpr(node->children[1], scopeNode);
		storing = false;
		
		analyzeExpr(node->children[1], scopeNode);
		string type = getExpressionType(node->children[1], scopeNode);
		
		if(type == "int32" || type == "bool" || type == "char")
			cil << insertTabs(scopeNode) << "ldc.i4 1" <<endl;
		else if(type == "float32")
			cil << insertTabs(scopeNode) << "ldc.r4 1" <<endl;
		else
		{
			//REVISAR
			cout << "Error: Pre decr con tipo no válido.\n";
			stringstream ss;
			ss << "$Error(" << node->line << "): PreDecrementExpr applied to invalid variable type: " << type << endl;
			errors.push_back(new class Error(ss.str(), node->line));
		}
		cil << insertTabs(scopeNode) << "sub" <<endl;		

		cil << postStrings.top();
		postStrings.pop();

		if(strcmp(node->parent->token, "ExprStmt")) //Necesitamos cargar la variable de nuevo
			analyzeExpr(node->children[1], scopeNode);
	
	}
	else if(!strcmp(node->token, "FieldAccess")) //Lo copie del QualifiedName
	{
		analyzeFieldAcess(node, scopeNode, false);	
		
	}
	else if(!strcmp(node->token, "CastExpr"))
	{
		analyzeCastExpr(node, scopeNode);
	}
	else if(!strcmp(node->token, "ExplicitConstructorInvocation"))
	{
		bool hasArguments = node->numChildren == 5;
		Node *parameterList = NULL;
		string params = "";
		
		cil << insertTabs(scopeNode) << "ldarg.0" << endl;
		
		if(hasArguments)
		{
			parameterList = node->children[2];
			params = analyzeFormalParameters(node->children[2], scopeNode);
		}
		if(!strcmp(node->children[0]->token, "this"))
		{	
			cout << "Gets here. Params are " << params << endl;
			cil << insertTabs(scopeNode) << "call instance void " << currentClass->id << "::.ctor(";
			cil << params;
			cil << ")" << endl;	
		}
		else if(!strcmp(node->children[0]->token, "super"))
		{
			cout << "Gets here. Params are " << params << endl;
			if(currentClass->hasBase)
			{
				cil << insertTabs(scopeNode) << "call instance void " << currentClass->base << "::.ctor(";
				cil << params;
				cil << ")" << endl;	
			}
			else
			{
				
				//REVISAR: SE REQUIERE LA LINEA.
			}
		}	
	
	}
	else if(!strcmp(node->token, "ArrayCreationExpr"))
	{
		//Solo hay UN caso válido:
		//new <PrimitiveType> <DimExprs>
		//cout << "LLEGA AQUI\n";
		if(node->numChildren == 3 && isPrimitiveType(node->children[1]))
		{
			//<DimExprs> => [<Expr>]
			analyzeExpr(node->children[2]->children[1], scopeNode);
			cil << insertTabs(scopeNode) << "newarr " << javaTypeToCil(getType(node->children[1])) << endl;
		}
		else
		{
			//REVISAR: AQUI DEBE LANZAR ERROR.
			cout << "Error en Analyze Expression" << endl;
		}
	}
	//Puede ser <Name> [<Expr>] o <PrimaryNoNewArray> [<Expr>]
	else if(!strcmp(node->token, "ArrayAccess"))
	{
		//Cargamos primero el arreglo.
		bool isStoring = storing;
		storing = false;
		analyzeExpr(node->children[0], scopeNode);
		
		
		//REVISAR: SE HACE CAST A INT? SE DEBE LANZAR ERROR AQUI...
		//Primero cargamos el índice.
		analyzeExpr(node->children[2], scopeNode);
		string type = getExpressionType(node->children[0], scopeNode);
		int pos = type.find("[]");
		type = type.substr(0, pos);
		
		bool isInt = true;
		
		if(type == "int32" || type == "bool" || type == "char")
		{
			
			isInt = true;
		}
		else if(type == "float32")
		{
			isInt = false;			
		}
		else
		{
			//REVISAR: AQUI HAY QUE ARROJAR ERROR.
			cout << "Error: array access of invalid type.\n";
			cout << "Type: " << type << endl;
		}
		
		if(isStoring)
		{
				stringstream ss;
				if(isInt)
				{
					ss << insertTabs(scopeNode) << "stelem.i4" << endl;
				}
				else
				{
					ss << insertTabs(scopeNode) << "stelem.r4" << endl;
				}
				postStrings.push(ss.str());
		}
		else
		{
			if(isInt)
				cil << insertTabs(scopeNode) << "ldelem.i4" << endl;
			else
				cil << insertTabs(scopeNode) << "ldelem.r4" << endl;
		}
		
		storing = isStoring;
		
	}
	else
	{
		cout << "ERROR: Análisis de nodo " << node->token << " aún no está implementado." << endl;
	}
}

//Recibe un <CastExpr>
void analyzeCastExpr(Node *node, ScopeNode* scopeNode)
{
	//En esta gramática en particular, tenemos cuatro opciones (una no usada)
	if(node->numChildren == 4)
	{
		Node * castType = node->children[1];
		//Tenemos <CastExpr> => ( <PrimitiveType> ) <UnaryExpr>
		if(!strcmp(castType->token, "PrimitiveType") || !strcmp(castType->token, "NumericType") || !strcmp(castType->token, "IntegralType"))
		{
			analyzeExpr(node->children[3], scopeNode);	
			char * primType = castType->leafValue();
			
			if(!strcmp(primType, "float"))	//Float es el único caso que requiere conv.r4.
			{
				cil << insertTabs(scopeNode) << "conv.r4" << endl;
			}
			else	//Los tres otros casos (char, int, boolean) tienen la misma representación (int32).
			{
				
				cil << insertTabs(scopeNode) << "conv.i4" << endl;
			}
		}
		else 	//<CastExpr> => ( <Expr > ) <UnaryExprNotPlusMinus>, exclusivamente usado para casts a clases.
		{
			
			if(!strcmp(node->children[1]->token, "Identifier"))
			{
				analyzeExpr(node->children[3], scopeNode);	
				ClassSymbol *classSymbol = (ClassSymbol*)symbolTable->Find(node->children[1]->leafValue(), scopeInic->scopeNum);
				if(classSymbol == NULL)
				{
					stringstream ss;
					ss << "$Error(" << node->children[1]->children[0]->getLine() << "): Attempting to cast object to undefined class type." << endl;
					errors.push_back(new class Error(ss.str(), node->children[1]->children[0]->getLine()));
					return;
				}
				cil << insertTabs(scopeNode) << "castclass " << classSymbol->id << endl;
			}
			else
			{
				//REVISAR: No se guarda bien el número de la línea aquí.
				stringstream ss;
				ss << "$Error(" << node->children[0]->getLine() << "): Attempting to use QualifiedName in cast expression. Only primitive types or identifiers allowed." << endl;
				errors.push_back(new class Error(ss.str(), node->children[0]->getLine()));
				return;
			}			
		}
	}
	else if(node->numChildren == 5)
	{
		Node * castType = node->children[1];
		//Tenemos <CastExpr> => ( <PrimitiveType> <Dims> ) <UnaryExpr>
		if(!strcmp(castType->token, "PrimitiveType") || !strcmp(castType->token, "NumericType") || !strcmp(castType->token, "IntegralType"))
		{
			//REVISAR: No se guarda bien el número de la línea aquí.
			stringstream ss;
			ss << "$Error(" << castType->children[0]->getLine() << "): Casting to primitive type array not allowed." << endl;
			errors.push_back(new class Error(ss.str(), castType->children[0]->getLine()));
			return;
		}
		else //Tenemos <CastExpr> => ( <Name> <Dims> ) <UnaryExpr>
		{	
			//REVISAR: No se guarda bien el número de la línea aquí.
			stringstream ss;
			ss << "$Error(" << castType->children[0]->getLine() << "): Casting to arrays of class type not allowed." << endl;
			errors.push_back(new class Error(ss.str(), castType->children[0]->getLine()));
			return;
		}
	}
}

void analyzeBlockStmts(Node *node, ScopeNode * scopeNode)
{
	if(node->visited)
	{
		return;
	}
	node->visited = true;
	
	if(!strcmp(node->token, "Assignment"))
	{
		analyzeAssignment(node, scopeNode);
	}
	else if(!strcmp(node->token, "MethodInvocation"))
	{
		
		analyzeMethodInvocation(node, scopeNode);
	}
	else if(!strcmp(node->token, "ReturnStmt"))
	{
		if(node->numChildren == 2)
		{
			cil << insertTabs(scopeNode) << "ret" << endl;
		}
		else
		{
			string returnType = getExpressionType(node->children[1], scopeNode);
//			cout << "Return type of method " << currentMethod->id << ": " << returnType << endl;
//			cout << "Declared return type: " << currentMethod->returnType << endl;
			if(returnType ==  javaTypeToCil(currentMethod->returnType))
			{
				analyzeExpr(node->children[1], scopeNode);
				cil << insertTabs(scopeNode) << "ret" << endl;
			}
			else
			{
				stringstream ss;
				//REVISAR.
				ss << "$Error(" << node->children[0]->line << "): Must return expression that evaluates to " << currentMethod->returnType << endl;
				errors.push_back(new class Error(ss.str(), node->children[0]->line));
				
				analyzeExpr(node->children[1], scopeNode);
				cil << insertTabs(scopeNode) << "ret" << endl;
			}
			
		}
	}
}

void continueToCil(Node* continueNode, ScopeNode * scopeNode)
{
	numNode* flujo = ordenFlujo;
	while(flujo->getNum() == IF || flujo->getNum() == ELSE || flujo->getNum() == SWITCH)
	{
		flujo = flujo->getDad();
	}

	if(flujo->getNum() == -1)
	{
		//Error: no debe haber un continue fuera de un loop.
		semanticErrors = true;
		stringstream ss;
		ss << "Line " << continueNode->children[0]->getLine() << ": Continue cannot be used outside a loop.\n";	
		errors.push_back(new class Error(ss.str(), continueNode->children[0]->getLine()));
 
		return; //no esta dentro de un loop
	}
	else
	{
		cil << insertTabs(scopeNode) << "br ";
		if(flujo->getNum() == WHILE)
			cil << "WHILE_CONDITION_" << whileNode->getNum() << endl;
		else if(flujo->getNum() == FOR)
			cil << "FOR_UPDATE_" << forNode->getNum() << endl;
		else if(flujo->getNum() == DO)
			cil << "DO_CONDITION_" << doNode->getNum() << endl;
	}
}

void breakToCil(Node* breakNode, ScopeNode * scopeNode)
{
	
	numNode* flujo = ordenFlujo;
	while(flujo->getNum() == IF || flujo->getNum() == ELSE)
	{
		flujo = flujo->getDad();
	}

	if(flujo->getNum() == -1) 
	{
		//Error: no debe haber un break fuera de un loop o switch.
		semanticErrors = true;
		stringstream ss;
		ss << "Line " << breakNode->children[0]->getLine() << ": Break cannot be used outside a loop or a switch.\n";	
		errors.push_back(new class Error(ss.str(), breakNode->children[0]->getLine()));
 
		return; //no esta dentro de un loop
	}
	else
	{
		cil << insertTabs(scopeNode) << "br ";
		if(flujo->getNum() == WHILE)
			cil << "END_WHILE_" << whileNode->getNum() << endl;
		else if(flujo->getNum() == FOR)
			cil << "END_FOR_" << forNode->getNum() << endl;
		else if(flujo->getNum() == DO)
			cil << "END_DO_" << doNode->getNum() << endl;
		else if(flujo->getNum() == SWITCH)
			cil << "END_SWITCH_" << switchNode->getNum() << endl;
	}
}

//Este método analiza, primeramente, las clases, métodos, constructores y atributos, cuyo uso es BFS y por lo mismo debemos cargarlos antes.
void analyzeBFS(Node *node, ScopeNode *scopeNode, int depth)
{

	if(node == NULL) return;
	Node *tmp = node;
	
	if(!strcmp(node->token, "ClassDeclaration"))
	{		
		analizeClassSymbol(node, scopeNode);
		if(currentClass != NULL)
			scopeNode = incrementScope(scopeNode);
		else
		{
			markErrorsDFS(node);
		}
	}
	if(currentClass != NULL)
	{
		if(!strcmp(node->token, "ConstructorDeclaration"))
		{
			scopeNode = incrementScope(scopeNode);
			analyzeConstructorSymbol(node, scopeNode);
		}
		else if(!strcmp(node->token, "MethodDeclaration"))
		{
			scopeNode = incrementScope(scopeNode);
			analizeMethodSymbol(node, scopeNode);
		
		}
		else if(!strcmp(node->token, "FieldDeclaration"))
		{
			currentClass->fields.push_back(node);
			analyzeAttrSymbol(node, scopeNode);
		}
		
		if(currentMethod != NULL)
			if(!strcmp(node->token, "FormalParameter"))
			{		
				analyzeParameterSymbol(node, scopeNode);
			}

	}
	for(int i = 0; i < node->numChildren; i++)
	{
		analyzeBFS(node->children[i], scopeNode, depth+1);
	}
	
	//scopeNode = scopeNode->dad;
}

void addDefaultConstructors()
{
	//Este for itera sobre los scopes correspondientes a las clases
	for(int i = 0; i < scopeInic->numChildren; i++)
	{
		ScopeNode * classScope = scopeInic->children[i];
		bool hasConstructor = false;
		//Estos serán métodos, constructores o atributos
		for(int j = 0; j < classScope->numSymbols; j++)
		{
			Symbol * insideSymbol = classScope->symbols[j];
			//Nos interesan sólo los constructores.
			if(insideSymbol != NULL && !strcmp(insideSymbol->type, "CONSTRUCTOR"))
			{
				hasConstructor = true;
				break;
			}
		}
		if(!hasConstructor)
		{
			Method * conSymbol = new Method();
			conSymbol->id = scopeInic->symbols[i]->id;
			ClassSymbol * holder = (ClassSymbol*)scopeInic->symbols[i];
			holder->AddConstructor(conSymbol);
			conSymbol->scope = holder->englobingScope;
			conSymbol->isMain = false;
			conSymbol->numParams = 0;
			conSymbol->type = (char*)"CONSTRUCTOR";
			classScope->AddSymbol(conSymbol);
			symbolTable->Insert(conSymbol);
			conSymbol->visibility = PUBLIC;
			conSymbol->returnType = (char*)"void";
		}
	}
}

ScopeNode * getSymbolScope(Node* node)
{
	if(!strcmp(node->token, "ClassDeclaration"))
	{
		return getScopeByNum(((ClassSymbol*)node->symbol)->englobingScope, scopeInic);
	}
	else if(!strcmp(node->token, "MethodDeclaration"))
	{
		//printf("Attempting to get scope of MethodDeclaration with englobingScope %d\n", ((Method*)node->symbol)->englobingScope);
		return getScopeByNum(((Method*)node->symbol)->englobingScope, scopeInic);
	}
	else if(!strcmp(node->token, "ConstructorDeclaration"))
	{
		//printf("Attempting to get scope of Constructor with englobingScope %d\n", ((Method*)node->symbol)->englobingScope);
		return getScopeByNum(((Method*)node->symbol)->englobingScope, scopeInic);
	}
}

//Escribe, al encontrar un constructor, el código de inicialización de los atributos.
void writeAttributeInit(ScopeNode * scopeNode)
{
	//Recorremos, al revés, la lista de atributos de la clase. (DEBE ser al revés por el orden en que se agregaron!)
	for(int i = 0; i < currentClass->attributes.size(); i++)
	{		
		//Si el atributo tiene código de inicialización...
		if(currentClass->attributes[i]->initializerCode != NULL)
		{
			//Cargamos la variable CIL. Creamos un nodo pues loadCilVariable sólo acepta nodos.
			Node * idNode = new Node("Identifier", new Node(currentClass->attributes[i]->id, 0), 0);
			//cout << "Attempting to analyze " << currentClass->attributes[i]->id << endl;
			
			//Cargamos el código cil que guarda el valor.
			storing = true;
			loadCilVariable(idNode, scopeNode, true);
			storing = false;
			
			//Cargamos la expresión.
			analyzeExpr(currentClass->attributes[i]->initializerCode, scopeNode);
					
			//Escribimos la parte final del código CIL que guarda el valor.
			cil << postStrings.top();
			postStrings.pop();
		}
	}
}

//Arma la lista de scopes segun el arbol de derivación
void createScopeTree(Node* node, ScopeNode * scopeNode, int depth)
{
	//cout << "Se cae en " << node->token << endl;
	if(node->skipAnalysis)
	{		
		return;
	}

	//cout << "Dies in " << node->token << endl;
	//Condición de seguridad, en rigor no debería pasar.
	if(node == NULL) return;
	int i;
	
	char* open = (char*)"{";
	char* close = (char*)"}";

		char* foundToken = node->token;		
	
		if(strcmp(foundToken, close) == 0 && !aumentoEnDeclaration)
		{
			//ocurre si nos salimos de un método.
			if(scopeNode->dad->scopeNum == currentClassScope)
			{
				if(expectingReturn)
				{
					semanticErrors = true;
					stringstream ss;
					ss << "$Error(" << currentMethod->line << "): Method " << currentMethod->id << " must have a return.\n";	
					errors.push_back(new class Error(ss.str(), currentMethod->line));
					expectingReturn = false;
				}
				//Esto ocurre si el método actual es void.
				if(!strcmp(currentMethod->returnType, "void"))
				{		
					//Este caso es en el que nos salimos del scope de un método; Si es void, nos aseguramos
					//De que tenga un ret al final.				
					cil << insertTabs(scopeNode) << "ret" << endl;
					writeExplicitRet = false;
				}
				
			}
			//Esto ocurre si es que nos salimos de una clase.
			else if(scopeNode->dad->scopeNum == scopeInic->scopeNum)
			{
				
				//Intentamos encontrar el símbolo correspondiente al constructor, el cual está en el scope
				//Si éste no existe, lo escribimos.
				if(!currentClass->hasExplicitConstructor)
				{
					
					cil << insertTabs(scopeNode) << ".method public instance void .ctor() cil managed" << endl;
					cil << insertTabs(scopeNode) << "{" << endl;					
					scopeNode = incrementScope(scopeNode); //Aumentamos el scope.
					
					//Si la clase hereda de otra, DEBEMOS agregar una llamada al constructor por defecto.
					if(currentClass->hasBase)
					{
						cil << insertTabs(scopeNode) << "ldarg.0" << endl;
						cil << insertTabs(scopeNode) << "call instance void " << currentClass->baseClass->id << "::.ctor()"	<< endl;
					}
					
					writeAttributeInit(scopeNode);	//Escribimos la inicialización para los atributos.
					cil << insertTabs(scopeNode) << "ret" << endl;	//Retornamos...
					cil << insertTabs(scopeNode->dad) << "}" << endl;	//Y escribimos la llave final.
					scopeNode = scopeNode->dad;	//Se disminuye el scope al anterior.
				}
			}
			//Se inserta una llave en el cil.
			cil << insertTabs(scopeNode->dad) << "}\n\n";
		}
				//Entramos a un constructor	
		else if(!strcmp(foundToken, open) && scopeNode->dad->scopeNum == currentClass->englobingScope &&  !strcmp(currentMethod->type, "CONSTRUCTOR" ))
		{			
			writeAttributeInit(scopeNode);
		}
		
		//Si es null, hubo un error y no analiza lo que está adentro para evitar segfaulting.

		if(!strcmp(foundToken, "ClassDeclaration"))
		{
			writeClassCil(node);
			cil << insertTabs(scopeNode) << "{" << endl;
			scopeNode = getSymbolScope(node);
			//printf("Scope node increased to %d\n", scopeNode->scopeNum);
			
		}
		else if(!strcmp(foundToken, "MethodDeclaration"))
		{			
			scopeNode = getSymbolScope(node);
			//printf("Got scopeNode %d\n", scopeNode->scopeNum);
			//printf("Scope node increased to %d\n", scopeNode->scopeNum);
			writeMethodCil(node);			
		}
		else if(!strcmp(foundToken, "WhileStmt") | !strcmp(foundToken, "WhileStmtNoShortIf") | !strcmp(foundToken, "IfThenStmt") | !strcmp(foundToken, "IfThenElseStmt") | !strcmp(foundToken, "IfThenElseStmtNoShortIf") | !strcmp(foundToken, "ForStmt") | !strcmp(foundToken, "ForStmtNoShortIf") | !strcmp(foundToken, "DoStmt") | !strcmp(foundToken, "SwitchStmt"))
{
			//printf("*se aumento en declaration, %s, dad->%s, scope: %i \n", foundToken, node->token, scopeNode->scopeNum);
			scopeNode = incrementScope(scopeNode);
			if(!strcmp(foundToken, "IfThenStmt") )
			{
				numNode* flujo = new numNode(IF);
				flujo->setDad(ordenFlujo);
				ordenFlujo = flujo;

				ifCount++;
				numNode* nuevo = new numNode(ifCount);
				nuevo->setDad(ifNode);
				ifNode = nuevo;

numNode* nuevoElse = new numNode(-1); //se cambia solo cuando nos encontramos con el else
				nuevoElse->setDad(elseNode);
				elseNode = nuevoElse;

				cil << insertTabs(scopeNode->dad) << "IF_" << ifNode->getNum() << ":" << endl;
				ifThenToCil(node, scopeNode);
			}
			else if(!strcmp(foundToken, "IfThenElseStmt") | !strcmp(foundToken, "IfThenElseStmtNoShortIf") )
			{

				numNode* flujo = new numNode(IF);
				flujo->setDad(ordenFlujo);
				ordenFlujo = flujo;

				ifCount++;
				numNode* nuevo = new numNode(ifCount);
				nuevo->setDad(ifNode);
				ifNode = nuevo;


				numNode* nuevoElse = new numNode(-1); //se cambia solo cuando nos encontramos con el else
				nuevoElse->setDad(elseNode);
				elseNode = nuevoElse;

				cil << insertTabs(scopeNode->dad) << "IF_" << ifNode->getNum() << ":" << endl;
				ifThenElseToCil(node, scopeNode);
			}
			else if(!strcmp(foundToken, "WhileStmt") | !strcmp(foundToken, "WhileStmtNoShortIf"))
			{
				numNode* flujo = new numNode(WHILE);
				flujo->setDad(ordenFlujo);
				ordenFlujo = flujo;

				whileCount++;
				numNode* nuevo = new numNode(whileCount);
				nuevo->setDad(whileNode);
				whileNode = nuevo;
				whileToCil(node, scopeNode);
			}
			else if(!strcmp(foundToken, "ForStmt") | !strcmp(foundToken, "ForStmtNoShortIf") )
			{
				numNode* flujo = new numNode(FOR);
				flujo->setDad(ordenFlujo);
				ordenFlujo = flujo;

				forCount++;
				numNode* nuevo = new numNode(forCount);
				nuevo->setDad(forNode);
				forNode = nuevo;

				cil << endl << insertTabs(scopeNode->dad) << "FOR_" << forCount <<":" << endl;
				forToCil(node, scopeNode);
			}
			else if(!strcmp(foundToken, "DoStmt") )
			{
				numNode* flujo = new numNode(DO);
				flujo->setDad(ordenFlujo);
				ordenFlujo = flujo;

				doCount++;
				numNode* nuevo = new numNode(doCount);
				nuevo->setDad(doNode);
				doNode = nuevo;
				//doToCil se llama al final del do

				cil << endl << insertTabs(scopeNode->dad) << "DO_" << doCount <<":" << endl;
			}
			else if(!strcmp(foundToken, "SwitchStmt") )
			{
				caseCount = 0;

				numNode* flujo = new numNode(SWITCH);
				flujo->setDad(ordenFlujo);
				ordenFlujo = flujo;

				switchCount++;
				numNode* nuevo = new numNode(switchCount);
				nuevo->setDad(switchNode);
				nuevo->extra = 0;
				switchNode = nuevo;

				cil << endl << insertTabs(scopeNode->dad) << "SWITCH_" << switchCount <<":" << endl;
				//testswitch
				cil << insertTabs(scopeNode->dad) << "ldc.i4 0" << endl;

				//switchToCil(node, scopeNode);
			}
			else
				cil << "Se encontró algo raro en los statements de flujo: " << foundToken << endl;

		}
		else if(!strcmp(foundToken, "else"))
		{
			/*numNode* flujo = new numNode(ELSE);
			flujo->setDad(ordenFlujo);
			ordenFlujo = flujo;*/

			elseNode->setNum(ifNode->getNum());
//cil << "se cambio el numero del else node po: " << ifNode->getNum();
			cil << insertTabs(scopeNode->dad) << "br END_IF_" << ifNode->getNum() << endl;
			//cil << insertTabs(scopeNode->dad) << "ELSE_IF_" << ifNode->getNum()<< ":" << endl;
			cil << insertTabs(scopeNode->dad) << "ELSE_BODY_" << ifNode->getNum() << ":" << endl;
			scopeNode = scopeNode->dad;
//cil << "se disminuyo scope en el else" <<endl;
			elseCount++;
		}
		else if(!strcmp(foundToken, "while"))
		{
			if(!strcmp(node->parent->token, "DoStmt"))
			{	
				doToCil(node, scopeNode);
			}
		}
		else if(!strcmp(foundToken, "SwitchLabel"))
		{
			if(!strcmp(node->children[0]->token, "case"))
			{
				int num = caseNode->getNum();
				num++;

				numNode* nuevo = new numNode(num);
				nuevo->setDad(caseNode);
				caseNode = nuevo;
				
				//Primero cargamos el valor del switch
				/*Node* switchParent = node->parent; //SwitchLabel->SwitchBlockStmtGroup
				while(strcmp(switchParent->token, "SwitchStmt"))
				{
					switchParent = switchParent->parent;
				}
				Node* switchCond = switchParent->children[2];
				loadCilVariable(switchCond, scopeNode, false);*/
	cil<< insertTabs(scopeNode->dad)<< "ldc.i4 1"<< endl;
		cil<< insertTabs(scopeNode->dad)<< "ceq"<< endl;
cil<< insertTabs(scopeNode->dad)<< "brtrue SWITCH_" << switchNode->getNum() << "_CASE_" << caseNode->getNum() << "_BODY" << endl;
		cil<< insertTabs(scopeNode->dad)<< "ldc.i4 0"<< endl;

				cil<< insertTabs(scopeNode->dad)<< "SWITCH_" << switchNode->getNum() << "_CASE_" << caseNode->getNum() << ":" << endl;

				Node* swStmt = node;
				bool encontrado = false;
				while(!encontrado)
				{
					swStmt = swStmt->parent;
					if(!strcmp(swStmt->token, "SwitchStmt"))
					encontrado = true;					
				}
	
				caseToCil(node, swStmt, scopeNode);
//testswitch
				cil<< insertTabs(scopeNode->dad)<< "pop"<< endl;
cil<< insertTabs(scopeNode->dad)<< "SWITCH_" << switchNode->getNum() << "_CASE_" << caseNode->getNum() << "_BODY:" << endl;
				cil<< insertTabs(scopeNode->dad)<< "ldc.i4 1"<< endl;
			}
			else
			{
				cil << insertTabs(scopeNode->dad)<< "SWITCH_" << switchNode->getNum() << "_DEFAULT:" << endl;
//testswitch
				//sino entro en un case anterior no entramos (no hay cascada)
				cil  << insertTabs(scopeNode->dad)<< "ldc.i4 0" << endl;
				cil  << insertTabs(scopeNode->dad)<< "ceq" << endl;
				cil<< insertTabs(scopeNode->dad)<< "brtrue END_SWITCH_"<< switchNode->getNum() << "_DEFAULT" << endl;
				cil<< insertTabs(scopeNode->dad)<< "SWITCH_"<< switchNode->getNum() << "_DEFAULT_BODY:" << endl;
				cil<< insertTabs(scopeNode->dad)<< "ldc.i4 1"<< endl;

			}
		}
		else if(!strcmp(foundToken, "SwitchBlock"))
		{
			cil<< insertTabs(scopeNode->dad)  << "{"<< endl;
		}

		else if(!strcmp(foundToken, "Block"))
		{
			bloque = true;
			
			if(strcmp(node->parent->token, "MethodDeclaration") && strcmp(node->parent->token, "MethodBody"))
			{
				cil << insertTabs(scopeNode) << "{" << endl;
			}
			/*if(!ifElse)
				cil<< insertTabs(scopeNode->dad)  << "{"<< endl;	
			else*/
		
		}
		else if(!strcmp(foundToken, "ConstructorDeclaration"))
		{			
			scopeNode = getSymbolScope(node);
			writeConstructorCil(node);
		}
		else if(!strcmp(foundToken, "ConstructorBody"))
		{
			
			cil << insertTabs(scopeNode->dad) << "{\n";
			Method * constructor = currentMethod;
			
			//Si no hay llamada explícita a constructor y heredamos de otra 
			//clase, llamamos a su constructor por defecto.
			if(!constructor->hasExplicitConInv && currentClass->hasBase)
			{
				//Pero, debemos revisar si la clase base no tiene constructores. Esto generaría error si es que NO tiene un constructor que recibe 0 parámetros. REVISAR.
				if(currentClass->baseClass->hasExplicitConstructor)
				{
					bool hasEmpty = false;
					for(int i = 0; i < currentClass->baseClass->constructors.size(); i++)
					{
						Method * baseCons = currentClass->baseClass->constructors[i];
						if(baseCons->params.size() == 0)
							hasEmpty = true;
					}
					if(!hasEmpty)
					{
						stringstream ss;
						//REVISAR: Esta linea es invalida...
						ss << "$Error(" << currentMethod->line << "): Must explicitly call adequate base class constructor." << endl;
						errors.push_back(new class Error(ss.str(), currentMethod->line));
					}
					else
					{
						cil << insertTabs(scopeNode) << "ldarg.0" << endl;
						cil << insertTabs(scopeNode) << "call instance void " << currentClass->baseClass->id << "::.ctor()"	<< endl;
					}
				}
				else
				{			
					cil << insertTabs(scopeNode) << "ldarg.0" << endl;
					cil << insertTabs(scopeNode) << "call instance void " << currentClass->baseClass->id << "::.ctor()"	<< endl;
				}
			}
		}
		else if(!strcmp(foundToken, "FormalParameter"))
		{
			//printf("*se llama a formal parameter\n");
			writeParamCil(node);
		}
		else if(!strcmp(foundToken, "LocalVariableDeclaration") && strcmp(node->parent->token, "ForStmt") && strcmp(node->parent->token, "ForStmtNoShortIf") )
		{		

			//printf("*se llama a local variable declaration\n");
			analyzeLocalVarDeclarationSymbol(node, scopeNode);
			
		}
		else if(!strcmp(foundToken, "ExprStmt"))
		{
			analyzeExprStmt(node, scopeNode);
		}
		else if(!strcmp(foundToken, "PostIncrementExpr") | !strcmp(foundToken, "PreIncrementExpr") | !strcmp(foundToken, "PostDecrementExpr") | !strcmp(foundToken, "PreDecrementExpr"))
		{
			//para i++ y similares que estan solos y no en una asignacion o declaracion
			if(!strcmp(node->parent->token, "ExprStmt"))
			{
				analyzeExpr(node, scopeNode);  
			}

		}
		else if(!strcmp(foundToken, "ExplicitConstructorInvocation"))
		{
			analyzeExpr(node, scopeNode);
		}
		else if(!strcmp(foundToken, "FieldDeclaration"))
       		{
       			writeFieldCil(node);
		}
		else if(!strcmp(foundToken, "ReturnStmt"))
		{
			analyzeBlockStmts(node, scopeNode);
			expectingReturn = false;
			writeExplicitRet = false;
		}
		else if(!strcmp(foundToken, "ContinueStmt"))
		{
			continueToCil(node, scopeNode);
		}
		else if(!strcmp(foundToken, "BreakStmt")) //Necesitamos hacer un salto incondicional al final del s
		{
			breakToCil(node, scopeNode);
		}
		
		
		if(node->visited == false && currentClass != NULL && scopeNode->scopeNum > currentClass->englobingScope)	//La segunda condición asegura que al inicializar atributos no escribamos cil donde no corresponde xD
		{	
			//printf("Calling analyzeBlockStmts with scopeNode %d\n", scopeNode->scopeNum);
			analyzeBlockStmts(node, scopeNode);
		}
		

		

		//printf("Error en %s scope %d, children %d\n", node->token, scopeNode->scopeNum, node->numChildren);
		for(i = 0; i < node->numChildren; i++)
		{		
			Node* child = node->children[i];		
			createScopeTree(child, scopeNode, depth+1);
		
		}

	//printf("Current node: %s, scope: %d, depth: %d\n",node->token, scopeNode->scopeNum, depth);

		//Para cerrar los "controles de flujo":
		 if(!strcmp(foundToken, "WhileStmt") | !strcmp(foundToken, "WhileStmtNoShortIf") | !strcmp(foundToken, "IfThenStmt") | !strcmp(foundToken, "IfThenElseStmt") | !strcmp(foundToken, "IfThenElseStmtNoShortIf") | !strcmp(foundToken, "ForStmt") | !strcmp(foundToken, "ForStmtNoShortIf") | !strcmp(foundToken, "DoStmt")| !strcmp(foundToken, "SwitchStmt"))
		{
			//cil << insertTabs(scopeNode) << "}f\n\n";
//cil << ordenFlujo->getNum() << " token: " << foundToken <<endl;
			if(ordenFlujo->getNum() ==ELSE)
			{
				cil << insertTabs(scopeNode->dad) << "END_IF_" << ifNode->getNum() <<":" << endl;
				ifNode = ifNode->getDad();
				elseNode = elseNode->getDad();
			}
			else if(ordenFlujo->getNum() == IF ) //Estamos dentro de un bloque if o ifelse
			{
				cil << insertTabs(scopeNode->dad) << "END_IF_" << ifNode->getNum() <<":" << endl;
				//cil << insertTabs(scopeNode->dad) << "END_ELSE_IF_" << elseNode->getNum() <<":" << endl;
				ifNode = ifNode->getDad();
				elseNode = elseNode->getDad(); //Se crea un if fantasma
			}
			else if(ordenFlujo->getNum() == WHILE)
			{
				
				cil << insertTabs(scopeNode->dad) << "br WHILE_CONDITION_" << whileNode->getNum() << endl;
				cil << insertTabs(scopeNode->dad) << "END_WHILE_" << whileNode->getNum() <<":" << endl;
				
				whileNode = whileNode->getDad();
			}
			else if(ordenFlujo->getNum() == FOR)
			{
				
				cil << insertTabs(scopeNode->dad) << "br FOR_UPDATE_" << forNode->getNum() << endl;
				cil << insertTabs(scopeNode->dad) << "END_FOR_" << forNode->getNum() <<":" << endl;
					
				forNode = forNode->getDad();
			}
			else if(ordenFlujo->getNum() == DO)
			{					
				cil << insertTabs(scopeNode->dad) << "END_DO_" << doNode->getNum() <<":" << endl;
				doNode = doNode->getDad();
			}
			else if(ordenFlujo->getNum() == SWITCH )
			{
				cil << insertTabs(scopeNode->dad) << "END_SWITCH_" << switchNode->getNum() <<":" << endl;
				//testswitch
				if(switchNode->extra == 1)
				{
					cil << insertTabs(scopeNode->dad) << "ldc.i4 0" << endl;
					cil << insertTabs(scopeNode->dad) << "ceq" << endl;
					cil << insertTabs(scopeNode->dad) << "brtrue SWITCH_" << switchNode->getNum() << "_DEFAULT_BODY" << endl;
				}
				else if (switchNode->extra == 0) //No hay default
					cil << insertTabs(scopeNode->dad) << "pop" << endl; //Se saca el flag del stack
				else //Hay mas de un default
				{
					semanticErrors = true;	
					int line = node->getLine();
					stringstream ss;
					ss << "Line " << line << ": There is more than one 'default' label present in this switch" << endl;
					errors.push_back(new class Error(ss.str(), line));
				}
				
				switchNode = switchNode->getDad();
			}

			if(ordenFlujo->getNum() != -1)
			{
//cil << "orden flujo antes era: " << ordenFlujo->getNum();
				ordenFlujo = ordenFlujo->getDad();
//cil << " orden flujo ahora es: " << ordenFlujo->getNum()<< endl;
			}

		}
		else if(/*!strcmp(foundToken, "SwitchLabel") && (!strcmp(node->parent->token, "SwitchBlock")  || (strcmp(node->parent->parent->token, "SwitchBlockStmtGroup") && strcmp(node->parent->token, "SwitchBlockStmtGroup")) )*/ (!strcmp(foundToken, "SwitchLabel")&& strcmp(node->parent->token, "SwitchBlockStmtGroup") && (node->indexArrayParent < (node->parent->numChildren-1)))|| !strcmp(foundToken, "SwitchBlockStmtGroup") || (!strcmp(foundToken, "SwitchLabel")&& !strcmp(node->parent->token, "SwitchLabels") && !strcmp(node->parent->parent->token, "SwitchLabels") ))
		{
			//cil<< insertTabs(scopeNode->dad)<< "br END_SWITCH_"<< switchNode->getNum()<< endl;
//int num = node->parent->numChildren -1;
//cil << "foundTOken: " << foundToken << " parentNumChild: " << num << " node Index: " <<  node->indexArrayParent << endl;

			if((!strcmp(foundToken, "SwitchBlockStmtGroup") && 
(!strcmp(node->children[0]->children[0]->token, "default") || (node->children[0]->numChildren == 2 && !strcmp(node->children[0]->children[1]->children[0]->token, "default"))) )|| 
((!strcmp(node->children[0]->token, "default") || (node->numChildren == 2 && !strcmp(node->children[1]->children[0]->token, "default")) && !strcmp(foundToken, "SwitchLabel"))))
			{
				cil<< insertTabs(scopeNode->dad)<< "br REAL_END_SWITCH_" << switchNode->getNum() << "_DEFAULT" <<endl;
				cil<< insertTabs(scopeNode->dad)<< "END_SWITCH_" << switchNode->getNum() << "_DEFAULT:" <<endl;
				//testswitch
				cil  << insertTabs(scopeNode->dad)<< "ldc.i4 0" << endl;
				cil<< insertTabs(scopeNode->dad)<< "REAL_END_SWITCH_" << switchNode->getNum() << "_DEFAULT:" <<endl;
				switchNode->extra = switchNode->extra + 1;
			}
			else
				cil<< insertTabs(scopeNode->dad)<< "END_SWITCH_" << switchNode->getNum() << "_CASE_" << caseNode->getNum() << ":" <<endl;
		}

		
}
/*
bool setEndCase (Node* node)
{
	if(!strcmp(foundToken, "SwitchLabel") && node->indexArrayParent < node->parent->numChildren)

}*/

ScopeNode* incrementScope (ScopeNode* scopeNode)
{
	numScope++;	//Se aumenta el contador de scopes.
	ScopeNode* newNode = new ScopeNode (numScope, scopeNode);	//Se crea un nuevo scopeNode.
	scopeNode->AddChild(newNode);	//Al scopeNode actual se le asigna el nuevo como hijo.
	
	if(currentClass != NULL && !currentClass->addedThis)	//Si estamos en una clase y no le hemos agregado el símbolo this, lo hacemos.
	{
		Symbol * thisSymbol = new Symbol();
		thisSymbol->id = (char*)"this";
		thisSymbol->type = (char*)"PREDEFINED";
		thisSymbol->scope = numScope;
		newNode->AddSymbol(thisSymbol);
		currentClass->addedThis = true;	
		symbolTable->Insert(thisSymbol);	
	}	
	
	return newNode;
}

//Método para podar.
void cutTree(Node *actual, Node *lastToken)
{	
	//Corta todo nodo que sólo tenga un hijo y que además el hijo no sea hoja. Esto se hace para preservar cierta información como tipo de literales.
	for(int i = 0; i < actual->numChildren; i++)
	{	
		while(actual->children[i]->numChildren == 1 && actual->children[i]->children[0]->numChildren > 0)
			actual->children[i] = actual->children[i]->children[0];		
			
		cutTree(actual->children[i], actual);
	}

}

//Se imprimen los scopesHijos y luego se buscan los scopesHijos de los hijos
void printScope(ScopeNode * scopeNode)
{
	if(scopeNode != NULL)
	{
		int numChildren = scopeNode->numChildren;
		if(numChildren > 0)
		{
			for(int i = 0; i < numChildren; i++)	
			{
				printChild(scopeNode->getChild(i));
				printSymbols(scopeNode->getChild(i));
				printScope(scopeNode->getChild(i));
			}
		}
	}	
	else
	{
		printf("scopeNode es nulo!");
	}
}



//Imprime toda la ascendencia de un scope.
void printChild(ScopeNode * scopeNode)
{
	if( scopeNode == NULL) return;
	
	int num = scopeNode->scopeNum;
	if(scopeNode->dad == NULL) 
	{
		printf("%i: \n", num);
		return;
	}
	else
	{
		printf("%i->", num);
		printChild(scopeNode->dad);
	}
}

//Se imprimen los hijos correspondientes para cada scope, para la tabla de scopes
void printSymbols (ScopeNode* scopeNode)
{

	int numSymbols = scopeNode->numSymbols;
	for(int i = 0; i < numSymbols; i++)
	{
		Symbol* sym = scopeNode->getSymbol(i);
		printf("   %s (%s)\n", sym->id, sym->type);
	}
}

//Revisa scope por scope y solicita imprimir los simbolos pertinentes a cada uno.
void printSymbolTree (ScopeNode *scopeNode)
{

	printSymbolsDetail(scopeNode);
	if(scopeNode != NULL)
	{
		int numChildren = scopeNode->numChildren;
		while(numChildren > 0)
		{ 
			for(int i = 0; i < numChildren; i++)	
			{
				printSymbolsDetail(scopeNode->children[i]);
			}
			scopeNode = scopeNode->children[0];
			numChildren = scopeNode->numChildren;
		}
	}	
	else
	{
		printf("scopeNode es nulo!");
	}

}

//Imprime el detalle de todos los simbolos de un scope
void printSymbolsDetail (ScopeNode *scopeNode)
{
	int num = scopeNode->numSymbols;

	for (int i = 0; i < num; i++)
	{
		Symbol* sym = scopeNode->getSymbol(i);

		printf("%s (%s):\n", sym->id, sym->type);

		if(!strcmp(sym->type, "VARIABLE") )
		{
			Variable* var = (Variable*)scopeNode->getSymbol(i);
			prints((char*)"Tipo", var->variableType);
			prints((char*)"Valor", var->value);
			printi((char*)"Num Dimensiones", var->numDimensions);
		}

		else if(!strcmp(sym->type, "CLASS"))
		{
			ClassSymbol* clase = (ClassSymbol*)scopeNode->getSymbol(i);
			printi((char*)"Visibilidad", clase->visibility);
		}
		else if(!strcmp(sym->type, "PARAMETER"))
		{
			Parameter* param = (Parameter*)scopeNode->getSymbol(i);
			prints((char*)"Tipo", param->paramType);
			//prints((char*)"Valor", param->value);
			printi((char*)"Num Dimensiones", param->numDimensions);
		
		}
		else if(!strcmp(sym->type, "METHOD") || !strcmp(sym->type, "CONSTRUCTOR"))
		{
			Method* met = (Method*)scopeNode->getSymbol(i);
			printi((char*)"Visibilidad", met->visibility);
			prints((char*)"Tipo de retorno", met->returnType);
		}
		else if(!strcmp(sym->type, "ATTRIBUTE"))
		{
			Attribute* var = (Attribute*)scopeNode->getSymbol(i);
			printi((char*)"Visibilidad", var->visibility);
			prints((char*)"Tipo", var->variableType);
			prints((char*)"Valor", var->value);
		}
	}

}

char* getVis(int num)
{

	if(num == 0)
	{
		return (char*)"public ";
	}
	else if(num == 1)
	{
		return (char*)"family ";
	}
	else if(num == 2 || num == 3)
	{
		return (char*)"private ";
	}
	else
		return (char*)" ";

}

//Imprime dos string
void prints(char* descripcion, char * valor)
{
	printf("   %s: %s\n", descripcion, valor);
}

//imprime un string y un int
void printi(char* descripcion, int valor)
{
	printf("   %s: %i\n", descripcion, valor);
}

vector<string> splitStr(string toSplit, string splitStr)
{
	vector<string> toReturn;
	
	size_t jumpPos = toSplit.find(splitStr);
//	cout << "\n\n\nCOMENZAMOS SPLITTING:\n\n\n";
	while(jumpPos!=string::npos)
	{
		string line = toSplit.substr(0, jumpPos);
		toReturn.push_back(line);
		
//		cout << line.c_str() << endl;
//		cout << "-------------" << endl;
		toSplit = toSplit.substr(jumpPos + 1);
		jumpPos = toSplit.find(splitStr);
	}
	if(toSplit.length()>0) toReturn.push_back(toSplit);
	return toReturn;
}

vector<string> splitStr(string toSplit)
{
	return splitStr(toSplit, "\n");
}

string concatStr(vector<string> toConcat)
{
	string toReturn = "";
	for(int i = 0; i < toConcat.size(); i++)
	{
		toReturn = toReturn + toConcat[i] + "\n";
	}
	if(toReturn != "") toReturn = toReturn.substr(0, toReturn.length() - 1);
	
	return toReturn;
}

