/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

	#include "quad.h"
	
	int yyerror (char* yaccProvidedMessage);
	int yylex (void);
	
	extern int yylineno;
	extern char * yyval;
	extern char * yytext;
	extern FILE * yyin;
	extern FILE * yyout;
	
	
	
	quad *tmpquad[100], *fortmpquad=NULL;
	expr *tmpCall=NULL;
	int i=0, normCall= 0, paramCounter=0, LogicFlag =0, Balls=0, ErrorFlag = 0;
	int loopstart[100],loopindex=0, Qindex=0, forstart=0;
	SymbolNode  *TmpNode;
	intlist *tmp = NULL;

#line 88 "parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    IF = 258,
    ELSE = 259,
    WHILE = 260,
    FOR = 261,
    FUNCTION = 262,
    RETURN = 263,
    BREAK = 264,
    CONTINUE = 265,
    LOCAL = 266,
    TRUE = 267,
    FALSE = 268,
    NIL = 269,
    NOT = 270,
    AND = 271,
    OR = 272,
    ASSIGN = 273,
    PLUS = 274,
    MINUS = 275,
    MULTI = 276,
    DIV = 277,
    MOD = 278,
    EQUAL = 279,
    NEQUAL = 280,
    PPLUS = 281,
    MMINUS = 282,
    GREATER = 283,
    LESS = 284,
    GREATER_EQUAL = 285,
    LESS_EQUAL = 286,
    NUMBER = 287,
    REALNUM = 288,
    ID = 289,
    STRING = 290,
    LEFT_CBRACKET = 291,
    RIGHT_CBRACKET = 292,
    LEFT_SBRACKET = 293,
    RIGHT_SBRACKET = 294,
    LEFT_PARENTHES = 295,
    RIGHT_PARENTHES = 296,
    SEMICOLON = 297,
    COMMA = 298,
    COLON = 299,
    DCOLON = 300,
    DOT = 301,
    DOTS = 302,
    COMMENT = 303,
    COMMENT2 = 304,
    OTHER = 305,
    UMINUS = 306,
    LEFT_SBRANCKET = 307,
    RIGHT_SBRANCKET = 308,
    LEFT_CBRANCKET = 309,
    RIGHT_CBRANCKET = 310
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define WHILE 260
#define FOR 261
#define FUNCTION 262
#define RETURN 263
#define BREAK 264
#define CONTINUE 265
#define LOCAL 266
#define TRUE 267
#define FALSE 268
#define NIL 269
#define NOT 270
#define AND 271
#define OR 272
#define ASSIGN 273
#define PLUS 274
#define MINUS 275
#define MULTI 276
#define DIV 277
#define MOD 278
#define EQUAL 279
#define NEQUAL 280
#define PPLUS 281
#define MMINUS 282
#define GREATER 283
#define LESS 284
#define GREATER_EQUAL 285
#define LESS_EQUAL 286
#define NUMBER 287
#define REALNUM 288
#define ID 289
#define STRING 290
#define LEFT_CBRACKET 291
#define RIGHT_CBRACKET 292
#define LEFT_SBRACKET 293
#define RIGHT_SBRACKET 294
#define LEFT_PARENTHES 295
#define RIGHT_PARENTHES 296
#define SEMICOLON 297
#define COMMA 298
#define COLON 299
#define DCOLON 300
#define DOT 301
#define DOTS 302
#define COMMENT 303
#define COMMENT2 304
#define OTHER 305
#define UMINUS 306
#define LEFT_SBRANCKET 307
#define RIGHT_SBRANCKET 308
#define LEFT_CBRANCKET 309
#define RIGHT_CBRANCKET 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 131 "parser.y" /* yacc.c:355  */

	char* strVal;
	int intVal;
	double dbVal;
	struct expr *expression;
	struct stmt *statement;
	struct quad *quad;

#line 247 "parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 262 "parser.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  70
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   561

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   142,   142,   145,   148,   151,   173,   177,   181,   185,
     188,   199,   210,   213,   216,   223,   229,   231,   233,   235,
     237,   239,   256,   274,   284,   294,   304,   314,   324,   334,
     341,   341,   367,   371,   374,   382,   402,   402,   421,   441,
     441,   462,   482,   483,   486,   489,   492,   497,   500,   503,
     506,   509,   512,   517,   556,   591,   599,   604,   608,   614,
     618,   621,   633,   648,   660,   661,   664,   675,   675,   692,
     697,   703,   708,   715,   719,   725,   730,   731,   734,   739,
     740,   740,   749,   756,   758,   749,   771,   794,   794,   771,
     806,   806,   826,   829,   829,   848,   851,   855,   855,   864,
     864,   894,   898,   893,   936,   939,   966,   936,   982,   986
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "FOR", "FUNCTION",
  "RETURN", "BREAK", "CONTINUE", "LOCAL", "TRUE", "FALSE", "NIL", "NOT",
  "AND", "OR", "ASSIGN", "PLUS", "MINUS", "MULTI", "DIV", "MOD", "EQUAL",
  "NEQUAL", "PPLUS", "MMINUS", "GREATER", "LESS", "GREATER_EQUAL",
  "LESS_EQUAL", "NUMBER", "REALNUM", "ID", "STRING", "LEFT_CBRACKET",
  "RIGHT_CBRACKET", "LEFT_SBRACKET", "RIGHT_SBRACKET", "LEFT_PARENTHES",
  "RIGHT_PARENTHES", "SEMICOLON", "COMMA", "COLON", "DCOLON", "DOT",
  "DOTS", "COMMENT", "COMMENT2", "OTHER", "UMINUS", "LEFT_SBRANCKET",
  "RIGHT_SBRANCKET", "LEFT_CBRANCKET", "RIGHT_CBRANCKET", "$accept",
  "program", "statements", "stmt", "expr", "assignexpr", "$@1", "term",
  "$@2", "$@3", "primary", "const", "lvalue", "member", "call",
  "callsuffix", "normcall", "methodcall", "$@4", "elist", "cexprs",
  "objectdef", "indexed", "clindexedelem", "indexedelem", "block", "$@5",
  "funcdef", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "idlist", "$@12",
  "cidlist", "$@13", "ifstmt", "$@14", "ifstart", "$@15", "whilestmt",
  "$@16", "$@17", "forstmt", "$@18", "$@19", "$@20", "returnstmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF -140

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-140)))

#define YYTABLE_NINF -40

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-40)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     161,   -38,   -20,   -13,     3,   196,    -3,     5,    11,  -140,
    -140,  -140,   266,   266,     8,     8,  -140,  -140,  -140,  -140,
      21,   231,    -2,  -140,    25,    60,  -140,   161,   326,  -140,
    -140,  -140,  -140,    67,  -140,   -17,  -140,  -140,  -140,  -140,
     161,  -140,  -140,  -140,  -140,  -140,   266,  -140,    22,  -140,
     342,  -140,  -140,  -140,  -140,  -140,    54,   -12,   -17,   -12,
    -140,   161,   266,   310,    24,    26,    23,   374,    39,  -140,
    -140,  -140,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,  -140,   266,   266,    30,    49,
      68,    61,    62,  -140,  -140,  -140,   266,   266,    56,    84,
     266,   266,    55,    58,  -140,  -140,    59,   161,   293,   266,
    -140,  -140,  -140,    63,  -140,  -140,    66,   130,   130,    29,
      29,  -140,  -140,  -140,   517,   517,   530,   530,   530,   530,
     443,    69,  -140,  -140,   266,  -140,  -140,   464,    70,  -140,
    -140,   397,   420,  -140,  -140,    75,    66,    64,   266,   310,
      23,   266,  -140,  -140,    72,   504,  -140,  -140,   161,  -140,
    -140,   266,    75,  -140,    74,  -140,   485,  -140,  -140,    76,
     266,  -140,   161,   358,    77,    73,  -140,  -140,  -140,    79,
    -140,  -140,  -140,    87,  -140,    86,  -140,   266,    86,  -140,
    -140,    82,  -140,    73,  -140,  -140,   161,  -140
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,    82,     0,     0,     0,     0,    50,
      51,    52,     0,     0,     0,     0,    47,    48,    53,    49,
      80,    70,     0,    14,     0,     0,     2,     4,     0,    15,
      29,    33,    46,    42,    56,    43,    44,    12,    13,     6,
       0,     7,     8,     9,    99,   101,    70,    86,     0,   109,
       0,    10,    11,    54,    41,    34,     0,    35,     0,    38,
      79,     0,     0,    72,     0,     0,    77,     0,     0,    55,
       1,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,    70,     0,     0,
       0,     0,     0,    62,    64,    65,     0,    70,     0,    96,
       0,     0,     0,     0,    83,   108,     0,     4,     0,     0,
      69,    73,    74,     0,    75,    32,    45,    21,    22,    16,
      17,    18,    19,    20,    23,    24,    25,    26,    27,    28,
       0,     0,    57,    67,     0,    37,    40,     0,     0,    59,
      97,     0,     0,   104,    87,    92,     0,     0,     0,    72,
      77,    70,    58,    66,     0,    31,    60,    61,     0,   100,
     102,     0,    92,    90,     0,    81,     0,    71,    76,     0,
      70,    98,     0,     0,     0,    95,    84,    78,    63,     0,
     103,   105,    88,     0,    91,     0,    68,    70,     0,    93,
      85,     0,    89,    95,   106,    94,     0,   107
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,  -140,   -23,   -39,    -5,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,     0,  -140,    41,  -140,  -140,  -140,  -140,   -43,
     -47,  -140,  -140,   -26,   -10,  -139,  -140,   -16,  -140,  -140,
    -140,  -140,  -140,  -140,   -37,  -140,   -67,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,    29,    90,    30,    91,    92,
      31,    32,    33,    34,    35,    93,    94,    95,   154,    64,
     110,    36,    65,   114,    66,    37,    61,    38,    48,   145,
     185,   103,   162,   188,   164,   175,   184,   193,    39,   158,
      40,   100,    41,   101,   172,    42,   161,   187,   196,    43
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,    99,    44,   102,    71,     4,    68,    54,    55,     8,
       9,    10,    11,    12,    57,    59,    63,    67,    13,     8,
      45,    96,   107,    97,    14,    15,    86,    46,    87,    98,
      16,    17,    18,    19,    88,    89,    21,    47,    22,    51,
     106,    63,    18,    24,   131,    53,   190,    52,    56,   192,
      76,    77,    78,    24,   138,    58,    58,   108,    60,    69,
      70,     4,   104,   111,   132,   112,   113,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     116,   130,    63,   133,   147,   -30,   134,   135,   140,   136,
     139,   137,    63,   -36,   -39,   141,   142,   143,   144,    62,
     146,   165,   167,   150,   149,    86,   151,    87,   169,   163,
     153,   157,   170,    88,    89,   176,   183,   178,   182,   171,
     186,   189,    20,   194,   168,   174,   195,   179,     0,   155,
       0,     0,     0,   180,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   166,   191,     0,    63,     0,     0,    74,
      75,    76,    77,    78,    79,    80,   173,   197,    81,    82,
      83,    84,     0,     0,     1,    63,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,     0,     0,     0,
       0,    13,    63,     0,     0,     0,     0,    14,    15,     0,
       0,     0,     0,    16,    17,    18,    19,    20,     0,    21,
       0,    22,     0,    23,     0,     0,    24,     8,     9,    10,
      11,    12,     0,     0,     0,     0,    13,     0,     0,     0,
       0,     0,    14,    15,     0,     0,     0,     0,    16,    17,
      18,    19,     0,     0,    21,     0,    22,     0,    49,     0,
       0,    24,     8,     9,    10,    11,    12,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,    14,    15,     0,
       0,     0,     0,    16,    17,    18,    19,    62,     0,    21,
       0,    22,     0,     0,     0,     0,    24,     8,     9,    10,
      11,    12,     0,     0,     0,     0,    13,     0,     0,     0,
       0,     0,    14,    15,     0,     0,     0,     0,    16,    17,
      18,    19,     0,     0,    21,     0,    22,     0,     0,    72,
      73,    24,    74,    75,    76,    77,    78,    79,    80,     0,
       0,    81,    82,    83,    84,     0,    72,    73,     0,    74,
      75,    76,    77,    78,    79,    80,     0,   148,    81,    82,
      83,    84,    72,    73,     0,    74,    75,    76,    77,    78,
      79,    80,     0,   109,    81,    82,    83,    84,    72,    73,
       0,    74,    75,    76,    77,    78,    79,    80,    85,     0,
      81,    82,    83,    84,    72,    73,     0,    74,    75,    76,
      77,    78,    79,    80,   105,     0,    81,    82,    83,    84,
      72,    73,     0,    74,    75,    76,    77,    78,    79,    80,
     181,     0,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,    72,    73,   115,    74,    75,    76,    77,
      78,    79,    80,     0,     0,    81,    82,    83,    84,     0,
       0,     0,     0,     0,     0,     0,    72,    73,   159,    74,
      75,    76,    77,    78,    79,    80,     0,     0,    81,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,    72,
      73,   160,    74,    75,    76,    77,    78,    79,    80,     0,
       0,    81,    82,    83,    84,     0,     0,     0,     0,     0,
      72,    73,   152,    74,    75,    76,    77,    78,    79,    80,
       0,     0,    81,    82,    83,    84,     0,     0,     0,     0,
       0,    72,    73,   156,    74,    75,    76,    77,    78,    79,
      80,     0,     0,    81,    82,    83,    84,     0,     0,     0,
      72,    73,   177,    74,    75,    76,    77,    78,    79,    80,
       0,     0,    81,    82,    83,    84,    74,    75,    76,    77,
      78,   -40,   -40,     0,     0,    81,    82,    83,    84,    74,
      75,    76,    77,    78,     0,     0,     0,     0,   -40,   -40,
     -40,   -40
};

static const yytype_int16 yycheck[] =
{
       5,    40,    40,    46,    27,     7,    22,    12,    13,    11,
      12,    13,    14,    15,    14,    15,    21,    22,    20,    11,
      40,    38,    61,    40,    26,    27,    38,    40,    40,    46,
      32,    33,    34,    35,    46,    47,    38,    34,    40,    42,
      56,    46,    34,    45,    87,    34,   185,    42,    40,   188,
      21,    22,    23,    45,    97,    14,    15,    62,    37,    34,
       0,     7,    40,    39,    34,    39,    43,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      41,    86,    87,    34,   107,    18,    18,    26,     4,    27,
      34,    96,    97,    26,    27,   100,   101,    42,    40,    36,
      41,    37,   149,   113,   109,    38,    40,    40,   151,    34,
      41,    41,    40,    46,    47,    41,    43,    41,    41,   158,
      41,    34,    36,    41,   150,   162,   193,   170,    -1,   134,
      -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   187,    -1,   151,    -1,    -1,    19,
      20,    21,    22,    23,    24,    25,   161,   196,    28,    29,
      30,    31,    -1,    -1,     3,   170,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    20,   187,    -1,    -1,    -1,    -1,    26,    27,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    38,
      -1,    40,    -1,    42,    -1,    -1,    45,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    -1,    -1,    38,    -1,    40,    -1,    42,    -1,
      -1,    45,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,    38,
      -1,    40,    -1,    -1,    -1,    -1,    45,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    -1,    -1,    38,    -1,    40,    -1,    -1,    16,
      17,    45,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    30,    31,    -1,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    -1,    44,    28,    29,
      30,    31,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    -1,    43,    28,    29,    30,    31,    16,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    42,    -1,
      28,    29,    30,    31,    16,    17,    -1,    19,    20,    21,
      22,    23,    24,    25,    42,    -1,    28,    29,    30,    31,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      42,    -1,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    17,    41,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    41,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      17,    41,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      16,    17,    39,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    16,    17,    39,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    28,    29,    30,    31,    -1,    -1,    -1,
      16,    17,    37,    19,    20,    21,    22,    23,    24,    25,
      -1,    -1,    28,    29,    30,    31,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    29,    30,    31,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    28,    29,
      30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    20,    26,    27,    32,    33,    34,    35,
      36,    38,    40,    42,    45,    57,    58,    59,    60,    61,
      63,    66,    67,    68,    69,    70,    77,    81,    83,    94,
      96,    98,   101,   105,    40,    40,    40,    34,    84,    42,
      60,    42,    42,    34,    60,    60,    40,    68,    70,    68,
      37,    82,    36,    60,    75,    78,    80,    60,    83,    34,
       0,    58,    16,    17,    19,    20,    21,    22,    23,    24,
      25,    28,    29,    30,    31,    42,    38,    40,    46,    47,
      62,    64,    65,    71,    72,    73,    38,    40,    46,    59,
      97,    99,    75,    87,    40,    42,    83,    59,    60,    43,
      76,    39,    39,    43,    79,    41,    41,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    75,    34,    34,    18,    26,    27,    60,    75,    34,
       4,    60,    60,    42,    40,    85,    41,    58,    44,    60,
      80,    40,    39,    41,    74,    60,    39,    41,    95,    41,
      41,   102,    88,    34,    90,    37,    60,    76,    79,    75,
      40,    59,   100,    60,    90,    91,    41,    37,    41,    75,
      59,    42,    41,    43,    92,    86,    41,   103,    89,    34,
      81,    75,    81,    93,    41,    92,   104,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      62,    61,    63,    63,    63,    63,    64,    63,    63,    65,
      63,    63,    66,    66,    66,    66,    66,    67,    67,    67,
      67,    67,    67,    68,    68,    68,    68,    69,    69,    69,
      69,    70,    70,    70,    71,    71,    72,    74,    73,    75,
      75,    76,    76,    77,    77,    78,    79,    79,    80,    81,
      82,    81,    84,    85,    86,    83,    87,    88,    89,    83,
      91,    90,    90,    93,    92,    92,    94,    95,    94,    97,
      96,    99,   100,    98,   102,   103,   104,   101,   105,   105
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       0,     4,     3,     1,     2,     2,     0,     3,     2,     0,
       3,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     3,     4,     3,
       4,     4,     2,     6,     1,     1,     3,     0,     6,     2,
       0,     3,     0,     3,     3,     2,     3,     0,     5,     2,
       0,     5,     0,     0,     0,     8,     0,     0,     0,     9,
       0,     3,     0,     0,     4,     0,     2,     0,     5,     0,
       5,     0,     0,     7,     0,     0,     0,    12,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
#line 142 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout," program ==> statements \n");}
#line 1559 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 145 "parser.y" /* yacc.c:1646  */
    {
									fprintf(yyout,"statements ==> stmt statements\n");
								}
#line 1567 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 148 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"statements ==> empty \n");}
#line 1573 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 151 "parser.y" /* yacc.c:1646  */
    {
							if (LogicFlag){
								backpatch(Truehead, currQuad);
								backpatch(Falsehead, currQuad+2);
								
								/*fix last JUMP*/
								tmpquad[98] = quads+currQuad-1;
								tmpquad[98]->label = currQuad+2;
								/*Threeway*/
								(yyval.expression) = insertExpr(assign, ConstBool_exp(1), NULL, currQuad, boolexpr_e);
								insertQuad(jump,NULL,NULL,NULL,currQuad+2,currQuad);								
								insertQuad(assign, (yyval.expression), ConstBool_exp(0), NULL, -1, boolexpr_e);
							
								insertQuad(assign,(yyvsp[-1].expression), (yyval.expression),NULL,-1,currQuad);
								LogicFlag = 0;
							}
							
							
							//$$=NULL;
							strcpy(dflt_tmpname ,"_tmp00");
							fprintf(yyout,"stmt ==> expr; \n");
						}
#line 1600 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 173 "parser.y" /* yacc.c:1646  */
    {
							(yyval.expression)=(yyvsp[0].expression);
							LogicFlag = 0;
							fprintf(yyout,"stmt ==> ifstmt \n");}
#line 1609 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 177 "parser.y" /* yacc.c:1646  */
    {
							(yyval.expression)=NULL;
							LogicFlag = 0;
							fprintf(yyout,"stmt ==> whilestmt  \n");}
#line 1618 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 181 "parser.y" /* yacc.c:1646  */
    {
							(yyval.expression)=NULL;
							LogicFlag = 0;
							fprintf(yyout,"stmt ==> forstmt \n");}
#line 1627 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 185 "parser.y" /* yacc.c:1646  */
    {
							(yyval.expression)=NULL;
							fprintf(yyout,"stmt ==> returnstmt \n");}
#line 1635 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 188 "parser.y" /* yacc.c:1646  */
    {
								if (loopindex>0){
									BreakHead=CreateIntList(currQuad,BreakHead);
									insertQuad(jump, NULL, NULL, NULL, -1, currQuad);
								}
								else{
									printf("Error!!! In Line %d | Break statement found. Not in loop.\n",yylineno);
									ErrorFlag = 1;
								}
								fprintf(yyout,"stmt ==> break; \n");
							}
#line 1651 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 199 "parser.y" /* yacc.c:1646  */
    {
								if (loopindex>0){
									ContinueHead=CreateIntList(currQuad,ContinueHead);
									insertQuad(jump, NULL, NULL, NULL, -1, currQuad);
								}
								else{
									printf("Error!!! In Line %d | Continue statement found. Not in loop.\n",yylineno);
									ErrorFlag = 1;
								}
								fprintf(yyout,"stmt ==> continue; \n");
							}
#line 1667 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 210 "parser.y" /* yacc.c:1646  */
    {
							(yyval.expression)=(yyvsp[0].expression);
							fprintf(yyout,"stmt ==> block \n");}
#line 1675 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 213 "parser.y" /* yacc.c:1646  */
    {
							(yyval.expression)=(yyvsp[0].expression);
							fprintf(yyout,"stmt ==> funcdef \n");}
#line 1683 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 216 "parser.y" /* yacc.c:1646  */
    {	
							(yyval.expression)=NULL;
							fprintf(yyout,"stmt ==> ; \n"); 
							strcpy(dflt_tmpname ,"_tmp00");
						}
#line 1693 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 223 "parser.y" /* yacc.c:1646  */
    {	
						(yyval.expression)=(yyvsp[0].expression);
						(yyval.expression)->type=assgnexpr_e;						
						Balls=1;
						fprintf(yyout,"expr ==> assignexpr  \n");
					}
#line 1704 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 229 "parser.y" /* yacc.c:1646  */
    { 	(yyval.expression)=insertExpr(add,(yyvsp[-2].expression),(yyvsp[0].expression), currQuad,arithexpr_e);
								fprintf(yyout,"expr ==>  expr + expr  \n");}
#line 1711 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 231 "parser.y" /* yacc.c:1646  */
    { 	(yyval.expression)=insertExpr(sub,(yyvsp[-2].expression),(yyvsp[0].expression), currQuad,arithexpr_e);
								fprintf(yyout,"expr ==>  expr - expr  \n");}
#line 1718 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 233 "parser.y" /* yacc.c:1646  */
    { 	(yyval.expression)=insertExpr(mul,(yyvsp[-2].expression),(yyvsp[0].expression), currQuad,arithexpr_e);
								fprintf(yyout,"expr ==>  expr * expr  \n");}
#line 1725 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 235 "parser.y" /* yacc.c:1646  */
    { 	(yyval.expression)=insertExpr(divv,(yyvsp[-2].expression),(yyvsp[0].expression), currQuad,arithexpr_e);
								fprintf(yyout,"expr ==>  expr div expr  \n");}
#line 1732 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 237 "parser.y" /* yacc.c:1646  */
    { 	(yyval.expression)=insertExpr(mod,(yyvsp[-2].expression),(yyvsp[0].expression), currQuad,arithexpr_e);
								fprintf(yyout,"expr ==>  expr mod expr  \n");}
#line 1739 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 240 "parser.y" /* yacc.c:1646  */
    {	
								/*an to $1 (to if )paei sto true fix it*/
								tmp = (intlist*) malloc (sizeof(intlist) );
								tmp->currentquad = currQuad -4;
								backpatch(tmp, currQuad-2);
								/*Delete apo thn true list gia na mhn to pathsei */
								Truehead = DeleteIntList(currQuad-4, Truehead);
								//free(tmp);
								tmp = NULL;
								
								Falsehead=CreateIntList(currQuad-1,Falsehead);/*$3 jump*/
								Falsehead=CreateIntList(currQuad-3,Falsehead);/*$1 jump*/

								LogicFlag =1;
								fprintf(yyout,"expr ==>  expr and expr  \n");
							}
#line 1760 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 256 "parser.y" /* yacc.c:1646  */
    {			
								tmp = (intlist*) malloc (sizeof(intlist) );

								/*an to $1 (to jump)paei sto false fix it*/
								/*normal*/
								tmp->currentquad = currQuad -3;
								backpatch(tmp, currQuad-2);	
								/*Delete apo thn false list gia na mhn to pathsei */
								Falsehead = DeleteIntList(currQuad-3, Falsehead);
								Truehead = CreateIntList(currQuad-4,Truehead);/*$4 if*/
								//free(tmp);
								tmp = NULL;										
								
								Truehead = CreateIntList(currQuad-2,Truehead);/*$1 if*/
								
								LogicFlag =1;
								fprintf(yyout,"expr ==>  expr or expr  \n");
							}
#line 1783 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 274 "parser.y" /* yacc.c:1646  */
    { /*initialize the expression's if and jump with the right labels*/
							  /*ifshit*/
							  insertQuad(if_eq,(yyvsp[-2].expression), (yyvsp[0].expression), NULL, currQuad+2,currQuad);
							  /*jump*/
							  insertQuad(jump,NULL,NULL,NULL, currQuad+1,currQuad);							 						
							  
							  LogicFlag =1;
							  Balls=1;
							  fprintf(yyout,"expr ==>  expr == expr  \n");							  
							}
#line 1798 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 284 "parser.y" /* yacc.c:1646  */
    { /*initialize the expression's if and jump with the right labels*/
							  /*ifshit*/
							  insertQuad(if_noteq,(yyvsp[-2].expression), (yyvsp[0].expression), NULL, currQuad+2,currQuad);
							  /*jump*/
							  insertQuad(jump,NULL,NULL,NULL, currQuad+1,currQuad);							 						
							  
							  Balls=1;
							  LogicFlag =1;
							  fprintf(yyout,"expr ==>  expr != expr  \n");
							}
#line 1813 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 294 "parser.y" /* yacc.c:1646  */
    { /*initialize the expression's if and jump with the right labels*/
							  /*ifshit*/
							  insertQuad(if_greater,(yyvsp[-2].expression), (yyvsp[0].expression), NULL, currQuad+2,currQuad);
							  /*jump*/
							  insertQuad(jump,NULL,NULL,NULL, currQuad+1,currQuad);							 						
							  
							  Balls=1;
							  LogicFlag =1;
							  fprintf(yyout,"expr ==>  expr > expr  \n");
							}
#line 1828 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 304 "parser.y" /* yacc.c:1646  */
    { /*initialize the expression's if and jump with the right labels*/
							  /*ifshit*/
							  insertQuad(if_less,(yyvsp[-2].expression), (yyvsp[0].expression), NULL, currQuad+2,currQuad);
							  /*jump*/
							  insertQuad(jump,NULL,NULL,NULL, currQuad+1,currQuad);							 						
							  
							  Balls=1;
							  LogicFlag =1;
							  fprintf(yyout,"expr ==>  expr < expr \n");
							}
#line 1843 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 314 "parser.y" /* yacc.c:1646  */
    {  	/*initialize the expression's if and jump with the right labels*/
										/*ifshit*/
										insertQuad(if_geatereq,(yyvsp[-2].expression), (yyvsp[0].expression), NULL, currQuad+2,currQuad);
										/*jump*/
										insertQuad(jump,NULL,NULL,NULL, currQuad+1,currQuad);							 						
										
										Balls=1;
										LogicFlag =1;
										fprintf(yyout,"expr ==> expr >= expr  \n");
									}
#line 1858 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 324 "parser.y" /* yacc.c:1646  */
    {   /*initialize the expression's if and jump with the right labels*/
										/*ifshit*/
										insertQuad(if_lesseq,(yyvsp[-2].expression), (yyvsp[0].expression), NULL, currQuad+2,currQuad);
										/*jump*/
										insertQuad(jump,NULL,NULL,NULL, currQuad+1,currQuad);							 						
										
										Balls=1;
										LogicFlag =1;
										fprintf(yyout,"expr ==> expr <= expr  \n");
									}
#line 1873 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 334 "parser.y" /* yacc.c:1646  */
    {
		
							(yyval.expression) = (yyvsp[0].expression);
							fprintf(yyout,"expr ==> term  \n");
						}
#line 1883 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 341 "parser.y" /* yacc.c:1646  */
    {
						if (!ArrayFlag){
							for (i=scope; i>-1; i--){
								if ( (Scope_NameTypeLookup(ScopeArray, i, yylval.strVal, USERFUNC) )
									||  (Scope_NameTypeLookup(ScopeArray, i, yylval.strVal, LIBFUNC)) )
								{
									printf("Error!!! In Line %d | Can not assign any value to %s\n",yylineno, yylval.strVal);
									ErrorFlag = 1;
									break;
								}
							}
						}
						ArrayFlag = 0;
						if ((yyvsp[0].expression)->type == tableitem_e){
							tmpquad[99] = quads+(currQuad-1);
							tmpquad[99]->op = tablesetelem;
						}
					}
#line 1906 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 359 "parser.y" /* yacc.c:1646  */
    {
							if (!LogicFlag)
								insertQuad(assign,(yyvsp[-3].expression), (yyvsp[0].expression),NULL,-1,currQuad);
								
							fprintf(yyout,"assignexpr ==> lvalue = expr \n");
						}
#line 1917 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 368 "parser.y" /* yacc.c:1646  */
    { (yyval.expression)=(yyvsp[-1].expression);
								fprintf(yyout,"term ==> (expr) \n");
							}
#line 1925 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 371 "parser.y" /* yacc.c:1646  */
    { (yyval.expression)=(yyvsp[0].expression); 
							  fprintf(yyout,"term ==> primary\n");
							}
#line 1933 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 374 "parser.y" /* yacc.c:1646  */
    {
									insertQuad(uminus,(yyvsp[0].expression),NULL, NULL, -1, currQuad);
									if ((yyvsp[0].expression)->type == tableitem_e){
										tmpquad[99] = quads+(currQuad-1);
										tmpquad[99]->op = tablesetelem;
									}
									fprintf(yyout,"term ==> -expr\n");
								}
#line 1946 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 382 "parser.y" /* yacc.c:1646  */
    {
								(yyval.expression)=(yyvsp[0].expression);
								
								insertQuad(add,(yyvsp[0].expression), (yyvsp[0].expression), ConstInt_exp(1),-1,currQuad);
								if ((yyvsp[0].expression)->type == tableitem_e){
									tmpquad[99] = quads+(currQuad-1);
									tmpquad[99]->op = tablesetelem;
								}
								
								for (i=scope; i>-1; i--){
								if ( (Scope_NameTypeLookup(ScopeArray, i, yylval.strVal, USERFUNC) )
									||  (Scope_NameTypeLookup(ScopeArray, i, yylval.strVal, LIBFUNC)) )
								{
									printf("Error!!! In Line %d | Can not assign any value to %s\n",yylineno, yylval.strVal);
									ErrorFlag = 1;
									break;
								}
							}
							fprintf(yyout,"term ==> ++lvalue\n");
						}
#line 1971 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 402 "parser.y" /* yacc.c:1646  */
    {
					for (i=scope; i>-1; i--){
						if ( (Scope_NameTypeLookup(ScopeArray, i, yylval.strVal, USERFUNC) )
							||  (Scope_NameTypeLookup(ScopeArray, i, yylval.strVal, LIBFUNC)) )
						{
							printf("Error!!! In Line %d | Can not assign any value to %s\n",yylineno, yylval.strVal);
							ErrorFlag = 1;
							break;
						}
					}
				 }
#line 1987 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 412 "parser.y" /* yacc.c:1646  */
    { 
							insertQuad(add,(yyvsp[-2].expression),(yyvsp[-2].expression),ConstInt_exp(1),-1,currQuad);
							if ((yyvsp[-2].expression)->type == tableitem_e){
									tmpquad[99] = quads+(currQuad-1);
									tmpquad[99]->op = tablesetelem;
							}
							
				 			fprintf(yyout,"term ==> lvalue++\n");
						 }
#line 2001 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 421 "parser.y" /* yacc.c:1646  */
    {
							(yyval.expression)=(yyvsp[0].expression);
							
							insertQuad(sub,(yyvsp[0].expression), (yyvsp[0].expression), ConstInt_exp(1),-1,currQuad);
							if ((yyvsp[0].expression)->type == tableitem_e){
									tmpquad[99] = quads+(currQuad-1);
									tmpquad[99]->op = tablesetelem;
								}
								
							for (i=scope; i>-1; i--){
								if ( (Scope_NameTypeLookup(ScopeArray, i, yylval.strVal, USERFUNC) )
									||  (Scope_NameTypeLookup(ScopeArray, i, yylval.strVal, LIBFUNC)) )
								{
									printf("Error!!! In Line %d | Can not assign any value to %s\n",yylineno, yylval.strVal);
									ErrorFlag = 1;
									break;
								}
							}						        
							fprintf(yyout,"term ==> --lvalue\n");
						}
#line 2026 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 441 "parser.y" /* yacc.c:1646  */
    {
					for (i=scope; i>-1; i--){
						if ( (Scope_NameTypeLookup(ScopeArray, i, yylval.strVal, USERFUNC) )
							||  (Scope_NameTypeLookup(ScopeArray, i, yylval.strVal, LIBFUNC)) )
						{
							printf("Error!!! In Line %d | Can not assign any value to %s\n",yylineno, yylval.strVal);
							ErrorFlag = 1;
							break;
						}
					}
				 }
#line 2042 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 451 "parser.y" /* yacc.c:1646  */
    { 
							(yyval.expression)=(yyvsp[-2].expression);
							
							insertQuad(sub,(yyvsp[-2].expression),(yyvsp[-2].expression),ConstInt_exp(1),-1,currQuad);
							if ((yyvsp[-2].expression)->type == tableitem_e){
									tmpquad[99] = quads+(currQuad-1);
									tmpquad[99]->op = tablesetelem;
							}
							
							fprintf(yyout,"term ==> lvalue--\n");
						  }
#line 2058 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 462 "parser.y" /* yacc.c:1646  */
    {
						//$$ = insertExpr(not,$2,NULL,currQuad,boolexpr_e);
						/*initialize the expression's if and jump with the right labels*/
						/*ifshit*/
						insertQuad(if_eq, (yyvsp[0].expression), ConstBool_exp(0), NULL, currQuad+2,currQuad);
						/*jump*/
						insertQuad(jump,NULL,NULL,NULL, currQuad+1,currQuad);							 						
							  
						LogicFlag =1;
						
						if ((yyvsp[0].expression)->type == tableitem_e){
									tmpquad[99] = quads+(currQuad-1);
									tmpquad[99]->op = tablesetelem;
						}
						
						fprintf(yyout,"term ==> !expr\n");
					}
#line 2080 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 482 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"primary ==>  lvalue\n");}
#line 2086 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 483 "parser.y" /* yacc.c:1646  */
    {
										(yyval.expression)=(yyvsp[0].expression);
										fprintf(yyout,"primary ==>  call\n");}
#line 2094 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 486 "parser.y" /* yacc.c:1646  */
    {
										(yyval.expression)=(yyvsp[0].expression);
										fprintf(yyout,"primary ==>  objectdef\n");}
#line 2102 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 489 "parser.y" /* yacc.c:1646  */
    {
														(yyval.expression)=(yyvsp[-1].expression);
														fprintf(yyout,"primary ==>  (funcdef)\n");}
#line 2110 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 492 "parser.y" /* yacc.c:1646  */
    { 
										(yyval.expression)=(yyvsp[0].expression);
										fprintf(yyout,"primary ==>  const\n");}
#line 2118 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 497 "parser.y" /* yacc.c:1646  */
    {
					 (yyval.expression)=ConstInt_exp(yylval.intVal);
					 fprintf(yyout,"const ==> number \n");}
#line 2126 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 500 "parser.y" /* yacc.c:1646  */
    {
					 (yyval.expression)=ConstDouble_exp(yylval.dbVal);
					 fprintf(yyout,"const ==> realnum\n");}
#line 2134 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 503 "parser.y" /* yacc.c:1646  */
    {
					 (yyval.expression)= ConstString_exp(yylval.strVal);
					 fprintf(yyout,"const ==> string\n");}
#line 2142 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 506 "parser.y" /* yacc.c:1646  */
    {
					 (yyval.expression)=ConstBool_exp(1);
					 fprintf(yyout,"const ==> true\n");}
#line 2150 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 509 "parser.y" /* yacc.c:1646  */
    {
					 (yyval.expression)=ConstBool_exp(0);
					 fprintf(yyout,"const ==> false\n");}
#line 2158 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 512 "parser.y" /* yacc.c:1646  */
    {
					 (yyval.expression)=ConstNil_exp();
					 fprintf(yyout,"const ==> nil\n");}
#line 2166 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 517 "parser.y" /* yacc.c:1646  */
    {
				fprintf(yyout,"lvalue ==> ID \n");
				
				for (i=scope; i>-1; i--){
					if ( TmpNode = Scope_NameLookup(ScopeArray, i, yytext) ){
						(yyval.expression)=lvalue_expr(TmpNode);
						if ( (i != 0) && (TmpNode->type != USERFUNC) && (TmpNode->type != LIBFUNC) ){
						/*if it not found in scope 0 and it is not a Function */ 
						
							if (FuncSearch(ScopeArray, i, scope-1) ){/*if there is a function between*/
								printf("Error!!! In Line %d | Can not access %s\n",yylineno, yylval.strVal);
								ErrorFlag = 1;
							}
						}
						break;
					}
				}
				/*if ID was not found*/
				if (i == -1){
					
					if (scope == 0){
						offset++;
						ScopeSpace=strdup("Programm Variables");
						(yyval.expression)=lvalue_expr(InsertToSymTable(oSymTable, ScopeArray, yytext, GLOBAL, scope, yylineno,offset,ScopeSpace,-1)); 
					}
					else{
						if (FunctionFlag>=0){
						    ScopeSpace=strdup("Function Local");
						    functionoffsets[FunctionFlag]++;
						    (yyval.expression)=lvalue_expr(InsertToSymTable(oSymTable, ScopeArray, yytext, LOKAL, scope, yylineno,functionoffsets[FunctionFlag],ScopeSpace,-1));
						}
						else{
						    offset++;
						    ScopeSpace=strdup("Programm Variables");
						    (yyval.expression)=lvalue_expr(InsertToSymTable(oSymTable, ScopeArray, yytext, LOKAL, scope, yylineno,offset,ScopeSpace,-1));
						}
					}
				}
			}
#line 2210 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 556 "parser.y" /* yacc.c:1646  */
    {
						fprintf(yyout,"lvalue ==> LOCAL ID \n");
						if( !(TmpNode=Scope_NameLookup(ScopeArray,scope,yytext)) ){
							
							if( Scope_NameTypeLookup(ScopeArray,0, yytext, LIBFUNC) ){
								printf("Error!!! In Line %d | %s Shadows a Library Function!\n",yylineno, yytext);
								ErrorFlag = 1;
							}
							else{
								
							
								if(scope==0){	//In Scope 0 Local var becomes global
									offset++;
									ScopeSpace=strdup("Programm Variables");
									(yyval.expression)=lvalue_expr(InsertToSymTable(oSymTable, ScopeArray, strdup(yytext), GLOBAL, scope, yylineno,offset,ScopeSpace,-1));
								}
								else{
								
									if (FunctionFlag>=0){
									    ScopeSpace=strdup("Function Local");
									    functionoffsets[FunctionFlag]++;									    
									    (yyval.expression)=lvalue_expr(InsertToSymTable(oSymTable, ScopeArray, yytext, LOKAL, scope, yylineno,functionoffsets[FunctionFlag],ScopeSpace,-1)); 
									}
									else{
									    offset++;
									    ScopeSpace=strdup("Programm Variables");
									    (yyval.expression)=lvalue_expr(InsertToSymTable(oSymTable, ScopeArray, yytext, LOKAL, scope, yylineno,offset,ScopeSpace,-1));
									}
								}
							}
						}
						else{
							(yyval.expression)=lvalue_expr(TmpNode);
						}
					}
#line 2250 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 591 "parser.y" /* yacc.c:1646  */
    {
						fprintf(yyout,"lvalue ==> DCOLON ID \n");
						if(!(TmpNode=Scope_NameLookup(ScopeArray,0, yytext)) ){
							(yyval.expression)=lvalue_expr(TmpNode);
							printf("Error!!! In Line %d |  There is no member on global scope with the name %s\n",yylineno, yylval.strVal);
							ErrorFlag = 1;
						}
					}
#line 2263 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 599 "parser.y" /* yacc.c:1646  */
    {
										(yyval.expression)=(yyvsp[0].expression);
										fprintf(yyout,"lvalue ==> member \n");}
#line 2271 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 604 "parser.y" /* yacc.c:1646  */
    {
							(yyval.expression) = insertExpr(tablegetelem, (yyvsp[-2].expression), ConstString_exp(yylval.strVal), currQuad, tableitem_e);
							fprintf(yyout,"member ==> lvalue.id \n");
						}
#line 2280 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 609 "parser.y" /* yacc.c:1646  */
    {
							ArrayFlag = 1;
							(yyval.expression) = insertExpr(tablegetelem, (yyvsp[-3].expression), (yyvsp[-1].expression), currQuad, tableitem_e);
							fprintf(yyout,"member ==> lvalue[expr] \n");
						}
#line 2290 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 614 "parser.y" /* yacc.c:1646  */
    {	//NOT TESTED
							(yyval.expression) = insertExpr(tablegetelem, (yyvsp[-2].expression), ConstString_exp(yylval.strVal), currQuad, tableitem_e);
							fprintf(yyout,"member ==> call().id) \n");
						}
#line 2299 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 618 "parser.y" /* yacc.c:1646  */
    {ArrayFlag = 1; fprintf(yyout,"member ==> call()[expr] \n");}
#line 2305 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 621 "parser.y" /* yacc.c:1646  */
    {
								  expr *parametr=(yyvsp[-1].expression);
								  while(parametr!=NULL){
									insertQuad(param, NULL,parametr,NULL, -1, currQuad);
									parametr=parametr->next;
								  }
								  expr* tmpexpr=lvalue_expr(InsertToSymTable(oSymTable,ScopeArray,GenerateTmpName(),GLOBAL,scope, yylineno,offset, "Programm Variables",-1));
								  insertQuad(call,(yyvsp[-3].expression),NULL,NULL,-1,currQuad);
								  insertQuad(getretval,tmpexpr,NULL,NULL,-1,currQuad);
								  (yyval.expression)=tmpexpr;
								  fprintf(yyout,"call ==> call(elist)\n");
								  }
#line 2322 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 633 "parser.y" /* yacc.c:1646  */
    {
						if (normCall){
							insertQuad(call,(yyvsp[-1].expression),NULL,NULL,-1,currQuad);	
						}
						else{
							tmpquad[99] = quads+currQuad-(paramCounter+1);
							tmpquad[99]->arg1 = (yyvsp[-1].expression);
							insertQuad(param, NULL, (yyvsp[-1].expression), NULL, -1, currQuad);
							insertQuad(call,tmpCall,NULL,NULL,-1,currQuad);
						}
						tmpCall=lvalue_expr(InsertToSymTable(oSymTable,ScopeArray,GenerateTmpName(),GLOBAL,scope, yylineno,offset, "Programm Variables",-1));
						insertQuad(getretval,tmpCall,NULL,NULL,-1,currQuad);
						(yyval.expression)=tmpCall;
					  fprintf(yyout,"call ==> lvalue callsuffix\n");
					  }
#line 2342 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 648 "parser.y" /* yacc.c:1646  */
    {
												expr *parametr=(yyvsp[-1].expression);
												while(parametr!=NULL){
												      insertQuad(param, NULL,parametr,NULL, -1, currQuad);
												      parametr=parametr->next;
												}
												insertQuad(call,(yyvsp[-4].expression),NULL,NULL,-1,currQuad);
												insertQuad(getretval,lvalue_expr(InsertToSymTable(oSymTable,ScopeArray,GenerateTmpName(),GLOBAL,scope, yylineno,offset, "Programm Variables",-1)),NULL,NULL,-1,currQuad);
												fprintf(yyout,"call ==> (funcdef)(elist)\n");
												}
#line 2357 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 660 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"callsuffix ==> normcall\n");}
#line 2363 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 661 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"callsuffix ==> methodcall \n");}
#line 2369 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 664 "parser.y" /* yacc.c:1646  */
    {
							  expr *parametr=(yyvsp[-1].expression);
							  while(parametr!=NULL){
								insertQuad(param, NULL,parametr,NULL, -1, currQuad);
								parametr=parametr->next;
							  }
							  normCall = 1;
							  fprintf(yyout,"normalcall ==> (elist)\n");
							  }
#line 2383 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 675 "parser.y" /* yacc.c:1646  */
    {
						tmpCall = insertExpr(tablegetelem, NULL, ConstString_exp(yylval.strVal), currQuad, tableitem_e);
					  }
#line 2391 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 678 "parser.y" /* yacc.c:1646  */
    {
										
										expr *parametr=(yyvsp[-1].expression);
										paramCounter=0;
										while(parametr!=NULL){
											insertQuad(param, NULL,parametr,NULL, -1, currQuad);
											parametr=parametr->next;
											paramCounter++;
										}
										normCall = 0;
										fprintf(yyout,"methodcall ==> ..id (elist)\n");
									   }
#line 2408 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 692 "parser.y" /* yacc.c:1646  */
    {
			  (yyval.expression)=(yyvsp[-1].expression);
			  (yyval.expression)->next=(yyvsp[0].expression);
			  fprintf(yyout,"elist ==> expr cexprs\n");
			  }
#line 2418 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 697 "parser.y" /* yacc.c:1646  */
    {
				  (yyval.expression)=NULL;
				  fprintf(yyout,"elist ==> empty \n");
				  }
#line 2427 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 703 "parser.y" /* yacc.c:1646  */
    {
			      (yyval.expression)=(yyvsp[-1].expression);
			      (yyval.expression)->next=(yyvsp[0].expression);
			      fprintf(yyout,"cexprs ==> COMMA expr exprs \n");
			      }
#line 2437 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 708 "parser.y" /* yacc.c:1646  */
    {
				    (yyval.expression)=NULL;
				    fprintf(yyout,"elist ==> empty \n");
				    }
#line 2446 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 715 "parser.y" /* yacc.c:1646  */
    {
														(yyval.expression)=insert_tableelist((yyvsp[-1].expression),currQuad);
														fprintf(yyout,"objectdef ==> [elist]\n");
													}
#line 2455 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 719 "parser.y" /* yacc.c:1646  */
    {
														(yyval.expression) = (yyvsp[-1].expression);
														fprintf(yyout,"objectdef ==> [indexed]\n");
													}
#line 2464 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 725 "parser.y" /* yacc.c:1646  */
    {
											(yyval.expression)=(yyvsp[-1].expression);
											fprintf(yyout,"indexed ==> indexedelem clindexedelem\n");}
#line 2472 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 730 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"clindexedelem ==> ,indexedelem *\n");}
#line 2478 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 731 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"clindexedelem ==> empty\n");}
#line 2484 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 734 "parser.y" /* yacc.c:1646  */
    {
																		(yyval.expression)=(yyvsp[-1].expression);
																		fprintf(yyout,"indexedelem ==> [expr : expr]\n");}
#line 2492 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 739 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"block ==> {}\n");}
#line 2498 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 740 "parser.y" /* yacc.c:1646  */
    {scope++;}
#line 2504 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 740 "parser.y" /* yacc.c:1646  */
    {	
																			(yyval.expression)=(yyvsp[-2].expression);
																			fprintf(yyout,"block ==> [stmt*]\n");
																			/*Hide the symbols of this scope*/
																			Scope_Hide(scope, ScopeArray);
																			scope--; 
																		 }
#line 2516 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 749 "parser.y" /* yacc.c:1646  */
    {				
						FunctionFlag++;
						functionNames[FunctionFlag]=strdup(GenerateTmpName());
						InsertToSymTable(oSymTable, ScopeArray,functionNames[FunctionFlag], USERFUNC, scope, yylineno,-1,NULL,currQuad);
						insertQuad(funcstart, ConstString_exp(functionNames[FunctionFlag]), NULL, NULL, -1, currQuad);
						
				   }
#line 2528 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 756 "parser.y" /* yacc.c:1646  */
    {
									scope++;
					    		 }
#line 2536 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 758 "parser.y" /* yacc.c:1646  */
    {
														scope--; 
														Argoffset=0;
														 }
#line 2545 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 763 "parser.y" /* yacc.c:1646  */
    {	 
													      (yyval.expression)=ConstString_exp(functionNames[FunctionFlag]);
													      insertQuad(funcend, ConstString_exp(functionNames[FunctionFlag]), NULL, NULL, -1, currQuad);
													      setFuncVarNum(ScopeArray,functionoffsets[FunctionFlag], functionNames[FunctionFlag], scope);
													      functionoffsets[FunctionFlag]=0;
													      FunctionFlag--;
												   	      fprintf(yyout,"funcdef ==> FUNCTION (idlist) {}\n");
												   	    }
#line 2558 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 771 "parser.y" /* yacc.c:1646  */
    {  
						TmpNode = Scope_NameLookup(ScopeArray, scope, yytext);
				
						/*function exists in same scope*/
						if ( TmpNode ){
							printf("Error!!! In Line %d | Redeclaration of %s.\n",yylineno, TmpNode->name);
							ErrorFlag = 1;
							
						}/*shadowing of library function*/ 
						else if (Scope_NameTypeLookup(ScopeArray,0, yytext, LIBFUNC)){
							printf("Error!!! In Line %d |  %s Shadows a Library Function!\n",yylineno,yytext);
							ErrorFlag = 1;
							
						}/*al iz vel just insert*/
						else{
							InsertToSymTable(oSymTable, ScopeArray, yytext, USERFUNC, scope, yylineno,-1,NULL,currQuad);
							FunctionFlag++;
							functionNames[FunctionFlag]=strdup(yytext);
							insertQuad(funcstart, ConstString_exp(functionNames[FunctionFlag]), NULL, NULL, -1, currQuad);
							
						}
					 }
#line 2585 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 794 "parser.y" /* yacc.c:1646  */
    {scope++;}
#line 2591 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 794 "parser.y" /* yacc.c:1646  */
    {scope--; Argoffset=0;}
#line 2597 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 796 "parser.y" /* yacc.c:1646  */
    {
														  (yyval.expression)=ConstString_exp(functionNames[FunctionFlag]);
														  insertQuad(funcend, ConstString_exp(functionNames[FunctionFlag]), NULL, NULL, -1, currQuad);
														  setFuncVarNum(ScopeArray,functionoffsets[FunctionFlag], functionNames[FunctionFlag], scope);																  
														  functionoffsets[FunctionFlag]=0; 
														  FunctionFlag--;
														  fprintf(yyout,"funcdef ==> FUNCTION ID (idlist) {}\n");
														}
#line 2610 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 806 "parser.y" /* yacc.c:1646  */
    {	
				if (FunctionFlag>=0)
				      InsertArgToFunction (oSymTable, ScopeArray, ScopeArray[scope-1] , yytext);
				
				
				if ( TmpNode = Scope_NameLookup(ScopeArray, scope, yytext) ){/*if it already exists*/
					printf("Error!!!In Line %d |  Formal redefinition of %s !\n",yylineno, yylval.strVal);
					ErrorFlag = 1;
				}
				else if (Scope_NameTypeLookup(ScopeArray,0, yytext, LIBFUNC) ){/*if it shadows a lib function*/
					printf("Error!!!In Line %d |  Formal; %s Shadows a Library Function!\n",yylineno, yylval.strVal);
					ErrorFlag = 1;
				}
				else{/*insert*/
					ScopeSpace = strdup("Formal Argument");
					InsertToSymTable(oSymTable, ScopeArray, yytext, FORMAL, scope, yylineno, Argoffset, ScopeSpace,-1); 
					Argoffset++;
				}

				 }
#line 2635 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 825 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"idlist ==> ID cidlist\n");}
#line 2641 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 826 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"idlist ==> empty\n");}
#line 2647 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 829 "parser.y" /* yacc.c:1646  */
    {
						
						if (FunctionFlag>=0)  InsertArgToFunction (oSymTable, ScopeArray, ScopeArray[scope-1] , yytext);
								
						if ( TmpNode = Scope_NameLookup(ScopeArray, scope, yytext) ){/*if it already exists*/
							printf("Error!!!In Line %d |  Formal redefinition of %s !\n",yylineno, yylval.strVal);
							ErrorFlag = 1;
						}
						else if (Scope_NameTypeLookup(ScopeArray,0, yytext, LIBFUNC) ){/*if it shadows a lib function*/
							printf("Error!!!In Line %d |  Formal %s Shadows a Library Function!\n",yylineno, yylval.strVal);
							ErrorFlag = 1;
						}
						else{/*insert*/
							ScopeSpace = strdup("Formal Argument");
							InsertToSymTable(oSymTable, ScopeArray, yytext, FORMAL, scope, yylineno, Argoffset, ScopeSpace,-1); 
							Argoffset++; 
						}
						
		     	  }
#line 2671 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 847 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"cidlist ==> , ID cidlist\n");}
#line 2677 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 848 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"cidlist ==> empty\n");}
#line 2683 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 851 "parser.y" /* yacc.c:1646  */
    {
			fprintf(yyout,"ifstmt ==> if (expr) stmt\n");
			tmpquad[--Qindex]->label=currQuad;
			}
#line 2692 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 855 "parser.y" /* yacc.c:1646  */
    {
			    tmpquad[--Qindex]->label=currQuad+1;
			    tmpquad[Qindex++] = insertQuad(jump,NULL,NULL,NULL,-1,currQuad);
			   }
#line 2701 "parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 858 "parser.y" /* yacc.c:1646  */
    {
				  fprintf(yyout,"ifstmt ==> if (expr) stmt else stmt\n");
				  tmpquad[--Qindex]->label=currQuad;
				}
#line 2710 "parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 864 "parser.y" /* yacc.c:1646  */
    {
							LogicFlag = 1;
							}
#line 2718 "parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 866 "parser.y" /* yacc.c:1646  */
    {
														if (!Balls){
															/*initialize the expression's if and jump with the right labels*/
															/*ifshit*/
															insertQuad(if_eq,(yyvsp[-1].expression), ConstBool_exp(1), NULL, currQuad+2,currQuad);
															/*jump*/
															insertQuad(jump,NULL,NULL,NULL, currQuad+1,currQuad);	
														}
														
														backpatch(Truehead, currQuad);
														backpatch(Falsehead, currQuad+2);
														/*fix last JUMP*/
														tmpquad[98] = quads+currQuad-1;
														tmpquad[98]->label = currQuad+2;
														/*Threeway*/
														(yyvsp[-1].expression) = insertExpr(assign, ConstBool_exp(1), NULL, currQuad, boolexpr_e);
														insertQuad(jump,NULL,NULL,NULL,currQuad+2,currQuad);								
														insertQuad(assign, (yyvsp[-1].expression), ConstBool_exp(0), NULL, -1, boolexpr_e);
														
														LogicFlag = 0;
														Balls=0;
														
														insertQuad(if_eq,NULL,(yyvsp[-1].expression),ConstBool_exp(1), currQuad+2, currQuad);
														tmpquad[Qindex++] = insertQuad(jump,NULL,NULL,NULL,-1,currQuad);
												}
#line 2748 "parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 894 "parser.y" /* yacc.c:1646  */
    {loopstart[loopindex++]=currQuad;
					LogicFlag = 1;
					}
#line 2756 "parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 898 "parser.y" /* yacc.c:1646  */
    {
									if (!Balls){
															/*initialize the expression's if and jump with the right labels*/
															/*ifshit*/
															insertQuad(if_eq,(yyvsp[-1].expression), ConstBool_exp(1), NULL, currQuad+2,currQuad);
															/*jump*/
															insertQuad(jump,NULL,NULL,NULL, currQuad+1,currQuad);	
									}
								 
									backpatch(Truehead, currQuad);
									backpatch(Falsehead, currQuad+2);
									/*fix last JUMP*/
									tmpquad[98] = quads+currQuad-1;
									tmpquad[98]->label = currQuad+2;
									/*Threeway*/
									(yyvsp[-1].expression) = insertExpr(assign, ConstBool_exp(1), NULL, currQuad, boolexpr_e);
									insertQuad(jump,NULL,NULL,NULL,currQuad+2,currQuad);								
									insertQuad(assign, (yyvsp[-1].expression), ConstBool_exp(0), NULL, -1, boolexpr_e);
								
									LogicFlag = 0;
									Balls=0;
								 		 
									insertQuad(if_eq,NULL,(yyvsp[-1].expression),ConstBool_exp(1), currQuad+2, currQuad);
									tmpquad[Qindex++]=insertQuad(jump,NULL,NULL,NULL,-1,currQuad);							      
							     }
#line 2786 "parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 923 "parser.y" /* yacc.c:1646  */
    {
										insertQuad(jump,NULL,NULL,NULL,loopstart[--loopindex],currQuad);
										tmpquad[--Qindex]->label=currQuad;
										backpatch(BreakHead, currQuad);
										backpatch(ContinueHead, loopstart[loopindex]);
										BreakHead=CreateIntList(-666,BreakHead);
										ContinueHead=CreateIntList(-666,ContinueHead);
										
										(yyval.expression) = (yyvsp[-3].expression);
										fprintf(yyout,"whilestmt ==> while (expr) stmt\n");
								    }
#line 2802 "parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 936 "parser.y" /* yacc.c:1646  */
    {  LogicFlag = 1;
												forstart=currQuad; }
#line 2809 "parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 939 "parser.y" /* yacc.c:1646  */
    {
									
										if (!Balls){
															/*initialize the expression's if and jump with the right labels*/
															/*ifshit*/
															insertQuad(if_eq,(yyvsp[-1].expression), ConstBool_exp(1), NULL, currQuad+2,currQuad);
															/*jump*/
															insertQuad(jump,NULL,NULL,NULL, currQuad+1,currQuad);	
										}
								
										backpatch(Truehead, currQuad);
										backpatch(Falsehead, currQuad+2);
										
										/*fix last JUMP*/
										tmpquad[98] = quads+currQuad-1;
										tmpquad[98]->label = currQuad+2;
										/*Threeway*/
										(yyvsp[-1].expression) = insertExpr(assign, ConstBool_exp(1), NULL, currQuad, boolexpr_e);
										insertQuad(jump,NULL,NULL,NULL,currQuad+2,currQuad);																			
										insertQuad(assign, (yyvsp[-1].expression), ConstBool_exp(0), NULL, -1, boolexpr_e);
								
										LogicFlag = 0;
										Balls=0;
										fortmpquad=insertQuad(if_eq,NULL,(yyvsp[-1].expression),ConstBool_exp(1), -1, currQuad); 
										tmpquad[Qindex++]=insertQuad(jump,NULL,NULL,NULL,-1,currQuad);
										loopstart[loopindex++]=currQuad;
									}
#line 2841 "parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 966 "parser.y" /* yacc.c:1646  */
    {insertQuad(jump,NULL,NULL,NULL,forstart,currQuad);
											 fortmpquad->label=currQuad;
											}
#line 2849 "parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 969 "parser.y" /* yacc.c:1646  */
    {
											  insertQuad(jump,NULL,NULL,NULL,loopstart[--loopindex],currQuad);
											  tmpquad[--Qindex]->label=currQuad;
											  backpatch(BreakHead, currQuad);
											  backpatch(ContinueHead, loopstart[loopindex]);
											  BreakHead=CreateIntList(-666,BreakHead);
											  ContinueHead=CreateIntList(-666,ContinueHead);
											  
											  (yyval.expression) = (yyvsp[-6].expression);
											  fprintf(yyout,"forstmt ==> for(elist; expr; elist) stmt\n");
											}
#line 2865 "parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 982 "parser.y" /* yacc.c:1646  */
    { 
										insertQuad(ret,(yyvsp[-1].expression),NULL,NULL,-1,currQuad);
										fprintf(yyout,"returnstmt ==> return expr ;\n");
									}
#line 2874 "parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 986 "parser.y" /* yacc.c:1646  */
    {
								insertQuad(ret,NULL,NULL,NULL,-1,currQuad);
								fprintf(yyout,"returnstmt ==> return ;\n");
							  }
#line 2883 "parser.c" /* yacc.c:1646  */
    break;


#line 2887 "parser.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 992 "parser.y" /* yacc.c:1906  */


int yyerror (char* yaccProvidedMessage)
{
	fprintf(stderr, "%s: at line %d, before token: '%s'\n", yaccProvidedMessage, yylineno, yytext);
}

int main(int argc, char** argv)
{

	if (argc == 3){
		if( !(yyin = fopen(argv[1], "r")) ) {
			fprintf(stderr, "Cannot Open File: %s\n", argv[1]);
			yyin = stdin;
		}
		if(!(yyout = fopen(argv[2], "w")) )
		{
			fprintf(stderr, "Cannot Open File: %s\n", argv[2]);
			yyout = stdout;
		}
	}
	else if (argc == 2){
		if( !(yyin = fopen(argv[1], "r")) ) {
			fprintf(stderr, "Cannot Open File: %s\n", argv[1]);
			yyin = stdin;
		}
	}
	else{
		fprintf(stderr, "WTF...Give mama some arguments ;P \n");
		return 0;
	}
	
	/*memory allocation of sym table*/
	oSymTable = SymTable_new();
	/*init the library functions*/
	InsertToSymTable(oSymTable, ScopeArray,"print", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"input", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"objectmemberkeys", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"objecttotalmembers", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"objectcopy", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"totalarguments", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"argument", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"typeof", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"stronum", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"sqrt", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"cos", LIBFUNC , 0, 0,-1,NULL,-1);
	InsertToSymTable(oSymTable, ScopeArray,"sin", LIBFUNC , 0, 0,-1,NULL,-1);
	
	yyparse();
	
	printf("\n\nActives of Symbol Table!!\n");
	
	SymTable_Print(oSymTable);
	
	//printf("\n\nEverything of All ScopeLists!!\n");
	
	//PrintAllScopes(ScopeArray);
	
	printf("\n\n\n\n\n");
	
	if(!ErrorFlag)
	    PrintQuads();
	return 0;
}
