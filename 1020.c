#include <stdio.h>
 
int main() {
    int I;
    scanf("%i", &I);
    printf("%i ano(s)\n%i mes(es)\n%i dia(s)\n", I/365, (I%365)/30, (I%365)%30);
}
