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
    STRING = 258,
    INTEGER = 259,
    REAL = 260,
    LOCAL = 261,
    NIL = 262,
    ID = 263,
    BLOCK_COMMENT = 264,
    LINE_COMMENT = 265,
    ESCAPE_CHARACTERS = 266,
    SPACE = 267,
    IF = 268,
    ELSE = 269,
    WHILE = 270,
    FOR = 271,
    FUNCTION = 272,
    RETURN = 273,
    BREAK = 274,
    CONTINUE = 275,
    AND = 276,
    NOT = 277,
    OR = 278,
    TRUE = 279,
    FALSE = 280,
    EQUAL = 281,
    MINUS = 282,
    EQUALEQUAL = 283,
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
    EOF = 307,
    UNDEFINED = 308,
    UMINUS = 309
  };
#endif
/* Tokens.  */
#define STRING 258
#define INTEGER 259
#define REAL 260
#define LOCAL 261
#define NIL 262
#define ID 263
#define BLOCK_COMMENT 264
#define LINE_COMMENT 265
#define ESCAPE_CHARACTERS 266
#define SPACE 267
#define IF 268
#define ELSE 269
#define WHILE 270
#define FOR 271
#define FUNCTION 272
#define RETURN 273
#define BREAK 274
#define CONTINUE 275
#define AND 276
#define NOT 277
#define OR 278
#define TRUE 279
#define FALSE 280
#define EQUAL 281
#define MINUS 282
#define EQUALEQUAL 283
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
#define EOF 307
#define UNDEFINED 308
#define UMINUS 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 17 "parser.y" /* yacc.c:1909  */

    int intValue;
    char* stringValue;
    double realValue;

#line 168 "parser.hpp" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
