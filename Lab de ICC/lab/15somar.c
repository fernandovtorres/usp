#include <stdio.h> 

int count(int n){
    if(n == 1){
        return 1;
    } else if(n == 0){
        return 0;
    }
    n-=1;
    return count(n) + 1;
}

int soma(int n, int m){
    return count(n) + count(m);
}

int main(){
    int n, m; scanf(" %d %d", &n, &m);
    printf("%d", soma(n, m));
    return 0;
}
