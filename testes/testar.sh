#!/bin/sh

set -eu

ROOT=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
BIN="$ROOT/oxitona"
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
    esperado=$2
    if "$BIN" "$CASOS/$caso" >"$TMP_DIR/saida" 2>"$TMP_DIR/erro"; then
        echo "FAIL: $caso (deveria falhar)"
        cat "$TMP_DIR/saida" "$TMP_DIR/erro"
        falhou=$((falhou + 1))
    elif grep -Fq "$esperado" "$TMP_DIR/erro"; then
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

esperar_saida 01_expressoes.oxi "total=14; fracao=7; resto=2"
esperar_saida 02_tipos.oxi "tipos-ok"
esperar_saida 03_atribuicao.oxi "contador=2"
esperar_saida 04_fluxo.oxi "4"
esperar_saida 05_funcoes.oxi "soma=12"
esperar_entrada 06_obter.oxi "21 8.5 fiel Ana" "dados=21;8.5;fiel;Ana"

esperar_erro erro_obter_sem_variavel.oxi "expecting TOKEN_VIRGULA"
esperar_erro erro_obter_marcador.oxi "especificadores válidos"
esperar_erro erro_tipo.oxi "Soma exige números"
esperar_erro erro_divisao.oxi "Divisão inválida"
esperar_erro erro_funcao.oxi "Quantidade de argumentos inválida"
esperar_erro erro_retorno.oxi "terminou sem retornar valor"

echo "Resultado: $passou passaram; $falhou falharam."
test "$falhou" -eq 0
