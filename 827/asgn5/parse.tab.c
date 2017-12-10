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
    //SyntaxScope& scope = SyntaxScope::getInstance();
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
#define YYLAST   888

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
       0,    79,    79,    87,    90,    91,   117,   121,   124,   125,
     128,   129,   132,   133,   136,   137,   140,   150,   151,   154,
     155,   158,   159,   162,   163,   166,   167,   170,   171,   174,
     175,   178,   179,   182,   183,   186,   187,   190,   191,   198,
     203,   211,   212,   215,   217,   221,   222,   223,   228,   229,
     230,   231,   234,   271,   288,   293,   300,   312,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     333,   339,   346,   353,   356,   364,   367,   368,   371,   372,
     375,   378,   381,   382,   383,   384,   385,   388,   391,   394,
     399,   402,   405,   406,   409,   410,   413,   414,   417,   418,
     421,   424,   427,   428,   431,   432,   433,   436,   437,   440,
     441,   444,   445,   448,   449,   452,   453,   456,   457,   460,
     463,   464,   467,   468,   471,   472,   475,   476,   477,   478,
     479,   480,   481,   482,   485,   490,   497,   498,   501,   502,
     505,   506,   509,   510,   513,   514,   517,   518,   521,   522,
     525,   528,   529,   532,   533,   536,   537,   540,   541,   544,
     545,   548,   554,   562,   567,   575,   576,   579,   580,   583,
     584,   587,   588,   591,   592,   599,   601,   604,   605,   608,
     609,   612,   613,   616,   617,   652,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   665,   670,   677,   678,
     681,   682,   685,   686,   689,   690,   693,   694,   709,   710,
     713,   718,   742,   744,   746,   748,   752,   765,   772,   773,
     774,   777,   787,   805,   806,   809,   815,   817,   819,   821,
     827,   832,   837,   840,   841,   844,   845,   848,   849,   852,
     853,   856,   857,   860,   861,   864,   865,   868,   869,   872,
     878,   879,   882,   883,   886,   887,   890,   891,   892,   895,
     896,   899,   900,   903,   904,   907,   908,   911,   912,   915,
     920,   935,   936,   939,   940,   943,   944,   947,   948,   951,
     952,   955,   956,   959,   965,   966,   969,   970,   973,   974,
     977,   978,   979,   982,   983,   986,   987,   990,   991,   994,
     995,   998,   999,  1002,  1003,  1006,  1007,  1010,  1011,  1014,
    1015,  1018,  1019,  1022,  1023
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

#define YYPACT_NINF -291

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-291)))

#define YYTABLE_NINF -261

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -291,    87,  -291,   383,  -291,  -291,  -291,  -291,  -291,  -291,
     624,    96,   624,  -291,   111,  -291,   130,   806,  -291,   806,
     806,  -291,   138,   624,    96,   106,   624,    40,   624,  -291,
     798,  -291,   330,   624,   624,  -291,  -291,   110,   624,   624,
     624,  -291,  -291,    93,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,    27,   133,  -291,   289,   125,   128,   140,    54,
      62,   168,  -291,   806,  -291,  -291,    91,  -291,    35,  -291,
    -291,   142,  -291,    15,  -291,    99,     1,   108,   125,  -291,
       7,   126,   132,    32,  -291,   144,  -291,   147,    29,   624,
     153,    22,    70,   120,  -291,   145,  -291,   117,  -291,  -291,
     146,   118,  -291,  -291,   624,  -291,  -291,   160,  -291,   602,
     162,  -291,   175,  -291,  -291,  -291,  -291,    56,   166,   798,
     798,  -291,   798,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,   141,   152,   806,   806,   806,   806,  -291,  -291,   806,
    -291,  -291,   806,  -291,  -291,  -291,  -291,   806,  -291,    19,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,  -291,   199,    40,   624,   209,   139,  -291,  -291,
     624,   602,   624,   149,   176,   178,   624,   624,    30,   167,
     174,   183,   602,    96,   224,  -291,   624,  -291,   226,   227,
      16,  -291,   221,   624,   806,   195,  -291,  -291,  -291,   195,
    -291,  -291,   806,   195,  -291,  -291,   196,   195,   624,  -291,
     179,  -291,   104,   602,    36,   806,  -291,   675,   624,    10,
     133,  -291,  -291,  -291,   125,   128,   140,    54,    62,   168,
    -291,   806,   236,   139,   718,  -291,    40,  -291,  -291,  -291,
    -291,  -291,   164,  -291,    86,  -291,  -291,  -291,   165,  -291,
     169,   602,   806,   204,   206,   217,  -291,   244,  -291,  -291,
    -291,   245,  -291,  -291,  -291,  -291,   211,  -291,  -291,   181,
     624,   212,   145,   197,   624,  -291,  -291,   198,  -291,   624,
     219,  -291,  -291,   204,   529,   624,   228,   109,   230,   218,
     602,   624,   125,  -291,  -291,  -291,   624,  -291,  -291,   189,
     225,   232,   194,  -291,   234,  -291,   207,   624,   624,    26,
    -291,   235,   237,  -291,  -291,   125,   624,  -291,   602,   276,
     205,   241,  -291,   134,   273,  -291,   246,  -291,  -291,    -7,
    -291,   247,  -291,  -291,   798,   772,  -291,   624,  -291,  -291,
    -291,   456,    31,   602,   250,   239,   253,   602,   254,  -291,
    -291,  -291,  -291,   240,  -291,   255,   624,  -291,  -291,  -291,
     624,  -291,  -291,   222,  -291,   602,  -291,   249,  -291,  -291,
     244,   624,   267,   303,    16,   624,  -291,    58,   279,    72,
     275,  -291,   252,  -291,  -291,  -291,  -291,  -291,   624,  -291,
    -291,   602,   283,  -291,   602,  -291,   602,  -291,   258,  -291,
     290,   288,  -291,  -291,   292,  -291,   298,   602,  -291,  -291,
     301,   772,  -291,  -291,  -291,   772,   302,   772,  -291,  -291,
    -291,   772,   305,  -291,  -291,   602,  -291,  -291,  -291,   624,
    -291,  -291,   762,  -291,   602,   602,  -291,   624,    85,  -291,
     772,    72,  -291,   772,  -291,  -291,  -291,   624,  -291,  -291,
    -291,  -291,  -291,  -291,  -291,  -291,  -291
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
       0,   173,     0,   185,   186,   187,   188,   189,   191,   190,
     192,   194,     0,     0,     0,     0,     0,   204,   205,     0,
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
    -291,  -291,  -291,  -291,  -291,   300,    98,  -291,  -291,   306,
    -291,  -183,  -291,  -291,  -291,  -291,  -187,  -190,  -291,  -291,
    -256,    -2,  -291,   107,  -291,    97,  -291,  -291,  -291,   -56,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,    49,  -291,  -291,  -291,  -291,  -291,  -291,   -36,   154,
      78,  -291,  -291,    14,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,    45,
      53,  -291,  -291,  -176,  -291,  -291,  -291,  -290,  -291,   -10,
    -291,  -132,   223,   -11,  -291,  -291,   -14,   208,   210,   213,
    -291,   202,  -291,   214,  -291,   -59,  -291,  -291,  -291,  -291,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,   -51,    -8,  -291,  -291,    -9,  -291,   -26,  -291,  -291,
    -291,  -291,   328,  -291,  -291,  -291,  -291,  -291,  -291,   -80,
    -291,   -88,   257,  -291,   -84,  -103,  -291,  -291,   -23,  -291
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
     208,   251,   296,   -29,   209,   275,   298,    92,   276,   380,
     302,   191,   154,     5,     6,     7,     8,     9,   360,   171,
     172,   173,   174,   175,   176,   177,   215,   309,   316,   219,
     204,   186,   406,   178,   223,   252,   196,   192,   160,   161,
     227,   -29,   407,   179,    12,   186,   310,   311,   199,   214,
     140,   187,   210,   188,   139,   253,   254,     4,   210,     5,
       6,     7,     8,     9,   327,   334,   277,   140,   328,   205,
     180,    92,    25,    26,   350,   405,    27,    28,   250,    30,
     213,   214,   181,   358,   226,   431,    96,   200,   157,   182,
      12,    35,    36,   214,   236,   222,    11,    40,   140,   437,
     158,   241,    14,   189,   369,    97,   237,    16,   214,   244,
     190,   458,   431,   104,   384,   459,   109,   461,    25,    26,
     129,   462,    27,    28,   305,    30,   306,   364,   258,   305,
     154,   259,   387,   142,   396,   155,   267,    35,    36,   156,
     473,   274,   170,   475,   193,   260,   163,   164,   165,   166,
     265,   391,   392,   185,   202,   197,   273,   410,   203,   353,
     198,   415,   317,   206,   218,   221,   285,   225,   214,   222,
      98,   228,   233,   292,   429,   293,   235,   238,    98,   423,
     242,   243,   256,   297,   261,   436,   271,   -11,   303,   272,
     186,   312,   397,   402,   281,  -103,   382,   269,   315,   284,
     258,   286,   287,   259,   290,   444,   294,   299,   446,   304,
     447,   318,   326,   332,   321,   336,   338,   333,   339,   275,
     342,   456,   344,   349,   329,   464,   354,   355,   335,   347,
     357,     5,     6,     7,     8,     9,   368,   372,   363,   465,
     367,   373,  -259,   374,   376,   377,   383,   385,   469,   470,
     348,   388,   390,   389,   315,   393,   417,   394,   395,   356,
     411,   412,    12,   414,   416,   362,   418,   424,  -260,   402,
     -29,   132,    47,   402,   320,   402,   371,   427,   428,   402,
     143,   144,   145,   146,   147,   148,   441,   378,   379,   435,
      25,    26,   140,   445,    27,    28,   386,    30,   402,   452,
     449,   402,   454,     5,     6,     7,     8,     9,   455,    35,
      36,   457,   460,   134,   314,   149,   463,   403,   150,   135,
     151,   319,   359,   325,   425,   340,   370,   283,   152,    47,
     366,   248,   245,   240,    12,   246,   419,   448,   420,   247,
     422,   136,   468,   474,   472,     0,   249,   224,     0,     0,
       0,   426,     0,     0,     0,   430,     5,     6,     7,     8,
       9,     0,    25,    26,     0,     0,    27,    28,   443,    30,
       0,     0,     0,     0,     0,     0,   124,     0,   321,     0,
       0,    35,    36,     0,     0,    10,    11,    12,     0,    13,
       0,     0,    14,     0,     0,    15,     0,    16,    17,     0,
       0,     0,    18,     0,    19,     0,    20,    21,    22,   466,
      23,    24,   329,     0,     0,    25,    26,   471,     0,    27,
      28,    29,    30,     0,    31,    32,    33,   476,    34,     5,
       6,     7,     8,     9,    35,    36,    37,     0,    38,    39,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
      12,     0,    13,     0,     0,    14,     0,     0,    15,   404,
      16,    17,     0,     0,     0,     0,     0,    19,     0,    20,
      21,    22,     0,    23,    24,     0,     0,     0,    25,    26,
       0,     0,    27,    28,     0,    30,     0,    31,    32,    33,
       0,    34,     5,     6,     7,     8,     9,    35,    36,    37,
       0,    38,    39,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,    12,     0,    13,     0,     0,    14,     0,
       0,    15,     0,    16,    17,     0,     0,     0,     0,     0,
      19,     0,    20,    21,    22,     0,    23,    24,     0,     0,
       0,    25,    26,     0,     0,    27,    28,     0,    30,     0,
      31,    32,    33,     0,    34,     5,     6,     7,     8,     9,
      35,    36,    37,     0,    38,    39,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,     0,     0,    10,     0,    12,     0,    13,     0,
       0,     0,     0,     0,    15,     0,     0,    17,     0,     0,
       0,     0,     0,    19,     0,     0,    21,    22,    12,     0,
      24,     0,     0,     0,    25,    26,     0,     0,    27,    28,
     230,    30,     0,    31,    32,    33,     0,    34,     5,     6,
       7,     8,     9,    35,    36,     0,    25,    26,     0,    40,
      27,    28,     0,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    35,    36,    10,     0,    12,
       0,    13,     0,     0,     0,     0,     0,    15,     0,     0,
      17,     5,     6,     7,     8,     9,    19,     0,     0,    21,
      22,     0,     0,    24,     0,     0,     0,    25,    26,     0,
       0,    27,    28,   313,    30,     0,    31,    32,    33,     0,
      34,     0,    12,     0,     0,     0,    35,    36,     0,     0,
       0,     0,    40,     0,   320,     5,     6,     7,     8,     9,
       0,     0,     0,     0,   467,     5,     6,     7,     8,     9,
      25,    26,     0,     0,    27,    28,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,    12,     0,     0,    35,
      36,     5,     6,     7,     8,     9,    12,     0,     0,     5,
       6,     7,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    26,     0,     0,    27,    28,
       0,    30,    12,     0,   398,    26,     0,     0,    27,    28,
      12,    30,     0,    35,    36,     0,     0,     0,     0,     0,
       0,     0,     0,    35,    36,     0,     0,     0,     0,     0,
       0,    26,     0,     0,    27,    28,     0,    30,     0,    26,
       0,     0,    27,    28,     0,     0,     0,     0,     0,    35,
      36,     0,     0,     0,     0,     0,     0,    35,    36
};

static const yytype_int16 yycheck[] =
{
      10,     3,    12,    17,    27,    19,    20,   139,    34,   112,
     193,    20,   115,    23,    40,   191,    26,    27,    28,    30,
     210,     5,    32,    33,    83,    11,   202,     5,    38,    39,
       8,    12,   219,    40,    12,     5,   223,     5,     8,    13,
     227,    40,    35,     3,     4,     5,     6,     7,   304,    14,
      15,    16,    17,    18,    19,    20,   112,   233,    48,   115,
      31,    46,    31,    28,   120,    46,    59,    66,     6,     7,
     126,    78,    41,    38,    34,    46,    40,    41,    46,    53,
      70,    66,    66,    68,    57,    66,    67,     0,    66,     3,
       4,     5,     6,     7,     8,   271,    66,    70,    12,   109,
      65,     5,    62,    63,   291,   361,    66,    67,   167,    69,
      40,    53,    77,   300,   124,    57,     5,   103,    64,    84,
      34,    81,    82,    53,    68,    53,    33,    87,    70,    57,
      76,   142,    39,    34,   310,     5,    80,    44,    53,   153,
      41,   431,    57,     5,   331,   435,    40,   437,    62,    63,
      40,   441,    66,    67,    50,    69,    52,    48,   184,    50,
      35,   184,   338,    30,   351,    37,   192,    81,    82,    29,
     460,   197,    81,   463,    66,   185,     8,     9,    10,    11,
     190,    47,    48,    41,    40,    59,   196,   363,    41,   292,
      58,   367,   251,    40,    74,    78,   206,    79,    53,    53,
     214,    41,    40,   213,   394,   214,    31,    41,   222,   385,
      69,    59,    13,   222,     5,   398,    40,    78,   228,    41,
      46,   235,   354,   355,    41,    58,   329,    78,   238,     5,
     256,     5,     5,   256,    13,   411,    41,    41,   414,    60,
     416,     5,    78,    78,   254,    41,    40,    78,    31,     5,
       5,   427,    41,    41,   264,   442,    59,    59,   272,    78,
      41,     3,     4,     5,     6,     7,    48,    78,    40,   445,
      40,    46,    40,    79,    40,    68,    41,    40,   454,   455,
     290,     5,    41,    78,   294,    12,    46,    41,    41,   299,
      40,    52,    34,    40,    40,   305,    41,    48,    40,   431,
      78,   311,   304,   435,    46,   437,   316,    40,     5,   441,
      21,    22,    23,    24,    25,    26,    41,   327,   328,    40,
      62,    63,    70,    40,    66,    67,   336,    69,   460,    41,
      40,   463,    40,     3,     4,     5,     6,     7,    40,    81,
      82,    40,    40,    43,   237,    56,    41,   357,    59,    43,
      61,   253,   303,   256,   390,   277,   311,   203,    69,   361,
     307,   159,   154,   140,    34,   155,   376,   418,   376,   156,
     380,    43,   452,   461,   458,    -1,   162,   120,    -1,    -1,
      -1,   391,    -1,    -1,    -1,   395,     3,     4,     5,     6,
       7,    -1,    62,    63,    -1,    -1,    66,    67,   408,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,   418,    -1,
      -1,    81,    82,    -1,    -1,    32,    33,    34,    -1,    36,
      -1,    -1,    39,    -1,    -1,    42,    -1,    44,    45,    -1,
      -1,    -1,    49,    -1,    51,    -1,    53,    54,    55,   449,
      57,    58,   452,    -1,    -1,    62,    63,   457,    -1,    66,
      67,    68,    69,    -1,    71,    72,    73,   467,    75,     3,
       4,     5,     6,     7,    81,    82,    83,    -1,    85,    86,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    -1,    36,    -1,    -1,    39,    -1,    -1,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,
      54,    55,    -1,    57,    58,    -1,    -1,    -1,    62,    63,
      -1,    -1,    66,    67,    -1,    69,    -1,    71,    72,    73,
      -1,    75,     3,     4,     5,     6,     7,    81,    82,    83,
      -1,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    -1,    36,    -1,    -1,    39,    -1,
      -1,    42,    -1,    44,    45,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    53,    54,    55,    -1,    57,    58,    -1,    -1,
      -1,    62,    63,    -1,    -1,    66,    67,    -1,    69,    -1,
      71,    72,    73,    -1,    75,     3,     4,     5,     6,     7,
      81,    82,    83,    -1,    85,    86,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    32,    -1,    34,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    54,    55,    34,    -1,
      58,    -1,    -1,    -1,    62,    63,    -1,    -1,    66,    67,
      68,    69,    -1,    71,    72,    73,    -1,    75,     3,     4,
       5,     6,     7,    81,    82,    -1,    62,    63,    -1,    87,
      66,    67,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    32,    -1,    34,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      45,     3,     4,     5,     6,     7,    51,    -1,    -1,    54,
      55,    -1,    -1,    58,    -1,    -1,    -1,    62,    63,    -1,
      -1,    66,    67,    68,    69,    -1,    71,    72,    73,    -1,
      75,    -1,    34,    -1,    -1,    -1,    81,    82,    -1,    -1,
      -1,    -1,    87,    -1,    46,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    12,     3,     4,     5,     6,     7,
      62,    63,    -1,    -1,    66,    67,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    81,
      82,     3,     4,     5,     6,     7,    34,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    66,    67,
      -1,    69,    34,    -1,    62,    63,    -1,    -1,    66,    67,
      34,    69,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    66,    67,    -1,    69,    -1,    63,
      -1,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    89,    90,    92,     0,     3,     4,     5,     6,     7,
      32,    33,    34,    36,    39,    42,    44,    45,    49,    51,
      53,    54,    55,    57,    58,    62,    63,    66,    67,    68,
      69,    71,    72,    73,    75,    81,    82,    83,    85,    86,
      87,    91,    93,    95,    96,    97,   108,   109,   111,   112,
     116,   121,   122,   123,   124,   125,   126,   127,   128,   131,
     132,   133,   142,   144,   145,   146,   147,   149,   150,   151,
     155,   167,   169,   170,   171,   172,   174,   175,   176,   177,
     179,   181,   183,   184,   185,   187,   192,   195,   205,   210,
     226,   167,     5,   141,   167,   225,     5,     5,   174,   203,
     174,   203,   134,   227,     5,   167,   137,   140,   141,    40,
      99,   101,   167,   191,   206,   167,   188,   189,   194,   226,
     167,   190,   193,   171,    76,   118,   167,   167,   205,    40,
     167,   157,   167,   205,    93,    97,   210,   110,   117,    57,
      70,   168,    30,    21,    22,    23,    24,    25,    26,    56,
      59,    61,    69,   173,    35,    37,    29,    64,    76,   178,
       6,     7,   180,     8,     9,    10,    11,   182,   183,   186,
      81,    14,    15,    16,    17,    18,    19,    20,    28,    38,
      65,    77,    84,   114,   115,    41,    46,    66,    68,    34,
      41,    40,    66,    66,    98,   204,    59,    59,    58,    46,
     141,   143,    40,    41,    31,   167,    40,     5,     8,    12,
      66,   103,   105,    40,    53,   117,   209,   223,    74,   117,
     223,    78,    53,   117,   220,    79,   167,   117,    41,   130,
      68,   109,   161,    40,   156,    31,    68,    80,    41,   169,
     170,   171,    69,    59,   174,   175,   176,   177,   179,   181,
     183,    12,    46,    66,    67,   196,    13,   113,   205,   226,
     167,     5,    94,   212,   213,   167,   161,   205,   211,    78,
      99,    40,    41,   167,   205,     5,     8,    66,   135,   136,
     138,    41,   161,   137,     5,   167,     5,     5,   105,   106,
      13,   100,   167,   203,    41,   104,   104,   203,   104,    41,
     119,   120,   104,   167,    60,    50,    52,   152,   158,   161,
      40,    41,   174,    68,   111,   167,    48,   183,     5,    94,
      46,   167,   197,   199,   200,   113,    78,     8,    12,   167,
     216,   217,    78,    78,   161,   174,    41,   129,    40,    31,
     138,   139,     5,   148,    41,   102,   107,    78,   167,    41,
     104,   207,   208,   223,    59,    59,   167,    41,   104,   129,
     108,   162,   167,    40,    48,   153,   158,    40,    48,   161,
     157,   167,    78,    46,    79,   198,    40,    68,   167,   167,
      13,   218,   223,    41,   104,    40,   167,   161,     5,    78,
      41,    47,    48,    12,    41,    41,   104,   169,    62,   163,
     165,   166,   169,   167,    43,   108,    31,    41,   159,   160,
     161,    40,    52,   154,    40,   161,    40,    46,    41,   167,
     200,   214,   167,   161,    48,   136,   167,    40,     5,   105,
     167,    57,   222,   223,   224,    40,    99,    57,   219,   220,
     221,    41,   164,   167,   161,    40,   161,   161,   199,    40,
     201,   202,    41,   215,    40,    40,   161,    40,   165,   165,
      40,   165,   165,    41,   104,   161,   167,    12,   217,   161,
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
#line 80 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
        // std::cout << "at beginning" << std::endl;
        // if ($1) { ($1)->eval()->print(); }
    }
#line 1910 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 87 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1916 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 90 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1922 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 92 "includes/parse.y" /* yacc.c:1646  */
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
#line 1950 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 118 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1958 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 121 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1964 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 128 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 1970 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 129 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 1976 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 141 "includes/parse.y" /* yacc.c:1646  */
    {
            // std::cout << "func define" << std::endl;
            (yyval.node) = new FuncNode((yyvsp[-3].identifier), (yyvsp[0].node));
            pool.add((yyval.node));

            delete [] (yyvsp[-3].identifier);
        }
#line 1988 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 166 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 1994 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 170 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-1].identifier); }
#line 2000 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 171 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2006 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 178 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2012 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 190 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2018 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 192 "includes/parse.y" /* yacc.c:1646  */
    {
            // std::cout << "stmt: compound_stmt" << std::endl;
            (yyval.node) = (yyvsp[0].node);
        }
#line 2027 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 199 "includes/parse.y" /* yacc.c:1646  */
    {
            // std::cout << "simple_stmt 1 impossible" << std::endl;
            (yyval.node) = (yyvsp[-3].node);
        }
#line 2036 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 204 "includes/parse.y" /* yacc.c:1646  */
    {
            // std::cout << "simple_stmt 2" << std::endl;
            (yyval.node) = (yyvsp[-2].node);
            // ($1)->eval()->print();
        }
#line 2046 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 216 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2052 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 218 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
        }
#line 2060 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 221 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2066 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 222 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2072 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 224 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            std::cout << "flow(return)" << std::endl;
        }
#line 2081 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 228 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2087 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 229 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2093 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 230 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2099 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 231 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible" << std::endl; }
#line 2105 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 235 "includes/parse.y" /* yacc.c:1646  */
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
#line 2146 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 272 "includes/parse.y" /* yacc.c:1646  */
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
#line 2165 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 289 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            // std::cout << "pick_yield_expr_testlist1" << std::endl;
        }
#line 2174 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 294 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            // std::cout << "pick_yield_expr_testlist2" << std::endl;
        }
#line 2183 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 301 "includes/parse.y" /* yacc.c:1646  */
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
#line 2199 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 313 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = nullptr;
            // std::cout << "star_EQUAL2" << std::endl;
        }
#line 2208 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 319 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2214 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 320 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2220 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 321 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2226 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 322 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2232 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 323 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2238 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 324 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2244 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 325 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2250 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 326 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2256 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 327 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2262 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 328 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2268 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 329 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2274 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 330 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2280 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 334 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = new PrintNode((yyvsp[0].node));
            pool.add((yyval.node));
            // std::cout << "print_stmt1" << std::endl;
        }
#line 2290 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 340 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = NULL;
            // std::cout << "print_stmt2" << std::endl;
        }
#line 2299 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 347 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-2].node); //should always be NULL
            // if ($3) {
            //     ($3)->eval()->print();
            // }
        }
#line 2310 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 353 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2316 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 357 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-2].node);
            // if ($1) {
            //     ($1)->eval()->print();
            // }
            // std::cout << "opt_test1" << std::endl;
        }
#line 2328 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 364 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2334 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 381 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2340 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 382 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2346 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 383 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2352 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 384 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2358 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 385 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2364 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 395 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = new ReturnNode((yyvsp[0].node));
            pool.add((yyval.node));
        }
#line 2373 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 399 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2379 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 436 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-2].identifier); delete [] (yyvsp[0].identifier); }
#line 2385 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 437 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2391 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 440 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2397 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 456 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2403 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 457 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2409 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 460 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-1].identifier); }
#line 2415 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 463 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[0].identifier); }
#line 2421 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 475 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2427 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 476 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2433 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 477 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2439 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 478 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2445 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 479 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2451 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 480 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2457 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 481 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2463 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 482 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2469 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 486 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = new IfNode((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[0].node));
            pool.add((yyval.node));
        }
#line 2478 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 491 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = new IfNode((yyvsp[-3].node), (yyvsp[-1].node), nullptr);
            pool.add((yyval.node));
        }
#line 2487 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 549 "includes/parse.y" /* yacc.c:1646  */
    {
            //
            (yyval.node) = (yyvsp[0].node);
            // std::cout << "suite: simple_stmt" << std::endl;
        }
#line 2497 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 555 "includes/parse.y" /* yacc.c:1646  */
    {
            //
            (yyval.node) = (yyvsp[-1].node);
            // std::cout << "NEWLINE INDENT plus_stmt DEDENT" << std::endl;
        }
#line 2507 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 563 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].node);
            dynamic_cast<SuiteNode*>((yyval.node))->add((yyvsp[0].node));
        }
#line 2516 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 568 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = new SuiteNode();
            dynamic_cast<SuiteNode*>((yyval.node))->add((yyvsp[0].node));
            pool.add((yyval.node));
        }
#line 2526 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 591 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2532 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 593 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = NULL;
            std::cout << "impossible lambdef" << std::endl;
        }
#line 2541 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 600 "includes/parse.y" /* yacc.c:1646  */
    { std::cout << "test: opt_IF_ELSE" << std::endl; }
#line 2547 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 604 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2553 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 605 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2559 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 608 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2565 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 609 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2571 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 612 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2577 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 613 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2583 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 616 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2589 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 618 "includes/parse.y" /* yacc.c:1646  */
    {
            switch ((yyvsp[-1].op)) {
                case OP_LESS :
                    (yyval.node) = new LessBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                    pool.add((yyval.node));
                    break;
                case OP_GREATER :
                    (yyval.node) = new GreaterBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                    pool.add((yyval.node));
                    break;
                case OP_EQEQUAL :
                    (yyval.node) = new EqequalBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                    pool.add((yyval.node));
                    break;
                case OP_LESSEQUAL :
                    (yyval.node) = new LessEqualBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                    pool.add((yyval.node));
                    break;
                case OP_GREATEREQUAL :
                    (yyval.node) = new GreaterBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                    pool.add((yyval.node));
                    break;
                case OP_NOTEQUAL :
                    (yyval.node) = new NotEqualBinaryNode((yyvsp[-2].node), (yyvsp[0].node));
                    pool.add((yyval.node));
                    break;
                default :
                    throw std::string("comp_op error");
                    break;
            }
            (yyval.node) = (yyvsp[-2].node);
        }
#line 2626 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 652 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2632 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 653 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2638 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 654 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2644 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 655 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2650 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 656 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2656 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 657 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2662 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 658 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2668 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 659 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2674 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 660 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2680 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 661 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2686 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 662 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2692 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 666 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            //std::cout << "expr1" << std::endl;
        }
#line 2701 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 671 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-2].node);
            //std::cout << "expr2" << std::endl;
        }
#line 2710 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 677 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2716 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 678 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2722 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 681 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2728 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 682 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2734 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 685 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2740 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 686 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 2746 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 693 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2752 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 695 "includes/parse.y" /* yacc.c:1646  */
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
#line 2769 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 709 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2775 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 710 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2781 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 714 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
            //std::cout << "term1" << std::endl;
        }
#line 2790 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 719 "includes/parse.y" /* yacc.c:1646  */
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
#line 2816 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 743 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2822 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 745 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2828 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 747 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2834 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 749 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2840 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 753 "includes/parse.y" /* yacc.c:1646  */
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
#line 2857 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 766 "includes/parse.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
        //std::cout << "factor2" << std::endl;
    }
#line 2866 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 772 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2872 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 773 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = (yyvsp[0].op); }
#line 2878 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 774 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.op) = 0; }
#line 2884 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 778 "includes/parse.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-1].op) == OP_DOUBLESTAR) {
                (yyval.node) = new ExpBinaryNode((yyvsp[-3].node), (yyvsp[0].node));
                pool.add((yyval.node));
            }
            else {
                std::cout << "DOUBLESTAR wrong" << std::endl;
            }
        }
#line 2898 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 788 "includes/parse.y" /* yacc.c:1646  */
    {
            if((yyvsp[0].node)) {
                // std::cout << "call function" << std::endl;
                // std::string fname = reinterpret_cast<IdentNode*>($1)->getIdent();
                if (dynamic_cast<const IdentNode*>((yyvsp[-1].node))) {
                    std::string fname = dynamic_cast<const IdentNode*>((yyvsp[-1].node))->getIdent();
                    (yyval.node) = new CallNode(fname);
                    pool.add((yyval.node));
                }
            }
            else {
                (yyval.node) = (yyvsp[-1].node);
            }
            //std::cout << "power2" << std::endl;
        }
#line 2918 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 805 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2924 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 806 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 2930 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 810 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-1].node);
            // std::cout << "atom1" << std::endl;
            if (!(yyvsp[-1].node)) { std::cout << "empty parens" << std::endl; }
        }
#line 2940 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 816 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible atom2" << std::endl; }
#line 2946 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 818 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible atom3" << std::endl; }
#line 2952 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 820 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible atom4" << std::endl; }
#line 2958 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 822 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = new IdentNode((yyvsp[0].identifier));
            delete [] (yyvsp[0].identifier);
            pool.add((yyval.node));
        }
#line 2968 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 828 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = new IntLiteral((yyvsp[0].intNumber));
            pool.add((yyval.node));
        }
#line 2977 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 833 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = new FloatLiteral((yyvsp[0].fltNumber));
            pool.add((yyval.node));
        }
#line 2986 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 837 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; std::cout << "impossible atom8" << std::endl; }
#line 2992 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 233:
#line 840 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2998 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 841 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3004 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 844 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3010 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 845 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 3016 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 864 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 3022 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 865 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); }
#line 3028 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 873 "includes/parse.y" /* yacc.c:1646  */
    {
            //should be parameters
            (yyval.node) = new IdentNode("");
            pool.add((yyval.node));
        }
#line 3038 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 878 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; }
#line 3044 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 879 "includes/parse.y" /* yacc.c:1646  */
    { (yyval.node) = nullptr; delete [] (yyvsp[0].identifier); }
#line 3050 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 916 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[-2].node);
            //std::cout << "testlist1" << std::endl;
        }
#line 3059 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 270:
#line 921 "includes/parse.y" /* yacc.c:1646  */
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
#line 3076 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 951 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-5].identifier); }
#line 3082 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 952 "includes/parse.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-2].identifier); }
#line 3088 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 960 "includes/parse.y" /* yacc.c:1646  */
    {
            (yyval.node) = nullptr;
        }
#line 3096 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1018 "includes/parse.y" /* yacc.c:1646  */
    { std::cout << "impossible YIELD" << std::endl; (yyval.node) = (yyvsp[0].node); }
#line 3102 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1019 "includes/parse.y" /* yacc.c:1646  */
    { std::cout << "impossible YIELD" << std::endl; }
#line 3108 "parse.tab.c" /* yacc.c:1646  */
    break;


#line 3112 "parse.tab.c" /* yacc.c:1646  */
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
#line 1026 "includes/parse.y" /* yacc.c:1906  */


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
