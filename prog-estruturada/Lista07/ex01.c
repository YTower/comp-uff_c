#include <stdio.h>

#define LINHA 3
#define COLUNA 3

void ler_mat(int matriz[LINHA][COLUNA]) {
    printf("elementos da matriz:\n");
  
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            printf("Digite o elemento da posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void soma_mat(int matriz1[LINHA][COLUNA], int matriz2[LINHA][COLUNA], int res[LINHA][COLUNA]) {
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            res[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

void imprimir_matriz(int matriz[LINHA][COLUNA]) {
    printf("resultante:\n");
  
    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz1[LINHA][COLUNA];
    int matriz2[LINHA][COLUNA];
    int res[LINHA][COLUNA];

    printf("Leitura da primeira matriz:\n");
    ler_mat(matriz1);

    printf("Leitura da segunda matriz:\n");
    ler_mat(matriz2);

    soma_mat(matriz1, matriz2, res);

    imprimir_matriz(res);

    return 0;
}
