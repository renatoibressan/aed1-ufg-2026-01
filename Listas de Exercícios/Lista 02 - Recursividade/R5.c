#include <stdio.h>

int resultadoTabuleiro(char tab[3][3], char jogador);

int main() {
    char tab[3][3], jogador;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf(" %c", &tab[i][j]);
        }
    }
    scanf(" %c", &jogador);
    int resultado = resultadoTabuleiro(tab, jogador);
    if (resultado == 1) printf("VITORIA\n");
    else if (resultado == 0) printf("EMPATE\n");
    else printf("DERROTA\n");
    return 0;
}

int resultadoTabuleiro(char tab[3][3], char jogador1) {
    char vencedor = '.';
    int temEmpate = 0, temEspaco = 0, temVencedor = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tab[i][j] == '.') {
                temEspaco = 1;
                break;
            }
        }
        if (temEspaco) break;
    }
    if (tab[0][0] == tab[0][1] && tab[0][0] == tab[0][2] && tab[0][0] != '.') {
        vencedor = tab[0][0];
        temVencedor = 1;
    }
    if (tab[1][0] == tab[1][1] && tab[1][0] == tab[1][2] && tab[1][0] != '.') {
        vencedor = tab[1][0];
        temVencedor = 1;
    }
    if (tab[2][0] == tab[2][1] && tab[2][0] == tab[2][2] && tab[2][0] != '.') {
        vencedor = tab[2][0];
        temVencedor = 1;
    }
    if (tab[0][0] == tab[1][0] && tab[0][0] == tab[2][0] && tab[0][0] != '.') {
        vencedor = tab[0][0];
        temVencedor = 1;
    }
    if (tab[0][1] == tab[1][1] && tab[0][1] == tab[2][1] && tab[0][1] != '.') {
        vencedor = tab[0][1];
        temVencedor = 1;
    }
    if (tab[0][2] == tab[1][2] && tab[0][2] == tab[2][2] && tab[0][2] != '.') {
        vencedor = tab[0][2];
        temVencedor = 1;
    }
    if (tab[0][0] == tab[1][1] && tab[0][0] == tab[2][2] && tab[0][0] != '.') {
        vencedor = tab[0][0];
        temVencedor = 1;
    }
    if (tab[0][2] == tab[1][1] && tab[0][2] == tab[2][0] && tab[0][2] != '.') {
        vencedor = tab[0][2];
        temVencedor = 1;
    }
    if (temVencedor) return (jogador1 == vencedor) ? 1 : -1;
    if (!temEspaco) return 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tab[i][j] == '.') {
                tab[i][j] = jogador1;
                char jogador2 = (jogador1 == 'X') ? 'O' : 'X';
                int resultado = resultadoTabuleiro(tab, jogador2);
                tab[i][j] = '.';
                if (resultado == -1) return 1;
                if (resultado == 0) temEmpate = 1;
            }
        }
    }
    return (temEmpate) ? 0 : -1;
}