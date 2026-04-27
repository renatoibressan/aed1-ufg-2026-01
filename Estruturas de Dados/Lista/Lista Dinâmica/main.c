#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica.h"

int main() {
    No *l = NULL;
    int x, i = 0;
    while (1) {
        i++;
        printf("Insira o %d-esimo valor da lista (ou valor invalido para encerrar a operacao): ", i);
        if (scanf("%d", &x) != 1) {
            printf("Valor invalido!\n(Operacao encerrada)\n");
            break;
        }
        l = insere_inicio(l, x);
    }
    imprime_lista("Lista final:", l);
    libera_lista(&l);
    return 0;
}