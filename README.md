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
  * `vazio`: tipo de retorno para funções sem valor de retorno.
  * `sermão`: instrução destinada a comentários documentados no código.
- **Declaração Explícita de Variáveis:** sintaxe `guarde <id> = <expressão> : <tipo>!`.
- **Operadores:**
  * Aritméticos: `+` (soma e concatenação de `textão`), `-`, `*`, `/` e `%`.
  * Relacionais: `>`, `<`, `>=`, `<=`, `==` e `!=`.
  * Lógicos: `e`, `ou` e `não`.
- **Controle de Fluxo e Repetição:** condicionais com `se`, ramos intermediários `ou se` (**todo encadeamento com `ou se` exige um ramo final `senão` obrigatório**) e ramo alternativo `senão`; laços com `repetir` e desvios `parar!` / `pular!`.
- **Sub-rotinas (Funções):** declaração via `função <nome>(<params>) : <tipo_retorno> abrir ... fechar` e retorno via `voltar!`.
- **Entrada e Saída Nativa:** `exibir(...)!` para saída no console e `obter("<formato>", var1, ...)!` para leitura tipada da entrada padrão (`%t`, `%f`, `%s`, `%tex`).

### Exemplo de Programa (`exemplo.oxi`)
```text
sermão "Cálculo de média e verificação de aprovação"
guarde nota1 = 7.5 : fração!
guarde nota2 = 8.0 : fração!
guarde media = (nota1 + nota2) / 2 : fração!

se (media >= 7.0) abrir
  exibir("Aluno aprovado com media: ", media)!
fechar ou se (media >= 5.0) abrir
  exibir("Aluno em recuperação com media: ", media)!
fechar senão abrir
  exibir("Aluno reprovado.")!
fechar
```

---

## 📚 Documentação Técnica (Etapa 3)

A documentação oficial e atualizada da entrega final está organizada na pasta [`docs/`](docs/):

- [**Especificação da Linguagem e Gramática Formal**](docs/ESPECIFICACAO_E_GRAMATICA.md) — especificação léxica completa, gramática formal em BNF alinhada ao `parser.y`, precedência de operadores e regras semânticas.
- [**Arquitetura Técnica e Decisões de Implementação**](docs/ARQUITETURA.md) — pipeline Flex/Bison/AST, hierarquia de nós da AST, `TabelaSimbolos`, padrão **Interpreter**, desaçucaramento de `ou se` e sistema de diagnósticos.
- [**Plano de Testes e Resultados Esperados**](docs/TESTES.md) — catálogo completo dos 24 testes automatizados (programas oficiais, casos de sucesso e casos de erro) com entradas e saídas esperadas.

*(O arquivo `Documentação da Linguagem Oxítona.pdf` na raiz é mantido apenas como registro histórico da proposta inicial da Etapa 1.)*

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

O projeto conta com um `Makefile` na raiz que automatiza a geração do analisador sintático (`bison -d parser.y`), do analisador léxico (`flex lexer.l`), a compilação conjunta em C++17 (`g++`) e a criação do binário `./oxitona` junto ao seu alias `./oxi`.

1. **Compilar o interpretador (`./oxitona` e alias `./oxi`):**
   ```bash
   make
   ```

2. **Recompilar do zero (limpando artefatos gerados anteriormente):**
   ```bash
   make clean && make
   ```

---

## 🧪 Como Executar os Testes

O repositório inclui os quatro programas oficiais da especificação (`testes/prog1.oxi` a `testes/prog4.oxi`) e uma bateria automatizada de testes de regressão em `testes/casos/`.

### 1. Executar a bateria completa de testes automatizados (24 testes)
Valida os 4 programas oficiais (`prog1.oxi`..`prog4.oxi`) e os 20 casos de regressão (expressões, tipos, atribuições, controle de fluxo, condicionais encadeadas `ou se`, funções, entrada via `obter` e diagnósticos de erro):
```bash
make test
```
*(Ou diretamente via script: `sh testes/testar.sh`)*

### 2. Executar o teste rápido padrão do `Makefile`
Executa o primeiro programa da documentação (`testes/prog1.oxi`):
```bash
make testar
```

### 3. Executar os programas de demonstração da documentação individualmente
```bash
./oxitona testes/prog1.oxi
./oxitona testes/prog2.oxi
./oxitona testes/prog3.oxi
./oxitona testes/prog4.oxi
```

---

## 💻 Como Executar um Arquivo Avulso (`.oxi`)

Para interpretar qualquer código-fonte escrito na linguagem Oxítona, passe o caminho do arquivo `.oxi` como argumento para `./oxitona` (ou para o alias `./oxi`):

```bash
./oxitona caminho/para/arquivo.oxi
# ou usando o alias:
./oxi caminho/para/arquivo.oxi
```

Para consultar rapidamente as opções aceitas na linha de comando, use `--help` (ou `-h`):

```bash
./oxitona --help
```

Os erros são exibidos no formato do GCC, com caminho, linha, coluna, categoria, trecho da fonte e marcador de posição. Para acrescentar o detalhe interno do parser em erros sintáticos, use o modo debug (`--debug` ou `-g`):

```bash
./oxitona --debug caminho/para/arquivo.oxi
```

Os diagnósticos identificam erros léxicos (`lexical error`), sintáticos (`syntax error`), semânticos (`semantic error`) e de execução (`runtime error`), além de erros de abertura de arquivo (`file error`). Verificações de tipos e nomes são feitas durante a execução do interpretador, não em uma etapa separada de compilação.

---

## 🤖 Declaração de Uso de Inteligência Artificial (Seção 8 do Edital)

Em conformidade com a **Seção 8 do edital da disciplina**, declaramos que a equipe utilizou a ferramenta **Google Gemini** (via interface web e **Antigravity CLI**) como recurso de apoio nas seguintes atividades:

- **Auditoria de conformidade** entre o código-fonte implementado e a especificação da linguagem;
- **Auxílio na depuração e refatoração** de módulos internos (tratamento de exceções de controle de fluxo, sistema de diagnósticos de erro e isolamento de escopos);
- **Criação e ampliação de casos de teste automatizados**;
- **Estruturação e revisão da documentação técnica** do projeto.

Todo o código-fonte, todas as decisões arquiteturais e todos os casos de teste foram **revisados, validados e compreendidos integralmente** pelos integrantes da equipe.

---

## 📂 Estrutura do Projeto

```text
.
├── Documentação da Linguagem Oxítona.pdf  # Proposta inicial da linguagem (Etapa 1 - histórico)
├── README.md                              # Guia principal de uso, compilação, testes e declaração de IA
├── Makefile                               # Automação de build (oxitona / oxi), testes e limpeza
├── lexer.l                                # Especificação léxica (Flex)
├── parser.y                               # Gramática LALR(1) e construção da AST (Bison)
├── ast.h                                  # Definição dos nós da AST e Tabela de Símbolos
├── ast.cpp                                # Implementação do interpretador e regras semânticas
├── diagnosticos.h                         # Interface do módulo de diagnósticos de erro
├── diagnosticos.cpp                       # Emissão de erros estilo GCC e suporte ao modo --debug
├── main.cpp                               # Ponto de entrada, flags CLI e integração Flex/Bison/AST
├── docs/
│   ├── ESPECIFICACAO_E_GRAMATICA.md       # Especificação atualizada e gramática formal BNF (Etapa 3)
│   ├── ARQUITETURA.md                     # Documentação técnica da arquitetura e decisões de projeto
│   └── TESTES.md                          # Plano de testes e resultados esperados (24 testes)
└── testes/
    ├── prog1.oxi .. prog4.oxi             # Programas oficiais da documentação
    ├── testar.sh                          # Script de testes automatizados (24 verificações)
    └── casos/                             # 20 casos de regressão (sucesso e erro)
```
