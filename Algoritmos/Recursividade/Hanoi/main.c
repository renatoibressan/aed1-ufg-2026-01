#include <stdio.h>
#include "hanoi.h"

int main() {
    int n;
    printf("Insira a quantidade de discos: ");
    if (scanf("%d", &n) != 1) {
        printf("Leitura nao suportada!\n(Programa abortado)\n");
        return 1;
    }
    if (n < 1) {
        printf("Valor %d invalido!\n(Programa abortado)\n", n);
        return 1;
    }
    printf("Movimentos:\n");
    hanoi(n, 'A', 'C', 'B');
    return 0;
}