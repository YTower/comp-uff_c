//função para arredondar valores em float
#include <stdio.h>
#include <math.h>

void print_round(float a)
{
    float k = a - (int) a;

    if (k < 0.5)
        printf("%d\n", (int) a);
    else if (k >= 0.5)
        printf("%d\n", (int) a + 1);
        
}



int main(void)
{
    float x;
    char c;

    printf("Informe um valor float: ");
    scanf("%f", &x);

    print_round(x);

    return 0;
}