/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "takeo.y"


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lista.h"
#include <string.h>

list *variaveis;
list *tipos;

list *parametros;

int quantidadeParametros = 0;

int whileAtivo = 0;

int labels = 10;
int fors = 10;
int whiles = 10;

int inFunc = 0;

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern FILE *yyout;
FILE *selecoes;

void *imprimeString(void *data);
void *imprimeInteiro(void *data);
void imprimeBefore();
void imprimeAfter();
void read();
void empilhaPrint(char *c);
void writeOutput(char *s);
void yyerror(const char* s);
void imprimeFimMain();

void somaIdentValor(char *ident, int valor);
void atribuiInteiro(char *nome, int valor);
void atribuiPilha(char *nome);
char* itoa(int val);

void imprimeValor(char *identificador);
int idIdentificador(char *identificador);

void leValor(char *identificador);

void somaInteiroInteiro(int a, int b);
void criaVariavel(char *identificador);

void somaVarVar(char *identificador1, char *identificador2);
void atribuicaoSoma(char *identificador);

void novoInteiroSemInicializacao(char *identificador);

void ifIdentIgualInteiro(char *identificador, int valor);
void ifIdentMenorInteiro(char *identificador, int valor);

void volta();
void voltaWhile();

void desvioElse();

int invocaFor(char *identificador, int inicial);
void finalizaFor(int idIdentificador, int limitante, int passo);

void invocaWhile();
void finalizaWhile();

void criaFuncao(int tipo, char *nome);
void finalizaFuncao(int tipo);
void adicionaParametro(int tipo,char *nome);

void preparaParaChamarFuncao(char *nome);
void preparaParaChamarFuncao2(int valor);

void chamaFuncaoAtribuindo(char *identificador, char *nome);


#line 152 "takeo.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_TAKEO_TAB_H_INCLUDED
# define YY_YY_TAKEO_TAB_H_INCLUDED
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
    T_INT = 258,
    T_REAL = 259,
    T_BOOL = 260,
    T_IDENT = 261,
    T_LITERAL = 262,
    T_STR = 263,
    T_TRUE = 264,
    T_FALSE = 265,
    T_END_LINE = 266,
    T_DOIS_PONTOS = 267,
    T_VIRGULA = 268,
    T_STRING_TIPO = 269,
    T_BOOL_TIPO = 270,
    T_INT_TIPO = 271,
    T_REAL_TIPO = 272,
    T_MAIN = 273,
    T_RETURN = 274,
    T_IF = 275,
    T_WHILE = 276,
    T_FOR = 277,
    T_PRINT = 278,
    T_READ = 279,
    T_PLUS = 280,
    T_MINUS = 281,
    T_MULTIPLY = 282,
    T_DIVIDE = 283,
    T_APPEND = 284,
    T_PAR_LEFT = 285,
    T_CHA_LEFT = 286,
    T_PAR_RIGHT = 287,
    T_COL_RIGHT = 288,
    T_CHA_RIGHT = 289,
    T_EQQ = 290,
    T_LESS = 291,
    T_MORE = 292,
    T_EQUAL = 293,
    T_OR = 294,
    T_AND = 295,
    T_COL_LEFT = 296,
    T_THEN1 = 297,
    T_THEN2 = 298,
    T_ELSE = 299,
    T_PREC_STR = 300,
    T_RET = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 84 "takeo.y"

	int ival;
	float fval;
	char *str;

#line 257 "takeo.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TAKEO_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   707

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  175
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  395

#define YYUNDEFTOK  2
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   140,   140,   141,   142,   143,   146,   147,   150,   153,
     154,   155,   156,   159,   160,   161,   164,   165,   166,   167,
     168,   171,   171,   171,   174,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   196,   197,   198,   199,   202,   203,   204,   207,
     208,   209,   210,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   228,   231,   232,   235,
     236,   237,   238,   239,   240,   243,   244,   247,   248,   249,
     250,   251,   252,   253,   256,   257,   260,   264,   265,   266,
     267,   268,   271,   274,   275,   276,   279,   280,   281,   284,
     285,   286,   289,   292,   292,   295,   296,   299,   300,   303,
     304,   304,   307,   310,   311,   314,   315,   318,   318,   318,
     319,   320,   323,   324,   325,   328,   329,   330,   331,   332,
     333,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   383,   384,   385
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_INT", "T_REAL", "T_BOOL", "T_IDENT",
  "T_LITERAL", "T_STR", "T_TRUE", "T_FALSE", "T_END_LINE", "T_DOIS_PONTOS",
  "T_VIRGULA", "T_STRING_TIPO", "T_BOOL_TIPO", "T_INT_TIPO", "T_REAL_TIPO",
  "T_MAIN", "T_RETURN", "T_IF", "T_WHILE", "T_FOR", "T_PRINT", "T_READ",
  "T_PLUS", "T_MINUS", "T_MULTIPLY", "T_DIVIDE", "T_APPEND", "T_PAR_LEFT",
  "T_CHA_LEFT", "T_PAR_RIGHT", "T_COL_RIGHT", "T_CHA_RIGHT", "T_EQQ",
  "T_LESS", "T_MORE", "T_EQUAL", "T_OR", "T_AND", "T_COL_LEFT", "T_THEN1",
  "T_THEN2", "T_ELSE", "T_PREC_STR", "T_RET", "$accept", "inicial",
  "global", "main", "tipo", "parametros", "parametros_chamada", "funcao",
  "$@1", "$@2", "chamada_funcao", "escopo", "comando_unico", "retorno",
  "identificadores", "identificador_inteiro", "novo_inteiro",
  "valores_vetor_int", "identificador_float", "valores_vetor_float",
  "identificador_string", "valores_vetor_string", "string",
  "identificador_bool", "valores_vetor_bool", "booleano",
  "repeticao_uma_linha", "repeticao_varias_linhas", "repeticao_label",
  "while_init", "$@3", "selecao_uma_linha", "selecao_varias_linhas",
  "else", "$@4", "operacao_logica_label", "io", "entrada", "saida", "$@5",
  "$@6", "argumentos_print", "operacao", "operacao_inteira",
  "operacao_real", "operacao_logica", "operacao_string", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF (-285)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-111)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,    77,    65,    88,   116,   130,    24,    16,   496,   134,
    -285,  -285,     4,  -285,  -285,  -285,   123,   153,     5,     6,
    -285,    38,  -285,   496,  -285,  -285,  -285,  -285,  -285,   148,
    -285,   136,  -285,   125,   168,    15,   162,   502,   170,    86,
     166,   203,    12,   205,   201,   224,  -285,   202,   215,  -285,
     245,   225,  -285,     9,   256,  -285,   235,   496,    52,   274,
     273,   272,   234,   255,  -285,   275,  -285,   341,   157,   185,
     300,   390,   264,   291,   515,   114,  -285,  -285,  -285,   195,
     221,  -285,   288,   290,   346,   352,   353,  -285,  -285,  -285,
     356,   355,   383,   398,   377,   496,   402,   384,  -285,   413,
    -285,  -285,   321,  -285,  -285,  -285,  -285,  -285,   403,  -285,
    -285,  -285,   427,   433,   400,  -285,  -285,  -285,  -285,   403,
    -285,  -285,   449,   412,  -285,  -285,   426,  -285,   448,  -285,
     443,   470,   430,   455,   445,  -285,  -285,   471,   390,   390,
    -285,   473,   479,   468,   495,  -285,   553,  -285,   245,  -285,
    -285,   500,   483,   496,   630,   471,   522,  -285,  -285,  -285,
    -285,  -285,  -285,   553,   524,  -285,   528,   500,   500,   532,
    -285,  -285,    70,  -285,   654,     8,  -285,  -285,    65,    88,
     116,   130,   331,   518,   521,   551,   556,    93,  -285,   630,
    -285,  -285,  -285,  -285,   534,   509,  -285,  -285,  -285,  -285,
    -285,  -285,   167,   154,    67,   561,  -285,  -285,  -285,  -285,
    -285,  -285,  -285,  -285,   630,  -285,   287,   493,   516,   333,
    -285,    25,  -285,   333,   360,    17,    98,    18,   241,   286,
    -285,   546,  -285,  -285,  -285,  -285,  -285,  -285,  -285,   333,
    -285,  -285,    93,   131,    93,    93,  -285,    93,    93,    93,
      93,  -285,   333,   333,   333,   333,   333,  -285,   652,  -285,
     334,   461,  -285,   461,  -285,   461,  -285,  -285,   574,   554,
     519,   573,   581,   575,  -285,   586,   583,    98,  -285,  -285,
     588,  -285,  -285,   565,   328,   541,   557,  -285,   557,  -285,
    -285,    46,   541,    46,   541,   557,  -285,   557,  -285,   461,
     461,   461,  -285,  -285,   564,   566,   587,   598,   593,   606,
     579,  -285,  -285,   602,   582,   604,  -285,   603,   485,  -285,
     614,   605,   608,  -285,   609,   514,  -285,   323,   592,   596,
     630,   584,  -285,   597,  -285,  -285,  -285,   616,   627,  -285,
    -285,   630,  -285,   333,   360,   375,   623,  -285,   333,   635,
     610,   397,   611,   581,   628,   584,   543,   619,   625,   636,
    -285,   651,   657,   661,  -285,  -285,   634,   659,   665,   572,
     299,   675,   672,   630,   299,   601,   630,  -285,   673,   684,
     419,   630,  -285,   441,   685,   662,  -285,   463,  -285,   664,
     686,  -285,   687,   299,   299
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    12,    10,     9,    11,     0,     0,     3,     0,
       6,    49,     0,    50,    52,    51,     0,     0,     0,     0,
      66,     0,     1,     2,     7,    12,    10,     9,    11,     0,
       4,     0,    53,     0,     0,    91,     0,     0,    86,     0,
       0,     0,     0,     0,     0,     0,    77,     0,     0,    87,
       0,     0,    69,     0,     0,     5,     0,    15,     0,     0,
       0,     0,     0,     0,    60,     0,    74,     0,     0,     0,
       0,    20,     0,     0,     0,     0,    61,    83,    62,     0,
       0,    81,     0,     0,     0,     0,     0,    93,    95,    94,
       0,     0,     0,     0,     0,    15,     0,     0,    54,     0,
      56,    55,     0,   132,   133,   134,   131,   138,   137,   142,
     141,   173,    18,    16,     0,   174,   175,   143,   136,   135,
     140,   139,     0,     0,    78,    79,     0,    88,     0,    70,
       0,     0,     0,    13,     0,    57,    58,     0,    20,    20,
      24,     0,     0,     0,     0,    80,     0,    89,     0,    71,
      72,     0,     0,    15,   103,    67,     0,    19,    17,    63,
      64,    65,    86,     0,     0,    84,     0,     0,    75,     0,
      21,    14,     0,   144,     0,     0,   159,   160,     0,     0,
       0,     0,     0,     0,     0,   117,     0,     0,    27,   103,
      41,    25,    31,    29,     0,     0,    35,    33,    37,   113,
     114,    39,     0,     0,     0,     0,    68,    59,    85,    82,
      90,    92,    76,    73,   103,   126,     0,     0,     0,     0,
     130,     0,    48,     0,     0,     0,     0,     0,     0,     0,
      28,     0,    26,    32,    30,    36,    34,    38,    40,     0,
     104,   125,     0,     0,     0,     0,   128,     0,     0,     0,
       0,   127,     0,     0,     0,     0,     0,   129,    22,   172,
       0,   171,   169,   168,   166,   165,   162,    46,     0,     0,
     112,     0,     0,     0,   121,     0,     0,   122,   118,   116,
       0,   157,     8,     0,     0,   149,   139,   151,   158,   152,
     150,   153,   145,   154,   146,   155,   147,   156,   148,   170,
     167,   164,   161,   163,     0,     0,     0,     0,     0,     0,
       0,   124,   123,     0,     0,     0,    23,     0,   103,   102,
       0,     0,     0,   119,     0,   103,    47,     0,     0,     0,
     103,   105,    43,     0,    42,    44,    45,     0,     0,   120,
     115,   103,    96,     0,     0,   103,     0,   106,     0,     0,
       0,   103,     0,     0,     0,   107,   103,     0,     0,     0,
      99,     0,     0,     0,   108,   109,     0,     0,     0,   103,
     103,     0,     0,   103,   103,   103,   103,    98,     0,     0,
     103,   103,    97,   103,     0,     0,   111,   103,   101,     0,
       0,   100,     0,   103,   103
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -285,  -285,  -285,   690,     2,   -84,   432,   677,  -285,  -285,
     -15,  -209,  -255,   512,     0,  -285,  -285,   547,  -285,   416,
    -285,   540,   -13,  -285,  -285,   558,  -101,  -183,  -260,  -284,
    -285,   -89,  -175,   349,  -285,  -231,   -56,  -285,  -285,  -285,
    -285,   428,  -134,   -12,  -100,   -33,   691
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,    96,    97,   114,    30,   214,   304,
     188,   189,   331,   190,   191,    11,    12,   156,    13,   169,
      14,   164,   165,    15,   166,    90,   332,   193,   273,   194,
     195,   334,   197,   347,   366,   269,   335,   199,   200,   226,
     313,   278,   336,   202,   203,   204,   205
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,    40,     9,    41,    42,   258,   234,    24,   283,     9,
      29,   132,   308,    92,   236,    32,    46,    49,    61,   220,
     201,    62,     1,    78,    22,    29,    64,    75,   274,   279,
       2,     3,     4,     5,   333,    93,   267,    72,    79,    80,
      65,   333,    33,    47,    50,    34,    48,    51,   222,    52,
      67,    68,    69,   192,    70,   238,   108,   110,   275,   280,
     216,   217,   218,    98,   219,   196,   268,   119,   121,   171,
     342,    18,   333,   243,   244,   234,    53,    65,   251,    54,
     201,   215,   245,   236,   354,   333,   333,   229,   233,    73,
     333,   333,    74,   362,    19,    65,    73,   173,   198,    74,
     235,   365,   252,   253,   254,   162,   255,   256,   144,   333,
     333,   276,   352,   192,   377,    16,    39,   357,    17,   342,
     382,   345,    20,   187,   238,   196,    35,    36,    58,    37,
      38,    59,   351,   237,    73,   173,    21,   120,   377,   382,
      79,    80,   285,   287,   289,   290,   117,   292,   294,   296,
     298,    60,    31,    39,    56,    39,    44,   233,   198,    45,
      73,   187,   234,   107,   380,   246,    57,   383,   234,   235,
     236,    63,   387,    66,   230,   228,   236,    76,   241,   247,
     248,   249,   250,   261,   263,   265,   266,    39,    73,   232,
     270,   109,   242,    79,   243,   244,   201,   234,    73,    72,
     234,   118,   237,   245,   234,   236,   270,   201,   236,    84,
      85,   238,   236,   277,    77,    39,    81,   238,    86,   299,
     300,   301,   302,   303,    73,    39,   272,   120,    91,   192,
     284,   286,   288,   284,    82,   291,   293,   295,   297,   201,
     192,   196,   201,   230,   233,   101,   238,   201,    87,   238,
     233,    39,   196,   238,    88,    89,   235,    83,   232,    94,
      79,    80,   235,   311,   277,    95,   242,    79,   243,   244,
     115,   116,   192,   117,   198,   192,    99,   245,   103,   233,
     192,   104,   233,   100,   196,   198,   233,   196,   102,   237,
     259,   235,   196,   260,   235,   237,   176,   177,   235,    67,
      68,    69,   172,   173,    71,   327,   175,   111,   176,   177,
     270,   247,   248,   249,   250,   270,    65,   198,   281,   328,
     198,   329,   185,   186,   237,   198,   122,   237,   123,   187,
     230,   237,   136,   137,   172,   173,   230,   221,   175,   260,
     176,   177,   176,   177,   105,   232,   353,   106,    67,    68,
      69,   232,    70,   242,    79,   243,   244,   124,   216,   217,
     218,   187,   219,   125,   245,   230,   271,   127,   230,   216,
     217,   218,   230,   219,    25,    26,    27,    28,   172,   173,
     232,   174,   175,   232,   176,   177,   126,   232,   128,   178,
     179,   180,   181,   112,   129,   183,   113,   184,   185,   186,
     172,   173,   130,   174,   175,   187,   176,   177,   133,   355,
     131,   178,   179,   180,   181,   142,   134,   183,   143,   184,
     185,   186,   172,   173,   135,   174,   175,   187,   176,   177,
      80,   360,   140,   178,   179,   180,   181,   145,   146,   183,
     138,   184,   185,   186,   172,   173,   139,   174,   175,   187,
     176,   177,   141,   386,   149,   178,   179,   180,   181,   147,
     148,   183,   152,   184,   185,   186,   172,   173,   153,   174,
     175,   187,   176,   177,   155,   388,   154,   178,   179,   180,
     181,   150,   151,   183,   159,   184,   185,   186,   172,   173,
     160,   327,   175,   187,   176,   177,   262,   391,    71,   260,
     255,   256,   176,   177,   168,   328,   161,   329,   185,   186,
      25,    26,    27,    28,   170,   187,   330,   172,   173,   264,
     327,   175,   260,   176,   177,   176,   177,    67,    68,    69,
     240,    70,    71,   207,   328,   209,   329,   185,   186,   210,
      67,    68,    69,   213,   187,   341,   172,   173,   223,   327,
     175,   224,   176,   177,   252,   253,   254,   225,   255,   256,
     162,   163,   227,   328,   239,   329,   185,   186,   249,   250,
     157,   158,   257,   187,  -110,   172,   173,   305,   327,   175,
     282,   176,   177,   211,   212,   307,   306,   271,   309,   310,
     162,   314,   328,   245,   329,   185,   186,   315,   316,   318,
     317,   319,   187,   376,   172,   173,   320,   327,   175,   321,
     176,   177,   322,   323,   326,   324,   325,   337,   338,   339,
     340,   328,   343,   329,   185,   186,   344,   348,   346,   349,
     350,   187,   381,   172,   173,   356,   174,   175,   358,   176,
     177,   363,   359,   361,   178,   179,   180,   181,   369,   182,
     183,   367,   184,   185,   186,   172,   173,   368,   174,   175,
     187,   176,   177,   370,   372,   373,   178,   179,   180,   181,
     371,   374,   183,  -103,   184,   185,   186,   375,   378,    67,
      68,    69,   187,    70,    71,   379,   384,   385,   389,   216,
     217,   218,    16,   219,   390,    17,   392,    23,   393,   394,
      55,   231,   206,   208,   364,   312,   167,    43
};

static const yytype_int16 yycheck[] =
{
       0,    16,     0,    16,    16,   214,   189,     7,   239,     7,
       8,    95,   272,     4,   189,    11,    11,    11,    33,    11,
     154,    33,     6,    11,     0,    23,    11,    39,    11,    11,
      14,    15,    16,    17,   318,    26,    11,    29,    26,    27,
      25,   325,    38,    38,    38,    41,    41,    41,   182,    11,
      25,    26,    27,   154,    29,   189,    68,    69,    41,    41,
      35,    36,    37,    11,    39,   154,    41,    79,    80,   153,
     325,     6,   356,    27,    28,   258,    38,    25,    11,    41,
     214,    11,    36,   258,   344,   369,   370,   187,   189,     3,
     374,   375,     6,   353,     6,    25,     3,     4,   154,     6,
     189,   356,    35,    36,    37,     7,    39,    40,   123,   393,
     394,    13,   343,   214,   369,    38,    30,   348,    41,   374,
     375,   330,     6,    30,   258,   214,     3,     4,     3,     6,
       7,     6,   341,   189,     3,     4,     6,     6,   393,   394,
      26,    27,   242,   243,   244,   245,    32,   247,   248,   249,
     250,    26,    18,    30,     6,    30,     3,   258,   214,     6,
       3,    30,   345,     6,   373,    11,    30,   376,   351,   258,
     345,     3,   381,    11,   189,   187,   351,    11,    11,    25,
      26,    27,    28,   216,   217,   218,   219,    30,     3,   189,
     223,     6,    25,    26,    27,    28,   330,   380,     3,    29,
     383,     6,   258,    36,   387,   380,   239,   341,   383,     7,
       8,   345,   387,   226,    11,    30,    11,   351,     3,   252,
     253,   254,   255,   256,     3,    30,   224,     6,     3,   330,
     242,   243,   244,   245,    33,   247,   248,   249,   250,   373,
     341,   330,   376,   258,   345,    11,   380,   381,     3,   383,
     351,    30,   341,   387,     9,    10,   345,    33,   258,     3,
      26,    27,   351,   276,   277,    30,    25,    26,    27,    28,
       6,     7,   373,    32,   330,   376,     3,    36,     3,   380,
     381,     6,   383,    11,   373,   341,   387,   376,    33,   345,
       3,   380,   381,     6,   383,   351,     9,    10,   387,    25,
      26,    27,     3,     4,    30,     6,     7,     7,     9,    10,
     343,    25,    26,    27,    28,   348,    25,   373,    32,    20,
     376,    22,    23,    24,   380,   381,    38,   383,    38,    30,
     345,   387,    11,    12,     3,     4,   351,     6,     7,     6,
       9,    10,     9,    10,     3,   345,   344,     6,    25,    26,
      27,   351,    29,    25,    26,    27,    28,    11,    35,    36,
      37,    30,    39,    11,    36,   380,     6,    11,   383,    35,
      36,    37,   387,    39,    14,    15,    16,    17,     3,     4,
     380,     6,     7,   383,     9,    10,    33,   387,    33,    14,
      15,    16,    17,     3,    11,    20,     6,    22,    23,    24,
       3,     4,     4,     6,     7,    30,     9,    10,     6,    34,
      33,    14,    15,    16,    17,     3,    32,    20,     6,    22,
      23,    24,     3,     4,    11,     6,     7,    30,     9,    10,
      27,    34,    32,    14,    15,    16,    17,    11,    12,    20,
      13,    22,    23,    24,     3,     4,    13,     6,     7,    30,
       9,    10,     3,    34,    11,    14,    15,    16,    17,    11,
      12,    20,    32,    22,    23,    24,     3,     4,    13,     6,
       7,    30,     9,    10,     3,    34,    31,    14,    15,    16,
      17,    11,    12,    20,    11,    22,    23,    24,     3,     4,
      11,     6,     7,    30,     9,    10,     3,    34,    30,     6,
      39,    40,     9,    10,     4,    20,    11,    22,    23,    24,
      14,    15,    16,    17,    31,    30,    31,     3,     4,     3,
       6,     7,     6,     9,    10,     9,    10,    25,    26,    27,
      21,    29,    30,    11,    20,    11,    22,    23,    24,    11,
      25,    26,    27,    11,    30,    31,     3,     4,    30,     6,
       7,    30,     9,    10,    35,    36,    37,     6,    39,    40,
       7,     8,     6,    20,    30,    22,    23,    24,    27,    28,
     138,   139,    11,    30,    31,     3,     4,     3,     6,     7,
      34,     9,    10,   167,   168,    12,    32,     6,    13,     3,
       7,     3,    20,    36,    22,    23,    24,    32,    34,    12,
      34,     3,    30,    31,     3,     4,    13,     6,     7,     3,
       9,    10,    33,    11,    11,    33,    12,     3,    13,    11,
      11,    20,    30,    22,    23,    24,    30,    30,    44,    13,
       3,    30,    31,     3,     4,    12,     6,     7,     3,     9,
      10,    13,    32,    32,    14,    15,    16,    17,    12,    19,
      20,    32,    22,    23,    24,     3,     4,    32,     6,     7,
      30,     9,    10,    12,     3,    31,    14,    15,    16,    17,
      13,    12,    20,    21,    22,    23,    24,    12,     3,    25,
      26,    27,    30,    29,    30,    13,    13,     3,     3,    35,
      36,    37,    38,    39,    32,    41,    32,     7,    12,    12,
      23,   189,   155,   163,   355,   277,   148,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    14,    15,    16,    17,    48,    49,    50,    51,
      61,    62,    63,    65,    67,    70,    38,    41,     6,     6,
       6,     6,     0,    50,    61,    14,    15,    16,    17,    51,
      54,    18,    11,    38,    41,     3,     4,     6,     7,    30,
      57,    69,    90,    93,     3,     6,    11,    38,    41,    11,
      38,    41,    11,    38,    41,    54,     6,    30,     3,     6,
      26,    57,    90,     3,    11,    25,    11,    25,    26,    27,
      29,    30,    29,     3,     6,    90,    11,    11,    11,    26,
      27,    11,    33,    33,     7,     8,     3,     3,     9,    10,
      72,     3,     4,    26,     3,    30,    51,    52,    11,     3,
      11,    11,    33,     3,     6,     3,     6,     6,    90,     6,
      90,     7,     3,     6,    53,     6,     7,    32,     6,    90,
       6,    90,    38,    38,    11,    11,    33,    11,    33,    11,
       4,    33,    52,     6,    32,    11,    11,    12,    13,    13,
      32,     3,     3,     6,    57,    11,    12,    11,    12,    11,
      11,    12,    32,    13,    31,     3,    64,    53,    53,    11,
      11,    11,     7,     8,    68,    69,    71,    72,     4,    66,
      31,    52,     3,     4,     6,     7,     9,    10,    14,    15,
      16,    17,    19,    20,    22,    23,    24,    30,    57,    58,
      60,    61,    73,    74,    76,    77,    78,    79,    83,    84,
      85,    89,    90,    91,    92,    93,    64,    11,    68,    11,
      11,    66,    66,    11,    55,    11,    35,    36,    37,    39,
      11,     6,    89,    30,    30,     6,    86,     6,    90,    91,
      57,    60,    61,    73,    74,    78,    79,    83,    89,    30,
      21,    11,    25,    27,    28,    36,    11,    25,    26,    27,
      28,    11,    35,    36,    37,    39,    40,    11,    58,     3,
       6,    92,     3,    92,     3,    92,    92,    11,    41,    82,
      92,     6,    51,    75,    11,    41,    13,    69,    88,    11,
      41,    32,    34,    82,    90,    91,    90,    91,    90,    91,
      91,    90,    91,    90,    91,    90,    91,    90,    91,    92,
      92,    92,    92,    92,    56,     3,    32,    12,    75,    13,
       3,    69,    88,    87,     3,    32,    34,    34,    12,     3,
      13,     3,    33,    11,    33,    12,    11,     6,    20,    22,
      31,    59,    73,    76,    78,    83,    89,     3,    13,    11,
      11,    31,    59,    30,    30,    58,    44,    80,    30,    13,
       3,    58,    82,    51,    75,    34,    12,    82,     3,    32,
      34,    32,    75,    13,    80,    59,    81,    32,    32,    12,
      12,    13,     3,    31,    12,    12,    31,    59,     3,    13,
      58,    31,    59,    58,    13,     3,    34,    58,    34,     3,
      32,    34,    32,    12,    12
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    48,    48,    48,    49,    49,    50,    51,
      51,    51,    51,    52,    52,    52,    53,    53,    53,    53,
      53,    55,    56,    54,    57,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    59,    59,    59,    59,    60,    60,    60,    61,
      61,    61,    61,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    63,    64,    64,    65,
      65,    65,    65,    65,    65,    66,    66,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    69,    70,    70,    70,
      70,    70,    71,    72,    72,    72,    73,    73,    73,    74,
      74,    74,    75,    77,    76,    78,    78,    79,    79,    80,
      81,    80,    82,    83,    83,    84,    84,    86,    87,    85,
      85,    85,    88,    88,    88,    89,    89,    89,    89,    89,
      89,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    93,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     3,     1,     2,     9,     1,
       1,     1,     1,     2,     4,     0,     1,     3,     1,     3,
       0,     0,     0,    10,     4,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     3,     6,     2,     1,
       1,     1,     1,     2,     4,     4,     4,     5,     5,     7,
       4,     4,     4,     7,     7,     7,     2,     1,     2,     3,
       5,     6,     6,     8,     4,     1,     2,     3,     5,     5,
       6,     4,     8,     4,     1,     2,     1,     3,     5,     6,
       8,     3,     2,     1,     1,     1,     6,    11,    10,     8,
      13,    12,     3,     0,     2,     6,     7,     8,     9,     3,
       0,     6,     1,     1,     1,     6,     3,     0,     0,     5,
       6,     3,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 8:
#line 150 "takeo.y"
                                                                                          {imprimeFimMain();}
#line 1761 "takeo.tab.c"
    break;

  case 9:
#line 153 "takeo.y"
                                        {(yyval.ival)=1;}
#line 1767 "takeo.tab.c"
    break;

  case 10:
#line 154 "takeo.y"
                                        {(yyval.ival)=2;}
#line 1773 "takeo.tab.c"
    break;

  case 11:
#line 155 "takeo.y"
                                        {(yyval.ival)=3;}
#line 1779 "takeo.tab.c"
    break;

  case 12:
#line 156 "takeo.y"
                                        {(yyval.ival)=4;}
#line 1785 "takeo.tab.c"
    break;

  case 13:
#line 159 "takeo.y"
                                                                                {adicionaParametro((yyvsp[-1].ival),(yyvsp[0].str));}
#line 1791 "takeo.tab.c"
    break;

  case 14:
#line 160 "takeo.y"
                                                                        {adicionaParametro((yyvsp[-3].ival),(yyvsp[-2].str));}
#line 1797 "takeo.tab.c"
    break;

  case 16:
#line 164 "takeo.y"
                                                                                {preparaParaChamarFuncao((yyvsp[0].str));}
#line 1803 "takeo.tab.c"
    break;

  case 17:
#line 165 "takeo.y"
                                                                {preparaParaChamarFuncao((yyvsp[-2].str));}
#line 1809 "takeo.tab.c"
    break;

  case 18:
#line 166 "takeo.y"
                                                                                                {preparaParaChamarFuncao2((yyvsp[0].ival));}
#line 1815 "takeo.tab.c"
    break;

  case 19:
#line 167 "takeo.y"
                                                                {preparaParaChamarFuncao2((yyvsp[-2].ival));}
#line 1821 "takeo.tab.c"
    break;

  case 21:
#line 171 "takeo.y"
                                                                  {criaFuncao((yyvsp[-5].ival),(yyvsp[-4].str));}
#line 1827 "takeo.tab.c"
    break;

  case 22:
#line 171 "takeo.y"
                                                                                              {finalizaFuncao((yyvsp[-7].ival));}
#line 1833 "takeo.tab.c"
    break;

  case 24:
#line 174 "takeo.y"
                                                                                        {(yyval.str)=(yyvsp[-3].str);}
#line 1839 "takeo.tab.c"
    break;

  case 54:
#line 214 "takeo.y"
                                                                                                                                                        {atribuiInteiro((yyvsp[-3].str),(yyvsp[-1].ival));}
#line 1845 "takeo.tab.c"
    break;

  case 55:
#line 215 "takeo.y"
                                                                                                                                                {atribuiPilha((yyvsp[-3].str));}
#line 1851 "takeo.tab.c"
    break;

  case 56:
#line 216 "takeo.y"
                                                                                                                                                {chamaFuncaoAtribuindo((yyvsp[-3].str),(yyvsp[-1].str));}
#line 1857 "takeo.tab.c"
    break;

  case 61:
#line 221 "takeo.y"
                                                                                                                                                        {chamaFuncaoAtribuindo((yyvsp[-3].str),(yyvsp[-1].str));}
#line 1863 "takeo.tab.c"
    break;

  case 62:
#line 222 "takeo.y"
                                                                                                                                                {atribuicaoSoma((yyvsp[-3].str));}
#line 1869 "takeo.tab.c"
    break;

  case 66:
#line 228 "takeo.y"
                                 {novoInteiroSemInicializacao((yyvsp[0].str)); (yyval.str) = (yyvsp[0].str);}
#line 1875 "takeo.tab.c"
    break;

  case 86:
#line 260 "takeo.y"
                                                {(yyval.str) = (yyvsp[0].str);}
#line 1881 "takeo.tab.c"
    break;

  case 99:
#line 284 "takeo.y"
                                                                                                                                        {finalizaWhile();}
#line 1887 "takeo.tab.c"
    break;

  case 101:
#line 286 "takeo.y"
                                                                                                                                                                        {finalizaFor((yyvsp[-9].ival),(yyvsp[-7].ival),(yyvsp[-5].ival));}
#line 1893 "takeo.tab.c"
    break;

  case 102:
#line 289 "takeo.y"
                                             {(yyval.ival)=invocaFor((yyvsp[-2].str),(yyvsp[0].ival));}
#line 1899 "takeo.tab.c"
    break;

  case 103:
#line 292 "takeo.y"
            {invocaWhile();}
#line 1905 "takeo.tab.c"
    break;

  case 107:
#line 299 "takeo.y"
                                                                                                                                                        {volta();}
#line 1911 "takeo.tab.c"
    break;

  case 110:
#line 304 "takeo.y"
                               {desvioElse();}
#line 1917 "takeo.tab.c"
    break;

  case 111:
#line 304 "takeo.y"
                                                                             {volta();}
#line 1923 "takeo.tab.c"
    break;

  case 112:
#line 307 "takeo.y"
                                       {}
#line 1929 "takeo.tab.c"
    break;

  case 116:
#line 315 "takeo.y"
                                                                                                                                                        {leValor((yyvsp[-1].str));}
#line 1935 "takeo.tab.c"
    break;

  case 117:
#line 318 "takeo.y"
               {imprimeBefore();}
#line 1941 "takeo.tab.c"
    break;

  case 118:
#line 318 "takeo.y"
                                                   {imprimeAfter();}
#line 1947 "takeo.tab.c"
    break;

  case 121:
#line 320 "takeo.y"
                                                                                                                                                {imprimeValor((yyvsp[-1].str));}
#line 1953 "takeo.tab.c"
    break;

  case 122:
#line 323 "takeo.y"
                                                                                        {empilhaPrint((yyvsp[0].str));}
#line 1959 "takeo.tab.c"
    break;

  case 123:
#line 324 "takeo.y"
                                                                                        {empilhaPrint((yyvsp[-1].str));}
#line 1965 "takeo.tab.c"
    break;

  case 124:
#line 325 "takeo.y"
                                                                                                {empilhaPrint((yyvsp[0].str));}
#line 1971 "takeo.tab.c"
    break;

  case 131:
#line 336 "takeo.y"
                                                                                                        {somaVarVar((yyvsp[-2].str),(yyvsp[0].str));}
#line 1977 "takeo.tab.c"
    break;

  case 132:
#line 337 "takeo.y"
                                                                                                                        {somaInteiroInteiro((yyvsp[-2].ival),(yyvsp[0].ival));}
#line 1983 "takeo.tab.c"
    break;

  case 133:
#line 338 "takeo.y"
                                                                                                                        {somaIdentValor((yyvsp[0].str),(yyvsp[-2].ival));}
#line 1989 "takeo.tab.c"
    break;

  case 134:
#line 339 "takeo.y"
                                                                                                                        {somaIdentValor((yyvsp[-2].str),(yyvsp[0].ival));}
#line 1995 "takeo.tab.c"
    break;

  case 169:
#line 378 "takeo.y"
                                                                                                                        {ifIdentMenorInteiro((yyvsp[-2].str),(yyvsp[0].ival));}
#line 2001 "takeo.tab.c"
    break;

  case 172:
#line 381 "takeo.y"
                                                                                                                        {ifIdentIgualInteiro((yyvsp[-2].str),(yyvsp[0].ival));}
#line 2007 "takeo.tab.c"
    break;


#line 2011 "takeo.tab.c"

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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
#line 388 "takeo.y"


int main(int argc, char *argv[])
{
    ++argv, --argc;
	char ch;
	if ( argc > 0 ){
		yyin = fopen(argv[0], "r" );
	}
	else{
		yyin = stdin;
	}

	yyout = fopen("out.j","w");
	FILE *model = fopen("jasmin/model.j","r");
	
	if (yyout == NULL || model == NULL ){
		printf("Falha durante a compilação");
	}

	while ((ch = fgetc(model)) != EOF)
      fputc(ch, yyout);

	variaveis = list_create(sizeof(char) * 20);
	tipos = list_create(sizeof(int));

	parametros = list_create(sizeof(int));

	do {
		yyparse();
	} while(!feof(yyin));

	list_destroy(variaveis);
	list_destroy(tipos);

	list_destroy(parametros);

	fclose(model);
	fclose(yyout);

	printf("Compilado com sucesso!\n");

	return 0;
}


void imprimeFimMain(){
	writeOutput("\n\treturn");
    writeOutput("\n.end method\n");
	list_destroy(variaveis);
	variaveis = list_create(sizeof(char) * 20);
}

void imprimeBefore(){
	writeOutput("\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;");
}

void read(){
	writeOutput("\n\tgetstatic java/lang/System/in Ljava/io/InputStream;");
	writeOutput("\n\tinvokevirtual java/io/InputStream/read()I");
}

void imprimeAfter(){
	writeOutput("\n\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V");
}

int idIdentificador(char *identificador){
	int ret = -1;
	for(int i=0;i<variaveis->tam;i++){
		if( strcmp((char*)(elementAt(variaveis,i)),identificador)== 0){
			ret = i;
		}
	}
	if(inFunc == 0){
		ret++;
	}
	return ret;
}

void imprimeValor(char *identificador){
	writeOutput("\n\tiload ");
	int id = idIdentificador(identificador);
	if(id != 0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
	writeOutput("\n\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap");
	writeOutput("\n\tinvokevirtual java/io/PrintStream/println(I)V\n");
}


void empilhaPrint(char *c){
	writeOutput("\n\tldc \"");
	writeOutput(c);
	writeOutput("\"");
}

void writeOutput(char *s){
	fprintf(yyout,"%s", s);
}

void writeSelecoes(char *s){
	fprintf(selecoes,"%s", s);
}

void yyerror(const char* s) {
	fprintf(stderr, "Erro de análise (sintática): %s\n", s);
	exit(1);
}

void novoInteiroSemInicializacao(char *identificador){
	push(variaveis,identificador,variaveis->tam);
	writeOutput("\n\tldc 0\n\tistore ");
	int id = variaveis->tam;
	if(id>0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
}

void atribuiPilha(char *nome){
	writeOutput("\n\tistore ");
	int id = variaveis->tam;
	if(id>0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
}

void atribuiInteiro(char *nome, int valor){
	writeOutput("\n\tldc ");
	if(valor!=0){
		writeOutput(itoa(valor));
	}else{
		writeOutput("0");
	}
	
	writeOutput("\n\tistore ");
	int id = variaveis->tam;
	if(id>0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
	writeOutput("\n");
	
}

char* itoa(int val){
	static char buf[32] = {0};
	if(val==0) return &buf[0];
	int i = 30;
	for(; val && i ; --i, val /= 10)
		buf[i] = "0123456789abcdef"[val % 10];
	return &buf[i+1];
}

void somaIdentValor(char *ident, int valor){
	int id = idIdentificador(ident);
	writeOutput("\n\tiload ");
	if(id!=0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
	writeOutput("\n\tldc ");
	writeOutput(itoa(valor));
	writeOutput("\n\tiadd");
}

void somaInteiroInteiro(int a, int b){
	writeOutput("\n\tldc ");
	writeOutput(itoa(a));
	writeOutput("\n\tldc ");
	writeOutput(itoa(b));
	writeOutput("\n\tiadd");
}


void leValor(char *identificador){
	int id = idIdentificador(identificador);
	writeOutput("\n\tinvokestatic Output.read()I");
	writeOutput("\n\tistore ");
	if(id>0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
	
}

void somaVarVar(char *identificador1, char *identificador2){
	int id1 = idIdentificador(identificador1);
	int id2 = idIdentificador(identificador2);
	writeOutput("\n\tiload ");
	if(id1 !=0){
		writeOutput(itoa(id1));
	}else{
		writeOutput("0");
	}
	writeOutput("\n\tiload ");
	if(id2!=0){
		writeOutput(itoa(id2));
	}else{
		writeOutput("0");
	}
	writeOutput("\n\tiadd");
}

void atribuicaoSoma(char *identificador){
	int id = idIdentificador(identificador);
	writeOutput("\n\tistore ");
	if(id>0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
}

void ifIdentIgualInteiro(char *identificador, int valor){
	int id = idIdentificador(identificador);
	writeOutput("\n\tiload ");
	if(id!=0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
	writeOutput("\n\tldc ");
	writeOutput(itoa(valor));
	writeOutput("\n\tisub");
	writeOutput("\n\tifne Label");
	writeOutput(itoa(labels));
}

void ifIdentMenorInteiro(char *identificador, int valor){
	int id = idIdentificador(identificador);
	writeOutput("\n\tiload ");
	if(id!=0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
	writeOutput("\n\tldc ");
	writeOutput(itoa(valor));
	writeOutput("\n\tisub");
	writeOutput("\n\tifge Label");
	writeOutput(itoa(labels));
}


void volta(){
	writeOutput("\nLabel");
	writeOutput(itoa(labels));
	writeOutput(":");
	labels++;
}

void desvioElse(){
	writeOutput("\n\tgoto Label");
	writeOutput(itoa(labels+1));
	writeOutput("\nLabel");
	writeOutput(itoa(labels));
	writeOutput(":");
	labels++;
}

int invocaFor(char *identificador, int inicial){
	novoInteiroSemInicializacao(identificador);
	atribuiInteiro(identificador, inicial);
	int id = idIdentificador(identificador);
	writeOutput("\nFor");
	writeOutput(itoa(fors));
	writeOutput(":");
	return id;
}

void invocaWhile(){
	whileAtivo = 1;
	labels++;
	writeOutput("\nWhile");
	writeOutput(itoa(whiles));
	writeOutput(":");
}

void finalizaFor(int idIdentificador, int limitante, int passo){
	writeOutput("\n\tiinc ");
	if(idIdentificador!=0){
		writeOutput(itoa(idIdentificador));
	}else{
		writeOutput(itoa(idIdentificador));
	}
	writeOutput(" ");
	writeOutput(itoa(passo));
	writeOutput("\n\tldc ");
	writeOutput(itoa(limitante));
	writeOutput("\n\tiload ");
	if(idIdentificador!=0){
		writeOutput(itoa(idIdentificador));
	}else{
		writeOutput("0");
	}
	writeOutput("\n\tisub");
	writeOutput("\n\tifle Fim");
	writeOutput(itoa(fors+1));
	writeOutput("\n\tgoto For");
	writeOutput(itoa(fors));
	writeOutput("\nFim");
	writeOutput(itoa(fors+1));
	writeOutput(":");
	fors++;
}

void finalizaWhile(){
	writeOutput("\n\tgoto While");
	writeOutput(itoa(whiles));
	writeOutput("\nLabel");
	writeOutput(itoa(labels));
	writeOutput(":");
	labels++;
	whileAtivo = 0;
}

void criaFuncao(int tipo, char *nome){
	inFunc = 1;
	writeOutput(".method public static ");
	writeOutput(nome);
	writeOutput("(");
	for(int i=0;i<quantidadeParametros;i++){
		writeOutput("I");
	}
	writeOutput(")");
	writeOutput("I");
	writeOutput("\n\t.limit stack 5");
	writeOutput("\n\t.limit locals 5");
}

void finalizaFuncao(int tipo){
	inFunc = 0;
	writeOutput("\n\tireturn");
	writeOutput("\n.end method");
}

void adicionaParametro(int tipo , char *nome){
	push(parametros,(void*)(&tipo),parametros->tam);
	push(variaveis,nome,variaveis->tam);
}

void preparaParaChamarFuncao(char *nome){
	int id = idIdentificador(nome);
	writeOutput("\n\tiload ");
	if(id!=0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
	quantidadeParametros++;
}

void preparaParaChamarFuncao2(int valor){
	writeOutput("\n\tldc ");
	if(valor!=0){
		writeOutput(itoa(valor));
	}else{
		writeOutput("0");
	}
	quantidadeParametros++;
}

void chamaFuncaoAtribuindo(char *identificador, char *nome){
	writeOutput("\n\tinvokestatic Output/");
	writeOutput(nome);
	writeOutput("(");
	for(int i=0;i<quantidadeParametros;i++){
		writeOutput("I");
	}
	writeOutput(")");
	writeOutput("I\n\tistore ");
	int id = idIdentificador(identificador);
	if(id>0){
		writeOutput(itoa(id));
	}else{
		writeOutput("0");
	}
}
