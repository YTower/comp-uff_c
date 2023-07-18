//verificar se um número dado pelo input é primo
#include <stdio.h>

void print_primo(int x)
{
	int divisores = 0;

	for (int i=1; i <= x; i++)
		if (x % i == 0)
			divisores += 1;
	if (divisores != 2)
		printf("O número não é primo.\n");
	else if (divisores == 2)
		printf("O número é primo.\n");

}

int main(void)
{
	int x;

	printf("Informe um valor: ");
	scanf("%d", &x);

	print_primo(x);

	return 0;


}