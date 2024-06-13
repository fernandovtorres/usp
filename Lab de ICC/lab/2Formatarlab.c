#include <stdio.h>

int main() {
    char a[8];
    scanf("%s", a);
    printf("%.2s/%.2s/%.4s", a, a+2, a+4);
}
