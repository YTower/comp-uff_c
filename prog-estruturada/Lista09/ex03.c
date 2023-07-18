#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    char inputFileName[50], outputFileName[50];
    char line[MAX_LINE_LENGTH];
    
    printf("Digite o nome do arquivo .c de entrada: ");
    scanf("%s", inputFileName);
    
    printf("Digite o nome do arquivo .c de saída: ");
    scanf("%s", outputFileName);
    
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");
    
    if (inputFile == NULL || outputFile == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        exit(1);
    }
    
    while (fgets(line, MAX_LINE_LENGTH, inputFile) != NULL) {
        // Verifica se a linha começa com o marcador de comentário "//"
        if (strncmp(line, "//", 2) != 0) {
            fputs(line, outputFile);
        }
    }
    
    printf("Arquivo gerado com sucesso!\n");
    
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}
