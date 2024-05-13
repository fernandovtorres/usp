#include <stdio.h>
#include <math.h>
    
int main() {
    int dez, mil, a;
    for (int i = 1000; i < 10000; i++){
        a = i;
        mil = i / 100;
        dez = a - (mil*100);
        if (sqrt(i) == dez + mil) printf("%d\n", i);
    }
};