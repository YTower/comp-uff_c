#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));

	int numero = 0 + rand() % 101;
	int palpite;
	int tentativas = 0;

	printf("Um número foi sorteado! Tente acertar: ");
	scanf("%d", &palpite);
	tentativas++;

	while (palpite != numero) {

		tentativas++;

		if (palpite < numero)
			printf("O número sorteado é maior! Tente outra vez: ");
		else if (palpite > numero)
			printf("O número sorteado é menor! Tente outra vez: ");
		
		scanf("%d", &palpite);
	}
	printf("Você acertou! Seu número de tentativas foi: %d\n", tentativas);
	return 0;
}