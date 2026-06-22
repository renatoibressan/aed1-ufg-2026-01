#include <stdio.h>
#include <stdlib.h>
// Fila 3
typedef struct no {
    int dado;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tam;
} Fila;

typedef struct {
    Fila fila;
} Pilha;

void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tam = 0;
}

int vazia(Fila *fila) {
    return (!(fila->inicio));
}

void enqueue(Fila *fila, int val) {
    No *novo = malloc(sizeof(No));
    if (!novo) return;
    novo->dado = val;
    novo->prox = NULL;
    if (vazia(fila)) fila->inicio = novo;
    else fila->fim->prox = novo;
    fila->fim = novo;
    fila->tam++;
}

int dequeue(Fila *fila) {
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

int tamanhoFila(Fila *fila) {
    return fila->tam;
}

void limparFila(Fila *fila) {
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

void inicializarPilha(Pilha *pilha) {
    inicializarFila(&pilha->fila);
}

void push(Pilha *pilha, int val) {
    enqueue(&pilha->fila, val);
    for (int i = 0; i < pilha->fila.tam - 1; i++) {
        int x = dequeue(&pilha->fila);
        enqueue(&pilha->fila, x);
    }
}

int pop(Pilha *pilha) {
    return dequeue(&pilha->fila);
}

int topo(Pilha *pilha) {
    return frente(&pilha->fila);
}

int tamanhoPilha(Pilha *pilha) {
    return tamanhoFila(&pilha->fila);
}

void limparPilha(Pilha *pilha) {
    limparFila(&pilha->fila);
}

int main() {
    int q;
    Pilha pilha;
    inicializarPilha(&pilha);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        char op;
        scanf(" %c", &op);
        switch (op) {
            case 'P': {
                int x;
                scanf("%d", &x);
                push(&pilha, x);
                break;
            }
            case 'O': {
                int o = pop(&pilha);
                printf("%d\n", o);
                break;
            }
            case 'T': {
                int t = topo(&pilha);
                printf("%d\n", t);
                break;
            }
            case 'S': {
                int s = tamanhoPilha(&pilha);
                printf("%d\n", s);
                break;
            }
            case 'C': {
                limparPilha(&pilha);
                break;
            }
            default: { break; }
        }
    }
    limparPilha(&pilha);
    return 0;
}