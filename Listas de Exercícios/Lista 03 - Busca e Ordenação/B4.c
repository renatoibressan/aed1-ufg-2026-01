#include <stdio.h>
#include <stdlib.h>
#define N 200000
#define P 100000000000000LL
// Corte de Cabos (com Merge Sort)
void mesclaVetor(int *v, int aux[], int inicial, int meio, int final);

void ordenaVetor(int *v, int aux[], int inicial, int final);

long long pedacos(int *v, int n, long long p);

int main() {
    int n, *v = NULL, aux[N];
    long long p;
    scanf("%d %lld", &n, &p);
    if (n < 1 || n > N) return 1;
    v = (int *)malloc(n*sizeof(int));
    if (v == NULL) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    ordenaVetor(v, aux, 0, n - 1);
    long long res = pedacos(v, n, p);
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

long long pedacos(int *v, int n, long long p) {
    long long soma, resultado  = 0;
    long long esq = 1, dir = v[n - 1];
    while (esq <= dir) {
        soma = 0;
        long long meio = esq + (dir - esq) / 2;
        for (int i = 0; i < n; i++) {
            soma += v[i] / meio;
        }
        if (soma >= p) {
            resultado = meio;
            esq = meio + 1;
        } else {
            dir = meio - 1;
        }
    }
    return resultado;
}