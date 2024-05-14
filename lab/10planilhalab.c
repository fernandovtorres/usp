#include <stdio.h>

void sort(float *p, int n){
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (p[i] > p[j]) {
                float temp; temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}
int main() {
    int n, m; scanf(" %d %d ", &n, &m);
    float media = 0, mediaexe[m];
    float matriz[n][m];
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            scanf("%f ", &matriz[i][j]);
            media += matriz[i][j];
        }
        if (media/m >= 5) {
            printf("Media do aluno %d = %.2f : Aprovado\n", i+1, media/m);
        }
        else{ 
            printf("Media do aluno %d = %.2f : Reprovado\n", i+1, media/m);
        }
        media = 0;
    }
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            media += matriz[j][i];
        }
        mediaexe[i] = media/n;
        media = 0;
    }
    printf("\n");
    sort(mediaexe, m);
    for(int i = 0; i < m; i++) {
        printf("%.2f ", mediaexe[i]);
    }
    printf("\n");
    return 0;
}