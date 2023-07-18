// definir o tipo de variável para obter os outputs esperados
#include <stdio.h>

void script_c(float a, float b, float c)
{
	a = 3;
	b = a/2;
	c = b + 3.1;

	printf("%.1f\n", c);
}

void script_b(float a, int b, float c)
{
	a = 3;
	b = a/2;
	c = b + 3.1;

	printf("%.1lf\n", c);
}

void script_a(int a, int b, int c)
{
	a = 3;
	b = a/2;
	c = b + 3.1;

	printf("%d\n", c);
}

int main(void)
{
	int a;
	int b;
	int c;
	
	script_a(a, b, c);
	script_b(a, b, c);
	script_c(a, b, c);

	return 0;
}