#include <stdio.h>
#include <stdlib.h>
#define N 200000
// Busca Binaria (com Merge Sort)
void mesclaVetor(int *v, int aux[], int inicial, int meio, int final);

void ordenaVetor(int *v, int aux[], int inicial, int final);

int buscaBinaria(int *v, int n, int x);

int main() {
    int n, q, i, x, res;
    int *v = NULL, aux[N];
    scanf("%d %d", &n, &q);
    if (n < 1 || n > N || q < 1 || q > N) return 1;
    v = (int *)malloc(n*sizeof(int));
    if (v == NULL) return 1;
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    ordenaVetor(v, aux, 0, n - 1);
    for (i = 0; i < q; i++) {
        scanf("%d", &x);
        res = buscaBinaria(v, n, x);
        printf("%d\n", res);
    }
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

int buscaBinaria(int *v, int n, int x) {
    int inicial = 0, final = n - 1;
    while (inicial <= final) {
        int meio = inicial + (final - inicial) / 2;
        if (v[meio] == x) return 1;
        else if (v[meio] < x) inicial = meio + 1;
        else final = meio - 1;
    }
    return 0;
}