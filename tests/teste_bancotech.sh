#!/usr/bin/env bash
# Testes de regressao do BancoTech (Linux / Colab)
set -euo pipefail

cd "$(dirname "$0")/.."
binario="$(mktemp)"
saida="$(mktemp)"
trap 'rm -f "$binario" "$saida"' EXIT

gcc -std=c11 -Wall -Wextra -pedantic src/bancotech.c -o "$binario" -lm

# Deposito e saque validos, seguidos de consulta ao resumo
printf '1\n2\n300\n3\n150\n4\n0\n' | "$binario" > "$saida"
grep -q 'Total depositado: R$ 300.00' "$saida"
grep -q 'Total sacado: R$ 150.00' "$saida"
grep -q 'Saldo final: R$ 1150.00' "$saida"
grep -q 'Obrigado por utilizar o BancoTech!' "$saida"
echo 'OK: operacoes e encerramento'

# Entrada nao numerica, opcao nao mapeada e saque insuficiente
printf 'abc\n9\n3\n9999\n0\n' | "$binario" > "$saida"
grep -q 'Opcao invalida! Digite um numero de 0 a 4.' "$saida"
grep -q 'Opcao nao suportada!' "$saida"
grep -q 'Saque negado: saldo insuficiente.' "$saida"
grep -q 'Saldo final: R$ 1000.00' "$saida"
echo 'OK: validacao de menu e saldo'

# Valores invalidos nao alteram saldo
printf '2\n-10\n3\n0\n0\n' | "$binario" > "$saida"
grep -q 'Valor invalido!' "$saida"
grep -q 'Saldo final: R$ 1000.00' "$saida"
echo 'OK: valores invalidos'

echo 'Todos os testes passaram.'
