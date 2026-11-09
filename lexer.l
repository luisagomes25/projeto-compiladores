%{
#include <stdio.h>
/* #include "parser.tab.h" -> O Caio vai precisar disto no futuro */
%}

%option noyywrap

%%

"guarde"    { printf("TOKEN_GUARDE\n"); }
"testar"    { printf("TOKEN_TESTAR\n"); }
"senão"     { printf("TOKEN_SENAO\n"); }
"repetir"   { printf("TOKEN_REPETIR\n"); }
"abrir"     { printf("TOKEN_ABRIR\n"); }
"fechar"    { printf("TOKEN_FECHAR\n"); }
"exibir"    { printf("TOKEN_EXIBIR\n"); }
"obter"     { printf("TOKEN_OBTER\n"); }

"total"     { printf("TOKEN_TIPO_TOTAL\n"); }
"fração"    { printf("TOKEN_TIPO_FRACAO\n"); }
"sinal"     { printf("TOKEN_TIPO_SINAL\n"); }
"textão"    { printf("TOKEN_TIPO_TEXTAO\n"); }
"sermão"    { printf("TOKEN_TIPO_SERMAO\n"); }

"fiel"      { printf("TOKEN_FIEL\n"); }
"fatal"     { printf("TOKEN_FATAL\n"); }

"!"         { printf("TOKEN_TERMINADOR\n"); }
":"         { printf("TOKEN_DOIS_PONTOS\n"); }
"="         { printf("TOKEN_ATRIBUICAO\n"); }
"+"         { printf("TOKEN_SOMA\n"); }
"-"         { printf("TOKEN_SUBTRACAO\n"); }
"*"         { printf("TOKEN_MULTIPLICACAO\n"); }
"/"         { printf("TOKEN_DIVISAO\n"); }
"("         { printf("TOKEN_PAREN_ESQ\n"); }
")"         { printf("TOKEN_PAREN_DIR\n"); }

[a-zA-Z_][a-zA-Z0-9_]*  { printf("TOKEN_ID (%s)\n", yytext); }
[0-9]+                  { printf("TOKEN_NUM_INT (%s)\n", yytext); }
[0-9]+\.[0-9]+          { printf("TOKEN_NUM_FRACAO (%s)\n", yytext); }
\"[^\"]*\"              { printf("TOKEN_TEXTO (%s)\n", yytext); }

[ \t\n\r]+              { /* Ignora espaços em branco e quebras de linha */ }

.                       { printf("ERRO LEXICO: Caracter invalido '%s'\n", yytext); }

%%

/* Função main temporária para você testar isoladamente */
int main() {
    printf("Iniciando Analisador Lexico da Oxitona...\n");
    yylex();
    return 0;
}