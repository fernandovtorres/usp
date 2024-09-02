#include "Pilha.h"
#include <stdlib.h>
#include <stdio.h>

struct pilha {
  ITEM *item[TAM];
  int tamanho;
};


PILHA* pilha_criar(void) {
  PILHA* p;
  p = (PILHA*) malloc(sizeof(PILHA)); //oie
  if (p != NULL) {
    p->tamanho = 0;
    return p;
  }
  return NULL;
}

void pilha_apagar(PILHA** pilha){
  if (*pilha != NULL) {
    free(*pilha);
    *pilha = NULL;
  }
  return;
}

bool pilha_vazia(PILHA* pilha) {
  if (pilha != NULL && pilha->tamanho == 0) return true;
  return false;
}

bool pilha_cheia(PILHA* pilha) {
  if (pilha != NULL && pilha->tamanho == TAM) return true;
  return false;
}

int pilha_tamanho(PILHA* pilha) {
  if (pilha != NULL) return pilha->tamanho;
  return -1;
}

ITEM* pilha_topo(PILHA* pilha){
  if (pilha != NULL) return pilha->item[pilha->tamanho - 1];
  return NULL;

}

bool pilha_empilhar(PILHA* pilha, ITEM* item){
  if(pilha != NULL && !(pilha_cheia(pilha))) {
    pilha->item[pilha->tamanho++] = item;
    return true;
  }
  return false;
}

ITEM* pilha_desempilhar(PILHA* pilha){
  ITEM* i;
  if(pilha != NULL && !(pilha_vazia(pilha))) {
    i = pilha_topo(pilha);
    pilha->item[pilha->tamanho-1] = NULL;
    pilha->tamanho--;
    return i;
  }
  return NULL;
}

void pilha_print(PILHA* p) {
  if(p != NULL && !(pilha_vazia(p))) {
    for(int i = 0; i < p->tamanho; i ++) {
      item_imprimir(p->item[i]);
    } 
  }
  return;
}

