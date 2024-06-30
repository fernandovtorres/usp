#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void palavras(int a, int c, char *str){
    c++;
    for(int i = 0; i < 26; i++){
        char d = i+97;
        if(a != c) {
            str[c-1] = d;
            palavras(a, c, str);
        } else {
            printf("%s%c", str, i+97);
            printf("\n");
        }
    }
}

int main(){
    int m; scanf(" %d", &m);
    char *str = malloc(m * sizeof(char));
    palavras(m, 0, str);
    free(str);
    return 0;
}
