#include <stdio.h>

int main() {
    double valor;
    int notas, moedas;
    int valoresNotas[] = {100, 50, 20, 10, 5, 2};
    int valoresMoedas[] = {100, 50, 25, 10, 5, 1};

    scanf("%lf", &valor);
    
    int valorCentavos = (int)(valor * 100 + 0.5); 
    
    printf("NOTAS:\n");
    for (int i = 0; i < 6; i++) {
        notas = valorCentavos / (valoresNotas[i] * 100);
        printf("%d nota(s) de R$ %d.00\n", notas, valoresNotas[i]);
        valorCentavos %= (valoresNotas[i] * 100);
    }
    
    printf("MOEDAS:\n");
    for (int i = 0; i < 6; i++) {
        moedas = valorCentavos / valoresMoedas[i];
        printf("%d moeda(s) de R$ %.2f\n", moedas, valoresMoedas[i] / 100.0);
        valorCentavos %= valoresMoedas[i];
    }
    
    return 0;
}
