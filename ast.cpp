#include "ast.h"
#include <cmath>

namespace {
double numero(const ValorTipado& v) {
    if (std::holds_alternative<int>(v.valor)) return std::get<int>(v.valor);
    if (std::holds_alternative<double>(v.valor)) return std::get<double>(v.valor);
    throw std::runtime_error("Operação numérica exige valor numérico.");
}
struct SinalParar {};
struct SinalPular {};
struct SinalRetorno { bool possui_valor; ValorTipado valor; };
bool numerico(const ValorTipado& v) { return std::holds_alternative<int>(v.valor) || std::holds_alternative<double>(v.valor); }
ValorTipado resultado_numerico(double v, bool fracao) {
    return fracao ? ValorTipado{TipoDado::Fracao, v} : ValorTipado{TipoDado::Total, static_cast<int>(v)};
}
void exigir_sinal(const ValorTipado& v) { if (!std::holds_alternative<bool>(v.valor)) throw std::runtime_error("A condição exige um valor do tipo sinal."); }
}

std::string valor_para_string(const ValorTipado& v) {
    if (std::holds_alternative<int>(v.valor)) return std::to_string(std::get<int>(v.valor));
    if (std::holds_alternative<double>(v.valor)) { std::string s = std::to_string(std::get<double>(v.valor)); while (s.back() == '0') s.pop_back(); if (s.back() == '.') s.pop_back(); return s; }
    if (std::holds_alternative<bool>(v.valor)) return std::get<bool>(v.valor) ? "fiel" : "fatal";
    return std::get<std::string>(v.valor);
}
bool valor_verdadeiro(const ValorTipado& v) { exigir_sinal(v); return std::get<bool>(v.valor); }
bool valor_compativel(TipoDado destino, const ValorTipado& v) {
    if (destino == TipoDado::Fracao && (v.tipo == TipoDado::Total || v.tipo == TipoDado::Fracao)) return true;
    return destino == v.tipo;
}
ValorTipado converter_valor(TipoDado destino, const ValorTipado& v) {
    if (!valor_compativel(destino, v)) throw std::runtime_error("Tipos incompatíveis na atribuição.");
    if (destino == TipoDado::Fracao && v.tipo == TipoDado::Total) return {destino, static_cast<double>(std::get<int>(v.valor))};
    return {destino, v.valor};
}

bool TabelaSimbolos::existe(const std::string& n) const { return variaveis.find(n) != variaveis.end() || (pai && pai->existe(n)); }
const ValorTipado& TabelaSimbolos::obter(const std::string& n) const { auto i = variaveis.find(n); if (i != variaveis.end()) return i->second; if (pai) return pai->obter(n); throw std::runtime_error("Variável '" + n + "' não declarada."); }
void TabelaSimbolos::definir(const std::string& n, TipoDado tipo, const ValorTipado& v) { if (existe(n)) throw std::runtime_error("Variável '" + n + "' já declarada."); variaveis[n] = converter_valor(tipo, v); }
void TabelaSimbolos::atribuir(const std::string& n, const ValorTipado& v) { auto i = variaveis.find(n); if (i != variaveis.end()) { i->second = converter_valor(i->second.tipo, v); return; } if (pai) { pai->atribuir(n, v); return; } throw std::runtime_error("Variável '" + n + "' não declarada."); }
void TabelaSimbolos::registrar_funcao(const std::string& n, NoFuncao* f) { funcoes[n] = f; }
NoFuncao* TabelaSimbolos::obter_funcao(const std::string& n) const { auto i=funcoes.find(n); if(i!=funcoes.end()) return i->second; if(pai)return pai->obter_funcao(n); return nullptr; }

NoLiteral::NoLiteral(const ValorTipado& v) : valor(v) {} ValorTipado NoLiteral::avaliar(TabelaSimbolos&) { return valor; }
NoVariavel::NoVariavel(const std::string& n) : nome(n) {} ValorTipado NoVariavel::avaliar(TabelaSimbolos& t) { return t.obter(nome); }

#define BIN_IMPL(NOME, OP) \
NOME::NOME(NoExpressao* e, NoExpressao* d) : esq(e), dir(d) {} \
NOME::~NOME() { delete esq; delete dir; }

BIN_IMPL(NoSoma, +) ValorTipado NoSoma::avaliar(TabelaSimbolos& t) { auto a=esq->avaliar(t), b=dir->avaliar(t); if (a.tipo==TipoDado::Textao && b.tipo==TipoDado::Textao) return {TipoDado::Textao, std::get<std::string>(a.valor)+std::get<std::string>(b.valor)}; if (!numerico(a)||!numerico(b)) throw std::runtime_error("Soma exige números ou dois textões."); return resultado_numerico(numero(a)+numero(b), a.tipo==TipoDado::Fracao||b.tipo==TipoDado::Fracao); }
BIN_IMPL(NoSubtracao, -) ValorTipado NoSubtracao::avaliar(TabelaSimbolos& t) { auto a=esq->avaliar(t), b=dir->avaliar(t); if (!numerico(a)||!numerico(b)) throw std::runtime_error("Subtração exige números."); return resultado_numerico(numero(a)-numero(b), a.tipo==TipoDado::Fracao||b.tipo==TipoDado::Fracao); }
BIN_IMPL(NoMultiplicacao, *) ValorTipado NoMultiplicacao::avaliar(TabelaSimbolos& t) { auto a=esq->avaliar(t), b=dir->avaliar(t); if (!numerico(a)||!numerico(b)) throw std::runtime_error("Multiplicação exige números."); return resultado_numerico(numero(a)*numero(b), a.tipo==TipoDado::Fracao||b.tipo==TipoDado::Fracao); }
BIN_IMPL(NoDivisao, /) ValorTipado NoDivisao::avaliar(TabelaSimbolos& t) { auto a=esq->avaliar(t), b=dir->avaliar(t); if (!numerico(a)||!numerico(b)||numero(b)==0) throw std::runtime_error("Divisão inválida."); return {TipoDado::Fracao, numero(a)/numero(b)}; }
BIN_IMPL(NoModulo, %) ValorTipado NoModulo::avaliar(TabelaSimbolos& t) { auto a=esq->avaliar(t), b=dir->avaliar(t); if (a.tipo!=TipoDado::Total||b.tipo!=TipoDado::Total||std::get<int>(b.valor)==0) throw std::runtime_error("Módulo exige inteiros e divisor diferente de zero."); return {TipoDado::Total, std::get<int>(a.valor)%std::get<int>(b.valor)}; }

NoComparacao::NoComparacao(NoExpressao* e, NoExpressao* d, OperadorComparacao o):esq(e),dir(d),operador(o){} NoComparacao::~NoComparacao(){delete esq;delete dir;}
ValorTipado NoComparacao::avaliar(TabelaSimbolos& t){auto a=esq->avaliar(t),b=dir->avaliar(t); bool r=false; if(operador==OperadorComparacao::Igual||operador==OperadorComparacao::Diferente){if(a.tipo==TipoDado::Textao&&b.tipo==TipoDado::Textao)r=std::get<std::string>(a.valor)==std::get<std::string>(b.valor);else if(numerico(a)&&numerico(b))r=numero(a)==numero(b);else if(a.tipo==TipoDado::Sinal&&b.tipo==TipoDado::Sinal)r=std::get<bool>(a.valor)==std::get<bool>(b.valor);else throw std::runtime_error("Valores incompatíveis na comparação."); if(operador==OperadorComparacao::Diferente)r=!r;}else{if(!numerico(a)||!numerico(b))throw std::runtime_error("Comparação relacional exige números.");double x=numero(a),y=numero(b);if(operador==OperadorComparacao::Maior)r=x>y;else if(operador==OperadorComparacao::Menor)r=x<y;else if(operador==OperadorComparacao::MaiorIgual)r=x>=y;else r=x<=y;}return {TipoDado::Sinal,r};}
NoLogico::NoLogico(NoExpressao*e,NoExpressao*d,OperadorLogico o):esq(e),dir(d),operador(o){} NoLogico::~NoLogico(){delete esq;delete dir;} ValorTipado NoLogico::avaliar(TabelaSimbolos&t){bool a=valor_verdadeiro(esq->avaliar(t)),b=valor_verdadeiro(dir->avaliar(t));return{TipoDado::Sinal,operador==OperadorLogico::E?a&&b:a||b};}
NoNegacao::NoNegacao(NoExpressao*e):expressao(e){} NoNegacao::~NoNegacao(){delete expressao;} ValorTipado NoNegacao::avaliar(TabelaSimbolos&t){return{TipoDado::Sinal,!valor_verdadeiro(expressao->avaliar(t))};}
NoMenosUnario::NoMenosUnario(NoExpressao*e):expressao(e){} NoMenosUnario::~NoMenosUnario(){delete expressao;} ValorTipado NoMenosUnario::avaliar(TabelaSimbolos&t){auto v=expressao->avaliar(t);if(!numerico(v))throw std::runtime_error("Sinal negativo exige número.");return v.tipo==TipoDado::Total?ValorTipado{v.tipo,-std::get<int>(v.valor)}:ValorTipado{v.tipo,-std::get<double>(v.valor)};}

NoGuarde::NoGuarde(const std::string&n,TipoDado ty,NoExpressao*e):nome(n),tipo(ty),expressao(e){} NoGuarde::~NoGuarde(){delete expressao;} void NoGuarde::executar(TabelaSimbolos&t){t.definir(nome,tipo,expressao->avaliar(t));}
NoAtribuicao::NoAtribuicao(const std::string&n,NoExpressao*e):nome(n),expressao(e){} NoAtribuicao::~NoAtribuicao(){delete expressao;} void NoAtribuicao::executar(TabelaSimbolos&t){t.atribuir(nome,expressao->avaliar(t));}
NoFuncao::NoFuncao(const std::string&n,const std::vector<ParametroFuncao>&p,TipoDado r,NoBloco*b):nome(n),parametros(p),retorno(r),corpo(b){} NoFuncao::~NoFuncao(){delete corpo;} void NoFuncao::executar(TabelaSimbolos&t){t.registrar_funcao(nome,this);}
ValorTipado NoFuncao::chamar(TabelaSimbolos& pai_tabela,const std::vector<NoExpressao*>& args){if(args.size()!=parametros.size())throw std::runtime_error("Quantidade de argumentos inválida na função '"+nome+"'."); TabelaSimbolos local(&pai_tabela); for(size_t i=0;i<args.size();++i)local.definir(parametros[i].nome,parametros[i].tipo,args[i]->avaliar(pai_tabela)); try{corpo->executar(local);}catch(const SinalRetorno& r){if(retorno==TipoDado::Vazio){if(r.possui_valor)throw std::runtime_error("Função '"+nome+"' não pode retornar valor.");return{TipoDado::Vazio,0};}if(!r.possui_valor)throw std::runtime_error("Função '"+nome+"' precisa retornar um valor.");return converter_valor(retorno,r.valor);} if(retorno!=TipoDado::Vazio)throw std::runtime_error("Função '"+nome+"' terminou sem retornar valor.");return{TipoDado::Vazio,0};}
NoChamada::NoChamada(const std::string&n,const std::vector<NoExpressao*>&a):nome(n),argumentos(a){} NoChamada::~NoChamada(){for(auto a:argumentos)delete a;} ValorTipado NoChamada::avaliar(TabelaSimbolos&t){NoFuncao*f=t.obter_funcao(nome);if(!f)throw std::runtime_error("Função '"+nome+"' não declarada.");return f->chamar(t,argumentos);}
NoExibir::NoExibir(const std::vector<NoExpressao*>&e):expressoes(e){} NoExibir::~NoExibir(){for(auto e:expressoes)delete e;} void NoExibir::executar(TabelaSimbolos&t){for(auto e:expressoes)std::cout<<valor_para_string(e->avaliar(t));std::cout<<std::endl;}
NoBloco::NoBloco(const std::vector<NoAST*>&c):comandos(c){} NoBloco::~NoBloco(){for(auto c:comandos)delete c;} void NoBloco::executar(TabelaSimbolos&t){for(auto c:comandos)c->executar(t);}
NoCondicional::NoCondicional(NoExpressao*c,NoBloco*a,NoBloco*s):condicao(c),entao(a),senao(s){} NoCondicional::~NoCondicional(){delete condicao;delete entao;delete senao;} void NoCondicional::executar(TabelaSimbolos&t){if(valor_verdadeiro(condicao->avaliar(t)))entao->executar(t);else if(senao)senao->executar(t);}
NoRepeticao::NoRepeticao(NoExpressao*c,NoBloco*b):condicao(c),corpo(b){} NoRepeticao::~NoRepeticao(){delete condicao;delete corpo;} void NoRepeticao::executar(TabelaSimbolos&t){while(valor_verdadeiro(condicao->avaliar(t))){try{corpo->executar(t);}catch(const SinalParar&){break;}catch(const SinalPular&){}}}
void NoParar::executar(TabelaSimbolos&){throw SinalParar();} void NoPular::executar(TabelaSimbolos&){throw SinalPular();}
NoVoltar::NoVoltar(NoExpressao*e):expressao(e){} NoVoltar::~NoVoltar(){delete expressao;} void NoVoltar::executar(TabelaSimbolos&t){if(expressao)throw SinalRetorno{true,expressao->avaliar(t)};throw SinalRetorno{false,{TipoDado::Vazio,0}};}
NoObter::NoObter(const std::vector<std::string>&n,const std::vector<TipoDado>&t):nomes(n),tipos(t){} void NoObter::executar(TabelaSimbolos&t){for(size_t i=0;i<nomes.size();++i){if(!t.existe(nomes[i]))throw std::runtime_error("Variável '"+nomes[i]+"' não declarada no obter.");if(tipos[i]==TipoDado::Total){int v;if(!(std::cin>>v))throw std::runtime_error("Entrada inválida para total.");t.atribuir(nomes[i],{TipoDado::Total,v});}else if(tipos[i]==TipoDado::Fracao){double v;if(!(std::cin>>v))throw std::runtime_error("Entrada inválida para fração.");t.atribuir(nomes[i],{TipoDado::Fracao,v});}else if(tipos[i]==TipoDado::Sinal){std::string v;std::cin>>v;if(v!="fiel"&&v!="fatal")throw std::runtime_error("Entrada inválida para sinal.");t.atribuir(nomes[i],{TipoDado::Sinal,v=="fiel"});}else{std::string v;std::cin>>v;t.atribuir(nomes[i],{TipoDado::Textao,v});}}}
