#include <stdio.h>
// Vai ser impresso: 10, 20, 30, 40, 50
int main() {
    
    
    int numbers[5] = {0, 0, 0, 0, 0};
    int *p;
    int n;
    p = numbers;
    *p = 10;
    p++;
    *p = 20;
    p = &numbers[2];
    *p = 30;
    p = numbers + 3;
    *p = 40;
    p = numbers;
    *(p + 4) = 50;

    for(n = 0; n < 5; n++) {
        printf("%d\n", numbers[n]);
    }
    
    
    
    
    
    return 0;
}