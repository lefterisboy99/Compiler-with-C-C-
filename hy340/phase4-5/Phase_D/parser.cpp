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
#line 1 "grammar.y" /* yacc.c:339  */

    #include "manage_g_action.h"
    #include "vm_def.h"

    void yyerror (char const *s);
    int yylex(void);

    unsigned short int scope = 0;

    extern FILE* yyin;
    extern char yytext[];
    extern int yylineno;

    vector <bool> isBlock;
    
    vector <string> str_statements = { "if" , "else", "while" , "for" , "funcdef" , "block"  };
    vector <string> statement_stack;

    int is_func_rule = 0; //an o kanonas poy ekteleitai einai funcution definition
    unsigned int anon_func = 0; //metraei poses anonimes synarthseis yparxoyn
    int is_member_call = 0;

    vector <ioquad_t> quads;//quad table
    vector <unsigned int> functionLocalStack;

    vector <vector<unsigned long int>> break_list;
    vector <vector<unsigned long int>> cont_list;

    // vector <vector<unsigned long int>> func_ret_list;

    extern void generate();
    extern void print_instructions();
    extern void create_binary();
    extern void print_instructions();
    extern void set_srcLines();

    extern void read_binary();

    extern vector <double> numConsts;
    extern vector <string> strConsts;
    extern vector <string> libFunctions;
    extern vector <userfunc_t> userFuncs;
    extern vector <instruction_t> instructions_table;

    int ultrex = 0;

#line 113 "parser.cpp" /* yacc.c:339  */

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
# define YYDEBUG 1
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
    AND = 266,
    NOT = 267,
    OR = 268,
    LOCAL = 269,
    TRUE = 270,
    FALSE = 271,
    NIL = 272,
    EQ = 273,
    NE = 274,
    LT = 275,
    GT = 276,
    GE = 277,
    LE = 278,
    PLUSPLUS = 279,
    MINUSMINUS = 280,
    COLONCOLON = 281,
    DOTDOT = 282,
    SINGLE_LINE_COMMENT = 283,
    NESTED_COMMENT = 284,
    ID = 285,
    STRING = 286,
    INTEGER = 287,
    REAL = 288,
    number = 289,
    UMINUS = 290
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
#define AND 266
#define NOT 267
#define OR 268
#define LOCAL 269
#define TRUE 270
#define FALSE 271
#define NIL 272
#define EQ 273
#define NE 274
#define LT 275
#define GT 276
#define GE 277
#define LE 278
#define PLUSPLUS 279
#define MINUSMINUS 280
#define COLONCOLON 281
#define DOTDOT 282
#define SINGLE_LINE_COMMENT 283
#define NESTED_COMMENT 284
#define ID 285
#define STRING 286
#define INTEGER 287
#define REAL 288
#define number 289
#define UMINUS 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 47 "grammar.y" /* yacc.c:355  */

    unsigned long unsigned_label;
    unsigned int locals_size;
    char *strVal;
    double realVal;
    struct expr *exprNode;
    struct node *symbol;
    struct type_of_call *typeOfCall;
    struct forNode *forNode;

#line 234 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 249 "parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   552

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    23,     2,     2,
      36,    37,    21,    19,    39,    20,    41,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    38,
       2,    18,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
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
      15,    16,    17,    24,    25,    26,    27,    28,    29,    30,
      31,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   103,   103,   106,   111,   115,   116,   117,   120,   122,
     125,   133,   139,   140,   141,   144,   146,   153,   160,   167,
     173,   179,   182,   185,   188,   191,   194,   197,   200,   203,
     206,   209,   211,   220,   226,   241,   258,   274,   290,   293,
     312,   313,   314,   316,   319,   324,   325,   326,   327,   330,
     333,   341,   342,   345,   349,   367,   374,   377,   382,   396,
     415,   422,   425,   431,   431,   447,   460,   468,   480,   480,
     491,   491,   500,   511,   516,   539,   539,   539,   548,   557,
     580,   586,   592,   597,   602,   607,   614,   615,   616,   621,
     621,   631,   638,   644,   644,   654,   677,   688,   697,   699,
     701,   701,   716,   716,   736,   743
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "FOR", "FUNCTION",
  "RETURN", "BREAK", "CONTINUE", "AND", "NOT", "OR", "LOCAL", "TRUE",
  "FALSE", "NIL", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "EQ", "NE",
  "LT", "GT", "GE", "LE", "PLUSPLUS", "MINUSMINUS", "'{'", "'}'", "'['",
  "']'", "'('", "')'", "';'", "','", "':'", "'.'", "COLONCOLON", "DOTDOT",
  "SINGLE_LINE_COMMENT", "NESTED_COMMENT", "ID", "STRING", "INTEGER",
  "REAL", "number", "UMINUS", "$accept", "program", "stmts", "stmt",
  "expr", "D", "term", "assignexpr", "primary", "lvalue", "member", "call",
  "callsuffix", "normcall", "methodcall", "elist", "objectdef", "$@1",
  "indexed", "indexedelem", "$@2", "block", "$@3", "funcname",
  "funcprefix", "funcargs", "$@4", "$@5", "funcbody", "funcdef", "const",
  "idlist", "ifprefix", "$@6", "elseprefix", "ifstmt", "$@7", "whilestmt",
  "whilestart", "whilecond", "N", "M", "forprefix", "$@8", "forstmt",
  "$@9", "returnstmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    61,    43,
      45,    42,    47,    37,   273,   274,   275,   276,   277,   278,
     279,   280,   123,   125,    91,    93,    40,    41,    59,    44,
      58,    46,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290
};
# endif

#define YYPACT_NINF -163

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-163)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -163,     4,   114,  -163,  -163,  -163,  -163,   -35,   186,   -25,
     -22,   224,     3,  -163,  -163,  -163,   224,    52,    52,  -163,
      57,   163,  -163,    38,  -163,  -163,  -163,  -163,  -163,   278,
    -163,  -163,  -163,   388,  -163,   -29,  -163,  -163,    49,  -163,
    -163,   114,  -163,  -163,    55,  -163,  -163,  -163,    60,    68,
    -163,  -163,  -163,   298,  -163,  -163,  -163,  -163,  -163,   102,
     -26,   -29,   -26,  -163,  -163,   224,     7,  -163,   338,    74,
    -163,  -163,  -163,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,  -163,   224,  -163,  -163,   224,   224,
      67,    70,  -163,  -163,  -163,   224,   224,    72,  -163,    80,
     121,   224,   114,   224,   224,   224,  -163,    90,    21,   224,
     471,     8,  -163,    57,  -163,    96,   224,   224,    -1,    -1,
    -163,  -163,  -163,   501,   501,   523,   523,   523,   523,   471,
     414,    11,  -163,    97,   433,    19,  -163,    91,  -163,  -163,
    -163,   114,   357,  -163,    53,   376,     6,    96,  -163,   256,
    -163,   224,  -163,   224,   512,   490,  -163,  -163,   224,  -163,
    -163,  -163,    58,  -163,  -163,  -163,  -163,  -163,   224,   471,
      66,    71,  -163,    92,  -163,   114,   224,   452,  -163,  -163,
    -163,  -163,  -163,   318,  -163,  -163,  -163,  -163
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,    89,    96,   100,    73,     0,     0,
       0,     0,     0,    83,    84,    82,     0,     0,     0,    70,
      63,     0,    14,     0,    45,    81,    80,    85,     3,     0,
      29,    15,    38,    40,    48,    41,    42,    12,     0,    13,
      44,     0,     6,     7,     0,    98,     8,     9,     0,     0,
      72,    74,   105,     0,    10,    11,    33,    46,    32,     0,
      34,     0,    36,     4,    68,    62,     0,    66,     0,     0,
      47,    30,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     0,    35,    37,     0,    62,
       0,     0,    54,    56,    57,     0,    62,     0,    75,     0,
      92,     0,     0,    62,     0,    62,   104,     0,     0,     0,
      60,     0,    65,     0,    31,    43,     0,     0,    16,    17,
      18,    19,    20,    25,    26,    23,    21,    22,    24,    39,
       0,     0,    49,     0,     0,     0,    51,    88,    78,    79,
      91,     0,     0,    95,     0,     0,     0,     0,    71,     0,
      64,     0,    67,    62,    28,    27,    50,    58,    62,    52,
      53,    86,     0,    93,    97,    98,    90,    99,     0,    61,
       0,     0,    76,     0,    94,     0,     0,     0,    55,    59,
      77,    87,   102,     0,    69,    98,   101,   103
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,    73,   -40,    -2,    69,  -163,  -163,  -163,    43,
    -163,    47,  -163,  -163,  -163,   -71,  -163,  -163,  -163,    27,
    -163,    44,  -163,  -163,  -163,  -163,  -163,  -163,  -163,   -19,
    -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,
    -162,  -163,  -163,  -163,  -163,  -163,  -163
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    28,   110,   116,    30,    31,    32,    33,
      34,    35,    92,    93,    94,   111,    36,    65,    66,    67,
     109,    37,    63,    51,    38,    99,   137,   180,   139,    39,
      40,   162,    41,    48,   141,    42,   174,    43,    44,   102,
     103,   176,    45,    49,    46,   185,    47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,   100,    69,   175,     3,    95,    53,    96,    88,    56,
      89,    50,    97,    54,    58,    90,    55,    91,   131,    68,
      75,    76,    77,   187,     4,   135,     5,     6,     7,     8,
       9,    10,   144,    11,   146,    12,    13,    14,    15,    29,
     107,    16,   112,   150,   167,   151,   113,   151,   157,    57,
     151,    17,    18,    19,   148,    20,   160,    21,   151,    22,
      60,    62,   143,    23,    61,    61,    12,    24,    25,    26,
      27,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   170,   129,    70,    98,   130,   171,    59,    64,
     165,   101,   151,   134,    23,   172,   104,   173,    24,   142,
      29,   163,   145,   178,   105,   151,    29,   149,   179,     7,
     151,   115,    19,   132,   154,   155,   133,     4,   136,     5,
       6,     7,     8,     9,    10,   140,    11,   147,    12,    13,
      14,    15,   153,   158,    16,   182,   108,   161,   181,    29,
     152,   117,     0,   138,    17,    18,    19,     0,    20,   169,
      21,     0,    22,     0,     0,     0,    23,     0,     0,     0,
      24,    25,    26,    27,     0,     0,   177,     0,     0,     0,
       7,     0,     0,    29,   183,    11,     0,    12,    13,    14,
      15,     0,     0,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    18,     0,     0,    20,    11,    21,
      12,    13,    14,    15,     0,    23,    16,     0,     0,    24,
      25,    26,    27,     0,     0,     0,    17,    18,     0,     0,
      20,     0,    21,     0,    52,     0,     0,     0,    23,     0,
       0,     0,    24,    25,    26,    27,    11,     0,    12,    13,
      14,    15,     0,     0,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,     0,     0,    20,     0,
      21,     0,     0,     0,     0,     0,    23,    71,     0,    72,
      24,    25,    26,    27,     0,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,     0,     0,     0,    71,
       0,    72,     0,     0,     0,     0,   168,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,     0,    71,
       0,    72,     0,     0,     0,     0,    84,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,     0,    71,
       0,    72,     0,     0,     0,     0,   106,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,     0,    71,
       0,    72,     0,     0,     0,     0,   186,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    71,     0,
      72,     0,     0,     0,     0,   114,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    71,     0,    72,
       0,     0,     0,     0,   164,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    85,     0,     0,     0,
       0,     0,     0,   166,     0,     0,     0,     0,    86,    87,
       0,     0,    88,     0,    89,    71,     0,    72,     0,    90,
       0,    91,     0,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    71,     0,    72,     0,     0,   156,
       0,     0,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    71,     0,    72,     0,     0,   159,     0,
       0,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    71,     0,    72,   184,     0,     0,     0,     0,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    71,     0,     0,     0,     0,     0,     0,     0,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      73,    74,    75,    76,    77,    -1,    -1,    80,    81,    82,
      83,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    73,    74,    75,    76,    77,     0,     0,    -1,
      -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
       2,    41,    21,   165,     0,    34,     8,    36,    34,    11,
      36,    46,    41,    38,    16,    41,    38,    43,    89,    21,
      21,    22,    23,   185,     3,    96,     5,     6,     7,     8,
       9,    10,   103,    12,   105,    14,    15,    16,    17,    41,
      59,    20,    35,    35,    38,    39,    39,    39,    37,    46,
      39,    30,    31,    32,    33,    34,    37,    36,    39,    38,
      17,    18,   102,    42,    17,    18,    14,    46,    47,    48,
      49,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,   153,    85,    46,    36,    88,   158,    36,    32,
      37,    36,    39,    95,    42,    37,    36,    39,    46,   101,
     102,   141,   104,    37,    36,    39,   108,   109,    37,     7,
      39,    37,    32,    46,   116,   117,    46,     3,    46,     5,
       6,     7,     8,     9,    10,     4,    12,    37,    14,    15,
      16,    17,    36,    36,    20,   175,    63,    46,    46,   141,
     113,    72,    -1,    99,    30,    31,    32,    -1,    34,   151,
      36,    -1,    38,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    -1,    -1,   168,    -1,    -1,    -1,
       7,    -1,    -1,   175,   176,    12,    -1,    14,    15,    16,
      17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    34,    12,    36,
      14,    15,    16,    17,    -1,    42,    20,    -1,    -1,    46,
      47,    48,    49,    -1,    -1,    -1,    30,    31,    -1,    -1,
      34,    -1,    36,    -1,    38,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    46,    47,    48,    49,    12,    -1,    14,    15,
      16,    17,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    34,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    42,    11,    -1,    13,
      46,    47,    48,    49,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    11,
      -1,    13,    -1,    -1,    -1,    -1,    40,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    11,
      -1,    13,    -1,    -1,    -1,    -1,    38,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    11,
      -1,    13,    -1,    -1,    -1,    -1,    38,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    11,
      -1,    13,    -1,    -1,    -1,    -1,    38,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    11,    -1,
      13,    -1,    -1,    -1,    -1,    37,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    11,    -1,    13,
      -1,    -1,    -1,    -1,    37,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    34,    -1,    36,    11,    -1,    13,    -1,    41,
      -1,    43,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    11,    -1,    13,    -1,    -1,    35,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    11,    -1,    13,    -1,    -1,    35,    -1,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    11,    -1,    13,    33,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    19,    20,    21,    22,    23,    -1,    -1,    26,
      27,    28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,    54,     0,     3,     5,     6,     7,     8,     9,
      10,    12,    14,    15,    16,    17,    20,    30,    31,    32,
      34,    36,    38,    42,    46,    47,    48,    49,    55,    56,
      58,    59,    60,    61,    62,    63,    68,    73,    76,    81,
      82,    84,    87,    89,    90,    94,    96,    98,    85,    95,
      46,    75,    38,    56,    38,    38,    56,    46,    56,    36,
      61,    63,    61,    74,    32,    69,    70,    71,    56,    81,
      46,    11,    13,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    38,    18,    30,    31,    34,    36,
      41,    43,    64,    65,    66,    34,    36,    41,    36,    77,
      55,    36,    91,    92,    36,    36,    38,    81,    54,    72,
      56,    67,    35,    39,    37,    37,    57,    57,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    67,    46,    46,    56,    67,    46,    78,    73,    80,
       4,    86,    56,    55,    67,    56,    67,    37,    33,    56,
      35,    39,    71,    36,    56,    56,    35,    37,    36,    35,
      37,    46,    83,    55,    37,    37,    37,    38,    40,    56,
      67,    67,    37,    39,    88,    92,    93,    56,    37,    37,
      79,    46,    55,    56,    33,    97,    38,    92
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    59,
      60,    60,    60,    60,    60,    61,    61,    61,    61,    62,
      62,    62,    62,    63,    63,    63,    64,    64,    65,    66,
      67,    67,    67,    69,    68,    68,    70,    70,    72,    71,
      74,    73,    75,    75,    76,    78,    79,    77,    80,    81,
      82,    82,    82,    82,    82,    82,    83,    83,    83,    85,
      84,    86,    87,    88,    87,    89,    90,    91,    92,    93,
      95,    94,    97,    96,    98,    98
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     4,     1,
       0,     3,     2,     2,     2,     2,     2,     2,     1,     3,
       1,     1,     1,     3,     1,     1,     2,     2,     1,     3,
       4,     3,     4,     4,     2,     6,     1,     1,     3,     5,
       1,     3,     0,     0,     4,     3,     1,     3,     0,     6,
       0,     4,     1,     0,     2,     0,     0,     5,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     0,     0,
       5,     1,     2,     0,     5,     3,     1,     3,     0,     0,
       0,     8,     0,     8,     3,     2
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
        case 3:
#line 106 "grammar.y" /* yacc.c:1646  */
    { 
    if( ultrex == 0 )
        resetTmpVarNameC();
    
}
#line 1541 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 115 "grammar.y" /* yacc.c:1646  */
    { (yyval.exprNode) = (yyvsp[-1].exprNode);}
#line 1547 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 116 "grammar.y" /* yacc.c:1646  */
    {}
#line 1553 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 117 "grammar.y" /* yacc.c:1646  */
    {break_list.pop_back();
                cont_list.pop_back();
        }
#line 1561 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 120 "grammar.y" /* yacc.c:1646  */
    {break_list.pop_back();
                cont_list.pop_back();}
#line 1568 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 122 "grammar.y" /* yacc.c:1646  */
    {
            is_correct_return();
        }
#line 1576 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 126 "grammar.y" /* yacc.c:1646  */
    {  
            
            is_correct_break_continue("break");
            break_list[break_list.size()-1].push_back( quads.size() );
            emit(JUMP_B , NULL, NULL, NULL , 0, yylineno);

        }
#line 1588 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 134 "grammar.y" /* yacc.c:1646  */
    { 
            is_correct_break_continue("continue");
            cont_list[cont_list.size()-1].push_back( quads.size() );
            emit(JUMP_C , NULL, NULL, NULL , 0, yylineno);
        }
#line 1598 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 139 "grammar.y" /* yacc.c:1646  */
    {}
#line 1604 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 140 "grammar.y" /* yacc.c:1646  */
    {}
#line 1610 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 141 "grammar.y" /* yacc.c:1646  */
    {}
#line 1616 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 144 "grammar.y" /* yacc.c:1646  */
    { (yyval.exprNode) = (yyvsp[0].exprNode);}
#line 1622 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 146 "grammar.y" /* yacc.c:1646  */
    { 
        if ( !is_op_applicable((yyvsp[-2].exprNode)) || !is_op_applicable((yyvsp[0].exprNode)) )
            cout << "Illegal expr + expr on line: " << yylineno << endl; 
        
        (yyval.exprNode) = emit_op(ADD, (yyvsp[-2].exprNode) , (yyvsp[0].exprNode), 0 , yylineno); 
    }
#line 1633 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 153 "grammar.y" /* yacc.c:1646  */
    { 
        if ( !is_op_applicable((yyvsp[-2].exprNode)) || !is_op_applicable((yyvsp[0].exprNode)) )
            cout << "Illegal expr - expr on line: " << yylineno << endl; 

        (yyval.exprNode) = emit_op(SUB, (yyvsp[-2].exprNode) , (yyvsp[0].exprNode), 0 , yylineno);
    }
#line 1644 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 160 "grammar.y" /* yacc.c:1646  */
    { 
        if ( !is_op_applicable((yyvsp[-2].exprNode)) || !is_op_applicable((yyvsp[0].exprNode)) )
            cout << "Illegal expr * expr on line: " << yylineno << endl; 
            
        (yyval.exprNode) = emit_op(MUL, (yyvsp[-2].exprNode) , (yyvsp[0].exprNode), 0 , yylineno);     
    }
#line 1655 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 167 "grammar.y" /* yacc.c:1646  */
    { 
        if ( !is_op_applicable((yyvsp[-2].exprNode)) || !is_op_applicable((yyvsp[0].exprNode)) )
            cout << "Illegal expr / expr on line: " << yylineno << endl; 

        (yyval.exprNode) = emit_op(DIV, (yyvsp[-2].exprNode) , (yyvsp[0].exprNode), 0 , yylineno); 
    }
#line 1666 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 173 "grammar.y" /* yacc.c:1646  */
    { 
        if ( !is_op_applicable((yyvsp[-2].exprNode)) || !is_op_applicable((yyvsp[0].exprNode)) )
            cout << "Illegal expr \% expr on line: " << yylineno << endl; 

        (yyval.exprNode) = emit_op(MOD, (yyvsp[-2].exprNode) , (yyvsp[0].exprNode), 0 , yylineno); 
    }
#line 1677 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 179 "grammar.y" /* yacc.c:1646  */
    {
        (yyval.exprNode) = emit_relop(IF_GREATER ,(yyvsp[-2].exprNode) , (yyvsp[0].exprNode), 0 , yylineno);
    }
#line 1685 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 182 "grammar.y" /* yacc.c:1646  */
    {
        (yyval.exprNode) = emit_relop(IF_GREATEREQ ,(yyvsp[-2].exprNode) , (yyvsp[0].exprNode), 0 , yylineno);
    }
#line 1693 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 185 "grammar.y" /* yacc.c:1646  */
    {
        (yyval.exprNode) = emit_relop(IF_LESS ,(yyvsp[-2].exprNode) , (yyvsp[0].exprNode), 0 , yylineno);
    }
#line 1701 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 188 "grammar.y" /* yacc.c:1646  */
    {
        (yyval.exprNode) = emit_relop(IF_LESSEQ ,(yyvsp[-2].exprNode) , (yyvsp[0].exprNode), 0 , yylineno);
    }
#line 1709 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 191 "grammar.y" /* yacc.c:1646  */
    {
        (yyval.exprNode) = emit_relop(IF_EQ ,(yyvsp[-2].exprNode) , (yyvsp[0].exprNode), 0 , yylineno);
    }
#line 1717 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 194 "grammar.y" /* yacc.c:1646  */
    {
        (yyval.exprNode) = emit_relop(IF_NOTEQ ,(yyvsp[-2].exprNode) , (yyvsp[0].exprNode), 0 , yylineno);
    }
#line 1725 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 197 "grammar.y" /* yacc.c:1646  */
    {
        (yyval.exprNode) = emit_boolop(IO_OR ,(yyvsp[-3].exprNode) , (yyvsp[0].exprNode), 0 , yylineno);
    }
#line 1733 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 200 "grammar.y" /* yacc.c:1646  */
    {
        (yyval.exprNode) = emit_boolop(IO_AND ,(yyvsp[-3].exprNode) , (yyvsp[0].exprNode), 0 , yylineno);
    }
#line 1741 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 203 "grammar.y" /* yacc.c:1646  */
    {(yyval.exprNode) = (yyvsp[0].exprNode);}
#line 1747 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 206 "grammar.y" /* yacc.c:1646  */
    { (yyval.unsigned_label) = quads.size(); }
#line 1753 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 209 "grammar.y" /* yacc.c:1646  */
    { (yyval.exprNode) = (yyvsp[-1].exprNode);}
#line 1759 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 211 "grammar.y" /* yacc.c:1646  */
    { 
            if ( is_op_applicable((yyvsp[0].exprNode)) == false ){
                cout << "Illegal  unary minus on expr on line: " << yylineno << endl; 
            }
            (yyval.exprNode) = newExpr(ARITHM_EXPR_E);
            (yyval.exprNode)->sym = newTmpVarName();
            emit(IO_UMINUS , (yyval.exprNode) , (yyvsp[0].exprNode) , NULL , 0 , yylineno);

    }
#line 1773 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 220 "grammar.y" /* yacc.c:1646  */
    {
        (yyval.exprNode) = newExpr(BOOL_EXPR_E);
        (yyval.exprNode)->sym = newTmpVarName();
        emit(IO_NOT, (yyval.exprNode), (yyvsp[0].exprNode), NULL, 0, yylineno);
    }
#line 1783 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 226 "grammar.y" /* yacc.c:1646  */
    {
            Manage_term__pre_post_op_lvalue( (yyvsp[0].exprNode)->sym , "\"++\"" + (yyvsp[0].exprNode)->sym->name ); 
            if((yyvsp[0].exprNode)->type == TABLE_ITEM_E ){
                (yyval.exprNode) = emit_ifTableItem((yyvsp[0].exprNode));
                emit(ADD, (yyval.exprNode) , (yyval.exprNode) , newExpr_constNum(1), 0, yylineno);
			    emit( TABLESETELEM, (yyvsp[0].exprNode) , (yyvsp[0].exprNode)->index, (yyval.exprNode), 0, yylineno);
            }
            else {
                emit(ADD, (yyvsp[0].exprNode), (yyvsp[0].exprNode) , newExpr_constNum(1), 0, yylineno);
                (yyval.exprNode) = newExpr(ARITHM_EXPR_E);
                (yyval.exprNode)->sym = newTmpVarName();
                emit(ASSIGN, (yyval.exprNode), (yyvsp[0].exprNode) , NULL , 0 ,yylineno);
            }
        }
#line 1802 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 241 "grammar.y" /* yacc.c:1646  */
    { 
        Manage_term__pre_post_op_lvalue( (yyvsp[-1].exprNode)->sym , (yyvsp[-1].exprNode)->sym->name + "\"++\"" );
        (yyval.exprNode) = newExpr(VAR_E);
		(yyval.exprNode)->sym = newTmpVarName();
        if( (yyvsp[-1].exprNode)->type == TABLE_ITEM_E ){
			expr *value = emit_ifTableItem((yyvsp[-1].exprNode));
			emit(ASSIGN, (yyval.exprNode), value , NULL , 0 ,yylineno);
			emit(ADD, value, value , newExpr_constNum(1), 0, yylineno);
			emit( TABLESETELEM, (yyvsp[-1].exprNode), (yyvsp[-1].exprNode)->index, value,  0, yylineno);
		}
		else {
			emit(ASSIGN , (yyval.exprNode), (yyvsp[-1].exprNode) , NULL, 0, yylineno);
			emit(ADD, (yyvsp[-1].exprNode), (yyvsp[-1].exprNode) , newExpr_constNum(1), 0, yylineno);
		}

    }
#line 1823 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 258 "grammar.y" /* yacc.c:1646  */
    { 
        Manage_term__pre_post_op_lvalue( (yyvsp[0].exprNode)->sym , "\"--\"" + (yyvsp[0].exprNode)->sym->name ); 
        if((yyvsp[0].exprNode)->type == TABLE_ITEM_E ){
                (yyval.exprNode) = emit_ifTableItem((yyvsp[0].exprNode));
                emit(SUB, (yyval.exprNode) , (yyval.exprNode) , newExpr_constNum(1), 0, yylineno);
			    emit( TABLESETELEM, (yyvsp[0].exprNode), (yyvsp[0].exprNode)->index, (yyval.exprNode), 0, yylineno);
        }
        else {
            emit(SUB, (yyvsp[0].exprNode), (yyvsp[0].exprNode) , newExpr_constNum(1), 0, yylineno);
            (yyval.exprNode) = newExpr(ARITHM_EXPR_E);
            (yyval.exprNode)->sym = newTmpVarName();
            emit(ASSIGN, (yyval.exprNode), (yyvsp[0].exprNode) , NULL , 0 ,yylineno);
        }
    
    }
#line 1843 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 274 "grammar.y" /* yacc.c:1646  */
    { 
        Manage_term__pre_post_op_lvalue( (yyvsp[-1].exprNode)->sym , (yyvsp[-1].exprNode)->sym->name + "\"--\"" );
        (yyval.exprNode) = newExpr(VAR_E);
		(yyval.exprNode)->sym = newTmpVarName();
        if( (yyvsp[-1].exprNode)->type == TABLE_ITEM_E ){
			expr *value = emit_ifTableItem((yyvsp[-1].exprNode));
			emit(ASSIGN, (yyval.exprNode), value , NULL , 0 ,yylineno);
			emit(SUB, value, value , newExpr_constNum(1), 0, yylineno);
			emit( TABLESETELEM, (yyvsp[-1].exprNode), (yyvsp[-1].exprNode)->index, value, 0, yylineno);
		}
		else {
			emit(ASSIGN , (yyval.exprNode), (yyvsp[-1].exprNode) , NULL, 0, yylineno);
			emit(SUB, (yyvsp[-1].exprNode), (yyvsp[-1].exprNode) , newExpr_constNum(1), 0, yylineno);
		}
    
    }
#line 1864 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 290 "grammar.y" /* yacc.c:1646  */
    { (yyval.exprNode) = (yyvsp[0].exprNode);}
#line 1870 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 293 "grammar.y" /* yacc.c:1646  */
    { 
                
                Manage_assignexpr__lvalue_assignment_expr((yyvsp[-2].exprNode)->sym);
                if( (yyvsp[-2].exprNode)->type == TABLE_ITEM_E ){
                    emit(TABLESETELEM , (yyvsp[-2].exprNode), (yyvsp[-2].exprNode)->index, (yyvsp[0].exprNode), 0 , yylineno );
                    (yyval.exprNode) = emit_ifTableItem((yyvsp[-2].exprNode));
                    (yyval.exprNode)->type = ASSIGN_EXPR_E;
                }
                else{
                    emit(ASSIGN , (yyvsp[-2].exprNode) , (yyvsp[0].exprNode) , NULL , 0 , yylineno );
                    (yyval.exprNode) =  newExpr(ASSIGN_EXPR_E);

                    (yyval.exprNode)->sym = newTmpVarName();
                    emit( ASSIGN ,  (yyval.exprNode) , (yyvsp[-2].exprNode) , NULL , 0 , yylineno );  
                }
            }
#line 1891 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 312 "grammar.y" /* yacc.c:1646  */
    { (yyval.exprNode) = emit_ifTableItem((yyvsp[0].exprNode));  }
#line 1897 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 313 "grammar.y" /* yacc.c:1646  */
    {}
#line 1903 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 314 "grammar.y" /* yacc.c:1646  */
    {}
#line 1909 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 316 "grammar.y" /* yacc.c:1646  */
    {
            (yyval.exprNode) = lvalueExpr((yyvsp[-1].symbol));
        }
#line 1917 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 319 "grammar.y" /* yacc.c:1646  */
    {   (yyval.exprNode) = (yyvsp[0].exprNode); 
                    // print_const_from_type( *($$) );
                }
#line 1925 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 324 "grammar.y" /* yacc.c:1646  */
    { (yyval.exprNode) = Manage_lvalue__ID((yyvsp[0].strVal)); DEBUG_PRINTS_OFFSET("lvalue->ID");}
#line 1931 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 325 "grammar.y" /* yacc.c:1646  */
    { (yyval.exprNode) = Manage_lvalue__LOCAL_ID((yyvsp[0].strVal));  DEBUG_PRINTS_OFFSET("lvalue -> local id");}
#line 1937 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 326 "grammar.y" /* yacc.c:1646  */
    { (yyval.exprNode) = Manage_lvalue__COLONCOLON_ID((yyvsp[0].strVal)); }
#line 1943 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 327 "grammar.y" /* yacc.c:1646  */
    {}
#line 1949 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 330 "grammar.y" /* yacc.c:1646  */
    {// To ID einai strVal
            (yyval.exprNode) = member_item( (yyvsp[-2].exprNode) , (yyvsp[0].strVal) );
        }
#line 1957 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 333 "grammar.y" /* yacc.c:1646  */
    {

            (yyvsp[-3].exprNode) = emit_ifTableItem((yyvsp[-3].exprNode));
            (yyval.exprNode) = newExpr(TABLE_ITEM_E);
            (yyval.exprNode)->sym = (yyvsp[-3].exprNode)->sym;
            (yyval.exprNode)->index = (yyvsp[-1].exprNode); // The index is the expression.
        
        }
#line 1970 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 341 "grammar.y" /* yacc.c:1646  */
    {is_member_call++;}
#line 1976 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 342 "grammar.y" /* yacc.c:1646  */
    {}
#line 1982 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 345 "grammar.y" /* yacc.c:1646  */
    {
            (yyval.exprNode) = make_call( (yyvsp[-3].exprNode) , (yyvsp[-1].exprNode) );
        }
#line 1990 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 349 "grammar.y" /* yacc.c:1646  */
    {

            if( (yyvsp[0].typeOfCall)->is_method == true ){
                expr *self = (yyvsp[-1].exprNode);
                (yyvsp[-1].exprNode) = emit_ifTableItem( member_item( self , (yyvsp[0].typeOfCall)->name ) );
                (yyvsp[0].typeOfCall)->elist->insert( (yyvsp[0].typeOfCall)->elist->begin() , *self ); 
            }
            expr *tmp = newExpr(VAR_E);//wrap type_of_call_type_to expr to call make_call with second arg expr
        
            tmp->elist = (yyvsp[0].typeOfCall)->elist;

            (yyval.exprNode) = make_call((yyvsp[-1].exprNode) , tmp );

            if( is_lib_func_2((yyvsp[-1].exprNode)->sym->name) == true ){
                (yyvsp[-1].exprNode)->type = LIB_FUNC_E;
            }
        }
#line 2012 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 367 "grammar.y" /* yacc.c:1646  */
    {
            expr *func = newExpr(USER_FUNC_E);
            func->sym = (yyvsp[-4].symbol);
            (yyval.exprNode) = make_call(func , (yyvsp[-1].exprNode) );
        }
#line 2022 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 374 "grammar.y" /* yacc.c:1646  */
    {
                (yyval.typeOfCall) = (yyvsp[0].typeOfCall);
            }
#line 2030 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 377 "grammar.y" /* yacc.c:1646  */
    {
                (yyval.typeOfCall) = (yyvsp[0].typeOfCall);
            }
#line 2038 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 382 "grammar.y" /* yacc.c:1646  */
    {
    type_of_call_t* typeOfCall=new type_of_call_t;
    if((yyvsp[-1].exprNode)->elist==NULL){
        typeOfCall->elist=new vector<expr>();
    }else{
        typeOfCall->elist = (yyvsp[-1].exprNode)->elist;
    }
    
    typeOfCall->is_method = false;
    typeOfCall->name = NULL;
    (yyval.typeOfCall)=typeOfCall;
}
#line 2055 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 396 "grammar.y" /* yacc.c:1646  */
    {/*equivalent to lvalue.id(lvalue, elist)*/ 
    // cout << "Debug:methodCall -> ID (edo): " << $2 << endl; 
    
    if( (yyval.typeOfCall) == NULL)
        (yyval.typeOfCall) = new type_of_call_t;

    (yyval.typeOfCall)->elist = new vector<expr>();
    if( (yyvsp[-1].exprNode)->elist != NULL ){
        (yyval.typeOfCall)->elist = (yyvsp[-1].exprNode)->elist;
    }
    (yyval.typeOfCall)->is_method = true;
    (yyval.typeOfCall)->name = strdup((yyvsp[-3].strVal));
    
    // for( size_t i = 0; i < ($$)->elist->size() ; i++ ){
    //     cout << "\tmethod call [ " << i  << "] " <<  ($$)->elist->at(i).num_const << endl;
    // }
}
#line 2077 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 415 "grammar.y" /* yacc.c:1646  */
    {
                // cout << "elist->expr: " << $1->num_const << endl;
                (yyval.exprNode)->elist = new vector<expr>();
                (yyval.exprNode)->elist->push_back(*(yyvsp[0].exprNode));

                // cout << "elist 2 : " << ($$)->elist->size() "elist 3 : " << ($$)->elist->at(0).num_const << endl;
            }
#line 2089 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 422 "grammar.y" /* yacc.c:1646  */
    {
                (yyvsp[-2].exprNode)->elist->push_back(*(yyvsp[0].exprNode));
            }
#line 2097 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 425 "grammar.y" /* yacc.c:1646  */
    {
                (yyval.exprNode) = newExpr(NEW_TABLE_E);
                (yyval.exprNode)->elist = NULL;
            }
#line 2106 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 431 "grammar.y" /* yacc.c:1646  */
    {ultrex++;}
#line 2112 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 431 "grammar.y" /* yacc.c:1646  */
    {
                ultrex--;
               expr *table = newExpr(NEW_TABLE_E);
                table->sym = newTmpVarName();
                emit(TABLECREATE , table , NULL  , NULL , 0 , yylineno );
                
                if( ((yyvsp[-1].exprNode))->elist != NULL  ){
                    for( unsigned i = 0; i < ((yyvsp[-1].exprNode))->elist->size(); i++ ){
                        emit( TABLESETELEM , table , newExpr_constNum(i) , &((yyvsp[-1].exprNode)->elist->at(i)) , 0 , yylineno );
                    }
                }

                (yyval.exprNode) = table;
               
            }
#line 2132 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 447 "grammar.y" /* yacc.c:1646  */
    {
                expr *t = newExpr(NEW_TABLE_E);
                t->sym = newTmpVarName();
                emit(TABLECREATE , t , NULL , NULL , 0 , yylineno );

                for( unsigned i = 0; i < (yyvsp[-1].exprNode)->ilist->size(); ++i ){
                    emit(TABLESETELEM , t , &((yyvsp[-1].exprNode)->ilist->at(i).first) , &((yyvsp[-1].exprNode)->ilist->at(i).second), 0 , yylineno );//TODO: check
                }

                (yyval.exprNode) = t;
            }
#line 2148 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 460 "grammar.y" /* yacc.c:1646  */
    {
                // ultrex = 1;
                expr *e = newExpr(TMP_E);//tmp
                e->ilist = new vector<pair<expr,expr>>();
                e->ilist->push_back( *((yyvsp[0].exprNode)->ipair) );
                
                (yyval.exprNode) = e;
            }
#line 2161 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 468 "grammar.y" /* yacc.c:1646  */
    {
                // ultrex = 1;
                (yyvsp[-2].exprNode)->ilist->push_back( *((yyvsp[0].exprNode)->ipair) );    
                // for ( unsigned i =0; i < $1->ilist->size(); ++i ){
                //     cout << "\t indexed: [" << i << "]: " <<  ($1)->ilist->at(i).first.str_const << endl;
                //     cout << "\t indexed: [" << i << "] " << ($1)->ilist->at(i).second.num_const << endl;
                // }
            }
#line 2174 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 480 "grammar.y" /* yacc.c:1646  */
    {ultrex++;}
#line 2180 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 480 "grammar.y" /* yacc.c:1646  */
    {
    expr *e = newExpr(TMP_E);//tmp
    e->ipair = new pair<expr,expr>();
    e->ipair->first = *(yyvsp[-3].exprNode);
    e->ipair->second = *(yyvsp[-1].exprNode);
    // cout << "indexedelem $2: " <<  (*(e->ipair)).first.str_const <<  (*(e->ipair)).second.num_const << endl;
    (yyval.exprNode) = e;
    ultrex--;
}
#line 2194 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 491 "grammar.y" /* yacc.c:1646  */
    {    Manage__open_block(); 
                    // cout << "~~~~~~~~~~~" << currScopeOffset() << endl;
               }
#line 2202 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 495 "grammar.y" /* yacc.c:1646  */
    { Manage__close_block(); 

            }
#line 2210 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 500 "grammar.y" /* yacc.c:1646  */
    { 
                node_t *symbol = Manage_ID_OR_NOT__ID((yyvsp[0].strVal)); 
                if(symbol == NULL ){
                    cout << "lib func check me!" << endl;
                }
                else{
                    (yyval.symbol) = symbol;
                }

                DEBUG_PRINTS_OFFSET("funcname -> id");
            }
#line 2226 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 511 "grammar.y" /* yacc.c:1646  */
    { (yyval.symbol) = Manage_ID_OR_NOT__Anonymous();
                DEBUG_PRINTS_OFFSET("funcname -> anon");
             }
#line 2234 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 516 "grammar.y" /* yacc.c:1646  */
    {  
                is_func_rule++; 
                isBlock.push_back(false);
                statement_stack.push_back("funcdef");
                statement_stack.push_back("block");   

                (yyval.symbol) = (yyvsp[0].symbol);
                (yyval.symbol)->iaddress = quads.size();
                (yyval.symbol)->func_j = quads.size(); 
                emit(JUMP , NULL , NULL ,NULL , 0 , yylineno);
                emit( FUNCSTART , NULL , lvalueExpr((yyval.symbol)) , NULL , 0 , yylineno );
                functionLocalStack.push_back(currScopeOffset());
                DEBUG_PRINTS_OFFSET("funcname -> funcpprefix 1");
                enterScopeSpace();
                resetFormalArgsOffset();
                
                // func_ret_list.push_back(vector<unsigned long int>());


                DEBUG_PRINTS_OFFSET("funcname -> funcpprefix 2");
            }
#line 2260 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 539 "grammar.y" /* yacc.c:1646  */
    {scope++; }
#line 2266 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 539 "grammar.y" /* yacc.c:1646  */
    {scope--; restoreCurrScopeOffset(0);}
#line 2272 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 540 "grammar.y" /* yacc.c:1646  */
    {   
                enterScopeSpace();
                resetFuncLocalOffset();
                
                DEBUG_PRINTS_OFFSET("funcname -> funcargs");
            }
#line 2283 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 548 "grammar.y" /* yacc.c:1646  */
    {
                // cout << "~~~~OUTSIDE BLOCK~~~~" << currScopeOffset() << endl;
                (yyval.locals_size) = currScopeOffset();
                clear_statement_stack();
                exitScopeSpace();
                DEBUG_PRINTS_OFFSET("funcname -> funcbody");
            }
#line 2295 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 557 "grammar.y" /* yacc.c:1646  */
    {
            exitScopeSpace();
            (yyvsp[-2].symbol)->total_locals = (yyvsp[0].locals_size);
            // cout <<"~~~~~~~~~~~" << $1->total_locals << endl;
            restoreCurrScopeOffset(functionLocalStack.back() );
            functionLocalStack.pop_back();
            (yyval.symbol) = (yyvsp[-2].symbol);
            emit( FUNCEND , NULL , lvalueExpr((yyvsp[-2].symbol)) , NULL , 0 , yylineno );

            DEBUG_PRINTS_OFFSET("funcname ->  funcdef end.");

            patchLabel( (yyvsp[-2].symbol)->func_j , quads.size() );

            // for( unsigned int i = 0; i < func_ret_list[func_ret_list.size()-1].size(); ++i ){
            //     quads[ func_ret_list[func_ret_list.size()-1].at(i) ].label =  quads.size()-1;
            // }

            // func_ret_list.pop_back();

        }
#line 2320 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 580 "grammar.y" /* yacc.c:1646  */
    {
                expr *expr =  newExpr( CONST_NUM_E );   
                expr->num_const = (yyvsp[0].realVal);
                (yyval.exprNode) = expr;    
            }
#line 2330 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 586 "grammar.y" /* yacc.c:1646  */
    {   
                expr *expr =  newExpr( CONST_STRING_E );   
                expr->str_const = strdup((yyvsp[0].strVal));
                (yyval.exprNode) = expr;  
                // cout << "test for lib funcs:::::::    " << expr->str_const << endl;
            }
#line 2341 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 592 "grammar.y" /* yacc.c:1646  */
    {
                expr *expr =  newExpr( NIL_E ); 
                (yyval.exprNode) = expr;  

            }
#line 2351 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 597 "grammar.y" /* yacc.c:1646  */
    {
                expr *expr =  newExpr( CONST_BOOL_E );
                expr->bool_const = 1;
                (yyval.exprNode) = expr; 
            }
#line 2361 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 602 "grammar.y" /* yacc.c:1646  */
    {
                expr *expr =  newExpr( CONST_BOOL_E );
                expr->bool_const = 0;
                (yyval.exprNode) = expr; 
            }
#line 2371 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 607 "grammar.y" /* yacc.c:1646  */
    {
                expr *expr =  newExpr( CONST_NUM_E );   
                expr->num_const = (yyvsp[0].realVal);
                (yyval.exprNode) = expr;
            }
#line 2381 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 614 "grammar.y" /* yacc.c:1646  */
    {Manage_idlist__ID((yyvsp[0].strVal)); incrCurrScopeOffset(); DEBUG_PRINTS_OFFSET("idlist -> id");}
#line 2387 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 615 "grammar.y" /* yacc.c:1646  */
    { Manage_idlist__idlist_comma_ID((yyvsp[0].strVal)); incrCurrScopeOffset(); DEBUG_PRINTS_OFFSET("idlist -> id , [id]"); }
#line 2393 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 621 "grammar.y" /* yacc.c:1646  */
    { statement_stack.push_back("if");
               statement_stack.push_back("block");}
#line 2400 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 624 "grammar.y" /* yacc.c:1646  */
    {
                            emit( IF_EQ, NULL , (yyvsp[-1].exprNode) , newExpr_constBool(1), quads.size()+2 , yylineno );//TODO:check if result must be NULL
                            (yyval.unsigned_label) = quads.size();
                            emit(JUMP , NULL, NULL, NULL , 0, yylineno);
                        }
#line 2410 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 631 "grammar.y" /* yacc.c:1646  */
    { statement_stack.push_back("else"); 
                statement_stack.push_back("block");
                (yyval.unsigned_label)=quads.size();
                emit(JUMP , NULL, NULL, NULL , 0, yylineno);
            }
#line 2420 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 638 "grammar.y" /* yacc.c:1646  */
    { 
    // printf(" ifprefix stmt %d \n",yylineno); 
            
            patchLabel((yyvsp[-1].unsigned_label),quads.size());
        }
#line 2430 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 644 "grammar.y" /* yacc.c:1646  */
    {clear_statement_stack();}
#line 2436 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 645 "grammar.y" /* yacc.c:1646  */
    { 
              patchLabel((yyvsp[-4].unsigned_label),(yyvsp[-2].unsigned_label) + 1);
              patchLabel((yyvsp[-2].unsigned_label),quads.size());
            }
#line 2445 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 654 "grammar.y" /* yacc.c:1646  */
    {
        
        clear_statement_stack();
        
        emit(JUMP , NULL, NULL, NULL , (yyvsp[-2].unsigned_label) , yylineno); 
        patchLabel( (yyvsp[-1].unsigned_label) , quads.size() );
        

        // patch break_"jumps"
        unsigned long int index = break_list.size()-1;
        for( unsigned long int i = 0 ; i < break_list[index].size(); ++i ){
            patchLabel( break_list[index][i] , quads.size() );
        }

        // patch cont_"jumps"
        index = cont_list.size()-1;
        for( unsigned long int i = 0 ; i < cont_list[index].size(); ++i ){
            patchLabel( cont_list[index][i] , (yyvsp[-2].unsigned_label) );
        }

}
#line 2471 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 677 "grammar.y" /* yacc.c:1646  */
    {
                statement_stack.push_back("while");
                statement_stack.push_back("block");

                break_list.push_back( vector<unsigned long int>() );
                cont_list.push_back( vector<unsigned long int>() );               
                (yyval.unsigned_label) = quads.size();

            }
#line 2485 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 688 "grammar.y" /* yacc.c:1646  */
    {
            emit( IF_EQ, NULL , (yyvsp[-1].exprNode) , newExpr_constBool(1), quads.size()+2 , yylineno );
            (yyval.unsigned_label) = quads.size();
            emit(JUMP , NULL, NULL, NULL , 0 , yylineno);
            
        }
#line 2496 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 697 "grammar.y" /* yacc.c:1646  */
    {(yyval.unsigned_label) = quads.size(); emit(JUMP , NULL, NULL, NULL , 0 , yylineno);}
#line 2502 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 699 "grammar.y" /* yacc.c:1646  */
    {(yyval.unsigned_label) = quads.size();}
#line 2508 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 701 "grammar.y" /* yacc.c:1646  */
    { 
                 statement_stack.push_back("for");
                 statement_stack.push_back("block");
                 break_list.push_back( vector<unsigned long int>() );
                 cont_list.push_back( vector<unsigned long int>() );
                }
#line 2519 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 707 "grammar.y" /* yacc.c:1646  */
    {
                    forNode *e = new forNode();
                    e->test = (yyvsp[-2].unsigned_label);
                    e->enter = quads.size();
                    
                    emit( IF_EQ, NULL , (yyvsp[-1].exprNode) , newExpr_constBool(1), 0 , yylineno );
                    (yyval.forNode)=e;
                }
#line 2532 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 716 "grammar.y" /* yacc.c:1646  */
    {clear_statement_stack();}
#line 2538 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 716 "grammar.y" /* yacc.c:1646  */
    {
                patchLabel((yyvsp[-7].forNode)->enter,(yyvsp[-3].unsigned_label)+1);
                patchLabel((yyvsp[-6].unsigned_label),quads.size());
                patchLabel((yyvsp[-3].unsigned_label),(yyvsp[-7].forNode)->test);
                patchLabel((yyvsp[0].unsigned_label),(yyvsp[-6].unsigned_label)+1);
                

                unsigned long int index = break_list.size()-1;
                for( unsigned long int i = 0 ; i < break_list[index].size(); ++i ){
                    patchLabel( break_list[index][i] , quads.size() );
                }

                // patch cont_"jumps"
                index = cont_list.size()-1;
                for( unsigned long int i = 0 ; i < cont_list[index].size(); ++i ){
                    patchLabel( cont_list[index][i] , (yyvsp[-6].unsigned_label)+1 );
                }
              
            }
#line 2562 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 736 "grammar.y" /* yacc.c:1646  */
    { 
                emit( RET , NULL , (yyvsp[-1].exprNode) , NULL, 0 , yylineno);
                //func_ret_list[func_ret_list.size()-1].push_back(quads.size());
               // emit( JUMP , NULL , NULL , NULL, 0 , yylineno);


            }
#line 2574 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 743 "grammar.y" /* yacc.c:1646  */
    { 
                emit( RET , NULL , NULL , NULL, 0 , yylineno);
               // func_ret_list[func_ret_list.size()-1].push_back(quads.size());
                //emit( JUMP , NULL , NULL , NULL, 0 , yylineno);
            }
#line 2584 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2588 "parser.cpp" /* yacc.c:1646  */
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
#line 750 "grammar.y" /* yacc.c:1906  */


void yyerror(char const *s)
{
	fflush(stdout);
	fprintf(stderr , "yyerror! line:[%d] [%s]\n" ,yylineno, s );
}

extern unsigned int programVarOffset;

int main(int argc, char *argv[])
{
    if(argc>1){
        if(!(yyin=fopen(argv[1],"r"))){
            fprintf(stderr, "Cannot read file : %s\n",argv[1]);
            return 1;            
        }
    }
    else{
        yyin = stdin;
    }
    init_SymTable();
    yyparse();          
    printf( "\x1B[34m""\n###########################################     Symbol table:     ###########################################\n\n""\x1B[0m"  );
    print_SymTable();
    printQuads();

    generate();
    set_srcLines();
    print_instructions( instructions_table ,numConsts, strConsts , libFunctions , userFuncs);
    create_binary();

    // read_binary(); 
    return 0;
}
