#include <stdio.h>

int main(void){
    int n, m, soma = 0, dois = 1; scanf(" %d", &n); scanf(" %d", &m);
    int p1[n], p2[m], *p11 = p1, *p22 = p2;
    p11 += n-1; p22 += m-1;
    for(int i = 0; i < n; i++){
        scanf("%d", &p1[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &p2[i]);
    }
    for(int i = n; i > 0; i--){
        soma += (*p11) * dois;
        dois *= 2;
        p11 --;
    }
    dois = 1;
    for(int i = m; i > 0; i--){
        soma += (*p22) * dois;
        dois *= 2;
        p22 --;
    }
    printf("%d", soma);
    return 0;
}
