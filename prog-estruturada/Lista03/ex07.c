#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int size = 1;
    do {
        size = rand() % 30;
    } while (size % 2 != 0);

    int array[size];
    int num = 0;
    int *pInicio, *pFinal;

    for (int i = 0; i < size; i++) {
        num = rand() % 99 + 1;
        array[i] = num;
    }

    printf("O array gerado foi: \n\n");

    for (int i = 0; i < size; i++) {

        if (i == 0) {
            printf("[%d, ", array[i]);
        } else if (i == size - 1) {
            printf("%d]", array[i]);
        } else {
            printf("%d, ", array[i]);
        }
    }

    pInicio = array;
    pFinal = &array[size - 1];

    while (pInicio < pFinal) {
        printf("\n\n\nPonteiro inicio: %d", *pInicio);
        printf("\nPonteiro final: %d", *pFinal);
        pInicio++;
        pFinal--;
    }
}
