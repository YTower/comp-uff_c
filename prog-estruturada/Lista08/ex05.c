#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa {
  int codigo;
  char nome[81];
};
typedef struct pessoa Pessoa;

Pessoa* busca(int n, Pessoa** vet, int codigo) {
  int inicio = 0;
  int fim = n - 1;

  while (inicio <= fim) {
    int meio = (inicio + fim) / 2;

    if(vet[meio]->codigo == codigo) {
      return vet[meio];
    }
    else if (vet[meio]->codigo < codigo) {
      inicio = meio + 1;
    }
    else {
      fim = meio - 1;
    }
  }

  return NULL;
}

int main() {
    Pessoa* pessoas[5];

    Pessoa pessoa1;
    pessoa1.codigo = 1001;
    strcpy(pessoa1.nome, "João");
    pessoas[0] = &pessoa1;

    Pessoa pessoa2;
    pessoa2.codigo = 2002;
    strcpy(pessoa2.nome, "Thales");
    pessoas[1] = &pessoa2;

    Pessoa pessoa3;
    pessoa3.codigo = 3003;
    strcpy(pessoa3.nome, "Vinicius");
    pessoas[2] = &pessoa3;

    Pessoa pessoa4;
    pessoa4.codigo = 4004;
    strcpy(pessoa4.nome, "Yuri");
    pessoas[3] = &pessoa4;

    Pessoa pessoa5;
    pessoa5.codigo = 5005;
    strcpy(pessoa5.nome, "Julia");
    pessoas[4] = &pessoa5;

    int codigo_busca;
    printf("Digite o código da pessoa a ser buscada: ");
    scanf("%d", &codigo_busca);

    Pessoa* pessoa_encontrada = busca(5, pessoas, codigo_busca);

    if (pessoa_encontrada != NULL) {
        printf("Pessoa encontrada: %s\n", pessoa_encontrada->nome);
    } else {
        printf("Pessoa não encontrada.\n");
    }

    return 0;
}
