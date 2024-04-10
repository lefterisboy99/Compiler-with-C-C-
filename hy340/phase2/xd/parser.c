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

	#include "Symtable.h"
	
	int yyerror (char* yaccProvidedMessage);
	int yylex (void);
	
	extern int yylineno;
	extern char * yyval;
	extern char * yytext;
	extern FILE * yyin;
	extern FILE * yyout;
	int scope=0, i=0, FunctionFlag = 0, ArrayFlag = 0;
	char dflt_name[3] = "$_ "; //default func name 
	
	SymTable_T *oSymTable;
	SymbolNode *ScopeArray[SCOPE_MAX], *TmpNode;

#line 84 "parser.c" /* yacc.c:339  */

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
#line 103 "parser.y" /* yacc.c:355  */

	char* strVal;
	int intVal;
	double dbVal;

#line 240 "parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 255 "parser.c" /* yacc.c:358  */

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
#define YYFINAL  69
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   543

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

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
       0,   111,   111,   114,   115,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     147,   147,   165,   166,   167,   168,   179,   179,   189,   200,
     200,   210,   214,   215,   216,   217,   218,   221,   222,   223,
     224,   225,   226,   229,   251,   267,   273,   276,   277,   278,
     279,   282,   283,   284,   287,   288,   291,   294,   297,   298,
     301,   302,   306,   307,   310,   313,   314,   317,   320,   321,
     321,   329,   333,   333,   329,   336,   350,   350,   336,   354,
     354,   368,   371,   371,   386,   389,   390,   393,   396,   399,
     400
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
  "callsuffix", "normcall", "methodcall", "elist", "cexprs", "objectdef",
  "indexed", "clindexedelem", "indexedelem", "block", "$@4", "funcdef",
  "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "idlist", "$@11", "cidlist",
  "$@12", "ifstmt", "whilestmt", "forstmt", "returnstmt", YY_NULLPTR
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

#define YYPACT_NINF -132

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-132)))

#define YYTABLE_NINF -40

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-40)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     142,   -31,    -3,     1,    10,   213,    17,    19,    16,  -132,
    -132,  -132,   248,   248,    -9,    -9,  -132,  -132,  -132,  -132,
      23,    83,   178,  -132,    28,    63,  -132,   142,   308,  -132,
    -132,  -132,  -132,     8,  -132,     7,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,   248,   248,   248,  -132,    24,  -132,   324,
    -132,  -132,  -132,  -132,  -132,    58,   -35,     7,   -35,  -132,
     142,   248,   292,    40,    46,    44,   356,    45,  -132,  -132,
    -132,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,  -132,   248,   248,    54,    55,    74,
      67,    72,  -132,  -132,  -132,   248,   248,    66,   379,   402,
      59,    65,  -132,  -132,    71,   142,   275,   248,  -132,  -132,
    -132,    70,  -132,  -132,    68,    -1,    -1,    -8,    -8,  -132,
    -132,  -132,   499,   499,   512,   512,   512,   512,   425,    73,
    -132,    80,   248,  -132,  -132,   446,    81,  -132,   142,   142,
     248,  -132,    79,    68,    89,   248,   292,    44,   248,  -132,
    -132,   248,   486,  -132,  -132,   125,  -132,   340,    79,  -132,
      90,  -132,   467,  -132,  -132,    91,    92,   142,   248,    93,
      87,  -132,  -132,  -132,  -132,  -132,    95,  -132,   103,  -132,
     102,   142,   102,  -132,  -132,  -132,  -132,    87,  -132
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,    81,     0,     0,     0,     0,    50,
      51,    52,     0,     0,     0,     0,    47,    48,    53,    49,
      79,    69,     0,    14,     0,     0,     2,     4,     0,    15,
      29,    33,    46,    42,    56,    43,    44,    12,    13,     6,
       7,     8,     9,     0,     0,    69,    85,     0,   100,     0,
      10,    11,    54,    41,    34,     0,    35,     0,    38,    78,
       0,     0,    71,     0,     0,    76,     0,     0,    55,     1,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     0,    69,     0,     0,     0,
       0,     0,    62,    64,    65,     0,    69,     0,     0,     0,
       0,     0,    82,    99,     0,     4,     0,     0,    68,    72,
      73,     0,    74,    32,    45,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     0,     0,
      57,     0,     0,    37,    40,     0,     0,    59,     0,     0,
       0,    86,    91,     0,     0,     0,    71,    76,    69,    58,
      66,    69,    31,    60,    61,    95,    97,     0,    91,    89,
       0,    80,     0,    70,    75,     0,     0,     0,    69,     0,
      94,    83,    77,    63,    67,    96,     0,    87,     0,    90,
       0,     0,     0,    92,    84,    98,    88,    94,    93
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,   -21,   -56,    -5,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,    18,  -132,    43,  -132,  -132,  -132,   -44,    -7,
    -132,  -132,    -6,    31,  -131,  -132,   -12,  -132,  -132,  -132,
    -132,  -132,  -132,   -14,  -132,   -29,  -132,  -132,  -132,  -132,
    -132
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,    29,    89,    30,    90,    91,
      31,    32,    33,    34,    35,    92,    93,    94,    63,   108,
      36,    64,   112,    65,    37,    60,    38,    47,   142,   180,
     101,   158,   182,   160,   170,   179,   187,    39,    40,    41,
      42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,   100,     8,    85,   105,    86,    70,    53,    54,    43,
      67,    87,    88,    75,    76,    77,    62,    66,    73,    74,
      75,    76,    77,    78,    79,    18,   -30,    80,    81,    82,
      83,    55,    56,    58,   -36,   -39,    24,    44,    98,    99,
      62,    45,   129,   104,    46,    95,    85,    96,    86,   184,
      52,   186,   136,    97,    87,    88,   106,    57,    57,    50,
      59,    51,    68,    69,   102,     4,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   109,
     128,    62,   155,   156,   144,   110,   114,   111,   130,   131,
     135,    62,   132,   133,     8,     9,    10,    11,    12,   134,
     137,   140,   146,    13,   165,   141,    61,   166,   148,    14,
      15,   175,   143,   159,   150,    16,    17,    18,    19,    61,
     151,    21,   154,    22,   176,   185,   161,   152,    24,   167,
     178,   171,   173,   174,   177,   157,   181,   183,    20,   163,
     162,   164,   147,    62,   169,     1,    62,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,   188,     0,
       0,     0,    13,    62,     0,     0,     0,     0,    14,    15,
       0,     0,     0,     0,    16,    17,    18,    19,    20,     0,
      21,     0,    22,     0,    23,     4,     0,    24,     0,     8,
       9,    10,    11,    12,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,    14,    15,     0,     0,     0,     0,
      16,    17,    18,    19,     0,     0,    21,     0,    22,     0,
       0,     0,     0,    24,     8,     9,    10,    11,    12,     0,
       0,     0,     0,    13,     0,     0,     0,     0,     0,    14,
      15,     0,     0,     0,     0,    16,    17,    18,    19,     0,
       0,    21,     0,    22,     0,    48,     0,     0,    24,     8,
       9,    10,    11,    12,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,    14,    15,     0,     0,     0,     0,
      16,    17,    18,    19,     0,     0,    21,     0,    22,     0,
       0,    71,    72,    24,    73,    74,    75,    76,    77,    78,
      79,     0,     0,    80,    81,    82,    83,     0,    71,    72,
       0,    73,    74,    75,    76,    77,    78,    79,     0,   145,
      80,    81,    82,    83,    71,    72,     0,    73,    74,    75,
      76,    77,    78,    79,     0,   107,    80,    81,    82,    83,
      71,    72,     0,    73,    74,    75,    76,    77,    78,    79,
      84,     0,    80,    81,    82,    83,    71,    72,     0,    73,
      74,    75,    76,    77,    78,    79,   103,     0,    80,    81,
      82,    83,    71,    72,     0,    73,    74,    75,    76,    77,
      78,    79,   168,     0,    80,    81,    82,    83,     0,     0,
       0,     0,     0,     0,     0,    71,    72,   113,    73,    74,
      75,    76,    77,    78,    79,     0,     0,    80,    81,    82,
      83,     0,     0,     0,     0,     0,     0,     0,    71,    72,
     138,    73,    74,    75,    76,    77,    78,    79,     0,     0,
      80,    81,    82,    83,     0,     0,     0,     0,     0,     0,
       0,    71,    72,   139,    73,    74,    75,    76,    77,    78,
      79,     0,     0,    80,    81,    82,    83,     0,     0,     0,
       0,     0,    71,    72,   149,    73,    74,    75,    76,    77,
      78,    79,     0,     0,    80,    81,    82,    83,     0,     0,
       0,     0,     0,    71,    72,   153,    73,    74,    75,    76,
      77,    78,    79,     0,     0,    80,    81,    82,    83,     0,
       0,     0,    71,    72,   172,    73,    74,    75,    76,    77,
      78,    79,     0,     0,    80,    81,    82,    83,    73,    74,
      75,    76,    77,   -40,   -40,     0,     0,    80,    81,    82,
      83,    73,    74,    75,    76,    77,     0,     0,     0,     0,
     -40,   -40,   -40,   -40
};

static const yytype_int16 yycheck[] =
{
       5,    45,    11,    38,    60,    40,    27,    12,    13,    40,
      22,    46,    47,    21,    22,    23,    21,    22,    19,    20,
      21,    22,    23,    24,    25,    34,    18,    28,    29,    30,
      31,    40,    14,    15,    26,    27,    45,    40,    43,    44,
      45,    40,    86,    55,    34,    38,    38,    40,    40,   180,
      34,   182,    96,    46,    46,    47,    61,    14,    15,    42,
      37,    42,    34,     0,    40,     7,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    39,
      85,    86,   138,   139,   105,    39,    41,    43,    34,    34,
      95,    96,    18,    26,    11,    12,    13,    14,    15,    27,
      34,    42,   107,    20,   148,    40,    36,   151,    40,    26,
      27,   167,    41,    34,    41,    32,    33,    34,    35,    36,
      40,    38,    41,    40,   168,   181,    37,   132,    45,     4,
      43,    41,    41,    41,    41,   140,    41,    34,    36,   146,
     145,   147,   111,   148,   158,     3,   151,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,   187,    -1,
      -1,    -1,    20,   168,    -1,    -1,    -1,    -1,    26,    27,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,
      38,    -1,    40,    -1,    42,     7,    -1,    45,    -1,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    -1,    -1,    38,    -1,    40,    -1,
      -1,    -1,    -1,    45,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    -1,
      -1,    38,    -1,    40,    -1,    42,    -1,    -1,    45,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    -1,    -1,    38,    -1,    40,    -1,
      -1,    16,    17,    45,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    28,    29,    30,    31,    -1,    16,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    -1,    44,
      28,    29,    30,    31,    16,    17,    -1,    19,    20,    21,
      22,    23,    24,    25,    -1,    43,    28,    29,    30,    31,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      42,    -1,    28,    29,    30,    31,    16,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    42,    -1,    28,    29,
      30,    31,    16,    17,    -1,    19,    20,    21,    22,    23,
      24,    25,    42,    -1,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    41,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      41,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    17,    41,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    16,    17,    39,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,    16,    17,    39,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    28,    29,    30,    31,    -1,
      -1,    -1,    16,    17,    37,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    28,    29,    30,    31,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    28,    29,    30,
      31,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    20,    26,    27,    32,    33,    34,    35,
      36,    38,    40,    42,    45,    57,    58,    59,    60,    61,
      63,    66,    67,    68,    69,    70,    76,    80,    82,    93,
      94,    95,    96,    40,    40,    40,    34,    83,    42,    60,
      42,    42,    34,    60,    60,    40,    68,    70,    68,    37,
      81,    36,    60,    74,    77,    79,    60,    82,    34,     0,
      58,    16,    17,    19,    20,    21,    22,    23,    24,    25,
      28,    29,    30,    31,    42,    38,    40,    46,    47,    62,
      64,    65,    71,    72,    73,    38,    40,    46,    60,    60,
      74,    86,    40,    42,    82,    59,    60,    43,    75,    39,
      39,    43,    78,    41,    41,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    74,
      34,    34,    18,    26,    27,    60,    74,    34,    41,    41,
      42,    40,    84,    41,    58,    44,    60,    79,    40,    39,
      41,    40,    60,    39,    41,    59,    59,    60,    87,    34,
      89,    37,    60,    75,    78,    74,    74,     4,    42,    89,
      90,    41,    37,    41,    41,    59,    74,    41,    43,    91,
      85,    41,    88,    34,    80,    59,    80,    92,    91
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
      69,    70,    70,    70,    71,    71,    72,    73,    74,    74,
      75,    75,    76,    76,    77,    78,    78,    79,    80,    81,
      80,    83,    84,    85,    82,    86,    87,    88,    82,    90,
      89,    89,    92,    91,    91,    93,    93,    94,    95,    96,
      96
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
       4,     4,     2,     6,     1,     1,     3,     5,     2,     0,
       3,     0,     3,     3,     2,     3,     0,     5,     2,     0,
       5,     0,     0,     0,     8,     0,     0,     0,     9,     0,
       3,     0,     0,     4,     0,     5,     7,     5,     9,     3,
       2
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
#line 111 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout," program ==> statements \n");}
#line 1544 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 114 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"statements ==> stmt statements\n");}
#line 1550 "parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 115 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"statements ==> empty \n");}
#line 1556 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 118 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"stmt ==> expr; \n");}
#line 1562 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 119 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"stmt ==> ifstmt \n");}
#line 1568 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 120 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"stmt ==> whilestmt  \n");}
#line 1574 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 121 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"stmt ==> forstmt \n");}
#line 1580 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 122 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"stmt ==> returnstmt \n");}
#line 1586 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 123 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"stmt ==> break; \n");}
#line 1592 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 124 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"stmt ==> continue; \n");}
#line 1598 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 125 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"stmt ==> block \n");}
#line 1604 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 126 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"stmt ==> funcdef \n");}
#line 1610 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 127 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"stmt ==> ; \n");}
#line 1616 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 130 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"expr ==> assignexpr  \n");}
#line 1622 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 131 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"expr ==>  expr and expr  \n");}
#line 1628 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 132 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"expr ==>  expr or expr  \n");}
#line 1634 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 133 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"expr ==>  expr + expr  \n");}
#line 1640 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 134 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"expr ==>  expr - expr  \n");}
#line 1646 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 135 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"expr ==>  expr * expr  \n");}
#line 1652 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 136 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"expr ==>  expr div expr  \n");}
#line 1658 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 137 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"expr ==>  expr mod expr  \n");}
#line 1664 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 138 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"expr ==>  expr == expr  \n");}
#line 1670 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 139 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"expr ==>  expr != expr  \n");}
#line 1676 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 140 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"expr ==>  expr > expr  \n");}
#line 1682 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 141 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"expr ==>  expr < expr \n");}
#line 1688 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 142 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"expr ==> expr >= expr  \n");}
#line 1694 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 143 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"expr ==> expr <= expr  \n");}
#line 1700 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 144 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"expr ==> term  \n");}
#line 1706 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 147 "parser.y" /* yacc.c:1646  */
    {
				printf("%s is here",yylval.strVal);
						if (!ArrayFlag){
							for (i=scope; i>-1; i--){
								if ( (Scope_NameTypeLookup(ScopeArray, i, scope, yylval.strVal, USERFUNC) )
									||  (Scope_NameTypeLookup(ScopeArray, i, scope, yylval.strVal, LIBFUNC)) )
								{
									printf("Error!!! In Line %d | Can not assign any value to %s\n",yylineno, yylval.strVal);
									break;
								}
							}
						}
						ArrayFlag = 0;
					}
#line 1725 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 161 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"assignexpr ==> lvalue = expr \n");}
#line 1731 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 165 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"term ==> (expr) \n");}
#line 1737 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 166 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"term ==> primary\n");}
#line 1743 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 167 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"term ==> -expr\n");}
#line 1749 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 168 "parser.y" /* yacc.c:1646  */
    {
							for (i=scope; i>-1; i--){
								if ( (Scope_NameTypeLookup(ScopeArray, i, scope, yylval.strVal, USERFUNC) )
									||  (Scope_NameTypeLookup(ScopeArray, i, scope, yylval.strVal, LIBFUNC)) )
								{
									printf("Error!!! In Line %d | Can not assign any value to %s\n",yylineno, yylval.strVal);
									break;
								}
							}
							fprintf(yyout,"term ==> ++lvalue\n");
						}
#line 1765 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 179 "parser.y" /* yacc.c:1646  */
    {
					for (i=scope; i>-1; i--){
						if ( (Scope_NameTypeLookup(ScopeArray, i, scope, yylval.strVal, USERFUNC) )
							||  (Scope_NameTypeLookup(ScopeArray, i, scope, yylval.strVal, LIBFUNC)) )
						{
							printf("Error!!! In Line %d | Can not assign any value to %s\n",yylineno, yylval.strVal);
							break;
						}
					}
				 }
#line 1780 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 188 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"term ==> lvalue++\n");}
#line 1786 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 189 "parser.y" /* yacc.c:1646  */
    {
							for (i=scope; i>-1; i--){
								if ( (Scope_NameTypeLookup(ScopeArray, i, scope, yylval.strVal, USERFUNC) )
									||  (Scope_NameTypeLookup(ScopeArray, i, scope, yylval.strVal, LIBFUNC)) )
								{
									printf("Error!!! In Line %d | Can not assign any value to %s\n",yylineno, yylval.strVal);
									break;
								}
							}
							fprintf(yyout,"term ==> --lvalue\n");
						}
#line 1802 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 200 "parser.y" /* yacc.c:1646  */
    {
					for (i=scope; i>-1; i--){
						if ( (Scope_NameTypeLookup(ScopeArray, i, scope, yylval.strVal, USERFUNC) )
							||  (Scope_NameTypeLookup(ScopeArray, i, scope, yylval.strVal, LIBFUNC)) )
						{
							printf("Error!!! In Line %d | Can not assign any value to %s\n",yylineno, yylval.strVal);
							break;
						}
					}
				 }
#line 1817 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 209 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"term ==> lvalue--\n");}
#line 1823 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 210 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"term ==> !expr\n");}
#line 1829 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 214 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"primary ==>  lvalue\n");}
#line 1835 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 215 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"primary ==>  call\n");}
#line 1841 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 216 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"primary ==>  objectdef\n");}
#line 1847 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 217 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"primary ==>  (funcdef)\n");}
#line 1853 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 218 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"primary ==>  const\n");}
#line 1859 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 221 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"const ==> number \n");}
#line 1865 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 222 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"const ==> realnum\n");}
#line 1871 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 223 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"const ==> string\n");}
#line 1877 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 224 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"const ==> true\n");}
#line 1883 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 225 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"const ==> false\n");}
#line 1889 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 226 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"const ==> nil\n");}
#line 1895 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 229 "parser.y" /* yacc.c:1646  */
    {
				fprintf(yyout,"lvalue ==> ID \n");
				
				for (i=scope; i>-1; i--){
					if ( TmpNode = Scope_NameLookup(ScopeArray, i, yytext) ){
						if ( (i != 0) && (TmpNode->type != USERFUNC) && (TmpNode->type != LIBFUNC) ){
						/*if it not found in scope 0 and it is not a Function */ 
						
							if (FuncSearch(ScopeArray, i, scope-1) )/*if there is a function between*/
								printf("Error!!! In Line %d | Can not access %s\n",yylineno, yylval.strVal);
						}
						break;
					}
				}
				/*if ID was not found*/
				if (i == -1){
					if (scope == 0)
						InsertToSymTable(oSymTable, ScopeArray, yytext, GLOBAL, scope, yylineno); 
					else
						InsertToSymTable(oSymTable, ScopeArray, yytext, LOKAL, scope, yylineno); 
				}
			}
#line 1922 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 251 "parser.y" /* yacc.c:1646  */
    {
						fprintf(yyout,"lvalue ==> LOCAL ID \n");
						if( Scope_NameTypeLookup(ScopeArray,0, 0, yytext, LIBFUNC) ){
							printf("Error!!! In Line %d | %s Shadows a Library Function!\n",yylineno, yytext);
						}
						else if( Scope_NameLookup(ScopeArray,scope,yytext) == NULL){
							/*don't insert into symtable if local id exists in scope*/
						}
						else{
						
							if(scope==0)	//In Scope 0 Local var becomes global
								InsertToSymTable(oSymTable, ScopeArray, strdup(yytext), GLOBAL, scope, yylineno);
							else
								InsertToSymTable(oSymTable, ScopeArray, strdup(yytext), LOKAL, scope, yylineno);
						}
					}
#line 1943 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 267 "parser.y" /* yacc.c:1646  */
    {
						fprintf(yyout,"lvalue ==> DCOLON ID \n");
						if(Scope_NameLookup(ScopeArray,0, yytext)== NULL){
							printf("Error!!! In Line %d |  There is no member on global scope with the name %s\n",yylineno, yylval.strVal);
						}
					}
#line 1954 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 273 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"lvalue ==> member \n");}
#line 1960 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 276 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"member ==> lvalue.id \n");}
#line 1966 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 277 "parser.y" /* yacc.c:1646  */
    {ArrayFlag = 1; fprintf(yyout,"member ==> lvalue[expr] \n");}
#line 1972 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 278 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"member ==> call().id) \n");}
#line 1978 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 279 "parser.y" /* yacc.c:1646  */
    {ArrayFlag = 1; fprintf(yyout,"member ==> call()[expr] \n");}
#line 1984 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 282 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"call ==> call(elist)\n");}
#line 1990 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 283 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"call ==> lvalue callsuffix\n");}
#line 1996 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 284 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"call ==> (funcdef)(elist)\n");}
#line 2002 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 287 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"callsuffix ==> normcall\n");}
#line 2008 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 288 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"callsuffix ==> methodcall \n");}
#line 2014 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 291 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"normalcall ==> (elist)\n");}
#line 2020 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 294 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"methodcall ==> ..id (elist)\n");}
#line 2026 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 297 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"elist ==> expr cexprs\n");}
#line 2032 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 298 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"elist ==> empty \n");}
#line 2038 "parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 301 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"cexprs ==> COMMA expr exprs \n");}
#line 2044 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 302 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"elist ==> empty \n");}
#line 2050 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 306 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"objectdef ==> [elist]\n");}
#line 2056 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 307 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"objectdef ==> [indexed]\n");}
#line 2062 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 310 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"indexed ==> indexedelem clindexedelem\n");}
#line 2068 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 313 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"clindexedelem ==> ,indexedelem *\n");}
#line 2074 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 314 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"clindexedelem ==> empty\n");}
#line 2080 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 317 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"indexedelem ==> [expr : expr]\n");}
#line 2086 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 320 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"block ==> {}\n");}
#line 2092 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 321 "parser.y" /* yacc.c:1646  */
    {scope++;}
#line 2098 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 321 "parser.y" /* yacc.c:1646  */
    {	
																			fprintf(yyout,"block ==> [stmt*]\n");
																			/*Hide the symbols of this scope*/
																			Scope_Hide(scope, ScopeArray);
																			scope--; 
																		 }
#line 2109 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 329 "parser.y" /* yacc.c:1646  */
    {
						FunctionFlag++;
						InsertToSymTable(oSymTable, ScopeArray, dflt_name, USERFUNC, scope, yylineno);
						dflt_name[2] ++;
				   }
#line 2119 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 333 "parser.y" /* yacc.c:1646  */
    {scope++;}
#line 2125 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 333 "parser.y" /* yacc.c:1646  */
    {scope--; }
#line 2131 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 333 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"funcdef ==> FUNCTION (idlist) {}\n");
																						FunctionFlag--;}
#line 2138 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 336 "parser.y" /* yacc.c:1646  */
    {  TmpNode = Scope_NameLookup(ScopeArray, scope, yytext);
						FunctionFlag++;
						/*function exists in same scope*/
						if ( TmpNode ){
							printf("Error!!! In Line %d | Redeclaration of %s.\n",yylineno, TmpNode->name);
						}/*shadowing of library function*/ 
						else if (Scope_NameTypeLookup(ScopeArray, 0, 0,yytext, LIBFUNC)){
							printf("Error!!! In Line %d |  %s Shadows a Library Function!\n",yylineno,yytext);
						}/*al iz vel just insert*/
						else{
							InsertToSymTable(oSymTable, ScopeArray, yytext, USERFUNC, scope, yylineno);
						}
					 }
#line 2156 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 350 "parser.y" /* yacc.c:1646  */
    {scope++;}
#line 2162 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 350 "parser.y" /* yacc.c:1646  */
    {scope--;}
#line 2168 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 350 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"funcdef ==> FUNCTION ID (idlist) {}\n");
																						 FunctionFlag--;}
#line 2175 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 354 "parser.y" /* yacc.c:1646  */
    {	
				if (FunctionFlag>0)  InsertArgToFunction (oSymTable, ScopeArray, ScopeArray[scope-1] , yytext);
					
				if ( TmpNode = Scope_NameLookup(ScopeArray, scope, yytext) ){/*if it already exists*/
					printf("Error!!!In Line %d |  Formal redefinition of %s !\n",yylineno, yylval.strVal);
				}
				else if (Scope_NameTypeLookup(ScopeArray,0, 0, yytext, LIBFUNC) ){/*if it shadows a lib function*/
					printf("Error!!!In Line %d |  Formal; %s Shadows a Library Function!\n",yylineno, yylval.strVal);
				}
				else{/*insert*/
					InsertToSymTable(oSymTable, ScopeArray, yytext, FORMAL, scope, yylineno); 
				}

				 }
#line 2194 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 367 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"idlist ==> ID cidlist\n");}
#line 2200 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 368 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"idlist ==> empty\n");}
#line 2206 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 371 "parser.y" /* yacc.c:1646  */
    {
						
						if (FunctionFlag>0)  InsertArgToFunction (oSymTable, ScopeArray, ScopeArray[scope-1] , yytext);
								
						if ( TmpNode = Scope_NameLookup(ScopeArray, scope, yytext) ){/*if it already exists*/
							printf("Error!!!In Line %d |  Formal redefinition of %s !\n",yylineno, yylval.strVal);
						}
						else if (Scope_NameTypeLookup(ScopeArray, 0, 0, yytext, LIBFUNC) ){/*if it shadows a lib function*/
							printf("Error!!!In Line %d |  Formal %s Shadows a Library Function!\n",yylineno, yylval.strVal);
						}
						else{/*insert*/
							InsertToSymTable(oSymTable, ScopeArray, yytext, FORMAL, scope, yylineno); 
						}
						
		     	  }
#line 2226 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 385 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"cidlist ==> , ID cidlist\n");}
#line 2232 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 386 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"cidlist ==> empty\n");}
#line 2238 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 389 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"ifstmt ==> if (expr) stmt\n");}
#line 2244 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 390 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"ifstmt ==> if (expr) stmt else stmt\n");}
#line 2250 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 393 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"whilestmt ==> while (expr) stmt\n");}
#line 2256 "parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 396 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"forstmt ==> for(elist; expr; elist) stmt\n");}
#line 2262 "parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 399 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"returnstmt ==> return expr ;\n");}
#line 2268 "parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 400 "parser.y" /* yacc.c:1646  */
    {fprintf(yyout,"returnstmt ==> return ;\n");}
#line 2274 "parser.c" /* yacc.c:1646  */
    break;


#line 2278 "parser.c" /* yacc.c:1646  */
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
#line 403 "parser.y" /* yacc.c:1906  */


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
	InsertToSymTable(oSymTable, ScopeArray,"print", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"input", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"objectmemberkeys", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"objecttotalmembers", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"objectcopy", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"totalarguments", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"argument", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"typeof", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"stronum", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"sqrt", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"cos", LIBFUNC , 0, 0);
	InsertToSymTable(oSymTable, ScopeArray,"sin", LIBFUNC , 0, 0);
	
	yyparse();
	
	printf("\n\nActives of Symbol Table!!\n");
	SymTable_Print(oSymTable);
	printf("\n\nEverything of All ScopeLists!!\n");
	PrintAllScopes(ScopeArray);
	
	return 0;
}

