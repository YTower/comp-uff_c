//implementar uma função que calcula a área e a circunferência de um círculo
#include <stdio.h>
#include <stdlib.h>

void calc_circulo(float r, float* circunferencia, float* area)
{
const float PI = 3.141592;

*circunferencia = 2 * PI * r;
*area = PI * (r * r);

}

int main(void)
{	
	float r, circunferencia, area;

	printf("Informe o valor do raio da circunferência: ");
	scanf("%f", &r);

	calc_circulo(r, &circunferencia, &area);

	printf("A circunferência é: %.2f\n", circunferencia);
	printf("A área é: %.2f\n", area);

	return 0;
}
