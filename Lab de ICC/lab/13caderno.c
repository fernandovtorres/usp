#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* nome;
    int qntFarinha;
    int qntOvo;
    int qntOleo;
    int qntAcucar;
    int qntChocolate;
} receita;

typedef struct {
    int farinha;
    int ovo;
    int oleo;
    int acucar;
    int chocolate;
} estoque;

#define INITestoque(x) estoque x = {.farinha = 0, .ovo = 0, .oleo = 0, .acucar = 0, .chocolate = 0}

void registrar(receita **caderno, int index) {
    receita nova;
    nova.nome = malloc(sizeof(char)*20);
    scanf(" %s", nova.nome);
    scanf(" %d %d %d %d %d", &nova.qntFarinha, &nova.qntOvo, &nova.qntOleo, &nova.qntAcucar, &nova.qntChocolate);
    (*caderno)[index-1] = nova;
}

void cadastroDeCompras(estoque* x) {
    int qnt; scanf(" %d", &qnt);
    x->farinha += qnt; scanf(" %d", &qnt);
    x->ovo += qnt; scanf(" %d", &qnt);
    x->oleo += qnt; scanf(" %d", &qnt);
    x->acucar += qnt; scanf(" %d", &qnt);
    x->chocolate += qnt;
}

void fazerReceita(estoque* x, receita* caderno){
    if(x->farinha >= caderno->qntFarinha && x->ovo >= caderno->qntOvo && x->oleo >= caderno->qntOleo && x->acucar >= caderno->qntAcucar && x->chocolate >= caderno->qntChocolate){
        printf("%s feita com sucesso!\n", caderno->nome);
        x->farinha -= caderno->qntFarinha;
        x->ovo -= caderno->qntOvo;
        x->oleo -= caderno->qntOleo;
        x->acucar -= caderno->qntAcucar;
        x->chocolate -= caderno->qntChocolate;
    } else {
        if(x->farinha < caderno->qntFarinha) {
            printf("Farinha insuficiente\n");
            return;
        }
        if(x->ovo < caderno->qntOvo) {
            printf("Ovos insuficientes\n");
            return;
        }
        if(x->oleo < caderno->qntOleo) {
            printf("Oleo insuficiente\n");
            return;
        }
        if(x->acucar < caderno->qntAcucar) {
            printf("Acucar insuficiente\n");
            return;
        }
        if(x->chocolate < caderno->qntChocolate) {
            printf("Chocolate insuficiente\n");
            return;
        }
    }
}

void printarBonito(estoque* x, int cnt) {
    printf("Quantidade no estoque:\n");
    printf("Acucar: %d\n", x->acucar);
    printf("Chocolate: %d\n", x->chocolate);
    printf("Farinha: %d\n", x->farinha);
    printf("Oleo: %d\n", x->oleo);
    printf("Ovos: %d\n", x->ovo);
    printf("Receitas cadastradas: %d\n", cnt);
}

int main(void){
    INITestoque(x);
    int cnt = 0;
    receita* cadernoDeReceitas = NULL;
    while(1) {
        char comando; scanf(" %c", &comando);
        switch (comando) {
            case 82: //R
                cnt++;
                cadernoDeReceitas = realloc(cadernoDeReceitas, sizeof(receita)*cnt);
                registrar(&cadernoDeReceitas, cnt);
                break;
            case 67: //C
                cadastroDeCompras(&x);
                break;
            case 70: //F
                int index; scanf(" %d", &index);
                if(index >= cnt) {
                    printf("Receita nao encontrada!\n");
                } else {
                    fazerReceita(&x, &cadernoDeReceitas[index]);
                }
                break;
            case 83: //S
                printarBonito(&x, cnt);
                cnt = -1;
                break;
            default:
                printf("Codigo invalido\n");
                break;
        }
        if(cnt == -1) {
            break;
        }
    }
    free(cadernoDeReceitas);
    return 0;
}