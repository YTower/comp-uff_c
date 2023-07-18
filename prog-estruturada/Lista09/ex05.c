#include <stdio.h>

int main() {
  int i;

  for (i = 1; i <= 10; i++) {
    char nome_arquivo[100];
    sprintf(nome_arquivo, "teste%02d.txt", i);
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
      printf("Erro ao criar o arquivo %s.\n", nome_arquivo);
      return 1;
    }

    fprintf(arquivo, "Texto do arquivo %02d\n", i);

    fclose(arquivo); 
  }

  printf("Os arquivos foram gerados com sucesso.\n");

  return 0;
}
