#include <stdio.h>

#define LINHAS 3
#define COLUNAS 3

void ler_mat(int matriz[LINHAS][COLUNAS]) {
    printf("elementos da matriz:\n");

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("Digite o elemento da posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void soma_mat(int matriz1[LINHAS][COLUNAS], int matriz2[LINHAS][COLUNAS], int res[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            res[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

int soma_d(int matriz[LINHAS][COLUNAS]) {
    int soma = 0;

    for (int i = 0; i < LINHAS; i++) {
        soma += matriz[i][i];
    }

    return soma;
}

void mult_mat(int matriz1[LINHAS][COLUNAS], int matriz2[LINHAS][COLUNAS], int res[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            res[i][j] = 0;

            for (int k = 0; k < COLUNAS; k++) {
                res[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

void print_mat(int matriz[LINHAS][COLUNAS]) {
    printf("Matriz:\n");

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz1[LINHAS][COLUNAS];
    int matriz2[LINHAS][COLUNAS];
    int res_soma[LINHAS][COLUNAS];
    int res_mult[LINHAS][COLUNAS];
    int soma_d1, soma_d2;

    printf("primeira matriz:\n");
    ler_mat(matriz1);

    printf("segunda matriz:\n");
    ler_mat(matriz2);

    soma_mat(matriz1, matriz2, res_soma);
    soma_d1 = soma_d(matriz1);
    soma_d2 = soma_d(matriz2);
    mult_mat(matriz1, matriz2, res_mult);

    printf("Soma:\n");
    print_mat(res_soma);

    printf("Soma da diagonal da primeira matriz: %d\n", soma_d1);
    printf("Soma da diagonal da segunda matriz: %d\n", soma_d2);

    printf("Produto:\n");
    print_mat(res_mult);

    return 0;
}
