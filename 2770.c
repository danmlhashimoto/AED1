#include <stdio.h>

int main() {
    int X, Y, M;
    
    while (scanf("%d %d %d", &X, &Y, &M) != EOF) {
        for (int i = 0; i < M; i++) {
            int Xi, Yi;
            scanf("%d %d", &Xi, &Yi);
            
            if ((Xi <= X && Yi <= Y) || (Yi <= X && Xi <= Y)) {
                printf("Sim\n");
            } else {
                printf("Nao\n");
            }
        }
    }
    
    return 0;
}
