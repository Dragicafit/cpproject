#include "expression.h"

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "arene.h"
#include "constantes.h"
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

int32_t aleat(int32_t exp) { return rand() % exp; }

int32_t cardinal() { return ROBOT_MAX; }

int32_t self() { return r->id; }

int32_t speed() { return r->vitesse; }

int32_t state(int32_t exp) { return PV_MAX - a->l_robot[exp]->degat; }

int32_t gpsx(int32_t exp) { return a->l_robot[exp]->position.x - 5; }

int32_t gpsy(int32_t exp) { return a->l_robot[exp]->position.y - 5; }

int32_t angle(int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
  return (int32_t)atan((y2 - y1) - (x2 - x1));
}

int32_t TargetX(int32_t x1, int32_t angle, int32_t length) {
  return (int32_t)(x1 + length * cos(angle));
}

int32_t TargetY(int32_t y1, int32_t angle, int32_t length) {
  return (int32_t)(y1 + length * sin(angle));
}

int32_t distance(int32_t x1, int32_t y1, int32_t x2, int32_t y2) {
  return (int32_t)sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}