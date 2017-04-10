/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     END = 0,
     Identifier = 258,
     StringLiteral = 259,
     FloatingPointLiteral = 260,
     CharLiteral = 261,
     IntegerLiteral = 262,
     DoubleQuote = 263,
     Underscore = 264,
     Letter = 265,
     SingleQuote = 266,
     Error = 267,
     TrueOrFalse = 268,
     Boolean = 269,
     Float = 270,
     Int = 271,
     Char = 272,
     Corchete = 273,
     punto = 274,
     Class = 275,
     Extends = 276,
     OpenLlave = 277,
     CloseLlave = 278,
     Coma = 279,
     PuntoComa = 280,
     variableDeclarator = 281,
     Void = 282,
     OpenParentesis = 283,
     This = 284,
     If = 285,
     Else = 286,
     Switch = 287,
     Case = 288,
     Default = 289,
     DosPtos = 290,
     While = 291,
     Do = 292,
     For = 293,
     Break = 294,
     Continue = 295,
     Return = 296,
     New = 297,
     AddOp = 298,
     Not = 299,
     MultOp = 300,
     And = 301,
     Or = 302,
     Tongo = 303,
     OpenCorchete = 304,
     CloseCorchete = 305,
     super = 306,
     modifier = 307,
     CloseParentesis = 308,
     Equals = 309,
     Relacion = 310,
     Igualdad = 311,
     OrOr = 312,
     AndAnd = 313,
     PlusPlus = 314,
     MinusMinus = 315,
     Prec1 = 316
   };
#endif
/* Tokens.  */
#define END 0
#define Identifier 258
#define StringLiteral 259
#define FloatingPointLiteral 260
#define CharLiteral 261
#define IntegerLiteral 262
#define DoubleQuote 263
#define Underscore 264
#define Letter 265
#define SingleQuote 266
#define Error 267
#define TrueOrFalse 268
#define Boolean 269
#define Float 270
#define Int 271
#define Char 272
#define Corchete 273
#define punto 274
#define Class 275
#define Extends 276
#define OpenLlave 277
#define CloseLlave 278
#define Coma 279
#define PuntoComa 280
#define variableDeclarator 281
#define Void 282
#define OpenParentesis 283
#define This 284
#define If 285
#define Else 286
#define Switch 287
#define Case 288
#define Default 289
#define DosPtos 290
#define While 291
#define Do 292
#define For 293
#define Break 294
#define Continue 295
#define Return 296
#define New 297
#define AddOp 298
#define Not 299
#define MultOp 300
#define And 301
#define Or 302
#define Tongo 303
#define OpenCorchete 304
#define CloseCorchete 305
#define super 306
#define modifier 307
#define CloseParentesis 308
#define Equals 309
#define Relacion 310
#define Igualdad 311
#define OrOr 312
#define AndAnd 313
#define PlusPlus 314
#define MinusMinus 315
#define Prec1 316




/* Copy the first part of user declarations.  */
#line 1 "bison.y"



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




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 178 "bison.y"
{	
	char* str;
	class Node* node;
}
/* Line 193 of yacc.c.  */
#line 395 "bison.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 420 "bison.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4293

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  104
/* YYNRULES -- Number of rules.  */
#define YYNRULES  346
/* YYNRULES -- Number of states.  */
#define YYNSTATES  710

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    10,    12,    14,    16,
      18,    20,    22,    24,    26,    28,    30,    32,    34,    37,
      39,    41,    43,    47,    51,    55,    59,    63,    68,    73,
      75,    77,    81,    86,    88,    91,    93,    95,    97,   100,
     102,   108,   113,   118,   123,   128,   134,   140,   146,   152,
     157,   160,   164,   169,   172,   174,   177,   179,   181,   183,
     185,   190,   194,   198,   200,   204,   206,   210,   214,   216,
     220,   223,   228,   230,   233,   237,   240,   244,   247,   252,
     256,   260,   262,   266,   270,   273,   275,   277,   281,   284,
     289,   293,   298,   304,   307,   312,   316,   320,   323,   326,
     330,   334,   339,   343,   348,   353,   359,   365,   370,   376,
     381,   386,   391,   397,   403,   410,   416,   421,   426,   432,
     438,   445,   451,   455,   458,   461,   466,   470,   472,   475,
     477,   479,   482,   485,   487,   489,   491,   493,   495,   497,
     499,   501,   503,   505,   507,   509,   511,   513,   515,   517,
     519,   521,   524,   527,   529,   531,   533,   535,   537,   539,
     541,   547,   553,   559,   565,   570,   578,   586,   594,   602,
     609,   614,   622,   630,   638,   646,   653,   659,   665,   671,
     677,   682,   686,   691,   695,   699,   702,   707,   711,   715,
     718,   724,   729,   733,   737,   739,   742,   745,   747,   750,
     754,   757,   761,   765,   770,   776,   782,   788,   794,   799,
     805,   811,   817,   823,   828,   836,   844,   852,   860,   867,
     875,   883,   892,   899,   903,   913,   922,   931,   939,   948,
     956,   964,   971,   978,   986,   994,  1002,  1012,  1021,  1030,
    1038,  1047,  1055,  1063,  1070,  1077,  1085,  1093,  1101,  1103,
    1105,  1107,  1109,  1113,  1116,  1120,  1123,  1127,  1130,  1132,
    1134,  1136,  1138,  1142,  1144,  1146,  1148,  1150,  1156,  1161,
    1163,  1167,  1171,  1175,  1180,  1184,  1189,  1193,  1197,  1201,
    1205,  1207,  1210,  1214,  1218,  1221,  1225,  1229,  1233,  1238,
    1242,  1249,  1255,  1262,  1268,  1273,  1278,  1283,  1285,  1287,
    1289,  1291,  1294,  1297,  1299,  1301,  1304,  1306,  1309,  1312,
    1314,  1317,  1319,  1325,  1330,  1335,  1341,  1347,  1352,  1354,
    1358,  1360,  1364,  1366,  1370,  1372,  1376,  1378,  1382,  1384,
    1388,  1390,  1394,  1396,  1400,  1402,  1406,  1408,  1410,  1412,
    1416,  1418,  1420,  1422,  1424,  1426,  1428
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      63,     0,    -1,    64,    -1,    -1,    75,    -1,     7,    -1,
       5,    -1,     6,    -1,     4,    -1,    13,    -1,    67,    -1,
      70,    -1,    68,    -1,    14,    -1,    69,    -1,    15,    -1,
      16,    -1,    17,    -1,     1,    25,    -1,    71,    -1,    72,
      -1,    73,    -1,    67,    49,    50,    -1,    73,    49,    50,
      -1,     1,    49,    50,    -1,    73,     1,    50,    -1,    67,
       1,    50,    -1,    73,    49,     1,    25,    -1,    67,    49,
       1,    25,    -1,     3,    -1,    74,    -1,    73,    19,     3,
      -1,    73,    19,     1,    25,    -1,    76,    -1,    75,    76,
      -1,    79,    -1,    25,    -1,    78,    -1,    77,    78,    -1,
      52,    -1,    77,    20,     3,    80,    81,    -1,    77,    20,
       3,    81,    -1,    77,     1,     3,    81,    -1,    77,    20,
       1,    81,    -1,     1,    20,     3,    81,    -1,    77,     1,
       3,    80,    81,    -1,    77,    20,     1,    80,    81,    -1,
       1,    20,     3,    80,    81,    -1,    77,    20,     3,     1,
      81,    -1,    77,     3,     3,    81,    -1,    21,    71,    -1,
      22,    82,    23,    -1,    22,    82,     1,     0,    -1,    82,
      23,    -1,    83,    -1,    82,    83,    -1,    84,    -1,    96,
      -1,    85,    -1,    90,    -1,    77,    66,    86,    25,    -1,
      66,    86,    25,    -1,    77,    66,    25,    -1,    87,    -1,
      86,    24,    87,    -1,    88,    -1,    88,    54,    89,    -1,
      88,     1,    89,    -1,     3,    -1,    88,    49,    50,    -1,
      88,    50,    -1,    88,    49,     1,    25,    -1,   164,    -1,
      91,    95,    -1,    77,    66,    92,    -1,    66,    92,    -1,
      77,    27,    92,    -1,    27,    92,    -1,     3,    28,    93,
      53,    -1,     3,    28,    53,    -1,    92,    49,    50,    -1,
      94,    -1,    93,    24,    94,    -1,    93,     1,    94,    -1,
      66,    88,    -1,   100,    -1,    25,    -1,    77,    97,    98,
      -1,    97,    98,    -1,     3,    28,    93,    53,    -1,     3,
      28,    53,    -1,     1,    28,    93,    53,    -1,     3,    28,
      93,     1,    22,    -1,     3,    53,    -1,    22,    99,   101,
      23,    -1,    22,    99,    23,    -1,    22,   101,    23,    -1,
      22,    23,    -1,     1,    23,    -1,     1,    99,    23,    -1,
       1,   101,    23,    -1,     1,    99,   101,    23,    -1,    22,
       1,     0,    -1,    22,    99,     1,     0,    -1,    22,   101,
       1,     0,    -1,    22,    99,   101,     1,     0,    -1,    29,
      28,   134,    53,    25,    -1,    29,    28,    53,    25,    -1,
      51,    28,   134,    53,    25,    -1,    51,    28,    53,    25,
      -1,    51,     1,    53,    25,    -1,    51,    28,     1,    25,
      -1,    51,     1,   134,    53,    25,    -1,    51,    28,   134,
       1,    25,    -1,    51,    28,   134,    53,     1,    23,    -1,
      51,    28,    53,     1,    23,    -1,    29,     1,    53,    25,
      -1,    29,    28,     1,    25,    -1,    29,     1,   134,    53,
      25,    -1,    29,    28,   134,     1,    25,    -1,    29,    28,
     134,    53,     1,    23,    -1,    29,    28,    53,     1,    23,
      -1,    22,   101,    23,    -1,    22,    23,    -1,     1,    23,
      -1,    22,   101,     1,     0,    -1,    22,     1,     0,    -1,
     102,    -1,   101,   102,    -1,   103,    -1,   105,    -1,   104,
      25,    -1,    66,    86,    -1,   107,    -1,   111,    -1,   112,
      -1,   120,    -1,   123,    -1,   107,    -1,   113,    -1,   121,
      -1,   124,    -1,   100,    -1,   108,    -1,   109,    -1,   114,
      -1,   122,    -1,   128,    -1,   129,    -1,   130,    -1,    25,
      -1,   110,    25,    -1,   110,     1,    -1,   161,    -1,   146,
      -1,   147,    -1,   143,    -1,   144,    -1,   140,    -1,   133,
      -1,    30,    28,   164,    53,   105,    -1,    30,     1,   164,
      53,   105,    -1,    30,    28,   164,     1,   105,    -1,    30,
      28,     1,    53,   105,    -1,    30,     1,    53,   105,    -1,
      30,    28,   164,    53,   106,    31,   105,    -1,    30,     1,
     164,    53,   106,    31,   105,    -1,    30,    28,   164,     1,
     106,    31,   105,    -1,    30,    28,     1,    53,   106,    31,
     105,    -1,    30,     1,    53,   106,    31,   105,    -1,    30,
       1,    31,   105,    -1,    30,    28,   164,    53,   106,    31,
     106,    -1,    30,     1,   164,    53,   106,    31,   106,    -1,
      30,    28,   164,     1,   106,    31,   106,    -1,    30,    28,
       1,    53,   106,    31,   106,    -1,    30,     1,    53,   106,
      31,   106,    -1,    32,    28,   164,    53,   115,    -1,    32,
       1,   164,    53,   115,    -1,    32,    28,   164,     1,   115,
      -1,    32,    28,     1,    53,   115,    -1,    32,     1,    53,
     115,    -1,    32,     1,   115,    -1,    22,   116,   118,    23,
      -1,    22,   116,    23,    -1,    22,   118,    23,    -1,    22,
      23,    -1,     1,   116,   118,    23,    -1,     1,   116,    23,
      -1,     1,   118,    23,    -1,     1,    23,    -1,    22,   116,
     118,     1,     0,    -1,    22,   118,     1,     0,    -1,    22,
       1,     0,    -1,    22,     1,    23,    -1,   117,    -1,   116,
     117,    -1,   118,   101,    -1,   119,    -1,   118,   119,    -1,
      33,   165,    35,    -1,    34,    35,    -1,    34,     1,    25,
      -1,    33,     1,    35,    -1,    33,   165,     1,    25,    -1,
      36,    28,   164,    53,   105,    -1,    36,     1,   164,    53,
     105,    -1,    36,    28,   164,     1,   105,    -1,    36,    28,
       1,    53,   105,    -1,    36,     1,    53,   105,    -1,    36,
      28,   164,    53,   106,    -1,    36,     1,   164,    53,   106,
      -1,    36,    28,   164,     1,   106,    -1,    36,    28,     1,
      53,   106,    -1,    36,     1,    53,   106,    -1,    37,   105,
      36,    28,   164,    53,    25,    -1,    37,   105,    36,     1,
     164,    53,    25,    -1,    37,   105,    36,    28,   164,     1,
      25,    -1,    37,   105,    36,    28,     1,    53,    25,    -1,
      37,   105,    36,     1,    53,    25,    -1,    37,     1,    36,
      28,   164,    53,    25,    -1,    37,   105,     1,    28,   164,
      53,    25,    -1,    37,   105,    36,    28,   164,    53,     1,
      22,    -1,    37,   105,     1,   164,    53,    25,    -1,    37,
       1,    25,    -1,    38,    28,   125,    25,   164,    25,   126,
      53,   105,    -1,    38,    28,   125,    25,   164,    25,    53,
     105,    -1,    38,    28,   125,    25,    25,   126,    53,   105,
      -1,    38,    28,   125,    25,    25,    53,   105,    -1,    38,
      28,    25,   164,    25,   126,    53,   105,    -1,    38,    28,
      25,   164,    25,    53,   105,    -1,    38,    28,    25,    25,
     126,    53,   105,    -1,    38,    28,    25,    25,    53,   105,
      -1,    38,    28,    25,     1,    53,   105,    -1,    38,    28,
      25,    25,     1,    53,   105,    -1,    38,    28,    25,     1,
      25,    53,   105,    -1,    38,    28,     1,    25,    25,    53,
     105,    -1,    38,    28,   125,    25,   164,    25,   126,    53,
     106,    -1,    38,    28,   125,    25,   164,    25,    53,   106,
      -1,    38,    28,   125,    25,    25,   126,    53,   106,    -1,
      38,    28,   125,    25,    25,    53,   106,    -1,    38,    28,
      25,   164,    25,   126,    53,   106,    -1,    38,    28,    25,
     164,    25,    53,   106,    -1,    38,    28,    25,    25,   126,
      53,   106,    -1,    38,    28,    25,    25,    53,   106,    -1,
      38,    28,    25,     1,    53,   106,    -1,    38,    28,    25,
      25,     1,    53,   106,    -1,    38,    28,    25,     1,    25,
      53,   106,    -1,    38,    28,     1,    25,    25,    53,   106,
      -1,   127,    -1,   104,    -1,   127,    -1,   110,    -1,   127,
      24,   110,    -1,    39,    25,    -1,    39,     1,    23,    -1,
      40,    25,    -1,    41,   164,    25,    -1,    41,    25,    -1,
     132,    -1,   135,    -1,    65,    -1,    29,    -1,    28,   164,
      53,    -1,   133,    -1,   139,    -1,   140,    -1,   141,    -1,
      42,    71,    28,   134,    53,    -1,    42,    71,    28,    53,
      -1,   164,    -1,   134,    24,   164,    -1,     1,    24,   164,
      -1,   134,     1,   164,    -1,    42,    67,   136,   138,    -1,
      42,    67,   136,    -1,    42,    71,   136,   138,    -1,    42,
      71,   136,    -1,    42,    67,     1,    -1,    42,    71,     1,
      -1,    42,     1,   136,    -1,   137,    -1,   136,   137,    -1,
      49,   164,    50,    -1,    49,     1,    50,    -1,    49,    50,
      -1,   138,    49,    50,    -1,   131,    19,     3,    -1,    51,
      19,     3,    -1,    73,    28,   134,    53,    -1,    73,    28,
      53,    -1,   131,    19,     3,    28,   134,    53,    -1,   131,
      19,     3,    28,    53,    -1,    51,    19,     3,    28,   134,
      53,    -1,    51,    19,     3,    28,    53,    -1,   131,    19,
       1,    53,    -1,    73,    49,   164,    50,    -1,   132,    49,
     164,    50,    -1,   131,    -1,    73,    -1,   143,    -1,   144,
      -1,   142,    59,    -1,   142,    60,    -1,   146,    -1,   147,
      -1,    43,   145,    -1,   148,    -1,    59,   145,    -1,    60,
     145,    -1,   142,    -1,    44,   145,    -1,   149,    -1,    28,
      67,   138,    53,   145,    -1,    28,    67,    53,   145,    -1,
      28,   164,    53,   148,    -1,    28,    73,   138,    53,   148,
      -1,    28,    67,   138,     1,   145,    -1,    28,    67,     1,
     145,    -1,   145,    -1,   150,    45,   145,    -1,   150,    -1,
     151,    43,   150,    -1,   151,    -1,   152,    55,   151,    -1,
     152,    -1,   153,    56,   152,    -1,   153,    -1,   154,    46,
     153,    -1,   154,    -1,   155,    48,   154,    -1,   155,    -1,
     156,    47,   155,    -1,   156,    -1,   157,    58,   156,    -1,
     157,    -1,   158,    57,   157,    -1,   158,    -1,   159,    -1,
     161,    -1,   162,   163,   160,    -1,    73,    -1,   139,    -1,
     141,    -1,    54,    -1,    26,    -1,   160,    -1,   164,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   298,   298,   301,   302,   308,   312,   315,   318,   321,
     325,   328,   332,   335,   339,   342,   346,   349,   352,   358,
     361,   365,   369,   374,   380,   385,   390,   395,   400,   406,
     409,   413,   418,   424,   427,   432,   435,   439,   442,   452,
     461,   470,   479,   485,   490,   495,   500,   505,   510,   515,
     524,   530,   536,   541,   553,   556,   561,   564,   568,   571,
     575,   581,   586,   594,   597,   608,   611,   616,   631,   636,
     647,   655,   663,   667,   672,   677,   681,   686,   691,   697,
     702,   708,   711,   716,   730,   735,   738,   742,   747,   774,
     780,   785,   798,   804,   813,   819,   824,   829,   833,   839,
     845,   851,   857,   864,   870,   876,   883,   890,   896,   903,
     909,   915,   921,   927,   933,   939,   945,   951,   957,   963,
     969,   975,  1002,  1007,  1026,  1032,  1038,  1045,  1048,  1053,
    1056,  1061,  1076,  1081,  1084,  1087,  1090,  1093,  1097,  1100,
    1103,  1106,  1111,  1114,  1117,  1120,  1123,  1126,  1129,  1132,
    1136,  1140,  1144,  1151,  1154,  1157,  1160,  1163,  1166,  1169,
    1173,  1180,  1187,  1194,  1201,  1225,  1234,  1241,  1248,  1256,
    1263,  1280,  1289,  1296,  1303,  1310,  1326,  1333,  1340,  1347,
    1354,  1361,  1369,  1375,  1380,  1385,  1389,  1395,  1401,  1407,
    1413,  1426,  1432,  1438,  1445,  1448,  1453,  1458,  1461,  1466,
    1471,  1475,  1481,  1487,  1494,  1501,  1508,  1515,  1522,  1530,
    1537,  1544,  1551,  1558,  1574,  1583,  1590,  1597,  1604,  1612,
    1619,  1626,  1633,  1640,  1648,  1659,  1669,  1680,  1690,  1701,
    1711,  1721,  1730,  1743,  1757,  1773,  1787,  1798,  1808,  1818,
    1827,  1837,  1846,  1855,  1864,  1877,  1891,  1907,  1921,  1924,
    1928,  1932,  1935,  1942,  1948,  1960,  1965,  1972,  1979,  1982,
    1987,  1990,  1993,  1998,  2001,  2004,  2007,  2011,  2018,  2034,
    2037,  2042,  2052,  2063,  2069,  2074,  2080,  2086,  2093,  2100,
    2108,  2111,  2116,  2121,  2133,  2137,  2143,  2148,  2155,  2161,
    2166,  2174,  2181,  2189,  2196,  2209,  2215,  2222,  2225,  2228,
    2231,  2235,  2241,  2247,  2250,  2253,  2257,  2261,  2267,  2273,
    2276,  2280,  2284,  2291,  2297,  2303,  2310,  2316,  2323,  2326,
    2332,  2335,  2341,  2344,  2350,  2353,  2360,  2363,  2369,  2372,
    2378,  2381,  2387,  2390,  2396,  2399,  2405,  2409,  2412,  2416,
    2422,  2425,  2428,  2432,  2435,  2439,  2443
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "Identifier", "StringLiteral",
  "FloatingPointLiteral", "CharLiteral", "IntegerLiteral", "DoubleQuote",
  "Underscore", "Letter", "SingleQuote", "Error", "TrueOrFalse", "Boolean",
  "Float", "Int", "Char", "Corchete", "punto", "Class", "Extends",
  "OpenLlave", "CloseLlave", "Coma", "PuntoComa", "variableDeclarator",
  "Void", "OpenParentesis", "This", "If", "Else", "Switch", "Case",
  "Default", "DosPtos", "While", "Do", "For", "Break", "Continue",
  "Return", "New", "AddOp", "Not", "MultOp", "And", "Or", "Tongo",
  "OpenCorchete", "CloseCorchete", "super", "modifier", "CloseParentesis",
  "Equals", "Relacion", "Igualdad", "OrOr", "AndAnd", "PlusPlus",
  "MinusMinus", "Prec1", "$accept", "Start", "CompilationUnit", "Literal",
  "Type", "PrimitiveType", "NumericType", "IntegralType", "ReferenceType",
  "ClassType", "ArrayType", "Name", "QualifiedName", "TypeDeclarations",
  "TypeDeclaration", "Modifiers", "Modifier", "ClassDeclaration", "Super",
  "ClassBody", "ClassBodyDeclarations", "ClassBodyDeclaration",
  "ClassMemberDeclaration", "FieldDeclaration", "VariableDeclarators",
  "VariableDeclarator", "VariableDeclaratorId", "VariableInitializer",
  "MethodDeclaration", "MethodHeader", "MethodDeclarator",
  "FormalParameterList", "FormalParameter", "MethodBody",
  "ConstructorDeclaration", "ConstructorDeclarator", "ConstructorBody",
  "ExplicitConstructorInvocation", "Block", "BlockStmts", "BlockStmt",
  "LocalVariableDeclarationStmt", "LocalVariableDeclaration", "Stmt",
  "StmtNoShortIf", "StmtNoTrailingSubstatement", "EmptyStmt", "ExprStmt",
  "StmtExpr", "IfThenStmt", "IfThenElseStmt", "IfThenElseStmtNoShortIf",
  "SwitchStmt", "SwitchBlock", "SwitchBlockStmtGroups",
  "SwitchBlockStmtGroup", "SwitchLabels", "SwitchLabel", "WhileStmt",
  "WhileStmtNoShortIf", "DoStmt", "ForStmt", "ForStmtNoShortIf", "ForInit",
  "ForUpdate", "StmtExprList", "BreakStmt", "ContinueStmt", "ReturnStmt",
  "Primary", "PrimaryNoNewArray", "ClassInstanceCreationExpr",
  "ArgumentList", "ArrayCreationExpr", "DimExprs", "DimExpr", "Dims",
  "FieldAccess", "MethodInvocation", "ArrayAccess", "PostfixExpr",
  "PostIncrementExpr", "PostDecrementExpr", "UnaryExpr",
  "PreIncrementExpr", "PreDecrementExpr", "UnaryExprNotPlusMinus",
  "CastExpr", "MultiplicativeExpr", "AdditiveExpr", "RelationalExpr",
  "EqualityExpr", "AndExpr", "ExclusiveOrExpr", "InclusiveOrExpr",
  "ConditionalAndExpr", "ConditionalOrExpr", "ConditionalExpr",
  "AssignmentExpr", "Assignment", "LeftHandSide", "AssignmentOperator",
  "Expr", "ConstantExpr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    65,    65,    65,
      66,    66,    67,    67,    68,    68,    69,    69,    69,    70,
      70,    71,    72,    72,    72,    72,    72,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    78,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      80,    81,    81,    81,    82,    82,    83,    83,    84,    84,
      85,    85,    85,    86,    86,    87,    87,    87,    88,    88,
      88,    88,    89,    90,    91,    91,    91,    91,    92,    92,
      92,    93,    93,    93,    94,    95,    95,    96,    96,    97,
      97,    97,    97,    97,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,   100,   100,   100,   100,   100,   101,   101,   102,
     102,   103,   104,   105,   105,   105,   105,   105,   106,   106,
     106,   106,   107,   107,   107,   107,   107,   107,   107,   107,
     108,   109,   109,   110,   110,   110,   110,   110,   110,   110,
     111,   111,   111,   111,   111,   112,   112,   112,   112,   112,
     112,   113,   113,   113,   113,   113,   114,   114,   114,   114,
     114,   114,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   116,   116,   117,   118,   118,   119,
     119,   119,   119,   119,   120,   120,   120,   120,   120,   121,
     121,   121,   121,   121,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   125,   125,
     126,   127,   127,   128,   128,   129,   130,   130,   131,   131,
     132,   132,   132,   132,   132,   132,   132,   133,   133,   134,
     134,   134,   134,   135,   135,   135,   135,   135,   135,   135,
     136,   136,   137,   137,   138,   138,   139,   139,   140,   140,
     140,   140,   140,   140,   140,   141,   141,   142,   142,   142,
     142,   143,   144,   145,   145,   145,   145,   146,   147,   148,
     148,   148,   149,   149,   149,   149,   149,   149,   150,   150,
     151,   151,   152,   152,   153,   153,   154,   154,   155,   155,
     156,   156,   157,   157,   158,   158,   159,   160,   160,   161,
     162,   162,   162,   163,   163,   164,   165
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     3,     3,     3,     3,     3,     4,     4,     1,
       1,     3,     4,     1,     2,     1,     1,     1,     2,     1,
       5,     4,     4,     4,     4,     5,     5,     5,     5,     4,
       2,     3,     4,     2,     1,     2,     1,     1,     1,     1,
       4,     3,     3,     1,     3,     1,     3,     3,     1,     3,
       2,     4,     1,     2,     3,     2,     3,     2,     4,     3,
       3,     1,     3,     3,     2,     1,     1,     3,     2,     4,
       3,     4,     5,     2,     4,     3,     3,     2,     2,     3,
       3,     4,     3,     4,     4,     5,     5,     4,     5,     4,
       4,     4,     5,     5,     6,     5,     4,     4,     5,     5,
       6,     5,     3,     2,     2,     4,     3,     1,     2,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       5,     5,     5,     5,     4,     7,     7,     7,     7,     6,
       4,     7,     7,     7,     7,     6,     5,     5,     5,     5,
       4,     3,     4,     3,     3,     2,     4,     3,     3,     2,
       5,     4,     3,     3,     1,     2,     2,     1,     2,     3,
       2,     3,     3,     4,     5,     5,     5,     5,     4,     5,
       5,     5,     5,     4,     7,     7,     7,     7,     6,     7,
       7,     8,     6,     3,     9,     8,     8,     7,     8,     7,
       7,     6,     6,     7,     7,     7,     9,     8,     8,     7,
       8,     7,     7,     6,     6,     7,     7,     7,     1,     1,
       1,     1,     3,     2,     3,     2,     3,     2,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     5,     4,     1,
       3,     3,     3,     4,     3,     4,     3,     3,     3,     3,
       1,     2,     3,     3,     2,     3,     3,     3,     4,     3,
       6,     5,     6,     5,     4,     4,     4,     1,     1,     1,
       1,     2,     2,     1,     1,     2,     1,     2,     2,     1,
       2,     1,     5,     4,     4,     5,     5,     4,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,    36,    39,     0,     2,     0,    33,     0,    37,
      35,     0,     1,    34,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,    29,    13,    15,    16,    17,     0,
       0,     0,     0,     0,    12,    14,    11,    19,    20,     0,
      30,     0,     0,    44,     0,    54,    56,    58,    59,     0,
      57,     0,     0,    42,    49,     0,    43,     0,     0,    41,
      18,     0,     0,     0,    93,    29,    50,    21,     0,     0,
      77,    68,     0,    63,     0,    75,     0,     0,     0,     0,
       0,     0,     0,     0,    47,    53,    55,     0,     0,    86,
      73,    85,     0,     0,    88,    45,    46,    48,    40,     0,
       0,     0,    81,    24,    90,     0,     0,    51,     0,     0,
       0,    61,     0,     0,    70,     0,    26,     0,    22,    25,
       0,    31,     0,    23,    76,    62,     0,    74,    87,   124,
       0,     8,     6,     7,     5,     9,   123,   150,     0,   261,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   260,     0,     0,   142,     0,   127,   129,     0,
     130,   133,   143,   144,     0,   134,   135,   145,   136,   146,
     137,   147,   148,   149,   297,   258,   159,   259,   264,   158,
     266,     0,   156,   157,   154,   155,   153,     0,     0,    98,
       0,     0,     0,     0,     0,    97,     0,     0,    68,    84,
       0,     0,    91,     0,    89,    52,    79,     0,    80,    64,
       0,     0,     0,   298,    67,   263,   265,   309,   299,   300,
     318,   303,   304,   306,   311,   320,   322,   324,   326,   328,
     330,   332,   334,   336,   337,   345,   338,    72,     0,    69,
      66,    28,    32,    27,    60,   126,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   253,   255,   257,
       0,     0,     0,     0,     0,   298,   264,   266,   307,   308,
     132,     0,     0,     0,   122,   128,   131,   152,   151,     0,
       0,   301,   302,   344,   343,     0,     0,     0,     0,     0,
      99,     0,   100,   102,     0,    95,     0,     0,    96,    83,
      82,    92,    78,     0,     0,   298,     0,   305,   310,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    71,
     262,     0,     0,     0,     0,     0,     0,     0,     0,   181,
       0,     0,     0,     0,     0,     0,     0,   223,     0,     0,
       0,     0,     0,   249,   251,     0,   248,   254,   256,     0,
     279,   280,   277,   274,   278,     0,   276,   287,     0,   289,
       0,   269,     0,   125,     0,   286,     0,   339,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   101,   103,
       0,    94,   104,     0,     0,     0,     0,     0,     0,   262,
     319,   321,   323,   325,   327,   329,   331,   333,   335,   170,
       0,     0,     0,   164,     0,   133,   139,   140,   141,     0,
       0,     0,     0,   189,     0,     0,     0,   194,     0,   197,
       0,   185,     0,     0,   180,     0,     0,     0,     0,   208,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,     0,     0,   281,     0,   273,
     268,     0,   275,     0,     0,     0,     0,   288,   295,   294,
       0,   296,   116,     0,   117,     0,   107,     0,     0,   110,
       0,   111,     0,   109,     0,     0,   105,   317,   284,   313,
       0,     0,     0,     0,   314,     0,     0,     0,     0,     0,
       0,   161,     0,   163,     0,   162,     0,   160,     0,     0,
     346,     0,     0,   200,   187,   195,     0,   188,     0,   198,
     192,   193,   183,     0,     0,   184,   177,   179,   178,   176,
     205,   207,   206,   204,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   250,     0,     0,
       0,   252,   283,   282,   267,   293,     0,   271,   272,   270,
     291,     0,   118,   121,   119,     0,   106,   112,   115,   113,
       0,   108,   316,   285,   312,   315,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,     0,     0,
       0,     0,   202,     0,   199,   201,   186,     0,   182,   191,
       0,   262,   222,   218,     0,     0,     0,     0,     0,     0,
     232,     0,   231,     0,     0,     0,     0,     0,     0,   292,
     290,   120,   114,     0,     0,     0,     0,     0,   213,     0,
       0,     0,     0,    18,     0,     0,     0,     0,   166,   168,
     167,   165,   203,   190,   219,   220,   215,   217,   216,     0,
     214,   235,   234,   233,   230,   229,     0,   227,     0,     0,
       0,     0,     0,     0,     0,     0,   210,   212,   211,   209,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   221,
     228,   226,   225,     0,   175,     0,     0,     0,     0,     0,
       0,   244,     0,   243,     0,     0,     0,     0,     0,     0,
     224,   172,   174,   173,   171,   247,   246,   245,   242,   241,
       0,   239,     0,     0,     0,   240,   238,   237,     0,   236
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,   152,   153,    33,    34,    35,    36,    37,
      38,   213,    40,     6,     7,    41,     9,    10,    42,    43,
      44,    45,    46,    47,    72,    73,    74,   214,    48,    49,
      70,   101,   102,    90,    50,    51,    94,   192,   155,   508,
     157,   158,   159,   160,   404,   161,   162,   163,   164,   165,
     166,   406,   167,   329,   416,   417,   418,   419,   168,   407,
     169,   170,   408,   345,   536,   537,   171,   172,   173,   174,
     175,   176,   360,   177,   350,   351,   386,   178,   179,   180,
     181,   182,   183,   220,   184,   185,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   186,
     187,   285,   361,   501
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -467
static const yytype_int16 yypact[] =
{
      41,     0,  -467,  -467,    32,  -467,    63,  -467,   225,  -467,
    -467,   228,  -467,  -467,   262,   308,   273,  -467,   342,   342,
     781,   342,   887,   431,   277,  -467,  -467,  -467,  -467,   344,
     395,   386,   392,   372,  -467,  -467,  -467,  -467,  -467,   301,
    -467,   614,   781,  -467,  1002,  -467,  -467,  -467,  -467,   528,
    -467,   309,   781,  -467,  -467,   781,  -467,   666,   781,  -467,
    -467,   641,   171,   120,  -467,  -467,  -467,   269,  1097,   397,
     414,   397,    76,  -467,   116,   414,   429,    21,   442,   321,
     167,   386,   303,   309,  -467,  -467,  -467,   490,  2890,  -467,
    -467,  -467,  2939,  2988,  -467,  -467,  -467,  -467,  -467,   317,
     525,    14,  -467,  -467,  -467,    54,   235,  -467,   254,   494,
     525,  -467,  3993,   290,  -467,  3993,  -467,   516,  -467,  -467,
     521,  -467,   530,  -467,   414,  -467,   358,   414,  -467,  -467,
      36,  -467,  -467,  -467,  -467,  -467,  -467,  -467,  3993,  -467,
      98,   162,   340,  2227,   531,   412,   538,  3726,   914,   558,
    3993,  3993,  -467,   525,   542,  -467,  3037,  -467,  -467,   572,
    -467,  -467,  -467,  -467,   469,  -467,  -467,  -467,  -467,  -467,
    -467,  -467,  -467,  -467,   585,   517,   325,  -467,   218,   401,
     334,   398,   559,   574,  -467,  -467,  -467,   361,   507,  -467,
     127,   477,  3086,  3135,   323,  -467,  3184,  3233,  -467,   601,
     641,   641,  -467,   850,  -467,  -467,  -467,   119,  -467,  -467,
    1853,  3993,  3993,   714,  -467,  -467,  -467,   398,  -467,  -467,
    -467,  -467,  -467,  -467,  -467,   562,   578,   590,   615,   638,
     644,   660,   651,   659,  -467,  -467,  -467,  -467,   692,  -467,
    -467,  -467,  -467,  -467,  -467,  -467,   669,  3665,  2112,   348,
    3415,  3753,  3434,   591,    26,   426,   696,  -467,  -467,  -467,
     698,   449,    16,   156,   722,   169,  -467,  -467,  -467,  -467,
     702,   619,   707,   379,  -467,  -467,  -467,  -467,  -467,   326,
    3993,  -467,  -467,  -467,  -467,  3993,   786,   931,  1007,  1152,
    -467,  3282,  -467,  -467,   423,  -467,  3331,   487,  -467,  -467,
    -467,  -467,  -467,   703,    43,   720,   676,  -467,  -467,  3993,
    3993,  3993,  3993,  3993,  3993,  3993,  3993,  3993,  3993,  -467,
    -467,  2326,  3373,   678,   679,    24,   620,   541,   413,  -467,
     685,   688,   105,  2326,   699,   700,   143,  -467,   726,  4026,
     425,   450,  1228,  -467,  -467,   730,   737,  -467,  -467,  3483,
     713,  -467,  -467,   715,  -467,  1373,   715,   742,   741,  -467,
     138,  -467,   728,  -467,   719,   748,   729,  -467,   755,   179,
     640,   496,   180,   756,   205,   665,   533,   206,  -467,  -467,
     491,  -467,  -467,  3993,   733,  3993,   226,  3786,   462,  2292,
    -467,   562,   578,   590,   615,   638,   644,   660,   651,  -467,
     448,   465,   757,  -467,   763,   769,  -467,  -467,  -467,  3373,
    3373,  3373,  3373,  -467,  3494,    59,   662,  -467,  2426,  -467,
      35,  -467,   711,  2694,  -467,   413,   413,   413,   413,  -467,
    2326,  2326,  2326,  2326,  3993,  1853,   735,  3813,  3543,   761,
     381,  1785,   776,  3846,  4233,   754,   759,  -467,  2033,   758,
    -467,   265,   758,  1449,  3993,  3993,  3993,  -467,  -467,  -467,
    1594,  -467,  -467,   780,  -467,   783,  -467,  3873,   546,  -467,
     785,  -467,   788,  -467,  3906,   547,  -467,  -467,  -467,  -467,
    3993,   762,  3993,  2292,  -467,  3684,  3554,  3933,  3603,  2620,
    2326,  -467,   782,  -467,   787,  -467,   793,  -467,   796,   797,
    -467,   126,   791,  -467,  -467,  -467,  2743,  -467,  2792,  -467,
    -467,  -467,  -467,  2841,   508,  -467,  -467,  -467,  -467,  -467,
    -467,  -467,  -467,  -467,   764,   794,   809,   810,   799,   801,
     188,   816,   824,  2326,   825,  2326,   826,   737,  4053,  4086,
     813,  -467,  -467,  -467,  -467,  -467,   279,  -467,  -467,  -467,
    -467,   285,  -467,  -467,  -467,   817,  -467,  -467,  -467,  -467,
     827,  -467,  -467,  -467,  -467,  -467,  3373,   829,   831,   237,
    3373,   832,   833,   255,   544,  1670,   838,  -467,  2326,  2326,
    2326,  2326,  -467,   858,  -467,  -467,  -467,   537,  -467,  -467,
     862,  2082,  -467,  -467,   866,   867,   868,   583,  2326,  2326,
    -467,  2326,  -467,  2326,  2326,   846,  2326,   847,  4113,  -467,
    -467,  -467,  -467,   818,  3373,  3373,  3373,  3373,  -467,  3373,
    3373,  3373,  3373,   880,   399,  3614,   881,  3966,  -467,  -467,
    -467,  -467,  -467,  -467,  -467,  -467,  -467,  -467,  -467,   885,
    -467,  -467,  -467,  -467,  -467,  -467,  2326,  -467,  2326,  2326,
     857,  3373,   882,   902,   909,   910,  -467,  -467,  -467,  -467,
     859,   863,  3373,   890,  3373,   893,  4146,  4173,   886,  -467,
    -467,  -467,  -467,  2326,  -467,  3373,  3373,  3373,  3373,  3373,
    3373,  -467,  3373,  -467,  3373,  3373,   894,  3373,   896,  4206,
    -467,  -467,  -467,  -467,  -467,  -467,  -467,  -467,  -467,  -467,
    3373,  -467,  3373,  3373,   897,  -467,  -467,  -467,  3373,  -467
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -467,  -467,  -467,  -467,    61,  -134,  -467,  -467,  -467,   -23,
    -467,   -18,  -467,  -467,   946,    89,   123,  -467,   573,  1188,
     923,   545,  -467,  -467,   -69,   844,   855,   841,  -467,  -467,
     117,   -10,   409,  -467,  -467,   916,   878,   869,   917,   -36,
    -146,  -467,  -250,   -97,  1988,  1914,  -467,  -467,  -222,  -467,
    -467,  -467,  -467,  -274,   642,  -245,  -308,  -402,  -467,  -467,
    -467,  -467,  -467,   476,  -466,  -246,  -467,  -467,  -467,  -467,
    -467,   388,  -258,  -467,   424,   296,   -71,  -102,   609,   -64,
     830,  1051,  1272,  -143,  1493,  1714,  -371,  -467,   656,   658,
     663,   657,   668,   670,   655,   667,  -467,  -467,   693,  1935,
    -467,  -467,  2065,  -467
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -343
static const yytype_int16 yytable[] =
{
      39,    39,    39,    39,    39,   343,    66,   268,   269,   346,
     275,    67,    39,   126,   262,   200,   509,   352,   484,   423,
      11,   509,   117,    39,    39,   411,    39,   339,   369,   372,
     374,   377,    12,   344,    39,   510,   245,    39,   201,    39,
      39,    -3,     1,    39,   383,    39,   254,   275,   266,   266,
      39,   275,   156,   105,   424,   203,   193,   197,   511,   129,
     502,    60,   340,    -4,     1,   349,     2,   202,   307,   308,
     154,   118,   605,   607,   154,   154,   304,   412,   201,    32,
      32,    32,    32,    32,   270,    62,   267,   267,     2,     8,
      39,    32,   384,     3,   503,     8,   385,   451,   207,   247,
     110,   111,    82,    32,   509,    32,   427,   204,   506,   266,
     266,   509,   565,    32,   513,     3,    32,   112,    32,    32,
     200,    99,   100,    65,   100,   263,   248,   583,   286,    32,
      67,    17,   265,   265,    25,    26,    27,    28,   154,   455,
     -65,   -65,   650,   201,   432,   275,  -261,   267,   267,    75,
     275,   516,   517,   518,   519,   287,   291,   354,   428,   665,
     296,   584,   456,   249,    17,   113,   114,   390,   122,   100,
     115,   505,   302,   104,   154,   154,  -261,   505,   154,   154,
     455,   467,    39,    39,   355,    39,  -261,  -261,    79,   596,
     250,   457,   305,   265,   265,   546,   433,   271,   124,   127,
     686,   688,   551,   456,   456,   349,   455,   474,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   123,   309,   344,
     484,   103,   541,   704,   399,   403,    14,   480,    15,   456,
     456,    18,   463,   468,   388,   205,   429,   154,   616,   343,
     477,   597,   479,   346,  -341,    16,   267,   267,   267,   267,
     267,   267,   267,   267,   267,    99,   621,    65,   470,   475,
      60,   100,   100,    61,   100,    19,   455,   344,    25,    26,
      27,    28,  -341,   154,    21,   481,    22,     3,   154,   482,
     455,   266,   449,   266,    62,   452,   455,   266,    79,   456,
     617,   238,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   304,    78,   456,   -21,    63,    71,   206,   622,   456,
      92,    20,   491,   493,   495,   497,   344,   344,   544,   267,
      79,   267,   120,   293,   121,   267,   -21,   364,   125,   365,
      64,    93,   609,   520,   521,   522,   523,   562,   610,   564,
     239,   251,    60,    23,  -263,    24,   129,    65,    60,   326,
      80,    65,   131,   132,   133,   134,    25,    26,    27,    28,
    -342,   135,   275,    29,    30,   265,    62,   265,   252,    31,
     327,   265,    62,    76,  -263,   -10,   210,   139,   266,   363,
     266,   266,   110,   244,  -263,  -263,   344,   283,  -342,    69,
     148,   211,   212,   577,     3,    71,    23,   -10,    24,   149,
     154,   328,   129,   344,    60,   154,   532,   150,   151,    25,
      26,    27,    28,   256,   326,   284,   267,   305,   267,   267,
    -265,    77,    31,   379,   661,   108,   437,   341,    62,    65,
     131,   132,   133,   134,   533,   327,   600,   257,   602,   135,
      25,    26,    27,    28,   344,   344,   129,     3,    60,   485,
    -265,   342,   662,   438,   138,   139,    60,   281,   282,    61,
    -265,  -265,   265,   109,   265,   265,   487,   344,   148,   403,
     277,   154,    62,   429,    60,   439,   486,   149,   288,   116,
      62,   628,   629,   630,   631,   150,   151,   382,   154,   266,
     154,   476,   119,   488,   278,   154,   264,   465,   349,    62,
     215,   641,   642,   215,   643,   289,   644,   645,   589,   647,
     129,   481,    60,   129,   129,   483,    60,   491,   493,   495,
     497,   466,   520,   521,   522,   523,   215,   267,   198,    87,
     129,   129,    60,    60,   472,   215,    62,   633,   215,   215,
      62,   241,   420,    78,   208,   -21,   242,   555,   560,   670,
      88,   671,   672,    89,   577,   243,    62,    62,   473,   255,
     129,    79,    60,   258,   421,   600,   280,   602,  -340,   623,
     271,   556,   561,   265,   414,   415,   690,   264,   628,   629,
     630,   631,   641,   642,   639,   643,    62,   644,   645,    86,
     647,   272,    52,    62,    55,    58,  -340,   276,   215,   215,
     215,  -298,  -298,   670,   279,   671,   672,   310,   640,   299,
     300,   690,   299,    86,   129,    23,   337,    24,  -299,  -299,
     358,   311,    65,   131,   132,   133,   134,   338,    25,    26,
      27,    28,   135,  -300,  -300,   215,   215,   215,   215,   215,
     215,    81,    99,   413,    65,   312,   447,   210,   139,   447,
     113,   114,   447,   414,   415,    25,    26,    27,    28,   215,
     215,   148,   211,   212,   454,   464,     3,    23,   215,    24,
     149,   313,   359,   215,   215,   215,   215,   215,   150,   151,
      25,    26,    27,    28,   314,   504,   353,   356,    30,   454,
     471,    60,   315,    31,    61,   414,   415,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   316,   122,   317,
      65,   131,   132,   133,   134,    62,   318,   319,     3,   347,
     135,   216,   320,   348,   216,   357,   110,   215,    60,   389,
     215,   409,   410,    79,   512,   210,   139,   215,   425,    79,
    -340,   426,   271,   215,   414,   415,  -340,   216,   271,   148,
     211,   212,   430,   431,   434,   443,   216,   123,   149,   216,
     216,   444,   349,   309,   448,   454,   150,   151,  -340,   387,
     453,   215,   459,   215,  -340,   215,   460,   215,   458,   461,
     462,   469,    23,   478,    24,   489,   531,   358,   526,    65,
     131,   132,   133,   134,   490,    25,    26,    27,    28,   135,
    -138,   538,   215,    30,   542,   552,   553,   481,    31,   543,
     557,   558,   563,   578,   210,   139,   585,   590,   579,   216,
     216,   216,   215,   215,   580,   215,   215,   581,   148,   211,
     212,   215,   582,     3,   592,   593,   215,   149,   608,   368,
     611,   215,   215,   215,   215,   150,   151,   591,   215,   651,
     612,    99,   594,    65,   595,   215,   216,   216,   216,   216,
     216,   216,   215,   627,    25,    26,    27,    28,   215,   598,
     215,   215,   301,   215,   215,   215,   215,   599,   601,   603,
     216,   216,   614,   632,   615,   619,   620,   634,    57,   216,
      24,   636,   637,   638,   216,   216,   216,   216,   216,   646,
     648,    25,    26,    27,    28,   660,   666,   669,    29,    30,
     673,   689,   679,   675,    31,   261,   680,    65,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,    25,    26,
      27,    28,   370,   676,    65,   131,   132,   133,   134,     3,
     677,   678,   217,   682,   135,   217,   684,   700,   216,   702,
     708,   216,    13,    68,   209,   199,   240,    83,   216,   210,
     139,   128,   196,   215,   216,   576,    91,   391,   217,   422,
     392,   394,   397,   148,   211,   212,   393,   217,   367,   215,
     217,   217,   149,   395,   371,   398,   396,     0,     0,     0,
     150,   151,   216,     0,   216,     0,   216,     0,   216,     0,
       0,     0,     0,    23,     0,    24,     0,     0,   358,     0,
      65,   131,   132,   133,   134,   215,    25,    26,    27,    28,
     135,     0,     0,   216,     0,    85,     0,     0,     0,    31,
       0,     0,     0,     0,     0,   210,   139,     0,     0,     0,
     217,   217,   217,   216,   216,     0,   216,   216,     0,   148,
     211,   212,   216,     0,     3,     0,     0,   216,   149,     0,
     373,     0,   216,   216,   216,   216,   150,   151,     0,   216,
       0,     0,     0,     0,     0,     0,   216,   217,   217,   217,
     217,   217,   217,   216,     0,     0,     0,     0,     0,   216,
       0,   216,   216,     0,   216,   216,   216,   216,   106,     0,
      24,   217,   217,     0,     0,     0,     0,     0,     0,     0,
     217,    25,    26,    27,    28,   217,   217,   217,   217,   217,
     107,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,     3,
       0,     0,     0,   375,     0,    65,   131,   132,   133,   134,
       0,     0,     0,   218,     0,   135,   218,     0,     0,   217,
       0,     0,   217,     0,     0,     0,     0,     0,     0,   217,
     210,   139,     0,     0,   216,   217,     0,     0,     0,   218,
       0,     0,     0,     0,   148,   211,   212,     0,   218,     0,
     216,   218,   218,   149,     0,   376,     0,    53,    54,    56,
      59,   150,   151,   217,     0,   217,     0,   217,     0,   217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   440,
      84,    65,   131,   132,   133,   134,   216,     0,     0,     0,
      95,   135,     0,    96,   217,    97,    98,     0,     0,     0,
       0,     0,     0,   441,     0,     0,   210,   139,     0,     0,
       0,   218,   218,   218,   217,   217,     0,   217,   217,     0,
     148,   211,   212,   217,     0,     0,     0,     0,   217,   149,
       0,     0,     0,   217,   217,   217,   217,   150,   151,     0,
     217,     0,     0,     0,     0,     0,     0,   217,   218,   218,
     218,   218,   218,   218,   217,     0,     0,     0,     0,     0,
     217,     0,   217,   217,     0,   217,   217,   217,   217,     0,
       0,     0,   218,   218,     0,     0,     0,     0,     0,     0,
       0,   218,     0,     0,     0,     0,   218,   218,   218,   218,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
       0,     0,     0,     0,   358,     0,    65,   131,   132,   133,
     134,     0,     0,     0,   219,     0,   135,   219,     0,     0,
     218,     0,     0,   218,     0,     0,     0,     0,     0,     0,
     218,   210,   139,     0,     0,   217,   218,     0,     0,     0,
     219,     0,     0,     0,     0,   148,   211,   212,     0,   219,
       0,   217,   219,   219,   149,     0,   450,     0,     0,     0,
       0,     0,   150,   151,   218,     0,   218,     0,   218,     0,
     218,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     358,     0,    65,   131,   132,   133,   134,   217,     0,     0,
       0,     0,   135,     0,     0,   218,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   210,   139,     0,
       0,     0,   219,   219,   219,   218,   218,     0,   218,   218,
       0,   148,   211,   212,   218,     0,     0,     0,     0,   218,
     149,     0,   545,     0,   218,   218,   218,   218,   150,   151,
       0,   218,     0,     0,     0,     0,     0,     0,   218,   219,
     219,   219,   219,   219,   219,   218,     0,     0,     0,     0,
       0,   218,     0,   218,   218,     0,   218,   218,   218,   218,
       0,     0,     0,   219,   219,     0,     0,     0,     0,     0,
       0,     0,   219,     0,     0,     0,     0,   219,   219,   219,
     219,   219,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,     0,     0,     0,     0,   358,     0,    65,   131,   132,
     133,   134,     0,     0,     0,   221,     0,   135,   221,     0,
       0,   219,     0,     0,   219,     0,     0,     0,     0,     0,
       0,   219,   210,   139,     0,     0,   218,   219,     0,     0,
       0,   221,     0,     0,     0,     0,   148,   211,   212,     0,
     221,     0,   218,   221,   221,   149,     0,   550,     0,     0,
       0,     0,     0,   150,   151,   219,     0,   219,     0,   219,
       0,   219,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   624,     0,    65,   131,   132,   133,   134,   218,     0,
       0,     0,     0,   135,     0,     0,   219,     0,     0,     0,
       0,     0,     0,     0,     0,   625,     0,     0,   210,   139,
       0,     0,     0,   221,   221,   221,   219,   219,     0,   219,
     219,     0,   148,   211,   212,   219,     0,     0,     0,     0,
     219,   149,     0,     0,     0,   219,   219,   219,   219,   150,
     151,     0,   219,     0,     0,     0,     0,     0,     0,   219,
     221,   221,   221,   221,   221,   221,   219,     0,     0,     0,
       0,     0,   219,     0,   219,   219,     0,   219,   219,   219,
     219,     0,     0,     0,   221,   221,     0,     0,     0,     0,
       0,     0,     0,   221,     0,     0,     0,     0,   221,   221,
     221,   221,   221,     0,     0,     0,   534,     0,    65,   131,
     132,   133,   134,     0,     0,     0,     0,     0,   135,     0,
       0,     0,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,     0,   138,   139,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,   148,     0,   222,
       0,     0,   221,     0,     0,   221,   149,     0,   535,     0,
       0,     0,   221,     0,   150,   151,     0,   219,   221,     0,
       0,     0,   222,     0,   303,     0,    65,   131,   132,   133,
     134,   222,     0,   219,   222,   222,   135,    25,    26,    27,
      28,     0,     0,     0,     0,     0,   221,     0,   221,     0,
     221,   210,   139,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,   211,   212,     0,   219,
       0,     0,     0,     0,   149,     0,     0,   221,     0,     0,
       0,     0,   150,   151,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   222,   222,   222,   221,   221,     0,
     221,   221,     0,     0,     0,     0,   221,     0,     0,     0,
       0,   221,     0,     0,     0,     0,   221,   221,   221,   221,
       0,     0,     0,   221,     0,     0,     0,     0,     0,     0,
     221,   222,   222,   222,   222,   222,   222,   221,     0,     0,
       0,     0,     0,   221,     0,   221,     0,     0,   221,   221,
     221,   221,     0,     0,     0,   222,   222,     0,     0,     0,
       0,     0,     0,     0,   222,     0,     0,     0,     0,   222,
     222,   222,   222,   222,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,     0,   445,     0,    65,   131,   132,   133,
     134,     0,     0,     0,     0,     0,   135,   236,     0,     0,
     236,     0,     0,   222,     0,     0,   222,     0,     0,     0,
       0,   210,   139,   222,     0,     0,     0,     0,   221,   222,
       0,     0,     0,   236,     0,   148,   211,   212,     0,     0,
       0,     0,   236,   478,   149,    65,   131,   132,   133,   134,
       0,     0,   150,   151,     0,   135,     0,   222,     0,   222,
       0,   222,     0,     0,     0,     0,     0,   635,     0,     0,
     210,   139,     0,   324,     0,    65,   131,   132,   133,   134,
     221,     0,     0,     0,   148,   135,   212,     0,   222,     0,
       0,     0,     0,   149,     0,     0,     0,     0,     0,     0,
     210,   139,     0,     0,     0,   236,     0,     0,   222,   222,
       0,   222,   222,     0,   148,   211,   212,   222,     0,     0,
       0,     0,   222,   149,     0,     0,     0,   222,   222,   222,
     222,   150,   151,     0,   222,     0,     0,   237,     0,     0,
     237,   222,   236,   236,   236,   236,   236,   236,   222,     0,
       0,     0,     0,     0,   222,     0,   222,     0,     0,   222,
     222,   222,   222,   246,     0,     0,   236,   236,     0,     0,
       0,     0,   260,     0,     0,   236,     0,     0,     0,     0,
     236,   236,   236,   236,   236,     0,     0,     0,   253,     0,
      65,   131,   132,   133,   134,     0,   405,     0,     0,     0,
     135,     0,     0,     0,   236,     0,     0,     0,     0,    88,
       0,     0,   137,     0,     0,   138,   139,   140,     0,   141,
       0,     0,     0,   142,   143,   144,   145,   146,   147,   148,
       0,     0,     0,     0,   236,   306,     0,   236,   149,     0,
       0,     0,     0,     0,   236,     0,   150,   151,     0,   222,
     236,     0,     0,     0,     0,    65,   131,   132,   133,   134,
       0,     0,     0,     0,     0,   135,     0,     0,     0,     0,
       0,     0,   323,   325,   330,   332,   334,   336,     0,     0,
     210,   139,   236,   405,   405,   405,   405,    87,     0,    65,
     131,   132,   133,   134,   148,     0,   212,   362,     0,   135,
       0,   222,     0,   149,     0,   366,     0,     0,    88,   236,
       0,   137,     0,     0,   138,   139,   140,     0,   141,     0,
       0,     0,   142,   143,   144,   145,   146,   147,   148,   236,
     236,     0,   236,   236,   362,     0,     0,   149,   236,     0,
       0,     0,     0,   236,     0,   150,   151,     0,   236,   236,
     236,   236,     0,     0,     0,   236,     0,   492,   494,   496,
     498,     0,   236,     0,   436,     0,     0,   442,     0,   236,
       0,     0,     0,     0,   446,     0,     0,     0,     0,     0,
     236,   236,   236,   236,     0,     0,     0,   188,     0,    65,
     131,   132,   133,   134,     0,     0,     0,     0,     0,   135,
      25,    26,    27,    28,     0,     0,     0,     0,    88,   507,
       0,   137,   362,     0,   138,   139,   140,     0,   141,   414,
     415,     0,   142,   143,   144,   145,   146,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   500,
     405,     0,     0,     0,   405,   150,   151,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   524,
     525,     0,   528,   530,     0,     0,     0,     0,   540,     0,
     236,     0,     0,   446,     0,     0,     0,     0,     0,   547,
     548,   549,     0,     0,     0,     0,     0,     0,   405,   405,
     405,   405,   548,   405,   405,   405,   405,     0,     0,   548,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     567,   569,   571,   573,   613,     0,     0,     0,   618,     0,
       0,     0,   236,     0,     0,   405,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   405,     0,   405,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   405,
     405,   405,   405,   405,   405,     0,   405,     0,   405,   405,
       0,   405,   652,   653,   654,   655,     0,   656,   657,   658,
     659,     0,     0,     0,   405,     0,   405,   405,     0,     0,
       0,   574,   405,    65,   131,   132,   133,   134,     0,     0,
       0,     0,     0,   135,    25,    26,    27,    28,     0,   674,
     626,     0,     0,     0,     0,   575,     0,     0,   138,   139,
     681,     0,   683,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,   691,   692,   693,   694,   695,   696,     0,
     697,   149,   698,   699,     0,   701,     0,     0,     0,   150,
     151,     0,     0,     0,     0,     0,     0,     0,   705,     0,
     706,   707,   668,     0,     0,   514,   709,    65,   131,   132,
     133,   134,     0,     0,     0,     0,     0,   135,    25,    26,
      27,    28,     0,     0,     0,     0,    88,   515,     0,   137,
       0,     0,   138,   139,   140,     0,   141,   414,   415,     0,
     142,   143,   144,   145,   146,   147,   148,     0,     0,     0,
       0,     0,     0,     0,   188,   149,    65,   131,   132,   133,
     134,     0,     0,   150,   151,     0,   135,    25,    26,    27,
      28,     0,     0,     0,     0,    88,   586,     0,   137,     0,
       0,   138,   139,   140,     0,   141,   414,   415,     0,   142,
     143,   144,   145,   146,   147,   148,     0,     0,     0,     0,
       0,     0,     0,   188,   149,    65,   131,   132,   133,   134,
       0,     0,   150,   151,     0,   135,    25,    26,    27,    28,
       0,     0,     0,     0,    88,  -196,     0,   137,     0,     0,
     138,   139,   140,     0,   141,  -196,  -196,     0,   142,   143,
     144,   145,   146,   147,   148,     0,     0,     0,     0,     0,
       0,     0,   587,   149,    65,   131,   132,   133,   134,     0,
       0,   150,   151,     0,   135,    25,    26,    27,    28,     0,
       0,     0,     0,    88,   588,     0,   137,     0,     0,   138,
     139,   140,     0,   141,   414,   415,     0,   142,   143,   144,
     145,   146,   147,   148,     0,     0,     0,     0,     0,     0,
       0,   130,   149,    65,   131,   132,   133,   134,     0,     0,
     150,   151,     0,   135,    25,    26,    27,    28,     0,     0,
       0,     0,    88,   136,     0,   137,     0,     0,   138,   139,
     140,     0,   141,     0,     0,     0,   142,   143,   144,   145,
     146,   147,   148,     0,     0,     0,     0,     0,     0,     0,
     188,   149,    65,   131,   132,   133,   134,     0,     0,   150,
     151,     0,   135,    25,    26,    27,    28,     0,     0,     0,
       0,    88,   189,     0,   137,     0,     0,   138,   190,   140,
       0,   141,     0,     0,     0,   142,   143,   144,   145,   146,
     147,   148,     0,     0,     0,     0,     0,     0,     0,   194,
     191,    65,   131,   132,   133,   134,     0,     0,   150,   151,
       0,   135,    25,    26,    27,    28,     0,     0,     0,     0,
      88,   195,     0,   137,     0,     0,   138,   190,   140,     0,
     141,     0,     0,     0,   142,   143,   144,   145,   146,   147,
     148,     0,     0,     0,     0,     0,     0,     0,   273,   191,
      65,   131,   132,   133,   134,     0,     0,   150,   151,     0,
     135,    25,    26,    27,    28,     0,     0,     0,     0,    88,
     274,     0,   137,     0,     0,   138,   139,   140,     0,   141,
       0,     0,     0,   142,   143,   144,   145,   146,   147,   148,
       0,     0,     0,     0,     0,     0,     0,   188,   149,    65,
     131,   132,   133,   134,     0,     0,   150,   151,     0,   135,
      25,    26,    27,    28,     0,     0,     0,     0,    88,   290,
       0,   137,     0,     0,   138,   139,   140,     0,   141,     0,
       0,     0,   142,   143,   144,   145,   146,   147,   148,     0,
       0,     0,     0,     0,     0,     0,   188,   149,    65,   131,
     132,   133,   134,     0,     0,   150,   151,     0,   135,    25,
      26,    27,    28,     0,     0,     0,     0,    88,   292,     0,
     137,     0,     0,   138,   139,   140,     0,   141,     0,     0,
       0,   142,   143,   144,   145,   146,   147,   148,     0,     0,
       0,     0,     0,     0,     0,   294,   149,    65,   131,   132,
     133,   134,     0,     0,   150,   151,     0,   135,    25,    26,
      27,    28,     0,     0,     0,     0,    88,   295,     0,   137,
       0,     0,   138,   139,   140,     0,   141,     0,     0,     0,
     142,   143,   144,   145,   146,   147,   148,     0,     0,     0,
       0,     0,     0,     0,   297,   149,    65,   131,   132,   133,
     134,     0,     0,   150,   151,     0,   135,    25,    26,    27,
      28,     0,     0,     0,     0,    88,   298,     0,   137,     0,
       0,   138,   139,   140,     0,   141,     0,     0,     0,   142,
     143,   144,   145,   146,   147,   148,     0,     0,     0,     0,
       0,     0,     0,   188,   149,    65,   131,   132,   133,   134,
       0,     0,   150,   151,     0,   135,    25,    26,    27,    28,
       0,     0,     0,     0,    88,   378,     0,   137,     0,     0,
     138,   139,   140,     0,   141,     0,     0,     0,   142,   143,
     144,   145,   146,   147,   148,     0,     0,     0,     0,     0,
       0,     0,   380,   149,    65,   131,   132,   133,   134,     0,
       0,   150,   151,     0,   135,    25,    26,    27,    28,     0,
       0,     0,     0,    88,   381,     0,   137,     0,     0,   138,
     139,   140,     0,   141,     0,     0,     0,   142,   143,   144,
     145,   146,   147,   148,    87,     0,    65,   131,   132,   133,
     134,     0,   149,     0,     0,     0,   135,     0,     0,     0,
     150,   151,     0,     0,     0,    88,     0,     0,   137,     0,
       0,   138,   139,   400,     0,   141,     0,     0,     0,   401,
     143,   402,   145,   146,   147,   148,   331,     0,    65,   131,
     132,   133,   134,     0,   149,     0,     0,     0,   135,     0,
       0,     0,   150,   151,     0,   335,     0,    65,   131,   132,
     133,   134,     0,   210,   139,     0,     0,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,   211,   212,
       0,     0,   210,   139,     0,     0,   149,     0,     0,     0,
       0,     0,     0,     0,   150,   151,   148,   211,   212,     0,
       0,     0,     0,     0,   445,   149,    65,   131,   132,   133,
     134,     0,     0,   150,   151,   499,   135,    65,   131,   132,
     133,   134,     0,     0,     0,     0,     0,   135,     0,     0,
       0,   210,   139,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   210,   139,     0,   148,   211,   212,     0,     0,
       0,     0,     0,     0,   149,     0,   148,   211,   212,     0,
       0,     0,   150,   151,   529,   149,    65,   131,   132,   133,
     134,     0,     0,   150,   151,   568,   135,    65,   131,   132,
     133,   134,     0,     0,     0,     0,     0,   135,     0,     0,
       0,   210,   139,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   210,   139,     0,   148,   211,   212,     0,     0,
       0,     0,     0,     0,   149,     0,   148,   211,   212,     0,
       0,     0,   150,   151,   572,   149,    65,   131,   132,   133,
     134,     0,     0,   150,   151,   663,   135,    65,   131,   132,
     133,   134,     0,     0,     0,     0,     0,   135,     0,     0,
       0,   210,   139,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   139,     0,   148,   211,   212,     0,     0,
       0,     0,     0,     0,   149,     0,   148,     0,     0,     0,
       0,     0,   150,   151,     0,   149,     0,   664,    65,   131,
     132,   133,   134,   150,   151,     0,     0,     0,   135,     0,
       0,     0,     0,     0,     0,     0,     0,    65,   131,   132,
     133,   134,     0,   210,   139,     0,   321,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,   211,   212,
       0,     0,   210,   139,     0,   321,   149,     0,   322,     0,
       0,     0,     0,     0,   150,   151,   148,   211,   212,    65,
     131,   132,   133,   134,     0,   149,     0,   566,     0,   135,
       0,     0,     0,   150,   151,     0,     0,     0,     0,     0,
       0,   259,     0,     0,   210,   139,    65,   131,   132,   133,
     134,     0,     0,     0,     0,     0,   135,     0,   148,   211,
     212,     0,     0,     0,     0,     0,     0,   149,     0,     0,
       0,   210,   139,     0,     0,   150,   151,     0,     0,    65,
     131,   132,   133,   134,     0,   148,   211,   212,     0,   135,
       0,     0,     0,     0,   149,     0,   333,     0,     0,     0,
       0,     0,   150,   151,   210,   139,    65,   131,   132,   133,
     134,     0,     0,     0,     0,     0,   135,     0,   148,   211,
     212,     0,     0,     0,     0,     0,   478,   149,     0,     0,
       0,   210,   139,     0,     0,   150,   151,     0,     0,    65,
     131,   132,   133,   134,     0,   148,   211,   212,     0,   135,
       0,     0,     0,     0,   149,     0,   527,     0,     0,     0,
       0,   539,   150,   151,   210,   139,    65,   131,   132,   133,
     134,     0,     0,     0,     0,     0,   135,     0,   148,   211,
     212,     0,     0,     0,     0,     0,     0,   149,   554,     0,
       0,   210,   139,     0,     0,   150,   151,     0,     0,    65,
     131,   132,   133,   134,     0,   148,   211,   212,     0,   135,
       0,     0,     0,     0,   149,     0,     0,     0,     0,     0,
       0,   559,   150,   151,   210,   139,    65,   131,   132,   133,
     134,     0,     0,     0,     0,     0,   135,     0,   148,   211,
     212,     0,     0,     0,     0,     0,     0,   149,     0,     0,
       0,   210,   139,     0,     0,   150,   151,     0,     0,    65,
     131,   132,   133,   134,     0,   148,   211,   212,     0,   135,
       0,     0,     0,     0,   149,     0,   570,     0,     0,     0,
       0,   667,   150,   151,   210,   139,    65,   131,   132,   133,
     134,     0,     0,     0,     0,     0,   135,     0,   148,   211,
     212,     0,     0,     0,     0,     0,     0,   149,     0,     0,
       0,   210,   139,     0,     0,   150,   151,     0,     0,    65,
     131,   132,   133,   134,     0,   148,   211,   212,     0,   135,
       0,     0,     0,     0,   149,     0,     0,     0,     0,     0,
       0,     0,   150,   151,   435,   139,    65,   131,   132,   133,
     134,     0,     0,     0,     0,     0,   135,     0,   148,   211,
     212,     0,     0,     0,     0,     0,     0,   149,     0,     0,
       0,   138,   139,     0,     0,   150,   151,     0,     0,    65,
     131,   132,   133,   134,     0,   148,     0,     0,     0,   135,
       0,     0,     0,     0,   149,     0,   604,     0,     0,     0,
       0,     0,   150,   151,   138,   139,    65,   131,   132,   133,
     134,     0,     0,     0,     0,     0,   135,     0,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   606,
       0,   138,   139,     0,     0,   150,   151,     0,     0,    65,
     131,   132,   133,   134,     0,   148,     0,     0,     0,   135,
       0,     0,     0,     0,   149,     0,   649,     0,     0,     0,
       0,     0,   150,   151,   138,   139,    65,   131,   132,   133,
     134,     0,     0,     0,     0,     0,   135,     0,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   685,
       0,   138,   139,     0,     0,   150,   151,     0,     0,    65,
     131,   132,   133,   134,     0,   148,     0,     0,     0,   135,
       0,     0,     0,     0,   149,     0,   687,     0,     0,     0,
       0,     0,   150,   151,   138,   139,    65,   131,   132,   133,
     134,     0,     0,     0,     0,     0,   135,     0,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   703,
       0,   138,   139,     0,     0,   150,   151,     0,     0,     0,
       0,     0,     0,     0,     0,   148,     0,     0,     0,     0,
       0,     0,     0,     0,   149,     0,     0,     0,     0,     0,
       0,     0,   150,   151
};

static const yytype_int16 yycheck[] =
{
      18,    19,    20,    21,    22,   255,    29,   150,   151,   255,
     156,    29,    30,    82,   148,     1,   418,     1,   389,   327,
      20,   423,     1,    41,    42,     1,    44,     1,   286,   287,
     288,   289,     0,   255,    52,     0,     0,    55,    24,    57,
      58,     0,     1,    61,     1,    63,   143,   193,   150,   151,
      68,   197,    88,    63,   328,     1,    92,    93,    23,    23,
       1,    25,    36,     0,     1,    49,    25,    53,   211,   212,
      88,    50,   538,   539,    92,    93,   210,    53,    24,    18,
      19,    20,    21,    22,   153,    49,   150,   151,    25,     0,
     108,    30,    49,    52,    35,     6,    53,   355,   108,     1,
      24,    25,    41,    42,   506,    44,     1,    53,   416,   211,
     212,   513,   483,    52,   422,    52,    55,     1,    57,    58,
       1,     1,    61,     3,    63,   148,    28,     1,     1,    68,
     148,     8,   150,   151,    14,    15,    16,    17,   156,     1,
      24,    25,   608,    24,     1,   291,    19,   211,   212,    32,
     296,   425,   426,   427,   428,    28,   192,     1,    53,   625,
     196,    35,    24,     1,    41,    49,    50,   310,     1,   108,
      54,   416,    53,    53,   192,   193,    49,   422,   196,   197,
       1,     1,   200,   201,    28,   203,    59,    60,    19,     1,
      28,    53,   210,   211,   212,   453,    53,    28,    81,    82,
     666,   667,   460,    24,    24,    49,     1,     1,   310,   311,
     312,   313,   314,   315,   316,   317,   318,    50,    49,   441,
     591,    50,   444,   689,   321,   322,     1,     1,     3,    24,
      24,     3,    53,    53,   305,     0,   333,   255,     1,   489,
     383,    53,   385,   489,    26,    20,   310,   311,   312,   313,
     314,   315,   316,   317,   318,     1,     1,     3,    53,    53,
      25,   200,   201,    28,   203,     3,     1,   489,    14,    15,
      16,    17,    54,   291,     1,    49,     3,    52,   296,    53,
       1,   383,   353,   385,    49,   356,     1,   389,    19,    24,
      53,     1,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   435,     1,    24,     3,    28,     3,    53,    53,    24,
       1,     3,   409,   410,   411,   412,   538,   539,    53,   383,
      19,   385,     1,     0,     3,   389,    25,     1,    25,     3,
      53,    22,    53,   430,   431,   432,   433,   480,    53,   482,
      50,     1,    25,     1,    19,     3,    23,     3,    25,     1,
      49,     3,     4,     5,     6,     7,    14,    15,    16,    17,
      26,    13,   508,    21,    22,   383,    49,   385,    28,    27,
      22,   389,    49,     1,    49,     3,    28,    29,   480,     0,
     482,   483,    24,    25,    59,    60,   608,    26,    54,     3,
      42,    43,    44,   490,    52,     3,     1,    25,     3,    51,
     418,    53,    23,   625,    25,   423,    25,    59,    60,    14,
      15,    16,    17,     1,     1,    54,   480,   435,   482,   483,
      19,    49,    27,     0,    25,    28,     1,     1,    49,     3,
       4,     5,     6,     7,    53,    22,   533,    25,   535,    13,
      14,    15,    16,    17,   666,   667,    23,    52,    25,     1,
      49,    25,    53,    28,    28,    29,    25,    59,    60,    28,
      59,    60,   480,    49,   482,   483,     1,   689,    42,   566,
       1,   489,    49,   570,    25,    25,    28,    51,     1,    50,
      49,   578,   579,   580,   581,    59,    60,     0,   506,   591,
     508,     0,    50,    28,    25,   513,    19,     1,    49,    49,
     112,   598,   599,   115,   601,    28,   603,   604,     0,   606,
      23,    49,    25,    23,    23,    53,    25,   614,   615,   616,
     617,    25,   619,   620,   621,   622,   138,   591,     3,     1,
      23,    23,    25,    25,     1,   147,    49,     0,   150,   151,
      49,    25,     1,     1,    50,     3,    25,     1,     1,   646,
      22,   648,   649,    25,   651,    25,    49,    49,    25,    28,
      23,    19,    25,    25,    23,   662,    49,   664,    26,    25,
      28,    25,    25,   591,    33,    34,   673,    19,   675,   676,
     677,   678,   679,   680,     1,   682,    49,   684,   685,    44,
     687,    49,    19,    49,    21,    22,    54,    25,   210,   211,
     212,    59,    60,   700,    19,   702,   703,    45,    25,   200,
     201,   708,   203,    68,    23,     1,    25,     3,    59,    60,
       1,    43,     3,     4,     5,     6,     7,    36,    14,    15,
      16,    17,    13,    59,    60,   247,   248,   249,   250,   251,
     252,    27,     1,    23,     3,    55,   350,    28,    29,   353,
      49,    50,   356,    33,    34,    14,    15,    16,    17,   271,
     272,    42,    43,    44,    24,    25,    52,     1,   280,     3,
      51,    56,    53,   285,   286,   287,   288,   289,    59,    60,
      14,    15,    16,    17,    46,    23,   262,   263,    22,    24,
      25,    25,    48,    27,    28,    33,    34,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,    47,     1,    58,
       3,     4,     5,     6,     7,    49,    57,    25,    52,    23,
      13,   112,    53,    25,   115,     3,    24,   339,    25,    53,
     342,    53,    53,    19,    23,    28,    29,   349,    53,    19,
      26,    53,    28,   355,    33,    34,    26,   138,    28,    42,
      43,    44,    53,    53,    28,    25,   147,    50,    51,   150,
     151,    24,    49,    49,    49,    24,    59,    60,    54,    49,
      28,   383,    53,   385,    54,   387,    28,   389,    50,    50,
      25,    25,     1,    50,     3,    28,    25,     1,    53,     3,
       4,     5,     6,     7,    31,    14,    15,    16,    17,    13,
      31,    25,   414,    22,    50,    25,    23,    49,    27,    50,
      25,    23,    50,    31,    28,    29,    25,    53,    31,   210,
     211,   212,   434,   435,    31,   437,   438,    31,    42,    43,
      44,   443,    35,    52,    25,    25,   448,    51,    25,    53,
      23,   453,   454,   455,   456,    59,    60,    53,   460,    31,
      23,     1,    53,     3,    53,   467,   247,   248,   249,   250,
     251,   252,   474,    25,    14,    15,    16,    17,   480,    53,
     482,   483,    22,   485,   486,   487,   488,    53,    53,    53,
     271,   272,    53,    25,    53,    53,    53,    25,     1,   280,
       3,    25,    25,    25,   285,   286,   287,   288,   289,    53,
      53,    14,    15,    16,    17,    25,    25,    22,    21,    22,
      53,    25,    53,    31,    27,     1,    53,     3,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,    14,    15,
      16,    17,     1,    31,     3,     4,     5,     6,     7,    52,
      31,    31,   112,    53,    13,   115,    53,    53,   339,    53,
      53,   342,     6,    30,   110,   100,   115,    41,   349,    28,
      29,    83,    93,   575,   355,   489,    49,   311,   138,   327,
     312,   314,   317,    42,    43,    44,   313,   147,   285,   591,
     150,   151,    51,   315,    53,   318,   316,    -1,    -1,    -1,
      59,    60,   383,    -1,   385,    -1,   387,    -1,   389,    -1,
      -1,    -1,    -1,     1,    -1,     3,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,   627,    14,    15,    16,    17,
      13,    -1,    -1,   414,    -1,    23,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
     210,   211,   212,   434,   435,    -1,   437,   438,    -1,    42,
      43,    44,   443,    -1,    52,    -1,    -1,   448,    51,    -1,
      53,    -1,   453,   454,   455,   456,    59,    60,    -1,   460,
      -1,    -1,    -1,    -1,    -1,    -1,   467,   247,   248,   249,
     250,   251,   252,   474,    -1,    -1,    -1,    -1,    -1,   480,
      -1,   482,   483,    -1,   485,   486,   487,   488,     1,    -1,
       3,   271,   272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     280,    14,    15,    16,    17,   285,   286,   287,   288,   289,
      23,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,    52,
      -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,   112,    -1,    13,   115,    -1,    -1,   339,
      -1,    -1,   342,    -1,    -1,    -1,    -1,    -1,    -1,   349,
      28,    29,    -1,    -1,   575,   355,    -1,    -1,    -1,   138,
      -1,    -1,    -1,    -1,    42,    43,    44,    -1,   147,    -1,
     591,   150,   151,    51,    -1,    53,    -1,    19,    20,    21,
      22,    59,    60,   383,    -1,   385,    -1,   387,    -1,   389,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      42,     3,     4,     5,     6,     7,   627,    -1,    -1,    -1,
      52,    13,    -1,    55,   414,    57,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,    -1,    28,    29,    -1,    -1,
      -1,   210,   211,   212,   434,   435,    -1,   437,   438,    -1,
      42,    43,    44,   443,    -1,    -1,    -1,    -1,   448,    51,
      -1,    -1,    -1,   453,   454,   455,   456,    59,    60,    -1,
     460,    -1,    -1,    -1,    -1,    -1,    -1,   467,   247,   248,
     249,   250,   251,   252,   474,    -1,    -1,    -1,    -1,    -1,
     480,    -1,   482,   483,    -1,   485,   486,   487,   488,    -1,
      -1,    -1,   271,   272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   280,    -1,    -1,    -1,    -1,   285,   286,   287,   288,
     289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,   112,    -1,    13,   115,    -1,    -1,
     339,    -1,    -1,   342,    -1,    -1,    -1,    -1,    -1,    -1,
     349,    28,    29,    -1,    -1,   575,   355,    -1,    -1,    -1,
     138,    -1,    -1,    -1,    -1,    42,    43,    44,    -1,   147,
      -1,   591,   150,   151,    51,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    59,    60,   383,    -1,   385,    -1,   387,    -1,
     389,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,   627,    -1,    -1,
      -1,    -1,    13,    -1,    -1,   414,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    -1,   210,   211,   212,   434,   435,    -1,   437,   438,
      -1,    42,    43,    44,   443,    -1,    -1,    -1,    -1,   448,
      51,    -1,    53,    -1,   453,   454,   455,   456,    59,    60,
      -1,   460,    -1,    -1,    -1,    -1,    -1,    -1,   467,   247,
     248,   249,   250,   251,   252,   474,    -1,    -1,    -1,    -1,
      -1,   480,    -1,   482,   483,    -1,   485,   486,   487,   488,
      -1,    -1,    -1,   271,   272,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   280,    -1,    -1,    -1,    -1,   285,   286,   287,
     288,   289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,   112,    -1,    13,   115,    -1,
      -1,   339,    -1,    -1,   342,    -1,    -1,    -1,    -1,    -1,
      -1,   349,    28,    29,    -1,    -1,   575,   355,    -1,    -1,
      -1,   138,    -1,    -1,    -1,    -1,    42,    43,    44,    -1,
     147,    -1,   591,   150,   151,    51,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    59,    60,   383,    -1,   385,    -1,   387,
      -1,   389,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,     7,   627,    -1,
      -1,    -1,    -1,    13,    -1,    -1,   414,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    28,    29,
      -1,    -1,    -1,   210,   211,   212,   434,   435,    -1,   437,
     438,    -1,    42,    43,    44,   443,    -1,    -1,    -1,    -1,
     448,    51,    -1,    -1,    -1,   453,   454,   455,   456,    59,
      60,    -1,   460,    -1,    -1,    -1,    -1,    -1,    -1,   467,
     247,   248,   249,   250,   251,   252,   474,    -1,    -1,    -1,
      -1,    -1,   480,    -1,   482,   483,    -1,   485,   486,   487,
     488,    -1,    -1,    -1,   271,   272,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   280,    -1,    -1,    -1,    -1,   285,   286,
     287,   288,   289,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    -1,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,    42,    -1,   115,
      -1,    -1,   339,    -1,    -1,   342,    51,    -1,    53,    -1,
      -1,    -1,   349,    -1,    59,    60,    -1,   575,   355,    -1,
      -1,    -1,   138,    -1,     1,    -1,     3,     4,     5,     6,
       7,   147,    -1,   591,   150,   151,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,   383,    -1,   385,    -1,
     387,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    -1,   627,
      -1,    -1,    -1,    -1,    51,    -1,    -1,   414,    -1,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   210,   211,   212,   434,   435,    -1,
     437,   438,    -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,
      -1,   448,    -1,    -1,    -1,    -1,   453,   454,   455,   456,
      -1,    -1,    -1,   460,    -1,    -1,    -1,    -1,    -1,    -1,
     467,   247,   248,   249,   250,   251,   252,   474,    -1,    -1,
      -1,    -1,    -1,   480,    -1,   482,    -1,    -1,   485,   486,
     487,   488,    -1,    -1,    -1,   271,   272,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   280,    -1,    -1,    -1,    -1,   285,
     286,   287,   288,   289,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,    -1,     1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,   112,    -1,    -1,
     115,    -1,    -1,   339,    -1,    -1,   342,    -1,    -1,    -1,
      -1,    28,    29,   349,    -1,    -1,    -1,    -1,   575,   355,
      -1,    -1,    -1,   138,    -1,    42,    43,    44,    -1,    -1,
      -1,    -1,   147,    50,    51,     3,     4,     5,     6,     7,
      -1,    -1,    59,    60,    -1,    13,    -1,   383,    -1,   385,
      -1,   387,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,
      28,    29,    -1,     1,    -1,     3,     4,     5,     6,     7,
     627,    -1,    -1,    -1,    42,    13,    44,    -1,   414,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    -1,   210,    -1,    -1,   434,   435,
      -1,   437,   438,    -1,    42,    43,    44,   443,    -1,    -1,
      -1,    -1,   448,    51,    -1,    -1,    -1,   453,   454,   455,
     456,    59,    60,    -1,   460,    -1,    -1,   112,    -1,    -1,
     115,   467,   247,   248,   249,   250,   251,   252,   474,    -1,
      -1,    -1,    -1,    -1,   480,    -1,   482,    -1,    -1,   485,
     486,   487,   488,   138,    -1,    -1,   271,   272,    -1,    -1,
      -1,    -1,   147,    -1,    -1,   280,    -1,    -1,    -1,    -1,
     285,   286,   287,   288,   289,    -1,    -1,    -1,     1,    -1,
       3,     4,     5,     6,     7,    -1,   322,    -1,    -1,    -1,
      13,    -1,    -1,    -1,   309,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    25,    -1,    -1,    28,    29,    30,    -1,    32,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,   339,   210,    -1,   342,    51,    -1,
      -1,    -1,    -1,    -1,   349,    -1,    59,    60,    -1,   575,
     355,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,   247,   248,   249,   250,   251,   252,    -1,    -1,
      28,    29,   387,   409,   410,   411,   412,     1,    -1,     3,
       4,     5,     6,     7,    42,    -1,    44,   272,    -1,    13,
      -1,   627,    -1,    51,    -1,   280,    -1,    -1,    22,   414,
      -1,    25,    -1,    -1,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,   434,
     435,    -1,   437,   438,   309,    -1,    -1,    51,   443,    -1,
      -1,    -1,    -1,   448,    -1,    59,    60,    -1,   453,   454,
     455,   456,    -1,    -1,    -1,   460,    -1,   409,   410,   411,
     412,    -1,   467,    -1,   339,    -1,    -1,   342,    -1,   474,
      -1,    -1,    -1,    -1,   349,    -1,    -1,    -1,    -1,    -1,
     485,   486,   487,   488,    -1,    -1,    -1,     1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    22,    23,
      -1,    25,   387,    -1,    28,    29,    30,    -1,    32,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,   414,
     566,    -1,    -1,    -1,   570,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,
     435,    -1,   437,   438,    -1,    -1,    -1,    -1,   443,    -1,
     575,    -1,    -1,   448,    -1,    -1,    -1,    -1,    -1,   454,
     455,   456,    -1,    -1,    -1,    -1,    -1,    -1,   614,   615,
     616,   617,   467,   619,   620,   621,   622,    -1,    -1,   474,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     485,   486,   487,   488,   566,    -1,    -1,    -1,   570,    -1,
      -1,    -1,   627,    -1,    -1,   651,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   662,    -1,   664,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   675,
     676,   677,   678,   679,   680,    -1,   682,    -1,   684,   685,
      -1,   687,   614,   615,   616,   617,    -1,   619,   620,   621,
     622,    -1,    -1,    -1,   700,    -1,   702,   703,    -1,    -1,
      -1,     1,   708,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    -1,   651,
     575,    -1,    -1,    -1,    -1,    25,    -1,    -1,    28,    29,
     662,    -1,   664,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,   675,   676,   677,   678,   679,   680,    -1,
     682,    51,   684,   685,    -1,   687,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   700,    -1,
     702,   703,   627,    -1,    -1,     1,   708,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    22,    23,    -1,    25,
      -1,    -1,    28,    29,    30,    -1,    32,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    51,     3,     4,     5,     6,
       7,    -1,    -1,    59,    60,    -1,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    22,    23,    -1,    25,    -1,
      -1,    28,    29,    30,    -1,    32,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    51,     3,     4,     5,     6,     7,
      -1,    -1,    59,    60,    -1,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    22,    23,    -1,    25,    -1,    -1,
      28,    29,    30,    -1,    32,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    51,     3,     4,     5,     6,     7,    -1,
      -1,    59,    60,    -1,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    22,    23,    -1,    25,    -1,    -1,    28,
      29,    30,    -1,    32,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    51,     3,     4,     5,     6,     7,    -1,    -1,
      59,    60,    -1,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    22,    23,    -1,    25,    -1,    -1,    28,    29,
      30,    -1,    32,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    51,     3,     4,     5,     6,     7,    -1,    -1,    59,
      60,    -1,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    22,    23,    -1,    25,    -1,    -1,    28,    29,    30,
      -1,    32,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      51,     3,     4,     5,     6,     7,    -1,    -1,    59,    60,
      -1,    13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      22,    23,    -1,    25,    -1,    -1,    28,    29,    30,    -1,
      32,    -1,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    51,
       3,     4,     5,     6,     7,    -1,    -1,    59,    60,    -1,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    22,
      23,    -1,    25,    -1,    -1,    28,    29,    30,    -1,    32,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    51,     3,
       4,     5,     6,     7,    -1,    -1,    59,    60,    -1,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    22,    23,
      -1,    25,    -1,    -1,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    51,     3,     4,
       5,     6,     7,    -1,    -1,    59,    60,    -1,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    22,    23,    -1,
      25,    -1,    -1,    28,    29,    30,    -1,    32,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    51,     3,     4,     5,
       6,     7,    -1,    -1,    59,    60,    -1,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    22,    23,    -1,    25,
      -1,    -1,    28,    29,    30,    -1,    32,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    51,     3,     4,     5,     6,
       7,    -1,    -1,    59,    60,    -1,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    22,    23,    -1,    25,    -1,
      -1,    28,    29,    30,    -1,    32,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    51,     3,     4,     5,     6,     7,
      -1,    -1,    59,    60,    -1,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    22,    23,    -1,    25,    -1,    -1,
      28,    29,    30,    -1,    32,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    51,     3,     4,     5,     6,     7,    -1,
      -1,    59,    60,    -1,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    22,    23,    -1,    25,    -1,    -1,    28,
      29,    30,    -1,    32,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,     1,    -1,     3,     4,     5,     6,
       7,    -1,    51,    -1,    -1,    -1,    13,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,    22,    -1,    -1,    25,    -1,
      -1,    28,    29,    30,    -1,    32,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,     1,    -1,     3,     4,
       5,     6,     7,    -1,    51,    -1,    -1,    -1,    13,    -1,
      -1,    -1,    59,    60,    -1,     1,    -1,     3,     4,     5,
       6,     7,    -1,    28,    29,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      -1,    -1,    28,    29,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    60,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,     1,    51,     3,     4,     5,     6,
       7,    -1,    -1,    59,    60,     1,    13,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    42,    43,    44,    -1,
      -1,    -1,    59,    60,     1,    51,     3,     4,     5,     6,
       7,    -1,    -1,    59,    60,     1,    13,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    42,    43,    44,    -1,
      -1,    -1,    59,    60,     1,    51,     3,     4,     5,     6,
       7,    -1,    -1,    59,    60,     1,    13,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    59,    60,    -1,    51,    -1,    53,     3,     4,
       5,     6,     7,    59,    60,    -1,    -1,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    28,    29,    -1,    31,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      -1,    -1,    28,    29,    -1,    31,    51,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    59,    60,    42,    43,    44,     3,
       4,     5,     6,     7,    -1,    51,    -1,    53,    -1,    13,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    28,    29,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    28,    29,    -1,    -1,    59,    60,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    42,    43,    44,    -1,    13,
      -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    59,    60,    28,    29,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    50,    51,    -1,    -1,
      -1,    28,    29,    -1,    -1,    59,    60,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    42,    43,    44,    -1,    13,
      -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    -1,
      -1,    25,    59,    60,    28,    29,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    25,    -1,
      -1,    28,    29,    -1,    -1,    59,    60,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    42,    43,    44,    -1,    13,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    59,    60,    28,    29,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    28,    29,    -1,    -1,    59,    60,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    42,    43,    44,    -1,    13,
      -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    -1,
      -1,    25,    59,    60,    28,    29,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    28,    29,    -1,    -1,    59,    60,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    42,    43,    44,    -1,    13,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    28,    29,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    28,    29,    -1,    -1,    59,    60,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    42,    -1,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    59,    60,    28,    29,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,
      -1,    28,    29,    -1,    -1,    59,    60,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    42,    -1,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    59,    60,    28,    29,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,
      -1,    28,    29,    -1,    -1,    59,    60,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    42,    -1,    -1,    -1,    13,
      -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    59,    60,    28,    29,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    13,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,
      -1,    28,    29,    -1,    -1,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    25,    52,    63,    64,    75,    76,    77,    78,
      79,    20,     0,    76,     1,     3,    20,    78,     3,     3,
       3,     1,     3,     1,     3,    14,    15,    16,    17,    21,
      22,    27,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    77,    80,    81,    82,    83,    84,    85,    90,    91,
      96,    97,    80,    81,    81,    80,    81,     1,    80,    81,
      25,    28,    49,    28,    53,     3,    71,    73,    82,     3,
      92,     3,    86,    87,    88,    92,     1,    49,     1,    19,
      49,    27,    66,    97,    81,    23,    83,     1,    22,    25,
      95,   100,     1,    22,    98,    81,    81,    81,    81,     1,
      66,    93,    94,    50,    53,    93,     1,    23,    28,    49,
      24,    25,     1,    49,    50,    54,    50,     1,    50,    50,
       1,     3,     1,    50,    92,    25,    86,    92,    98,    23,
       1,     4,     5,     6,     7,    13,    23,    25,    28,    29,
      30,    32,    36,    37,    38,    39,    40,    41,    42,    51,
      59,    60,    65,    66,    73,   100,   101,   102,   103,   104,
     105,   107,   108,   109,   110,   111,   112,   114,   120,   122,
     123,   128,   129,   130,   131,   132,   133,   135,   139,   140,
     141,   142,   143,   144,   146,   147,   161,   162,     1,    23,
      29,    51,    99,   101,     1,    23,    99,   101,     3,    88,
       1,    24,    53,     1,    53,     0,    53,    93,    50,    87,
      28,    43,    44,    73,    89,   133,   140,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   164,     1,    50,
      89,    25,    25,    25,    25,     0,   164,     1,    28,     1,
      28,     1,    28,     1,   105,    28,     1,    25,    25,    25,
     164,     1,    67,    71,    19,    73,   139,   141,   145,   145,
      86,    28,    49,     1,    23,   102,    25,     1,    25,    19,
      49,    59,    60,    26,    54,   163,     1,    28,     1,    28,
      23,   101,    23,     0,     1,    23,   101,     1,    23,    94,
      94,    22,    53,     1,    67,    73,   164,   145,   145,    49,
      45,    43,    55,    56,    46,    48,    47,    58,    57,    25,
      53,    31,    53,   164,     1,   164,     1,    22,    53,   115,
     164,     1,   164,    53,   164,     1,   164,    25,    36,     1,
      36,     1,    25,   104,   110,   125,   127,    23,    25,    49,
     136,   137,     1,   136,     1,    28,   136,     3,     1,    53,
     134,   164,   164,     0,     1,     3,   164,   160,    53,   134,
       1,    53,   134,    53,   134,     1,    53,   134,    23,     0,
       1,    23,     0,     1,    49,    53,   138,    49,   138,    53,
     145,   150,   151,   152,   153,   154,   155,   156,   157,   105,
      30,    36,    38,   105,   106,   107,   113,   121,   124,    53,
      53,     1,    53,    23,    33,    34,   116,   117,   118,   119,
       1,    23,   116,   118,   115,    53,    53,     1,    53,   105,
      53,    53,     1,    53,    28,    28,   164,     1,    28,    25,
       1,    25,   164,    25,    24,     1,   164,   137,    49,   138,
      53,   134,   138,    28,    24,     1,    24,    53,    50,    53,
      28,    50,    25,    53,    25,     1,    25,     1,    53,    25,
      53,    25,     1,    25,     1,    53,     0,   145,    50,   145,
       1,    49,    53,    53,   148,     1,    28,     1,    28,    28,
      31,   105,   106,   105,   106,   105,   106,   105,   106,     1,
     164,   165,     1,    35,    23,   117,   118,    23,   101,   119,
       0,    23,    23,   118,     1,    23,   115,   115,   115,   115,
     105,   105,   105,   105,   164,   164,    53,    53,   164,     1,
     164,    25,    25,    53,     1,    53,   126,   127,    25,    25,
     164,   110,    50,    50,    53,    53,   134,   164,   164,   164,
      53,   134,    25,    23,    25,     1,    25,    25,    23,    25,
       1,    25,   145,    50,   145,   148,    53,   164,     1,   164,
      53,   164,     1,   164,     1,    25,   125,   105,    31,    31,
      31,    31,    35,     1,    35,    25,    23,     1,    23,     0,
      53,    53,    25,    25,    53,    53,     1,    53,    53,    53,
     105,    53,   105,    53,    53,   126,    53,   126,    25,    53,
      53,    23,    23,   106,    53,    53,     1,    53,   106,    53,
      53,     1,    53,    25,     1,    25,   164,    25,   105,   105,
     105,   105,    25,     0,    25,    25,    25,    25,    25,     1,
      25,   105,   105,   105,   105,   105,    53,   105,    53,    53,
     126,    31,   106,   106,   106,   106,   106,   106,   106,   106,
      25,    25,    53,     1,    53,   126,    25,    25,   164,    22,
     105,   105,   105,    53,   106,    31,    31,    31,    31,    53,
      53,   106,    53,   106,    53,    53,   126,    53,   126,    25,
     105,   106,   106,   106,   106,   106,   106,   106,   106,   106,
      53,   106,    53,    53,   126,   106,   106,   106,    53,   106
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 298 "bison.y"
    {
	root = (yyvsp[(1) - (1)].node);
;}
    break;

  case 3:
#line 301 "bison.y"
    { ;}
    break;

  case 4:
#line 303 "bison.y"
    {
	(yyval.node) = new Node ("Compilation Unit", 1);
	(yyval.node) -> AddChild((yyvsp[(1) - (1)].node));
;}
    break;

  case 5:
#line 308 "bison.y"
    {
		(yyval.node) = new Node ("Literal",1); 		
		(yyval.node)->AddChild(new Node("IntegerLiteral", new Node((yyvsp[(1) - (1)].str), 0), (yylsp[(1) - (1)]).first_line));
		;}
    break;

  case 6:
#line 312 "bison.y"
    {
		(yyval.node) = new Node ("Literal",1); 
		(yyval.node)->AddChild(new Node("FloatingPointLiteral", new Node((yyvsp[(1) - (1)].str), 0), (yylsp[(1) - (1)]).first_line)); ;}
    break;

  case 7:
#line 315 "bison.y"
    {
		(yyval.node) = new Node ("Literal",1); 
		(yyval.node)->AddChild(new Node("CharLiteral", new Node((yyvsp[(1) - (1)].str), 0), (yylsp[(1) - (1)]).first_line)); ;}
    break;

  case 8:
#line 318 "bison.y"
    {
		(yyval.node) = new Node ("Literal",1); 
		(yyval.node)->AddChild(new Node("StringLiteral", new Node((yyvsp[(1) - (1)].str), 0), (yylsp[(1) - (1)]).first_line)); ;}
    break;

  case 9:
#line 321 "bison.y"
    {
		(yyval.node) = new Node ("Literal",1); 
		(yyval.node)->AddChild(new Node("TrueOrFalse", new Node((yyvsp[(1) - (1)].str), 0), (yylsp[(1) - (1)]).first_line)); ;}
    break;

  case 10:
#line 325 "bison.y"
    {
		(yyval.node) = new Node ("Type",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 11:
#line 328 "bison.y"
    {
		(yyval.node) = new Node ("Type",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 12:
#line 332 "bison.y"
    {
		(yyval.node) = new Node ("PrimitiveType",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 13:
#line 335 "bison.y"
    {
		(yyval.node) = new Node ("PrimitiveType",1); 
		(yyval.node)->AddChild(new Node((yyvsp[(1) - (1)].str), 0)); ;}
    break;

  case 14:
#line 339 "bison.y"
    {
		(yyval.node) = new Node ("NumericType",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 15:
#line 342 "bison.y"
    {
		(yyval.node) = new Node ("NumericType",1); 
		(yyval.node)->AddChild(new Node((yyvsp[(1) - (1)].str), 0)); ;}
    break;

  case 16:
#line 346 "bison.y"
    {
		(yyval.node) = new Node ("IntegralType",1); 
		(yyval.node) -> AddChild (new Node((yyvsp[(1) - (1)].str), 0)); ;}
    break;

  case 17:
#line 349 "bison.y"
    {
		(yyval.node) = new Node ("IntegralType", 1); 
		(yyval.node) -> AddChild (new Node((yyvsp[(1) - (1)].str), 0)); ;}
    break;

  case 18:
#line 352 "bison.y"
    { 
		codigo_sin_errores = false;
		mierror = (yylsp[(1) - (2)]).first_line;
		printf("Line %d: IntegralType (char, int) expected \n",mierror);
		yyerrok ;;}
    break;

  case 19:
#line 358 "bison.y"
    {
		(yyval.node) = new Node ("ReferenceType",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 20:
#line 361 "bison.y"
    {
		(yyval.node) = new Node ("ReferenceType",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 21:
#line 365 "bison.y"
    {
		(yyval.node) = new Node ("ClassType",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 22:
#line 369 "bison.y"
    {
		(yyval.node) = new Node ("ArrayType",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node)); 
		(yyval.node) -> AddChild(new Node((yyvsp[(2) - (3)].str), 0));
		(yyval.node) -> AddChild(new Node((yyvsp[(3) - (3)].str), 0));;}
    break;

  case 23:
#line 374 "bison.y"
    {
		(yyval.node) = new Node ("ArrayType",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node)); 
		(yyval.node) -> AddChild(new Node((yyvsp[(2) - (3)].str), 0));
		(yyval.node) -> AddChild(new Node((yyvsp[(3) - (3)].str), 0));;}
    break;

  case 24:
#line 380 "bison.y"
    { 
		codigo_sin_errores = false;
		mierror = (yylsp[(1) - (3)]).first_line;
		printf("Line %d: PrimitiveType expected\n",mierror);
		yyerrok ;;}
    break;

  case 25:
#line 385 "bison.y"
    { 
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (3)]).first_line;
		printf("Line %d: Opening bracket expected after Name\n",mierror);
		yyerrok ;;}
    break;

  case 26:
#line 390 "bison.y"
    { 
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (3)]).first_line;
		printf("Line %d: Opening bracket expected after PrimitiveType\n",mierror);
		yyerrok ;;}
    break;

  case 27:
#line 395 "bison.y"
    { 
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (4)]).first_line;
		printf("Closing bracket expected after Name \n");
		yyerrok ;;}
    break;

  case 28:
#line 400 "bison.y"
    { 
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (4)]).first_line;
		printf("Closing bracket expected after PrimitiveType\n");
		yyerrok ;;}
    break;

  case 29:
#line 406 "bison.y"
    {
		(yyval.node) = new Node ("Name",1); 
		(yyval.node)->AddChild(new Node("Identifier", new Node((yyvsp[(1) - (1)].str), 0), (yylsp[(1) - (1)]).first_line)); ;}
    break;

  case 30:
#line 409 "bison.y"
    {
		(yyval.node) = new Node ("Name",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 31:
#line 413 "bison.y"
    {
		(yyval.node) = new Node ("QualifiedName",3);
		(yyval.node) -> AddChild((yyvsp[(1) - (3)].node)); 
		(yyval.node) -> AddChild(new Node(".", 0));		
		(yyval.node)->AddChild(new Node("Identifier", new Node((yyvsp[(3) - (3)].str), 0), (yylsp[(3) - (3)]).first_line)); ;}
    break;

  case 32:
#line 419 "bison.y"
    {
			mierror = (yylsp[(3) - (4)]).first_line;
			printf("Line %d: invalid name for method call\n", mierror);
		;}
    break;

  case 33:
#line 424 "bison.y"
    {
		(yyval.node) = new Node ("TypeDeclarations",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 34:
#line 427 "bison.y"
    {
		(yyval.node) = new Node ("TypeDeclarations",2); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (2)].node)); 
		(yyval.node) -> AddChild((yyvsp[(2) - (2)].node)); ;}
    break;

  case 35:
#line 432 "bison.y"
    {
		(yyval.node) = new Node ("TypeDeclaration",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node));;}
    break;

  case 36:
#line 435 "bison.y"
    {
		(yyval.node) = new Node ("TypeDeclaration",1); 
		(yyval.node) -> AddChild (new Node(";", 0)); ;}
    break;

  case 37:
#line 439 "bison.y"
    {
		(yyval.node) = new Node ("Modifiers",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 38:
#line 442 "bison.y"
    {
		(yyval.node) = new Node ("Modifiers",2); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (2)].node));
		(yyval.node) -> AddChild((yyvsp[(2) - (2)].node)); ;}
    break;

  case 39:
#line 452 "bison.y"
    {
		(yyval.node) = new Node ("Modifier",1); 
		(yyval.node) -> AddChild(new Node((yyvsp[(1) - (1)].str), 0)); ;}
    break;

  case 40:
#line 461 "bison.y"
    {
		(yyval.node) = new Node ("ClassDeclaration",5); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (5)].node)); 
		(yyval.node) -> AddChild (new Node("class", 0));
		(yyval.node)->AddChild(new Node("Identifier", new Node((yyvsp[(3) - (5)].str), 0), (yylsp[(3) - (5)]).first_line));
		(yyval.node) -> AddChild ((yyvsp[(4) - (5)].node));
		(yyval.node) -> AddChild ((yyvsp[(5) - (5)].node));

			;}
    break;

  case 41:
#line 470 "bison.y"
    {
		(yyval.node) = new Node ("ClassDeclaration",4); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (4)].node));		
		(yyval.node) -> AddChild (new Node((yyvsp[(2) - (4)].str), 0));
		(yyval.node)->AddChild(new Node("Identifier", new Node((yyvsp[(3) - (4)].str), 0), (yylsp[(3) - (4)]).first_line));
		(yyval.node) -> AddChild ((yyvsp[(4) - (4)].node));
		;}
    break;

  case 42:
#line 479 "bison.y"
    { 
	
		codigo_sin_errores = false;		
		mierror = (yylsp[(2) - (4)]).first_line;							
		printf("Line %d: class keyword Expected\n", mierror);
		yyerrok ;;}
    break;

  case 43:
#line 485 "bison.y"
    { 
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (4)]).first_line;
		printf("Line %d: Class name expected\n", mierror);	
		yyerrok ;;}
    break;

  case 44:
#line 490 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(1) - (4)]).first_line;
		printf("Line %d: Modifier (public, private...) expected\n", mierror);		
		yyerrok ;;}
    break;

  case 45:
#line 495 "bison.y"
    { 
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (5)]).first_line;
		printf("Line %d: class keyword expected\n", mierror);
		yyerrok ;;}
    break;

  case 46:
#line 500 "bison.y"
    { 
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (5)]).first_line;
		printf("Line %d: Class name expected\n", mierror);
		yyerrok ;;}
    break;

  case 47:
#line 505 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(1) - (5)]).first_line;
		printf("Line %d: Modifier (public, private...) expected\n", mierror);	
		yyerrok ;;}
    break;

  case 48:
#line 510 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (5)]).first_line;
		if(debug) printf("Line %d: en extends Superclass.Classname\n", mierror);
		yyerrok ;;}
    break;

  case 49:
#line 515 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (4)]).first_line;
		yyerror("sintax error, unexpected Identifier, expected Class");
		printf("Line %d: unexpected Identifier, expected 'class'\n", mierror);
		yyerrok;
	;}
    break;

  case 50:
#line 524 "bison.y"
    {
		(yyval.node) = new Node ("Super",2); 
		(yyval.node)->line = (yylsp[(1) - (2)]).first_line;
		(yyval.node) -> AddChild (new Node((yyvsp[(1) - (2)].str), 0));
		(yyval.node) -> AddChild ((yyvsp[(2) - (2)].node)); ;}
    break;

  case 51:
#line 530 "bison.y"
    {
		(yyval.node) = new Node ("ClassBody",3);
		(yyval.node) -> AddChild(new Node("{", 0)); 
		(yyval.node) -> AddChild ((yyvsp[(2) - (3)].node)); 
		(yyval.node) -> AddChild(new Node("}", 0));;}
    break;

  case 52:
#line 536 "bison.y"
    {
		codigo_sin_errores = false;
		if(debug) printf("Ending bracket '}' missing\n");
		yyerrok ;;}
    break;

  case 53:
#line 541 "bison.y"
    {
		mierror = (yylsp[(1) - (2)]).first_line;
		codigo_sin_errores = false;
		(yyval.node) = new Node ("ClassBody",2);
		(yyval.node) -> AddChild ((yyvsp[(1) - (2)].node)); 
		(yyval.node) -> AddChild (new Node((yyvsp[(2) - (2)].str), 0)); 
		yyerror("syntax error: unexpected ClassBodyDeclarations, expected OpenLlave");
		printf("Line %d: Missing opening bracket {\n", mierror);
		yyerrok ;
	;}
    break;

  case 54:
#line 553 "bison.y"
    {
		(yyval.node) = new Node ("ClassBodyDeclarations",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 55:
#line 556 "bison.y"
    {
		(yyval.node) = new Node ("ClassBodyDeclarations",2); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (2)].node)); 
		(yyval.node) -> AddChild ((yyvsp[(2) - (2)].node));;}
    break;

  case 56:
#line 561 "bison.y"
    {
		(yyval.node) = new Node ("ClassBodyDeclaration",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 57:
#line 564 "bison.y"
    {
		(yyval.node) = new Node ("ClassBodyDeclaration",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 58:
#line 568 "bison.y"
    {
		(yyval.node) = new Node ("ClassMemberDeclaration",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 59:
#line 571 "bison.y"
    {
		(yyval.node) = new Node ("ClassMemberDeclaration",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 60:
#line 575 "bison.y"
    {
		(yyval.node) = new Node ("FieldDeclaration",4); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (4)].node)); 
		(yyval.node) -> AddChild ((yyvsp[(2) - (4)].node));
		(yyval.node) -> AddChild ((yyvsp[(3) - (4)].node));
		(yyval.node) -> AddChild (new Node(";", 0));;}
    break;

  case 61:
#line 581 "bison.y"
    {
		(yyval.node) = new Node ("FieldDeclaration",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node)); 
		(yyval.node) -> AddChild ((yyvsp[(2) - (3)].node)); 
		(yyval.node) -> AddChild (new Node(";", 0));;}
    break;

  case 62:
#line 586 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (3)]).first_line;
		yyerror("syntax error, unexpected PuntoComa, expected VariableDeclarators");
		printf("Line %d: VariableDeclarators expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 63:
#line 594 "bison.y"
    {
		(yyval.node) = new Node ("VariableDeclarators",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 64:
#line 597 "bison.y"
    {
		(yyval.node) = new Node ("VariableDeclarators",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node), (yylsp[(1) - (3)]).first_line); 
		(yyval.node) -> AddChild (new Node((yyvsp[(2) - (3)].str), 0), (yylsp[(2) - (3)]).first_line);
		(yyval.node) -> AddChild ((yyvsp[(3) - (3)].node), (yylsp[(3) - (3)]).first_line); ;}
    break;

  case 65:
#line 608 "bison.y"
    {
		(yyval.node) = new Node ("VariableDeclarator",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 66:
#line 611 "bison.y"
    {
		(yyval.node) = new Node ("VariableDeclarator",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node)); 
		(yyval.node) -> AddChild (new Node((yyvsp[(2) - (3)].str), 0));
		(yyval.node) -> AddChild ((yyvsp[(3) - (3)].node)); ;}
    break;

  case 67:
#line 616 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (3)]).first_line;
		printf("Line %d: '=' token likely missing.\n", mierror);
		yyerrok;
	;}
    break;

  case 68:
#line 631 "bison.y"
    {
		(yyval.node) = new Node ("VariableDeclaratorId",1); 
		(yyval.node)->AddChild(new Node("Identifier", new Node((yyvsp[(1) - (1)].str), 0), (yylsp[(1) - (1)]).first_line)); 
		//printf("Encontrada variable %s en linea %d\n", $1, @1.first_line);
		;}
    break;

  case 69:
#line 636 "bison.y"
    {
		(yyval.node) = new Node ("VariableDeclaratorId",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node)); 
		(yyval.node) -> AddChild (new Node("[", 0));
		(yyval.node) -> AddChild (new Node("]", 0));;}
    break;

  case 70:
#line 648 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (2)]).first_line;
		yyerror("syntax error: unexpected CloseCorchete, expecting OpenCorchete");
		printf("Line %d: Close Bracket ']' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 71:
#line 656 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (4)]).first_line;
		printf("Line %d: Open Bracket '[' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 72:
#line 663 "bison.y"
    {
		(yyval.node) = new Node ("VariableInitializer",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 73:
#line 667 "bison.y"
    {
		(yyval.node) = new Node ("MethodDeclaration",2); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (2)].node)); 
		(yyval.node) -> AddChild ((yyvsp[(2) - (2)].node));;}
    break;

  case 74:
#line 672 "bison.y"
    {
		(yyval.node) = new Node ("MethodHeader",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node));
		(yyval.node) -> AddChild ((yyvsp[(2) - (3)].node));
		(yyval.node) -> AddChild ((yyvsp[(3) - (3)].node)); ;}
    break;

  case 75:
#line 677 "bison.y"
    {
		(yyval.node) = new Node ("MethodHeader",2); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (2)].node));
		(yyval.node) -> AddChild ((yyvsp[(2) - (2)].node)); ;}
    break;

  case 76:
#line 681 "bison.y"
    {
		(yyval.node) = new Node ("MethodHeader",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node));
		(yyval.node) -> AddChild (new Node((yyvsp[(2) - (3)].str), 0));
		(yyval.node) -> AddChild ((yyvsp[(3) - (3)].node)); ;}
    break;

  case 77:
#line 686 "bison.y"
    {
		(yyval.node) = new Node ("MethodHeader",2); 
		(yyval.node) -> AddChild (new Node((yyvsp[(1) - (2)].str), 0)); 
		(yyval.node) -> AddChild ((yyvsp[(2) - (2)].node));;}
    break;

  case 78:
#line 691 "bison.y"
    {
		(yyval.node) = new Node ("MethodDeclarator",4); 
		(yyval.node)->AddChild(new Node("Identifier", new Node((yyvsp[(1) - (4)].str), 0), (yylsp[(1) - (4)]).first_line));
		(yyval.node) -> AddChild (new Node("(", 0));
		(yyval.node) -> AddChild ((yyvsp[(3) - (4)].node));
		(yyval.node) -> AddChild (new Node(")", 0));;}
    break;

  case 79:
#line 697 "bison.y"
    {
		(yyval.node) = new Node ("MethodDeclarator",3); 
		(yyval.node)->AddChild(new Node("Identifier", new Node((yyvsp[(1) - (3)].str), 0), (yylsp[(1) - (3)]).first_line));
		(yyval.node) -> AddChild (new Node("(", 0));
		(yyval.node) -> AddChild( new Node(")", 0));;}
    break;

  case 80:
#line 702 "bison.y"
    {
		(yyval.node) = new Node ("MethodDeclarator",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node)); 
		(yyval.node) -> AddChild (new Node("[", 0));
		(yyval.node) -> AddChild (new Node("]", 0));;}
    break;

  case 81:
#line 708 "bison.y"
    {
		(yyval.node) = new Node ("FormalParameterList",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 82:
#line 711 "bison.y"
    {
		(yyval.node) = new Node ("FormalParameterList",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node));
		(yyval.node) -> AddChild (new Node(",", 0)); 
		(yyval.node) -> AddChild ((yyvsp[(3) - (3)].node));;}
    break;

  case 83:
#line 716 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (3)]).first_line;
		printf("Line %d: Comma ',' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 84:
#line 730 "bison.y"
    {
		(yyval.node) = new Node ("FormalParameter",2); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (2)].node));
		(yyval.node) -> AddChild ((yyvsp[(2) - (2)].node)); ;}
    break;

  case 85:
#line 735 "bison.y"
    {
		(yyval.node) = new Node ("MethodBody",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 86:
#line 738 "bison.y"
    {
		(yyval.node) = new Node ("MethodBody",1); 
		(yyval.node) -> AddChild (new Node(";", 0)); ;}
    break;

  case 87:
#line 742 "bison.y"
    {
		(yyval.node) = new Node ("ConstructorDeclaration",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node)); 
		(yyval.node) -> AddChild ((yyvsp[(2) - (3)].node)); 
		(yyval.node) -> AddChild ((yyvsp[(3) - (3)].node)); ;}
    break;

  case 88:
#line 747 "bison.y"
    {
		(yyval.node) = new Node ("ConstructorDeclaration",2); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (2)].node));
		(yyval.node) -> AddChild ((yyvsp[(2) - (2)].node));  ;}
    break;

  case 89:
#line 774 "bison.y"
    {
		(yyval.node) = new Node ("ConstructorDeclarator",4); 
		(yyval.node)->AddChild(new Node("Identifier", new Node((yyvsp[(1) - (4)].str), 0), (yylsp[(1) - (4)]).first_line));
		(yyval.node) -> AddChild (new Node("(", 0));
		(yyval.node) -> AddChild ((yyvsp[(3) - (4)].node)); 
		(yyval.node) -> AddChild (new Node(")", 0));;}
    break;

  case 90:
#line 780 "bison.y"
    {
		(yyval.node) = new Node ("ConstructorDeclarator",3); 
		(yyval.node)->AddChild(new Node("Identifier", new Node((yyvsp[(1) - (3)].str), 0), (yylsp[(1) - (3)]).first_line));
		(yyval.node) -> AddChild (new Node("(", 0));
		(yyval.node) -> AddChild (new Node(")", 0));;}
    break;

  case 91:
#line 785 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(1) - (4)]).first_line;
		printf("Line %d: Identifier expected in ConstructorDeclarator.\n", mierror);
		yyerrok;
	;}
    break;

  case 92:
#line 798 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(1) - (5)]).first_line;
		printf("Line %d: Close parenthesis ')' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 93:
#line 804 "bison.y"
    {
	codigo_sin_errores = false;
	mierror = (yylsp[(1) - (2)]).first_line;
	yyerror("syntax error, unexpected CloseParentesis, expecting OpenParentesis");
	printf("Line %d: Open parenthesis '(' expected in ConstructorDeclarator.\n", mierror);
	yyerrok;
        ;}
    break;

  case 94:
#line 813 "bison.y"
    {
		(yyval.node) = new Node ("ConstructorBody",4); 
		(yyval.node) -> AddChild (new Node("{", 0));
		(yyval.node) -> AddChild ((yyvsp[(2) - (4)].node)); 
		(yyval.node) -> AddChild ((yyvsp[(3) - (4)].node)); 
		(yyval.node) -> AddChild (new Node("}", 0));;}
    break;

  case 95:
#line 819 "bison.y"
    {
		(yyval.node) = new Node ("ConstructorBody",3); 
		(yyval.node) -> AddChild (new Node("{", 0));
		(yyval.node) -> AddChild ((yyvsp[(2) - (3)].node)); 
		(yyval.node) -> AddChild (new Node("}", 0));;}
    break;

  case 96:
#line 824 "bison.y"
    {
		(yyval.node) = new Node ("ConstructorBody",3); 
		(yyval.node) -> AddChild (new Node("{", 0));
		(yyval.node) -> AddChild ((yyvsp[(2) - (3)].node)); 
		(yyval.node) -> AddChild (new Node("}", 0));;}
    break;

  case 97:
#line 829 "bison.y"
    {
		(yyval.node) = new Node ("ConstructorBody",2); 
		(yyval.node) -> AddChild (new Node("{", 0));
		(yyval.node) -> AddChild (new Node("}", 0)); ;}
    break;

  case 98:
#line 833 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(1) - (2)]).first_line;
		printf("Line %d: Open bracket { expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 99:
#line 839 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(1) - (3)]).first_line;
		printf("Line %d: Open bracket { expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 100:
#line 845 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(1) - (3)]).first_line;
		printf("Line %d: Open bracket { expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 101:
#line 851 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(1) - (4)]).first_line;
		printf("Line %d: Open bracket { expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 102:
#line 857 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (3)]).first_line;
		printf("Line %d: Close bracket } expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 103:
#line 864 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (4)]).first_line;
		printf("Line %d: Close bracket } expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 104:
#line 870 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (4)]).first_line;
		printf("Line %d: Close bracket } expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 105:
#line 876 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(4) - (5)]).first_line;
		printf("Line %d: Close bracket } expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 106:
#line 883 "bison.y"
    {
		(yyval.node) = new Node ("ExplicitConstructorInvocation",5); 
		(yyval.node) -> AddChild (new Node("this", 0));
		(yyval.node) -> AddChild (new Node("(", 0)); 
		(yyval.node) -> AddChild ((yyvsp[(3) - (5)].node)); 
		(yyval.node) -> AddChild (new Node(")", 0));
		(yyval.node) -> AddChild (new Node(";", 0)); ;}
    break;

  case 107:
#line 890 "bison.y"
    {
		(yyval.node) = new Node ("ExplicitConstructorInvocation",4); 
		(yyval.node) -> AddChild (new Node("this", 0));
		(yyval.node) -> AddChild (new Node("(", 0)); 
		(yyval.node) -> AddChild (new Node(")", 0));
		(yyval.node) -> AddChild (new Node(";", 0)); ;}
    break;

  case 108:
#line 896 "bison.y"
    {
		(yyval.node) = new Node ("ExplicitConstructorInvocation",5); 
		(yyval.node) -> AddChild (new Node("super", 0));
		(yyval.node) -> AddChild (new Node("(", 0)); 
		(yyval.node) -> AddChild ((yyvsp[(3) - (5)].node)); 
		(yyval.node) -> AddChild (new Node(")", 0));
		(yyval.node) -> AddChild (new Node(";", 0)); ;}
    break;

  case 109:
#line 903 "bison.y"
    {
		(yyval.node) = new Node("ExplicitConstructorInvocation",4); 
		(yyval.node) -> AddChild (new Node("super", 0));
		(yyval.node) -> AddChild (new Node("(", 0)); 
		(yyval.node) -> AddChild (new Node(")", 0));
		(yyval.node) -> AddChild (new Node(";", 0)); ;}
    break;

  case 110:
#line 909 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (4)]).first_line;
		printf("Line %d: Open Parenthesis '(' expected after super.\n", mierror);
		yyerrok;
	;}
    break;

  case 111:
#line 915 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (4)]).first_line;
		printf("Line %d: Close Parenthesis ')' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 112:
#line 921 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (5)]).first_line;
		printf("Line %d: Open Parenthesis '(' expected after super.\n", mierror);
		yyerrok;
	;}
    break;

  case 113:
#line 927 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(4) - (5)]).first_line;
		printf("Line %d: Close Parenthesis ')' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 114:
#line 933 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(5) - (6)]).first_line;
		printf("Line %d: Semicolon ';' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 115:
#line 939 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(4) - (5)]).first_line;
		printf("Line %d: Semicolon ';' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 116:
#line 945 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (4)]).first_line;
		printf("Line %d: Open Parenthesis '(' expected after super.\n", mierror);
		yyerrok;
	;}
    break;

  case 117:
#line 951 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (4)]).first_line;
		printf("Line %d: Close Parenthesis ')' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 118:
#line 957 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (5)]).first_line;
		printf("Line %d: Open Parenthesis '(' expected after super.\n", mierror);
		yyerrok;
	;}
    break;

  case 119:
#line 963 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(4) - (5)]).first_line;
		printf("Line %d: Close Parenthesis ')' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 120:
#line 969 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(5) - (6)]).first_line;
		printf("Line %d: Semicolon ';' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 121:
#line 975 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(4) - (5)]).first_line;
		printf("Line %d: Semicolon ';' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 122:
#line 1002 "bison.y"
    {
		(yyval.node) = new Node ("Block",3); 
		(yyval.node) -> AddChild (new Node("{", 0)); 
		(yyval.node) -> AddChild ((yyvsp[(2) - (3)].node)); 
		(yyval.node) -> AddChild (new Node("}", 0)); ;}
    break;

  case 123:
#line 1007 "bison.y"
    {
		(yyval.node) = new Node ("Block",2); 
		(yyval.node) -> AddChild (new Node("{", 0)); 
		(yyval.node) -> AddChild (new Node("}", 0)); ;}
    break;

  case 124:
#line 1026 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(1) - (2)]).first_line;
		printf("Line %d: Open bracket '{' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 125:
#line 1032 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (4)]).first_line;
		printf("Line %d: Close bracket '}' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 126:
#line 1038 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (3)]).first_line;
		printf("Line %d: Close bracket '}' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 127:
#line 1045 "bison.y"
    {
		(yyval.node) = new Node ("BlockStmts",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 128:
#line 1048 "bison.y"
    {
		(yyval.node) = new Node ("BlockStmts",2); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (2)].node)); 
		(yyval.node) -> AddChild ((yyvsp[(2) - (2)].node)); ;}
    break;

  case 129:
#line 1053 "bison.y"
    {
		(yyval.node) = new Node ("BlockStmt",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 130:
#line 1056 "bison.y"
    {
		(yyval.node) = new Node ("BlockStmt",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 131:
#line 1061 "bison.y"
    {
		(yyval.node) = new Node ("LocalVariableDeclarationStmt",2); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (2)].node), (yylsp[(1) - (2)]).first_line);
		(yyval.node) -> AddChild(new Node(";", 0)); ;}
    break;

  case 132:
#line 1076 "bison.y"
    {
		(yyval.node) = new Node ("LocalVariableDeclaration",2); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (2)].node));
		(yyval.node) -> AddChild ((yyvsp[(2) - (2)].node));  ;}
    break;

  case 133:
#line 1081 "bison.y"
    {
		(yyval.node) = new Node ("Stmt",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 134:
#line 1084 "bison.y"
    {
		(yyval.node) = new Node ("Stmt",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 135:
#line 1087 "bison.y"
    {
		(yyval.node) = new Node ("Stmt",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 136:
#line 1090 "bison.y"
    {
		(yyval.node) = new Node ("Stmt",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 137:
#line 1093 "bison.y"
    {
		(yyval.node) = new Node ("Stmt",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 138:
#line 1097 "bison.y"
    {
		(yyval.node) = new Node ("StmtNoShortIf",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 139:
#line 1100 "bison.y"
    {
		(yyval.node) = new Node ("StmtNoShortIf",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 140:
#line 1103 "bison.y"
    {
		(yyval.node) = new Node ("StmtNoShortIf",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 141:
#line 1106 "bison.y"
    {
		(yyval.node) = new Node ("StmtNoShortIf",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 142:
#line 1111 "bison.y"
    {
		(yyval.node) = new Node ("StmtNoTrailingSubstatement",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 143:
#line 1114 "bison.y"
    {
		(yyval.node) = new Node ("StmtNoTrailingSubstatement",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 144:
#line 1117 "bison.y"
    {
		(yyval.node) = new Node ("StmtNoTrailingSubstatement",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 145:
#line 1120 "bison.y"
    {
		(yyval.node) = new Node ("StmtNoTrailingSubstatement",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 146:
#line 1123 "bison.y"
    {
		(yyval.node) = new Node ("StmtNoTrailingSubstatement",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 147:
#line 1126 "bison.y"
    {
		(yyval.node) = new Node ("StmtNoTrailingSubstatement",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 148:
#line 1129 "bison.y"
    {
		(yyval.node) = new Node ("StmtNoTrailingSubstatement",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 149:
#line 1132 "bison.y"
    {
		(yyval.node) = new Node ("StmtNoTrailingSubstatement",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 150:
#line 1136 "bison.y"
    {
		(yyval.node) = new Node ("EmptyStmt",1); 
		(yyval.node) -> AddChild (new Node(";",0)); ;}
    break;

  case 151:
#line 1140 "bison.y"
    {
		(yyval.node) = new Node ("ExprStmt",2); 
		(yyval.node) -> AddChild((yyvsp[(1) - (2)].node));
		(yyval.node) -> AddChild (new Node(";", 0)); ;}
    break;

  case 152:
#line 1144 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (2)]).first_line;
		printf("Line %d: expected ;\n", mierror);
		yyerrok;
	;}
    break;

  case 153:
#line 1151 "bison.y"
    {
		(yyval.node) = new Node ("StmtExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 154:
#line 1154 "bison.y"
    {
		(yyval.node) = new Node ("StmtExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 155:
#line 1157 "bison.y"
    {
		(yyval.node) = new Node ("StmtExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 156:
#line 1160 "bison.y"
    {
		(yyval.node) = new Node ("StmtExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 157:
#line 1163 "bison.y"
    {
		(yyval.node) = new Node ("StmtExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 158:
#line 1166 "bison.y"
    {
		(yyval.node) = new Node ("StmtExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 159:
#line 1169 "bison.y"
    {
		(yyval.node) = new Node ("StmtExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 160:
#line 1173 "bison.y"
    {
		(yyval.node) = new Node ("IfThenStmt",5); 
		(yyval.node) -> AddChild (new Node("if",0)); 
		(yyval.node) -> AddChild (new Node("(",0)); 
		(yyval.node) -> AddChild ((yyvsp[(3) - (5)].node)); 
		(yyval.node) -> AddChild (new Node(")",0)); 
		(yyval.node) -> AddChild ((yyvsp[(5) - (5)].node)); ;}
    break;

  case 161:
#line 1181 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (5)]).first_line;
		printf("Line %d: Open parenthesis '(' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 162:
#line 1188 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(4) - (5)]).first_line;
		printf("Line %d: Close parenthesis ')' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 163:
#line 1195 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (5)]).first_line;
		printf("Line %d: Error in if expression expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 164:
#line 1202 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (4)]).first_line;
		printf("Line %d: Open parenthesis '(' and expression expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 165:
#line 1225 "bison.y"
    {
		(yyval.node) = new Node ("IfThenElseStmt",7); 
		(yyval.node) -> AddChild (new Node("if",0)); 
		(yyval.node) -> AddChild (new Node("(",0)); 
		(yyval.node) -> AddChild ((yyvsp[(3) - (7)].node)); 
		(yyval.node) -> AddChild (new Node(")",0)); 
		(yyval.node) -> AddChild ((yyvsp[(5) - (7)].node)); 
		(yyval.node) -> AddChild (new Node("else",0)); 
		(yyval.node) -> AddChild ((yyvsp[(7) - (7)].node)); ;}
    break;

  case 166:
#line 1235 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (7)]).first_line;
		printf("Line %d: Open parenthesis '(' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 167:
#line 1242 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(4) - (7)]).first_line;
		printf("Line %d: Close parenthesis ')' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 168:
#line 1249 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (7)]).first_line;
		printf("Line %d: Error in if expression expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 169:
#line 1257 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (6)]).first_line;
		printf("Line %d: Open parenthesis '(' and expression expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 170:
#line 1264 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (4)]).first_line;
		printf("Line %d: Open parenthesis '(', expression and Close parenthesis ')' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 171:
#line 1280 "bison.y"
    {
		(yyval.node) = new Node ("IfThenElseStmtNoShortIf",7); 
		(yyval.node) -> AddChild (new Node("if",0)); 
		(yyval.node) -> AddChild (new Node("(",0)); 
		(yyval.node) -> AddChild ((yyvsp[(3) - (7)].node)); 
		(yyval.node) -> AddChild (new Node(")",0)); 
		(yyval.node) -> AddChild ((yyvsp[(5) - (7)].node)); 
		(yyval.node) -> AddChild (new Node("else",0)); 
		(yyval.node) -> AddChild ((yyvsp[(7) - (7)].node)); ;}
    break;

  case 172:
#line 1290 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (7)]).first_line;
		printf("Line %d: Open parenthesis '(' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 173:
#line 1297 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(4) - (7)]).first_line;
		printf("Line %d: Close parenthesis ')' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 174:
#line 1304 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (7)]).first_line;
		printf("Line %d: Error in if expression expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 175:
#line 1311 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (6)]).first_line;
		printf("Line %d: Open parenthesis '(' and expression expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 176:
#line 1326 "bison.y"
    {
		(yyval.node) = new Node ("SwitchStmt",5); 
		(yyval.node) -> AddChild (new Node("switch",0), (yylsp[(1) - (5)]).first_line); 
		(yyval.node) -> AddChild (new Node("(",0)); 
		(yyval.node) -> AddChild ((yyvsp[(3) - (5)].node)); 
		(yyval.node) -> AddChild (new Node(")",0)); 
		(yyval.node) -> AddChild ((yyvsp[(5) - (5)].node));  ;}
    break;

  case 177:
#line 1334 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (5)]).first_line;
		printf("Line %d: Open parenthesis '(' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 178:
#line 1341 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(4) - (5)]).first_line;
		printf("Line %d: Close parenthesis ')' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 179:
#line 1348 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (5)]).first_line;
		printf("Line %d: Error in if expression expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 180:
#line 1355 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (4)]).first_line;
		printf("Line %d: Open parenthesis '(' and expression expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 181:
#line 1362 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (3)]).first_line;
		printf("Line %d: Open parenthesis '(', expression and Close parenthesis ')' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 182:
#line 1369 "bison.y"
    {
		(yyval.node) = new Node ("SwitchBlock",4); 
		(yyval.node) -> AddChild (new Node("{",0)); 
		(yyval.node) -> AddChild ((yyvsp[(2) - (4)].node), (yylsp[(2) - (4)]).first_line); 
		(yyval.node) -> AddChild ((yyvsp[(3) - (4)].node), (yylsp[(3) - (4)]).first_line);
		(yyval.node) -> AddChild (new Node("}",0));;}
    break;

  case 183:
#line 1375 "bison.y"
    {
		(yyval.node) = new Node ("SwitchBlock",3); 
		(yyval.node) -> AddChild (new Node("{",0)); 
		(yyval.node) -> AddChild ((yyvsp[(2) - (3)].node), (yylsp[(2) - (3)]).first_line); 
		(yyval.node) -> AddChild (new Node("}",0)); ;}
    break;

  case 184:
#line 1380 "bison.y"
    {
		(yyval.node) = new Node ("SwitchBlock",3); 
		(yyval.node) -> AddChild (new Node("{",0)); 
		(yyval.node) -> AddChild ((yyvsp[(2) - (3)].node), (yylsp[(2) - (3)]).first_line); 
		(yyval.node) -> AddChild (new Node("}",0));;}
    break;

  case 185:
#line 1385 "bison.y"
    {
		(yyval.node) = new Node ("SwitchBlock",2); 
		(yyval.node) -> AddChild (new Node("{",0)); 
		(yyval.node) -> AddChild (new Node("}",0)); ;}
    break;

  case 186:
#line 1389 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(1) - (4)]).first_line;
		printf("Line %d: Open bracket '{'.\n", mierror);
		yyerrok;
	;}
    break;

  case 187:
#line 1395 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(1) - (3)]).first_line;
		printf("Line %d: Open bracket '{'.\n", mierror);
		yyerrok;
	;}
    break;

  case 188:
#line 1401 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(1) - (3)]).first_line;
		printf("Line %d: Open bracket '{'.\n", mierror);
		yyerrok;
	;}
    break;

  case 189:
#line 1407 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(1) - (2)]).first_line;
		printf("Line %d: Open bracket '{'.\n", mierror);
		yyerrok;
	;}
    break;

  case 190:
#line 1413 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(4) - (5)]).first_line;
		printf("Line %d: Close bracket '}'.\n", mierror);
		yyerrok;
	;}
    break;

  case 191:
#line 1426 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (4)]).first_line;
		printf("Line %d: Close bracket '}'.\n", mierror);
		yyerrok;
	;}
    break;

  case 192:
#line 1432 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (3)]).first_line;
		printf("Line %d: Close bracket '}'.\n", mierror);
		yyerrok;
	;}
    break;

  case 193:
#line 1438 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (3)]).first_line;
		printf("Line %d: Errors in Statements or Labels\n", mierror);
		yyerrok;
	;}
    break;

  case 194:
#line 1445 "bison.y"
    {
		(yyval.node) = new Node ("SwitchBlockStmtGroups",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 195:
#line 1448 "bison.y"
    {
		(yyval.node) = new Node ("SwitchBlockStmtGroups",2); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (2)].node), (yylsp[(1) - (2)]).first_line); 
		(yyval.node) -> AddChild ((yyvsp[(2) - (2)].node), (yylsp[(2) - (2)]).first_line);;}
    break;

  case 196:
#line 1453 "bison.y"
    {
		(yyval.node) = new Node ("SwitchBlockStmtGroup",2); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (2)].node), (yylsp[(1) - (2)]).first_line); 
		(yyval.node) -> AddChild ((yyvsp[(2) - (2)].node), (yylsp[(2) - (2)]).first_line);;}
    break;

  case 197:
#line 1458 "bison.y"
    {
		(yyval.node) = new Node ("SwitchLabels",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 198:
#line 1461 "bison.y"
    {
		(yyval.node) = new Node ("SwitchLabels",2); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (2)].node), (yylsp[(1) - (2)]).first_line); 
		(yyval.node) -> AddChild ((yyvsp[(2) - (2)].node), (yylsp[(2) - (2)]).first_line);;}
    break;

  case 199:
#line 1466 "bison.y"
    {
		(yyval.node) = new Node ("SwitchLabel",3); 
		(yyval.node) -> AddChild (new Node("case",0), (yylsp[(1) - (3)]).first_line); 		
		(yyval.node) -> AddChild ((yyvsp[(2) - (3)].node)); 
		(yyval.node) -> AddChild (new Node(":",0)); ;}
    break;

  case 200:
#line 1471 "bison.y"
    {
		(yyval.node) = new Node ("SwitchLabel",2); 
		(yyval.node) -> AddChild (new Node("default",0), (yylsp[(1) - (2)]).first_line); 		
		(yyval.node) -> AddChild (new Node(":",0)); ;}
    break;

  case 201:
#line 1475 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (3)]).first_line;
		printf("Line %d: Colon ':' expected \n", mierror);
		yyerrok;
	;}
    break;

  case 202:
#line 1481 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (3)]).first_line;
		printf("Line %d: Errors in ConstantExpresion\n", mierror);
		yyerrok;
	;}
    break;

  case 203:
#line 1487 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (4)]).first_line;
		printf("Line %d: Colon ':' expected\n", mierror);
		yyerrok;
	;}
    break;

  case 204:
#line 1494 "bison.y"
    {
		(yyval.node) = new Node ("WhileStmt",5); 
		(yyval.node) -> AddChild (new Node("while",0)); 	
		(yyval.node) -> AddChild (new Node("(",0)); 		
		(yyval.node) -> AddChild ((yyvsp[(3) - (5)].node)); 
		(yyval.node) -> AddChild (new Node(")",0));
		(yyval.node) -> AddChild ((yyvsp[(5) - (5)].node)); ;}
    break;

  case 205:
#line 1502 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (5)]).first_line;
		printf("Line %d: Open parenthesis '(' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 206:
#line 1509 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(4) - (5)]).first_line;
		printf("Line %d: Close parenthesis ')' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 207:
#line 1516 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (5)]).first_line;
		printf("Line %d: Error in while, expression expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 208:
#line 1523 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (4)]).first_line;
		printf("Line %d: Open parenthesis '(' and expression expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 209:
#line 1530 "bison.y"
    {
		(yyval.node) = new Node ("WhileStmtNoShortIf",5); 
		(yyval.node) -> AddChild (new Node("while",0)); 	
		(yyval.node) -> AddChild (new Node("(",0)); 		
		(yyval.node) -> AddChild ((yyvsp[(3) - (5)].node)); 
		(yyval.node) -> AddChild (new Node(")",0));
		(yyval.node) -> AddChild ((yyvsp[(5) - (5)].node)); ;}
    break;

  case 210:
#line 1538 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (5)]).first_line;
		printf("Line %d: Open parenthesis '(' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 211:
#line 1545 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(4) - (5)]).first_line;
		printf("Line %d: Close parenthesis ')' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 212:
#line 1552 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (5)]).first_line;
		printf("Line %d: Error in while, expression expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 213:
#line 1559 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (4)]).first_line;
		printf("Line %d: Open parenthesis '(' and expression expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 214:
#line 1574 "bison.y"
    {
		(yyval.node) = new Node ("DoStmt",7); 
		(yyval.node) -> AddChild (new Node("do",0)); 			
		(yyval.node) -> AddChild ((yyvsp[(2) - (7)].node)); 
		(yyval.node) -> AddChild (new Node("while",0)); 
		(yyval.node) -> AddChild (new Node("(",0)); 
		(yyval.node) -> AddChild ((yyvsp[(5) - (7)].node)); 
		(yyval.node) -> AddChild (new Node(")",0));
		(yyval.node) -> AddChild (new Node(";",0));;}
    break;

  case 215:
#line 1584 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(4) - (7)]).first_line;
		printf("Line %d: Open parenthesis '(' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 216:
#line 1591 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(6) - (7)]).first_line;
		printf("Line %d: Close parenthesis ')' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 217:
#line 1598 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(5) - (7)]).first_line;
		printf("Line %d: expression expected after '('.\n", mierror);
		yyerrok;
	;}
    break;

  case 218:
#line 1605 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(4) - (6)]).first_line;
		printf("Line %d: Open parenthesis '(' and expression expected after 'while'.\n", mierror);
		yyerrok;
	;}
    break;

  case 219:
#line 1613 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (7)]).first_line;
		printf("Line %d: Statement expected after 'Do'.\n", mierror);
		yyerrok;
	;}
    break;

  case 220:
#line 1620 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (7)]).first_line;
		printf("Line %d: 'while' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 221:
#line 1627 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(7) - (8)]).first_line;
		printf("Line %d: SemiColon ';' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 222:
#line 1634 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (6)]).first_line;
		printf("Line %d: 'while (' expected.\n", mierror);
		yyerrok;
	;}
    break;

  case 223:
#line 1641 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (3)]).first_line;
		printf("Line %d: Error after 'Do', check statement and expressions.\n", mierror);
		yyerrok;
	;}
    break;

  case 224:
#line 1648 "bison.y"
    {
		(yyval.node) = new Node ("ForStmt",9); 
		(yyval.node) -> AddChild (new Node("for",0)); 
		(yyval.node) -> AddChild (new Node("(",0)); 			
		(yyval.node) -> AddChild ((yyvsp[(3) - (9)].node)); 
		(yyval.node) -> AddChild (new Node(";",0)); 
		(yyval.node) -> AddChild ((yyvsp[(5) - (9)].node)); 
		(yyval.node) -> AddChild (new Node(";",0));
		(yyval.node) -> AddChild ((yyvsp[(7) - (9)].node)); 
		(yyval.node) -> AddChild (new Node(")",0));
		(yyval.node) -> AddChild ((yyvsp[(9) - (9)].node));  ;}
    break;

  case 225:
#line 1659 "bison.y"
    {
		(yyval.node) = new Node ("ForStmt",8); 
		(yyval.node) -> AddChild (new Node("for",0)); 
		(yyval.node) -> AddChild (new Node("(",0)); 			
		(yyval.node) -> AddChild ((yyvsp[(3) - (8)].node)); 
		(yyval.node) -> AddChild (new Node(";",0)); 
		(yyval.node) -> AddChild ((yyvsp[(5) - (8)].node)); 
		(yyval.node) -> AddChild (new Node(";",0));
		(yyval.node) -> AddChild (new Node(")",0));
		(yyval.node) -> AddChild ((yyvsp[(8) - (8)].node));   ;}
    break;

  case 226:
#line 1669 "bison.y"
    {
		(yyval.node) = new Node ("ForStmt",8); 
		(yyval.node) -> AddChild (new Node("for",0)); 
		(yyval.node) -> AddChild (new Node("(",0)); 			
		(yyval.node) -> AddChild ((yyvsp[(3) - (8)].node)); 
		(yyval.node) -> AddChild (new Node(";",0)); 
		(yyval.node) -> AddChild (new Node(";",0));
		(yyval.node) -> AddChild ((yyvsp[(6) - (8)].node)); 
		(yyval.node) -> AddChild (new Node(")",0));
		(yyval.node) -> AddChild ((yyvsp[(8) - (8)].node));   ;}
    break;

  case 227:
#line 1680 "bison.y"
    {
		(yyval.node) = new Node ("ForStmt",7); 
		(yyval.node) -> AddChild (new Node("for",0)); 
		(yyval.node) -> AddChild (new Node("(",0)); 			
		(yyval.node) -> AddChild ((yyvsp[(3) - (7)].node)); 
		(yyval.node) -> AddChild (new Node(";",0)); 
		(yyval.node) -> AddChild (new Node(";",0));
		(yyval.node) -> AddChild (new Node(")",0));
		(yyval.node) -> AddChild ((yyvsp[(7) - (7)].node));  ;}
    break;

  case 228:
#line 1690 "bison.y"
    {
		(yyval.node) = new Node ("ForStmt",8); 
		(yyval.node) -> AddChild (new Node("for",0)); 
		(yyval.node) -> AddChild (new Node("(",0)); 			
		(yyval.node) -> AddChild (new Node(";",0)); 
		(yyval.node) -> AddChild ((yyvsp[(4) - (8)].node)); 
		(yyval.node) -> AddChild (new Node(";",0));
		(yyval.node) -> AddChild ((yyvsp[(6) - (8)].node)); 
		(yyval.node) -> AddChild (new Node(")",0));
		(yyval.node) -> AddChild ((yyvsp[(8) - (8)].node));  ;}
    break;

  case 229:
#line 1701 "bison.y"
    {
		(yyval.node) = new Node ("ForStmt",7); 
		(yyval.node) -> AddChild (new Node("for",0)); 
		(yyval.node) -> AddChild (new Node("(",0)); 			
		(yyval.node) -> AddChild (new Node(";",0)); 
		(yyval.node) -> AddChild ((yyvsp[(4) - (7)].node)); 
		(yyval.node) -> AddChild (new Node(";",0));
		(yyval.node) -> AddChild (new Node(")",0));
		(yyval.node) -> AddChild ((yyvsp[(7) - (7)].node));   ;}
    break;

  case 230:
#line 1711 "bison.y"
    {
		(yyval.node) = new Node ("ForStmt",7); 
		(yyval.node) -> AddChild (new Node("for",0)); 
		(yyval.node) -> AddChild (new Node("(",0)); 			
		(yyval.node) -> AddChild (new Node(";",0)); 
		(yyval.node) -> AddChild (new Node(";",0));
		(yyval.node) -> AddChild ((yyvsp[(5) - (7)].node)); 
		(yyval.node) -> AddChild (new Node(")",0));
		(yyval.node) -> AddChild ((yyvsp[(7) - (7)].node));   ;}
    break;

  case 231:
#line 1721 "bison.y"
    {
		(yyval.node) = new Node ("ForStmt",6); 
		(yyval.node) -> AddChild (new Node("for",0)); 
		(yyval.node) -> AddChild (new Node("(",0)); 			
		(yyval.node) -> AddChild (new Node(";",0)); 
		(yyval.node) -> AddChild (new Node(";",0));
		(yyval.node) -> AddChild (new Node(")",0));
		(yyval.node) -> AddChild ((yyvsp[(6) - (6)].node));   ;}
    break;

  case 232:
#line 1730 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(4) - (6)]).first_line;
		(yyval.node) = new Node ("ForStmt",6); 
		(yyval.node) -> AddChild (new Node("for",0)); 
		(yyval.node) -> AddChild (new Node("(",0)); 			
		(yyval.node) -> AddChild (new Node(";",0)); 
		(yyval.node) -> AddChild (new Node("error",0));
		(yyval.node) -> AddChild (new Node(")",0));
		(yyval.node) -> AddChild ((yyvsp[(6) - (6)].node));
		printf("Line %d: Error in for statement, likely ; missing\n", mierror);
		yyerrok;
		   ;}
    break;

  case 233:
#line 1743 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(5) - (7)]).first_line;
		(yyval.node) = new Node ("ForStmt",7); 
		(yyval.node) -> AddChild (new Node("for",0)); 
		(yyval.node) -> AddChild (new Node("(",0)); 			
		(yyval.node) -> AddChild (new Node(";",0)); 
		(yyval.node) -> AddChild (new Node(";",0));
		(yyval.node) -> AddChild (new Node("error", 0)); 
		(yyval.node) -> AddChild (new Node(")",0));
		(yyval.node) -> AddChild ((yyvsp[(7) - (7)].node));  
		printf("Line %d: Error in for statement after the second ;, in update phase\n", mierror);
		 ;}
    break;

  case 234:
#line 1757 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(4) - (7)]).first_line;
		(yyval.node) = new Node ("ForStmt",7); 
		(yyval.node) -> AddChild (new Node("for",0)); 
		(yyval.node) -> AddChild (new Node("(",0)); 			
		(yyval.node) -> AddChild (new Node(";",0)); 
		(yyval.node) -> AddChild (new Node("error", 0)); 
		(yyval.node) -> AddChild (new Node(";",0));
		(yyval.node) -> AddChild (new Node(")",0));
		(yyval.node) -> AddChild ((yyvsp[(7) - (7)].node));   
		printf("Line %d: Error found after first ; in for statement\n", mierror);
		yyerrok;
		 ;}
    break;

  case 235:
#line 1773 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (7)]).first_line;
		(yyval.node) = new Node ("ForStmt",7); 
		(yyval.node) -> AddChild (new Node("for",0)); 
		(yyval.node) -> AddChild (new Node("(",0)); 			
		(yyval.node) -> AddChild (new Node("error", 0)); 
		(yyval.node) -> AddChild (new Node(";",0)); 
		(yyval.node) -> AddChild (new Node(";",0));
		(yyval.node) -> AddChild (new Node(")",0));
		(yyval.node) -> AddChild ((yyvsp[(7) - (7)].node)); 
		printf("Line %d: Error found in for initializer.\n", mierror);
		yyerrok; ;}
    break;

  case 236:
#line 1787 "bison.y"
    {
		(yyval.node) = new Node ("ForStmtNoShortIf",9); 
		(yyval.node) -> AddChild(new Node("for", 0));
		(yyval.node) -> AddChild(new Node("(", 0));
		(yyval.node) -> AddChild((yyvsp[(3) - (9)].node));
		(yyval.node) -> AddChild(new Node(";", 0));
		(yyval.node) -> AddChild((yyvsp[(5) - (9)].node));
		(yyval.node) -> AddChild(new Node(";", 0));
		(yyval.node) -> AddChild((yyvsp[(7) - (9)].node));
		(yyval.node) -> AddChild(new Node(")", 0));
		(yyval.node) -> AddChild((yyvsp[(9) - (9)].node));	 ;}
    break;

  case 237:
#line 1798 "bison.y"
    {
		(yyval.node) = new Node ("ForStmtNoShortIf",8); 
		(yyval.node) -> AddChild(new Node("for", 0)); 
		(yyval.node) -> AddChild(new Node("(", 0));
		(yyval.node) -> AddChild((yyvsp[(3) - (8)].node));
		(yyval.node) -> AddChild(new Node(";", 0));
		(yyval.node) -> AddChild((yyvsp[(5) - (8)].node));
		(yyval.node) -> AddChild(new Node(";", 0));
		(yyval.node) -> AddChild(new Node(")", 0));
		(yyval.node) -> AddChild((yyvsp[(8) - (8)].node));	;}
    break;

  case 238:
#line 1808 "bison.y"
    {
		(yyval.node) = new Node ("ForStmtNoShortIf",8); 
		(yyval.node) -> AddChild(new Node("for", 0)); 
		(yyval.node) -> AddChild(new Node("(", 0));
		(yyval.node) -> AddChild((yyvsp[(3) - (8)].node));
		(yyval.node) -> AddChild(new Node(";", 0));
		(yyval.node) -> AddChild(new Node(";", 0));
		(yyval.node) -> AddChild((yyvsp[(6) - (8)].node));
		(yyval.node) -> AddChild(new Node(")", 0));
		(yyval.node) -> AddChild((yyvsp[(8) - (8)].node));	;}
    break;

  case 239:
#line 1818 "bison.y"
    {
		(yyval.node) = new Node ("ForStmtNoShortIf",7); 
		(yyval.node) -> AddChild(new Node("for", 0)); 
		(yyval.node) -> AddChild(new Node("(", 0)); 
		(yyval.node) -> AddChild((yyvsp[(3) - (7)].node));
		(yyval.node) -> AddChild(new Node(";", 0));
		(yyval.node) -> AddChild(new Node(";", 0));
		(yyval.node) -> AddChild(new Node(")", 0));
		(yyval.node) -> AddChild((yyvsp[(7) - (7)].node));	;}
    break;

  case 240:
#line 1827 "bison.y"
    {
		(yyval.node) = new Node ("ForStmtNoShortIf",8); 
		(yyval.node) -> AddChild(new Node("for", 0)); 
		(yyval.node) -> AddChild(new Node("(", 0)); 
		(yyval.node) -> AddChild(new Node(";", 0));
		(yyval.node) -> AddChild((yyvsp[(4) - (8)].node));
		(yyval.node) -> AddChild(new Node(";", 0));
		(yyval.node) -> AddChild((yyvsp[(6) - (8)].node));
		(yyval.node) -> AddChild(new Node(")", 0));
		(yyval.node) -> AddChild((yyvsp[(8) - (8)].node));	 ;}
    break;

  case 241:
#line 1837 "bison.y"
    {
		(yyval.node) = new Node ("ForStmtNoShortIf",7);  
		(yyval.node) -> AddChild(new Node("for", 0)); 
		(yyval.node) -> AddChild(new Node("(", 0)); 
		(yyval.node) -> AddChild(new Node(";", 0));
		(yyval.node) -> AddChild((yyvsp[(4) - (7)].node));
		(yyval.node) -> AddChild(new Node(";", 0));
		(yyval.node) -> AddChild(new Node(")", 0));
		(yyval.node) -> AddChild((yyvsp[(7) - (7)].node));	;}
    break;

  case 242:
#line 1846 "bison.y"
    {
		(yyval.node) = new Node ("ForStmtNoShortIf",7); 
		(yyval.node) -> AddChild(new Node("for", 0)); 
		(yyval.node) -> AddChild(new Node("(", 0)); 
		(yyval.node) -> AddChild(new Node(";", 0));
		(yyval.node) -> AddChild(new Node(";", 0));
		(yyval.node) -> AddChild((yyvsp[(5) - (7)].node));
		(yyval.node) -> AddChild(new Node(")", 0));
		(yyval.node) -> AddChild((yyvsp[(7) - (7)].node));	;}
    break;

  case 243:
#line 1855 "bison.y"
    {
		(yyval.node) = new Node ("ForStmtNoShortIf",6); 
		(yyval.node) -> AddChild(new Node("for", 0)); 
		(yyval.node) -> AddChild(new Node("(", 0)); 
		(yyval.node) -> AddChild(new Node(";", 0));
		(yyval.node) -> AddChild(new Node(";", 0));
		(yyval.node) -> AddChild(new Node(")", 0));
		(yyval.node) -> AddChild((yyvsp[(6) - (6)].node)); ;}
    break;

  case 244:
#line 1864 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(4) - (6)]).first_line;
		(yyval.node) = new Node ("ForStmt",6); 
		(yyval.node) -> AddChild (new Node("for",0)); 
		(yyval.node) -> AddChild (new Node("(",0)); 			
		(yyval.node) -> AddChild (new Node(";",0)); 
		(yyval.node) -> AddChild (new Node("error",0));
		(yyval.node) -> AddChild (new Node(")",0));
		(yyval.node) -> AddChild ((yyvsp[(6) - (6)].node));
		printf("Line %d: Error in for statement, likely ; missing\n", mierror);
		yyerrok;
		   ;}
    break;

  case 245:
#line 1877 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(5) - (7)]).first_line;
		(yyval.node) = new Node ("ForStmt",7); 
		(yyval.node) -> AddChild (new Node("for",0)); 
		(yyval.node) -> AddChild (new Node("(",0)); 			
		(yyval.node) -> AddChild (new Node(";",0)); 
		(yyval.node) -> AddChild (new Node(";",0));
		(yyval.node) -> AddChild (new Node("error", 0)); 
		(yyval.node) -> AddChild (new Node(")",0));
		(yyval.node) -> AddChild ((yyvsp[(7) - (7)].node));  
		printf("Line %d: Error in for statement after the second ;, in update phase\n", mierror);
		 ;}
    break;

  case 246:
#line 1891 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(4) - (7)]).first_line;
		(yyval.node) = new Node ("ForStmt",7); 
		(yyval.node) -> AddChild (new Node("for",0)); 
		(yyval.node) -> AddChild (new Node("(",0)); 			
		(yyval.node) -> AddChild (new Node(";",0)); 
		(yyval.node) -> AddChild (new Node("error", 0)); 
		(yyval.node) -> AddChild (new Node(";",0));
		(yyval.node) -> AddChild (new Node(")",0));
		(yyval.node) -> AddChild ((yyvsp[(7) - (7)].node));   
		printf("Line %d: Error found after first ; in for statement\n", mierror);
		yyerrok;
		 ;}
    break;

  case 247:
#line 1907 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (7)]).first_line;
		(yyval.node) = new Node ("ForStmt",7); 
		(yyval.node) -> AddChild (new Node("for",0)); 
		(yyval.node) -> AddChild (new Node("(",0)); 			
		(yyval.node) -> AddChild (new Node("error", 0)); 
		(yyval.node) -> AddChild (new Node(";",0)); 
		(yyval.node) -> AddChild (new Node(";",0));
		(yyval.node) -> AddChild (new Node(")",0));
		(yyval.node) -> AddChild ((yyvsp[(7) - (7)].node)); 
		printf("Line %d: Error found in for initializer.\n", mierror);
		yyerrok; ;}
    break;

  case 248:
#line 1921 "bison.y"
    {
		(yyval.node) = new Node ("ForInit",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 249:
#line 1924 "bison.y"
    {
		(yyval.node) = new Node ("ForInit",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 250:
#line 1928 "bison.y"
    {
		(yyval.node) = new Node ("ForUpdate",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 251:
#line 1932 "bison.y"
    {
		(yyval.node) = new Node ("StmtExprList",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 252:
#line 1935 "bison.y"
    {
		(yyval.node) = new Node ("StmtExprList",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node));
		(yyval.node) -> AddChild(new Node(",", 0));
		(yyval.node) -> AddChild((yyvsp[(3) - (3)].node));
		 ;}
    break;

  case 253:
#line 1942 "bison.y"
    {
		int line  = (yylsp[(1) - (2)]).first_line;
		(yyval.node) = new Node ("BreakStmt",2); 
		(yyval.node) -> AddChild(new Node("break", 0), line);
		(yyval.node) -> AddChild(new Node(";", 0)); ;}
    break;

  case 254:
#line 1948 "bison.y"
    {
		
		mierror = (yylsp[(2) - (3)]).first_line;
		(yyval.node) = new Node ("BreakStmt",2); 
		(yyval.node) -> AddChild(new Node("break", 0));
		(yyval.node) -> AddChild(new Node("error", 0)); 
		(yyval.node) -> AddChild(new Node("}", 0)); 
		printf("Line %d: ; missing after break keyword.\n", mierror);
		yyerrok;
		;}
    break;

  case 255:
#line 1960 "bison.y"
    {
		(yyval.node) = new Node ("ContinueStmt",2); 
		(yyval.node) -> AddChild(new Node("continue", 0), (yylsp[(1) - (2)]).first_line);
		(yyval.node) -> AddChild(new Node(";", 0)); ;}
    break;

  case 256:
#line 1965 "bison.y"
    {
		(yyval.node) = new Node ("ReturnStmt",3); 
	
		(yyval.node) -> AddChild(new Node("return", 0));
		(yyval.node)->children[0]->line = (yylsp[(1) - (3)]).first_line;
		(yyval.node) -> AddChild ((yyvsp[(2) - (3)].node)); 
		(yyval.node) -> AddChild(new Node(";", 0)); ;}
    break;

  case 257:
#line 1972 "bison.y"
    {
		(yyval.node) = new Node ("ReturnStmt",2);
	
		(yyval.node) -> AddChild(new Node("return", 0));
		(yyval.node)->children[0]->line = (yylsp[(1) - (2)]).first_line;
		(yyval.node) -> AddChild(new Node(";", 0)); ;}
    break;

  case 258:
#line 1979 "bison.y"
    {
		(yyval.node) = new Node ("Primary",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 259:
#line 1982 "bison.y"
    {
		(yyval.node) = new Node ("Primary",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 260:
#line 1987 "bison.y"
    {
		(yyval.node) = new Node ("PrimaryNoNewArray",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 261:
#line 1990 "bison.y"
    {
		(yyval.node) = new Node ("PrimaryNoNewArray",1); 
		(yyval.node) -> AddChild(new Node("this", 0)); ;}
    break;

  case 262:
#line 1993 "bison.y"
    {
		(yyval.node) = new Node ("PrimaryNoNewArray",3); 
		(yyval.node) -> AddChild(new Node("(", 0));
		(yyval.node) -> AddChild((yyvsp[(2) - (3)].node), (yylsp[(2) - (3)]).first_line);
		(yyval.node) -> AddChild(new Node(")", 0)); ;}
    break;

  case 263:
#line 1998 "bison.y"
    {
		(yyval.node) = new Node ("PrimaryNoNewArray",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 264:
#line 2001 "bison.y"
    {
		(yyval.node) = new Node ("PrimaryNoNewArray",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 265:
#line 2004 "bison.y"
    {
		(yyval.node) = new Node ("PrimaryNoNewArray",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 266:
#line 2007 "bison.y"
    {
		(yyval.node) = new Node ("PrimaryNoNewArray",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 267:
#line 2011 "bison.y"
    {
		(yyval.node) = new Node ("ClassInstanceCreationExpr",5); 
		(yyval.node) -> AddChild(new Node("new", 0));
		(yyval.node) -> AddChild((yyvsp[(2) - (5)].node));
		(yyval.node) -> AddChild(new Node("(", 0));
		(yyval.node) -> AddChild((yyvsp[(4) - (5)].node));
		(yyval.node) -> AddChild(new Node(")", 0));;}
    break;

  case 268:
#line 2018 "bison.y"
    {
		(yyval.node) = new Node ("ClassInstanceCreationExpr",4); 
		(yyval.node) -> AddChild(new Node("new", 0));
		(yyval.node) -> AddChild((yyvsp[(2) - (4)].node));
		(yyval.node) -> AddChild(new Node("(", 0));
		(yyval.node) -> AddChild(new Node(")", 0));;}
    break;

  case 269:
#line 2034 "bison.y"
    {
		(yyval.node) = new Node ("ArgumentList",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 270:
#line 2037 "bison.y"
    {
		(yyval.node) = new Node ("ArgumentList",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node));
		(yyval.node) -> AddChild(new Node(",", 0));
		(yyval.node) -> AddChild((yyvsp[(3) - (3)].node));	;}
    break;

  case 271:
#line 2042 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(1) - (3)]).first_line;
		(yyval.node) = new Node("ArgumentList", 3);
		(yyval.node) -> AddChild(new Node("error", 0));
		(yyval.node) -> AddChild(new Node(",", 0));
		(yyval.node) -> AddChild((yyvsp[(3) - (3)].node));
		printf("Line %d: Error in argument list before ','\n", mierror);
		yyerrok;
		;}
    break;

  case 272:
#line 2052 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (3)]).first_line;
		(yyval.node) = new Node("ArgumentList", 3);
		(yyval.node) -> AddChild((yyvsp[(1) - (3)].node));
		(yyval.node) -> AddChild(new Node("error", 0));
		(yyval.node) -> AddChild((yyvsp[(3) - (3)].node));
		printf("Line %d: Error in argument list, expecting ',' or valid parameter\n", mierror);
		yyerrok;
	;}
    break;

  case 273:
#line 2063 "bison.y"
    {
		(yyval.node) = new Node ("ArrayCreationExpr",4); 
		(yyval.node) -> AddChild (new Node("new", 0));
		(yyval.node) -> AddChild ((yyvsp[(2) - (4)].node));
		(yyval.node) -> AddChild ((yyvsp[(3) - (4)].node)); 
		(yyval.node) -> AddChild ((yyvsp[(4) - (4)].node));;}
    break;

  case 274:
#line 2069 "bison.y"
    {
		(yyval.node) = new Node ("ArrayCreationExpr",3); 
		(yyval.node) -> AddChild(new Node("new", 0));
		(yyval.node) -> AddChild ((yyvsp[(2) - (3)].node));
		(yyval.node) -> AddChild ((yyvsp[(3) - (3)].node)); ;}
    break;

  case 275:
#line 2074 "bison.y"
    {
		(yyval.node) = new Node ("ArrayCreationExpr",4); 
		(yyval.node) -> AddChild(new Node("new", 0));
		(yyval.node) -> AddChild ((yyvsp[(2) - (4)].node));
		(yyval.node) -> AddChild ((yyvsp[(3) - (4)].node));
		(yyval.node) -> AddChild ((yyvsp[(4) - (4)].node)); ;}
    break;

  case 276:
#line 2080 "bison.y"
    {
		(yyval.node) = new Node ("ArrayCreationExpr",3); 
		(yyval.node) -> AddChild(new Node("new", 0));
		(yyval.node) -> AddChild ((yyvsp[(2) - (3)].node));
		(yyval.node) -> AddChild ((yyvsp[(3) - (3)].node)); ;}
    break;

  case 277:
#line 2087 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (3)]).first_line;
		printf("Line %d: Error with dimensions\n", mierror);
		yyerrok;
	;}
    break;

  case 278:
#line 2094 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (3)]).first_line;
		printf("Line %d: Error with dimensions in array creation\n", mierror);
		yyerrok;
	;}
    break;

  case 279:
#line 2101 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (3)]).first_line;
		printf("Line %d: Error in array declaration: Expecting primitive type or ClassType.\n", mierror);
		yyerrok;
	;}
    break;

  case 280:
#line 2108 "bison.y"
    {
		(yyval.node) = new Node ("DimExprs",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 281:
#line 2111 "bison.y"
    {
		(yyval.node) = new Node ("DimExprs",2); 
		(yyval.node) -> AddChild((yyvsp[(1) - (2)].node));
		(yyval.node) -> AddChild((yyvsp[(2) - (2)].node)); ;}
    break;

  case 282:
#line 2116 "bison.y"
    {
		(yyval.node) = new Node ("DimExpr",3); 
		(yyval.node) -> AddChild(new Node("[", 0));
		(yyval.node) -> AddChild ((yyvsp[(2) - (3)].node));
		(yyval.node) -> AddChild(new Node("]", 0)); ;}
    break;

  case 283:
#line 2122 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(2) - (3)]).first_line;
		(yyval.node) = new Node("DimExpr", 3);
		(yyval.node) -> AddChild(new Node("[", 0));
		(yyval.node) -> AddChild(new Node("error", 0));
		(yyval.node) -> AddChild(new Node("]", 0));
		printf("Line %d: Error in expression within []\n", mierror);
		yyerrok;	
	;}
    break;

  case 284:
#line 2133 "bison.y"
    {
		(yyval.node) = new Node ("Dims",2); 
		(yyval.node) -> AddChild(new Node("[", 0));
		(yyval.node) -> AddChild(new Node("]", 0)); ;}
    break;

  case 285:
#line 2137 "bison.y"
    {
		(yyval.node) = new Node ("Dims",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node));
		(yyval.node) -> AddChild(new Node("[", 0));
		(yyval.node) -> AddChild(new Node("]", 0)); ;}
    break;

  case 286:
#line 2143 "bison.y"
    {
		(yyval.node) = new Node ("FieldAccess",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node));
		(yyval.node) -> AddChild(new Node(".", 0)); 
		(yyval.node)->AddChild(new Node("Identifier", new Node((yyvsp[(3) - (3)].str), 0), (yylsp[(3) - (3)]).first_line));;}
    break;

  case 287:
#line 2148 "bison.y"
    {
		(yyval.node) = new Node ("FieldAccess",3); 
		(yyval.node) -> AddChild(new Node("super", 0));
		(yyval.node) -> AddChild(new Node(".", 0));
		(yyval.node)->AddChild(new Node("Identifier", new Node((yyvsp[(3) - (3)].str), 0), (yylsp[(3) - (3)]).first_line)); ;}
    break;

  case 288:
#line 2155 "bison.y"
    {
		(yyval.node) = new Node ("MethodInvocation",4); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (4)].node));
		(yyval.node) -> AddChild(new Node("(", 0));
		(yyval.node) -> AddChild((yyvsp[(3) - (4)].node)); 
		(yyval.node) -> AddChild(new Node(")", 0));;}
    break;

  case 289:
#line 2161 "bison.y"
    {
		(yyval.node) = new Node ("MethodInvocation",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node));
		(yyval.node) -> AddChild(new Node("(", 0));
		(yyval.node) -> AddChild(new Node(")", 0)); ;}
    break;

  case 290:
#line 2166 "bison.y"
    {
		(yyval.node) = new Node ("MethodInvocation",6); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (6)].node));
		(yyval.node) -> AddChild(new Node(".", 0));
		(yyval.node)->AddChild(new Node("Identifier", new Node((yyvsp[(3) - (6)].str), 0), (yylsp[(3) - (6)]).first_line));
		(yyval.node) -> AddChild(new Node("(", 0));
		(yyval.node) -> AddChild((yyvsp[(5) - (6)].node));
		(yyval.node) -> AddChild(new Node(")", 0)); ;}
    break;

  case 291:
#line 2174 "bison.y"
    {
		(yyval.node) = new Node ("MethodInvocation",5); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (5)].node));
		(yyval.node) -> AddChild(new Node(".", 0));
		(yyval.node)->AddChild(new Node("Identifier", new Node((yyvsp[(3) - (5)].str), 0), (yylsp[(3) - (5)]).first_line));
		(yyval.node) -> AddChild(new Node("(", 0));
		(yyval.node) -> AddChild(new Node(")", 0)); ;}
    break;

  case 292:
#line 2181 "bison.y"
    {
		(yyval.node) = new Node ("MethodInvocation",6); 
		(yyval.node) -> AddChild(new Node("super", 0));
		(yyval.node) -> AddChild(new Node(".", 0));
		(yyval.node)->AddChild(new Node("Identifier", new Node((yyvsp[(3) - (6)].str), 0), (yylsp[(3) - (6)]).first_line));
		(yyval.node) -> AddChild(new Node("(", 0));
		(yyval.node) -> AddChild((yyvsp[(5) - (6)].node));
		(yyval.node) -> AddChild(new Node(")", 0)); ;}
    break;

  case 293:
#line 2189 "bison.y"
    {
		(yyval.node) = new Node ("MethodInvocation",5); 
		(yyval.node) -> AddChild(new Node("super", 0));
		(yyval.node) -> AddChild(new Node(".", 0));
		(yyval.node)->AddChild(new Node("Identifier", new Node((yyvsp[(3) - (5)].str), 0), (yylsp[(3) - (5)]).first_line));
		(yyval.node) -> AddChild(new Node("(", 0));
		(yyval.node) -> AddChild(new Node(")", 0)); ;}
    break;

  case 294:
#line 2197 "bison.y"
    {
		codigo_sin_errores = false;
		mierror = (yylsp[(3) - (4)]).first_line;
		(yyval.node) = new Node("MethodInvocation", 4);
		(yyval.node) -> AddChild((yyvsp[(1) - (4)].node));
		(yyval.node) -> AddChild(new Node((yyvsp[(2) - (4)].str), 0));
		(yyval.node) -> AddChild(new Node("error", 0));
		(yyval.node) -> AddChild(new Node((yyvsp[(4) - (4)].str), 0));
		printf("Line %d: Error in method call, expected (\n", mierror);
		yyerrok;
	;}
    break;

  case 295:
#line 2209 "bison.y"
    {
		(yyval.node) = new Node ("ArrayAccess",4); 
		(yyval.node) -> AddChild((yyvsp[(1) - (4)].node));
		(yyval.node) -> AddChild(new Node("[", 0));
		(yyval.node) -> AddChild ((yyvsp[(3) - (4)].node));
		(yyval.node) -> AddChild(new Node("]", 0)); ;}
    break;

  case 296:
#line 2215 "bison.y"
    {
		(yyval.node) = new Node ("ArrayAccess",4); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (4)].node));
		(yyval.node) -> AddChild(new Node("[", 0));
		(yyval.node) -> AddChild((yyvsp[(3) - (4)].node));
		(yyval.node) -> AddChild(new Node("]", 0)); ;}
    break;

  case 297:
#line 2222 "bison.y"
    {
		(yyval.node) = new Node ("PostfixExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 298:
#line 2225 "bison.y"
    {
		(yyval.node) = new Node ("PostfixExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 299:
#line 2228 "bison.y"
    {
		(yyval.node) = new Node ("PostfixExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 300:
#line 2231 "bison.y"
    {
		(yyval.node) = new Node ("PostfixExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 301:
#line 2235 "bison.y"
    {
		(yyval.node) = new Node ("PostIncrementExpr",2); 
		(yyval.node)->line = (yylsp[(1) - (2)]).first_line;
		(yyval.node) -> AddChild ((yyvsp[(1) - (2)].node)); 
		(yyval.node) -> AddChild(new Node("++", 0));;}
    break;

  case 302:
#line 2241 "bison.y"
    {
		(yyval.node) = new Node ("PostDecrementExpr",2); 
		(yyval.node)->line = (yylsp[(1) - (2)]).first_line;
		(yyval.node) -> AddChild ((yyvsp[(1) - (2)].node));
		(yyval.node) -> AddChild(new Node("--", 0)); ;}
    break;

  case 303:
#line 2247 "bison.y"
    {
		(yyval.node) = new Node ("UnaryExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 304:
#line 2250 "bison.y"
    {
		(yyval.node) = new Node ("UnaryExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 305:
#line 2253 "bison.y"
    {
		(yyval.node) = new Node ("UnaryExpr",2); 
		(yyval.node)->AddChild(new Node("AddOp", new Node((yyvsp[(1) - (2)].str), 0), (yylsp[(1) - (2)]).first_line));
		(yyval.node) -> AddChild ((yyvsp[(2) - (2)].node)); ;}
    break;

  case 306:
#line 2257 "bison.y"
    {
		(yyval.node) = new Node ("UnaryExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 307:
#line 2261 "bison.y"
    {
		(yyval.node) = new Node ("PreIncrementExpr",2); 
		(yyval.node)->line = (yylsp[(2) - (2)]).first_line;
		(yyval.node) -> AddChild(new Node("++", 0));
		(yyval.node) -> AddChild ((yyvsp[(2) - (2)].node)); ;}
    break;

  case 308:
#line 2267 "bison.y"
    {
		(yyval.node)->line = (yylsp[(2) - (2)]).first_line;
		(yyval.node) = new Node ("PreDecrementExpr",2); 
		(yyval.node) -> AddChild(new Node("--", 0));
		(yyval.node) -> AddChild ((yyvsp[(2) - (2)].node)); ;}
    break;

  case 309:
#line 2273 "bison.y"
    {
		(yyval.node) = new Node ("UnaryExprNotPlusMinus",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 310:
#line 2276 "bison.y"
    {
		(yyval.node) = new Node ("UnaryExprNotPlusMinus",2); 
		(yyval.node) -> AddChild(new Node((yyvsp[(1) - (2)].str), 0));
		(yyval.node) -> AddChild ((yyvsp[(2) - (2)].node)); ;}
    break;

  case 311:
#line 2280 "bison.y"
    {
		(yyval.node) = new Node ("UnaryExprNotPlusMinus",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 312:
#line 2284 "bison.y"
    {
		(yyval.node) = new Node ("CastExpr",5); 
		(yyval.node) -> AddChild(new Node("(", 0));
		(yyval.node) -> AddChild ((yyvsp[(2) - (5)].node));
		(yyval.node) -> AddChild((yyvsp[(3) - (5)].node));
		(yyval.node) -> AddChild(new Node(")", 0));
		(yyval.node) -> AddChild((yyvsp[(5) - (5)].node)); ;}
    break;

  case 313:
#line 2291 "bison.y"
    {
		(yyval.node) = new Node ("CastExpr",4); 
		(yyval.node) -> AddChild(new Node("(", 0));
		(yyval.node) -> AddChild ((yyvsp[(2) - (4)].node)); 
		(yyval.node) -> AddChild(new Node(")", 0));
		(yyval.node) -> AddChild((yyvsp[(4) - (4)].node));;}
    break;

  case 314:
#line 2297 "bison.y"
    {
		(yyval.node) = new Node ("CastExpr",4); 
		(yyval.node) -> AddChild(new Node("(", 0));
		(yyval.node) -> AddChild ((yyvsp[(2) - (4)].node)); 
		(yyval.node) -> AddChild(new Node(")", 0));
		(yyval.node) -> AddChild((yyvsp[(4) - (4)].node));;}
    break;

  case 315:
#line 2303 "bison.y"
    {
		(yyval.node) = new Node ("CastExpr",5); 
		(yyval.node) -> AddChild(new Node("(", 0));
		(yyval.node) -> AddChild ((yyvsp[(2) - (5)].node));
		(yyval.node) -> AddChild((yyvsp[(3) - (5)].node));
		(yyval.node) -> AddChild(new Node(")", 0));
		(yyval.node) -> AddChild((yyvsp[(5) - (5)].node)); ;}
    break;

  case 316:
#line 2311 "bison.y"
    {
	 	mierror = (yylsp[(4) - (5)]).first_line;
	 	printf("Line %d: Missing )\n", mierror);
	 	yyerrok;
	 ;}
    break;

  case 317:
#line 2317 "bison.y"
    {
	 	mierror = (yylsp[(3) - (4)]).first_line;
	 	printf("Line %d: Missing )\n", mierror);
	 	yyerrok;	
	 ;}
    break;

  case 318:
#line 2323 "bison.y"
    {
		(yyval.node) = new Node ("MultiplicativeExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 319:
#line 2326 "bison.y"
    {
		(yyval.node) = new Node ("MultiplicativeExpr",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node));
		(yyval.node)->AddChild(new Node("MultOp", new Node((yyvsp[(2) - (3)].str), 0), (yylsp[(2) - (3)]).first_line));
		(yyval.node) -> AddChild((yyvsp[(3) - (3)].node)); ;}
    break;

  case 320:
#line 2332 "bison.y"
    {
		(yyval.node) = new Node ("AdditiveExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 321:
#line 2335 "bison.y"
    {
		(yyval.node) = new Node ("AdditiveExpr",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node));
		(yyval.node)->AddChild(new Node("AddOp", new Node((yyvsp[(2) - (3)].str), 0), (yylsp[(2) - (3)]).first_line));
		(yyval.node) -> AddChild((yyvsp[(3) - (3)].node));	;}
    break;

  case 322:
#line 2341 "bison.y"
    {
		(yyval.node) = new Node ("RelationalExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 323:
#line 2344 "bison.y"
    {
		(yyval.node) = new Node ("RelationalExpr",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node));
		(yyval.node)->AddChild(new Node("Relacion", new Node((yyvsp[(2) - (3)].str), 0), (yylsp[(2) - (3)]).first_line));
		(yyval.node) -> AddChild((yyvsp[(3) - (3)].node)); ;}
    break;

  case 324:
#line 2350 "bison.y"
    {
		(yyval.node) = new Node ("EqualityExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 325:
#line 2353 "bison.y"
    {
		(yyval.node) = new Node ("EqualityExpr",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node));
		(yyval.node)->AddChild(new Node("Igualdad", new Node((yyvsp[(2) - (3)].str), 0), (yylsp[(2) - (3)]).first_line));
		(yyval.node) -> AddChild((yyvsp[(3) - (3)].node));  ;}
    break;

  case 326:
#line 2360 "bison.y"
    {
		(yyval.node) = new Node ("AndExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 327:
#line 2363 "bison.y"
    {
		(yyval.node) = new Node ("AndExpr",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node));
		(yyval.node) -> AddChild(new Node("&", 0));
		(yyval.node) -> AddChild((yyvsp[(3) - (3)].node)); ;}
    break;

  case 328:
#line 2369 "bison.y"
    {
		(yyval.node) = new Node ("ExclusiveOrExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 329:
#line 2372 "bison.y"
    {
		(yyval.node) = new Node ("ExclusiveOrExpr",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node));
		(yyval.node) -> AddChild(new Node("^", 0));
		(yyval.node) -> AddChild((yyvsp[(3) - (3)].node)); ;}
    break;

  case 330:
#line 2378 "bison.y"
    {
		(yyval.node) = new Node ("InclusiveOrExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 331:
#line 2381 "bison.y"
    {
		(yyval.node) = new Node ("InclusiveOrExpr",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node));
		(yyval.node) -> AddChild(new Node("|", 0));
		(yyval.node) -> AddChild((yyvsp[(3) - (3)].node)); ;}
    break;

  case 332:
#line 2387 "bison.y"
    {
		(yyval.node) = new Node ("ConditionalAndExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 333:
#line 2390 "bison.y"
    {
		(yyval.node) = new Node ("ConditionalAndExpr",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node));
		(yyval.node) -> AddChild(new Node("&&", 0));
		(yyval.node) -> AddChild((yyvsp[(3) - (3)].node)); ;}
    break;

  case 334:
#line 2396 "bison.y"
    {
		(yyval.node) = new Node ("ConditionalOrExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 335:
#line 2399 "bison.y"
    {
		(yyval.node) = new Node ("ConditionalOrExpr",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node));
		(yyval.node) -> AddChild(new Node("||", 0));
		(yyval.node) -> AddChild((yyvsp[(3) - (3)].node)); ;}
    break;

  case 336:
#line 2405 "bison.y"
    {
		(yyval.node) = new Node ("ConditionalExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 337:
#line 2409 "bison.y"
    {
		(yyval.node) = new Node ("AssignmentExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 338:
#line 2412 "bison.y"
    {
		(yyval.node) = new Node ("AssignmentExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 339:
#line 2416 "bison.y"
    {
		(yyval.node) = new Node ("Assignment",3); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (3)].node));
		(yyval.node) -> AddChild ((yyvsp[(2) - (3)].node));
		(yyval.node) -> AddChild ((yyvsp[(3) - (3)].node)); ;}
    break;

  case 340:
#line 2422 "bison.y"
    {
		(yyval.node) = new Node ("LeftHandSide",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 341:
#line 2425 "bison.y"
    {
		(yyval.node) = new Node ("LeftHandSide",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 342:
#line 2428 "bison.y"
    {
		(yyval.node) = new Node ("LeftHandSide",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 343:
#line 2432 "bison.y"
    {
		(yyval.node) = new Node ("AssignmentOperator",1); 
		(yyval.node) -> AddChild (new Node("=", 0)); ;}
    break;

  case 344:
#line 2435 "bison.y"
    {
		(yyval.node) = new Node ("AssignmentOperator",1); 
		(yyval.node)->AddChild(new Node((yyvsp[(1) - (1)].str), 0), (yylsp[(1) - (1)]).first_line); ;}
    break;

  case 345:
#line 2439 "bison.y"
    {
		(yyval.node) = new Node ("Expr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;

  case 346:
#line 2443 "bison.y"
    {
		(yyval.node) = new Node ("ConstantExpr",1); 
		(yyval.node) -> AddChild ((yyvsp[(1) - (1)].node)); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 6219 "bison.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 2447 "bison.y"


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


