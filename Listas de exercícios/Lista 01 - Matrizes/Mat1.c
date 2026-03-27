#include <stdio.h>
#define N 199
// Quadrado Magico
void inicializarMatriz(int m[N][N], int n);

void gerarQuadradoMagico(int m[N][N], int n);

void imprimirMatriz(int m[N][N], int n);

int main() {
    int n, m[N][N];
    scanf("%d", &n);
    if (n % 2 == 0 || n < 1 || n > N) return 0;
    inicializarMatriz(m, n);
    gerarQuadradoMagico(m, n);
    imprimirMatriz(m, n);
    return 0;
}

void inicializarMatriz(int m[N][N], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m[i][j] = 0;
        }
    }
}

void gerarQuadradoMagico(int m[N][N], int n) {
    int i = 0, j = n / 2, k;
    int linhaAnterior, colunaAnterior;
    int novaLinha, novaColuna;
    for (k = 1; k <= (n * n); k++) {
        m[i][j] = k;
        linhaAnterior = i;
        colunaAnterior = j;
        novaLinha = i - 1;
        if (novaLinha < 0) novaLinha = n - 1;
        novaColuna = j - 1;
        if (novaColuna < 0) novaColuna = n - 1;
        if (m[novaLinha][novaColuna] != 0) {
            i = linhaAnterior + 1;
            j = colunaAnterior;
        } else {
            i = novaLinha;
            j = novaColuna;
        }
    }
}

void imprimirMatriz(int m[N][N], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}