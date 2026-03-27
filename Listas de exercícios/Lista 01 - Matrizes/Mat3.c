#include <stdio.h>
#include <stdlib.h>
// Matriz N-Dimensional
int calcularIndiceLinear(int *ids, int *dims, int n);

void atribuirValor(int *arr, int id, int x);

int main() {
    int k, q, i, j, x;
    int indiceLinear, dimensao, total = 1;
    int *s = NULL;
    int *arr = NULL;
    int *ids = NULL;
    char op;
    scanf("%d", &k);
    s = (int *)malloc(k*sizeof(int));
    if (s == NULL) return 1;
    for (i = 0; i < k; i++) {
        scanf("%d", &s[i]);
        total *= s[i];
    }
    dimensao = s[k - 1];
    arr = (int *)malloc(total*sizeof(int));
    if (arr == NULL) {
        free(s);
        return 1;
    }
    for (i = 0; i < total; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &q);
    ids = (int *)malloc(k*sizeof(int));
    if (ids == NULL) {
        free(s);
        free(arr);
        return 1;
    }
    for (i = 0; i < q; i++) {
        scanf(" %c", &op);
        for (j = 0; j < k; j++) {
            scanf("%d", &ids[j]);
        }
        scanf("%d", &x);
        indiceLinear = calcularIndiceLinear(ids, s, k);
        atribuirValor(arr, indiceLinear, x);
    }
    for (i = 0; i < total; i++) {
        printf("%d ", arr[i]);
        if ((i + 1) % dimensao == 0) printf("\n");
    }
    free(s);
    free(arr);
    free(ids);
    return 0;
}

int calcularIndiceLinear(int *ids, int *dims, int n) {
    int i, id = 0, x = 1;
    for (i = n - 1; i >= 0; i--) {
        id += ids[i] * x;
        x *= dims[i];
    }
    return id;
}

void atribuirValor(int *arr, int id, int x) {
    arr[id] = x;
}