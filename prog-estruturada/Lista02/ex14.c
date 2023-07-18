#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

enum opinions
{
	OTIMO = 0,
	BOM = 1,
	REGULAR = 2,
	RUIM = 3,
	PESSIMO = 4,
};

typedef struct s_opinion
{
	int total;
	int total_age;
	int max_age;
	int min_age;
} t_opinion;

typedef struct s_spec
{
	int age;
	int opinion;
} t_spec;

void set_opinions(t_spec *spec, int n, t_opinion *opinion)
{
	for (int i = 0; i < n; i++) {
		opinion[spec[i].opinion].total++;
		opinion[spec[i].opinion].total_age += spec[i].age;
		if (spec[i].age > opinion[spec[i].opinion].max_age)
			opinion[spec[i].opinion].max_age = spec[i].age;
		if (opinion[spec[i].opinion].min_age == 0 || spec[i].age < opinion[spec[i].opinion].min_age)
			opinion[spec[i].opinion].min_age = spec[i].age;
	}
}

void print_opinions(t_opinion *opinion)
{
	char str[5][8] = {"Ótimo", "Bom", "Regular", "Ruim", "Péssimo"};

	for (int i = 0; i < 5; i++) {
		printf("%s\nTotal: %d\nIdade total: %d\nMaior idade: %d\nMenor idade: %d\n\n",
			str[i], opinion[i].total, opinion[i].total_age, opinion[i].max_age, opinion[i].min_age);
	}
}

int main(void)
{
	int n;

	printf("Número de espectadores à responder o questionário: ");
	scanf("%d", &n);

	t_spec *spec = malloc(sizeof(t_spec) * n);
	if (spec == NULL)
		return 1;

	/* generate random specs */
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++) {
		printf("Espectador %d de %d:\n", i + 1, n);
		spec[i].age = rand() % 70 + 10;
		printf("Idade: %d\n", spec[i].age);
		spec[i].opinion = rand() % 5;
		printf("Opinião: %d\n", spec[i].opinion);
	}

	printf("\n==================\n\n");

	t_opinion opinion[5] = {0};

	/* register opinions information */
	set_opinions(spec, n, opinion);
	free(spec);

	/* easy way to check if everything is correct, not needed in the exercice */
	print_opinions(opinion);

	printf("a) %d\n", opinion[OTIMO].total);
	if (opinion[BOM].total > opinion[REGULAR].total)
		printf("b) %.2f%%\n", (opinion[BOM].total - opinion[REGULAR].total) / (float)opinion[REGULAR].total * 100);
	else
		printf("b) %.2f%%\n", (opinion[REGULAR].total - opinion[BOM].total) / (float)opinion[BOM].total * 100);
	printf("c) %.2f\n", (float)opinion[RUIM].total_age / opinion[RUIM].total);
	printf("d) %2.f%% %d\n", ((float)opinion[PESSIMO].total / n) * 100, opinion[PESSIMO].max_age);
	printf("e) %d\n", abs(opinion[OTIMO].max_age - opinion[PESSIMO].max_age));

	return 0;
}