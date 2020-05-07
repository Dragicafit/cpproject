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

int32_t par(int32_t exp1, operator op, int32_t exp2) {
  switch (op) {
    case PLUS:
      return exp1 + exp2;
    case MINUS:
      return exp1 - exp2;
    case MULT:
      return exp1 * exp2;
    case DIV:
      return exp1 / exp2;
    case MOD:
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

char condition(int32_t exp1, comparison comp, int32_t exp2) {
  switch (comp) {
    case STRIC_INF:
      return exp1 < exp2;
    case INF:
      return exp1 <= exp2;
    case EQ:
      return exp1 == exp2;
    case DIFF:
      return exp1 != exp2;
    case SUP:
      return exp1 >= exp2;
    case STRICT_SUP:
      return exp1 > exp2;
    default:
      return 0;
  }
}

void Goto(uint32_t nb) { r->ligne = nb; }

void poke(int32_t add, int32_t value) { r->adresses[add] = value; }

void ifThen(char condition, uint32_t number) {
  if (condition) {
    Goto(number);
  }
}

void engine(uint32_t angle, uint32_t speed) {
  r->vitesse = speed;
  r->angle = angle;
}
