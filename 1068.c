#include <stdio.h>
#include <string.h>

#define MAX 1000

int validar_parenteses(const char *expressao) {
    int pilha = 0;
    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            pilha++;
        } else if (expressao[i] == ')') {
            if (pilha == 0) {
                return 0;
            }
            pilha--;
        }
    }
    return pilha == 0;
}

int main() {
    char expressao[MAX];
    while (fgets(expressao, MAX, stdin)) {
        expressao[strcspn(expressao, "\n")] = 0;
        printf("%s\n", validar_parenteses(expressao) ? "correct" : "incorrect");
    }
    return 0;
}
