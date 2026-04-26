#include <stdio.h>
#include "busca_saddleback.h"

int main() {
    int m[100][100], n, x, pos[2], resultado;
    printf("Insira a ordem da matriz: ");
    scanf("%d", &n);
    if (n < 0 || n > 100) {
        printf("Ordem invalida!\n(Programa abortado)\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Insira o elemento [%d,%d] da matriz: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
        bubble_sort(m[i], n);
    }
    printf("Insira o valor para ser encontrado: ");
    scanf("%d", &x);
    resultado = busca_saddleback(m, n, x, pos);
    (resultado) ? printf("O valor %d se encontra na posicao [%d,%d] da matriz\n", x, pos[0], pos[1]) : printf("O valor %d nao se encontra na matriz\n", x);
    return 0;
}