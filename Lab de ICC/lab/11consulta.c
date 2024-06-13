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

void merge(dado *esq, dado *dir, dado *a, int tam) {
    int esqsize = tam/2;
    int dirsize = tam - esqsize;
    int i = 0, l = 0, r = 0;

    while (l < esqsize && r < dirsize) {
        if(esq[l].ip > dir[r].ip) { // só trocar para alterar a ordem
            a[i] = esq[l];
            i++;
            l++;
        } else {
            a[i] = dir[r];
            i++;
            r++;
        }
    }
    while (l < esqsize) {
        a[i] = esq[l];
        i++;
        l++;
    }
    while (r < dirsize) {
        a[i] = dir[r];
        i++;
        r++;
    }
}

void mergesort(dado a[], int tam) {
    if(tam <= 1) return;
    int meio = tam/2;
    dado arresq[meio];
    dado arrdir[tam-meio];

    int i = 0;
    int j = 0;
    for(; i < tam; i++){
        if(i < meio) {
            arresq[i] = a[i];
        } else {
            arrdir[j] = a[i];
            j++;
        }
    }
    mergesort(arresq, meio);
    mergesort(arrdir, tam-meio);
    merge(arresq, arrdir, a, tam);
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
        mergesort(dados, n);
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
