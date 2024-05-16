#include <stdio.h>
#include <string.h>

int main(){
    int n; scanf(" %d", &n);
    char mar[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            scanf(" %c", &mar[i][j]);
        }
    }
    int a; scanf(" %d", &a);
    char coord[4];
    for(int i = 0; i < a; i++) {
        int x, y, z;
        scanf(" %s", coord);
        x = coord[0]-65;
        y = coord[1]-49;
        z = coord[2]-48;
        if (z >= 0) y = z + 9 + (10 * y);
        if(mar[x][y] == 'N') {
            printf("acerto!\n");
            mar[x][y] = 'X';
        } else {
            printf("erro!\n");
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            printf("%c ", mar[i][j]);
        }
        printf("\n");
    }
}