%{
#include <iostream>
#include "ast.h"

extern int yylex();
extern int yylineno;
void yyerror(const char *s);
%}

/* Declaracao dos tokens que vem do Flex */
%token TOKEN_GUARDE TOKEN_TESTAR TOKEN_SENAO TOKEN_REPETIR TOKEN_ABRIR TOKEN_FECHAR TOKEN_EXIBIR TOKEN_OBTER
%token TOKEN_TIPO_TOTAL TOKEN_TIPO_FRACAO TOKEN_TIPO_SINAL TOKEN_TIPO_TEXTAO TOKEN_TIPO_SERMAO
%token TOKEN_FIEL TOKEN_FATAL TOKEN_TERMINADOR TOKEN_DOIS_PONTOS TOKEN_ATRIBUICAO
%token TOKEN_SOMA TOKEN_SUBTRACAO TOKEN_MULTIPLICACAO TOKEN_DIVISAO TOKEN_PAREN_ESQ TOKEN_PAREN_DIR
%token TOKEN_MAIOR TOKEN_MENOR TOKEN_MAIOR_IGUAL TOKEN_MENOR_IGUAL TOKEN_IGUALDADE TOKEN_DIFERENTE TOKEN_VIRGULA
%token TOKEN_ID TOKEN_NUM_TOTAL TOKEN_NUM_FRACAO TOKEN_TEXTO

%%
/* Regra inicial temporaria pro Caio ter por onde comecar */
programa:
    /* vazio */
    | programa comando
    ;

comando:
    TOKEN_TIPO_SERMAO TOKEN_TEXTO { std::cout << "Comentario lido pelo parser!" << std::endl; }
    | error TOKEN_TERMINADOR { yyerrok; } /* Recuperacao de erro basica */
    ;
%%

void yyerror(const char *s) {
    std::cerr << "Erro sintático na linha " << yylineno << ": " << s << std::endl;
}