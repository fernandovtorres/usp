#include <stdio.h>

int main(void){
    int n[1500000], a, b;
    for (int i = 0; i < 1500000; i++) {
        n[i] = 0;
    }
    n[1] = 1;
    for (int i = 2; i <= 1500000; i++){
        if(!n[i]) {
            for (int j = 2; j*i <= 1500000; j++){
                n[j*i] = 1;
            }
        }
    }
    scanf(" %d", &a);
    for (int i = 0; i < a; i++){
        scanf(" %d", &b);
        if (!n[b]) {
            printf("Sim\n");
        } else {
            printf("Nao\n");
        }
    }
    return 0;
}
