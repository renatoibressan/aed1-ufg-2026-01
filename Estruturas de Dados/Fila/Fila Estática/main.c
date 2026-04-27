#include <stdio.h>
#include <stdlib.h>
#include "fila_estatica.h"

int main() {
    Fila f;
    int x, op = -1, checkup = 1;
    inicializa_fila(&f);
    while (op != 0) {
        printf("1. Adicionar ao final da fila (enfileirar/enqueue)\n2. Remover do inicio da fila (desenfileirar/dequeue)\n0. Encerrar a operacao\nInsira a opcao desejada: ");
        scanf("%d", &op);
        while (op < 0 || op > 2) {
            printf("Opcao invalida!\nInsira a opcao desejada: ");
            scanf("%d", &op);
        }
        switch (op) {
            case 1:
                if (!checkup) {
                    printf("Pilha cheia!\n");
                    break;
                }
                printf("Insira um valor a ser acrescentado a fila: ");
                scanf("%d", &x);
                checkup = enqueue(&f, x);
                if (checkup) printf("Elemento %d acrescentado com sucesso!\n", x);
                break;
            case 2:
                int removido;
                (!dequeue(&f, &removido)) ? printf("Fila vazia!\n") : printf("Elemento %d removido da fila\n", removido);
            default: break;
        }
    }
    imprime_fila("Fila final:", &f);
    return 0;
}