//imprimir os n primeiros termos da sequência fibonacci, n dado pelo input
#include <stdio.h>

void fibonacci(int k)
{
	int t1 = 1;
	int t2 = 1;
	

	printf("%d %d ", t1, t2);

	for (int i = 3; i <= k; i++){
		int tn = t1 + t2;
		printf("%d ", tn);
		t1 = t2;
		t2 = tn;
	}
	printf("\n");
}

int main(void)
{	
	int k;

	printf("Informe quantos termos da sequência devem ser retornados: ");
	scanf("%d", &k);

	fibonacci(k);


	return 0;
}