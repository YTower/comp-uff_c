#include <stdio.h>
#include <math.h>

#define MAX 100

typedef struct {
    int idade;
    float altura;
    char sexo;
} Pessoa;

int main() {
    Pessoa pessoas[MAX];
    int n_pessoas;
    int n_mulheres = 0;
    int n_homens = 0;
    float soma_altura = 0;
    float media_altura;
    float variancia_altura = 0;
    
    printf("Quantas pessoas serão registradas? (max: %d): ", MAX);
    scanf("%d", &n_pessoas);
    
    for (int i = 0; i < n_pessoas; i++) {
        printf("\nPessoa %d:\n", i+1);
        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);
        printf("Altura: ");
        scanf("%f", &pessoas[i].altura);
        printf("Sexo (M/F): ");
        scanf(" %c", &pessoas[i].sexo);
        

        if (pessoas[i].sexo == 'F' && pessoas[i].idade >= 20 && pessoas[i].idade <= 35) {
            n_mulheres++;
        }
        if (pessoas[i].sexo == 'M' && pessoas[i].altura > 1.80) {
            n_homens++;
        }
        
        soma_altura += pessoas[i].altura;
    }
    
    media_altura = soma_altura / n_pessoas;
    
    for (int i = 0; i < n_pessoas; i++) {
        variancia_altura += pow(pessoas[i].altura - media_altura, 2);
    }
    variancia_altura /= n_pessoas;
    
    printf("Mulheres entre 20 e 35 anos: %d\n", n_mulheres);
    printf("Homens com altura maior que 1,80m: %d\n", n_homens);
    printf("Variância da altura: %.2f\n", variancia_altura);
    
    return 0;
}