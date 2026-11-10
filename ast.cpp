#include "ast.h"

// --- Lógica de Expressões ---

NoLiteral::NoLiteral(double v) : valor(v) {}
double NoLiteral::avaliar(TabelaSimbolos& tabela) {
    return valor;
}

NoVariavel::NoVariavel(std::string n) : nome(n) {}
double NoVariavel::avaliar(TabelaSimbolos& tabela) {
    if (tabela.variaveis.find(nome) == tabela.variaveis.end()) {
        throw std::runtime_error("Erro fatal: Variavel '" + nome + "' nao declarada.");
    }
    return tabela.variaveis[nome];
}

NoSoma::NoSoma(NoExpressao* e, NoExpressao* d) : esq(e), dir(d) {}
NoSoma::~NoSoma() { delete esq; delete dir; }
double NoSoma::avaliar(TabelaSimbolos& tabela) {
    return esq->avaliar(tabela) + dir->avaliar(tabela);
}

NoMultiplicacao::NoMultiplicacao(NoExpressao* e, NoExpressao* d) : esq(e), dir(d) {}
NoMultiplicacao::~NoMultiplicacao() { delete esq; delete dir; }
double NoMultiplicacao::avaliar(TabelaSimbolos& tabela) {
    return esq->avaliar(tabela) * dir->avaliar(tabela);
}

// --- Lógica de Comandos ---

NoGuarde::NoGuarde(std::string n, NoExpressao* expr) : nome(n), expressao(expr) {}
NoGuarde::~NoGuarde() { delete expressao; }
void NoGuarde::executar(TabelaSimbolos& tabela) {
    // Avalia a expressão e salva o resultado no std::map do Gabriel
    double valor_avaliado = expressao->avaliar(tabela);
    tabela.variaveis[nome] = valor_avaliado;
}

NoExibir::NoExibir(NoExpressao* expr) : expressao(expr) {}
NoExibir::~NoExibir() { delete expressao; }
void NoExibir::executar(TabelaSimbolos& tabela) {
    // Calcula o que está dentro do exibir() e imprime
    double valor = expressao->avaliar(tabela);
    std::cout << valor << std::endl;
}