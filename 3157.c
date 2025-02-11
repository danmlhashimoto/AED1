#include <stdio.h>
#include <string.h>

int main() {
    char texto[281];
    
    while (fgets(texto, sizeof(texto), stdin)) {
        printf("Nao se refuta ciencia com opiniao\n");
    }
    
    return 0;
}
