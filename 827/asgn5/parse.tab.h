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
    LESS = 276,
    GREATER = 277,
    EQEQUAL = 278,
    GREATEREQUAL = 279,
    LESSEQUAL = 280,
    NOTEQUAL = 281,
    IMAG = 282,
    AMPEREQUAL = 283,
    AMPERSAND = 284,
    AND = 285,
    AS = 286,
    ASSERT = 287,
    AT = 288,
    BACKQUOTE = 289,
    BAR = 290,
    BREAK = 291,
    CIRCUMFLEX = 292,
    CIRCUMFLEXEQUAL = 293,
    CLASS = 294,
    COLON = 295,
    COMMA = 296,
    CONTINUE = 297,
    DEDENT = 298,
    DEF = 299,
    DEL = 300,
    DOT = 301,
    ELIF = 302,
    ELSE = 303,
    ENDMARKER = 304,
    EXCEPT = 305,
    EXEC = 306,
    FINALLY = 307,
    FOR = 308,
    FROM = 309,
    GLOBAL = 310,
    GRLT = 311,
    IF = 312,
    IMPORT = 313,
    IN = 314,
    INDENT = 315,
    IS = 316,
    LAMBDA = 317,
    LBRACE = 318,
    LEFTSHIFT = 319,
    LEFTSHIFTEQUAL = 320,
    LPAR = 321,
    LSQB = 322,
    NEWLINE = 323,
    NOT = 324,
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
#line 19 "includes/parse.y" /* yacc.c:1909  */

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
