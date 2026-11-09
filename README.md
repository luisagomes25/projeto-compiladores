# Interpretador - Linguagem Oxítona

Projeto de desenvolvimento de um interpretador para a linguagem didática **Oxítona**, construído em C/C++, Flex e Bison, para a disciplina de Compiladores.

## 👥 Equipe
* Gabriel Alves Marques Silva (Infraestrutura, Testes e Analisador Léxico)
* Luis Felipe de Arruda Gomes (Árvore Sintática Abstrata e Interpretador)
* Caio Vinícius B. de Medeiros (Analisador Sintático e Gramática)

## 🚀 Como Compilar e Executar (Ambiente Linux/WSL)

O projeto utiliza um `Makefile` para automatizar a compilação. Certifique-se de ter o `flex`, `bison` e o `gcc`/`g++` instalados no seu ambiente.

1. Compile o projeto:
   ```bash
   make

   Execute o analisador:
   ./analisador_lexico

   Para limpar os arquivos compilados:
   make clean