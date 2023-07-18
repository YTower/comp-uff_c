#include <stdio.h>

void readValuesFrom(int v[], int n)
{
    printf("Insira %d valores inteiros:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
}

void printValuesFrom(int v[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n\n");
}

int searchValueFrom(int v[], int n, int value)
{
    for (int i = 0; i < n; i++) {
        if (v[i] == value) {
            return i;
        }
    }
    return -1;
}

void replaceValuesFrom(int v[], int n)
{
    int aux[n];
    aux[0] = v[0];
    for (int i = 1; i < n; i++) {
        aux[i] = aux[i - 1] + v[i];
    }
    for (int i = 0; i < n; i++) {
        v[i] = aux[i];
    }
}

int main()
{
    int values[7];
    readValuesFrom(values, 7);

    printf("\n");

    printValuesFrom(values, 7);

    printf("\n");

    int valueToSeach = 0;
    printf("Insira o valor para busca: ");
    scanf("%d", &valueToSeach);
    int pos = searchValueFrom(values, 7, valueToSeach);
    if (pos != -1) {
        printf("\nO valor %d esta na posicao(indice): %d\n", valueToSeach, pos);
    } else {
        printf("\nO valor %d nao esta contido no array\n", valueToSeach);
    }

    printf("\n");

    replaceValuesFrom(values, 7);

    printf("O array apos a substiuicao:\n");
    printValuesFrom(values, 7);

    return 0;
}
