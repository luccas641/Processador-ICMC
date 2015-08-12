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
#line 11 "parser.y" /* yacc.c:339  */

#include "node.hpp"
#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <assert.h>

#define YYDEBUG 1

/* ***** Precisamos disso aqui para fazer o parser funcionar ***** */
extern int yylex();                 // funcao do lexico que retorna o proximo token
int yyerror(const char *errmsg);    // funcao que mostra uma mensagem de erro qnd o parser acha um erro gramatical no codigo

extern FILE *yyin;                  // ponteiro para o arquivo de entrada. Precisa dele para chamar o parser mais de uma vez
extern int yylineno;                // numero da linha

using namespace std;

/* ***** Isso aqui e' para a parte semantica ***** */
TAD *t;                             // tabela de simbolos

bool declarado = false;
bool preProcessamento = false;

// debug
int debug = 0;
bool debug_sintatico = false;
bool debug_instrucao = true;

// nao ter return em funcao que nao eh void
// declarar uma funcao dentro de outra
int stack = 28000;      // inicio da stack na memoria
int offset = 0;
int ifseq = 0;
int loopseq = 0;
vector<int> loop_stack;
vector<int> if_stack;


int initialization_size = 0;

int salva_stack = -1;
string salva_identificador;
int stack_ampersand = -1;

int flag_ponteiro = -1;

// caso especial de matriz
int endereco_base;
int offset_linha;
int offset_coluna;

vector<int> initializer_list;

typedef enum {nenhuma, ampersand, asterisco, exclamacao, menos} operacao_unaria;
operacao_unaria operacao = nenhuma;


typedef enum {eq, mul_eq, div_eq, mod_eq, add_eq, sub_eq, inc_eq, dec_eq, land_eq, lxor_eq, lor_eq} tipo_atribuicao;
tipo_atribuicao atribuicao = eq;

int stack_antes_de_entrar_no_escopo; // para a stack voltar para a posicao que estava apos sair do escopo

Entrada *f = NULL;              // referencia para a funcao corrente
Entrada *e = NULL;
bool begin_parametro = false;   // flag para comecar a guarda tudo como parametro
bool type_void = false;         // flag para checa o tipo void, funciona junto com isFunctionVoid
vector<int> arg_list;

int insideLoop = 0;             // serve para evitar breaks fora de loops
bool isFunctionVoid = false;    // serve para evitar returns em funcoes void
bool funcao_tem_return = false; // serve para evitar que funcao void tenha return

vector<int> switch_stack;
int insideSwitch = 0;
int insideCase = 0;
int statement_seq = 0;
int case_seq = 0;
int switch_seq = 0;

// mensagens de erro
void errorMsg(string msg);
void warningMsg(string msg);

// verifica se o identificador que esta sendo declarado ja esta na tabela de simbolos
bool declarando(string &id);
bool referenciando(string &id);

void declara_variaveis_e_parametros(string id, int nbytes);
void declara_label(string id);
void declara_funcao(string id);

// como nao tem include, o arquivo deve ter main para ser executado
bool tem_main = false;
bool is_main = false;

int mapa[32000];

int correcao_stack_matriz = -1; // correcao da posicao da stack quando se declara matriz

void checa_label(string id);

void referencia_funcao(string id);

string int_or_char(string id);

void push(string value, int a);

string to_str(int value);

void expressao_binaria(char op);

void relacao_binaria(char op);

void msg_sintatico(string msg);

void msg_instrucao(string msg);

void salva_tipo(string tipo);

void function_definition();


#line 191 "parser.cpp" /* yacc.c:339  */

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
   by #include "parser.hpp".  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    STRING_LITERAL = 258,
    IDENTIFIER = 259,
    CONSTANT = 260,
    MENOR = 261,
    MAIOR = 262,
    MENOR_IGUAL = 263,
    MAIOR_IGUAL = 264,
    IGUAL_IGUAL = 265,
    EXCLAMACAO_IGUAL = 266,
    AMPERSAND_AMPERSAND = 267,
    PIPE_PIPE = 268,
    EXCLAMACAO = 269,
    IGUAL = 270,
    MAIS_IGUAL = 271,
    MENOS_IGUAL = 272,
    ASTERISCO_IGUAL = 273,
    BARRA_IGUAL = 274,
    MAIOR_MAIOR_IGUAL = 275,
    MENOR_MENOR_IGUAL = 276,
    PORCENTAGEM_IGUAL = 277,
    CIRCUNFLEXO_IGUAL = 278,
    AMPERSAND_IGUAL = 279,
    PIPE_IGUAL = 280,
    VOID = 281,
    INT = 282,
    CHAR = 283,
    BOOL = 284,
    IF = 285,
    ELSE = 286,
    FOR = 287,
    WHILE = 288,
    BREAK = 289,
    SWITCH = 290,
    CASE = 291,
    CONTINUE = 292,
    INCLUDE = 293,
    GOTO = 294,
    RETURN = 295,
    CONST = 296,
    DEFAULT = 297,
    EXTERN = 298,
    STATIC = 299,
    MAIS = 300,
    MENOS = 301,
    MAIS_MAIS = 302,
    MENOS_MENOS = 303,
    ASTERISCO = 304,
    BARRA = 305,
    PORCENTAGEM = 306,
    CIRCUNFLEXO = 307,
    DOIS_PONTOS = 308,
    VIRGULA = 309,
    PONTO_VIRGULA = 310,
    INTERROGACAO = 311,
    SUSTENIDO = 312,
    ABRE_COLCHETES = 313,
    FECHA_COLCHETES = 314,
    ABRE_PARENTESES = 315,
    FECHA_PARENTESES = 316,
    ABRE_CHAVES = 317,
    FECHA_CHAVES = 318,
    MENOR_MENOR = 319,
    MAIOR_MAIOR = 320,
    PIPE = 321,
    AMPERSAND = 322,
    TIL = 323,
    BREAKP = 324,
    OUT = 325,
    IN = 326,
    UNSIGNED = 327,
    UNION = 328,
    TYPE_NAME = 329,
    TYPEDEF = 330,
    STRUCT = 331,
    SIZEOF = 332,
    SIGNED = 333,
    RESTRICT = 334,
    REGISTER = 335,
    INLINE = 336,
    IMAGINARY = 337,
    ELLIPSIS = 338,
    DO = 339,
    COMPLEX = 340,
    AUTO = 341,
    VOLATILE = 342,
    ENUM = 343,
    PONTO = 344,
    DOUBLE = 345,
    SHORT = 346,
    LONG = 347,
    FLOAT = 348
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 136 "parser.y" /* yacc.c:355  */

    int token;
    std::string *string;

#line 330 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 345 "parser.cpp" /* yacc.c:358  */

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


#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
# define YYCOPY_NEEDED 1
#endif


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
#define YYFINAL  53
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1212

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  83
/* YYNRULES -- Number of rules.  */
#define YYNRULES  232
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  383

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   348

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
      85,    86,    87,    88,    89,    90,    91,    92,    93
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   210,   210,   216,   219,   222,   227,   238,   244,   276,
     314,   343,   381,   384,   393,   405,   417,   428,   432,   439,
     442,   449,   456,   507,   510,   516,   520,   524,   527,   531,
     534,   541,   544,   550,   553,   557,   561,   568,   571,   575,
     582,   585,   589,   596,   599,   603,   607,   611,   618,   621,
     625,   632,   635,   642,   645,   652,   655,   662,   665,   672,
     675,   682,   685,   692,   695,   764,   768,   772,   776,   780,
     784,   788,   792,   796,   800,   804,   811,   814,   820,   826,
     829,   835,   838,   841,   844,   847,   850,   853,   856,   862,
     865,   871,   881,   912,   915,   918,   921,   924,   930,   934,
     938,   942,   946,   950,   954,   958,   961,   964,   968,   971,
     974,   980,   983,   986,   992,   995,  1001,  1004,  1010,  1016,
    1019,  1022,  1025,  1031,  1034,  1040,  1043,  1046,  1052,  1055,
    1058,  1061,  1064,  1070,  1073,  1079,  1082,  1088,  1091,  1094,
    1100,  1106,  1109,  1118,  1123,  1143,  1187,  1190,  1193,  1196,
    1202,  1205,  1211,  1214,  1220,  1223,  1226,  1232,  1235,  1238,
    1241,  1244,  1247,  1250,  1253,  1259,  1266,  1272,  1275,  1278,
    1281,  1287,  1293,  1296,  1302,  1305,  1311,  1314,  1317,  1320,
    1323,  1326,  1329,  1335,  1343,  1355,  1366,  1369,  1375,  1383,
    1401,  1404,  1410,  1413,  1419,  1422,  1428,  1431,  1437,  1444,
    1451,  1463,  1472,  1490,  1500,  1514,  1518,  1532,  1549,  1558,
    1571,  1586,  1598,  1614,  1622,  1628,  1636,  1648,  1657,  1673,
    1676,  1682,  1685,  1691,  1697,  1698,  1704,  1707,  1713,  1717,
    1723,  1740,  1752
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING_LITERAL", "IDENTIFIER",
  "CONSTANT", "MENOR", "MAIOR", "MENOR_IGUAL", "MAIOR_IGUAL",
  "IGUAL_IGUAL", "EXCLAMACAO_IGUAL", "AMPERSAND_AMPERSAND", "PIPE_PIPE",
  "EXCLAMACAO", "IGUAL", "MAIS_IGUAL", "MENOS_IGUAL", "ASTERISCO_IGUAL",
  "BARRA_IGUAL", "MAIOR_MAIOR_IGUAL", "MENOR_MENOR_IGUAL",
  "PORCENTAGEM_IGUAL", "CIRCUNFLEXO_IGUAL", "AMPERSAND_IGUAL",
  "PIPE_IGUAL", "VOID", "INT", "CHAR", "BOOL", "IF", "ELSE", "FOR",
  "WHILE", "BREAK", "SWITCH", "CASE", "CONTINUE", "INCLUDE", "GOTO",
  "RETURN", "CONST", "DEFAULT", "EXTERN", "STATIC", "MAIS", "MENOS",
  "MAIS_MAIS", "MENOS_MENOS", "ASTERISCO", "BARRA", "PORCENTAGEM",
  "CIRCUNFLEXO", "DOIS_PONTOS", "VIRGULA", "PONTO_VIRGULA", "INTERROGACAO",
  "SUSTENIDO", "ABRE_COLCHETES", "FECHA_COLCHETES", "ABRE_PARENTESES",
  "FECHA_PARENTESES", "ABRE_CHAVES", "FECHA_CHAVES", "MENOR_MENOR",
  "MAIOR_MAIOR", "PIPE", "AMPERSAND", "TIL", "BREAKP", "OUT", "IN",
  "UNSIGNED", "UNION", "TYPE_NAME", "TYPEDEF", "STRUCT", "SIZEOF",
  "SIGNED", "RESTRICT", "REGISTER", "INLINE", "IMAGINARY", "ELLIPSIS",
  "DO", "COMPLEX", "AUTO", "VOLATILE", "ENUM", "PONTO", "DOUBLE", "SHORT",
  "LONG", "FLOAT", "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "function_specifier", "declarator",
  "direct_declarator", "pointer", "type_qualifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "statement", "breakp_statement", "in_statement", "out_statement",
  "labeled_statement", "begin_case", "compound_statement",
  "block_item_list", "block_item", "expression_statement",
  "selection_statement", "begin_switch", "begin_labeled", "begin_else",
  "iteration_statement", "begin_labeled5", "begin_while", "begin_labeled2",
  "begin_for", "begin_labeled3", "begin_labeled4", "jump_statement",
  "translation_unit", "external_declaration", "function_definition",
  "opt_parametros", "parameter_list", "parameter_declaration",
  "begin_funcao", "begin_parametro", "end_parametro", YY_NULLPTR
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
     345,   346,   347,   348
};
# endif

#define YYPACT_NINF -298

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-298)))

#define YYTABLE_NINF -231

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1035,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,
    -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,     8,
    -298,  -298,  -298,  -298,  -298,    18,  1035,  1035,  -298,    19,
    -298,  1035,  1035,   237,  -298,  -298,   -34,    47,   102,    70,
    -298,    73,  -298,    39,  -298,    58,     6,  -298,  -298,    51,
    1065,  -298,  -298,  -298,  -298,    47,   116,    -5,  -298,   112,
    -298,  -298,    70,    42,  -298,   646,   115,  -298,  -298,  1119,
    1065,  1065,  1010,  -298,    41,  1065,     9,   946,    11,  -298,
     162,  -298,  -298,  -298,  -298,   146,  -298,  -298,  -298,  -298,
     982,   982,  -298,   499,   548,  -298,  -298,   164,   175,   998,
    -298,    13,   224,   946,  -298,   130,   166,   144,   163,   206,
     183,   200,   195,   250,    31,  -298,  -298,  -298,  -298,  -298,
      42,   207,   213,  -298,  1091,  -298,  -298,  -298,   946,   172,
    -298,   216,  -298,    14,  -298,  -298,  -298,  -298,  -298,  -298,
     212,   946,   682,   499,  -298,  -298,  -298,    49,    -8,   210,
     946,   268,  -298,    61,   646,    -1,  -298,   946,   946,   499,
    -298,  -298,  -298,   269,  -298,  -298,  -298,  -298,  -298,  -298,
    -298,  -298,  -298,  -298,  -298,   946,  -298,   946,   946,   946,
     946,   946,   946,   946,   946,   946,   946,   946,   946,   946,
     946,   946,   946,   946,   946,   946,  -298,    58,  -298,   214,
    1119,  -298,  -298,    41,  -298,   946,  -298,   277,    88,  -298,
      55,  -298,   222,   946,  -298,   721,    65,   147,  -298,   227,
     757,   215,  -298,   548,  -298,  -298,  -298,  -298,   232,   226,
     228,  -298,  -298,  -298,  -298,  -298,   130,   130,   166,   166,
     144,   144,   144,   144,   163,   163,   206,   183,   200,   195,
     250,   176,  -298,   317,  -298,  -298,  -298,  -298,   229,   234,
     946,  -298,   231,  -298,   235,  -298,   236,  -298,   238,   227,
     796,   548,  -298,  -298,  -298,   646,   946,  -298,   231,   946,
      77,   230,  -298,  -298,   241,   240,   946,   242,   294,   832,
     248,  -298,  -298,   249,   599,   177,  -298,    43,  -298,  -298,
    -298,  -298,   408,  -298,  -298,  -298,  -298,   243,   246,  -298,
    -298,   946,  -298,  -298,  -298,  -298,   255,  -298,   260,    66,
    -298,   247,  -298,   599,   946,  -298,   946,   248,  -298,   252,
    -298,   179,  -298,   599,  -298,   293,  -298,  -298,  -298,   946,
     871,   105,  -298,  -298,  -298,  -298,  -298,    78,    82,   599,
    -298,  -298,  -298,   272,    90,  -298,   871,  -298,  -298,   599,
    -298,   599,  -298,   946,  -298,   599,  -298,   907,   302,  -298,
      91,  -298,  -298,    92,   599,  -298,   599,   279,   599,  -298,
    -298,  -298,  -298
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    98,   101,    99,   107,   137,    94,    95,   106,   115,
     110,    93,   114,   105,   138,    97,   140,    96,   139,     0,
     104,   100,   102,   103,   222,     0,    81,    83,   108,     0,
     109,    85,    87,     0,   219,   221,   132,     0,   143,   146,
      79,     0,    89,    91,   142,     0,     0,    82,    84,   113,
       0,    86,    88,     1,   220,     0,   135,     0,   133,     0,
     150,   148,   147,     0,    80,     0,   143,   141,   231,   224,
       0,   120,     0,   116,     0,   122,     0,     0,     0,   128,
       0,   151,   149,    90,     6,     2,     5,    30,    27,    28,
       0,     0,    26,     0,     0,    25,    29,     0,     0,     0,
      12,    19,    31,     0,    33,    37,    40,    43,    48,    51,
      53,    55,    57,    59,    61,    63,   165,    92,     3,     4,
       0,     0,   225,   226,     0,   119,   112,   117,     0,     0,
     123,   125,   121,     0,   129,    31,    78,   136,   130,   134,
     144,     0,     0,     0,    20,    21,    76,     0,   152,     0,
       0,     0,   167,     0,     0,     0,   172,     0,     0,     0,
      23,    14,    15,     0,    65,    69,    70,    66,    67,    72,
      71,    68,    74,    73,    75,     0,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   229,     0,   232,     0,
       0,   111,   126,     0,   118,     0,   131,     0,     0,     8,
       0,    17,     0,     0,     7,     0,     0,   154,   153,   155,
       0,     0,   175,     0,   166,   168,   171,   173,     0,     0,
       0,    13,    64,    34,    35,    36,    38,    39,    41,    42,
      44,    45,    46,    47,    49,    50,    52,    54,    56,    58,
      60,     0,   228,     0,   223,   227,   124,   127,     0,    10,
       0,     9,     0,    77,    26,   158,     0,   164,     0,   156,
       0,     0,    32,   174,   169,     0,     0,   184,    24,     0,
       2,     0,   211,   209,     0,     0,     0,     0,     0,     0,
       0,   196,   190,     0,     0,     0,   194,     0,   195,   182,
     176,   177,     0,   192,   178,   179,   180,     0,     0,   181,
     145,     0,    18,   162,   159,   157,    26,   160,     0,     0,
     170,     0,    62,     0,     0,   216,     0,     0,   215,     0,
     217,     0,   189,     0,   183,     0,   197,   191,   193,     0,
       0,     0,   163,   161,    16,   185,   186,     0,     0,     0,
     214,   218,   188,     0,     0,   213,     0,    11,   202,     0,
     201,     0,   187,     0,   210,     0,   212,     0,   198,   200,
       0,   204,   208,     0,     0,   203,     0,     0,     0,   206,
     199,   205,   207
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -298,  -298,  -298,  -298,     5,  -298,   -99,    74,    75,    -9,
      71,   145,   148,   149,   143,   154,  -298,   -64,   -57,  -298,
     -88,  -112,  -234,   -25,  -298,   274,  -298,     0,  -298,  -298,
     270,   -48,   -54,  -298,   135,  -298,   287,   -58,     3,  -298,
     -63,   -36,   -14,  -298,  -103,   139,   150,   -55,    97,   151,
    -298,   218,  -211,  -298,  -298,  -298,  -298,    44,   170,  -298,
      68,  -297,  -298,  -298,  -298,  -298,  -298,     2,  -298,  -298,
    -298,  -298,  -298,  -298,  -298,   343,  -298,  -298,  -298,   178,
    -298,  -298,  -298
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   100,   101,   210,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   146,   175,
     295,   137,    24,    25,    41,    42,    26,    71,    28,    29,
      72,    73,    74,   129,   130,    30,    57,    58,    75,    32,
      43,    44,    45,    62,   149,   218,   219,   152,   153,   154,
     155,   156,   298,   299,   118,   119,   300,   333,   301,   302,
     303,   304,   305,   361,   359,   376,   306,   374,   307,   365,
     308,   367,   356,   309,    33,    34,    35,   121,   122,   123,
      46,    69,   199
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    47,    48,    31,   176,   147,    51,    52,   116,    67,
     117,   131,    36,   136,   226,    56,   202,   125,    56,   296,
     139,   132,    38,    49,   127,    61,    27,    27,    55,    31,
      31,    27,    27,    27,    31,    31,    31,   116,   221,   148,
     212,    39,    60,   355,   194,    66,    66,    66,    82,    78,
     215,    56,   216,   208,    65,   147,   230,   150,    79,   366,
     161,   162,    66,   133,   136,    81,    68,    39,   296,   120,
      37,   147,   134,    40,   138,   139,   127,   206,   233,   234,
     235,    50,   135,   335,   196,   211,   136,   195,   151,   148,
      39,    39,    39,   257,   128,   144,   145,   116,    40,   225,
     228,   229,   163,   213,   160,   148,   197,   251,   135,   260,
     214,     5,   346,    70,    39,   223,   261,    80,   232,    39,
     223,   272,   352,   215,   224,   216,   267,    63,    64,   344,
     323,    77,   213,   135,   217,   141,   213,   142,   362,   358,
     131,   136,   213,   360,   213,   213,   213,   259,   368,    14,
     369,   364,   377,   372,   371,   135,   263,    18,   266,   213,
      59,   252,  -230,   379,   357,   380,   116,   382,   274,   184,
     185,   186,   187,    59,   327,   240,   241,   242,   243,   177,
     178,   179,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     120,   331,   217,   312,   141,   215,   142,   216,   182,   183,
     135,   180,   181,   318,   116,   322,   188,   189,   116,   321,
     320,   140,   136,   341,   157,   135,   203,   204,   297,   279,
     213,   213,   336,   213,   351,   158,   347,    53,   348,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     190,   354,   191,    27,   236,   237,    31,   238,   239,   244,
     245,   192,   193,     1,     2,     3,     4,   200,   198,   205,
     207,   220,   222,   231,   273,   370,   253,   297,     5,   373,
       6,     7,   258,   262,   135,   270,   276,   277,   310,   278,
     324,   135,   311,   271,   313,   314,   325,   328,   329,   315,
     326,   332,    27,   339,   334,    31,   340,   350,   345,     8,
       9,    10,    11,    12,   342,    13,    14,    15,    16,   343,
      84,   280,    86,    17,    18,    19,   353,    20,    21,    22,
      23,    87,   363,   375,   381,   246,   249,    83,   256,   247,
     124,   248,    76,     1,     2,     3,     4,   281,   250,   282,
     283,   284,   285,   286,   287,   268,   288,   289,     5,   290,
       6,     7,    88,    89,    90,    91,    92,   269,   319,   254,
     338,   349,   291,   227,   275,   378,    54,    93,   255,   253,
     292,     0,     0,     0,    95,    96,   293,    97,    98,     8,
       9,    10,    11,    12,    99,    13,    14,    15,    16,     0,
       0,   294,     0,    17,    18,    19,     0,    20,    21,    22,
      23,    84,   280,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     4,   281,     0,
     282,   283,   284,   285,   286,   287,     0,   288,   289,     5,
     290,     6,     7,    88,    89,    90,    91,    92,     0,     0,
       0,     0,     0,   291,     0,     0,     0,     0,    93,     0,
     253,   337,     0,     0,     0,    95,    96,   293,    97,    98,
       8,     9,    10,    11,    12,    99,    13,    14,    15,    16,
       0,     0,   294,     0,    17,    18,    19,     0,    20,    21,
      22,    23,    84,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     0,     0,     0,    88,    89,    90,    91,    92,     0,
       0,    84,    85,    86,     0,     0,     0,     0,     0,    93,
       0,     0,    87,     0,     0,     0,    95,    96,     0,    97,
      98,     8,     9,    10,     0,    12,    99,    13,    14,     0,
       0,     0,     0,     0,     0,     0,    18,    19,     0,    20,
      21,    22,    23,    88,    89,    90,    91,    92,     0,     0,
       0,     0,    84,   280,    86,     0,   150,     0,    93,     0,
      94,     0,     0,    87,     0,    95,    96,     0,    97,    98,
       0,     0,     0,     0,     0,    99,     0,     0,     0,   281,
       0,   282,   283,   284,   285,   286,   287,   151,   288,   289,
       0,   290,     0,     0,    88,    89,    90,    91,    92,    84,
      85,    86,     0,     0,   291,     0,     0,     0,     0,    93,
      87,   253,     0,     0,     0,     0,    95,    96,   293,    97,
      98,     0,     0,     0,     0,     0,    99,     0,     0,     0,
       0,     0,     0,   294,     0,    84,    85,    86,     0,     0,
       0,    88,    89,    90,    91,    92,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,     0,    94,     0,
       0,     0,     0,    95,    96,     0,    97,    98,     0,     0,
       0,     0,     0,    99,    84,    85,    86,    88,    89,    90,
      91,    92,     0,     0,     0,    87,     0,     0,     0,     0,
       0,     0,    93,   209,     0,     0,     0,     0,     0,    95,
      96,     0,    97,    98,     0,     0,     0,     0,     0,    99,
      84,    85,    86,     0,     0,     0,    88,    89,    90,    91,
     264,    87,     0,     0,     0,     0,     0,     0,     0,     0,
     265,    93,     0,     0,     0,     0,     0,     0,    95,    96,
       0,    97,    98,     0,     0,     0,     0,     0,    99,    84,
      85,    86,    88,    89,    90,    91,    92,     0,     0,     0,
      87,     0,     0,     0,     0,     0,     0,    93,     0,   271,
       0,     0,     0,     0,    95,    96,     0,    97,    98,     0,
       0,     0,     0,     0,    99,    84,    85,    86,     0,     0,
       0,    88,    89,    90,    91,   316,    87,     0,     0,     0,
       0,     0,     0,     0,     0,   317,    93,     0,     0,     0,
       0,     0,     0,    95,    96,     0,    97,    98,     0,     0,
       0,     0,     0,    99,    84,    85,    86,    88,    89,    90,
      91,    92,     0,     0,     0,    87,     0,   330,     0,     0,
       0,     0,    93,     0,     0,     0,     0,     0,     0,    95,
      96,     0,    97,    98,     0,     0,     0,     0,     0,    99,
      84,    85,    86,     0,     0,     0,    88,    89,    90,    91,
      92,    87,     0,     0,     0,     0,   291,     0,     0,     0,
       0,    93,     0,     0,     0,     0,     0,     0,    95,    96,
       0,    97,    98,     0,     0,     0,     0,     0,    99,    84,
      85,    86,    88,    89,    90,    91,    92,     0,     0,     0,
      87,     0,     0,     0,     0,     0,     0,    93,   372,     0,
       0,     0,     0,     0,    95,    96,     0,    97,    98,     0,
       0,     0,     0,     0,    99,    84,    85,    86,     0,     0,
       0,    88,    89,    90,    91,    92,    87,     0,     0,     0,
       0,    84,    85,    86,     0,     0,    93,     0,     0,     0,
       0,     0,    87,    95,    96,     0,    97,    98,     0,     0,
       0,     0,     0,    99,     0,     0,     0,    88,    89,    90,
      91,    92,     0,     0,     0,     0,     1,     2,     3,     4,
       0,     0,   143,    88,    89,    90,    91,    92,     0,    95,
      96,     5,    97,    98,     0,     0,     0,     0,   159,    99,
       0,     1,     2,     3,     4,    95,    96,     0,    97,    98,
       0,     0,     0,   126,     0,    99,     5,     0,     6,     7,
       0,     0,     8,     9,    10,     0,    12,     0,    13,    14,
       0,     1,     2,     3,     4,     0,     0,    18,    19,     0,
      20,    21,    22,    23,     0,     0,     5,     8,     9,    10,
      11,    12,     0,    13,    14,    15,    16,     1,     2,     3,
       4,    17,    18,    19,     0,    20,    21,    22,    23,     0,
       0,     0,     5,     0,     0,     0,     0,     8,     9,    10,
       0,    12,     0,    13,    14,     1,     2,     3,     4,     0,
       0,     0,    18,    19,   201,    20,    21,    22,    23,     0,
       0,     0,     0,     8,     9,    10,     0,    12,     0,    13,
      14,     0,     0,     0,     0,     0,     0,     0,    18,    19,
       0,    20,    21,    22,    23,     0,     0,     0,     0,     0,
       0,     8,     9,    10,     0,    12,     0,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,     0,    20,
      21,    22,    23
};

static const yytype_int16 yycheck[] =
{
       0,    26,    27,     0,   103,    93,    31,    32,    65,    45,
      65,    74,     4,    77,    15,     4,   128,    71,     4,   253,
      78,    75,     4,     4,    72,    39,    26,    27,    62,    26,
      27,    31,    32,    33,    31,    32,    33,    94,   150,    93,
     143,    49,    39,   340,    13,     4,     4,     4,    62,    54,
      58,     4,    60,   141,    15,   143,   159,    58,    63,   356,
      47,    48,     4,    54,   128,    62,    60,    49,   302,    69,
      62,   159,    63,    55,    63,   133,   124,    63,   177,   178,
     179,    62,    77,   294,   120,   142,   150,    56,    89,   143,
      49,    49,    49,   205,    53,    90,    91,   154,    55,   154,
     157,   158,    89,    54,    99,   159,   120,   195,   103,    54,
      61,    41,   323,    62,    49,    54,    61,     5,   175,    49,
      54,   220,   333,    58,    63,    60,    61,    54,    55,    63,
      53,    15,    54,   128,   148,    58,    54,    60,   349,    61,
     203,   205,    54,    61,    54,    54,    54,    59,   359,    79,
     361,    61,    61,    61,   365,   150,   213,    87,   215,    54,
      58,   197,    60,   374,    59,   376,   223,   378,   223,     6,
       7,     8,     9,    58,   286,   184,   185,   186,   187,    49,
      50,    51,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     200,   289,   216,   260,    58,    58,    60,    60,    64,    65,
     205,    45,    46,   270,   271,   279,    10,    11,   275,   276,
     275,    59,   286,   311,    60,   220,    54,    55,   253,    53,
      54,    54,    55,    54,    55,    60,   324,     0,   326,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      67,   339,    52,   253,   180,   181,   253,   182,   183,   188,
     189,    66,    12,    26,    27,    28,    29,    54,    61,    53,
      58,    61,     4,     4,    59,   363,    62,   302,    41,   367,
      43,    44,     5,    61,   279,    58,    54,    61,    59,    61,
      60,   286,    58,    62,    59,    59,    55,    55,     4,    61,
      60,    53,   302,    60,    55,   302,    60,    55,    61,    72,
      73,    74,    75,    76,    59,    78,    79,    80,    81,    59,
       3,     4,     5,    86,    87,    88,    33,    90,    91,    92,
      93,    14,    60,    31,    55,   190,   193,    63,   203,   191,
      70,   192,    55,    26,    27,    28,    29,    30,   194,    32,
      33,    34,    35,    36,    37,   216,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,   217,   271,   199,
     302,   327,    55,   155,   223,   373,    33,    60,   200,    62,
      63,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      -1,    84,    -1,    86,    87,    88,    -1,    90,    91,    92,
      93,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    -1,
      32,    33,    34,    35,    36,    37,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    60,    -1,
      62,    63,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    -1,    84,    -1,    86,    87,    88,    -1,    90,    91,
      92,    93,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    45,    46,    47,    48,    49,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    14,    -1,    -1,    -1,    67,    68,    -1,    70,
      71,    72,    73,    74,    -1,    76,    77,    78,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    90,
      91,    92,    93,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,    58,    -1,    60,    -1,
      62,    -1,    -1,    14,    -1,    67,    68,    -1,    70,    71,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    30,
      -1,    32,    33,    34,    35,    36,    37,    89,    39,    40,
      -1,    42,    -1,    -1,    45,    46,    47,    48,    49,     3,
       4,     5,    -1,    -1,    55,    -1,    -1,    -1,    -1,    60,
      14,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    -1,     3,     4,     5,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    62,    -1,
      -1,    -1,    -1,    67,    68,    -1,    70,    71,    -1,    -1,
      -1,    -1,    -1,    77,     3,     4,     5,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,
      68,    -1,    70,    71,    -1,    -1,    -1,    -1,    -1,    77,
       3,     4,     5,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      -1,    70,    71,    -1,    -1,    -1,    -1,    -1,    77,     3,
       4,     5,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    62,
      -1,    -1,    -1,    -1,    67,    68,    -1,    70,    71,    -1,
      -1,    -1,    -1,    -1,    77,     3,     4,     5,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    70,    71,    -1,    -1,
      -1,    -1,    -1,    77,     3,     4,     5,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    14,    -1,    55,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    -1,    70,    71,    -1,    -1,    -1,    -1,    -1,    77,
       3,     4,     5,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    14,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      -1,    70,    71,    -1,    -1,    -1,    -1,    -1,    77,     3,
       4,     5,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    -1,    70,    71,    -1,
      -1,    -1,    -1,    -1,    77,     3,     4,     5,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    14,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    14,    67,    68,    -1,    70,    71,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      -1,    -1,    60,    45,    46,    47,    48,    49,    -1,    67,
      68,    41,    70,    71,    -1,    -1,    -1,    -1,    60,    77,
      -1,    26,    27,    28,    29,    67,    68,    -1,    70,    71,
      -1,    -1,    -1,    63,    -1,    77,    41,    -1,    43,    44,
      -1,    -1,    72,    73,    74,    -1,    76,    -1,    78,    79,
      -1,    26,    27,    28,    29,    -1,    -1,    87,    88,    -1,
      90,    91,    92,    93,    -1,    -1,    41,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    81,    26,    27,    28,
      29,    86,    87,    88,    -1,    90,    91,    92,    93,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    -1,    72,    73,    74,
      -1,    76,    -1,    78,    79,    26,    27,    28,    29,    -1,
      -1,    -1,    87,    88,    63,    90,    91,    92,    93,    -1,
      -1,    -1,    -1,    72,    73,    74,    -1,    76,    -1,    78,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    88,
      -1,    90,    91,    92,    93,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    73,    74,    -1,    76,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    90,
      91,    92,    93
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    27,    28,    29,    41,    43,    44,    72,    73,
      74,    75,    76,    78,    79,    80,    81,    86,    87,    88,
      90,    91,    92,    93,   116,   117,   120,   121,   122,   123,
     129,   132,   133,   168,   169,   170,     4,    62,     4,    49,
      55,   118,   119,   134,   135,   136,   174,   117,   117,     4,
      62,   117,   117,     0,   169,    62,     4,   130,   131,    58,
     132,   136,   137,    54,    55,    15,     4,   135,    60,   175,
      62,   121,   124,   125,   126,   132,   130,    15,    54,    63,
       5,   132,   136,   119,     3,     4,     5,    14,    45,    46,
      47,    48,    49,    60,    62,    67,    68,    70,    71,    77,
      95,    96,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   141,   148,   149,
     121,   171,   172,   173,   124,   126,    63,   125,    53,   127,
     128,   134,   126,    54,    63,    98,   111,   115,    63,   131,
      59,    58,    60,    60,    98,    98,   112,   114,   126,   138,
      58,    89,   141,   142,   143,   144,   145,    60,    60,    60,
      98,    47,    48,    89,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   113,   100,    49,    50,    51,
      45,    46,    64,    65,     6,     7,     8,     9,    10,    11,
      67,    52,    66,    12,    13,    56,   135,   136,    61,   176,
      54,    63,   115,    54,    55,    53,    63,    58,   114,    61,
      97,   112,   138,    54,    61,    58,    60,   136,   139,   140,
      61,   115,     4,    54,    63,   141,    15,   145,   112,   112,
     138,     4,   112,   100,   100,   100,   101,   101,   102,   102,
     103,   103,   103,   103,   104,   104,   105,   106,   107,   108,
     109,   114,   135,    62,   152,   173,   128,   115,     5,    59,
      54,    61,    61,   112,    49,    59,   112,    61,   139,   140,
      58,    62,   100,    59,   141,   143,    54,    61,    61,    53,
       4,    30,    32,    33,    34,    35,    36,    37,    39,    40,
      42,    55,    63,    69,    84,   114,   116,   117,   146,   147,
     150,   152,   153,   154,   155,   156,   160,   162,   164,   167,
      59,    58,   112,    59,    59,    61,    49,    59,   112,   142,
     141,   112,   111,    53,    60,    55,    60,   115,    55,     4,
      55,   114,    53,   151,    55,   146,    55,    63,   154,    60,
      60,   114,    59,    59,    63,    61,   146,   114,   114,   151,
      55,    55,   146,    33,   114,   155,   166,    59,    61,   158,
      61,   157,   146,    60,    61,   163,   155,   165,   146,   146,
     114,   146,    61,   114,   161,    31,   159,    61,   161,   146,
     146,    55,   146
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    96,    96,    96,    96,    96,    97,    97,    98,
      98,    98,    98,    98,    98,    99,    99,    99,    99,    99,
      99,   100,   100,   101,   101,   101,   101,   102,   102,   102,
     103,   103,   103,   104,   104,   104,   104,   104,   105,   105,
     105,   106,   106,   107,   107,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   114,   114,   115,   116,
     116,   117,   117,   117,   117,   117,   117,   117,   117,   118,
     118,   119,   119,   120,   120,   120,   120,   120,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   122,   122,   122,   123,   123,   124,   124,   125,   126,
     126,   126,   126,   127,   127,   128,   128,   128,   129,   129,
     129,   129,   129,   130,   130,   131,   131,   132,   132,   132,
     133,   134,   134,   135,   135,   135,   136,   136,   136,   136,
     137,   137,   138,   138,   139,   139,   139,   140,   140,   140,
     140,   140,   140,   140,   140,   141,   141,   142,   142,   142,
     142,   143,   144,   144,   145,   145,   146,   146,   146,   146,
     146,   146,   146,   147,   148,   149,   150,   150,   150,   151,
     152,   152,   153,   153,   154,   154,   155,   155,   156,   156,
     156,   157,   158,   159,   160,   160,   160,   160,   161,   162,
     163,   164,   165,   166,   167,   167,   167,   167,   167,   168,
     168,   169,   169,   170,   171,   171,   172,   172,   173,   173,
     174,   175,   176
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     3,     4,
       4,     7,     1,     3,     2,     2,     6,     1,     3,     1,
       2,     2,     2,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     2,
       3,     1,     2,     1,     2,     1,     2,     1,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     4,     2,     1,     1,     1,     2,     3,     2,
       1,     2,     1,     1,     3,     1,     2,     3,     4,     5,
       5,     6,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     2,     1,     1,     4,     7,     1,     2,     2,     3,
       1,     2,     1,     2,     1,     1,     2,     3,     2,     3,
       3,     4,     3,     4,     2,     1,     3,     1,     2,     3,
       4,     2,     1,     2,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     6,     3,     4,     3,     1,
       2,     3,     1,     2,     1,     1,     1,     2,     5,     7,
       5,     1,     1,     1,     5,     7,     6,     7,     1,     1,
       1,     1,     1,     1,     3,     2,     2,     2,     3,     1,
       2,     1,     1,     6,     0,     1,     1,     3,     3,     2,
       1,     1,     1
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
      YY_LAC_DISCARD ("YYBACKUP");                              \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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

/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return 1 if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yytype_int16 **yybottom,
                      yytype_int16 *yybottom_no_free,
                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
{
  YYSIZE_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYSIZE_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYSIZE_T yyalloc = 2 * yysize_new;
      yytype_int16 *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                         \
do {                                                             \
  if (!yy_lac_established)                                       \
    {                                                            \
      YYDPRINTF ((stderr,                                        \
                  "LAC: initial context established for %s\n",   \
                  yytname[yytoken]));                            \
      yy_lac_established = 1;                                    \
      {                                                          \
        int yy_lac_status =                                      \
          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
        if (yy_lac_status == 2)                                  \
          goto yyexhaustedlab;                                   \
        if (yy_lac_status == 1)                                  \
          goto yyerrlab;                                         \
      }                                                          \
    }                                                            \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      if (yydebug)                                                       \
        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
                   Event "\n");                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return 2 if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  yytype_int16 *yyes_prev = yyssp;
  yytype_int16 *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          yyrule = yydefact[*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      {
        YYSIZE_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
        if (yyesp != yyes_prev)
          {
            YYSIZE_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yylen -= yysize;
                yyesp = yyes_prev;
              }
          }
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      {
        int yystate;
        {
          int yylhs = yyr1[yyrule] - YYNTOKENS;
          yystate = yypgoto[yylhs] + *yyesp;
          if (yystate < 0 || YYLAST < yystate
              || yycheck[yystate] != *yyesp)
            yystate = yydefgoto[yylhs];
          else
            yystate = yytable[yystate];
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            *yyesp = yystate;
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return 2;
              }
            *++yyesp = yystate;
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}


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
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyesa, yytype_int16 **yyes,
                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
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
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          int yyx;

          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
              {
                {
                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
                                              yyssp, yyx);
                  if (yy_lac_status == 2)
                    return 2;
                  if (yy_lac_status == 1)
                    continue;
                }
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
# if YYDEBUG
      else if (yydebug)
        YYFPRINTF (stderr, "No expected tokens.\n");
# endif
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

    yytype_int16 yyesa[20];
    yytype_int16 *yyes;
    YYSIZE_T yyes_capacity;

  int yy_lac_established = 0;
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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  yyes = yyesa;
  yyes_capacity = sizeof yyesa / sizeof *yyes;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
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
  YY_LAC_DISCARD ("shift");

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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


  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
          case 2:
#line 210 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("IDENTIFIER");
        if(referenciando(*(yyvsp[0].string)))
        push(to_str(t->busca(*(yyvsp[0].string), &declarado)->endereco), 1);
        initialization_size = 1;
	}
#line 2148 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 216 "parser.y" /* yacc.c:1646  */
    {
		msg_sintatico("in_statement");
    }
#line 2156 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 219 "parser.y" /* yacc.c:1646  */
    {
        msg_sintatico("out_statement");
    }
#line 2164 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 222 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("CONSTANT");
        push(*(yyvsp[0].string), 2); 
        initialization_size = 1;
	}
#line 2174 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 227 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("STRING_LITERAL");

        string aux = *(yyvsp[0].string), aux2; 
        for(int i=0; i < aux.size(); i++) { 
            aux2 = aux[i]; 
            push(aux2, 3); 
        }
        push("0", 2);   // coloca um \0 no fim da string
        initialization_size = aux.size()+1;
	}
#line 2190 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 238 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_PARENTESES expression FECHA_PARENTESES");
        /*
            NAO PRECISA FAZER NADA
        */
	}
#line 2201 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 244 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("primary_expression: IDENTIFIER ABRE_PARENTESES args_list FECHA_PARENTESES");

        referencia_funcao(*(yyvsp[-2].string));

        if(!preProcessamento && t->getEscopo() > 0 || preProcessamento && t->getEscopo() ==0) {
            msg_instrucao("; call funcao: " + *(yyvsp[-2].string));
            msg_instrucao("; salvando as variaveis do escopo");

            // salva as variaveis do escopo para permitir recursao
            vector<Entrada> lista = t->variaveis_escopo();
            for(int i = 0; i < lista.size(); i++) {
                cout << "load r0, " << lista[i].endereco << endl
                     << "push r0" << endl;
            }

            msg_instrucao("; nao tem parametros");

            cout << "call " << "__function_label_" << *(yyvsp[-2].string) << "__" << endl;

            msg_instrucao("; recupera as variaveis do escopo da funcao");

            // recupera as variaveis do escopo para permitir recursao
            for(int i = lista.size()-1; i >= 0 ; i--) {
                cout << "pop r0" << endl
                     << "store " << lista[i].endereco << ", r0" << endl;
            }
            cout << endl;
        }
        arg_list.clear();
        initialization_size = 1;
	}
#line 2238 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 276 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("postfix_expression ABRE_PARENTESES argument_expression_list FECHA_PARENTESES");

        referencia_funcao(*(yyvsp[-3].string));

        if(!preProcessamento && t->getEscopo() > 0 || preProcessamento && t->getEscopo() ==0) {
            msg_instrucao("; call funcao: " + *(yyvsp[-3].string));
            msg_instrucao("; salvando as variaveis do escopo");

            // salva as variaveis do escopo para permitir recursao
            vector<Entrada> lista = t->variaveis_escopo();
            for(int i = 0; i < lista.size(); i++) {
                cout << "load r0, " << lista[i].endereco << endl
                     << "push r0" << endl;
            }

            msg_instrucao("; salvando os argumentos da funcao: " + f->parametros.size());

            // salva os argumentos da funcao
            for(int i = 0; i < arg_list.size(); i++) {
                cout << "load r0, " << arg_list[i] << endl
                     << "push r0" << endl;
            }

            cout << "call " << "__function_label_" << *(yyvsp[-3].string) << "__" << endl;

            msg_instrucao("; recupera as variaveis do escopo da funcao");

            // recupera as variaveis do escopo para permitir recursao
            for(int i = lista.size()-1; i >= 0 ; i--) {
                cout << "pop r0" << endl
                     << "store " << lista[i].endereco << ", r0" << endl;
            }
            cout << endl;
        }
        arg_list.clear();
        initialization_size = 1;
	}
#line 2281 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 314 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("postfix_expression ABRE_COLCHETES expression FECHA_COLCHETES");
/*
        if(!preProcessamento) {
        cout<< "load r0, " << stack+2 << endl
            << "loadn r1, #" << stack+1 << endl
            << "add r7, r0, r1" << endl
            << "store " << stack+2 << ", r7" << endl;
        stack++;
        }
*/
        referenciando(*(yyvsp[-3].string));
        if(!preProcessamento && t->getEscopo() > 0 || preProcessamento && t->getEscopo() == 0) {
            if(debug_instrucao) 
                cout << "; " << t->buscaEndereco(stack) << "(" << stack << ") recebe o conteudo da variavel: " << *(yyvsp[-3].string) << endl; 

            endereco_base = t->busca(*(yyvsp[-3].string), &declarado)->endereco;

            cout<< "load r0, " << stack + 1 << endl
                << "load r1, " << endereco_base << endl
                << "sub r7, r1, r0" << endl
                << "loadi r1, r7" << endl
                << "store " << stack+1 << ", r1" << endl;
            stack_ampersand = -2;

            mapa[stack+1] = -2;
        }
        initialization_size = 1;
	}
#line 2315 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 343 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("postfix_expression ABRE_COLCHETES expression FECHA_COLCHETES");
/*
        if(!preProcessamento) {
        cout<< "load r0, " << stack+2 << endl
            << "loadn r1, #" << stack+1 << endl
            << "add r7, r0, r1" << endl
            << "store " << stack+2 << ", r7" << endl;
        stack++;
        }
*/
        referenciando(*(yyvsp[-6].string));  
        if(!preProcessamento && t->getEscopo() > 0 || preProcessamento && t->getEscopo() == 0) {
            if(debug_instrucao) 
                cout << "; " << t->buscaEndereco(stack) << "(" << stack << ") recebe o conteudo da variavel: " << *(yyvsp[-6].string) << endl; 

            endereco_base = t->busca(*(yyvsp[-6].string), &declarado)->endereco;

            cout<< "load r0, " << stack + 1 << endl
                << "load r1, " << stack + 2 << endl
                << "load r2, " << endereco_base << endl
                << "sub r2, r2, r1" << endl
                << "loadi r1, r2" << endl
                << "sub r7, r1, r0" << endl
                << "loadi r1, r7" << endl
                << "store " << stack+2 << ", r1" << endl;

            cout << "; matriz, valor da stack " << stack+2 << endl;
            mapa[stack+2] = -2;

            stack++;
            stack_ampersand = -2;
        }
        initialization_size = 1;
	}
#line 2355 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 381 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("primary_expression");
	}
#line 2363 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 384 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("postfix_expression PONTO IDENTIFIER");
	}
#line 2371 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 393 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("postfix_expression MAIS_MAIS");
        if(!preProcessamento) {
        cout<< "load r0, " << stack+1 << endl
            << "inc r0" << endl
            << "store " << stack+1 << ", r0" << endl;
        if(mapa[stack+1] == -2)
            cout << "storei r7, r0"<< endl;
        else
            cout << "store " << mapa[stack+1] << ", r0" << endl;
        }
	}
#line 2388 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 405 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("postfix_expression MENOS_MENOS");
        if(!preProcessamento) {
        cout<< "load r0, " << stack+1 << endl
            << "dec r0" << endl
            << "store " << stack+1 << ", r0" << endl;
        if(mapa[stack+1] == -2)
            cout << "storei r7, r0"<< endl;
        else
            cout << "store " << mapa[stack+1] << ", r0" << endl;
        }
	}
#line 2405 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 417 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_PARENTESES type_name FECHA_PARENTESES ABRE_CHAVES initializer_list FECHA_CHAVES");
	}
#line 2413 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 428 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("assignment_expression");
        arg_list.push_back(stack+1);
	}
#line 2422 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 432 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("argument_expression_list VIRGULA assignment_expression");
        arg_list.push_back(stack+1);
	}
#line 2431 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 439 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("postfix_expression");
	}
#line 2439 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 442 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("MAIS_MAIS unary_expression");
        if(!preProcessamento)
        cout<< "load r0, " << stack+1 << endl
            << "inc r0" << endl
            << "store " << stack+1 << endl;
	}
#line 2451 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 449 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("MENOS_MENOS unary_expression");
        if(!preProcessamento)
        cout<< "load r0, " << stack+1 << endl
            << "dec r0" << endl
            << "store " << stack+1 << endl;
	}
#line 2463 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 456 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("unary_operator cast_expression");

        if(!preProcessamento && t->getEscopo() > 0 || preProcessamento && t->getEscopo() ==0)
        switch(operacao) {
            case ampersand:
                if(stack_ampersand == -1)
                    errorMsg("ampersand deve ser usado com variaveis");

                if(!preProcessamento) {
                    msg_instrucao("; endereco");

                    if(stack_ampersand == -2) {   // caso especial de matriz
                        stack++;
                        cout << "store " << stack << ", r7" << endl << endl; 
                        stack--;  
                    }
                    else {
                        stack++;
                        ostringstream convert;
                        convert << stack_ampersand;
                        push(convert.str(), 2);
                    }
                }
                stack_ampersand = -1;
                break;

            case asterisco:
                cout<< "load r0, " << stack+1 << endl
                    << "loadi r1, r0" << endl
                    << "store " << stack+1 << ", r1" << endl;
                break;

            case menos:
                cout<< "load r0, " << stack+1 << endl
                    << "loadn r1, #0" << endl
                    << "sub r1, r1, r0" << endl
                    << "store " << stack+1 << ", r1" << endl;
                break;

            case exclamacao:
                cout<< "load r0, " << stack+1 << endl
                    << "not r0, r0" << endl
                    << "store " << stack+1 << ", r0" << endl;
                break;

            default:
                break;
        }
        operacao = nenhuma;
	}
#line 2519 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 507 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("SIZEOF unary_expression");
	}
#line 2527 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 510 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("SIZEOF ABRE_PARENTESES type_name FECHA_PARENTESES");
	}
#line 2535 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 516 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("AMPERSAND");
        operacao = ampersand;
	}
#line 2544 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 520 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ASTERISCO2");
        operacao = asterisco;
	}
#line 2553 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 524 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("MAIS");
	}
#line 2561 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 527 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("MENOS");
        operacao = menos;
	}
#line 2570 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 531 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("TIL");
	}
#line 2578 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 534 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("EXCLAMACAO");
        operacao = exclamacao;
	}
#line 2587 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 541 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("unary_expression");
	}
#line 2595 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 544 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_PARENTESES type_name FECHA_PARENTESES cast_expression");
	}
#line 2603 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 550 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("cast_expression");
	}
#line 2611 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 553 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("multiplicative_expression ASTERISCO cast_expression");
        expressao_binaria('*'); 
	}
#line 2620 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 557 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("multiplicative_expression BARRA cast_expression");
        expressao_binaria('/'); 
	}
#line 2629 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 561 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("multiplicative_expression '' cast_expression");
        expressao_binaria('%'); 
	}
#line 2638 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 568 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("multiplicative_expression");
	}
#line 2646 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 571 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("additive_expression MAIS multiplicative_expression");
        expressao_binaria('+'); 
	}
#line 2655 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 575 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("additive_expression MENOS multiplicative_expression");
        expressao_binaria('-'); 
	}
#line 2664 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 582 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("additive_expression");
	}
#line 2672 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 585 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("shift_expression MENOR_MENOR additive_expression");
        expressao_binaria('l'); 
	}
#line 2681 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 589 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("shift_expression MAIOR_MAIOR additive_expression");
        expressao_binaria('r'); 
	}
#line 2690 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 596 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("shift_expression");
	}
#line 2698 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 599 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("relational_expression MENOR shift_expression");
        relacao_binaria('<');
	}
#line 2707 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 603 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("relational_expression MAIOR shift_expression");
        relacao_binaria('>');
	}
#line 2716 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 607 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("relational_expression MENOR_IGUAL shift_expression");
        relacao_binaria('m');
	}
#line 2725 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 611 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("relational_expression MAIOR_IGUAL shift_expression");
        relacao_binaria('M');
	}
#line 2734 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 618 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("relational_expression");
	}
#line 2742 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 621 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("equality_expression IGUAL_IGUAL relational_expression");
        relacao_binaria('=');
	}
#line 2751 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 625 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("equality_expression EXCLAMACAO_IGUAL relational_expression");
        relacao_binaria('!');
	}
#line 2760 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 632 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("equality_expression");
	}
#line 2768 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 635 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("and_expression AMPERSAND equality_expression");
        expressao_binaria('&'); 
	}
#line 2777 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 642 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("and_expression");
	}
#line 2785 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 645 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("exclusive_or_expression CIRCUNFLEXO and_expression");
        expressao_binaria('^'); 
	}
#line 2794 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 652 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("exclusive_or_expression");
	}
#line 2802 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 655 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("inclusive_or_expression PIPE exclusive_or_expression");
        expressao_binaria('|'); 
	}
#line 2811 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 662 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("inclusive_or_expression");
	}
#line 2819 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 665 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("logical_and_expression AMPERSAND_AMPERSAND inclusive_or_expression");
        relacao_binaria('e');
	}
#line 2828 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 672 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("logical_and_expression");
	}
#line 2836 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 675 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("logical_or_expression PIPE_PIPE logical_and_expression");
        relacao_binaria('o');
	}
#line 2845 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 682 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("logical_or_expression");
	}
#line 2853 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 685 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("logical_or_expression INTERROGACAO expression DOIS_PONTOS conditional_expression");
        relacao_binaria('?');
	}
#line 2862 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 692 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("conditional_expression");
	}
#line 2870 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 695 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("unary_expression assignment_operator assignment_expression");

        if(!preProcessamento && t->getEscopo() > 0 || preProcessamento && t->getEscopo() ==0) {
            if(debug_instrucao)
                cout<< "; assignment salvando no endereco apontado por: " << t->buscaEndereco(stack+2) << "(" << stack+2 << ") o conteudo de " 
                    << t->buscaEndereco(stack+1) << "(" << stack+1 << ")" << endl;

            cout<< "load r0, " << stack+1 << endl; // resultado
            switch(atribuicao) {
                case eq:
                    break;

                case mul_eq: 
                    cout<< "load r1, " << stack+2 << endl;
                    cout << "mul r0, r1, r0" << endl;
                    break;

                case div_eq:
                    cout<< "load r1, " << stack+2 << endl;
                    cout << "div r0, r1, r0" << endl;
                    break;

                case mod_eq:
                    cout<< "load r1, " << stack+2 << endl;
                    cout << "mod r0, r1, r0" << endl;
                    break;

                case add_eq:
                    cout<< "load r1, " << stack+2 << endl;
                    cout << "add r0, r1, r0" << endl;
                    break;

                case sub_eq:
                    cout<< "load r1, " << stack+2 << endl;
                    cout << "sub r0, r1, r0" << endl;
                    break;

                case dec_eq:
                    cout<< "dec r0" << endl;
                    break;

                case inc_eq:
                    cout<< "inc r0" << endl;
                    break;

                case land_eq:
                case lor_eq:
                case lxor_eq:
                default:
                    break;
            }
            cout << "; valor da stack: " << stack << endl;
            if(mapa[stack+2] > 0) {
                cout<< "store " << mapa[stack+2] << ", r0 ; variavel " << t->buscaEndereco(mapa[stack+2]) << " recebe o conteudo de r0" << endl << endl; 
                mapa[stack+2] = -1;
            }
            else if(mapa[stack+2] == -2) {
                cout<< "storei r7, r0 ; endereco apontado por r7 recebe o conteudo de r0" << endl << endl; 
                mapa[stack+2] = -1;
            }
            else 
                errorMsg("acesso errado a matriz");
            stack = stack+2;
        }
	}
#line 2941 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 764 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("IGUAL");
        atribuicao = eq;
	}
#line 2950 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 768 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ASTERISCO_IGUAL");
        atribuicao = mul_eq;
	}
#line 2959 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 772 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("BARRA_IGUAL");
        atribuicao = div_eq;
	}
#line 2968 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 776 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("PORCENTAGEM_IGUAL");
        atribuicao = mod_eq;
	}
#line 2977 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 780 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("MAIS_IGUAL");
        atribuicao = add_eq;
	}
#line 2986 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 784 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("MENOS_IGUAL");
        atribuicao = sub_eq;
	}
#line 2995 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 788 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("MENOR_MENOR_IGUAL");
        atribuicao = dec_eq;
	}
#line 3004 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 792 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("MAIOR_MAIOR_IGUAL");
        atribuicao = inc_eq;
	}
#line 3013 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 796 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("AMPERSAND_IGUAL");
        atribuicao = land_eq;
	}
#line 3022 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 800 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("CIRCUNFLEXO_IGUAL");
        atribuicao = lxor_eq;
	}
#line 3031 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 804 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("PIPE_IGUAL");
        atribuicao = lor_eq;
	}
#line 3040 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 811 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("assignment_expression");
	}
#line 3048 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 814 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("expression VIRGULA assignment_expression");
	}
#line 3056 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 820 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("conditional_expression");
	}
#line 3064 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 826 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("declaration_specifiers PONTO_VIRGULA");
	}
#line 3072 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 829 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("declaration_specifiers init_declarator_list PONTO_VIRGULA");
	}
#line 3080 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 835 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("storage_class_specifier");
	}
#line 3088 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 838 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("storage_class_specifier declaration_specifiers");
	}
#line 3096 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 841 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("type_specifier");
	}
#line 3104 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 844 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("type_specifier declaration_specifiers");
	}
#line 3112 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 847 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("type_qualifier");
	}
#line 3120 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 850 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("type_qualifier declaration_specifiers");
	}
#line 3128 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 853 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("function_specifier");
	}
#line 3136 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 856 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("function_specifier declaration_specifiers");
	}
#line 3144 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 862 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("init_declarator");
	}
#line 3152 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 865 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("init_declarator_list VIRGULA init_declarator");
	}
#line 3160 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 871 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("declarator");
        if(correcao_stack_matriz != -1 && stack != correcao_stack_matriz) {
            msg_instrucao("acerta o ponteiro da matriz/vetor");
            //cout << "stack: " << stack << endl;
            //cout << "correcao: " << correcao_stack_matriz << endl;
            stack = correcao_stack_matriz;
            correcao_stack_matriz = -1;
        }
	}
#line 3175 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 881 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("declarator IGUAL initializer");

        if(!preProcessamento && t->getEscopo() > 0 || preProcessamento && t->getEscopo() ==0) {
            assert(initializer_list.size() >= 0);
            if(initializer_list.size() == 1) { // para variaveis simples e strings
                if(initialization_size > 1)
                    cout<< "loadn r0, #" << initializer_list[0] << endl;
                else if(initialization_size == 1)
                    cout<< "load r0, " << initializer_list[0] << endl;

                cout<< "store " << initializer_list[0]+1 << ", r0" << endl; 
                stack++;
            }
            
            else if(initializer_list.size() > 1) { // para vetores e matrizes
                msg_instrucao("acerta o ponteiro da matriz/vetor");
                cout << "; correcao da stack" << endl;
                if(stack != correcao_stack_matriz)
                    stack = correcao_stack_matriz;
                correcao_stack_matriz = -1;
                cout << "; stack = "<< stack << endl;
                //cout<< "loadn r0, #" << initializer_list[0] << endl
                //    << "store " << initializer_list[0]+1 << ", r0" << endl; 
            }
        }
        initializer_list.clear();
	}
#line 3208 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 912 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("TYPEDEF");
	}
#line 3216 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 915 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("EXTERN");
	}
#line 3224 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 918 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("STATIC");
	}
#line 3232 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 921 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("AUTO");
	}
#line 3240 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 924 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("REGISTER");
	}
#line 3248 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 930 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("VOID");
        salva_tipo("void");
	}
#line 3257 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 934 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("CHAR");
        salva_tipo("char");
	}
#line 3266 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 938 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("SHORT");
        salva_tipo("short");
	}
#line 3275 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 942 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("INT");
        salva_tipo("int");
	}
#line 3284 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 946 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("LONG");
        salva_tipo("long");
	}
#line 3293 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 950 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("FLOAT");
        salva_tipo("long");
	}
#line 3302 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 954 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("DOUBLE");
        salva_tipo("double");
	}
#line 3311 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 958 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("SIGNED");
	}
#line 3319 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 961 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("UNSIGNED");
	}
#line 3327 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 964 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("BOOL");
        salva_tipo("bool");
	}
#line 3336 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 968 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("struct_or_union_specifier");
	}
#line 3344 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 971 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("enum_specifier");
	}
#line 3352 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 974 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("TYPE_NAME");
	}
#line 3360 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 980 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("struct_or_union IDENTIFIER ABRE_CHAVES struct_declaration_list FECHA_CHAVES");
	}
#line 3368 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 983 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("struct_or_union ABRE_CHAVES struct_declaration_list FECHA_CHAVES");
	}
#line 3376 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 986 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("struct_or_union IDENTIFIER");
	}
#line 3384 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 992 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("STRUCT");
	}
#line 3392 "parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 995 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("UNION");
	}
#line 3400 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1001 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("struct_declaration");
	}
#line 3408 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1004 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("struct_declaration_list struct_declaration");
	}
#line 3416 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1010 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("specifier_qualifier_list struct_declarator_list PONTO_VIRGULA");
	}
#line 3424 "parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1016 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("type_specifier specifier_qualifier_list");
	}
#line 3432 "parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1019 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("type_specifier");
	}
#line 3440 "parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1022 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("type_qualifier specifier_qualifier_list");
	}
#line 3448 "parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1025 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("type_qualifier");
	}
#line 3456 "parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1031 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("struct_declarator");
	}
#line 3464 "parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1034 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("struct_declarator_list VIRGULA struct_declarator");
	}
#line 3472 "parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1040 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("declarator");
	}
#line 3480 "parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1043 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("DOIS_PONTOS constant_expression");
	}
#line 3488 "parser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1046 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("declarator DOIS_PONTOS constant_expression");
	}
#line 3496 "parser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1052 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ENUM ABRE_CHAVES enumerator_list FECHA_CHAVES");
	}
#line 3504 "parser.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1055 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ENUM IDENTIFIER ABRE_CHAVES enumerator_list FECHA_CHAVES");
	}
#line 3512 "parser.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1058 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ENUM ABRE_CHAVES enumerator_list VIRGULA FECHA_CHAVES");
	}
#line 3520 "parser.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1061 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ENUM IDENTIFIER ABRE_CHAVES enumerator_list VIRGULA FECHA_CHAVES");
	}
#line 3528 "parser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1064 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ENUM IDENTIFIER");
	}
#line 3536 "parser.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1070 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("enumerator");
	}
#line 3544 "parser.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1073 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("enumerator_list VIRGULA enumerator");
	}
#line 3552 "parser.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1079 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("IDENTIFIER");
	}
#line 3560 "parser.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1082 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("IDENTIFIER IGUAL constant_expression");
	}
#line 3568 "parser.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1088 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("CONST");
	}
#line 3576 "parser.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1091 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("RESTRICT");
	}
#line 3584 "parser.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1094 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("VOLATILE");
	}
#line 3592 "parser.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1100 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("INLINE");
	}
#line 3600 "parser.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1106 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("pointer direct_declarator");
	}
#line 3608 "parser.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1109 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("direct_declarator");
	}
#line 3616 "parser.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1118 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("IDENTIFIER");
        declara_variaveis_e_parametros(*(yyvsp[0].string), 1);
        salva_identificador = *(yyvsp[0].string); 
	}
#line 3626 "parser.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1123 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("direct_declarator ABRE_COLCHETES CONSTANT FECHA_COLCHETES");

        declara_variaveis_e_parametros(*(yyvsp[-3].string), atoi((yyvsp[-1].string)->c_str())+1); 
        salva_identificador = *(yyvsp[-3].string);

        if(!preProcessamento && t->getEscopo() > 0 || preProcessamento && t->getEscopo() == 0) {
            if(flag_ponteiro > 0)
                errorMsg("vetor de ponteiros nao e' suportado");

                msg_instrucao("acerta o ponteiro da matriz/vetor");
                cout<< "loadn r0, #" << stack << endl
                    << "store " << stack+1 << ", r0" << endl; 

            if(!begin_parametro) {
                salva_stack = stack; 
                correcao_stack_matriz = stack - atoi((yyvsp[-1].string)->c_str());
            }
        }
	}
#line 3651 "parser.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1143 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("direct_declarator ABRE_COLCHETES CONSTANT FECHA_COLCHETES");

        declara_variaveis_e_parametros(*(yyvsp[-6].string), atoi((yyvsp[-4].string)->c_str()) * atoi((yyvsp[-1].string)->c_str()) + 1 + atoi((yyvsp[-4].string)->c_str())); 
        salva_identificador = *(yyvsp[-6].string);

        if(!preProcessamento && t->getEscopo() > 0 || preProcessamento && t->getEscopo() == 0) {
            if(flag_ponteiro > 0)
                errorMsg("matriz de ponteiros nao e' suportado");

            if(!begin_parametro) {
                salva_stack = stack; 

                msg_instrucao("acerta o ponteiro da matriz/vetor");
                cout<< "loadn r0, #" << stack << endl
                    << "store " << stack+1 << ", r0" << endl; 

                int nlinhas = atoi((yyvsp[-4].string)->c_str());
                int ncolunas = atoi((yyvsp[-1].string)->c_str());
                int offset = stack - nlinhas;
                cout << "loadn r0, #" << stack << endl;
                for(int i = 0; i < nlinhas; i++) {
                    cout << "loadn r1, #" << offset << endl
                         << "storei r0, r1" << endl
                         << "dec r0" << endl;
                    offset = offset - ncolunas;
                }
                cout << endl;
                stack = stack - nlinhas;  // aloquei os espacos para o vetor de ponteiros da matriz
                correcao_stack_matriz = offset; 
            }
        }
	}
#line 3689 "parser.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1187 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ASTERISCO");
	}
#line 3697 "parser.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1190 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ASTERISCO type_qualifier_list");
	}
#line 3705 "parser.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1193 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ASTERISCO pointer");
	}
#line 3713 "parser.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1196 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ASTERISCO type_qualifier_list pointer");
	}
#line 3721 "parser.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1202 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("type_qualifier");
	}
#line 3729 "parser.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1205 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("type_qualifier_list type_qualifier");
	}
#line 3737 "parser.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1211 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("specifier_qualifier_list");
	}
#line 3745 "parser.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1214 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("specifier_qualifier_list abstract_declarator");
	}
#line 3753 "parser.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1220 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("pointer");
	}
#line 3761 "parser.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1223 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("direct_abstract_declarator");
	}
#line 3769 "parser.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1226 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("pointer direct_abstract_declarator");
	}
#line 3777 "parser.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1232 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_PARENTESES abstract_declarator FECHA_PARENTESES");
	}
#line 3785 "parser.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1235 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_COLCHETES FECHA_COLCHETES");
	}
#line 3793 "parser.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1238 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_COLCHETES assignment_expression FECHA_COLCHETES");
	}
#line 3801 "parser.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1241 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("direct_abstract_declarator ABRE_COLCHETES FECHA_COLCHETES");
	}
#line 3809 "parser.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1244 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("direct_abstract_declarator ABRE_COLCHETES assignment_expression FECHA_COLCHETES");
	}
#line 3817 "parser.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1247 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_COLCHETES ASTERISCO FECHA_COLCHETES");
	}
#line 3825 "parser.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1250 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("direct_abstract_declarator ABRE_COLCHETES ASTERISCO FECHA_COLCHETES");
	}
#line 3833 "parser.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1253 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_PARENTESES FECHA_PARENTESES");
	}
#line 3841 "parser.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1259 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("assignment_expression");
        if(initialization_size == 1)
            initializer_list.push_back(stack+1);
        else if(initialization_size > 1)
            initializer_list.push_back(stack+initialization_size);
	}
#line 3853 "parser.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1266 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_CHAVES initializer_list FECHA_CHAVES");
	}
#line 3861 "parser.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1272 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("initializer");
	}
#line 3869 "parser.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1275 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("designation initializer");
	}
#line 3877 "parser.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1278 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("initializer_list VIRGULA initializer");
	}
#line 3885 "parser.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1281 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("initializer_list VIRGULA designation initializer");
	}
#line 3893 "parser.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1287 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("designator_list IGUAL");
	}
#line 3901 "parser.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1293 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("designator");
	}
#line 3909 "parser.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1296 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("designator_list designator");
	}
#line 3917 "parser.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1302 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_COLCHETES constant_expression FECHA_COLCHETES");
	}
#line 3925 "parser.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1305 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("PONTO IDENTIFIER");
	}
#line 3933 "parser.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1311 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("labeled_statement");
	}
#line 3941 "parser.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1314 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("compound_statement");
	}
#line 3949 "parser.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1317 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("expression_statement");
	}
#line 3957 "parser.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1320 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("selection_statement");
	}
#line 3965 "parser.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1323 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("iteration_statement");
	}
#line 3973 "parser.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1326 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("jump_statement");
	}
#line 3981 "parser.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1329 "parser.y" /* yacc.c:1646  */
    {
		msg_sintatico("breakp_statement");
    }
#line 3989 "parser.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1335 "parser.y" /* yacc.c:1646  */
    {
        msg_sintatico("breakp_statement breakp");
        if(!preProcessamento)
        cout << "breakp" << endl; 
    }
#line 3999 "parser.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1343 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("breakp in abre_parenteses primary_expression virgula primary_expression fecha_parenteses");
        if(!preProcessamento) {
            cout << "load r1, " << stack+1 << endl;
            cout << "in r0, r1" << endl; 
            cout << "store " << stack << ", r0" << endl;
            stack--;
        }
    }
#line 4013 "parser.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1355 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("breakp in abre_parenteses primary_expression virgula primary_expression fecha_parenteses");
        if(!preProcessamento) {
            cout << "load r0, " << stack+2 << endl;
            cout << "load r1, " << stack+1 << endl;
            cout << "out r0, r1" << endl; 
        }
    }
#line 4026 "parser.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1366 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("IDENTIFIER DOIS_PONTOS statement");
	}
#line 4034 "parser.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1369 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("CASE constant_expression DOIS_PONTOS statement");
        cout << "; labeled_statement case, zerou" << endl;
        insideCase = 0;
        cout<< "jmp __label_statement_" << statement_seq+1 << "__" << endl;
	}
#line 4045 "parser.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1375 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("DEFAULT DOIS_PONTOS statement");
        cout << "; labeled_statement default, zerou" << endl;
        insideCase = 0;
	}
#line 4055 "parser.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1383 "parser.y" /* yacc.c:1646  */
    {   
		msg_sintatico("DOIS_PONTOS");
        cout << "; dois pontos, incrementou" << endl;
        insideCase = 1;
        if(!preProcessamento) {
            cout<< "__label_case_" << case_seq << "__:" << endl;
            cout<< "load r1, " << stack+1 << endl
                << "cmp r0, r1" << endl
                << "jeq __label_statement_" << statement_seq << "__" << endl;
            cout<< "jmp __label_case_" << case_seq << "__" << endl
                << "__label_statement_" << statement_seq << "__:" << endl;
            case_seq++;
            statement_seq++;
        }
    }
#line 4075 "parser.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1401 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_CHAVES FECHA_CHAVES");
	}
#line 4083 "parser.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1404 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_CHAVES block_item_list FECHA_CHAVES");
	}
#line 4091 "parser.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 1410 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("block_item");
	}
#line 4099 "parser.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 1413 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("block_item_list block_item");
	}
#line 4107 "parser.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1419 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("declaration");
	}
#line 4115 "parser.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 1422 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("statement");
	}
#line 4123 "parser.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 1428 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("PONTO_VIRGULA");
	}
#line 4131 "parser.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 1431 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("expression PONTO_VIRGULA");
	}
#line 4139 "parser.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 1437 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("IF ABRE_PARENTESES expression FECHA_PARENTESES statement");
        if(!preProcessamento) {
            cout << "__exit_if_label" << if_stack.back() << "__:" << endl; 
            if_stack.pop_back();
        }
	}
#line 4151 "parser.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1444 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("IF ABRE_PARENTESES expression FECHA_PARENTESES statement ELSE statement");
        if(!preProcessamento) {
            cout << "__exit_else_label" << if_stack.back() << "__:" << endl; 
            if_stack.pop_back();
        }
	}
#line 4163 "parser.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1451 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("SWITCH ABRE_PARENTESES expression FECHA_PARENTESES statement");
        insideSwitch--;
        if(switch_stack.back() == 1)
            switch_stack.pop_back();
        else
            errorMsg("switch stack esta errada");
        switch_seq++;
	}
#line 4177 "parser.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1463 "parser.y" /* yacc.c:1646  */
    {
        if(!preProcessamento)
            cout<< "load r0, " << stack+1 << endl;
        insideSwitch++;
        switch_stack.push_back(1);
    }
#line 4188 "parser.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1472 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("begin_labeled fecha_parenteses");
            if(!preProcessamento) {
                ifseq++;
                if_stack.push_back(ifseq);

                cout << "load r0, " << stack+1 << endl;
                stack++;
                cout << "loadn r1, #0" << endl;
                cout << "cmp r0, r1" << endl;
                cout << "jeq __exit_if_label" << if_stack.back() << "__" << endl; // else
                cout << "jmp __if_label" << if_stack.back() << "__" << endl;
                cout << "__if_label" << if_stack.back() << "__:" << endl; 
            }
    }
#line 4208 "parser.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1490 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("begin_else else");
        if(!preProcessamento) {
            cout << "jmp __exit_else_label" << if_stack.back() << "__" << endl; 
            cout << "__exit_if_label" << if_stack.back() << "__:" << endl;
        }
    }
#line 4220 "parser.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1500 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("WHILE ABRE_PARENTESES expression FECHA_PARENTESES statement");
        insideLoop--;
        if(!preProcessamento) {
            cout << "jmp __loop_label_begin"<< loop_stack.back() << "__" << endl;
            cout << "__exit_loop_label" << loop_stack.back() << "__:" << endl;
            cout << "; ----- end while -----" << endl;
        }
        if(switch_stack.back() == 2)
            switch_stack.pop_back();
        else
            errorMsg("switch stack esta errada");
        loop_stack.pop_back();
	}
#line 4239 "parser.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1514 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("DO statement WHILE ABRE_PARENTESES expression FECHA_PARENTESES PONTO_VIRGULA");
        errorMsg("do while nao e' suportado nesta versao");
	}
#line 4248 "parser.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1518 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("FOR ABRE_PARENTESES expression_statement expression_statement FECHA_PARENTESES statement");
        insideLoop--;
        if(!preProcessamento) {
            cout << "jmp __loop_label2_begin"<< loop_stack.back() << "__" << endl;
            cout << "__exit_loop_label" << loop_stack.back() << "__:" << endl;
            cout << "; ----- end for -----" << endl;
        }
        if(switch_stack.back() == 2)
            switch_stack.pop_back();
        else
            errorMsg("switch stack esta errada");
        loop_stack.pop_back();
	}
#line 4267 "parser.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1532 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("FOR ABRE_PARENTESES expression_statement expression_statement expression FECHA_PARENTESES statement");
        insideLoop--;
        if(!preProcessamento) {
            cout << "jmp __loop_label2_begin"<< loop_stack.back() << "__" << endl;
            cout << "__exit_loop_label" << loop_stack.back() << "__:" << endl;
            cout << "; ----- end for -----" << endl;
        }
        if(switch_stack.back() == 2)
            switch_stack.pop_back();
        else
            errorMsg("switch stack esta errada");
        loop_stack.pop_back();
	}
#line 4286 "parser.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1549 "parser.y" /* yacc.c:1646  */
    { 
        if(!preProcessamento) {
        cout << "jmp __loop_label_begin"<< loop_stack.back() << "__" << endl;
        cout << "__loop_label3_begin" << loop_stack.back() << "__:" << endl;
        }
    }
#line 4297 "parser.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1558 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("begin_while while");
        msg_instrucao("while");
        loop_stack.push_back(loopseq);
            insideLoop++;
            if(!preProcessamento)
                cout << "__loop_label_begin" << loop_stack.back() << "__:" << endl; 
        switch_stack.push_back(2);
        loopseq++;
    }
#line 4312 "parser.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1571 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("begin_labeled2 fecha_parenteses");
            //stack++;
            if(!preProcessamento) {
                cout << "load r0, " << stack+1 << endl;
                cout << "loadn r1, #0" << endl;
                cout << "cmp r0, r1" << endl;
                cout << "jeq __exit_loop_label" << loop_stack.back() << "__" << endl;
                cout << "jmp __loop_label" << loop_stack.back() << "__" << endl;
                cout << "__loop_label" << loop_stack.back() << "__:" << endl;
            }
    }
#line 4329 "parser.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1586 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("begin_for for");
            insideLoop++;
            if(!preProcessamento && debug_instrucao)
                cout << ";----- begin for -----" << endl;
        switch_stack.push_back(2);
        loop_stack.push_back(loopseq);
        loopseq++;
    }
#line 4343 "parser.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1598 "parser.y" /* yacc.c:1646  */
    {
        msg_sintatico("begin_labeled3 expression_statement");
            stack++;
            if(!preProcessamento) {
                cout << "load r0, " << stack << endl;
                cout << "loadn r1, #0" << endl;
                cout << "cmp r0, r1" << endl;
                cout << "jeq __exit_loop_label" << loop_stack.back() << "__" << endl;

                cout << "jmp __loop_label3_begin" << loop_stack.back() << "__" << endl;
                cout << "__loop_label2_begin" << loop_stack.back() << "__:" << endl;
            }
    }
#line 4361 "parser.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1614 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("begin_labeled4 expression_statement");
        if(!preProcessamento)
            cout << "__loop_label_begin" << loop_stack.back() << "__:" << endl; 
    }
#line 4371 "parser.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 1622 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("GOTO IDENTIFIER PONTO_VIRGULA");
        checa_label(*(yyvsp[-1].string)); 
        if(!preProcessamento && debug_sintatico) 
            cout << "jump_statement: IDENTIFIER " << *(yyvsp[-1].string) << endl; 
	}
#line 4382 "parser.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1628 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("CONTINUE PONTO_VIRGULA");
        if(insideLoop == 0) { 
            errorMsg("continue fora de loop"); 
        } 
        if(!preProcessamento)
        cout << "jmp __loop_label_begin"<< loop_stack.back() << "__" << endl;
	}
#line 4395 "parser.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1636 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("BREAK PONTO_VIRGULA");
        if(insideLoop == 0 && insideCase == 0) {
            cout << "; case: " << insideCase << " loop: " << insideLoop << endl; 
            errorMsg("break fora de loop"); 
        } 
        if(!preProcessamento)
            if(switch_stack.back() == 2)
                cout << "jmp __exit_loop_label" << loop_stack.back() << "__" << endl;
            else if(switch_stack.back() == 1)
                cout << "jmp __exit_switch_label" << switch_seq << "__" << endl;
	}
#line 4412 "parser.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1648 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("RETURN PONTO_VIRGULA");
        if(!preProcessamento && f->nome != "main") {
            cout << "rts" << endl;
        }
        else if(!preProcessamento && f->nome == "main") {
            cout << "breakp" << endl;
        }
	}
#line 4426 "parser.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1657 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("RETURN expression PONTO_VIRGULA");
        if(isFunctionVoid) { 
            errorMsg("funcao void retornando valor"); 
        } 
        funcao_tem_return = true;
        if(!preProcessamento && f->nome != "main") {
            cout << "rts" << endl;
        }
        else if(!preProcessamento && f->nome == "main") {
            cout << "breakp" << endl;
        }
	}
#line 4444 "parser.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 1673 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("external_declaration");
	}
#line 4452 "parser.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1676 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("translation_unit external_declaration");
	}
#line 4460 "parser.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1682 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("function_definition");
	}
#line 4468 "parser.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1685 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("declaration");
	}
#line 4476 "parser.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1691 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("declaration_specifiers declarator compound_statement");
        function_definition();
	}
#line 4485 "parser.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1698 "parser.y" /* yacc.c:1646  */
    {
        msg_sintatico("opt_parametros parameter_list");
    }
#line 4493 "parser.cpp" /* yacc.c:1646  */
    break;

  case 226:
#line 1704 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("parameter_list parameter_declaration");
    }
#line 4501 "parser.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1707 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("parameter_list parameter_list VIRGULA parameter_declaration");
    }
#line 4509 "parser.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1713 "parser.y" /* yacc.c:1646  */
    { 
        flag_ponteiro = -1; 
        msg_sintatico("parameter_declaration type_specifier pointer direct_declarator");
    }
#line 4518 "parser.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1717 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("parameter_declaration type_specifier direct_declarator");
    }
#line 4526 "parser.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 1723 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("begin_funcao IDENTIFIER");

        if(*(yyvsp[0].string) == "main") {
            tem_main = true;
            is_main = true;
        }

        declara_funcao(*(yyvsp[0].string)); 
        t->insereEscopo(); 
        if(type_void) 
            isFunctionVoid = true; 
        stack_antes_de_entrar_no_escopo = stack; 
    }
#line 4545 "parser.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1740 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("begin_parametro ABRE_PARENTESES");

        begin_parametro = true; 
        if(!preProcessamento) {
            msg_instrucao("; declarando funcao: " + f->nome);
            cout << "__function_label_" << f->nome << "__:" << endl;
        }
    }
#line 4559 "parser.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 1752 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("end_parametro FECHA_PARENTESES");

        begin_parametro = false; 

        if(!preProcessamento) {
            if(f->parametros.size() > 0)
                msg_instrucao("; resgatando os parametros");

            for(int i = f->parametros.size(); i--; ) {
                if(debug_instrucao)
                    cout << "pop r0 ; resgatou " << f->parametros[i].nome << endl;
                else 
                    cout << "pop r0" << endl;
                cout << "store " << f->parametros[i].endereco << ", r0" << endl;
            }
            cout << endl;
        }
    }
#line 4583 "parser.cpp" /* yacc.c:1646  */
    break;


#line 4587 "parser.cpp" /* yacc.c:1646  */
        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
                                        yyesa, &yyes, &yyes_capacity, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
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

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

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

#if 1
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1773 "parser.y" /* yacc.c:1906  */


void function_definition() {
    assert(f != NULL);
    if(!funcao_tem_return && !isFunctionVoid)
        warningMsg("funcao " + f->nome + " nao esta retornando nenhum valor");

    stack = stack_antes_de_entrar_no_escopo; 
    t->removeEscopo(); 
    f = NULL; 
    isFunctionVoid = false; 
    funcao_tem_return = false;

    if(is_main && !preProcessamento)
        cout << "breakp" << endl;

    is_main = false;
    if(!preProcessamento)
    cout << "rts" << endl;
}

void salva_tipo(string tipo) {
    if(tipo == "void")
        type_void = true;
    else
        type_void = false;
    e = t->busca(tipo, &declarado); 
    if(e == NULL) { 
        errorMsg("tipo nao declarado"); 
    } 
}

void expressao_binaria(char op) {
    if(!preProcessamento) {
        if(debug_instrucao)
            cout << "; expressao_binaria: " << stack+2 << " " << op << " " << stack+1 << endl;

        cout << "load r0, " << stack+2 << endl
             << "load r1, " << stack+1 << endl;
        switch(op) {
            case '+': cout << "add r2, r0, r1" << endl; break;
            case '*': cout << "mul r2, r0, r1" << endl; break;
            case '-': cout << "sub r2, r0, r1" << endl; break;
            case '/': cout << "div r2, r0, r1" << endl; break;
            case '%': cout << "mod r2, r0, r1" << endl; break;
            case 'l': cout << "shiftl0 r2, r0, r1" << endl; break; // shift left
            case 'r': cout << "shiftr0 r2, r0, r1" << endl; break; // shift right
            case '|': cout << "or r2, r0, r1" << endl; break;
            case '^': cout << "xor r2, r0, r1" << endl; break;
            case '&': cout << "and r2, r0, r1" << endl; break;
            default: errorMsg("operacao invalida"); break;
        }
        cout << "store " << stack+2 << ", r2" << endl << endl;
        stack++;
    }
}

void relacao_binaria(char op) {
    if(!preProcessamento) {
        msg_instrucao("relacao_binaria");

        cout<< "load r0, " << stack+2 << endl
            << "load r1, " << stack+1 << endl
            << "loadn r2, #" << stack+2 << endl;

        switch(op) {
            case 'e': cout<< "call __and_routine__" << endl; break;
            case 'o': cout<< "call __or_routine__" << endl; break;
            case '=': cout<< "call __equal_routine__" << endl; break;
            case '!': cout<< "call __not_equal_routine__" << endl; break;
            case 'm': cout<< "call __equal_less_routine__" << endl; break;
            case 'M': cout<< "call __equal_more_routine__" << endl; break;
            case '<': cout<< "call __less_routine__" << endl; break;
            case '>': cout<< "call __more_routine__" << endl; break;
            default: errorMsg("operacao invalida"); break;
        }
        //cout << "store " << stack+2 << ", r2" << endl << endl;
        stack++;
    }
}

// verifica se o identificador que esta sendo declarado ja esta na tabela de simbolos
bool declarando(string &id) {
    Entrada *e = t->declarado(id); 
    if(e != NULL) {
        ostringstream convert;
        convert << "O identificador " << id << " ja foi declarado";
        errorMsg(convert.str());
        return false;
    }
    return true;
}

bool referenciando(string &id) {
    bool aux;
    Entrada *e = t->busca(id, &aux);
    if(aux == false) {
        ostringstream convert;
        convert << "O identificador " << id << " nao foi declarado";
        errorMsg(convert.str());
        return false;
    }
    return true;
}

void errorMsg(string msg) { 
    if(preProcessamento) {
    std::cout << "; @(" << yylineno << ") ERRO - " << msg << endl;
    exit(1);  
    }
}

void warningMsg(string msg) { 
    if(preProcessamento)
    std::cout << "; @(" << yylineno << ") WARNING - " << msg << endl;
}

string to_str(int value) {
    char buffer[33];
    sprintf(buffer, "%d", value);
    string aux = buffer;
    return aux;
}

void push(string value, int a) {
    if(!preProcessamento && t->getEscopo() > 0 || preProcessamento && t->getEscopo() ==0) {
        switch(a) {
            case 1: // variavel
                if(debug_instrucao) 
                    cout << "; " << t->buscaEndereco(stack) << "(" << stack << ") recebe o conteudo da variavel: " << t->buscaEndereco(atoi(value.c_str())) << "(" << value << ")" << endl; 
                cout << "load r0, " << value << endl 
                     << "store " << stack << ", r0" << endl << endl;
                stack_ampersand = atoi(value.c_str());

                mapa[stack] = atoi(value.c_str());
                break;

            case 2: // valor constante numero
                if(debug_instrucao) 
                    cout << "; " << t->buscaEndereco(stack) << "(" << stack << ") recebe o conteudo: " << value << endl; 
                cout << "loadn r0, #" << value << endl 
                     << "store " << stack << ", r0" << endl << endl;

                mapa[stack] = -1;
                break;

            case 3: // valor constante caracter
                if(debug_instrucao) 
                    cout << "; " << t->buscaEndereco(stack) << "(" << stack << ") recebe o conteudo: " << value << endl; 
                cout << "loadn r0, #'" << value << "'" << endl 
                     << "store " << stack << ", r0" << endl << endl;

                mapa[stack] = -1;
                break;

            default:
                break;
        }
        stack--;
    }
}

void declara_variaveis_e_parametros(string id, int nbytes) {
	// se for um parametro, insere na tabela de simbolos e na funcao pai
	if(begin_parametro) {
		// verifica se o parametro ja nao foi declarado
		if(declarando(id)) {
			Entrada *p = t->insereParametro(id, e);
            p->endereco = stack;
            p->ponteiro = flag_ponteiro;
            p->nbytes = nbytes;

			assert(f != NULL);
			f->insereParametro(p);
            if(!preProcessamento && debug_instrucao) 
                cout << "; variavel: " << id << " alocada em " << stack << endl << endl;
            stack--;
		}
	}
	// senao e' uma variavel sendo declarada
	else {
        if(t->getEscopo() == 0 && !preProcessamento)
            return;
		if(declarando(id)) {
			Entrada *v = t->insereVariavel(id, e);
            v->endereco = stack;
            v->ponteiro = flag_ponteiro;
            v->nbytes = nbytes;

            if(((!preProcessamento && t->getEscopo() > 0) || (preProcessamento && t->getEscopo() == 0)) && debug_instrucao) 
                cout << "; variavel: " << id << " alocada em " << stack << " com " << nbytes << " bytes" << endl << endl;
            stack--;
		}
	}
}

void declara_label(string id) {
	assert(f != NULL);
	t->insereLabel(id, &declarado, f);
}

void checa_label(string id) {
	if(t->buscaLabel(id, f) == false) {
        ostringstream convert;
        convert << "label: " << id << " nao declarada";
        errorMsg(convert.str());
	}
}

void declara_funcao(string id) {
    // se nao foi declarado, declara
    Entrada *aux = t->busca(id, &declarado);
    if(declarado == false) {
        f = t->insereFuncao(id, e, 0);
    }
    // se foi, compara os parametros
    else {
        f = aux;
        begin_parametro = true;
    }
}

void referencia_funcao(string id) {
    if(referenciando(id)) { 
        Entrada *fr = t->busca(id, &declarado);
        if(arg_list.size() != fr->parametros.size()) {
            ostringstream convert;
            convert << "funcao: " << id << " esperava: " << fr->parametros.size() << " parametros mas encontrou: " << arg_list.size() << " parametros";
            errorMsg(convert.str());
        }
        /* checagem dos tipos da funcao
        else
            for(int i = 0; i < arg_list.size(); i++) 
                if(fr->parametros[i].tipo->nome.compare(arg_list[i]) != 0) {
                    std::cout << "@(" << yylineno << ") WARNING - ";
                    cout << "funcao: " << id << " esperava: \"" << fr->parametros[i].tipo->nome << "\" mas encontrou: \"" << arg_list[i] << "\"" << endl;
                }
        */
    } 
}

string int_or_char(string id) {
    if(id[0] == '\'')
        return "char";
    return "int";
}

int yyerror(char const *s) {
	fflush(stdout);
	cout << "@(" << yylineno << ") ERRO - " << s << endl;
    exit(0);
}

void msg_sintatico(string msg) {
    if(debug_sintatico && preProcessamento)
	    cout << "; @(" << yylineno << ") SINTATICO - " << msg << endl;
}

void msg_instrucao(string msg) {
    if(debug_instrucao)
	    cout << "; @(" << yylineno << ") INSTRUCAO - " << msg << endl;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        cout << "ERRO - Uso incorreto" << endl
             << "Uso: ./parser arquivo_testes.txt" << endl;
        return 0;
    }
    if(argc == 3)
        debug = 1;

    int yylineno_backup = yylineno; // salva o contador de linhas
    stack_antes_de_entrar_no_escopo = stack;

    t = new TAD();
    offset = stack;

    cout << ";---------- BEGIN - PRE PROCESSAMENTO ----------" << endl;
    yyin = fopen(argv[1], "r"); // abre o arquivo
    preProcessamento = true;
    yyparse();                  // processa o arquivo
    offset = t->filtro(offset);       // remove tudo da tabela de simbolos que nao seja procedure e functions
    preProcessamento = false;
    fclose(yyin);               // fecha o arquivo
    cout << ";---------- END PRE PROCESSAMENTO ----------" << endl;

    yylineno = yylineno_backup; // reseta o contador de linhas

    if(!tem_main)
        errorMsg("o arquivo deve ter um main");

    cout << ";---------- BEGIN ----------" << endl;
    stack = offset;
    if(debug_instrucao) {
        vector<Entrada> listaVarGlobal = t->variaveis_escopo();
        for(int i = 0; i < listaVarGlobal.size(); i++) {
            cout << "; variavel: " << listaVarGlobal[i].nome << " alocada em " << listaVarGlobal[i].endereco << endl << endl;
        }
    }

    yyin = fopen(argv[1], "r");

    cout << "jmp __function_label_main__" << endl;

    // r0 posicao na tela
    // r1 caractere a ser impresso
    // r2 comeco da string na memoria e indice para o load do r1
    // r3 fim da string na memoria
    // r4 caracteres %, d, s, c
    // r5 
    // r6 \0
    // r7 
    
    // operadores logicos
    cout<< "__and_routine__:" << endl
        << "and r0, r1, r0" << endl
        << "loadn r1, #0" << endl
        << "cmp r0, r1" << endl
        << "jne __true__" << endl
        << "jmp __false__" << endl;

    cout<< "__or_routine__:" << endl
        << "or r0, r1, r0" << endl
        << "loadn r1, #0" << endl
        << "cmp r0, r1" << endl
        << "jne __true__" << endl
        << "jmp __false__" << endl;

    cout<< "__equal_routine__:" << endl
        << "cmp r0, r1" << endl
        << "jne __false__" << endl
        << "jmp __true__" << endl;

    cout<< "__not_equal_routine__:" << endl
        << "cmp r0, r1" << endl
        << "jne __true__" << endl
        << "jmp __false__" << endl;

    cout<< "__less_routine__:" << endl
        << "cmp r0, r1" << endl
        << "jle __true__" << endl
        << "jmp __false__" << endl;

    cout<< "__more_routine__:" << endl
        << "cmp r0, r1" << endl
        << "jgr __true__" << endl
        << "jmp __false__" << endl;

    cout<< "__equal_less_routine__:" << endl
        << "cmp r0, r1" << endl
        << "jel __true__" << endl
        << "jmp __false__" << endl;

    cout<< "__equal_more_routine__:" << endl
        << "cmp r0, r1" << endl
        << "jeg __true__" << endl
        << "jmp __false__" << endl;

    cout<< "__true__:" << endl
        << "loadn r0, #1" << endl
        << "storei r2, r0" << endl
        << "rts" << endl;

    cout<< "__false__:" << endl
        << "loadn r0, #0" << endl
        << "storei r2, r0" << endl
        << "rts" << endl;

    yyparse();
    fclose(yyin);
    cout << ";---------- END ----------" << endl;

    //t->log();
    //t->labelLog();
    delete t;

    return 0;
}


