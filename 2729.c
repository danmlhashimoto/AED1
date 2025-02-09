#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 1000
#define MAX_TAMANHO 21

int comparar(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void organizar_lista_compras(int n, char listas[][MAX_ITENS * MAX_TAMANHO]) {
    for (int i = 0; i < n; i++) {
        char *itens[MAX_ITENS];
        int count = 0;
        char *token = strtok(listas[i], " ");
        while (token != NULL) {
            int encontrado = 0;
            for (int j = 0; j < count; j++) {
                if (strcmp(itens[j], token) == 0) {
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                itens[count] = token;
                count++;
            }
            token = strtok(NULL, " ");
        }
        qsort(itens, count, sizeof(char *), comparar);
        for (int j = 0; j < count; j++) {
            if (j > 0) printf(" ");
            printf("%s", itens[j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    
    char listas[n][MAX_ITENS * MAX_TAMANHO];
    for (int i = 0; i < n; i++) {
        fgets(listas[i], sizeof(listas[i]), stdin);
        listas[i][strcspn(listas[i], "\n")] = 0;
    }
    
    organizar_lista_compras(n, listas);
    return 0;
}
