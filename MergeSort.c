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

/* função auxiliar para intercalar dois sub-vetores */
void intercalar(int v[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    /* vetores temporários */
    int L[n1], R[n2];

    /* copiando dados para os vetores temporários */
    for (int i = 0; i < n1; i++)
        L[i] = v[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[meio + 1 + j];

    /* valores iniciais */
    int i = 0, j = 0, k = inicio;

    /* intercala os dois vetores */
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    /* copia os elementos restantes de L[] */
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    /* copia os elementos restantes de R[] */
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

/* função recursiva do MergeSort */
void mergeSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        /* ordena a primeira e a segunda metade */
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);

        /* intercala as metades ordenadas */
        intercalar(v, inicio, meio, fim);
    }
}

int main() {
    clock_t t; /* variável para armazenar tempo */
    int v[TAM]; /* vetor com nº de posições igual a TAM */

    gerarVetor(v);
    t = clock(); /* armazena o tempo */
    mergeSort(v, 0, TAM - 1);
    t = clock() - t; /* tempo inicial - final */
    printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000))); /* conversão para double */
}
