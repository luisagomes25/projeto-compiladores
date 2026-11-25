%{ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "diagnosticos.h"
#include "parser.tab.h"

extern int erro_lexico;
static int linha_lexer = 1;
static int coluna_lexer = 1;
#define YY_USER_ACTION \
    yylloc.first_line = linha_lexer; \
    yylloc.first_column = coluna_lexer; \
    for (int i = 0; i < yyleng; ++i) { \
        unsigned char caractere = static_cast<unsigned char>(yytext[i]); \
        if (yytext[i] == '\n') { ++linha_lexer; coluna_lexer = 1; } \
        else if (yytext[i] == '\t') coluna_lexer = ((coluna_lexer - 1) / 8 + 1) * 8 + 1; \
        else if ((caractere & 0xC0) != 0x80) ++coluna_lexer; \
    } \
    yylloc.last_line = linha_lexer; \
    yylloc.last_column = coluna_lexer;
%}

%option noyywrap nounput

%%

"guarde"    { return TOKEN_GUARDE; }
"se"        { return TOKEN_SE; }
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
"textao"    { return TOKEN_TIPO_TEXTAO; }
"vazio"     { return TOKEN_TIPO_VAZIO; }

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

.                       { erro_lexico = 1; diagnostico::emitir("lexical error", yylloc.first_line, yylloc.first_column, yyleng, std::string("caractere inválido '") + yytext + "'"); return TOKEN_ERRO; }

<<EOF>>                 { yylloc.first_line = yylloc.last_line = linha_lexer; yylloc.first_column = yylloc.last_column = coluna_lexer; return 0; }

%%
