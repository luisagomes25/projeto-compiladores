#include <cstdio>
#include <iostream>
#include "ast.h"

extern int yyparse();
extern FILE* yyin;
extern NoPrograma* arvore_raiz;

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " arquivo.oxi" << std::endl;
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        std::cerr << "Erro ao abrir o arquivo " << argv[1] << std::endl;
        return 1;
    }

    if (yyparse() != 0) {
        fclose(yyin);
        delete arvore_raiz;
        return 1;
    }
    fclose(yyin);

    try {
        TabelaSimbolos tabela;
        arvore_raiz->executar(tabela);
        delete arvore_raiz;
        return 0;
    } catch (const std::exception& erro) {
        std::cerr << "Erro durante a execução: " << erro.what() << std::endl;
        delete arvore_raiz;
        return 1;
    }
}
