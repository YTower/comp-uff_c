#include <stdio.h>

void print_numbers(void)
{
	for (int i = 1000; i <= 9999; i++) {

		int first_half = i / 100;
		int second_half = i % 100;
		int sum = first_half + second_half;

		if (sum * sum == i)
			printf("%d ", i);
		
	}
	printf("\n");
}

int main(void)
{
	print_numbers();

	return 0;
}