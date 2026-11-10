/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_GUARDE = 258,
     TOKEN_TESTAR = 259,
     TOKEN_SENAO = 260,
     TOKEN_REPETIR = 261,
     TOKEN_ABRIR = 262,
     TOKEN_FECHAR = 263,
     TOKEN_EXIBIR = 264,
     TOKEN_OBTER = 265,
     TOKEN_PARAR = 266,
     TOKEN_PULAR = 267,
     TOKEN_FUNCAO = 268,
     TOKEN_VOLTAR = 269,
     TOKEN_SERMAO = 270,
     TOKEN_TIPO_TOTAL = 271,
     TOKEN_TIPO_FRACAO = 272,
     TOKEN_TIPO_SINAL = 273,
     TOKEN_TIPO_TEXTAO = 274,
     TOKEN_FIEL = 275,
     TOKEN_FATAL = 276,
     TOKEN_E = 277,
     TOKEN_OU = 278,
     TOKEN_NAO = 279,
     TOKEN_TERMINADOR = 280,
     TOKEN_DOIS_PONTOS = 281,
     TOKEN_ATRIBUICAO = 282,
     TOKEN_SOMA = 283,
     TOKEN_SUBTRACAO = 284,
     TOKEN_MULTIPLICACAO = 285,
     TOKEN_DIVISAO = 286,
     TOKEN_MODULO = 287,
     TOKEN_PAREN_ESQ = 288,
     TOKEN_PAREN_DIR = 289,
     TOKEN_MAIOR = 290,
     TOKEN_MENOR = 291,
     TOKEN_MAIOR_IGUAL = 292,
     TOKEN_MENOR_IGUAL = 293,
     TOKEN_IGUALDADE = 294,
     TOKEN_DIFERENTE = 295,
     TOKEN_VIRGULA = 296,
     TOKEN_ERRO = 297,
     TOKEN_ID = 298,
     TOKEN_TEXTO = 299,
     TOKEN_NUM_TOTAL = 300,
     TOKEN_NUM_FRACAO = 301,
     UMINUS = 302
   };
#endif
/* Tokens.  */
#define TOKEN_GUARDE 258
#define TOKEN_TESTAR 259
#define TOKEN_SENAO 260
#define TOKEN_REPETIR 261
#define TOKEN_ABRIR 262
#define TOKEN_FECHAR 263
#define TOKEN_EXIBIR 264
#define TOKEN_OBTER 265
#define TOKEN_PARAR 266
#define TOKEN_PULAR 267
#define TOKEN_FUNCAO 268
#define TOKEN_VOLTAR 269
#define TOKEN_SERMAO 270
#define TOKEN_TIPO_TOTAL 271
#define TOKEN_TIPO_FRACAO 272
#define TOKEN_TIPO_SINAL 273
#define TOKEN_TIPO_TEXTAO 274
#define TOKEN_FIEL 275
#define TOKEN_FATAL 276
#define TOKEN_E 277
#define TOKEN_OU 278
#define TOKEN_NAO 279
#define TOKEN_TERMINADOR 280
#define TOKEN_DOIS_PONTOS 281
#define TOKEN_ATRIBUICAO 282
#define TOKEN_SOMA 283
#define TOKEN_SUBTRACAO 284
#define TOKEN_MULTIPLICACAO 285
#define TOKEN_DIVISAO 286
#define TOKEN_MODULO 287
#define TOKEN_PAREN_ESQ 288
#define TOKEN_PAREN_DIR 289
#define TOKEN_MAIOR 290
#define TOKEN_MENOR 291
#define TOKEN_MAIOR_IGUAL 292
#define TOKEN_MENOR_IGUAL 293
#define TOKEN_IGUALDADE 294
#define TOKEN_DIFERENTE 295
#define TOKEN_VIRGULA 296
#define TOKEN_ERRO 297
#define TOKEN_ID 298
#define TOKEN_TEXTO 299
#define TOKEN_NUM_TOTAL 300
#define TOKEN_NUM_FRACAO 301
#define UMINUS 302




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 15 "parser.y"
{
    double numero;
    char *texto;
    TipoDado tipo;
    NoExpressao *expressao;
    NoAST *comando;
    NoBloco *bloco;
    std::vector<NoAST*> *comandos;
    std::vector<NoExpressao*> *argumentos;
}
/* Line 1529 of yacc.c.  */
#line 154 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

