#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Lista 2
typedef struct no {
    int dado;
    struct no *ant;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tam;
} Lista;

void inicializar(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void inserir(Lista *lista, int pos, int val) {
    if (pos < 0 || pos > lista->tam) {
        printf("-1\n");
        return;
    }
    No *novo = malloc(sizeof(No));
    novo->dado = val;
    novo->ant = NULL;
    novo->prox = NULL;
    if (pos == 0) {
        novo->prox = lista->inicio;
        if (lista->inicio) lista->inicio->ant = novo;
        else lista->fim = novo;
        lista->inicio = novo;
        lista->tam++;
        return;
    }
    if (pos == lista->tam) {
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
        lista->tam++;
        return;
    }
    No *atual = lista->inicio;
    for (int i = 0; i < pos; i++) {
        atual = atual->prox;
    }
    novo->prox = atual;
    novo->ant = atual->ant;
    atual->ant->prox = novo;
    atual->ant = novo;
    lista->tam++;
}

void remover(Lista *lista, int pos) {
    if (pos < 0 || pos >= lista->tam) {
        printf("-1\n");
        return;
    }
    if (pos == 0) {
        No *removido = lista->inicio;
        lista->inicio = removido->prox;
        if (lista->inicio) lista->inicio->ant = NULL;
        else lista->fim = NULL;
        free(removido);
        lista->tam--;
        return;
    }
    if (pos == lista->tam - 1) {
        No *removido = lista->fim;
        lista->fim = removido->ant;
        lista->fim->prox = NULL;
        free(removido);
        lista->tam--;
        return;
    }
    No *removido = lista->inicio;
    for (int i = 0; i < pos; i++) {
        removido = removido->prox;
    }
    removido->ant->prox = removido->prox;
    removido->prox->ant = removido->ant;
    free(removido);
    lista->tam--;
}

void consultar(Lista *lista, int pos) {
    if (pos < 0 || pos >= lista->tam) {
        printf("-1\n");
        return;
    }
    if (pos < lista->tam / 2) {
        No *atual = lista->inicio;
        for (int i = 0; i < pos; i++) {
            atual = atual->prox;
        }
        printf("%d\n", atual->dado);
        return;
    }
    No *atual = lista->fim;
    for (int i = lista->tam - 1; i > pos; i--) {
        atual = atual->ant;
    }
    printf("%d\n", atual->dado);
}

int tamanho(Lista *lista) {
    return lista->tam;
}

void imprimir_esquerda(Lista *lista) {
    No *atual = lista->inicio;
    for (int i = 0; atual; i++) {
        if (i > 0) printf(" ");
        printf("%d", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

void imprimir_direita(Lista *lista) {
    No *atual = lista->fim;
    for (int i = 0; atual; i++) {
        if (i > 0) printf(" ");
        printf("%d", atual->dado);
        atual = atual->ant;
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
    lista->fim = NULL;
    lista->tam = 0;
}

int main() {
    int q;
    Lista lista;
    inicializar(&lista);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        char op[3];
        int p = 0;
        scanf("%s", op);
        if (strcmp(op, "I") == 0) {
            int x;
            scanf("%d %d", &p, &x);
            inserir(&lista, p, x);
        } else if (strcmp(op, "R") == 0) {
            scanf("%d", &p);
            remover(&lista, p);
        } else if (strcmp(op, "G") == 0) {
            scanf("%d", &p);
            consultar(&lista, p);
        } else if (strcmp(op, "T") == 0) {
            int t = tamanho(&lista);
            printf("%d\n", t);
        } else if (strcmp(op, "PL") == 0) {
            imprimir_esquerda(&lista);
        } else if (strcmp(op, "PR") == 0) {
            imprimir_direita(&lista);
        }
    }
    liberar(&lista);
    return 0;
}