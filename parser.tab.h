/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_GUARDE = 258,            /* TOKEN_GUARDE  */
    TOKEN_TESTAR = 259,            /* TOKEN_TESTAR  */
    TOKEN_SENAO = 260,             /* TOKEN_SENAO  */
    TOKEN_REPETIR = 261,           /* TOKEN_REPETIR  */
    TOKEN_ABRIR = 262,             /* TOKEN_ABRIR  */
    TOKEN_FECHAR = 263,            /* TOKEN_FECHAR  */
    TOKEN_EXIBIR = 264,            /* TOKEN_EXIBIR  */
    TOKEN_OBTER = 265,             /* TOKEN_OBTER  */
    TOKEN_TIPO_TOTAL = 266,        /* TOKEN_TIPO_TOTAL  */
    TOKEN_TIPO_FRACAO = 267,       /* TOKEN_TIPO_FRACAO  */
    TOKEN_TIPO_SINAL = 268,        /* TOKEN_TIPO_SINAL  */
    TOKEN_TIPO_TEXTAO = 269,       /* TOKEN_TIPO_TEXTAO  */
    TOKEN_TIPO_SERMAO = 270,       /* TOKEN_TIPO_SERMAO  */
    TOKEN_FIEL = 271,              /* TOKEN_FIEL  */
    TOKEN_FATAL = 272,             /* TOKEN_FATAL  */
    TOKEN_TERMINADOR = 273,        /* TOKEN_TERMINADOR  */
    TOKEN_DOIS_PONTOS = 274,       /* TOKEN_DOIS_PONTOS  */
    TOKEN_ATRIBUICAO = 275,        /* TOKEN_ATRIBUICAO  */
    TOKEN_SOMA = 276,              /* TOKEN_SOMA  */
    TOKEN_SUBTRACAO = 277,         /* TOKEN_SUBTRACAO  */
    TOKEN_MULTIPLICACAO = 278,     /* TOKEN_MULTIPLICACAO  */
    TOKEN_DIVISAO = 279,           /* TOKEN_DIVISAO  */
    TOKEN_PAREN_ESQ = 280,         /* TOKEN_PAREN_ESQ  */
    TOKEN_PAREN_DIR = 281,         /* TOKEN_PAREN_DIR  */
    TOKEN_MAIOR = 282,             /* TOKEN_MAIOR  */
    TOKEN_MENOR = 283,             /* TOKEN_MENOR  */
    TOKEN_MAIOR_IGUAL = 284,       /* TOKEN_MAIOR_IGUAL  */
    TOKEN_MENOR_IGUAL = 285,       /* TOKEN_MENOR_IGUAL  */
    TOKEN_IGUALDADE = 286,         /* TOKEN_IGUALDADE  */
    TOKEN_DIFERENTE = 287,         /* TOKEN_DIFERENTE  */
    TOKEN_VIRGULA = 288,           /* TOKEN_VIRGULA  */
    TOKEN_ID = 289,                /* TOKEN_ID  */
    TOKEN_NUM_TOTAL = 290,         /* TOKEN_NUM_TOTAL  */
    TOKEN_NUM_FRACAO = 291,        /* TOKEN_NUM_FRACAO  */
    TOKEN_TEXTO = 292              /* TOKEN_TEXTO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
