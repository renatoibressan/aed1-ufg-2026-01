#include <stdio.h>
#include <stdlib.h>
#define N 200000
// Fila 4
typedef struct {
    int frente, tras, tam;
    int dados[N];
} Deque;

void inicializar(Deque *deque) {
    deque->frente = deque->tras = deque->tam = 0;
}

int vazia(Deque *deque) {
    return (deque->tam == 0);
}

void push_back(Deque *deque, int val) {
    deque->dados[deque->tras] = val;
    deque->tras = (deque->tras + 1) % N;
    deque->tam++;
}

void pop_front(Deque *deque) {
    if (vazia(deque)) return;
    deque->frente = (deque->frente + 1) % N;
    deque->tam--;
}

void pop_back(Deque *deque) {
    if (vazia(deque)) return;
    deque->tras = (deque->tras - 1 + N) % N;
    deque->tam--;
}

int front(Deque *deque) {
    return deque->dados[deque->frente];
}

int back(Deque *deque) {
    return deque->dados[deque->tras];
}

void sliding_window(Deque *deque, int v[], int n, int k) {
    long long soma = 0;
    for (int i = 0; i < n; i++) {
        while (!vazia(deque) && front(deque) <= i - k) pop_front(deque);
        while (!vazia(deque) && v[back(deque)] > v[i]) pop_back(deque);
        push_back(deque, i);
        soma += v[i];
        if (i >= k) soma -= v[i - k];
        printf("%lld\n", soma);
    }
}

int main() {
    int n, k, v[N];
    Deque deque;
    inicializar(&deque);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    sliding_window(&deque, v, n, k);
    return 0;
}