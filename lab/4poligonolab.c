#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846



int main(void){
    int n;
    double l, a, A;
    scanf("%d %lf", &n, &l);
    a = l/(2*tan(PI/n));
    A = ((l*n)/2) * a;
    printf("%lf", A);
}