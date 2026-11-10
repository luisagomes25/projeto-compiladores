/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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
     TOKEN_TIPO_VAZIO = 275,
     TOKEN_FIEL = 276,
     TOKEN_FATAL = 277,
     TOKEN_E = 278,
     TOKEN_OU = 279,
     TOKEN_NAO = 280,
     TOKEN_TERMINADOR = 281,
     TOKEN_DOIS_PONTOS = 282,
     TOKEN_ATRIBUICAO = 283,
     TOKEN_SOMA = 284,
     TOKEN_SUBTRACAO = 285,
     TOKEN_MULTIPLICACAO = 286,
     TOKEN_DIVISAO = 287,
     TOKEN_MODULO = 288,
     TOKEN_PAREN_ESQ = 289,
     TOKEN_PAREN_DIR = 290,
     TOKEN_MAIOR = 291,
     TOKEN_MENOR = 292,
     TOKEN_MAIOR_IGUAL = 293,
     TOKEN_MENOR_IGUAL = 294,
     TOKEN_IGUALDADE = 295,
     TOKEN_DIFERENTE = 296,
     TOKEN_VIRGULA = 297,
     TOKEN_ERRO = 298,
     TOKEN_ID = 299,
     TOKEN_TEXTO = 300,
     TOKEN_NUM_TOTAL = 301,
     TOKEN_NUM_FRACAO = 302,
     UMINUS = 303
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
#define TOKEN_TIPO_VAZIO 275
#define TOKEN_FIEL 276
#define TOKEN_FATAL 277
#define TOKEN_E 278
#define TOKEN_OU 279
#define TOKEN_NAO 280
#define TOKEN_TERMINADOR 281
#define TOKEN_DOIS_PONTOS 282
#define TOKEN_ATRIBUICAO 283
#define TOKEN_SOMA 284
#define TOKEN_SUBTRACAO 285
#define TOKEN_MULTIPLICACAO 286
#define TOKEN_DIVISAO 287
#define TOKEN_MODULO 288
#define TOKEN_PAREN_ESQ 289
#define TOKEN_PAREN_DIR 290
#define TOKEN_MAIOR 291
#define TOKEN_MENOR 292
#define TOKEN_MAIOR_IGUAL 293
#define TOKEN_MENOR_IGUAL 294
#define TOKEN_IGUALDADE 295
#define TOKEN_DIFERENTE 296
#define TOKEN_VIRGULA 297
#define TOKEN_ERRO 298
#define TOKEN_ID 299
#define TOKEN_TEXTO 300
#define TOKEN_NUM_TOTAL 301
#define TOKEN_NUM_FRACAO 302
#define UMINUS 303




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include <iostream>
#include <string>
#include <vector>
#include "ast.h"
extern int yylex();
extern int yylineno;
void yyerror(const char *s);
NoPrograma* arvore_raiz = 0;
static std::string texto_sem_aspas(char *s) { std::string r(s); delete[] s; if (r.size() >= 2) return r.substr(1, r.size()-2); return r; }
static std::string consumir_texto(char *s) { std::string r(s); delete[] s; return r; }
static bool tipos_do_formato(const std::string& formato, std::vector<TipoDado>& tipos) {
    for (size_t i=0; i<formato.size();) {
        if (formato[i] != '%') { ++i; continue; }
        if (formato.compare(i, 4, "%tex") == 0) { tipos.push_back(TipoDado::Textao); i += 4; }
        else if (formato.compare(i, 2, "%t") == 0) { tipos.push_back(TipoDado::Total); i += 2; }
        else if (formato.compare(i, 2, "%f") == 0) { tipos.push_back(TipoDado::Fracao); i += 2; }
        else if (formato.compare(i, 2, "%s") == 0) { tipos.push_back(TipoDado::Sinal); i += 2; }
        else return false;
    }
    return !tipos.empty();
}


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 26 "parser.y"
{
    double numero;
    char *texto;
    TipoDado tipo;
    NoExpressao *expressao;
    NoAST *comando;
    NoBloco *bloco;
    std::vector<NoAST*> *comandos;
    std::vector<NoExpressao*> *argumentos;
    std::vector<ParametroFuncao> *parametros;
    std::vector<std::string> *nomes;
    std::vector<TipoDado> *tipos;
}
/* Line 193 of yacc.c.  */
#line 230 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 243 "parser.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   286

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  140

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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    34,    42,    47,
      53,    55,    57,    59,    61,    67,    75,    82,    83,    86,
      92,    96,    99,   102,   111,   114,   118,   120,   122,   123,
     125,   129,   135,   137,   141,   142,   144,   146,   150,   152,
     154,   156,   158,   160,   162,   167,   171,   174,   177,   181,
     185,   189,   193,   197,   201,   205,   209,   213,   217,   221,
     225
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    -1,    -1,    51,    52,    -1,    53,
      -1,    54,    -1,    55,    -1,    56,    -1,    58,    -1,    59,
      -1,    60,    -1,    62,    -1,    64,    -1,    65,    -1,    66,
      -1,    15,    45,    -1,     3,    44,    28,    73,    27,    57,
      26,    -1,    44,    28,    73,    26,    -1,    44,    34,    71,
      35,    26,    -1,    16,    -1,    17,    -1,    18,    -1,    19,
      -1,     9,    34,    72,    35,    26,    -1,    10,    34,    45,
      42,    70,    35,    26,    -1,     4,    34,    73,    35,    63,
      61,    -1,    -1,     5,    63,    -1,     6,    34,    73,    35,
      63,    -1,     7,    51,     8,    -1,    11,    26,    -1,    12,
      26,    -1,    13,    44,    34,    68,    35,    27,    67,    63,
      -1,    14,    26,    -1,    14,    73,    26,    -1,    57,    -1,
      20,    -1,    -1,    69,    -1,    44,    27,    57,    -1,    69,
      42,    44,    27,    57,    -1,    44,    -1,    70,    42,    44,
      -1,    -1,    72,    -1,    73,    -1,    72,    42,    73,    -1,
      46,    -1,    47,    -1,    45,    -1,    21,    -1,    22,    -1,
      44,    -1,    44,    34,    71,    35,    -1,    34,    73,    35,
      -1,    30,    73,    -1,    25,    73,    -1,    73,    29,    73,
      -1,    73,    30,    73,    -1,    73,    31,    73,    -1,    73,
      32,    73,    -1,    73,    33,    73,    -1,    73,    36,    73,
      -1,    73,    37,    73,    -1,    73,    38,    73,    -1,    73,
      39,    73,    -1,    73,    40,    73,    -1,    73,    41,    73,
      -1,    73,    23,    73,    -1,    73,    24,    73,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    67,    68,    69,    70,
      71,    71,    71,    71,    72,    73,    74,    75,    75,    76,
      77,    78,    78,    79,    80,    80,    81,    81,    82,    82,
      83,    83,    84,    84,    85,    85,    86,    86,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_GUARDE", "TOKEN_TESTAR",
  "TOKEN_SENAO", "TOKEN_REPETIR", "TOKEN_ABRIR", "TOKEN_FECHAR",
  "TOKEN_EXIBIR", "TOKEN_OBTER", "TOKEN_PARAR", "TOKEN_PULAR",
  "TOKEN_FUNCAO", "TOKEN_VOLTAR", "TOKEN_SERMAO", "TOKEN_TIPO_TOTAL",
  "TOKEN_TIPO_FRACAO", "TOKEN_TIPO_SINAL", "TOKEN_TIPO_TEXTAO",
  "TOKEN_TIPO_VAZIO", "TOKEN_FIEL", "TOKEN_FATAL", "TOKEN_E", "TOKEN_OU",
  "TOKEN_NAO", "TOKEN_TERMINADOR", "TOKEN_DOIS_PONTOS", "TOKEN_ATRIBUICAO",
  "TOKEN_SOMA", "TOKEN_SUBTRACAO", "TOKEN_MULTIPLICACAO", "TOKEN_DIVISAO",
  "TOKEN_MODULO", "TOKEN_PAREN_ESQ", "TOKEN_PAREN_DIR", "TOKEN_MAIOR",
  "TOKEN_MENOR", "TOKEN_MAIOR_IGUAL", "TOKEN_MENOR_IGUAL",
  "TOKEN_IGUALDADE", "TOKEN_DIFERENTE", "TOKEN_VIRGULA", "TOKEN_ERRO",
  "TOKEN_ID", "TOKEN_TEXTO", "TOKEN_NUM_TOTAL", "TOKEN_NUM_FRACAO",
  "UMINUS", "$accept", "programa", "lista_comandos", "comando",
  "comentario", "declaracao", "atribuicao", "chamada_comando", "tipo",
  "exibicao", "entrada", "condicional", "senao_opcional", "repeticao",
  "bloco", "controle_fluxo", "funcao", "retorno", "tipo_retorno",
  "parametros_opcionais", "parametros", "lista_ids",
  "argumentos_opcionais", "argumentos", "expressao", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    53,    54,    55,    56,
      57,    57,    57,    57,    58,    59,    60,    61,    61,    62,
      63,    64,    64,    65,    66,    66,    67,    67,    68,    68,
      69,    69,    70,    70,    71,    71,    72,    72,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     7,     4,     5,
       1,     1,     1,     1,     5,     7,     6,     0,     2,     5,
       3,     2,     2,     8,     2,     3,     1,     1,     0,     1,
       3,     5,     1,     3,     0,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     4,     3,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     0,     0,     0,
       0,     0,    31,    32,     0,    51,    52,     0,    34,     0,
       0,    53,    50,    48,    49,     0,    16,     0,    44,     0,
       0,     0,     0,    46,     0,    38,    57,    56,     0,    44,
       0,     0,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,     0,     0,     0,
       0,     0,     0,     0,     0,    39,    55,     0,    69,    70,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    18,     0,     0,     3,    27,    29,    24,    47,    42,
       0,     0,     0,     0,    54,    19,    20,    21,    22,    23,
       0,     0,     0,    26,     0,     0,    40,     0,     0,    17,
      30,    28,    25,    43,    37,    36,     0,     0,    33,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    15,    16,    17,    18,    19,   120,    20,
      21,    22,   123,    23,   105,    24,    25,    26,   136,    84,
      85,   110,    75,    76,    53
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -107
static const yytype_int16 yypact[] =
{
    -107,     2,    62,  -107,   -43,   -14,   -11,    -4,    11,    10,
      17,     3,    57,    18,   -10,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,    34,    63,    63,
      63,    22,  -107,  -107,    12,  -107,  -107,    63,  -107,    63,
      63,    36,  -107,  -107,  -107,    88,  -107,    63,    63,    63,
     107,   126,   -16,   202,    38,    37,  -107,  -107,   145,    63,
      63,    63,  -107,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,   164,    51,    47,   183,    83,    83,
      66,    63,    50,    68,    61,    56,  -107,    64,   234,   221,
       1,     1,  -107,  -107,  -107,     9,     9,     9,     9,   247,
     247,  -107,    74,   116,  -107,   100,  -107,  -107,   202,  -107,
     -13,   116,    86,    71,  -107,  -107,  -107,  -107,  -107,  -107,
      90,     0,    83,  -107,    96,    79,  -107,   229,   114,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,    83,   116,  -107,  -107
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -107,  -107,    48,  -107,  -107,  -107,  -107,  -107,  -106,  -107,
    -107,  -107,  -107,  -107,   -72,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,    92,   123,   -12
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      45,    27,     3,     4,     5,   126,     6,   106,   130,     7,
       8,     9,    10,    11,    12,    13,    50,    51,    47,    80,
      28,   135,   124,    29,    48,    56,    81,    57,    58,   125,
      30,   139,    65,    66,    67,    74,    32,    77,    63,    64,
      65,    66,    67,    33,    14,    31,    55,    34,    88,    89,
     131,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    49,    46,   138,     4,     5,    54,     6,   108,
      59,     7,     8,     9,    10,    11,    12,    13,    35,    36,
      82,    83,    37,    38,    35,    36,   102,    39,    37,    81,
     104,    40,   107,    39,   109,   111,   112,    40,   113,   114,
     115,    41,    42,    43,    44,   122,    14,    41,    42,    43,
      44,    60,    61,   127,    62,   128,   129,    63,    64,    65,
      66,    67,   132,   133,    68,    69,    70,    71,    72,    73,
      60,    61,   116,   117,   118,   119,    63,    64,    65,    66,
      67,   137,    78,    68,    69,    70,    71,    72,    73,    60,
      61,    87,   121,    52,     0,    63,    64,    65,    66,    67,
       0,    79,    68,    69,    70,    71,    72,    73,    60,    61,
       0,     0,     0,     0,    63,    64,    65,    66,    67,     0,
      86,    68,    69,    70,    71,    72,    73,    60,    61,     0,
     101,     0,     0,    63,    64,    65,    66,    67,     0,     0,
      68,    69,    70,    71,    72,    73,    60,    61,     0,     0,
     103,     0,    63,    64,    65,    66,    67,     0,     0,    68,
      69,    70,    71,    72,    73,    60,    61,     0,     0,     0,
       0,    63,    64,    65,    66,    67,     0,     0,    68,    69,
      70,    71,    72,    73,    60,   116,   117,   118,   119,   134,
      63,    64,    65,    66,    67,     0,     0,    68,    69,    70,
      71,    72,    73,    63,    64,    65,    66,    67,     0,     0,
      68,    69,    70,    71,    72,    73,    63,    64,    65,    66,
      67,     0,     0,    68,    69,    70,    71
};

static const yytype_int16 yycheck[] =
{
      12,    44,     0,     3,     4,   111,     6,    79,     8,     9,
      10,    11,    12,    13,    14,    15,    28,    29,    28,    35,
      34,   127,    35,    34,    34,    37,    42,    39,    40,    42,
      34,   137,    31,    32,    33,    47,    26,    49,    29,    30,
      31,    32,    33,    26,    44,    34,    34,    44,    60,    61,
     122,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    28,    45,   136,     3,     4,    45,     6,    81,
      34,     9,    10,    11,    12,    13,    14,    15,    21,    22,
      42,    44,    25,    26,    21,    22,    35,    30,    25,    42,
       7,    34,    26,    30,    44,    27,    35,    34,    42,    35,
      26,    44,    45,    46,    47,     5,    44,    44,    45,    46,
      47,    23,    24,    27,    26,    44,    26,    29,    30,    31,
      32,    33,    26,    44,    36,    37,    38,    39,    40,    41,
      23,    24,    16,    17,    18,    19,    29,    30,    31,    32,
      33,    27,    35,    36,    37,    38,    39,    40,    41,    23,
      24,    59,   104,    30,    -1,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    39,    40,    41,    23,    24,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    38,    39,    40,    41,    23,    24,    -1,
      26,    -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,
      36,    37,    38,    39,    40,    41,    23,    24,    -1,    -1,
      27,    -1,    29,    30,    31,    32,    33,    -1,    -1,    36,
      37,    38,    39,    40,    41,    23,    24,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    -1,    -1,    36,    37,
      38,    39,    40,    41,    23,    16,    17,    18,    19,    20,
      29,    30,    31,    32,    33,    -1,    -1,    36,    37,    38,
      39,    40,    41,    29,    30,    31,    32,    33,    -1,    -1,
      36,    37,    38,    39,    40,    41,    29,    30,    31,    32,
      33,    -1,    -1,    36,    37,    38,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,    51,     0,     3,     4,     6,     9,    10,    11,
      12,    13,    14,    15,    44,    52,    53,    54,    55,    56,
      58,    59,    60,    62,    64,    65,    66,    44,    34,    34,
      34,    34,    26,    26,    44,    21,    22,    25,    26,    30,
      34,    44,    45,    46,    47,    73,    45,    28,    34,    28,
      73,    73,    72,    73,    45,    34,    73,    73,    73,    34,
      23,    24,    26,    29,    30,    31,    32,    33,    36,    37,
      38,    39,    40,    41,    73,    71,    72,    73,    35,    35,
      35,    42,    42,    44,    68,    69,    35,    71,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    26,    35,    27,     7,    63,    63,    26,    73,    44,
      70,    27,    35,    42,    35,    26,    16,    17,    18,    19,
      57,    51,     5,    61,    35,    42,    57,    27,    44,    26,
       8,    63,    26,    44,    20,    57,    67,    27,    63,    57
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
        case 2:
#line 64 "parser.y"
    { arvore_raiz = new NoPrograma(*(yyvsp[(1) - (1)].comandos)); delete (yyvsp[(1) - (1)].comandos); ;}
    break;

  case 3:
#line 65 "parser.y"
    { (yyval.comandos) = new std::vector<NoAST*>(); ;}
    break;

  case 4:
#line 65 "parser.y"
    { (yyval.comandos)=(yyvsp[(1) - (2)].comandos); (yyval.comandos)->push_back((yyvsp[(2) - (2)].comando)); ;}
    break;

  case 16:
#line 67 "parser.y"
    { delete[] (yyvsp[(2) - (2)].texto); (yyval.comando)=new NoComentario(); ;}
    break;

  case 17:
#line 68 "parser.y"
    { std::string n=consumir_texto((yyvsp[(2) - (7)].texto)); (yyval.comando)=new NoGuarde(n,(yyvsp[(6) - (7)].tipo),(yyvsp[(4) - (7)].expressao)); ;}
    break;

  case 18:
#line 69 "parser.y"
    { std::string n=consumir_texto((yyvsp[(1) - (4)].texto)); (yyval.comando)=new NoAtribuicao(n,(yyvsp[(3) - (4)].expressao)); ;}
    break;

  case 19:
#line 70 "parser.y"
    { std::string n=consumir_texto((yyvsp[(1) - (5)].texto)); (yyval.comando)=new NoChamada(n,*(yyvsp[(3) - (5)].argumentos)); delete (yyvsp[(3) - (5)].argumentos); ;}
    break;

  case 20:
#line 71 "parser.y"
    { (yyval.tipo)=TipoDado::Total; ;}
    break;

  case 21:
#line 71 "parser.y"
    { (yyval.tipo)=TipoDado::Fracao; ;}
    break;

  case 22:
#line 71 "parser.y"
    { (yyval.tipo)=TipoDado::Sinal; ;}
    break;

  case 23:
#line 71 "parser.y"
    { (yyval.tipo)=TipoDado::Textao; ;}
    break;

  case 24:
#line 72 "parser.y"
    { (yyval.comando)=new NoExibir(*(yyvsp[(3) - (5)].argumentos)); delete (yyvsp[(3) - (5)].argumentos); ;}
    break;

  case 25:
#line 73 "parser.y"
    { std::vector<TipoDado> tipos; std::string formato=texto_sem_aspas((yyvsp[(3) - (7)].texto)); if(!tipos_do_formato(formato,tipos)||tipos.size()!=(yyvsp[(5) - (7)].nomes)->size()){ delete (yyvsp[(5) - (7)].nomes); yyerror("obter exige especificadores válidos e uma variável para cada especificador"); YYERROR; } (yyval.comando)=new NoObter(formato,*(yyvsp[(5) - (7)].nomes),tipos); delete (yyvsp[(5) - (7)].nomes); ;}
    break;

  case 26:
#line 74 "parser.y"
    { (yyval.comando)=new NoCondicional((yyvsp[(3) - (6)].expressao),(yyvsp[(5) - (6)].bloco),(yyvsp[(6) - (6)].bloco)); ;}
    break;

  case 27:
#line 75 "parser.y"
    { (yyval.bloco)=0; ;}
    break;

  case 28:
#line 75 "parser.y"
    { (yyval.bloco)=(yyvsp[(2) - (2)].bloco); ;}
    break;

  case 29:
#line 76 "parser.y"
    { (yyval.comando)=new NoRepeticao((yyvsp[(3) - (5)].expressao),(yyvsp[(5) - (5)].bloco)); ;}
    break;

  case 30:
#line 77 "parser.y"
    { (yyval.bloco)=new NoBloco(*(yyvsp[(2) - (3)].comandos)); delete (yyvsp[(2) - (3)].comandos); ;}
    break;

  case 31:
#line 78 "parser.y"
    { (yyval.comando)=new NoParar(); ;}
    break;

  case 32:
#line 78 "parser.y"
    { (yyval.comando)=new NoPular(); ;}
    break;

  case 33:
#line 79 "parser.y"
    { std::string n=consumir_texto((yyvsp[(2) - (8)].texto)); (yyval.comando)=new NoFuncao(n,*(yyvsp[(4) - (8)].parametros),(yyvsp[(7) - (8)].tipo),(yyvsp[(8) - (8)].bloco)); delete (yyvsp[(4) - (8)].parametros); ;}
    break;

  case 34:
#line 80 "parser.y"
    { (yyval.comando)=new NoVoltar(); ;}
    break;

  case 35:
#line 80 "parser.y"
    { (yyval.comando)=new NoVoltar((yyvsp[(2) - (3)].expressao)); ;}
    break;

  case 36:
#line 81 "parser.y"
    { (yyval.tipo)=(yyvsp[(1) - (1)].tipo); ;}
    break;

  case 37:
#line 81 "parser.y"
    { (yyval.tipo)=TipoDado::Vazio; ;}
    break;

  case 38:
#line 82 "parser.y"
    { (yyval.parametros)=new std::vector<ParametroFuncao>(); ;}
    break;

  case 39:
#line 82 "parser.y"
    { (yyval.parametros)=(yyvsp[(1) - (1)].parametros); ;}
    break;

  case 40:
#line 83 "parser.y"
    { (yyval.parametros)=new std::vector<ParametroFuncao>(); (yyval.parametros)->push_back({consumir_texto((yyvsp[(1) - (3)].texto)),(yyvsp[(3) - (3)].tipo)}); ;}
    break;

  case 41:
#line 83 "parser.y"
    { (yyval.parametros)=(yyvsp[(1) - (5)].parametros); (yyval.parametros)->push_back({consumir_texto((yyvsp[(3) - (5)].texto)),(yyvsp[(5) - (5)].tipo)}); ;}
    break;

  case 42:
#line 84 "parser.y"
    { (yyval.nomes)=new std::vector<std::string>(); (yyval.nomes)->push_back(consumir_texto((yyvsp[(1) - (1)].texto))); ;}
    break;

  case 43:
#line 84 "parser.y"
    { (yyval.nomes)=(yyvsp[(1) - (3)].nomes); (yyval.nomes)->push_back(consumir_texto((yyvsp[(3) - (3)].texto))); ;}
    break;

  case 44:
#line 85 "parser.y"
    { (yyval.argumentos)=new std::vector<NoExpressao*>(); ;}
    break;

  case 45:
#line 85 "parser.y"
    { (yyval.argumentos)=(yyvsp[(1) - (1)].argumentos); ;}
    break;

  case 46:
#line 86 "parser.y"
    { (yyval.argumentos)=new std::vector<NoExpressao*>(); (yyval.argumentos)->push_back((yyvsp[(1) - (1)].expressao)); ;}
    break;

  case 47:
#line 86 "parser.y"
    { (yyval.argumentos)=(yyvsp[(1) - (3)].argumentos); (yyval.argumentos)->push_back((yyvsp[(3) - (3)].expressao)); ;}
    break;

  case 48:
#line 88 "parser.y"
    { (yyval.expressao)=new NoLiteral({TipoDado::Total,(int)(yyvsp[(1) - (1)].numero)}); ;}
    break;

  case 49:
#line 89 "parser.y"
    { (yyval.expressao)=new NoLiteral({TipoDado::Fracao,(yyvsp[(1) - (1)].numero)}); ;}
    break;

  case 50:
#line 90 "parser.y"
    { (yyval.expressao)=new NoLiteral({TipoDado::Textao,texto_sem_aspas((yyvsp[(1) - (1)].texto))}); ;}
    break;

  case 51:
#line 91 "parser.y"
    { (yyval.expressao)=new NoLiteral({TipoDado::Sinal,true}); ;}
    break;

  case 52:
#line 92 "parser.y"
    { (yyval.expressao)=new NoLiteral({TipoDado::Sinal,false}); ;}
    break;

  case 53:
#line 93 "parser.y"
    { (yyval.expressao)=new NoVariavel(consumir_texto((yyvsp[(1) - (1)].texto))); ;}
    break;

  case 54:
#line 94 "parser.y"
    { std::string n=consumir_texto((yyvsp[(1) - (4)].texto)); (yyval.expressao)=new NoChamada(n,*(yyvsp[(3) - (4)].argumentos)); delete (yyvsp[(3) - (4)].argumentos); ;}
    break;

  case 55:
#line 95 "parser.y"
    { (yyval.expressao)=(yyvsp[(2) - (3)].expressao); ;}
    break;

  case 56:
#line 96 "parser.y"
    { (yyval.expressao)=new NoMenosUnario((yyvsp[(2) - (2)].expressao)); ;}
    break;

  case 57:
#line 97 "parser.y"
    { (yyval.expressao)=new NoNegacao((yyvsp[(2) - (2)].expressao)); ;}
    break;

  case 58:
#line 98 "parser.y"
    { (yyval.expressao)=new NoSoma((yyvsp[(1) - (3)].expressao),(yyvsp[(3) - (3)].expressao)); ;}
    break;

  case 59:
#line 99 "parser.y"
    { (yyval.expressao)=new NoSubtracao((yyvsp[(1) - (3)].expressao),(yyvsp[(3) - (3)].expressao)); ;}
    break;

  case 60:
#line 100 "parser.y"
    { (yyval.expressao)=new NoMultiplicacao((yyvsp[(1) - (3)].expressao),(yyvsp[(3) - (3)].expressao)); ;}
    break;

  case 61:
#line 101 "parser.y"
    { (yyval.expressao)=new NoDivisao((yyvsp[(1) - (3)].expressao),(yyvsp[(3) - (3)].expressao)); ;}
    break;

  case 62:
#line 102 "parser.y"
    { (yyval.expressao)=new NoModulo((yyvsp[(1) - (3)].expressao),(yyvsp[(3) - (3)].expressao)); ;}
    break;

  case 63:
#line 103 "parser.y"
    { (yyval.expressao)=new NoComparacao((yyvsp[(1) - (3)].expressao),(yyvsp[(3) - (3)].expressao),OperadorComparacao::Maior); ;}
    break;

  case 64:
#line 104 "parser.y"
    { (yyval.expressao)=new NoComparacao((yyvsp[(1) - (3)].expressao),(yyvsp[(3) - (3)].expressao),OperadorComparacao::Menor); ;}
    break;

  case 65:
#line 105 "parser.y"
    { (yyval.expressao)=new NoComparacao((yyvsp[(1) - (3)].expressao),(yyvsp[(3) - (3)].expressao),OperadorComparacao::MaiorIgual); ;}
    break;

  case 66:
#line 106 "parser.y"
    { (yyval.expressao)=new NoComparacao((yyvsp[(1) - (3)].expressao),(yyvsp[(3) - (3)].expressao),OperadorComparacao::MenorIgual); ;}
    break;

  case 67:
#line 107 "parser.y"
    { (yyval.expressao)=new NoComparacao((yyvsp[(1) - (3)].expressao),(yyvsp[(3) - (3)].expressao),OperadorComparacao::Igual); ;}
    break;

  case 68:
#line 108 "parser.y"
    { (yyval.expressao)=new NoComparacao((yyvsp[(1) - (3)].expressao),(yyvsp[(3) - (3)].expressao),OperadorComparacao::Diferente); ;}
    break;

  case 69:
#line 109 "parser.y"
    { (yyval.expressao)=new NoLogico((yyvsp[(1) - (3)].expressao),(yyvsp[(3) - (3)].expressao),OperadorLogico::E); ;}
    break;

  case 70:
#line 110 "parser.y"
    { (yyval.expressao)=new NoLogico((yyvsp[(1) - (3)].expressao),(yyvsp[(3) - (3)].expressao),OperadorLogico::Ou); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1886 "parser.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 111 "parser.y"

void yyerror(const char *s) { std::cerr << "Erro sintático na linha " << yylineno << ": " << s << std::endl; }

