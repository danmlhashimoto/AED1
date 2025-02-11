#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_TAMANHO 10004
#define MAX_PALAVRAS 1000

// N funncionou aaaaaa

typedef struct {
    char letra;
    char palavra[31];
    int economia;
} Abreviacao;

int cmp(const void *a, const void *b) {
    return ((Abreviacao *)a)->letra - ((Abreviacao *)b)->letra;
}

int main() {
    char linha[MAX_TAMANHO];
    
    while (fgets(linha, MAX_TAMANHO, stdin)) {
        if (linha[0] == '.' && linha[1] == '\n') break;
        
        char palavras[MAX_PALAVRAS][31];
        int contagem[MAX_PALAVRAS] = {0};
        int num_palavras = 0;
        
        char *token = strtok(linha, " \n");
        while (token) {
            int encontrado = 0;
            for (int i = 0; i < num_palavras; i++) {
                if (strcmp(palavras[i], token) == 0) {
                    contagem[i]++;
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                strcpy(palavras[num_palavras], token);
                contagem[num_palavras++] = 1;
            }
            token = strtok(NULL, " \n");
        }
        
        Abreviacao abreviacoes[26] = {0};
        int num_abreviacoes = 0;
        
        for (int i = 0; i < num_palavras; i++) {
            char letra = palavras[i][0];
            int economia = (strlen(palavras[i]) - 2) * contagem[i];
            
            if (economia > 0) {
                if (abreviacoes[letra - 'a'].letra == 0 || economia > abreviacoes[letra - 'a'].economia) {
                    abreviacoes[letra - 'a'].letra = letra;
                    strcpy(abreviacoes[letra - 'a'].palavra, palavras[i]);
                    abreviacoes[letra - 'a'].economia = economia;
                }
            }
        }
        
        qsort(abreviacoes, 26, sizeof(Abreviacao), cmp);
        
        char resultado[MAX_TAMANHO] = "";
        char *ptr = resultado;
        char *temp = strtok(linha, " \n");
        while (temp) {
            int substituido = 0;
            for (int i = 0; i < 26; i++) {
                if (abreviacoes[i].letra == temp[0] && strcmp(abreviacoes[i].palavra, temp) == 0) {
                    ptr += sprintf(ptr, "%c. ", abreviacoes[i].letra);
                    substituido = 1;
                    break;
                }
            }
            if (!substituido) {
                ptr += sprintf(ptr, "%s ", temp);
            }
            temp = strtok(NULL, " \n");
        }
        
        printf("%s\n", resultado);
        
        int abreviacoes_usadas = 0;
        for (int i = 0; i < 26; i++) {
            if (abreviacoes[i].letra != 0) abreviacoes_usadas++;
        }
        printf("%d\n", abreviacoes_usadas);
        for (int i = 0; i < 26; i++) {
            if (abreviacoes[i].letra != 0) {
                printf("%c. = %s\n", abreviacoes[i].letra, abreviacoes[i].palavra);
            }
        }
    }
    
    return 0;
}
