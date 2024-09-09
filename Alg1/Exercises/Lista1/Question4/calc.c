#include "calc.h"

double sum(double n1, double n2) { return n1 + n2; }

double sub(double n1, double n2) { return n1 - n2; }

double mult(double n1, double n2) { return n1 * n2; }

double div(double n1, double n2) {
  if (!n2) {
    return 0;
  }
  return n1 / n2;
}
