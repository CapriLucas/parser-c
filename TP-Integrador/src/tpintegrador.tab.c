
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
#line 1 "tpintegrador.y"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int yylex ();
int yyerror (char*);
int yywrap(){
    return(1);
}



extern int yylineno;
// usar yylineno para las lineas en ts

FILE* yyin;
FILE* yyout;



/* Line 189 of yacc.c  */
#line 98 "tpintegrador.tab.c"

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
     OPREL = 267,
     OPINCDEC = 268,
     T_DATO = 269,
     TCLASE = 270,
     FLECHA = 271,
     OPDESIGUAL = 272,
     OPERADORUNARIO = 273,
     IF = 274,
     ELSE = 275,
     SIZEOF = 276,
     SWITCH = 277,
     WHILE = 278,
     DO = 279,
     FOR = 280,
     RETURN = 281,
     CONTINUE = 282,
     GOTO = 283,
     BREAK = 284,
     CASE = 285,
     DEFAULT = 286,
     CNORECONOCIDO = 287,
     errorLexico = 288
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 28 "tpintegrador.y"

char ccval[20]; // cadenas
struct yylval_Tokens
  {
      int tipo;
      int ival;
      double dval;
  } estructura;
struct yylval_TokenError
  {
      int linea;
      char nomError[20];
  } errorLex;



/* Line 214 of yacc.c  */
#line 184 "tpintegrador.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 196 "tpintegrador.tab.c"

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
#define YYLAST   319

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNRULES -- Number of states.  */
#define YYNSTATES  198

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      47,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    40,    49,     2,
      41,    42,    38,    36,    46,    37,    45,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    48,
       2,     2,     2,    34,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    25,    27,    33,    35,    39,    41,    45,    47,
      51,    53,    57,    59,    63,    67,    69,    73,    77,    81,
      83,    86,    91,    93,    98,   103,   107,   111,   114,   115,
     117,   121,   123,   125,   127,   129,   131,   135,   137,   139,
     141,   143,   146,   149,   153,   157,   159,   162,   166,   168,
     172,   175,   176,   179,   186,   194,   195,   197,   201,   205,
     210,   211,   213,   220,   223,   225,   227,   229,   231,   233,
     235,   238,   245,   251,   252,   254,   257,   258,   260,   263,
     265,   268,   275,   281,   282,   285,   291,   299,   309,   313,
     316,   319,   323,   328,   332,   336,   337
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    -1,    53,    54,    -1,    69,    -1,    82,
      -1,    55,    -1,    33,    -1,     1,    -1,    56,    -1,    57,
      -1,    64,     8,    56,    -1,    58,    -1,    58,    34,    55,
      35,    57,    -1,    59,    -1,    58,     9,    59,    -1,    60,
      -1,    59,    10,    60,    -1,    61,    -1,    60,    11,    61,
      -1,    62,    -1,    61,    12,    62,    -1,    63,    -1,    62,
      36,    63,    -1,    62,    37,    63,    -1,    64,    -1,    63,
      38,    64,    -1,    63,    39,    64,    -1,    63,    40,    64,
      -1,    65,    -1,    13,    64,    -1,    21,    41,    14,    42,
      -1,    68,    -1,    65,    43,    55,    44,    -1,     5,    41,
      66,    42,    -1,    65,    45,     5,    -1,    65,    16,     5,
      -1,    65,    13,    -1,    -1,    67,    -1,    66,    46,    67,
      -1,    56,    -1,     5,    -1,     3,    -1,     4,    -1,     6,
      -1,    41,    55,    42,    -1,    47,    -1,    70,    -1,    77,
      -1,    81,    -1,    14,    71,    -1,    74,    48,    -1,    38,
      74,    48,    -1,     5,    72,    48,    -1,    73,    -1,    72,
      73,    -1,    43,    55,    44,    -1,    75,    -1,    74,    46,
      75,    -1,     5,    76,    -1,    -1,     8,    57,    -1,    14,
       5,    41,    78,    42,    48,    -1,    14,    38,     5,    41,
      78,    42,    48,    -1,    -1,    79,    -1,    79,    46,    78,
      -1,    14,    80,     5,    -1,    14,    38,    80,     5,    -1,
      -1,    49,    -1,    14,     5,    41,    78,    42,    82,    -1,
      83,    47,    -1,    84,    -1,    88,    -1,    90,    -1,    91,
      -1,    92,    -1,    48,    -1,    55,    48,    -1,    50,    85,
      47,    86,    51,    47,    -1,    50,    85,    86,    51,    47,
      -1,    -1,    69,    -1,    85,    69,    -1,    -1,    82,    -1,
      87,    82,    -1,    82,    -1,    87,    82,    -1,    19,    41,
      55,    42,    82,    89,    -1,    22,    41,    55,    42,    82,
      -1,    -1,    20,    82,    -1,    23,    41,    55,    42,    82,
      -1,    24,    82,    23,    41,    55,    42,    48,    -1,    25,
      41,    93,    48,    93,    48,    93,    42,    82,    -1,    26,
      93,    48,    -1,    27,    48,    -1,    29,    48,    -1,    28,
       5,    48,    -1,    30,    57,    35,    82,    -1,    31,    35,
      82,    -1,     5,    35,    82,    -1,    -1,    55,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    80,    80,    81,    85,    86,    87,    88,    96,   102,
     105,   106,   110,   111,   113,   114,   116,   117,   119,   120,
     127,   128,   139,   140,   154,   156,   165,   166,   167,   171,
     180,   181,   185,   195,   196,   203,   204,   205,   208,   209,
     210,   212,   228,   229,   230,   231,   232,   249,   250,   251,
     252,   256,   264,   265,   266,   274,   275,   278,   281,   282,
     285,   293,   294,   298,   309,   322,   323,   324,   328,   336,
     348,   349,   352,   361,   362,   363,   364,   365,   366,   369,
     370,   373,   374,   378,   379,   380,   383,   384,   385,   388,
     389,   395,   396,   399,   400,   404,   405,   406,   410,   411,
     412,   413,   417,   418,   419,   422,   423
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CENTERO", "CREAL", "ID", "LCADENA",
  "CCARACTER", "OPASIG", "OR", "AND", "OPIGUAL", "OPREL", "OPINCDEC",
  "T_DATO", "TCLASE", "FLECHA", "OPDESIGUAL", "OPERADORUNARIO", "IF",
  "ELSE", "SIZEOF", "SWITCH", "WHILE", "DO", "FOR", "RETURN", "CONTINUE",
  "GOTO", "BREAK", "CASE", "DEFAULT", "CNORECONOCIDO", "errorLexico",
  "'?'", "':'", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'", "'['",
  "']'", "'.'", "','", "'\\n'", "';'", "'&'", "'{'", "'}'", "$accept",
  "input", "line", "expresion", "expresionAsignacion",
  "expresionCondicional", "expresionOr", "expresionAnd",
  "expresionIgualdad", "expresionRelacional", "expresionAditiva",
  "expresionMultiplicativa", "expresionUnaria", "expresionPostFijo",
  "listaArgumentos", "expresionAsignacionBis", "expresionPrimaria",
  "declaracion", "declaracionDeVariables", "declaracionDeVariablesPuntero",
  "listaArreglos", "arreglo", "listaVariablesSimples", "variableSimple",
  "inicializador", "declaracionDeFunciones", "opcionArgumentos",
  "argumentoSimple", "referencia", "definicionDeFuncion", "sentencia",
  "sentenciaExpresion", "sentenciaCompuesta", "listaDeclaracionesOpcional",
  "listaSentenciasOpcional", "listaSentencias", "sentenciaSeleccion",
  "elseSent", "sentenciaIteracion", "sentenciaSalto", "sentenciaEtiqueta",
  "expresionOpc", 0
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
     285,   286,   287,   288,    63,    58,    43,    45,    42,    47,
      37,    40,    41,    91,    93,    46,    44,    10,    59,    38,
     123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    54,    54,    54,    54,    54,    55,
      56,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      61,    61,    62,    62,    62,    63,    63,    63,    63,    64,
      64,    64,    65,    65,    65,    65,    65,    65,    66,    66,
      66,    67,    68,    68,    68,    68,    68,    69,    69,    69,
      69,    70,    71,    71,    71,    72,    72,    73,    74,    74,
      75,    76,    76,    77,    77,    78,    78,    78,    79,    79,
      80,    80,    81,    82,    82,    82,    82,    82,    82,    83,
      83,    84,    84,    85,    85,    85,    86,    86,    86,    87,
      87,    88,    88,    89,    89,    90,    90,    90,    91,    91,
      91,    91,    92,    92,    92,    93,    93
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     5,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     4,     1,     4,     4,     3,     3,     2,     0,     1,
       3,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     2,     2,     3,     3,     1,     2,     3,     1,     3,
       2,     0,     2,     6,     7,     0,     1,     3,     3,     4,
       0,     1,     6,     2,     1,     1,     1,     1,     1,     1,
       2,     6,     5,     0,     1,     2,     0,     1,     2,     1,
       2,     6,     5,     0,     2,     5,     7,     9,     3,     2,
       2,     3,     4,     3,     3,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     8,    43,    44,    42,    45,     0,     0,
       0,     0,     0,     0,     0,     0,   105,     0,     0,     0,
       0,     0,     7,     0,    47,    79,    83,     3,     6,     9,
      10,    12,    14,    16,    18,    20,    22,    25,    29,    32,
       4,    48,    49,    50,     5,     0,    74,    75,    76,    77,
      78,     0,    38,    42,    30,    61,     0,    51,     0,    58,
       0,     0,     0,     0,     0,     0,   105,   106,     0,    99,
       0,   100,     0,    25,     0,     0,    84,    86,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,    73,   104,    41,     0,    39,     0,
      65,     0,     0,    55,    60,    61,     0,     0,    52,     0,
       0,     0,     0,     0,     0,    98,   101,     0,   103,    46,
      47,    85,    89,     0,     0,    15,     0,    17,    19,    21,
      23,    24,    26,    27,    28,    11,    36,     0,    35,    34,
       0,    62,    70,     0,    66,     0,    54,    56,    65,    53,
      61,    59,     0,    31,     0,     0,     0,   105,   102,     0,
       0,    90,     0,    33,    40,    70,    71,     0,     0,    65,
      57,     0,    93,    92,    95,     0,     0,     0,    82,    13,
       0,    68,    63,    72,    67,     0,     0,    91,     0,   105,
      81,    69,    64,    94,    96,     0,     0,    97
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    27,    64,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    97,    98,    39,    40,    41,    57,
     102,   103,    58,    59,   104,    42,   143,   144,   167,    43,
     122,    45,    46,    77,   123,   124,    47,   187,    48,    49,
      50,    68
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -140
static const yytype_int16 yypact[] =
{
    -140,   177,  -140,  -140,  -140,  -140,   -14,  -140,     1,     3,
     -29,   -16,    18,    20,   239,    26,     1,    21,    34,    22,
       1,    14,  -140,     1,  -140,  -140,     4,  -140,    23,  -140,
    -140,    10,    58,    61,    62,    -2,     8,    67,    13,  -140,
    -140,  -140,  -140,  -140,  -140,    29,  -140,  -140,  -140,  -140,
    -140,   239,     1,    36,  -140,     2,    73,  -140,    -8,  -140,
       1,    65,     1,     1,    23,    59,     1,  -140,    35,  -140,
      37,  -140,    49,  -140,   239,    44,  -140,   209,  -140,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
    -140,    82,     1,    83,  -140,  -140,  -140,    -9,  -140,     1,
      75,     1,   -12,  -140,  -140,    16,     7,    85,  -140,    63,
      64,    66,    68,    71,    56,  -140,  -140,   239,  -140,  -140,
     239,  -140,    69,    70,   239,    58,    72,    61,    62,    -2,
       8,     8,  -140,  -140,  -140,  -140,  -140,    74,  -140,  -140,
       1,  -140,   -21,    77,    76,    80,  -140,  -140,    75,  -140,
     101,  -140,   239,  -140,   239,   239,     1,     1,  -140,    78,
      79,    81,     1,  -140,  -140,    84,  -140,   108,   269,    75,
    -140,    86,    94,  -140,  -140,    88,    87,    89,  -140,  -140,
     110,  -140,  -140,  -140,  -140,    90,   239,  -140,    91,     1,
    -140,  -140,  -140,  -140,  -140,    95,   239,  -140
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,  -140,  -140,     0,   -37,   -18,  -140,    38,    46,    43,
      48,   -20,    12,  -140,  -140,     5,  -140,   -23,  -140,  -140,
    -140,    39,    92,    33,  -140,  -140,  -139,  -140,   -22,  -140,
      -1,  -140,  -140,  -140,    27,  -140,  -140,  -140,  -140,  -140,
    -140,   -55
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -89
static const yytype_int16 yytable[] =
{
      44,    28,    72,    76,     4,     5,    53,     7,    55,   171,
      99,   114,    60,    65,     8,    96,    67,   165,     9,    79,
      54,    51,    11,    75,    99,    61,    90,    52,   166,    91,
     184,   101,    73,   139,    84,    85,   146,   140,   107,    70,
     108,    56,    23,   100,    80,   101,    86,    87,    88,    74,
      95,    24,   135,   107,   121,   149,    92,   148,    93,    62,
     109,    63,   111,   112,   130,   131,    67,    66,    81,    69,
      71,    78,    82,   118,    83,    89,    94,    52,   105,   110,
     126,   141,   113,   115,   117,   116,   119,   136,   138,   142,
     150,    73,   137,    73,    73,    73,    73,    73,   132,   133,
     134,   145,   176,    96,   157,   152,   153,   162,   154,    99,
     155,    73,   156,   181,   186,   191,   158,   125,   163,   168,
     -87,   160,   169,   161,   170,   128,   178,   127,   185,   177,
     188,   129,   -88,   166,   195,   189,   190,   196,   192,   194,
     151,   147,     0,   180,   179,   164,     0,   159,   106,     0,
       0,   172,     0,   173,   174,     0,   175,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   183,     0,     0,
       0,     0,     0,     0,    73,     0,     0,     2,     3,     0,
       4,     5,     6,     7,     0,   193,     0,     0,     0,    67,
       8,     9,     0,     0,     0,   197,    10,     0,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
      22,     0,     4,     5,     6,     7,     0,     0,    23,     0,
       0,     0,     8,     9,    24,    25,     0,    26,    10,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,     4,     5,     6,     7,     0,     0,     0,     0,
      23,     0,     8,     0,     0,     0,   120,    25,    10,    26,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,     4,     5,     6,     7,     0,     0,     0,     0,
      23,     0,     8,     0,     0,     0,     0,    25,    10,    26,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     0,   182,     0,    26
};

static const yytype_int16 yycheck[] =
{
       1,     1,    20,    26,     3,     4,     5,     6,     5,   148,
       8,    66,    41,    14,    13,    52,    16,    38,    14,     9,
       8,    35,    21,    23,     8,    41,    13,    41,    49,    16,
     169,    43,    20,    42,    36,    37,    48,    46,    46,     5,
      48,    38,    41,    41,    34,    43,    38,    39,    40,    35,
      51,    47,    89,    46,    77,    48,    43,    41,    45,    41,
      60,    41,    62,    63,    84,    85,    66,    41,    10,    48,
      48,    48,    11,    74,    12,     8,    47,    41,     5,    14,
      80,    99,    23,    48,    35,    48,    42,     5,     5,    14,
       5,    79,    92,    81,    82,    83,    84,    85,    86,    87,
      88,   101,   157,   140,    48,    42,    42,    35,    42,     8,
      42,    99,    41,     5,    20,     5,   117,    79,    44,    42,
      51,    51,    46,   124,    44,    82,    47,    81,    42,    51,
      42,    83,    51,    49,   189,    48,    47,    42,    48,    48,
     107,   102,    -1,   165,   162,   140,    -1,   120,    56,    -1,
      -1,   152,    -1,   154,   155,    -1,   156,   157,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,
      -1,    -1,    -1,    -1,   162,    -1,    -1,     0,     1,    -1,
       3,     4,     5,     6,    -1,   186,    -1,    -1,    -1,   189,
      13,    14,    -1,    -1,    -1,   196,    19,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      33,    -1,     3,     4,     5,     6,    -1,    -1,    41,    -1,
      -1,    -1,    13,    14,    47,    48,    -1,    50,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      41,    -1,    13,    -1,    -1,    -1,    47,    48,    19,    50,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      41,    -1,    13,    -1,    -1,    -1,    -1,    48,    19,    50,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,     0,     1,     3,     4,     5,     6,    13,    14,
      19,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    33,    41,    47,    48,    50,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    68,
      69,    70,    77,    81,    82,    83,    84,    88,    90,    91,
      92,    35,    41,     5,    64,     5,    38,    71,    74,    75,
      41,    41,    41,    41,    55,    82,    41,    55,    93,    48,
       5,    48,    57,    64,    35,    55,    69,    85,    48,     9,
      34,    10,    11,    12,    36,    37,    38,    39,    40,     8,
      13,    16,    43,    45,    47,    82,    56,    66,    67,     8,
      41,    43,    72,    73,    76,     5,    74,    46,    48,    55,
      14,    55,    55,    23,    93,    48,    48,    35,    82,    42,
      47,    69,    82,    86,    87,    59,    55,    60,    61,    62,
      63,    63,    64,    64,    64,    56,     5,    55,     5,    42,
      46,    57,    14,    78,    79,    55,    48,    73,    41,    48,
       5,    75,    42,    42,    42,    42,    41,    48,    82,    86,
      51,    82,    35,    44,    67,    38,    49,    80,    42,    46,
      44,    78,    82,    82,    82,    55,    93,    51,    47,    57,
      80,     5,    48,    82,    78,    42,    20,    89,    42,    48,
      47,     5,    48,    82,    48,    93,    42,    82
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
        case 7:

/* Line 1455 of yacc.c  */
#line 88 "tpintegrador.y"
    {
                char *cadena = (char *)malloc((strlen((yyvsp[(1) - (1)].errorLex).nomError) + 1) * sizeof(char *));
                strcpy(cadena,(yyvsp[(1) - (1)].errorLex).nomError); 
                int linea = (yyvsp[(1) - (1)].errorLex).linea;
                listaErroresLexicos = agregarErrorLexico(listaErroresLexicos, cadena , linea);

        ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 96 "tpintegrador.y"
    {printf("\nSe encontro un error sintactico en la linea %d. Imposible emparejar por alguna produccion\n", yylineno);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 140 "tpintegrador.y"
    {  if((yyvsp[(1) - (3)].estructura).tipo==(yyvsp[(3) - (3)].estructura).tipo) { 
                                                        if((yyvsp[(1) - (3)].estructura).tipo==1){
                                                        (yyval.estructura).ival=(yyvsp[(1) - (3)].estructura).ival+(yyvsp[(3) - (3)].estructura).ival;
                                                        printf("El resultado es: %d\n",(yyval.estructura).ival);
                                                        }else{
                                                        (yyval.estructura).dval=(yyvsp[(1) - (3)].estructura).dval+(yyvsp[(3) - (3)].estructura).dval;
                                                        printf("El resultado es: %f\n",(yyval.estructura).dval);
                                                        }
                                                           } else {
                                                                printf("Error semantico en la linea %d Los operandos son de distinto tipo \n",yylineno);
                                                                printf("Tipo1 = %d. Tipo2 = %d. \n",(yyvsp[(1) - (3)].estructura).tipo,(yyvsp[(3) - (3)].estructura).tipo);
                                                                }
                                                        ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 156 "tpintegrador.y"
    {
                    if((yyvsp[(1) - (1)].estructura).tipo==1){
                    (yyval.estructura).tipo=(yyvsp[(1) - (1)].estructura).tipo;
                    (yyval.estructura).ival=(yyvsp[(1) - (1)].estructura).ival;
                    }else{
                        (yyval.estructura).tipo=(yyvsp[(1) - (1)].estructura).tipo;
                        (yyval.estructura).dval=(yyvsp[(1) - (1)].estructura).dval;
                        }
                                        ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 171 "tpintegrador.y"
    {
                    if((yyvsp[(1) - (1)].estructura).tipo==1){
                    (yyval.estructura).tipo=(yyvsp[(1) - (1)].estructura).tipo;
                    (yyval.estructura).ival=(yyvsp[(1) - (1)].estructura).ival;
                    }else{
                        (yyval.estructura).tipo=(yyvsp[(1) - (1)].estructura).tipo;
                        (yyval.estructura).dval=(yyvsp[(1) - (1)].estructura).dval;
                        }
                                        ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 185 "tpintegrador.y"
    {

                    if((yyvsp[(1) - (1)].estructura).tipo==1){
                    (yyval.estructura).tipo=(yyvsp[(1) - (1)].estructura).tipo;
                    (yyval.estructura).ival=(yyvsp[(1) - (1)].estructura).ival;
                    }else{
                        (yyval.estructura).tipo=(yyvsp[(1) - (1)].estructura).tipo;
                        (yyval.estructura).dval=(yyvsp[(1) - (1)].estructura).dval;
                        }
                                        ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 196 "tpintegrador.y"
    {
                    char *id = (char *)malloc((strlen((yyvsp[(1) - (4)].ccval)) + 1) * sizeof(char *));
                    strcpy(id,(yyvsp[(1) - (4)].ccval));
                    int linea = yylineno;
                    comprobarInvocacionFuncion(listaFunciones,listaParametrosAux,id,linea);
                    listaParametrosAux = NULL;
                ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 212 "tpintegrador.y"
    {
                                        char *id = (char *)malloc((strlen((yyvsp[(1) - (1)].ccval)) + 1) * sizeof(char *));
                                        strcpy(id,(yyvsp[(1) - (1)].ccval));
                                        variableAux = buscarVariable(listaVariables, id);
                                        char *tipo = (char *)malloc((strlen(variableAux->tipoVar) + 1) * sizeof(char *));
                                        if(variableAux == NULL){
                                                strcpy(tipo,"undefined");
                                        }
                                        else{
                                                strcpy(tipo,variableAux->tipoVar);

                                        }
                                        listaParametrosAux = agregarVariable(listaParametrosAux,id,tipo);
                                        variableAux = NULL;
                                        ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 228 "tpintegrador.y"
    {strcpy((yyval.ccval),(yyvsp[(1) - (1)].ccval));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 229 "tpintegrador.y"
    {(yyval.estructura).ival=(yyvsp[(1) - (1)].estructura).ival; (yyval.estructura).tipo=(yyvsp[(1) - (1)].estructura).tipo;;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 230 "tpintegrador.y"
    {(yyval.estructura).dval=(yyvsp[(1) - (1)].estructura).dval; (yyval.estructura).tipo=(yyvsp[(1) - (1)].estructura).tipo;;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 256 "tpintegrador.y"
    {
                                        strcat((yyvsp[(1) - (2)].ccval),(yyvsp[(2) - (2)].ccval));
                                        int linea = yylineno;
                                        listaVariables = pasarVariablesDeAux(listaVariables,listaVariablesAux, (yyvsp[(1) - (2)].ccval),linea);
                                        listaVariablesAux = destroyListaVar(listaVariablesAux);
        ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 264 "tpintegrador.y"
    {strcpy((yyval.ccval), "");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 265 "tpintegrador.y"
    {strcpy((yyval.ccval), "*");;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 266 "tpintegrador.y"
    {
                                        strcpy((yyval.ccval), " arreglo");
                                        char *cadena = (char *)malloc((strlen((yyvsp[(1) - (3)].ccval)) + 1) * sizeof(char *));
                                        strcpy(cadena,(yyvsp[(1) - (3)].ccval));
                                        listaVariablesAux = agregarVariable(listaVariablesAux,cadena," ");
        
        ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 285 "tpintegrador.y"
    {
                                        char *cadena = (char *)malloc((strlen((yyvsp[(1) - (2)].ccval)) + 1) * sizeof(char *));
                                        strcpy(cadena,(yyvsp[(1) - (2)].ccval));
                                        listaVariablesAux = agregarVariable(listaVariablesAux,cadena,"not yet");
                                        strcpy((yyval.ccval), (yyvsp[(1) - (2)].ccval));
        ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 298 "tpintegrador.y"
    {
                                        char *id = (char *)malloc((strlen((yyvsp[(2) - (6)].ccval)) + 1) * sizeof(char *));
                                        strcpy(id,(yyvsp[(2) - (6)].ccval));
                                        char *tipo = (char *)malloc((strlen((yyvsp[(1) - (6)].ccval)) + 1) * sizeof(char *));
                                        strcpy(tipo,(yyvsp[(1) - (6)].ccval));
                                        int cantidad = contarParametros(listaParametrosAux);
                                        int linea = yylineno;
                                        listaFunciones = validarFuncionYAgregarla(listaFunciones,listaParametrosAux, id,tipo,cantidad,linea);
                                        listaParametrosAux = NULL;
                                        ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 309 "tpintegrador.y"
    {
                                        char *id = (char *)malloc((strlen((yyvsp[(3) - (7)].ccval)) + 1) * sizeof(char *));
                                        strcpy(id,(yyvsp[(3) - (7)].ccval));
                                        strcat((yyvsp[(1) - (7)].ccval),"*");
                                        char *tipo = (char *)malloc((strlen((yyvsp[(1) - (7)].ccval)) + 1) * sizeof(char *));
                                        strcpy(tipo,(yyvsp[(1) - (7)].ccval));
                                        int cantidad = contarParametros(listaParametrosAux);
                                        int linea = yylineno;
                                        listaFunciones = validarFuncionYAgregarla(listaFunciones,listaParametrosAux, id,tipo,cantidad,linea);
                                        listaParametrosAux = NULL;
        ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 328 "tpintegrador.y"
    {
                                        char *id = (char *)malloc((strlen((yyvsp[(3) - (3)].ccval)) + 1) * sizeof(char *));
                                        strcpy(id,(yyvsp[(3) - (3)].ccval));
                                        char *tipo = (char *)malloc((strlen((yyvsp[(1) - (3)].ccval)) + 1) * sizeof(char *));
                                        strcpy(tipo,(yyvsp[(1) - (3)].ccval));
                                        listaParametrosAux = agregarVariable(listaParametrosAux,id,tipo);
        
;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 336 "tpintegrador.y"
    {
                                        char *id = (char *)malloc((strlen((yyvsp[(4) - (4)].ccval)) + 1) * sizeof(char *));
                                        strcpy(id,(yyvsp[(4) - (4)].ccval));
                                        strcat((yyvsp[(1) - (4)].ccval),"*");
                                        char *tipo = (char *)malloc((strlen((yyvsp[(1) - (4)].ccval)) + 1) * sizeof(char *));
                                        strcpy(tipo,(yyvsp[(1) - (4)].ccval));
                                        listaParametrosAux = agregarVariable(listaParametrosAux,id,tipo);

;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 352 "tpintegrador.y"
    {printf ("\nSe encontro la funcion %s de tipo %s\n ", (yyvsp[(2) - (6)].ccval), (yyvsp[(1) - (6)].ccval));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 373 "tpintegrador.y"
    {printf("Sentencia compuesta encontrada.\n"); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 374 "tpintegrador.y"
    {printf("Sentencia compuesta encontrada.\n"); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 395 "tpintegrador.y"
    {printf("Sentencia de seleccion If encontrada.\n"); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 396 "tpintegrador.y"
    {printf("Sentencia de seleccion switch encontrada.\n"); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 400 "tpintegrador.y"
    {printf("Sentencia de seleccion If-Else encontrada.\n"); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 404 "tpintegrador.y"
    {printf("Sentencia de Iteracion while encontrada.\n"); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 405 "tpintegrador.y"
    {printf("Sentencia de Iteracion do while encontrada.\n"); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 406 "tpintegrador.y"
    {printf("Sentencia de Iteracion for encontrada.\n"); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 410 "tpintegrador.y"
    {printf("Sentencia de salto return encontrada.\n"); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 411 "tpintegrador.y"
    {printf("Sentencia de salto continue encontrada.\n"); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 412 "tpintegrador.y"
    {printf("Sentencia de salto break encontrada.\n"); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 413 "tpintegrador.y"
    {printf("Sentencia de salto goto encontrada.\n"); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 417 "tpintegrador.y"
    {printf("Sentencia de etiqueta case encontrada.\n"); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 418 "tpintegrador.y"
    {printf("Sentencia de etiqueta default encontrada.\n"); ;}
    break;



/* Line 1455 of yacc.c  */
#line 1957 "tpintegrador.tab.c"
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
#line 428 "tpintegrador.y"



int yyerror (char *mensajeError){  //tambien ver como hay que manerjarlo en el archivo de salida o si es necesario (todavia no me fije)
        fprintf(yyout, "Se encontro un error sintatico\n ", mensajeError);
}


//La TS es global no hace falta ingresarla en putVariable

int main (){


yyin = fopen("Entrada.c","r");
yyout= fopen("Salida.txt", "w");
yyparse();
mostrarListaErroresLexicos(listaErroresLexicos);
printf("\n\n\n");
mostrarListaErroresSemanticos(listaErroresSemanticos);
printf("\n\n\n");
mostrarListaVariables(listaVariables);
mostrarListaFunciones(listaFunciones);




}
