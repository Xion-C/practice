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
    Node* temp[64];
    int tempcount = 0;

#line 81 "parse.tab.c" /* yacc.c:339  */

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
#line 18 "includes/parse.y" /* yacc.c:355  */

  Node* node;
  int intNumber;
  float fltNumber;
  char *identifier;
  int op;

#line 217 "parse.tab.c" /* yacc.c:355  */
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

#line 246 "parse.tab.c" /* yacc.c:358  */

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
#define YYLAST   913

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
       0,    59,    59,    67,    70,    71,    74,    85,    88,    89,
      92,    93,    96,    97,   100,   101,   104,   107,   108,   111,
     112,   115,   116,   119,   120,   123,   124,   127,   128,   131,
     132,   135,   136,   139,   140,   143,   144,   147,   148,   151,
     156,   163,   164,   167,   168,   173,   174,   175,   176,   177,
     178,   179,   182,   219,   246,   251,   258,   265,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     286,   291,   298,   305,   308,   316,   319,   320,   323,   324,
     327,   330,   333,   334,   335,   336,   337,   340,   343,   346,
     347,   350,   353,   354,   357,   358,   361,   362,   365,   366,
     369,   372,   375,   376,   379,   380,   381,   384,   385,   388,
     389,   392,   393,   396,   397,   400,   401,   404,   405,   408,
     411,   412,   415,   416,   419,   420,   423,   424,   425,   426,
     427,   428,   429,   430,   433,   434,   437,   438,   441,   442,
     445,   446,   449,   450,   453,   454,   457,   458,   461,   462,
     465,   468,   469,   472,   473,   476,   477,   480,   481,   484,
     485,   488,   489,   492,   493,   496,   497,   500,   501,   504,
     505,   508,   509,   512,   513,   520,   521,   524,   525,   528,
     529,   532,   533,   536,   537,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   553,   558,   565,   566,
     569,   570,   573,   574,   577,   578,   581,   582,   597,   599,
     603,   608,   632,   634,   636,   638,   642,   655,   662,   663,
     664,   667,   677,   684,   685,   688,   694,   695,   696,   697,
     703,   708,   713,   716,   717,   720,   721,   724,   725,   728,
     729,   732,   733,   736,   737,   740,   741,   744,   745,   748,
     749,   750,   753,   754,   757,   758,   761,   762,   763,   766,
     767,   770,   771,   774,   775,   778,   779,   782,   783,   786,
     791,   806,   807,   810,   811,   814,   815,   818,   819,   822,
     823,   826,   827,   830,   833,   834,   837,   838,   841,   842,
     845,   846,   847,   850,   851,   854,   855,   858,   859,   862,
     863,   866,   867,   870,   871,   874,   875,   878,   879,   882,
     883,   886,   887,   890,   891
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
  "DOUBLESTAREQUAL", "DOUBLESLASHEQUAL", "IMAG", "AMPEREQUAL", "AMPERSAND",
  "AND", "AS", "ASSERT", "AT", "BACKQUOTE", "BAR", "BREAK", "CIRCUMFLEX",
  "CIRCUMFLEXEQUAL", "CLASS", "COLON", "COMMA", "CONTINUE", "DEDENT",
  "DEF", "DEL", "DOT", "ELIF", "ELSE", "ENDMARKER", "EQEQUAL", "EXCEPT",
  "EXEC", "FINALLY", "FOR", "FROM", "GLOBAL", "GREATER", "GREATEREQUAL",
  "GRLT", "IF", "IMPORT", "IN", "INDENT", "IS", "LAMBDA", "LBRACE",
  "LEFTSHIFT", "LEFTSHIFTEQUAL", "LESS", "LESSEQUAL", "LPAR", "LSQB",
  "NEWLINE", "NOT", "NOTEQUAL", "OR", "PASS", "PRINT", "RAISE", "RBRACE",
  "RETURN", "RIGHTSHIFT", "RIGHTSHIFTEQUAL", "RPAR", "RSQB", "SEMI",
  "STRING", "TILDE", "TRY", "VBAREQUAL", "WHILE", "WITH", "YIELD",
  "$accept", "start", "file_input", "pick_NEWLINE_stmt",
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

#define YYPACT_NINF -314

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-314)))

#define YYTABLE_NINF -261

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -314,    59,  -314,   410,  -314,  -314,  -314,  -314,  -314,  -314,
     787,    57,   787,  -314,    89,  -314,    97,   309,  -314,   309,
     309,  -314,   105,   787,    57,    30,   787,   270,   787,  -314,
     831,  -314,   318,   787,   787,  -314,  -314,    98,   787,   787,
     787,  -314,  -314,    25,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,    -5,   116,  -314,   618,   124,   134,   132,     6,
     120,   159,  -314,   309,  -314,  -314,    78,  -314,    28,  -314,
    -314,   138,  -314,    13,  -314,   128,     5,   117,   124,  -314,
      27,   125,   129,    32,  -314,   149,  -314,   150,   108,   787,
     154,    22,    37,   119,  -314,   146,  -314,   112,  -314,  -314,
     147,   118,  -314,  -314,   787,  -314,  -314,   163,  -314,    70,
     165,  -314,   176,  -314,  -314,  -314,  -314,    17,   167,   831,
     831,  -314,   831,  -314,  -314,  -314,  -314,  -314,   139,  -314,
    -314,   155,  -314,   309,   309,   309,   309,  -314,  -314,   309,
    -314,  -314,   309,  -314,  -314,  -314,  -314,   309,  -314,    26,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,   193,   270,   787,   205,   136,  -314,  -314,
     787,    70,   787,   141,   178,   181,   787,   787,    46,   162,
     180,   189,    70,    57,   220,  -314,   787,  -314,   222,   224,
      16,  -314,   218,   787,   309,   197,  -314,  -314,  -314,   197,
    -314,  -314,   309,   197,  -314,  -314,   199,   197,   787,  -314,
     179,  -314,   127,    70,   142,   309,  -314,   629,   787,    -1,
     116,  -314,  -314,  -314,   124,   134,   132,     6,   120,   159,
    -314,   309,   232,   136,   720,  -314,   270,  -314,  -314,  -314,
    -314,  -314,   161,  -314,   337,  -314,  -314,  -314,   164,  -314,
     168,    70,   309,   206,   209,   223,  -314,   240,  -314,  -314,
    -314,   242,  -314,  -314,  -314,  -314,   214,  -314,  -314,   172,
     787,   217,   146,   200,   787,  -314,  -314,   201,  -314,   787,
     225,  -314,  -314,   206,   556,   787,   219,    44,   227,   221,
      70,   787,   124,  -314,  -314,  -314,   787,  -314,  -314,   184,
     226,   230,   186,  -314,   233,  -314,   192,   787,   787,    20,
    -314,   235,   234,  -314,  -314,   124,   787,  -314,    70,   266,
     194,   246,  -314,   137,   271,  -314,   247,  -314,  -314,     1,
    -314,   250,  -314,  -314,   831,   813,  -314,   787,  -314,  -314,
    -314,   483,    68,    70,   252,   241,   253,    70,   256,  -314,
    -314,  -314,  -314,   251,  -314,   257,   787,  -314,  -314,  -314,
     787,  -314,  -314,   215,  -314,    70,  -314,   254,  -314,  -314,
     240,   787,   260,   292,    16,   787,  -314,    53,   273,     7,
     265,  -314,   238,  -314,  -314,  -314,  -314,  -314,   787,  -314,
    -314,    70,   276,  -314,    70,  -314,    70,  -314,   702,  -314,
     277,   269,  -314,  -314,   285,  -314,   286,    70,  -314,  -314,
     293,   813,  -314,  -314,  -314,   813,   298,   813,  -314,  -314,
    -314,   813,   299,  -314,  -314,    70,  -314,  -314,  -314,   787,
    -314,  -314,   746,  -314,    70,    70,  -314,   787,    67,  -314,
     813,     7,  -314,   813,  -314,  -314,  -314,   787,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314
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
     241,    58,    59,    60,    61,    62,    68,    69,    63,    65,
      66,    67,    64,    53,     0,     0,     0,   285,     9,   228,
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
    -314,  -314,  -314,  -314,  -314,   290,    86,  -314,  -314,   305,
    -314,  -183,  -314,  -314,  -314,  -314,  -187,  -190,  -314,  -314,
    -273,    -2,  -314,   113,  -314,    99,  -314,  -314,  -314,    34,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,    50,  -314,  -314,  -314,  -314,  -314,  -314,   -36,   153,
      81,  -314,  -314,    14,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,    49,
      54,  -314,  -314,  -176,  -314,  -314,  -314,  -313,  -314,   -10,
    -314,  -132,   228,   -11,  -314,  -314,   -14,   208,   212,   207,
    -314,   213,  -314,   202,  -314,   -59,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,   -47,    -3,  -314,  -314,    -9,  -314,   -26,  -314,  -314,
    -314,  -314,   333,  -314,  -314,  -314,  -314,  -314,  -314,   -73,
    -314,   -81,   262,  -314,   -71,  -103,  -314,  -314,   -23,  -314
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
     288,   207,   126,   127,   168,    93,   282,   207,   130,   132,
     208,   360,   296,   380,   209,   -29,   298,    92,   251,   191,
     302,   316,   171,   172,   173,   174,   175,   176,   177,   139,
     178,   275,    11,   186,   276,   222,   154,   309,    14,     4,
     179,   437,    92,    16,   109,   140,   252,   157,   214,   140,
     192,   213,   199,     5,     6,     7,     8,     9,   187,   -29,
     188,   210,   158,   196,   236,   214,   364,   210,   405,   305,
     180,   253,   254,   406,    96,   334,    10,   237,    12,   205,
      13,   214,    97,   407,   350,   181,    15,   431,   250,    17,
     104,   277,   182,   358,   226,   214,    19,   200,   458,    21,
      22,   431,   459,   140,   461,    24,   160,   161,   462,    25,
      26,   241,   129,   204,   369,    27,    28,   230,    30,   244,
     142,    31,    32,    33,   384,    34,   215,   473,   186,   219,
     475,    35,    36,   154,   223,   156,   189,    40,   258,   170,
     227,   259,   387,   190,   396,   155,   267,   163,   164,   165,
     166,   274,   305,   185,   306,   260,   310,   311,   391,   392,
     265,   197,   193,   202,   198,   203,   273,   410,   206,   353,
     221,   415,   317,   218,   214,   222,   285,   225,   228,   233,
      98,   235,   238,   292,   429,   293,   256,   242,    98,   423,
     261,   243,   271,   297,   -11,   436,   272,  -103,   303,   269,
     186,   312,   397,   402,   281,   284,   382,   286,   315,   287,
     258,   290,   294,   259,   299,   444,   304,   318,   446,   326,
     447,   336,   332,   338,   321,   275,   333,   342,   339,   344,
     347,   456,   349,   363,   329,   464,   354,   355,   335,   377,
     357,   367,   372,   368,  -259,   374,   373,   376,   385,   465,
     383,   388,   389,     5,     6,     7,     8,     9,   469,   470,
     348,   390,   394,   393,   315,   395,   411,   414,   412,   356,
     416,   417,   418,   -29,   427,   362,   424,   428,    12,   402,
     441,   132,    47,   402,   452,   402,   371,   435,   140,   402,
     445,   449,     5,     6,     7,     8,     9,   378,   379,   454,
     455,     5,     6,     7,     8,     9,   386,   457,   402,    25,
      26,   402,   460,   134,   463,    27,    28,    12,    30,   319,
       5,     6,     7,     8,     9,   327,    12,   403,   135,   328,
     314,    35,    36,   359,   425,   325,   283,    40,   340,    47,
     370,   366,   245,   247,   249,    12,   419,   246,   240,    26,
     422,   448,   248,   420,    27,    28,   136,    25,    26,   468,
     474,   426,   224,    27,    28,   430,    30,   472,     0,     0,
      35,    36,     0,     0,   124,     0,    25,    26,   443,    35,
      36,     0,    27,    28,     0,    30,     0,     0,   321,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    35,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,    12,   466,
      13,     0,   329,    14,     0,     0,    15,   471,    16,    17,
       0,     0,     0,    18,     0,     0,    19,   476,    20,    21,
      22,     0,     0,     0,    23,    24,     0,     0,     0,    25,
      26,     0,     0,     0,     0,    27,    28,    29,    30,     0,
       0,    31,    32,    33,     0,    34,     5,     6,     7,     8,
       9,    35,    36,    37,     0,    38,    39,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,    12,     0,    13,     0,     0,    14,     0,     0,    15,
     404,    16,    17,     0,     0,     0,     0,     0,     0,    19,
       0,    20,    21,    22,     0,     0,     0,    23,    24,     0,
       0,     0,    25,    26,     0,     0,     0,     0,    27,    28,
       0,    30,     0,     0,    31,    32,    33,     0,    34,     5,
       6,     7,     8,     9,    35,    36,    37,     0,    38,    39,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,     0,    13,     0,     0,    14,
       0,     0,    15,     0,    16,    17,     0,     0,     0,     0,
       0,     0,    19,     0,    20,    21,    22,     0,     0,     0,
      23,    24,     0,     0,     0,    25,    26,     0,     0,     0,
       0,    27,    28,     0,    30,     0,     0,    31,    32,    33,
       0,    34,     5,     6,     7,     8,     9,    35,    36,    37,
       0,    38,    39,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     0,    12,     0,    13,
       0,     0,   143,     0,     0,    15,     0,     0,    17,   144,
     145,   146,     0,     0,   147,    19,   148,     0,    21,    22,
       0,   149,   150,     0,    24,     0,   151,   152,    25,    26,
       0,     0,     0,     0,    27,    28,   313,    30,     0,     0,
      31,    32,    33,     0,    34,     5,     6,     7,     8,     9,
      35,    36,     0,     0,     0,     0,    40,     0,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,     0,     0,
      12,     0,     0,     0,     0,     0,  -260,     0,     0,     0,
       0,     0,   320,     0,     0,     0,     0,     0,    12,     5,
       6,     7,     8,     9,     0,     0,     0,     0,   467,     0,
     320,    25,    26,     0,     0,     0,     0,    27,    28,     0,
      30,     0,     0,     0,    12,     0,     0,     0,     0,    25,
      26,     0,     0,    35,    36,    27,    28,     0,    30,     0,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,    35,    36,     0,     0,    25,    26,     0,     0,     0,
       0,    27,    28,     0,    30,    12,     5,     6,     7,     8,
       9,     0,     0,     0,     0,     0,     0,    35,    36,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     9,     0,
       0,    12,     0,     0,     0,     0,    25,    26,     0,     0,
       0,     0,    27,    28,     0,    30,     0,     0,     0,    12,
       0,     0,     0,     0,     0,     0,     0,     0,    35,    36,
       0,     0,   398,    26,     0,     0,     0,     0,    27,    28,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,     0,    35,    36,    27,    28,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,    36
};

static const yytype_int16 yycheck[] =
{
      10,     3,    12,    17,    27,    19,    20,   139,    34,   112,
     193,    20,   115,    23,    40,   191,    26,    27,    28,    30,
     210,     5,    32,    33,    83,    11,   202,     5,    38,    39,
       8,   304,   219,    13,    12,    34,   223,     5,    12,    34,
     227,    42,    14,    15,    16,    17,    18,    19,    20,    54,
      22,     5,    27,    40,     8,    48,    29,   233,    33,     0,
      32,    54,     5,    38,    34,    70,    40,    61,    48,    70,
      65,    34,    40,     3,     4,     5,     6,     7,    65,    78,
      67,    65,    76,    56,    67,    48,    42,    65,   361,    45,
      62,    65,    66,    25,     5,   271,    26,    80,    28,   109,
      30,    48,     5,    35,   291,    77,    36,    54,   167,    39,
       5,    65,    84,   300,   124,    48,    46,   103,   431,    49,
      50,    54,   435,    70,   437,    55,     6,     7,   441,    59,
      60,   142,    34,    25,   310,    65,    66,    67,    68,   153,
      24,    71,    72,    73,   331,    75,   112,   460,    40,   115,
     463,    81,    82,    29,   120,    23,    28,    87,   184,    81,
     126,   184,   338,    35,   351,    31,   192,     8,     9,    10,
      11,   197,    45,    35,    47,   185,    34,    35,    41,    42,
     190,    56,    65,    34,    55,    35,   196,   363,    34,   292,
      78,   367,   251,    74,    48,    48,   206,    79,    35,    34,
     214,    25,    35,   213,   394,   214,    13,    68,   222,   385,
       5,    56,    34,   222,    78,   398,    35,    55,   228,    78,
      40,   235,   354,   355,    35,     5,   329,     5,   238,     5,
     256,    13,    35,   256,    35,   411,    57,     5,   414,    78,
     416,    35,    78,    34,   254,     5,    78,     5,    25,    35,
      78,   427,    35,    34,   264,   442,    56,    56,   272,    67,
      35,    34,    78,    42,    34,    79,    40,    34,    34,   445,
      35,     5,    78,     3,     4,     5,     6,     7,   454,   455,
     290,    35,    35,    12,   294,    35,    34,    34,    47,   299,
      34,    40,    35,    78,    34,   305,    42,     5,    28,   431,
      35,   311,   304,   435,    35,   437,   316,    34,    70,   441,
      34,    34,     3,     4,     5,     6,     7,   327,   328,    34,
      34,     3,     4,     5,     6,     7,   336,    34,   460,    59,
      60,   463,    34,    43,    35,    65,    66,    28,    68,   253,
       3,     4,     5,     6,     7,     8,    28,   357,    43,    12,
     237,    81,    82,   303,   390,   256,   203,    87,   277,   361,
     311,   307,   154,   156,   162,    28,   376,   155,   140,    60,
     380,   418,   159,   376,    65,    66,    43,    59,    60,   452,
     461,   391,   120,    65,    66,   395,    68,   458,    -1,    -1,
      81,    82,    -1,    -1,    76,    -1,    59,    60,   408,    81,
      82,    -1,    65,    66,    -1,    68,    -1,    -1,   418,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    81,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,   449,
      30,    -1,   452,    33,    -1,    -1,    36,   457,    38,    39,
      -1,    -1,    -1,    43,    -1,    -1,    46,   467,    48,    49,
      50,    -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    -1,
      -1,    71,    72,    73,    -1,    75,     3,     4,     5,     6,
       7,    81,    82,    83,    -1,    85,    86,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    -1,    30,    -1,    -1,    33,    -1,    -1,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    48,    49,    50,    -1,    -1,    -1,    54,    55,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    65,    66,
      -1,    68,    -1,    -1,    71,    72,    73,    -1,    75,     3,
       4,     5,     6,     7,    81,    82,    83,    -1,    85,    86,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    30,    -1,    -1,    33,
      -1,    -1,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    48,    49,    50,    -1,    -1,    -1,
      54,    55,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      -1,    65,    66,    -1,    68,    -1,    -1,    71,    72,    73,
      -1,    75,     3,     4,     5,     6,     7,    81,    82,    83,
      -1,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    -1,    30,
      -1,    -1,    44,    -1,    -1,    36,    -1,    -1,    39,    51,
      52,    53,    -1,    -1,    56,    46,    58,    -1,    49,    50,
      -1,    63,    64,    -1,    55,    -1,    68,    69,    59,    60,
      -1,    -1,    -1,    -1,    65,    66,    67,    68,    -1,    -1,
      71,    72,    73,    -1,    75,     3,     4,     5,     6,     7,
      81,    82,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    28,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,
      40,    59,    60,    -1,    -1,    -1,    -1,    65,    66,    -1,
      68,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    59,
      60,    -1,    -1,    81,    82,    65,    66,    -1,    68,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    -1,    -1,    59,    60,    -1,    -1,    -1,
      -1,    65,    66,    -1,    68,    28,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    -1,    65,    66,    -1,    68,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    65,    66,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    81,    82,    65,    66,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    89,    90,    92,     0,     3,     4,     5,     6,     7,
      26,    27,    28,    30,    33,    36,    38,    39,    43,    46,
      48,    49,    50,    54,    55,    59,    60,    65,    66,    67,
      68,    71,    72,    73,    75,    81,    82,    83,    85,    86,
      87,    91,    93,    95,    96,    97,   108,   109,   111,   112,
     116,   121,   122,   123,   124,   125,   126,   127,   128,   131,
     132,   133,   142,   144,   145,   146,   147,   149,   150,   151,
     155,   167,   169,   170,   171,   172,   174,   175,   176,   177,
     179,   181,   183,   184,   185,   187,   192,   195,   205,   210,
     226,   167,     5,   141,   167,   225,     5,     5,   174,   203,
     174,   203,   134,   227,     5,   167,   137,   140,   141,    34,
      99,   101,   167,   191,   206,   167,   188,   189,   194,   226,
     167,   190,   193,   171,    76,   118,   167,   167,   205,    34,
     167,   157,   167,   205,    93,    97,   210,   110,   117,    54,
      70,   168,    24,    44,    51,    52,    53,    56,    58,    63,
      64,    68,    69,   173,    29,    31,    23,    61,    76,   178,
       6,     7,   180,     8,     9,    10,    11,   182,   183,   186,
      81,    14,    15,    16,    17,    18,    19,    20,    22,    32,
      62,    77,    84,   114,   115,    35,    40,    65,    67,    28,
      35,    34,    65,    65,    98,   204,    56,    56,    55,    40,
     141,   143,    34,    35,    25,   167,    34,     5,     8,    12,
      65,   103,   105,    34,    48,   117,   209,   223,    74,   117,
     223,    78,    48,   117,   220,    79,   167,   117,    35,   130,
      67,   109,   161,    34,   156,    25,    67,    80,    35,   169,
     170,   171,    68,    56,   174,   175,   176,   177,   179,   181,
     183,    12,    40,    65,    66,   196,    13,   113,   205,   226,
     167,     5,    94,   212,   213,   167,   161,   205,   211,    78,
      99,    34,    35,   167,   205,     5,     8,    65,   135,   136,
     138,    35,   161,   137,     5,   167,     5,     5,   105,   106,
      13,   100,   167,   203,    35,   104,   104,   203,   104,    35,
     119,   120,   104,   167,    57,    45,    47,   152,   158,   161,
      34,    35,   174,    67,   111,   167,    42,   183,     5,    94,
      40,   167,   197,   199,   200,   113,    78,     8,    12,   167,
     216,   217,    78,    78,   161,   174,    35,   129,    34,    25,
     138,   139,     5,   148,    35,   102,   107,    78,   167,    35,
     104,   207,   208,   223,    56,    56,   167,    35,   104,   129,
     108,   162,   167,    34,    42,   153,   158,    34,    42,   161,
     157,   167,    78,    40,    79,   198,    34,    67,   167,   167,
      13,   218,   223,    35,   104,    34,   167,   161,     5,    78,
      35,    41,    42,    12,    35,    35,   104,   169,    59,   163,
     165,   166,   169,   167,    37,   108,    25,    35,   159,   160,
     161,    34,    47,   154,    34,   161,    34,    40,    35,   167,
     200,   214,   167,   161,    42,   136,   167,    34,     5,   105,
     167,    54,   222,   223,   224,    34,    99,    54,   219,   220,
     221,    35,   164,   167,   161,    34,   161,   161,   199,    34,
     201,   202,    35,   215,    34,    34,   161,    34,   165,   165,
      34,   165,   165,    35,   104,   161,   167,    12,   217,   161,
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
#line 60 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
        // std::cout << "at beginning" << std::endl;
        // if ($1) { ($1)->eval()->print(); }
    }
#line 1913 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 67 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1919 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 70 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1925 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 71 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1931 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 75 "includes/parse.y" /* yacc.c:1646  */
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
#line 1946 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 85 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1952 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 104 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-3].identifier); }
#line 1958 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 123 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 1964 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 127 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-1].identifier); }
#line 1970 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 128 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 1976 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 135 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 1982 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 147 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1988 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 148 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 1994 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 152 "includes/parse.y" /* yacc.c:1646  */
    {
        // std::cout << "simple_stmt1" << std::endl;
        (yyval.node) = (yyvsp[-3].node);
    }
#line 2003 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 157 "includes/parse.y" /* yacc.c:1646  */
    {
        // std::cout << "simple_stmt2" << std::endl;
        (yyval.node) = (yyvsp[-2].node);
    }
#line 2012 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 167 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2018 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 169 "includes/parse.y" /* yacc.c:1646  */
    {
        //just print, no need to pass the node
        (yyval.node) = NULL;
    }
#line 2027 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 173 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2033 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 174 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2039 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 175 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2045 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 176 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2051 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 177 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2057 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 178 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2063 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 179 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2069 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 183 "includes/parse.y" /* yacc.c:1646  */
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
            case 0:
                std::cout << "augassign error" << std::endl;
            break;
        }
    }
#line 2110 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 220 "includes/parse.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].node)) {
            // std::cout << "expr_stmt2" << std::endl;
            (yyval.node) = new AsgBinaryNode((yyvsp[-1].node), (yyvsp[0].node));
            pool.add((yyval.node));

            tempcount--;
            if (tempcount) { //not only one EQUAL
                tempcount--;
                Node* equ;
                for( ; tempcount>=0; tempcount--) {
                    equ = new AsgBinaryNode(temp[tempcount], (yyvsp[0].node));
                    pool.add(equ);
                }
            }
            if(tempcount < 0) {
                tempcount = 0;
            }
        }
        else {
            (yyval.node) = (yyvsp[-1].node);
            ((yyvsp[-1].node))->eval()->print();
        }
    }
#line 2139 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 247 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
        // std::cout << "pick_yield_expr_testlist1" << std::endl;
    }
#line 2148 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 252 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
        // std::cout << "pick_yield_expr_testlist2" << std::endl;
    }
#line 2157 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 259 "includes/parse.y" /* yacc.c:1646  */
    {
        // if ($1 == NULL)  //means this is the bottom of the equal tree
        (yyval.node) = (yyvsp[0].node);
        temp[tempcount++] = (yyvsp[0].node);
        // std::cout << "star_EQUAL1" << std::endl;
    }
#line 2168 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 266 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = NULL;
        // std::cout << "star_EQUAL2" << std::endl;
    }
#line 2177 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 272 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2183 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 273 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2189 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 274 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2195 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 275 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2201 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 276 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2207 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 277 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2213 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 278 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2219 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 279 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2225 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 280 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2231 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 281 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2237 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 282 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2243 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 283 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2249 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 287 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
        // std::cout << "print_stmt1" << std::endl;
    }
#line 2258 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 292 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = NULL;
        // std::cout << "print_stmt2" << std::endl;
    }
#line 2267 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 299 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-2].node); //should always be NULL
        if ((yyvsp[0].node)) {
            ((yyvsp[0].node))->eval()->print();
        }
    }
#line 2278 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 305 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2284 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 309 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-2].node);
        if ((yyvsp[-2].node)) {
            ((yyvsp[-2].node))->eval()->print();
        }
        // std::cout << "opt_test1" << std::endl;
    }
#line 2296 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 316 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2302 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 384 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-2].identifier); delete [] (yyvsp[0].identifier); }
#line 2308 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 385 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2314 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 388 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2320 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 404 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2326 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 405 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2332 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 408 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-1].identifier); }
#line 2338 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 411 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2344 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 512 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2350 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 514 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = NULL;
        std::cout << "impossible lambdef" << std::endl;
    }
#line 2359 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 524 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2365 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 525 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2371 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 528 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2377 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 529 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2383 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 532 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2389 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 533 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2395 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 536 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2401 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 537 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2407 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 554 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
        //std::cout << "expr1" << std::endl;
    }
#line 2416 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 559 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-2].node);
        //std::cout << "expr2" << std::endl;
    }
#line 2425 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 565 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2431 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 566 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2437 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 569 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2443 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 570 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2449 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 573 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2455 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 574 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2461 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 581 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2467 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 583 "includes/parse.y" /* yacc.c:1646  */
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
#line 2484 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 598 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2490 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 600 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2496 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 604 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
        //std::cout << "term1" << std::endl;
    }
#line 2505 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 609 "includes/parse.y" /* yacc.c:1646  */
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
#line 2531 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 633 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2537 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 635 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2543 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 637 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2549 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 639 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2555 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 643 "includes/parse.y" /* yacc.c:1646  */
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
#line 2572 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 656 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
        //std::cout << "factor2" << std::endl;
    }
#line 2581 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 662 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2587 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 663 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2593 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 664 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2599 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 668 "includes/parse.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-1].op) == OP_DOUBLESTAR) {
            (yyval.node) = new ExpBinaryNode((yyvsp[-3].node), (yyvsp[0].node));
            pool.add((yyval.node));
        }
        else {
            std::cout << "DOUBLESTAR wrong" << std::endl;
        }
    }
#line 2613 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 678 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-1].node);
        //std::cout << "power2" << std::endl;
    }
#line 2622 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 689 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-1].node);
        // std::cout << "atom1" << std::endl;
        if (!(yyvsp[-1].node)) { std::cout << "empty parens" << std::endl; }
    }
#line 2632 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 694 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible atom2" << std::endl; }
#line 2638 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 695 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible atom3" << std::endl; }
#line 2644 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 696 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible atom4" << std::endl; }
#line 2650 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 698 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = new IdentNode((yyvsp[0].identifier));
        delete [] (yyvsp[0].identifier);
        pool.add((yyval.node));
    }
#line 2660 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 704 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = new IntLiteral((yyvsp[0].intNumber));
        pool.add((yyval.node));
    }
#line 2669 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 709 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = new FloatLiteral((yyvsp[0].fltNumber));
        pool.add((yyval.node));
    }
#line 2678 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 713 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible atom8" << std::endl; }
#line 2684 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 716 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2690 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 717 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2696 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 720 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2702 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 721 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2708 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 740 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2714 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 741 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2720 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 750 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2726 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 787 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-2].node);
        //std::cout << "testlist1" << std::endl;
    }
#line 2735 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 792 "includes/parse.y" /* yacc.c:1646  */
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
#line 2752 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 822 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-5].identifier); }
#line 2758 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 823 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-2].identifier); }
#line 2764 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 886 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2770 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 887 "includes/parse.y" /* yacc.c:1646  */
    { std::cout << "impossible YIELD" << std::endl; }
#line 2776 "parse.tab.c" /* yacc.c:1646  */
    break;


#line 2780 "parse.tab.c" /* yacc.c:1646  */
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
#line 894 "includes/parse.y" /* yacc.c:1906  */


#include <stdio.h>
void yyerror (const char *s)
{
    if(yylloc.first_line > 0)	{
        fprintf (stderr, "%d.%d-%d.%d:", yylloc.first_line, yylloc.first_column,
	                                     yylloc.last_line,  yylloc.last_column);
    }
    fprintf(stderr, " %s with [%s]\n", s, yytext);
}
