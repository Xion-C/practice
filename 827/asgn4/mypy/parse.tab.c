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
#line 2 "includes/parse.y" /* yacc.c:339  */

    #include "includes/ast.h"
	#include <iostream>
	#include <map>
	#include <cmath>

	int yylex ();
	extern char *yytext;
	void yyerror (const char *);

	PoolOfNodes& pool = PoolOfNodes::getInstance(); //prevent memory leak

#line 79 "parse.tab.c" /* yacc.c:339  */

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
   by #include "parse.tab.h".  */
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
#line 16 "includes/parse.y" /* yacc.c:355  */

  Node* node;
  int intNumber;
  float fltNumber;
  char *identifier;
  int op;

#line 215 "parse.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 244 "parse.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   902

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  140
/* YYNRULES -- Number of rules.  */
#define YYNRULES  314
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  477

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   342

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    64,    67,    68,    71,    82,    85,    86,
      89,    90,    93,    94,    97,    98,   101,   104,   105,   108,
     109,   112,   113,   116,   117,   120,   121,   124,   125,   128,
     129,   132,   133,   136,   137,   140,   141,   144,   145,   148,
     153,   160,   161,   164,   165,   170,   171,   172,   173,   174,
     175,   176,   179,   189,   205,   210,   217,   222,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     243,   248,   255,   262,   265,   273,   276,   277,   280,   281,
     284,   287,   290,   291,   292,   293,   294,   297,   300,   303,
     304,   307,   310,   311,   314,   315,   318,   319,   322,   323,
     326,   329,   332,   333,   336,   337,   338,   341,   342,   345,
     346,   349,   350,   353,   354,   357,   358,   361,   362,   365,
     368,   369,   372,   373,   376,   377,   380,   381,   382,   383,
     384,   385,   386,   387,   390,   391,   394,   395,   398,   399,
     402,   403,   406,   407,   410,   411,   414,   415,   418,   419,
     422,   425,   426,   429,   430,   433,   434,   437,   438,   441,
     442,   445,   446,   449,   450,   453,   454,   457,   458,   461,
     462,   465,   466,   469,   470,   477,   478,   481,   482,   485,
     486,   489,   490,   493,   494,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   510,   515,   522,   523,
     526,   527,   530,   531,   534,   535,   538,   539,   554,   556,
     560,   565,   589,   591,   593,   595,   599,   612,   619,   620,
     621,   624,   634,   641,   642,   645,   651,   652,   653,   654,
     660,   665,   670,   673,   674,   677,   678,   681,   682,   685,
     686,   689,   690,   693,   694,   697,   698,   701,   702,   705,
     706,   707,   710,   711,   714,   715,   718,   719,   720,   723,
     724,   727,   728,   731,   732,   735,   736,   739,   740,   743,
     748,   755,   756,   759,   760,   763,   764,   767,   768,   771,
     772,   775,   776,   779,   782,   783,   786,   787,   790,   791,
     794,   795,   796,   799,   800,   803,   804,   807,   808,   811,
     812,   815,   816,   819,   820,   823,   824,   827,   828,   831,
     832,   835,   836,   839,   840
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "NAME", "PLUS", "MINUS",
  "STAR", "SLASH", "PERCENT", "DOUBLESLASH", "DOUBLESTAR", "IMAG",
  "AMPEREQUAL", "AMPERSAND", "AND", "AS", "ASSERT", "AT", "BACKQUOTE",
  "BAR", "BREAK", "CIRCUMFLEX", "CIRCUMFLEXEQUAL", "CLASS", "COLON",
  "COMMA", "CONTINUE", "DEDENT", "DEF", "DEL", "DOT", "DOUBLESLASHEQUAL",
  "DOUBLESTAREQUAL", "ELIF", "ELSE", "ENDMARKER", "EQEQUAL", "EQUAL",
  "EXCEPT", "EXEC", "FINALLY", "FOR", "FROM", "GLOBAL", "GREATER",
  "GREATEREQUAL", "GRLT", "IF", "IMPORT", "IN", "INDENT", "IS", "LAMBDA",
  "LBRACE", "LEFTSHIFT", "LEFTSHIFTEQUAL", "LESS", "LESSEQUAL", "LPAR",
  "LSQB", "MINEQUAL", "NEWLINE", "NOT", "NOTEQUAL", "OR", "PASS",
  "PERCENTEQUAL", "PLUSEQUAL", "PRINT", "RAISE", "RBRACE", "RETURN",
  "RIGHTSHIFT", "RIGHTSHIFTEQUAL", "RPAR", "RSQB", "SEMI", "SLASHEQUAL",
  "STAREQUAL", "STRING", "TILDE", "TRY", "VBAREQUAL", "WHILE", "WITH",
  "YIELD", "$accept", "start", "file_input", "pick_NEWLINE_stmt",
  "star_NEWLINE_stmt", "decorator", "opt_arglist", "decorators",
  "decorated", "funcdef", "parameters", "varargslist", "opt_EQUAL_test",
  "star_fpdef_COMMA", "opt_DOUBLESTAR_NAME", "pick_STAR_DOUBLESTAR",
  "opt_COMMA", "fpdef", "fplist", "star_fpdef_notest", "stmt",
  "simple_stmt", "star_SEMI_small_stmt", "small_stmt", "expr_stmt",
  "pick_yield_expr_testlist", "star_EQUAL", "augassign", "print_stmt",
  "star_COMMA_test", "opt_test", "plus_COMMA_test", "opt_test_2",
  "del_stmt", "pass_stmt", "flow_stmt", "break_stmt", "continue_stmt",
  "return_stmt", "yield_stmt", "raise_stmt", "opt_COMMA_test",
  "opt_test_3", "import_stmt", "import_name", "import_from",
  "pick_dotted_name", "pick_STAR_import", "import_as_name",
  "dotted_as_name", "import_as_names", "star_COMMA_import_as_name",
  "dotted_as_names", "dotted_name", "global_stmt", "star_COMMA_NAME",
  "exec_stmt", "assert_stmt", "compound_stmt", "if_stmt", "star_ELIF",
  "while_stmt", "for_stmt", "try_stmt", "plus_except", "opt_ELSE",
  "opt_FINALLY", "with_stmt", "star_COMMA_with_item", "with_item",
  "except_clause", "pick_AS_COMMA", "opt_AS_COMMA", "suite", "plus_stmt",
  "testlist_safe", "plus_COMMA_old_test", "old_test", "old_lambdef",
  "test", "opt_IF_ELSE", "or_test", "and_test", "not_test", "comparison",
  "comp_op", "expr", "xor_expr", "and_expr", "shift_expr",
  "pick_LEFTSHIFT_RIGHTSHIFT", "arith_expr", "pick_PLUS_MINUS", "term",
  "pick_multop", "factor", "pick_unop", "power", "star_trailer", "atom",
  "pick_yield_expr_testlist_comp", "opt_yield_test", "opt_listmaker",
  "opt_dictorsetmaker", "plus_STRING", "listmaker", "testlist_comp",
  "lambdef", "trailer", "subscriptlist", "star_COMMA_subscript",
  "subscript", "opt_test_only", "opt_sliceop", "sliceop", "exprlist",
  "star_COMMA_expr", "testlist", "dictorsetmaker", "star_test_COLON_test",
  "pick_for_test_test", "pick_for_test", "classdef", "opt_testlist",
  "arglist", "star_argument_COMMA", "star_COMMA_argument",
  "opt_DOUBLESTAR_test", "pick_argument", "argument", "opt_comp_for",
  "list_iter", "list_for", "list_if", "comp_iter", "comp_for", "comp_if",
  "testlist1", "yield_expr", "star_DOT", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342
};
# endif

#define YYPACT_NINF -331

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-331)))

#define YYTABLE_NINF -261

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -331,    61,  -331,   400,  -331,  -331,  -331,  -331,  -331,  -331,
     750,    74,   750,  -331,    95,  -331,   116,    42,  -331,    42,
      42,  -331,   122,   750,    74,    50,   750,   261,   750,  -331,
     820,  -331,   708,   750,   750,  -331,  -331,   131,   750,   750,
     750,  -331,  -331,    35,  -331,  -331,  -331,  -331,  -331,  -331,
    -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,
    -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,
    -331,  -331,    -7,   156,  -331,   807,   152,   151,   161,   -19,
     143,   132,  -331,    42,  -331,  -331,    96,  -331,   296,  -331,
    -331,   154,  -331,    21,  -331,    53,     7,   118,   152,  -331,
      23,   128,   133,    45,  -331,   158,  -331,   155,    24,   750,
     159,    22,   111,   121,  -331,   145,  -331,   114,  -331,  -331,
     163,   120,  -331,  -331,   750,  -331,  -331,   167,  -331,    65,
     169,  -331,   181,  -331,  -331,  -331,  -331,   -12,   172,   820,
     820,  -331,   820,  -331,  -331,  -331,  -331,  -331,   137,  -331,
    -331,   160,  -331,    42,    42,    42,    42,  -331,  -331,    42,
    -331,  -331,    42,  -331,  -331,  -331,  -331,    42,  -331,    31,
    -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,
    -331,  -331,  -331,   168,   261,   750,   197,   136,  -331,  -331,
     750,    65,   750,   138,   184,   189,   750,   750,    30,   170,
     185,   192,    65,    74,   219,  -331,   750,  -331,   220,   222,
      26,  -331,   190,   750,    42,   204,  -331,  -331,  -331,   204,
    -331,  -331,    42,   204,  -331,  -331,   205,   204,   750,  -331,
     182,  -331,   123,    65,   141,    42,  -331,   613,   750,    28,
     156,  -331,  -331,  -331,   152,   151,   161,   -19,   143,   132,
    -331,    42,   231,   136,   720,  -331,   261,  -331,  -331,  -331,
    -331,  -331,   165,  -331,   329,  -331,  -331,  -331,   166,  -331,
     171,    65,    42,   210,   213,   226,  -331,   240,  -331,  -331,
    -331,   241,  -331,  -331,  -331,  -331,   221,  -331,  -331,   173,
     750,   223,   145,   201,   750,  -331,  -331,   202,  -331,   750,
     229,  -331,  -331,   210,   542,   750,   233,   115,   234,   225,
      65,   750,   152,  -331,  -331,  -331,   750,  -331,  -331,   186,
     238,   237,   180,  -331,   245,  -331,   209,   750,   750,   117,
    -331,   246,   248,  -331,  -331,   152,   750,  -331,    65,   270,
     200,   250,  -331,   134,   271,  -331,   255,  -331,  -331,    13,
    -331,   258,  -331,  -331,   820,   813,  -331,   750,  -331,  -331,
    -331,   471,    71,    65,   260,   249,   262,    65,   264,  -331,
    -331,  -331,  -331,   265,  -331,   266,   750,  -331,  -331,  -331,
     750,  -331,  -331,   211,  -331,    65,  -331,   256,  -331,  -331,
     240,   750,   268,   291,    26,   750,  -331,     9,   272,    69,
     273,  -331,   242,  -331,  -331,  -331,  -331,  -331,   750,  -331,
    -331,    65,   278,  -331,    65,  -331,    65,  -331,   684,  -331,
     281,   284,  -331,  -331,   286,  -331,   287,    65,  -331,  -331,
     288,   813,  -331,  -331,  -331,   813,   293,   813,  -331,  -331,
    -331,   813,   297,  -331,  -331,    65,  -331,  -331,  -331,   750,
    -331,  -331,   788,  -331,    65,    65,  -331,   750,    73,  -331,
     813,    69,  -331,   813,  -331,  -331,  -331,   750,  -331,  -331,
    -331,  -331,  -331,  -331,  -331,  -331,  -331
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       7,     0,     2,     0,     1,   230,   231,   229,   218,   219,
       0,     0,     0,    87,     0,    88,     0,     0,     3,     0,
       0,   314,     0,     0,     0,    24,   240,   236,   238,     4,
       0,    81,    75,    93,    90,   242,   220,     0,     0,     0,
     312,     6,    13,     0,   133,   131,     5,    37,    42,    43,
      44,    45,    46,    47,    82,    83,    84,    86,    85,    48,
      98,    99,    49,    50,    51,    38,   126,   127,   128,   129,
     130,    73,   176,   177,   179,   182,   183,   196,   198,   200,
     202,   206,   210,     0,   217,   224,   232,   174,    57,   132,
      91,   125,   117,     0,   309,     0,     0,     0,   268,    80,
     123,     0,     0,     0,   121,     0,   115,   100,   110,     0,
       0,     0,    73,     0,   239,    73,   235,     0,   234,   233,
      73,     0,   237,   181,     0,    70,    73,    97,    89,     0,
       0,   152,   154,   311,    12,    15,    14,     0,   270,     0,
       0,   173,     0,   187,   186,   188,   190,   192,   194,   185,
     189,     0,   191,     0,     0,     0,     0,   204,   205,     0,
     208,   209,     0,   212,   213,   214,   215,     0,   216,   222,
     241,    63,    65,    69,    68,    66,    59,    62,    58,    67,
      61,    60,    64,    53,     0,     0,     0,   285,     9,   228,
       0,     0,   282,    24,     0,   266,     0,     0,     0,   313,
     102,   119,     0,     0,     0,   248,     0,    31,     0,     0,
       0,    19,    22,     0,     0,    30,   272,   277,   227,    30,
     245,   225,     0,    30,   243,   226,    79,    30,     0,    92,
       0,   161,     0,     0,     0,     0,    40,     0,   269,     0,
     178,   180,   195,   193,   184,   197,   199,   201,   203,   207,
     211,     0,     0,   285,   260,   223,     0,    52,    55,    54,
     124,   118,     0,    10,     0,   310,   280,   281,     0,    18,
       0,     0,   265,    95,     0,   108,   104,     0,   101,   114,
     106,     0,   137,   116,   109,   247,    26,    28,    36,     0,
       0,    30,   274,     0,    29,   278,   246,     0,   244,     0,
      30,    71,    74,    95,     0,   156,     0,   147,     0,   139,
       0,     0,   153,    39,    41,    72,     0,   221,   251,     0,
       0,   257,     0,   255,     0,    56,     0,     0,     0,   296,
     283,    30,     0,    17,    16,   267,     0,   122,     0,     0,
       0,   112,   120,   135,     0,    27,    34,    32,    21,    23,
      20,    30,   271,   275,     0,     0,    77,    29,    78,    96,
     164,     0,   160,     0,     0,   149,     0,     0,     0,   150,
     151,   175,   249,     0,   250,   253,   260,     8,   287,   292,
       0,   293,   295,   284,   290,     0,    94,   141,   107,   105,
     111,     0,     0,     0,    33,    29,   276,   306,    24,   300,
     166,   170,   169,    76,   162,   163,   157,   158,     0,   155,
     143,     0,     0,   142,     0,   145,     0,   256,   252,   259,
     262,   289,   294,   279,     0,   113,     0,     0,    25,    35,
       0,     0,   305,   303,   304,     0,     0,     0,   299,   297,
     298,     0,    30,   159,   146,     0,   144,   138,   254,   264,
     258,   261,     0,   291,     0,     0,   134,     0,   308,   172,
       0,   302,   168,    29,   165,   148,   263,     0,   286,   140,
     136,   273,   307,   171,   301,   167,   288
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -331,  -331,  -331,  -331,  -331,   280,    85,  -331,  -331,   301,
    -331,  -183,  -331,  -331,  -331,  -331,  -187,  -190,  -331,  -331,
    -283,    -2,  -331,    90,  -331,    83,  -331,  -331,  -331,    33,
    -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,
    -331,    37,  -331,  -331,  -331,  -331,  -331,  -331,   -45,   147,
      75,  -331,  -331,    14,  -331,  -331,  -331,  -331,  -331,  -331,
    -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,    40,
      39,  -331,  -331,  -176,  -331,  -331,  -331,  -330,  -331,   -10,
    -331,  -132,   214,   -11,  -331,  -331,   -14,   203,   206,   199,
    -331,   208,  -331,   194,  -331,   -59,  -331,  -331,  -331,  -331,
    -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,  -331,
    -331,   -58,   -13,  -331,  -331,    -9,  -331,   -26,  -331,  -331,
    -331,  -331,   319,  -331,  -331,  -331,  -331,  -331,  -331,   -84,
    -331,   -92,   252,  -331,   -85,  -103,  -331,  -331,   -23,  -331
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    41,     3,    42,   262,    43,    44,    45,
     194,   110,   291,   111,   345,   211,   295,   212,   289,   346,
      46,   231,   137,    48,    49,   257,   183,   184,    50,   138,
     125,   300,   301,    51,    52,    53,    54,    55,    56,    57,
      58,   337,   229,    59,    60,    61,   102,   278,   279,   106,
     280,   341,   107,   108,    62,   201,    63,    64,    65,    66,
     343,    67,    68,    69,   307,   365,   413,    70,   234,   131,
     308,   408,   409,   232,   361,   399,   442,   400,   401,    71,
     141,    72,    73,    74,    75,   153,    76,    77,    78,    79,
     159,    80,   162,    81,   167,    82,    83,    84,   169,    85,
     116,   117,   121,   113,    86,   122,   118,    87,   255,   322,
     375,   323,   324,   450,   451,    99,   195,    88,   114,   351,
     352,   216,    89,   268,   263,   264,   421,   453,   330,   331,
     381,   438,   439,   440,   432,   433,   434,    95,    90,   103
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,    47,    94,    98,   119,   100,    98,   239,   128,   217,
     270,   101,   220,   105,   133,   266,   112,   115,   120,   123,
     288,   360,   126,   127,   168,    93,   282,   207,   130,   132,
     208,   207,   296,   191,   209,   275,   298,   157,   276,   -29,
     302,   204,   139,   251,   154,     5,     6,     7,     8,     9,
      92,   236,   214,   186,    11,   158,   186,   309,   431,   140,
      14,     4,    12,   252,   316,    16,   237,   192,     5,     6,
       7,     8,     9,   189,   196,   140,   109,   199,   405,    92,
     190,   187,   210,    10,   188,    12,   210,    13,   406,   -29,
     277,   253,   254,    15,   140,   334,    17,    26,   407,   205,
      96,   458,    27,    28,   350,   459,    19,   461,   250,    21,
      22,   462,   222,   358,   226,    24,   214,   200,   437,    25,
      26,    97,   431,    35,    36,    27,    28,   104,   230,    30,
     473,   241,    31,   475,   369,    32,    33,   213,    34,   244,
     163,   164,   165,   166,   384,   215,    35,    36,   219,   160,
     161,   364,    40,   223,   214,   305,   380,   129,   258,   227,
     214,   259,   387,   305,   396,   306,   267,   310,   311,   391,
     392,   274,   142,   154,   155,   260,   156,   170,   193,   197,
     265,   185,   203,   198,   202,   206,   273,   410,   214,   353,
     221,   415,   317,   218,   228,   233,   285,   225,   235,   238,
      98,   242,   261,   292,   429,   293,   222,   256,    98,   423,
     271,   243,   -11,   297,   269,   436,   272,   186,   303,   281,
    -103,   312,   397,   402,   284,   286,   382,   287,   315,   290,
     258,   294,   299,   259,   304,   444,   318,   336,   446,   338,
     447,   326,   332,   339,   321,   275,   342,   333,   344,   347,
     349,   456,   354,   355,   329,   464,   357,   374,   335,   363,
     367,   368,   372,  -259,     5,     6,     7,     8,     9,   465,
     373,   376,   377,   383,   385,   388,   389,   390,   469,   470,
     348,    12,   394,   393,   315,   395,   411,   -29,   414,   356,
     416,   412,   424,   418,   427,   362,   428,   417,   435,   402,
     441,   132,    47,   402,   445,   402,   371,   449,   140,   402,
     171,   452,   454,   455,   457,    25,    26,   378,   379,   460,
     172,    27,    28,   134,   463,    30,   386,   314,   402,   173,
     174,   402,     5,     6,     7,     8,     9,   327,   319,   325,
     359,   328,    35,    36,   135,   425,   366,   403,    40,    12,
     283,   370,   340,   175,   240,   247,   249,   245,   176,    47,
     448,   246,   136,   420,   177,   178,   419,   248,   468,   474,
     422,   179,   224,   472,     0,   180,   181,     0,     0,     0,
     182,   426,     0,    25,    26,   430,     0,     0,     0,    27,
      28,     0,     0,    30,     0,     0,     0,     0,   443,     0,
       0,     0,     0,     5,     6,     7,     8,     9,   321,     0,
      35,    36,     0,     0,     0,     0,     0,     0,    10,    11,
      12,     0,    13,     0,     0,    14,     0,     0,    15,     0,
      16,    17,     0,     0,     0,     0,     0,    18,     0,   466,
       0,    19,   329,    20,    21,    22,     0,   471,     0,    23,
      24,     0,     0,     0,    25,    26,     0,   476,     0,     0,
      27,    28,     0,    29,    30,     0,     0,    31,     0,     0,
      32,    33,     0,    34,     5,     6,     7,     8,     9,     0,
       0,    35,    36,    37,     0,    38,    39,    40,     0,    10,
      11,    12,     0,    13,     0,     0,    14,     0,     0,    15,
     404,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,    20,    21,    22,     0,     0,     0,
      23,    24,     0,     0,     0,    25,    26,     0,     0,     0,
       0,    27,    28,     0,     0,    30,     0,     0,    31,     0,
       0,    32,    33,     0,    34,     5,     6,     7,     8,     9,
       0,     0,    35,    36,    37,     0,    38,    39,    40,     0,
      10,    11,    12,     0,    13,     0,     0,    14,     0,     0,
      15,     0,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,    20,    21,    22,     0,     0,
       0,    23,    24,     0,     0,     0,    25,    26,     0,     0,
       0,     0,    27,    28,     0,     0,    30,     0,     0,    31,
       0,     0,    32,    33,     0,    34,     5,     6,     7,     8,
       9,     0,     0,    35,    36,    37,     0,    38,    39,    40,
       0,    10,     0,    12,     0,    13,     0,     0,     0,     0,
       0,    15,     0,     0,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     0,     0,    21,    22,     0,
       0,     0,     0,    24,     0,     0,     0,    25,    26,     0,
       0,     0,     0,    27,    28,     0,   313,    30,     0,     0,
      31,     0,     0,    32,    33,     0,    34,     5,     6,     7,
       8,     9,     0,     0,    35,    36,     0,     0,     0,     0,
      40,     0,     0,     0,    12,     0,     0,     0,     0,     0,
    -260,     5,     6,     7,     8,     9,   320,     0,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
      12,     0,     0,     0,    27,    28,     0,     0,    30,     0,
       0,     0,   320,     5,     6,     7,     8,     9,     0,     0,
       0,     0,    25,    26,     0,    35,    36,     0,    27,    28,
      12,     0,    30,     0,    25,    26,     0,     0,     0,     0,
      27,    28,   124,     0,    30,     0,     0,     0,     0,    35,
      36,     5,     6,     7,     8,     9,     0,     0,     0,     0,
     467,    35,    36,     0,    25,    26,     0,     0,    12,     0,
      27,    28,     0,     0,    30,     0,     5,     6,     7,     8,
       9,     0,     0,     5,     6,     7,     8,     9,     0,     0,
       0,    35,    36,    12,     0,     0,     0,     0,     0,     0,
      12,     0,    25,    26,     0,   143,     0,     0,    27,    28,
       0,     0,    30,   144,   145,   146,     0,     0,   147,     0,
     148,     0,     0,     0,     0,   149,   150,   398,    26,    35,
      36,   151,   152,    27,    28,    26,     0,    30,     0,     0,
      27,    28,     0,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    35,    36,     0,     0,     0,     0,
       0,    35,    36
};

static const yytype_int16 yycheck[] =
{
      10,     3,    12,    17,    27,    19,    20,   139,    34,   112,
     193,    20,   115,    23,    40,   191,    26,    27,    28,    30,
     210,   304,    32,    33,    83,    11,   202,     5,    38,    39,
       8,     5,   219,    26,    12,     5,   223,    56,     8,    26,
     227,    17,    49,    12,    21,     3,     4,     5,     6,     7,
       5,    63,    43,    32,    19,    74,    32,   233,    49,    66,
      25,     0,    20,    32,    36,    30,    78,    60,     3,     4,
       5,     6,     7,    20,    51,    66,    26,    32,   361,     5,
      27,    60,    60,    18,    63,    20,    60,    22,    17,    76,
      60,    60,    61,    28,    66,   271,    31,    55,    27,   109,
       5,   431,    60,    61,   291,   435,    41,   437,   167,    44,
      45,   441,    43,   300,   124,    50,    43,   103,    49,    54,
      55,     5,    49,    81,    82,    60,    61,     5,    63,    64,
     460,   142,    67,   463,   310,    70,    71,    26,    73,   153,
       8,     9,    10,    11,   331,   112,    81,    82,   115,     6,
       7,    36,    87,   120,    43,    40,    39,    26,   184,   126,
      43,   184,   338,    40,   351,    42,   192,    26,    27,    35,
      36,   197,    16,    21,    23,   185,    15,    81,    60,    51,
     190,    27,    27,    50,    26,    26,   196,   363,    43,   292,
      76,   367,   251,    72,    27,    26,   206,    77,    17,    27,
     214,    64,     5,   213,   394,   214,    43,    39,   222,   385,
      26,    51,    76,   222,    76,   398,    27,    32,   228,    27,
      50,   235,   354,   355,     5,     5,   329,     5,   238,    39,
     256,    27,    27,   256,    52,   411,     5,    27,   414,    26,
     416,    76,    76,    17,   254,     5,     5,    76,    27,    76,
      27,   427,    51,    51,   264,   442,    27,    77,   272,    26,
      26,    36,    76,    26,     3,     4,     5,     6,     7,   445,
      32,    26,    63,    27,    26,     5,    76,    27,   454,   455,
     290,    20,    27,    12,   294,    27,    26,    76,    26,   299,
      26,    42,    36,    27,    26,   305,     5,    32,    26,   431,
      27,   311,   304,   435,    26,   437,   316,    26,    66,   441,
      14,    27,    26,    26,    26,    54,    55,   327,   328,    26,
      24,    60,    61,    43,    27,    64,   336,   237,   460,    33,
      34,   463,     3,     4,     5,     6,     7,     8,   253,   256,
     303,    12,    81,    82,    43,   390,   307,   357,    87,    20,
     203,   311,   277,    57,   140,   156,   162,   154,    62,   361,
     418,   155,    43,   376,    68,    69,   376,   159,   452,   461,
     380,    75,   120,   458,    -1,    79,    80,    -1,    -1,    -1,
      84,   391,    -1,    54,    55,   395,    -1,    -1,    -1,    60,
      61,    -1,    -1,    64,    -1,    -1,    -1,    -1,   408,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,   418,    -1,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    37,    -1,   449,
      -1,    41,   452,    43,    44,    45,    -1,   457,    -1,    49,
      50,    -1,    -1,    -1,    54,    55,    -1,   467,    -1,    -1,
      60,    61,    -1,    63,    64,    -1,    -1,    67,    -1,    -1,
      70,    71,    -1,    73,     3,     4,     5,     6,     7,    -1,
      -1,    81,    82,    83,    -1,    85,    86,    87,    -1,    18,
      19,    20,    -1,    22,    -1,    -1,    25,    -1,    -1,    28,
      29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    43,    44,    45,    -1,    -1,    -1,
      49,    50,    -1,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    60,    61,    -1,    -1,    64,    -1,    -1,    67,    -1,
      -1,    70,    71,    -1,    73,     3,     4,     5,     6,     7,
      -1,    -1,    81,    82,    83,    -1,    85,    86,    87,    -1,
      18,    19,    20,    -1,    22,    -1,    -1,    25,    -1,    -1,
      28,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    -1,    43,    44,    45,    -1,    -1,
      -1,    49,    50,    -1,    -1,    -1,    54,    55,    -1,    -1,
      -1,    -1,    60,    61,    -1,    -1,    64,    -1,    -1,    67,
      -1,    -1,    70,    71,    -1,    73,     3,     4,     5,     6,
       7,    -1,    -1,    81,    82,    83,    -1,    85,    86,    87,
      -1,    18,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    -1,    44,    45,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    60,    61,    -1,    63,    64,    -1,    -1,
      67,    -1,    -1,    70,    71,    -1,    73,     3,     4,     5,
       6,     7,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,
      87,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      26,     3,     4,     5,     6,     7,    32,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
      20,    -1,    -1,    -1,    60,    61,    -1,    -1,    64,    -1,
      -1,    -1,    32,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    54,    55,    -1,    81,    82,    -1,    60,    61,
      20,    -1,    64,    -1,    54,    55,    -1,    -1,    -1,    -1,
      60,    61,    74,    -1,    64,    -1,    -1,    -1,    -1,    81,
      82,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    81,    82,    -1,    54,    55,    -1,    -1,    20,    -1,
      60,    61,    -1,    -1,    64,    -1,     3,     4,     5,     6,
       7,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    81,    82,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    -1,    54,    55,    -1,    38,    -1,    -1,    60,    61,
      -1,    -1,    64,    46,    47,    48,    -1,    -1,    51,    -1,
      53,    -1,    -1,    -1,    -1,    58,    59,    54,    55,    81,
      82,    64,    65,    60,    61,    55,    -1,    64,    -1,    -1,
      60,    61,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,
      -1,    81,    82
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    89,    90,    92,     0,     3,     4,     5,     6,     7,
      18,    19,    20,    22,    25,    28,    30,    31,    37,    41,
      43,    44,    45,    49,    50,    54,    55,    60,    61,    63,
      64,    67,    70,    71,    73,    81,    82,    83,    85,    86,
      87,    91,    93,    95,    96,    97,   108,   109,   111,   112,
     116,   121,   122,   123,   124,   125,   126,   127,   128,   131,
     132,   133,   142,   144,   145,   146,   147,   149,   150,   151,
     155,   167,   169,   170,   171,   172,   174,   175,   176,   177,
     179,   181,   183,   184,   185,   187,   192,   195,   205,   210,
     226,   167,     5,   141,   167,   225,     5,     5,   174,   203,
     174,   203,   134,   227,     5,   167,   137,   140,   141,    26,
      99,   101,   167,   191,   206,   167,   188,   189,   194,   226,
     167,   190,   193,   171,    74,   118,   167,   167,   205,    26,
     167,   157,   167,   205,    93,    97,   210,   110,   117,    49,
      66,   168,    16,    38,    46,    47,    48,    51,    53,    58,
      59,    64,    65,   173,    21,    23,    15,    56,    74,   178,
       6,     7,   180,     8,     9,    10,    11,   182,   183,   186,
      81,    14,    24,    33,    34,    57,    62,    68,    69,    75,
      79,    80,    84,   114,   115,    27,    32,    60,    63,    20,
      27,    26,    60,    60,    98,   204,    51,    51,    50,    32,
     141,   143,    26,    27,    17,   167,    26,     5,     8,    12,
      60,   103,   105,    26,    43,   117,   209,   223,    72,   117,
     223,    76,    43,   117,   220,    77,   167,   117,    27,   130,
      63,   109,   161,    26,   156,    17,    63,    78,    27,   169,
     170,   171,    64,    51,   174,   175,   176,   177,   179,   181,
     183,    12,    32,    60,    61,   196,    39,   113,   205,   226,
     167,     5,    94,   212,   213,   167,   161,   205,   211,    76,
      99,    26,    27,   167,   205,     5,     8,    60,   135,   136,
     138,    27,   161,   137,     5,   167,     5,     5,   105,   106,
      39,   100,   167,   203,    27,   104,   104,   203,   104,    27,
     119,   120,   104,   167,    52,    40,    42,   152,   158,   161,
      26,    27,   174,    63,   111,   167,    36,   183,     5,    94,
      32,   167,   197,   199,   200,   113,    76,     8,    12,   167,
     216,   217,    76,    76,   161,   174,    27,   129,    26,    17,
     138,   139,     5,   148,    27,   102,   107,    76,   167,    27,
     104,   207,   208,   223,    51,    51,   167,    27,   104,   129,
     108,   162,   167,    26,    36,   153,   158,    26,    36,   161,
     157,   167,    76,    32,    77,   198,    26,    63,   167,   167,
      39,   218,   223,    27,   104,    26,   167,   161,     5,    76,
      27,    35,    36,    12,    27,    27,   104,   169,    54,   163,
     165,   166,   169,   167,    29,   108,    17,    27,   159,   160,
     161,    26,    42,   154,    26,   161,    26,    32,    27,   167,
     200,   214,   167,   161,    36,   136,   167,    26,     5,   105,
     167,    49,   222,   223,   224,    26,    99,    49,   219,   220,
     221,    27,   164,   167,   161,    26,   161,   161,   199,    26,
     201,   202,    27,   215,    26,    26,   161,    26,   165,   165,
      26,   165,   165,    27,   104,   161,   167,    12,   217,   161,
     161,   167,   222,   165,   219,   165,   167
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    90,    91,    91,    92,    92,    93,    93,
      94,    94,    95,    95,    96,    96,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   107,   108,   108,   109,
     109,   110,   110,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   112,   112,   113,   113,   114,   114,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     116,   116,   117,   117,   118,   118,   119,   119,   120,   120,
     121,   122,   123,   123,   123,   123,   123,   124,   125,   126,
     126,   127,   128,   128,   129,   129,   130,   130,   131,   131,
     132,   133,   134,   134,   135,   135,   135,   136,   136,   137,
     137,   138,   138,   139,   139,   140,   140,   141,   141,   142,
     143,   143,   144,   144,   145,   145,   146,   146,   146,   146,
     146,   146,   146,   146,   147,   147,   148,   148,   149,   149,
     150,   150,   151,   151,   152,   152,   153,   153,   154,   154,
     155,   156,   156,   157,   157,   158,   158,   159,   159,   160,
     160,   161,   161,   162,   162,   163,   163,   164,   164,   165,
     165,   166,   166,   167,   167,   168,   168,   169,   169,   170,
     170,   171,   171,   172,   172,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   174,   174,   175,   175,
     176,   176,   177,   177,   178,   178,   179,   179,   180,   180,
     181,   181,   182,   182,   182,   182,   183,   183,   184,   184,
     184,   185,   185,   186,   186,   187,   187,   187,   187,   187,
     187,   187,   187,   188,   188,   189,   189,   190,   190,   191,
     191,   192,   192,   193,   193,   194,   194,   195,   195,   196,
     196,   196,   197,   197,   198,   198,   199,   199,   199,   200,
     200,   201,   201,   202,   202,   203,   203,   204,   204,   205,
     205,   206,   206,   207,   207,   208,   208,   209,   209,   210,
     210,   211,   211,   212,   213,   213,   214,   214,   215,   215,
     216,   216,   216,   217,   217,   218,   218,   219,   219,   220,
     220,   221,   221,   222,   222,   223,   223,   224,   224,   225,
     225,   226,   226,   227,   227
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     0,     6,     3,
       1,     0,     2,     1,     2,     2,     5,     3,     2,     2,
       4,     2,     0,     4,     0,     3,     0,     3,     2,     1,
       0,     1,     3,     3,     2,     3,     0,     1,     1,     4,
       3,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     1,     3,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     3,     0,     3,     0,     3,     2,     2,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     3,     1,     2,     0,     3,     0,     1,     1,
       2,     4,     2,     2,     1,     3,     1,     3,     1,     3,
       1,     3,     2,     3,     0,     1,     3,     1,     3,     3,
       3,     0,     5,     2,     4,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     8,     5,     5,     0,     7,     4,
       9,     6,     6,     6,     4,     3,     3,     0,     3,     0,
       5,     3,     0,     3,     1,     3,     1,     1,     1,     2,
       0,     1,     4,     2,     1,     3,     1,     3,     2,     1,
       1,     4,     3,     2,     1,     4,     0,     1,     3,     1,
       3,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     4,     2,     2,     0,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     0,     1,
       0,     2,     1,     2,     3,     2,     3,     4,     3,     3,
       3,     2,     3,     2,     3,     0,     3,     1,     4,     1,
       0,     1,     0,     2,     1,     3,     2,     3,     0,     3,
       2,     4,     2,     5,     0,     1,     2,     1,     2,     7,
       4,     1,     0,     2,     3,     0,     3,     0,     3,     0,
       2,     4,     2,     2,     3,     1,     0,     1,     1,     5,
       4,     3,     2,     1,     1,     5,     4,     3,     2,     1,
       3,     2,     1,     2,     0
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 57 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
        // std::cout << "at beginning" << std::endl;
        // if ($1) { ($1)->eval()->print(); }
    }
#line 1909 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 64 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1915 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 67 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1921 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 68 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1927 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 72 "includes/parse.y" /* yacc.c:1646  */
    {
        // if ($1) {
        //     $$ = $1;
        // }
        // else {
        //     $$ = $2;
        // }
        // if ($1) { delete [] $1; }
        (yyval.node) = (yyvsp[0].node);
    }
#line 1942 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 82 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1948 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 101 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-3].identifier); }
#line 1954 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 120 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 1960 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 124 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-1].identifier); }
#line 1966 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 125 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 1972 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 132 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 1978 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 144 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1984 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 145 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 1990 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 149 "includes/parse.y" /* yacc.c:1646  */
    {
        // std::cout << "simple_stmt1" << std::endl;
        (yyval.node) = (yyvsp[-3].node);
    }
#line 1999 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 154 "includes/parse.y" /* yacc.c:1646  */
    {
        // std::cout << "simple_stmt2" << std::endl;
        (yyval.node) = (yyvsp[-2].node);
    }
#line 2008 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 164 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2014 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 166 "includes/parse.y" /* yacc.c:1646  */
    {
        //just print, no need to pass the node
        (yyval.node) = NULL;
    }
#line 2023 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 170 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2029 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 171 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2035 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 172 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2041 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 173 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2047 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 174 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2053 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 175 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2059 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 176 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2065 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 180 "includes/parse.y" /* yacc.c:1646  */
    {
        //Node* lhs = new IdentNode($1);
        //($1)->print();
        (yyval.node) = new AsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
        // pool.add($1);
        pool.add((yyval.node));
        //delete [] $1;
        //std::cout << "expr_stmt1" << std::endl;
    }
#line 2079 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 190 "includes/parse.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].node)) {
            // std::cout << "expr_stmt2" << std::endl;
            (yyval.node) = new AsgBinaryNode((yyvsp[-1].node), (yyvsp[0].node));
            //pool.add($1);
            pool.add((yyval.node));
            //delete [] $1;
        }
        else {
            (yyval.node) = (yyvsp[-1].node);
            ((yyvsp[-1].node))->eval()->print();
        }
    }
#line 2097 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 206 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
        // std::cout << "pick_yield_expr_testlist1" << std::endl;
    }
#line 2106 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 211 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
        // std::cout << "pick_yield_expr_testlist2" << std::endl;
    }
#line 2115 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 218 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
        // std::cout << "star_EQUAL1" << std::endl;
    }
#line 2124 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 223 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = NULL;
        // std::cout << "star_EQUAL2" << std::endl;
    }
#line 2133 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 244 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
        // std::cout << "print_stmt1" << std::endl;
    }
#line 2142 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 249 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = NULL;
        // std::cout << "print_stmt2" << std::endl;
    }
#line 2151 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 256 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-2].node); //should always be NULL
        if ((yyvsp[0].node)) {
            ((yyvsp[0].node))->eval()->print();
        }
    }
#line 2162 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 262 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2168 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 266 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-2].node);
        if ((yyvsp[-2].node)) {
            ((yyvsp[-2].node))->eval()->print();
        }
        // std::cout << "opt_test1" << std::endl;
    }
#line 2180 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 273 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2186 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 341 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-2].identifier); delete [] (yyvsp[0].identifier); }
#line 2192 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 342 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2198 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 345 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2204 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 361 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2210 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 362 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2216 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 365 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-1].identifier); }
#line 2222 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 368 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2228 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 469 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2234 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 471 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = NULL;
        std::cout << "impossible lambdef" << std::endl;
    }
#line 2243 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 481 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2249 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 482 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2255 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 485 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2261 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 486 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2267 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 489 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2273 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 490 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2279 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 493 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2285 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 494 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2291 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 511 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
        //std::cout << "expr1" << std::endl;
    }
#line 2300 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 516 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-2].node);
        //std::cout << "expr2" << std::endl;
    }
#line 2309 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 522 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2315 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 523 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2321 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 526 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2327 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 527 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2333 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 530 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2339 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 531 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2345 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 538 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2351 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 540 "includes/parse.y" /* yacc.c:1646  */
    {
        switch ((yyvsp[-1].op)) {
        case OP_PLUS:
            (yyval.node) = new AddBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
            pool.add((yyval.node));
        break;
        case OP_MINUS:
            (yyval.node) = new SubBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
            pool.add((yyval.node));
        break;
        }
    }
#line 2368 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 555 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2374 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 557 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2380 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 561 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
        //std::cout << "term1" << std::endl;
    }
#line 2389 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 566 "includes/parse.y" /* yacc.c:1646  */
    {
        switch ((yyvsp[-1].op)) {
        case OP_STAR:
            (yyval.node) = new MulBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
            pool.add((yyval.node));
            break;
        case OP_SLASH:
            (yyval.node) = new DivBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
            pool.add((yyval.node));
            break;
        case OP_PERCENT:
            (yyval.node) = new ModBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
            pool.add((yyval.node));
            break;
        case OP_DOUBLESLASH:
            (yyval.node) = new FlrDivBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
            pool.add((yyval.node));
            break;
        }
        //std::cout << "term2" << std::endl;
    }
#line 2415 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 590 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2421 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 592 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2427 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 594 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2433 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 596 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2439 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 600 "includes/parse.y" /* yacc.c:1646  */
    {
        switch ((yyvsp[-1].op)) {
        case OP_PLUS:
            (yyval.node) = new PositiveUnaryNode((yyvsp[0].node));
            pool.add((yyval.node));
            break;
        case OP_MINUS:
            (yyval.node) = new NegativeUnaryNode((yyvsp[0].node));
            pool.add((yyval.node));
            break;
        }
    }
#line 2456 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 613 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
        //std::cout << "factor2" << std::endl;
    }
#line 2465 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 619 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2471 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 620 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2477 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 621 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2483 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 625 "includes/parse.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-1].op) == OP_DOUBLESTAR) {
            (yyval.node) = new ExpBinaryNode((yyvsp[-3].node), (yyvsp[0].node));
            pool.add((yyval.node));
        }
        else {
            std::cout << "DOUBLESTAR wrong" << std::endl;
        }
    }
#line 2497 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 635 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-1].node);
        //std::cout << "power2" << std::endl;
    }
#line 2506 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 646 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-1].node);
        // std::cout << "atom1" << std::endl;
        if (!(yyvsp[-1].node)) { std::cout << "empty parens" << std::endl; }
    }
#line 2516 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 651 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible atom2" << std::endl; }
#line 2522 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 652 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible atom3" << std::endl; }
#line 2528 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 653 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible atom4" << std::endl; }
#line 2534 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 655 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = new IdentNode((yyvsp[0].identifier));
        delete [] (yyvsp[0].identifier);
        pool.add((yyval.node));
    }
#line 2544 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 661 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = new IntLiteral((yyvsp[0].intNumber));
        pool.add((yyval.node));
    }
#line 2553 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 666 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = new FloatLiteral((yyvsp[0].fltNumber));
        pool.add((yyval.node));
    }
#line 2562 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 670 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible atom8" << std::endl; }
#line 2568 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 673 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2574 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 674 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2580 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 677 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2586 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 678 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2592 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 697 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2598 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 698 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2604 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 707 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2610 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 744 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-2].node);
        //std::cout << "testlist1" << std::endl;
    }
#line 2619 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 749 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-1].node);
        //std::cout << "testlist2" << std::endl;
    }
#line 2628 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 771 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-5].identifier); }
#line 2634 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 772 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-2].identifier); }
#line 2640 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 835 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2646 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 836 "includes/parse.y" /* yacc.c:1646  */
    { std::cout << "impossible YIELD" << std::endl; }
#line 2652 "parse.tab.c" /* yacc.c:1646  */
    break;


#line 2656 "parse.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 843 "includes/parse.y" /* yacc.c:1906  */


#include <stdio.h>
void yyerror (const char *s)
{
    if(yylloc.first_line > 0)	{
        fprintf (stderr, "%d.%d-%d.%d:", yylloc.first_line, yylloc.first_column,
	                                     yylloc.last_line,  yylloc.last_column);
    }
    fprintf(stderr, " %s with [%s]\n", s, yytext);
}
