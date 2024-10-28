#include <stdio.h>

int verLinha(int matriz[9][9]) {
    for (int i = 0; i < 9; i++) {
        int numeros[9] = {0};
        for (int j = 0; j < 9; j++) {
            int num = matriz[i][j];
            if (num < 1 || num > 9 || numeros[num - 1]) return 0;
            numeros[num - 1] = 1;
        }
    }
    return 1;
}

int verColuna(int matriz[9][9]) {
    for (int j = 0; j < 9; j++) {
        int numeros[9] = {0};
        for (int i = 0; i < 9; i++) {
            int num = matriz[i][j];
            if (num < 1 || num > 9 || numeros[num - 1]) return 0;
            numeros[num - 1] = 1;
        }
    }
    return 1;
}

int verBloco(int matriz[9][9]) {
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            int numeros[9] = {0};
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    int num = matriz[i + k][j + l];
                    if (num < 1 || num > 9 || numeros[num - 1]) return 0;
                    numeros[num - 1] = 1;
                }
            }
        }
    }
    return 1;
}

int verSudoku(int matriz[9][9]) {
    return verLinha(matriz) && verColuna(matriz) && verBloco(matriz);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int k = 1; k <= n; k++) {
        int matriz[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }
        printf("Instancia %d\n", k);
        if (verSudoku(matriz)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }

    return 0;
}
