#include "Pilha.h"
#include "item.h"
#include <stdlib.h>

float rpn(char *sequencia) {
  int index = 0, qntNumeros = 0;
  PILHA *pilha = pilha_criar();
  double *operando1, *operando2, resultado, *doubleToChar;
  doubleToChar = malloc(sizeof(double));
  while (sequencia[index]) {
    switch (sequencia[index]) {
    case '*':
      operando2 = (double *)item_get_dados(pilha_desempilhar(pilha));
      operando1 = (double *)item_get_dados(pilha_desempilhar(pilha));
      resultado = (*operando1) * (*operando2);
      doubleToChar = realloc(doubleToChar, sizeof(double) * (++qntNumeros));
      doubleToChar[qntNumeros - 1] = resultado;
      pilha_empilhar(pilha, item_criar(index, &(doubleToChar[qntNumeros - 1])));
      break;

    case '/':
      operando2 = (double *)item_get_dados(pilha_desempilhar(pilha));
      operando1 = (double *)item_get_dados(pilha_desempilhar(pilha));
      resultado = (*operando1) / (*operando2);
      doubleToChar = realloc(doubleToChar, sizeof(double) * (++qntNumeros));
      doubleToChar[qntNumeros - 1] = resultado;
      pilha_empilhar(pilha, item_criar(index, &(doubleToChar[qntNumeros - 1])));

      break;

    case '+':
      operando2 = (double *)item_get_dados(pilha_desempilhar(pilha));
      operando1 = (double *)item_get_dados(pilha_desempilhar(pilha));
      resultado = (*operando1) + (*operando2);
      doubleToChar = realloc(doubleToChar, sizeof(double) * (++qntNumeros));
      doubleToChar[qntNumeros - 1] = resultado;
      pilha_empilhar(pilha, item_criar(index, &(doubleToChar[qntNumeros - 1])));

      break;

    case '-':
      operando2 = (double *)item_get_dados(pilha_desempilhar(pilha));
      operando1 = (double *)item_get_dados(pilha_desempilhar(pilha));
      resultado = (*operando1) - (*operando2);
      doubleToChar = realloc(doubleToChar, sizeof(double) * (++qntNumeros));
      doubleToChar[qntNumeros - 1] = resultado;
      pilha_empilhar(pilha, item_criar(index, &(doubleToChar[qntNumeros - 1])));

      break;

    default:
      doubleToChar = realloc(doubleToChar, sizeof(double) * (++qntNumeros));
      doubleToChar[qntNumeros - 1] = (double)(sequencia[index] - '0');
      pilha_empilhar(pilha, item_criar(index, &(doubleToChar[qntNumeros - 1])));
      break;
    }
    index++;
  }
  ITEM *itemtemp = pilha_topo(pilha);
  double *dado = item_get_dados(itemtemp);
  return ((float)(*dado));
}
