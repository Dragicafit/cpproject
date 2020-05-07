#include <stdio.h>
#include <stdlib.h>

#include "arene.h"
#include "expression.h"
#include "parser.h"
#include "robot.h"

robot *r;
arene *a;

int32_t par(int32_t exp1, char op, int32_t exp2) {
  switch (op) {
    case '+':
      return exp1 + exp2;
    case '-':
      return exp1 - exp2;
    case '*':
      return exp1 * exp2;
    case '/':
      return exp1 / exp2;
    case '%':
      return exp1 % exp2;
    default:
      return 0;
  }
}

int32_t peek(int32_t exp) { return r->adresses[exp]; }

int32_t RAND(int32_t exp) { return rand() % exp; }

int32_t cardinal() { return ROBOT_MAX; }