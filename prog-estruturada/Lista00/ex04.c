// receber input de 3 notas e avaliar se o aluno está aprovado, reprovado ou apto para a VS
#include <stdio.h>
#include <math.h>


void average(float a, float b, float c)
{
	float media = (a + b + c)/3;

	if (media < 4)
		printf("Sua média é: %.2f\nVocê está reprovado.", media);
	else if (media < 6 && media > 4)
		printf("Sua média é: %.2f\nVocê está apto para a VS.", media);
	else if (media >= 6)
		printf("Sua média é: %.2f\nVocê está aprovado.", media);
	printf("\n");

}
int main(void)
{
	float p1;
	float p2;
	float p3;

	printf("Informe as notas P1, P2 e P3: ");
	scanf("%f %f %f", &p1, &p2, &p3);

	if (p1 < 0 || p2 < 0 || p3 < 0 || p1 > 10 || p2 > 10 || p3 > 10)
		return printf("Valor inválido.\n");
	

	average(p1, p2, p3);

	return 0;
}