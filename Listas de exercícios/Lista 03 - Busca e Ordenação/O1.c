#include <stdio.h>
#include <stdlib.h>
#define N 200000
// Ordenação 1 (Merge Sort)
void mesclaVetor(int *v, int aux[], int inicial, int meio, int final);

void ordenaVetor(int *v, int aux[], int inicial, int final);

int main() {
    int n, i;
    int *v = NULL, aux[N];
    scanf("%d", &n);
    v = (int *)malloc(n*sizeof(int));
    if (v == NULL) return 1;
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    int esquerda = 0;
    int direita = n - 1;
    int meio = (esquerda + direita) / 2;
    ordenaVetor(v, aux, 0, n - 1);
    for (i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", v[i]);
    }
    printf("\n");
    free(v);
    return 0;
}

void mesclaVetor(int *v, int aux[], int inicial, int meio, int final) {
    int k, j;
    for (k = inicial; k <= final; k++) {
        aux[k] = v[k];
    }
    j = meio + 1;
    for (k = inicial; k <= final; k++) {
        if (inicial > meio) v[k] = aux[j++];
        else if (j > final) v[k] = aux[inicial++];
        else if (aux[inicial] <= aux[j]) v[k] = aux[inicial++];
        else v[k] = aux[j++];
    }
}

void ordenaVetor(int *v, int aux[], int inicial, int final) {
    int meio;
    if (final > inicial) {
        meio = (inicial + final) / 2;
        ordenaVetor(v, aux, inicial, meio);
        ordenaVetor(v, aux, meio + 1, final);
        mesclaVetor(v, aux, inicial, meio, final);
    }
}