#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FUNCIONARIOS 100

struct funcionario {
    char nome[81];      /* nome do funcionário */
    float valor_hora;   /* valor da hora de trabalho em Reais */
    int horas_mes;      /* horas trabalhadas em um mês */
};

typedef struct funcionario Funcionario;

void lerFuncionarios(Funcionario** vetor, int* tamanho, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    char nome[81];
    float valor_hora;
    int horas_mes;

    while (fscanf(arquivo, "%[^\n]%*c%f%d", nome, &valor_hora, &horas_mes) == 3) {
        if (*tamanho == MAX_FUNCIONARIOS) {
            printf("O vetor de funcionários está cheio.\n");
            break;
        }

        Funcionario* novoFuncionario = (Funcionario*)malloc(sizeof(Funcionario));
        strcpy(novoFuncionario->nome, nome);
        novoFuncionario->valor_hora = valor_hora;
        novoFuncionario->horas_mes = horas_mes;

        vetor[*tamanho] = novoFuncionario;
        (*tamanho)++;
    }

    fclose(arquivo);
}

void carrega(int n, Funcionario** vet, char* arquivo) {
    FILE* file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("ERRO\n");
        exit(1);
    }

    int i = 0;
    char nome[81];
    float valor_hora;
    int horas_mes;

    while (fscanf(file, "%[^\n]%*c%f%d", nome, &valor_hora, &horas_mes) == 3) {
        if (i >= n) {
            printf("O vetor de funcionários não possui espaço suficiente.\n");
            break;
        }

        Funcionario* novoFuncionario = (Funcionario*)malloc(sizeof(Funcionario));
        strcpy(novoFuncionario->nome, nome);
        novoFuncionario->valor_hora = valor_hora;
        novoFuncionario->horas_mes = horas_mes;

        vet[i] = novoFuncionario;
        i++;
    }

    fclose(file);
}


int main() {
    Funcionario* funcionarios[MAX_FUNCIONARIOS];
    int tamanho = 0;

    const char* nomeArquivo = "funcionarios.txt";
    lerFuncionarios(funcionarios, &tamanho, nomeArquivo);

    // Exemplo de uso: imprimir os funcionários lidos
    for (int i = 0; i < tamanho; i++) {
        printf("Funcionário %d:\n", i + 1);
        printf("Nome: %s\n", funcionarios[i]->nome);
        printf("Valor da hora: %.2f\n", funcionarios[i]->valor_hora);
        printf("Horas trabalhadas: %d\n", funcionarios[i]->horas_mes);
        printf("\n");
    }

    // Libera a memória alocada pelos funcionários
    for (int i = 0; i < tamanho; i++) {
        free(funcionarios[i]);
    }

    return 0;
}
