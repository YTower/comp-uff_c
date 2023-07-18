#include <stdio.h>

#define TAM 3

void ler_mat(float matriz[TAM][TAM]) {
    printf("elementos da matriz:\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("Digite o elemento da posição [%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }
}

void print_mat(float matriz[TAM][TAM]) {
    printf("Matriz:\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

void mat_inversa(float matriz[TAM][TAM], float inversa[TAM][TAM]) {
    float det = 0.0;

    for (int i = 0; i < TAM; i++) {
        det += (matriz[0][i] * (matriz[1][(i + 1) % TAM] * matriz[2][(i + 2) % TAM] - matriz[1][(i + 2) % TAM] * matriz[2][(i + 1) % TAM]));
    }

    if (det == 0) {
        printf("não tem inversa\n");
        return;
    }

    float adjunta[TAM][TAM];
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            adjunta[i][j] = (matriz[(j + 1) % TAM][(i + 1) % TAM] * matriz[(j + 2) % TAM][(i + 2) % TAM]) - (matriz[(j + 1) % TAM][(i + 2) % TAM] * matriz[(j + 2) % TAM][(i + 1) % TAM]);
        }
    }

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            inversa[i][j] = adjunta[i][j] / det;
        }
    }
}

int ver_simetria(float matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = i + 1; j < TAM; j++) {
            if (matriz[i][j] != matriz[j][i]) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    float matriz[TAM][TAM];
    float inversa[TAM][TAM];

    ler_mat(matriz);
    print_mat(matriz);

    mat_inversa(matriz, inversa);

    print_mat(inversa);

    int simetrica = ver_simetria(matriz);

    if (simetrica) {
        printf("A matriz é simétrica.\n");
    } else {
        printf("A matriz não é simétrica.\n");
    }

    return 0;
}
