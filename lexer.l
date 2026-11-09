%{
#include <stdio.h>
#include "parser.tab.h"
%}

%option noyywrap
%option yylineno

%%

"guarde"    { printf("Linha %d: TOKEN_GUARDE\n", yylineno); }
"testar"    { printf("Linha %d: TOKEN_TESTAR\n", yylineno); }
"senão"     { printf("Linha %d: TOKEN_SENAO\n", yylineno); }
"repetir"   { printf("Linha %d: TOKEN_REPETIR\n", yylineno); }
"abrir"     { printf("Linha %d: TOKEN_ABRIR\n", yylineno); }
"fechar"    { printf("Linha %d: TOKEN_FECHAR\n", yylineno); }
"exibir"    { printf("Linha %d: TOKEN_EXIBIR\n", yylineno); }
"obter"     { printf("Linha %d: TOKEN_OBTER\n", yylineno); }

"total"     { printf("Linha %d: TOKEN_TIPO_TOTAL\n", yylineno); }
"fração"    { printf("Linha %d: TOKEN_TIPO_FRACAO\n", yylineno); }
"sinal"     { printf("Linha %d: TOKEN_TIPO_SINAL\n", yylineno); }
"textão"    { printf("Linha %d: TOKEN_TIPO_TEXTAO\n", yylineno); }
"sermão"    { printf("Linha %d: TOKEN_TIPO_SERMAO\n", yylineno); }

"fiel"      { printf("Linha %d: TOKEN_FIEL\n", yylineno); }
"fatal"     { printf("Linha %d: TOKEN_FATAL\n", yylineno); }

"!"         { printf("Linha %d: TOKEN_TERMINADOR\n", yylineno); }
":"         { printf("Linha %d: TOKEN_DOIS_PONTOS\n", yylineno); }
"="         { printf("Linha %d: TOKEN_ATRIBUICAO\n", yylineno); }
"+"         { printf("Linha %d: TOKEN_SOMA\n", yylineno); }
"-"         { printf("Linha %d: TOKEN_SUBTRACAO\n", yylineno); }
"*"         { printf("Linha %d: TOKEN_MULTIPLICACAO\n", yylineno); }
"/"         { printf("Linha %d: TOKEN_DIVISAO\n", yylineno); }
"("         { printf("Linha %d: TOKEN_PAREN_ESQ\n", yylineno); }
")"         { printf("Linha %d: TOKEN_PAREN_DIR\n", yylineno); }
">"         { printf("Linha %d: TOKEN_MAIOR\n", yylineno); }
"<"         { printf("Linha %d: TOKEN_MENOR\n", yylineno); }
">="        { printf("Linha %d: TOKEN_MAIOR_IGUAL\n", yylineno); }
"<="        { printf("Linha %d: TOKEN_MENOR_IGUAL\n", yylineno); }
"=="        { printf("Linha %d: TOKEN_IGUALDADE\n", yylineno); }
"!="        { printf("Linha %d: TOKEN_DIFERENTE\n", yylineno); }
","         { printf("Linha %d: TOKEN_VIRGULA\n", yylineno); }

[a-zA-Z_][a-zA-Z0-9_]*  { printf("Linha %d: TOKEN_ID (%s)\n", yylineno, yytext); }
[0-9]+                  { printf("Linha %d: TOKEN_NUM_TOTAL (%s)\n", yylineno, yytext); }
[0-9]+\.[0-9]+          { printf("Linha %d: TOKEN_NUM_FRACAO (%s)\n", yylineno, yytext); }
\"[^\"]*\"              { printf("Linha %d: TOKEN_TEXTO (%s)\n", yylineno, yytext); }

[ \t\n\r]+              { /* Ignora espacos */ }

.                       { printf("ERRO LEXICO na linha %d: Caracter invalido '%s'\n", yylineno, yytext); }

%%