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
    #include "includes/nodeType.h"
    // #include

    #include <iostream>
    #include <map>
    #include <cmath>
    int yylex ();
    extern char *yytext;
    void yyerror (const char *);

    PoolOfNodes& pool = PoolOfNodes::getInstance(); //prevent memory leak
    SyntaxScope& scope = SyntaxScope::getInstance();
    // Node* temp[64];
    // int tempcount = 0;

#line 84 "parse.tab.c" /* yacc.c:339  */

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
#line 21 "includes/parse.y" /* yacc.c:355  */

    Node* node;
    int intNumber;
    float fltNumber;
    char *identifier;
    int op;

#line 220 "parse.tab.c" /* yacc.c:355  */
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

#line 249 "parse.tab.c" /* yacc.c:358  */

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
#define YYLAST   821

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  141
/* YYNRULES -- Number of rules.  */
#define YYNRULES  315
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  478

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
       0,    78,    78,    86,    89,    90,   116,   120,   123,   124,
     127,   128,   131,   132,   135,   136,   139,   139,   151,   152,
     155,   156,   159,   160,   163,   164,   167,   168,   171,   172,
     175,   176,   179,   180,   183,   184,   187,   188,   191,   192,
     199,   204,   212,   213,   216,   218,   222,   223,   224,   229,
     230,   231,   232,   235,   272,   289,   294,   301,   313,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   334,   340,   347,   354,   357,   365,   368,   369,   372,
     373,   376,   379,   382,   383,   384,   385,   386,   389,   392,
     395,   400,   403,   406,   407,   410,   411,   414,   415,   418,
     419,   422,   425,   428,   429,   432,   433,   434,   437,   438,
     441,   442,   445,   446,   449,   450,   453,   454,   457,   458,
     461,   464,   465,   468,   469,   472,   473,   476,   478,   479,
     480,   481,   482,   484,   485,   488,   492,   496,   497,   500,
     501,   504,   505,   508,   509,   512,   513,   516,   517,   520,
     521,   524,   527,   528,   531,   532,   535,   536,   539,   540,
     543,   544,   547,   553,   561,   566,   574,   575,   578,   579,
     582,   583,   586,   587,   590,   591,   598,   600,   603,   604,
     607,   608,   611,   612,   615,   616,   645,   646,   647,   648,
     649,   650,   651,   652,   653,   654,   655,   658,   663,   670,
     671,   674,   675,   678,   679,   682,   683,   686,   687,   702,
     703,   706,   711,   735,   737,   739,   741,   745,   758,   765,
     766,   767,   770,   780,   792,   793,   796,   802,   804,   806,
     808,   814,   819,   824,   827,   828,   831,   832,   835,   836,
     839,   840,   843,   844,   847,   848,   851,   852,   855,   856,
     859,   860,   861,   864,   865,   868,   869,   872,   873,   874,
     877,   878,   881,   882,   885,   886,   889,   890,   893,   894,
     897,   902,   917,   918,   921,   922,   925,   926,   929,   930,
     933,   934,   937,   938,   941,   944,   945,   948,   949,   952,
     953,   956,   957,   958,   961,   962,   965,   966,   969,   970,
     973,   974,   977,   978,   981,   982,   985,   986,   989,   990,
     993,   994,   997,   998,  1001,  1002
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "NAME", "PLUS", "MINUS",
  "STAR", "SLASH", "PERCENT", "DOUBLESLASH", "DOUBLESTAR", "EQUAL",
  "PLUSEQUAL", "MINEQUAL", "STAREQUAL", "SLASHEQUAL", "PERCENTEQUAL",
  "DOUBLESTAREQUAL", "DOUBLESLASHEQUAL", "LESS", "GREATER", "EQEQUAL",
  "GREATEREQUAL", "LESSEQUAL", "NOTEQUAL", "IMAG", "AMPEREQUAL",
  "AMPERSAND", "AND", "AS", "ASSERT", "AT", "BACKQUOTE", "BAR", "BREAK",
  "CIRCUMFLEX", "CIRCUMFLEXEQUAL", "CLASS", "COLON", "COMMA", "CONTINUE",
  "DEDENT", "DEF", "DEL", "DOT", "ELIF", "ELSE", "ENDMARKER", "EXCEPT",
  "EXEC", "FINALLY", "FOR", "FROM", "GLOBAL", "GRLT", "IF", "IMPORT", "IN",
  "INDENT", "IS", "LAMBDA", "LBRACE", "LEFTSHIFT", "LEFTSHIFTEQUAL",
  "LPAR", "LSQB", "NEWLINE", "NOT", "OR", "PASS", "PRINT", "RAISE",
  "RBRACE", "RETURN", "RIGHTSHIFT", "RIGHTSHIFTEQUAL", "RPAR", "RSQB",
  "SEMI", "STRING", "TILDE", "TRY", "VBAREQUAL", "WHILE", "WITH", "YIELD",
  "$accept", "start", "file_input", "pick_NEWLINE_stmt",
  "star_NEWLINE_stmt", "decorator", "opt_arglist", "decorators",
  "decorated", "funcdef", "$@1", "parameters", "varargslist",
  "opt_EQUAL_test", "star_fpdef_COMMA", "opt_DOUBLESTAR_NAME",
  "pick_STAR_DOUBLESTAR", "opt_COMMA", "fpdef", "fplist",
  "star_fpdef_notest", "stmt", "simple_stmt", "star_SEMI_small_stmt",
  "small_stmt", "expr_stmt", "pick_yield_expr_testlist", "star_EQUAL",
  "augassign", "print_stmt", "star_COMMA_test", "opt_test",
  "plus_COMMA_test", "opt_test_2", "del_stmt", "pass_stmt", "flow_stmt",
  "break_stmt", "continue_stmt", "return_stmt", "yield_stmt", "raise_stmt",
  "opt_COMMA_test", "opt_test_3", "import_stmt", "import_name",
  "import_from", "pick_dotted_name", "pick_STAR_import", "import_as_name",
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

#define YYPACT_NINF -280

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-280)))

#define YYTABLE_NINF -262

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -280,    90,  -280,   339,  -280,  -280,  -280,  -280,  -280,  -280,
     680,    29,   680,  -280,   144,  -280,   147,    53,  -280,    53,
      53,  -280,   164,   680,    29,   116,   680,    63,   680,  -280,
     714,  -280,   595,   680,   680,  -280,  -280,   149,   680,   680,
     680,  -280,  -280,   151,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,   -16,   157,  -280,   713,   156,   155,   169,    17,
     132,   229,  -280,    53,  -280,  -280,   118,  -280,   737,  -280,
    -280,   159,  -280,   115,  -280,   114,    -4,   139,   156,  -280,
       5,   150,   153,    25,  -280,   168,  -280,   171,    55,   680,
     176,    30,    93,   143,  -280,   166,  -280,   146,  -280,  -280,
     172,   148,  -280,  -280,   680,  -280,  -280,   190,  -280,    40,
     203,  -280,   215,  -280,  -280,  -280,  -280,    37,   209,   714,
     714,  -280,   714,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,   182,   193,    53,    53,    53,    53,  -280,  -280,    53,
    -280,  -280,    53,  -280,  -280,  -280,  -280,    53,  -280,   112,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,   240,    63,   680,   250,   178,  -280,  -280,
     680,    40,   680,   179,  -280,   218,   680,   680,    44,   210,
     221,   228,    40,    29,   266,  -280,   680,  -280,   267,   268,
      34,  -280,   261,   680,    53,   234,  -280,  -280,  -280,   234,
    -280,  -280,    53,   234,  -280,  -280,   236,   234,   680,  -280,
     219,  -280,     1,    40,   125,    53,  -280,   573,   680,     7,
     157,  -280,  -280,  -280,   156,   155,   169,    17,   132,   229,
    -280,    53,   273,   178,   646,  -280,    63,  -280,  -280,  -280,
    -280,  -280,   204,  -280,   258,  -280,  -280,  -280,   205,  -280,
     212,   241,    53,   246,   248,   260,  -280,   288,  -280,  -280,
    -280,   289,  -280,  -280,  -280,  -280,   255,  -280,  -280,   220,
     680,   256,   166,   245,   680,  -280,  -280,   249,  -280,   680,
     259,  -280,  -280,   246,   500,   680,   270,     0,   271,   264,
      40,   680,   156,  -280,  -280,  -280,   680,  -280,  -280,   235,
     269,   274,   237,  -280,   279,  -280,   239,   680,   680,    20,
    -280,   281,   283,  -280,    40,   156,   680,  -280,    40,   324,
     252,   291,  -280,   129,   321,  -280,   293,  -280,  -280,    -3,
    -280,   294,  -280,  -280,   714,   697,  -280,   680,  -280,  -280,
    -280,   427,    48,    40,   296,   285,   298,    40,   301,  -280,
    -280,  -280,  -280,   302,  -280,   308,   680,  -280,  -280,  -280,
     680,  -280,  -280,   272,  -280,    40,  -280,  -280,   303,  -280,
    -280,   288,   680,   312,   348,    34,   680,  -280,     8,   314,
      27,   315,  -280,   287,  -280,  -280,  -280,  -280,  -280,   680,
    -280,  -280,    40,   318,  -280,    40,  -280,    40,  -280,   167,
    -280,   320,   322,  -280,  -280,   325,  -280,   327,    40,  -280,
    -280,   328,   697,  -280,  -280,  -280,   697,   329,   697,  -280,
    -280,  -280,   697,   323,  -280,  -280,    40,  -280,  -280,  -280,
     680,  -280,  -280,   663,  -280,    40,    40,  -280,   680,    94,
    -280,   697,    27,  -280,   697,  -280,  -280,  -280,   680,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       7,     0,     2,     0,     1,   231,   232,   230,   219,   220,
       0,     0,     0,    88,     0,    89,     0,     0,     3,     0,
       0,   315,     0,     0,     0,    25,   241,   237,   239,     4,
       0,    82,    76,    94,    91,   243,   221,     0,     0,     0,
     313,     6,    13,     0,   134,   132,     5,    38,    43,    44,
      45,    46,    47,    48,    83,    84,    85,    87,    86,    49,
      99,   100,    50,    51,    52,    39,   127,   128,   129,   130,
     131,    74,   177,   178,   180,   183,   184,   197,   199,   201,
     203,   207,   211,     0,   218,   225,   233,   175,    58,   133,
      92,   126,   118,     0,   310,     0,     0,     0,   269,    81,
     124,     0,     0,     0,   122,     0,   116,   101,   111,     0,
       0,     0,    74,     0,   240,    74,   236,     0,   235,   234,
      74,     0,   238,   182,     0,    71,    74,    98,    90,     0,
       0,   153,   155,   312,    12,    15,    14,     0,   271,     0,
       0,   174,     0,   186,   187,   188,   189,   190,   192,   191,
     193,   195,     0,     0,     0,     0,     0,   205,   206,     0,
     209,   210,     0,   213,   214,   215,   216,     0,   217,   223,
     242,    59,    60,    61,    62,    63,    69,    70,    64,    66,
      67,    68,    65,    54,     0,     0,     0,   286,     9,   229,
       0,     0,   283,    25,    16,   267,     0,     0,     0,   314,
     103,   120,     0,     0,     0,   249,     0,    32,     0,     0,
       0,    20,    23,     0,     0,    31,   273,   278,   228,    31,
     246,   226,     0,    31,   244,   227,    80,    31,     0,    93,
       0,   162,     0,     0,     0,     0,    41,     0,   270,     0,
     179,   181,   196,   194,   185,   198,   200,   202,   204,   208,
     212,     0,     0,   286,   261,   224,     0,    53,    56,    55,
     125,   119,     0,    10,     0,   311,   281,   282,     0,    19,
       0,     0,   266,    96,     0,   109,   105,     0,   102,   115,
     107,     0,   138,   117,   110,   248,    27,    29,    37,     0,
       0,    31,   275,     0,    30,   279,   247,     0,   245,     0,
      31,    72,    75,    96,     0,   157,     0,   148,     0,   140,
       0,     0,   154,    40,    42,    73,     0,   222,   252,     0,
       0,   258,     0,   256,     0,    57,     0,     0,     0,   297,
     284,    31,     0,    18,     0,   268,     0,   123,     0,     0,
       0,   113,   121,   136,     0,    28,    35,    33,    22,    24,
      21,    31,   272,   276,     0,     0,    78,    30,    79,    97,
     165,     0,   161,     0,     0,   150,     0,     0,     0,   151,
     152,   176,   250,     0,   251,   254,   261,     8,   288,   293,
       0,   294,   296,   285,   291,     0,    17,    95,   142,   108,
     106,   112,     0,     0,     0,    34,    30,   277,   307,    25,
     301,   167,   171,   170,    77,   163,   164,   158,   159,     0,
     156,   144,     0,     0,   143,     0,   146,     0,   257,   253,
     260,   263,   290,   295,   280,     0,   114,     0,     0,    26,
      36,     0,     0,   306,   304,   305,     0,     0,     0,   300,
     298,   299,     0,    31,   160,   147,     0,   145,   139,   255,
     265,   259,   262,     0,   292,     0,     0,   135,     0,   309,
     173,     0,   303,   169,    30,   166,   149,   264,     0,   287,
     141,   137,   274,   308,   172,   302,   168,   289
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -280,  -280,  -280,  -280,  -280,   319,   102,  -280,  -280,   331,
    -280,  -280,  -179,  -280,  -280,  -280,  -280,  -208,  -201,  -280,
    -280,  -273,    -2,  -280,   124,  -280,   120,  -280,  -280,  -280,
      16,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,    74,  -280,  -280,  -280,  -280,  -280,  -280,   -11,
     184,   108,  -280,  -280,    15,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
      68,    82,  -280,  -280,  -170,  -280,  -280,  -280,  -279,  -280,
     -10,  -280,  -133,   251,    -5,  -280,  -280,   -12,   244,   262,
     247,  -280,   254,  -280,   233,  -280,   -63,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,   -19,    28,  -280,  -280,    -8,  -280,   -30,  -280,
    -280,  -280,  -280,   372,  -280,  -280,  -280,  -280,  -280,  -280,
     -37,  -280,   -44,   299,  -280,   -36,   -88,  -280,  -280,   -24,
    -280
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    41,     3,    42,   262,    43,    44,    45,
     271,   194,   110,   291,   111,   345,   211,   295,   212,   289,
     346,    46,   231,   137,    48,    49,   257,   183,   184,    50,
     138,   125,   300,   301,    51,    52,    53,    54,    55,    56,
      57,    58,   337,   229,    59,    60,    61,   102,   278,   279,
     106,   280,   341,   107,   108,    62,   201,    63,    64,    65,
      66,   343,    67,    68,    69,   307,   365,   414,    70,   234,
     131,   308,   409,   410,   232,   361,   400,   443,   401,   402,
      71,   141,    72,    73,    74,    75,   153,    76,    77,    78,
      79,   159,    80,   162,    81,   167,    82,    83,    84,   169,
      85,   116,   117,   121,   113,    86,   122,   118,    87,   255,
     322,   375,   323,   324,   451,   452,    99,   195,    88,   114,
     351,   352,   216,    89,   268,   263,   264,   422,   454,   330,
     331,   381,   439,   440,   441,   433,   434,   435,    95,    90,
     103
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,    47,    94,   119,   128,    98,   239,   100,    98,   288,
     133,   296,   101,   105,   270,   298,   112,   115,   120,   302,
     168,   266,   126,   127,   217,   123,    93,   220,   130,   132,
      92,   360,   282,   380,    92,   207,   191,   -30,   208,   207,
     154,   139,   209,     5,     6,     7,     8,     9,   364,   275,
     305,   305,   276,   306,   140,   316,     5,     6,     7,     8,
       9,   214,   192,   309,   196,   432,     5,     6,     7,     8,
       9,   199,    10,   214,    12,   -30,    13,   140,   140,   407,
     222,   157,    15,   350,   438,    17,   204,    12,   406,   408,
       4,    19,   358,   158,    21,    22,   210,    12,    24,   205,
     210,   186,    25,    26,   250,   236,    27,    28,   230,    30,
     277,    31,    32,    33,   226,    34,    26,   237,   200,    27,
      28,    35,    36,   384,   251,    25,    26,    40,   215,    27,
      28,   219,    30,   213,    35,    36,   223,   241,   160,   161,
     369,   244,   227,   397,    35,    36,   214,   214,   189,    96,
      40,   432,    97,   459,   258,   190,   109,   460,   252,   462,
     259,   186,   267,   463,   386,   310,   311,   274,   388,   104,
       5,     6,     7,     8,     9,   260,   392,   393,   253,   254,
     265,   187,   474,   188,    11,   476,   273,   142,   317,   129,
      14,   154,   155,   411,   430,    16,   285,   416,   156,   170,
     185,    12,    98,   292,   353,   193,   293,  -261,   202,   197,
      98,   198,   203,   320,   297,   424,   206,   218,   303,   214,
     437,   398,   403,   312,   221,   222,   258,   225,   315,    25,
      26,   228,   259,    27,    28,   465,    30,   163,   164,   165,
     166,   382,   445,   233,   321,   447,   235,   448,    35,    36,
     238,   242,   243,   256,   329,   261,   -11,   269,   457,   272,
     335,     5,     6,     7,     8,     9,   327,   186,  -104,   281,
     328,   284,   286,   287,   290,   294,   466,   299,   318,   304,
     348,   334,   326,   332,   315,   470,   471,   336,   338,   356,
     333,   339,    12,   275,   342,   362,   344,   349,   347,   403,
     357,   132,    47,   403,   354,   403,   371,   377,   355,   403,
     363,   367,   368,   372,  -260,   373,   374,   378,   379,   376,
      25,    26,   383,   385,    27,    28,   387,    30,   403,   389,
     390,   403,   391,   394,   395,   396,   412,   413,   415,    35,
      36,   417,     5,     6,     7,     8,     9,   404,   418,   419,
     -30,   425,   428,   429,   436,   319,   442,   140,   446,    47,
     450,   314,   134,   453,   464,   455,   420,   456,   458,   461,
     423,    10,    11,    12,   135,    13,   325,   359,    14,   370,
     426,    15,   427,    16,    17,   340,   431,   283,    18,   366,
      19,   240,    20,    21,    22,   249,    23,    24,   245,   444,
     449,    25,    26,   247,   421,    27,    28,    29,    30,   321,
      31,    32,    33,   248,    34,   136,   469,   246,   475,   224,
      35,    36,    37,   473,    38,    39,    40,     0,     0,     0,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
     467,     0,     0,   329,     0,     0,     0,     0,   472,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   477,    10,
      11,    12,     0,    13,     0,     0,    14,     0,     0,    15,
     405,    16,    17,     0,     0,     0,     0,     0,    19,     0,
      20,    21,    22,     0,    23,    24,     0,     0,     0,    25,
      26,     0,     0,    27,    28,     0,    30,     0,    31,    32,
      33,     0,    34,     5,     6,     7,     8,     9,    35,    36,
      37,     0,    38,    39,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,     0,    13,     0,     0,    14,
       0,     0,    15,     0,    16,    17,     0,     0,     0,     0,
       0,    19,     0,    20,    21,    22,     0,    23,    24,     0,
       0,     0,    25,    26,     0,     0,    27,    28,     0,    30,
       0,    31,    32,    33,     0,    34,     5,     6,     7,     8,
       9,    35,    36,    37,     0,    38,    39,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,     0,     0,    10,     0,    12,     0,    13,
       0,     0,     0,     0,     0,    15,     0,     0,    17,     0,
       0,     0,     0,     0,    19,     0,     0,    21,    22,    12,
       0,    24,     0,     0,     0,    25,    26,     0,     0,    27,
      28,   313,    30,     0,    31,    32,    33,     0,    34,     5,
       6,     7,     8,     9,    35,    36,     0,    25,    26,     0,
      40,    27,    28,     0,    30,     0,     5,     6,     7,     8,
       9,   124,     0,     0,     0,   468,    35,    36,     0,     0,
      12,     0,     0,     5,     6,     7,     8,     9,     0,     0,
       0,     0,   320,     0,     0,     0,     0,    12,     0,     0,
       5,     6,     7,     8,     9,     0,     0,     0,    25,    26,
       0,     0,    27,    28,    12,    30,     0,     5,     6,     7,
       8,     9,     0,     0,     0,    25,    26,    35,    36,    27,
      28,    12,    30,     0,   143,   144,   145,   146,   147,   148,
       0,     0,    25,    26,    35,    36,    27,    28,    12,    30,
       0,   171,   172,   173,   174,   175,   176,   177,     0,   399,
      26,    35,    36,    27,    28,   178,    30,     0,     0,   149,
       0,     0,   150,     0,   151,   179,     0,    26,    35,    36,
      27,    28,   152,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,    36,     0,     0,     0,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   181,     0,     0,     0,     0,     0,
       0,   182
};

static const yytype_int16 yycheck[] =
{
      10,     3,    12,    27,    34,    17,   139,    19,    20,   210,
      40,   219,    20,    23,   193,   223,    26,    27,    28,   227,
      83,   191,    32,    33,   112,    30,    11,   115,    38,    39,
       5,   304,   202,    13,     5,     5,    40,    40,     8,     5,
      35,    57,    12,     3,     4,     5,     6,     7,    48,     5,
      50,    50,     8,    52,    70,    48,     3,     4,     5,     6,
       7,    53,    66,   233,    59,    57,     3,     4,     5,     6,
       7,    46,    32,    53,    34,    78,    36,    70,    70,    31,
      53,    64,    42,   291,    57,    45,    31,    34,   361,    41,
       0,    51,   300,    76,    54,    55,    66,    34,    58,   109,
      66,    46,    62,    63,   167,    68,    66,    67,    68,    69,
      66,    71,    72,    73,   124,    75,    63,    80,   103,    66,
      67,    81,    82,   331,    12,    62,    63,    87,   112,    66,
      67,   115,    69,    40,    81,    82,   120,   142,     6,     7,
     310,   153,   126,   351,    81,    82,    53,    53,    34,     5,
      87,    57,     5,   432,   184,    41,    40,   436,    46,   438,
     184,    46,   192,   442,   334,    40,    41,   197,   338,     5,
       3,     4,     5,     6,     7,   185,    47,    48,    66,    67,
     190,    66,   461,    68,    33,   464,   196,    30,   251,    40,
      39,    35,    37,   363,   395,    44,   206,   367,    29,    81,
      41,    34,   214,   213,   292,    66,   214,    40,    40,    59,
     222,    58,    41,    46,   222,   385,    40,    74,   228,    53,
     399,   354,   355,   235,    78,    53,   256,    79,   238,    62,
      63,    41,   256,    66,    67,   443,    69,     8,     9,    10,
      11,   329,   412,    40,   254,   415,    31,   417,    81,    82,
      41,    69,    59,    13,   264,     5,    78,    78,   428,    41,
     272,     3,     4,     5,     6,     7,     8,    46,    58,    41,
      12,     5,     5,     5,    13,    41,   446,    41,     5,    60,
     290,    40,    78,    78,   294,   455,   456,    41,    40,   299,
      78,    31,    34,     5,     5,   305,    41,    41,    78,   432,
      41,   311,   304,   436,    59,   438,   316,    68,    59,   442,
      40,    40,    48,    78,    40,    46,    79,   327,   328,    40,
      62,    63,    41,    40,    66,    67,   336,    69,   461,     5,
      78,   464,    41,    12,    41,    41,    40,    52,    40,    81,
      82,    40,     3,     4,     5,     6,     7,   357,    46,    41,
      78,    48,    40,     5,    40,   253,    41,    70,    40,   361,
      40,   237,    43,    41,    41,    40,   376,    40,    40,    40,
     380,    32,    33,    34,    43,    36,   256,   303,    39,   311,
     391,    42,   392,    44,    45,   277,   396,   203,    49,   307,
      51,   140,    53,    54,    55,   162,    57,    58,   154,   409,
     419,    62,    63,   156,   376,    66,    67,    68,    69,   419,
      71,    72,    73,   159,    75,    43,   453,   155,   462,   120,
      81,    82,    83,   459,    85,    86,    87,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
     450,    -1,    -1,   453,    -1,    -1,    -1,    -1,   458,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   468,    32,
      33,    34,    -1,    36,    -1,    -1,    39,    -1,    -1,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      53,    54,    55,    -1,    57,    58,    -1,    -1,    -1,    62,
      63,    -1,    -1,    66,    67,    -1,    69,    -1,    71,    72,
      73,    -1,    75,     3,     4,     5,     6,     7,    81,    82,
      83,    -1,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    -1,    36,    -1,    -1,    39,
      -1,    -1,    42,    -1,    44,    45,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    53,    54,    55,    -1,    57,    58,    -1,
      -1,    -1,    62,    63,    -1,    -1,    66,    67,    -1,    69,
      -1,    71,    72,    73,    -1,    75,     3,     4,     5,     6,
       7,    81,    82,    83,    -1,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    32,    -1,    34,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    54,    55,    34,
      -1,    58,    -1,    -1,    -1,    62,    63,    -1,    -1,    66,
      67,    68,    69,    -1,    71,    72,    73,    -1,    75,     3,
       4,     5,     6,     7,    81,    82,    -1,    62,    63,    -1,
      87,    66,    67,    -1,    69,    -1,     3,     4,     5,     6,
       7,    76,    -1,    -1,    -1,    12,    81,    82,    -1,    -1,
      34,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    34,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    62,    63,
      -1,    -1,    66,    67,    34,    69,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    62,    63,    81,    82,    66,
      67,    34,    69,    -1,    21,    22,    23,    24,    25,    26,
      -1,    -1,    62,    63,    81,    82,    66,    67,    34,    69,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    62,
      63,    81,    82,    66,    67,    28,    69,    -1,    -1,    56,
      -1,    -1,    59,    -1,    61,    38,    -1,    63,    81,    82,
      66,    67,    69,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    84
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    89,    90,    92,     0,     3,     4,     5,     6,     7,
      32,    33,    34,    36,    39,    42,    44,    45,    49,    51,
      53,    54,    55,    57,    58,    62,    63,    66,    67,    68,
      69,    71,    72,    73,    75,    81,    82,    83,    85,    86,
      87,    91,    93,    95,    96,    97,   109,   110,   112,   113,
     117,   122,   123,   124,   125,   126,   127,   128,   129,   132,
     133,   134,   143,   145,   146,   147,   148,   150,   151,   152,
     156,   168,   170,   171,   172,   173,   175,   176,   177,   178,
     180,   182,   184,   185,   186,   188,   193,   196,   206,   211,
     227,   168,     5,   142,   168,   226,     5,     5,   175,   204,
     175,   204,   135,   228,     5,   168,   138,   141,   142,    40,
     100,   102,   168,   192,   207,   168,   189,   190,   195,   227,
     168,   191,   194,   172,    76,   119,   168,   168,   206,    40,
     168,   158,   168,   206,    93,    97,   211,   111,   118,    57,
      70,   169,    30,    21,    22,    23,    24,    25,    26,    56,
      59,    61,    69,   174,    35,    37,    29,    64,    76,   179,
       6,     7,   181,     8,     9,    10,    11,   183,   184,   187,
      81,    14,    15,    16,    17,    18,    19,    20,    28,    38,
      65,    77,    84,   115,   116,    41,    46,    66,    68,    34,
      41,    40,    66,    66,    99,   205,    59,    59,    58,    46,
     142,   144,    40,    41,    31,   168,    40,     5,     8,    12,
      66,   104,   106,    40,    53,   118,   210,   224,    74,   118,
     224,    78,    53,   118,   221,    79,   168,   118,    41,   131,
      68,   110,   162,    40,   157,    31,    68,    80,    41,   170,
     171,   172,    69,    59,   175,   176,   177,   178,   180,   182,
     184,    12,    46,    66,    67,   197,    13,   114,   206,   227,
     168,     5,    94,   213,   214,   168,   162,   206,   212,    78,
     100,    98,    41,   168,   206,     5,     8,    66,   136,   137,
     139,    41,   162,   138,     5,   168,     5,     5,   106,   107,
      13,   101,   168,   204,    41,   105,   105,   204,   105,    41,
     120,   121,   105,   168,    60,    50,    52,   153,   159,   162,
      40,    41,   175,    68,   112,   168,    48,   184,     5,    94,
      46,   168,   198,   200,   201,   114,    78,     8,    12,   168,
     217,   218,    78,    78,    40,   175,    41,   130,    40,    31,
     139,   140,     5,   149,    41,   103,   108,    78,   168,    41,
     105,   208,   209,   224,    59,    59,   168,    41,   105,   130,
     109,   163,   168,    40,    48,   154,   159,    40,    48,   162,
     158,   168,    78,    46,    79,   199,    40,    68,   168,   168,
      13,   219,   224,    41,   105,    40,   162,   168,   162,     5,
      78,    41,    47,    48,    12,    41,    41,   105,   170,    62,
     164,   166,   167,   170,   168,    43,   109,    31,    41,   160,
     161,   162,    40,    52,   155,    40,   162,    40,    46,    41,
     168,   201,   215,   168,   162,    48,   137,   168,    40,     5,
     106,   168,    57,   223,   224,   225,    40,   100,    57,   220,
     221,   222,    41,   165,   168,   162,    40,   162,   162,   200,
      40,   202,   203,    41,   216,    40,    40,   162,    40,   166,
     166,    40,   166,   166,    41,   105,   162,   168,    12,   218,
     162,   162,   168,   223,   166,   220,   166,   168
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    90,    91,    91,    92,    92,    93,    93,
      94,    94,    95,    95,    96,    96,    98,    97,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   117,   117,   118,   118,   119,   119,   120,   120,   121,
     121,   122,   123,   124,   124,   124,   124,   124,   125,   126,
     127,   127,   128,   129,   129,   130,   130,   131,   131,   132,
     132,   133,   134,   135,   135,   136,   136,   136,   137,   137,
     138,   138,   139,   139,   140,   140,   141,   141,   142,   142,
     143,   144,   144,   145,   145,   146,   146,   147,   147,   147,
     147,   147,   147,   147,   147,   148,   148,   149,   149,   150,
     150,   151,   151,   152,   152,   153,   153,   154,   154,   155,
     155,   156,   157,   157,   158,   158,   159,   159,   160,   160,
     161,   161,   162,   162,   163,   163,   164,   164,   165,   165,
     166,   166,   167,   167,   168,   168,   169,   169,   170,   170,
     171,   171,   172,   172,   173,   173,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   175,   175,   176,
     176,   177,   177,   178,   178,   179,   179,   180,   180,   181,
     181,   182,   182,   183,   183,   183,   183,   184,   184,   185,
     185,   185,   186,   186,   187,   187,   188,   188,   188,   188,
     188,   188,   188,   188,   189,   189,   190,   190,   191,   191,
     192,   192,   193,   193,   194,   194,   195,   195,   196,   196,
     197,   197,   197,   198,   198,   199,   199,   200,   200,   200,
     201,   201,   202,   202,   203,   203,   204,   204,   205,   205,
     206,   206,   207,   207,   208,   208,   209,   209,   210,   210,
     211,   211,   212,   212,   213,   214,   214,   215,   215,   216,
     216,   217,   217,   217,   218,   218,   219,   219,   220,   220,
     221,   221,   222,   222,   223,   223,   224,   224,   225,   225,
     226,   226,   227,   227,   228,   228
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     0,     6,     3,
       1,     0,     2,     1,     2,     2,     0,     6,     3,     2,
       2,     4,     2,     0,     4,     0,     3,     0,     3,     2,
       1,     0,     1,     3,     3,     2,     3,     0,     1,     1,
       4,     3,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     1,     1,     3,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     3,     0,     3,     0,     3,     2,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     3,     1,     2,     0,     3,     0,     1,
       1,     2,     4,     2,     2,     1,     3,     1,     3,     1,
       3,     1,     3,     2,     3,     0,     1,     3,     1,     3,
       3,     3,     0,     5,     2,     4,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     8,     5,     5,     0,     7,
       4,     9,     6,     6,     6,     4,     3,     3,     0,     3,
       0,     5,     3,     0,     3,     1,     3,     1,     1,     1,
       2,     0,     1,     4,     2,     1,     3,     1,     3,     2,
       1,     1,     4,     3,     2,     1,     4,     0,     1,     3,
       1,     3,     2,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     4,     2,     2,     0,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     0,
       1,     0,     2,     1,     2,     3,     2,     3,     4,     3,
       3,     3,     2,     3,     2,     3,     0,     3,     1,     4,
       1,     0,     1,     0,     2,     1,     3,     2,     3,     0,
       3,     2,     4,     2,     5,     0,     1,     2,     1,     2,
       7,     4,     1,     0,     2,     3,     0,     3,     0,     3,
       0,     2,     4,     2,     2,     3,     1,     0,     1,     1,
       5,     4,     3,     2,     1,     1,     5,     4,     3,     2,
       1,     3,     2,     1,     2,     0
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
#line 79 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
        // std::cout << "at beginning" << std::endl;
        // if ($1) { ($1)->eval()->print(); }
    }
#line 1900 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 86 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1906 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 89 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1912 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 91 "includes/parse.y" /* yacc.c:1646  */
    {
            // static int n = 0;
            // std::cout << "stmt : " << n++ << std::endl;
            if((yyvsp[0].node)) {
                (yyval.node) = (yyvsp[0].node);
                //std::cout << "here 1" << std::endl;
                // $1->eval();
                //std::cout << "here 2" << std::endl;

                // IdentNode* id = dynamic_cast<IdentNode*>($1);
                // if (id) {
                //     id->eval()->print();
                // }
                const Node* tmp = (yyvsp[0].node)->eval();
                if(nodeGroup((yyvsp[0].node))==T_IDENT || nodeGroup((yyvsp[0].node))==T_EXPR) {
                    tmp->print();
                }
                // $1->eval()->print();
            }
            else {
                std::cout << "No statement could be evaluated " << std::endl;
            }
        }
#line 1940 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 117 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1948 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 120 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1954 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 139 "includes/parse.y" /* yacc.c:1646  */
    { scope.scopeIn();
                            std::cout << "scope in :" << scope.getScope() << std::endl; }
#line 1961 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 141 "includes/parse.y" /* yacc.c:1646  */
    {
            // std::cout << "func define" << std::endl;
            (yyval.node) = new FuncNode((yyvsp[-4].identifier), (yyvsp[0].node));

            scope.scopeOut();
            std::cout << "scope out :" << scope.getScope() << std::endl;
            delete [] (yyvsp[-4].identifier);
        }
#line 1974 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 167 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 1980 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 171 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-1].identifier); }
#line 1986 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 172 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 1992 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 179 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 1998 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 191 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2004 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 193 "includes/parse.y" /* yacc.c:1646  */
    {
            // std::cout << "stmt: compound_stmt" << std::endl;
            (yyval.node) = (yyvsp[0].node);
        }
#line 2013 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 200 "includes/parse.y" /* yacc.c:1646  */
    {
            // std::cout << "simple_stmt 1 impossible" << std::endl;
            (yyval.node) = (yyvsp[-3].node);
        }
#line 2022 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 205 "includes/parse.y" /* yacc.c:1646  */
    {
            // std::cout << "simple_stmt 2" << std::endl;
            (yyval.node) = (yyvsp[-2].node);
            // ($1)->eval()->print();
        }
#line 2032 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 217 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2038 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 219 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2046 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 222 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2052 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 223 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2058 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 225 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            std::cout << "flow(return)" << std::endl;
        }
#line 2067 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 229 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2073 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 230 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2079 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 231 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2085 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 232 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2091 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 236 "includes/parse.y" /* yacc.c:1646  */
    {
            // std::cout << "expr_stmt1" << std::endl;
            switch ((yyvsp[-1].op)) {
                case OP_PLUSEQUAL:
                    (yyval.node) = new PlusAsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                    pool.add((yyval.node));
                break;
                case OP_MINEQUAL:
                    (yyval.node) = new MinAsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                    pool.add((yyval.node));
                break;
                case OP_STAREQUAL:
                    (yyval.node) = new MulAsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                    pool.add((yyval.node));
                break;
                case OP_SLASHEQUAL:
                    (yyval.node) = new DivAsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                    pool.add((yyval.node));
                break;
                case OP_PERCENTEQUAL:
                    (yyval.node) = new ModAsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                    pool.add((yyval.node));
                break;
                case OP_DOUBLESTAREQUAL:
                    (yyval.node) = new ExpAsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                    pool.add((yyval.node));
                break;
                case OP_DOUBELSLASHEQUAL:
                    (yyval.node) = new FlrDivAsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                    pool.add((yyval.node));
                break;
                default:
                    throw std::string("augassign error");
                break;
            }
        }
#line 2132 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 273 "includes/parse.y" /* yacc.c:1646  */
    {
            if ((yyvsp[0].node)) {
                // std::cout << "expr_stmt 2" << std::endl;
                // if(!$1) {
                //     std::cout << "expr_stmt 2 $1" << std::endl;
                // }
                (yyval.node) = new AsgBinaryNode((yyvsp[-1].node), (yyvsp[0].node));
                pool.add((yyval.node));
            }
            else {
                (yyval.node) = (yyvsp[-1].node);
                //($1)->eval()->print();
            }
        }
#line 2151 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 290 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            // std::cout << "pick_yield_expr_testlist1" << std::endl;
        }
#line 2160 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 295 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            // std::cout << "pick_yield_expr_testlist2" << std::endl;
        }
#line 2169 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 302 "includes/parse.y" /* yacc.c:1646  */
    {
            // std::cout << "star_EQUAL 1" << std::endl;
            if ((yyvsp[-2].node)) { //means more than one EQUAL
                // std::cout << "star_EQUAL 1 $1" << std::endl;
                (yyval.node) = new AsgBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                pool.add((yyval.node));
            }
            else {
                (yyval.node) = (yyvsp[0].node);
            }
        }
#line 2185 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 314 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = nullptr;
            // std::cout << "star_EQUAL2" << std::endl;
        }
#line 2194 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 320 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2200 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 321 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2206 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 322 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2212 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 323 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2218 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 324 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2224 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 325 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2230 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 326 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2236 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 327 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2242 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 328 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2248 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 329 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2254 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 330 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2260 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 331 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2266 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 335 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = new PrintNode((yyvsp[0].node));
            pool.add((yyval.node));
            // std::cout << "print_stmt1" << std::endl;
        }
#line 2276 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 341 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = NULL;
            // std::cout << "print_stmt2" << std::endl;
        }
#line 2285 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 348 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-2].node); //should always be NULL
            // if ($3) {
            //     ($3)->eval()->print();
            // }
        }
#line 2296 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 354 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2302 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 358 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-2].node);
            // if ($1) {
            //     ($1)->eval()->print();
            // }
            // std::cout << "opt_test1" << std::endl;
        }
#line 2314 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 365 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2320 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 382 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2326 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 383 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2332 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 384 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2338 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 385 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2344 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 386 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2350 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 396 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = new ReturnNode((yyvsp[0].node));
            pool.add((yyval.node));
        }
#line 2359 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 400 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2365 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 437 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-2].identifier); delete [] (yyvsp[0].identifier); }
#line 2371 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 438 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2377 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 441 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2383 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 457 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2389 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 458 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2395 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 461 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-1].identifier); }
#line 2401 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 464 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2407 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 477 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2413 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 478 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2419 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 479 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2425 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 480 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2431 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 481 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2437 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 483 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2443 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 484 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2449 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 485 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2455 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 489 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = nullptr;
        }
#line 2463 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 493 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2469 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 548 "includes/parse.y" /* yacc.c:1646  */
    {
            //
            (yyval.node) = (yyvsp[0].node);
            std::cout << "suite: simple_stmt" << std::endl;
        }
#line 2479 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 554 "includes/parse.y" /* yacc.c:1646  */
    {
            //
            (yyval.node) = (yyvsp[-1].node);
            std::cout << "NEWLINE INDENT plus_stmt DEDENT" << std::endl;
        }
#line 2489 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 562 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].node);
            dynamic_cast<SuiteNode*>((yyval.node))->add((yyvsp[0].node));
        }
#line 2498 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 567 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = new SuiteNode();
            dynamic_cast<SuiteNode*>((yyval.node))->add((yyvsp[0].node));
            pool.add((yyval.node));
        }
#line 2508 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 590 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2514 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 592 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = NULL;
            std::cout << "impossible lambdef" << std::endl;
        }
#line 2523 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 599 "includes/parse.y" /* yacc.c:1646  */
    { std::cout << "test: opt_IF_ELSE" << std::endl; }
#line 2529 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 603 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2535 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 604 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2541 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 607 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2547 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 608 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2553 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 611 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2559 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 612 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2565 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 615 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2571 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 617 "includes/parse.y" /* yacc.c:1646  */
    {
            switch ((yyvsp[-1].op)) {
                case OP_LESS :

                    break;
                case OP_GREATER :

                    break;
                case OP_EQEQUAL :

                    break;
                case OP_GREATEREQUAL :

                    break;
                case OP_LESSEQUAL :

                    break;
                case OP_NOTEQUAL :

                    break;
                default :
                    throw std::string("comp_op error");
                    break;
            }
            (yyval.node) = (yyvsp[-2].node);
        }
#line 2602 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 645 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2608 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 646 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2614 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 647 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2620 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 648 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2626 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 649 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2632 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 650 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2638 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 651 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2644 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 652 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2650 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 653 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2656 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 654 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2662 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 655 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2668 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 659 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            //std::cout << "expr1" << std::endl;
        }
#line 2677 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 664 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-2].node);
            //std::cout << "expr2" << std::endl;
        }
#line 2686 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 670 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2692 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 671 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2698 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 674 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2704 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 675 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2710 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 678 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2716 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 679 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2722 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 686 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2728 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 688 "includes/parse.y" /* yacc.c:1646  */
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
#line 2745 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 702 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2751 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 703 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2757 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 707 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            //std::cout << "term1" << std::endl;
        }
#line 2766 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 712 "includes/parse.y" /* yacc.c:1646  */
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
#line 2792 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 736 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2798 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 738 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2804 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 740 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2810 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 742 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2816 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 746 "includes/parse.y" /* yacc.c:1646  */
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
#line 2833 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 759 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
        //std::cout << "factor2" << std::endl;
    }
#line 2842 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 765 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2848 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 766 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2854 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 767 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2860 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 771 "includes/parse.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-1].op) == OP_DOUBLESTAR) {
                (yyval.node) = new ExpBinaryNode((yyvsp[-3].node), (yyvsp[0].node));
                pool.add((yyval.node));
            }
            else {
                std::cout << "DOUBLESTAR wrong" << std::endl;
            }
        }
#line 2874 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 781 "includes/parse.y" /* yacc.c:1646  */
    {
            if((yyvsp[0].node)) {
                std::cout << "call function" << std::endl;
            }
            else {
                (yyval.node) = (yyvsp[-1].node);
            }
            //std::cout << "power2" << std::endl;
        }
#line 2888 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 792 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2894 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 793 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2900 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 797 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].node);
            // std::cout << "atom1" << std::endl;
            if (!(yyvsp[-1].node)) { std::cout << "empty parens" << std::endl; }
        }
#line 2910 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 803 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible atom2" << std::endl; }
#line 2916 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 805 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible atom3" << std::endl; }
#line 2922 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 807 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible atom4" << std::endl; }
#line 2928 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 809 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = new IdentNode((yyvsp[0].identifier));
            delete [] (yyvsp[0].identifier);
            pool.add((yyval.node));
        }
#line 2938 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 815 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = new IntLiteral((yyvsp[0].intNumber));
            pool.add((yyval.node));
        }
#line 2947 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 820 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = new FloatLiteral((yyvsp[0].fltNumber));
            pool.add((yyval.node));
        }
#line 2956 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 824 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible atom8" << std::endl; }
#line 2962 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 827 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2968 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 828 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2974 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 831 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2980 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 237:
#line 832 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2986 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 851 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2992 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 247:
#line 852 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2998 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 861 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 3004 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 898 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-2].node);
            //std::cout << "testlist1" << std::endl;
        }
#line 3013 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 271:
#line 903 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].node);
            // std::cout << "testlist 2" << std::endl;
            // if(!$1) { std::cout << "testlist 2 NULL error" << std::endl; }
            // else {
            //     if(($1)->eval()) {
            //         std::cout << "print: " << std::endl;
            //         ($1)->eval()->print();
            //     }
            // }
            // ($1)->eval()->print();
        }
#line 3030 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 933 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-5].identifier); }
#line 3036 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 934 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-2].identifier); }
#line 3042 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 997 "includes/parse.y" /* yacc.c:1646  */
    { std::cout << "impossible YIELD" << std::endl; (yyval.node) = (yyvsp[0].node); }
#line 3048 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 998 "includes/parse.y" /* yacc.c:1646  */
    { std::cout << "impossible YIELD" << std::endl; }
#line 3054 "parse.tab.c" /* yacc.c:1646  */
    break;


#line 3058 "parse.tab.c" /* yacc.c:1646  */
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
#line 1005 "includes/parse.y" /* yacc.c:1906  */


#include <stdio.h>
void yyerror (const char *s)
{
    if(yylloc.first_line > 0)	{
        fprintf (
            stderr, "%d.%d-%d.%d:",
            yylloc.first_line,
            yylloc.first_column,
            yylloc.last_line,
            yylloc.last_column);
    }
    fprintf(stderr, " %s with [%s]\n", s, yytext);
}
