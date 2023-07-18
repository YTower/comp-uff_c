//gera um número aleatório e recebe palpites pelo input e informa se o palpite foi acertivo ou não
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));

	char letra = 'a' + rand() % 26;
	char palpite;
	int tentativas = 0;

	printf("Uma letra entre a e z foi sorteada. Tente adivinhar: ");
	scanf("%c", &palpite);
	tentativas++;
	
	while (palpite != letra) {

		tentativas++;

        if (palpite > letra)
            printf("Não foi dessa vez... A letra sorteada vem antes!\n");

        else if (palpite < letra)
            printf("A letra sorteada está depois dessa!\n");

        scanf(" %c", &palpite);
	}


	printf("Você acertou! Seu número de tentativas foi: %d\n", tentativas);
	return 0;
}