#include <stdio.h>

int main(void){
    int n1, n2, n3=0, *p, *q, *temp;
    scanf(" %d %d", &n1, &n2);
    p = &n1; q = &n2; temp = &n3;
    *temp = *p;
    *p = *q;
    *q = *temp;
    printf("%d %d", *p, *q);
    
    return 0;
}
