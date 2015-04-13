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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         HSQL_STYPE
#define YYLTYPE         HSQL_LTYPE
/* Substitute the variable and function names.  */
#define yyparse         hsql_parse
#define yylex           hsql_lex
#define yyerror         hsql_error
#define yydebug         hsql_debug
#define yynerrs         hsql_nerrs


/* Copy the first part of user declarations.  */
#line 1 "bison_parser.y" /* yacc.c:339  */

/**
 * bison_parser.y
 * defines bison_parser.h
 * outputs bison_parser.c
 *
 * Grammar File Spec: http://dinosaur.compilertools.net/bison/bison_6.html
 *
 */
/*********************************
 ** Section 1: C Declarations
 *********************************/

#include "sqllib.h"
#include "bison_parser.h"
#include "flex_lexer.h"

#include <stdio.h>

using namespace hsql;

int yyerror(YYLTYPE* llocp, SQLStatementList** result, yyscan_t scanner, const char *msg) {

	SQLStatementList* list = new SQLStatementList();
	list->isValid = false;
	list->parser_msg = strdup(msg);
	list->error_line = llocp->first_line;
	list->error_col = llocp->first_column;

	*result = list;
	return 0;
}




#line 111 "bison_parser.cpp" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "bison_parser.h".  */
#ifndef YY_HSQL_BISON_PARSER_H_INCLUDED
# define YY_HSQL_BISON_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef HSQL_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define HSQL_DEBUG 1
#  else
#   define HSQL_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define HSQL_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined HSQL_DEBUG */
#if HSQL_DEBUG
extern int hsql_debug;
#endif
/* "%code requires" blocks.  */
#line 43 "bison_parser.y" /* yacc.c:355  */

// %code requires block
#include "parser_typedef.h"

// Auto update column and line number
#define YY_USER_ACTION \
    yylloc->first_line = yylloc->last_line; \
    yylloc->first_column = yylloc->last_column; \
    for(int i = 0; yytext[i] != '\0'; i++) { \
    	yylloc->total_column++; \
        if(yytext[i] == '\n') { \
            yylloc->last_line++; \
            yylloc->last_column = 0; \
        } \
        else { \
            yylloc->last_column++; \
        } \
    }

#line 169 "bison_parser.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef HSQL_TOKENTYPE
# define HSQL_TOKENTYPE
  enum hsql_tokentype
  {
    SQL_IDENTIFIER = 258,
    SQL_STRING = 259,
    SQL_FLOATVAL = 260,
    SQL_INTVAL = 261,
    SQL_NOTEQUALS = 262,
    SQL_LESSEQ = 263,
    SQL_GREATEREQ = 264,
    SQL_DEALLOCATE = 265,
    SQL_PARAMETERS = 266,
    SQL_INTERSECT = 267,
    SQL_TEMPORARY = 268,
    SQL_TIMESTAMP = 269,
    SQL_DISTINCT = 270,
    SQL_GROUPKEY = 271,
    SQL_NVARCHAR = 272,
    SQL_RESTRICT = 273,
    SQL_TRUNCATE = 274,
    SQL_ANALYZE = 275,
    SQL_BETWEEN = 276,
    SQL_CASCADE = 277,
    SQL_COLUMNS = 278,
    SQL_CONTROL = 279,
    SQL_DEFAULT = 280,
    SQL_EXECUTE = 281,
    SQL_EXPLAIN = 282,
    SQL_HISTORY = 283,
    SQL_INTEGER = 284,
    SQL_NATURAL = 285,
    SQL_PREPARE = 286,
    SQL_PRIMARY = 287,
    SQL_SCHEMAS = 288,
    SQL_SPATIAL = 289,
    SQL_VIRTUAL = 290,
    SQL_BEFORE = 291,
    SQL_COLUMN = 292,
    SQL_CREATE = 293,
    SQL_DELETE = 294,
    SQL_DIRECT = 295,
    SQL_DOUBLE = 296,
    SQL_ESCAPE = 297,
    SQL_EXCEPT = 298,
    SQL_EXISTS = 299,
    SQL_GLOBAL = 300,
    SQL_HAVING = 301,
    SQL_IMPORT = 302,
    SQL_INSERT = 303,
    SQL_ISNULL = 304,
    SQL_OFFSET = 305,
    SQL_RENAME = 306,
    SQL_SCHEMA = 307,
    SQL_SELECT = 308,
    SQL_SORTED = 309,
    SQL_TABLES = 310,
    SQL_UNIQUE = 311,
    SQL_UNLOAD = 312,
    SQL_UPDATE = 313,
    SQL_VALUES = 314,
    SQL_AFTER = 315,
    SQL_ALTER = 316,
    SQL_CROSS = 317,
    SQL_DELTA = 318,
    SQL_GROUP = 319,
    SQL_INDEX = 320,
    SQL_INNER = 321,
    SQL_LIMIT = 322,
    SQL_LOCAL = 323,
    SQL_MERGE = 324,
    SQL_MINUS = 325,
    SQL_ORDER = 326,
    SQL_OUTER = 327,
    SQL_RIGHT = 328,
    SQL_TABLE = 329,
    SQL_UNION = 330,
    SQL_USING = 331,
    SQL_WHERE = 332,
    SQL_CALL = 333,
    SQL_DATE = 334,
    SQL_DESC = 335,
    SQL_DROP = 336,
    SQL_FILE = 337,
    SQL_FROM = 338,
    SQL_FULL = 339,
    SQL_HASH = 340,
    SQL_HINT = 341,
    SQL_INTO = 342,
    SQL_JOIN = 343,
    SQL_LEFT = 344,
    SQL_LIKE = 345,
    SQL_LOAD = 346,
    SQL_NULL = 347,
    SQL_PART = 348,
    SQL_PLAN = 349,
    SQL_SHOW = 350,
    SQL_TEXT = 351,
    SQL_TIME = 352,
    SQL_VIEW = 353,
    SQL_WITH = 354,
    SQL_ADD = 355,
    SQL_ALL = 356,
    SQL_AND = 357,
    SQL_ASC = 358,
    SQL_CSV = 359,
    SQL_FOR = 360,
    SQL_INT = 361,
    SQL_KEY = 362,
    SQL_NOT = 363,
    SQL_OFF = 364,
    SQL_SET = 365,
    SQL_TBL = 366,
    SQL_TOP = 367,
    SQL_AS = 368,
    SQL_BY = 369,
    SQL_IF = 370,
    SQL_IN = 371,
    SQL_IS = 372,
    SQL_OF = 373,
    SQL_ON = 374,
    SQL_OR = 375,
    SQL_TO = 376,
    SQL_EQUALS = 377,
    SQL_LESS = 378,
    SQL_GREATER = 379,
    SQL_NOTNULL = 380,
    SQL_UMINUS = 381
  };
#endif

/* Value type.  */
#if ! defined HSQL_STYPE && ! defined HSQL_STYPE_IS_DECLARED
typedef union HSQL_STYPE HSQL_STYPE;
union HSQL_STYPE
{
#line 99 "bison_parser.y" /* yacc.c:355  */

	double fval;
	int64_t ival;
	char* sval;
	uint uval;
	bool bval;

	hsql::SQLStatement* statement;
	hsql::SelectStatement* 	select_stmt;
	hsql::ImportStatement* 	import_stmt;
	hsql::CreateStatement* 	create_stmt;
	hsql::InsertStatement* 	insert_stmt;
	hsql::DeleteStatement* 	delete_stmt;
	hsql::UpdateStatement* 	update_stmt;
	hsql::DropStatement*   	drop_stmt;
	hsql::PrepareStatement* prep_stmt;
	hsql::ExecuteStatement* exec_stmt;

	hsql::TableRef* table;
	hsql::Expr* expr;
	hsql::OrderDescription* order;
	hsql::OrderType order_type;
	hsql::LimitDescription* limit;
	hsql::ColumnDefinition* column_t;
	hsql::GroupByDescription* group_t;
	hsql::UpdateClause* update_t;

	hsql::SQLStatementList* stmt_list;

	std::vector<char*>* str_vec;
	std::vector<hsql::TableRef*>* table_vec;
	std::vector<hsql::ColumnDefinition*>* column_vec;
	std::vector<hsql::UpdateClause*>* update_vec;
	std::vector<hsql::Expr*>* expr_vec;

#line 344 "bison_parser.cpp" /* yacc.c:355  */
};
# define HSQL_STYPE_IS_TRIVIAL 1
# define HSQL_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined HSQL_LTYPE && ! defined HSQL_LTYPE_IS_DECLARED
typedef struct HSQL_LTYPE HSQL_LTYPE;
struct HSQL_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define HSQL_LTYPE_IS_DECLARED 1
# define HSQL_LTYPE_IS_TRIVIAL 1
#endif



int hsql_parse (hsql::SQLStatementList** result, yyscan_t scanner);

#endif /* !YY_HSQL_BISON_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 372 "bison_parser.cpp" /* yacc.c:358  */

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
         || (defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL \
             && defined HSQL_STYPE_IS_TRIVIAL && HSQL_STYPE_IS_TRIVIAL)))

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
#define YYFINAL  50
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   454

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  147
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  150
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  269

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   381

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   133,     2,     2,
     138,   139,   131,   129,   145,   130,   140,   132,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   142,   141,
     124,   122,   125,   146,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   136,     2,   137,   134,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   143,     2,   144,     2,     2,     2,     2,
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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   123,   126,   127,
     128,   135
};

#if HSQL_DEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   229,   229,   236,   237,   241,   246,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   267,   272,   280,   284,
     296,   304,   308,   318,   324,   330,   337,   347,   348,   352,
     353,   357,   358,   362,   369,   370,   371,   372,   384,   388,
     392,   404,   412,   424,   430,   440,   441,   451,   460,   461,
     465,   477,   478,   482,   483,   487,   492,   504,   505,   506,
     510,   521,   522,   526,   531,   536,   537,   541,   546,   550,
     551,   554,   555,   559,   560,   561,   566,   567,   568,   575,
     576,   580,   581,   585,   592,   593,   594,   595,   596,   600,
     601,   602,   606,   607,   611,   612,   613,   614,   615,   616,
     617,   618,   619,   620,   621,   626,   627,   628,   629,   630,
     631,   635,   639,   640,   644,   645,   646,   650,   655,   656,
     660,   664,   669,   680,   681,   691,   692,   698,   703,   704,
     709,   719,   727,   728,   733,   734,   738,   739,   747,   759,
     760,   761,   762,   763,   769,   775,   779,   788,   789,   794,
     795
};
#endif

#if HSQL_DEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "FLOATVAL",
  "INTVAL", "NOTEQUALS", "LESSEQ", "GREATEREQ", "DEALLOCATE", "PARAMETERS",
  "INTERSECT", "TEMPORARY", "TIMESTAMP", "DISTINCT", "GROUPKEY",
  "NVARCHAR", "RESTRICT", "TRUNCATE", "ANALYZE", "BETWEEN", "CASCADE",
  "COLUMNS", "CONTROL", "DEFAULT", "EXECUTE", "EXPLAIN", "HISTORY",
  "INTEGER", "NATURAL", "PREPARE", "PRIMARY", "SCHEMAS", "SPATIAL",
  "VIRTUAL", "BEFORE", "COLUMN", "CREATE", "DELETE", "DIRECT", "DOUBLE",
  "ESCAPE", "EXCEPT", "EXISTS", "GLOBAL", "HAVING", "IMPORT", "INSERT",
  "ISNULL", "OFFSET", "RENAME", "SCHEMA", "SELECT", "SORTED", "TABLES",
  "UNIQUE", "UNLOAD", "UPDATE", "VALUES", "AFTER", "ALTER", "CROSS",
  "DELTA", "GROUP", "INDEX", "INNER", "LIMIT", "LOCAL", "MERGE", "MINUS",
  "ORDER", "OUTER", "RIGHT", "TABLE", "UNION", "USING", "WHERE", "CALL",
  "DATE", "DESC", "DROP", "FILE", "FROM", "FULL", "HASH", "HINT", "INTO",
  "JOIN", "LEFT", "LIKE", "LOAD", "NULL", "PART", "PLAN", "SHOW", "TEXT",
  "TIME", "VIEW", "WITH", "ADD", "ALL", "AND", "ASC", "CSV", "FOR", "INT",
  "KEY", "NOT", "OFF", "SET", "TBL", "TOP", "AS", "BY", "IF", "IN", "IS",
  "OF", "ON", "OR", "TO", "'='", "EQUALS", "'<'", "'>'", "LESS", "GREATER",
  "NOTNULL", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "UMINUS", "'['",
  "']'", "'('", "')'", "'.'", "';'", "':'", "'{'", "'}'", "','", "'?'",
  "$accept", "input", "statement_list", "statement",
  "preparable_statement", "prepare_statement", "execute_statement",
  "import_statement", "import_file_type", "file_path", "create_statement",
  "create_index_statement", "opt_index_type", "opt_not_exists",
  "column_def_commalist", "column_def", "column_type", "drop_statement",
  "delete_statement", "truncate_statement", "insert_statement",
  "opt_column_list", "update_statement", "update_clause_commalist",
  "update_clause", "select_statement", "select_with_paren",
  "select_no_paren", "set_operator", "select_clause", "opt_distinct",
  "select_list", "from_clause", "opt_where", "opt_group", "opt_having",
  "opt_order", "opt_order_type", "opt_limit", "expr_list", "literal_list",
  "expr_alias", "expr", "scalar_expr", "unary_expr", "binary_expr",
  "comp_expr", "function_expr", "column_name", "literal", "string_literal",
  "num_literal", "int_literal", "star_expr", "placeholder_expr",
  "table_ref", "table_ref_atomic", "table_ref_commalist", "table_ref_name",
  "table_ref_name_no_alias", "table_name", "alias", "opt_alias",
  "join_clause", "opt_join_type", "join_table", "join_condition",
  "opt_semicolon", "ident_commalist", YY_NULLPTR
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
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,    61,   377,    60,    62,   378,   379,   380,    43,
      45,    42,    47,    37,    94,   381,    91,    93,    40,    41,
      46,    59,    58,   123,   125,    44,    63
};
# endif

#define YYPACT_NINF -219

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-219)))

#define YYTABLE_NINF -146

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-146)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     206,    23,    25,    76,    87,    11,    38,    41,    39,    83,
      25,   -33,   -34,   125,   -14,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
      12,   126,    -8,  -219,    -5,   -32,  -219,    19,    70,    25,
      35,    25,  -219,     7,    30,  -219,   140,    25,     8,    13,
    -219,   206,  -219,  -219,  -219,    32,  -219,    96,    84,  -219,
     147,    10,   209,   206,    47,    25,   155,    82,  -219,    79,
      28,   -98,  -219,  -219,  -219,     7,     7,  -219,     7,  -219,
      85,    22,  -219,   109,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,   173,  -219,  -219,  -219,
    -219,  -219,     7,   106,   172,  -219,  -219,  -101,  -219,  -219,
     -14,   136,   -50,    66,     7,  -219,   182,   184,    -3,    83,
     185,   307,   -57,    40,     3,    82,     7,  -219,     7,     7,
       7,     7,     7,    99,   189,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,  -219,  -219,    72,   -54,  -219,
     175,    84,   146,  -219,    10,    56,  -219,    90,   205,    25,
     243,   123,  -219,  -219,   -61,    75,  -219,     7,  -219,  -219,
     -34,  -219,    69,   -37,    15,  -219,    20,   151,  -219,   320,
     293,   293,   320,   307,     7,  -219,   262,   320,   293,   293,
     -57,   -57,    86,    86,    86,  -219,    10,   173,  -219,  -219,
    -219,  -219,  -219,   172,  -219,  -219,   139,    -7,   -44,  -219,
      80,    25,  -219,   220,    10,    73,    88,     3,  -219,  -219,
    -219,  -219,  -219,   138,   110,  -219,   320,  -219,  -219,  -219,
     182,  -219,  -219,  -219,  -219,  -219,  -219,   205,   184,  -219,
    -219,   -42,  -219,    15,  -219,    91,     6,     7,  -219,  -219,
     -25,  -219,    34,     3,   -34,  -219,   111,   -43,  -219,  -219,
     107,     7,     7,  -219,    15,   243,  -219,   243,  -219
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    28,     0,     0,     0,    62,
       0,     0,     0,     0,   148,     3,     6,     5,    15,     8,
       9,    25,    14,    11,    12,    10,    13,     7,    51,    52,
      72,     0,   132,    42,    18,     0,    27,    30,     0,     0,
       0,     0,    61,     0,     0,   131,     0,     0,     0,     0,
       1,   147,     2,    58,    59,     0,    57,     0,    78,    39,
       0,     0,     0,     0,     0,     0,     0,    66,    21,     0,
      46,   112,   117,   118,   120,     0,     0,   121,     0,   122,
       0,    63,    79,   137,    85,    86,    87,    94,    88,    89,
      91,   114,   115,   119,    90,   116,     0,    40,    38,    54,
      53,     4,     0,    72,     0,    55,   133,     0,    81,    16,
     148,     0,     0,     0,     0,    41,     0,     0,     0,    62,
       0,    93,    92,     0,     0,    66,     0,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   136,    83,     0,    66,    48,
      75,    78,    76,    19,     0,     0,    29,     0,     0,     0,
      65,     0,    22,   149,     0,     0,    44,     0,   113,    84,
       0,    64,   123,   125,   137,   127,   143,    68,    80,   106,
     109,   110,   103,   101,     0,   134,   102,   105,   107,   108,
      96,    95,    98,    97,    99,   100,     0,     0,    47,    74,
      73,    71,    56,     0,    82,    17,     0,     0,     0,    31,
       0,     0,    45,     0,     0,     0,     0,     0,   130,   139,
     140,   142,   141,     0,     0,    60,   104,    50,    49,    77,
       0,    35,    36,    37,    34,    33,    24,     0,     0,    20,
     150,     0,   111,     0,   128,   124,     0,     0,    23,    32,
       0,    43,   126,     0,     0,   145,     0,    70,    26,   129,
       0,     0,     0,    67,     0,   146,   138,    69,   144
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -219,  -219,   186,   207,   198,  -219,  -219,  -219,  -219,    31,
    -219,  -219,  -219,  -219,  -219,    26,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,    71,  -149,   254,   -10,  -219,   215,
     154,  -219,  -219,   -95,  -219,  -219,   171,  -219,   124,    29,
      65,   156,   -71,  -219,  -219,  -219,  -219,  -219,  -219,   -60,
     -99,  -219,   -84,  -219,  -219,  -219,  -191,  -219,    42,  -219,
      -2,  -218,   112,  -219,  -219,    43,  -219,   170,    46
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,    15,    16,    17,    18,    19,    69,   161,
      20,    21,    38,    65,   208,   209,   235,    22,    23,    24,
      25,   118,    26,   148,   149,    27,    28,    29,    57,    30,
      43,    80,   125,   115,   225,   263,    58,   201,   105,    81,
     107,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,   171,   172,   245,   173,    44,
     174,   145,   146,   175,   223,   176,   266,    52,   164
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,   108,    49,   262,   121,   122,    32,   123,    45,    32,
      71,    72,    73,    74,    72,    73,    74,   162,   127,     9,
     152,   216,   231,   114,    53,   252,   244,    36,    32,  -145,
     177,   150,    46,   157,   232,  -145,  -145,    67,   153,    70,
     119,    47,   120,   160,   154,    98,   268,   128,   129,   130,
       9,  -145,  -145,   198,    31,    54,   165,   179,   180,   181,
     182,   183,   259,   112,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   141,   142,   143,   144,   212,    34,
     128,   129,   130,    55,   213,    37,   219,    56,   158,   233,
      35,   197,   220,   221,   204,   236,   215,   251,    42,   234,
    -144,   237,   126,   154,    12,   260,  -144,  -144,   166,   222,
      62,    63,   127,   226,   258,    75,   128,   129,   130,   229,
     213,    39,  -144,  -144,    40,    50,    41,    51,   134,    59,
     131,   162,    60,    61,    64,    66,   227,    76,    77,    68,
      96,   170,   132,    97,   254,    78,   102,    99,   133,     9,
     106,   104,   100,    79,   108,   111,    79,   210,   113,   114,
     135,   116,   136,   131,   137,   138,   117,   126,   124,   139,
     140,   141,   142,   143,   144,   132,   147,    55,    74,   169,
     156,   133,   128,   129,   130,   159,    72,   163,   168,   184,
     265,   267,   185,   135,   196,   136,   203,   137,   138,   131,
     205,   206,   139,   140,   141,   142,   143,   144,   207,   239,
     211,   132,   242,   214,   217,   224,     1,   133,   238,     1,
     144,   230,   134,   240,   247,     2,   246,   243,     2,   135,
     261,   136,     3,   137,   138,     3,   253,     4,   139,   140,
     141,   142,   143,   144,     5,     6,   264,     5,     6,   110,
     128,   129,   130,     7,     8,   199,     7,     8,   101,     9,
     109,   248,     9,   249,    10,   131,    48,    10,   228,   128,
     129,   130,   103,   167,   151,   202,   257,   132,   200,   241,
     155,     0,   178,   133,   250,     0,   218,    11,   255,   256,
      11,     0,     0,     0,     0,   135,     0,   136,     0,   137,
     138,  -146,  -146,     0,   139,   140,   141,   142,   143,   144,
       0,     0,     0,     0,   128,   129,   130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   128,   129,   130,
       0,     0,     0,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,   132,     0,    12,     0,     0,
       0,   133,   131,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   135,   132,   136,     0,   137,   138,     0,
     133,     0,   139,   140,   141,   142,   143,   144,     0,     0,
       0,     0,     0,     0,   136,     0,   137,   138,     0,     0,
       0,   139,   140,   141,   142,   143,   144,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     131,     0,     0,     0,     0,   133,     0,  -146,  -146,     0,
       0,     0,   139,   140,   141,   142,   143,   144,     0,   136,
       0,   137,   138,     0,     0,     0,   139,   140,   141,   142,
     143,   144,   136,     0,   137,   138,     0,     0,     0,   139,
     140,   141,   142,   143,   144
};

static const yytype_int16 yycheck[] =
{
       2,    61,    12,    46,    75,    76,     3,    78,    10,     3,
       3,     4,     5,     6,     4,     5,     6,   116,     3,    53,
     104,   170,    29,    77,    12,   243,   217,    16,     3,    66,
     125,   102,    65,    83,    41,    72,    73,    39,   139,    41,
     138,    74,   140,   114,   145,    47,   264,     7,     8,     9,
      53,    88,    89,   148,    31,    43,    59,   128,   129,   130,
     131,   132,   253,    65,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   131,   132,   133,   134,   139,     3,
       7,     8,     9,    71,   145,    74,    66,    75,   138,    96,
       3,   145,    72,    73,   154,   139,   167,   139,    15,   106,
      66,   145,   145,   145,   138,   254,    72,    73,   118,    89,
     142,   143,     3,   184,   139,   108,     7,     8,     9,   203,
     145,    83,    88,    89,    83,     0,    87,   141,   113,     3,
      90,   230,   140,   138,   115,    65,   196,   130,   131,   104,
     110,   138,   102,     3,   138,   138,   114,   139,   108,    53,
       3,    67,   139,   146,   214,   108,   146,   159,     3,    77,
     120,    82,   122,    90,   124,   125,   138,   145,    83,   129,
     130,   131,   132,   133,   134,   102,     3,    71,     6,   139,
      44,   108,     7,     8,     9,   119,     4,     3,     3,    90,
     261,   262,     3,   120,   122,   122,    50,   124,   125,    90,
     144,   111,   129,   130,   131,   132,   133,   134,     3,   211,
      87,   102,   139,   138,   145,    64,    10,   108,   138,    10,
     134,    82,   113,     3,   114,    19,    88,   139,    19,   120,
     119,   122,    26,   124,   125,    26,   145,    31,   129,   130,
     131,   132,   133,   134,    38,    39,   139,    38,    39,    63,
       7,     8,     9,    47,    48,    80,    47,    48,    51,    53,
      62,   230,    53,   237,    58,    90,    12,    58,   197,     7,
       8,     9,    57,   119,   103,   151,   247,   102,   103,   214,
     110,    -1,   126,   108,   238,    -1,   174,    81,   246,   246,
      81,    -1,    -1,    -1,    -1,   120,    -1,   122,    -1,   124,
     125,     8,     9,    -1,   129,   130,   131,   132,   133,   134,
      -1,    -1,    -1,    -1,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,     8,     9,
      -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   138,   102,    -1,   138,    -1,    -1,
      -1,   108,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   120,   102,   122,    -1,   124,   125,    -1,
     108,    -1,   129,   130,   131,   132,   133,   134,    -1,    -1,
      -1,    -1,    -1,    -1,   122,    -1,   124,   125,    -1,    -1,
      -1,   129,   130,   131,   132,   133,   134,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    -1,    -1,   108,    -1,   124,   125,    -1,
      -1,    -1,   129,   130,   131,   132,   133,   134,    -1,   122,
      -1,   124,   125,    -1,    -1,    -1,   129,   130,   131,   132,
     133,   134,   122,    -1,   124,   125,    -1,    -1,    -1,   129,
     130,   131,   132,   133,   134
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    19,    26,    31,    38,    39,    47,    48,    53,
      58,    81,   138,   148,   149,   150,   151,   152,   153,   154,
     157,   158,   164,   165,   166,   167,   169,   172,   173,   174,
     176,    31,     3,   207,     3,     3,    16,    74,   159,    83,
      83,    87,    15,   177,   206,   207,    65,    74,   173,   174,
       0,   141,   214,    12,    43,    71,    75,   175,   183,     3,
     140,   138,   142,   143,   115,   160,    65,   207,   104,   155,
     207,     3,     4,     5,     6,   108,   130,   131,   138,   146,
     178,   186,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   110,     3,   207,   139,
     139,   150,   114,   176,    67,   185,     3,   187,   196,   151,
     149,   108,   207,     3,    77,   180,    82,   138,   168,   138,
     140,   189,   189,   189,    83,   179,   145,     3,     7,     8,
       9,    90,   102,   108,   113,   120,   122,   124,   125,   129,
     130,   131,   132,   133,   134,   208,   209,     3,   170,   171,
     189,   183,   199,   139,   145,   214,    44,    83,   138,   119,
     189,   156,   197,     3,   215,    59,   174,   177,     3,   139,
     138,   202,   203,   205,   207,   210,   212,   180,   188,   189,
     189,   189,   189,   189,    90,     3,   189,   189,   189,   189,
     189,   189,   189,   189,   189,   189,   122,   145,   180,    80,
     103,   184,   185,    50,   196,   144,   111,     3,   161,   162,
     207,    87,   139,   145,   138,   189,   172,   145,   209,    66,
      72,    73,    89,   211,    64,   181,   189,   196,   171,   199,
      82,    29,    41,    96,   106,   163,   139,   145,   138,   207,
       3,   187,   139,   139,   203,   204,    88,   114,   156,   162,
     215,   139,   208,   145,   138,   205,   212,   186,   139,   203,
     172,   119,    46,   182,   139,   189,   213,   189,   208
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   147,   148,   149,   149,   150,   150,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   152,   152,   153,   153,
     154,   155,   156,   157,   157,   157,   158,   159,   159,   160,
     160,   161,   161,   162,   163,   163,   163,   163,   164,   164,
     164,   165,   166,   167,   167,   168,   168,   169,   170,   170,
     171,   172,   172,   173,   173,   174,   174,   175,   175,   175,
     176,   177,   177,   178,   179,   180,   180,   181,   181,   182,
     182,   183,   183,   184,   184,   184,   185,   185,   185,   186,
     186,   187,   187,   188,   189,   189,   189,   189,   189,   190,
     190,   190,   191,   191,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   193,   193,   193,   193,   193,
     193,   194,   195,   195,   196,   196,   196,   197,   198,   198,
     199,   200,   201,   202,   202,   203,   203,   203,   204,   204,
     205,   206,   207,   207,   208,   208,   209,   209,   210,   211,
     211,   211,   211,   211,   212,   212,   213,   214,   214,   215,
     215
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     6,     2,     5,
       7,     1,     1,     8,     7,     1,     9,     1,     0,     3,
       0,     1,     3,     2,     1,     1,     1,     1,     3,     3,
       3,     4,     2,     8,     5,     3,     0,     5,     1,     3,
       3,     1,     1,     3,     3,     3,     5,     1,     1,     1,
       6,     1,     0,     1,     2,     2,     0,     4,     0,     2,
       0,     4,     0,     1,     1,     0,     2,     4,     0,     1,
       3,     1,     3,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     3,     3,     3,     3,
       3,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     4,     1,     1,     3,
       2,     1,     1,     3,     2,     1,     1,     0,     6,     1,
       1,     1,     1,     0,     4,     1,     1,     1,     0,     1,
       3
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
      yyerror (&yylloc, result, scanner, YY_("syntax error: cannot back up")); \
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
#if HSQL_DEBUG

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
# if defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL

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
                  Type, Value, Location, result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, hsql::SQLStatementList** result, yyscan_t scanner)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, hsql::SQLStatementList** result, yyscan_t scanner)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, result, scanner);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, hsql::SQLStatementList** result, yyscan_t scanner)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, result, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !HSQL_DEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !HSQL_DEBUG */


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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, hsql::SQLStatementList** result, yyscan_t scanner)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (hsql::SQLStatementList** result, yyscan_t scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined HSQL_LTYPE_IS_TRIVIAL && HSQL_LTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

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

/* User initialization code.  */
#line 77 "bison_parser.y" /* yacc.c:1429  */
{
	// Initialize
	yylloc.first_column = 0;
	yylloc.last_column = 0;
	yylloc.first_line = 0;
	yylloc.last_line = 0;
	yylloc.total_column = 0;
	yylloc.placeholder_id = 0;
}

#line 1654 "bison_parser.cpp" /* yacc.c:1429  */
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
      yychar = yylex (&yylval, &yylloc, scanner);
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
#line 229 "bison_parser.y" /* yacc.c:1646  */
    {
			*result = (yyvsp[-1].stmt_list);
		}
#line 1845 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 236 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.stmt_list) = new SQLStatementList((yyvsp[0].statement)); }
#line 1851 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 237 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].stmt_list)->addStatement((yyvsp[0].statement)); (yyval.stmt_list) = (yyvsp[-2].stmt_list); }
#line 1857 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 241 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyvsp[0].prep_stmt)->setPlaceholders(yyloc.placeholder_list);
			yyloc.placeholder_list.clear();
			(yyval.statement) = (yyvsp[0].prep_stmt);
		}
#line 1867 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 251 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].select_stmt); }
#line 1873 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 252 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].import_stmt); }
#line 1879 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 253 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].create_stmt); }
#line 1885 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 254 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].insert_stmt); }
#line 1891 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 255 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 1897 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 256 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].delete_stmt); }
#line 1903 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 257 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].update_stmt); }
#line 1909 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 258 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].drop_stmt); }
#line 1915 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 259 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].exec_stmt); }
#line 1921 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 267 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.prep_stmt) = new PrepareStatement();
			(yyval.prep_stmt)->name = (yyvsp[-2].sval);
			(yyval.prep_stmt)->query = new SQLStatementList((yyvsp[0].statement));
		}
#line 1931 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 272 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.prep_stmt) = new PrepareStatement();
			(yyval.prep_stmt)->name = (yyvsp[-4].sval);
			(yyval.prep_stmt)->query = (yyvsp[-2].stmt_list);
		}
#line 1941 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 280 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.exec_stmt) = new ExecuteStatement();
			(yyval.exec_stmt)->name = (yyvsp[0].sval);
		}
#line 1950 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 284 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.exec_stmt) = new ExecuteStatement();
			(yyval.exec_stmt)->name = (yyvsp[-3].sval);
			(yyval.exec_stmt)->parameters = (yyvsp[-1].expr_vec);
		}
#line 1960 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 296 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.import_stmt) = new ImportStatement((ImportStatement::ImportType) (yyvsp[-4].uval));
			(yyval.import_stmt)->file_path = (yyvsp[-2].sval);
			(yyval.import_stmt)->table_name = (yyvsp[0].sval);
		}
#line 1970 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 304 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = ImportStatement::kImportCSV; }
#line 1976 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 308 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].expr)->name; }
#line 1982 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 318 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.create_stmt) = new CreateStatement(CreateStatement::kTableFromTbl);
			(yyval.create_stmt)->if_not_exists = (yyvsp[-5].bval);
			(yyval.create_stmt)->table_name = (yyvsp[-4].sval);
			(yyval.create_stmt)->file_path = (yyvsp[0].sval);
		}
#line 1993 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 324 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.create_stmt) = new CreateStatement(CreateStatement::kTable);
			(yyval.create_stmt)->if_not_exists = (yyvsp[-4].bval);
			(yyval.create_stmt)->table_name = (yyvsp[-3].sval);
			(yyval.create_stmt)->columns = (yyvsp[-1].column_vec);
		}
#line 2004 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 337 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.create_stmt) = new CreateStatement(CreateStatement::kIndex);
			(yyval.create_stmt)->index_type = (CreateStatement::IndexType) (yyvsp[-7].uval);
			(yyval.create_stmt)->index_name = (yyvsp[-5].sval);
			(yyval.create_stmt)->table_name = (yyvsp[-3].sval);
			(yyval.create_stmt)->index_columns = (yyvsp[-1].str_vec);
		}
#line 2016 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 347 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = CreateStatement::kGroupKeyIndex;}
#line 2022 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 348 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = CreateStatement::kDefaultIndex; }
#line 2028 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 352 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = true; }
#line 2034 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 353 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = false; }
#line 2040 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 357 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.column_vec) = new std::vector<ColumnDefinition*>(); (yyval.column_vec)->push_back((yyvsp[0].column_t)); }
#line 2046 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 358 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].column_vec)->push_back((yyvsp[0].column_t)); (yyval.column_vec) = (yyvsp[-2].column_vec); }
#line 2052 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 362 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.column_t) = new ColumnDefinition((yyvsp[-1].sval), (ColumnDefinition::DataType) (yyvsp[0].uval));
		}
#line 2060 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 369 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = ColumnDefinition::INT; }
#line 2066 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 370 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = ColumnDefinition::INT; }
#line 2072 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 371 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = ColumnDefinition::DOUBLE; }
#line 2078 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 372 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = ColumnDefinition::TEXT; }
#line 2084 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 384 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.drop_stmt) = new DropStatement(DropStatement::kTable);
			(yyval.drop_stmt)->name = (yyvsp[0].sval);
		}
#line 2093 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 388 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.drop_stmt) = new DropStatement(DropStatement::kPreparedStatement);
			(yyval.drop_stmt)->name = (yyvsp[0].sval);
		}
#line 2102 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 392 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.drop_stmt) = new DropStatement(DropStatement::kIndex);
			(yyval.drop_stmt)->name = (yyvsp[0].sval);
		}
#line 2111 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 404 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.delete_stmt) = new DeleteStatement();
			(yyval.delete_stmt)->table_name = (yyvsp[-1].sval);
			(yyval.delete_stmt)->expr = (yyvsp[0].expr);
		}
#line 2121 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 412 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.delete_stmt) = new DeleteStatement();
			(yyval.delete_stmt)->table_name = (yyvsp[0].sval);
		}
#line 2130 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 424 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.insert_stmt) = new InsertStatement(InsertStatement::kInsertValues);
			(yyval.insert_stmt)->table_name = (yyvsp[-5].sval);
			(yyval.insert_stmt)->columns = (yyvsp[-4].str_vec);
			(yyval.insert_stmt)->values = (yyvsp[-1].expr_vec);
		}
#line 2141 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 430 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.insert_stmt) = new InsertStatement(InsertStatement::kInsertSelect);
			(yyval.insert_stmt)->table_name = (yyvsp[-2].sval);
			(yyval.insert_stmt)->columns = (yyvsp[-1].str_vec);
			(yyval.insert_stmt)->select = (yyvsp[0].select_stmt);
		}
#line 2152 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 440 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.str_vec) = (yyvsp[-1].str_vec); }
#line 2158 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 441 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.str_vec) = NULL; }
#line 2164 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 451 "bison_parser.y" /* yacc.c:1646  */
    {
		(yyval.update_stmt) = new UpdateStatement();
		(yyval.update_stmt)->table = (yyvsp[-3].table);
		(yyval.update_stmt)->updates = (yyvsp[-1].update_vec);
		(yyval.update_stmt)->where = (yyvsp[0].expr);
	}
#line 2175 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 460 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.update_vec) = new std::vector<UpdateClause*>(); (yyval.update_vec)->push_back((yyvsp[0].update_t)); }
#line 2181 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 461 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].update_vec)->push_back((yyvsp[0].update_t)); (yyval.update_vec) = (yyvsp[-2].update_vec); }
#line 2187 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 465 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.update_t) = new UpdateClause();
			(yyval.update_t)->column = (yyvsp[-2].sval);
			(yyval.update_t)->value = (yyvsp[0].expr);
		}
#line 2197 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 482 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 2203 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 483 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.select_stmt) = (yyvsp[-1].select_stmt); }
#line 2209 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 487 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.select_stmt) = (yyvsp[-2].select_stmt);
			(yyval.select_stmt)->order = (yyvsp[-1].order);
			(yyval.select_stmt)->limit = (yyvsp[0].limit);
		}
#line 2219 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 492 "bison_parser.y" /* yacc.c:1646  */
    {
			// TODO: allow multiple unions (through linked list)
			// TODO: capture type of set_operator
			// TODO: might overwrite order and limit of first select here
			(yyval.select_stmt) = (yyvsp[-4].select_stmt);
			(yyval.select_stmt)->union_select = (yyvsp[-2].select_stmt);
			(yyval.select_stmt)->order = (yyvsp[-1].order);
			(yyval.select_stmt)->limit = (yyvsp[0].limit);
		}
#line 2233 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 510 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.select_stmt) = new SelectStatement();
			(yyval.select_stmt)->select_distinct = (yyvsp[-4].bval);
			(yyval.select_stmt)->select_list = (yyvsp[-3].expr_vec);
			(yyval.select_stmt)->from_table = (yyvsp[-2].table);
			(yyval.select_stmt)->where_clause = (yyvsp[-1].expr);
			(yyval.select_stmt)->group_by = (yyvsp[0].group_t);
		}
#line 2246 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 521 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = true; }
#line 2252 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 522 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.bval) = false; }
#line 2258 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 531 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.table) = (yyvsp[0].table); }
#line 2264 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 536 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2270 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 537 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = NULL; }
#line 2276 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 541 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.group_t) = new GroupByDescription();
			(yyval.group_t)->columns = (yyvsp[-1].expr_vec);
			(yyval.group_t)->having = (yyvsp[0].expr);
		}
#line 2286 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 546 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.group_t) = NULL; }
#line 2292 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 550 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2298 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 551 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = NULL; }
#line 2304 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 554 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order) = new OrderDescription((yyvsp[0].order_type), (yyvsp[-1].expr)); }
#line 2310 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 555 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order) = NULL; }
#line 2316 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 559 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_type) = kOrderAsc; }
#line 2322 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 560 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_type) = kOrderDesc; }
#line 2328 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 561 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.order_type) = kOrderAsc; }
#line 2334 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 566 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = new LimitDescription((yyvsp[0].expr)->ival, kNoOffset); delete (yyvsp[0].expr); }
#line 2340 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 567 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = new LimitDescription((yyvsp[-2].expr)->ival, (yyvsp[0].expr)->ival); delete (yyvsp[-2].expr); delete (yyvsp[0].expr); }
#line 2346 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 568 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.limit) = NULL; }
#line 2352 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 575 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr_vec) = new std::vector<Expr*>(); (yyval.expr_vec)->push_back((yyvsp[0].expr)); }
#line 2358 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 576 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr)); (yyval.expr_vec) = (yyvsp[-2].expr_vec); }
#line 2364 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 580 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr_vec) = new std::vector<Expr*>(); (yyval.expr_vec)->push_back((yyvsp[0].expr)); }
#line 2370 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 581 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].expr_vec)->push_back((yyvsp[0].expr)); (yyval.expr_vec) = (yyvsp[-2].expr_vec); }
#line 2376 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 585 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = (yyvsp[-1].expr);
			(yyval.expr)->alias = (yyvsp[0].sval);
		}
#line 2385 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 592 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 2391 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 606 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(Expr::UMINUS, (yyvsp[0].expr)); }
#line 2397 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 607 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpUnary(Expr::NOT, (yyvsp[0].expr)); }
#line 2403 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 612 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '-', (yyvsp[0].expr)); }
#line 2409 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 613 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '+', (yyvsp[0].expr)); }
#line 2415 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 614 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '/', (yyvsp[0].expr)); }
#line 2421 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 615 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '*', (yyvsp[0].expr)); }
#line 2427 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 616 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '%', (yyvsp[0].expr)); }
#line 2433 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 617 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '^', (yyvsp[0].expr)); }
#line 2439 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 618 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), Expr::AND, (yyvsp[0].expr)); }
#line 2445 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 619 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), Expr::OR, (yyvsp[0].expr)); }
#line 2451 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 620 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), Expr::LIKE, (yyvsp[0].expr)); }
#line 2457 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 621 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-3].expr), Expr::NOT_LIKE, (yyvsp[0].expr)); }
#line 2463 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 626 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '=', (yyvsp[0].expr)); }
#line 2469 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 627 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), Expr::NOT_EQUALS, (yyvsp[0].expr)); }
#line 2475 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 628 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '<', (yyvsp[0].expr)); }
#line 2481 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 629 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), '>', (yyvsp[0].expr)); }
#line 2487 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 630 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), Expr::LESS_EQ, (yyvsp[0].expr)); }
#line 2493 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 631 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeOpBinary((yyvsp[-2].expr), Expr::GREATER_EQ, (yyvsp[0].expr)); }
#line 2499 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 635 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeFunctionRef((yyvsp[-4].sval), (yyvsp[-1].expr), (yyvsp[-2].bval)); }
#line 2505 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 639 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeColumnRef((yyvsp[0].sval)); }
#line 2511 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 640 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeColumnRef((yyvsp[-2].sval), (yyvsp[0].sval)); }
#line 2517 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 650 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeLiteral((yyvsp[0].sval)); }
#line 2523 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 655 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeLiteral((yyvsp[0].fval)); }
#line 2529 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 660 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = Expr::makeLiteral((yyvsp[0].ival)); }
#line 2535 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 664 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Expr(kExprStar); }
#line 2541 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 669 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = Expr::makePlaceholder(yylloc.total_column);
			yyloc.placeholder_list.push_back((yyval.expr));
		}
#line 2550 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 681 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyvsp[0].table_vec)->push_back((yyvsp[-2].table));
			auto tbl = new TableRef(kTableCrossProduct);
			tbl->list = (yyvsp[0].table_vec);
			(yyval.table) = tbl;
		}
#line 2561 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 692 "bison_parser.y" /* yacc.c:1646  */
    {
			auto tbl = new TableRef(kTableSelect);
			tbl->select = (yyvsp[-2].select_stmt);
			tbl->alias = (yyvsp[0].sval);
			(yyval.table) = tbl;
		}
#line 2572 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 703 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.table_vec) = new std::vector<TableRef*>(); (yyval.table_vec)->push_back((yyvsp[0].table)); }
#line 2578 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 704 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].table_vec)->push_back((yyvsp[0].table)); (yyval.table_vec) = (yyvsp[-2].table_vec); }
#line 2584 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 709 "bison_parser.y" /* yacc.c:1646  */
    {
			auto tbl = new TableRef(kTableName);
			tbl->name = (yyvsp[-1].sval);
			tbl->alias = (yyvsp[0].sval);
			(yyval.table) = tbl;
		}
#line 2595 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 719 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.table) = new TableRef(kTableName);
			(yyval.table)->name = (yyvsp[0].sval);
		}
#line 2604 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 733 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = (yyvsp[0].sval); }
#line 2610 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 739 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.sval) = NULL; }
#line 2616 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 748 "bison_parser.y" /* yacc.c:1646  */
    {
			(yyval.table) = new TableRef(kTableJoin);
			(yyval.table)->join = new JoinDefinition();
			(yyval.table)->join->type = (JoinType) (yyvsp[-4].uval);
			(yyval.table)->join->left = (yyvsp[-5].table);
			(yyval.table)->join->right = (yyvsp[-2].table);
			(yyval.table)->join->condition = (yyvsp[0].expr);
		}
#line 2629 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 759 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinInner; }
#line 2635 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 760 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinOuter; }
#line 2641 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 761 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinLeft; }
#line 2647 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 762 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinRight; }
#line 2653 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 763 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.uval) = kJoinInner; }
#line 2659 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 769 "bison_parser.y" /* yacc.c:1646  */
    {
			auto tbl = new TableRef(kTableSelect);
			tbl->select = (yyvsp[-2].select_stmt);
			tbl->alias = (yyvsp[0].sval);
			(yyval.table) = tbl;
		}
#line 2670 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 794 "bison_parser.y" /* yacc.c:1646  */
    { (yyval.str_vec) = new std::vector<char*>(); (yyval.str_vec)->push_back((yyvsp[0].sval)); }
#line 2676 "bison_parser.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 795 "bison_parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].str_vec)->push_back((yyvsp[0].sval)); (yyval.str_vec) = (yyvsp[-2].str_vec); }
#line 2682 "bison_parser.cpp" /* yacc.c:1646  */
    break;


#line 2686 "bison_parser.cpp" /* yacc.c:1646  */
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
      yyerror (&yylloc, result, scanner, YY_("syntax error"));
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
        yyerror (&yylloc, result, scanner, yymsgp);
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
                      yytoken, &yylval, &yylloc, result, scanner);
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
                  yystos[yystate], yyvsp, yylsp, result, scanner);
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
  yyerror (&yylloc, result, scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, result, scanner);
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
#line 798 "bison_parser.y" /* yacc.c:1906  */

/*********************************
 ** Section 4: Additional C code
 *********************************/

/* empty */

