typedef struct no {
    int dado;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tam;
} Fila;

void inicializa_fila(Fila *f);
int enqueue(Fila *f, int val);
int dequeue(Fila *f, int *val);
void imprime_fila(const char *mensagem, No *head);
void libera_fila(Fila *f);