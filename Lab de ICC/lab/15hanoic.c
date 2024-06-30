#include <stdio.h>

int resultado;


void Hanoi(int n, char pilhaInicial, char pilhaFinal, char pilhaAuxiliar){
    if (n == 0) {
        return;
    }
    Hanoi(n - 1, pilhaInicial, pilhaAuxiliar, pilhaFinal);
    printf("Move disco %d da pilha %c para a pilha %c\n", n, pilhaInicial, pilhaFinal);
    Hanoi(n - 1, pilhaAuxiliar, pilhaFinal, pilhaInicial);
}

int main() {
    int n; scanf(" %d", &n);
    Hanoi(n, 'A', 'C', 'B');
    return 0;
}
