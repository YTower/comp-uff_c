//resolver equações de segundo grau
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct coeficientes {
    int a;
    int b;
    int c;    

} coeficientes;

void print_res(int a, int b, int c)
{
    double delta = (b * b) - (4 * a * c);
    double x1 = (-(b) + sqrt(delta))/(2 * a);
    double x2 = (-(b) - sqrt(delta))/(2 * a);

    if (delta < 0)
        printf("Não há solução real");

    else if (delta >= 0)
        printf("O delta da equação é: %.2lf.\n", delta);
        if (delta == 0)    
            printf("A equação possui raíz única %.2lf", x1);
        if (delta > 0)
            printf("As raízes da equação são: {%.2lf, %.2lf}", x1, x2);

    
}

int main(void)
{
    coeficientes f;

    printf("Informe os valores de a, b e c da equação: ");
    scanf("%d %d %d", &f.a, &f.b, &f.c);
    printf("A sua expressão é: (%d)x² + (%d)x + (%d)\n", f.a, f.b, f.c);
    printf("O resultado da expressão é: ");
    print_res(f.a, f.b, f.c);
    printf("\n");

    return 0;
}