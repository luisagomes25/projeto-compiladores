%{ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "parser.tab.h"
%}

%option noyywrap
%option yylineno

%%

"guarde"    { return TOKEN_GUARDE; }
"testar"    { return TOKEN_TESTAR; }
"senão"     { return TOKEN_SENAO; }
"repetir"   { return TOKEN_REPETIR; }
"abrir"     { return TOKEN_ABRIR; }
"fechar"    { return TOKEN_FECHAR; }
"exibir"    { return TOKEN_EXIBIR; }
"obter"     { return TOKEN_OBTER; }
"parar"     { return TOKEN_PARAR; }
"pular"     { return TOKEN_PULAR; }
"função"    { return TOKEN_FUNCAO; }
"voltar"    { return TOKEN_VOLTAR; }
"sermão"    { return TOKEN_SERMAO; }

"total"     { return TOKEN_TIPO_TOTAL; }
"fração"    { return TOKEN_TIPO_FRACAO; }
"sinal"     { return TOKEN_TIPO_SINAL; }
"textão"    { return TOKEN_TIPO_TEXTAO; }

"fiel"      { return TOKEN_FIEL; }
"fatal"     { return TOKEN_FATAL; }
"e"         { return TOKEN_E; }
"ou"        { return TOKEN_OU; }
"não"       { return TOKEN_NAO; }

"!"         { return TOKEN_TERMINADOR; }
":"         { return TOKEN_DOIS_PONTOS; }
"="         { return TOKEN_ATRIBUICAO; }
"+"         { return TOKEN_SOMA; }
"-"         { return TOKEN_SUBTRACAO; }
"*"         { return TOKEN_MULTIPLICACAO; }
"/"         { return TOKEN_DIVISAO; }
"%"         { return TOKEN_MODULO; }
"("         { return TOKEN_PAREN_ESQ; }
")"         { return TOKEN_PAREN_DIR; }
">="        { return TOKEN_MAIOR_IGUAL; }
"<="        { return TOKEN_MENOR_IGUAL; }
"=="        { return TOKEN_IGUALDADE; }
"!="        { return TOKEN_DIFERENTE; }
">"         { return TOKEN_MAIOR; }
"<"         { return TOKEN_MENOR; }
","         { return TOKEN_VIRGULA; }

[a-zA-Z_][a-zA-Z0-9_]*  { yylval.texto = new char[strlen(yytext) + 1]; strcpy(yylval.texto, yytext); return TOKEN_ID; }
[0-9]+\.[0-9]+          { yylval.numero = strtod(yytext, NULL); return TOKEN_NUM_FRACAO; }
[0-9]+                  { yylval.numero = strtod(yytext, NULL); return TOKEN_NUM_TOTAL; }
\"[^\"]*\"            { yylval.texto = new char[strlen(yytext) + 1]; strcpy(yylval.texto, yytext); return TOKEN_TEXTO; }

[ \t\n\r]+              { /* Ignora espacos */ }

.                       { fprintf(stderr, "ERRO LEXICO na linha %d: Caracter invalido '%s'\n", yylineno, yytext); return TOKEN_ERRO; }

%%
