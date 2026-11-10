#include <iostream>
#include <cstdio>
#include "ast.h"

extern int yyparse();
extern FILE* yyin;

// Função criada para o Luís testar as classes da AST manualmente
void testar_ast_manualmente() {
    std::cout << "--- Teste Manual da AST (Logica do Luis) ---" << std::endl;
    TabelaSimbolos tabela;

    try {
        // Simulando a execução do Programa 1 da documentação:
        // guarde base = 5.0 : fração!
        NoGuarde* n1 = new NoGuarde("base", new NoLiteral(5.0));
        
        // guarde altura = 2.5 : fração!
        NoGuarde* n2 = new NoGuarde("altura", new NoLiteral(2.5));
        
        // guarde area = base * altura : fração!
        NoGuarde* n3 = new NoGuarde("area", new NoMultiplicacao(new NoVariavel("base"), new NoVariavel("altura")));
        
        // exibir(area)!
        NoExibir* n4 = new NoExibir(new NoVariavel("area"));

        // Percorrendo a árvore (Execução)
        n1->executar(tabela);
        n2->executar(tabela);
        n3->executar(tabela);
        std::cout << "A area calculada no teste eh: ";
        n4->executar(tabela);

        // Limpeza de memória
        delete n1; delete n2; delete n3; delete n4;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------------------------\n\n";
}

int main(int argc, char **argv) {
    // Roda o teste da AST direto na main como a equipe combinou
    testar_ast_manualmente();

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