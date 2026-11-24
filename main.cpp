#include <cstdio>
#include <iostream>
#include <string>
#include "ast.h"
#include "diagnosticos.h"

extern int yyparse();
extern FILE* yyin;
extern NoPrograma* arvore_raiz;
int erro_lexico = 0;

int main(int argc, char **argv) {
    bool debug = false;
    const char* caminho = nullptr;
    for (int i = 1; i < argc; ++i) {
        std::string argumento = argv[i];
        if (argumento == "--debug" || argumento == "-g") debug = true;
        else if (argumento == "--help" || argumento == "-h") {
            std::cout << "Uso: " << argv[0] << " [--debug] arquivo.oxi\n";
            return 0;
        } else if (!caminho) caminho = argv[i];
        else {
            diagnostico::erro_de_argumentos("informe apenas um arquivo .oxi");
            return 2;
        }
    }

    if (!caminho) {
        diagnostico::erro_de_argumentos("uso: oxi [--debug] arquivo.oxi");
        return 1;
    }

    diagnostico::configurar(caminho, debug);
    yyin = fopen(caminho, "r");
    if (!yyin) {
        diagnostico::emitir("file error", 0, 0, 0, "não foi possível abrir o arquivo");
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
        diagnostico::emitir("runtime error", linha_execucao_atual, coluna_execucao_atual, 1, erro.what());
        delete arvore_raiz;
        return 1;
    }
}
