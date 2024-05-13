#include <stdio.h>


void sort(int *p, int n){
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (p[i] > p[j] && p[j] != 0 && p[i] != 0) {
                int temp; temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            if (p[j] == 0) {
                int temp; temp = p[j+1];
                p[j+1] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main(){
    int x; scanf(" %d", &x);
    int pontos[x], ordernados[x];
    for(int i = 0; i<x; i++) {
        scanf(" %d", &pontos[i]); // Insere os Valores no Array de pontos
    }
    int d = 1;
    for(int i = 0; i<x; i++){ // Só insere os valores no Array que será ordenado caso o valor não exista dentro do "ordenados"
        for(int j = 0; j < x-(x-i); j++){
            if(pontos[i] == ordernados[j]) {
                d = 0;
                break;
            }
        }
        if (d) {
            ordernados[i] = pontos[i];
        } else {
            ordernados[i] = 0;
        }
        d = 1;
    }
    sort(ordernados, x); // Ordena o vetor e joga os 0's para a direita
    for(int i = 0; i < x; i++) { // Correlaciona os pontos com a posição no vetor ordenado e printa os indexes referentes
        int index;
        for(int j = 0; j < x; j++) {
            if(pontos[i] == ordernados[j]) {
                index = j;
                break;
            }
        }
        printf("%dº Atleta, %d Pontos, %dº Colocado\n", i+1, pontos[i], index+1);
    }

}