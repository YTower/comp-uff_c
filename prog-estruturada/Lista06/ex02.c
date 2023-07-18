#include <stdio.h>

void inicializarVetorMultiplos(int vetor[], int tamanho, int multiplo) {
    int i;
    for (i = 0; i < tamanho; i++) {
        vetor[i] = (i + 1) * multiplo;
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[10];

    inicializarVetorMultiplos(vetor, 10, 5);
    imprimirVetor(vetor, 10);

    return 0;
}
