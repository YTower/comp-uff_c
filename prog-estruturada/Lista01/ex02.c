//calcular os n primeiros naturais ímpares, dado n pelo input
#include <stdio.h>


void print_sum_N(int n)
{
	int sum = 0;
	int odd_n = 1;

	for (int i = 1; odd_n <= n; i++){
		if (i % 2 != 0){
			odd_n +=1;
			sum += i;
		}
			
	}
	printf("\nA soma dos %d primeiros naturais ímpares é: %d\n\n", n, sum);
			

}

int main(void)
{
	int x;

	printf("Informe quantos números ímpares devem ser somados: ");
	scanf("%d", &x);

	print_sum_N(x);

	return 0;
}