#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** aloca(int tam){
    int** mat = (int**) malloc(tam * sizeof(int *));
    for(int i = 0; i < tam; i++){
        mat[i] = (int *) malloc(tam * sizeof(int));
    }
    return mat;
}

void escrevermatriz(int** mat, int tam) {
    for(int i = 0; i < tam; i ++){
        for(int j = 0; j < tam; j++){
            scanf(" %d", &mat[i][j]);
        }
    }
}

void printarmatriz(int** mat, int tam){
    for(int i = 0; i < tam; i ++){
        for(int j = 0; j < tam; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int tam; scanf(" %d", &tam);
    tam = sqrt(tam);
    int **matriz = aloca(tam);
    escrevermatriz(matriz, tam);
    printarmatriz(matriz, tam);
    for(int i = 0; i < tam; i++){
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}
