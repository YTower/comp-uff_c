// programa que recebe input de 3 inteiros retorna o maior o menor os pares e a média entre eles
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void print_even(int *e)
{	
	printf("Números pares: ");

	for (int i = 0; i < 3; i++) {
		if (e[i] % 2 == 0)
			printf("%d ", e[i]);
	}
	printf("\n");
}


void print_average(int *a)
{
	int media = 0;

	printf("Média entre os valores: ");

	for (int i = 0; i < 3; i++){
		media += a[i];
	}
	printf("%.2lf\n", (float)media / 3);
}


void print_smallest(int *s)
{
	int smallest = 2147483647;
	for (int i = 0; i < 3; i++){
		if (s[i] < smallest)
			smallest = s[i];
	}
	printf("Menor número: %d\n", smallest);
}


void print_greatest(int *g)
{
	int greatest = -2147483647;

	for (int i = 0; i < 3; i++){
		if (g[i] > greatest)
			greatest = g[i];
	}
	printf("Maior número: %d\n", greatest);
}


int main(void)
{
	int* x = malloc(3 * sizeof(int));

	if (x == NULL)
		return 1;

	
	printf("Informe 3 valores inteiros: ");
	scanf("%d %d %d", &x[0], &x[1], &x[2]);
	printf("\n");

	print_greatest(x);
	print_smallest(x);
	print_even(x);
	print_average(x);


	free(x);

	return 0;
}