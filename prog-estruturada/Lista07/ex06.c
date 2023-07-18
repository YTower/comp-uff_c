#include <stdio.h>

#define TAM 5

void print_tab(int tabela[TAM][TAM]) {
    printf("Distâncias entre as cidades:\n");
    printf("   1   2   3   4   5\n");

    for (int i = 0; i < TAM; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < TAM; j++) {
            if (j <= i) {
                printf("   -");
            } else {
                printf("%4d", tabela[i][j]);
            }
        }
        printf("\n");
    }
}

int calc_dist(int tabela[TAM][TAM], int cidade1, int cidade2) {
    if (cidade1 == cidade2) {
        return 0;
    } else if (cidade1 > cidade2) {
        return tabela[cidade2 - 1][cidade1 - 1];
    } else {
        return tabela[cidade1 - 1][cidade2 - 1];
    }
}

int calc_dist_total(int tabela[TAM][TAM], int percurso[], int tamanho) {
    int dist_total = 0;
    for (int i = 0; i < tamanho - 1; i++) {
        dist_total += calc_dist(tabela, percurso[i], percurso[i + 1]);
    }
    return dist_total;
}

int main() {
    int tabela_dist[TAM][TAM] = {
        {0, 15, 30, 5, 12},
        {15, 0, 10, 17, 28},
        {30, 10, 0, 3, 11},
        {5, 17, 3, 0, 80},
        {12, 28, 11, 80, 0}
    };

    print_tab(tabela_dist);

    int cidade1, cidade2;
    while (1) {
        printf("\nDigite o código da primeira cidade (0 para sair): ");
        scanf("%d", &cidade1);
        if (cidade1 == 0) {
            break;
        }
        printf("Digite o código da segunda cidade (0 para sair): ");
        scanf("%d", &cidade2);
        if (cidade2 == 0) {
            break;
        }

        int dist = calc_dist(tabela_dist, cidade1, cidade2);
        if (dist == 0) {
            printf("As cidades são iguais.\n");
        } else if (dist < 0) {
            printf("Código de cidade inválido.\n");
        } else {
            printf("Distância entre as cidades %d e %d: %d km\n", cidade1, cidade2, dist);
        }
    }

    int percurso[] = {1, 2, 3, 2, 5, 1, 4};
    int tam_perc = TAMof(percurso) / TAMof(percurso[0]);
    int dist_total = calc_dist_total(tabela_dist, percurso, tam_perc);
    printf("\nDistância total percorrida no percurso: %d km\n", dist_total);

    return 0;
}
