#include <stdio.h>
#include <string.h>
int main(void) {
  char texto[] = "foi muito facil";
  int i;
  for (i = 0; texto[i] != '\0'; i++) { // A declaração for (i = 0; texto [i]! = '\ 0'; i ++) é um loop que percorre toda a string até encontrar o caractere nulo '\ 0' ou o final da string.
    if (texto[i] == ' ') // Dentro do loop usamos um if para verificar se o caractere atual é um espaço em branco.
      break; // Se o caractere atual for um espaço em branco, usamos a instrução break para sair do loop.
  }
  i++; // Em seguida, incrementamos i em uma unidade para que a próxima instrução de loop comece a partir da próxima posição do caractere.
  for (; texto[i] != '\0'; i++) { // Depois disso, usamos outro loop for para imprimir todos os caracteres restantes da string. Observe que não usamos a instrução de inicialização no loop for, porque já inicializamos i na instrução de loop anterior. Observe também que não usamos a instrução de incremento no loop for, porque já incrementamos i na instrução de loop anterior. Observe também que o loop for não tem condição de término, porque queremos imprimir todos os caracteres restantes da string. Observe também que usamos uma instrução de loop vazia, porque não queremos fazer nada dentro do loop.
    printf("%c", texto[i]); 
  }
  return 0; // Saída: muito facil
}
