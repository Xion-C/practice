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
    IMAG = 268,
    AMPEREQUAL = 269,
    AMPERSAND = 270,
    AND = 271,
    AS = 272,
    ASSERT = 273,
    AT = 274,
    BACKQUOTE = 275,
    BAR = 276,
    BREAK = 277,
    CIRCUMFLEX = 278,
    CIRCUMFLEXEQUAL = 279,
    CLASS = 280,
    COLON = 281,
    COMMA = 282,
    CONTINUE = 283,
    DEDENT = 284,
    DEF = 285,
    DEL = 286,
    DOT = 287,
    DOUBLESLASHEQUAL = 288,
    DOUBLESTAREQUAL = 289,
    ELIF = 290,
    ELSE = 291,
    ENDMARKER = 292,
    EQEQUAL = 293,
    EQUAL = 294,
    EXCEPT = 295,
    EXEC = 296,
    FINALLY = 297,
    FOR = 298,
    FROM = 299,
    GLOBAL = 300,
    GREATER = 301,
    GREATEREQUAL = 302,
    GRLT = 303,
    IF = 304,
    IMPORT = 305,
    IN = 306,
    INDENT = 307,
    IS = 308,
    LAMBDA = 309,
    LBRACE = 310,
    LEFTSHIFT = 311,
    LEFTSHIFTEQUAL = 312,
    LESS = 313,
    LESSEQUAL = 314,
    LPAR = 315,
    LSQB = 316,
    MINEQUAL = 317,
    NEWLINE = 318,
    NOT = 319,
    NOTEQUAL = 320,
    OR = 321,
    PASS = 322,
    PERCENTEQUAL = 323,
    PLUSEQUAL = 324,
    PRINT = 325,
    RAISE = 326,
    RBRACE = 327,
    RETURN = 328,
    RIGHTSHIFT = 329,
    RIGHTSHIFTEQUAL = 330,
    RPAR = 331,
    RSQB = 332,
    SEMI = 333,
    SLASHEQUAL = 334,
    STAREQUAL = 335,
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
#line 16 "includes/parse.y" /* yacc.c:1909  */

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
