/*

Seja o seguinte trecho de programa:

int i = 3;
int j = 5;

int *p;
int *q;

p = &i;
q = &j;

Qual é o valor das seguintes expressões?

a) p == &i;

b) *p - *q 

c) **&p 

d) 3* - *p/(*q)+7 */

/* ===========RESPOSTAS================= */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 3;
	int j = 5;

	int *p;
	int *q;

	p = &i;
	q = &j;
	
	printf("a) %d\n", p == &i);
	printf("b) %d\n", *p - *q );
	printf("c) %d\n", **&p );
	printf("d) %d\n", 3 * - *p / (*q) + 7);

	return 0;

}