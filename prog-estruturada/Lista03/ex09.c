#include <stdio.h>

int otimo_calculator(int n, int* opinioes);
int percent(int n, int* opinioes);
int media_ruim(int n, int* idades, int* opinioes);
int percent_maior_pessimo(int n, int* idades, int* opinioes, int* maior_idade_pessimo);
int dif_maior_idade(int n, int* idades, int* opinioes);

int main()
{
    int n = 1;
    int x = 0;
    int maior_idade_pessimo = 0;

    printf("#Esse e o mesmo exercicio que o exercicio 14 da lista 3# \n\nQuantas pessoas farao parte da pesquisa? ");
    scanf("%d", &n);
    printf("\n");

    int idades[n];
    int opinioes[n];

    for (int i = 0; i < n; ++i) {
        printf("Insira a idade da pessoa na posicao %d: ", i + 1);
        scanf("%d", &idades[i]);

        printf("Insira a avaliacao da pessoa na posicao %d (sendo 0 para pessimo, 1 para ruim, 2 para regular, 3 para bom e 4 para otimo): ", i + 1);
        scanf("%d", &opinioes[i]);
    }

    int cont_otimo = otimo_calculator(n, opinioes);
    int diferenca_percentual = percent(n, opinioes);
    int porcentagem_pessimo = percent_maior_pessimo(n, idades, opinioes, &maior_idade_pessimo);
    float media = media_ruim(n, idades, opinioes);
    int diferenca = dif_maior_idade(n, idades, opinioes);

    printf("\nA quantidade de respostas otimo foi: %d", cont_otimo);
    printf("\n\nA diferenca percentual entre respostas bom e regular foi: %d", diferenca_percentual);
    printf("\n\nA media de idade das pessoas que responderam ruim foi: %.1f", media);
    printf("\n\nA porcentagem de respostas pessimo foi: %d \n\nA maior idade que utilizou esta opcao foi: %d", porcentagem_pessimo, maior_idade_pessimo);
    printf("\n\nA diferenca de idade entre a maior idade que respondeu otimo e a maior idade que respondeu ruim foi: %d\n\n\n", diferenca);

    return 0;
}

int otimo_calculator(int n, int* opinioes)
{
    int cont_otimo = 0;
    for (int i = 0; i < n; ++i) {
        if (opinioes[i] == 4) {
            cont_otimo++;
        }
    }
    return cont_otimo;
}

int percent(int n, int* opinioes)
{
    int cont_bom = 0;
    int cont_regular = 0;

    for (int i = 0; i < n; ++i) {
        if (opinioes[i] == 2) {
            cont_regular++;
        }
        if (opinioes[i] == 3) {
            cont_bom++;
        }
    }

    int porcentagem_regular = cont_regular * 100 / n;
    int porcentagem_bom = cont_bom * 100 / n;

    int diferenca_percentual = porcentagem_regular - porcentagem_bom;

    if (diferenca_percentual < 0) {
        diferenca_percentual = diferenca_percentual * (-1);
    }

    return diferenca_percentual;
}

int media_ruim(int n, int* idades, int* opinioes)
{
    int sum_idades = 0;
    float cont = 0;
    int media = 0;
    for (int i = 0; i < n; ++i) {
        if (opinioes[i] == 1) {
            cont++;
            sum_idades = sum_idades + idades[i];
        }
    }
    if (cont == 0) {
        return media;
    } else {
        int media = sum_idades / cont;
        return media;
    }
}

int percent_maior_pessimo(int n, int* idades, int* opinioes, int* maior_idade_pessimo)
{
    int cont_pessimo = 0;
    for (int i = 0; i < n; ++i) {
        if (opinioes[i] == 0) {
            cont_pessimo++;
            if (idades[i] > *maior_idade_pessimo) {
                *maior_idade_pessimo = idades[i];
            }
        }
    }

    int porcentagem_pessimo = cont_pessimo * 100 / n;

    return porcentagem_pessimo;
}

int dif_maior_idade(int n, int* idades, int* opinioes)
{
    int maior_idade_ruim = 0;
    int maior_idade_otimo = 0;

    for (int i = 0; i < n; ++i) {
        if (opinioes[i] == 1) {
            if (opinioes[i] > maior_idade_ruim) {
                maior_idade_ruim = idades[i];
            }
        }
        if (opinioes[i] == 4) {
            if (opinioes[i] > maior_idade_otimo) {
                maior_idade_otimo = idades[i];
            }
        }
    }
    int dif = maior_idade_otimo - maior_idade_ruim;

    if (dif < 0) {
        dif = dif * (-1);
    }
    return dif;
}
