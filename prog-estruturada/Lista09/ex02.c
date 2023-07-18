#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float media(char* mat, char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("ERRO\n");
        exit(1);
    }

    char linha[100];
    char matricula[10];
    float p1, p2, p3;
    float media = -1.0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        sscanf(linha, "%s %f %f %f", matricula, &p1, &p2, &p3);
        if (strcmp(matricula, mat) == 0) {
            media = (p1 + p2 + p3) / 3.0;
            break;
        }
    }

    fclose(arquivo);
    return media;
}

int main() {
    char matricula[10] = "8820324-3";
    char nome_arquivo[] = "notas.txt";
    float resultado = media(matricula, nome_arquivo);

    if (resultado == -1.0) {
        printf("Matrícula não encontrada\n");
    } else {
        printf("Média: %.1f\n", resultado);
    }

    return 0;
}
