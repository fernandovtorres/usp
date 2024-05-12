#include <stdio.h>

int pa(int n){
    return ((1+n)*n)/2;
}

int main(){
    int x, total = 0; scanf(" %d", &x);
    for(int i = 0; i < x-1; i++){
        int k; scanf(" %d", &k);
        total += k;
    }
    printf("Numero desaparecido: %d\n", pa(x) - total);
}