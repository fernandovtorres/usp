#include <stdio.h>


int primo(int n) {
    if (n <= 1){
        return 0;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main(void) {
    int a, b, primoo, maiorprimo = 0, menorprimo = 10000;
    scanf(" %d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (primo(i)){
            primoo = i;
            if (primoo > maiorprimo) {
                maiorprimo = primoo;
            }
            if (primoo < menorprimo) {
                menorprimo = primoo;
            }
        }
        
    }
    if (maiorprimo == 0) {
        printf("nenhum primo no intervalo");
    } else {
        printf("menor primo: %d\nmaior primo: %d", menorprimo, maiorprimo);
    }
}
