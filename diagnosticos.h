#ifndef DIAGNOSTICOS_H
#define DIAGNOSTICOS_H

#include <string>

namespace diagnostico {
void configurar(const std::string& arquivo, bool debug);
void emitir(const std::string& categoria, int linha, int coluna, int extensao,
            const std::string& mensagem, const std::string& detalhe_debug = "");
void erro_de_argumentos(const std::string& mensagem);
}

#endif
