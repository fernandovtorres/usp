#include <stdio.h>
    
int main() {
    int n; 
    float acu = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        if (i%2){
            acu += (-1) * (1./(i+1));
        } else {
            acu += 1./(i+1);
        }
    }
    printf("%.4f", acu);
};