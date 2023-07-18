#include <stdio.h>
	
void main()
{	
	float vet[5] = {1.1,2.2,3.3,4.4,5.5};
	float *f;
	int i;
	
	f = vet;

	printf("contador/valor/valor/endereco/endereco\n");

	for(i = 0 ; i <= 4 ; i++){
		printf("\ni = %d",i);
		printf(" vet[%d] = %.1f",i, vet[i]);
		printf(" *(f + %d) = %.1f",i, *(f+i));
		printf(" &vet[%d] = %X",i, &vet[i]);
		printf(" (f + %d) = %X\n",i, f+i);
	}	
}

/*

O programa imprime uma tabela com as informações sobre os vetores:

1. valor de i
2. valor de vet[i]
2. valor do elemento que (f + i) aponta
4. endereço de vet[i]
5. valor do endereço de (f + i)


i = 0 vet[0] = 1.1 *(f + 0) = 1.1 &vet[0] = 1.10 (f + 0) = 1.10

i = 1 vet[1] = 2.2 *(f + 1) = 2.2 &vet[1] = 2.20 (f + 1) = 2.20

i = 2 vet[2] = 3.3 *(f + 2) = 3.3 &vet[2] = 3.30 (f + 2) = 3.30

i = 3 vet[3] = 4.4 *(f + 3) = 4.4 &vet[3] = 4.40 (f + 3) = 4.40

i = 4 vet[4] = 5.5 *(f + 4) = 5.5 &vet[4] = 5.50 (f + 4) = 5.50
*/