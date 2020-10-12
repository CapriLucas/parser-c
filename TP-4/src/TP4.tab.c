
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "TP4.y"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex ();
int yyerror (char*);
int yywrap(){
    return(1);
}



extern FILE* yyin;
extern FILE* yyout;



/* Line 189 of yacc.c  */
#line 93 "TP4.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CENTERO = 258,
     CREAL = 259,
     ID = 260,
     LCADENA = 261,
     CCARACTER = 262,
     OPASIG = 263,
     OR = 264,
     AND = 265,
     OPIGUAL = 266,
     OPCORR = 267,
     OPREL = 268,
     OPINCDEC = 269,
     TDATO = 270,
     TCLASE = 271,
     FLECHA = 272,
     STRUNION = 273,
     CALTIPO = 274,
     ENUM = 275,
     IF = 276,
     ELSE = 277,
     SIOF = 278,
     SWITCH = 279,
     WHILE = 280,
     DO = 281,
     FOR = 282,
     RETURN = 283,
     CONTINUE = 284,
     GOTO = 285,
     BREAK = 286,
     CASE = 287,
     DEFAULT = 288
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 20 "TP4.y"

char* ccval; // cadenas
double dval; // numeros reales/racionales
int ival; // numeros enteros



/* Line 214 of yacc.c  */
#line 170 "TP4.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 182 "TP4.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   527

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  170
/* YYNRULES -- Number of states.  */
#define YYNSTATES  282

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      34,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,     2,     2,    53,    54,     2,
      41,    42,    40,    50,    35,    51,    45,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    39,
      48,    36,    49,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,    55,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    14,    16,    19,
      22,    25,    29,    30,    32,    33,    35,    37,    41,    43,
      47,    49,    53,    58,    60,    64,    66,    70,    72,    78,
      81,    82,    84,    86,    89,    93,    96,    99,   100,   102,
     104,   108,   110,   114,   117,   118,   120,   123,   127,   128,
     130,   132,   135,   136,   138,   140,   144,   149,   154,   155,
     157,   159,   165,   167,   171,   174,   177,   183,   186,   188,
     192,   194,   198,   200,   202,   205,   207,   210,   211,   213,
     217,   222,   227,   228,   230,   231,   233,   235,   237,   239,
     241,   243,   245,   248,   253,   254,   256,   257,   259,   261,
     264,   266,   269,   276,   282,   283,   286,   292,   300,   310,
     314,   317,   320,   324,   329,   333,   337,   339,   343,   344,
     346,   348,   352,   354,   356,   362,   364,   368,   370,   374,
     376,   380,   382,   386,   388,   390,   392,   394,   398,   400,
     404,   408,   410,   414,   418,   422,   424,   427,   429,   432,
     435,   438,   443,   445,   447,   449,   451,   453,   455,   457,
     462,   467,   471,   475,   478,   480,   484,   486,   488,   490,
     492
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      58,     0,    -1,    -1,    58,    59,    -1,    34,    -1,   113,
      34,    -1,   101,    -1,    60,    -1,    61,    63,    -1,    68,
      62,    -1,    69,    62,    -1,    70,    62,    94,    -1,    -1,
      61,    -1,    -1,    64,    -1,    65,    -1,    64,    35,    65,
      -1,    79,    -1,    79,    36,    66,    -1,   115,    -1,    37,
      67,    38,    -1,    37,    67,    35,    38,    -1,    66,    -1,
      67,    35,    66,    -1,    16,    -1,    15,    71,    90,    -1,
      19,    -1,    18,    72,    37,    73,    38,    -1,    18,     5,
      -1,    -1,     5,    -1,    74,    -1,    73,    74,    -1,    75,
      77,    39,    -1,    69,    76,    -1,    70,    76,    -1,    -1,
      75,    -1,    78,    -1,    77,    35,    78,    -1,    80,    -1,
      80,    39,   117,    -1,    82,    85,    -1,    -1,    79,    -1,
      40,    84,    -1,    40,    84,    81,    -1,    -1,    81,    -1,
      70,    -1,    83,    70,    -1,    -1,    83,    -1,     5,    -1,
      41,    79,    42,    -1,    85,    43,    86,    44,    -1,    85,
      41,    87,    42,    -1,    -1,   117,    -1,    88,    -1,    88,
      35,    45,    45,    45,    -1,    89,    -1,    88,    35,    89,
      -1,    61,    79,    -1,    61,    97,    -1,    20,    72,    37,
      91,    38,    -1,    20,     5,    -1,    92,    -1,    91,    35,
      92,    -1,    93,    -1,    93,    36,   117,    -1,     5,    -1,
       5,    -1,    75,    97,    -1,    81,    -1,    82,    98,    -1,
      -1,    96,    -1,    41,    96,    42,    -1,    99,    43,    86,
      44,    -1,    99,    41,   100,    42,    -1,    -1,    98,    -1,
      -1,    87,    -1,   102,    -1,   103,    -1,   108,    -1,   110,
      -1,   111,    -1,   112,    -1,   114,    39,    -1,    37,   105,
     104,    38,    -1,    -1,   107,    -1,    -1,   106,    -1,    60,
      -1,   106,    60,    -1,   101,    -1,   107,   101,    -1,    21,
      41,   113,    42,   101,   109,    -1,    24,    41,   113,    42,
     101,    -1,    -1,    22,   101,    -1,    25,    41,   113,    42,
     101,    -1,    26,   101,    25,    41,   113,    42,    39,    -1,
      27,    41,   114,    39,   114,    39,   114,    42,   101,    -1,
      28,   114,    39,    -1,    29,    39,    -1,    31,    39,    -1,
      30,     5,    39,    -1,    32,   117,    46,   101,    -1,    33,
      46,   101,    -1,     5,    46,   101,    -1,   115,    -1,   113,
      35,   115,    -1,    -1,   113,    -1,   117,    -1,   127,   116,
     115,    -1,     8,    -1,   118,    -1,   118,    47,   113,    46,
     117,    -1,   119,    -1,   118,     9,   119,    -1,   120,    -1,
     119,    10,   120,    -1,   121,    -1,   120,    11,   121,    -1,
     123,    -1,   121,   122,   123,    -1,    48,    -1,    49,    -1,
      13,    -1,   124,    -1,   123,    12,   124,    -1,   125,    -1,
     124,    50,   125,    -1,   124,    51,   125,    -1,   127,    -1,
     125,    40,   126,    -1,   125,    52,   126,    -1,   125,    53,
     126,    -1,   127,    -1,    15,   126,    -1,   129,    -1,    14,
     127,    -1,   128,   126,    -1,    23,   127,    -1,    23,    41,
      95,    42,    -1,    54,    -1,    40,    -1,    50,    -1,    51,
      -1,    55,    -1,    56,    -1,   131,    -1,   129,    43,   113,
      44,    -1,   129,    41,   130,    42,    -1,   129,    45,     5,
      -1,   129,    17,     5,    -1,   129,    14,    -1,   115,    -1,
     130,    35,   115,    -1,     5,    -1,     3,    -1,     4,    -1,
       6,    -1,    41,   113,    42,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    40,    40,    41,    44,    45,    46,    47,    55,    58,
      59,    60,    63,    64,    66,    67,    69,    70,    72,    73,
      75,    76,    77,    79,    80,    83,    85,    87,    89,    90,
      92,    93,    95,    96,    98,   100,   101,   103,   104,   106,
     107,   109,   110,   113,   116,   117,   120,   121,   126,   127,
     130,   131,   133,   134,   136,   137,   138,   139,   141,   142,
     144,   145,   147,   148,   150,   151,   153,   154,   156,   157,
     159,   160,   162,   164,   166,   168,   169,   171,   172,   174,
     175,   176,   178,   179,   181,   182,   189,   190,   191,   192,
     193,   194,   197,   200,   203,   204,   207,   208,   211,   212,
     215,   216,   221,   222,   225,   226,   230,   231,   232,   236,
     237,   238,   239,   243,   244,   245,   256,   257,   259,   260,
     262,   263,   265,   267,   268,   270,   271,   273,   274,   276,
     277,   279,   280,   282,   282,   282,   284,   285,   288,   289,
     290,   292,   293,   294,   295,   297,   298,   300,   301,   302,
     303,   304,   306,   306,   306,   306,   306,   306,   308,   309,
     310,   311,   312,   313,   315,   316,   318,   318,   318,   318,
     318
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CENTERO", "CREAL", "ID", "LCADENA",
  "CCARACTER", "OPASIG", "OR", "AND", "OPIGUAL", "OPCORR", "OPREL",
  "OPINCDEC", "TDATO", "TCLASE", "FLECHA", "STRUNION", "CALTIPO", "ENUM",
  "IF", "ELSE", "SIOF", "SWITCH", "WHILE", "DO", "FOR", "RETURN",
  "CONTINUE", "GOTO", "BREAK", "CASE", "DEFAULT", "'\\n'", "','", "'='",
  "'{'", "'}'", "';'", "'*'", "'('", "')'", "'['", "']'", "'.'", "':'",
  "'?'", "'<'", "'>'", "'+'", "'-'", "'/'", "'%'", "'&'", "'~'", "'!'",
  "$accept", "input", "line", "declaracion", "espDec", "espDecOP",
  "listDeclaradoresOp", "listDeclaradores", "declarador", "inicializador",
  "listInic", "espClase", "espTipo", "calTipo", "espStrunion", "idOp",
  "listStruct", "declStruct", "listCal", "listCalOp", "declaradoresStruct",
  "declaStruct", "decla", "declaOp", "punt", "puntOp", "listaCalTip",
  "listaCalTipOp", "declaDir", "expCondOp", "listTipoParam", "listParam",
  "declParam", "espEnum", "listEnum", "enumerador", "constEnum", "nomTyp",
  "nomTipo", "declAbs", "declAbsOp", "declAbsDir", "declAbsDirOp",
  "listTipoParamOp", "sentencia", "sentExp", "sentComp", "listsentOp",
  "listDeclaracionesOp", "listDeclaraciones", "listsent", "sentSelecc",
  "elseSent", "sentIterac", "sentSalto", "sentEtiq", "expresion", "expOp",
  "expAsig", "operAsig", "expCond", "expOr", "expAnd", "expIgual",
  "expRel", "opRela", "expCorr", "expAdi", "expMul", "expConv", "expUna",
  "opUna", "expPFijo", "listaArg", "expPri", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    10,    44,    61,   123,   125,    59,
      42,    40,    41,    91,    93,    46,    58,    63,    60,    62,
      43,    45,    47,    37,    38,   126,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    59,    59,    59,    59,    60,    61,
      61,    61,    62,    62,    63,    63,    64,    64,    65,    65,
      66,    66,    66,    67,    67,    68,    69,    70,    71,    71,
      72,    72,    73,    73,    74,    75,    75,    76,    76,    77,
      77,    78,    78,    79,    80,    80,    81,    81,    82,    82,
      83,    83,    84,    84,    85,    85,    85,    85,    86,    86,
      87,    87,    88,    88,    89,    89,    90,    90,    91,    91,
      92,    92,    93,    94,    95,    96,    96,    97,    97,    98,
      98,    98,    99,    99,   100,   100,   101,   101,   101,   101,
     101,   101,   102,   103,   104,   104,   105,   105,   106,   106,
     107,   107,   108,   108,   109,   109,   110,   110,   110,   111,
     111,   111,   111,   112,   112,   112,   113,   113,   114,   114,
     115,   115,   116,   117,   117,   118,   118,   119,   119,   120,
     120,   121,   121,   122,   122,   122,   123,   123,   124,   124,
     124,   125,   125,   125,   125,   126,   126,   127,   127,   127,
     127,   127,   128,   128,   128,   128,   128,   128,   129,   129,
     129,   129,   129,   129,   130,   130,   131,   131,   131,   131,
     131
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     2,     2,
       2,     3,     0,     1,     0,     1,     1,     3,     1,     3,
       1,     3,     4,     1,     3,     1,     3,     1,     5,     2,
       0,     1,     1,     2,     3,     2,     2,     0,     1,     1,
       3,     1,     3,     2,     0,     1,     2,     3,     0,     1,
       1,     2,     0,     1,     1,     3,     4,     4,     0,     1,
       1,     5,     1,     3,     2,     2,     5,     2,     1,     3,
       1,     3,     1,     1,     2,     1,     2,     0,     1,     3,
       4,     4,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     0,     1,     0,     1,     1,     2,
       1,     2,     6,     5,     0,     2,     5,     7,     9,     3,
       2,     2,     3,     4,     3,     3,     1,     3,     0,     1,
       1,     3,     1,     1,     5,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     2,     1,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     3,     3,     2,     1,     3,     1,     1,     1,     1,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,   118,     1,   167,   168,   166,   169,     0,     0,    25,
      27,     0,     0,     0,     0,   118,     0,   118,     0,     0,
       0,     0,     0,     4,    96,   153,     0,   154,   155,   152,
     156,   157,     3,     7,    14,    12,    12,    12,     6,    86,
      87,    88,    89,    90,    91,   119,     0,   116,   120,   123,
     125,   127,   129,   131,   136,   138,   141,     0,   147,   158,
     118,   166,   148,    30,     0,     0,     0,   150,     0,     0,
       0,   119,   118,     0,   110,     0,   111,     0,   141,   118,
      98,    94,    97,     0,    52,     8,    15,    16,    18,    49,
       0,    13,     9,    10,     0,     5,     0,    92,     0,     0,
       0,     0,   135,   133,   134,     0,     0,     0,     0,     0,
       0,     0,   122,     0,     0,   149,   145,   163,     0,     0,
       0,     0,   115,    29,     0,    30,    26,     0,    37,    37,
      48,     0,     0,     0,     0,     0,   109,   112,   118,   114,
     100,     0,    95,    99,   170,    50,    53,    46,    48,     0,
      54,    48,    43,    73,    11,   117,   126,     0,   128,   130,
     132,   137,   139,   140,   142,   143,   144,   121,   146,   162,
     164,     0,     0,   161,     0,    67,     0,   118,    38,    35,
      36,    49,    82,    78,    74,   151,   118,   118,     0,   118,
     113,    93,   101,    51,    47,    17,     0,    19,    20,     0,
       0,    58,     0,     0,   160,   159,     0,    32,    44,     0,
     104,    48,    76,     0,   103,   106,     0,     0,    23,     0,
      55,    48,     0,    60,    62,     0,    59,   124,   165,    28,
      33,     0,    39,    45,    41,    72,     0,    68,    70,   118,
     102,     0,    84,    58,     0,   118,     0,    21,    64,    82,
      65,    57,     0,    56,    44,    34,     0,     0,    66,     0,
     105,    79,    85,     0,     0,   107,     0,    22,    24,    48,
       0,    63,    40,    42,    69,    71,    81,    80,   118,     0,
     108,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    32,    33,    34,    92,    85,    86,    87,   197,
     219,    35,    36,    37,    64,   124,   206,   207,   178,   179,
     231,   232,    88,   234,    89,    90,   146,   147,   152,   225,
     222,   223,   224,   126,   236,   237,   238,   154,   131,   183,
     184,   212,   213,   263,    38,    39,    40,   141,    81,    82,
     142,    41,   240,    42,    43,    44,    71,    46,    47,   113,
      48,    49,    50,    51,    52,   105,    53,    54,    55,   115,
      56,    57,    58,   171,    59
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -192
static const yytype_int16 yypact[] =
{
    -192,   243,  -192,  -192,  -192,   -28,  -192,   450,    16,  -192,
    -192,     9,   471,    45,    65,   321,    85,   450,    91,   158,
     125,   450,   119,  -192,   124,  -192,   450,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,   126,   124,   124,   124,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,    77,   129,  -192,  -192,     7,
     159,   162,     8,   163,   105,    -9,   169,   428,   101,  -192,
     321,  -192,  -192,   165,   160,   450,   364,  -192,   450,   450,
     153,   144,   450,   142,  -192,   143,  -192,   139,  -192,   321,
    -192,   282,   124,     5,   167,  -192,   152,  -192,   154,  -192,
      17,  -192,  -192,  -192,   183,  -192,   450,  -192,   450,   450,
     450,   450,  -192,  -192,  -192,   450,   450,   450,   450,   428,
     428,   428,  -192,   450,   428,  -192,  -192,  -192,   184,   450,
     450,   186,  -192,   155,   156,   189,  -192,    46,    27,    27,
      56,   161,    47,    49,   157,   166,  -192,  -192,   321,  -192,
    -192,   164,   282,  -192,  -192,  -192,   167,   126,   126,   407,
    -192,   126,    95,  -192,  -192,  -192,   159,     3,   162,     8,
     163,   105,    -9,    -9,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,    55,    -3,  -192,    27,   155,   170,   321,  -192,  -192,
    -192,    82,   168,  -192,  -192,  -192,   321,   321,   450,   450,
    -192,  -192,  -192,  -192,  -192,  -192,   407,  -192,  -192,   171,
     124,   450,   450,   450,  -192,  -192,    14,  -192,    21,   192,
     178,   126,   108,   111,  -192,  -192,    87,   172,  -192,    90,
    -192,    13,   173,   175,  -192,   174,  -192,  -192,  -192,  -192,
    -192,    34,  -192,  -192,   180,  -192,   112,  -192,   176,   321,
    -192,   179,   124,   450,   181,   450,   385,  -192,  -192,    22,
    -192,  -192,    20,  -192,    21,  -192,   450,   192,  -192,   450,
    -192,  -192,  -192,   185,   187,  -192,   188,  -192,  -192,   126,
     177,  -192,  -192,  -192,  -192,  -192,  -192,  -192,   321,   190,
    -192,  -192
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -192,  -192,  -192,   -10,   -26,   122,  -192,  -192,    58,  -171,
    -192,  -192,   -58,   -61,  -192,    76,  -192,    -2,   -53,    79,
    -192,   -40,  -134,  -192,  -128,  -102,  -192,  -192,  -192,   -20,
     -25,  -192,   -24,  -192,  -192,   -23,  -192,  -192,  -192,  -191,
      12,  -192,  -192,  -192,   -15,  -192,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,    11,   -13,   -89,  -192,
     -18,  -192,   131,   136,   138,  -192,   135,   145,    53,    23,
      -6,  -192,  -192,  -192,  -192
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -119
static const yytype_int16 yytable[] =
{
      70,    62,   181,    77,    73,   129,    67,   155,   128,    91,
      91,    91,    45,   130,    80,    78,    98,   199,    60,   194,
     241,   102,   150,   145,   167,   218,   -48,   150,   182,     8,
     170,   109,    96,    10,    63,     8,     9,    83,    96,    10,
      96,   205,     8,   110,   111,   122,    10,   144,   -77,   202,
      65,   116,   229,    84,    99,   -77,   103,   104,   151,   135,
     198,    84,   -48,   269,   139,   270,   140,   129,   129,   254,
     128,   128,   143,   255,   233,   268,   127,    83,   241,   132,
     133,    96,    96,   181,    96,   193,    68,   248,   177,   186,
     203,   187,    78,   181,    78,    78,    84,   204,   -77,    78,
      78,    78,    78,   116,   116,   116,    69,   198,   116,   182,
     157,    95,    96,   129,   228,   117,   128,   -75,   118,   249,
     233,   208,    96,   190,   -75,   246,    72,   192,   247,   244,
      74,   172,   164,   165,   166,   199,   200,   168,   201,     8,
       9,   181,   119,    10,   120,   129,   121,   257,   128,   -83,
     258,   -83,   242,   208,   243,   107,   108,   198,    93,    94,
     162,   163,   210,    75,    76,    79,    84,   249,    97,   100,
     123,   214,   215,   101,   221,   106,   217,   112,   134,    96,
     125,   136,   137,   226,   227,   138,    10,   148,   153,   169,
     149,   173,   -31,   174,   175,    78,    78,   235,   188,   216,
     239,   176,   191,   185,   230,   189,   195,   209,   180,   211,
     252,   245,   259,   220,   272,   251,   221,   262,   253,   256,
     265,   261,   279,   264,   260,   226,   221,   276,   271,   156,
     278,   277,   266,   250,   274,   281,   158,    78,   273,   159,
     160,   275,     0,     2,     0,     0,     3,     4,     5,     6,
      78,   161,     0,    78,     0,     0,     0,     7,     8,     9,
       0,     0,    10,   280,    11,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,     0,     0,
      24,     0,     0,    25,    26,     3,     4,     5,     6,     0,
       0,     0,     0,    27,    28,     0,     7,    29,    30,    31,
       0,     0,     0,    11,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,     0,     0,     0,    24,
       0,  -118,    25,    26,     3,     4,     5,     6,     0,     0,
       0,     0,    27,    28,     0,     7,    29,    30,    31,     0,
       0,     0,    11,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     0,     0,     0,    24,     0,
       0,    25,    26,     0,     0,     0,     0,     3,     4,    61,
       6,    27,    28,     0,     0,    29,    30,    31,     7,     8,
       0,     0,     0,    10,     0,     0,     0,    12,     3,     4,
      61,     6,     0,     0,     0,     0,     0,     0,     0,     7,
       0,     0,     0,     0,    25,    26,     0,     0,    12,     0,
       3,     4,    61,     6,    27,    28,     0,     0,    29,    30,
      31,     7,   196,   267,     0,    25,    26,     0,     0,     0,
      12,     3,     4,    61,     6,    27,    28,     0,     0,    29,
      30,    31,     7,   114,   196,     0,     0,    25,    26,     0,
       0,    12,     0,     3,     4,    61,     6,    27,    28,     0,
       0,    29,    30,    31,     7,     0,     0,     0,    25,    26,
       0,     0,     0,    12,     3,     4,    61,     6,    27,    28,
       0,     0,    29,    30,    31,     7,     0,     0,     0,     0,
      25,    26,     0,     0,    12,     0,     0,     0,     0,     0,
      27,    28,     0,     0,    29,    30,    31,     0,     0,     0,
       0,    25,    66,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    28,     0,     0,    29,    30,    31
};

static const yytype_int16 yycheck[] =
{
      15,     7,   130,    21,    17,    66,    12,    96,    66,    35,
      36,    37,     1,    66,    24,    21,     9,   151,    46,   147,
     211,    13,     5,    84,   113,   196,     5,     5,   130,    15,
     119,    40,    35,    19,    18,    15,    16,    26,    35,    19,
      35,    44,    15,    52,    53,    60,    19,    42,    35,    46,
      41,    57,    38,    40,    47,    42,    48,    49,    41,    72,
     149,    40,    41,    41,    79,    45,    81,   128,   129,    35,
     128,   129,    82,    39,   208,   246,    65,    66,   269,    68,
      69,    35,    35,   211,    35,   146,    41,   221,    42,    42,
      35,    42,    98,   221,   100,   101,    40,    42,    42,   105,
     106,   107,   108,   109,   110,   111,    41,   196,   114,   211,
      99,    34,    35,   174,   203,    14,   174,    35,    17,   221,
     254,   174,    35,   138,    42,    35,    41,   142,    38,    42,
      39,   120,   109,   110,   111,   269,    41,   114,    43,    15,
      16,   269,    41,    19,    43,   206,    45,    35,   206,    41,
      38,    43,    41,   206,    43,    50,    51,   246,    36,    37,
     107,   108,   177,     5,    39,    46,    40,   269,    39,    10,
       5,   186,   187,    11,   200,    12,   189,     8,    25,    35,
      20,    39,    39,   201,   202,    46,    19,    35,     5,     5,
      36,     5,    37,    37,     5,   201,   202,     5,    41,   188,
      22,   125,    38,    42,   206,    39,   148,    37,   129,    41,
      35,    39,    36,    42,   254,    42,   242,   242,    44,    39,
      39,    42,    45,   243,   239,   243,   252,    42,   252,    98,
      42,    44,   245,   221,   257,    45,   100,   243,   256,   101,
     105,   259,    -1,     0,    -1,    -1,     3,     4,     5,     6,
     256,   106,    -1,   259,    -1,    -1,    -1,    14,    15,    16,
      -1,    -1,    19,   278,    21,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      37,    -1,    -1,    40,    41,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    50,    51,    -1,    14,    54,    55,    56,
      -1,    -1,    -1,    21,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    37,
      -1,    39,    40,    41,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    50,    51,    -1,    14,    54,    55,    56,    -1,
      -1,    -1,    21,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    37,    -1,
      -1,    40,    41,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    50,    51,    -1,    -1,    54,    55,    56,    14,    15,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    23,     3,     4,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    23,    -1,
       3,     4,     5,     6,    50,    51,    -1,    -1,    54,    55,
      56,    14,    37,    38,    -1,    40,    41,    -1,    -1,    -1,
      23,     3,     4,     5,     6,    50,    51,    -1,    -1,    54,
      55,    56,    14,    15,    37,    -1,    -1,    40,    41,    -1,
      -1,    23,    -1,     3,     4,     5,     6,    50,    51,    -1,
      -1,    54,    55,    56,    14,    -1,    -1,    -1,    40,    41,
      -1,    -1,    -1,    23,     3,     4,     5,     6,    50,    51,
      -1,    -1,    54,    55,    56,    14,    -1,    -1,    -1,    -1,
      40,    41,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      50,    51,    -1,    -1,    54,    55,    56,    -1,    -1,    -1,
      -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    -1,    -1,    54,    55,    56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    58,     0,     3,     4,     5,     6,    14,    15,    16,
      19,    21,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    37,    40,    41,    50,    51,    54,
      55,    56,    59,    60,    61,    68,    69,    70,   101,   102,
     103,   108,   110,   111,   112,   113,   114,   115,   117,   118,
     119,   120,   121,   123,   124,   125,   127,   128,   129,   131,
      46,     5,   127,    18,    71,    41,    41,   127,    41,    41,
     101,   113,    41,   114,    39,     5,    39,   117,   127,    46,
      60,   105,   106,   113,    40,    63,    64,    65,    79,    81,
      82,    61,    62,    62,    62,    34,    35,    39,     9,    47,
      10,    11,    13,    48,    49,   122,    12,    50,    51,    40,
      52,    53,     8,   116,    15,   126,   127,    14,    17,    41,
      43,    45,   101,     5,    72,    20,    90,   113,    69,    70,
      75,    95,   113,   113,    25,   114,    39,    39,    46,   101,
     101,   104,   107,    60,    42,    70,    83,    84,    35,    36,
       5,    41,    85,     5,    94,   115,   119,   113,   120,   121,
     123,   124,   125,   125,   126,   126,   126,   115,   126,     5,
     115,   130,   113,     5,    37,     5,    72,    42,    75,    76,
      76,    81,    82,    96,    97,    42,    42,    42,    41,    39,
     101,    38,   101,    70,    81,    65,    37,    66,   115,    79,
      41,    43,    46,    35,    42,    44,    73,    74,    75,    37,
     101,    41,    98,    99,   101,   101,   113,   114,    66,    67,
      42,    61,    87,    88,    89,    86,   117,   117,   115,    38,
      74,    77,    78,    79,    80,     5,    91,    92,    93,    22,
     109,    96,    41,    43,    42,    39,    35,    38,    79,    82,
      97,    42,    35,    44,    35,    39,    39,    35,    38,    36,
     101,    42,    87,   100,    86,    39,   114,    38,    66,    41,
      45,    89,    78,   117,    92,   117,    42,    44,    42,    45,
     101,    45
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 93:

/* Line 1455 of yacc.c  */
#line 200 "TP4.y"
    {fprintf(yyout,"Sentencia Compuesta encontrada:\n");;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 221 "TP4.y"
    {printf("Sentencia de seleccion If encontrada.\n"); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 222 "TP4.y"
    {printf("Sentencia de seleccion switch encontrada.\n"); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 226 "TP4.y"
    {printf("Sentencia de seleccion If-Else encontrada.\n"); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 230 "TP4.y"
    {printf("Sentencia de Iteracion while encontrada.\n"); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 231 "TP4.y"
    {printf("Sentencia de Iteracion do while encontrada.\n"); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 232 "TP4.y"
    {printf("Sentencia de Iteracion for encontrada.\n"); ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 236 "TP4.y"
    {printf("Sentencia de salto return encontrada.\n"); ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 237 "TP4.y"
    {printf("Sentencia de salto continue encontrada.\n"); ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 238 "TP4.y"
    {printf("Sentencia de salto break encontrada.\n"); ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 239 "TP4.y"
    {printf("Sentencia de salto goto encontrada.\n"); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 243 "TP4.y"
    {printf("Sentencia de etiqueta case encontrada.\n"); ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 244 "TP4.y"
    {printf("Sentencia de etiqueta default encontrada.\n"); ;}
    break;



/* Line 1455 of yacc.c  */
#line 1796 "TP4.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



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
		      yytoken, &yylval);
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 321 "TP4.y"



//Si el analizador no empareja con ninguna produccion se muestra un msj de error con su linea 

int yyerror (char* mensaje)  
{  
    printf ("Error: %s\n", mensaje);
}


int main (){
yyin = fopen("Entrada.txt","r");
yyout = fopen("Salida.txt","w");
yyparse();

}



