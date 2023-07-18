#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Livro {
  int ano;
  char titulo[100];
  char autor[100];
  int nVolume; // Número de exemplares de um dado livro.
  float preco;
} Livro;

typedef struct Biblioteca {
  Livro **V;   // Armazena a informação de n livros !!
  int nLivros; // Número de livros existentes na biblioteca.
} Biblioteca;

Livro *fillLivro() {
  Livro *novoLivro = (Livro *)malloc(sizeof(Livro));

  printf("Digite o ano do livro: ");
  scanf("%d", &novoLivro->ano);
  printf("Digite o título do livro: ");
  scanf(" %[^\n]s", novoLivro->titulo);
  printf("Digite o autor do livro: ");
  scanf(" %[^\n]s", novoLivro->autor);
  printf("Digite o número de exemplares do livro: ");
  scanf("%d", &novoLivro->nVolume);
  printf("Digite o preço do livro: ");
  scanf("%f", &novoLivro->preco);

  return novoLivro;
}

Biblioteca *fillBiblioteca(int numLivros) {
  Biblioteca *novaBiblioteca = (Biblioteca *)malloc(sizeof(Biblioteca));
  novaBiblioteca->V = (Livro **)malloc(numLivros * sizeof(Livro *));
  novaBiblioteca->nLivros = numLivros;

  for (int i = 0; i < numLivros; i++) {
    printf("\nPreenchendo informações do livro %d:\n", i + 1);
    novaBiblioteca->V[i] = fillLivro();
  }

  return novaBiblioteca;
}

void valorBiblioteca(Biblioteca *b1, int numLivros) {
  float valorTotal = 0.0;

  for (int i = 0; i < numLivros; i++) {
    valorTotal += b1->V[i]->nVolume * b1->V[i]->preco;
  }

  printf("\nO valor total da biblioteca é: R$ %.2f\n", valorTotal);
}

Livro *maiorBiblioteca(Biblioteca *b1, int numLivros) {
  Livro *maiorLivro = b1->V[0];

  for (int i = 1; i < numLivros; i++) {
    if (b1->V[i]->nVolume > maiorLivro->nVolume) {
      maiorLivro = b1->V[i];
    }
  }

  return maiorLivro;
}

int main() {
  int numLivros;
  printf("Digite o número de livros da biblioteca: ");
  scanf("%d", &numLivros);

  Biblioteca *biblioteca = fillBiblioteca(numLivros);

  valorBiblioteca(biblioteca, numLivros);

  Livro *livroMaiorBiblioteca = maiorBiblioteca(biblioteca, numLivros);
  printf("\nO livro com maior número de exemplares é:\n");
  printf("Título: %s\n", livroMaiorBiblioteca->titulo);
  printf("Autor: %s\n", livroMaiorBiblioteca->autor);
  printf("Número de exemplares: %d\n", livroMaiorBiblioteca->nVolume);

  // Liberar memória
  for (int i = 0; i < numLivros; i++) {
    free(biblioteca->V[i]);
  }
  free(biblioteca->V);
  free(biblioteca);

  return 0;
}
