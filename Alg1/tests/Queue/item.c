#include "item.h"
#include <stdlib.h>
struct item_ {
  int chave;
  void *comp;
};

ITEM *item_criar(int chave, void *comp) {
  ITEM *item = malloc(sizeof(ITEM));
  if (!item) {
    return NULL;
  }
  item->chave = chave;
  item->comp = comp;
  return item;
}
bool item_apagar(ITEM **item) {
  if (*item) {
    free(*item);
    *item = NULL;
    return true;
  }
  return false;
}
int item_get_chave(ITEM *item) {
  if (item) {
    return item->chave;
  }
  exit(1);
}
bool item_set_chave(ITEM *item, int chave) {
  if (item) {
    item->chave = chave;
    return true;
  }
  return false;
}
void *item_get_dados(ITEM *item) {
  if (item) {
    return item->comp;
  }
  return NULL;
}
