#include <stdio.h>
#include <math.h>

int main(void){   
    int n1, n2, n3, n4;
    scanf(" %d %d %d %d", &n1, &n2, &n3, &n4);
    if ((n1 == 0 || n2 == 0 || n3 == 0 || n4 == 0) || (n1 == n2 && n2 != n3) || (n2 == n3 && n3 != n4)){
        printf("nenhum!\n");
    } else if (n1 == n2 && n2 == n3 && n3 == n4){
        printf("quadrado!\n");
    } else {
        printf("retangulo!");
    }
    return 0;
}
