/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "minic.y"

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


#line 204 "minic.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_MINIC_TAB_H_INCLUDED
# define YY_YY_MINIC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    teof = 258,
    tnull = 259,
    tnot = 260,
    tnotequ = 261,
    tmod = 262,
    tmodAssign = 263,
    tand = 264,
    tlparen = 265,
    trparen = 266,
    tmul = 267,
    tmulAssign = 268,
    tplus = 269,
    tinc = 270,
    taddAssign = 271,
    tcomma = 272,
    tminus = 273,
    tdec = 274,
    tsubAssign = 275,
    tdiv = 276,
    tdivAssign = 277,
    tsemicolon = 278,
    tless = 279,
    tlesse = 280,
    tassign = 281,
    tequal = 282,
    tgreat = 283,
    tgreate = 284,
    tlbracket = 285,
    trbracket = 286,
    tconst = 287,
    telse = 288,
    tif = 289,
    tint = 290,
    treturn = 291,
    tvoid = 292,
    twhile = 293,
    tlbrace = 294,
    tor = 295,
    trbrace = 296,
    tident = 297,
    tnumber = 298,
    IFX = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 134 "minic.y"

	struct nodeType *node;
	int value;
	char *string;

#line 307 "minic.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MINIC_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   141

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

#define YYUNDEFTOK  2
#define YYMAXUTOK   299


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   152,   152,   153,   154,   155,   157,   158,   161,   164,
     166,   167,   168,   169,   170,   172,   174,   176,   178,   180,
     181,   182,   183,   184,   188,   189,   191,   192,   193,   194,
     196,   197,   198,   200,   202,   206,   208,   209,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   221,   222,   223,
     224,   225,   226,   227,   229,   230,   231,   233,   235,   237,
     239,   241,   243,   244,   246,   247,   249,   250,   252,   254,
     255,   257,   259,   261,   263,   264,   266,   268,   269,   271,
     273,   275,   276,   277,   278,   279,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "teof", "tnull", "tnot", "tnotequ",
  "tmod", "tmodAssign", "tand", "tlparen", "trparen", "tmul", "tmulAssign",
  "tplus", "tinc", "taddAssign", "tcomma", "tminus", "tdec", "tsubAssign",
  "tdiv", "tdivAssign", "tsemicolon", "tless", "tlesse", "tassign",
  "tequal", "tgreat", "tgreate", "tlbracket", "trbracket", "tconst",
  "telse", "tif", "tint", "treturn", "tvoid", "twhile", "tlbrace", "tor",
  "trbrace", "tident", "tnumber", "IFX", "$accept", "mini_c",
  "translation_unit", "external_dcl", "function_def", "function_header",
  "dcl_spec", "dcl_specifiers", "dcl_specifier", "type_qualifier",
  "type_specifier", "function_name", "formal_param", "opt_formal_param",
  "formal_param_list", "param_dcl", "compound_st", "opt_dcl_list",
  "declaration_list", "declaration", "init_dcl_list", "init_declarator",
  "declarator", "opt_number", "opt_stat_list", "statement_list",
  "statement", "expression_st", "opt_expression", "if_st", "while_st",
  "return_st", "expression", "assignment_exp", "logical_or_exp",
  "logical_and_exp", "equality_exp", "relational_exp", "additive_exp",
  "multiplicative_exp", "unary_exp", "postfix_exp", "opt_actual_param",
  "actual_param", "actual_param_list", "primary_exp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

#define YYPACT_NINF (-81)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-50)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      13,   -81,   -81,   -81,    16,    13,   -81,   -81,   -28,   -29,
      13,   -81,   -81,   -81,   -81,   -81,   -81,    13,   -81,     0,
      33,    11,   -81,    44,   -81,    36,    66,    13,   -81,    32,
      13,   -81,    36,   -81,    37,    58,    64,    64,    64,    64,
      64,    82,    64,    83,   -81,   -81,   -81,    53,    66,   -81,
     -81,    75,   -81,   -81,   -81,   -81,   -81,    61,    90,     2,
      62,    59,    19,   102,    17,   -81,   -81,   -81,    85,    36,
     106,   103,   -81,   -81,   -81,   -81,   108,   -81,   -81,   -81,
      64,    98,    64,   -81,   -81,   -81,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,   -81,   -81,    64,   -81,
     -81,   -81,    13,   -81,   112,   -81,   114,    90,   -81,     2,
      62,    62,    59,    59,    59,    59,    19,    19,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   115,   -81,
     110,    99,   -81,    -1,    -1,   -81,    64,   -81,    96,   -81,
     -81,    -1,   -81
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    14,    15,    16,     0,     2,     3,     5,     0,     0,
       9,    10,    12,    13,     6,     1,     4,    26,     7,    34,
       0,     0,    30,    32,    11,     0,    39,    25,    27,    37,
      20,     8,     0,    29,     0,    34,     0,     0,     0,     0,
       0,     0,    49,     0,    96,    97,    42,     0,    38,    40,
      43,     0,    44,    45,    46,    48,    54,    55,    62,    64,
      66,    69,    74,    77,    81,    86,    28,    36,     0,     0,
       0,    19,    21,    31,    33,    83,     0,    84,    82,    85,
       0,     0,     0,    24,    41,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    89,    90,     0,    35,
      23,    18,     0,    98,     0,    53,     0,    63,    77,    65,
      68,    67,    71,    73,    70,    72,    75,    76,    80,    78,
      79,    61,    59,    57,    58,    60,    56,    94,     0,    91,
      93,     0,    22,    49,    49,    88,     0,    87,    50,    52,
      95,    49,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -81,   -81,   -81,   126,   -81,   -81,   -15,   -81,   122,   -81,
     -81,   -81,   -81,   -81,   -81,    23,   125,   -81,   -81,    22,
     -81,   104,    65,   -81,   -81,   -81,   -48,   -81,    95,   -81,
     -81,   -81,   -36,   -80,   -81,    52,    54,   -37,    21,   -27,
     -33,   -81,   -81,   -81,   -81,   -81
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    20,    31,    70,    71,    72,    46,    26,    27,    14,
      21,    22,    23,    68,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   138,   139,   140,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      84,    76,    25,    75,    36,    77,    78,    79,    88,    37,
     -17,    17,    25,    19,    38,    69,    15,    39,    40,   131,
     132,   133,   134,   135,   136,   137,    96,   105,    32,    89,
      29,    97,   106,    41,    33,    42,   107,    43,    17,    28,
      98,    44,    45,    30,   114,     1,   116,   108,     2,    66,
       3,   120,   121,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   128,   129,   130,   150,   126,   127,    36,
      34,    36,   141,    94,    37,    67,    37,    95,    35,    38,
      74,    38,    39,    40,    39,    40,    90,    91,    29,   -49,
      92,    93,    80,    82,    83,   148,   149,    69,    85,    87,
      41,    86,    42,   152,    43,    17,    44,    45,    44,    45,
      99,   122,   123,   124,   125,   100,   109,   111,   101,   113,
     112,   115,   102,   143,   103,   144,   145,   146,   104,   151,
     147,    16,    24,    18,   110,   142,    73,    81,   117,     0,
       0,   119
};

static const yytype_int16 yycheck[] =
{
      48,    37,    17,    36,     5,    38,    39,    40,     6,    10,
      10,    39,    27,    42,    15,    30,     0,    18,    19,    99,
     100,   101,   102,   103,   104,   105,     7,    10,    17,    27,
      30,    12,    15,    34,    23,    36,    19,    38,    39,    17,
      21,    42,    43,    10,    80,    32,    82,    30,    35,    27,
      37,    88,    89,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,   146,    94,    95,     5,
      26,     5,   108,    14,    10,    43,    10,    18,    42,    15,
      43,    15,    18,    19,    18,    19,    24,    25,    30,    23,
      28,    29,    10,    10,    41,   143,   144,   112,    23,     9,
      34,    40,    36,   151,    38,    39,    42,    43,    42,    43,
       8,    90,    91,    92,    93,    13,    31,    11,    16,    11,
      17,    23,    20,    11,    22,    11,    11,    17,    26,    33,
      31,     5,    10,     8,    69,   112,    32,    42,    86,    -1,
      -1,    87
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    35,    37,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    64,     0,    48,    39,    61,    42,
      56,    65,    66,    67,    53,    51,    62,    63,    64,    30,
      10,    57,    17,    23,    26,    42,     5,    10,    15,    18,
      19,    34,    36,    38,    42,    43,    61,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    90,    64,    43,    68,    51,
      58,    59,    60,    66,    43,    85,    77,    85,    85,    85,
      10,    73,    10,    41,    71,    23,    40,     9,     6,    27,
      24,    25,    28,    29,    14,    18,     7,    12,    21,     8,
      13,    16,    20,    22,    26,    10,    15,    19,    30,    31,
      67,    11,    17,    11,    77,    23,    77,    80,    85,    81,
      82,    82,    83,    83,    83,    83,    84,    84,    85,    85,
      85,    78,    78,    78,    78,    78,    78,    78,    87,    88,
      89,    77,    60,    11,    11,    11,    17,    31,    71,    71,
      78,    33,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    49,    50,    51,
      52,    52,    53,    53,    54,    55,    55,    56,    57,    58,
      58,    59,    59,    60,    61,    62,    62,    63,    63,    64,
      65,    65,    66,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    71,    71,    71,    71,    72,    73,    73,
      74,    74,    75,    76,    77,    78,    78,    78,    78,    78,
      78,    78,    79,    79,    80,    80,    81,    81,    81,    82,
      82,    82,    82,    82,    83,    83,    83,    84,    84,    84,
      84,    85,    85,    85,    85,    85,    86,    86,    86,    86,
      86,    87,    87,    88,    89,    89,    90,    90,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       0,     1,     3,     2,     4,     1,     0,     1,     2,     3,
       1,     3,     1,     3,     1,     4,     1,     0,     1,     0,
       1,     2,     1,     1,     1,     1,     1,     2,     1,     0,
       5,     7,     5,     3,     1,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     2,     2,     1,     4,     4,     2,
       2,     1,     0,     1,     1,     3,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 152 "minic.y"
                                                          {semantic(1); temp = makeToken(PROGRAM, nodeName[PROGRAM]); root = buildTree(temp,(yyvsp[0].node));  }
#line 1601 "minic.tab.c"
    break;

  case 3:
#line 153 "minic.y"
                                                          {semantic(2); (yyval.node) = (yyvsp[0].node);}
#line 1607 "minic.tab.c"
    break;

  case 4:
#line 154 "minic.y"
                                                            {semantic(3);appendBro((yyvsp[-1].node),(yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node);}
#line 1613 "minic.tab.c"
    break;

  case 5:
#line 155 "minic.y"
                                                            {semantic(4); 
(yyval.node) = (yyvsp[0].node);}
#line 1620 "minic.tab.c"
    break;

  case 6:
#line 157 "minic.y"
                                                            {semantic(5);(yyval.node) = (yyvsp[0].node);}
#line 1626 "minic.tab.c"
    break;

  case 7:
#line 158 "minic.y"
                                                           {semantic(6);
appendBro((yyvsp[-1].node) ,(yyvsp[0].node));
temp = makeToken(FUNC_DEF, nodeName[FUNC_DEF]); (yyval.node) = buildTree(temp,(yyvsp[-1].node)); }
#line 1634 "minic.tab.c"
    break;

  case 8:
#line 161 "minic.y"
                                                           {semantic(7);
appendBro((yyvsp[-2].node),(yyvsp[-1].node)); appendBro((yyvsp[-1].node),(yyvsp[0].node));
temp = makeToken(FUNC_HEAD , nodeName[FUNC_HEAD]); (yyval.node) = buildTree(temp,(yyvsp[-2].node)); }
#line 1642 "minic.tab.c"
    break;

  case 9:
#line 164 "minic.y"
                                                           {semantic(8);
temp = makeToken(DCL_SPEC, nodeName[DCL_SPEC]); (yyval.node) = buildTree(temp,(yyvsp[0].node)); }
#line 1649 "minic.tab.c"
    break;

  case 10:
#line 166 "minic.y"
                                                           {semantic(9); (yyval.node) = (yyvsp[0].node);}
#line 1655 "minic.tab.c"
    break;

  case 11:
#line 167 "minic.y"
                                                        {semantic(10);appendBro((yyvsp[-1].node),(yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node);}
#line 1661 "minic.tab.c"
    break;

  case 12:
#line 168 "minic.y"
                                                            {semantic(11); (yyval.node) = (yyvsp[0].node);}
#line 1667 "minic.tab.c"
    break;

  case 13:
#line 169 "minic.y"
                                                             {semantic(12);(yyval.node) = (yyvsp[0].node);}
#line 1673 "minic.tab.c"
    break;

  case 14:
#line 170 "minic.y"
                                                         {semantic(13);
temp = makeToken(CONST_NODE, nodeName[CONST_NODE]); (yyval.node) = buildTree(temp,NULL); }
#line 1680 "minic.tab.c"
    break;

  case 15:
#line 172 "minic.y"
                                                          {semantic(14);
temp = makeToken(INT_NODE, nodeName[INT_NODE]); (yyval.node) = buildTree(temp,NULL);}
#line 1687 "minic.tab.c"
    break;

  case 16:
#line 174 "minic.y"
                                                        {semantic(15);
                 temp = makeToken(VOID_NODE, nodeName[VOID_NODE]); (yyval.node) = buildTree(temp,NULL);}
#line 1694 "minic.tab.c"
    break;

  case 17:
#line 176 "minic.y"
                                                         {semantic(16);
temp = makeToken(TIDENT, (yyvsp[0].string)); (yyval.node) = buildNode(temp);}
#line 1701 "minic.tab.c"
    break;

  case 18:
#line 178 "minic.y"
                                                                 {semantic(17);
temp = makeToken(FORMAL_PARA, nodeName[FORMAL_PARA]); (yyval.node) = buildTree(temp,(yyvsp[-1].node));}
#line 1708 "minic.tab.c"
    break;

  case 19:
#line 180 "minic.y"
                                                                {semantic(18); (yyval.node) = (yyvsp[0].node);}
#line 1714 "minic.tab.c"
    break;

  case 20:
#line 181 "minic.y"
                        {semantic(19); (yyval.node) = NULL;}
#line 1720 "minic.tab.c"
    break;

  case 21:
#line 182 "minic.y"
                                                                 {semantic(20);(yyval.node) = (yyvsp[0].node);}
#line 1726 "minic.tab.c"
    break;

  case 22:
#line 183 "minic.y"
                                                                  {semantic(21);appendBro((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node) = (yyvsp[-2].node);}
#line 1732 "minic.tab.c"
    break;

  case 23:
#line 184 "minic.y"
                                                        {semantic(22);
appendBro((yyvsp[-1].node),(yyvsp[0].node)); 
temp = makeToken(PARAM_DCL, nodeName[PARAM_DCL]); (yyval.node) = buildTree(temp,(yyvsp[-1].node));}
#line 1740 "minic.tab.c"
    break;

  case 24:
#line 188 "minic.y"
                                                                  {semantic(23); appendBro((yyvsp[-2].node),(yyvsp[-1].node));temp = makeToken(COMPOUND_ST, nodeName[COMPOUND_ST]);(yyval.node) = buildTree(temp,(yyvsp[-2].node)); }
#line 1746 "minic.tab.c"
    break;

  case 25:
#line 189 "minic.y"
                                                            {semantic(24);
temp = makeToken(DCL_LIST, nodeName[DCL_LIST]);(yyval.node) = buildTree(temp,(yyvsp[0].node));}
#line 1753 "minic.tab.c"
    break;

  case 26:
#line 191 "minic.y"
                                                                {semantic(25);temp = makeToken(DCL_LIST, nodeName[DCL_LIST]);(yyval.node) = buildTree(temp,NULL);}
#line 1759 "minic.tab.c"
    break;

  case 27:
#line 192 "minic.y"
                                                                  {semantic(26);(yyval.node) = (yyvsp[0].node);}
#line 1765 "minic.tab.c"
    break;

  case 28:
#line 193 "minic.y"
                                                                 {semantic(27);appendBro((yyvsp[-1].node),(yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node);}
#line 1771 "minic.tab.c"
    break;

  case 29:
#line 194 "minic.y"
                                                                 {semantic(28); appendBro((yyvsp[-2].node),(yyvsp[-1].node));
temp = makeToken(DCL, nodeName[DCL]);(yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 1778 "minic.tab.c"
    break;

  case 30:
#line 196 "minic.y"
                                                             {semantic(29);(yyval.node) = (yyvsp[0].node);}
#line 1784 "minic.tab.c"
    break;

  case 31:
#line 197 "minic.y"
                                                               {semantic(30);appendBro((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node) = (yyvsp[-2].node);}
#line 1790 "minic.tab.c"
    break;

  case 32:
#line 198 "minic.y"
                                                                  {semantic(31);
(yyval.node) = (yyvsp[0].node);}
#line 1797 "minic.tab.c"
    break;

  case 33:
#line 200 "minic.y"
                                                            {semantic(32); Node *ptr; temp_2 = makeToken(TNUMBER , (yyvsp[0].string)); ptr = buildNode(temp_2);
                 appendBro((yyvsp[-2].node),ptr); (yyval.node)= (yyvsp[-2].node);}
#line 1804 "minic.tab.c"
    break;

  case 34:
#line 202 "minic.y"
                                                           {semantic(33);
temp = makeToken(SIMPLE_VAR, nodeName[SIMPLE_VAR]);temp_2 = makeToken(TIDENT, (yyvsp[0].string)); Node* ptr =buildNode(temp_2); Node*ptr2 = buildTree(temp,ptr);
temp = makeToken(DCL_ITEM, nodeName[DCL_ITEM]);
(yyval.node) = buildTree(temp,ptr2);}
#line 1813 "minic.tab.c"
    break;

  case 35:
#line 206 "minic.y"
                                                                    {semantic(34);temp = makeToken(ARRAY_VAR, nodeName[ARRAY_VAR]);temp_2 = makeToken(TIDENT, (yyvsp[-3].string)); Node* ptr =buildNode(temp_2); appendBro(ptr , (yyvsp[-1].node));  Node*ptr2 = buildTree(temp,ptr); temp = makeToken(DCL_ITEM, nodeName[DCL_ITEM]);
(yyval.node) = buildTree(temp,ptr2);}
#line 1820 "minic.tab.c"
    break;

  case 36:
#line 208 "minic.y"
                                                               {semantic(35); temp = makeToken(TNUMBER, (yyvsp[0].string)); (yyval.node) = buildNode(temp);}
#line 1826 "minic.tab.c"
    break;

  case 37:
#line 209 "minic.y"
                                                                  {semantic(36);(yyval.node) = NULL;}
#line 1832 "minic.tab.c"
    break;

  case 38:
#line 211 "minic.y"
                                                            {semantic(37);temp = makeToken(STAT_LIST ,nodeName[STAT_LIST]); (yyval.node) = buildTree(temp,(yyvsp[0].node));}
#line 1838 "minic.tab.c"
    break;

  case 39:
#line 212 "minic.y"
                                                           {semantic(38); (yyval.node) = NULL;}
#line 1844 "minic.tab.c"
    break;

  case 40:
#line 213 "minic.y"
                                                             {semantic(39); (yyval.node) = (yyvsp[0].node);}
#line 1850 "minic.tab.c"
    break;

  case 41:
#line 214 "minic.y"
                                                               {semantic(40);appendBro((yyvsp[-1].node),(yyvsp[0].node)); (yyval.node) = (yyvsp[-1].node);}
#line 1856 "minic.tab.c"
    break;

  case 42:
#line 215 "minic.y"
                                                               {semantic(41); (yyval.node) = (yyvsp[0].node);}
#line 1862 "minic.tab.c"
    break;

  case 43:
#line 216 "minic.y"
                                                                   {semantic(42);(yyval.node) = (yyvsp[0].node);}
#line 1868 "minic.tab.c"
    break;

  case 44:
#line 217 "minic.y"
                                                                  {semantic(43);(yyval.node) = (yyvsp[0].node);}
#line 1874 "minic.tab.c"
    break;

  case 45:
#line 218 "minic.y"
                                                                  {semantic(44);(yyval.node) = (yyvsp[0].node);}
#line 1880 "minic.tab.c"
    break;

  case 46:
#line 219 "minic.y"
                                                                  {semantic(45);(yyval.node) = (yyvsp[0].node);}
#line 1886 "minic.tab.c"
    break;

  case 47:
#line 221 "minic.y"
                                                               {semantic(46);temp = makeToken(EXP_ST ,nodeName[EXP_ST]); (yyval.node) = buildTree(temp,(yyvsp[-1].node));}
#line 1892 "minic.tab.c"
    break;

  case 48:
#line 222 "minic.y"
                                                              {semantic(47);(yyval.node) =(yyvsp[0].node);}
#line 1898 "minic.tab.c"
    break;

  case 49:
#line 223 "minic.y"
                                                            {semantic(48);(yyval.node) = NULL;}
#line 1904 "minic.tab.c"
    break;

  case 50:
#line 224 "minic.y"
                                                                      {semantic(49);appendBro((yyvsp[-2].node),(yyvsp[0].node));temp = makeToken(IF_ST ,nodeName[IF_ST]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 1910 "minic.tab.c"
    break;

  case 51:
#line 225 "minic.y"
                                                                             {semantic(50); appendBro((yyvsp[-4].node), (yyvsp[-2].node)); appendBro((yyvsp[-2].node),(yyvsp[0].node)); temp = makeToken(IF_ELSE_ST ,nodeName[IF_ELSE_ST]); (yyval.node) = buildTree(temp,(yyvsp[-4].node));}
#line 1916 "minic.tab.c"
    break;

  case 52:
#line 226 "minic.y"
                                                                 {semantic(51); appendBro((yyvsp[-2].node) ,(yyvsp[0].node));temp = makeToken(WHILE_ST ,nodeName[WHILE_ST]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 1922 "minic.tab.c"
    break;

  case 53:
#line 227 "minic.y"
                                                                {semantic(52); temp = makeToken(RETURN_ST ,nodeName[RETURN_ST]); (yyval.node) = buildTree(temp,(yyvsp[-1].node));}
#line 1928 "minic.tab.c"
    break;

  case 54:
#line 229 "minic.y"
                                                            {semantic(53);(yyval.node) = (yyvsp[0].node);}
#line 1934 "minic.tab.c"
    break;

  case 55:
#line 230 "minic.y"
                                                           {semantic(54); (yyval.node) = (yyvsp[0].node);}
#line 1940 "minic.tab.c"
    break;

  case 56:
#line 231 "minic.y"
                                                               {semantic(55); appendBro((yyvsp[-2].node),(yyvsp[0].node));
                 temp = makeToken(ASSIGN_OP ,nodeName[ASSIGN_OP]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 1947 "minic.tab.c"
    break;

  case 57:
#line 233 "minic.y"
                                                                {semantic(56);appendBro((yyvsp[-2].node),(yyvsp[0].node));
                 temp = makeToken(ADD_ASSIGN ,nodeName[ADD_ASSIGN]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 1954 "minic.tab.c"
    break;

  case 58:
#line 235 "minic.y"
                                                                 {semantic(57);appendBro((yyvsp[-2].node),(yyvsp[0].node));
                 temp = makeToken(SUB_ASSIGN ,nodeName[SUB_ASSIGN]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 1961 "minic.tab.c"
    break;

  case 59:
#line 237 "minic.y"
                                                                {semantic(58);appendBro((yyvsp[-2].node),(yyvsp[0].node));
                 temp = makeToken(MUL_ASSIGN ,nodeName[MUL_ASSIGN]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 1968 "minic.tab.c"
    break;

  case 60:
#line 239 "minic.y"
                                                                {semantic(59);appendBro((yyvsp[-2].node),(yyvsp[0].node));
                 temp = makeToken(DIV_ASSIGN ,nodeName[DIV_ASSIGN]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 1975 "minic.tab.c"
    break;

  case 61:
#line 241 "minic.y"
                                                               {semantic(60);appendBro((yyvsp[-2].node),(yyvsp[0].node));
                 temp = makeToken(MOD_ASSIGN ,nodeName[MOD_ASSIGN]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 1982 "minic.tab.c"
    break;

  case 62:
#line 243 "minic.y"
                                                                {semantic(61); (yyval.node) = (yyvsp[0].node);}
#line 1988 "minic.tab.c"
    break;

  case 63:
#line 244 "minic.y"
                                                         {semantic(62); appendBro((yyvsp[-2].node),(yyvsp[0].node));
                 temp = makeToken(LOGICAL_OR ,nodeName[LOGICAL_OR]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 1995 "minic.tab.c"
    break;

  case 64:
#line 246 "minic.y"
                                                                {semantic(63);(yyval.node) =(yyvsp[0].node);}
#line 2001 "minic.tab.c"
    break;

  case 65:
#line 247 "minic.y"
                                                          {semantic(64);appendBro((yyvsp[-2].node),(yyvsp[0].node));
                 temp = makeToken(LOGICAL_AND ,nodeName[LOGICAL_AND]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 2008 "minic.tab.c"
    break;

  case 66:
#line 249 "minic.y"
                                                                 {semantic(65);(yyval.node) =(yyvsp[0].node);}
#line 2014 "minic.tab.c"
    break;

  case 67:
#line 250 "minic.y"
                                                               {semantic(66);appendBro((yyvsp[-2].node),(yyvsp[0].node));
                 temp = makeToken(EQ ,nodeName[EQ]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 2021 "minic.tab.c"
    break;

  case 68:
#line 252 "minic.y"
                                                             {semantic(67);appendBro((yyvsp[-2].node),(yyvsp[0].node));
                 temp = makeToken(NE ,nodeName[NE]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 2028 "minic.tab.c"
    break;

  case 69:
#line 254 "minic.y"
                                                                {semantic(68); (yyval.node) = (yyvsp[0].node);}
#line 2034 "minic.tab.c"
    break;

  case 70:
#line 255 "minic.y"
                                                             {semantic(69);appendBro((yyvsp[-2].node),(yyvsp[0].node));
                 temp = makeToken(GT ,nodeName[GT]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 2041 "minic.tab.c"
    break;

  case 71:
#line 257 "minic.y"
                                                              {semantic(70);appendBro((yyvsp[-2].node),(yyvsp[0].node));
                 temp = makeToken(LT ,nodeName[LT]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 2048 "minic.tab.c"
    break;

  case 72:
#line 259 "minic.y"
                                                               {semantic(71);appendBro((yyvsp[-2].node),(yyvsp[0].node));
                 temp = makeToken(GE ,nodeName[GE]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 2055 "minic.tab.c"
    break;

  case 73:
#line 261 "minic.y"
                                                                {semantic(72); appendBro((yyvsp[-2].node),(yyvsp[0].node));
                 temp = makeToken(LE ,nodeName[LE]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 2062 "minic.tab.c"
    break;

  case 74:
#line 263 "minic.y"
                                                                {semantic(73); (yyval.node) =(yyvsp[0].node);}
#line 2068 "minic.tab.c"
    break;

  case 75:
#line 264 "minic.y"
                                                                 {semantic(74); appendBro((yyvsp[-2].node),(yyvsp[0].node));
                 temp = makeToken(ADD ,nodeName[ADD]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 2075 "minic.tab.c"
    break;

  case 76:
#line 266 "minic.y"
                                                                  {semantic(75);appendBro((yyvsp[-2].node),(yyvsp[0].node));
                 temp = makeToken(SUB ,nodeName[SUB]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 2082 "minic.tab.c"
    break;

  case 77:
#line 268 "minic.y"
                                                                    {semantic(76);(yyval.node) = (yyvsp[0].node);}
#line 2088 "minic.tab.c"
    break;

  case 78:
#line 269 "minic.y"
                                                              {semantic(77);appendBro((yyvsp[-2].node),(yyvsp[0].node));
                 temp = makeToken(MUL ,nodeName[MUL]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 2095 "minic.tab.c"
    break;

  case 79:
#line 271 "minic.y"
                                                                 {semantic(78);appendBro((yyvsp[-2].node),(yyvsp[0].node));
                 temp = makeToken(DIV ,nodeName[DIV]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 2102 "minic.tab.c"
    break;

  case 80:
#line 273 "minic.y"
                                                                 {semantic(79);appendBro((yyvsp[-2].node),(yyvsp[0].node));
                 temp = makeToken(MOD ,nodeName[MOD]); (yyval.node) = buildTree(temp,(yyvsp[-2].node));}
#line 2109 "minic.tab.c"
    break;

  case 81:
#line 275 "minic.y"
                                                                    {semantic(80); (yyval.node) = (yyvsp[0].node);}
#line 2115 "minic.tab.c"
    break;

  case 82:
#line 276 "minic.y"
                                                                       {semantic(81);temp = makeToken(UNARY_MINUS ,nodeName[UNARY_MINUS]); (yyval.node) = buildTree(temp,(yyvsp[0].node));}
#line 2121 "minic.tab.c"
    break;

  case 83:
#line 277 "minic.y"
                                                                        {semantic(82);temp = makeToken(LOGICAL_NOT ,nodeName[LOGICAL_NOT]); (yyval.node) = buildTree(temp,(yyvsp[0].node));}
#line 2127 "minic.tab.c"
    break;

  case 84:
#line 278 "minic.y"
                                                                         {semantic(83);temp = makeToken(PRE_INC ,nodeName[PRE_INC]); (yyval.node) = buildTree(temp,(yyvsp[0].node));}
#line 2133 "minic.tab.c"
    break;

  case 85:
#line 279 "minic.y"
                                                          {semantic(84);
                   temp = makeToken(PRE_DEC ,nodeName[PRE_DEC]); (yyval.node) = buildTree(temp,(yyvsp[0].node));}
#line 2140 "minic.tab.c"
    break;

  case 86:
#line 281 "minic.y"
                                                               {semantic(85);(yyval.node) = (yyvsp[0].node);}
#line 2146 "minic.tab.c"
    break;

  case 87:
#line 282 "minic.y"
                                                                        {semantic(86);appendBro((yyvsp[-3].node),(yyvsp[-1].node)); temp = makeToken(INDEX ,nodeName[INDEX]); (yyval.node) = buildTree(temp,(yyvsp[-3].node));}
#line 2152 "minic.tab.c"
    break;

  case 88:
#line 283 "minic.y"
                                                                        {semantic(87);appendBro((yyvsp[-3].node),(yyvsp[-1].node)); temp = makeToken(CALL ,nodeName[CALL]); (yyval.node) = buildTree(temp,(yyvsp[-3].node));}
#line 2158 "minic.tab.c"
    break;

  case 89:
#line 284 "minic.y"
                                                              {semantic(88);temp = makeToken(POST_INC ,nodeName[POST_INC]); (yyval.node) = buildTree(temp,(yyvsp[-1].node));}
#line 2164 "minic.tab.c"
    break;

  case 90:
#line 285 "minic.y"
                                                               {semantic(89);temp = makeToken(POST_DEC ,nodeName[POST_DEC]); (yyval.node) = buildTree(temp,(yyvsp[-1].node));}
#line 2170 "minic.tab.c"
    break;

  case 91:
#line 286 "minic.y"
                                                                {semantic(90);(yyval.node) = (yyvsp[0].node);}
#line 2176 "minic.tab.c"
    break;

  case 92:
#line 287 "minic.y"
                                                                  {semantic(91);(yyval.node) = NULL;}
#line 2182 "minic.tab.c"
    break;

  case 93:
#line 288 "minic.y"
                                                          {semantic(92);temp = makeToken(ACTUAL_PARAM ,nodeName[ACTUAL_PARAM]); (yyval.node) = buildTree(temp,(yyvsp[0].node));}
#line 2188 "minic.tab.c"
    break;

  case 94:
#line 289 "minic.y"
                                                             {semantic(93);(yyval.node) = (yyvsp[0].node);}
#line 2194 "minic.tab.c"
    break;

  case 95:
#line 290 "minic.y"
                                                                          {semantic(94);appendBro((yyvsp[-2].node),(yyvsp[0].node)); (yyval.node)= (yyvsp[-2].node);}
#line 2200 "minic.tab.c"
    break;

  case 96:
#line 291 "minic.y"
                                                                            {semantic(95); temp = makeToken(TIDENT ,(yyvsp[0].string)); (yyval.node) = buildNode(temp);}
#line 2206 "minic.tab.c"
    break;

  case 97:
#line 292 "minic.y"
                                                                              {semantic(96);temp = makeToken(TNUMBER ,(yyvsp[0].string)); (yyval.node) = buildNode(temp);}
#line 2212 "minic.tab.c"
    break;

  case 98:
#line 293 "minic.y"
                                                                            {semantic(97);(yyval.node) = (yyvsp[-1].node);}
#line 2218 "minic.tab.c"
    break;


#line 2222 "minic.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 295 "minic.y"

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
