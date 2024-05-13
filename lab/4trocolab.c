#include <stdio.h>

int main(void){
    int n1, duz, cem, cinq, vint, dez, cinc, dois, um;
    duz = cem = cinq = vint = dez = cinc = dois = um = 0;
    scanf("%d", &n1);
    while(n1 != 0){
        if (n1 - 200 >= 0) {
            duz ++;
            n1 -= 200;
        } else if (n1 - 100 >= 0){
            cem ++;
            n1 -= 100;
        } else if (n1 - 50 >= 0) {
            cinq ++;
            n1 -= 50;
        } else if (n1 - 20 >= 0) {
            vint ++;
            n1 -= 20;
        } else if (n1 - 10 >= 0) {
            dez ++;
            n1 -= 10;
        } else if (n1 - 5 >= 0) {
            cinc ++;
            n1 -= 5;
        } else if (n1 - 2 >= 0) {
            dois ++;
            n1 -= 2;
        } else {
            um++;
            n1 --;
        }
    }
    printf("%d nota(s) de R$ 200\n%d nota(s) de R$ 100\n%d nota(s) de R$ 50\n%d nota(s) de R$ 20\n%d nota(s) de R$ 10\n%d nota(s) de R$ 5\n%d nota(s) de R$ 2\n%d moeda(s) de R$ 1", duz, cem, cinq, vint, dez, cinc, dois, um);
    return 0;
}