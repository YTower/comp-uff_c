//programa que recebe um input de horas trabalhadas e valor por hora e retorna o custo semanal do trabalhador + adicionais de carga horária
#include <stdio.h>
#include <stdlib.h>


typedef struct trabalhador{

	int time;
	float value;

} Worker;


void print_res(Worker x)
{
	if (x.time <= 40)
		printf("O salário semanal deste funcionário é %.2f\n", (x.time * x.value));
	else if (x.time > 40 && x.time <= 60)
		printf("O salário semanal deste funcionário é %.2f\n", (x.time * x.value) + (((x.time - 40) * x.value) * 1.5));
	else if (x.time > 60)
		printf("O salário semanal deste funcionário é %.2f\n", (x.time * x.value) + (((x.time - 40) * x.value) * 2));
}


int main(void)
{
	Worker x;

	printf("Informe a carga horária semanal e o valor por hora do trabalhador: ");
	scanf("%d %f", &x.time, &x.value);

	print_res(x);

	return 0;
}
