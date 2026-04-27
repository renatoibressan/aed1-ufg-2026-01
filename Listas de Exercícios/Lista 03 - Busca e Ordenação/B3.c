#include <stdio.h>
#include <stdlib.h>
#define N 200000
// Soma das Distancias (com Merge Sort)
void mesclaVetor(int *v, int aux[], int inicial, int meio, int final);

void ordenaVetor(int *v, int aux[], int inicial, int final);

int mediana(int *v, int n);

long long modulo(long long n);

long long somaDistancias(int *v, int n);

int main() {
    int n, *v = NULL, aux[N];
    scanf("%d", &n);
    if (n < 1 || n > N) return 1;
    v = (int *)malloc(n*sizeof(int));
    if (v == NULL) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    ordenaVetor(v, aux, 0, n - 1);
    long long res = somaDistancias(v, n);
    printf("%lld\n", res);
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

int mediana(int *v, int n) {
    return v[n / 2];
}

long long modulo(long long n) {
    return (n < 0) ? -n : n;
}

long long somaDistancias(int *v, int n) {
    long long soma = 0;
    int x = mediana(v, n);
    for (int i = 0; i < n; i++) {
        int distancia = x - v[i];
        soma += modulo(distancia);
    }
    return soma;
}