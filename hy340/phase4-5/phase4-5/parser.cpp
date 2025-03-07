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

    #include "symbolTable.h"

    int yyerror (string yaccProvidedMessage){ return 0; }
    int yylex(void);

    extern int yylineno;
	extern char * yyval;
	extern char * yytext;
	extern FILE * yyin;
	extern FILE * yyout;

    vector <int>    break_vector;
    vector <int>    continue_vector;
    vector <string> break_continues_belong;

    int break_counter = 0;
    int continue_counter = 0;

    unsigned char loop_intersect = 0 ;
    unsigned char break_intersect = 1 ;
    vector <int>  valid_jumps;
    vector <int>  false_jumps;
    vector <vector<int>> repach;
    vector <vector <int>> continue_quads;
    vector <vector <int>>  break_quads;
    vector <int>  loop_start;
    vector <int>  loop_end;
    vector <int>  false_quads;
    vector <int>  operation_list;

    int SCOPE = 0;
    string GLOBAL_ID;
    bool isLogic = 0;
    bool isrelop = 0;
    bool isnt    = 0;
    bool isindex = 0;
    bool isLib    = 0;

    vector<SymbolTableEntry> FORMAL_ARGUMENTS; 

#line 108 "parser.cpp" /* yacc.c:339  */

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
   by #include "parser.hpp".  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    ASSIGN = 258,
    STRING = 259,
    INTEGER = 260,
    REAL = 261,
    LOCAL = 262,
    NIL = 263,
    ID = 264,
    BLOCK_COMMENT = 265,
    LINE_COMMENT = 266,
    ESCAPE_CHARACTERS = 267,
    SPACE = 268,
    IF = 269,
    ELSE = 270,
    WHILE = 271,
    FOR = 272,
    FUNCTION = 273,
    RETURN = 274,
    BREAK = 275,
    CONTINUE = 276,
    AND = 277,
    NOT = 278,
    OR = 279,
    TRUE = 280,
    FALSE = 281,
    MINUS = 282,
    EQUAL = 283,
    DIFFER = 284,
    BIGGER = 285,
    LESS = 286,
    BIGGER_EQ = 287,
    LESS_EQ = 288,
    MINUSMINUS = 289,
    PLUSPLUS = 290,
    MOD = 291,
    MULTIPLY = 292,
    DIV = 293,
    PLUS = 294,
    CURLY_START_BRACKET = 295,
    CURLY_END_BRACKET = 296,
    START_BRACKET = 297,
    END_BRACKET = 298,
    START_PARENTHESIS = 299,
    END_PARENTHESIS = 300,
    SEMICOLON = 301,
    COMMA = 302,
    COLON = 303,
    DOUBLE_COLON = 304,
    DOT = 305,
    DOUBLE_DOT = 306,
    UNDEFINED = 307,
    UMINUS = 308
  };
#endif
/* Tokens.  */
#define ASSIGN 258
#define STRING 259
#define INTEGER 260
#define REAL 261
#define LOCAL 262
#define NIL 263
#define ID 264
#define BLOCK_COMMENT 265
#define LINE_COMMENT 266
#define ESCAPE_CHARACTERS 267
#define SPACE 268
#define IF 269
#define ELSE 270
#define WHILE 271
#define FOR 272
#define FUNCTION 273
#define RETURN 274
#define BREAK 275
#define CONTINUE 276
#define AND 277
#define NOT 278
#define OR 279
#define TRUE 280
#define FALSE 281
#define MINUS 282
#define EQUAL 283
#define DIFFER 284
#define BIGGER 285
#define LESS 286
#define BIGGER_EQ 287
#define LESS_EQ 288
#define MINUSMINUS 289
#define PLUSPLUS 290
#define MOD 291
#define MULTIPLY 292
#define DIV 293
#define PLUS 294
#define CURLY_START_BRACKET 295
#define CURLY_END_BRACKET 296
#define START_BRACKET 297
#define END_BRACKET 298
#define START_PARENTHESIS 299
#define END_PARENTHESIS 300
#define SEMICOLON 301
#define COMMA 302
#define COLON 303
#define DOUBLE_COLON 304
#define DOT 305
#define DOUBLE_DOT 306
#define UNDEFINED 307
#define UMINUS 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 45 "parser.y" /* yacc.c:355  */

    int                         intValue;
    char*                       stringValue;
    double                      realValue;
    bool                        boolValue;
    void*                       nilValue;
    struct expr*                exprValue;
    struct call*                callValue;
    struct SymbolTableEntry*    symbValue;
    unsigned                    unsdValue;
    struct forJump*             forjValue;
    

#line 268 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 283 "parser.cpp" /* yacc.c:358  */

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
#define YYLAST   476

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  218

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   148,   148,   154,   159,   164,   196,   199,   200,   201,
     203,   202,   240,   239,   271,   272,   273,   276,   282,   295,
     306,   317,   328,   339,   376,   412,   447,   484,   519,   555,
     555,   597,   597,   642,   650,   654,   659,   664,   674,   712,
     711,   750,   788,   787,   825,   856,   861,   865,   869,   877,
     880,   919,   953,   965,   973,   972,  1060,  1068,  1068,  1085,
    1085,  1096,  1096,  1100,  1114,  1127,  1150,  1168,  1174,  1182,
    1182,  1194,  1209,  1208,  1242,  1251,  1249,  1283,  1290,  1290,
    1309,  1329,  1336,  1342,  1349,  1401,  1400,  1410,  1409,  1423,
    1444,  1450,  1422,  1474,  1476,  1525,  1531,  1474,  1556,  1563,
    1570,  1577,  1583,  1588,  1596,  1595,  1620,  1625,  1623,  1655,
    1658,  1692,  1699,  1708,  1717,  1736,  1770,  1802,  1808,  1813,
    1813,  1850,  1884,  1884,  1922,  1922
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "STRING", "INTEGER", "REAL",
  "LOCAL", "NIL", "ID", "BLOCK_COMMENT", "LINE_COMMENT",
  "ESCAPE_CHARACTERS", "SPACE", "IF", "ELSE", "WHILE", "FOR", "FUNCTION",
  "RETURN", "BREAK", "CONTINUE", "AND", "NOT", "OR", "TRUE", "FALSE",
  "MINUS", "EQUAL", "DIFFER", "BIGGER", "LESS", "BIGGER_EQ", "LESS_EQ",
  "MINUSMINUS", "PLUSPLUS", "MOD", "MULTIPLY", "DIV", "PLUS",
  "CURLY_START_BRACKET", "CURLY_END_BRACKET", "START_BRACKET",
  "END_BRACKET", "START_PARENTHESIS", "END_PARENTHESIS", "SEMICOLON",
  "COMMA", "COLON", "DOUBLE_COLON", "DOT", "DOUBLE_DOT", "UNDEFINED",
  "UMINUS", "$accept", "program", "stmts", "stmt", "$@1", "$@2", "expr",
  "$@3", "$@4", "Q", "term", "$@5", "$@6", "primary", "lvalue",
  "assignexpr", "$@7", "member", "$@8", "$@9", "$@10", "call",
  "callsuffix", "normcall", "$@11", "methodcall", "elist", "$@12",
  "commaexpr", "$@13", "objectdef", "$@14", "indexed", "commaindexedelem",
  "indexedelem", "block", "$@15", "$@16", "funcdef", "$@17", "$@18",
  "$@19", "$@20", "$@21", "$@22", "$@23", "const", "idlist", "$@24",
  "commaid", "$@25", "ifprefix", "ifstmt", "elseprefix", "whilestart",
  "whilecond", "whilestmt", "N", "M", "forprefix", "$@26", "forstmt",
  "returnstmt", "$@27", "$@28", YY_NULLPTR
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
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF -175

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-175)))

#define YYTABLE_NINF -125

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-125)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      90,  -175,  -175,  -175,    -5,  -175,  -175,   -39,  -175,  -175,
       1,   -28,  -175,  -175,   191,  -175,  -175,   191,     8,     8,
     -15,     7,   159,  -175,    26,    56,  -175,    90,   214,  -175,
    -175,     4,  -175,  -175,     9,  -175,  -175,  -175,  -175,    90,
    -175,    14,  -175,  -175,  -175,  -175,  -175,   191,    30,    32,
      71,   191,    42,    44,    46,  -175,  -175,    75,    70,    31,
      70,    59,    90,   191,   191,    58,    55,   274,    74,  -175,
    -175,  -175,  -175,  -175,   191,   191,   191,   191,   191,   191,
     191,   191,   191,   191,   191,  -175,  -175,  -175,  -175,    94,
      91,    93,   102,  -175,  -175,  -175,   191,   191,   191,  -175,
     114,   191,    90,   191,   293,   191,  -175,  -175,   234,  -175,
    -175,  -175,    86,  -175,    90,    -8,   385,    92,  -175,     7,
    -175,  -175,    89,  -175,  -175,     5,   411,   411,   437,   437,
     437,   437,  -175,  -175,  -175,     5,   191,   191,   128,    96,
    -175,  -175,   191,   385,   331,    97,   129,  -175,    90,   312,
    -175,    98,  -175,    95,   135,   103,  -175,    89,   105,   191,
     101,  -175,    55,   191,   191,   191,   349,   107,  -175,   191,
     385,  -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,   108,
    -175,  -175,   367,   191,  -175,  -175,   109,   424,   398,  -175,
    -175,   111,    90,   191,   110,  -175,   135,  -175,   385,  -175,
    -175,  -175,   254,   149,  -175,   119,   115,   101,  -175,  -175,
    -175,  -175,  -175,  -175,   110,   119,  -175,  -175
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,   100,    99,    98,     0,   101,    50,     0,   114,   119,
      89,   122,    10,    12,     0,   102,   103,     0,     0,     0,
      87,    78,     0,    16,     0,     0,     2,     4,     0,    33,
      36,    45,    17,    53,    46,    47,    14,    15,    49,     0,
       6,     0,     7,   117,     8,     9,    51,     0,     0,     0,
       0,     0,     0,     0,     0,    44,    37,     0,    41,     0,
      38,     0,     0,     0,    74,     0,    83,     0,     0,    52,
       1,     3,    29,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,    59,    69,    57,     0,
       0,     0,     0,    65,    67,    68,     0,     0,    74,    61,
     111,     0,     0,    74,     0,    74,    90,    94,     0,   125,
      11,    13,     0,    86,     4,     0,    72,     0,    80,     0,
      81,    35,    48,    34,    34,    19,    27,    28,    23,    25,
      24,    26,    22,    20,    21,    18,     0,    74,     0,     0,
      40,    43,     0,    56,     0,     0,     0,   113,     0,     0,
     116,     0,   110,     0,   106,     0,   123,     0,     0,     0,
      77,    79,    83,    74,     0,     0,     0,     0,    58,    74,
      55,    63,    64,    62,   112,   115,   117,   118,   104,     0,
      95,    88,     0,     0,    73,    82,     0,    30,    32,    60,
      70,     0,     0,     0,   109,    91,   106,    84,    75,    66,
      71,   117,     0,     0,   105,     0,     0,    77,   121,   120,
     107,    92,    96,    76,   109,     0,   108,    97
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -175,    47,   143,   -30,  -175,  -175,   -14,  -175,  -175,    48,
    -175,  -175,  -175,  -175,    60,  -175,  -175,  -175,  -175,  -175,
    -175,    67,  -175,  -175,  -175,  -175,   -92,  -175,   -36,  -175,
    -175,  -175,  -175,    11,    57,  -171,  -175,  -175,   -21,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,   -22,  -175,   -34,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -174,  -175,  -175,
    -175,  -175,  -175,  -175,  -175
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    53,    54,    28,   123,   124,   164,
      29,    90,    91,    30,    31,    32,    92,    33,   138,   136,
     146,    34,    93,    94,   137,    95,   117,   160,   184,   207,
      35,    64,    65,   120,    66,    36,    61,    62,    37,    49,
     154,   205,    50,   155,   196,   215,    38,   179,   194,   204,
     214,    39,    40,   148,    41,   102,    42,   103,   193,    43,
      48,    44,    45,    51,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    68,   192,    56,    46,    47,   145,   -54,    67,   100,
     -93,   151,    96,   153,    72,     4,    73,     6,  -124,    74,
      75,    76,    77,    78,    79,    80,   -85,   208,    81,    82,
      83,    84,   114,   104,   211,    69,   112,   108,   -42,   -39,
     159,    81,    82,    83,   217,   167,    86,    63,    87,   115,
     116,    97,    57,    98,    88,    89,    70,    24,   101,    99,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   186,   150,    97,   105,    98,   106,   191,    58,    60,
     107,    99,   143,   144,   116,    59,    59,   149,   109,   116,
     110,   116,   111,    10,     1,     2,     3,     4,     5,     6,
     113,   118,   119,   139,     7,   142,     8,     9,    10,    11,
      12,    13,    86,    14,    87,    15,    16,    17,   174,   122,
      88,    89,   166,   116,    18,    19,   140,   141,   170,   147,
      20,   157,    21,   163,    22,   161,    23,   168,   173,    24,
     169,   177,   172,   176,   178,   182,   181,   180,   183,   116,
     187,   188,   190,   195,   199,   116,   200,   203,   210,    20,
     212,   158,   201,     1,     2,     3,     4,     5,     6,   198,
      71,   213,   165,   185,   206,     0,   162,    10,     0,   202,
     216,     0,    14,     0,    15,    16,    17,     0,     0,     0,
       0,     0,     0,    18,    19,     1,     2,     3,     4,     5,
       6,    21,     0,    22,     0,     0,     0,     0,    24,     0,
       0,     0,     0,     0,    14,     0,    15,    16,    17,     0,
       0,     0,     0,     0,     0,    18,    19,     0,     0,     0,
       0,     0,     0,    21,     0,    22,    72,     0,    73,     0,
      24,    74,    75,    76,    77,    78,    79,    80,     0,     0,
      81,    82,    83,    84,     0,     0,    72,     0,    73,     0,
      85,    74,    75,    76,    77,    78,    79,    80,     0,     0,
      81,    82,    83,    84,     0,     0,    72,     0,    73,     0,
     156,    74,    75,    76,    77,    78,    79,    80,     0,     0,
      81,    82,    83,    84,     0,     0,    72,     0,    73,     0,
     209,    74,    75,    76,    77,    78,    79,    80,     0,     0,
      81,    82,    83,    84,     0,    72,     0,    73,     0,   121,
      74,    75,    76,    77,    78,    79,    80,     0,     0,    81,
      82,    83,    84,     0,    72,     0,    73,     0,   152,    74,
      75,    76,    77,    78,    79,    80,     0,     0,    81,    82,
      83,    84,     0,    72,     0,    73,     0,   175,    74,    75,
      76,    77,    78,    79,    80,     0,     0,    81,    82,    83,
      84,    72,     0,    73,   171,     0,    74,    75,    76,    77,
      78,    79,    80,     0,     0,    81,    82,    83,    84,    72,
       0,    73,   189,     0,    74,    75,    76,    77,    78,    79,
      80,     0,     0,    81,    82,    83,    84,    72,   197,    73,
       0,     0,    74,    75,    76,    77,    78,    79,    80,     0,
      72,    81,    82,    83,    84,    74,    75,    76,    77,    78,
      79,    80,     0,     0,    81,    82,    83,    84,    74,  -125,
    -125,    77,    78,    79,    80,     0,     0,    81,    82,    83,
      84,    74,    75,    76,    77,    78,    79,    80,     0,     0,
      81,    82,    83,    84,    74,     0,     0,  -125,  -125,  -125,
    -125,     0,     0,    81,    82,    83,    84
};

static const yytype_int16 yycheck[] =
{
      14,    22,   176,    17,     9,    44,    98,     3,    22,    39,
       9,   103,     3,   105,    22,     7,    24,     9,    46,    27,
      28,    29,    30,    31,    32,    33,    41,   201,    36,    37,
      38,    39,    62,    47,   205,     9,    57,    51,    34,    35,
      48,    36,    37,    38,   215,   137,    42,    40,    44,    63,
      64,    42,    44,    44,    50,    51,     0,    49,    44,    50,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,   163,   102,    42,    44,    44,    44,   169,    18,    19,
       9,    50,    96,    97,    98,    18,    19,   101,    46,   103,
      46,   105,    46,    18,     4,     5,     6,     7,     8,     9,
      41,    43,    47,     9,    14,     3,    16,    17,    18,    19,
      20,    21,    42,    23,    44,    25,    26,    27,   148,    45,
      50,    51,   136,   137,    34,    35,    35,    34,   142,    15,
      40,    45,    42,    44,    44,    43,    46,     9,     9,    49,
      44,    46,    45,    45,     9,   159,    41,    44,    47,   163,
     164,   165,    45,    45,    45,   169,    45,    47,     9,    40,
      45,   114,   192,     4,     5,     6,     7,     8,     9,   183,
      27,   207,   124,   162,   196,    -1,   119,    18,    -1,   193,
     214,    -1,    23,    -1,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,     4,     5,     6,     7,     8,
       9,    42,    -1,    44,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    44,    22,    -1,    24,    -1,
      49,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      36,    37,    38,    39,    -1,    -1,    22,    -1,    24,    -1,
      46,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      36,    37,    38,    39,    -1,    -1,    22,    -1,    24,    -1,
      46,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      36,    37,    38,    39,    -1,    -1,    22,    -1,    24,    -1,
      46,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      36,    37,    38,    39,    -1,    22,    -1,    24,    -1,    45,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    36,
      37,    38,    39,    -1,    22,    -1,    24,    -1,    45,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    36,    37,
      38,    39,    -1,    22,    -1,    24,    -1,    45,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    36,    37,    38,
      39,    22,    -1,    24,    43,    -1,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    36,    37,    38,    39,    22,
      -1,    24,    43,    -1,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    36,    37,    38,    39,    22,    41,    24,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    -1,
      22,    36,    37,    38,    39,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    36,    37,    38,    39,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    36,    37,    38,
      39,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      36,    37,    38,    39,    27,    -1,    -1,    30,    31,    32,
      33,    -1,    -1,    36,    37,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    14,    16,    17,
      18,    19,    20,    21,    23,    25,    26,    27,    34,    35,
      40,    42,    44,    46,    49,    55,    56,    57,    60,    64,
      67,    68,    69,    71,    75,    84,    89,    92,   100,   105,
     106,   108,   110,   113,   115,   116,     9,    44,   114,    93,
      96,   117,   118,    58,    59,    60,    60,    44,    68,    75,
      68,    90,    91,    40,    85,    86,    88,    60,    92,     9,
       0,    56,    22,    24,    27,    28,    29,    30,    31,    32,
      33,    36,    37,    38,    39,    46,    42,    44,    50,    51,
      65,    66,    70,    76,    77,    79,     3,    42,    44,    50,
      57,    44,   109,   111,    60,    44,    44,     9,    60,    46,
      46,    46,    92,    41,    57,    60,    60,    80,    43,    47,
      87,    45,    45,    61,    62,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    73,    78,    72,     9,
      35,    34,     3,    60,    60,    80,    74,    15,   107,    60,
      57,    80,    45,    80,    94,    97,    46,    45,    55,    48,
      81,    43,    88,    44,    63,    63,    60,    80,     9,    44,
      60,    43,    45,     9,    57,    45,    45,    46,     9,   101,
      44,    41,    60,    47,    82,    87,    80,    60,    60,    43,
      45,    80,   111,   112,   102,    45,    98,    41,    60,    45,
      45,    57,    60,    47,   103,    95,   101,    83,   111,    46,
       9,    89,    45,    82,   104,    99,   103,    89
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    57,    57,    57,
      58,    57,    59,    57,    57,    57,    57,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    61,
      60,    62,    60,    60,    63,    64,    64,    64,    64,    65,
      64,    64,    66,    64,    64,    67,    67,    67,    67,    67,
      68,    68,    68,    68,    70,    69,    69,    72,    71,    73,
      71,    74,    71,    71,    75,    75,    75,    76,    76,    78,
      77,    79,    81,    80,    80,    83,    82,    82,    85,    84,
      84,    86,    87,    87,    88,    90,    89,    91,    89,    93,
      94,    95,    92,    96,    97,    98,    99,    92,   100,   100,
     100,   100,   100,   100,   102,   101,   101,   104,   103,   103,
     105,   106,   106,   107,   108,   109,   110,   111,   112,   114,
     113,   115,   117,   116,   118,   116
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       0,     3,     0,     3,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     0,
       5,     0,     5,     1,     0,     3,     1,     2,     2,     0,
       3,     2,     0,     3,     2,     1,     1,     1,     3,     1,
       1,     2,     2,     1,     0,     4,     3,     0,     4,     0,
       5,     0,     4,     4,     4,     2,     6,     1,     1,     0,
       4,     5,     0,     3,     0,     0,     4,     0,     0,     4,
       3,     2,     3,     0,     5,     0,     3,     0,     5,     0,
       0,     0,     8,     0,     0,     0,     0,    10,     1,     1,
       1,     1,     1,     1,     0,     3,     0,     0,     4,     0,
       4,     2,     4,     1,     1,     3,     3,     0,     0,     0,
       8,     7,     0,     4,     0,     3
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
#line 149 "parser.y" /* yacc.c:1646  */
    {
                cout << "program -> stmt*" << endl;
            }
#line 1582 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 155 "parser.y" /* yacc.c:1646  */
    {
                cout << "stmts -> stmt stmts" << endl;
            }
#line 1590 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 159 "parser.y" /* yacc.c:1646  */
    {
                cout << "stmts -> " << endl;
            }
#line 1598 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 165 "parser.y" /* yacc.c:1646  */
    {
                isindex = 0;

                cout << "stmt -> expr;" << endl;

                lwarning = false;
                isnt     = false;
                isLib = false;

                if(isLogic) {

                    (yyvsp[-1].exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                    (yyvsp[-1].exprValue)->sym->space=currscopespace();

                    isLogic = false;
                    struct expr* e = new_expr(constbool_e);
                    e->boolConst = 1;
                    emit(assign, e, nullptr, (yyvsp[-1].exprValue), 0, yylineno);

                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                    e = new_expr(constbool_e);
                    e->boolConst = 0;
                    emit(assign, e, nullptr, (yyvsp[-1].exprValue), 0, yylineno);

                    backpatch((yyvsp[-1].exprValue)->truelist, nextquadlabel() - 3);
                    backpatch((yyvsp[-1].exprValue)->falselist, nextquadlabel() - 1);
                
                }
                tempcounter = 0;
            }
#line 1634 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 196 "parser.y" /* yacc.c:1646  */
    { 
                cout << "stmt -> ifstmt" << endl; 
            }
#line 1642 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 199 "parser.y" /* yacc.c:1646  */
    { cout << "stmt -> whilestmt" << endl; }
#line 1648 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 200 "parser.y" /* yacc.c:1646  */
    { cout << "stmt -> forstmt" << endl; }
#line 1654 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 201 "parser.y" /* yacc.c:1646  */
    { cout << "stmt -> returnstmt" << endl; }
#line 1660 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 203 "parser.y" /* yacc.c:1646  */
    {
                cout << "stmt -> break" << endl;
                if(break_quads.size()>0)
                    break_quads.at(break_quads.size()-1).push_back(nextquadlabel());
                break_counter++;

                //loop_counter--;
                if(break_continues_belong.size() == 0){
                    cout << "\033[1;31m" <<
                        "Can't use break here at line "<< yylineno <<
                        "\033[0m" << endl;
                    exit(-1);                        
                }else{
                    if(break_continues_belong.back()=="function"){
                        cout << "\033[1;31m" <<
                        "Can't use break inside of a function at line "<< yylineno <<
                        "\033[0m" << endl;
                        exit(-1);  
                    }
                }

                
                
                emit(jump,nullptr, nullptr, nullptr, 0, yylineno);

            }
#line 1691 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 230 "parser.y" /* yacc.c:1646  */
    { 
                if(loop_intersect){
                    loop_intersect = 0;
                    false_jumps.push_back(0);
                    
                }
                false_jumps.push_back(nextquadlabel() - 1);
                break_vector.push_back(nextquadlabel() - 2);
            }
#line 1705 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 240 "parser.y" /* yacc.c:1646  */
    {
                cout << "stmt -> continue" << endl;
                if(continue_quads.size()>0)
                    continue_quads.at(continue_quads.size()-1).push_back(nextquadlabel());
                continue_counter++;

                if(break_continues_belong.size() == 0){
                    cout << "\033[1;31m" << 
                        "Can't use continue outside of loops at line "<< yylineno <<
                        "\033[0m" << endl;
                        exit(-1);  
                }else{
                    if(break_continues_belong.back()=="function"){
                        cout << "\033[1;31m" <<
                        "Can't use continue inside of a function at line "<< yylineno <<
                        "\033[0m" << endl;
                        exit(-1);  
                    }
                }

                
                
                emit(jump,nullptr, nullptr, nullptr, 0, yylineno);
                
            }
#line 1735 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 266 "parser.y" /* yacc.c:1646  */
    { 
                cout << "program -> stmt*" << endl;

                continue_vector.push_back(nextquadlabel() - 2);
            }
#line 1745 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 271 "parser.y" /* yacc.c:1646  */
    { cout << "stmt -> block" << endl; }
#line 1751 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 272 "parser.y" /* yacc.c:1646  */
    { cout << "stmt -> funcdef" << endl; }
#line 1757 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 273 "parser.y" /* yacc.c:1646  */
    { cout << "stmt -> ;" << endl; }
#line 1763 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 277 "parser.y" /* yacc.c:1646  */
    { 
                cout << "expr -> assignexpr" << endl;
                (yyval.exprValue) = (yyvsp[0].exprValue);
                
            }
#line 1773 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 283 "parser.y" /* yacc.c:1646  */
    { 
                cout << "expr -> expr + expr" << endl;
                (yyval.exprValue) = new_expr(arithexpr_e);
                (yyval.exprValue)->sym = assign_temp((yyvsp[-2].exprValue),(yyvsp[0].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                (yyval.exprValue)->sym->space = currscopespace();
                // if($1->type == constnum_e && $3->type == constnum_e){
                //         $$->type = constnum_e;
                // }
        
                operation_list.push_back(nextquadlabel());
                emit(add, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), (yyval.exprValue), 0 ,yylineno);
            }
#line 1790 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 296 "parser.y" /* yacc.c:1646  */
    {
                cout << "expr -> expr - expr" << endl;
                (yyval.exprValue) = new_expr(arithexpr_e);
                (yyval.exprValue)->sym = assign_temp((yyvsp[-2].exprValue),(yyvsp[0].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                (yyval.exprValue)->sym->space = currscopespace();
                // if($1->type == constnum_e && $3->type == constnum_e){
                //         $$->type = constnum_e;
                // }
                emit(sub, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), (yyval.exprValue), 0 ,yylineno);
            }
#line 1805 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 307 "parser.y" /* yacc.c:1646  */
    {
                cout << "expr -> expr * expr" << endl;
                (yyval.exprValue) = new_expr(arithexpr_e);
                (yyval.exprValue)->sym = assign_temp((yyvsp[-2].exprValue),(yyvsp[0].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                (yyval.exprValue)->sym->space = currscopespace();
                // if($1->type == constnum_e && $3->type == constnum_e){
                //         $$->type = constnum_e;
                // }
                emit(mul, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), (yyval.exprValue), 0 ,yylineno);
            }
#line 1820 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 318 "parser.y" /* yacc.c:1646  */
    {
                cout << "expr -> expr / expr" << endl;
                (yyval.exprValue) = new_expr(arithexpr_e);
                (yyval.exprValue)->sym = assign_temp((yyvsp[-2].exprValue),(yyvsp[0].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                (yyval.exprValue)->sym->space = currscopespace();
                // if($1->type == constnum_e && $3->type == constnum_e){
                //         $$->type = constnum_e;
                // }
                emit(_div, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), (yyval.exprValue), 0 ,yylineno);
            }
#line 1835 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 329 "parser.y" /* yacc.c:1646  */
    { 
                cout << "expr -> expr % expr" << endl;
                (yyval.exprValue) = new_expr(arithexpr_e);
                (yyval.exprValue)->sym = assign_temp((yyvsp[-2].exprValue),(yyvsp[0].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                (yyval.exprValue)->sym->space = currscopespace();
                // if($1->type == constnum_e && $3->type == constnum_e){
                //         $$->type = constnum_e;
                // }
                emit(mod, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), (yyval.exprValue), 0 ,yylineno);
            }
#line 1850 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 340 "parser.y" /* yacc.c:1646  */
    {
                cout << "expr -> expr > expr" << endl;
                
                if(isnt) {
                    expr *e = new_expr(constbool_e);
                    e->boolConst = 1;
                    emit(assign, e, nullptr, (yyval.exprValue), 0, yylineno);

                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                    e = new_expr(constbool_e);
                    e->boolConst = 0;
                    emit(assign, e, nullptr, (yyval.exprValue), 0, yylineno);
                    backpatch((yyvsp[-2].exprValue)->truelist, nextquadlabel() - 3);
                    backpatch((yyvsp[-2].exprValue)->falselist, nextquadlabel() - 1);

                    isnt = false;
                }

                isLogic = true;
                isrelop = true;


                (yyval.exprValue) = new_expr(boolexpr_e);
                //$$->sym = assign_temp($1, $3, SCOPE, yylineno, FUNC_DEPTH);

                // if($1->type == constnum_e && $3->type == constnum_e){
                //     $$->type = constbool_e;
                // }

                (yyval.exprValue)->truelist.push_back(nextquadlabel());
                (yyval.exprValue)->falselist.push_back(nextquadlabel()+1);
                emit(if_greater, (yyvsp[-2].exprValue) , (yyvsp[0].exprValue), nullptr, nextquadlabel() + 2, yylineno);  
                emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 3, yylineno);

            }
#line 1891 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 377 "parser.y" /* yacc.c:1646  */
    { 
                cout << "expr -> expr >= expr" << endl;
                
                if(isnt) {
                    expr *e = new_expr(constbool_e);
                    e->boolConst = 1;
                    emit(assign, e, nullptr, (yyval.exprValue), 0, yylineno);

                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                    e = new_expr(constbool_e);
                    e->boolConst = 0;
                    emit(assign, e, nullptr, (yyval.exprValue), 0, yylineno);
                    backpatch((yyvsp[-2].exprValue)->truelist, nextquadlabel() - 3);
                    backpatch((yyvsp[-2].exprValue)->falselist, nextquadlabel() - 1);

                    isnt = false;
                }

                (yyval.exprValue) = new_expr(boolexpr_e);
                //$$->sym = assign_temp($1, $3, SCOPE, yylineno, FUNC_DEPTH);
                isLogic = true;               
                isrelop = true;
                

                // if($1->type == constnum_e && $3->type == constnum_e){
                //     $$->type = constbool_e;
                // }
                
                (yyval.exprValue)->truelist.push_back(nextquadlabel());
                emit(if_greatereq, (yyvsp[-2].exprValue) , (yyvsp[0].exprValue), nullptr, nextquadlabel() + 2, yylineno);
                
                (yyval.exprValue)->falselist.push_back(nextquadlabel());
                emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 3, yylineno);
            }
#line 1931 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 413 "parser.y" /* yacc.c:1646  */
    {
                cout << "expr -> expr < expr" << endl; 
                
                if(isnt) {
                    expr *e = new_expr(constbool_e);
                    e->boolConst = 1;
                    emit(assign, e, nullptr, (yyval.exprValue), 0, yylineno);

                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                    e = new_expr(constbool_e);
                    e->boolConst = 0;
                    emit(assign, e, nullptr, (yyval.exprValue), 0, yylineno);
                    backpatch((yyvsp[-2].exprValue)->truelist, nextquadlabel() - 3);
                    backpatch((yyvsp[-2].exprValue)->falselist, nextquadlabel() - 1);

                    isnt = false;
                }

                (yyval.exprValue) = new_expr(boolexpr_e);
                //$$->sym = assign_temp($1, $3, SCOPE, yylineno, FUNC_DEPTH);
                isLogic = true;
                isrelop = true;

                // if($1->type == constnum_e && $3->type == constnum_e){
                //     $$->type = constbool_e;
                // }
                
                (yyval.exprValue)->truelist.push_back(nextquadlabel());
                emit(if_less, (yyvsp[-2].exprValue) , (yyvsp[0].exprValue), nullptr, nextquadlabel() + 2, yylineno);
                
                (yyval.exprValue)->falselist.push_back(nextquadlabel());
                emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 3, yylineno);
            }
#line 1970 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 448 "parser.y" /* yacc.c:1646  */
    {
                cout << "expr -> expr <= expr" << endl; 
                
                if(isnt) {

                    expr *e = new_expr(constbool_e);
                    e->boolConst = 1;
                    emit(assign, e, nullptr, (yyval.exprValue), 0, yylineno);

                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                    e = new_expr(constbool_e);
                    e->boolConst = 0;
                    emit(assign, e, nullptr, (yyval.exprValue), 0, yylineno);
                    backpatch((yyvsp[-2].exprValue)->truelist, nextquadlabel() - 3);
                    backpatch((yyvsp[-2].exprValue)->falselist, nextquadlabel() - 1);

                    isnt = false;
                }

                (yyval.exprValue) = new_expr(boolexpr_e);
                //$$->sym = assign_temp($1, $3, SCOPE, yylineno, FUNC_DEPTH);
                isLogic = true;
                isrelop = true;
               
                // if($1->type == constnum_e && $3->type == constnum_e){
                //     $$->type = constbool_e;
                // }
                
                (yyval.exprValue)->truelist.push_back(nextquadlabel());
                emit(if_lesseq, (yyvsp[-2].exprValue) , (yyvsp[0].exprValue), nullptr, nextquadlabel() + 2, yylineno);
                
                (yyval.exprValue)->falselist.push_back(nextquadlabel());
                emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 3, yylineno);

            }
#line 2011 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 485 "parser.y" /* yacc.c:1646  */
    {
                cout << "expr -> expr == expr" << endl;
                
                if(isnt) {
                    expr *e = new_expr(constbool_e);
                    e->boolConst = 1;
                    emit(assign, e, nullptr, (yyval.exprValue), 0, yylineno);

                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                    e = new_expr(constbool_e);
                    e->boolConst = 0;
                    emit(assign, e, nullptr, (yyval.exprValue), 0, yylineno);
                    backpatch((yyvsp[-2].exprValue)->truelist, nextquadlabel() - 3);
                    backpatch((yyvsp[-2].exprValue)->falselist, nextquadlabel() - 1);

                    isnt = false;
                }

                (yyval.exprValue) = new_expr(boolexpr_e);
                //$$->sym = assign_temp($1, $3, SCOPE, yylineno, FUNC_DEPTH);
                isLogic = true;
                isrelop = true;
                
                // if($1->type == $3->type){
                //     $$->type = constbool_e;
                // }
                
                (yyval.exprValue)->truelist.push_back(nextquadlabel());
                emit(if_eq, (yyvsp[-2].exprValue) , (yyvsp[0].exprValue), nullptr, nextquadlabel() + 2, yylineno);
                
                (yyval.exprValue)->falselist.push_back(nextquadlabel());
                emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 3, yylineno);
            }
#line 2050 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 520 "parser.y" /* yacc.c:1646  */
    { 
                cout << "expr -> expr != expr" << endl; 
                
                if(isnt) {

                    expr *e = new_expr(constbool_e);
                    e->boolConst = 1;
                    emit(assign, e, nullptr, (yyval.exprValue), 0, yylineno);

                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                    e = new_expr(constbool_e);
                    e->boolConst = 0;
                    emit(assign, e, nullptr, (yyval.exprValue), 0, yylineno);
                    backpatch((yyvsp[-2].exprValue)->truelist, nextquadlabel() - 3);
                    backpatch((yyvsp[-2].exprValue)->falselist, nextquadlabel() - 1);

                    isnt = false;
                }

                (yyval.exprValue) = new_expr(boolexpr_e);
                //$$->sym = assign_temp($1, $3, SCOPE, yylineno, FUNC_DEPTH);
                isLogic = true;
                isrelop=true;

                // if($1->type == $3->type){
                //     $$->type = constbool_e;
                // }
                
                (yyval.exprValue)->truelist.push_back(nextquadlabel());
                emit(if_noteq, (yyvsp[-2].exprValue) , (yyvsp[0].exprValue), nullptr, nextquadlabel() + 2, yylineno);
                
                (yyval.exprValue)->falselist.push_back(nextquadlabel());
                emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 3, yylineno);
            }
#line 2090 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 555 "parser.y" /* yacc.c:1646  */
    {
                if((yyvsp[-1].exprValue)->truelist.empty()){
                    (yyvsp[-1].exprValue)->truelist.push_back(nextquadlabel());
                    expr* e=new_expr(constbool_e);
                    e->boolConst=1;
                    emit(if_eq, (yyvsp[-1].exprValue), e,nullptr, nextquadlabel() + 2, yylineno);
                    (yyvsp[-1].exprValue)->falselist.push_back(nextquadlabel());
                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);
                }
            }
#line 2105 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 565 "parser.y" /* yacc.c:1646  */
    { 
                isLib=false;
                cout << "expr -> expr && expr" << endl; 
                (yyval.exprValue) = new_expr(boolexpr_e);
                isLogic = true;
                (yyval.exprValue)->sym = assign_temp((yyvsp[-4].exprValue),(yyvsp[0].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                (yyval.exprValue)->sym->space = currscopespace();
                // if($1->type == constbool_e && $5->type == constbool_e){
                //     $$->type = constbool_e;
                // }

                if ((yyvsp[0].exprValue)->truelist.empty()) {
                    (yyvsp[0].exprValue)->truelist.push_back(nextquadlabel());
                    expr* e=new_expr(constbool_e);
                    e->boolConst=1;
                    emit(if_eq, (yyvsp[0].exprValue), e,nullptr, nextquadlabel() + 2, yylineno);
                    (yyvsp[0].exprValue)->falselist.push_back(nextquadlabel());
                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);
                }

                
                backpatch((yyvsp[-4].exprValue)->truelist, (yyvsp[-1].unsdValue));
                
                for(int i=0; i<(yyvsp[-4].exprValue)->falselist.size(); i++){
                    (yyval.exprValue)->falselist.push_back((yyvsp[-4].exprValue)->falselist.at(i));
                }
                for(int i=0; i<(yyvsp[0].exprValue)->falselist.size(); i++){
                    (yyval.exprValue)->falselist.push_back((yyvsp[0].exprValue)->falselist.at(i));
                }

                (yyval.exprValue)->truelist = (yyvsp[0].exprValue)->truelist;
            }
#line 2142 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 597 "parser.y" /* yacc.c:1646  */
    {
                if((yyvsp[-1].exprValue)->truelist.empty()){
                    (yyvsp[-1].exprValue)->truelist.push_back(nextquadlabel());
                    expr* e=new_expr(constbool_e);
                    e->boolConst=1;
                    emit(if_eq, (yyvsp[-1].exprValue), e,nullptr, nextquadlabel() + 2, yylineno);
                    (yyvsp[-1].exprValue)->falselist.push_back(nextquadlabel());
                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);
                }
            }
#line 2157 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 607 "parser.y" /* yacc.c:1646  */
    { 
                isLib=false;
                cout << "expr -> expr || expr" << endl;
                (yyval.exprValue) = new_expr(boolexpr_e);
                (yyval.exprValue)->sym = assign_temp((yyvsp[-4].exprValue),(yyvsp[0].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                (yyval.exprValue)->sym->space = currscopespace();
                isLogic=true;
                // if($1->type == constbool_e && $5->type == constbool_e){
                //     $$->type = constbool_e;
                // }

                if ((yyvsp[0].exprValue)->truelist.empty()) {
                    (yyvsp[0].exprValue)->truelist.push_back(nextquadlabel());
                    expr* e=new_expr(constbool_e);
                    e->boolConst=1;
                    emit(if_eq, (yyvsp[0].exprValue), e,nullptr, nextquadlabel() + 2, yylineno);
                    (yyvsp[0].exprValue)->falselist.push_back(nextquadlabel());
                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);
                }

                

                backpatch((yyvsp[-4].exprValue)->falselist, (yyvsp[-1].unsdValue));

                
                for(int i=0; i<(yyvsp[-4].exprValue)->truelist.size(); i++){
                    (yyval.exprValue)->truelist.push_back((yyvsp[-4].exprValue)->truelist.at(i));
                }
                for(int i=0; i<(yyvsp[0].exprValue)->truelist.size(); i++){
                    (yyval.exprValue)->truelist.push_back((yyvsp[0].exprValue)->truelist.at(i));
                }

                (yyval.exprValue)->falselist = (yyvsp[0].exprValue)->falselist;
 
            }
#line 2197 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 643 "parser.y" /* yacc.c:1646  */
    {
                cout << "expr -> term" << endl; 
                (yyval.exprValue) = (yyvsp[0].exprValue);
            }
#line 2206 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 650 "parser.y" /* yacc.c:1646  */
    {
                (yyval.unsdValue) = nextquadlabel();
            }
#line 2214 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 655 "parser.y" /* yacc.c:1646  */
    {
                cout << "term -> (expr)" << endl;
                (yyval.exprValue) = (yyvsp[-1].exprValue);
            }
#line 2223 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 660 "parser.y" /* yacc.c:1646  */
    {
                cout << "term -> primary" << endl; 
                (yyval.exprValue) = (yyvsp[0].exprValue);
            }
#line 2232 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 665 "parser.y" /* yacc.c:1646  */
    {
                cout << "term -> -expr" << endl; 

                //check_arith($expr, "Cannot use uminus operator to a not aritmentic expression ", yylineno);
                (yyval.exprValue) = new_expr(arithexpr_e);
                (yyval.exprValue)->sym = istempexpr((yyvsp[0].exprValue)) ? (yyvsp[0].exprValue)->sym : newtemp(SCOPE, yylineno, FUNC_DEPTH);
                (yyval.exprValue)->sym->space = currscopespace();
                emit(uminus,(yyvsp[0].exprValue), nullptr, (yyval.exprValue), 0, yylineno);
            }
#line 2246 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 676 "parser.y" /* yacc.c:1646  */
    {
                cout << "term -> ++lvalue" << endl;

                SymbolTableEntry *entry_ptr = Lookup(create_entry(GLOBAL_ID,0,0,LLOCAL,FUNC_DEPTH), SCOPE);
                if(isFunction(*entry_ptr) && !isindex){
                    cout << "\033[1;31m" << 
                        "Function used as lvalue (++function)  at line "<< yylineno <<
                        "\033[0m" << endl;
                        exit(-1);  
                }

                //check_arith($lvalue, "Cannot use pre increment operator to a not aritmentic expression ", yylineno);
                if ((yyvsp[0].exprValue)->type == tableitem_e) {

                    (yyval.exprValue) = emit_iftableitem((yyvsp[0].exprValue), SCOPE, yylineno, FUNC_DEPTH);

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(add, (yyval.exprValue), e, (yyval.exprValue), 0, yylineno);
                    emit(tablesetelem, (yyvsp[0].exprValue)->index, (yyval.exprValue), (yyvsp[0].exprValue), 0, yylineno);
                }
                else {

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(add, (yyvsp[0].exprValue), e, (yyvsp[0].exprValue), 0, yylineno);
                    (yyval.exprValue) = new_expr(arithexpr_e);
                    (yyval.exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                    (yyval.exprValue)->sym->space = currscopespace();
                    emit(assign, (yyvsp[0].exprValue), nullptr, (yyval.exprValue), 0, yylineno);
                }
            }
#line 2285 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 712 "parser.y" /* yacc.c:1646  */
    {
                SymbolTableEntry *entry_ptr = Lookup(create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH), SCOPE);
                if(isFunction(*entry_ptr) && !isindex){
                    cout << "\033[1;31m" << 
                        "Function used as lvalue (function++)  at line "<< yylineno <<
                        "\033[0m" << endl;
                    exit(-1);  
                }
            }
#line 2299 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 722 "parser.y" /* yacc.c:1646  */
    {
                cout << "term -> lvalue++" << endl;

                //check_arith($lvalue, "Cannot use post increment operator to a not aritmentic expression ", yylineno);
                (yyval.exprValue) = new_expr(var_e);
                (yyval.exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                (yyval.exprValue)->sym->space = currscopespace();
                if ((yyvsp[-2].exprValue)->type == tableitem_e) {

                    expr* val = emit_iftableitem((yyvsp[-2].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                    emit(assign, val, NULL, (yyval.exprValue), 0, yylineno);

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(add, val, e, val,  0, yylineno);
                    emit(tablesetelem, (yyvsp[-2].exprValue)->index, val, (yyvsp[-2].exprValue), 0, yylineno);
                }
                else {
                    emit(assign, (yyvsp[-2].exprValue), nullptr, (yyval.exprValue), 0, yylineno);

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(add, (yyvsp[-2].exprValue), e, (yyvsp[-2].exprValue), 0, yylineno);
                }
            }
#line 2331 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 752 "parser.y" /* yacc.c:1646  */
    {
                cout << "term -> --lvalue" << endl;

                SymbolTableEntry *entry_ptr = Lookup(create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH), SCOPE);
                if(isFunction(*entry_ptr) && !isindex){
                    cout << "\033[1;31m" << 
                        "Function used as lvalue (--function)  at line "<< yylineno <<
                        "\033[0m" << endl;
                    exit(-1);  
                }

                //check_arith($lvalue, "Cannot use pre decrement operator to a not aritmentic expression ", yylineno);
                if ((yyvsp[0].exprValue)->type == tableitem_e) {

                    (yyval.exprValue) = emit_iftableitem((yyvsp[0].exprValue), SCOPE, yylineno, FUNC_DEPTH);

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(sub, (yyval.exprValue), e, (yyval.exprValue), 0, yylineno);
                    emit(tablesetelem, (yyvsp[0].exprValue)->index, (yyval.exprValue), (yyvsp[0].exprValue), 0, yylineno);
                }
                else {

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(sub, (yyvsp[0].exprValue), e, (yyvsp[0].exprValue), 0, yylineno);
                    (yyval.exprValue) = new_expr(arithexpr_e);
                    (yyval.exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                    (yyval.exprValue)->sym->space = currscopespace();
                    emit(assign, (yyvsp[0].exprValue), nullptr, (yyval.exprValue), 0, yylineno);
                }
            }
#line 2370 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 788 "parser.y" /* yacc.c:1646  */
    {
                SymbolTableEntry *entry_ptr = Lookup(create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH), SCOPE);
                if(isFunction(*entry_ptr) && !isindex){
                    cout << "\033[1;31m" << 
                        "Function used as lvalue (function--)  at line "<< yylineno <<
                        "\033[0m" << endl;
                    exit(-1);  
                }
            }
#line 2384 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 798 "parser.y" /* yacc.c:1646  */
    {
                cout << "term -> lvalue--" << endl;

                //check_arith($lvalue, "Cannot use post decrement operator to a not aritmentic expression ", yylineno);
                (yyval.exprValue) = new_expr(var_e);
                (yyval.exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                (yyval.exprValue)->sym->space = currscopespace();
                if ((yyvsp[-2].exprValue)->type == tableitem_e) {

                    expr* val = emit_iftableitem((yyvsp[-2].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                    emit(assign, val, NULL, (yyval.exprValue), 0, yylineno);

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(sub, val, e, val,  0, yylineno);
                    emit(tablesetelem, (yyvsp[-2].exprValue)->index, val, (yyvsp[-2].exprValue), 0, yylineno);
                }
                else {
                    emit(assign, (yyvsp[-2].exprValue), nullptr, (yyval.exprValue), 0, yylineno);

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(sub, (yyvsp[-2].exprValue), e, (yyvsp[-2].exprValue), 0, yylineno);
                }
            }
#line 2416 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 826 "parser.y" /* yacc.c:1646  */
    {
                cout << "term -> !expr" << endl;

                isLogic = true;
                isnt    = true;
               

                (yyval.exprValue) = new_expr(boolexpr_e);
                (yyval.exprValue)->sym = istempexpr((yyvsp[0].exprValue)) ? (yyvsp[0].exprValue)->sym : newtemp(SCOPE, yylineno, FUNC_DEPTH);
                (yyval.exprValue)->sym->space = currscopespace();
                if ((yyvsp[0].exprValue)->truelist.empty()) {
                    (yyvsp[0].exprValue)->truelist.push_back(nextquadlabel());
                    expr* e=new_expr(constbool_e);
                    e->boolConst=1;
                    emit(if_eq, (yyvsp[0].exprValue) , e, nullptr, nextquadlabel() + 2, yylineno);
                
                    (yyvsp[0].exprValue)->falselist.push_back(nextquadlabel());
                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 3, yylineno);

                    (yyval.exprValue)->falselist = (yyvsp[0].exprValue)->truelist;
                    (yyval.exprValue)->truelist =  (yyvsp[0].exprValue)->falselist;                        

                }  else {
                    (yyval.exprValue)->falselist = (yyvsp[0].exprValue)->truelist;
                    (yyval.exprValue)->truelist =  (yyvsp[0].exprValue)->falselist;
                }              
            }
#line 2448 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 856 "parser.y" /* yacc.c:1646  */
    {
                        cout << "primary -> lvalue" << endl;

                        (yyval.exprValue) = emit_iftableitem((yyvsp[0].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                    }
#line 2458 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 862 "parser.y" /* yacc.c:1646  */
    {
                cout << "primary -> call" << endl;
            }
#line 2466 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 866 "parser.y" /* yacc.c:1646  */
    {
                cout << "primary -> objectdef" << endl;
            }
#line 2474 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 870 "parser.y" /* yacc.c:1646  */
    {
                cout << "primary -> (funcdef)" << endl;

                (yyval.exprValue) = new_expr(programfunc_e);
                (yyval.exprValue)->sym = (yyvsp[-1].symbValue);
                (yyval.exprValue)->sym->space = currscopespace(); 
            }
#line 2486 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 877 "parser.y" /* yacc.c:1646  */
    { cout << "primary -> const" << endl; }
#line 2492 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 881 "parser.y" /* yacc.c:1646  */
    {   
                cout << "lvalue -> id" << endl;

                GLOBAL_ID = (yyvsp[0].stringValue);

                SymbolTableEntry * entry_ptr = Lookup(create_entry((yyvsp[0].stringValue),0,0,LLOCAL, FUNC_DEPTH),SCOPE);
                SymbolTableEntry entry=create_entry((yyvsp[0].stringValue), SCOPE, yylineno, GLOBAL, FUNC_DEPTH);
                if(entry_ptr== NULL ){
                    
                    entry.space  = currscopespace();
                    entry.offset = currscopeoffset();
                    inccurentscopeoffset();
                    cout << currscopeoffset() << " name " << entry.value.varVal->name << endl << endl;

                    if(SCOPE==0){
                        Insert(entry);
                        (yyval.exprValue) = lvalue_expr(update_entry(entry));         
                    }
                    else{
                        entry.type=LLOCAL;
                        Insert(entry);
                        (yyval.exprValue) = lvalue_expr(update_entry(entry));

                    }
                } else{
                    if(isFunction(*entry_ptr)) lwarning = true;
                    
                    if(entry_ptr->type!=USERFUNC&&entry_ptr->type!=LIBFUNC&&entry_ptr->value.varVal->scope!=0){
                        if(get_func_depth(*entry_ptr)!=get_func_depth(entry)){
                            cout << "\033[1;31m" << 
                            "Can't access this var at line "<< yylineno <<
                            "\033[0m" << endl;
                        exit(-1);  
                        }
                    }
                    (yyval.exprValue) = lvalue_expr(update_entry(*entry_ptr));
                }
            }
#line 2535 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 920 "parser.y" /* yacc.c:1646  */
    {
                cout << "lvalue -> local id" << endl;

                GLOBAL_ID=(yyvsp[0].stringValue);
                SymbolTableEntry entry = create_entry((yyvsp[0].stringValue), SCOPE, yylineno, GLOBAL, FUNC_DEPTH);
                SymbolTableEntry *entry_ptr = Lookup_scope(entry, SCOPE);
                if(entry_ptr==NULL){

                    entry.space  = currscopespace();
                    entry.offset = currscopeoffset();
                    inccurentscopeoffset();
                    cout << currscopeoffset() << " name " << entry.value.varVal->name << endl << endl;

                    if(SCOPE==0){
                        Insert_local(entry);
                        (yyval.exprValue) = lvalue_expr(update_entry(entry));
                    }
                    else{
                        entry.type = LLOCAL;
                        Insert_local(entry);
                        (yyval.exprValue) = lvalue_expr(update_entry(entry));
                    }
                }else if(entry_ptr->type == LIBFUNC){
                    cout << "\033[1;31m" << 
                    "Collision with library function at line "<< yylineno <<
                    "\033[0m" << endl;
                exit(-1);  
                }
                else {
                    if(isFunction(*entry_ptr)) lwarning = true;
                    (yyval.exprValue) = lvalue_expr(update_entry(*entry_ptr));
                }
            }
#line 2573 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 954 "parser.y" /* yacc.c:1646  */
    {
                cout << "lvalue -> ::id" << endl;

                if(!Lookup_scope(create_entry((yyvsp[0].stringValue),0,0,LLOCAL, FUNC_DEPTH),0)){
                    cout << "\033[1;31m" << 
                    "Global id not found at line "<< yylineno <<
                    "\033[0m" << endl;
                exit(-1);  
                }else
                    (yyval.exprValue) = lvalue_expr(update_entry(*Lookup_scope(create_entry((yyvsp[0].stringValue),0,0,LLOCAL, FUNC_DEPTH),0)  ));
            }
#line 2589 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 966 "parser.y" /* yacc.c:1646  */
    {
                cout << "lvalue -> member" << endl;
                (yyval.exprValue) = (yyvsp[0].exprValue);
            }
#line 2598 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 973 "parser.y" /* yacc.c:1646  */
    {  
                SymbolTableEntry entry = create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH);
                SymbolTableEntry *entry_ptr = Lookup(entry,SCOPE);
                if(entry_ptr){      
                    if(isFunction(*entry_ptr) && lwarning && !isindex){
                            cout << "\033[1;31m" << 
                            "Function used as lvalue at line "<< yylineno <<
                            "\033[0m" << endl;
                            exit(-1);  

                            lwarning = false;
                        
                    }
                }
             }
#line 2618 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 989 "parser.y" /* yacc.c:1646  */
    {
                cout << "assignexpr -> lvalue = expr" << endl;

                
                if((yyvsp[-3].exprValue)->type != tableitem_e)
                {
                    if(!(yyvsp[0].exprValue)->truelist.empty()) {

                        (yyvsp[0].exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                        (yyvsp[0].exprValue)->sym->space=currscopespace();
                        struct expr* e = new_expr(constbool_e);
                        e->boolConst = 1;
                        
                        emit(assign, e, nullptr, (yyvsp[0].exprValue), 0, yylineno);

                        emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                        e = new_expr(constbool_e);
                        e->boolConst = 0;
                        emit(assign, e, nullptr, (yyvsp[0].exprValue), 0, yylineno);
                        
                        backpatch((yyvsp[0].exprValue)->truelist, nextquadlabel() - 3);
                        backpatch((yyvsp[0].exprValue)->falselist, nextquadlabel() - 1);
                        isLogic=false;

                        emit(assign, (yyvsp[0].exprValue), nullptr, (yyvsp[-3].exprValue), 0, yylineno);
                        (yyval.exprValue) = new_expr(assignexpr_e);
                        (yyval.exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                        (yyval.exprValue)->sym->space=currscopespace();
                        emit(assign, (yyvsp[-3].exprValue), nullptr, (yyval.exprValue), 0, yylineno);
                        
                    }else{
                        
                        emit(assign, (yyvsp[0].exprValue), nullptr, (yyvsp[-3].exprValue), 0, yylineno);
                        (yyval.exprValue) = new_expr(assignexpr_e);
                        (yyval.exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                        (yyval.exprValue)->sym->space=currscopespace();
                        emit(assign, (yyvsp[-3].exprValue), nullptr, (yyval.exprValue), 0, yylineno);
                    }
                }
                else
                {
                    isnt = false;
                    isLib = false;
                    if(isLogic) {

                        (yyvsp[0].exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                        (yyvsp[0].exprValue)->sym->space=currscopespace();

                        isLogic = false;
                        struct expr* e = new_expr(constbool_e);
                        e->boolConst = 1;
                        emit(assign, e, nullptr, (yyvsp[0].exprValue), 0, yylineno);

                        emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                        e = new_expr(constbool_e);
                        e->boolConst = 0;
                        emit(assign, e, nullptr, (yyvsp[0].exprValue), 0, yylineno);

                        backpatch((yyvsp[0].exprValue)->truelist, nextquadlabel() - 3);
                        backpatch((yyvsp[0].exprValue)->falselist, nextquadlabel() - 1);
                    
                    }

                    emit(tablesetelem, (yyvsp[-3].exprValue)->index, (yyvsp[0].exprValue), (yyvsp[-3].exprValue), 0, yylineno);
                    (yyval.exprValue) = emit_iftableitem((yyvsp[-3].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                    (yyval.exprValue)->type = assignexpr_e;
                }
               
            }
#line 2694 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 1060 "parser.y" /* yacc.c:1646  */
    {
                cout << "\033[1;31m" << 
                        "Function used as lvalue at line "<< yylineno <<
                        "\033[0m" << endl;
                    exit(-1);  
            }
#line 2705 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 1068 "parser.y" /* yacc.c:1646  */
    {lwarning = false;}
#line 2711 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 1069 "parser.y" /* yacc.c:1646  */
    {
                cout << "member -> lvalue.id" << endl;
                
                (yyvsp[-3].exprValue)   = emit_iftableitem((yyvsp[-3].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                
                expr* ti  = new_expr(tableitem_e); 
                ti->sym   = (yyvsp[-3].exprValue)->sym;
                
                ti->index = new_expr(conststring_e);
                ti->index->strConst = strdup((yyvsp[0].stringValue));
                
                string_table.push_back(ti->index->strConst);

                (yyval.exprValue) =  ti;

            }
#line 2732 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 1085 "parser.y" /* yacc.c:1646  */
    {isindex = 1;}
#line 2738 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 1086 "parser.y" /* yacc.c:1646  */
    { 
                                                cout << "member -> lvalue[expr]" << endl;
                                                (yyvsp[-4].exprValue)   = emit_iftableitem((yyvsp[-4].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                                                expr* ti  = new_expr(tableitem_e); 
                                                ti->sym   = (yyvsp[-4].exprValue)->sym;

                                                ti->index = (yyvsp[-1].exprValue);

                                                (yyval.exprValue) =  ti;
                                            }
#line 2753 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 1096 "parser.y" /* yacc.c:1646  */
    {lwarning = false;}
#line 2759 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 1097 "parser.y" /* yacc.c:1646  */
    { 
                                                cout << "member -> call.id" << endl; 
                                            }
#line 2767 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 1101 "parser.y" /* yacc.c:1646  */
    { 
                                                cout << "member -> call[expr]" << endl;

                                                (yyvsp[-3].exprValue)   = emit_iftableitem((yyvsp[-3].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                                                expr* ti  = new_expr(tableitem_e); 
                                                ti->sym   = (yyvsp[-3].exprValue)->sym;

                                                ti->index = (yyvsp[-1].exprValue);

                                                (yyval.exprValue) =  ti;
                                            }
#line 2783 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 1115 "parser.y" /* yacc.c:1646  */
    {
                cout << "call -> call (elist)" << endl;

                vector <expr*> reversed_elist;
                expr* temp = (yyvsp[-1].exprValue);
                while (temp) {
                    reversed_elist.push_back(temp);
                    temp = temp->next;
                }

                (yyval.exprValue) = make_call((yyvsp[-3].exprValue), reversed_elist, SCOPE, yylineno, FUNC_DEPTH);
            }
#line 2800 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 1128 "parser.y" /* yacc.c:1646  */
    { 
                cout << "call -> lvalue callsuffix" << endl; 

                vector <expr*> reversed_elist;
                expr* temp = (yyvsp[0].callValue)->elist;
                while (temp) {
                    reversed_elist.push_back(temp);
                    temp = temp->next;
                }

                (yyvsp[-1].exprValue) = emit_iftableitem((yyvsp[-1].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                if ((yyvsp[0].callValue)->method ){
                    expr* t = (yyvsp[-1].exprValue);
                    (yyvsp[-1].exprValue) = emit_iftableitem(member_item(t, (yyvsp[0].callValue)->name, SCOPE, yylineno, FUNC_DEPTH),
                                                                                 SCOPE, yylineno, FUNC_DEPTH);

                    if((yyvsp[0].callValue)->elist)
                        (yyvsp[0].callValue)->elist->next = t ;
                    reversed_elist.insert(reversed_elist.begin(), 1, t);
                }
                (yyval.exprValue) = make_call((yyvsp[-1].exprValue), reversed_elist, SCOPE, yylineno, FUNC_DEPTH);
            }
#line 2827 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 1151 "parser.y" /* yacc.c:1646  */
    { 
                cout << "call -> (funcdef)(elist)" << endl; 

                expr* func = new_expr(programfunc_e);
                func->sym = (yyvsp[-4].symbValue);

                vector <expr*> reversed_elist;
                expr* temp = (yyvsp[-1].exprValue);
                while (temp) {
                    reversed_elist.push_back(temp);
                    temp = temp->next;
                }
                
                (yyval.exprValue) = make_call(func, reversed_elist, SCOPE, yylineno, FUNC_DEPTH);
            }
#line 2847 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 1169 "parser.y" /* yacc.c:1646  */
    {
                cout << "callsuffix -> normcall" << endl; 

                (yyval.callValue) = (yyvsp[0].callValue);
            }
#line 2857 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 1175 "parser.y" /* yacc.c:1646  */
    {
                cout << "callsuffix -> methodcall" << endl; 

                (yyval.callValue) = (yyvsp[0].callValue);
            }
#line 2867 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 1182 "parser.y" /* yacc.c:1646  */
    {isLib=true;}
#line 2873 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 1183 "parser.y" /* yacc.c:1646  */
    { 
                cout << "normcall -> (elist)" << endl;

                (yyval.callValue) = new struct call;
        
                (yyval.callValue)->elist = (yyvsp[-1].exprValue);
                (yyval.callValue)->method = 0;
                (yyval.callValue)->name = nullptr;
            }
#line 2887 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 1195 "parser.y" /* yacc.c:1646  */
    { 
                cout << "methodcall -> ..id(elist)" << endl;

                (yyval.callValue) = new struct call;

                string_table.push_back((yyvsp[-3].stringValue));

                (yyval.callValue)->elist = (yyvsp[-1].exprValue);
                (yyval.callValue)->method = 1;
                (yyval.callValue)->name = (yyvsp[-3].stringValue);
            }
#line 2903 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 1209 "parser.y" /* yacc.c:1646  */
    {
                cout<<isLib<<endl;
                if(isLogic && !isLib) {

                    (yyvsp[0].exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                    (yyvsp[0].exprValue)->sym->space = currscopespace();
                    isLogic = false;
                    isLib=false;
                    struct expr* e = new_expr(constbool_e);
                    e->boolConst = 1;
                    emit(assign, e, nullptr, (yyvsp[0].exprValue), 0, yylineno);

                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                    e = new_expr(constbool_e);
                    e->boolConst = 0;
                    emit(assign, e, nullptr, (yyvsp[0].exprValue), 0, yylineno);

                    backpatch((yyvsp[0].exprValue)->truelist, nextquadlabel() - 3);
                    backpatch((yyvsp[0].exprValue)->falselist, nextquadlabel() - 1);
                
                }
                isLogic = false;
                isLib=false;
                isnt = false;
            }
#line 2934 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 1236 "parser.y" /* yacc.c:1646  */
    {
                cout << "elist -> expr commaexpr" << endl; 

                (yyval.exprValue)->next  = (yyvsp[0].exprValue);
            }
#line 2944 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 1242 "parser.y" /* yacc.c:1646  */
    { 
                cout << "elist -> " << endl;

                (yyval.exprValue) = nullptr;
            }
#line 2954 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 1251 "parser.y" /* yacc.c:1646  */
    {
                cout<<isLib<<endl;
                if(isLogic && !isLib) {

                    (yyvsp[0].exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                    (yyvsp[0].exprValue)->sym->space = currscopespace();
                    isLogic = false;
                    isLib = false;
                    struct expr* e = new_expr(constbool_e);
                    e->boolConst = 1;
                    emit(assign, e, nullptr, (yyvsp[0].exprValue), 0, yylineno);

                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                    e = new_expr(constbool_e);
                    e->boolConst = 0;
                    emit(assign, e, nullptr, (yyvsp[0].exprValue), 0, yylineno);

                    backpatch((yyvsp[0].exprValue)->truelist, nextquadlabel() - 3);
                    backpatch((yyvsp[0].exprValue)->falselist, nextquadlabel() - 1);
                
                }
                isLib = false;
                isnt = false;
            }
#line 2984 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 1277 "parser.y" /* yacc.c:1646  */
    { 
                cout << "commaexpr -> ,expr commaexpr" << endl; 
                (yyval.exprValue) = (yyvsp[-2].exprValue);
                (yyval.exprValue)->next = (yyvsp[0].exprValue);
            }
#line 2994 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 1283 "parser.y" /* yacc.c:1646  */
    { 
                cout << "commaexpr -> " << endl; 

                (yyval.exprValue) = nullptr;
            }
#line 3004 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 1290 "parser.y" /* yacc.c:1646  */
    {isindex = 1;}
#line 3010 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 1291 "parser.y" /* yacc.c:1646  */
    {
                                                    cout << "objectdef -> [elist]" << endl; 

                                                    expr* t = new_expr(tableitem_e);
                                                    t->sym = newtemp_nolookup(SCOPE, yylineno, FUNC_DEPTH);
                                                    t->sym->space = currscopespace();
                                                    emit(tablecreate, nullptr, nullptr, t, 0, yylineno);

                                                    for (int i = 0; (yyvsp[-1].exprValue); (yyvsp[-1].exprValue) = (yyvsp[-1].exprValue)->next){
                                                        number_table.push_back(i);
                                                        
                                                        expr* e = new_expr(constnum_e);
                                                        e->numConst = i++;
                                                        emit(tablesetelem, e, (yyvsp[-1].exprValue), t, 0, yylineno);
                                                    } 
                                                    
                                                    (yyval.exprValue) = t;
                                                }
#line 3033 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 1310 "parser.y" /* yacc.c:1646  */
    { 
                                                    cout << "objectdef -> [indexed]" << endl;

                                                    expr* t = new_expr(tableitem_e);
                                                    t->sym = newtemp_nolookup(SCOPE, yylineno, FUNC_DEPTH);
                                                    t->sym->space = currscopespace();
                                                    emit(tablecreate, nullptr, nullptr, t, 0, yylineno);

                                                    expr* temp = (yyvsp[-1].exprValue);
                                                    while(temp) {
                                                        emit(tablesetelem, temp->index, temp, t, 0 , yylineno);
                                                        temp = temp->next;
                                                    }

                                                    (yyval.exprValue) = t;
                                                }
#line 3054 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 1329 "parser.y" /* yacc.c:1646  */
    {
                                                        cout << "indexed -> indexedelem commaindexedelem" << endl;

                                                        (yyval.exprValue)->next = (yyvsp[0].exprValue);
                                                    }
#line 3064 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 1336 "parser.y" /* yacc.c:1646  */
    {
                                                            cout << "commaindexelem -> ,indexelem commaindexelem" << endl;

                                                            (yyval.exprValue) = (yyvsp[-1].exprValue);
                                                            (yyval.exprValue)->next = (yyvsp[0].exprValue);
                                                        }
#line 3075 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1342 "parser.y" /* yacc.c:1646  */
    {
                                                            cout << "commaindexelem -> " << endl;

                                                            (yyval.exprValue) = nullptr;
                                                        }
#line 3085 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 1350 "parser.y" /* yacc.c:1646  */
    {
                        cout << "indexelem -> {expr:expr}" << endl;
                        if((yyvsp[-1].exprValue)->type == constnum_e){
                            (yyval.exprValue) = new_expr(constnum_e);
                            (yyval.exprValue)->numConst = (yyvsp[-1].exprValue)->numConst;
                        }
                        if((yyvsp[-1].exprValue)->type == constbool_e){
                            (yyval.exprValue) = new_expr(constbool_e);
                            (yyval.exprValue)->boolConst = (yyvsp[-1].exprValue)->boolConst;
                        }
                        if((yyvsp[-1].exprValue)->type == conststring_e){
                            (yyval.exprValue) = new_expr(conststring_e);
                            (yyval.exprValue)->strConst = (yyvsp[-1].exprValue)->strConst;
                        }
                        if((yyvsp[-1].exprValue)->type == arithexpr_e){
                            (yyval.exprValue) = new_expr(arithexpr_e);
                            (yyval.exprValue)->sym = (yyvsp[-1].exprValue)->sym;
                        }
                        if((yyvsp[-1].exprValue)->type == boolexpr_e){
                            (yyval.exprValue) = new_expr(boolexpr_e);
                            (yyval.exprValue)->sym = (yyvsp[-1].exprValue)->sym;
                        }
                        if((yyvsp[-1].exprValue)->type == var_e){
                            (yyval.exprValue) = new_expr(var_e);
                            (yyval.exprValue)->sym = (yyvsp[-1].exprValue)->sym;

                        }if((yyvsp[-1].exprValue)->type == tableitem_e){
                            (yyval.exprValue) = new_expr(tableitem_e);
                            (yyval.exprValue)->sym = (yyvsp[-1].exprValue)->sym;

                        }if((yyvsp[-1].exprValue)->type == libraryfunc_e){
                            (yyval.exprValue) = new_expr(libraryfunc_e);
                            (yyval.exprValue)->sym = (yyvsp[-1].exprValue)->sym;

                        }if((yyvsp[-1].exprValue)->type == assignexpr_e){
                            (yyval.exprValue) = new_expr(assignexpr_e);
                            (yyval.exprValue)->sym = (yyvsp[-1].exprValue)->sym;
                        }
                        if((yyvsp[-1].exprValue)->type == nil_e){
                            (yyval.exprValue) = new_expr(nil_e);
                            (yyval.exprValue)->sym = (yyvsp[-1].exprValue)->sym;
                        }
                        if((yyvsp[-1].exprValue)->type == programfunc_e){
                            (yyval.exprValue) = new_expr(programfunc_e);
                            (yyval.exprValue)->sym = (yyvsp[-1].exprValue)->sym;
                        }
                        (yyval.exprValue)->index = (yyvsp[-3].exprValue);
                    }
#line 3138 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 1401 "parser.y" /* yacc.c:1646  */
    {
                        SCOPE++;
                    }
#line 3146 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 1405 "parser.y" /* yacc.c:1646  */
    {
                        cout << "block -> {}" << endl;
                        Hide(SCOPE--);
                    }
#line 3155 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1410 "parser.y" /* yacc.c:1646  */
    {
                        SCOPE++;
                    }
#line 3163 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1415 "parser.y" /* yacc.c:1646  */
    {
                        cout << "block -> {stmt program}" << endl;
                        Hide(SCOPE--);
                    }
#line 3172 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1423 "parser.y" /* yacc.c:1646  */
    {
                        SymbolTableEntry entry = create_entry(generate_function_name(),SCOPE,yylineno,USERFUNC, FUNC_DEPTH);
                        Insert(entry);
                        FUNC_DEPTH++;
                        
                        
                        if(!scopeoffsetStack.empty())
                            scopeoffsetStack.back()->sym->value.funVal->totalLocals = currscopeoffset();

                        expr *expr = new_expr(programfunc_e);
                        expr->sym = update_entry(entry);
                        expr->sym->space = currscopespace();
                        expr->sym->value.funVal->iaddress = nextquadlabel();
                        
                        emit(funcstart, nullptr, nullptr, expr, 0, yylineno);

                        scopeoffsetStack.push_back(expr);
                        resetformalargsoffset();
                        break_continues_belong.push_back("function");
                    }
#line 3197 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1444 "parser.y" /* yacc.c:1646  */
    {
                        SCOPE++;
                        enterscopespace();
                    }
#line 3206 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1450 "parser.y" /* yacc.c:1646  */
    {
                        SCOPE--;
                        resetfunctionlocalsoffset();
                        enterscopespace();
                    }
#line 3216 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1456 "parser.y" /* yacc.c:1646  */
    {
                        cout << "funcdef -> function (idlist) block" << endl;                        
                        FUNC_DEPTH--;
                        break_continues_belong.pop_back();
                        emit(funcend, nullptr, nullptr, scopeoffsetStack.back(), 0, yylineno);

                        scopeoffsetStack.back()->sym->value.funVal->totalLocals = currscopeoffset();
                        (yyval.symbValue) = scopeoffsetStack.back()->sym;
                        (yyval.symbValue)->space = currscopespace();
                        scopeoffsetStack.pop_back();
                        

                        if(!scopeoffsetStack.empty()){
                            inccurentscopeoffset(scopeoffsetStack.back()->sym->value.funVal->totalLocals);
                        }
                        exitscopespace();
                        exitscopespace();
                    }
#line 3239 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1474 "parser.y" /* yacc.c:1646  */
    {fflag = true;}
#line 3245 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1476 "parser.y" /* yacc.c:1646  */
    {   
                        
                        
                        SymbolTableEntry entry = create_entry((yyvsp[0].stringValue), SCOPE, yylineno, USERFUNC, FUNC_DEPTH);
                        SymbolTableEntry *entry_ptr_glb = Lookup(entry, SCOPE);
                        SymbolTableEntry *entry_ptr = Lookup_scope(entry,SCOPE);
                        if(entry_ptr==NULL){
                            if(entry_ptr_glb==NULL){
                                Insert(entry);
                            }else if(entry_ptr_glb->type==LIBFUNC){
                                cout << "\033[1;31m" << 
                            "Lib function redeclaration at line "<< yylineno <<
                            "\033[0m" << endl;
                            exit(-1);  
                            }else{
                                Insert(entry);
                            }
                        }else if(entry_ptr->type == LIBFUNC){
                            cout << "\033[1;31m" << 
                            "Lib function redeclaration at line "<< yylineno <<
                            "\033[0m" << endl;
                            exit(-1);  
                        }else if(entry_ptr->type == USERFUNC){
                            cout << "\033[1;31m" << 
                            "User function redeclaration at line "<< yylineno <<
                            "\033[0m" << endl;
                            exit(-1);  
                        }else if(entry_ptr->type==GLOBAL||entry_ptr->type==LLOCAL||entry_ptr->type==FORMAL){
                            cout << "\033[1;31m" << 
                            "Variable already defined at line "<< yylineno <<
                            "\033[0m" << endl;
                            exit(-1);  
                        }
                        FUNC_DEPTH++;
                        if(!scopeoffsetStack.empty())
                            scopeoffsetStack.back()->sym->value.funVal->totalLocals = currscopeoffset();

                        expr *expr = new_expr(programfunc_e);
                        expr->sym = update_entry(entry);
                        expr->sym->space = currscopespace();
                        expr->sym->value.funVal->iaddress = nextquadlabel();
                        
                        emit(funcstart, nullptr, nullptr, expr, 0, yylineno);

                        scopeoffsetStack.push_back(expr);
                        resetformalargsoffset();
                        break_continues_belong.push_back("function");
                    }
#line 3298 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1525 "parser.y" /* yacc.c:1646  */
    {
                        SCOPE++;
                        enterscopespace();
                    }
#line 3307 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1531 "parser.y" /* yacc.c:1646  */
    {
                        SCOPE--;
                        enterscopespace();
                        resetfunctionlocalsoffset();
                    }
#line 3317 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1537 "parser.y" /* yacc.c:1646  */
    {
                        cout << "funcdef -> function id(idlist) block" << endl;
                        FUNC_DEPTH--;
                        break_continues_belong.pop_back();
                        emit(funcend, nullptr, nullptr, scopeoffsetStack.back(), 0, yylineno);

                        scopeoffsetStack.back()->sym->value.funVal->totalLocals = currscopeoffset();
                        (yyval.symbValue) = scopeoffsetStack.back()->sym;
                        (yyval.symbValue)->space = currscopespace();
                        scopeoffsetStack.pop_back();

                        if(!scopeoffsetStack.empty()){
                            inccurentscopeoffset(scopeoffsetStack.back()->sym->value.funVal->totalLocals);
                        }
                        exitscopespace();
                        exitscopespace();
                    }
#line 3339 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1556 "parser.y" /* yacc.c:1646  */
    { 
                                    cout << "const -> real" << endl;
                                    (yyval.exprValue) = new_expr(constnum_e);
                                    (yyval.exprValue)->numConst = (yyvsp[0].realValue);

                                    number_table.push_back((yyvsp[0].realValue));
                                }
#line 3351 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1563 "parser.y" /* yacc.c:1646  */
    { 
                                    cout << "const -> integer" << endl; 
                                    (yyval.exprValue) = new_expr(constnum_e);
                                    (yyval.exprValue)->numConst = (yyvsp[0].intValue);

                                    number_table.push_back((yyvsp[0].intValue));
                                }
#line 3363 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1570 "parser.y" /* yacc.c:1646  */
    {
                                    cout << "const -> string" << endl; 
                                    (yyval.exprValue) = new_expr(conststring_e);
                                    (yyval.exprValue)->strConst = (yyvsp[0].stringValue);

                                    string_table.push_back((yyvsp[0].stringValue));
                                }
#line 3375 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1577 "parser.y" /* yacc.c:1646  */
    { 
                                    cout << "const -> nil" << endl;
                                    (yyval.exprValue) = new_expr(nil_e);
                                    //! NIL == empty string
                                    //$const->strConst = nullptr;
                                }
#line 3386 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1583 "parser.y" /* yacc.c:1646  */
    { 
                                    cout << "const -> true" << endl;
                                    (yyval.exprValue) = new_expr(constbool_e);
                                    (yyval.exprValue)->boolConst = true;
                                }
#line 3396 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1588 "parser.y" /* yacc.c:1646  */
    { 
                                    cout << "const -> false" << endl;
                                    (yyval.exprValue) = new_expr(constbool_e);
                                    (yyval.exprValue)->boolConst = false; 
                                }
#line 3406 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1596 "parser.y" /* yacc.c:1646  */
    {
                        FORMAL_ARGUMENTS.clear();
                        SymbolTableEntry entry = create_entry((yyvsp[0].stringValue), SCOPE, yylineno, FORMAL, FUNC_DEPTH);
                        cout << scopeSpaceCounter << endl;
                        entry.space  = currscopespace();
                        entry.offset = currscopeoffset();
                        inccurentscopeoffset();
                        SymbolTableEntry* entry_ptr = Lookup_scope(entry, 0);
                        if(entry_ptr != NULL){
                            if(entry_ptr->type != LIBFUNC){
                                Insert(entry);
                                FORMAL_ARGUMENTS.push_back(entry);
                            }else{
                                cout << "\033[1;31m" << 
                                "Library function as formal argument at line "<< yylineno <<
                                "\033[0m" << endl;
                                exit(-1);  
                            }
                        }else{
                            Insert(entry);
                            FORMAL_ARGUMENTS.push_back(entry);
                        }     
                    }
#line 3434 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1619 "parser.y" /* yacc.c:1646  */
    { cout << "idlist -> id commaid" << endl; }
#line 3440 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1620 "parser.y" /* yacc.c:1646  */
    { cout << "idlist -> " << endl; }
#line 3446 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1625 "parser.y" /* yacc.c:1646  */
    {
                        SymbolTableEntry entry = create_entry((yyvsp[0].stringValue), SCOPE, yylineno, FORMAL, FUNC_DEPTH);
                        entry.space  = currscopespace();
                        entry.offset = currscopeoffset();
                        inccurentscopeoffset();
                        SymbolTableEntry* entry_ptr = Lookup_scope(entry, 0);
                        if(entry_ptr != NULL){
                            if(entry_ptr->type != LIBFUNC){
                                Insert(entry);
                                FORMAL_ARGUMENTS.push_back(entry);
                            }else{
                                cout << "\033[1;31m" << 
                                "Library function as formal argument at line "<< yylineno <<
                                "\033[0m" << endl;
                                exit(-1);  
                            }
                        }else{
                            for(int i=0; i<FORMAL_ARGUMENTS.size(); i++){
                                if((yyvsp[0].stringValue) == get_name(FORMAL_ARGUMENTS.at(i))){
                                    cout << "\033[1;31m" << 
                                    "Formal redeclaration at line "<< yylineno <<
                                    "\033[0m" << endl;
                                    exit(-1);  
                                }else{                
                                    Insert(entry);
                                }
                            }
                        }    
                    }
#line 3480 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1654 "parser.y" /* yacc.c:1646  */
    { cout << "commaid -> ,id commaid" << endl; }
#line 3486 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1655 "parser.y" /* yacc.c:1646  */
    { cout << "commaid -> " << endl; }
#line 3492 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1659 "parser.y" /* yacc.c:1646  */
    {
                        cout << "ifprefix -> if(expr)" << endl;

                        expr *e = new_expr(constbool_e);
                        e->boolConst = 1;
                        (yyvsp[-1].exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                        (yyvsp[-1].exprValue)->sym->space = currscopespace();
                        isLib = false;
                        isnt = false;
                        if(isLogic) {
                            isLogic = false;
                            struct expr* e = new_expr(constbool_e);
                            e->boolConst = 1;
                            emit(assign, e, nullptr, (yyvsp[-1].exprValue), 0, yylineno);

                            emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                            e = new_expr(constbool_e);
                            e->boolConst = 0;
                            emit(assign, e, nullptr, (yyvsp[-1].exprValue), 0, yylineno);
                            backpatch((yyvsp[-1].exprValue)->truelist, nextquadlabel() -3);
                            backpatch((yyvsp[-1].exprValue)->falselist, nextquadlabel() - 1);
                            
                        
                        }
                        emit(if_eq, (yyvsp[-1].exprValue), e, nullptr, nextquadlabel() + 2, yylineno);

                        (yyval.unsdValue) = nextquadlabel();
                        emit(jump, nullptr, nullptr, nullptr, 0, yylineno);
                        
                    }
#line 3528 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1693 "parser.y" /* yacc.c:1646  */
    {
                        cout << "ifstmt -> ifprefix stmt" << endl;

                        patchlabel((yyvsp[-1].unsdValue), nextquadlabel());
                        
                    }
#line 3539 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1700 "parser.y" /* yacc.c:1646  */
    { 
                        cout << "ifstmt -> ifprefix stmt elseprefix stmt" << endl;

                        patchlabel((yyvsp[-3].unsdValue), (yyvsp[-1].unsdValue) + 1);
                        patchlabel((yyvsp[-1].unsdValue), nextquadlabel());
                    }
#line 3550 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1709 "parser.y" /* yacc.c:1646  */
    {
                        cout << "ifstmt -> elseprefix" << endl;

                        (yyval.unsdValue) = nextquadlabel();
                        emit(jump, nullptr, nullptr, nullptr, 0, yylineno);
                    }
#line 3561 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1718 "parser.y" /* yacc.c:1646  */
    {
                        cout << "whilestart -> WHILE" << endl;
                        loop_counter++;
                        loop_intersect = 1;

                        (yyval.unsdValue) = nextquadlabel();
                        loop_start.push_back(nextquadlabel());
                        if(break_intersect){
                            valid_jumps.push_back(nextquadlabel() + 1);
                            break_intersect = 0;
                        }
                        vector<int> v;
                        continue_quads.push_back(v);
                        break_quads.push_back(v);
                        break_continues_belong.push_back("while");
                    }
#line 3582 "parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1737 "parser.y" /* yacc.c:1646  */
    {
                        cout << "whilecond -> (expr)" << endl;

                        expr* e = new_expr(constbool_e);
                        e->boolConst = 1;
                        (yyvsp[-1].exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                        (yyvsp[-1].exprValue)->sym->space = currscopespace();
                        isLib = false;
                        isnt = false;
                        if(isLogic) {
                            isLogic = false;
                            struct expr* e = new_expr(constbool_e);
                            e->boolConst = 1;
                            emit(assign, e, nullptr, (yyvsp[-1].exprValue), 0, yylineno);

                            emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                            e = new_expr(constbool_e);
                            e->boolConst = 0;
                            emit(assign, e, nullptr, (yyvsp[-1].exprValue), 0, yylineno);
                            backpatch((yyvsp[-1].exprValue)->truelist, nextquadlabel() -3);
                            backpatch((yyvsp[-1].exprValue)->falselist, nextquadlabel() - 1);
                        
                        
                        }
                        emit(if_eq, (yyvsp[-1].exprValue), e, nullptr, nextquadlabel() + 2, yylineno);

                        (yyval.unsdValue) = nextquadlabel();
                        
                        emit(jump, nullptr, nullptr, nullptr, 0, yylineno);
                    }
#line 3618 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1771 "parser.y" /* yacc.c:1646  */
    {
                        cout << "whilestmt -> whilestart whilecond stmt" << endl;

                        emit(jump, nullptr, nullptr, nullptr, (yyvsp[-2].unsdValue), yylineno);
                        patchlabel((yyvsp[-1].unsdValue), nextquadlabel());
                        loop_end.push_back(nextquadlabel());                                               

                        if(continue_quads.size()>0)
                            for(int j=0;j<continue_quads.at(continue_quads.size()-1).size();j++){
                                
                                patchlabel(continue_quads.at(continue_quads.size()-1).at(j), loop_start.at(loop_start.size()-1));
                            }
                        if(break_quads.size()>0)
                            for(int j=0;j<break_quads.at(break_quads.size()-1).size();j++){
                                patchlabel(break_quads.at(break_quads.size()-1).at(j), loop_end.at(loop_end.size()-1));
                            }
                        
                        
                        loop_start.pop_back();
                        loop_end.pop_back();
                        break_continues_belong.pop_back();
                        if(continue_quads.size()>0)
                            continue_quads.pop_back();
                        if(break_quads.size()>0)
                            break_quads.pop_back();

                        loop_counter--;
                        if(loop_counter < 0) loop_counter=0;
                    }
#line 3652 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1802 "parser.y" /* yacc.c:1646  */
    { 
                        (yyval.unsdValue) = nextquadlabel(); 
                        emit(jump,nullptr,nullptr, nullptr, 0, yylineno); 
                    }
#line 3661 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1808 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.unsdValue) = nextquadlabel(); 
                    }
#line 3669 "parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1813 "parser.y" /* yacc.c:1646  */
    {loop_counter++;break_continues_belong.push_back("for");}
#line 3675 "parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1814 "parser.y" /* yacc.c:1646  */
    {
                        cout << "forprefix -> for(elist;expr;" << endl;

                        (yyval.forjValue) = new struct forJump;
                        (yyval.forjValue)->test = (yyvsp[-2].unsdValue);
                        
                        expr *e = new_expr(constbool_e);
                        e->boolConst = 1;
                        (yyvsp[-1].exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                        (yyvsp[-1].exprValue)->sym->space = currscopespace();
                        isLib = false;
                        isnt = false;
                        if(isLogic) {
                            isLogic = false;
                            struct expr* e = new_expr(constbool_e);
                            e->boolConst = 1;
                            emit(assign, e, nullptr, (yyvsp[-1].exprValue), 0, yylineno);

                            emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                            e = new_expr(constbool_e);
                            e->boolConst = 0;
                            emit(assign, e, nullptr, (yyvsp[-1].exprValue), 0, yylineno);
                            backpatch((yyvsp[-1].exprValue)->truelist, nextquadlabel() -3);
                            backpatch((yyvsp[-1].exprValue)->falselist, nextquadlabel() - 1);
                            
                        
                        }
                        (yyval.forjValue)->enter = nextquadlabel();
                        emit(if_eq, (yyvsp[-1].exprValue), e, nullptr, 0, yylineno);
                        vector<int> v;
                        continue_quads.push_back(v);
                        break_quads.push_back(v);
                    }
#line 3714 "parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1851 "parser.y" /* yacc.c:1646  */
    {
                        cout << "forstmt -> elist) stmt" << endl;

                        patchlabel((yyvsp[-6].forjValue)->enter, (yyvsp[-2].unsdValue) + 1);
                        patchlabel((yyvsp[-5].unsdValue) , nextquadlabel());
                        patchlabel((yyvsp[-2].unsdValue) , (yyvsp[-6].forjValue)->test);
                        patchlabel((yyvsp[0].unsdValue) , (yyvsp[-5].unsdValue) + 1);
                        loop_start.push_back((yyvsp[-5].unsdValue) + 1);
                        loop_end.push_back(nextquadlabel());
                        

                        if(continue_quads.size()>0)
                            for(int j=0;j<continue_quads.at(continue_quads.size()-1).size();j++){
                                patchlabel(continue_quads.at(continue_quads.size()-1).at(j), loop_start.at(loop_start.size()-1));
                            }
                        if(break_quads.size()>0)
                            for(int j=0;j<break_quads.at(break_quads.size()-1).size();j++){
                                patchlabel(break_quads.at(break_quads.size()-1).at(j), loop_end.at(loop_end.size()-1));
                            }


                        loop_start.pop_back();
                        loop_end.pop_back();
                        break_continues_belong.pop_back();
                        if(continue_quads.size()>0)
                            continue_quads.pop_back();
                        if(break_quads.size()>0)
                            break_quads.pop_back();
                        loop_counter--;
                        if(loop_counter < 0) loop_counter=0;
                    }
#line 3750 "parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1884 "parser.y" /* yacc.c:1646  */
    {
                        if(FUNC_DEPTH==0){
                            cout << "\033[1;31m" << 
                                    "Return outside of function at line "<< yylineno <<
                                    "\033[0m" << endl;
                                exit(-1);  
                        }

                    }
#line 3764 "parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1894 "parser.y" /* yacc.c:1646  */
    { 
                        cout << "returnstmt -> return expr;" << endl;

                        isnt = false;
                        isLib = false;
                        if(isLogic) {

                            (yyvsp[-1].exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                            (yyvsp[-1].exprValue)->sym->space=currscopespace();

                            isLogic = false;
                            struct expr* e = new_expr(constbool_e);
                            e->boolConst = 1;
                            emit(assign, e, nullptr, (yyvsp[-1].exprValue), 0, yylineno);

                            emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 2, yylineno);

                            e = new_expr(constbool_e);
                            e->boolConst = 0;
                            emit(assign, e, nullptr, (yyvsp[-1].exprValue), 0, yylineno);

                            backpatch((yyvsp[-1].exprValue)->truelist, nextquadlabel() - 3);
                            backpatch((yyvsp[-1].exprValue)->falselist, nextquadlabel() - 1);
                        
                        }

                        emit(ret, nullptr, nullptr, (yyvsp[-1].exprValue), 0, yylineno);
                    }
#line 3797 "parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1922 "parser.y" /* yacc.c:1646  */
    {
                        if(FUNC_DEPTH==0){
                            cout << "\033[1;31m" << 
                                    "Return outside of function at line "<< yylineno <<
                                    "\033[0m" << endl;
                                    exit(-1);  
                        }
                    }
#line 3810 "parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1930 "parser.y" /* yacc.c:1646  */
    { 
                        cout << "returnstmt -> return;" << endl; 

                        emit(ret, nullptr, nullptr, nullptr, 0, yylineno);
                    }
#line 3820 "parser.cpp" /* yacc.c:1646  */
    break;


#line 3824 "parser.cpp" /* yacc.c:1646  */
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
#line 1939 "parser.y" /* yacc.c:1906  */


int main(int argc, char** argv){

    if(argc>1){
        if(!(yyin=fopen(argv[1],"r"))){
            printf("Cannot open file %s",argv[1]);
            return -1;
        }
    }else
        yyin=stdin;
    
    
    Insert(create_entry("print", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("input", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("objectmemberkeys", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("objecttotalmembers", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("objectcopy", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("totalarguments", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("argument", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("typeof", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("strtonum", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("sqrt", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("cos", 0, 0, LIBFUNC,FUNC_DEPTH));
    Insert(create_entry("sin", 0, 0, LIBFUNC,FUNC_DEPTH));
    libfunc_table.push_back("print");               //done
    libfunc_table.push_back("input");
    libfunc_table.push_back("objectmemberkeys");
    libfunc_table.push_back("objecttotalmembers");
    libfunc_table.push_back("objectcopy");
    libfunc_table.push_back("totalarguments");      //done
    libfunc_table.push_back("argument");
    libfunc_table.push_back("strtonum");
    libfunc_table.push_back("sqrt");                //done
    libfunc_table.push_back("cos");                 //done
    libfunc_table.push_back("sin");                 //done
    libfunc_table.push_back("typeof");              //done
    
    
    yyparse();
    if (quads.empty())
        return 0;
    
    print_symbol_table();
    print_quads();

    number_table.push_back(1); //++ --
    run_generate();
    create_binary();
    return 0;
}
