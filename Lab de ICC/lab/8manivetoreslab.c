#include <stdio.h>
#include <ctype.h>
int main() {
    int fibo[17], legal[100], a = 0, temp;
    char z;
    fibo[1] = fibo[0] = 1;
    for (int i = 2; i < 17; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    while(1) {
        int x; scanf(" %d", &x);
        if (x != 1) {
            legal[a] = x;
        } else {
            legal[a] = x;
            break;
        }
        a++; 
    }
    scanf(" %c", &z);
    if (z == 'a') {
       printf("vetor ordenado:");
       for(int i = 0; i < 100; i++){
           if (legal[i] != 1){
               for (int j = 0; j < 100; j++){
                   if (legal[j] != 1){
                       if(legal[i] < legal[j]){
                           temp = legal[i];
                           legal[i] = legal[j];
                           legal[j] = temp;
                       }
                   } else {
                       break;
                   }
               }
           }else {
               break;
           }
       }
       for (int i = 0; i < 100; i++){
           if (legal[i] != 1) {
               printf("%d ", legal[i]);
           } else {
               break;
           }
       }
    } else if (z == 'b'){
        printf("Numeros de Fibonacci:");
        for(int i = 0; i < 100; i++){
            if (legal[i] != 0) {
                for(int j = 2; j < 17; j++){
                    if (legal[i] == fibo[j]){
                        printf("%d ", fibo[j]);
                    }
                }
            } else {
                break;
            }
        }
    } else if (z == 'c') {
        printf("Vetor maiusculo:");
        for (int i = 0; i < 100; i++){
            if (legal[i] != 1){
                printf("%c ", toupper(legal[i]));
            } else break;
        }
    } else {
        printf("Comando inexistente");
    }
    return 0;
}
