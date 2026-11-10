#ifndef AST_H
#define AST_H

#include <string>
#include <map>
#include <iostream>
#include <stdexcept>

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

// --- Extensão criada pelo Luís: Expressões ---
// Necessário pois expressões precisam retornar um valor numérico para contas
class NoExpressao : public NoAST {
public:
    virtual double avaliar(TabelaSimbolos& tabela) = 0;
    void executar(TabelaSimbolos& tabela) override { avaliar(tabela); }
};

// Nó para números literais (ex: 5.0, 10)
class NoLiteral : public NoExpressao {
    double valor;
public:
    NoLiteral(double v);
    double avaliar(TabelaSimbolos& tabela) override;
};

// Nó para buscar valor de uma variável salva na Tabela de Símbolos
class NoVariavel : public NoExpressao {
    std::string nome;
public:
    NoVariavel(std::string n);
    double avaliar(TabelaSimbolos& tabela) override;
};

// Nós de Operações Matemáticas
class NoSoma : public NoExpressao {
    NoExpressao* esq;
    NoExpressao* dir;
public:
    NoSoma(NoExpressao* e, NoExpressao* d);
    ~NoSoma();
    double avaliar(TabelaSimbolos& tabela) override;
};

class NoMultiplicacao : public NoExpressao {
    NoExpressao* esq;
    NoExpressao* dir;
public:
    NoMultiplicacao(NoExpressao* e, NoExpressao* d);
    ~NoMultiplicacao();
    double avaliar(TabelaSimbolos& tabela) override;
};

// --- Extensão criada pelo Luís: Comandos ---

// Nó para declaração 'guarde variavel = valor : tipo!'
class NoGuarde : public NoAST {
    std::string nome;
    NoExpressao* expressao;
public:
    NoGuarde(std::string n, NoExpressao* expr);
    ~NoGuarde();
    void executar(TabelaSimbolos& tabela) override;
};

// Nó para comando 'exibir(variavel)!'
class NoExibir : public NoAST {
    NoExpressao* expressao;
public:
    NoExibir(NoExpressao* expr);
    ~NoExibir();
    void executar(TabelaSimbolos& tabela) override;
};

#endif