// receber um valor em segundos e converter para horas-minutos-segundos
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int* converte(int t)
{
    int* f = malloc(3 * sizeof(int));

    if (f == NULL)
        return NULL;

    f[0] = t % 60;
    f[1] = (t / 60) % 60;
    f[2] = (t / 60) / 60;
    
    return f;
}

int main(void)
{   
    int x;
    int* p;

    printf("Informe o tempo em segundos: ");
    scanf("%d", &x);

    p = converte(x);
    if (p == NULL)
        return 1;

    printf("%02dh%02dm%02ds\n", p[2], p[1], p[0]);

    free(p);

    return 0;
}