#include <stdio.h>

int main(void)
{
	int* pti;
	int veti[] = {10, 7, 2, 6, 3};
	pti = veti;

	printf("%d\n", *pti);
	printf("%d\n", *(pti + 2));
	printf("%d\n", pti[4]);
	printf("%d\n", pti[1]);
	printf("%d\n", *(veti + 3));

	return 0;
}

// A afirmação "d)" é falsa, pois o termo de índice 1 do vetor é o 7.

