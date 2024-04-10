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

    vector <int> break_vector;
    vector <int> continue_vector;

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
    bool isAnd   = 0;
    bool isnt    = 0;

    vector <vector <int>> backup_truelists;
    vector <vector <int>> backup_falselists;


    vector<SymbolTableEntry> FORMAL_ARGUMENTS; 

#line 111 "parser.cpp" /* yacc.c:339  */

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
#line 48 "parser.y" /* yacc.c:355  */

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
    

#line 271 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 286 "parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  71
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   505

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

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
       0,   151,   151,   157,   162,   200,   228,   231,   232,   233,
     235,   234,   265,   264,   288,   289,   290,   293,   299,   312,
     323,   334,   345,   356,   393,   429,   464,   501,   536,   572,
     572,   612,   612,   655,   663,   667,   672,   677,   686,   722,
     721,   759,   795,   794,   831,   868,   873,   877,   881,   888,
     891,   924,   952,   963,   971,   970,  1033,  1040,  1040,  1058,
    1069,  1069,  1073,  1087,  1100,  1122,  1140,  1146,  1154,  1166,
    1179,  1178,  1208,  1217,  1215,  1246,  1253,  1269,  1288,  1295,
    1301,  1308,  1360,  1359,  1369,  1368,  1382,  1401,  1407,  1381,
    1429,  1431,  1474,  1480,  1429,  1504,  1509,  1514,  1519,  1525,
    1530,  1538,  1537,  1558,  1563,  1561,  1589,  1592,  1622,  1629,
    1638,  1647,  1665,  1695,  1726,  1732,  1737,  1737,  1770,  1803,
    1803,  1817,  1817
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
  "assignexpr", "$@7", "member", "$@8", "$@9", "call", "callsuffix",
  "normcall", "methodcall", "elist", "$@10", "commaexpr", "$@11",
  "objectdef", "indexed", "commaindexedelem", "indexedelem", "block",
  "$@12", "$@13", "funcdef", "$@14", "$@15", "$@16", "$@17", "$@18",
  "$@19", "$@20", "const", "idlist", "$@21", "commaid", "$@22", "ifprefix",
  "ifstmt", "elseprefix", "whilestart", "whilecond", "whilestmt", "N", "M",
  "forprefix", "$@23", "forstmt", "returnstmt", "$@24", "$@25", YY_NULLPTR
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

#define YYPACT_NINF -192

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-192)))

#define YYTABLE_NINF -122

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-122)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      90,  -192,  -192,  -192,    -3,  -192,  -192,   -34,  -192,  -192,
      14,   -18,  -192,  -192,   211,  -192,  -192,   211,     9,     9,
       1,   159,   205,  -192,    34,    45,  -192,    90,   256,  -192,
    -192,     6,  -192,  -192,     2,  -192,  -192,  -192,  -192,    90,
    -192,     3,  -192,  -192,  -192,  -192,  -192,   211,     7,    10,
      46,   211,    13,    26,    30,  -192,  -192,    42,   -25,   -15,
     -25,    36,    90,   211,   427,    35,    38,    32,   316,    37,
    -192,  -192,  -192,  -192,  -192,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,  -192,   211,   211,  -192,
      78,    54,    57,    97,  -192,  -192,  -192,   211,   211,   211,
    -192,    86,   211,    90,   211,   335,   211,  -192,  -192,   276,
    -192,  -192,  -192,    48,  -192,    90,   234,    55,  -192,  -192,
      63,  -192,  -192,    61,  -192,  -192,    -6,   142,   142,   466,
     466,   466,   466,  -192,  -192,  -192,    -6,   373,    67,   105,
      74,  -192,  -192,   211,   427,   391,    75,   110,  -192,    90,
     354,  -192,    77,  -192,    80,   114,    83,  -192,    61,    87,
     211,   211,  -192,    32,   211,   211,   211,  -192,  -192,  -192,
     211,   427,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,
      88,  -192,  -192,   409,   427,  -192,    92,   453,   440,    93,
      90,   211,    84,  -192,   114,  -192,    55,  -192,  -192,  -192,
     296,   126,  -192,   100,    96,  -192,  -192,  -192,  -192,  -192,
    -192,    84,   100,  -192,  -192
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    97,    96,    95,     0,    98,    50,     0,   111,   116,
      86,   119,    10,    12,     0,    99,   100,     0,     0,     0,
      84,    72,     0,    16,     0,     0,     2,     4,     0,    33,
      36,    45,    17,    53,    46,    47,    14,    15,    49,     0,
       6,     0,     7,   114,     8,     9,    51,     0,     0,     0,
       0,     0,     0,     0,     0,    44,    37,     0,    41,     0,
      38,     0,     0,     0,    70,     0,     0,    80,     0,     0,
      52,     1,     3,    29,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     0,    72,    57,
       0,     0,     0,     0,    64,    66,    67,     0,     0,    72,
      60,   108,     0,     0,    72,     0,    72,    87,    91,     0,
     122,    11,    13,     0,    83,     4,     0,    75,    76,    77,
       0,    78,    35,    48,    34,    34,    19,    27,    28,    23,
      25,    24,    26,    22,    20,    21,    18,     0,     0,     0,
       0,    40,    43,     0,    56,     0,     0,     0,   110,     0,
       0,   113,     0,   107,     0,   103,     0,   120,     0,     0,
       0,     0,    71,    80,    72,     0,     0,    59,    68,    58,
      72,    55,    62,    63,    61,   109,   112,   114,   115,   101,
       0,    92,    85,     0,    73,    79,     0,    30,    32,     0,
       0,     0,   106,    88,   103,    81,    75,    65,    69,   114,
       0,     0,   102,     0,     0,    74,   118,   117,   104,    89,
      93,   106,     0,   105,    94
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -192,    27,   116,   -28,  -192,  -192,   -14,  -192,  -192,    19,
    -192,  -192,  -192,  -192,    -5,  -192,  -192,  -192,  -192,  -192,
      20,  -192,  -192,  -192,   -84,  -192,   -51,  -192,  -192,  -192,
     -10,    28,  -191,  -192,  -192,   -21,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,   -45,  -192,   -57,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,  -175,  -192,  -192,  -192,  -192,  -192,
    -192,  -192
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    53,    54,    28,   124,   125,   165,
      29,    91,    92,    30,    31,    32,    93,    33,   139,   147,
      34,    94,    95,    96,    65,   117,   162,   196,    35,    66,
     121,    67,    36,    61,    62,    37,    49,   155,   203,    50,
     156,   194,   212,    38,   180,   192,   202,   211,    39,    40,
     149,    41,   103,    42,   104,   191,    43,    48,    44,    45,
      51,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    69,   190,    56,   138,    97,    46,    64,    68,   -54,
      47,   101,   209,    58,    60,   146,     4,    87,     6,    88,
     152,   214,   154,   -90,   206,    89,    90,    98,  -121,    99,
      82,    83,    84,   105,   115,   100,   113,   109,    59,    59,
     -42,   -39,   -82,    70,    98,    71,    99,   102,    87,   116,
      88,   106,   100,    57,   107,   108,    89,    90,    24,   110,
      10,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   111,   137,    64,   151,   112,   114,   118,   120,
     186,   119,   123,   144,   145,    64,   189,   140,   150,   141,
      64,   142,    64,   158,     1,     2,     3,     4,     5,     6,
     143,   148,   161,    63,     7,   164,     8,     9,    10,    11,
      12,    13,   168,    14,   169,    15,    16,    17,   170,   174,
     173,   175,   177,   179,    18,    19,   178,   181,   182,   171,
      20,   201,    21,   193,    22,   208,    23,   197,   198,    24,
      20,   210,   159,    72,   166,   205,   183,   184,   163,   204,
      64,   187,   188,   185,   213,     0,    64,     0,     0,     0,
       0,     0,   199,     1,     2,     3,     4,     5,     6,    75,
    -122,  -122,    78,    79,    80,    81,     0,   200,    82,    83,
      84,    85,    14,     0,    15,    16,    17,     0,     0,     0,
       0,     0,     0,    18,    19,     0,     0,     0,     0,    63,
       0,    21,     0,    22,     0,     0,     0,     0,    24,     1,
       2,     3,     4,     5,     6,     1,     2,     3,     4,     5,
       6,     0,     0,    10,     0,     0,     0,     0,    14,     0,
      15,    16,    17,     0,    14,     0,    15,    16,    17,    18,
      19,     0,     0,     0,     0,    18,    19,    21,     0,    22,
       0,     0,     0,    21,    24,    22,    73,     0,    74,     0,
      24,    75,    76,    77,    78,    79,    80,    81,     0,     0,
      82,    83,    84,    85,     0,     0,     0,     0,    73,     0,
      74,     0,   160,    75,    76,    77,    78,    79,    80,    81,
       0,     0,    82,    83,    84,    85,     0,     0,    73,     0,
      74,     0,    86,    75,    76,    77,    78,    79,    80,    81,
       0,     0,    82,    83,    84,    85,     0,     0,    73,     0,
      74,     0,   157,    75,    76,    77,    78,    79,    80,    81,
       0,     0,    82,    83,    84,    85,     0,     0,    73,     0,
      74,     0,   207,    75,    76,    77,    78,    79,    80,    81,
       0,     0,    82,    83,    84,    85,     0,    73,     0,    74,
       0,   122,    75,    76,    77,    78,    79,    80,    81,     0,
       0,    82,    83,    84,    85,     0,    73,     0,    74,     0,
     153,    75,    76,    77,    78,    79,    80,    81,     0,     0,
      82,    83,    84,    85,     0,    73,     0,    74,     0,   176,
      75,    76,    77,    78,    79,    80,    81,     0,     0,    82,
      83,    84,    85,    73,     0,    74,   167,     0,    75,    76,
      77,    78,    79,    80,    81,     0,     0,    82,    83,    84,
      85,    73,     0,    74,   172,     0,    75,    76,    77,    78,
      79,    80,    81,     0,     0,    82,    83,    84,    85,    73,
     195,    74,     0,     0,    75,    76,    77,    78,    79,    80,
      81,     0,    73,    82,    83,    84,    85,    75,    76,    77,
      78,    79,    80,    81,     0,     0,    82,    83,    84,    85,
      75,    76,    77,    78,    79,    80,    81,     0,     0,    82,
      83,    84,    85,    75,     0,     0,  -122,  -122,  -122,  -122,
       0,     0,    82,    83,    84,    85
};

static const yytype_int16 yycheck[] =
{
      14,    22,   177,    17,    88,     3,     9,    21,    22,     3,
      44,    39,   203,    18,    19,    99,     7,    42,     9,    44,
     104,   212,   106,     9,   199,    50,    51,    42,    46,    44,
      36,    37,    38,    47,    62,    50,    57,    51,    18,    19,
      34,    35,    41,     9,    42,     0,    44,    44,    42,    63,
      44,    44,    50,    44,    44,     9,    50,    51,    49,    46,
      18,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    46,    87,    88,   103,    46,    41,    43,    47,
     164,    43,    45,    97,    98,    99,   170,     9,   102,    35,
     104,    34,   106,    45,     4,     5,     6,     7,     8,     9,
       3,    15,    47,    40,    14,    44,    16,    17,    18,    19,
      20,    21,    45,    23,     9,    25,    26,    27,    44,     9,
      45,   149,    45,     9,    34,    35,    46,    44,    41,   143,
      40,    47,    42,    45,    44,     9,    46,    45,    45,    49,
      40,    45,   115,    27,   125,   196,   160,   161,   120,   194,
     164,   165,   166,   163,   211,    -1,   170,    -1,    -1,    -1,
      -1,    -1,   190,     4,     5,     6,     7,     8,     9,    27,
      28,    29,    30,    31,    32,    33,    -1,   191,    36,    37,
      38,    39,    23,    -1,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    40,
      -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    49,     4,
       5,     6,     7,     8,     9,     4,     5,     6,     7,     8,
       9,    -1,    -1,    18,    -1,    -1,    -1,    -1,    23,    -1,
      25,    26,    27,    -1,    23,    -1,    25,    26,    27,    34,
      35,    -1,    -1,    -1,    -1,    34,    35,    42,    -1,    44,
      -1,    -1,    -1,    42,    49,    44,    22,    -1,    24,    -1,
      49,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    22,    -1,
      24,    -1,    48,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    36,    37,    38,    39,    -1,    -1,    22,    -1,
      24,    -1,    46,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    36,    37,    38,    39,    -1,    -1,    22,    -1,
      24,    -1,    46,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    36,    37,    38,    39,    -1,    -1,    22,    -1,
      24,    -1,    46,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    36,    37,    38,    39,    -1,    22,    -1,    24,
      -1,    45,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    36,    37,    38,    39,    -1,    22,    -1,    24,    -1,
      45,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      36,    37,    38,    39,    -1,    22,    -1,    24,    -1,    45,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    36,
      37,    38,    39,    22,    -1,    24,    43,    -1,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    36,    37,    38,
      39,    22,    -1,    24,    43,    -1,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    36,    37,    38,    39,    22,
      41,    24,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    -1,    22,    36,    37,    38,    39,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    36,    37,    38,    39,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    36,
      37,    38,    39,    27,    -1,    -1,    30,    31,    32,    33,
      -1,    -1,    36,    37,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    14,    16,    17,
      18,    19,    20,    21,    23,    25,    26,    27,    34,    35,
      40,    42,    44,    46,    49,    55,    56,    57,    60,    64,
      67,    68,    69,    71,    74,    82,    86,    89,    97,   102,
     103,   105,   107,   110,   112,   113,     9,    44,   111,    90,
      93,   114,   115,    58,    59,    60,    60,    44,    68,    74,
      68,    87,    88,    40,    60,    78,    83,    85,    60,    89,
       9,     0,    56,    22,    24,    27,    28,    29,    30,    31,
      32,    33,    36,    37,    38,    39,    46,    42,    44,    50,
      51,    65,    66,    70,    75,    76,    77,     3,    42,    44,
      50,    57,    44,   106,   108,    60,    44,    44,     9,    60,
      46,    46,    46,    89,    41,    57,    60,    79,    43,    43,
      47,    84,    45,    45,    61,    62,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    78,    72,
       9,    35,    34,     3,    60,    60,    78,    73,    15,   104,
      60,    57,    78,    45,    78,    91,    94,    46,    45,    55,
      48,    47,    80,    85,    44,    63,    63,    43,    45,     9,
      44,    60,    43,    45,     9,    57,    45,    45,    46,     9,
      98,    44,    41,    60,    60,    84,    78,    60,    60,    78,
     108,   109,    99,    45,    95,    41,    81,    45,    45,    57,
      60,    47,   100,    92,    98,    80,   108,    46,     9,    86,
      45,   101,    96,   100,    86
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    57,    57,    57,
      58,    57,    59,    57,    57,    57,    57,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    61,
      60,    62,    60,    60,    63,    64,    64,    64,    64,    65,
      64,    64,    66,    64,    64,    67,    67,    67,    67,    67,
      68,    68,    68,    68,    70,    69,    69,    72,    71,    71,
      73,    71,    71,    74,    74,    74,    75,    75,    76,    77,
      79,    78,    78,    81,    80,    80,    82,    82,    83,    84,
      84,    85,    87,    86,    88,    86,    90,    91,    92,    89,
      93,    94,    95,    96,    89,    97,    97,    97,    97,    97,
      97,    99,    98,    98,   101,   100,   100,   102,   103,   103,
     104,   105,   106,   107,   108,   109,   111,   110,   112,   114,
     113,   115,   113
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       0,     3,     0,     3,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     0,
       5,     0,     5,     1,     0,     3,     1,     2,     2,     0,
       3,     2,     0,     3,     2,     1,     1,     1,     3,     1,
       1,     2,     2,     1,     0,     4,     3,     0,     4,     4,
       0,     4,     4,     4,     2,     6,     1,     1,     3,     5,
       0,     3,     0,     0,     4,     0,     3,     3,     2,     3,
       0,     5,     0,     3,     0,     5,     0,     0,     0,     8,
       0,     0,     0,     0,    10,     1,     1,     1,     1,     1,
       1,     0,     3,     0,     0,     4,     0,     4,     2,     4,
       1,     1,     3,     3,     0,     0,     0,     8,     7,     0,
       4,     0,     3
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
#line 152 "parser.y" /* yacc.c:1646  */
    {
                cout << "program -> stmt*" << endl;
            }
#line 1590 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 158 "parser.y" /* yacc.c:1646  */
    {
                cout << "stmts -> stmt stmts" << endl;
            }
#line 1598 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 162 "parser.y" /* yacc.c:1646  */
    {
                cout << "stmts -> " << endl;
                

                /*
                //correct repeated jumps
                if(loop_counter == 0){

                    int empty_while = 0;
                    for(int i=0; i<false_jumps.size(); i++){
                        if(!false_jumps.at(i))
                            empty_while++;
                    }
                    empty_while = (empty_while%2) ? 0 : 1;

                    vector<vector<int>> repach;
                    for(int i=0; i<false_jumps.size(); i++){
                        
                        if(!false_jumps.at(i)){
                            vector<int> v;
                            repach.push_back(v);
                        }else{
                            repach.back().push_back(false_jumps.at(i));
                        }
                    }
                    for(int i=0; i<repach.size() - empty_while; i++){
                        cout << endl << valid_jumps.at(i) << " : ";
                        for(int j=0; j<repach.at(i).size(); j++){

                            quads.at(repach.at(i).at(j) - 1).label = quads.at(valid_jumps.at(i)-1).label;
                        }
                    }

                    cout << endl;
                }*/
            }
#line 1639 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 201 "parser.y" /* yacc.c:1646  */
    {
                cout << "stmt -> expr;" << endl;

                lwarning = false;
                isnt     = false;

                if(isLogic) {

                    (yyvsp[-1].exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);

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
#line 1671 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 228 "parser.y" /* yacc.c:1646  */
    { 
                cout << "stmt -> ifstmt" << endl; 
            }
#line 1679 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 231 "parser.y" /* yacc.c:1646  */
    { cout << "stmt -> whilestmt" << endl; }
#line 1685 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 232 "parser.y" /* yacc.c:1646  */
    { cout << "stmt -> forstmt" << endl; }
#line 1691 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 233 "parser.y" /* yacc.c:1646  */
    { cout << "stmt -> returnstmt" << endl; }
#line 1697 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 235 "parser.y" /* yacc.c:1646  */
    {
                cout << "stmt -> break" << endl;
                if(break_quads.size()>0)
                    break_quads.at(break_quads.size()-1).push_back(nextquadlabel());
                break_counter++;

                //loop_counter--;
                if(loop_counter <= 0){
                    cout << "\033[1;31m" <<
                        "Can't use break here at line "<< yylineno <<
                        "\033[0m" << endl;
                        loop_counter=0;
                }

                
                
                emit(jump,nullptr, nullptr, nullptr, 0, yylineno);

            }
#line 1721 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 255 "parser.y" /* yacc.c:1646  */
    { 
                if(loop_intersect){
                    loop_intersect = 0;
                    false_jumps.push_back(0);
                    
                }
                false_jumps.push_back(nextquadlabel() - 1);
                break_vector.push_back(nextquadlabel() - 2);
            }
#line 1735 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 265 "parser.y" /* yacc.c:1646  */
    {
                cout << "stmt -> continue" << endl;
                if(continue_quads.size()>0)
                    continue_quads.at(continue_quads.size()-1).push_back(nextquadlabel());
                continue_counter++;

                if(loop_counter == 0){
                    cout << "\033[1;31m" << 
                        "Can't use continue outside of loops at line "<< yylineno <<
                        "\033[0m" << endl;
                }

                
                
                emit(jump,nullptr, nullptr, nullptr, 0, yylineno);
                
            }
#line 1757 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 283 "parser.y" /* yacc.c:1646  */
    { 
                cout << "program -> stmt*" << endl;

                continue_vector.push_back(nextquadlabel() - 2);
            }
#line 1767 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 288 "parser.y" /* yacc.c:1646  */
    { cout << "stmt -> block" << endl; }
#line 1773 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 289 "parser.y" /* yacc.c:1646  */
    { cout << "stmt -> funcdef" << endl; }
#line 1779 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 290 "parser.y" /* yacc.c:1646  */
    { cout << "stmt -> ;" << endl; }
#line 1785 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 294 "parser.y" /* yacc.c:1646  */
    { 
                cout << "expr -> assignexpr" << endl;
                (yyval.exprValue) = (yyvsp[0].exprValue);
                
            }
#line 1795 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 300 "parser.y" /* yacc.c:1646  */
    { 
                cout << "expr -> expr + expr" << endl;
                (yyval.exprValue) = new_expr(arithexpr_e);
                (yyval.exprValue)->sym = assign_temp((yyvsp[-2].exprValue),(yyvsp[0].exprValue), SCOPE, yylineno, FUNC_DEPTH);

                if((yyvsp[-2].exprValue)->type == constnum_e && (yyvsp[0].exprValue)->type == constnum_e){
                        (yyval.exprValue)->type = constnum_e;
                }
        
                operation_list.push_back(nextquadlabel());
                emit(add, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), (yyval.exprValue), 0 ,yylineno);
            }
#line 1812 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 313 "parser.y" /* yacc.c:1646  */
    {
                cout << "expr -> expr - expr" << endl;
                (yyval.exprValue) = new_expr(arithexpr_e);
                (yyval.exprValue)->sym = assign_temp((yyvsp[-2].exprValue),(yyvsp[0].exprValue), SCOPE, yylineno, FUNC_DEPTH);

                if((yyvsp[-2].exprValue)->type == constnum_e && (yyvsp[0].exprValue)->type == constnum_e){
                        (yyval.exprValue)->type = constnum_e;
                }
                emit(sub, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), (yyval.exprValue), 0 ,yylineno);
            }
#line 1827 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 324 "parser.y" /* yacc.c:1646  */
    {
                cout << "expr -> expr * expr" << endl;
                (yyval.exprValue) = new_expr(arithexpr_e);
                (yyval.exprValue)->sym = assign_temp((yyvsp[-2].exprValue),(yyvsp[0].exprValue), SCOPE, yylineno, FUNC_DEPTH);

                if((yyvsp[-2].exprValue)->type == constnum_e && (yyvsp[0].exprValue)->type == constnum_e){
                        (yyval.exprValue)->type = constnum_e;
                }
                emit(mul, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), (yyval.exprValue), 0 ,yylineno);
            }
#line 1842 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 335 "parser.y" /* yacc.c:1646  */
    {
                cout << "expr -> expr / expr" << endl;
                (yyval.exprValue) = new_expr(arithexpr_e);
                (yyval.exprValue)->sym = assign_temp((yyvsp[-2].exprValue),(yyvsp[0].exprValue), SCOPE, yylineno, FUNC_DEPTH);

                if((yyvsp[-2].exprValue)->type == constnum_e && (yyvsp[0].exprValue)->type == constnum_e){
                        (yyval.exprValue)->type = constnum_e;
                }
                emit(_div, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), (yyval.exprValue), 0 ,yylineno);
            }
#line 1857 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 346 "parser.y" /* yacc.c:1646  */
    { 
                cout << "expr -> expr % expr" << endl;
                (yyval.exprValue) = new_expr(arithexpr_e);
                (yyval.exprValue)->sym = assign_temp((yyvsp[-2].exprValue),(yyvsp[0].exprValue), SCOPE, yylineno, FUNC_DEPTH);

                if((yyvsp[-2].exprValue)->type == constnum_e && (yyvsp[0].exprValue)->type == constnum_e){
                        (yyval.exprValue)->type = constnum_e;
                }
                emit(mod, (yyvsp[-2].exprValue), (yyvsp[0].exprValue), (yyval.exprValue), 0 ,yylineno);
            }
#line 1872 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 357 "parser.y" /* yacc.c:1646  */
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

                if((yyvsp[-2].exprValue)->type == constnum_e && (yyvsp[0].exprValue)->type == constnum_e){
                    (yyval.exprValue)->type = constbool_e;
                }

                (yyval.exprValue)->truelist.push_back(nextquadlabel());
                (yyval.exprValue)->falselist.push_back(nextquadlabel()+1);
                emit(if_greater, (yyvsp[-2].exprValue) , (yyvsp[0].exprValue), nullptr, nextquadlabel() + 2, yylineno);  
                emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 3, yylineno);

            }
#line 1913 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 394 "parser.y" /* yacc.c:1646  */
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
                

                if((yyvsp[-2].exprValue)->type == constnum_e && (yyvsp[0].exprValue)->type == constnum_e){
                    (yyval.exprValue)->type = constbool_e;
                }
                
                (yyval.exprValue)->truelist.push_back(nextquadlabel());
                emit(if_greatereq, (yyvsp[-2].exprValue) , (yyvsp[0].exprValue), nullptr, nextquadlabel() + 2, yylineno);
                
                (yyval.exprValue)->falselist.push_back(nextquadlabel());
                emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 3, yylineno);
            }
#line 1953 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 430 "parser.y" /* yacc.c:1646  */
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

                if((yyvsp[-2].exprValue)->type == constnum_e && (yyvsp[0].exprValue)->type == constnum_e){
                    (yyval.exprValue)->type = constbool_e;
                }
                
                (yyval.exprValue)->truelist.push_back(nextquadlabel());
                emit(if_less, (yyvsp[-2].exprValue) , (yyvsp[0].exprValue), nullptr, nextquadlabel() + 2, yylineno);
                
                (yyval.exprValue)->falselist.push_back(nextquadlabel());
                emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 3, yylineno);
            }
#line 1992 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 465 "parser.y" /* yacc.c:1646  */
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
               
                if((yyvsp[-2].exprValue)->type == constnum_e && (yyvsp[0].exprValue)->type == constnum_e){
                    (yyval.exprValue)->type = constbool_e;
                }
                
                (yyval.exprValue)->truelist.push_back(nextquadlabel());
                emit(if_lesseq, (yyvsp[-2].exprValue) , (yyvsp[0].exprValue), nullptr, nextquadlabel() + 2, yylineno);
                
                (yyval.exprValue)->falselist.push_back(nextquadlabel());
                emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 3, yylineno);

            }
#line 2033 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 502 "parser.y" /* yacc.c:1646  */
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
                
                if((yyvsp[-2].exprValue)->type == (yyvsp[0].exprValue)->type){
                    (yyval.exprValue)->type = constbool_e;
                }
                
                (yyval.exprValue)->truelist.push_back(nextquadlabel());
                emit(if_eq, (yyvsp[-2].exprValue) , (yyvsp[0].exprValue), nullptr, nextquadlabel() + 2, yylineno);
                
                (yyval.exprValue)->falselist.push_back(nextquadlabel());
                emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 3, yylineno);
            }
#line 2072 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 537 "parser.y" /* yacc.c:1646  */
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

                if((yyvsp[-2].exprValue)->type == (yyvsp[0].exprValue)->type){
                    (yyval.exprValue)->type = constbool_e;
                }
                
                (yyval.exprValue)->truelist.push_back(nextquadlabel());
                emit(if_noteq, (yyvsp[-2].exprValue) , (yyvsp[0].exprValue), nullptr, nextquadlabel() + 2, yylineno);
                
                (yyval.exprValue)->falselist.push_back(nextquadlabel());
                emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 3, yylineno);
            }
#line 2112 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 572 "parser.y" /* yacc.c:1646  */
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
#line 2127 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 582 "parser.y" /* yacc.c:1646  */
    { 
                cout << "expr -> expr && expr" << endl; 
                (yyval.exprValue) = new_expr(boolexpr_e);
                isLogic = true;
                (yyval.exprValue)->sym = assign_temp((yyvsp[-4].exprValue),(yyvsp[0].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                if((yyvsp[-4].exprValue)->type == constbool_e && (yyvsp[0].exprValue)->type == constbool_e){
                    (yyval.exprValue)->type = constbool_e;
                }

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
#line 2162 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 612 "parser.y" /* yacc.c:1646  */
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
#line 2177 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 622 "parser.y" /* yacc.c:1646  */
    { 
                cout << "expr -> expr || expr" << endl;
                (yyval.exprValue) = new_expr(boolexpr_e);
                (yyval.exprValue)->sym = assign_temp((yyvsp[-4].exprValue),(yyvsp[0].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                isLogic=true;
                if((yyvsp[-4].exprValue)->type == constbool_e && (yyvsp[0].exprValue)->type == constbool_e){
                    (yyval.exprValue)->type = constbool_e;
                }

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
#line 2215 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 656 "parser.y" /* yacc.c:1646  */
    {
                cout << "expr -> term" << endl; 
                (yyval.exprValue) = (yyvsp[0].exprValue);
            }
#line 2224 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 663 "parser.y" /* yacc.c:1646  */
    {
                (yyval.unsdValue) = nextquadlabel();
            }
#line 2232 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 668 "parser.y" /* yacc.c:1646  */
    {
                cout << "term -> (expr)" << endl;
                (yyval.exprValue) = (yyvsp[-1].exprValue);
            }
#line 2241 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 673 "parser.y" /* yacc.c:1646  */
    {
                cout << "term -> primary" << endl; 
                (yyval.exprValue) = (yyvsp[0].exprValue);
            }
#line 2250 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 678 "parser.y" /* yacc.c:1646  */
    {
                cout << "term -> -expr" << endl; 

                check_arith((yyvsp[0].exprValue), "Cannot use uminus operator to a not aritmentic expression ", yylineno);
                (yyval.exprValue) = new_expr(arithexpr_e);
                (yyval.exprValue)->sym = istempexpr((yyvsp[0].exprValue)) ? (yyvsp[0].exprValue)->sym : newtemp(SCOPE, yylineno, FUNC_DEPTH);
                emit(uminus,(yyvsp[0].exprValue), nullptr, (yyval.exprValue), 0, yylineno);
            }
#line 2263 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 688 "parser.y" /* yacc.c:1646  */
    {
                cout << "term -> ++lvalue" << endl;

                SymbolTableEntry *entry_ptr = Lookup(create_entry(GLOBAL_ID,0,0,LLOCAL,FUNC_DEPTH), SCOPE);
                if(isFunction(*entry_ptr)){
                    cout << "\033[1;31m" << 
                        "Function used as lvalue (++function)  at line "<< yylineno <<
                        "\033[0m" << endl;
                }

                check_arith((yyvsp[0].exprValue), "Cannot use pre increment operator to a not aritmentic expression ", yylineno);
                if ((yyvsp[0].exprValue)->type == tableitem_e) {

                    (yyval.exprValue) = emit_iftableitem((yyvsp[0].exprValue), SCOPE, yylineno, FUNC_DEPTH);

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(add, (yyval.exprValue), e, (yyval.exprValue), 0, yylineno);
                    emit(tablesetelem, (yyvsp[0].exprValue), (yyvsp[0].exprValue)->index, (yyval.exprValue), 0, yylineno);
                }
                else {

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(add, (yyvsp[0].exprValue), e, (yyvsp[0].exprValue), 0, yylineno);
                    (yyval.exprValue) = new_expr(arithexpr_e);
                    (yyval.exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                    emit(assign, (yyvsp[0].exprValue), nullptr, (yyval.exprValue), 0, yylineno);
                }
            }
#line 2300 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 722 "parser.y" /* yacc.c:1646  */
    {
                SymbolTableEntry *entry_ptr = Lookup(create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH), SCOPE);
                if(isFunction(*entry_ptr)){
                    cout << "\033[1;31m" << 
                        "Function used as lvalue (function++)  at line "<< yylineno <<
                        "\033[0m" << endl;
                }
            }
#line 2313 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 731 "parser.y" /* yacc.c:1646  */
    {
                cout << "term -> lvalue++" << endl;

                check_arith((yyvsp[-2].exprValue), "Cannot use post increment operator to a not aritmentic expression ", yylineno);
                (yyval.exprValue) = new_expr(var_e);
                (yyval.exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);

                if ((yyvsp[-2].exprValue)->type == tableitem_e) {

                    expr* val = emit_iftableitem((yyvsp[-2].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                    emit(assign, val, NULL, (yyval.exprValue), 0, yylineno);

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(add, val, e, val,  0, yylineno);
                    emit(tablesetelem, (yyvsp[-2].exprValue), (yyvsp[-2].exprValue)->index, val, 0, yylineno);
                }
                else {
                    emit(assign, (yyvsp[-2].exprValue), nullptr, (yyval.exprValue), 0, yylineno);

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(add, (yyvsp[-2].exprValue), e, (yyvsp[-2].exprValue), 0, yylineno);
                }
            }
#line 2345 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 761 "parser.y" /* yacc.c:1646  */
    {
                cout << "term -> --lvalue" << endl;

                SymbolTableEntry *entry_ptr = Lookup(create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH), SCOPE);
                if(isFunction(*entry_ptr)){
                    cout << "\033[1;31m" << 
                        "Function used as lvalue (--function)  at line "<< yylineno <<
                        "\033[0m" << endl;
                }

                check_arith((yyvsp[0].exprValue), "Cannot use pre decrement operator to a not aritmentic expression ", yylineno);
                if ((yyvsp[0].exprValue)->type == tableitem_e) {

                    (yyval.exprValue) = emit_iftableitem((yyvsp[0].exprValue), SCOPE, yylineno, FUNC_DEPTH);

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(sub, (yyval.exprValue), e, (yyval.exprValue), 0, yylineno);
                    emit(tablesetelem, (yyvsp[0].exprValue), (yyvsp[0].exprValue)->index, (yyval.exprValue), 0, yylineno);
                }
                else {

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(sub, (yyvsp[0].exprValue), e, (yyvsp[0].exprValue), 0, yylineno);
                    (yyval.exprValue) = new_expr(arithexpr_e);
                    (yyval.exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                    emit(assign, (yyvsp[0].exprValue), nullptr, (yyval.exprValue), 0, yylineno);
                }
            }
#line 2382 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 795 "parser.y" /* yacc.c:1646  */
    {
                SymbolTableEntry *entry_ptr = Lookup(create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH), SCOPE);
                if(isFunction(*entry_ptr)){
                    cout << "\033[1;31m" << 
                        "Function used as lvalue (function--)  at line "<< yylineno <<
                        "\033[0m" << endl;
                }
            }
#line 2395 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 804 "parser.y" /* yacc.c:1646  */
    {
                cout << "term -> lvalue--" << endl;

                check_arith((yyvsp[-2].exprValue), "Cannot use post decrement operator to a not aritmentic expression ", yylineno);
                (yyval.exprValue) = new_expr(var_e);
                (yyval.exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);

                if ((yyvsp[-2].exprValue)->type == tableitem_e) {

                    expr* val = emit_iftableitem((yyvsp[-2].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                    emit(assign, val, NULL, (yyval.exprValue), 0, yylineno);

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(sub, val, e, val,  0, yylineno);
                    emit(tablesetelem, (yyvsp[-2].exprValue), (yyvsp[-2].exprValue)->index, val, 0, yylineno);
                }
                else {
                    emit(assign, (yyvsp[-2].exprValue), nullptr, (yyval.exprValue), 0, yylineno);

                    expr* e = new_expr(constnum_e);
                    e->numConst = 1;

                    emit(sub, (yyvsp[-2].exprValue), e, (yyvsp[-2].exprValue), 0, yylineno);
                }
            }
#line 2427 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 832 "parser.y" /* yacc.c:1646  */
    {
                cout << "term -> !expr" << endl;

                isLogic = true;
                isnt    = true;
               

                (yyval.exprValue) = new_expr(boolexpr_e);
                (yyval.exprValue)->sym = istempexpr((yyvsp[0].exprValue)) ? (yyvsp[0].exprValue)->sym : newtemp(SCOPE, yylineno, FUNC_DEPTH);

                if ((yyvsp[0].exprValue)->truelist.empty()) {
                   // isLogic = false;
                   /* $2->truelist.push_back(nextquadlabel());
                    emit(if_eq, $2, $2,nullptr, nextquadlabel() + 2, yylineno);
                    $2->falselist.push_back(nextquadlabel());
                    emit(jump,nullptr, nullptr, nullptr, nextquadlabel() + 1, yylineno);*/

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
#line 2465 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 868 "parser.y" /* yacc.c:1646  */
    {
                        cout << "primary -> lvalue" << endl;

                        (yyvsp[0].exprValue)   = emit_iftableitem((yyvsp[0].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                    }
#line 2475 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 874 "parser.y" /* yacc.c:1646  */
    {
                cout << "primary -> call" << endl;
            }
#line 2483 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 878 "parser.y" /* yacc.c:1646  */
    {
                cout << "primary -> objectdef" << endl;
            }
#line 2491 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 882 "parser.y" /* yacc.c:1646  */
    {
                cout << "primary -> (funcdef)" << endl;

                (yyval.exprValue) = new_expr(programfunc_e);
                (yyval.exprValue)->sym = (yyvsp[-1].symbValue); 
            }
#line 2502 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 888 "parser.y" /* yacc.c:1646  */
    { cout << "primary -> const" << endl; }
#line 2508 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 892 "parser.y" /* yacc.c:1646  */
    {   
                cout << "lvalue -> id" << endl;

                GLOBAL_ID = (yyvsp[0].stringValue);

                SymbolTableEntry * entry_ptr = Lookup(create_entry((yyvsp[0].stringValue),0,0,LLOCAL, FUNC_DEPTH),SCOPE);
                SymbolTableEntry entry=create_entry((yyvsp[0].stringValue), SCOPE, yylineno, GLOBAL, FUNC_DEPTH);
                if(entry_ptr== NULL ){

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
                        }
                    }
                    (yyval.exprValue) = lvalue_expr(update_entry(*entry_ptr));
                }
            }
#line 2545 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 925 "parser.y" /* yacc.c:1646  */
    {
                cout << "lvalue -> local id" << endl;

                GLOBAL_ID=(yyvsp[0].stringValue);
                SymbolTableEntry entry = create_entry((yyvsp[0].stringValue), SCOPE, yylineno, GLOBAL, FUNC_DEPTH);
                SymbolTableEntry *entry_ptr = Lookup_scope(entry, SCOPE);
                if(entry_ptr==NULL){

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
                }
                else {
                    if(isFunction(*entry_ptr)) lwarning = true;
                    (yyval.exprValue) = lvalue_expr(update_entry(*entry_ptr));
                }
            }
#line 2577 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 953 "parser.y" /* yacc.c:1646  */
    {
                cout << "lvalue -> ::id" << endl;

                if(!Lookup_scope(create_entry((yyvsp[0].stringValue),0,0,LLOCAL, FUNC_DEPTH),0)){
                    cout << "\033[1;31m" << 
                    "Global id not found at line "<< yylineno <<
                    "\033[0m" << endl;
                }else
                    (yyval.exprValue) = lvalue_expr(update_entry(*Lookup_scope(create_entry((yyvsp[0].stringValue),0,0,LLOCAL, FUNC_DEPTH),0)  ));
            }
#line 2592 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 964 "parser.y" /* yacc.c:1646  */
    {
                cout << "lvalue -> member" << endl;
                (yyval.exprValue) = (yyvsp[0].exprValue);
            }
#line 2601 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 971 "parser.y" /* yacc.c:1646  */
    {  
                SymbolTableEntry entry = create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH);
                SymbolTableEntry *entry_ptr = Lookup(entry,SCOPE);
                if(entry_ptr){      
                    if(isFunction(*entry_ptr) && lwarning){
                            cout << "\033[1;31m" << 
                            "Function used as lvalue at line "<< yylineno <<
                            "\033[0m" << endl;

                            lwarning = false;
                        
                    }
                }
             }
#line 2620 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 986 "parser.y" /* yacc.c:1646  */
    {
                cout << "assignexpr -> lvalue = expr" << endl;

                
                if((yyvsp[-3].exprValue)->type != tableitem_e)
                {
                    if(!(yyvsp[0].exprValue)->truelist.empty()) {

                        (yyvsp[0].exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);

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

                        emit(assign, (yyvsp[-3].exprValue), nullptr, (yyval.exprValue), 0, yylineno);
                        
                    }else{
                        
                        emit(assign, (yyvsp[0].exprValue), nullptr, (yyvsp[-3].exprValue), 0, yylineno);
                        (yyval.exprValue) = new_expr(assignexpr_e);
                        (yyval.exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);

                        emit(assign, (yyvsp[-3].exprValue), nullptr, (yyval.exprValue), 0, yylineno);
                    }
                }
                else
                {
                    emit(tablesetelem, (yyvsp[-3].exprValue), (yyvsp[-3].exprValue)->index, (yyvsp[0].exprValue), 0, yylineno);
                    (yyval.exprValue) = emit_iftableitem((yyvsp[-3].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                    (yyval.exprValue)->type = assignexpr_e;
                }
               
            }
#line 2672 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 1033 "parser.y" /* yacc.c:1646  */
    {
                cout << "\033[1;31m" << 
                        "Function used as lvalue at line "<< yylineno <<
                        "\033[0m" << endl;
            }
#line 2682 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 1040 "parser.y" /* yacc.c:1646  */
    {lwarning = false;}
#line 2688 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 1041 "parser.y" /* yacc.c:1646  */
    {
                cout << "member -> lvalue.id" << endl;
                
                (yyvsp[-3].exprValue)   = emit_iftableitem((yyvsp[-3].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                
                expr* ti  = new_expr(tableitem_e); 
                ti->sym   = (yyvsp[-3].exprValue)->sym;
                
                ti->index = new_expr(conststring_e);
                
                
                ti->index->strConst = strdup((yyvsp[0].stringValue));
                

                (yyval.exprValue) =  ti;

            }
#line 2710 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 1059 "parser.y" /* yacc.c:1646  */
    { 
                                                cout << "member -> lvalue[expr]" << endl;
                                                (yyvsp[-3].exprValue)   = emit_iftableitem((yyvsp[-3].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                                                expr* ti  = new_expr(tableitem_e); 
                                                ti->sym   = (yyvsp[-3].exprValue)->sym;

                                                ti->index = (yyvsp[-1].exprValue);

                                                (yyval.exprValue) =  ti;
                                            }
#line 2725 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 1069 "parser.y" /* yacc.c:1646  */
    {lwarning = false;}
#line 2731 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 1070 "parser.y" /* yacc.c:1646  */
    { 
                                                cout << "member -> call.id" << endl; 
                                            }
#line 2739 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 1074 "parser.y" /* yacc.c:1646  */
    { 
                                                cout << "member -> call[expr]" << endl;

                                                (yyvsp[-3].exprValue)   = emit_iftableitem((yyvsp[-3].exprValue), SCOPE, yylineno, FUNC_DEPTH);
                                                expr* ti  = new_expr(tableitem_e); 
                                                ti->sym   = (yyvsp[-3].exprValue)->sym;

                                                ti->index = (yyvsp[-1].exprValue);

                                                (yyval.exprValue) =  ti;
                                            }
#line 2755 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 1088 "parser.y" /* yacc.c:1646  */
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
#line 2772 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 1101 "parser.y" /* yacc.c:1646  */
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
                    
                    (yyvsp[0].callValue)->elist->next = t ;
                    reversed_elist.insert(reversed_elist.begin(), 1, t);
                }
                (yyval.exprValue) = make_call((yyvsp[-1].exprValue), reversed_elist, SCOPE, yylineno, FUNC_DEPTH);
            }
#line 2798 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 1123 "parser.y" /* yacc.c:1646  */
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
#line 2818 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 1141 "parser.y" /* yacc.c:1646  */
    {
                cout << "callsuffix -> normcall" << endl; 

                (yyval.callValue) = (yyvsp[0].callValue);
            }
#line 2828 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 1147 "parser.y" /* yacc.c:1646  */
    {
                cout << "callsuffix -> methodcall" << endl; 

                (yyval.callValue) = (yyvsp[0].callValue);
            }
#line 2838 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 1155 "parser.y" /* yacc.c:1646  */
    { 
                cout << "normcall -> (elist)" << endl;

                (yyval.callValue) = new struct call;
        
                (yyval.callValue)->elist = (yyvsp[-1].exprValue);
                (yyval.callValue)->method = 0;
                (yyval.callValue)->name = nullptr;
            }
#line 2852 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 1167 "parser.y" /* yacc.c:1646  */
    { 
                cout << "methodcall -> ..id(elist)" << endl;

                (yyval.callValue) = new struct call;

                (yyval.callValue)->elist = (yyvsp[-1].exprValue);
                (yyval.callValue)->method = 1;
                (yyval.callValue)->name = (yyvsp[-3].stringValue);
            }
#line 2866 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 1179 "parser.y" /* yacc.c:1646  */
    {
                if(isLogic) {

                    (yyvsp[0].exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);

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
                isnt = false;
            }
#line 2893 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 1202 "parser.y" /* yacc.c:1646  */
    {
                cout << "elist -> expr commaexpr" << endl; 

                (yyval.exprValue)->next  = (yyvsp[0].exprValue);
            }
#line 2903 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 1208 "parser.y" /* yacc.c:1646  */
    { 
                cout << "elist -> " << endl;

                (yyval.exprValue) = nullptr;
            }
#line 2913 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 1217 "parser.y" /* yacc.c:1646  */
    {
                if(isLogic) {

                    (yyvsp[0].exprValue)->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);

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
                isnt = false;
            }
#line 2940 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 1240 "parser.y" /* yacc.c:1646  */
    { 
                cout << "commaexpr -> ,expr commaexpr" << endl; 
                (yyval.exprValue) = (yyvsp[-2].exprValue);
                (yyval.exprValue)->next = (yyvsp[0].exprValue);
            }
#line 2950 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 1246 "parser.y" /* yacc.c:1646  */
    { 
                cout << "commaexpr -> " << endl; 

                (yyval.exprValue) = nullptr;
            }
#line 2960 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 1253 "parser.y" /* yacc.c:1646  */
    { 
                                                    cout << "objectdef -> [elist]" << endl; 

                                                    expr* t = new_expr(tableitem_e);
                                                    t->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                                                    emit(tablecreate, nullptr, nullptr, t, 0, yylineno);

                                                    for (int i = 0; (yyvsp[-1].exprValue); (yyvsp[-1].exprValue) = (yyvsp[-1].exprValue)->next){
                                                        
                                                        expr* e = new_expr(constnum_e);
                                                        e->numConst = i++;
                                                        emit(tablesetelem, e, (yyvsp[-1].exprValue), t, 0, yylineno);
                                                    } 
                                                    
                                                    (yyval.exprValue) = t;
                                                }
#line 2981 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 1270 "parser.y" /* yacc.c:1646  */
    { 
                                                    cout << "objectdef -> [indexed]" << endl;

                                                    expr* t = new_expr(tableitem_e);
                                                    t->sym = newtemp(SCOPE, yylineno, FUNC_DEPTH);
                                                    emit(tablecreate, nullptr, nullptr, t, 0, yylineno);

                                                    expr* temp = (yyvsp[-1].exprValue);
                                                    while(temp) {
                                                        emit(tablesetelem, temp->index, temp, t, 0 , yylineno);
                                                        temp = temp->next;
                                                    }

                                                    (yyval.exprValue) = t;
                                                }
#line 3001 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 1288 "parser.y" /* yacc.c:1646  */
    {
                                                        cout << "indexed -> indexedelem commaindexedelem" << endl;

                                                        (yyval.exprValue)->next = (yyvsp[0].exprValue);
                                                    }
#line 3011 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 1295 "parser.y" /* yacc.c:1646  */
    {
                                                            cout << "commaindexelem -> ,indexelem commaindexelem" << endl;

                                                            (yyval.exprValue) = (yyvsp[-1].exprValue);
                                                            (yyval.exprValue)->next = (yyvsp[0].exprValue);
                                                        }
#line 3022 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 1301 "parser.y" /* yacc.c:1646  */
    {
                                                            cout << "commaindexelem -> " << endl;

                                                            (yyval.exprValue) = nullptr;
                                                        }
#line 3032 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 1309 "parser.y" /* yacc.c:1646  */
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
#line 3085 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 1360 "parser.y" /* yacc.c:1646  */
    {
                        SCOPE++;
                    }
#line 3093 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 1364 "parser.y" /* yacc.c:1646  */
    {
                        cout << "block -> {}" << endl;
                        Hide(SCOPE--);
                    }
#line 3102 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 1369 "parser.y" /* yacc.c:1646  */
    {
                        SCOPE++;
                    }
#line 3110 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 1374 "parser.y" /* yacc.c:1646  */
    {
                        cout << "block -> {stmt program}" << endl;
                        Hide(SCOPE--);
                    }
#line 3119 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 1382 "parser.y" /* yacc.c:1646  */
    {
                        SymbolTableEntry entry = create_entry(generate_function_name(),SCOPE,yylineno,USERFUNC, FUNC_DEPTH);
                        Insert(entry);
                        FUNC_DEPTH++;
                        
                        if(!scopeoffsetStack.empty())
                            scopeoffsetStack.back()->sym->value.funVal->totalLocals = currscopeoffset();

                        expr *expr = new_expr(programfunc_e);
                        expr->sym = update_entry(entry);
                        expr->sym->value.funVal->iaddress = nextquadlabel();
                        
                        emit(funcstart, nullptr, nullptr, expr, 0, yylineno);

                        scopeoffsetStack.push_back(expr);
                        enterscopespace();
                        resetformalargsoffset();
                    }
#line 3142 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 1401 "parser.y" /* yacc.c:1646  */
    {
                        SCOPE++;
                        enterscopespace();
                    }
#line 3151 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 1407 "parser.y" /* yacc.c:1646  */
    {
                        SCOPE--;
                        resetfunctionlocalsoffset();
                        enterscopespace();
                    }
#line 3161 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 1413 "parser.y" /* yacc.c:1646  */
    {
                        cout << "funcdef -> function (idlist) block" << endl;
                        exitscopespace();
                        exitscopespace();

                        emit(funcend, nullptr, nullptr, scopeoffsetStack.back(), 0, yylineno);

                        scopeoffsetStack.back()->sym->value.funVal->totalLocals = currscopeoffset();
                        (yyval.symbValue) = scopeoffsetStack.back()->sym;
                        scopeoffsetStack.pop_back();
                        

                        if(!scopeoffsetStack.empty()){
                            inccurentscopeoffset(scopeoffsetStack.back()->sym->value.funVal->totalLocals);
                        }
                    }
#line 3182 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 1429 "parser.y" /* yacc.c:1646  */
    {fflag = true;}
#line 3188 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 1431 "parser.y" /* yacc.c:1646  */
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
                            }else{
                                Insert(entry);
                            }
                        }else if(entry_ptr->type == LIBFUNC){
                            cout << "\033[1;31m" << 
                            "Lib function redeclaration at line "<< yylineno <<
                            "\033[0m" << endl;
                        }else if(entry_ptr->type == USERFUNC){
                            cout << "\033[1;31m" << 
                            "User function redeclaration at line "<< yylineno <<
                            "\033[0m" << endl;
                        }else if(entry_ptr->type==GLOBAL||entry_ptr->type==LLOCAL||entry_ptr->type==FORMAL){
                            cout << "\033[1;31m" << 
                            "Variable already defined at line "<< yylineno <<
                            "\033[0m" << endl;
                        }
                        FUNC_DEPTH++;
                        if(!scopeoffsetStack.empty())
                            scopeoffsetStack.back()->sym->value.funVal->totalLocals = currscopeoffset();

                        expr *expr = new_expr(programfunc_e);
                        expr->sym = update_entry(entry);
                        expr->sym->value.funVal->iaddress = nextquadlabel();
                        
                        emit(funcstart, nullptr, nullptr, expr, 0, yylineno);

                        scopeoffsetStack.push_back(expr);
                        enterscopespace();
                        resetformalargsoffset();
                    }
#line 3235 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 1474 "parser.y" /* yacc.c:1646  */
    {
                        SCOPE++;
                        enterscopespace();
                    }
#line 3244 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 1480 "parser.y" /* yacc.c:1646  */
    {
                        SCOPE--;
                        enterscopespace();
                        resetfunctionlocalsoffset();
                    }
#line 3254 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 1486 "parser.y" /* yacc.c:1646  */
    {
                        cout << "funcdef -> function id(idlist) block" << endl;
                        FUNC_DEPTH--;
                        exitscopespace();
                        exitscopespace();

                        emit(funcend, nullptr, nullptr, scopeoffsetStack.back(), 0, yylineno);

                        scopeoffsetStack.back()->sym->value.funVal->totalLocals = currscopeoffset();
                        (yyval.symbValue) = scopeoffsetStack.back()->sym;
                        scopeoffsetStack.pop_back();

                        if(!scopeoffsetStack.empty()){
                            inccurentscopeoffset(scopeoffsetStack.back()->sym->value.funVal->totalLocals);
                        }
                    }
#line 3275 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 1504 "parser.y" /* yacc.c:1646  */
    { 
                                    cout << "const -> real" << endl;
                                    (yyval.exprValue) = new_expr(constnum_e);
                                    (yyval.exprValue)->numConst = (yyvsp[0].realValue);
                                }
#line 3285 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 1509 "parser.y" /* yacc.c:1646  */
    { 
                                    cout << "const -> integer" << endl; 
                                    (yyval.exprValue) = new_expr(constnum_e);
                                    (yyval.exprValue)->numConst = (yyvsp[0].intValue);
                                }
#line 3295 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 1514 "parser.y" /* yacc.c:1646  */
    {
                                    cout << "const -> string" << endl; 
                                    (yyval.exprValue) = new_expr(conststring_e);
                                    (yyval.exprValue)->strConst = (yyvsp[0].stringValue);
                                }
#line 3305 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 1519 "parser.y" /* yacc.c:1646  */
    { 
                                    cout << "const -> nil" << endl;
                                    (yyval.exprValue) = new_expr(nil_e);
                                    //! NIL == empty string
                                    //$const->strConst = nullptr;
                                }
#line 3316 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 1525 "parser.y" /* yacc.c:1646  */
    { 
                                    cout << "const -> true" << endl;
                                    (yyval.exprValue) = new_expr(constbool_e);
                                    (yyval.exprValue)->boolConst = true;
                                }
#line 3326 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1530 "parser.y" /* yacc.c:1646  */
    { 
                                    cout << "const -> false" << endl;
                                    (yyval.exprValue) = new_expr(constbool_e);
                                    (yyval.exprValue)->boolConst = false; 
                                }
#line 3336 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1538 "parser.y" /* yacc.c:1646  */
    {
                        FORMAL_ARGUMENTS.clear();
                        SymbolTableEntry entry = create_entry((yyvsp[0].stringValue), SCOPE, yylineno, FORMAL, FUNC_DEPTH);

                        SymbolTableEntry* entry_ptr = Lookup_scope(entry, 0);
                        if(entry_ptr != NULL){
                            if(entry_ptr->type != LIBFUNC){
                                Insert(entry);
                                FORMAL_ARGUMENTS.push_back(entry);
                            }else{
                                cout << "\033[1;31m" << 
                                "Library function as formal argument at line "<< yylineno <<
                                "\033[0m" << endl;
                            }
                        }else{
                            Insert(entry);
                            FORMAL_ARGUMENTS.push_back(entry);
                        }     
                    }
#line 3360 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1557 "parser.y" /* yacc.c:1646  */
    { cout << "idlist -> id commaid" << endl; }
#line 3366 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1558 "parser.y" /* yacc.c:1646  */
    { cout << "idlist -> " << endl; }
#line 3372 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1563 "parser.y" /* yacc.c:1646  */
    {
                        SymbolTableEntry entry = create_entry((yyvsp[0].stringValue), SCOPE, yylineno, FORMAL, FUNC_DEPTH);

                        SymbolTableEntry* entry_ptr = Lookup_scope(entry, 0);
                        if(entry_ptr != NULL){
                            if(entry_ptr->type != LIBFUNC){
                                Insert(entry);
                                FORMAL_ARGUMENTS.push_back(entry);
                            }else{
                                cout << "\033[1;31m" << 
                                "Library function as formal argument at line "<< yylineno <<
                                "\033[0m" << endl;
                            }
                        }else{
                            for(int i=0; i<FORMAL_ARGUMENTS.size(); i++){
                                if((yyvsp[0].stringValue) == get_name(FORMAL_ARGUMENTS.at(i))){
                                    cout << "\033[1;31m" << 
                                    "Formal redeclaration at line "<< yylineno <<
                                    "\033[0m" << endl;
                                }else{                
                                    Insert(entry);
                                }
                            }
                        }    
                    }
#line 3402 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1588 "parser.y" /* yacc.c:1646  */
    { cout << "commaid -> ,id commaid" << endl; }
#line 3408 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1589 "parser.y" /* yacc.c:1646  */
    { cout << "commaid -> " << endl; }
#line 3414 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1593 "parser.y" /* yacc.c:1646  */
    {
                        cout << "ifprefix -> if(expr)" << endl;

                        expr *e = new_expr(constbool_e);
                        e->boolConst = 1;
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
                        emit(if_eq, e, nullptr, (yyvsp[-1].exprValue), nextquadlabel() + 2, yylineno);

                        (yyval.unsdValue) = nextquadlabel();
                        emit(jump, nullptr, nullptr, nullptr, 0, yylineno);
                        
                    }
#line 3446 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1623 "parser.y" /* yacc.c:1646  */
    {
                        cout << "ifstmt -> ifprefix stmt" << endl;

                        patchlabel((yyvsp[-1].unsdValue), nextquadlabel());
                        
                    }
#line 3457 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1630 "parser.y" /* yacc.c:1646  */
    { 
                        cout << "ifstmt -> ifprefix stmt elseprefix stmt" << endl;

                        patchlabel((yyvsp[-3].unsdValue), (yyvsp[-1].unsdValue) + 1);
                        patchlabel((yyvsp[-1].unsdValue), nextquadlabel());
                    }
#line 3468 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1639 "parser.y" /* yacc.c:1646  */
    {
                        cout << "ifstmt -> elseprefix" << endl;

                        (yyval.unsdValue) = nextquadlabel();
                        emit(jump, nullptr, nullptr, nullptr, 0, yylineno);
                    }
#line 3479 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1648 "parser.y" /* yacc.c:1646  */
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
                    }
#line 3499 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1666 "parser.y" /* yacc.c:1646  */
    {
                        cout << "whilecond -> (expr)" << endl;

                        expr* e = new_expr(constbool_e);
                        e->boolConst = 1;
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
                        emit(if_eq,nullptr, e, (yyvsp[-1].exprValue), nextquadlabel() + 2, yylineno);

                        (yyval.unsdValue) = nextquadlabel();
                        
                        emit(jump, nullptr, nullptr, nullptr, 0, yylineno);
                    }
#line 3531 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1696 "parser.y" /* yacc.c:1646  */
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
                        if(continue_quads.size()>0)
                            continue_quads.pop_back();
                        if(break_quads.size()>0)
                            break_quads.pop_back();

                        loop_counter--;
                        if(loop_counter < 0) loop_counter=0;
                    }
#line 3564 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1726 "parser.y" /* yacc.c:1646  */
    { 
                        (yyval.unsdValue) = nextquadlabel(); 
                        emit(jump,nullptr,nullptr, nullptr, 0, yylineno); 
                    }
#line 3573 "parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1732 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.unsdValue) = nextquadlabel(); 
                    }
#line 3581 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1737 "parser.y" /* yacc.c:1646  */
    {loop_counter++;}
#line 3587 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1738 "parser.y" /* yacc.c:1646  */
    {
                        cout << "forprefix -> for(elist;expr;" << endl;

                        (yyval.forjValue) = new struct forJump;
                        (yyval.forjValue)->test = (yyvsp[-2].unsdValue);
                        
                        expr *e = new_expr(constbool_e);
                        e->boolConst = 1;
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
                        emit(if_eq, e, nullptr, (yyvsp[-1].exprValue), 0, yylineno);
                        vector<int> v;
                        continue_quads.push_back(v);
                        break_quads.push_back(v);
                    }
#line 3622 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1771 "parser.y" /* yacc.c:1646  */
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
                        if(continue_quads.size()>0)
                            continue_quads.pop_back();
                        if(break_quads.size()>0)
                            break_quads.pop_back();
                        loop_counter--;
                        if(loop_counter < 0) loop_counter=0;
                    }
#line 3657 "parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1803 "parser.y" /* yacc.c:1646  */
    {
                        if(FUNC_DEPTH==0){
                            cout << "\033[1;31m" << 
                                    "Return outside of function at line "<< yylineno <<
                                    "\033[0m" << endl;
                        }

                    }
#line 3670 "parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1812 "parser.y" /* yacc.c:1646  */
    { 
                        cout << "returnstmt -> return expr;" << endl;

                        emit(ret, nullptr, nullptr, (yyvsp[-1].exprValue), 0, yylineno);
                    }
#line 3680 "parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1817 "parser.y" /* yacc.c:1646  */
    {
                        if(FUNC_DEPTH==0){
                            cout << "\033[1;31m" << 
                                    "Return outside of function at line "<< yylineno <<
                                    "\033[0m" << endl;
                        }
                    }
#line 3692 "parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1824 "parser.y" /* yacc.c:1646  */
    { 
                        cout << "returnstmt -> return;" << endl; 

                        emit(ret, nullptr, nullptr, nullptr, 0, yylineno);
                    }
#line 3702 "parser.cpp" /* yacc.c:1646  */
    break;


#line 3706 "parser.cpp" /* yacc.c:1646  */
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
#line 1833 "parser.y" /* yacc.c:1906  */


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
    
    
    yyparse();
    
    print_symbol_table();
    print_quads();

    return 0;
}
