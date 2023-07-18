// implementar a função MDS
#include <stdio.h>
#include <stdlib.h>


void print_MDC(int* numbers)
{

	int mdc = 0;
	int greatest = -2147483647; //apenas um número definitivamente menor que x e y

	for (int k = 0; k < 2; k++)
		if (numbers[k] > greatest)
			greatest = numbers[k];

	//printf("greatest: %d\n", greatest);

	for (int i = 1; i <= greatest; i++) {
		if (numbers[0] % i == 0 && numbers[1] % i ==0)
			mdc = i;
	}
	printf("O MDC entre %d e %d é: %d\n", numbers[0], numbers[1], mdc);
}


int main(void)
{
	int* numbers = malloc(2 * sizeof(int));
	
	if (numbers == NULL)
		return 1;	

	printf("Informe dois valores para ser calculado o MDC: ");
	scanf("%d %d", &numbers[0], &numbers[1]);

	print_MDC(numbers);

	return 0;

}