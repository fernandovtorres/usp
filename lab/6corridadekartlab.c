#include <stdio.h>

int main(void){
    float velA, velB, distancia;
    int tempo, qnt;
    scanf(" %d", &qnt);
    for(int i = 0; i < qnt; i++){
        scanf(" %f %f %d", &velA, &velB, &tempo);
        if(tempo == 0){
            printf("A corrida ainda nao comecou\n");
        } else if(velA == 0 || velB == 0){
                if (velA > 0) printf("O piloto B desistiu inesperadamente\n");
                else if (velB > 0) printf("O piloto A desistiu inesperadamente\n");
                else printf("Os dois pilotos nao querem competir\n");
            
        } else if (tempo < 0 && (velA > 0 && velB > 0)) {
            printf("De alguma forma os pilotos voltaram no tempo\n");
        } else {
            if (velA > velB) {
                distancia = (velA - velB) * tempo;
                printf("O kart A venceu e percorreu %.2fkm a mais que o kart B\n", distancia);
            } else if (velB > velA) {
                distancia = (velB - velA) * tempo;
                printf("O kart B venceu e percorreu %.2fkm a mais que o kart A\n", distancia);
            } else {
                distancia = velA * tempo;
                printf("Os karts empataram, percorrendo cada %.2fkm\n", distancia);
            }
        }
    }
}