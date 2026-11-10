# Interpretador da Linguagem Oxítona

Interpretador completo para a linguagem de programação didática **Oxítona**, desenvolvido em **C++17**, **Flex** e **Bison** como projeto prático da disciplina de Compiladores.

---

## 👥 Integrantes da Equipe

- **Luis Felipe de Arruda Gomes** — Árvore Sintática Abstrata (AST) e Núcleo de Execução (Interpretador)
- **Caio Vinícius B. de Medeiros** — Analisador Sintático (Bison) e Gramática Livre de Contexto
- **Gabriel Alves Marques Silva** — Infraestrutura, Testes Automatizados e Analisador Léxico (Flex)

---

## 📖 Sobre a Linguagem Oxítona

A **Oxítona** é uma linguagem de programação imperativa, fortemente tipada e com sintaxe expressiva em língua portuguesa. Seu nome deriva de sua principal característica sintática: **toda instrução simples deve ser enfatizada no final pelo caractere de exclamação (`!`)**, enquanto blocos de código são delimitados explicitamente pelas palavras-chave `abrir` e `fechar`.

### Principais Características
- **Tipos de Dados:**
  * `total`: números inteiros (ex.: `10`, `-3`).
  * `fração`: números em ponto flutuante (ex.: `3.14`, `2.5`).
  * `sinal`: valores lógicos booleanos (`fiel` para verdadeiro e `fatal` para falso).
  * `textão`: cadeias de caracteres delimitadas por aspas duplas (ex.: `"Olá, Oxítona"`).
  * `sermão`: instrução destinada a comentários documentados no código.
- **Declaração Explícita de Variáveis:** sintaxe `guarde <id> = <expressão> : <tipo>!`.
- **Operadores:**
  * Aritméticos: `+` (soma e concatenação de `textão`), `-`, `*`, `/` e `%`.
  * Relacionais: `>`, `<`, `>=`, `<=`, `==` e `!=`.
  * Lógicos: `e`, `ou` e `não`.
- **Controle de Fluxo e Repetição:** condicionais com `testar` / `senão` e laços com `repetir`, incluindo desvios de fluxo `parar!` e `pular!`.
- **Sub-rotinas (Funções):** declaração via `função <nome>(<params>) : <tipo_retorno> abrir ... fechar` e retorno via `voltar!`.
- **Entrada e Saída Nativa:** `exibir(...)!` para saída no console e `obter("<formato>", var1, ...)!` para leitura tipada da entrada padrão (`%t`, `%f`, `%s`, `%tex`).

### Exemplo de Programa (`exemplo.oxi`)
```text
sermão "Cálculo de média e verificação de aprovação"
guarde nota1 = 7.5 : fração!
guarde nota2 = 8.0 : fração!
guarde media = (nota1 + nota2) / 2 : fração!

testar (media >= 7.0) abrir
  exibir("Aluno aprovado com media: ", media)!
fechar senão abrir
  exibir("Aluno reprovado.")!
fechar
```

---

## 🛠️ Pré-requisitos

Para compilar e executar o projeto em ambiente **Linux** ou **WSL (Windows Subsystem for Linux)**, certifique-se de ter instalados:

- **g++** (com suporte a C++17 ou superior)
- **Flex** (Fast Lexical Analyzer Generator)
- **Bison** (GNU Parser Generator)
- **Make**

Em distribuições baseadas em Debian/Ubuntu, instale as dependências com:
```bash
sudo apt update && sudo apt install -y build-essential flex bison
```

---

## 🚀 Como Compilar o Projeto

O projeto conta com um `Makefile` na raiz que automatiza a geração do analisador sintático (`bison -d parser.y`), do analisador léxico (`flex lexer.l`) e a compilação conjunta com a AST em C++17 (`g++`).

1. **Compilar o interpretador (`./oxitona`):**
   ```bash
   make
   ```

2. **Recompilar do zero (limpando artefatos gerados anteriormente):**
   ```bash
   make clean && make
   ```

---

## 🧪 Como Executar os Testes

O repositório inclui tanto os quatro programas oficiais da especificação (`testes/prog1.oxi` a `testes/prog4.oxi`) quanto uma bateria automatizada de testes de regressão em `testes/casos/`.

### 1. Executar a bateria completa de testes automatizados (12 casos)
Valida expressões, tipos, atribuições, controle de fluxo, funções, entrada via `obter` e tratamento de erros semânticos/execução:
```bash
make test
```
*(Ou diretamente via script: `sh testes/testar.sh`)*

### 2. Executar o teste rápido padrão do `Makefile`
Executa o primeiro programa da documentação (`testes/prog1.oxi`):
```bash
make testar
```

### 3. Executar os programas de demonstração da documentação
```bash
./oxitona testes/prog1.oxi
./oxitona testes/prog2.oxi
./oxitona testes/prog3.oxi
./oxitona testes/prog4.oxi
```

---

## 💻 Como Executar um Arquivo Avulso (`.oxi`)

Para interpretar qualquer código-fonte escrito na linguagem Oxítona, passe o caminho do arquivo `.oxi` como argumento para o binário `./oxitona`:

```bash
./oxitona caminho/para/arquivo.oxi
```

---

## 📂 Estrutura do Projeto

```text
.
├── Documentação da Linguagem Oxítona.pdf  # Especificação léxica, sintática e semântica
├── Makefile                               # Automação de build e execução de testes
├── lexer.l                                # Especificação léxica (Flex)
├── parser.y                               # Gramática e construção da AST (Bison)
├── ast.h                                  # Definição dos nós da AST e Tabela de Símbolos
├── ast.cpp                                # Implementação da execução e regras semânticas
├── main.cpp                               # Ponto de entrada e integração Flex/Bison/AST
└── testes/
    ├── prog1.oxi .. prog4.oxi             # Programas de exemplo da documentação oficial
    ├── testar.sh                          # Script de testes automatizados
    └── casos/                             # Casos de teste de sucesso e de erro
```