%{
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
%}

%error-verbose
%union {
    double numero;
    char *texto;
    TipoDado tipo;
    NoExpressao *expressao;
    NoAST *comando;
    NoBloco *bloco;
    std::vector<NoAST*> *comandos;
    std::vector<NoExpressao*> *argumentos;
}
%token TOKEN_GUARDE TOKEN_TESTAR TOKEN_SENAO TOKEN_REPETIR TOKEN_ABRIR TOKEN_FECHAR TOKEN_EXIBIR TOKEN_OBTER TOKEN_PARAR TOKEN_PULAR TOKEN_FUNCAO TOKEN_VOLTAR TOKEN_SERMAO
%token TOKEN_TIPO_TOTAL TOKEN_TIPO_FRACAO TOKEN_TIPO_SINAL TOKEN_TIPO_TEXTAO TOKEN_FIEL TOKEN_FATAL TOKEN_E TOKEN_OU TOKEN_NAO
%token TOKEN_TERMINADOR TOKEN_DOIS_PONTOS TOKEN_ATRIBUICAO TOKEN_SOMA TOKEN_SUBTRACAO TOKEN_MULTIPLICACAO TOKEN_DIVISAO TOKEN_MODULO TOKEN_PAREN_ESQ TOKEN_PAREN_DIR
%token TOKEN_MAIOR TOKEN_MENOR TOKEN_MAIOR_IGUAL TOKEN_MENOR_IGUAL TOKEN_IGUALDADE TOKEN_DIFERENTE TOKEN_VIRGULA TOKEN_ERRO
%token <texto> TOKEN_ID TOKEN_TEXTO
%token <numero> TOKEN_NUM_TOTAL TOKEN_NUM_FRACAO
%type <comandos> lista_comandos
%type <comando> comando comentario declaracao atribuicao exibicao entrada condicional repeticao controle_fluxo funcao retorno
%type <bloco> bloco senao_opcional
%type <tipo> tipo
%type <expressao> expressao
%type <argumentos> argumentos argumentos_opcionais
%left TOKEN_OU
%left TOKEN_E
%left TOKEN_IGUALDADE TOKEN_DIFERENTE
%left TOKEN_MAIOR TOKEN_MENOR TOKEN_MAIOR_IGUAL TOKEN_MENOR_IGUAL
%left TOKEN_SOMA TOKEN_SUBTRACAO
%left TOKEN_MULTIPLICACAO TOKEN_DIVISAO TOKEN_MODULO
%right TOKEN_NAO
%right UMINUS
%start programa
%%
programa: lista_comandos { arvore_raiz = new NoPrograma(*$1); delete $1; };
lista_comandos: /* vazio */ { $$ = new std::vector<NoAST*>(); } | lista_comandos comando { $$=$1; $$->push_back($2); };
comando: comentario | declaracao | atribuicao | exibicao | entrada | condicional | repeticao | controle_fluxo | funcao | retorno;
comentario: TOKEN_SERMAO TOKEN_TEXTO { delete[] $2; $$=new NoComentario(); };
declaracao: TOKEN_GUARDE TOKEN_ID TOKEN_ATRIBUICAO expressao TOKEN_DOIS_PONTOS tipo TOKEN_TERMINADOR { std::string n=consumir_texto($2); $$=new NoGuarde(n,$6,$4); };
atribuicao: TOKEN_ID TOKEN_ATRIBUICAO expressao TOKEN_TERMINADOR { std::string n=consumir_texto($1); $$=new NoAtribuicao(n,$3); };
tipo: TOKEN_TIPO_TOTAL { $$=TipoDado::Total; } | TOKEN_TIPO_FRACAO { $$=TipoDado::Fracao; } | TOKEN_TIPO_SINAL { $$=TipoDado::Sinal; } | TOKEN_TIPO_TEXTAO { $$=TipoDado::Textao; };
exibicao: TOKEN_EXIBIR TOKEN_PAREN_ESQ argumentos TOKEN_PAREN_DIR TOKEN_TERMINADOR { $$=new NoExibir(*$3); delete $3; };
entrada: TOKEN_OBTER TOKEN_PAREN_ESQ argumentos_opcionais TOKEN_PAREN_DIR TOKEN_TERMINADOR { for(auto e:*$3) delete e; delete $3; $$=new NoComentario(); };
condicional: TOKEN_TESTAR TOKEN_PAREN_ESQ expressao TOKEN_PAREN_DIR bloco senao_opcional { $$=new NoCondicional($3,$5,$6); };
senao_opcional: /* vazio */ { $$=0; } | TOKEN_SENAO bloco { $$=$2; };
repeticao: TOKEN_REPETIR TOKEN_PAREN_ESQ expressao TOKEN_PAREN_DIR bloco { $$=new NoRepeticao($3,$5); };
bloco: TOKEN_ABRIR lista_comandos TOKEN_FECHAR { $$=new NoBloco(*$2); delete $2; };
controle_fluxo: TOKEN_PARAR TOKEN_TERMINADOR { $$=new NoParar(); } | TOKEN_PULAR TOKEN_TERMINADOR { $$=new NoPular(); };
funcao: TOKEN_FUNCAO TOKEN_ID TOKEN_PAREN_ESQ parametros_opcionais TOKEN_PAREN_DIR bloco { delete[] $2; delete $6; $$=new NoComentario(); };
retorno: TOKEN_VOLTAR expressao TOKEN_TERMINADOR { delete $2; $$=new NoComentario(); };
parametros_opcionais: /* vazio */ | lista_ids;
lista_ids: TOKEN_ID { delete[] $1; } | lista_ids TOKEN_VIRGULA TOKEN_ID { delete[] $3; };
argumentos_opcionais: /* vazio */ { $$=new std::vector<NoExpressao*>(); } | argumentos { $$=$1; };
argumentos: expressao { $$=new std::vector<NoExpressao*>(); $$->push_back($1); } | argumentos TOKEN_VIRGULA expressao { $$=$1; $$->push_back($3); };
expressao:
 TOKEN_NUM_TOTAL { $$=new NoLiteral({TipoDado::Total,(int)$1}); }
 | TOKEN_NUM_FRACAO { $$=new NoLiteral({TipoDado::Fracao,$1}); }
 | TOKEN_TEXTO { $$=new NoLiteral({TipoDado::Textao,texto_sem_aspas($1)}); }
 | TOKEN_FIEL { $$=new NoLiteral({TipoDado::Sinal,true}); }
 | TOKEN_FATAL { $$=new NoLiteral({TipoDado::Sinal,false}); }
 | TOKEN_ID { $$=new NoVariavel(consumir_texto($1)); }
 | TOKEN_PAREN_ESQ expressao TOKEN_PAREN_DIR { $$=$2; }
 | TOKEN_SUBTRACAO expressao %prec UMINUS { $$=new NoMenosUnario($2); }
 | TOKEN_NAO expressao { $$=new NoNegacao($2); }
 | expressao TOKEN_SOMA expressao { $$=new NoSoma($1,$3); }
 | expressao TOKEN_SUBTRACAO expressao { $$=new NoSubtracao($1,$3); }
 | expressao TOKEN_MULTIPLICACAO expressao { $$=new NoMultiplicacao($1,$3); }
 | expressao TOKEN_DIVISAO expressao { $$=new NoDivisao($1,$3); }
 | expressao TOKEN_MODULO expressao { $$=new NoModulo($1,$3); }
 | expressao TOKEN_MAIOR expressao { $$=new NoComparacao($1,$3,OperadorComparacao::Maior); }
 | expressao TOKEN_MENOR expressao { $$=new NoComparacao($1,$3,OperadorComparacao::Menor); }
 | expressao TOKEN_MAIOR_IGUAL expressao { $$=new NoComparacao($1,$3,OperadorComparacao::MaiorIgual); }
 | expressao TOKEN_MENOR_IGUAL expressao { $$=new NoComparacao($1,$3,OperadorComparacao::MenorIgual); }
 | expressao TOKEN_IGUALDADE expressao { $$=new NoComparacao($1,$3,OperadorComparacao::Igual); }
 | expressao TOKEN_DIFERENTE expressao { $$=new NoComparacao($1,$3,OperadorComparacao::Diferente); }
 | expressao TOKEN_E expressao { $$=new NoLogico($1,$3,OperadorLogico::E); }
 | expressao TOKEN_OU expressao { $$=new NoLogico($1,$3,OperadorLogico::Ou); };
%%
void yyerror(const char *s) { std::cerr << "Erro sintático na linha " << yylineno << ": " << s << std::endl; }
