#include <stdio.h>

int main(void){
    int n; scanf(" %d", &n);
    int p[n], *x;
    x = p;
    for (int i = 0; i < n; i++){
        scanf(" %d", x);
        x++;
    }
    x --;
    for (int i = 0; i < n; i++){
        printf("%d ", *x);
        x --;
    }
    return 0;
}
