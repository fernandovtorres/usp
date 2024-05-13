#include <stdio.h>

int main(void){
    unsigned long long int n, zeros = 0, cinco = 5;
    scanf("%llu", &n);

    for (int i = 0; i < 12; i++){ // trocar 10 para 12 caso testes sejam 10⁹
        if (i != 0) cinco *= 5;
        zeros += n/cinco;
    }
    printf("%llu\n", zeros);

    return (0);
}