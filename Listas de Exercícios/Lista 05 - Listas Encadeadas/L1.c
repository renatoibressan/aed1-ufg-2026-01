#include <stdio.h>
#include <stdlib.h>
// Lista 1
typedef struct no {
    int dado;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
    int tam;
} Lista;

void inicializar(Lista *lista) {
    lista->inicio = NULL;
    lista->tam = 0;
}

int vazia(Lista *lista) {
    return (!(lista->inicio));
}

void inserir(Lista *lista, int pos, int val) {
    if (pos < 0 || pos > lista->tam) {
        printf("-1\n");
        return;
    }
    No *novo = malloc(sizeof(No));
    novo->dado = val;
    novo->prox = NULL;
    if (pos == 0) {
        novo->prox = lista->inicio;
        lista->inicio = novo;
        lista->tam++;
        return;
    }
    No *atual = lista->inicio;
    for (int i = 0; atual && i < pos - 1; i++) {
        atual = atual->prox;
    }
    if (!atual) {
        free(novo);
        printf("-1\n");
        return;
    }
    novo->prox = atual->prox;
    atual->prox = novo;
    lista->tam++;
}

void remover(Lista *lista, int pos) {
    if (pos < 0 || vazia(lista) || pos >= lista->tam) {
        printf("-1\n");
        return;
    }
    if (pos == 0) {
        No *removido = lista->inicio;
        lista->inicio = lista->inicio->prox;
        free(removido);
        lista->tam--;
        return;
    }
    No *atual = lista->inicio;
    for (int i = 0; atual && i < pos - 1; i++) {
        atual = atual->prox;
    }
    if (!atual || !atual->prox) {
        printf("-1\n");
        return;
    }
    No* removido = atual->prox;
    atual->prox = removido->prox;
    free(removido);
    lista->tam--;
}

void consultar(Lista *lista, int pos) {
    if (pos < 0 || vazia(lista) || pos >= lista->tam) {
        printf("-1\n");
        return;
    }
    No *atual = lista->inicio;
    for (int i = 0; atual && i < pos; i++) {
        atual = atual->prox;
    }
    printf("%d\n", atual->dado);
}

int tamanho(Lista *lista) {
    return lista->tam;
}

void imprimir(Lista *lista) {
    No *atual = lista->inicio;
    for (int i = 0; atual; i++) {
        if (i > 0) printf(" ");
        printf("%d", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

void liberar(Lista *lista) {
    No *atual = lista->inicio;
    while (atual) {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    lista->inicio = NULL;
    lista->tam = 0;
}

int main() {
    int q;
    Lista lista;
    inicializar(&lista);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        char op;
        int p = 0;
        scanf(" %c", &op);
        switch (op) {
            case 'I': {
                int x;
                scanf("%d %d", &p, &x);
                inserir(&lista, p, x);
                break;
            }
            case 'R': {
                scanf("%d", &p);
                remover(&lista, p);
                break;
            }
            case 'G': {
                scanf("%d", &p);
                consultar(&lista, p);
                break;
            }
            case 'T': {
                int t = tamanho(&lista);
                printf("%d\n", t);
                break;
            }
            case 'P': {
                imprimir(&lista);
                break;
            }
            default: { break; }
        }
    }
    liberar(&lista);
    return 0;
}