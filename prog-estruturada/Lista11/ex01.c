#include <stdio.h>

int somaImparesRecursiva(int vetor[], int tamanho) {
    if (tamanho == 0) {
        return 0;
    }
    int elemento = vetor[tamanho - 1];
    int soma = elemento % 2 == 1 ? elemento : 0; 
    return soma + somaImparesRecursiva(vetor, tamanho - 1);
}

int main() {
    int vetor[] = {2, 5, 8, 9, 12, 15};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int soma = somaImparesRecursiva(vetor, tamanho);
    printf("A soma dos numeros impares do vetor e: %d\n", soma);
    return 0;
}
