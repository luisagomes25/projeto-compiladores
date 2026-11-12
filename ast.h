#ifndef AST_H
#define AST_H

#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <variant>
#include <vector>

enum class TipoDado { Total, Fracao, Sinal, Textao, Vazio };
using Valor = std::variant<int, double, bool, std::string, std::monostate>;

struct ValorTipado {
    TipoDado tipo;
    Valor valor;
};

std::string valor_para_string(const ValorTipado& valor);
bool valor_verdadeiro(const ValorTipado& valor);
bool valor_compativel(TipoDado destino, const ValorTipado& valor);
ValorTipado converter_valor(TipoDado destino, const ValorTipado& valor);

class TabelaSimbolos {
    std::map<std::string, ValorTipado> variaveis;
    TabelaSimbolos* pai;
    std::map<std::string, class NoFuncao*> funcoes;
public:
    explicit TabelaSimbolos(TabelaSimbolos* escopo_pai = nullptr) : pai(escopo_pai) {}
    bool existe(const std::string& nome) const;
    const ValorTipado& obter(const std::string& nome) const;
    void definir(const std::string& nome, TipoDado tipo, const ValorTipado& valor);
    void atribuir(const std::string& nome, const ValorTipado& valor);
    void registrar_funcao(const std::string& nome, class NoFuncao* funcao);
    class NoFuncao* obter_funcao(const std::string& nome) const;
};

class NoAST {
public:
    virtual ~NoAST() {}
    virtual void executar(TabelaSimbolos& tabela) = 0;
};

class NoExpressao : public NoAST {
public:
    virtual ValorTipado avaliar(TabelaSimbolos& tabela) = 0;
    void executar(TabelaSimbolos& tabela) override { avaliar(tabela); }
};

class NoLiteral : public NoExpressao {
    ValorTipado valor;
public:
    explicit NoLiteral(const ValorTipado& v);
    ValorTipado avaliar(TabelaSimbolos&) override;
};

class NoVariavel : public NoExpressao {
    std::string nome;
public:
    explicit NoVariavel(const std::string& n);
    ValorTipado avaliar(TabelaSimbolos& tabela) override;
};

class NoSoma : public NoExpressao {
    NoExpressao* esq; NoExpressao* dir;
public:
    NoSoma(NoExpressao* e, NoExpressao* d); ~NoSoma();
    ValorTipado avaliar(TabelaSimbolos&) override;
};
class NoSubtracao : public NoExpressao {
    NoExpressao* esq; NoExpressao* dir;
public:
    NoSubtracao(NoExpressao* e, NoExpressao* d); ~NoSubtracao();
    ValorTipado avaliar(TabelaSimbolos&) override;
};
class NoMultiplicacao : public NoExpressao {
    NoExpressao* esq; NoExpressao* dir;
public:
    NoMultiplicacao(NoExpressao* e, NoExpressao* d); ~NoMultiplicacao();
    ValorTipado avaliar(TabelaSimbolos&) override;
};
class NoDivisao : public NoExpressao {
    NoExpressao* esq; NoExpressao* dir;
public:
    NoDivisao(NoExpressao* e, NoExpressao* d); ~NoDivisao();
    ValorTipado avaliar(TabelaSimbolos&) override;
};
class NoModulo : public NoExpressao {
    NoExpressao* esq; NoExpressao* dir;
public:
    NoModulo(NoExpressao* e, NoExpressao* d); ~NoModulo();
    ValorTipado avaliar(TabelaSimbolos&) override;
};

enum class OperadorComparacao { Maior, Menor, MaiorIgual, MenorIgual, Igual, Diferente };
class NoComparacao : public NoExpressao {
    NoExpressao* esq; NoExpressao* dir; OperadorComparacao operador;
public:
    NoComparacao(NoExpressao*, NoExpressao*, OperadorComparacao); ~NoComparacao();
    ValorTipado avaliar(TabelaSimbolos&) override;
};

enum class OperadorLogico { E, Ou };
class NoLogico : public NoExpressao {
    NoExpressao* esq; NoExpressao* dir; OperadorLogico operador;
public:
    NoLogico(NoExpressao*, NoExpressao*, OperadorLogico); ~NoLogico();
    ValorTipado avaliar(TabelaSimbolos&) override;
};
class NoNegacao : public NoExpressao {
    NoExpressao* expressao;
public:
    explicit NoNegacao(NoExpressao*); ~NoNegacao();
    ValorTipado avaliar(TabelaSimbolos&) override;
};
class NoMenosUnario : public NoExpressao {
    NoExpressao* expressao;
public:
    explicit NoMenosUnario(NoExpressao*); ~NoMenosUnario();
    ValorTipado avaliar(TabelaSimbolos&) override;
};

class NoGuarde : public NoAST {
    std::string nome; TipoDado tipo; NoExpressao* expressao;
public:
    NoGuarde(const std::string&, TipoDado, NoExpressao*); ~NoGuarde();
    void executar(TabelaSimbolos&) override;
};
class NoAtribuicao : public NoAST {
    std::string nome; NoExpressao* expressao;
public:
    NoAtribuicao(const std::string&, NoExpressao*); ~NoAtribuicao();
    void executar(TabelaSimbolos&) override;
};
struct ParametroFuncao { std::string nome; TipoDado tipo; };
class NoBloco;
class NoFuncao : public NoAST {
    std::string nome; std::vector<ParametroFuncao> parametros; TipoDado retorno; NoBloco* corpo;
public:
    NoFuncao(const std::string&, const std::vector<ParametroFuncao>&, TipoDado, NoBloco*);
    ~NoFuncao();
    void executar(TabelaSimbolos&) override;
    ValorTipado chamar(TabelaSimbolos&, const std::vector<NoExpressao*>&);
};
class NoChamada : public NoExpressao {
    std::string nome; std::vector<NoExpressao*> argumentos;
public:
    NoChamada(const std::string&, const std::vector<NoExpressao*>&); ~NoChamada();
    ValorTipado avaliar(TabelaSimbolos&) override;
};
class NoExibir : public NoAST {
    std::vector<NoExpressao*> expressoes;
public:
    explicit NoExibir(const std::vector<NoExpressao*>&); ~NoExibir();
    void executar(TabelaSimbolos&) override;
};

class NoComentario : public NoAST {
public:
    void executar(TabelaSimbolos&) override {}
};
class NoBloco : public NoAST {
    std::vector<NoAST*> comandos;
public:
    explicit NoBloco(const std::vector<NoAST*>&); ~NoBloco();
    void executar(TabelaSimbolos&) override;
};
class NoPrograma : public NoBloco {
public:
    explicit NoPrograma(const std::vector<NoAST*>& comandos) : NoBloco(comandos) {}
};
class NoCondicional : public NoAST {
    NoExpressao* condicao; NoBloco* entao; NoBloco* senao;
public:
    NoCondicional(NoExpressao*, NoBloco*, NoBloco*); ~NoCondicional();
    void executar(TabelaSimbolos&) override;
};
class NoRepeticao : public NoAST {
    NoExpressao* condicao; NoBloco* corpo;
public:
    NoRepeticao(NoExpressao*, NoBloco*); ~NoRepeticao();
    void executar(TabelaSimbolos&) override;
};
class NoParar : public NoAST { public: void executar(TabelaSimbolos&) override; };
class NoPular : public NoAST { public: void executar(TabelaSimbolos&) override; };
class NoVoltar : public NoAST {
    NoExpressao* expressao;
public:
    explicit NoVoltar(NoExpressao* = nullptr); ~NoVoltar();
    void executar(TabelaSimbolos&) override;
};
class NoObter : public NoAST {
    std::string formato; std::vector<std::string> nomes; std::vector<TipoDado> tipos;
public:
    NoObter(const std::string&, const std::vector<std::string>&, const std::vector<TipoDado>&);
    void executar(TabelaSimbolos&) override;
};

#endif
