#include <stdio.h>

int main() {
    int a, b, c, d;
    float e, f, g, h;
    char v[10];
    int x;

    int *p = &a;

    printf("Endereço apontado pelo ponteiro: %p\n", p);

    if (p == (int *)&a) printf("O endereço apontado coincide com o endereço de 'a'\n");
    if (p == (int *)&b) printf("O endereço apontado coincide com o endereço de 'b'\n");
    if (p == (int *)&c) printf("O endereço apontado coincide com o endereço de 'c'\n");
    if (p == (int *)&d) printf("O endereço apontado coincide com o endereço de 'd'\n");
    if (p == (int *)&e) printf("O endereço apontado coincide com o endereço de 'e'\n");
    if (p == (int *)&f) printf("O endereço apontado coincide com o endereço de 'f'\n");
    if (p == (int *)&g) printf("O endereço apontado coincide com o endereço de 'g'\n");
    if (p == (int *)&h) printf("O endereço apontado coincide com o endereço de 'h'\n");
    if (p == (int *)&v) printf("O endereço apontado coincide com o endereço de 'v'\n");
    if (p == (int *)&x) printf("O endereço apontado coincide com o endereço de 'x'\n");

    return 0;
}