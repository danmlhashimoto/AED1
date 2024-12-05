#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 50000 /* constante para definir tamanho do vetor */

/* função para gerar um vetor com valores aleatórios */
void gerarVetor(int v[]) {
    srand(time(NULL));
    for (int i = 0; i < TAM; i++) {
        /* gera um número aleatório entre 0 e 100000 */
        v[i] = rand() % 100001;
    }
}

/* função para ordenar o vetor usando InsertionSort */
void InsertionSort(int v[])
{
    for (int i = 1; i < TAM; i++) {
        int aux = v[i];
        int j = i - 1;

        /* move os elementos de v[0...i-1] que são maiores que a variavel auxiliar para uma posição a frente */
        while (j >= 0 && v[j] > aux) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = aux;
    }
}

int main() {
    clock_t t; /* variável para armazenar tempo */
    int v[TAM]; /* vetor com nº de posições igual a TAM */

    gerarVetor(v);
    t = clock(); /* armazena o tempo */
    InsertionSort(v);
    t = clock() - t; /* tempo inicial - final */
    printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000))); /* conversão para double */
}
