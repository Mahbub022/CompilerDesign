
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
#line 3 "grammer.y"

	#include<stdio.h>
	#include <string.h>
    extern	int yyerror(char *s);
	extern int yylex();
	extern int yyparse();
	extern FILE *yyin;
	extern FILE *yyout;
	extern int yylineno;

typedef struct {
    char *name;
    char *type;
    int intValue;
    double doubleValue;
    char *strValue;
    char charValue;
} Symbols;

Symbols data[20];
int countVar = 0 , countType = 0 ;
int countS = 1;
char varType[4][10]={"integer","float","character","string"};


void addValue(char *n, int t, int i,double d, char c, char *s)
{
    data[countVar].name= strdup(n);
    data[countVar].type= strdup(varType[t]);
    data[countVar].intValue = i;
    data[countVar].doubleValue = d;
    data[countVar].charValue = c;
    data[countVar].strValue = strdup(s);
}

int findVar(char *varName)
{
    int i=0;
    for(i ;i<=countVar;i++)
    {
        if(data[i].name != NULL && strcmp(data[i].name, varName) == 0)
        {
            return i;
        }
    }
    return 100;
}


void showVariable()
{
    printf("Variable\tType\tValue\n");
    int i=0;
    for(; i<=countVar;i++)
    {
        printf("%s\t%s\t", data[i].name, data[i].type);
        if(!strcmp( data[i].type,"integer"))
        {
            printf("%d\n", data[i].intValue);
        }
        else if(!strcmp( data[i].type,"float"))
        {
            printf("%.2f\n", data[i].doubleValue);
        }
        if(!strcmp( data[i].type,"character"))
        {
            printf("%c\n", data[i].charValue);
        }
        if(!strcmp( data[i].type,"string"))
        {
            printf("%s\n", data[i].strValue);
        }
    }
}




/* Line 189 of yacc.c  */
#line 152 "grammer.tab.c"

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
     INT = 258,
     FLOAT = 259,
     CHAR = 260,
     STRING = 261,
     VAR = 262,
     LET = 263,
     IF = 264,
     ELSE = 265,
     ELSIF = 266,
     SWITCH = 267,
     CASE = 268,
     DO = 269,
     FOR = 270,
     WHILE = 271,
     IN = 272,
     BREAK = 273,
     CONTINUE = 274,
     START = 275,
     FINISH = 276,
     AND = 277,
     OR = 278,
     EQUAl = 279,
     NOTEQUAL = 280,
     PLUS = 281,
     MINUS = 282,
     MULTIPLY = 283,
     DIVISION = 284,
     MODULO = 285,
     LESS = 286,
     GREATER = 287,
     LEFT = 288,
     RIGHT = 289,
     INCREMENT = 290,
     DECREMENT = 291,
     SPACE = 292,
     ANY = 293,
     HEADER = 294,
     COMMENT = 295,
     LETTERS = 296,
     REAl = 297,
     DIGITS = 298,
     DECLARE = 299,
     ASSIGN = 300,
     SINGLE = 301,
     MULTI = 302,
     IFS = 303
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 84 "grammer.y"

    int intValue;
    float floatValue;
    char charValue;
    char* stringValue;
    char* dataType;



/* Line 214 of yacc.c  */
#line 246 "grammer.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 258 "grammer.tab.c"

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
#define YYLAST   248

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNRULES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,     2,     2,    58,    51,     2,
      62,    63,    56,    54,    66,    55,     2,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    61,
      52,    49,    53,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    65,    59,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    50,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    41,    51,    60,
      63,    66,    69,    72,    88,    98,   102,   106,   110,   114,
     118,   122,   126,   130,   134,   138,   142,   146,   150,   154,
     158,   162,   166,   170,   174,   178,   182,   186,   188,   192,
     195,   196,   200,   202,   204,   208,   210,   212,   214
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      68,     0,    -1,    -1,    68,    69,    -1,    70,    -1,    38,
      -1,    72,    -1,    73,    -1,    80,    -1,    78,    -1,    77,
      -1,    71,    -1,    74,    -1,    61,    -1,    40,    -1,    39,
      -1,    15,    37,    62,    75,    63,    37,    64,    70,    65,
      -1,    80,    37,    61,    37,    79,    37,    61,    37,    76,
      -1,    78,    37,    61,    37,    79,    61,    37,    76,    -1,
      35,    41,    -1,    36,    41,    -1,    41,    35,    -1,    41,
      36,    -1,     9,    37,    62,    79,    63,    37,    64,    70,
      65,    37,    10,    37,    64,    70,    65,    -1,     9,    37,
      62,    79,    63,    37,    64,    70,    65,    -1,    41,    49,
      79,    -1,    41,    26,    79,    -1,    41,    27,    79,    -1,
      41,    28,    79,    -1,    41,    29,    79,    -1,    41,    30,
      79,    -1,    79,    56,    79,    -1,    79,    57,    79,    -1,
      79,    58,    79,    -1,    79,    54,    79,    -1,    79,    55,
      79,    -1,    79,    52,    79,    -1,    79,    53,    79,    -1,
      79,    59,    79,    -1,    79,    22,    79,    -1,    79,    23,
      79,    -1,    79,    31,    79,    -1,    79,    32,    79,    -1,
      79,    24,    79,    -1,    79,    25,    79,    -1,    79,    50,
      79,    -1,    79,    51,    79,    -1,    43,    -1,    84,    37,
      81,    -1,    83,    82,    -1,    -1,    66,    82,    82,    -1,
      83,    -1,    41,    -1,    41,    49,    79,    -1,     3,    -1,
       4,    -1,     5,    -1,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   125,   127,   128,   130,   131,   132,   133,
     134,   135,   136,   138,   140,   143,   145,   147,   148,   150,
     151,   152,   153,   155,   166,   180,   191,   203,   215,   227,
     239,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   270,   271,
     273,   274,   275,   277,   291,   306,   307,   308,   309
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "CHAR", "STRING", "VAR",
  "LET", "IF", "ELSE", "ELSIF", "SWITCH", "CASE", "DO", "FOR", "WHILE",
  "IN", "BREAK", "CONTINUE", "START", "FINISH", "AND", "OR", "EQUAl",
  "NOTEQUAL", "PLUS", "MINUS", "MULTIPLY", "DIVISION", "MODULO", "LESS",
  "GREATER", "LEFT", "RIGHT", "INCREMENT", "DECREMENT", "SPACE", "ANY",
  "HEADER", "COMMENT", "LETTERS", "REAl", "DIGITS", "DECLARE", "ASSIGN",
  "SINGLE", "MULTI", "IFS", "'='", "'|'", "'&'", "'<'", "'>'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'^'", "'!'", "';'", "'('", "')'", "'['",
  "']'", "','", "$accept", "program", "lines", "statements",
  "null_statement", "comments", "header_statement", "loop_statement",
  "forBlock", "value", "conditional_statement", "assignValue_statement",
  "exp", "variable_statement", "variable", "multiVar", "singleVar", "Type", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    61,
     124,    38,    60,    62,    43,    45,    42,    47,    37,    94,
      33,    59,    40,    41,    91,    93,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    68,    69,    69,    70,    70,    70,    70,
      70,    70,    70,    71,    72,    73,    74,    75,    75,    76,
      76,    76,    76,    77,    77,    78,    78,    78,    78,    78,
      78,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    80,    81,
      82,    82,    82,    83,    83,    84,    84,    84,    84
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     9,     9,     8,     2,
       2,     2,     2,    15,     9,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     2,
       0,     3,     1,     1,     3,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    55,    56,    57,    58,     0,     0,     5,
      15,    14,     0,    13,     3,     4,    11,     6,     7,    12,
      10,     9,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,    26,    27,    28,    29,
      30,    25,    53,    48,    50,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    49,    52,     0,
       0,     0,     0,    39,    40,    43,    44,    41,    42,    45,
      46,    36,    37,    34,    35,    31,    32,    33,    38,    54,
      50,     0,     0,     0,     0,    51,     0,     0,     0,     0,
       0,     0,     0,     0,    24,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,    19,    20,
      21,    22,    17,     0,     0,    23
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    14,    15,    16,    17,    18,    19,    46,   115,
      20,    21,    36,    22,    43,    67,    68,    23
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -85
static const yytype_int16 yypact[] =
{
     -85,     5,   -85,   -85,   -85,   -85,   -85,   -30,   -16,   -85,
     -85,   -85,   199,   -85,   -85,   -85,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,    27,   -20,    24,    39,    39,    39,    39,
      39,    39,    46,    39,    13,   -85,   134,   134,   134,   134,
     134,   134,    49,   -85,   -26,    38,    36,    63,    65,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,   -26,   -85,   -85,    66,
      67,    50,    51,   144,   144,   188,   188,   123,   123,   180,
     180,    20,    20,    -1,    -1,    54,    54,    54,    54,   134,
     -26,    53,    58,    73,    77,   -85,    44,    44,    39,    39,
      59,    60,    84,    96,    86,   -85,    89,    68,   120,    32,
      94,    95,   103,   119,    45,   -85,    32,    97,   -85,   -85,
     -85,   -85,   -85,    44,    98,   -85
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -85,   -85,   -85,   -84,   -85,   -85,   -85,   -85,   -85,    48,
     -85,   128,   -27,   133,   -85,   -25,   138,   -85
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      37,    38,    39,    40,    41,     2,    45,    24,     3,     4,
       5,     6,   100,   101,     7,    42,     3,     4,     5,     6,
       8,    25,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   124,
      66,    90,    33,     9,    10,    11,    12,     3,     4,     5,
       6,    53,    54,     7,    12,    61,    62,    63,    64,     8,
      49,    50,    51,    52,    32,    95,    13,   112,   113,    53,
      54,   102,   103,   114,    59,    60,    61,    62,    63,    64,
     120,   121,    35,    10,    11,    12,    34,    42,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    70,
      71,    69,    72,    91,    92,    13,    49,    50,    51,    52,
      98,    93,    94,    64,    99,    53,    54,    96,    49,    50,
      51,    52,    97,   108,   104,   105,   109,    53,    54,   110,
     111,   116,   117,   107,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   118,   106,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    49,    50,    51,    52,
     119,   123,    47,   125,   122,    53,    54,    48,    51,    52,
      44,     0,     0,     0,     0,    53,    54,    59,    60,    61,
      62,    63,    64,     0,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    51,    52,     0,     0,     0,     0,
       0,    53,    54,     0,     0,     0,     0,     0,     0,    53,
      54,     0,     0,     0,     0,    26,    27,    28,    29,    30,
       0,     0,    57,    58,    59,    60,    61,    62,    63,    64,
      57,    58,    59,    60,    61,    62,    63,    64,    31
};

static const yytype_int8 yycheck[] =
{
      27,    28,    29,    30,    31,     0,    33,    37,     3,     4,
       5,     6,    96,    97,     9,    41,     3,     4,     5,     6,
      15,    37,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   123,
      66,    66,    62,    38,    39,    40,    41,     3,     4,     5,
       6,    31,    32,     9,    41,    56,    57,    58,    59,    15,
      22,    23,    24,    25,    37,    90,    61,    35,    36,    31,
      32,    98,    99,    41,    54,    55,    56,    57,    58,    59,
      35,    36,    43,    39,    40,    41,    62,    41,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    49,    63,
      37,    63,    37,    37,    37,    61,    22,    23,    24,    25,
      37,    61,    61,    59,    37,    31,    32,    64,    22,    23,
      24,    25,    64,    37,    65,    65,    37,    31,    32,    61,
      10,    37,    37,    37,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    41,    61,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    22,    23,    24,    25,
      41,    64,    34,    65,   116,    31,    32,    34,    24,    25,
      32,    -1,    -1,    -1,    -1,    31,    32,    54,    55,    56,
      57,    58,    59,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    24,    25,    -1,    -1,    -1,    -1,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      -1,    -1,    52,    53,    54,    55,    56,    57,    58,    59,
      52,    53,    54,    55,    56,    57,    58,    59,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    68,     0,     3,     4,     5,     6,     9,    15,    38,
      39,    40,    41,    61,    69,    70,    71,    72,    73,    74,
      77,    78,    80,    84,    37,    37,    26,    27,    28,    29,
      30,    49,    37,    62,    62,    43,    79,    79,    79,    79,
      79,    79,    41,    81,    83,    79,    75,    78,    80,    22,
      23,    24,    25,    31,    32,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    49,    66,    82,    83,    63,
      63,    37,    37,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      82,    37,    37,    61,    61,    82,    64,    64,    37,    37,
      70,    70,    79,    79,    65,    65,    61,    37,    37,    37,
      61,    10,    35,    36,    41,    76,    37,    37,    41,    41,
      35,    36,    76,    64,    70,    65
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
        case 4:

/* Line 1455 of yacc.c  */
#line 127 "grammer.y"
    {printf("%d statement completed\n",countS); ++countS;;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 138 "grammer.y"
    {printf("NUll statement\n");;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 140 "grammer.y"
    {if(yylval.stringValue[0]=='/' && yylval.stringValue[1]=='/'){printf("Single line comment started using //\n");}
 						else {printf("Multiple lines comment started using <! and finished using !>\n");};}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 143 "grammer.y"
    {printf("Included header file is : %s\n",yylval.stringValue);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 145 "grammer.y"
    {printf("<--For loop finished\n");;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 147 "grammer.y"
    {printf("For loop started -->\n");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 148 "grammer.y"
    {printf("For loop started -->\n");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 155 "grammer.y"
    {
                                                                printf("IF ELSE block started --");
                                                                if((yyvsp[(4) - (15)].intValue) != 0)
                                                                {
                                                                    printf("IF block will be executed\n");
                                                                }
                                                                else
                                                                {
                                                                    printf("ELSE block will be executed\n");
                                                                }
                                                                    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 166 "grammer.y"
    {
                                                                printf("IF block started --");
                                                                if((yyvsp[(4) - (9)].intValue) != 0)
                                                                {
                                                                    printf("IF block will be executed\n");
                                                                }
                                                                else
                                                                {
                                                                    printf("NO block will be executed\n");
                                                                }
                                                                    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 180 "grammer.y"
    { int count = findVar((yyvsp[(1) - (3)].stringValue));
                                        if(count == 100)
                                        {
                                            printf("%s variable has not been declared\n",(yyvsp[(1) - (3)].stringValue));
                                        }
                                        else
                                        {
                                            data[count].intValue = (yyvsp[(3) - (3)].intValue);
                                            printf("%d has been assigned to %s variable\n",(yyvsp[(3) - (3)].intValue),(yyvsp[(1) - (3)].stringValue));
                                        }
                                            ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 191 "grammer.y"
    { int count = findVar((yyvsp[(1) - (3)].stringValue));
                                        if(count == 100)
                                        {
                                            printf("%s variable has not been declared\n",(yyvsp[(1) - (3)].stringValue));
                                        }
                                        else
                                        {
                                            (yyvsp[(3) - (3)].intValue) += data[count].intValue;
                                            data[count].intValue = (yyvsp[(3) - (3)].intValue);
                                            printf("%d has been assigned to %s variable\n",(yyvsp[(3) - (3)].intValue),(yyvsp[(1) - (3)].stringValue));
                                        }
                                            ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 203 "grammer.y"
    { int count = findVar((yyvsp[(1) - (3)].stringValue));
                                        if(count == 100)
                                        {
                                            printf("%s variable has not been declared\n",(yyvsp[(1) - (3)].stringValue));
                                        }
                                        else
                                        {
                                            (yyvsp[(3) - (3)].intValue) -= data[count].intValue;
                                            data[count].intValue = (yyvsp[(3) - (3)].intValue);
                                            printf("%d has been assigned to %s variable\n",(yyvsp[(3) - (3)].intValue),(yyvsp[(1) - (3)].stringValue));
                                        }
                                            ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 215 "grammer.y"
    { int count = findVar((yyvsp[(1) - (3)].stringValue));
                                        if(count == 100)
                                        {
                                            printf("%s variable has not been declared\n",(yyvsp[(1) - (3)].stringValue));
                                        }
                                        else
                                        {
                                            (yyvsp[(3) - (3)].intValue) *= data[count].intValue;
                                            data[count].intValue = (yyvsp[(3) - (3)].intValue);
                                            printf("%d has been assigned to %s variable\n",(yyvsp[(3) - (3)].intValue),(yyvsp[(1) - (3)].stringValue));
                                        }
                                            ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 227 "grammer.y"
    { int count = findVar((yyvsp[(1) - (3)].stringValue));
                                        if(count == 100)
                                        {
                                            printf("%s variable has not been declared\n",(yyvsp[(1) - (3)].stringValue));
                                        }
                                        else
                                        {
                                            (yyvsp[(3) - (3)].intValue) /= data[count].intValue;
                                            data[count].intValue = (yyvsp[(3) - (3)].intValue);
                                            printf("%d has been assigned to %s variable\n",(yyvsp[(3) - (3)].intValue),(yyvsp[(1) - (3)].stringValue));
                                        }
                                            ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 239 "grammer.y"
    { int count = findVar((yyvsp[(1) - (3)].stringValue));
                                        if(count == 100)
                                        {
                                            printf("%s variable has not been declared\n",(yyvsp[(1) - (3)].stringValue));
                                        }
                                        else
                                        {
                                            (yyvsp[(3) - (3)].intValue) /= data[count].intValue;
                                            data[count].intValue = (yyvsp[(3) - (3)].intValue);
                                            printf("%d has been assigned to %s variable\n",(yyvsp[(3) - (3)].intValue),(yyvsp[(1) - (3)].stringValue));
                                        }
                                            ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 252 "grammer.y"
    {(yyval.intValue) = (yyvsp[(1) - (3)].intValue) * (yyvsp[(3) - (3)].intValue);  ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 253 "grammer.y"
    {(yyval.intValue) = (yyvsp[(1) - (3)].intValue) / (yyvsp[(3) - (3)].intValue);  ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 254 "grammer.y"
    {(yyval.intValue) = (yyvsp[(1) - (3)].intValue) % (yyvsp[(3) - (3)].intValue);  ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 255 "grammer.y"
    { (yyval.intValue) = (yyvsp[(1) - (3)].intValue) + (yyvsp[(3) - (3)].intValue);  ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 256 "grammer.y"
    {(yyval.intValue) = (yyvsp[(1) - (3)].intValue) - (yyvsp[(3) - (3)].intValue);  ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 257 "grammer.y"
    {(yyval.intValue) = (yyvsp[(1) - (3)].intValue) < (yyvsp[(3) - (3)].intValue);  ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 258 "grammer.y"
    {(yyval.intValue) = (yyvsp[(1) - (3)].intValue) > (yyvsp[(3) - (3)].intValue);  ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 259 "grammer.y"
    {(yyval.intValue) = (yyvsp[(1) - (3)].intValue) ^ (yyvsp[(3) - (3)].intValue);  ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 260 "grammer.y"
    {(yyval.intValue) = (yyvsp[(1) - (3)].intValue) && (yyvsp[(3) - (3)].intValue);  ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 261 "grammer.y"
    {(yyval.intValue) = (yyvsp[(1) - (3)].intValue) || (yyvsp[(3) - (3)].intValue);  ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 262 "grammer.y"
    {(yyval.intValue) = (yyvsp[(1) - (3)].intValue) <= (yyvsp[(3) - (3)].intValue);  ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 263 "grammer.y"
    {(yyval.intValue) = (yyvsp[(1) - (3)].intValue) >= (yyvsp[(3) - (3)].intValue);  ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 264 "grammer.y"
    {(yyval.intValue) = (yyvsp[(1) - (3)].intValue) == (yyvsp[(3) - (3)].intValue);  ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 265 "grammer.y"
    {(yyval.intValue) = (yyvsp[(1) - (3)].intValue) != (yyvsp[(3) - (3)].intValue);  ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 266 "grammer.y"
    {(yyval.intValue) = (yyvsp[(1) - (3)].intValue) | (yyvsp[(3) - (3)].intValue);  ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 267 "grammer.y"
    {(yyval.intValue) = (yyvsp[(1) - (3)].intValue) & (yyvsp[(3) - (3)].intValue);  ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 268 "grammer.y"
    {(yyval.intValue) = (yyvsp[(1) - (1)].intValue);  ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 277 "grammer.y"
    {
                                    if(findVar((yyvsp[(1) - (1)].stringValue)) == 1)
                                    {
                                        printf("Variable %s has been declared before\n",(yyvsp[(1) - (1)].stringValue));
                                    }
                                    else
                                    {
                                        printf("Variable is : %s\n",(yyvsp[(1) - (1)].stringValue)); 
                                        data[countVar].name = strdup((yyvsp[(1) - (1)].stringValue));
                                        data[countVar].type = strdup(varType[countType]);
                                        data[countVar].intValue = 0;
                                        ++countVar;
                                    }
                                                ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 291 "grammer.y"
    {
                                        if(findVar((yyvsp[(1) - (3)].stringValue)) == 1)
                                        {
                                            printf("Variable %s has been declared before\n",(yyvsp[(1) - (3)].stringValue));
                                        }
                                        else
                                        {
                                            data[countVar].name = strdup((yyvsp[(1) - (3)].stringValue)); data[countVar].intValue = (yyvsp[(3) - (3)].intValue);
                                            data[countVar].type= strdup(varType[countType]);
                                            printf("Variable: %s \t Value: %d \t type :%s\n",data[countVar].name,data[countVar].intValue,data[countVar].type);
                                            ++countVar;
                                        }
        ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 306 "grammer.y"
    {countType = 0;;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 307 "grammer.y"
    {countType = 1;;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 308 "grammer.y"
    {countType = 2;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 309 "grammer.y"
    {countType = 3;;}
    break;



/* Line 1455 of yacc.c  */
#line 1960 "grammer.tab.c"
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
#line 311 "grammer.y"


int yyerror(char *s) {
    printf("Error at line %d: => %s\n",yylineno,s);
    return 0;
}

int main(void) {
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    yyparse();
}


/*
                                        char *n, int t, int i,double d, char c, char *s
                                        if(countType == 1)
                                        {
                                            d = 0;
                                            c = '0';
                                            s = strdup("NULL");
                                        }
                                        else if(countType == 2)
                                        {
                                            i = 0;
                                            c = '0';
                                            s = strdup("NULL");
                                        }
                                        else if(countType == 3)
                                        {
                                            i = 0;
                                            d = 0;
                                            c = strdup();
                                            s = strdup("NULL");

                                        } 
                                        else
                                        {
                                            d = 0;
                                            c = '0';
                                            s = strdup("NULL");
                                        }

*/
