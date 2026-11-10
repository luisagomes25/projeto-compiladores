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
     TOKEN_TIPO_TOTAL = 266,
     TOKEN_TIPO_FRACAO = 267,
     TOKEN_TIPO_SINAL = 268,
     TOKEN_TIPO_TEXTAO = 269,
     TOKEN_TIPO_SERMAO = 270,
     TOKEN_FIEL = 271,
     TOKEN_FATAL = 272,
     TOKEN_TERMINADOR = 273,
     TOKEN_DOIS_PONTOS = 274,
     TOKEN_ATRIBUICAO = 275,
     TOKEN_SOMA = 276,
     TOKEN_SUBTRACAO = 277,
     TOKEN_MULTIPLICACAO = 278,
     TOKEN_DIVISAO = 279,
     TOKEN_PAREN_ESQ = 280,
     TOKEN_PAREN_DIR = 281,
     TOKEN_MAIOR = 282,
     TOKEN_MENOR = 283,
     TOKEN_MAIOR_IGUAL = 284,
     TOKEN_MENOR_IGUAL = 285,
     TOKEN_IGUALDADE = 286,
     TOKEN_DIFERENTE = 287,
     TOKEN_VIRGULA = 288,
     TOKEN_ID = 289,
     TOKEN_NUM_TOTAL = 290,
     TOKEN_NUM_FRACAO = 291,
     TOKEN_TEXTO = 292
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
#define TOKEN_TIPO_TOTAL 266
#define TOKEN_TIPO_FRACAO 267
#define TOKEN_TIPO_SINAL 268
#define TOKEN_TIPO_TEXTAO 269
#define TOKEN_TIPO_SERMAO 270
#define TOKEN_FIEL 271
#define TOKEN_FATAL 272
#define TOKEN_TERMINADOR 273
#define TOKEN_DOIS_PONTOS 274
#define TOKEN_ATRIBUICAO 275
#define TOKEN_SOMA 276
#define TOKEN_SUBTRACAO 277
#define TOKEN_MULTIPLICACAO 278
#define TOKEN_DIVISAO 279
#define TOKEN_PAREN_ESQ 280
#define TOKEN_PAREN_DIR 281
#define TOKEN_MAIOR 282
#define TOKEN_MENOR 283
#define TOKEN_MAIOR_IGUAL 284
#define TOKEN_MENOR_IGUAL 285
#define TOKEN_IGUALDADE 286
#define TOKEN_DIFERENTE 287
#define TOKEN_VIRGULA 288
#define TOKEN_ID 289
#define TOKEN_NUM_TOTAL 290
#define TOKEN_NUM_FRACAO 291
#define TOKEN_TEXTO 292




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

