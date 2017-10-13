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

	int yylex (void);
	extern char *yytext;
	void yyerror (const char *);
	void printResult();
	int complexity = 1;
	int pre_firstline = 0;
	int func_nest = 0;

#line 76 "parse.tab.c" /* yacc.c:339  */

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
#line 28 "parse.y" /* yacc.c:355  */

	char * str;

#line 206 "parse.tab.c" /* yacc.c:355  */
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

#line 235 "parse.tab.c" /* yacc.c:358  */

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
#define YYLAST   885

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  140
/* YYNRULES -- Number of rules.  */
#define YYNRULES  313
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  476

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
       0,    37,    37,    40,    44,    45,    48,    49,    52,    53,
      56,    57,    60,    61,    64,    65,    68,    84,    85,    88,
      89,    92,    93,    96,    97,   100,   101,   104,   105,   108,
     109,   112,   113,   116,   117,   120,   121,   124,   125,   128,
     129,   132,   133,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   147,   148,   151,   152,   155,   156,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     173,   174,   177,   178,   181,   182,   185,   186,   189,   190,
     193,   196,   199,   200,   201,   202,   203,   206,   209,   212,
     213,   216,   219,   220,   223,   224,   227,   228,   231,   232,
     235,   238,   241,   242,   245,   246,   247,   250,   251,   254,
     255,   258,   259,   262,   263,   266,   267,   270,   271,   274,
     277,   278,   281,   282,   285,   286,   289,   291,   293,   295,
     297,   299,   301,   302,   305,   307,   311,   312,   315,   316,
     319,   320,   323,   324,   327,   328,   331,   332,   335,   336,
     339,   342,   343,   346,   347,   350,   351,   354,   355,   358,
     359,   362,   363,   366,   367,   370,   371,   374,   375,   378,
     379,   382,   383,   386,   387,   390,   391,   394,   395,   398,
     399,   402,   403,   406,   407,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   423,   424,   427,   428,
     431,   432,   435,   436,   439,   440,   443,   444,   447,   448,
     451,   452,   455,   456,   457,   458,   461,   462,   465,   466,
     467,   470,   471,   474,   475,   478,   479,   480,   481,   482,
     483,   484,   487,   488,   491,   492,   495,   496,   499,   500,
     503,   504,   507,   508,   511,   512,   515,   516,   519,   520,
     521,   524,   525,   528,   529,   532,   533,   534,   537,   538,
     541,   542,   545,   546,   549,   550,   553,   554,   557,   558,
     561,   562,   565,   566,   569,   570,   573,   574,   577,   578,
     581,   582,   585,   588,   589,   592,   593,   596,   597,   600,
     601,   602,   605,   606,   609,   610,   613,   614,   617,   618,
     621,   622,   625,   626,   629,   630,   633,   634,   637,   638,
     641,   642,   645,   646
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
     335,   336,   337,   338,   339,   340
};
# endif

#define YYPACT_NINF -289

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-289)))

#define YYTABLE_NINF -260

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -289,    55,  -289,   352,  -289,   744,     6,   744,  -289,    89,
    -289,   107,   805,  -289,   805,   805,  -289,   114,   744,     6,
      54,   744,    21,   744,  -289,  -289,  -289,   788,  -289,  -289,
    -289,   573,   744,   744,  -289,  -289,   105,   744,   744,   744,
    -289,  -289,   103,  -289,  -289,  -289,  -289,  -289,  -289,  -289,
    -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,
    -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,
    -289,     0,   131,  -289,   228,   148,   158,   169,    -6,    69,
      32,  -289,   805,  -289,  -289,    96,  -289,    26,  -289,  -289,
     160,  -289,    42,  -289,   110,    20,   127,   148,  -289,    46,
     139,   142,    15,  -289,   172,  -289,   173,    44,   744,   177,
       7,    23,   120,  -289,   159,  -289,   122,  -289,  -289,   161,
     124,  -289,  -289,   744,  -289,  -289,   180,  -289,   603,   183,
    -289,   193,  -289,  -289,  -289,  -289,    56,   185,   788,   788,
    -289,   788,  -289,  -289,  -289,  -289,  -289,   149,  -289,  -289,
     163,  -289,   805,   805,   805,   805,  -289,  -289,   805,  -289,
    -289,   805,  -289,  -289,  -289,  -289,   805,  -289,    62,  -289,
    -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,
    -289,  -289,   178,    21,   744,   147,   137,  -289,  -289,   744,
     603,   744,   143,   198,   200,   744,   744,    -9,   176,   202,
     205,   603,     6,   170,  -289,   744,   171,    -8,  -289,   174,
    -289,   194,   744,   805,   211,  -289,  -289,  -289,   211,  -289,
    -289,   805,   211,  -289,  -289,   212,   211,   744,  -289,   191,
    -289,   123,   603,   145,   805,  -289,   654,   744,    17,   131,
    -289,  -289,  -289,   148,   158,   169,    -6,    69,    32,  -289,
     182,   805,   137,   695,  -289,    21,  -289,  -289,  -289,  -289,
    -289,   167,  -289,    86,  -289,  -289,  -289,   168,  -289,   175,
     603,   805,   225,   227,   188,   239,  -289,  -289,  -289,  -289,
     195,  -289,  -289,  -289,  -289,  -289,  -289,   181,   233,   744,
     236,   159,   213,   744,  -289,  -289,   214,  -289,   744,   238,
    -289,  -289,   225,   524,   744,   244,   108,   245,   234,   603,
     744,   148,  -289,  -289,  -289,   744,  -289,  -289,   190,   242,
     254,   203,  -289,   256,  -289,   219,   744,   744,   121,  -289,
     263,   265,  -289,  -289,   148,   744,  -289,   603,   209,   232,
     266,  -289,   141,   267,  -289,   268,  -289,  -289,     9,  -289,
     273,  -289,  -289,   788,   774,  -289,   744,  -289,  -289,  -289,
     445,   118,   603,   275,   258,   279,   603,   280,  -289,  -289,
    -289,  -289,   277,  -289,   291,   744,  -289,  -289,  -289,   744,
    -289,  -289,   240,  -289,   603,  -289,   281,  -289,  -289,   188,
     744,   289,    -8,   259,   744,  -289,    65,   296,    81,   297,
    -289,   255,  -289,  -289,  -289,  -289,  -289,   744,  -289,  -289,
     603,   301,  -289,   603,  -289,   603,  -289,   288,  -289,   302,
     303,  -289,  -289,   305,  -289,   308,   603,  -289,  -289,   309,
     774,  -289,  -289,  -289,   774,   311,   774,  -289,  -289,  -289,
     774,   313,  -289,  -289,   603,  -289,  -289,  -289,   744,  -289,
    -289,   727,  -289,   603,   603,  -289,   744,   119,  -289,   774,
      81,  -289,   774,  -289,  -289,  -289,   744,  -289,  -289,  -289,
    -289,  -289,  -289,  -289,  -289,  -289
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       7,     0,     2,     0,     1,     0,     0,     0,    87,     0,
      88,     0,     0,     3,     0,     0,   313,     0,     0,     0,
      24,   239,   235,   237,   219,   229,     4,     0,   230,    81,
     218,    75,    93,    90,   241,   220,     0,     0,     0,   311,
       6,    13,     0,   133,   131,     5,    37,    42,    43,    44,
      45,    46,    47,    82,    83,    84,    86,    85,    48,    98,
      99,    49,    50,    51,    38,   126,   127,   128,   129,   130,
      73,   176,   177,   179,   182,   183,   196,   198,   200,   202,
     206,   210,     0,   217,   224,   231,   174,    57,   132,    91,
     125,   117,     0,   308,     0,     0,     0,   267,    80,   123,
       0,     0,     0,   121,     0,   115,   100,   110,     0,     0,
       0,    73,     0,   238,    73,   234,     0,   233,   232,    73,
       0,   236,   181,     0,    70,    73,    97,    89,     0,     0,
     152,   154,   310,    12,    15,    14,     0,   269,     0,     0,
     173,     0,   187,   186,   188,   190,   192,   194,   185,   189,
       0,   191,     0,     0,     0,     0,   204,   205,     0,   209,
     208,     0,   215,   214,   213,   212,     0,   216,   222,   240,
      63,    65,    69,    68,    66,    59,    62,    58,    67,    61,
      60,    64,    53,     0,     0,     0,   284,     9,   228,     0,
       0,   281,    24,     0,   265,     0,     0,     0,   312,   102,
     119,     0,     0,     0,   247,     0,     0,     0,    31,     0,
      19,    22,     0,     0,    30,   271,   276,   227,    30,   244,
     225,     0,    30,   242,   226,    79,    30,     0,    92,     0,
     161,     0,     0,     0,     0,    40,     0,   268,     0,   178,
     180,   195,   193,   184,   197,   199,   201,   203,   207,   211,
       0,     0,   284,   259,   223,     0,    52,    55,    54,   124,
     118,     0,    10,     0,   309,   279,   280,     0,    18,     0,
       0,   264,    95,     0,     0,   108,   104,   101,   114,   106,
       0,   137,   116,   109,   246,    28,    36,     0,    26,     0,
      30,   273,     0,    29,   277,   245,     0,   243,     0,    30,
      71,    74,    95,     0,   156,     0,   147,     0,   139,     0,
       0,   153,    39,    41,    72,     0,   250,   221,     0,     0,
     256,     0,   254,     0,    56,     0,     0,     0,   295,   282,
      30,     0,    17,    16,   266,     0,   122,     0,     0,     0,
     112,   120,   135,    34,    32,     0,    27,    21,    23,    20,
      30,   270,   274,     0,     0,    77,    29,    78,    96,   164,
       0,   160,     0,     0,   149,     0,     0,     0,   150,   151,
     175,   248,     0,   249,   252,   259,     8,   291,   286,     0,
     292,   294,   283,   289,     0,    94,   141,   105,   107,   111,
       0,     0,    33,     0,    29,   275,   305,    24,   299,   166,
     170,   169,    76,   162,   163,   157,   158,     0,   155,   143,
       0,     0,   142,     0,   145,     0,   255,   251,   258,   261,
     288,   293,   278,     0,   113,     0,     0,    35,    25,     0,
       0,   304,   302,   303,     0,     0,     0,   298,   296,   297,
       0,    30,   159,   146,     0,   144,   138,   253,   263,   257,
     260,     0,   290,     0,     0,   134,     0,   307,   172,     0,
     301,   168,    29,   165,   148,   262,     0,   285,   140,   136,
     272,   306,   171,   300,   167,   287
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -289,  -289,  -289,  -289,  -289,   276,    75,  -289,  -289,   290,
    -289,  -185,  -289,  -289,  -289,  -289,  -203,  -201,  -289,  -289,
    -278,    -2,  -289,    95,  -289,    80,  -289,  -289,  -289,   -66,
    -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,
    -289,    34,  -289,  -289,  -289,  -289,  -289,  -289,   -52,   136,
      67,  -289,  -289,    14,  -289,  -289,  -289,  -289,  -289,  -289,
    -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,    36,
      38,  -289,  -289,  -180,  -289,  -289,  -289,  -288,  -289,    -5,
    -289,  -134,   210,   -13,  -289,  -289,    -3,   197,   199,   201,
    -289,   196,  -289,   187,  -289,   -74,  -289,  -289,  -289,  -289,
    -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,
    -289,   -62,   -18,  -289,  -289,   -10,  -289,   -11,  -289,  -289,
    -289,  -289,   320,  -289,  -289,  -289,  -289,  -289,  -289,   -87,
    -289,   -95,   257,  -289,   -84,   -77,  -289,  -289,   -19,  -289
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    40,     3,    41,   261,    42,    43,    44,
     193,   109,   290,   110,   346,   210,   294,   211,   287,   343,
      45,   230,   136,    47,    48,   256,   182,   183,    49,   137,
     124,   299,   300,    50,    51,    52,    53,    54,    55,    56,
      57,   336,   228,    58,    59,    60,   101,   277,   278,   105,
     279,   340,   106,   107,    61,   200,    62,    63,    64,    65,
     342,    66,    67,    68,   306,   364,   412,    69,   233,   130,
     307,   407,   408,   231,   360,   398,   441,   399,   400,    70,
     140,    71,    72,    73,    74,   152,    75,    76,    77,    78,
     158,    79,   161,    80,   166,    81,    82,    83,   168,    84,
     115,   116,   120,   112,    85,   121,   117,    86,   254,   321,
     374,   322,   323,   449,   450,    98,   194,    87,   113,   350,
     351,   215,    88,   267,   262,   263,   420,   452,   329,   330,
     380,   437,   438,   439,   431,   432,   433,    94,    89,   102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      90,    46,    93,   118,   238,   100,   286,   269,   167,    97,
     265,    99,    97,   104,   122,   295,   111,   114,   119,   297,
      92,   281,   127,   301,   -29,   359,   125,   126,   132,   170,
       7,   206,   129,   131,   216,   190,   198,   219,   212,   171,
     138,   156,   274,   207,   315,   214,   275,   208,   218,   172,
     203,   173,   308,   222,   162,     4,   153,   213,   207,   226,
     139,    91,   208,   185,   157,   185,    20,    21,   276,   108,
      91,   191,    22,    23,   174,    24,    25,   139,    27,   175,
      28,   -29,   404,   250,   209,    30,   251,   349,   195,   176,
     333,   177,   249,   186,   163,     7,   357,   178,   187,   213,
      34,    35,   179,   204,   180,   430,    39,   164,   181,   165,
     326,     6,   235,   252,   253,   221,   199,     9,   225,   188,
     128,   436,    11,   159,   405,   139,   189,   383,   240,   368,
     236,    20,    21,   160,   406,   363,   141,    22,    23,   304,
      24,    25,   457,    27,    95,    28,   458,   395,   460,   243,
      30,   379,   461,   213,   304,   213,   305,   386,   153,   430,
     309,   310,    96,   327,   258,    34,    35,   390,   391,   103,
     154,   472,   257,   155,   474,   169,   184,   317,   192,   259,
     266,   196,   409,   197,   264,   273,   414,   201,   217,   202,
     272,   427,   205,   213,   220,   221,   227,   224,   232,   234,
     284,   237,   260,   292,   422,   242,   241,   291,   255,   -11,
      97,   296,   435,   270,   352,   268,   271,  -103,    97,   396,
     401,   280,   302,   185,   289,   283,   285,   293,   298,   288,
     443,   311,   314,   445,   303,   446,   258,   316,   463,   325,
     331,   335,   337,   275,   257,   339,   455,   332,   320,   345,
     341,   381,   348,   344,   356,   353,   354,   142,   328,   362,
     366,   367,   371,   372,   464,   143,   144,   145,   334,  -258,
     146,   375,   147,   468,   469,   376,   373,   148,   149,   382,
     384,   387,   389,   392,   347,   150,   151,   388,   314,   394,
     410,   411,   393,   355,   413,   415,   401,     7,   416,   361,
     401,    46,   401,  -259,   426,   131,   401,   417,   423,   319,
     370,   434,   -29,   440,   428,   139,   444,   448,   133,   451,
     453,   377,   378,   454,   456,   401,   459,   318,   401,   462,
     385,   313,   134,    20,    21,   324,   358,   424,   282,    22,
      23,   338,    24,    25,   365,    27,   369,    28,   248,   239,
     244,   402,    30,   245,   247,   447,   246,   419,    46,     5,
       6,     7,   135,     8,   467,   473,     9,    34,    35,    10,
     418,    11,    12,   471,   421,     0,   223,     0,     0,     0,
      13,     0,     0,     0,    14,   425,    15,    16,    17,   429,
       0,     0,    18,    19,     0,     0,     0,    20,    21,     0,
       0,     0,   442,    22,    23,     0,    24,    25,    26,    27,
       0,    28,   320,    29,     0,     0,    30,     0,    31,    32,
       0,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    35,    36,     0,    37,    38,    39,     0,     0,
       0,     0,     0,   465,     0,     0,   328,     0,     0,     0,
       0,   470,     5,     6,     7,     0,     8,     0,     0,     9,
       0,   475,    10,   403,    11,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,    15,
      16,    17,     0,     0,     0,    18,    19,     0,     0,     0,
      20,    21,     0,     0,     0,     0,    22,    23,     0,    24,
      25,     0,    27,     0,    28,     0,    29,     0,     0,    30,
       0,    31,    32,     0,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,    35,    36,     0,    37,    38,
      39,     5,     6,     7,     0,     8,     0,     0,     9,     0,
       0,    10,     0,    11,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,    15,    16,
      17,     0,     0,     0,    18,    19,     0,     0,     0,    20,
      21,     0,     0,     0,     0,    22,    23,     0,    24,    25,
       0,    27,     7,    28,     0,    29,     0,     0,    30,     0,
      31,    32,     0,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    35,    36,     0,    37,    38,    39,
       5,     0,     7,     0,     8,     0,     0,     0,    20,    21,
      10,     0,     0,    12,    22,    23,     0,    24,    25,     0,
      27,     0,    28,     0,     0,    14,     0,    30,    16,    17,
       0,     0,     0,   123,    19,     0,     0,     0,    20,    21,
       0,     0,    34,    35,    22,    23,     0,    24,    25,   229,
      27,     5,    28,     7,    29,     8,     0,    30,     0,    31,
      32,    10,    33,     0,    12,     0,     0,     0,     0,     0,
       0,     0,    34,    35,     0,     0,    14,     0,    39,    16,
      17,     0,     0,     0,     0,    19,     0,     0,     0,    20,
      21,     0,     0,     0,     7,    22,    23,     0,    24,    25,
     312,    27,     0,    28,     0,    29,   319,     0,    30,     0,
      31,    32,     0,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    35,     0,     7,     0,     0,    39,
      20,    21,     0,     0,     0,     0,    22,    23,     0,    24,
      25,   466,    27,     7,    28,     0,     0,     0,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,    21,    34,    35,     0,     0,    22,    23,
       0,    24,    25,     7,    27,     0,    28,     0,     0,    20,
      21,    30,     0,     0,     0,    22,    23,     7,    24,    25,
       0,    27,     0,    28,     0,     0,    34,    35,    30,     0,
       0,     0,     0,     0,     7,     0,     0,     0,     0,   397,
      21,     0,     0,    34,    35,    22,    23,     0,    24,    25,
       0,    27,     0,    28,    21,     0,     0,     0,    30,    22,
      23,     0,    24,    25,     0,    27,     0,    28,     0,     0,
       0,    21,    30,    34,    35,     0,    22,    23,     0,    24,
      25,     0,     0,     0,    28,     0,     0,    34,    35,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,    35
};

static const yytype_int16 yycheck[] =
{
       5,     3,     7,    22,   138,    15,   207,   192,    82,    12,
     190,    14,    15,    18,    27,   218,    21,    22,    23,   222,
       6,   201,    33,   226,    15,   303,    31,    32,    39,     3,
       9,    24,    37,    38,   111,    15,    21,   114,    15,    13,
      40,    47,    51,    51,    27,   111,    55,    55,   114,    23,
       6,    25,   232,   119,    22,     0,    10,    34,    51,   125,
      60,    55,    55,    21,    70,    21,    45,    46,    77,    15,
      55,    51,    51,    52,    48,    54,    55,    60,    57,    53,
      59,    72,   360,    21,    77,    64,    24,   290,    42,    63,
     270,    65,   166,    51,    62,     9,   299,    71,    56,    34,
      79,    80,    76,   108,    78,    40,    85,    75,    82,    77,
      24,     8,    56,    51,    52,    34,   102,    14,   123,     9,
      15,    40,    19,    54,     6,    60,    16,   330,   141,   309,
      74,    45,    46,    64,    16,    27,     5,    51,    52,    31,
      54,    55,   430,    57,    55,    59,   434,   350,   436,   152,
      64,    30,   440,    34,    31,    34,    33,   337,    10,    40,
      15,    16,    55,    77,   183,    79,    80,    26,    27,    55,
      12,   459,   183,     4,   462,    79,    16,   251,    51,   184,
     191,    42,   362,    41,   189,   196,   366,    15,    68,    16,
     195,   392,    15,    34,    72,    34,    16,    73,    15,     6,
     205,    16,    55,   213,   384,    42,    57,   212,    30,    72,
     213,   221,   397,    15,   291,    72,    16,    41,   221,   353,
     354,    16,   227,    21,    30,    55,    55,    16,    16,    55,
     410,   234,   237,   413,    43,   415,   255,    55,   441,    72,
      72,    16,    15,    55,   255,     6,   426,    72,   253,    16,
      55,   328,    16,    72,    16,    42,    42,    29,   263,    15,
      15,    27,    72,    21,   444,    37,    38,    39,   271,    15,
      42,    15,    44,   453,   454,    56,    73,    49,    50,    16,
      15,    72,    16,    16,   289,    57,    58,    55,   293,    16,
      15,    33,    24,   298,    15,    15,   430,     9,    21,   304,
     434,   303,   436,    15,    15,   310,   440,    16,    27,    21,
     315,    15,    72,    16,    55,    60,    15,    15,    42,    16,
      15,   326,   327,    15,    15,   459,    15,   252,   462,    16,
     335,   236,    42,    45,    46,   255,   302,   389,   202,    51,
      52,   274,    54,    55,   306,    57,   310,    59,   161,   139,
     153,   356,    64,   154,   158,   417,   155,   375,   360,     7,
       8,     9,    42,    11,   451,   460,    14,    79,    80,    17,
     375,    19,    20,   457,   379,    -1,   119,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    32,   390,    34,    35,    36,   394,
      -1,    -1,    40,    41,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,   407,    51,    52,    -1,    54,    55,    56,    57,
      -1,    59,   417,    61,    -1,    -1,    64,    -1,    66,    67,
      -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    80,    81,    -1,    83,    84,    85,    -1,    -1,
      -1,    -1,    -1,   448,    -1,    -1,   451,    -1,    -1,    -1,
      -1,   456,     7,     8,     9,    -1,    11,    -1,    -1,    14,
      -1,   466,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,
      35,    36,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      45,    46,    -1,    -1,    -1,    -1,    51,    52,    -1,    54,
      55,    -1,    57,    -1,    59,    -1,    61,    -1,    -1,    64,
      -1,    66,    67,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    80,    81,    -1,    83,    84,
      85,     7,     8,     9,    -1,    11,    -1,    -1,    14,    -1,
      -1,    17,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    35,
      36,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,    45,
      46,    -1,    -1,    -1,    -1,    51,    52,    -1,    54,    55,
      -1,    57,     9,    59,    -1,    61,    -1,    -1,    64,    -1,
      66,    67,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    80,    81,    -1,    83,    84,    85,
       7,    -1,     9,    -1,    11,    -1,    -1,    -1,    45,    46,
      17,    -1,    -1,    20,    51,    52,    -1,    54,    55,    -1,
      57,    -1,    59,    -1,    -1,    32,    -1,    64,    35,    36,
      -1,    -1,    -1,    70,    41,    -1,    -1,    -1,    45,    46,
      -1,    -1,    79,    80,    51,    52,    -1,    54,    55,    56,
      57,     7,    59,     9,    61,    11,    -1,    64,    -1,    66,
      67,    17,    69,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    80,    -1,    -1,    32,    -1,    85,    35,
      36,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    45,
      46,    -1,    -1,    -1,     9,    51,    52,    -1,    54,    55,
      56,    57,    -1,    59,    -1,    61,    21,    -1,    64,    -1,
      66,    67,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    80,    -1,     9,    -1,    -1,    85,
      45,    46,    -1,    -1,    -1,    -1,    51,    52,    -1,    54,
      55,    24,    57,     9,    59,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    79,    80,    -1,    -1,    51,    52,
      -1,    54,    55,     9,    57,    -1,    59,    -1,    -1,    45,
      46,    64,    -1,    -1,    -1,    51,    52,     9,    54,    55,
      -1,    57,    -1,    59,    -1,    -1,    79,    80,    64,    -1,
      -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    79,    80,    51,    52,    -1,    54,    55,
      -1,    57,    -1,    59,    46,    -1,    -1,    -1,    64,    51,
      52,    -1,    54,    55,    -1,    57,    -1,    59,    -1,    -1,
      -1,    46,    64,    79,    80,    -1,    51,    52,    -1,    54,
      55,    -1,    -1,    -1,    59,    -1,    -1,    79,    80,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    80
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    87,    88,    90,     0,     7,     8,     9,    11,    14,
      17,    19,    20,    28,    32,    34,    35,    36,    40,    41,
      45,    46,    51,    52,    54,    55,    56,    57,    59,    61,
      64,    66,    67,    69,    79,    80,    81,    83,    84,    85,
      89,    91,    93,    94,    95,   106,   107,   109,   110,   114,
     119,   120,   121,   122,   123,   124,   125,   126,   129,   130,
     131,   140,   142,   143,   144,   145,   147,   148,   149,   153,
     165,   167,   168,   169,   170,   172,   173,   174,   175,   177,
     179,   181,   182,   183,   185,   190,   193,   203,   208,   224,
     165,    55,   139,   165,   223,    55,    55,   172,   201,   172,
     201,   132,   225,    55,   165,   135,   138,   139,    15,    97,
      99,   165,   189,   204,   165,   186,   187,   192,   224,   165,
     188,   191,   169,    70,   116,   165,   165,   203,    15,   165,
     155,   165,   203,    91,    95,   208,   108,   115,    40,    60,
     166,     5,    29,    37,    38,    39,    42,    44,    49,    50,
      57,    58,   171,    10,    12,     4,    47,    70,   176,    54,
      64,   178,    22,    62,    75,    77,   180,   181,   184,    79,
       3,    13,    23,    25,    48,    53,    63,    65,    71,    76,
      78,    82,   112,   113,    16,    21,    51,    56,     9,    16,
      15,    51,    51,    96,   202,    42,    42,    41,    21,   139,
     141,    15,    16,     6,   165,    15,    24,    51,    55,    77,
     101,   103,    15,    34,   115,   207,   221,    68,   115,   221,
      72,    34,   115,   218,    73,   165,   115,    16,   128,    56,
     107,   159,    15,   154,     6,    56,    74,    16,   167,   168,
     169,    57,    42,   172,   173,   174,   175,   177,   179,   181,
      21,    24,    51,    52,   194,    30,   111,   203,   224,   165,
      55,    92,   210,   211,   165,   159,   203,   209,    72,    97,
      15,    16,   165,   203,    51,    55,    77,   133,   134,   136,
      16,   159,   135,    55,   165,    55,   103,   104,    55,    30,
      98,   165,   201,    16,   102,   102,   201,   102,    16,   117,
     118,   102,   165,    43,    31,    33,   150,   156,   159,    15,
      16,   172,    56,   109,   165,    27,    55,   181,    92,    21,
     165,   195,   197,   198,   111,    72,    24,    77,   165,   214,
     215,    72,    72,   159,   172,    16,   127,    15,   136,     6,
     137,    55,   146,   105,    72,    16,   100,   165,    16,   102,
     205,   206,   221,    42,    42,   165,    16,   102,   127,   106,
     160,   165,    15,    27,   151,   156,    15,    27,   159,   155,
     165,    72,    21,    73,   196,    15,    56,   165,   165,    30,
     216,   221,    16,   102,    15,   165,   159,    72,    55,    16,
      26,    27,    16,    24,    16,   102,   167,    45,   161,   163,
     164,   167,   165,    18,   106,     6,    16,   157,   158,   159,
      15,    33,   152,    15,   159,    15,    21,    16,   165,   198,
     212,   165,   159,    27,   134,   165,    15,   103,    55,   165,
      40,   220,   221,   222,    15,    97,    40,   217,   218,   219,
      16,   162,   165,   159,    15,   159,   159,   197,    15,   199,
     200,    16,   213,    15,    15,   159,    15,   163,   163,    15,
     163,   163,    16,   102,   159,   165,    24,   215,   159,   159,
     165,   220,   163,   217,   163,   165
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
     141,   141,   142,   142,   143,   143,   144,   144,   144,   144,
     144,   144,   144,   144,   145,   145,   146,   146,   147,   147,
     148,   148,   149,   149,   150,   150,   151,   151,   152,   152,
     153,   154,   154,   155,   155,   156,   156,   157,   157,   158,
     158,   159,   159,   160,   160,   161,   161,   162,   162,   163,
     163,   164,   164,   165,   165,   166,   166,   167,   167,   168,
     168,   169,   169,   170,   170,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   171,   172,   172,   173,   173,
     174,   174,   175,   175,   176,   176,   177,   177,   178,   178,
     179,   179,   180,   180,   180,   180,   181,   181,   182,   182,
     182,   183,   183,   184,   184,   185,   185,   185,   185,   185,
     185,   185,   186,   186,   187,   187,   188,   188,   189,   189,
     190,   190,   191,   191,   192,   192,   193,   193,   194,   194,
     194,   195,   195,   196,   196,   197,   197,   197,   198,   198,
     199,   199,   200,   200,   201,   201,   202,   202,   203,   203,
     204,   204,   205,   205,   206,   206,   207,   207,   208,   208,
     209,   209,   210,   211,   211,   212,   212,   213,   213,   214,
     214,   214,   215,   215,   216,   216,   217,   217,   218,   218,
     219,   219,   220,   220,   221,   221,   222,   222,   223,   223,
     224,   224,   225,   225
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
       1,     1,     1,     1,     1,     0,     1,     0,     1,     0,
       2,     1,     2,     3,     2,     3,     4,     3,     3,     3,
       2,     3,     2,     3,     0,     3,     1,     4,     1,     0,
       1,     0,     2,     1,     3,     2,     3,     0,     3,     2,
       4,     2,     5,     0,     1,     2,     1,     2,     7,     4,
       1,     0,     2,     3,     0,     3,     0,     3,     0,     2,
       4,     2,     2,     3,     1,     0,     1,     1,     5,     4,
       3,     2,     1,     1,     5,     4,     3,     2,     1,     3,
       2,     1,     2,     0
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
#line 41 "parse.y" /* yacc.c:1646  */
    { printResult(); }
#line 1892 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 69 "parse.y" /* yacc.c:1646  */
    {
		if((yylsp[-4]).first_line > 0) {
			func_nest++;
			complexity++;
			printf("nest+\n");
		}
		else {
			printf("com %d\n", complexity);
			complexity = 1;
		}
		printf("name - %s\n", (yyvsp[-3].str)); 
		pre_firstline = (yylsp[-4]).first_line;
	}
#line 1910 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 289 "parse.y" /* yacc.c:1646  */
    {
		printf("fl %d, fc %d, ll %d, lc %d\n",(yylsp[0]).first_line,(yylsp[0]).first_column,(yylsp[0]).last_line,(yylsp[0]).last_column); }
#line 1917 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 291 "parse.y" /* yacc.c:1646  */
    {
		complexity++; }
#line 1924 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 293 "parse.y" /* yacc.c:1646  */
    { 
		complexity++; }
#line 1931 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 295 "parse.y" /* yacc.c:1646  */
    {
		complexity++; }
#line 1938 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 297 "parse.y" /* yacc.c:1646  */
    {
		complexity++; }
#line 1945 "parse.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 299 "parse.y" /* yacc.c:1646  */
    {
		complexity++; }
#line 1952 "parse.tab.c" /* yacc.c:1646  */
    break;


#line 1956 "parse.tab.c" /* yacc.c:1646  */
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
#line 649 "parse.y" /* yacc.c:1906  */


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
	printf("Complexity : %d\n", complexity);
}


