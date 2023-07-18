#include <stdio.h>

int main() {
    
    int x[10];
    int y[10];

    for(int i = 0; i < 10; i++) {
        printf("Digite um numero: ");
        scanf("%d", &x[i]);
    }
    
    printf("-------------------\n");

    for(int i = 9; i >= 0; i--) {
        y[(9 - i)] = x[i];
    }
    printf("Vetor invertido: \n");
    for(int i = 0; i < 10; i++) {
        printf("%d\n", y[i]);
    }
    
    return 0;
}
