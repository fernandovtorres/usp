#include <stdio.h>

int main(void){
    // Full adder, 2 xor, 2 and e 1 or
    // !AB+A!B

    int n, m,  bit, dec = 0;
    scanf(" %d %d", &n, &m);

    for (int i = n; i > 0; i--){
        scanf(" %d", &bit);
        bit <<= i-1;
        dec += bit;
    }
    for (int i = m; i > 0; i--) {
        scanf(" %d", &bit);
        bit <<= i - 1;
        dec += bit;
    }
    printf("%d\n", dec);

    return (0);
}