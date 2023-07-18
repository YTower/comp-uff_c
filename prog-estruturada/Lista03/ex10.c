#include <stdio.h>

#define SIZE 20

int main()
{
    int lhs[SIZE], rhs[SIZE];
    float result[SIZE];
    char arithmeticOperations[SIZE];

    // Recebe os vetores de inteiros e o vetor de operações do usuário
    printf("Digite os elementos do primeiro vetor:\n");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &lhs[i]);
    }
    printf("Digite os elementos do segundo vetor:\n");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &rhs[i]);
    }
    printf("Digite as operacoes (+, -, * ou /) a serem realizadas:\n");
    for (int i = 0; i < SIZE; i++) {
        scanf(" %c", &arithmeticOperations[i]);
    }

    // Realiza as operações e armazena os resultados no vetor de resultado
    for (int i = 0; i < SIZE; i++) {
        if (arithmeticOperations[i] == '+') {
            result[i] = (float)lhs[i] + rhs[i];
        } else if (arithmeticOperations[i] == '-') {
            result[i] = (float)lhs[i] - rhs[i];
        } else if (arithmeticOperations[i] == '*') {
            result[i] = (float)lhs[i] * rhs[i];
        } else if (arithmeticOperations[i] == '/') {
            result[i] = (float)lhs[i] / rhs[i];
        } else {
            printf("Operacao invalida!\n");
            return 1;
        }
    }

    // Mostra o vetor de resultado na tela
    printf("Resultado:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%.2f ", result[i]);
    }
    printf("\n");

    return 0;
}
