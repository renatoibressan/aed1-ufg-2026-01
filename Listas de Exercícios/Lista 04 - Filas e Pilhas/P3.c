#include <stdio.h>
#include <stdlib.h>
// Pilha 3
typedef struct no {
    char op;
    struct no *prox;
} No;

typedef struct {
    No *topo;
    int tam;
} Pilha;

void inicializarPilha(Pilha *pilha) {
    pilha->topo = NULL;
    pilha->tam = 0;
}

void empilhar(Pilha *pilha, char val) {
    No *novo = malloc(sizeof(No));
    if (!novo) return;
    novo->op = val;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->tam++;
}

int vazia(Pilha *pilha) {
    return (!(pilha->topo));
}

char desempilhar(Pilha *pilha) {
    if (vazia(pilha)) return -1;
    No *temp = pilha->topo;
    char val = temp->op;
    pilha->topo = (pilha->topo)->prox;
    free(temp);
    pilha->tam--;
    return val;
}

char topo(Pilha *pilha) {
    return (vazia(pilha)) ? -1 : pilha->topo->op;
}

void limparPilha(Pilha *pilha) {
    No *atual = pilha->topo;
    while (atual) {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
        pilha->tam--;
    }
    pilha->topo = NULL;
}

size_t strcspn(const char *txt1, const char *txt2) {
    const char *p1, *p2;
    for (p1 = txt1; *p1 != '\0'; p1++) {
        for (p2 = txt2; *p2 != '\0'; p2++) {
            if (*p1 == *p2) return (p1 - txt1);
        }
    }
    return (p1 - txt1);
}

int validaExpressao(const char *expr) {
    int abertos = 0;
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') abertos++;
        else if (expr[i] == ')') {
            if (abertos == 0) return 0;
            abertos--;
        }
    }
    return abertos == 0;
}

int operando(char op) {
    return ((op >= '1' && op <= '9') || (op >= 'A' && op <= 'Z'));
}

int operador(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/' || op == '^');
}

int prioridade(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void imprimeExpressao(const char *expr) {
    printf("%s\n", expr);
    if (!validaExpressao(expr)) {
        printf("Expressao invalida\n\n");
        return;
    }
    char posfixa[2005] = "";
    int j = 0;
    Pilha pilha;
    inicializarPilha(&pilha);
    for (int i = 0; expr[i] != '\0'; i++) {
        if (operando(expr[i])) {
            posfixa[j++] = expr[i];
            posfixa[j++] = ' ';
        }
        else if (expr[i] == '(') empilhar(&pilha, expr[i]);
        else if (expr[i] == ')') {
            while (!vazia(&pilha) && topo(&pilha) != '(') {
                char c = desempilhar(&pilha);
                posfixa[j++] = c;
                posfixa[j++] = ' ';
            }
            if (vazia(&pilha)) {
                printf("Expressao invalida\n\n");
                limparPilha(&pilha);
                return;
            }
            desempilhar(&pilha);
        }
        else if (operador(expr[i])) {
            char c = expr[i];
            while (!vazia(&pilha) && topo(&pilha) != '(' && (prioridade(topo(&pilha)) > prioridade(c) || (prioridade(topo(&pilha)) == prioridade(c) && c != '^'))) {
                char topo = desempilhar(&pilha);
                posfixa[j++] = topo;
                posfixa[j++] = ' ';
            }
            empilhar(&pilha, c);
        }
    }
    while (!vazia(&pilha)) {
        char c = desempilhar(&pilha);
        if (c == '(') {
            printf("Expressao invalida\n\n");
            limparPilha(&pilha);
            return;
        }
        posfixa[j++] = c;
        posfixa[j++] = ' ';
    }
    if (j > 0 && posfixa[j - 1] == ' ') posfixa[j - 1] = '\0';
    else posfixa[j] = '\0';
    printf("%s\n\n", posfixa);
    limparPilha(&pilha);
}

int main() {
    char expr[1005];
    while (fgets(expr, sizeof(expr), stdin)) {
        expr[strcspn(expr, "\n")] = '\0';
        imprimeExpressao(expr);
    }
    return 0;
}