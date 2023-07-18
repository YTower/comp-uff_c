#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_char(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}

void sort_bolha(char vet[], int tamanho) {
    int i, j;
    char temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - 1 - i; j++) {
            if (vet[j] > vet[j + 1]) {
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
}

int particionar(char vet[], int inicio, int fim) {
    char pivo = vet[fim];
    int i = inicio - 1;
    int j;

    for (j = inicio; j <= fim - 1; j++) {
        if (vet[j] < pivo) {
            i++;
            char temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
        }
    }

    char temp = vet[i + 1];
    vet[i + 1] = vet[fim];
    vet[fim] = temp;

    return i + 1;
}

void quick_sort(char vet[], int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particionar(vet, inicio, fim);
        quick_sort(vet, inicio, pivo - 1);
        quick_sort(vet, pivo + 1, fim);
    }
}

int main() {
    char vet[] = "programacao";
    int tamanho = strlen(vet);

    printf("vet original: %s\n", vet);

    sort_bolha(vet, tamanho);
    printf("Ordenado usando o método da Bolha: %s\n", vet);

    quick_sort(vet, 0, tamanho - 1);
    printf("Ordenado usando o QuickSort: %s\n", vet);

    qsort(vet, tamanho, sizeof(char), compare_char);
    printf("Ordenado usando qsort: %s\n", vet);

    return 0;
}
