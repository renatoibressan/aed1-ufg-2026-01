#include <stdio.h>
#include <stdlib.h>
// Lista 3 (com Insertion Sort)
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

void inserir_lista(Lista *lista, int val) {
    No *novo = malloc(sizeof(No));
    novo->dado = val;
    novo->ant = NULL;
    novo->prox = NULL;
    if (!lista->inicio) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    lista->tam++;
}

void inserir_inicio(Lista *lista, No *novo) {
    novo->ant = NULL;
    novo->prox = lista->inicio;
    if (lista->inicio) lista->inicio->ant = novo;
    else lista->fim = novo;
    lista->inicio = novo;
}

void inserir_depois(Lista *lista, No *ref, No *novo) {
    novo->ant = ref;
    novo->prox = ref->prox;
    if (ref->prox) ref->prox->ant = novo;
    else lista->fim = novo;
    ref->prox = novo;
}

void desconectar(Lista *lista, No *atual) {
    if (atual->ant) atual->ant->prox = atual->prox;
    else lista->inicio = atual->prox;
    if (atual->prox) atual->prox->ant = atual->ant;
    else lista->fim = atual->ant;
}

void ordenar(Lista *lista) {
    if (!lista->inicio || !lista->inicio->prox) return;
    No *atual = lista->inicio->prox;
    while (atual) {
        No *prox = atual->prox;
        No *comp = atual->ant;
        while (comp && comp->dado > atual->dado) {
            comp = comp->ant;
        }
        if (comp != atual->ant) {
            desconectar(lista, atual);
            if (!comp) inserir_inicio(lista, atual);
            else inserir_depois(lista, comp, atual);
        }
        atual = prox;
    }
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
    lista->fim = NULL;
    lista->tam = 0;
}

int main() {
    int n;
    Lista lista;
    inicializar(&lista);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        inserir_lista(&lista, x);
    }
    ordenar(&lista);
    imprimir(&lista);
    liberar(&lista);
    return 0;
}