#include <stdio.h>
#include <stdbool.h>

#define MAX_N 50000

int main() {
    int N, M;
    int fila_inicial[MAX_N], sairam[MAX_N];
    bool saiu[MAX_N + 1] = { false }; 

    scanf("%d", &N);  
    for (int i = 0; i < N; i++) {
        scanf("%d", &fila_inicial[i]);
    }

    scanf("%d", &M); 
    for (int i = 0; i < M; i++) {
        scanf("%d", &sairam[i]); 
        saiu[sairam[i]] = true;  
    }

    for (int i = 0; i < N; i++) {
        if (!saiu[fila_inicial[i]]) {
            printf("%d ", fila_inicial[i]); 
        }
    }

    printf("\n");
    return 0;
}
