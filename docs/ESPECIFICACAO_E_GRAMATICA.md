# Especificação da Linguagem e Gramática Formal — Oxítona (Etapa 3)

> **Nota de versão:** Este documento constitui a **especificação oficial e atualizada da Etapa 3 (Entrega Final)** da linguagem **Oxítona**, refletindo integralmente a implementação final presente em `lexer.l`, `parser.y`, `ast.h`, `ast.cpp` e `diagnosticos.cpp`. O arquivo `Documentação da Linguagem Oxítona.pdf` na raiz do repositório é mantido apenas como registro histórico da proposta inicial (Etapa 1).

---

## 1. Evoluções em Relação à Proposta Inicial (Etapa 1)

Entre a especificação inicial e a entrega final, a linguagem passou pelos seguintes refinamentos documentados:

1. **Condicionais (`testar` → `se` e adição de `ou se`):** a palavra-chave condicional foi renomeada de `testar` para `se` para maior naturalidade em língua portuguesa, e foi introduzido o encadeamento `ou se` (com `senão` final obrigatório).
2. **Padrão de execução (`Visitor` → `Interpreter`):** optou-se pelo padrão **Interpreter** diretamente nos nós da AST (`executar()` e `avaliar()`), detalhado em [`ARQUITETURA.md`](ARQUITETURA.md).
3. **Verificação semântica em tempo de execução:** a verificação de tipos, declarações e chamadas ocorre durante a interpretação da AST (e não em fase separada pré-execução), com exceção da validação dos especificadores de formato de `obter`, verificados ainda durante a análise sintática (`semantic error`).
4. **Diagnósticos no padrão GCC:** adicionado suporte a mensagens detalhadas com caminho, linha, coluna (com contagem correta de UTF-8), trecho do código-fonte, marcador `^` e modo `--debug` / `-g`.

---

## 2. Especificação Léxica (`lexer.l`)

A linguagem Oxítona é **estritamente _case-sensitive_** e suporta palavras-chave acentuadas em UTF-8. Espaços em branco, tabulações (`\t`), retornos de carro (`\r`) e quebras de linha (`\n`) são ignorados pelo analisador léxico (`[ \t\n\r]+`), sendo utilizados internamente na macro `YY_USER_ACTION` para manter linha e coluna atualizadas.

### 2.1 Palavras Reservadas

| Categoria | Lexema | Token (Bison) | Descrição |
| :--- | :--- | :--- | :--- |
| Declaração | `guarde` | `TOKEN_GUARDE` | Declara uma variável tipada |
| Condicional | `se` | `TOKEN_SE` | Inicia estrutura condicional |
| Condicional | `senão` | `TOKEN_SENAO` | Ramo alternativo de condicional |
| Repetição | `repetir` | `TOKEN_REPETIR` | Laço condicional (equivalente a `while`) |
| Blocos | `abrir` | `TOKEN_ABRIR` | Abre bloco de comandos |
| Blocos | `fechar` | `TOKEN_FECHAR` | Fecha bloco de comandos |
| E/S | `exibir` | `TOKEN_EXIBIR` | Imprime valores na saída padrão |
| E/S | `obter` | `TOKEN_OBTER` | Lê valores formatados da entrada padrão |
| Controle de fluxo | `parar` | `TOKEN_PARAR` | Interrompe laço `repetir` (`break`) |
| Controle de fluxo | `pular` | `TOKEN_PULAR` | Avança para próxima iteração (`continue`) |
| Sub-rotinas | `função` | `TOKEN_FUNCAO` | Declara função |
| Sub-rotinas | `voltar` | `TOKEN_VOLTAR` | Retorna de uma função (`return`) |
| Comentário | `sermão` | `TOKEN_SERMAO` | Comando de comentário textual |
| Tipo primitivo | `total` | `TOKEN_TIPO_TOTAL` | Número inteiro (`int`) |
| Tipo primitivo | `fração` | `TOKEN_TIPO_FRACAO` | Número em ponto flutuante (`double`) |
| Tipo primitivo | `sinal` | `TOKEN_TIPO_SINAL` | Valor lógico booleano (`bool`) |
| Tipo primitivo | `textão` / `textao` | `TOKEN_TIPO_TEXTAO` | Cadeia de caracteres (`std::string`) |
| Tipo de retorno | `vazio` | `TOKEN_TIPO_VAZIO` | Ausência de valor de retorno em função |
| Literal lógico | `fiel` | `TOKEN_FIEL` | Verdadeiro (`true`) |
| Literal lógico | `fatal` | `TOKEN_FATAL` | Falso (`false`) |
| Operador lógico | `e` | `TOKEN_E` | Conjunção lógica (`&&`) |
| Operador lógico | `ou` | `TOKEN_OU` | Disjunção lógica (`\|\|`) e prefixo de `ou se` |
| Operador lógico | `não` | `TOKEN_NAO` | Negação lógica (`!`) |

### 2.2 Operadores e Delimitadores

| Símbolo | Token (Bison) | Finalidade |
| :--- | :--- | :--- |
| `!` | `TOKEN_TERMINADOR` | Terminador obrigatório de instruções simples |
| `:` | `TOKEN_DOIS_PONTOS` | Separador de anotação de tipo |
| `=` | `TOKEN_ATRIBUICAO` | Atribuição de valor |
| `,` | `TOKEN_VIRGULA` | Separador de argumentos, parâmetros e variáveis |
| `(` / `)` | `TOKEN_PAREN_ESQ` / `TOKEN_PAREN_DIR` | Agrupamento de expressões, condições e chamadas |
| `+`, `-`, `*`, `/`, `%` | `TOKEN_SOMA`, `TOKEN_SUBTRACAO`, `TOKEN_MULTIPLICACAO`, `TOKEN_DIVISAO`, `TOKEN_MODULO` | Operadores aritméticos (e concatenação com `+`) |
| `>`, `<`, `>=`, `<=`, `==`, `!=` | `TOKEN_MAIOR`, `TOKEN_MENOR`, `TOKEN_MAIOR_IGUAL`, `TOKEN_MENOR_IGUAL`, `TOKEN_IGUALDADE`, `TOKEN_DIFERENTE` | Operadores relacionais e de igualdade |

### 2.3 Identificadores, Literais e Erros Léxicos

| Padrão (Regex Flex) | Token (Bison) | Descrição |
| :--- | :--- | :--- |
| `[a-zA-Z_][a-zA-Z0-9_]*` | `TOKEN_ID` | Identificadores de variáveis e funções |
| `[0-9]+` | `TOKEN_NUM_TOTAL` | Literal inteiro (`total`) |
| `[0-9]+\.[0-9]+` | `TOKEN_NUM_FRACAO` | Literal decimal (`fração`) |
| `\"[^\"]*\"` | `TOKEN_TEXTO` | Literal textual (`textão`), sem quebra interna de aspas |
| `.` (qualquer outro caractere) | `TOKEN_ERRO` | Emite diagnóstico `lexical error` e sinaliza erro ao parser |

---

## 3. Gramática Formal (BNF)

A gramática abaixo corresponde exatamente às produções implementadas em `parser.y`. Ela é **LALR(1) livre de conflitos** (0 conflitos _shift/reduce_ e 0 conflitos _reduce/reduce_ verificados pelo GNU Bison).

```bnf
<programa>             ::= <lista_comandos>

<lista_comandos>       ::= ε
                         | <lista_comandos> <comando>

<comando>              ::= <comentario>
                         | <declaracao>
                         | <atribuicao>
                         | <chamada_comando>
                         | <exibicao>
                         | <entrada>
                         | <condicional>
                         | <repeticao>
                         | <controle_fluxo>
                         | <funcao>
                         | <retorno>

<comentario>           ::= "sermão" TOKEN_TEXTO

<declaracao>           ::= "guarde" TOKEN_ID "=" <expressao> ":" <tipo> "!"

<atribuicao>           ::= TOKEN_ID "=" <expressao> "!"

<chamada_comando>      ::= TOKEN_ID "(" <argumentos_opcionais> ")" "!"

<tipo>                 ::= "total"
                         | "fração"
                         | "sinal"
                         | "textão"

<exibicao>             ::= "exibir" "(" <argumentos> ")" "!"

<entrada>              ::= "obter" "(" TOKEN_TEXTO "," <lista_ids> ")" "!"

<condicional>          ::= "se" "(" <expressao> ")" <bloco> <senao_opcional>

<senao_opcional>       ::= ε
                         | "senão" <bloco>
                         | <encadeamento_ou>

<encadeamento_ou>      ::= "ou" "se" "(" <expressao> ")" <bloco> "senão" <bloco>
                         | "ou" "se" "(" <expressao> ")" <bloco> <encadeamento_ou>

<repeticao>            ::= "repetir" "(" <expressao> ")" <bloco>

<bloco>                ::= "abrir" <lista_comandos> "fechar"

<controle_fluxo>       ::= "parar" "!"
                         | "pular" "!"

<funcao>               ::= "função" TOKEN_ID "(" <parametros_opcionais> ")" ":" <tipo_retorno> <bloco>

<retorno>              ::= "voltar" "!"
                         | "voltar" <expressao> "!"

<tipo_retorno>         ::= <tipo>
                         | "vazio"

<parametros_opcionais> ::= ε
                         | <parametros>

<parametros>           ::= TOKEN_ID ":" <tipo>
                         | <parametros> "," TOKEN_ID ":" <tipo>

<lista_ids>            ::= TOKEN_ID
                         | <lista_ids> "," TOKEN_ID

<argumentos_opcionais> ::= ε
                         | <argumentos>

<argumentos>           ::= <expressao>
                         | <argumentos> "," <expressao>

<expressao>            ::= TOKEN_NUM_TOTAL
                         | TOKEN_NUM_FRACAO
                         | TOKEN_TEXTO
                         | "fiel"
                         | "fatal"
                         | TOKEN_ID
                         | TOKEN_ID "(" <argumentos_opcionais> ")"
                         | "(" <expressao> ")"
                         | "-" <expressao>
                         | "não" <expressao>
                         | <expressao> "+" <expressao>
                         | <expressao> "-" <expressao>
                         | <expressao> "*" <expressao>
                         | <expressao> "/" <expressao>
                         | <expressao> "%" <expressao>
                         | <expressao> ">" <expressao>
                         | <expressao> "<" <expressao>
                         | <expressao> ">=" <expressao>
                         | <expressao> "<=" <expressao>
                         | <expressao> "==" <expressao>
                         | <expressao> "!=" <expressao>
                         | <expressao> "e" <expressao>
                         | <expressao> "ou" <expressao>
```

### 3.1 Regra Específica do Encadeamento `ou se`

Conforme definido em `<senao_opcional>` e `<encadeamento_ou>`:
- Um comando `se (...) abrir ... fechar` pode existir sozinho ou acompanhado de `senão abrir ... fechar`.
- Quando há um ou mais ramos intermediários `ou se (...) abrir ... fechar`, **o encadeamento exige obrigatoriamente um ramo final `senão abrir ... fechar`**.
- Essa escolha garante fechamento exaustivo de decisões encadeadas e evita qualquer ambiguidade com o operador lógico `ou` ou com estruturas aninhadas:
  - `ou se` sem `se` anterior é rejeitado (`syntax error`).
  - `ou se` após `senão` é rejeitado (`syntax error`).
  - `se ... fechar ou se ... fechar` sem `senão` final é rejeitado (`syntax error`).

---

## 4. Precedência e Associatividade de Operadores

Listados da **menor** para a **maior** precedência (conforme declarações `%left` / `%right` em `parser.y`):

| Nível | Operadores | Associatividade | Categoria |
| :---: | :--- | :--- | :--- |
| 1 (menor) | `ou` | Esquerda | Disjunção lógica |
| 2 | `e` | Esquerda | Conjunção lógica |
| 3 | `==`, `!=` | Esquerda | Igualdade e desigualdade |
| 4 | `>`, `<`, `>=`, `<=` | Esquerda | Comparação relacional |
| 5 | `+`, `-` | Esquerda | Adição/concatenação e subtração |
| 6 | `*`, `/`, `%` | Esquerda | Multiplicação, divisão e módulo |
| 7 | `não` | Direita (unário) | Negação lógica |
| 8 (maior) | `-` (`UMINUS`) | Direita (unário) | Menos unário |

Parênteses `( ... )` sobrescrevem a precedência padrão.

---

## 5. Regras Semânticas e Sistema de Tipos

### 5.1 Tipos e Conversões
- **Declaração obrigatória:** toda variável deve ser declarada com `guarde <id> = <expr> : <tipo>!` antes de ser lida ou reatribuída. Não é permitido redeclarar uma variável já visível no escopo atual ou em escopos ancestrais.
- **Compatibilidade e promoção implícita:** atribuições, inicializações, passagens de argumento e retornos exigem tipo exato, com uma única promoção implícita permitida: valores `total` são promovidos automaticamente para `fração` quando o destino é `fração`. A conversão inversa (`fração` → `total`) gera `runtime error`.

### 5.2 Operações
- **Soma (`+`):** aceita dois números (`total`/`fração`) ou dois `textão` (concatenação). Misturar `textão` com número ou `sinal` gera `runtime error`.
- **Subtração (`-`) e Multiplicação (`*`):** exigem operandos numéricos; retornam `fração` se qualquer operando for `fração`, caso contrário `total`.
- **Divisão (`/`):** exige operandos numéricos e divisor diferente de zero. `total / total` realiza divisão inteira (`total`); caso haja `fração`, realiza divisão em ponto flutuante (`fração`). Divisão por zero gera `runtime error`.
- **Módulo (`%`):** exige dois operandos `total` e divisor diferente de zero.
- **Comparação relacional (`>`, `<`, `>=`, `<=`):** exige dois operandos numéricos e retorna `sinal`.
- **Igualdade (`==`, `!=`):** compara dois `textão`, dois números (`total`/`fração`) ou dois `sinal`, retornando `sinal`.
- **Operadores lógicos (`e`, `ou`, `não`) e condições (`se`, `ou se`, `repetir`):** exigem estritamente valores do tipo `sinal` (`fiel` ou `fatal`). Não há conversão implícita de números ou textos para booleano.

### 5.3 Entrada Formatada (`obter`)
A instrução `obter("<formato>", id1, id2, ...)!`:
- Valida **em tempo de análise sintática (`semantic error`)** se todos os especificadores presentes na string de formato são válidos (`%t` para `total`, `%f` para `fração`, `%s` para `sinal`, `%tex` para `textão`) e se a quantidade de especificadores corresponde exatamente ao número de variáveis informadas.
- Em tempo de execução, exibe o texto do formato sem os marcadores como prompt, verifica se cada variável foi declarada e valida o dado lido na entrada padrão (para `sinal`, aceita apenas `fiel` ou `fatal`).

### 5.4 Escopos e Funções
- Todo bloco `abrir ... fechar` cria um escopo filho na `TabelaSimbolos`. Variáveis declaradas em um bloco são locais a ele; leituras e atribuições alcançam variáveis de escopos externos.
- Funções podem ser chamadas tanto como **expressão** (ex.: `soma(7, 5)`) quanto como **comando** (ex.: `saudacao("Ana")!`).
- Funções com retorno diferente de `vazio` devem obrigatoriamente executar `voltar <expr>!`; terminar o corpo sem retornar valor dispara `runtime error`. Funções `: vazio` não podem retornar valor em `voltar`.
- `parar!` e `pular!` só podem ser executados dentro de um laço `repetir`; `voltar!` só pode ser executado dentro de uma `função`.
