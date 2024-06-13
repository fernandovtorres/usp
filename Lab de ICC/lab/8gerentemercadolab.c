#include <stdio.h>

int main(){
    int n, index; scanf(" %d", &n);
    float maior, total;
    if(n != 0){
        total = maior = 0;
        float v[n*4];
        for(int i = 0; i < n*4; i++){
            scanf(" %f", &v[i]);
        }
        for(int i = 1; i < n*4; i+=4){
            total += v[i] * v[i+2];
        }
        for(int i = 0; i < n*4; i+=4){
            total -= v[i] * v[i+2];
        }
        if (total > 0){
            printf("lucro: %.2f\n", total);
        } else {
            printf("prejuizo: %.2f\n", total*(-1));
        }
        for(int i = 0; i < n*4; i+=4){
            float x;
            x = (v[i+1]*v[i+3]) - (v[i]*v[i+2]);
            if (x > maior){
                maior = x;
                index = (i/4)+1;
            }
        }
        printf("produto: %d lucro relativo: %.2f", index, maior);
   } else {
       printf("Sem atividades registradas hoje");
   }
}
