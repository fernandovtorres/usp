#include <stdio.h>

int main(void) {
    int n1; //case é nome reservado
    char nome_1, nome_2, caracter; //nome de variável não pode começar com número e char é nome reservado
    scanf("%d %c %c %c", &n1, &nome_1, &nome_2, &caracter);
    int resposta; resposta = n1;
    printf("a resposta eh %d", resposta);
    return (0);
}