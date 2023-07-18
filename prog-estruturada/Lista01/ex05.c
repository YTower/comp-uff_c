#include <stdio.h>



void print_res(int x, int z)
{
	int k = 0;
	int c = 0;

	for (int i = x; k < z; i++){
		k += i;
		c++;
	}
	printf("%d\n", c);
}

int main(void)
{
	int x;
	int z;

	printf("Informe um valor para X e um falor para Z: ");
	scanf("%d %d", &x, &z);

	while (z <= x)
	{
		printf("Z deve ser maior do que X: ");
		scanf("%d", &z);
	}
		
	

	print_res(x, z);

	return 0;
}