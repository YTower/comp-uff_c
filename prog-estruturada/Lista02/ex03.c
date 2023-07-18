#include <stdio.h>

int main(void)
{
	int i = 5, *p;
	p = &i;

	printf("%p %d %d \n", p, *p + 2, 3 * *p);

	return 0;
}

// Saida : 4094 7 15 
