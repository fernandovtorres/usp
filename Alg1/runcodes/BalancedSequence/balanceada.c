#include <stdlib.h>
#include "Pilha.h"


bool balanceada(char * sequencia) {
    PILHA* p = pilha_criar();
    if(p == NULL) {
        exit(1);
    };
    int i = 0;
    char buffer = sequencia[i];
    while(buffer) {
        if(buffer == '(') {
            pilha_empilhar(p, item_criar(')'));
        } else if(buffer == '[') {
            pilha_empilhar(p, item_criar(']'));
        } else if(buffer == '{') {
            pilha_empilhar(p, item_criar('}'));
        } else if(pilha_vazia(p) || item_get_chave(pilha_desempilhar(p)) != buffer) {
            return false;
        }
        buffer = sequencia[++i];
    }
    return pilha_vazia(p);
}

