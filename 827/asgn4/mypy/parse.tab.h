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

#ifndef YY_YY_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSE_TAB_H_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    NAME = 260,
    PLUS = 261,
    MINUS = 262,
    STAR = 263,
    SLASH = 264,
    PERCENT = 265,
    DOUBLESLASH = 266,
    DOUBLESTAR = 267,
    EQUAL = 268,
    PLUSEQUAL = 269,
    MINEQUAL = 270,
    STAREQUAL = 271,
    SLASHEQUAL = 272,
    PERCENTEQUAL = 273,
    DOUBLESTAREQUAL = 274,
    DOUBLESLASHEQUAL = 275,
    IMAG = 276,
    AMPEREQUAL = 277,
    AMPERSAND = 278,
    AND = 279,
    AS = 280,
    ASSERT = 281,
    AT = 282,
    BACKQUOTE = 283,
    BAR = 284,
    BREAK = 285,
    CIRCUMFLEX = 286,
    CIRCUMFLEXEQUAL = 287,
    CLASS = 288,
    COLON = 289,
    COMMA = 290,
    CONTINUE = 291,
    DEDENT = 292,
    DEF = 293,
    DEL = 294,
    DOT = 295,
    ELIF = 296,
    ELSE = 297,
    ENDMARKER = 298,
    EQEQUAL = 299,
    EXCEPT = 300,
    EXEC = 301,
    FINALLY = 302,
    FOR = 303,
    FROM = 304,
    GLOBAL = 305,
    GREATER = 306,
    GREATEREQUAL = 307,
    GRLT = 308,
    IF = 309,
    IMPORT = 310,
    IN = 311,
    INDENT = 312,
    IS = 313,
    LAMBDA = 314,
    LBRACE = 315,
    LEFTSHIFT = 316,
    LEFTSHIFTEQUAL = 317,
    LESS = 318,
    LESSEQUAL = 319,
    LPAR = 320,
    LSQB = 321,
    NEWLINE = 322,
    NOT = 323,
    NOTEQUAL = 324,
    OR = 325,
    PASS = 326,
    PRINT = 327,
    RAISE = 328,
    RBRACE = 329,
    RETURN = 330,
    RIGHTSHIFT = 331,
    RIGHTSHIFTEQUAL = 332,
    RPAR = 333,
    RSQB = 334,
    SEMI = 335,
    STRING = 336,
    TILDE = 337,
    TRY = 338,
    VBAREQUAL = 339,
    WHILE = 340,
    WITH = 341,
    YIELD = 342
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 18 "includes/parse.y" /* yacc.c:1909  */

  Node* node;
  int intNumber;
  float fltNumber;
  char *identifier;
  int op;

#line 150 "parse.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSE_TAB_H_INCLUDED  */
