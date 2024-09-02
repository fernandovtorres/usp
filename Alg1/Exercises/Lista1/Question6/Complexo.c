#include "Complexo.h"
#include <stdlib.h>
struct complexo {
  double real, imag;
};
Complexo *criar(double real, double imag) {
  Complexo *complex = malloc(sizeof(Complexo));
  if (complex) {
    complex->real = real;
    complex->imag = imag;
  }
  return complex;
}
void liberar(Complexo *c) {
  if (c) {
    free(c);
    c = NULL;
  }
  return;
}
void copiar(Complexo *source, Complexo *target) {
  if (source && target) {
    target->real = source->real;
    target->imag = source->imag;
  }
  return;
}
Complexo *adicao(Complexo *a, Complexo *b) {
  Complexo *result = malloc(sizeof(Complexo));
  if (!result)
    return NULL;
  if (a && b) {
    result->real = a->real + b->real;
    result->imag = a->imag + b->imag;
    return result;
  }
  return NULL;
}
Complexo *subtracao(Complexo *a, Complexo *b) {
  Complexo *result = malloc(sizeof(Complexo));
  if (!result)
    return NULL;
  if (a && b) {
    result->real = a->real - b->real;
    result->imag = a->imag - b->imag;
    return result;
  }
  return NULL;
}
int e_real(Complexo *c) {
  if (c) {
    return c->imag == 0;
  }
  return 0;
}
double real(Complexo *c) {
  if (c) {
    return c->real;
  }
  return 0;
}
double imag(Complexo *c) {
  if (c) {
    return c->imag;
  }
  return 0;
}
void atribuir(Complexo *c, double real, double imag) {
  if (c) {
    c->real = real;
    c->imag = imag;
  }
  return;
}
void atribuir_real(Complexo *c, double real) {
  if (c)
    c->real = real;
  return;
}
void atribuir_imag(Complexo *c, double imag) {
  if (c)
    c->imag = imag;
  return;
}
