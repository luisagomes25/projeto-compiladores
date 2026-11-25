#!/bin/sh

set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
BIN="$ROOT/oxitona"
PROGS="$ROOT/testes"
CASOS="$ROOT/testes/casos"
TMP_DIR=$(mktemp -d "${TMPDIR:-/tmp}/oxitona-testes.XXXXXX")
trap 'rm -rf "$TMP_DIR"' EXIT HUP INT TERM

passou=0
falhou=0

esperar_saida() {
    caso=$1
    esperado=$2
    if "$BIN" "$CASOS/$caso" >"$TMP_DIR/saida" 2>"$TMP_DIR/erro" && grep -Fq "$esperado" "$TMP_DIR/saida"; then
        echo "PASS: $caso"
        passou=$((passou + 1))
    else
        echo "FAIL: $caso"
        cat "$TMP_DIR/saida" "$TMP_DIR/erro"
        falhou=$((falhou + 1))
    fi
}

esperar_erro() {
    caso=$1
    categoria=$2
    linha=$3
    esperado=$4
    if "$BIN" --debug "$CASOS/$caso" >"$TMP_DIR/saida" 2>"$TMP_DIR/erro"; then
        echo "FAIL: $caso (deveria falhar)"
        cat "$TMP_DIR/saida" "$TMP_DIR/erro"
        falhou=$((falhou + 1))
    elif grep -Fq "$esperado" "$TMP_DIR/erro" \
        && grep -Fq "$CASOS/$caso:$linha:" "$TMP_DIR/erro" \
        && grep -Fq ": error: $categoria:" "$TMP_DIR/erro" \
        && grep -Fq "| " "$TMP_DIR/erro" \
        && grep -Fq "^" "$TMP_DIR/erro"; then
        echo "PASS: $caso (erro esperado)"
        passou=$((passou + 1))
    else
        echo "FAIL: $caso (mensagem inesperada)"
        cat "$TMP_DIR/saida" "$TMP_DIR/erro"
        falhou=$((falhou + 1))
    fi
}

esperar_entrada() {
    caso=$1
    entrada=$2
    esperado=$3
    if printf '%s\n' "$entrada" | "$BIN" "$CASOS/$caso" >"$TMP_DIR/saida" 2>"$TMP_DIR/erro" && grep -Fq "$esperado" "$TMP_DIR/saida"; then
        echo "PASS: $caso (entrada)"
        passou=$((passou + 1))
    else
        echo "FAIL: $caso (entrada)"
        cat "$TMP_DIR/saida" "$TMP_DIR/erro"
        falhou=$((falhou + 1))
    fi
}

esperar_programa() {
    prog=$1
    esperado=$2
    if "$BIN" "$PROGS/$prog" >"$TMP_DIR/saida" 2>"$TMP_DIR/erro" && [ "$(cat "$TMP_DIR/saida")" = "$esperado" ]; then
        echo "PASS: $prog"
        passou=$((passou + 1))
    else
        echo "FAIL: $prog"
        cat "$TMP_DIR/saida" "$TMP_DIR/erro"
        falhou=$((falhou + 1))
    fi
}

esperar_programa prog1.oxi "A área é: 12.5"
esperar_programa prog2.oxi "Estado febril."
esperar_programa prog3.oxi "$(printf '1\n2\n3\n4\n5')"
esperar_programa prog4.oxi "Aluno aprovado com media: 7.75"

esperar_saida 01_expressoes.oxi "total=14; fracao=7; resto=2"
esperar_saida 02_tipos.oxi "tipos-ok"
esperar_saida 03_atribuicao.oxi "contador=2"
esperar_saida 04_fluxo.oxi "4"
esperar_saida 05_funcoes.oxi "soma=12"
esperar_entrada 06_obter.oxi "21 8.5 fiel Ana" "dados=21;8.5;fiel;Ana"
esperar_saida 07_condicionais.oxi "11112"
esperar_saida 08_condicionais_aninhadas.oxi "1"

esperar_erro erro_lexico.oxi "lexical error" 2 "caractere inválido"
esperar_erro erro_sintatico.oxi "syntax error" 2 "token inesperado ou ausente"
esperar_erro erro_obter_sem_variavel.oxi "syntax error" 1 "token inesperado ou ausente"
esperar_erro erro_obter_marcador.oxi "semantic error" 2 "especificadores válidos"
esperar_erro erro_tipo.oxi "runtime error" 3 "Soma exige números"
esperar_erro erro_divisao.oxi "runtime error" 2 "Divisão inválida"
esperar_erro erro_funcao.oxi "runtime error" 4 "Quantidade de argumentos inválida"
esperar_erro erro_retorno.oxi "runtime error" 1 "terminou sem retornar valor"
esperar_erro erro_condicao.oxi "runtime error" 1 "A condição exige um valor do tipo sinal"
esperar_erro erro_ou_antes_se.oxi "syntax error" 1 "token inesperado ou ausente"
esperar_erro erro_ou_depois_senao.oxi "syntax error" 7 "token inesperado ou ausente"
esperar_erro erro_ou_sem_senao.oxi "syntax error" 7 "token inesperado ou ausente"

echo "Resultado: $passou passaram; $falhou falharam."
test "$falhou" -eq 0
