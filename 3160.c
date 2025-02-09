#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 21
#define MAX_AMIGOS 1000

void inserir_amigos(char lista[][MAX_NOME], int *tamanho, char novos[][MAX_NOME], int novos_tamanho, char *amigo_indicado) {
    int pos = *tamanho;
    if (strcmp(amigo_indicado, "nao") != 0) {
        for (int i = 0; i < *tamanho; i++) {
            if (strcmp(lista[i], amigo_indicado) == 0) {
                pos = i;
                break;
            }
        }
    }
    
    for (int i = *tamanho - 1; i >= pos; i--) {
        strcpy(lista[i + novos_tamanho], lista[i]);
    }
    
    for (int i = 0; i < novos_tamanho; i++) {
        strcpy(lista[pos + i], novos[i]);
    }
    
    *tamanho += novos_tamanho;
}

int main() {
    char lista[MAX_AMIGOS][MAX_NOME], novos[MAX_AMIGOS][MAX_NOME], amigo_indicado[MAX_NOME];
    int tamanho = 0, novos_tamanho = 0;
    
    char linha[5000];
    fgets(linha, sizeof(linha), stdin);
    char *token = strtok(linha, " \n");
    while (token) {
        strcpy(lista[tamanho++], token);
        token = strtok(NULL, " \n");
    }
    
    fgets(linha, sizeof(linha), stdin);
    token = strtok(linha, " \n");
    while (token) {
        strcpy(novos[novos_tamanho++], token);
        token = strtok(NULL, " \n");
    }
    
    fgets(amigo_indicado, sizeof(amigo_indicado), stdin);
    amigo_indicado[strcspn(amigo_indicado, "\n")] = 0;
    
    inserir_amigos(lista, &tamanho, novos, novos_tamanho, amigo_indicado);
    
    for (int i = 0; i < tamanho; i++) {
        if (i > 0) printf(" ");
        printf("%s", lista[i]);
    }
    printf("\n");
    
    return 0;
}
