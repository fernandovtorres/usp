#include <stdio.h>

int main(void){
    int n, *p, **q;
    scanf("%d", &n);
    p = &n;
    q = &p;
    printf("Valor inicial da variavel: %d\n", n);
    printf("Valor do ponteiro antes do incremento: %d\n", *p);
    printf("Valor do ponteiro depois do incremento: %d\n", (*p)+=10);
    printf("Valor do ponteiro para ponteiro antes do incremento: %d\n", **q);
    printf("Valor do ponteiro para ponteiro depois da mudanca: %d\n", (**q)+=10);
    printf("Valor final da variavel: %d", n);
    
    return 0;
}
