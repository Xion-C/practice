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
#line 2 "parse.y" /* yacc.c:339  */

	#include <iostream>
	#include <vector>
	#include <string>
	int yylex (void);
	extern char *yytext;
	void yyerror (const char *);
	void printResult();
	int complexity = 1;
	const int start = 0;
	struct funcInfo {
		int complexity;
		int line;
		int column;
		std::string name;
	} fi;
	struct tryInfo {
		int column;
		int first_complexity;
	} tryi;
	std::vector<struct funcInfo> funcs;
	std::vector<struct tryInfo> trys;

#line 90 "parse.tab.c" /* yacc.c:339  */

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
    AMPEREQUAL = 258,
    AMPERSAND = 259,
    AND = 260,
    AS = 261,
    ASSERT = 262,
    AT = 263,
    BACKQUOTE = 264,
    BAR = 265,
    BREAK = 266,
    CIRCUMFLEX = 267,
    CIRCUMFLEXEQUAL = 268,
    CLASS = 269,
    COLON = 270,
    COMMA = 271,
    CONTINUE = 272,
    DEDENT = 273,
    DEF = 274,
    DEL = 275,
    DOT = 276,
    DOUBLESLASH = 277,
    DOUBLESLASHEQUAL = 278,
    DOUBLESTAR = 279,
    DOUBLESTAREQUAL = 280,
    ELIF = 281,
    ELSE = 282,
    ENDMARKER = 283,
    EQEQUAL = 284,
    EQUAL = 285,
    EXCEPT = 286,
    EXEC = 287,
    FINALLY = 288,
    FOR = 289,
    FROM = 290,
    GLOBAL = 291,
    GREATER = 292,
    GREATEREQUAL = 293,
    GRLT = 294,
    IF = 295,
    IMPORT = 296,
    IN = 297,
    INDENT = 298,
    IS = 299,
    LAMBDA = 300,
    LBRACE = 301,
    LEFTSHIFT = 302,
    LEFTSHIFTEQUAL = 303,
    LESS = 304,
    LESSEQUAL = 305,
    LPAR = 306,
    LSQB = 307,
    MINEQUAL = 308,
    MINUS = 309,
    NAME = 310,
    NEWLINE = 311,
    NOT = 312,
    NOTEQUAL = 313,
    NUMBER = 314,
    OR = 315,
    PASS = 316,
    PERCENT = 317,
    PERCENTEQUAL = 318,
    PLUS = 319,
    PLUSEQUAL = 320,
    PRINT = 321,
    RAISE = 322,
    RBRACE = 323,
    RETURN = 324,
    RIGHTSHIFT = 325,
    RIGHTSHIFTEQUAL = 326,
    RPAR = 327,
    RSQB = 328,
    SEMI = 329,
    SLASH = 330,
    SLASHEQUAL = 331,
    STAR = 332,
    STAREQUAL = 333,
    STRING = 334,
    TILDE = 335,
    TRY = 336,
    VBAREQUAL = 337,
    WHILE = 338,
    WITH = 339,
    YIELD = 340
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 42 "parse.y" /* yacc.c:355  */

	char * str;

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
#define YYLAST   855

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  141
/* YYNRULES -- Number of rules.  */
#define YYNRULES  314
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  477

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   340

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
      85
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    51,    51,    54,    58,    59,    62,    63,    66,    67,
      70,    71,    74,    75,    78,    79,    82,   100,   101,   104,
     105,   108,   109,   112,   113,   116,   117,   120,   121,   124,
     125,   128,   129,   132,   133,   136,   137,   140,   141,   144,
     145,   148,   149,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   163,   164,   167,   168,   171,   172,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     189,   190,   193,   194,   197,   198,   201,   202,   205,   206,
     209,   212,   215,   216,   217,   218,   219,   222,   225,   228,
     229,   232,   235,   236,   239,   240,   243,   244,   247,   248,
     251,   254,   257,   258,   261,   262,   263,   266,   267,   270,
     271,   274,   275,   278,   279,   282,   283,   286,   287,   290,
     293,   294,   297,   298,   301,   302,   305,   308,   311,   314,
     314,   320,   321,   322,   323,   326,   327,   330,   333,   336,
     337,   340,   341,   344,   345,   357,   358,   361,   362,   365,
     375,   378,   381,   382,   385,   386,   389,   392,   397,   398,
     401,   402,   405,   406,   409,   410,   413,   414,   417,   418,
     421,   422,   425,   426,   429,   430,   433,   434,   437,   438,
     441,   442,   445,   446,   449,   450,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   466,   467,   470,
     471,   474,   475,   478,   479,   482,   483,   486,   487,   490,
     491,   494,   495,   498,   499,   500,   501,   504,   505,   508,
     509,   510,   513,   514,   517,   518,   521,   522,   523,   524,
     525,   526,   527,   530,   531,   534,   535,   538,   539,   542,
     543,   546,   547,   550,   551,   554,   555,   558,   559,   562,
     563,   564,   567,   568,   571,   572,   575,   576,   577,   580,
     581,   584,   585,   588,   589,   592,   593,   596,   597,   600,
     601,   604,   605,   608,   609,   612,   613,   616,   617,   620,
     621,   624,   625,   628,   631,   632,   635,   636,   639,   640,
     643,   644,   645,   648,   649,   652,   653,   656,   657,   660,
     661,   664,   665,   668,   669,   672,   673,   676,   677,   680,
     681,   684,   685,   688,   689
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AMPEREQUAL", "AMPERSAND", "AND", "AS",
  "ASSERT", "AT", "BACKQUOTE", "BAR", "BREAK", "CIRCUMFLEX",
  "CIRCUMFLEXEQUAL", "CLASS", "COLON", "COMMA", "CONTINUE", "DEDENT",
  "DEF", "DEL", "DOT", "DOUBLESLASH", "DOUBLESLASHEQUAL", "DOUBLESTAR",
  "DOUBLESTAREQUAL", "ELIF", "ELSE", "ENDMARKER", "EQEQUAL", "EQUAL",
  "EXCEPT", "EXEC", "FINALLY", "FOR", "FROM", "GLOBAL", "GREATER",
  "GREATEREQUAL", "GRLT", "IF", "IMPORT", "IN", "INDENT", "IS", "LAMBDA",
  "LBRACE", "LEFTSHIFT", "LEFTSHIFTEQUAL", "LESS", "LESSEQUAL", "LPAR",
  "LSQB", "MINEQUAL", "MINUS", "NAME", "NEWLINE", "NOT", "NOTEQUAL",
  "NUMBER", "OR", "PASS", "PERCENT", "PERCENTEQUAL", "PLUS", "PLUSEQUAL",
  "PRINT", "RAISE", "RBRACE", "RETURN", "RIGHTSHIFT", "RIGHTSHIFTEQUAL",
  "RPAR", "RSQB", "SEMI", "SLASH", "SLASHEQUAL", "STAR", "STAREQUAL",
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
  "exec_stmt", "assert_stmt", "compound_stmt", "$@1", "if_stmt",
  "star_ELIF", "while_stmt", "for_stmt", "try_stmt", "plus_except",
  "opt_ELSE", "opt_FINALLY", "with_stmt", "star_COMMA_with_item",
  "with_item", "except_clause", "pick_AS_COMMA", "opt_AS_COMMA", "suite",
  "plus_stmt", "testlist_safe", "plus_COMMA_old_test", "old_test",
  "old_lambdef", "test", "opt_IF_ELSE", "or_test", "and_test", "not_test",
  "comparison", "comp_op", "expr", "xor_expr", "and_expr", "shift_expr",
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
     335,   336,   337,   338,   339,   340
};
# endif

#define YYPACT_NINF -375

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-375)))

#define YYTABLE_NINF -261

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -375,    54,  -375,   401,  -375,   343,    66,   343,  -375,    71,
    -375,    83,   307,  -375,   307,   307,  -375,   100,   343,    66,
      73,   343,    68,   343,  -375,  -375,  -375,   775,  -375,  -375,
    -375,   285,   343,   343,  -375,  -375,   343,   343,   343,  -375,
    -375,    81,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,
    -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,
    -375,  -375,  -375,  -375,    75,  -375,  -375,  -375,  -375,  -375,
      51,   154,  -375,   736,   152,   156,   167,   -11,    64,     6,
    -375,   307,  -375,  -375,    94,  -375,    27,  -375,  -375,   158,
    -375,    18,  -375,   115,     9,   124,   152,  -375,    31,   134,
     137,    17,  -375,   165,  -375,   166,    49,   343,   174,    10,
      33,   113,  -375,   160,  -375,   120,  -375,  -375,   161,   125,
    -375,  -375,   343,  -375,  -375,   180,  -375,   182,  -375,   193,
    -375,  -375,  -375,  -375,   -12,   186,  -375,   187,   775,   775,
    -375,   775,  -375,  -375,  -375,  -375,  -375,   145,  -375,  -375,
     162,  -375,   307,   307,   307,   307,  -375,  -375,   307,  -375,
    -375,   307,  -375,  -375,  -375,  -375,   307,  -375,    42,  -375,
    -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,
    -375,  -375,   181,    68,   343,   159,   146,  -375,  -375,   343,
     620,   343,   147,   205,   208,   343,   343,    -6,   188,   200,
     211,   620,    66,   173,  -375,   343,   176,    85,  -375,   178,
    -375,   207,   343,   307,   219,  -375,  -375,  -375,   219,  -375,
    -375,   307,   219,  -375,  -375,   224,   219,   343,  -375,   620,
     130,   307,  -375,   671,   620,   343,    16,   154,  -375,  -375,
    -375,   152,   156,   167,   -11,    64,     6,  -375,   190,   307,
     146,   712,  -375,    68,  -375,  -375,  -375,  -375,  -375,   169,
    -375,   106,  -375,   199,  -375,  -375,  -375,   171,  -375,   177,
     620,   307,   232,   236,   197,   247,  -375,  -375,  -375,  -375,
     202,  -375,  -375,  -375,  -375,  -375,  -375,   183,   238,   343,
     244,   160,   220,   343,  -375,  -375,   222,  -375,   343,   245,
    -375,  -375,   232,   239,   620,   343,   152,  -375,  -375,   136,
    -375,   343,  -375,  -375,   195,   249,   250,   203,  -375,   257,
    -375,   217,   343,   343,   107,  -375,   263,   559,   266,  -375,
    -375,   152,   343,  -375,   620,   213,   228,   273,  -375,   123,
     275,  -375,   271,  -375,  -375,     7,  -375,   281,  -375,  -375,
     775,   761,  -375,   343,  -375,  -375,   283,  -375,  -375,   343,
     284,   112,   286,  -375,  -375,   287,  -375,   288,   343,  -375,
    -375,  -375,   343,  -375,  -375,   233,  -375,  -375,   480,   620,
    -375,   280,  -375,  -375,   197,   343,   294,    85,   255,   343,
    -375,    24,   296,    67,   297,  -375,   252,  -375,   620,    40,
     620,   299,   282,   304,   620,  -375,   223,  -375,   305,   306,
    -375,  -375,  -375,  -375,   308,  -375,   311,   620,  -375,  -375,
     313,   761,  -375,  -375,  -375,   761,   314,   761,  -375,  -375,
    -375,   761,   316,  -375,  -375,  -375,   343,  -375,  -375,   620,
     318,  -375,   620,  -375,  -375,   343,  -375,  -375,   744,  -375,
     620,   620,  -375,   343,    95,  -375,   761,    67,  -375,   761,
    -375,  -375,  -375,   620,  -375,  -375,   343,  -375,  -375,  -375,
    -375,  -375,  -375,  -375,  -375,  -375,  -375
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       7,     0,     2,   129,     1,     0,     0,     0,    87,     0,
      88,     0,     0,     3,     0,     0,   314,     0,     0,     0,
      24,   240,   236,   238,   220,   230,     4,     0,   231,    81,
     219,    75,    93,    90,   242,   221,     0,     0,   312,     6,
      13,     0,   134,   132,     5,    37,    42,    43,    44,    45,
      46,    47,    82,    83,    84,    86,    85,    48,    98,    99,
      49,    50,    51,    38,     0,   126,   127,   128,   131,    73,
     177,   178,   180,   183,   184,   197,   199,   201,   203,   207,
     211,     0,   218,   225,   232,   175,    57,   133,    91,   125,
     117,     0,   309,     0,     0,     0,   268,    80,   123,     0,
       0,     0,   121,     0,   115,   100,   110,     0,     0,     0,
      73,     0,   239,    73,   235,     0,   234,   233,    73,     0,
     237,   182,     0,    70,    73,    97,    89,     0,   153,   155,
     311,    12,    15,    14,     0,     0,   130,   270,     0,     0,
     174,     0,   188,   187,   189,   191,   193,   195,   186,   190,
       0,   192,     0,     0,     0,     0,   205,   206,     0,   210,
     209,     0,   216,   215,   214,   213,     0,   217,   223,   241,
      63,    65,    69,    68,    66,    59,    62,    58,    67,    61,
      60,    64,    53,     0,     0,     0,   285,     9,   229,     0,
       0,   282,    24,     0,   266,     0,     0,     0,   313,   102,
     119,     0,     0,     0,   248,     0,     0,     0,    31,     0,
      19,    22,     0,     0,    30,   272,   277,   228,    30,   245,
     226,     0,    30,   243,   227,    79,    30,     0,    92,     0,
       0,     0,    40,     0,     0,   269,     0,   179,   181,   196,
     194,   185,   198,   200,   202,   204,   208,   212,     0,     0,
     285,   260,   224,     0,    52,    55,    54,   124,   118,     0,
      10,     0,   310,     0,   162,   280,   281,     0,    18,     0,
       0,   265,    95,     0,     0,   108,   104,   101,   114,   106,
       0,   138,   116,   109,   247,    28,    36,     0,    26,     0,
      30,   274,     0,    29,   278,   246,     0,   244,     0,    30,
      71,    74,    95,   140,     0,     0,   154,    39,    41,     0,
      72,     0,   251,   222,     0,     0,   257,     0,   255,     0,
      56,     0,     0,     0,   296,   283,    30,   129,     0,    17,
      16,   267,     0,   122,     0,     0,     0,   112,   120,   136,
      34,    32,     0,    27,    21,    23,    20,    30,   271,   275,
       0,     0,    77,    29,    78,    96,     0,   151,   152,   157,
       0,   148,     0,   176,   249,     0,   250,   253,   260,     8,
     292,   287,     0,   293,   295,   284,   290,   165,   129,     0,
      94,   142,   105,   107,   111,     0,     0,    33,     0,    29,
     276,   306,    24,   300,   167,   171,   170,    76,     0,   161,
       0,     0,   150,     0,     0,   256,   252,   259,   262,   289,
     294,   163,   164,   279,     0,   113,     0,     0,    35,    25,
       0,     0,   305,   303,   304,     0,     0,     0,   299,   297,
     298,     0,    30,   139,   158,   159,     0,   156,   144,     0,
       0,   143,     0,   146,   254,   264,   258,   261,     0,   291,
       0,     0,   135,     0,   308,   173,     0,   302,   169,    29,
     166,   160,   147,     0,   145,   263,     0,   286,   141,   137,
     273,   307,   172,   301,   168,   149,   288
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -375,  -375,  -375,  -375,  -375,   293,    88,  -375,  -375,   300,
    -375,  -182,  -375,  -375,  -375,  -375,  -193,  -199,  -375,  -375,
    -292,    -2,  -375,   102,  -375,    90,  -375,  -375,  -375,   -14,
    -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,
    -375,    43,  -375,  -375,  -375,  -375,  -375,  -375,   -38,   148,
      77,  -375,  -375,    15,  -375,  -375,  -375,  -375,  -375,  -375,
    -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,
      52,    -1,  -375,  -375,  -192,  -375,  -375,  -375,  -374,  -375,
      -5,  -375,  -135,   229,    -7,  -375,  -375,    -8,   194,   215,
     201,  -375,   212,  -375,   214,  -375,   -58,  -375,  -375,  -375,
    -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,  -375,
    -375,  -375,   -34,     5,  -375,  -375,    -4,  -375,   -19,  -375,
    -375,  -375,  -375,   333,  -375,  -375,  -375,  -375,  -375,  -375,
     -71,  -375,   -79,   261,  -375,   -73,   -98,  -375,  -375,   -17,
    -375
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    39,     3,    40,   259,    41,    42,    43,
     193,   108,   290,   109,   343,   210,   294,   211,   287,   340,
      44,   264,   134,    46,    47,   254,   182,   183,    48,   137,
     123,   299,   300,    49,    50,    51,    52,    53,    54,    55,
      56,   333,   228,    57,    58,    59,   100,   277,   278,   104,
     279,   337,   105,   106,    60,   200,    61,    62,    63,    64,
      65,   339,    66,    67,   136,   361,   402,   441,    68,   230,
     128,   362,   436,   437,   265,   378,   393,   432,   394,   395,
      69,   140,    70,    71,    72,    73,   152,    74,    75,    76,
      77,   158,    78,   161,    79,   166,    80,    81,    82,   168,
      83,   114,   115,   119,   111,    84,   120,   116,    85,   252,
     317,   367,   318,   319,   446,   447,    97,   194,    86,   112,
     347,   348,   215,    87,   267,   260,   261,   409,   449,   325,
     326,   373,   428,   429,   430,   422,   423,   424,    93,    88,
     101
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      89,    45,    92,   236,    96,   117,    98,    96,   286,   281,
     269,    99,   216,   103,   126,   219,   110,   113,   118,   130,
     121,    91,   -29,   167,   190,   295,   124,   125,   162,   297,
     170,   127,   129,   301,   206,   377,   156,   303,   198,   185,
     171,   153,   309,   311,   232,   274,   434,   454,   212,   275,
     172,   455,   173,   457,     4,   203,   435,   458,   213,   157,
     191,   207,   233,   248,   421,   208,   249,   213,   163,   186,
     185,   276,    90,   195,   187,   174,   139,     7,   330,   -29,
     175,   164,   472,   165,   139,   474,   412,   209,   107,     6,
     176,   138,   177,   250,   251,     9,   214,   346,   178,   218,
      11,   221,   204,   179,   222,   180,   354,   427,   247,   181,
     226,   139,   357,    20,    21,     7,   199,   225,   159,    22,
      23,    90,    24,    25,   188,    27,    94,    28,   160,   213,
     322,   189,    30,   376,   238,   421,   207,   372,    95,   401,
     208,   213,   381,   359,   241,   304,   305,    34,    35,   385,
     386,    20,    21,    38,   390,   102,   135,    22,    23,   141,
      24,    25,   153,    27,   255,    28,   256,   359,   154,   360,
      30,   155,   266,   169,   184,   192,   196,   273,   197,   257,
     201,   217,   202,   323,   262,    34,    35,   413,   418,   205,
     272,   313,   220,   349,   213,   221,   227,   229,   224,   231,
     284,   234,   239,   235,   240,    96,   433,   291,   438,   292,
     426,   253,   443,    96,   258,   391,   396,   296,   -11,   268,
     270,   185,   302,   306,   271,   452,   374,   280,   283,  -103,
     310,   285,     7,   288,   255,   293,   256,   289,  -260,   460,
     298,   321,   327,   328,   315,   312,   316,   462,   332,   329,
     464,   334,   275,   336,   342,   341,   324,   338,   468,   469,
     345,   353,   350,   331,   351,  -259,   356,   364,    20,    21,
     365,   475,   368,   369,    22,    23,   366,    24,    25,   375,
      27,   379,    28,   383,   344,   382,   396,    30,   310,   384,
     396,   387,   396,   352,     7,   388,   396,   389,   398,   400,
     129,   404,    34,    35,   406,   -29,   363,   414,   405,   417,
     419,   425,   139,   431,   439,   440,     7,   370,   371,   442,
     445,   396,   448,   450,   396,    45,   451,   380,   453,   456,
      20,    21,   459,   463,   131,   308,    22,    23,   314,    24,
      25,   132,    27,   320,    28,   355,   415,   242,   397,    30,
     282,   335,     7,    21,   399,   122,   244,   358,    22,    23,
     403,    24,    25,   407,    34,    35,    28,   410,   237,   243,
     245,    30,   444,   408,   133,   246,    45,   467,   473,   223,
     416,   471,     0,     0,   420,     0,    34,    35,    20,    21,
       0,     0,     0,     0,    22,    23,     0,    24,    25,     0,
      27,   316,    28,     0,     0,     0,     0,    30,     5,     6,
       7,     0,     8,     0,     0,     9,     0,     0,    10,     0,
      11,    12,    34,    35,     0,     0,     0,     0,     0,    13,
       0,   461,     0,    14,     0,    15,    16,    17,     0,     0,
     465,    18,    19,   324,     0,     0,    20,    21,   470,     0,
       0,     0,    22,    23,     0,    24,    25,    26,    27,     0,
      28,   476,    29,     0,     0,    30,     0,    31,    32,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,    35,     0,     0,    36,    37,    38,     5,     6,     7,
       0,     8,     0,     0,     9,     0,     0,    10,   411,    11,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,     0,    15,    16,    17,     0,     0,     0,
      18,    19,     0,     0,     0,    20,    21,     0,     0,     0,
       0,    22,    23,     0,    24,    25,     0,    27,     0,    28,
       0,    29,     0,     0,    30,     0,    31,    32,     0,    33,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      35,     0,     0,    36,    37,    38,     5,     6,     7,     0,
       8,     0,     0,     9,     0,     0,    10,     0,    11,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    14,     0,    15,    16,    17,     0,     0,     0,    18,
      19,     0,     0,     0,    20,    21,     0,     0,     0,     0,
      22,    23,     0,    24,    25,     0,    27,     0,    28,     0,
      29,     0,     0,    30,     0,    31,    32,     5,    33,     7,
       0,     8,     0,     0,     0,     0,     0,    10,    34,    35,
      12,     0,    36,    37,    38,     0,     0,     0,     0,     0,
       0,     0,    14,     0,     0,    16,    17,     0,     0,     0,
       0,    19,     0,     0,     0,    20,    21,     0,     0,     0,
       0,    22,    23,     0,    24,    25,   263,    27,     5,    28,
       7,    29,     8,     0,    30,     0,    31,    32,    10,    33,
       0,    12,     0,     0,     0,     0,     0,     0,     0,    34,
      35,     0,     0,    14,     0,    38,    16,    17,     0,     0,
       0,     0,    19,     0,     0,     0,    20,    21,     0,     0,
       0,     7,    22,    23,     0,    24,    25,   307,    27,     0,
      28,     0,    29,   315,     0,    30,     0,    31,    32,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,    35,     0,     7,     0,     0,    38,    20,    21,     0,
       0,     0,     0,    22,    23,   142,    24,    25,   466,    27,
       7,    28,     0,   143,   144,   145,    30,     0,   146,     0,
     147,     0,     0,     0,     7,   148,   149,     0,     0,    20,
      21,    34,    35,   150,   151,    22,    23,     0,    24,    25,
       0,    27,     0,    28,     0,     0,   392,    21,    30,     0,
       0,     0,    22,    23,     0,    24,    25,     0,    27,     0,
      28,    21,     0,    34,    35,    30,    22,    23,     0,    24,
      25,     0,    27,     0,    28,     0,     0,     0,     0,    30,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,    35
};

static const yytype_int16 yycheck[] =
{
       5,     3,     7,   138,    12,    22,    14,    15,   207,   201,
     192,    15,   110,    18,    33,   113,    21,    22,    23,    38,
      27,     6,    15,    81,    15,   218,    31,    32,    22,   222,
       3,    36,    37,   226,    24,   327,    47,   229,    21,    21,
      13,    10,   234,    27,    56,    51,     6,   421,    15,    55,
      23,   425,    25,   427,     0,     6,    16,   431,    34,    70,
      51,    51,    74,    21,    40,    55,    24,    34,    62,    51,
      21,    77,    55,    42,    56,    48,    60,     9,   270,    72,
      53,    75,   456,    77,    60,   459,   378,    77,    15,     8,
      63,    40,    65,    51,    52,    14,   110,   290,    71,   113,
      19,    34,   107,    76,   118,    78,   299,    40,   166,    82,
     124,    60,   304,    45,    46,     9,   101,   122,    54,    51,
      52,    55,    54,    55,     9,    57,    55,    59,    64,    34,
      24,    16,    64,   326,   141,    40,    51,    30,    55,    27,
      55,    34,   334,    31,   152,    15,    16,    79,    80,    26,
      27,    45,    46,    85,   347,    55,    81,    51,    52,     5,
      54,    55,    10,    57,   183,    59,   183,    31,    12,    33,
      64,     4,   191,    79,    16,    51,    42,   196,    41,   184,
      15,    68,    16,    77,   189,    79,    80,   379,   387,    15,
     195,   249,    72,   291,    34,    34,    16,    15,    73,     6,
     205,    15,    57,    16,    42,   213,   398,   212,   400,   213,
     392,    30,   404,   221,    55,   350,   351,   221,    72,    72,
      15,    21,   227,   231,    16,   417,   324,    16,    55,    41,
     235,    55,     9,    55,   253,    16,   253,    30,    15,   432,
      16,    72,    43,    72,    21,    55,   251,   439,    16,    72,
     442,    15,    55,     6,    16,    72,   261,    55,   450,   451,
      16,    16,    42,   271,    42,    15,    27,    72,    45,    46,
      21,   463,    15,    56,    51,    52,    73,    54,    55,    16,
      57,    15,    59,    55,   289,    72,   421,    64,   293,    16,
     425,    16,   427,   298,     9,    24,   431,    16,    15,    15,
     305,    15,    79,    80,    16,    72,   311,    27,    21,    15,
      55,    15,    60,    16,    15,    33,     9,   322,   323,    15,
      15,   456,    16,    15,   459,   327,    15,   332,    15,    15,
      45,    46,    16,    15,    41,   233,    51,    52,   250,    54,
      55,    41,    57,   253,    59,   302,   384,   153,   353,    64,
     202,   274,     9,    46,   359,    70,   155,   305,    51,    52,
     361,    54,    55,   368,    79,    80,    59,   372,   139,   154,
     158,    64,   406,   368,    41,   161,   378,   448,   457,   118,
     385,   454,    -1,    -1,   389,    -1,    79,    80,    45,    46,
      -1,    -1,    -1,    -1,    51,    52,    -1,    54,    55,    -1,
      57,   406,    59,    -1,    -1,    -1,    -1,    64,     7,     8,
       9,    -1,    11,    -1,    -1,    14,    -1,    -1,    17,    -1,
      19,    20,    79,    80,    -1,    -1,    -1,    -1,    -1,    28,
      -1,   436,    -1,    32,    -1,    34,    35,    36,    -1,    -1,
     445,    40,    41,   448,    -1,    -1,    45,    46,   453,    -1,
      -1,    -1,    51,    52,    -1,    54,    55,    56,    57,    -1,
      59,   466,    61,    -1,    -1,    64,    -1,    66,    67,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    80,    -1,    -1,    83,    84,    85,     7,     8,     9,
      -1,    11,    -1,    -1,    14,    -1,    -1,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      -1,    51,    52,    -1,    54,    55,    -1,    57,    -1,    59,
      -1,    61,    -1,    -1,    64,    -1,    66,    67,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      80,    -1,    -1,    83,    84,    85,     7,     8,     9,    -1,
      11,    -1,    -1,    14,    -1,    -1,    17,    -1,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    34,    35,    36,    -1,    -1,    -1,    40,
      41,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
      51,    52,    -1,    54,    55,    -1,    57,    -1,    59,    -1,
      61,    -1,    -1,    64,    -1,    66,    67,     7,    69,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    79,    80,
      20,    -1,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      -1,    51,    52,    -1,    54,    55,    56,    57,     7,    59,
       9,    61,    11,    -1,    64,    -1,    66,    67,    17,    69,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      80,    -1,    -1,    32,    -1,    85,    35,    36,    -1,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,     9,    51,    52,    -1,    54,    55,    56,    57,    -1,
      59,    -1,    61,    21,    -1,    64,    -1,    66,    67,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    80,    -1,     9,    -1,    -1,    85,    45,    46,    -1,
      -1,    -1,    -1,    51,    52,    29,    54,    55,    24,    57,
       9,    59,    -1,    37,    38,    39,    64,    -1,    42,    -1,
      44,    -1,    -1,    -1,     9,    49,    50,    -1,    -1,    45,
      46,    79,    80,    57,    58,    51,    52,    -1,    54,    55,
      -1,    57,    -1,    59,    -1,    -1,    45,    46,    64,    -1,
      -1,    -1,    51,    52,    -1,    54,    55,    -1,    57,    -1,
      59,    46,    -1,    79,    80,    64,    51,    52,    -1,    54,
      55,    -1,    57,    -1,    59,    -1,    -1,    -1,    -1,    64,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    80
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    87,    88,    90,     0,     7,     8,     9,    11,    14,
      17,    19,    20,    28,    32,    34,    35,    36,    40,    41,
      45,    46,    51,    52,    54,    55,    56,    57,    59,    61,
      64,    66,    67,    69,    79,    80,    83,    84,    85,    89,
      91,    93,    94,    95,   106,   107,   109,   110,   114,   119,
     120,   121,   122,   123,   124,   125,   126,   129,   130,   131,
     140,   142,   143,   144,   145,   146,   148,   149,   154,   166,
     168,   169,   170,   171,   173,   174,   175,   176,   178,   180,
     182,   183,   184,   186,   191,   194,   204,   209,   225,   166,
      55,   139,   166,   224,    55,    55,   173,   202,   173,   202,
     132,   226,    55,   166,   135,   138,   139,    15,    97,    99,
     166,   190,   205,   166,   187,   188,   193,   225,   166,   189,
     192,   170,    70,   116,   166,   166,   204,   166,   156,   166,
     204,    91,    95,   209,   108,    81,   150,   115,    40,    60,
     167,     5,    29,    37,    38,    39,    42,    44,    49,    50,
      57,    58,   172,    10,    12,     4,    47,    70,   177,    54,
      64,   179,    22,    62,    75,    77,   181,   182,   185,    79,
       3,    13,    23,    25,    48,    53,    63,    65,    71,    76,
      78,    82,   112,   113,    16,    21,    51,    56,     9,    16,
      15,    51,    51,    96,   203,    42,    42,    41,    21,   139,
     141,    15,    16,     6,   166,    15,    24,    51,    55,    77,
     101,   103,    15,    34,   115,   208,   222,    68,   115,   222,
      72,    34,   115,   219,    73,   166,   115,    16,   128,    15,
     155,     6,    56,    74,    15,    16,   168,   169,   170,    57,
      42,   173,   174,   175,   176,   178,   180,   182,    21,    24,
      51,    52,   195,    30,   111,   204,   225,   166,    55,    92,
     211,   212,   166,    56,   107,   160,   204,   210,    72,    97,
      15,    16,   166,   204,    51,    55,    77,   133,   134,   136,
      16,   160,   135,    55,   166,    55,   103,   104,    55,    30,
      98,   166,   202,    16,   102,   102,   202,   102,    16,   117,
     118,   102,   166,   160,    15,    16,   173,    56,   109,   160,
     166,    27,    55,   182,    92,    21,   166,   196,   198,   199,
     111,    72,    24,    77,   166,   215,   216,    43,    72,    72,
     160,   173,    16,   127,    15,   136,     6,   137,    55,   147,
     105,    72,    16,   100,   166,    16,   102,   206,   207,   222,
      42,    42,   166,    16,   102,   127,    27,   160,   156,    31,
      33,   151,   157,   166,    72,    21,    73,   197,    15,    56,
     166,   166,    30,   217,   222,    16,   102,   106,   161,    15,
     166,   160,    72,    55,    16,    26,    27,    16,    24,    16,
     102,   168,    45,   162,   164,   165,   168,   166,    15,   166,
      15,    27,   152,   157,    15,    21,    16,   166,   199,   213,
     166,    18,   106,   160,    27,   134,   166,    15,   103,    55,
     166,    40,   221,   222,   223,    15,    97,    40,   218,   219,
     220,    16,   163,   160,     6,    16,   158,   159,   160,    15,
      33,   153,    15,   160,   198,    15,   200,   201,    16,   214,
      15,    15,   160,    15,   164,   164,    15,   164,   164,    16,
     102,   166,   160,    15,   160,   166,    24,   216,   160,   160,
     166,   221,   164,   218,   164,   160,   166
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    88,    89,    89,    90,    90,    91,    91,
      92,    92,    93,    93,    94,    94,    95,    96,    96,    97,
      97,    98,    98,    99,    99,   100,   100,   101,   101,   102,
     102,   103,   103,   104,   104,   105,   105,   106,   106,   107,
     107,   108,   108,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   110,   110,   111,   111,   112,   112,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     114,   114,   115,   115,   116,   116,   117,   117,   118,   118,
     119,   120,   121,   121,   121,   121,   121,   122,   123,   124,
     124,   125,   126,   126,   127,   127,   128,   128,   129,   129,
     130,   131,   132,   132,   133,   133,   133,   134,   134,   135,
     135,   136,   136,   137,   137,   138,   138,   139,   139,   140,
     141,   141,   142,   142,   143,   143,   144,   144,   144,   145,
     144,   144,   144,   144,   144,   146,   146,   147,   147,   148,
     148,   149,   149,   150,   150,   151,   151,   152,   152,   153,
     153,   154,   155,   155,   156,   156,   157,   157,   158,   158,
     159,   159,   160,   160,   161,   161,   162,   162,   163,   163,
     164,   164,   165,   165,   166,   166,   167,   167,   168,   168,
     169,   169,   170,   170,   171,   171,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   173,   173,   174,
     174,   175,   175,   176,   176,   177,   177,   178,   178,   179,
     179,   180,   180,   181,   181,   181,   181,   182,   182,   183,
     183,   183,   184,   184,   185,   185,   186,   186,   186,   186,
     186,   186,   186,   187,   187,   188,   188,   189,   189,   190,
     190,   191,   191,   192,   192,   193,   193,   194,   194,   195,
     195,   195,   196,   196,   197,   197,   198,   198,   198,   199,
     199,   200,   200,   201,   201,   202,   202,   203,   203,   204,
     204,   205,   205,   206,   206,   207,   207,   208,   208,   209,
     209,   210,   210,   211,   212,   212,   213,   213,   214,   214,
     215,   215,   215,   216,   216,   217,   217,   218,   218,   219,
     219,   220,   220,   221,   221,   222,   222,   223,   223,   224,
     224,   225,   225,   226,   226
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
       3,     0,     5,     2,     4,     2,     1,     1,     1,     0,
       2,     1,     1,     1,     1,     8,     5,     5,     0,     7,
       4,     9,     6,     6,     6,     4,     3,     3,     0,     3,
       0,     5,     3,     0,     3,     1,     3,     1,     1,     1,
       2,     0,     1,     4,     2,     1,     3,     1,     3,     2,
       1,     1,     4,     3,     2,     1,     4,     0,     1,     3,
       1,     3,     2,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     4,     2,     2,     0,     3,     3,     3,     3,
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
        case 3:
#line 55 "parse.y" /* yacc.c:1646  */
    { printResult(); }
#line 1902 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 83 "parse.y" /* yacc.c:1646  */
    {
		if((yylsp[-4]).first_column - 1 > start) {
			complexity++;
		}
		else {
			fi.complexity = complexity;
			fi.line = (yylsp[-4]).first_line;
			fi.column = (yylsp[-4]).first_column - 1;
			fi.name = (yyvsp[-3].str);
			funcs.push_back(fi);
			complexity = 1;
			trys.clear();
		}
		delete [] (yyvsp[-3].str);
	}
#line 1922 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 305 "parse.y" /* yacc.c:1646  */
    {
		complexity++;
	}
#line 1930 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 308 "parse.y" /* yacc.c:1646  */
    {
		complexity++;
	}
#line 1938 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 311 "parse.y" /* yacc.c:1646  */
    {
		complexity++;
	}
#line 1946 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 314 "parse.y" /* yacc.c:1646  */
    {
		tryi.column = yylloc.first_column;
		tryi.first_complexity = complexity;
		trys.push_back(tryi);
		complexity++;
	}
#line 1957 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 330 "parse.y" /* yacc.c:1646  */
    {
		complexity++;
	}
#line 1965 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 345 "parse.y" /* yacc.c:1646  */
    {
		for(std::vector<struct tryInfo>::iterator it = trys.end() - 1; it>=trys.begin(); it--) {
			if(it->column == (yylsp[-2]).first_column) {
				complexity = it->first_complexity;
				trys.erase(it);
				break;
			}
		}
		//if(!flag) {printf("something goes wrong...\n");}
	}
#line 1980 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 365 "parse.y" /* yacc.c:1646  */
    {
		for(std::vector<struct tryInfo>::iterator it = trys.end() - 1; it>=trys.begin(); it--) {
			if(it->column == (yylsp[-2]).first_column) {
				complexity = it->first_complexity;
				trys.erase(it);
				break;
			}
		}
		//if(!flag) {printf("something goes wrong...\n");}
	}
#line 1995 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 389 "parse.y" /* yacc.c:1646  */
    {
		complexity++;
	}
#line 2003 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 392 "parse.y" /* yacc.c:1646  */
    {
		complexity++;
	}
#line 2011 "parse.tab.c" /* yacc.c:1646  */
    break;


#line 2015 "parse.tab.c" /* yacc.c:1646  */
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
#line 692 "parse.y" /* yacc.c:1906  */


#include <stdio.h>
void yyerror (const char *s)
{
	if(yylloc.first_line > 0) {
		fprintf (stderr, "%d.%d-%d.%d:", yylloc.first_line, yylloc.first_column, yylloc.last_line, yylloc.last_column);
	}
	fprintf(stderr, " %s with [%s]\n", s, yytext);
}

void printResult()
{
	//printf("Complexity : %d\n", complexity);

	// for(std::vector<struct funcInfo>::iterator it = funcs.begin(); it != funcs.end(); ++it) {
	// 	printf("(%d %d) %s : %d\n", it->line, it->column, it->name, it->complexity );
	// }
	while (!funcs.empty())
  {
    // printf("(\"%d:%d: \'%s\'\", %d)\n", funcs.back().line,
		// 	funcs.back().column, funcs.back().name, funcs.back().complexity );
		std::cout << "(\"" << funcs.back().line << ":" << funcs.back().column
			<< ": \'" << funcs.back().name << "\'\", "
			<< funcs.back().complexity << ")" << std::endl;
		funcs.pop_back();
  }
}
