#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar informações do aluno
typedef struct Aluno {
    int matricula;
    char nome[50];
    struct Aluno* proximo;
} Aluno;

// Função para imprimir a lista de alunos
void imprimirLista(Aluno* lista) {
    Aluno* atual = lista;
    while (atual != NULL) {
        printf("Matricula: %d, Nome: %s\n", atual->matricula, atual->nome);
        atual = atual->proximo;
    }
}

// Função para excluir um aluno da lista
Aluno* excluirAluno(Aluno* lista, int matricula) {
    Aluno* anterior = NULL;
    Aluno* atual = lista;

    // Encontrar o aluno na lista
    while (atual != NULL && atual->matricula != matricula) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Caso o aluno seja o primeiro da lista
    if (atual == lista) {
        lista = lista->proximo;
    }
    // Caso o aluno seja encontrado no meio ou no final da lista
    else if (atual != NULL) {
        anterior->proximo = atual->proximo;
    }

    // Liberar memória do aluno removido
    free(atual);

    return lista;
}

// Função para incluir um novo aluno na lista
Aluno* incluirAluno(Aluno* lista, int matricula, const char* nome) {
    // Criar um novo aluno
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    novoAluno->matricula = matricula;
    strcpy(novoAluno->nome, nome);
    novoAluno->proximo = NULL;

    // Caso a lista esteja vazia
    if (lista == NULL) {
        lista = novoAluno;
    }
    // Caso contrário, encontrar o último aluno da lista
    else {
        Aluno* atual = lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoAluno;
    }

    return lista;
}

// Função para alterar o nome de um aluno na lista
void alterarNome(Aluno* lista, int matricula, const char* novoNome) {
    Aluno* atual = lista;

    // Encontrar o aluno na lista
    while (atual != NULL && atual->matricula != matricula) {
        atual = atual->proximo;
    }

    // Se o aluno for encontrado, alterar o nome
    if (atual != NULL) {
        strcpy(atual->nome, novoNome);
    }
}

// Função para liberar a memória alocada pela lista
void liberarLista(Aluno* lista) {
    Aluno* atual = lista;
    while (atual != NULL) {
        Aluno* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main() {
    Aluno* lista = NULL;

    // Carregar a lista do arquivo (exemplo)
    lista = incluirAluno(lista, 1, "João");

