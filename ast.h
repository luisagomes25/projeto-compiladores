#ifndef AST_H
#define AST_H

#include <string>
#include <map>
#include <iostream>

// Tabela de Simbolos para o Luis gerenciar o 'guarde'
class TabelaSimbolos {
public:
    std::map<std::string, double> variaveis; 
    // Nota pro Luis: Comecamos com double para simplificar, 
    // depois voce pode criar uma struct para suportar 'textao' e 'sinal'
};

// Classe Base da Arvore Sintatica Abstrata (AST)
class NoAST {
public:
    virtual ~NoAST() {}
    virtual void executar(TabelaSimbolos& tabela) = 0; // O Luis implementa a logica aqui
};

#endif