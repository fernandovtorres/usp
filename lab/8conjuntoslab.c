#include <stdio.h>

int main() {
    int n, m, k = 1;
    scanf(" %d", &n);
    int a[n];
    for (int i = 0; i < n; i++){
        int x; scanf(" %d", &x);
        a[i] = x;
    }
    scanf(" %d", &m);
    int b[m];
    for (int i = 0; i < m; i++){
        int x; scanf(" %d", &x);
        b[i] = x;
    }
    printf("intersecao: ");
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                printf("%d ", a[i]);
                k = 0;
                a[i] = -85454568; // Eu sei que ta errado mas não pensei como fazer sem
            }
        }
    }
    if (k) {
        printf("vazio");
    }
    k = 1;
    printf("\na - b: ");
    for(int i = 0; i < n; i++) {
        if (a[i] != -85454568) {
            printf("%d ", a[i]);
            k = 0;
        }
    }
    if (k) {
        printf("vazio");
    }

    return 0;
}