#include <stdio.h>

void ler(int n, int matrix[n][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf(" %d", &matrix[i][j]);
        }
    }
}

void printm(int n, int matrix[n][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int isDiagonal(int n, int matrix[n][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j && matrix[i][j] != 0) {
                return 0;
            } else if(i == j && matrix[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void multiplicarMatriz(int n, int matrix1[n][n], int matrix2[n][n], int result[n][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            result[i][j] = 0;
            for(int k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int n, m;
    scanf(" %d %d", &n, &m);

    int matriz1[n][n], matriz2[m][m];
    printf("Matrizes:\n");

    ler(n, matriz1);
    printm(n, matriz1);

    ler(m, matriz2);
    printm(m, matriz2);

    if(isDiagonal(n, matriz1)) {
        printf("A matriz 1 eh diagonal\n");
    } else {
        printf("A matriz 1 nao eh diagonal\n");
    }

    if(isDiagonal(m, matriz2)) {
        printf("A matriz 2 eh diagonal\n");
    } else {
        printf("A matriz 2 nao eh diagonal\n");
    }

    if(n != m) {
        printf("Matrizes de tamanho incompativel\n");
    } else {
        int result[n][n];
        multiplicarMatriz(n, matriz1, matriz2, result);
        printf("Matriz multiplicada:\n");
        printm(n, result);
    }
    return 0;
}