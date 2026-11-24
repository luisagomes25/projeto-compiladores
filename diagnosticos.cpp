#include "diagnosticos.h"

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

namespace {
std::string arquivo_fonte;
bool modo_debug = false;

std::string expandir_tabs(const std::string& texto) {
    std::string resultado;
    int coluna = 0;
    for (char caractere : texto) {
        if (caractere == '\t') {
            int espacos = 8 - (coluna % 8);
            resultado.append(espacos, ' ');
            coluna += espacos;
        } else {
            resultado += caractere;
            if ((static_cast<unsigned char>(caractere) & 0xC0) != 0x80) ++coluna;
        }
    }
    return resultado;
}
}

void diagnostico::configurar(const std::string& arquivo, bool debug) {
    arquivo_fonte = arquivo;
    modo_debug = debug;
}

void diagnostico::emitir(const std::string& categoria, int linha, int coluna, int extensao,
                         const std::string& mensagem, const std::string& detalhe_debug) {
    std::cerr << arquivo_fonte;
    if (linha > 0) std::cerr << ':' << linha;
    if (linha > 0 && coluna > 0) std::cerr << ':' << coluna;
    std::cerr << ": error: " << categoria << ": " << mensagem << '\n';

    if (linha <= 0) return;

    std::ifstream fonte(arquivo_fonte);
    std::string texto;
    bool exibiu_contexto = false;
    for (int atual = 1; atual <= linha && std::getline(fonte, texto); ++atual) {
        if (atual == linha) {
            int largura = static_cast<int>(std::to_string(linha).size());
            std::cerr << ' ' << std::setw(largura) << atual << " | " << expandir_tabs(texto) << '\n';
            std::cerr << std::string(largura + 2, ' ') << " | "
                      << std::string(std::max(0, coluna - 1), ' ')
                      << std::string(std::max(1, extensao), '^') << '\n';
            exibiu_contexto = true;
            break;
        }
    }
    if (!exibiu_contexto) {
        int largura = static_cast<int>(std::to_string(linha).size());
        std::cerr << ' ' << std::setw(largura) << linha << " |\n";
        std::cerr << std::string(largura + 2, ' ') << " | "
                  << std::string(std::max(0, coluna - 1), ' ')
                  << std::string(std::max(1, extensao), '^') << '\n';
    }

    if (modo_debug && !detalhe_debug.empty())
        std::cerr << "note: parser: " << detalhe_debug << '\n';
}

void diagnostico::erro_de_argumentos(const std::string& mensagem) {
    std::cerr << "oxi: error: " << mensagem << '\n';
}
