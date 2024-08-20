#ifndef STACK_H
    #define STACK_H
    #include <stdbool.h>
        typedef struct element Elemento;
        typedef struct stack Pilha;

        Pilha* create_stack(void);
        bool isEmpty(Pilha* pilha);
        bool insert(Pilha* pilha, void* value);
        void* pop_item(Pilha* pilha);
        Elemento* top(Pilha* pilha);
        int stack_size(Pilha* pilha);

#endif