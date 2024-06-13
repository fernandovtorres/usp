#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *aloca(int n) {
    return malloc(sizeof(char) * n);
}

int main(void){
    char *a, *b;
    char param[21];
    a = aloca(131);
    b = aloca(131);
    fgets(a, 131, stdin);
    fgets(b, 131, stdin);
    fgets(param, 21, stdin);
    a[strcspn(a, "\r\n")] = 0;
    b[strcspn(b, "\r\n")] = 0;
    param[strcspn(param, "\r\n")] = 0;
    size_t tmn = strlen(param);
    char *ptr = strstr(a, param);
    if(ptr != NULL){
        *ptr = '\0';
        printf("%s", a);
    } else {
        printf("%s", a);
    }
    size_t tmn2 = strlen(a);
    if(tmn2 != 0 && a[tmn2-1] != 32) {
        printf(" ");
    }
    char *ptr2 = strstr(b, param);
    if(ptr2 != NULL){
        ptr2 += tmn+1;
        printf("%s", ptr2);
    }
    free(a);
    free(b);
    return 0;
}