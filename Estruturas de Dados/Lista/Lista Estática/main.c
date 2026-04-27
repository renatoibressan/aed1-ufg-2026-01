#include <stdio.h>
#include <stdlib.h>
#include "lista_estatica.h"

int main() {
    Lista l;
    int x, i = 0, checkup = 1;
    inicializa_lista(&l);
    while (1) {
        if (!checkup) {
            printf("Lista cheia!\n");
            break;
        }
        i++;
        printf("Insira o %d-esimo valor da lista (ou valor invalido para encerrar a operacao): ", i);
        if (scanf("%d", &x) != 1) {
            printf("Valor invalido!\n(Operacao encerrada)\n");
            break;
        }
        checkup = insere_final(&l, x);
    }
    imprime_lista("Lista final:", &l);
    return 0;
}