#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica.h"

No* insere_inicio(No *head, int val) {
    No *novo = malloc(sizeof(No));
    novo->dado = val;
    novo->prox = head;
    return novo;
}

void imprime_lista(const char *mensagem, No *head) {
    printf("%s\n[", mensagem);
    while (head) {
        printf("%d -> ", head->dado);
        head = head->prox;
    }
    printf("NULL]\n");
}

void libera_lista(No **head) {
    No *atual = *head;
    No *prox;
    while (atual) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    *head = NULL;
}