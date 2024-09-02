#include "Deque.h"
#include <stdlib.h>
struct deque_ {
  ITEM *arr[MAX_TAMANHO];
  int inicio, fim, qntItens;
};

DEQUE *deque_criar() {
  DEQUE *deque = malloc(sizeof(DEQUE));
  if (!deque) {
    return NULL;
  }
  deque->inicio = -1;
  deque->fim = -1;
  deque->qntItens = 0;
  return deque;
}

void deque_apagar(DEQUE **deque) {
  if (*deque) {
    free(*deque);
    *deque = NULL;
  }
  return;
}

bool deque_cheia(DEQUE *deque) {
  if (deque) {
    return ((deque->inicio == 0 && deque->fim == MAX_TAMANHO - 1) ||
            deque->inicio == deque->fim + 1);
  }
  return true;
}

bool deque_vazia(DEQUE *deque) {
  if (deque) {
    return (deque->inicio == -1);
  }
  return true;
}

bool deque_inserir_inicio(DEQUE *deque, ITEM *item) {
  if (!deque_cheia(deque)) {
    if (deque->inicio == -1) {
      deque->inicio = deque->fim = 0;
    } else if (deque->inicio == 0) {
      deque->inicio = MAX_TAMANHO - 1;
    } else {
      deque->inicio--;
    }
    deque->arr[deque->inicio] = item;
    deque->qntItens++;
    return true;
  }
  return false;
}

bool deque_inserir_fim(DEQUE *deque, ITEM *item) {
  if (!deque_cheia(deque)) {
    if (deque->inicio == -1) {
      deque->inicio = deque->fim = 0;
    } else if (deque->fim == MAX_TAMANHO - 1) {
      deque->fim = 0;
    } else {
      deque->fim++;
    }
    deque->arr[deque->fim] = item;
    deque->qntItens++;
    return true;
  }
  return false;
}

ITEM *deque_remover_inicio(DEQUE *deque) {
  if (!deque_vazia(deque)) {
    ITEM *i = deque->arr[deque->inicio];
    deque->arr[deque->inicio] = NULL;
    if (deque->inicio == deque->fim) {
      deque->inicio = deque->fim = -1;
    } else if (deque->inicio == MAX_TAMANHO - 1) {
      deque->inicio = 0;
    } else {
      deque->inicio++;
    }
    deque->qntItens--;
    return i;
  }
  return NULL;
}
ITEM *deque_remover_fim(DEQUE *deque) {
  if (!deque_vazia(deque)) {
    ITEM *i = deque->arr[deque->fim];
    deque->arr[deque->fim] = NULL;
    if (deque->inicio == deque->fim) {
      deque->inicio = deque->fim = -1;
    } else if (deque->fim == 0) {
      deque->fim = MAX_TAMANHO - 1;
    } else {
      deque->fim--;
    }
    deque->qntItens--;
    return i;
  }
  return NULL;
}

int deque_contar(DEQUE *deque) {
  if (deque) {
    return deque->qntItens;
  }
  return ERRO;
}
