#include <stdio.h>
#include <stdlib.h>
// Fila 1
typedef struct no {
    int dado;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tam;
} Fila;

void inicializar(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

int vazia(Fila *fila) {
    return (!(fila->inicio));
}

void enfileirar(Fila *fila, int val) {
    No *novo = malloc(sizeof(No));
    if (!novo) return;
    novo->dado = val;
    novo->prox = NULL;
    if (vazia(fila)) fila->inicio = novo;
    else fila->fim->prox = novo;
    fila->fim = novo;
    fila->tam++;
}

int desenfileirar(Fila *fila) {
    if (vazia(fila)) return -1;
    No *temp = fila->inicio;
    int val = temp->dado;
    fila->inicio = fila->inicio->prox;
    if (vazia(fila)) fila->fim = NULL;
    free(temp);
    fila->tam--;
    return val;
}

int frente(Fila *fila) {
    return (vazia(fila)) ? -1 : fila->inicio->dado;
}

int tras(Fila *fila) {
    return (vazia(fila)) ? -1 : fila->fim->dado;
}

int tamanho(Fila *fila) {
    return fila->tam;
}

void limpar(Fila *fila) {
    No *atual = fila->inicio;
    while (atual) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
        fila->tam--;
    }
    fila->inicio = NULL;
    fila->fim = NULL;
}

void imprimir(Fila *fila) {
    No *atual = fila->inicio;
    for (int i = 0; atual; i++) {
        if (i > 0) printf(" ");
        printf("%d", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    int q;
    Fila fila;
    inicializar(&fila);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        char op;
        scanf(" %c", &op);
        switch (op) {
            case 'I': {
                int x;
                scanf("%d", &x);
                enfileirar(&fila, x);
                break;
            }
            case 'R': {
                int r = desenfileirar(&fila);
                printf("%d\n", r);
                break;
            }
            case 'F': {
                int f = frente(&fila);
                printf("%d\n", f);
                break;
            }
            case 'B': {
                int b = tras(&fila);
                printf("%d\n", b);
                break;
            }
            case 'S': {
                int s = tamanho(&fila);
                printf("%d\n", s);
                break;
            }
            case 'C': {
                limpar(&fila);
                break;
            }
            case 'P': {
                imprimir(&fila);
                break;
            }
            default: { break; }
        }
    }
    limpar(&fila);
    return 0;
}