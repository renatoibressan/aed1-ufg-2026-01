#include <stdio.h>
#include <stdlib.h>
#define N 200000
// Fila 2
typedef struct {
    int inicio, fim, tam;
    int dados[N];
} Fila;

void inicializar(Fila *fila) {
    fila->inicio = fila->fim = fila->tam = 0;
}

int esta_vazia(Fila *fila) {
    return (fila->tam == 0);
}

void enqueue(Fila *fila, int val) {
    fila->dados[fila->fim] = val;
    fila->fim = (fila->fim + 1) % N;
    fila->tam++;
}

int dequeue(Fila *fila) {
    if (esta_vazia(fila)) return -1;
    int val = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % N;
    fila->tam--;
    return val;
}

void criar_fila(Fila *fila, int n) {
    for (int i = 1; i <= n; i++) {
        enqueue(fila, i);
    }
}

void rotacoes(Fila *fila, int k) {
    for (int i = 0; fila->tam > 1; i++) {
        int rot = (k - 1) % fila->tam;
        for (int j = 0; j < rot; j++) {
            int deslocado = dequeue(fila);
            enqueue(fila, deslocado);
        }
        int eliminado = dequeue(fila);
        if (i > 0) printf(" ");
        printf("%d", eliminado);
    }
    int vencedor = dequeue(fila);
    printf("\n%d\n", vencedor);
}

int main() {
    int n, k;
    Fila fila;
    inicializar(&fila);
    scanf("%d %d", &n, &k);
    criar_fila(&fila, n);
    rotacoes(&fila, k);
    return 0;
}