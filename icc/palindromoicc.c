#include <stdio.h>

int main(void){
    int n, d=0; scanf(" %d", &n);
    char c[n]; int alfa[26];
    for (int i = 0; i < 26; i++){
        alfa[i] = 0;
    }
    for (int i = 0; i < n; i++){
        scanf(" %c", &c[i]);
        alfa[c[i]-97]++;
    }
    if(!(n%2)){
       for (int i = 0; i < 26; i++){
            if ((alfa[i] % 2)) {
                printf("Nao");
                return 0;
            }
        } 
        printf("Sim");
    } else {
        for (int i = 0; i < 26; i++){
            if ((alfa[i] % 2)) {
                d++;
            }
        }
        if (d == 1){
            printf("Sim");
        }
        else {
            printf("Nao");
        }
    }
    return 0;
}
