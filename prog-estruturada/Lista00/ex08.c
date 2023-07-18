#include <stdio.h>
#include <math.h>

int total_de_notas(int valor)
{
	int n[] = {100, 50, 20, 10, 5, 2, 1};

	int qtd_notas = 0;

	for (int i = 0; i < 7; i++){
		qtd_notas += valor / n[i];
		valor = valor % n[i];
	}

	return qtd_notas;


		
}

int main(void)
{
	int v;
	


    printf("Informe o valor em dinheiro: ");
    scanf("%d", &v);

	int qtd_notas = total_de_notas(v);
	printf("%d\n", qtd_notas);
    
    return 0;
}