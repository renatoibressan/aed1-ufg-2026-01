#include <stdio.h>
#include "hanoi.h"

void hanoi(int n, char origem, char destino, char aux) {
    if (n == 1) {
        printf("%c -> %c\n", origem, destino);
        return;
    }
    hanoi(n - 1, origem, aux, destino);
    printf("%c -> %c\n", origem, destino);
    hanoi(n - 1, aux, destino, origem);
}