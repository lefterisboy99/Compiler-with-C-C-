/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

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

    int SCOPE = 0;
    string GLOBAL_ID;
    vector<SymbolTableEntry> FORMAL_ARGUMENTS; 

#line 83 "parser.cpp" /* yacc.c:339  */

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

union YYSTYPE
{
#line 20 "parser.y" /* yacc.c:355  */

    int intValue;
    char* stringValue;
    double realValue;

#line 235 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 252 "parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  68
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   496

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  201

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
       0,    85,    85,    86,    90,    95,    96,    97,    98,    99,
      99,   108,   108,   115,   116,   117,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   137,   138,   139,   140,   154,   153,   164,   178,   177,
     187,   191,   192,   193,   194,   195,   198,   227,   251,   261,
     265,   264,   280,   287,   287,   288,   289,   289,   290,   293,
     294,   294,   304,   307,   308,   311,   314,   317,   318,   321,
     322,   325,   326,   330,   333,   334,   337,   341,   340,   350,
     349,   363,   369,   374,   362,   378,   380,   413,   418,   378,
     428,   429,   430,   431,   432,   433,   437,   436,   457,   462,
     460,   488,   491,   492,   495,   495,   504,   504,   513,   513,
     521,   521
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
  "UMINUS", "$accept", "program", "stmt", "$@1", "$@2", "expr", "term",
  "$@3", "$@4", "primary", "lvalue", "assignexpr", "$@5", "member", "$@6",
  "$@7", "call", "$@8", "callsuffix", "normcall", "methodcall", "elist",
  "commaexpr", "objectdef", "indexed", "commaindexedelem", "indexedelem",
  "block", "$@9", "$@10", "funcdef", "$@11", "$@12", "$@13", "$@14",
  "$@15", "$@16", "$@17", "const", "idlist", "$@18", "commaid", "$@19",
  "ifstmt", "whilestmt", "$@20", "forstmt", "$@21", "returnstmt", "$@22",
  "$@23", YY_NULLPTR
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

#define YYPACT_NINF -178

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-178)))

#define YYTABLE_NINF -111

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-111)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      81,  -178,  -178,  -178,    -4,  -178,  -178,   -35,  -178,  -178,
       8,   -27,  -178,  -178,   190,  -178,  -178,   190,     6,     6,
      -5,   138,   184,  -178,    39,    52,    81,   234,  -178,  -178,
       3,  -178,  -178,    -1,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,   190,    25,    29,    31,    70,   190,    45,
      48,    50,  -178,  -178,    96,    78,    30,    78,    83,    81,
     190,   213,    88,    89,    79,   294,    90,  -178,  -178,  -178,
     190,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,  -178,   190,  -178,    98,   100,   135,   -16,
     190,   190,   190,  -178,   313,   190,   190,  -178,  -178,   254,
    -178,  -178,  -178,    95,  -178,    81,    -6,   190,  -178,  -178,
    -178,   101,  -178,  -178,   104,   431,   418,    73,   444,   444,
     457,   457,   457,   457,  -178,  -178,  -178,    73,   351,   140,
    -178,  -178,   190,   190,   142,  -178,  -178,  -178,   405,   369,
     107,   144,    81,   332,   108,   146,   112,  -178,   104,   116,
     190,   213,    79,   190,  -178,  -178,   405,   113,   115,  -178,
    -178,  -178,   147,    81,   190,  -178,   121,  -178,  -178,   387,
    -178,  -178,   122,  -178,   190,    81,  -178,   274,   123,  -178,
     146,  -178,  -178,   124,  -178,   190,   159,  -178,   134,   130,
    -178,   131,  -178,  -178,  -178,    81,   123,   134,  -178,  -178,
    -178
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    92,    91,    90,     0,    93,    46,     0,   104,   106,
      81,   108,     9,    11,     0,    94,    95,     0,     0,     0,
      79,    68,     0,    15,     0,     0,     3,     0,    30,    32,
      41,    16,    49,    42,    43,    13,    14,    45,     5,     6,
       7,     8,    47,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    40,    33,     0,    37,     0,    34,     0,     0,
       0,    70,     0,     0,    75,     0,     0,    48,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     0,    53,     0,     0,     0,     0,
       0,     0,    68,    56,     0,     0,    68,    82,    86,     0,
     111,    10,    12,     0,    78,     3,     0,     0,    67,    71,
      72,     0,    73,    31,    44,    28,    29,    18,    26,    27,
      22,    24,    23,    25,    21,    19,    20,    17,     0,     0,
      36,    39,     0,    68,     0,    61,    63,    64,    52,     0,
       0,     0,     0,     0,     0,    98,     0,   109,     0,     0,
       0,    70,    75,    68,    55,    54,    51,     0,     0,    58,
      59,    57,   102,     0,     0,    96,     0,    87,    80,     0,
      69,    74,     0,    65,    68,     0,   105,     0,   101,    83,
      98,    76,    62,     0,   103,    68,     0,    97,     0,     0,
      66,     0,    99,    84,    88,     0,   101,     0,   107,   100,
      89
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,   -22,   -58,  -178,  -178,   -14,  -178,  -178,  -178,  -178,
      21,  -178,  -178,  -178,  -178,  -178,    94,  -178,  -178,  -178,
    -178,   -82,    26,  -178,  -178,    27,    72,  -177,  -178,  -178,
     -10,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,     1,
    -178,   -12,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    50,    51,    27,    28,    86,    87,    29,
      30,    31,    88,    32,   129,   141,    33,    89,   135,   136,
     137,    62,   108,    34,    63,   112,    64,    35,    58,    59,
      36,    46,   145,   188,    47,   146,   180,   197,    37,   166,
     178,   187,   196,    38,    39,    44,    40,    45,    41,    48,
      49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,   105,    90,    53,    69,    42,   -50,    61,    65,    43,
     140,   193,    66,     4,   144,     6,    70,   -85,    71,  -110,
     200,    72,    73,    74,    75,    76,    77,    78,   133,    94,
      79,    80,    81,    82,    99,   134,   -77,   -38,   -35,    55,
      57,    91,   150,    92,   103,    84,   106,   -60,    67,    93,
      54,   157,    68,    85,   -60,    24,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    95,
     128,   172,    91,    96,    92,    97,   138,   139,    61,    98,
      93,   143,    61,   149,   162,     1,     2,     3,     4,     5,
       6,   100,   183,   151,   101,     7,   102,     8,     9,    10,
      11,    12,    13,   191,    14,   176,    15,    16,    17,    79,
      80,    81,    56,    56,    10,    18,    19,   184,   156,    61,
      84,    20,   -60,    21,   104,    22,   111,    23,    85,   -60,
      24,   109,   110,   130,   131,   114,   169,   198,   132,    61,
     148,    60,     1,     2,     3,     4,     5,     6,   153,   155,
     177,   158,   160,   161,   164,   165,   167,   168,   173,   174,
      61,    14,   175,    15,    16,    17,   179,   182,   192,   190,
     186,    61,    18,    19,    20,   194,   195,   170,    60,   171,
      21,   189,    22,   152,   199,     0,     0,    24,     1,     2,
       3,     4,     5,     6,     1,     2,     3,     4,     5,     6,
       0,     0,    10,     0,     0,     0,     0,    14,     0,    15,
      16,    17,     0,    14,     0,    15,    16,    17,    18,    19,
       0,     0,     0,     0,    18,    19,    21,     0,    22,     0,
       0,     0,    21,    24,    22,    70,     0,    71,     0,    24,
      72,    73,    74,    75,    76,    77,    78,     0,     0,    79,
      80,    81,    82,     0,     0,     0,    70,     0,    71,     0,
     107,    72,    73,    74,    75,    76,    77,    78,     0,     0,
      79,    80,    81,    82,     0,     0,    70,     0,    71,     0,
      83,    72,    73,    74,    75,    76,    77,    78,     0,     0,
      79,    80,    81,    82,     0,     0,    70,     0,    71,     0,
     147,    72,    73,    74,    75,    76,    77,    78,     0,     0,
      79,    80,    81,    82,     0,     0,    70,     0,    71,     0,
     185,    72,    73,    74,    75,    76,    77,    78,     0,     0,
      79,    80,    81,    82,     0,    70,     0,    71,     0,   113,
      72,    73,    74,    75,    76,    77,    78,     0,     0,    79,
      80,    81,    82,     0,    70,     0,    71,     0,   142,    72,
      73,    74,    75,    76,    77,    78,     0,     0,    79,    80,
      81,    82,     0,    70,     0,    71,     0,   163,    72,    73,
      74,    75,    76,    77,    78,     0,     0,    79,    80,    81,
      82,    70,     0,    71,   154,     0,    72,    73,    74,    75,
      76,    77,    78,     0,     0,    79,    80,    81,    82,    70,
       0,    71,   159,     0,    72,    73,    74,    75,    76,    77,
      78,     0,     0,    79,    80,    81,    82,    70,   181,    71,
       0,     0,    72,    73,    74,    75,    76,    77,    78,     0,
      70,    79,    80,    81,    82,    72,    73,    74,    75,    76,
      77,    78,     0,     0,    79,    80,    81,    82,    72,    73,
      74,    75,    76,    77,    78,     0,     0,    79,    80,    81,
      82,    72,  -111,  -111,    75,    76,    77,    78,     0,     0,
      79,    80,    81,    82,    72,     0,     0,  -111,  -111,  -111,
    -111,     0,     0,    79,    80,    81,    82
};

static const yytype_int16 yycheck[] =
{
      14,    59,     3,    17,    26,     9,     3,    21,    22,    44,
      92,   188,    22,     7,    96,     9,    22,     9,    24,    46,
     197,    27,    28,    29,    30,    31,    32,    33,    44,    43,
      36,    37,    38,    39,    48,    51,    41,    34,    35,    18,
      19,    42,    48,    44,    54,    42,    60,    44,     9,    50,
      44,   133,     0,    50,    51,    49,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    44,
      84,   153,    42,    44,    44,    44,    90,    91,    92,     9,
      50,    95,    96,   105,   142,     4,     5,     6,     7,     8,
       9,    46,   174,   107,    46,    14,    46,    16,    17,    18,
      19,    20,    21,   185,    23,   163,    25,    26,    27,    36,
      37,    38,    18,    19,    18,    34,    35,   175,   132,   133,
      42,    40,    44,    42,    41,    44,    47,    46,    50,    51,
      49,    43,    43,    35,    34,    45,   150,   195,     3,   153,
      45,    40,     4,     5,     6,     7,     8,     9,    44,     9,
     164,     9,    45,     9,    46,     9,    44,    41,    45,    44,
     174,    23,    15,    25,    26,    27,    45,    45,     9,    45,
      47,   185,    34,    35,    40,    45,    45,   151,    40,   152,
      42,   180,    44,   111,   196,    -1,    -1,    49,     4,     5,
       6,     7,     8,     9,     4,     5,     6,     7,     8,     9,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    23,    -1,    25,
      26,    27,    -1,    23,    -1,    25,    26,    27,    34,    35,
      -1,    -1,    -1,    -1,    34,    35,    42,    -1,    44,    -1,
      -1,    -1,    42,    49,    44,    22,    -1,    24,    -1,    49,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    36,
      37,    38,    39,    -1,    -1,    -1,    22,    -1,    24,    -1,
      47,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
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
      40,    42,    44,    46,    49,    55,    56,    59,    60,    63,
      64,    65,    67,    70,    77,    81,    84,    92,    97,    98,
     100,   102,     9,    44,    99,   101,    85,    88,   103,   104,
      57,    58,    59,    59,    44,    64,    70,    64,    82,    83,
      40,    59,    75,    78,    80,    59,    84,     9,     0,    55,
      22,    24,    27,    28,    29,    30,    31,    32,    33,    36,
      37,    38,    39,    46,    42,    50,    61,    62,    66,    71,
       3,    42,    44,    50,    59,    44,    44,    44,     9,    59,
      46,    46,    46,    84,    41,    56,    59,    47,    76,    43,
      43,    47,    79,    45,    45,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    68,
      35,    34,     3,    44,    51,    72,    73,    74,    59,    59,
      75,    69,    45,    59,    75,    86,    89,    46,    45,    55,
      48,    59,    80,    44,    43,     9,    59,    75,     9,    43,
      45,     9,    56,    45,    46,     9,    93,    44,    41,    59,
      76,    79,    75,    45,    44,    15,    56,    59,    94,    45,
      90,    41,    45,    75,    56,    46,    47,    95,    87,    93,
      45,    75,     9,    81,    45,    45,    96,    91,    56,    95,
      81
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    56,    56,    56,    57,
      56,    58,    56,    56,    56,    56,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    60,    60,    60,    60,    61,    60,    60,    62,    60,
      60,    63,    63,    63,    63,    63,    64,    64,    64,    64,
      66,    65,    65,    68,    67,    67,    69,    67,    67,    70,
      71,    70,    70,    72,    72,    73,    74,    75,    75,    76,
      76,    77,    77,    78,    79,    79,    80,    82,    81,    83,
      81,    85,    86,    87,    84,    88,    89,    90,    91,    84,
      92,    92,    92,    92,    92,    92,    94,    93,    93,    96,
      95,    95,    97,    97,    99,    98,   101,   100,   103,   102,
     104,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     0,
       3,     0,     3,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     1,     2,     2,     0,     3,     2,     0,     3,
       2,     1,     1,     1,     3,     1,     1,     2,     2,     1,
       0,     4,     3,     0,     4,     4,     0,     4,     4,     4,
       0,     3,     6,     1,     1,     3,     5,     2,     0,     3,
       0,     3,     3,     2,     3,     0,     5,     0,     3,     0,
       5,     0,     0,     0,     8,     0,     0,     0,     0,    10,
       1,     1,     1,     1,     1,     1,     0,     3,     0,     0,
       4,     0,     5,     7,     0,     6,     0,    10,     0,     4,
       0,     3
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
#line 85 "parser.y" /* yacc.c:1646  */
    { cout << "program -> stmt*" << endl; }
#line 1543 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 86 "parser.y" /* yacc.c:1646  */
    { cout << "program -> " << endl; }
#line 1549 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 91 "parser.y" /* yacc.c:1646  */
    {
                cout << "stmt -> expr;" << endl;
                lwarning = false;
            }
#line 1558 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 95 "parser.y" /* yacc.c:1646  */
    { cout << "stmt -> ifstmt" << endl; }
#line 1564 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 96 "parser.y" /* yacc.c:1646  */
    { cout << "stmt -> whilestmt" << endl; }
#line 1570 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 97 "parser.y" /* yacc.c:1646  */
    { cout << "stmt -> forstmt" << endl; }
#line 1576 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 98 "parser.y" /* yacc.c:1646  */
    { cout << "stmt -> returnstmt" << endl; }
#line 1582 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 99 "parser.y" /* yacc.c:1646  */
    {
                loop_counter--;
                if(loop_counter<0){
                    cout << "\033[1;31m" <<
                        "Can't use break here at line "<< yylineno <<
                        "\033[0m" << endl;
                        loop_counter=0;
                }
            }
#line 1596 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 107 "parser.y" /* yacc.c:1646  */
    { cout << "program -> stmt*" << endl; }
#line 1602 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 108 "parser.y" /* yacc.c:1646  */
    {
                if(loop_counter==0){
                    cout << "\033[1;31m" << 
                        "Can't use continue outside of loops at line "<< yylineno <<
                        "\033[0m" << endl;
                }
            }
#line 1614 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 114 "parser.y" /* yacc.c:1646  */
    { cout << "program -> stmt*" << endl; }
#line 1620 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 115 "parser.y" /* yacc.c:1646  */
    { cout << "stmt -> block" << endl; }
#line 1626 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 116 "parser.y" /* yacc.c:1646  */
    { cout << "stmt -> funcdef" << endl; }
#line 1632 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 117 "parser.y" /* yacc.c:1646  */
    { cout << "stmt -> ;" << endl; }
#line 1638 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 120 "parser.y" /* yacc.c:1646  */
    { cout << "expr -> assignexpr" << endl; }
#line 1644 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 121 "parser.y" /* yacc.c:1646  */
    { cout << "expr -> expr + expr" << endl; }
#line 1650 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 122 "parser.y" /* yacc.c:1646  */
    { cout << "expr -> expr - expr" << endl; }
#line 1656 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 123 "parser.y" /* yacc.c:1646  */
    { cout << "expr -> expr * expr" << endl; }
#line 1662 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 124 "parser.y" /* yacc.c:1646  */
    { cout << "expr -> expr / expr" << endl; }
#line 1668 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 125 "parser.y" /* yacc.c:1646  */
    { cout << "expr -> expr % expr" << endl; }
#line 1674 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 126 "parser.y" /* yacc.c:1646  */
    { cout << "expr -> expr > expr" << endl; }
#line 1680 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 127 "parser.y" /* yacc.c:1646  */
    { cout << "expr -> expr >= expr" << endl; }
#line 1686 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 128 "parser.y" /* yacc.c:1646  */
    { cout << "expr -> expr < expr" << endl; }
#line 1692 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 129 "parser.y" /* yacc.c:1646  */
    { cout << "expr -> expr <= expr" << endl; }
#line 1698 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 130 "parser.y" /* yacc.c:1646  */
    { cout << "expr -> expr == expr" << endl; }
#line 1704 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 131 "parser.y" /* yacc.c:1646  */
    { cout << "expr -> expr != expr" << endl; }
#line 1710 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 132 "parser.y" /* yacc.c:1646  */
    { cout << "expr -> expr && expr" << endl; }
#line 1716 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 133 "parser.y" /* yacc.c:1646  */
    { cout << "expr -> expr || expr" << endl; }
#line 1722 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 134 "parser.y" /* yacc.c:1646  */
    { cout << "expr -> term" << endl; }
#line 1728 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 137 "parser.y" /* yacc.c:1646  */
    { cout << "term -> (expr)" << endl; }
#line 1734 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 138 "parser.y" /* yacc.c:1646  */
    {{ cout << "term -> primary" << endl; }}
#line 1740 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 139 "parser.y" /* yacc.c:1646  */
    { cout << "term -> -expr" << endl; }
#line 1746 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 142 "parser.y" /* yacc.c:1646  */
    {
                cout << "term -> ++lvalue" << endl;

                SymbolTableEntry *entry_ptr = Lookup(create_entry(GLOBAL_ID,0,0,LLOCAL,FUNC_DEPTH), SCOPE);
                if(isFunction(*entry_ptr)){
                    cout << "\033[1;31m" << 
                        "Function used as lvalue (++function)  at line "<< yylineno <<
                        "\033[0m" << endl;
                }
            }
#line 1761 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 154 "parser.y" /* yacc.c:1646  */
    {
                SymbolTableEntry *entry_ptr = Lookup(create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH), SCOPE);
                if(isFunction(*entry_ptr)){
                    cout << "\033[1;31m" << 
                        "Function used as lvalue (function++)  at line "<< yylineno <<
                        "\033[0m" << endl;
                }
            }
#line 1774 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 162 "parser.y" /* yacc.c:1646  */
    { cout << "term -> lvalue++" << endl; }
#line 1780 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 166 "parser.y" /* yacc.c:1646  */
    {
                cout << "term -> --lvalue" << endl;

                SymbolTableEntry *entry_ptr = Lookup(create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH), SCOPE);
                if(isFunction(*entry_ptr)){
                    cout << "\033[1;31m" << 
                        "Function used as lvalue (--function)  at line "<< yylineno <<
                        "\033[0m" << endl;
                }
            }
#line 1795 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 178 "parser.y" /* yacc.c:1646  */
    {
                SymbolTableEntry *entry_ptr = Lookup(create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH), SCOPE);
                if(isFunction(*entry_ptr)){
                    cout << "\033[1;31m" << 
                        "Function used as lvalue (function--)  at line "<< yylineno <<
                        "\033[0m" << endl;
                }
            }
#line 1808 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 186 "parser.y" /* yacc.c:1646  */
    { cout << "term -> lvalue--" << endl; }
#line 1814 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 187 "parser.y" /* yacc.c:1646  */
    { cout << "term -> !expr" << endl; }
#line 1820 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 191 "parser.y" /* yacc.c:1646  */
    { cout << "primary -> lvalue" << endl; }
#line 1826 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 192 "parser.y" /* yacc.c:1646  */
    { cout << "primary -> call" << endl; }
#line 1832 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 193 "parser.y" /* yacc.c:1646  */
    { cout << "primary -> objectdef" << endl; }
#line 1838 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 194 "parser.y" /* yacc.c:1646  */
    { cout << "primary -> (funcdef)" << endl; }
#line 1844 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 195 "parser.y" /* yacc.c:1646  */
    { cout << "primary -> const" << endl; }
#line 1850 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 199 "parser.y" /* yacc.c:1646  */
    {   
                cout << "lvalue -> id" << endl;

                GLOBAL_ID = (yyvsp[0].stringValue);

                SymbolTableEntry * entry_ptr = Lookup(create_entry((yyvsp[0].stringValue),0,0,LLOCAL, FUNC_DEPTH),SCOPE);
                SymbolTableEntry entry=create_entry((yyvsp[0].stringValue), SCOPE, yylineno, GLOBAL, FUNC_DEPTH);
                if(entry_ptr== NULL ){

                    if(SCOPE==0){
                        Insert(entry);  
                    }
                    else{
                        entry.type=LLOCAL;
                        Insert(entry);
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
                }
            }
#line 1883 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 228 "parser.y" /* yacc.c:1646  */
    {
                cout << "lvalue -> local id" << endl;

                GLOBAL_ID=(yyvsp[0].stringValue);
                SymbolTableEntry entry = create_entry((yyvsp[0].stringValue), SCOPE, yylineno, GLOBAL, FUNC_DEPTH);
                SymbolTableEntry *entry_ptr = Lookup_scope(entry, SCOPE);
                if(entry_ptr==NULL){
                    if(SCOPE==0){
                        Insert_local(entry);
                    }
                    else{
                        entry.type = LLOCAL;
                        Insert_local(entry);
                    }
                }else if(entry_ptr->type == LIBFUNC){
                    cout << "\033[1;31m" << 
                    "Collision with library function at line "<< yylineno <<
                    "\033[0m" << endl;
                }
                else {
                    if(isFunction(*entry_ptr)) lwarning = true;
                }
            }
#line 1911 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 252 "parser.y" /* yacc.c:1646  */
    {
                cout << "lvalue -> ::id" << endl;

                if(!Lookup_scope(create_entry((yyvsp[0].stringValue),0,0,LLOCAL, FUNC_DEPTH),0)){
                    cout << "\033[1;31m" << 
                    "Global id not found at line "<< yylineno <<
                    "\033[0m" << endl;
                }
            }
#line 1925 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 265 "parser.y" /* yacc.c:1646  */
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
#line 1944 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 279 "parser.y" /* yacc.c:1646  */
    { cout << "assignexpr -> lvalue = expr" << endl; }
#line 1950 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 280 "parser.y" /* yacc.c:1646  */
    {
                 cout << "\033[1;31m" << 
                            "Function used as lvalue at line "<< yylineno <<
                            "\033[0m" << endl;
             }
#line 1960 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 287 "parser.y" /* yacc.c:1646  */
    {lwarning = false;}
#line 1966 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 287 "parser.y" /* yacc.c:1646  */
    { cout << "member -> lvalue.id" << endl; }
#line 1972 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 288 "parser.y" /* yacc.c:1646  */
    { cout << "member -> lvalue[expr]" << endl; }
#line 1978 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 289 "parser.y" /* yacc.c:1646  */
    {lwarning = false;}
#line 1984 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 289 "parser.y" /* yacc.c:1646  */
    { cout << "member -> call.id" << endl; }
#line 1990 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 290 "parser.y" /* yacc.c:1646  */
    { cout << "member -> call[expr]" << endl; }
#line 1996 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 293 "parser.y" /* yacc.c:1646  */
    { cout << "call -> call (elist)" << endl; }
#line 2002 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 294 "parser.y" /* yacc.c:1646  */
    {
                SymbolTableEntry entry = create_entry(GLOBAL_ID,0,0,LLOCAL, FUNC_DEPTH);
                SymbolTableEntry *entry_ptr = Lookup(entry,SCOPE);
                if(!isFunction(*entry_ptr)){
                   /* cout << "\033[1;31m" << 
                            "Can't use variable as func at line "<< yylineno <<
                            "\033[0m" << endl;*/
                }

            }
#line 2017 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 303 "parser.y" /* yacc.c:1646  */
    { cout << "call -> lvalue callsuffix" << endl; }
#line 2023 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 304 "parser.y" /* yacc.c:1646  */
    { cout << "call -> (funcdef)(elist)" << endl; }
#line 2029 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 307 "parser.y" /* yacc.c:1646  */
    { cout << "callsuffix -> normcall" << endl; }
#line 2035 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 308 "parser.y" /* yacc.c:1646  */
    { cout << "callsuffix -> methodcall" << endl; }
#line 2041 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 311 "parser.y" /* yacc.c:1646  */
    { cout << "normcall -> (elist)" << endl; }
#line 2047 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 314 "parser.y" /* yacc.c:1646  */
    { cout << "methodcall -> ..id(elist)" << endl; }
#line 2053 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 317 "parser.y" /* yacc.c:1646  */
    { cout << "elist -> expr commaexpr" << endl; }
#line 2059 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 318 "parser.y" /* yacc.c:1646  */
    { cout << "elist -> " << endl; }
#line 2065 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 321 "parser.y" /* yacc.c:1646  */
    { cout << "commaexpr -> ,expr commaexpr" << endl; }
#line 2071 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 322 "parser.y" /* yacc.c:1646  */
    { cout << "commaexpr -> " << endl; }
#line 2077 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 325 "parser.y" /* yacc.c:1646  */
    { cout << "objectdef -> [elist]" << endl; }
#line 2083 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 326 "parser.y" /* yacc.c:1646  */
    { cout << "objectdef -> [indexed]" << endl; }
#line 2089 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 330 "parser.y" /* yacc.c:1646  */
    { cout << "indexed -> indexedelem commaindexedelem" << endl; }
#line 2095 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 333 "parser.y" /* yacc.c:1646  */
    { cout << "commaindexelem -> ,indexelem commaindexelem" << endl; }
#line 2101 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 334 "parser.y" /* yacc.c:1646  */
    { cout << "commaindexelem -> " << endl; }
#line 2107 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 337 "parser.y" /* yacc.c:1646  */
    { cout << "indexelem -> {expr:expr}" << endl; }
#line 2113 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 341 "parser.y" /* yacc.c:1646  */
    {
                        SCOPE++;
                    }
#line 2121 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 345 "parser.y" /* yacc.c:1646  */
    {
                        cout << "block -> {}" << endl;
                        Hide(SCOPE--);
                    }
#line 2130 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 350 "parser.y" /* yacc.c:1646  */
    {
                        SCOPE++;
                    }
#line 2138 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 355 "parser.y" /* yacc.c:1646  */
    {
                        cout << "block -> {stmt program}" << endl;
                        Hide(SCOPE--);
                    }
#line 2147 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 363 "parser.y" /* yacc.c:1646  */
    {
                        SymbolTableEntry entry = create_entry(generate_function_name(),SCOPE,yylineno,USERFUNC, FUNC_DEPTH);
                        Insert(entry);
                        FUNC_DEPTH++;
                    }
#line 2157 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 369 "parser.y" /* yacc.c:1646  */
    {
                        SCOPE++;
                    }
#line 2165 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 374 "parser.y" /* yacc.c:1646  */
    {
                        SCOPE--;
                    }
#line 2173 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 377 "parser.y" /* yacc.c:1646  */
    { cout << "funcdef -> function (idlist) block" << endl; }
#line 2179 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 378 "parser.y" /* yacc.c:1646  */
    {fflag = true;}
#line 2185 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 380 "parser.y" /* yacc.c:1646  */
    {   
                        if(FUNC_DEPTH==0)
                            active_func.clear();
                        SymbolTableEntry entry = create_entry((yyvsp[0].stringValue), SCOPE, yylineno, USERFUNC, FUNC_DEPTH);
                        SymbolTableEntry *entry_ptr_glb = Lookup(entry, SCOPE);
                        SymbolTableEntry *entry_ptr = Lookup_scope(entry,SCOPE);
                        active_func.push_back((yyvsp[0].stringValue));
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
                    }
#line 2222 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 413 "parser.y" /* yacc.c:1646  */
    {
                        SCOPE++;
                    }
#line 2230 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 418 "parser.y" /* yacc.c:1646  */
    {
                        SCOPE--;
                    }
#line 2238 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 422 "parser.y" /* yacc.c:1646  */
    {
                        cout << "funcdef -> function id(idlist) block" << endl;
                        FUNC_DEPTH--;
                    }
#line 2247 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 428 "parser.y" /* yacc.c:1646  */
    { cout << "const -> real" << endl; }
#line 2253 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 429 "parser.y" /* yacc.c:1646  */
    { cout << "const -> integer" << endl; }
#line 2259 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 430 "parser.y" /* yacc.c:1646  */
    { cout << "const -> string" << endl; }
#line 2265 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 431 "parser.y" /* yacc.c:1646  */
    { cout << "const -> nil" << endl; }
#line 2271 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 432 "parser.y" /* yacc.c:1646  */
    { cout << "const -> true" << endl; }
#line 2277 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 433 "parser.y" /* yacc.c:1646  */
    { cout << "const -> false" << endl; }
#line 2283 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 437 "parser.y" /* yacc.c:1646  */
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
#line 2307 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 456 "parser.y" /* yacc.c:1646  */
    { cout << "idlist -> id commaid" << endl; }
#line 2313 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 457 "parser.y" /* yacc.c:1646  */
    { cout << "idlist -> " << endl; }
#line 2319 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 462 "parser.y" /* yacc.c:1646  */
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
#line 2349 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 487 "parser.y" /* yacc.c:1646  */
    { cout << "commaid -> ,id commaid" << endl; }
#line 2355 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 488 "parser.y" /* yacc.c:1646  */
    { cout << "commaid -> " << endl; }
#line 2361 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 491 "parser.y" /* yacc.c:1646  */
    { cout << "ifstmt -> if(expr) stmt" << endl; }
#line 2367 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 492 "parser.y" /* yacc.c:1646  */
    { cout << "ifstmt -> if(expr) stmt else stmt" << endl; }
#line 2373 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 495 "parser.y" /* yacc.c:1646  */
    {loop_counter++;}
#line 2379 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 496 "parser.y" /* yacc.c:1646  */
    {
                        cout << "whilestmt -> while(expr) stmt" << endl;

                        loop_counter--;
                        if(loop_counter < 0) loop_counter=0;
                    }
#line 2390 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 504 "parser.y" /* yacc.c:1646  */
    {loop_counter++;}
#line 2396 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 505 "parser.y" /* yacc.c:1646  */
    {
                        cout << "forstmt -> for(elist; expr; elist) stmt" << endl;

                        loop_counter--;
                        if(loop_counter < 0) loop_counter=0;
                    }
#line 2407 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 513 "parser.y" /* yacc.c:1646  */
    {
                        if(FUNC_DEPTH==0){
                            cout << "\033[1;31m" << 
                                    "Return outside of function at line "<< yylineno <<
                                    "\033[0m" << endl;
                        }

                    }
#line 2420 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 520 "parser.y" /* yacc.c:1646  */
    { cout << "returnstmt -> return expr;" << endl; }
#line 2426 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 521 "parser.y" /* yacc.c:1646  */
    {
                        if(FUNC_DEPTH==0){
                            cout << "\033[1;31m" << 
                                    "Return outside of function at line "<< yylineno <<
                                    "\033[0m" << endl;
                        }
                    }
#line 2438 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 527 "parser.y" /* yacc.c:1646  */
    { cout << "returnstmt -> return;" << endl; }
#line 2444 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2448 "parser.cpp" /* yacc.c:1646  */
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
#line 532 "parser.y" /* yacc.c:1906  */


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

    return 0;
}
