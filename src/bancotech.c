/*
 * BancoTech - Simulador bancario em C
 * Projeto academico: Algoritmos e Pensamento Computacional
 * Compilacao: gcc -std=c11 -Wall -Wextra -pedantic src/bancotech.c -o bancotech -lm
 * Observacao: simulacao educacional, sem movimentacao financeira real.
 */
#include <stdio.h>
#include <math.h>
#include <string.h>

#define TAM_LINHA 128

/* Retorna 1 para linha lida, 0 para entrada encerrada.
   Descarta o restante caso a linha exceda o limite. */
int lerLinha(char linha[], size_t tamanho) {
    if (fgets(linha, (int)tamanho, stdin) == NULL) return 0;
    if (strchr(linha, '\n') == NULL) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
    return 1;
}

/* Retorna 1 quando a entrada contem apenas um inteiro. */
int lerOpcao(int *opcao) {
    char linha[TAM_LINHA], extra;
    if (!lerLinha(linha, sizeof linha)) return -1;
    return sscanf(linha, " %d %c", opcao, &extra) == 1;
}

/* Retorna 1 quando o valor e um numero finito. */
int lerValor(double *valor) {
    char linha[TAM_LINHA], extra;
    if (!lerLinha(linha, sizeof linha)) return -1;
    return sscanf(linha, " %lf %c", valor, &extra) == 1 && isfinite(*valor);
}

int main(void) {
    int opcao = -1;
    int quantidadeDepositos = 0, quantidadeSaques = 0;
    double saldo = 1000.00;
    double valor = 0.0, totalDepositos = 0.0, totalSaques = 0.0;

    printf("========================================\n");
    printf("       BANCOTECH - SISTEMA BANCARIO\n");
    printf("========================================\n");
    printf("Bem-vindo ao BancoTech!\n");
    printf("Simulador educacional de operacoes bancarias.\n");

    do {
        printf("\n============== MENU ====================\n");
        printf("1 - Consultar saldo\n");
        printf("2 - Realizar deposito\n");
        printf("3 - Realizar saque\n");
        printf("4 - Resumo de movimentacoes\n");
        printf("0 - Encerrar sistema\n");
        printf("========================================\n");
        printf("Escolha uma opcao: ");
        fflush(stdout);

        int leitura = lerOpcao(&opcao);
        if (leitura == -1) {
            printf("\nEntrada encerrada.\n");
            break;
        }
        if (leitura == 0) {
            printf("Opcao invalida! Digite um numero de 0 a 4.\n");
            continue;
        }

        switch (opcao) {
            case 1:
                printf("\n--- CONSULTA DE SALDO ---\n");
                printf("Saldo disponivel: R$ %.2f\n", saldo);
                break;
            case 2: {
                printf("\n--- REALIZAR DEPOSITO ---\n");
                printf("Informe o valor: R$ ");
                fflush(stdout);
                int ok = lerValor(&valor);
                if (ok == -1) { opcao = 0; break; }
                if (!ok || valor <= 0 || !isfinite(saldo + valor)
                    || !isfinite(totalDepositos + valor)) {
                    printf("Valor invalido! Informe um valor positivo valido.\n");
                } else {
                    saldo += valor;
                    totalDepositos += valor;
                    quantidadeDepositos++;
                    printf("Deposito realizado com sucesso!\n");
                    printf("Novo saldo: R$ %.2f\n", saldo);
                }
                break;
            }
            case 3: {
                printf("\n--- REALIZAR SAQUE ---\n");
                printf("Informe o valor: R$ ");
                fflush(stdout);
                int ok = lerValor(&valor);
                if (ok == -1) { opcao = 0; break; }
                if (!ok || valor <= 0) {
                    printf("Valor invalido! Informe um valor positivo.\n");
                } else if (valor > saldo) {
                    printf("Saque negado: saldo insuficiente.\n");
                    printf("Saldo disponivel: R$ %.2f\n", saldo);
                } else if (!isfinite(totalSaques + valor)) {
                    printf("Valor invalido para o total acumulado.\n");
                } else {
                    saldo -= valor;
                    totalSaques += valor;
                    quantidadeSaques++;
                    printf("Saque realizado com sucesso!\n");
                    printf("Novo saldo: R$ %.2f\n", saldo);
                }
                break;
            }
            case 4:
                printf("\n--- RESUMO DE MOVIMENTACOES ---\n");
                printf("Depositos realizados: %d\n", quantidadeDepositos);
                printf("Total depositado: R$ %.2f\n", totalDepositos);
                printf("Saques realizados: %d\n", quantidadeSaques);
                printf("Total sacado: R$ %.2f\n", totalSaques);
                printf("Saldo atual: R$ %.2f\n", saldo);
                break;
            case 0:
                break;
            default:
                printf("Opcao nao suportada! Escolha de 0 a 4.\n");
                break;
        }
    } while (opcao != 0);

    printf("\n========================================\n");
    printf("          ENCERRAMENTO BANCOTECH\n");
    printf("========================================\n");
    printf("Depositos realizados: %d\n", quantidadeDepositos);
    printf("Total depositado: R$ %.2f\n", totalDepositos);
    printf("Saques realizados: %d\n", quantidadeSaques);
    printf("Total sacado: R$ %.2f\n", totalSaques);
    printf("Saldo final: R$ %.2f\n", saldo);
    printf("Obrigado por utilizar o BancoTech!\n");
    printf("Sistema encerrado com seguranca.\n");
    return 0;
}
