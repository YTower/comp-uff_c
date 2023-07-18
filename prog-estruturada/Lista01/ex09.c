//implementar  a função que inverte um número recebido pelo input
#include <stdio.h>

void INVERTE(unsigned int k)
{
	int inverted = 0;


	for (int i = 1; i < k ; i *= 10) {
		inverted = (k / i);
		printf("%d", inverted % 10);

	}
	printf("\n");
	
}

int main(void)
{
	unsigned int k;

	printf("Informe um valor: ");
	scanf("%d", &k);

	INVERTE(k);

	return 0;

}