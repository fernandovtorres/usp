#include "queue.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct no_ NO;

struct no_ {
  ITEM *item;
  NO *proximo;
};
struct fila_ {
  NO *inicio;
  NO *fim;
  int tamanho;
};

FILA *fila_criar(void) {
  FILA *fila = malloc(sizeof(FILA));
  if (!fila) {
    return NULL;
  }
  fila->inicio = fila->fim = NULL;
  fila->tamanho = 0;
  return fila;
}

bool fila_inserir(FILA *fila, ITEM *item) {
  NO *no = malloc(sizeof(NO));
  if (!no) {
    return false;
  }
  if (!fila || fila_cheia(fila)) {
    return false;
  }
  no->item = item;
  if (fila->inicio == NULL) {
    fila->inicio = fila->fim = no;
    no->proximo = NULL;
  } else {
    no->proximo = NULL;
    fila->fim->proximo = no;
    fila->fim = no;
  }
  fila->tamanho++;
  return true;
}

ITEM *fila_remover(FILA *fila) {
  if (!fila || fila_vazia(fila)) {
    return NULL;
  }
  NO *no = fila->inicio;
  if (fila->inicio == fila->fim) {
    fila->inicio = fila->fim = NULL;
  } else {
    fila->inicio = fila->inicio->proximo;
  }
  fila->tamanho--;
  no->proximo = NULL;
  return no->item;
}

void fila_apagar(FILA **fila) {
  if (*fila) {
    (*fila)->fim = NULL;
    while ((*fila)->inicio) {
      NO *no = (*fila)->inicio;
      (*fila)->inicio = (*fila)->inicio->proximo;
      free(no->item);
      free(no);
      no = NULL;
    }
    free(*fila);
    *fila = NULL;
  }
  return;
}

ITEM *fila_frente(FILA *fila) {
  if (!fila) {
    return NULL;
  }
  return fila->inicio->item;
}

int fila_tamanho(FILA *fila) {
  if (!fila) {
    exit(1);
  }
  return fila->tamanho;
}

bool fila_vazia(FILA *fila) {
  if (!fila) {
    return true;
  }
  return fila->inicio == NULL || fila->tamanho == 0;
}

bool fila_cheia(FILA *fila) {
  if (!fila) {
    return true;
  }
  NO *no = malloc(sizeof(NO));
  if (!no) {
    return true;
  }
  return false;
}

void fila_imprimir(FILA *fila) {
  if (fila) {
    NO *index = fila->inicio;
    while (fila->inicio != fila->fim) {
      printf(" %f", *((double *)item_get_dados(fila->inicio->item)));
      fila->inicio = fila->inicio->proximo;
    }
    printf(" %f", *((double *)item_get_dados(fila->inicio->item)));
  }
}
