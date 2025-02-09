#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 300

int precedencia(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int associatividade(char op) {
    if (op == '^') return 0;
    return 1;
}

void infixa_para_posfixa(char* infixa, char* posfixa) {
    char pilha[MAX];
    int topo = -1, j = 0;
    
    for (int i = 0; infixa[i] != '\0'; i++) {
        char c = infixa[i];
        
        if (isalnum(c)) {
            posfixa[j++] = c;
        } else if (c == '(') {
            pilha[++topo] = c;
        } else if (c == ')') {
            while (topo != -1 && pilha[topo] != '(') {
                posfixa[j++] = pilha[topo--];
            }
            topo--;
        } else {
            while (topo != -1 && precedencia(pilha[topo]) >= precedencia(c) &&
                  associatividade(c) == 1 || 
                  (associatividade(c) == 0 && precedencia(pilha[topo]) > precedencia(c))) {
                posfixa[j++] = pilha[topo--];
            }
            pilha[++topo] = c;
        }
    }
    
    while (topo != -1) {
        posfixa[j++] = pilha[topo--];
    }
    posfixa[j] = '\0';
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char infixa[MAX], posfixa[MAX];
        scanf("%s", infixa);

        infixa_para_posfixa(infixa, posfixa);
        printf("%s\n", posfixa);
    }

    return 0;
}

