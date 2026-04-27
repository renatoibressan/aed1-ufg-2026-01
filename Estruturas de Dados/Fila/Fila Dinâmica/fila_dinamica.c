#include <stdio.h>
#include <stdlib.h>
#include "fila_dinamica.h"

void inicializa_fila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
    f->tam = 0;
}

int enqueue(Fila *f, int val) {
    No *novo = malloc(sizeof(No));
    if (!novo) return 0;
    novo->dado = val;
    novo->prox = NULL;
    if (!(f->inicio)) f->inicio = novo;
    else f->fim->prox = novo;
    f->fim = novo;
    f->tam++;
    return 1;
}

int dequeue(Fila *f, int *val) {
    if (!(f->inicio)) return 0;
    No *temp = f->inicio;
    *val = temp->dado;
    f->inicio = f->inicio->prox;
    if (!(f->inicio)) f->fim = NULL;
    free(temp);
    f->tam--;
    return 1;
}

void imprime_fila(const char *mensagem, Fila *f) {
    No *atual = f->inicio;
    printf("%s\n", mensagem);
    while (atual) {
        printf("[%d] -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

void libera_fila(Fila *f) {
    No *atual = f->inicio;
    while (atual) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    f->inicio = NULL;
    f->fim = NULL;
}