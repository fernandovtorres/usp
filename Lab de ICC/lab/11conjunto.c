#include <stdio.h>
#include <stdlib.h>



void sort(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particao(int *a, int bot, int top) {
    int pivo = a[bot];
    int i = bot;
    int j = top;
    while(i < j){
        while(a[i] <= pivo && i <= top - 1) {
            i++;
        }
        while(a[j] > pivo && j >= bot + 1){
            j--;
        }
        if (i < j) {
            sort(&a[i], &a[j]);
        }
    }
    sort(&a[bot], &a[j]);
    return j;
}

void quicksort(int a[], int bot, int top) {
    if(bot < top) {
        int part = particao(a, bot, top);
        quicksort(a, bot, part-1);
        quicksort(a, part+1, top);
    }
}

int *lereescrevermatriz(int tam) {
    int *vetor = NULL;
    if(!tam){
        printf("vazio");
        return vetor;
    } else {
        vetor = (int *) calloc(tam, sizeof(int));
        for(int i = 0; i < tam; i++){
            scanf(" %d", &vetor[i]);
        }
        quicksort(vetor, 0, tam-1);
        for(int i = 0; i < tam; i++){
            printf("%d ", vetor[i]);
        }   
        return vetor;
    }
}

int *uniao(int *a, int *b, int tama, int tamb, int *tu) {
    int *unido = NULL;
    if(!tama && !tamb) {
        printf("vazio\n");
        return unido;
    }
    unido = (int *) calloc(tama+tamb, sizeof(int));
    for(int i = 0; i < tama; i++){
        (*tu)++;
        unido[(*tu)-1] = a[i];
    }
    for(int i = 0; i < tamb; i++){
        int verifica = 1;
        for(int j = 0; j < tama; j++) {
            if(b[i] == a[j]) {
                verifica = 0;
                break;
            }
        }
        if(verifica) {
            (*tu)++;
            unido[(*tu)-1] = b[i];
        }
    }
    unido = (int *) realloc(unido, (*tu)*sizeof(int));
    quicksort(unido, 0, (*tu)-1);
    for(int i = 0; i < (*tu); i ++) {
        printf("%d ", unido[i]);
    }
    printf("\n");
    return unido;
}

int *intersecao(int *a, int *b, int tama, int tamb, int *ti) {
    int *inter = NULL;
    if(!tama || !tamb){
        return inter;
    }
    inter = (int *) calloc(tama, sizeof(int));
    for(int i = 0; i < tama; i++){
        for(int j = 0; j < tamb; j++){
            if(a[i] == b[j]){
                (*ti)++;
                inter[(*ti)-1] = a[i];
                break;
            }
        }
    }
    inter = (int*) realloc(inter, (*ti)*sizeof(int));
    return inter;

}

void sub(int *uni, int *inte, int tuni, int tint, int tjun) {
    int *sub = NULL;
    if(!tuni && !tint) {
        printf("vazio\n");
        return;
    }
    sub = (int *) calloc(tuni, sizeof(int));
    for(int i = 0; i < tuni; i++) {
        int verifica = 1;
        for(int j = 0; j < tint; j++){
            if(uni[i] == inte[j]) {
                verifica = 0;
                break;
            }
        }
        if(verifica) {
            tjun++;
            sub[tjun-1] = uni[i];
        }
    }
    sub = (int *) realloc(sub, tjun*sizeof(int));
    if(sub == NULL) {
        printf("vazio\n");
        return;
    }
    quicksort(sub, 0, tjun-1);
    for(int i = 0; i < tjun; i++){
        printf("%d ", sub[i]);
    }
    printf("\n");
}

int main(){
    int tama, tamb, tu = 0, ti = 0, tj = 0;
    int *a = NULL, *b = NULL;
    scanf(" %d", &tama);
    printf("conjunto A: ");
    a = lereescrevermatriz(tama);
    scanf(" %d", &tamb);
    printf("\nconjunto B: ");
    b = lereescrevermatriz(tamb);
    printf("\nA uniao B: ");
    int *c = uniao(a, b, tama, tamb, &tu);
    printf("(A uniao B) - (A interseccao B): ");    
    int *d = intersecao(a, b, tama, tamb, &ti);
    sub(c, d, tu, ti, tj);

    free(a);
    free(b);
    free(c);
    free(d);
    return 0;
}