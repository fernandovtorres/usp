#include  <stdio.h>



int main() {
    long long int n;
    scanf("%lld", &n);
    char y[n];
    int x[n];
    double z[n];
    printf("char: %zu\nint: %zu\ndouble: %zu", sizeof(y), sizeof(x), sizeof(z));
}