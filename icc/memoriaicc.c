#include <stdio.h>
int main(void) {
    unsigned short int a, b, c;
    long int d = 0;
    scanf(" %hd %hd %hd", &a, &b, &c);
    d |= c; d <<= 16;
    d |= b; d <<= 16;
    d |= a;
    printf("%ld\n", d);
    return (0);
}
