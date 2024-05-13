#include <stdio.h>

int main(void){
    char str[26];
    int i = 0;
    scanf("%[^\n]s", str);
    do {
        if (*(str+i) >= 32) {
            printf("%c\n", *(str+i));
        } else {
            break;
        }
        i++;
    }while(1);
    return 0;
}
