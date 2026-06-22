#include <stdio.h>
#include <stdlib.h>
// Pilha 1
typedef struct no {
    int dado;
    struct no *prox;
} No;

typedef struct {
    No *topo;
    int tam;
} Pilha;

void inicializar(Pilha *pilha) {
    pilha->topo = NULL;
    pilha->tam = 0;
}

void empilhar(Pilha *pilha, int val) {
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

int desempilhar(Pilha *pilha) {
    if (vazia(pilha)) return -1;
    No *temp = pilha->topo;
    int val = temp->dado;
    pilha->topo = pilha->topo->prox;
    free(temp);
    pilha->tam--;
    return val;
}

int topo(Pilha *pilha) {
    return (vazia(pilha)) ? -1 : pilha->topo->dado;
}

int tamanho(Pilha *pilha) {
    return pilha->tam;
}

void limpar(Pilha *pilha) {
    No *atual = pilha->topo;
    while (atual) {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
        pilha->tam--;
    }
    pilha->topo = NULL;
}

void imprimir(Pilha *pilha) {
    No *atual = pilha->topo;
    for (int i = 0; atual; i++) {
        if (i > 0) printf(" ");
        printf("%d", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    int q;
    Pilha pilha;
    inicializar(&pilha);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        char op;
        scanf(" %c", &op);
        switch (op) {
            case 'I': {
                int x;
                scanf("%d", &x);
                empilhar(&pilha, x);
                break;
            }
            case 'R': {
                int r = desempilhar(&pilha);
                printf("%d\n", r);
                break;
            }
            case 'T': {
                int t = topo(&pilha);
                printf("%d\n", t);
                break;
            }
            case 'S': {
                int s = tamanho(&pilha);
                printf("%d\n", s);
                break;
            }
            case 'C': {
                limpar(&pilha);
                break;
            }
            case 'P': {
                imprimir(&pilha);
                break;
            }
            default: { break; }
        }
    }
    limpar(&pilha);
    return 0;
}