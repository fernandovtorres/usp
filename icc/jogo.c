#include <stdio.h>
#include <stdlib.h>
// . = 46;
// X = 88;
// * = 42;

char **alocar(int lin, int col){
    char **mat = (char **) malloc(lin * sizeof(char *));
    for(int i = 0; i < lin; i++){
        mat[i] = (char *) malloc(col * sizeof(char));
    }
    return mat;
}
void lermatriz(char** mat, int lin, int col){
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            scanf(" %c", &mat[i][j]);
        }
    }
}

void imprimir(char **mat, int lin, int col) {
    for(int i = 0; i < lin; i ++){
        for(int j = 0; j < col; j++){
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}

void jogar(char **mat, int lin, int col){
    for(int i = 0; i < lin; i++){
        int contador = 0;
        for(int j = 0; j < col; j++){
            if(mat[i][j] != 'X'){
                if(i && mat[i-1][j] == 'X') contador ++;
                if(j && mat[i][j-1] == 'X') contador ++;
                if(i != (lin-1) && mat[i+1][j] == 'X') contador++;
                if(j != (col-1) && mat[i][j+1] == 'X') contador++;
                if(!(contador%2)) mat[i][j] = '*';
                contador = 0; 
            }
        }
    }   
}

int main(void){
    int lin, col; scanf(" %d %d", &lin, &col);
    char **matriz = alocar(lin, col);
    lermatriz(matriz, lin, col);
    jogar(matriz, lin, col);
    imprimir(matriz, lin, col);
    return 0;
}