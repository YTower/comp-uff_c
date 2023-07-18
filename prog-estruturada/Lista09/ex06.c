#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    const float *numero1 = (const float *)a;
    const float *numero2 = (const float *)b;

    if (*numero1 < *numero2) {
        return -1;
    } else if (*numero1 > *numero2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *arquivo_txt, *arquivo_bin;
    char nome_arquivo_txt[] = "numeros.txt";
    char nome_arquivo_bin[] = "numeros.bin";
    float *numeros;
    int tamanho_vetor = 0;
    int i;

    arquivo_txt = fopen(nome_arquivo_txt, "r");
    if (arquivo_txt == NULL) {
        printf("Erro ao abrir o arquivo de texto.\n");
        return 1;
    }

    while (!feof(arquivo_txt)) {
        float numero;
        if (fscanf(arquivo_txt, "%f", &numero) == 1) {
            tamanho_vetor++;
        }
    }

    numeros = (float *)malloc(tamanho_vetor * sizeof(float));
    if (numeros == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(arquivo_txt);
        return 1;
    }

    fseek(arquivo_txt, 0, SEEK_SET);

    for (i = 0; i < tamanho_vetor; i++) {
        fscanf(arquivo_txt, "%f", &numeros[i]);
    }

    qsort(numeros, tamanho_vetor, sizeof(float), comparar);

    fclose(arquivo_txt);

    arquivo_bin = fopen(nome_arquivo_bin, "wb");
    if (arquivo_bin == NULL) {
        printf("Erro ao abrir o arquivo binário.\n");
        free(numeros);
        return 1;
    }

    fwrite(numeros, sizeof(float), tamanho_vetor, arquivo_bin);

    fclose(arquivo_bin);

    free(numeros);

    printf("Os números foram ordenados e gravados no arquivo binário com sucesso.\n");

    return 0;
}
