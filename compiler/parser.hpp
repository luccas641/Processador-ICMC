/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 136 "parser.y" /* yacc.c:1909  */

    int token;
    std::string *string;

#line 153 "parser.hpp" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
