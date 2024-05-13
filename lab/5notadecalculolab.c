#include <stdio.h>
#include <math.h>

int main(){   
    float n1, n2, e1, e2, e3, e4;
    scanf(" %f %f %f %f %f %f", &n1, &n2, &e1, &e2, &e3, &e4);
    if (e1 == e2 && e2 == e3 && e3 == e4 && e4 == 0){
        printf("Reprovado\n");
    }else if ((n1 + n2 + ((e1 + e2 + e3 + e4)/4))/3 < 3){
        printf("Reprovado\n");
    } else if ((n1 + n2 + ((e1 + e2 + e3 + e4)/4))/3 < 5){
        printf("Recuperacao\n");
    } else {
        printf("Aprovado\n");
    }
    return 0;
}
