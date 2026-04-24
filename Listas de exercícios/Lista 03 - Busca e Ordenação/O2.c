#include <stdio.h>
#include <stdlib.h>
#define N 10000000
// Ordenação 2 (Quick Sort)
void ordenaVetor(int *v, int inicial, int final);

int main() {
    int n, i, *v = NULL;
    scanf("%d", &n);
    v = (int *)malloc(n*sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    ordenaVetor(v, 0, n - 1);
    for (i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", v[i]);
    }
    printf("\n");
    free(v);
    return 0;
}

void ordenaVetor(int *v, int inicial, int final) {
    if (inicial >= final) return;
    int pivot = v[final];
    int i = inicial - 1;
    for (int j = inicial; j < final; j++) {
        if (v[j] < pivot) {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    int aux = v[i + 1];
    v[i + 1] = v[final];
    v[final] = aux;
    int posPivot = i + 1;
    ordenaVetor(v, inicial, posPivot - 1);
    ordenaVetor(v, posPivot + 1, final);
}