#include <stdio.h>

int divs(int n, int* max, int* min)
{
	int divisores = 0;

	for (int i = 1; i <= n; i++) {
		if (n % i == 0)
			divisores++;
	}
	
	if (divisores == 2)
		printf("é primo\n");

	else if (divisores != 2){

		for (int j = 1; j < *min; j++) {
			if (n % j == 0 && j != 1)
				*min = j;
		}
		for (int k = 1; k > *max; k++) {
			if (n % k == 0 && k != n)
				*max = k;
		}
		printf("não é primo\nMenor divisor de %d: %d\nMaior divisor de %d: %d \n", n, *min, n, *max);
		return 1;
	}

	return 0;
}
int main(void)
{
	int num;
	int min, max;

	min = -2147483647;
	max = 2147483647;
	
	printf("Informe um número: ");
	scanf("%d", &num);
	
	int res = divs(num, &min, &max);

	printf("%d\n", res);

	return 0;
}