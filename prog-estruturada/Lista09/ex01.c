#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float busca(char* arquivo, char* matricula) {
    FILE* file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("ERRO\n");
        exit(1);
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), file) != NULL) {
        char alunoMatricula[20];
        float alunoCR;
        sscanf(linha, "%s %f", alunoMatricula, &alunoCR);
        
        if (strcmp(alunoMatricula, matricula) == 0) {
            fclose(file);
            return alunoCR;
        }
    }

    fclose(file);
    return -1.0;
}
