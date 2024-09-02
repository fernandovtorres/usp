#include "stack.h"
#include <stdlib.h>

struct element {
  void *value;
  struct element *next;
};

struct stack {
  int total_qnt;
  struct element *head;
};

Pilha *create_stack(void) {
  Pilha *stack = (Pilha *)malloc(sizeof(Pilha));
  if (stack == NULL) {
    exit(1);
  }
  stack->total_qnt = 0;
  stack->head = NULL;
  return stack;
}

bool isEmpty(Pilha *pilha) {
  if (pilha != NULL && pilha->head == NULL) {
    return true;
  }
  return false;
}

bool insert(Pilha *pilha, void *value) {
  Elemento *elemento = (Elemento *)malloc(sizeof(Elemento));
  if (pilha != NULL && elemento != NULL) {
    elemento->value = value;
    elemento->next = pilha->head;
    pilha->head = elemento;
    pilha->total_qnt++;
    return true;
  }
  return false;
}

void *pop_item(Pilha *pilha) {
  void *valor;
  if (pilha != NULL && !(isEmpty(pilha))) {
    Elemento *dummy;
    dummy = pilha->head;
    pilha->head = dummy->next;
    pilha->total_qnt--;
    valor = dummy->value;
    free(dummy);
    return valor;
  }
  return NULL;
}

Elemento *top(Pilha *pilha) {
  if (pilha != NULL) {
    return pilha->head;
  }
  return NULL;
}

int stack_size(Pilha *pilha) {
  if (pilha != NULL) {
    return pilha->total_qnt;
  }
  exit(1);
}

Pilha *reverseStack(Pilha *pilha) {
  Pilha *reversed = malloc(sizeof(Pilha));
  if (!reversed) {
    return NULL;
  }
  Elemento *previous = NULL, *current = pilha->head, *next;
  reversed->total_qnt = pilha->total_qnt;
  while (current) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  reversed->head = previous;
  return reversed;
}
