#include <stdio.h>

void ler(int n, int m, char matriz[n][m]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            scanf(" %c", &matriz[i][j]);
        }
    }
}

void tirarCosplayers(int n, int m, char matriz[n][m]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            if (matriz[i][j] == 'c'){
                matriz[i][j] = 'x';
                for(int k = 0; k < n; k++) {
                    if(matriz[k][j] != 'c') matriz[k][j] = 'x';
                }
                for(int l = 0; l < m; l++) {
                    if(matriz[i][l] != 'c') matriz[i][l] = 'x';
                }
            } else if (matriz[i][j] == 'f') {
                matriz[i][j] = 'x';
            }
        }
    }
}

int verificarVaga(int n, int m, char matriz[n][m]) {
    int d = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            if(matriz[i][j] == 'v') {
                matriz[i][j] = 'o';
                d = 1;
            }
        }
    }
    return d;
}

void imprimirMatriz(int n, int m, char matriz[n][m]) {
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    scanf(" %d %d", &n, &m);
    char matriz[n][m];
    
    ler(n, m, matriz);
    tirarCosplayers(n, m, matriz);
    
    int vaga = verificarVaga(n, m, matriz);
    
    if (vaga) {
        imprimirMatriz(n, m, matriz);
    } else {
        printf("Eh um dia triste para os mono Yasuo");
    }
    
    return 0;
}