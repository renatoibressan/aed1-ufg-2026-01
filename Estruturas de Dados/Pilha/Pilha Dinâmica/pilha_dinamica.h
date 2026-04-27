typedef struct no {
    int dado;
    struct no *prox;
} No;

int push(No **topo, int val);
int pop(No **topo, int *val);
void imprime_pilha(const char *mensagem, No *topo);
void libera_pilha(No **topo);