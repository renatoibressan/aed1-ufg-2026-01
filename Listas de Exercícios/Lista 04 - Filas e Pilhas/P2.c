#include <stdio.h>
#include <stdlib.h>
// Pilha 2
typedef struct no {
    int dado;
    struct no *prox;
} No;

typedef struct {
    No *topo;
    int tam;
} Pilha;

typedef struct {
    Pilha pilhaEntrada;
    Pilha pilhaSaida;
} Fila;

void inicializarPilha(Pilha *pilha) {
    pilha->topo = NULL;
    pilha->tam = 0;
}

void push(Pilha *pilha, int val) {
    No *novo = malloc(sizeof(No));
    if (!novo) return;
    novo->dado = val;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->tam++;
}

int vazia(Pilha *pilha) {
    return (!(pilha->topo));
}

int pop(Pilha *pilha) {
    if (vazia(pilha)) return -1;
    No *temp = pilha->topo;
    int val = temp->dado;
    pilha->topo = (pilha->topo)->prox;
    free(temp);
    pilha->tam--;
    return val;
}

int topo(Pilha *pilha) {
    return (vazia(pilha)) ? -1 : pilha->topo->dado;
}

int tamanhoPilha(Pilha *pilha) {
    return pilha->tam;
}

void limparPilha(Pilha *pilha) {
    No *atual = pilha->topo;
    while (atual) {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
        pilha->tam--;
    }
    pilha->topo = NULL;
}

void inicializarFila(Fila *fila) {
    inicializarPilha(&fila->pilhaEntrada);
    inicializarPilha(&fila->pilhaSaida);
}

void enqueue(Fila *fila, int val) {
    push(&fila->pilhaEntrada, val);
}

int dequeue(Fila *fila) {
    if (vazia(&fila->pilhaSaida)) {
        while (!vazia(&fila->pilhaEntrada)) {
            int x = pop(&fila->pilhaEntrada);
            push(&fila->pilhaSaida, x);
        }
    }
    return pop(&fila->pilhaSaida);
}

int frente(Fila *fila) {
    if (vazia(&fila->pilhaSaida)) {
        while (!vazia(&fila->pilhaEntrada)) {
            int x = pop(&fila->pilhaEntrada);
            push(&fila->pilhaSaida, x);
        }
    }
    return topo(&fila->pilhaSaida);
}

int tamanhoFila(Fila *fila) {
    return tamanhoPilha(&fila->pilhaEntrada) + tamanhoPilha(&fila->pilhaSaida);
}

void limparFila(Fila *fila) {
    limparPilha(&fila->pilhaEntrada);
    limparPilha(&fila->pilhaSaida);
}

int main() {
    int q;
    Fila fila;
    inicializarFila(&fila);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        char op;
        scanf(" %c", &op);
        switch (op) {
            case 'I': {
                int x;
                scanf("%d", &x);
                enqueue(&fila, x);
                break;
            }
            case 'R': {
                int r = dequeue(&fila);
                printf("%d\n", r);
                break;
            }
            case 'F': {
                int f = frente(&fila);
                printf("%d\n", f);
                break;
            }
            case 'S': {
                int s = tamanhoFila(&fila);
                printf("%d\n", s);
                break;
            }
            case 'C': {
                limparFila(&fila);
                break;
            }
            default: { break; }
        }
    }
    limparFila(&fila);
    return 0;
}