typedef struct no {
    int dado;
    struct no *prox;
} No;

void insere_inicio(No **head, int val);
void imprime_lista(const char *mensagem, No *no);
void libera_lista(No **head);