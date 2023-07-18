#include <stdio.h>
#include <math.h>


void print_multiply(float a, float b)
{
	printf("%.2f\n", a * b);
}

void print_subtract(float a, float b)
{
	printf("%2.f\n", a - b);
}

void print_add(float a, float b)
{
	printf("%.2f\n", a + b);
	
}

int main(void)
{
	float x;
	float y;
	char c;

	printf("Informe a operação que deseja fazer: ");
	scanf("%f %c %f", &x, &c, &y);
	printf("\n");
	printf("A operação que deseja fazer é: %.2f %c %.2f\n", x, c, y);

	printf("Resultado da operação: ");

	if (c == '+')
		print_add(x, y);
	else if (c == '*')
		print_multiply(x, y);
	else if (c == '-')
		print_subtract(x, y);

	return 0;
}