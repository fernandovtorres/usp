#include <stdio.h>

int main() {
    char a;
    int b;
    scanf("%c", &a);
    fflush(stdin);
    scanf("%d", &b);
    printf("numero correspondente: %d\n", (int)a);
    printf("caracter correspondente: %c\n", (char)b);
    printf("octal: %o\n", b);
    printf("hexadecimal: %x", b);
    return 0;
}
