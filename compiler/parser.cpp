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
int flag_ponteiro_assignment = 0;
int flag_assignment = 0;

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


#line 193 "parser.cpp" /* yacc.c:339  */

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
    ASM = 327,
    UNSIGNED = 328,
    UNION = 329,
    TYPE_NAME = 330,
    TYPEDEF = 331,
    STRUCT = 332,
    SIZEOF = 333,
    SIGNED = 334,
    RESTRICT = 335,
    REGISTER = 336,
    INLINE = 337,
    IMAGINARY = 338,
    ELLIPSIS = 339,
    DO = 340,
    COMPLEX = 341,
    AUTO = 342,
    VOLATILE = 343,
    ENUM = 344,
    PONTO = 345,
    DOUBLE = 346,
    SHORT = 347,
    LONG = 348,
    FLOAT = 349
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 138 "parser.y" /* yacc.c:355  */

    int token;
    std::string *string;

#line 333 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 348 "parser.cpp" /* yacc.c:358  */

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
#define YYLAST   1174

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  84
/* YYNRULES -- Number of rules.  */
#define YYNRULES  234
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  388

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   349

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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   212,   212,   218,   221,   224,   227,   232,   243,   249,
     281,   319,   348,   386,   389,   398,   410,   422,   433,   437,
     444,   447,   454,   461,   516,   519,   525,   529,   533,   536,
     540,   543,   550,   553,   559,   562,   566,   570,   577,   580,
     584,   591,   594,   598,   605,   608,   612,   616,   620,   627,
     630,   634,   641,   644,   651,   654,   661,   664,   671,   674,
     681,   684,   691,   694,   701,   704,   780,   784,   788,   792,
     796,   800,   804,   808,   812,   816,   820,   827,   830,   836,
     842,   845,   851,   854,   857,   860,   863,   866,   869,   872,
     878,   881,   887,   897,   928,   931,   934,   937,   940,   946,
     950,   954,   958,   962,   966,   970,   974,   977,   980,   984,
     987,   990,   996,   999,  1002,  1008,  1011,  1017,  1020,  1026,
    1032,  1035,  1038,  1041,  1047,  1050,  1056,  1059,  1062,  1068,
    1071,  1074,  1077,  1080,  1086,  1089,  1095,  1098,  1104,  1107,
    1110,  1116,  1122,  1125,  1134,  1139,  1159,  1203,  1206,  1209,
    1212,  1218,  1221,  1227,  1230,  1236,  1239,  1242,  1248,  1251,
    1254,  1257,  1260,  1263,  1266,  1269,  1275,  1282,  1288,  1291,
    1294,  1297,  1303,  1309,  1312,  1318,  1321,  1327,  1330,  1333,
    1336,  1339,  1342,  1345,  1351,  1359,  1371,  1382,  1390,  1393,
    1399,  1407,  1425,  1428,  1434,  1437,  1443,  1446,  1452,  1455,
    1461,  1468,  1475,  1487,  1496,  1514,  1524,  1538,  1542,  1556,
    1573,  1582,  1595,  1610,  1622,  1638,  1646,  1652,  1660,  1672,
    1681,  1697,  1700,  1706,  1709,  1715,  1721,  1722,  1728,  1731,
    1737,  1741,  1747,  1764,  1776
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
  "MAIOR_MAIOR", "PIPE", "AMPERSAND", "TIL", "BREAKP", "OUT", "IN", "ASM",
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
  "asm_statement", "labeled_statement", "begin_case", "compound_statement",
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
     345,   346,   347,   348,   349
};
# endif

#define YYPACT_NINF -321

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-321)))

#define YYTABLE_NINF -233

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1003,  -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,
    -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,    36,
    -321,  -321,  -321,  -321,  -321,    59,  1003,  1003,  -321,    43,
    -321,  1003,  1003,   243,  -321,  -321,   -13,    47,   152,    69,
    -321,    34,  -321,    42,  -321,   111,    80,  -321,  -321,    45,
     220,  -321,  -321,  -321,  -321,    47,   110,    65,  -321,   145,
    -321,  -321,    69,    44,  -321,   652,   100,  -321,  -321,   -15,
     220,   220,  1040,  -321,    82,   220,    92,   940,    12,  -321,
     108,  -321,  -321,  -321,  -321,   161,  -321,  -321,  -321,  -321,
     956,   956,  -321,   508,   558,  -321,  -321,   130,   136,   146,
     992,  -321,    76,   523,   940,  -321,   143,   184,   173,   227,
     234,   149,   187,   159,   208,    10,  -321,  -321,  -321,  -321,
    -321,  -321,    44,   180,   202,  -321,  1080,  -321,  -321,  -321,
     940,   196,  -321,   215,  -321,    20,  -321,  -321,  -321,  -321,
    -321,  -321,   217,   940,   688,   508,  -321,  -321,  -321,    -9,
      87,   219,   940,   269,  -321,   134,   652,    -5,  -321,   940,
     940,   275,   508,  -321,  -321,  -321,   281,  -321,  -321,  -321,
    -321,  -321,  -321,  -321,  -321,  -321,  -321,  -321,   940,  -321,
     940,   940,   940,   940,   940,   940,   940,   940,   940,   940,
     940,   940,   940,   940,   940,   940,   940,   940,   940,  -321,
     111,  -321,   230,   -15,  -321,  -321,    82,  -321,   940,  -321,
     291,   109,  -321,    30,  -321,   237,   940,  -321,   724,   104,
     168,  -321,   244,   760,   242,  -321,   558,  -321,  -321,  -321,
    -321,   249,   245,   254,   260,  -321,  -321,  -321,  -321,  -321,
     143,   143,   184,   184,   173,   173,   173,   173,   227,   227,
     234,   149,   187,   159,   208,   200,  -321,   324,  -321,  -321,
    -321,  -321,   246,   268,   940,  -321,   271,  -321,   280,  -321,
     282,  -321,   279,   244,   796,   558,  -321,  -321,  -321,   652,
     940,  -321,  -321,   271,   940,   -38,   283,  -321,  -321,   287,
     284,   940,   290,   300,   832,   293,  -321,  -321,   292,   605,
     204,  -321,    67,  -321,  -321,  -321,  -321,   416,  -321,  -321,
    -321,  -321,   288,   289,  -321,  -321,   940,  -321,  -321,  -321,
    -321,   296,  -321,   303,   137,  -321,   313,  -321,   605,   940,
    -321,   940,   293,  -321,   320,  -321,   212,  -321,   605,  -321,
     343,  -321,  -321,  -321,   940,   868,   155,  -321,  -321,  -321,
    -321,  -321,    72,    90,   605,  -321,  -321,  -321,   317,   141,
    -321,   868,  -321,  -321,   605,  -321,   605,  -321,   940,  -321,
     605,  -321,   904,   347,  -321,   150,  -321,  -321,   154,   605,
    -321,   605,   325,   605,  -321,  -321,  -321,  -321
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    99,   102,   100,   108,   138,    95,    96,   107,   116,
     111,    94,   115,   106,   139,    98,   141,    97,   140,     0,
     105,   101,   103,   104,   224,     0,    82,    84,   109,     0,
     110,    86,    88,     0,   221,   223,   133,     0,   144,   147,
      80,     0,    90,    92,   143,     0,     0,    83,    85,   114,
       0,    87,    89,     1,   222,     0,   136,     0,   134,     0,
     151,   149,   148,     0,    81,     0,   144,   142,   233,   226,
       0,   121,     0,   117,     0,   123,     0,     0,     0,   129,
       0,   152,   150,    91,     7,     2,     6,    31,    28,    29,
       0,     0,    27,     0,     0,    26,    30,     0,     0,     0,
       0,    13,    20,    32,     0,    34,    38,    41,    44,    49,
      52,    54,    56,    58,    60,    62,    64,   166,    93,     3,
       4,     5,     0,     0,   227,   228,     0,   120,   113,   118,
       0,     0,   124,   126,   122,     0,   130,    32,    79,   137,
     131,   135,   145,     0,     0,     0,    21,    22,    77,     0,
     153,     0,     0,     0,   168,     0,     0,     0,   173,     0,
       0,     0,     0,    24,    15,    16,     0,    66,    70,    71,
      67,    68,    73,    72,    69,    75,    74,    76,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   231,
       0,   234,     0,     0,   112,   127,     0,   119,     0,   132,
       0,     0,     9,     0,    18,     0,     0,     8,     0,     0,
     155,   154,   156,     0,     0,   176,     0,   167,   169,   172,
     174,     0,     0,     0,     0,    14,    65,    35,    36,    37,
      39,    40,    42,    43,    45,    46,    47,    48,    50,    51,
      53,    55,    57,    59,    61,     0,   230,     0,   225,   229,
     125,   128,     0,    11,     0,    10,     0,    78,    27,   159,
       0,   165,     0,   157,     0,     0,    33,   175,   170,     0,
       0,   185,   187,    25,     0,     2,     0,   213,   211,     0,
       0,     0,     0,     0,     0,     0,   198,   192,     0,     0,
       0,   196,     0,   197,   183,   177,   178,     0,   194,   179,
     180,   181,     0,     0,   182,   146,     0,    19,   163,   160,
     158,    27,   161,     0,     0,   171,     0,    63,     0,     0,
     218,     0,     0,   217,     0,   219,     0,   191,     0,   184,
       0,   199,   193,   195,     0,     0,     0,   164,   162,    17,
     186,   188,     0,     0,     0,   216,   220,   190,     0,     0,
     215,     0,    12,   204,     0,   203,     0,   189,     0,   212,
       0,   214,     0,   200,   202,     0,   206,   210,     0,     0,
     205,     0,     0,     0,   208,   201,   207,   209
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -321,  -321,  -321,  -321,   -10,  -321,   -85,    93,   103,    75,
      99,   188,   189,   190,   186,   191,  -321,   -60,   -57,  -321,
     -89,  -102,  -239,   -25,  -321,   326,  -321,     0,  -321,  -321,
     337,   -26,   -32,  -321,   216,  -321,   335,   -23,     3,  -321,
     -65,   -40,   -18,  -321,   -28,   195,   203,   -27,   133,   198,
    -321,   253,  -227,  -321,  -321,  -321,  -321,  -321,    94,   223,
    -321,   120,  -320,  -321,  -321,  -321,  -321,  -321,    50,  -321,
    -321,  -321,  -321,  -321,  -321,  -321,   396,  -321,  -321,  -321,
     228,  -321,  -321,  -321
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   101,   102,   213,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   148,   178,
     300,   139,    24,    25,    41,    42,    26,    71,    28,    29,
      72,    73,    74,   131,   132,    30,    57,    58,    75,    32,
      43,    44,    45,    62,   151,   221,   222,   154,   155,   156,
     157,   158,   303,   304,   119,   120,   121,   305,   338,   306,
     307,   308,   309,   310,   366,   364,   381,   311,   379,   312,
     370,   313,   372,   361,   314,    33,    34,    35,   123,   124,
     125,    46,    69,   202
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    47,    48,    31,   149,    67,    51,    52,   117,   133,
     229,     1,     2,     3,     4,   328,    56,   138,   301,   179,
     143,    61,   144,   197,    56,   360,    27,    27,   205,    31,
      31,    27,    27,    27,    31,    31,    31,   117,   118,   127,
      36,   371,    60,   134,    82,   216,   129,    49,    66,    55,
     224,    56,   217,   152,   211,   141,   149,    65,     8,     9,
      10,   150,    12,    38,    13,    81,   198,   137,   301,   122,
     138,    66,   340,   149,    19,   140,    20,    21,    22,    23,
     146,   147,   199,   209,   264,   153,    66,   214,    63,    64,
     163,   265,   138,    39,   137,   237,   238,   239,    37,   117,
     129,   351,   231,   232,   200,    50,   261,    70,    39,   255,
       5,   357,   141,   150,    40,    66,    39,   215,    39,    78,
     137,   236,    40,   164,   165,    77,   216,   367,    79,   228,
     150,    39,   220,   363,   234,   130,    39,   373,   276,   374,
      68,   133,   137,   376,   216,   218,   135,   219,   138,    14,
      80,   365,   384,    39,   385,   136,   387,    18,    59,   267,
     256,   270,   218,   216,   219,   271,   166,   142,   263,   117,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   226,   332,
     159,   226,   180,   181,   182,   216,   160,   227,   137,   278,
     349,   220,   369,   122,   216,   336,   161,   317,   216,   216,
      59,   382,  -232,   137,   362,   377,   193,   323,   117,   143,
     196,   144,   117,   326,   327,   195,   218,   346,   219,   183,
     184,   138,   302,   187,   188,   189,   190,   185,   186,   194,
     352,   201,   353,    53,   191,   192,     1,     2,     3,     4,
     206,   207,   325,   284,   216,   359,   203,    27,   216,   341,
      31,     5,   244,   245,   246,   247,   216,   356,   208,     1,
       2,     3,     4,   225,   137,   210,   240,   241,   233,   375,
     223,   137,   302,   378,     5,   235,     6,     7,   242,   243,
     248,   249,   257,     8,     9,    10,   262,    12,   266,    13,
      14,   277,   274,   280,   334,   315,   281,    27,    18,    19,
      31,    20,    21,    22,    23,   282,     8,     9,    10,    11,
      12,   283,    13,    14,    15,    16,   316,    84,   285,    86,
      17,    18,    19,   275,    20,    21,    22,    23,    87,   318,
     320,   319,   330,   329,   331,   333,   337,   339,   344,   345,
       1,     2,     3,     4,   286,   347,   287,   288,   289,   290,
     291,   292,   348,   293,   294,     5,   295,     6,     7,    88,
      89,    90,    91,    92,   350,   355,   358,   368,   380,   296,
     386,   250,   253,   251,    93,   252,   257,   297,   254,    83,
      76,    95,    96,   298,    97,    98,    99,     8,     9,    10,
      11,    12,   100,    13,    14,    15,    16,   126,   324,   299,
     230,    17,    18,    19,   272,    20,    21,    22,    23,    84,
     285,    86,   260,   273,   279,   258,   354,   343,   383,    54,
      87,   259,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,   286,     0,   287,   288,
     289,   290,   291,   292,     0,   293,   294,     5,   295,     6,
       7,    88,    89,    90,    91,    92,     0,     0,     0,     0,
       0,   296,     0,     0,     0,     0,    93,     0,   257,   342,
       0,     0,     0,    95,    96,   298,    97,    98,    99,     8,
       9,    10,    11,    12,   100,    13,    14,    15,    16,     0,
       0,   299,     0,    17,    18,    19,     0,    20,    21,    22,
      23,    84,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     4,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     5,
       0,     0,     0,    88,    89,    90,    91,    92,     0,     0,
       0,    84,    85,    86,     0,     0,     0,     0,    93,     0,
       0,     0,    87,     0,     0,    95,    96,     0,    97,    98,
      99,     8,     9,    10,     0,    12,   100,    13,    14,     0,
       0,     0,     0,     0,     0,     0,    18,    19,     0,    20,
      21,    22,    23,    88,    89,    90,    91,    92,    84,   285,
      86,     0,     0,     0,     0,     0,   152,     0,    93,    87,
      94,     0,     0,     0,     0,    95,    96,     0,    97,    98,
      99,     0,     0,     0,     0,   286,   100,   287,   288,   289,
     290,   291,   292,     0,   293,   294,     0,   295,   153,     0,
      88,    89,    90,    91,    92,    84,    85,    86,     0,     0,
     296,     0,     0,     0,     0,    93,    87,   257,     0,     0,
       0,     0,    95,    96,   298,    97,    98,    99,     0,     0,
       0,     0,     0,   100,     0,     0,     0,     0,     0,     0,
     299,    84,    85,    86,     0,     0,     0,    88,    89,    90,
      91,    92,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,    94,     0,     0,     0,     0,    95,
      96,     0,    97,    98,    99,     0,     0,    84,    85,    86,
     100,     0,     0,    88,    89,    90,    91,    92,    87,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,   212,
       0,     0,     0,     0,     0,    95,    96,     0,    97,    98,
      99,     0,     0,    84,    85,    86,   100,     0,     0,    88,
      89,    90,    91,   268,    87,     0,     0,     0,     0,     0,
       0,     0,     0,   269,    93,     0,     0,     0,     0,     0,
       0,    95,    96,     0,    97,    98,    99,     0,     0,    84,
      85,    86,   100,     0,     0,    88,    89,    90,    91,    92,
      87,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,     0,   275,     0,     0,     0,     0,    95,    96,     0,
      97,    98,    99,     0,     0,    84,    85,    86,   100,     0,
       0,    88,    89,    90,    91,   321,    87,     0,     0,     0,
       0,     0,     0,     0,     0,   322,    93,     0,     0,     0,
       0,     0,     0,    95,    96,     0,    97,    98,    99,     0,
       0,    84,    85,    86,   100,     0,     0,    88,    89,    90,
      91,    92,    87,     0,     0,     0,     0,   335,     0,     0,
       0,     0,    93,     0,     0,     0,     0,     0,     0,    95,
      96,     0,    97,    98,    99,     0,     0,    84,    85,    86,
     100,     0,     0,    88,    89,    90,    91,    92,    87,     0,
       0,     0,     0,   296,     0,     0,     0,     0,    93,     0,
       0,     0,     0,     0,     0,    95,    96,     0,    97,    98,
      99,     0,     0,    84,    85,    86,   100,     0,     0,    88,
      89,    90,    91,    92,    87,     0,     0,     0,     0,    84,
      85,    86,     0,     0,    93,   377,     0,     0,     0,     0,
      87,    95,    96,     0,    97,    98,    99,     0,     0,     0,
       0,     0,   100,     0,     0,    88,    89,    90,    91,    92,
       0,     0,     0,     0,     0,    84,    85,    86,     0,     0,
      93,    88,    89,    90,    91,    92,    87,    95,    96,     0,
      97,    98,    99,     0,     0,     0,   145,     0,   100,     0,
       0,     0,     0,    95,    96,     0,    97,    98,    99,     1,
       2,     3,     4,     0,   100,     0,     0,    88,    89,    90,
      91,    92,     0,     0,     5,     0,     6,     7,     0,     0,
       0,     0,   162,     0,     0,     0,     0,     0,     0,    95,
      96,     0,    97,    98,    99,     0,     1,     2,     3,     4,
     100,     0,     0,     0,     0,     0,     8,     9,    10,    11,
      12,     5,    13,    14,    15,    16,     0,     0,     0,     0,
      17,    18,    19,     0,    20,    21,    22,    23,     0,     0,
       0,     0,     0,   128,     0,     0,     1,     2,     3,     4,
       0,     0,     0,     8,     9,    10,     0,    12,     0,    13,
      14,     5,     0,     0,     0,     0,     0,     0,    18,    19,
       0,    20,    21,    22,    23,     0,     0,     0,     0,     0,
       0,     0,     0,   204,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     9,    10,     0,    12,     0,    13,
      14,     0,     0,     0,     0,     0,     0,     0,    18,    19,
       0,    20,    21,    22,    23
};

static const yytype_int16 yycheck[] =
{
       0,    26,    27,     0,    93,    45,    31,    32,    65,    74,
      15,    26,    27,    28,    29,    53,     4,    77,   257,   104,
      58,    39,    60,    13,     4,   345,    26,    27,   130,    26,
      27,    31,    32,    33,    31,    32,    33,    94,    65,    71,
       4,   361,    39,    75,    62,    54,    72,     4,     4,    62,
     152,     4,    61,    58,   143,    78,   145,    15,    73,    74,
      75,    93,    77,     4,    79,    62,    56,    77,   307,    69,
     130,     4,   299,   162,    89,    63,    91,    92,    93,    94,
      90,    91,   122,    63,    54,    90,     4,   144,    54,    55,
     100,    61,   152,    49,   104,   180,   181,   182,    62,   156,
     126,   328,   159,   160,   122,    62,   208,    62,    49,   198,
      41,   338,   135,   145,    55,     4,    49,   145,    49,    54,
     130,   178,    55,    47,    48,    15,    54,   354,    63,   156,
     162,    49,   150,    61,   162,    53,    49,   364,   223,   366,
      60,   206,   152,   370,    54,    58,    54,    60,   208,    80,
       5,    61,   379,    49,   381,    63,   383,    88,    58,   216,
     200,   218,    58,    54,    60,    61,    90,    59,    59,   226,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,    54,   291,
      60,    54,    49,    50,    51,    54,    60,    63,   208,   226,
      63,   219,    61,   203,    54,   294,    60,   264,    54,    54,
      58,    61,    60,   223,    59,    61,    67,   274,   275,    58,
      12,    60,   279,   280,   284,    66,    58,   316,    60,    45,
      46,   291,   257,     6,     7,     8,     9,    64,    65,    52,
     329,    61,   331,     0,    10,    11,    26,    27,    28,    29,
      54,    55,   279,    53,    54,   344,    54,   257,    54,    55,
     257,    41,   187,   188,   189,   190,    54,    55,    53,    26,
      27,    28,    29,     4,   284,    58,   183,   184,     3,   368,
      61,   291,   307,   372,    41,     4,    43,    44,   185,   186,
     191,   192,    62,    73,    74,    75,     5,    77,    61,    79,
      80,    59,    58,    54,     4,    59,    61,   307,    88,    89,
     307,    91,    92,    93,    94,    61,    73,    74,    75,    76,
      77,    61,    79,    80,    81,    82,    58,     3,     4,     5,
      87,    88,    89,    62,    91,    92,    93,    94,    14,    59,
      61,    59,    55,    60,    60,    55,    53,    55,    60,    60,
      26,    27,    28,    29,    30,    59,    32,    33,    34,    35,
      36,    37,    59,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    61,    55,    33,    60,    31,    55,
      55,   193,   196,   194,    60,   195,    62,    63,   197,    63,
      55,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    70,   275,    85,
     157,    87,    88,    89,   219,    91,    92,    93,    94,     3,
       4,     5,   206,   220,   226,   202,   332,   307,   378,    33,
      14,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    -1,    32,    33,
      34,    35,    36,    37,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    60,    -1,    62,    63,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    -1,
      -1,    85,    -1,    87,    88,    89,    -1,    91,    92,    93,
      94,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    41,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    -1,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    14,    -1,    -1,    67,    68,    -1,    70,    71,
      72,    73,    74,    75,    -1,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    91,
      92,    93,    94,    45,    46,    47,    48,    49,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,    14,
      62,    -1,    -1,    -1,    -1,    67,    68,    -1,    70,    71,
      72,    -1,    -1,    -1,    -1,    30,    78,    32,    33,    34,
      35,    36,    37,    -1,    39,    40,    -1,    42,    90,    -1,
      45,    46,    47,    48,    49,     3,     4,     5,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    60,    14,    62,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      85,     3,     4,     5,    -1,    -1,    -1,    45,    46,    47,
      48,    49,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    -1,    62,    -1,    -1,    -1,    -1,    67,
      68,    -1,    70,    71,    72,    -1,    -1,     3,     4,     5,
      78,    -1,    -1,    45,    46,    47,    48,    49,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    70,    71,
      72,    -1,    -1,     3,     4,     5,    78,    -1,    -1,    45,
      46,    47,    48,    49,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    -1,    70,    71,    72,    -1,    -1,     3,
       4,     5,    78,    -1,    -1,    45,    46,    47,    48,    49,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    62,    -1,    -1,    -1,    -1,    67,    68,    -1,
      70,    71,    72,    -1,    -1,     3,     4,     5,    78,    -1,
      -1,    45,    46,    47,    48,    49,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    70,    71,    72,    -1,
      -1,     3,     4,     5,    78,    -1,    -1,    45,    46,    47,
      48,    49,    14,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    -1,    70,    71,    72,    -1,    -1,     3,     4,     5,
      78,    -1,    -1,    45,    46,    47,    48,    49,    14,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    70,    71,
      72,    -1,    -1,     3,     4,     5,    78,    -1,    -1,    45,
      46,    47,    48,    49,    14,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,
      14,    67,    68,    -1,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    -1,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
      60,    45,    46,    47,    48,    49,    14,    67,    68,    -1,
      70,    71,    72,    -1,    -1,    -1,    60,    -1,    78,    -1,
      -1,    -1,    -1,    67,    68,    -1,    70,    71,    72,    26,
      27,    28,    29,    -1,    78,    -1,    -1,    45,    46,    47,
      48,    49,    -1,    -1,    41,    -1,    43,    44,    -1,    -1,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    67,
      68,    -1,    70,    71,    72,    -1,    26,    27,    28,    29,
      78,    -1,    -1,    -1,    -1,    -1,    73,    74,    75,    76,
      77,    41,    79,    80,    81,    82,    -1,    -1,    -1,    -1,
      87,    88,    89,    -1,    91,    92,    93,    94,    -1,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    26,    27,    28,    29,
      -1,    -1,    -1,    73,    74,    75,    -1,    77,    -1,    79,
      80,    41,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      -1,    91,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    -1,    77,    -1,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      -1,    91,    92,    93,    94
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    27,    28,    29,    41,    43,    44,    73,    74,
      75,    76,    77,    79,    80,    81,    82,    87,    88,    89,
      91,    92,    93,    94,   117,   118,   121,   122,   123,   124,
     130,   133,   134,   170,   171,   172,     4,    62,     4,    49,
      55,   119,   120,   135,   136,   137,   176,   118,   118,     4,
      62,   118,   118,     0,   171,    62,     4,   131,   132,    58,
     133,   137,   138,    54,    55,    15,     4,   136,    60,   177,
      62,   122,   125,   126,   127,   133,   131,    15,    54,    63,
       5,   133,   137,   120,     3,     4,     5,    14,    45,    46,
      47,    48,    49,    60,    62,    67,    68,    70,    71,    72,
      78,    96,    97,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   142,   149,
     150,   151,   122,   173,   174,   175,   125,   127,    63,   126,
      53,   128,   129,   135,   127,    54,    63,    99,   112,   116,
      63,   132,    59,    58,    60,    60,    99,    99,   113,   115,
     127,   139,    58,    90,   142,   143,   144,   145,   146,    60,
      60,    60,    60,    99,    47,    48,    90,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   114,   101,
      49,    50,    51,    45,    46,    64,    65,     6,     7,     8,
       9,    10,    11,    67,    52,    66,    12,    13,    56,   136,
     137,    61,   178,    54,    63,   116,    54,    55,    53,    63,
      58,   115,    61,    98,   113,   139,    54,    61,    58,    60,
     137,   140,   141,    61,   116,     4,    54,    63,   142,    15,
     146,   113,   113,     3,   139,     4,   113,   101,   101,   101,
     102,   102,   103,   103,   104,   104,   104,   104,   105,   105,
     106,   107,   108,   109,   110,   115,   136,    62,   154,   175,
     129,   116,     5,    59,    54,    61,    61,   113,    49,    59,
     113,    61,   140,   141,    58,    62,   101,    59,   142,   144,
      54,    61,    61,    61,    53,     4,    30,    32,    33,    34,
      35,    36,    37,    39,    40,    42,    55,    63,    69,    85,
     115,   117,   118,   147,   148,   152,   154,   155,   156,   157,
     158,   162,   164,   166,   169,    59,    58,   113,    59,    59,
      61,    49,    59,   113,   143,   142,   113,   112,    53,    60,
      55,    60,   116,    55,     4,    55,   115,    53,   153,    55,
     147,    55,    63,   156,    60,    60,   115,    59,    59,    63,
      61,   147,   115,   115,   153,    55,    55,   147,    33,   115,
     157,   168,    59,    61,   160,    61,   159,   147,    60,    61,
     165,   157,   167,   147,   147,   115,   147,    61,   115,   163,
      31,   161,    61,   163,   147,   147,    55,   147
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    95,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    97,    97,    97,    97,    97,    98,    98,
      99,    99,    99,    99,    99,    99,   100,   100,   100,   100,
     100,   100,   101,   101,   102,   102,   102,   102,   103,   103,
     103,   104,   104,   104,   105,   105,   105,   105,   105,   106,
     106,   106,   107,   107,   108,   108,   109,   109,   110,   110,
     111,   111,   112,   112,   113,   113,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   115,   115,   116,
     117,   117,   118,   118,   118,   118,   118,   118,   118,   118,
     119,   119,   120,   120,   121,   121,   121,   121,   121,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   123,   123,   123,   124,   124,   125,   125,   126,
     127,   127,   127,   127,   128,   128,   129,   129,   129,   130,
     130,   130,   130,   130,   131,   131,   132,   132,   133,   133,
     133,   134,   135,   135,   136,   136,   136,   137,   137,   137,
     137,   138,   138,   139,   139,   140,   140,   140,   141,   141,
     141,   141,   141,   141,   141,   141,   142,   142,   143,   143,
     143,   143,   144,   145,   145,   146,   146,   147,   147,   147,
     147,   147,   147,   147,   148,   149,   150,   151,   152,   152,
     152,   153,   154,   154,   155,   155,   156,   156,   157,   157,
     158,   158,   158,   159,   160,   161,   162,   162,   162,   162,
     163,   164,   165,   166,   167,   168,   169,   169,   169,   169,
     169,   170,   170,   171,   171,   172,   173,   173,   174,   174,
     175,   175,   176,   177,   178
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     3,     3,
       4,     4,     7,     1,     3,     2,     2,     6,     1,     3,
       1,     2,     2,     2,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     3,     1,     2,     1,     2,     1,     2,     1,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     4,     2,     1,     1,     1,     2,     3,
       2,     1,     2,     1,     1,     3,     1,     2,     3,     4,
       5,     5,     6,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     2,     1,     1,     4,     7,     1,     2,     2,
       3,     1,     2,     1,     2,     1,     1,     2,     3,     2,
       3,     3,     4,     3,     4,     2,     1,     3,     1,     2,
       3,     4,     2,     1,     2,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     6,     4,     3,     4,
       3,     1,     2,     3,     1,     2,     1,     1,     1,     2,
       5,     7,     5,     1,     1,     1,     5,     7,     6,     7,
       1,     1,     1,     1,     1,     1,     3,     2,     2,     2,
       3,     1,     2,     1,     1,     6,     0,     1,     1,     3,
       3,     2,     1,     1,     1
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
#line 212 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("IDENTIFIER");
        if(referenciando(*(yyvsp[0].string)))
        push(to_str(t->busca(*(yyvsp[0].string), &declarado)->endereco), 1);
        initialization_size = 1;
	}
#line 2143 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 218 "parser.y" /* yacc.c:1646  */
    {
		msg_sintatico("in_statement");
    }
#line 2151 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 221 "parser.y" /* yacc.c:1646  */
    {
        msg_sintatico("out_statement");
    }
#line 2159 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 224 "parser.y" /* yacc.c:1646  */
    {
        msg_sintatico("asm_statement");
    }
#line 2167 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 227 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("CONSTANT");
        push(*(yyvsp[0].string), 2); 
        initialization_size = 1;
	}
#line 2177 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 232 "parser.y" /* yacc.c:1646  */
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
#line 2193 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 243 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_PARENTESES expression FECHA_PARENTESES");
        /*
            NAO PRECISA FAZER NADA
        */
	}
#line 2204 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 249 "parser.y" /* yacc.c:1646  */
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
#line 2241 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 281 "parser.y" /* yacc.c:1646  */
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
#line 2284 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 319 "parser.y" /* yacc.c:1646  */
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
#line 2318 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 348 "parser.y" /* yacc.c:1646  */
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
#line 2358 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 386 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("primary_expression");
	}
#line 2366 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 389 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("postfix_expression PONTO IDENTIFIER");
	}
#line 2374 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 398 "parser.y" /* yacc.c:1646  */
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
#line 2391 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 410 "parser.y" /* yacc.c:1646  */
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
#line 2408 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 422 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_PARENTESES type_name FECHA_PARENTESES ABRE_CHAVES initializer_list FECHA_CHAVES");
	}
#line 2416 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 433 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("assignment_expression");
        arg_list.push_back(stack+1);
	}
#line 2425 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 437 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("argument_expression_list VIRGULA assignment_expression");
        arg_list.push_back(stack+1);
	}
#line 2434 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 444 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("postfix_expression");
	}
#line 2442 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 447 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("MAIS_MAIS unary_expression");
        if(!preProcessamento)
        cout<< "load r0, " << stack+1 << endl
            << "inc r0" << endl
            << "store " << stack+1 << endl;
	}
#line 2454 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 454 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("MENOS_MENOS unary_expression");
        if(!preProcessamento)
        cout<< "load r0, " << stack+1 << endl
            << "dec r0" << endl
            << "store " << stack+1 << endl;
	}
#line 2466 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 461 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("unary_operator cast_expression");

        if(!preProcessamento && t->getEscopo() > 0 || preProcessamento && t->getEscopo() ==0)
        switch(operacao) {
            case ampersand:
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
                if(!flag_assignment){
                    flag_ponteiro_assignment = 1;
                    flag_assignment =0;
                    cout<< "load r0, " << stack+1 << endl
                        << "store " << stack+1 << ", r0" << endl;
                }else{
                    cout<< "load r0, " << stack+1 << endl
                        << "loadi r1, r0" << endl
                        << "store " << stack+1 << ", r1" << endl;
                }
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
#line 2526 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 516 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("SIZEOF unary_expression");
	}
#line 2534 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 519 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("SIZEOF ABRE_PARENTESES type_name FECHA_PARENTESES");
	}
#line 2542 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 525 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("AMPERSAND");
        operacao = ampersand;
	}
#line 2551 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 529 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ASTERISCO2");
        operacao = asterisco;
	}
#line 2560 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 533 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("MAIS");
	}
#line 2568 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 536 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("MENOS");
        operacao = menos;
	}
#line 2577 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 540 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("TIL");
	}
#line 2585 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 543 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("EXCLAMACAO");
        operacao = exclamacao;
	}
#line 2594 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 550 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("unary_expression");
	}
#line 2602 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 553 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_PARENTESES type_name FECHA_PARENTESES cast_expression");
	}
#line 2610 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 559 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("cast_expression");
	}
#line 2618 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 562 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("multiplicative_expression ASTERISCO cast_expression");
        expressao_binaria('*'); 
	}
#line 2627 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 566 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("multiplicative_expression BARRA cast_expression");
        expressao_binaria('/'); 
	}
#line 2636 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 570 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("multiplicative_expression '' cast_expression");
        expressao_binaria('%'); 
	}
#line 2645 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 577 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("multiplicative_expression");
	}
#line 2653 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 580 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("additive_expression MAIS multiplicative_expression");
        expressao_binaria('+'); 
	}
#line 2662 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 584 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("additive_expression MENOS multiplicative_expression");
        expressao_binaria('-'); 
	}
#line 2671 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 591 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("additive_expression");
	}
#line 2679 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 594 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("shift_expression MENOR_MENOR additive_expression");
        expressao_binaria('l'); 
	}
#line 2688 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 598 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("shift_expression MAIOR_MAIOR additive_expression");
        expressao_binaria('r'); 
	}
#line 2697 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 605 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("shift_expression");
	}
#line 2705 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 608 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("relational_expression MENOR shift_expression");
        relacao_binaria('<');
	}
#line 2714 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 612 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("relational_expression MAIOR shift_expression");
        relacao_binaria('>');
	}
#line 2723 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 616 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("relational_expression MENOR_IGUAL shift_expression");
        relacao_binaria('m');
	}
#line 2732 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 620 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("relational_expression MAIOR_IGUAL shift_expression");
        relacao_binaria('M');
	}
#line 2741 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 627 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("relational_expression");
	}
#line 2749 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 630 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("equality_expression IGUAL_IGUAL relational_expression");
        relacao_binaria('=');
	}
#line 2758 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 634 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("equality_expression EXCLAMACAO_IGUAL relational_expression");
        relacao_binaria('!');
	}
#line 2767 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 641 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("equality_expression");
	}
#line 2775 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 644 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("and_expression AMPERSAND equality_expression");
        expressao_binaria('&'); 
	}
#line 2784 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 651 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("and_expression");
	}
#line 2792 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 654 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("exclusive_or_expression CIRCUNFLEXO and_expression");
        expressao_binaria('^'); 
	}
#line 2801 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 661 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("exclusive_or_expression");
	}
#line 2809 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 664 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("inclusive_or_expression PIPE exclusive_or_expression");
        expressao_binaria('|'); 
	}
#line 2818 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 671 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("inclusive_or_expression");
	}
#line 2826 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 674 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("logical_and_expression AMPERSAND_AMPERSAND inclusive_or_expression");
        relacao_binaria('e');
	}
#line 2835 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 681 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("logical_and_expression");
	}
#line 2843 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 684 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("logical_or_expression PIPE_PIPE logical_and_expression");
        relacao_binaria('o');
	}
#line 2852 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 691 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("logical_or_expression");
	}
#line 2860 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 694 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("logical_or_expression INTERROGACAO expression DOIS_PONTOS conditional_expression");
        relacao_binaria('?');
	}
#line 2869 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 701 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("conditional_expression");
	}
#line 2877 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 704 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("unary_expression assignment_operator assignment_expression");
        if(!preProcessamento && t->getEscopo() > 0 || preProcessamento && t->getEscopo() ==0) {
            if(debug_instrucao)
                cout<< "; assignment salvando no endereco apontado por: " << t->buscaEndereco(stack+2) << "(" << stack+2 << ") o conteudo de " 
                    << t->buscaEndereco(stack+1) << "(" << stack+1 << ")" << endl;
            flag_assignment = 1;
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
            if(flag_ponteiro_assignment){
                flag_ponteiro_assignment = 0;
                cout << ";Assignment ponteiro" <<endl; 
                cout << "load r7, " << mapa[stack+2] <<endl;
                cout << "storei r7, r0 ; endereco apontado por r7 recebe o conteudo de r0" << endl << endl; 
                mapa[stack+2] = -1;
            }else{
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
            }
            stack = stack+2;  
        }
	}
#line 2955 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 780 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("IGUAL");
        atribuicao = eq;
	}
#line 2964 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 784 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ASTERISCO_IGUAL");
        atribuicao = mul_eq;
	}
#line 2973 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 788 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("BARRA_IGUAL");
        atribuicao = div_eq;
	}
#line 2982 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 792 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("PORCENTAGEM_IGUAL");
        atribuicao = mod_eq;
	}
#line 2991 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 796 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("MAIS_IGUAL");
        atribuicao = add_eq;
	}
#line 3000 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 800 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("MENOS_IGUAL");
        atribuicao = sub_eq;
	}
#line 3009 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 804 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("MENOR_MENOR_IGUAL");
        atribuicao = dec_eq;
	}
#line 3018 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 808 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("MAIOR_MAIOR_IGUAL");
        atribuicao = inc_eq;
	}
#line 3027 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 812 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("AMPERSAND_IGUAL");
        atribuicao = land_eq;
	}
#line 3036 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 816 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("CIRCUNFLEXO_IGUAL");
        atribuicao = lxor_eq;
	}
#line 3045 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 820 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("PIPE_IGUAL");
        atribuicao = lor_eq;
	}
#line 3054 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 827 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("assignment_expression");
	}
#line 3062 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 830 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("expression VIRGULA assignment_expression");
	}
#line 3070 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 836 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("conditional_expression");
	}
#line 3078 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 842 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("declaration_specifiers PONTO_VIRGULA");
	}
#line 3086 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 845 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("declaration_specifiers init_declarator_list PONTO_VIRGULA");
	}
#line 3094 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 851 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("storage_class_specifier");
	}
#line 3102 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 854 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("storage_class_specifier declaration_specifiers");
	}
#line 3110 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 857 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("type_specifier");
	}
#line 3118 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 860 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("type_specifier declaration_specifiers");
	}
#line 3126 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 863 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("type_qualifier");
	}
#line 3134 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 866 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("type_qualifier declaration_specifiers");
	}
#line 3142 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 869 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("function_specifier");
	}
#line 3150 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 872 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("function_specifier declaration_specifiers");
	}
#line 3158 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 878 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("init_declarator");
	}
#line 3166 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 881 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("init_declarator_list VIRGULA init_declarator");
	}
#line 3174 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 887 "parser.y" /* yacc.c:1646  */
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
#line 3189 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 897 "parser.y" /* yacc.c:1646  */
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
#line 3222 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 928 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("TYPEDEF");
	}
#line 3230 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 931 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("EXTERN");
	}
#line 3238 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 934 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("STATIC");
	}
#line 3246 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 937 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("AUTO");
	}
#line 3254 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 940 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("REGISTER");
	}
#line 3262 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 946 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("VOID");
        salva_tipo("void");
	}
#line 3271 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 950 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("CHAR");
        salva_tipo("char");
	}
#line 3280 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 954 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("SHORT");
        salva_tipo("short");
	}
#line 3289 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 958 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("INT");
        salva_tipo("int");
	}
#line 3298 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 962 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("LONG");
        salva_tipo("long");
	}
#line 3307 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 966 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("FLOAT");
        salva_tipo("long");
	}
#line 3316 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 970 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("DOUBLE");
        salva_tipo("double");
	}
#line 3325 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 974 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("SIGNED");
	}
#line 3333 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 977 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("UNSIGNED");
	}
#line 3341 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 980 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("BOOL");
        salva_tipo("bool");
	}
#line 3350 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 984 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("struct_or_union_specifier");
	}
#line 3358 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 987 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("enum_specifier");
	}
#line 3366 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 990 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("TYPE_NAME");
	}
#line 3374 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 996 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("struct_or_union IDENTIFIER ABRE_CHAVES struct_declaration_list FECHA_CHAVES");
	}
#line 3382 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 999 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("struct_or_union ABRE_CHAVES struct_declaration_list FECHA_CHAVES");
	}
#line 3390 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1002 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("struct_or_union IDENTIFIER");
	}
#line 3398 "parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1008 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("STRUCT");
	}
#line 3406 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1011 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("UNION");
	}
#line 3414 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1017 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("struct_declaration");
	}
#line 3422 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1020 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("struct_declaration_list struct_declaration");
	}
#line 3430 "parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1026 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("specifier_qualifier_list struct_declarator_list PONTO_VIRGULA");
	}
#line 3438 "parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1032 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("type_specifier specifier_qualifier_list");
	}
#line 3446 "parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1035 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("type_specifier");
	}
#line 3454 "parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1038 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("type_qualifier specifier_qualifier_list");
	}
#line 3462 "parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1041 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("type_qualifier");
	}
#line 3470 "parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1047 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("struct_declarator");
	}
#line 3478 "parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1050 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("struct_declarator_list VIRGULA struct_declarator");
	}
#line 3486 "parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1056 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("declarator");
	}
#line 3494 "parser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1059 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("DOIS_PONTOS constant_expression");
	}
#line 3502 "parser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1062 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("declarator DOIS_PONTOS constant_expression");
	}
#line 3510 "parser.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1068 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ENUM ABRE_CHAVES enumerator_list FECHA_CHAVES");
	}
#line 3518 "parser.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1071 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ENUM IDENTIFIER ABRE_CHAVES enumerator_list FECHA_CHAVES");
	}
#line 3526 "parser.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1074 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ENUM ABRE_CHAVES enumerator_list VIRGULA FECHA_CHAVES");
	}
#line 3534 "parser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1077 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ENUM IDENTIFIER ABRE_CHAVES enumerator_list VIRGULA FECHA_CHAVES");
	}
#line 3542 "parser.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1080 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ENUM IDENTIFIER");
	}
#line 3550 "parser.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1086 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("enumerator");
	}
#line 3558 "parser.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1089 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("enumerator_list VIRGULA enumerator");
	}
#line 3566 "parser.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1095 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("IDENTIFIER");
	}
#line 3574 "parser.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1098 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("IDENTIFIER IGUAL constant_expression");
	}
#line 3582 "parser.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1104 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("CONST");
	}
#line 3590 "parser.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1107 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("RESTRICT");
	}
#line 3598 "parser.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1110 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("VOLATILE");
	}
#line 3606 "parser.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1116 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("INLINE");
	}
#line 3614 "parser.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1122 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("pointer direct_declarator");
	}
#line 3622 "parser.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1125 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("direct_declarator");
	}
#line 3630 "parser.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1134 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("IDENTIFIER");
        declara_variaveis_e_parametros(*(yyvsp[0].string), 1);
        salva_identificador = *(yyvsp[0].string); 
	}
#line 3640 "parser.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1139 "parser.y" /* yacc.c:1646  */
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
#line 3665 "parser.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1159 "parser.y" /* yacc.c:1646  */
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
#line 3703 "parser.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1203 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ASTERISCO");
	}
#line 3711 "parser.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1206 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ASTERISCO type_qualifier_list");
	}
#line 3719 "parser.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 1209 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ASTERISCO pointer");
	}
#line 3727 "parser.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 1212 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ASTERISCO type_qualifier_list pointer");
	}
#line 3735 "parser.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 1218 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("type_qualifier");
	}
#line 3743 "parser.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 1221 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("type_qualifier_list type_qualifier");
	}
#line 3751 "parser.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 1227 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("specifier_qualifier_list");
	}
#line 3759 "parser.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 1230 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("specifier_qualifier_list abstract_declarator");
	}
#line 3767 "parser.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 1236 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("pointer");
	}
#line 3775 "parser.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 1239 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("direct_abstract_declarator");
	}
#line 3783 "parser.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 1242 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("pointer direct_abstract_declarator");
	}
#line 3791 "parser.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 1248 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_PARENTESES abstract_declarator FECHA_PARENTESES");
	}
#line 3799 "parser.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 1251 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_COLCHETES FECHA_COLCHETES");
	}
#line 3807 "parser.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 1254 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_COLCHETES assignment_expression FECHA_COLCHETES");
	}
#line 3815 "parser.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 1257 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("direct_abstract_declarator ABRE_COLCHETES FECHA_COLCHETES");
	}
#line 3823 "parser.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 1260 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("direct_abstract_declarator ABRE_COLCHETES assignment_expression FECHA_COLCHETES");
	}
#line 3831 "parser.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 1263 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_COLCHETES ASTERISCO FECHA_COLCHETES");
	}
#line 3839 "parser.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 1266 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("direct_abstract_declarator ABRE_COLCHETES ASTERISCO FECHA_COLCHETES");
	}
#line 3847 "parser.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 1269 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_PARENTESES FECHA_PARENTESES");
	}
#line 3855 "parser.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 1275 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("assignment_expression");
        if(initialization_size == 1)
            initializer_list.push_back(stack+1);
        else if(initialization_size > 1)
            initializer_list.push_back(stack+initialization_size);
	}
#line 3867 "parser.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 1282 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_CHAVES initializer_list FECHA_CHAVES");
	}
#line 3875 "parser.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 1288 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("initializer");
	}
#line 3883 "parser.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 1291 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("designation initializer");
	}
#line 3891 "parser.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 1294 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("initializer_list VIRGULA initializer");
	}
#line 3899 "parser.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 1297 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("initializer_list VIRGULA designation initializer");
	}
#line 3907 "parser.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 1303 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("designator_list IGUAL");
	}
#line 3915 "parser.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 1309 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("designator");
	}
#line 3923 "parser.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 1312 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("designator_list designator");
	}
#line 3931 "parser.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 1318 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_COLCHETES constant_expression FECHA_COLCHETES");
	}
#line 3939 "parser.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 1321 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("PONTO IDENTIFIER");
	}
#line 3947 "parser.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 1327 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("labeled_statement");
	}
#line 3955 "parser.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 1330 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("compound_statement");
	}
#line 3963 "parser.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 1333 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("expression_statement");
	}
#line 3971 "parser.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 1336 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("selection_statement");
	}
#line 3979 "parser.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 1339 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("iteration_statement");
	}
#line 3987 "parser.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 1342 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("jump_statement");
	}
#line 3995 "parser.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 1345 "parser.y" /* yacc.c:1646  */
    {
		msg_sintatico("breakp_statement");
    }
#line 4003 "parser.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 1351 "parser.y" /* yacc.c:1646  */
    {
        msg_sintatico("breakp_statement breakp");
        if(!preProcessamento)
        cout << "breakp" << endl; 
    }
#line 4013 "parser.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 1359 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("breakp in abre_parenteses primary_expression virgula primary_expression fecha_parenteses");
        if(!preProcessamento) {
            cout << "load r1, " << stack+1 << endl;
            cout << "in r0, r1" << endl; 
            cout << "store " << stack+1 << ", r0" << endl;
         
        }
    }
#line 4027 "parser.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 1371 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("breakp in abre_parenteses primary_expression virgula primary_expression fecha_parenteses");
        if(!preProcessamento) {
            cout << "load r0, " << stack+2 << endl;
            cout << "load r1, " << stack+1 << endl;
            cout << "out r0, r1" << endl; 
        }
    }
#line 4040 "parser.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 1382 "parser.y" /* yacc.c:1646  */
    { 
        if(!preProcessamento) {
            cout << *(yyvsp[-1].string) <<endl;
        }
    }
#line 4050 "parser.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 1390 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("IDENTIFIER DOIS_PONTOS statement");
	}
#line 4058 "parser.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 1393 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("CASE constant_expression DOIS_PONTOS statement");
        cout << "; labeled_statement case, zerou" << endl;
        insideCase = 0;
        cout<< "jmp __label_statement_" << statement_seq+1 << "__" << endl;
	}
#line 4069 "parser.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 1399 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("DEFAULT DOIS_PONTOS statement");
        cout << "; labeled_statement default, zerou" << endl;
        insideCase = 0;
	}
#line 4079 "parser.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 1407 "parser.y" /* yacc.c:1646  */
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
#line 4099 "parser.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 1425 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_CHAVES FECHA_CHAVES");
	}
#line 4107 "parser.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 1428 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("ABRE_CHAVES block_item_list FECHA_CHAVES");
	}
#line 4115 "parser.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 1434 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("block_item");
	}
#line 4123 "parser.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 1437 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("block_item_list block_item");
	}
#line 4131 "parser.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 1443 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("declaration");
	}
#line 4139 "parser.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 1446 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("statement");
	}
#line 4147 "parser.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 1452 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("PONTO_VIRGULA");
	}
#line 4155 "parser.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 1455 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("expression PONTO_VIRGULA");
	}
#line 4163 "parser.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 1461 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("IF ABRE_PARENTESES expression FECHA_PARENTESES statement");
        if(!preProcessamento) {
            cout << "__exit_if_label" << if_stack.back() << "__:" << endl; 
            if_stack.pop_back();
        }
	}
#line 4175 "parser.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 1468 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("IF ABRE_PARENTESES expression FECHA_PARENTESES statement ELSE statement");
        if(!preProcessamento) {
            cout << "__exit_else_label" << if_stack.back() << "__:" << endl; 
            if_stack.pop_back();
        }
	}
#line 4187 "parser.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 1475 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("SWITCH ABRE_PARENTESES expression FECHA_PARENTESES statement");
        insideSwitch--;
        if(switch_stack.back() == 1)
            switch_stack.pop_back();
        else
            errorMsg("switch stack esta errada");
        switch_seq++;
	}
#line 4201 "parser.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 1487 "parser.y" /* yacc.c:1646  */
    {
        if(!preProcessamento)
            cout<< "load r0, " << stack+1 << endl;
        insideSwitch++;
        switch_stack.push_back(1);
    }
#line 4212 "parser.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 1496 "parser.y" /* yacc.c:1646  */
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
#line 4232 "parser.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 1514 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("begin_else else");
        if(!preProcessamento) {
            cout << "jmp __exit_else_label" << if_stack.back() << "__" << endl; 
            cout << "__exit_if_label" << if_stack.back() << "__:" << endl;
        }
    }
#line 4244 "parser.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 1524 "parser.y" /* yacc.c:1646  */
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
#line 4263 "parser.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 1538 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("DO statement WHILE ABRE_PARENTESES expression FECHA_PARENTESES PONTO_VIRGULA");
        errorMsg("do while nao e' suportado nesta versao");
	}
#line 4272 "parser.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 1542 "parser.y" /* yacc.c:1646  */
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
#line 4291 "parser.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 1556 "parser.y" /* yacc.c:1646  */
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
#line 4310 "parser.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 1573 "parser.y" /* yacc.c:1646  */
    { 
        if(!preProcessamento) {
        cout << "jmp __loop_label_begin"<< loop_stack.back() << "__" << endl;
        cout << "__loop_label3_begin" << loop_stack.back() << "__:" << endl;
        }
    }
#line 4321 "parser.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 1582 "parser.y" /* yacc.c:1646  */
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
#line 4336 "parser.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 1595 "parser.y" /* yacc.c:1646  */
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
#line 4353 "parser.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 1610 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("begin_for for");
            insideLoop++;
            if(!preProcessamento && debug_instrucao)
                cout << ";----- begin for -----" << endl;
        switch_stack.push_back(2);
        loop_stack.push_back(loopseq);
        loopseq++;
    }
#line 4367 "parser.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 1622 "parser.y" /* yacc.c:1646  */
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
#line 4385 "parser.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 1638 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("begin_labeled4 expression_statement");
        if(!preProcessamento)
            cout << "__loop_label_begin" << loop_stack.back() << "__:" << endl; 
    }
#line 4395 "parser.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 1646 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("GOTO IDENTIFIER PONTO_VIRGULA");
        checa_label(*(yyvsp[-1].string)); 
        if(!preProcessamento && debug_sintatico) 
            cout << "jump_statement: IDENTIFIER " << *(yyvsp[-1].string) << endl; 
	}
#line 4406 "parser.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 1652 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("CONTINUE PONTO_VIRGULA");
        if(insideLoop == 0) { 
            errorMsg("continue fora de loop"); 
        } 
        if(!preProcessamento)
        cout << "jmp __loop_label_begin"<< loop_stack.back() << "__" << endl;
	}
#line 4419 "parser.cpp" /* yacc.c:1646  */
    break;

  case 218:
#line 1660 "parser.y" /* yacc.c:1646  */
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
#line 4436 "parser.cpp" /* yacc.c:1646  */
    break;

  case 219:
#line 1672 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("RETURN PONTO_VIRGULA");
        if(!preProcessamento && f->nome != "main") {
            cout << "rts" << endl;
        }
        else if(!preProcessamento && f->nome == "main") {
            cout << "breakp" << endl;
        }
	}
#line 4450 "parser.cpp" /* yacc.c:1646  */
    break;

  case 220:
#line 1681 "parser.y" /* yacc.c:1646  */
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
#line 4468 "parser.cpp" /* yacc.c:1646  */
    break;

  case 221:
#line 1697 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("external_declaration");
	}
#line 4476 "parser.cpp" /* yacc.c:1646  */
    break;

  case 222:
#line 1700 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("translation_unit external_declaration");
	}
#line 4484 "parser.cpp" /* yacc.c:1646  */
    break;

  case 223:
#line 1706 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("function_definition");
	}
#line 4492 "parser.cpp" /* yacc.c:1646  */
    break;

  case 224:
#line 1709 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("declaration");
	}
#line 4500 "parser.cpp" /* yacc.c:1646  */
    break;

  case 225:
#line 1715 "parser.y" /* yacc.c:1646  */
    { 
		msg_sintatico("declaration_specifiers declarator compound_statement");
        function_definition();
	}
#line 4509 "parser.cpp" /* yacc.c:1646  */
    break;

  case 227:
#line 1722 "parser.y" /* yacc.c:1646  */
    {
        msg_sintatico("opt_parametros parameter_list");
    }
#line 4517 "parser.cpp" /* yacc.c:1646  */
    break;

  case 228:
#line 1728 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("parameter_list parameter_declaration");
    }
#line 4525 "parser.cpp" /* yacc.c:1646  */
    break;

  case 229:
#line 1731 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("parameter_list parameter_list VIRGULA parameter_declaration");
    }
#line 4533 "parser.cpp" /* yacc.c:1646  */
    break;

  case 230:
#line 1737 "parser.y" /* yacc.c:1646  */
    { 
        flag_ponteiro = -1; 
        msg_sintatico("parameter_declaration type_specifier pointer direct_declarator");
    }
#line 4542 "parser.cpp" /* yacc.c:1646  */
    break;

  case 231:
#line 1741 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("parameter_declaration type_specifier direct_declarator");
    }
#line 4550 "parser.cpp" /* yacc.c:1646  */
    break;

  case 232:
#line 1747 "parser.y" /* yacc.c:1646  */
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
#line 4569 "parser.cpp" /* yacc.c:1646  */
    break;

  case 233:
#line 1764 "parser.y" /* yacc.c:1646  */
    { 
        msg_sintatico("begin_parametro ABRE_PARENTESES");

        begin_parametro = true; 
        if(!preProcessamento) {
            msg_instrucao("; declarando funcao: " + f->nome);
            cout << "__function_label_" << f->nome << "__:" << endl;
        }
    }
#line 4583 "parser.cpp" /* yacc.c:1646  */
    break;

  case 234:
#line 1776 "parser.y" /* yacc.c:1646  */
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
#line 4607 "parser.cpp" /* yacc.c:1646  */
    break;


#line 4611 "parser.cpp" /* yacc.c:1646  */
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
#line 1797 "parser.y" /* yacc.c:1906  */


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

                if(!value.compare("-1")){
                    cout << "loadn r0, " << "#__function_label_"<< t->buscaEndereco(atoi(value.c_str())) << "__" << endl 
                         << "store " << stack << ", r0" << endl << endl;
                    
                    stack_ampersand = atoi(value.c_str());

                    mapa[stack] = atoi(value.c_str());
                }else{
                    cout << "load r0, " << value << endl 
                         << "store " << stack << ", r0" << endl << endl;
                    stack_ampersand = atoi(value.c_str());

                    mapa[stack] = atoi(value.c_str());
                }
                break;

            case 2: // valor constante numero

                if(!value.compare("-1")) break;
                if(debug_instrucao) 
                    cout << "; " << t->buscaEndereco(stack) << "(" << stack << ") constante recebe o conteudo: " << value << endl; 
                cout << "loadn r0, #" << value << endl 
                     << "store " << stack << ", r0" << endl << endl;

                mapa[stack] = -1;
                break;

            case 3: // valor constante caracter
                if(debug_instrucao) 
                    cout << "; " << t->buscaEndereco(stack) << "(" << stack << ") caracter recebe o conteudo: " << value << endl; 
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


