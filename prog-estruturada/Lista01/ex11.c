//implementar a função exponencial
#include <stdio.h>
#include <math.h>

int main(void)
{	
	int base, expoente;

	printf("Informes os valores para a base e o expoente da potência: ");
	scanf("%d %d", &base, &expoente);

	int potencia = pow(base, expoente);

	printf("%d\n", potencia);

	return 0;
}