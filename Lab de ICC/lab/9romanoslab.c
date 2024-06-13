#include <stdio.h>
#include <string.h>

void converter(int a, char *resposta) {
    const char *romanos[] = {
        "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
    };
    const int arabicos[] = {
        1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
    };
    int c = 0;
    for (int i = 0; i < 13; i++){
        while(a >= arabicos[i]) {
            a -= arabicos[i];
            strcpy(resposta+c, romanos[i]);
            c = strlen(resposta);
        }
    }
}
    
int main(){
    int n; scanf(" %d", &n);
    for(int i = 0; i < n; i++){
        int x; scanf("  %d", &x);    
        char resposta[30]; converter(x, resposta);
        printf("%s\n", resposta);
    }
}