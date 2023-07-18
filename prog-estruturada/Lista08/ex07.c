#include <stdio.h>

struct data {
  int dd, mm, aa; /* Dia, mes e ano */
};
typedef struct data Data;
struct compromisso {
  char descricao[81]; /* Descricao do compromisso */
  Data dta;           /* Data do compromisso */
};
typedef struct compromisso Compromisso;

int main(void) {
  printf("Hello World\n");
  return 0;
}

Compromisso *busca(int n, Compromisso **vet, int d, int m, int a) {
  int inicio = 0;
  int fim = n - 1;

  while (inicio <= fim) {
    int meio = (inicio + fim) / 2;

    if (vet[meio]->dta.aa == a && vet[meio]->dta.mm == m &&
        vet[meio]->dta.dd == d) {
      return vet[meio];
    } else if (vet[meio]->dta.aa > a ||
               (vet[meio]->dta.aa == a && vet[meio]->dta.mm > m) ||
               (vet[meio]->dta.aa == a && vet[meio]->dta.mm == m &&
                vet[meio]->dta.dd > d)) {
      fim = meio - 1;
    } else {
      inicio = meio + 1;
    }
  }

  return NULL;
}
