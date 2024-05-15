#include <stdio.h>

int main(){
    int n, m, soma = 0; scanf(" %d %d", &n, &m);
    int matriz1[n][n], matriz2[m][m], diagonal1 = 1, diagonal2 = 1;
    printf("Matrizes:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf(" %d", &matriz1[i][j]);
            printf("%d ", matriz1[i][j]);
            if(i != j && matriz1[i][j] != 0 && diagonal1) diagonal1 = 0;
            else if (i == j && matriz1[i][j] == 0 && diagonal1) diagonal1 = 0;
        }
        printf("\n");
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            scanf(" %d", &matriz2[i][j]);
            printf("%d ", matriz2[i][j]);
            if(i != j && matriz2[i][j] != 0 && diagonal2) diagonal2 = 0;
            else if (i == j && matriz2[i][j] == 0 && diagonal2) diagonal2 = 0;
        }
        printf("\n");
    }
    if(diagonal1) printf("A matriz 1 eh diagonal\n");
    else printf("A matriz 1 nao eh diagonal\n");
    if(diagonal2) printf("A matriz 2 eh diagonal\n");
    else printf("A matriz 2 nao eh diagonal\n");
    if (n != m) {
        printf("Matrizes de tamanho incompativel\n");
    } else {
        printf("Matriz multiplicada:\n");
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                soma = 0;
                for (int k = 0; k < n; k++){
                    soma += matriz1[i][k] * matriz2[k][j];
                }
                printf("%d ", soma);
            }
            printf("\n");
        }
    }

    return 0;
}