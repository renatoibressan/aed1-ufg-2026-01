#include <stdio.h>
#include <stdlib.h>
#include "pilha_dinamica.h"

int main() {
    No *p = NULL;
    int x, op = -1, checkup = 1;
    while (op != 0) {
        printf("1. Adicionar ao topo da pilha\n2. Remover do topo da pilha\n0. Encerrar a operacao\nInsira a opcao desejada: ");
        scanf("%d", &op);
        while (op < 0 || op > 2) {
            printf("Opcao invalida!\nInsira a opcao desejada: ");
            scanf("%d", &op);
        }
        switch (op) {
            case 1:
                if (!checkup) {
                    printf("Memoria cheia!\n");
                    break;
                }
                printf("Insira um valor a ser acrescentado a pilha: ");
                scanf("%d", &x);
                checkup = push(&p, x);
                if (checkup) printf("Elemento %d acrescentado com sucesso!\n", x);
                break;
            case 2:
                int removido;
                (!pop(&p, &removido)) ? printf("Pilha vazia!\n") : printf("Elemento %d removido da pilha\n", removido);
                break;
            default: break;
        }
    }
    imprime_pilha("Pilha final:", p);
    libera_pilha(&p);
    return 0;
}