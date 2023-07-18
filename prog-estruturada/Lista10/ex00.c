#include <stdlib.h>

struct elemento {
    float info;
    struct elemento *prox;
};

typedef struct elemento Elemento;

Elemento* filtra(Elemento *lst, float min, float max) {
    Elemento *atual = lst;
    Elemento *anterior = NULL;

    // Percorre a lista
    while (atual != NULL) {
        Elemento *prox = atual->prox;

        // Verifica se o valor está fora do intervalo
        if (atual->info < min || atual->info > max) {
            // Remove o elemento da lista
            if (anterior != NULL) {
                anterior->prox = prox;
            } else {
                lst = prox;
            }

            // Libera a memória do elemento removido
            free(atual);
        } else {
            // Atualiza o ponteiro anterior
            anterior = atual;
        }

        // Move para o próximo elemento
        atual = prox;
    }

    return lst;
}
