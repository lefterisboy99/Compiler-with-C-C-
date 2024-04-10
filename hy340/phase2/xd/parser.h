/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 103 "parser.y" /* yacc.c:1909  */

	char* strVal;
	int intVal;
	double dbVal;

#line 170 "parser.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
