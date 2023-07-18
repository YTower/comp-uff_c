#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    char nome_arquivo[100];
    float *numeros;
    int tamanho_vetor = 0;
    float soma = 0;
    float media;
    int i;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);

    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (!feof(arquivo)) {
        float numero;
        if (fscanf(arquivo, "%f", &numero) == 1) {
            tamanho_vetor++;
        }
    }

    numeros = (float *)malloc(tamanho_vetor * sizeof(float));
    if (numeros == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(arquivo);
        return 1;
    }

    fseek(arquivo, 0, SEEK_SET);

    for (i = 0; i < tamanho_vetor; i++) {
        fscanf(arquivo, "%f", &numeros[i]);
        soma += numeros[i];
    }

    media = soma / tamanho_vetor;

    fclose(arquivo);

    printf("A média dos números é: %.2f\n", media);

    free(numeros);

    return 0;
}
