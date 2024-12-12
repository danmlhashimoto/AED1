#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 400000 /* constante para definir tamanho do vetor */

/* função para gerar um vetor com valores aleatórios */
void gerarVetor(int v[]) {
    srand(time(NULL));
    for (int i = 0; i < TAM; i++) {
        /* gera um número aleatório entre 0 e 100000 */
        v[i] = rand() % 100001;
    }
}

/* Função auxiliar para trocar dois elementos */
void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Função para separar o vetor */
int Separa(int v[], int low, int high) {
    int pivot = v[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (v[j] <= pivot) {
            i++;
            trocar(&v[i], &v[j]);
        }
    }
    trocar(&v[i + 1], &v[high]);
    return (i + 1);
}

/* Implementação do Quick Sort */
void QuickSort(int v[], int low, int high) {
    if (low < high) {
        int pi = Separa(v, low, high);

        // Ordena os subvetores
        QuickSort(v, low, pi - 1);
        QuickSort(v, pi + 1, high);
    }
}

int main() {
    clock_t t; /* variável para armazenar tempo */
    int v[TAM]; /* vetor com nº de posições igual a TAM */

    gerarVetor(v);
    t = clock(); /* armazena o tempo */
    QuickSort(v, 0, TAM - 1);
    t = clock() - t; /* tempo inicial - final */
    printf("Tempo de execucao: %lf ms\n", ((double)t) / ((CLOCKS_PER_SEC / 1000))); /* conversão para double */

    return 0;
}
