#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void read_names(char nomes[MAX][100]) {
    int i = 0;
    char nome[100];

    printf("Informe os nomes das pessoas (digite 'fim' para encerrar):\n");

    while (i < MAX) {
        printf("Nome %d: ", i + 1);
        scanf("%s", nome);

        if (strcmp(nome, "fim") == 0) {
            break;
        }

        strcpy(nomes[i], nome);
        i++;
    }
}

float media_tam(char nomes[MAX][100], int total_nomes) {
    int soma_tam = 0;

    for (int i = 0; i < total_nomes; i++) {
        soma_tam += strlen(nomes[i]);
    }

    return (float)soma_tam / total_nomes;
}

float var_nomes(char nomes[MAX][100], int total_nomes, float media) {
    float soma_dif = 0;

    for (int i = 0; i < total_nomes; i++) {
        int tam_nome = strlen(nomes[i]);
        soma_dif += (tam_nome - media) * (tam_nome - media);
    }

    return soma_dif / total_nomes;
}

int main() {
    char nomes[MAX][100];
    int total_nomes = 0;
    float media, variancia;

    read_names(nomes);
    total_nomes = strlen(nomes);

    media = media_tam(nomes, total_nomes);
    variancia = var_nomes(nomes, total_nomes, media);

    printf("Média do tamanho dos nomes: %.2f\n", media);
    printf("Variância do tamanho dos nomes: %.2f\n", variancia);

    return 0;
}
