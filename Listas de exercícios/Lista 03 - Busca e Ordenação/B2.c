#include <stdio.h>
#include <stdlib.h>
#define N 1000
#define Q 50000
// Busca ?? (com Insertion Sort)
void ordenaVetor(int *v, int n);

int buscaSaddleback(int **m, int n, int x);

int main() {
    int n, q, x, i, j, res;
    int **m = NULL;
    scanf("%d %d", &n, &q);
    if (n < 1 || n > N || q < 1 || q > Q) return 1;
    m = (int **)malloc(n*sizeof(int*));
    if (m == NULL) return 1;
    for (i = 0; i < n; i++) {
        m[i] = (int *)malloc(n*sizeof(int));
        if (m[i] == NULL) return 1;
        for (j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
        ordenaVetor(m[i], n);
    }
    for (i = 0; i < q; i++) {
        scanf("%d", &x);
        res = buscaSaddleback(m, n, x);
        printf("%d\n", res);
    }
    for (i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
    return 0;
}

void ordenaVetor(int *v, int n) {
    for (int i = 1; i < n; i++) {
        int aux = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > aux) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = aux;
    }
}

int buscaSaddleback(int **m, int n, int x) {
    int i = 0, j = n - 1;
    while (i < n && j >= 0) {
        if (m[i][j] == x) return 1;
        else if (m[i][j] > x) j--;
        else i++;
    }
    return 0;
}