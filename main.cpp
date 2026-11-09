#include <iostream>
#include <cstdio>
#include "ast.h"

extern int yyparse();
extern FILE* yyin;

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            std::cerr << "Erro ao abrir o arquivo " << argv[1] << std::endl;
            return 1;
        }
        yyin = file;
    }

    std::cout << "--- Iniciando Compilador Oxitona ---" << std::endl;
    // yyparse() chama o Bison, que chama o Flex automaticamente!
    if (yyparse() == 0) {
        std::cout << "--- Analise Sintatica Concluida com Sucesso ---" << std::endl;
    } else {
        std::cout << "--- Analise Sintatica Falhou ---" << std::endl;
    }

    return 0;
}