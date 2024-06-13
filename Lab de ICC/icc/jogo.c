    #include <stdio.h>
    #include <stdlib.h>

    /*
        Autor: Fernando Valentim Torres
        Descrição: Este código tem como objetivo simular um jogo de tabuleiro já iniciado e 
        indicar para o usuário quais são as possíveis posições nas quais ele pode executar uma jogada.
    */

    // Função para alocar memória para uma matriz bidimensional
    char **alocar(int lin, int col){
        char **mat = (char **) malloc(lin * sizeof(char *)); // Aloca memória para as linhas
        for(int i = 0; i < lin; i++){
            mat[i] = (char *) malloc(col * sizeof(char)); // Aloca memória para as colunas
        }
        return mat; // Retorna a matriz alocada
    }

    // Função para ler valores na matriz
    void lermatriz(char** mat, int lin, int col){
        for(int i = 0; i < lin; i++){
            for(int j = 0; j < col; j++){
                scanf(" %c", &mat[i][j]); // Lê um caractere para cada elemento da matriz
            }
        }
    }

    // Função para imprimir a matriz
    void imprimir(char **mat, int lin, int col) {
        for(int i = 0; i < lin; i ++){
            for(int j = 0; j < col; j++){
                printf("%c", mat[i][j]); // Imprime cada elemento da matriz
            }
            printf("\n"); // Imprime uma nova linha após cada linha da matriz
        }
    }

    // Função para jogar o jogo
    void jogar(char **mat, int lin, int col){
        for(int i = 0; i < lin; i++){
            int contador = 0;
            for(int j = 0; j < col; j++){
                if(mat[i][j] != 'X'){ // Se o elemento não for 'X'
                    if(i && mat[i-1][j] == 'X') contador ++; // verifica em cima
                    if(j && mat[i][j-1] == 'X') contador ++; // verifica na esquerda
                    if(i != (lin-1) && mat[i+1][j] == 'X') contador++; // Verifica em baixo
                    if(j != (col-1) && mat[i][j+1] == 'X') contador++; // Verifica na direita
                    if(!(contador%2)) mat[i][j] = '*'; // Se o número de 'X' for par, muda o elemento da posição para '*'
                    contador = 0; // Reseta o contador
                }
            }
        }   
    }

    int main(void){
        int lin, col; scanf(" %d %d", &lin, &col); // Lê o número de linhas e colunas
        char **matriz = alocar(lin, col); // Aloca memória para a matriz
        lermatriz(matriz, lin, col); // Lê os valores nd matriz
        jogar(matriz, lin, col); // Joga o jogo
        imprimir(matriz, lin, col); // Imprime a matriz resultante
        return 0;
    }