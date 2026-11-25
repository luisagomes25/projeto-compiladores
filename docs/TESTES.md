# Plano de Testes e Resultados Esperados — Linguagem Oxítona

Este documento cataloga toda a suíte automatizada de testes da linguagem **Oxítona**, composta por **24 verificações automáticas**: os **4 programas oficiais** da especificação (`testes/prog1.oxi` a `testes/prog4.oxi`) e **20 casos de regressão** em `testes/casos/` (8 casos de sucesso e 12 casos de erro).

---

## 1. Como Executar os Testes

### Bateria completa automatizada (24 testes)
```bash
make test
```
*(Alternativamente, após compilar com `make`, execute diretamente `sh testes/testar.sh`.)*

### Execução individual
```bash
./oxitona testes/prog1.oxi
./oxitona testes/casos/07_condicionais.oxi
./oxitona --debug testes/casos/erro_ou_sem_senao.oxi
```

### Estratégia de Validação (`testes/testar.sh`)
O script de testes define quatro funções auxiliares:
- `esperar_programa`: executa os programas oficiais (`prog1.oxi`..`prog4.oxi`), exige código de saída `0` e compara a saída padrão exata.
- `esperar_saida`: executa um caso de sucesso em `testes/casos/`, exige código de saída `0` e valida a saída esperada.
- `esperar_entrada`: injeta dados via `stdin` para testar a instrução `obter` e valida a saída gerada.
- `esperar_erro`: executa o interpretador com `--debug`, exige código de saída diferente de `0` e verifica simultaneamente:
  1. Presença do texto esperado da mensagem de erro;
  2. Cabeçalho no formato GCC (`<arquivo>:<linha>:`);
  3. Categoria correta (`: error: <categoria>:`);
  4. Recorte do código-fonte (`| `) e marcador de coluna (`^`).

---

## 2. Programas Oficiais da Especificação (`testes/prog1.oxi` .. `prog4.oxi`)

| Arquivo | Objetivo | Entrada (`stdin`) | Saída Esperada (`stdout`) |
| :--- | :--- | :---: | :--- |
| `testes/prog1.oxi` | Comentário `sermão`, declaração de `fração`, multiplicação e `exibir` com múltiplos argumentos (cálculo de área). | — | `A área é: 12.5` |
| `testes/prog2.oxi` | Estrutura condicional `se (...) abrir ... fechar senão abrir ... fechar` com comparação relacional (`>`). | — | `Estado febril.` |
| `testes/prog3.oxi` | Laço `repetir (cont <= 5)` com incremento de variável `total`. | — | `1`<br>`2`<br>`3`<br>`4`<br>`5` |
| `testes/prog4.oxi` | Programa completo: `sermão`, cálculo de média com parênteses e divisão por inteiro, decisão `se / senão`. | — | `Aluno aprovado com media: 7.75` |

---

## 3. Casos de Regressão — Sucesso (`testes/casos/01_*.oxi` .. `08_*.oxi`)

| Arquivo | Funcionalidades Validadas | Entrada (`stdin`) | Saída Esperada (`stdout`) |
| :--- | :--- | :---: | :--- |
| `01_expressoes.oxi` | Precedência aritmética (`+` vs `*`), divisão inteira promovida para `fração` e módulo (`%`). | — | `total=14; fracao=7; resto=2` |
| `02_tipos.oxi` | Tipos `textão` e `sinal`, concatenação com `+`, operador lógico `e` e igualdade `==` em `se`. | — | `Oxítona fiel`<br>`tipos-ok` |
| `03_atribuicao.oxi` | Declaração com `guarde` e reatribuições sucessivas de variável `total`. | — | `contador=2` |
| `04_fluxo.oxi` | Laço `repetir` combinado com `se` e instrução `pular!` (pula a exibição do valor `3`). | — | `1`, `2`, `4`, `5` (valida `4`) |
| `05_funcoes.oxi` | Declaração e chamada de função com retorno (`total`) via expressão e função `: vazio` via comando com `voltar!`. | — | `soma=12`<br>`Olá, Ana` |
| `06_obter.oxi` | Leitura formatada `obter` com todos os 4 especificadores (`%t`, `%f`, `%s`, `%tex`). | `21 8.5 fiel Ana` | `dados=21;8.5;fiel;Ana` |
| `07_condicionais.oxi` | Cadeias `se` / `ou se` / `senão`, múltiplos `ou se` encadeados em sequência, operador lógico `ou` dentro da condição e `se` isolado. | — | `11112` |
| `08_condicionais_aninhadas.oxi` | Condicionais `se` / `ou se` / `senão` aninhadas em múltiplos níveis. | — | `1` |

---

## 4. Casos de Regressão — Erros e Diagnósticos (`testes/casos/erro_*.oxi`)

| Arquivo | Categoria Esperada | Linha | Cenário Testado | Trecho de Mensagem Esperado (`stderr`) |
| :--- | :--- | :---: | :--- | :--- |
| `erro_lexico.oxi` | `lexical error` | 2 | Caractere inválido `@` fora do alfabeto da linguagem. | `caractere inválido` |
| `erro_sintatico.oxi` | `syntax error` | 2 | Declaração `guarde` sem identificador (`guarde = 1 : total!`). | `token inesperado ou ausente` |
| `erro_obter_sem_variavel.oxi` | `syntax error` | 1 | Chamada de `obter` sem vírgula e lista de variáveis. | `token inesperado ou ausente` |
| `erro_obter_marcador.oxi` | `semantic error` | 2 | Especificador de formato inválido `%x` em `obter`. | `especificadores válidos` |
| `erro_tipo.oxi` | `runtime error` | 3 | Soma incompatível entre `total` e `textão`. | `Soma exige números` |
| `erro_divisao.oxi` | `runtime error` | 2 | Divisão por zero (`10 / zero`). | `Divisão inválida` |
| `erro_funcao.oxi` | `runtime error` | 4 | Chamada de função com número incorreto de argumentos. | `Quantidade de argumentos inválida` |
| `erro_retorno.oxi` | `runtime error` | 1 | Função com retorno `total` que termina sem executar `voltar`. | `terminou sem retornar valor` |
| `erro_condicao.oxi` | `runtime error` | 1 | Condição de `se` com valor `total` (`1`) em vez de `sinal`. | `A condição exige um valor do tipo sinal` |
| `erro_ou_antes_se.oxi` | `syntax error` | 1 | Uso de `ou se` sem comando `se` anterior. | `token inesperado ou ausente` |
| `erro_ou_depois_senao.oxi` | `syntax error` | 7 | Uso de `ou se` após o encerramento de um ramo `senão`. | `token inesperado ou ausente` |
| `erro_ou_sem_senao.oxi` | `syntax error` | 7 | Encadeamento `se ... ou se ...` sem o ramo `senão` final obrigatório. | `token inesperado ou ausente` |

---

## 5. Resultado Esperado da Execução Completa

Ao executar `make test`, todos os 24 casos devem reportar `PASS`, encerrando com:

```text
Resultado: 24 passaram; 0 falharam.
```
