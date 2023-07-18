#include <stdio.h>
#include <stdlib.h>

float *acima_da_media(int n, float *vet, int *tam) {
    float media, soma;
    int tamanho_novo_vetor;
    soma = 0;
    tamanho_novo_vetor = 0;
    for(int i = 0; i < n; i++) {
        soma += vet[i];
    }

    media = soma / (n);
    
    for(int i = 0; i < n; i++) {
        if(vet[i] > media) {
            
            tamanho_novo_vetor += 1;
            
        }
    }
    
    *tam = tamanho_novo_vetor;

    float *v;
    v = (float *) malloc(tamanho_novo_vetor * sizeof(float));
    if(v == NULL) {
        return NULL;
    }
    
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(vet[i] > media) {
            v[j] = vet[i];
            j++;
        }
    }
    
    return v;
}



int main() {
    int tam = 0;
   
    float vet[] = {5.5, 3.2, 2.5, 9.4, 7.5, 4.1, 5.4, 8.0, 6.9};
    float *v = acima_da_media(9, vet, &tam);
    
    for(int i = 0; i < tam; i++) {
        printf("%.2f\n", v[i]);
    }


    free(v);
    return 0;
}
