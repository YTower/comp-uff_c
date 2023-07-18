#include <stdlib.h>

struct elemento {
    int info; /* Valor inteiro armazenado */
    struct elemento *prox; /* Ponteiro para o próximo elemento */
};

typedef struct elemento Elemento;

Elemento* copia(Elemento* lst) {
    if (lst == NULL) {
        return NULL; // Retorna NULL se a lista original for vazia
    }

    Elemento* novaLista = malloc(sizeof(Elemento)); // Aloca memória para o primeiro elemento da nova lista
    novaLista->info = lst->info; // Copia o valor do primeiro elemento

    Elemento* atual = novaLista; // Ponteiro para o elemento atual na nova lista
    lst = lst->prox; // Avança para o próximo elemento na lista original

    while (lst != NULL) {
        atual->prox = malloc(sizeof(Elemento)); // Aloca memória para o próximo elemento na nova lista
        atual = atual->prox; // Avança para o próximo elemento na nova lista
        atual->info = lst->info; // Copia o valor do elemento da lista original
        lst = lst->prox; // Avança para o próximo elemento na lista original
    }

    atual->prox = NULL; // Define o próximo ponteiro do último elemento da nova lista como NULL

    return novaLista; // Retorna o ponteiro para a nova lista
}
