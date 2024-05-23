#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    int ip;
    int codigo;
    char *conteudo;
} dado;

int somadivisoresprimos(int codigo) {
    int sum = 0;
    for (int i = 2; i <= codigo; i++) {
        if(!(codigo % i)) {
            int primo = 1;
            for(int j = 2; j < sqrt(i); j++) {
                if (!(i % j)) {
                    primo = 0;
                    break;
                }
            }
            if (primo) {
                sum += i;
            }
        }
    }
    return sum;
}

int particaoo(dado *a, int low, int high) {
    int pivo = a[low].ip;
    int i = low;
    int j = high;
    while(i < j) {
        while(a[i].ip <= pivo && i <= high - 1) {
            i ++;
        }
        while(a[j].ip > pivo && j >= low + 1) {
            j--;
        }
        if (i < j) {
            dado temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    dado temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void sort(dado a[], int low, int high) {
    if (low < high) {
        int particao = particaoo(a, low, high);
        sort(a, low, particao-1);
        sort(a, particao+1, high);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    if (n) {
        dado *dados = (dado *)calloc(n, sizeof(dado));
        for (int i = 0; i < n; i++) {       
            scanf("%d %d", &dados[i].ip, &dados[i].codigo);
            int maxtam = somadivisoresprimos(dados[i].codigo);
            dados[i].conteudo = (char *)calloc(maxtam + 1, sizeof(char));
            scanf("%s", dados[i].conteudo);
        }
        sort(dados, 0, n-1);
        for (int i = 0; i < n; i++) {
            printf("%s %d\n", dados[i].conteudo, dados[i].codigo);
        }
        for (int i = 0; i < n; i++) {
            free(dados[i].conteudo);
        }
        free(dados);
    } else {
        printf("Sem produtos a serem cadastrados\n");
    }

    return 0;
}
