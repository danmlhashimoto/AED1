#include <stdio.h>
#include <string.h>

int main() {
    char d, n[102];
    
    while (1) {
        scanf(" %c %s", &d, n);
        
        if (d == '0' && strcmp(n, "0") == 0) {
            break;
        }
        
        char resultado[102] = "";
        int j = 0;
        
        for (int i = 0; n[i] != '\0'; i++) {
            if (n[i] != d) {
                resultado[j++] = n[i];
            }
        }
        resultado[j] = '\0';
        
        if (j == 0) {
            printf("0\n");
        } else {
            int k = 0;
            while (resultado[k] == '0') {
                k++;
            }
            if (resultado[k] == '\0') {
                printf("0\n");
            } else {
                printf("%s\n", &resultado[k]);
            }
        }
    }
    
    return 0;
}
