#include <stdio.h>
#include <math.h>

int main(void){   
    int n1;
    int a;
    char *arr[] = {"Segunda: Aula de computacao",
                       "Terca: Treino de volei",
                       "Quarta: Aula de calculo",
                       "Quinta: Lista de GA",
                       "Sexta: Festa da Sacim",
                       "Sabado: Jantar em familia",
                       "Domingo: Depressao pos final de semana"};
    scanf(" %d", &n1);
    scanf(" %d", &a);
    if (n1 >= 1 && n1 <= 7){
        if (!a){
            for (int i = n1; i <= 7; i++){
                printf("%s\n", arr[i-1]);
            }
        } else {
            printf("%s", arr[n1 - 1]);
        }
    } else {
        printf("Dia nao registrado");
    }
    return 0;
}
