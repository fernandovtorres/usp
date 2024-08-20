#include "item.h"
#include <stdlib.h>
#include <stdio.h>

struct item_ {
    char chave;
};



ITEM *item_criar(char chave){
    ITEM* i = (ITEM*) malloc(sizeof(ITEM));
    if(i != NULL) {
        i->chave = chave;
        return i;
    }
    return NULL;
}

bool item_apagar(ITEM **item){
    if(*item != NULL) {
        free(*item);
        *item = NULL;
        return true;
    }
    return false;
}

void item_imprimir(ITEM *item){
    if(item != NULL) {
        printf("%c\n", item->chave);
    }
    return;
}

char item_get_chave(ITEM *item){
    if(item != NULL) {
        return item->chave;
    }
    return 0;
}

bool item_set_chave(ITEM *item, char chave){
    if(item != NULL) {
        item->chave = chave;
        return true;
    }
    return false;
}
