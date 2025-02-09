#include <stdio.h>
#include <string.h>

int contar_diamantes(char caso[]) {
    int diamantes = 0;
    int pilha = 0;

    for (int i = 0; i < strlen(caso); i++) {
        if (caso[i] == '<') {
            pilha++;
        } else if (caso[i] == '>' && pilha > 0) {
            pilha--;
            diamantes++;
        }
    }

    return diamantes;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char caso[1001];
        scanf("%s", caso);
        printf("%d\n", contar_diamantes(caso));
    }

    return 0;
}
