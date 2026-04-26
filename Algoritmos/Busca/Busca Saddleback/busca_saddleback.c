#include "busca_saddleback.h"

void bubble_sort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int busca_saddleback(int m[100][100], int n, int x, int pos[2]) {
    int i = 0, j = n - 1;
    while (i < n && j >= 0) {
        if (m[i][j] == x) {
            pos[0] = i + 1;
            pos[1] = j + 1;
            return 1;
        }
        else if (m[i][j] > x) j--;
        else i++;
    }
    return 0;
}