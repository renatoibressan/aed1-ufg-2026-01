#include <stdio.h>
#include <stdlib.h>
#define LIMITE 200000
// Matriz Esparsa
typedef struct matriz_esparsa {
    int indice;
    int valor;
} MatrizEsparsa;

void inicializarVetor(MatrizEsparsa *M, int n);

int posicaoNoVetor(MatrizEsparsa *M, int i, int n);

void inserirNoVetor(MatrizEsparsa *M, int i, int *n, int v);

void removerDoVetor(MatrizEsparsa *M, int i, int *n);

void atribuirValor(MatrizEsparsa *M, int i, int *n, int v);

void consultarIndice(MatrizEsparsa *M, int i, int n, int *v);

int main() {
    MatrizEsparsa M[LIMITE];
    int q, i, idx, x, tamanho = 0;
    char op;
    inicializarVetor(M, LIMITE);
    scanf("%d", &q);
    if (q < 1 || q > LIMITE) return 1;
    for (i = 0; i < q; i++) {
        scanf(" %c", &op);
        switch (op) {
            case 'A':
                scanf("%d %d", &idx, &x);
                atribuirValor(M, idx, &tamanho, x);
                break;
            case 'C':
                scanf("%d", &idx);
                consultarIndice(M, idx, tamanho, &x);
                printf("%d\n", x);
        }
    }
    return 0;
}

void inicializarVetor(MatrizEsparsa *M, int n) {
    int i;
    for (i = 0; i < n; i++) {
        M[i].indice = -1;
        M[i].valor = 0;
    }
}

int posicaoNoVetor(MatrizEsparsa *M, int i, int n) {
    int j;
    for (j = 0; j < n; j++) {
        if (M[j].indice == i) return j;
    }
    return -1;
}

void inserirNoVetor(MatrizEsparsa *M, int i, int *n, int v) {
    int j = 0, k;
    while (j < *n && M[j].indice < i) j++;
    for (k = *n; k > j; k--) M[k] = M[k - 1];
    M[j].indice = i;
    M[j].valor = v;
    (*n)++;
}

void removerDoVetor(MatrizEsparsa *M, int i, int *n) {
    int j;
    for (j = i; j < *n - 1; j++) M[j] = M[j + 1];
    M[*n - 1].indice = -1;
    M[*n - 1].valor = 0;
    (*n)--;
}

void atribuirValor(MatrizEsparsa *M, int i, int *n, int v) {
    if (i < 0) exit(EXIT_FAILURE);
    int j = posicaoNoVetor(M, i, *n);
    if (j == -1) {
        if (v != 0) inserirNoVetor(M, i, n, v);
    } else {
        if (v == 0) removerDoVetor(M, j, n);
        else M[j].valor = v;
    }
}

void consultarIndice(MatrizEsparsa *M, int i, int n, int *v) {
    if (i < 0) exit(EXIT_FAILURE);
    int j = posicaoNoVetor(M, i, n);
    if (j == -1) *v = 0;
    else *v = M[j].valor;
}