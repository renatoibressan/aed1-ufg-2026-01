#include <stdio.h>
#include <stdlib.h>
#include "pilha_dinamica.h"

int push(No **topo, int val) {
    No *novo = malloc(sizeof(No));
    if (!novo) return 0;
    novo->dado = val;
    novo->prox = *topo;
    *topo = novo;
    return 1;
}

int pop(No **topo, int *val) {
    if (!(*topo)) return 0;
    No *temp = *topo;
    *val = temp->dado;
    *topo = (*topo)->prox;
    free(temp);
    return 1;
}

void imprime_pilha(const char *mensagem, No *topo) {
    printf("%s\n", mensagem);
    while (topo) {
        printf("[%d]\n", topo->dado);
        topo = topo->prox;
    }
}

void libera_pilha(No **topo) {
    No *atual = *topo;
    while (atual) {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    *topo = NULL;
}