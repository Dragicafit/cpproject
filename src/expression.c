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

char conditions(condition *condition) {
  int32_t exp1 = Expression(condition->expression1);
  int32_t exp2 = Expression(condition->expression2);
  switch (condition->comparison) {
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

void Wait(int32_t delay) {
  if (delay < 0) return;
  r->wait = delay;
}

void Goto(uint32_t nb) { r->ligne = nb; }

void poke(int32_t add, int32_t value) { r->adresses[add] = value; }

void ifThen(char condition, uint32_t number) {
  if (condition) {
    Goto(number);
  }
}

void Engine(uint32_t angle, uint32_t speed) {
  r->vitesse = speed;
  r->angle = angle;
}

void Shoot(uint32_t angle, uint32_t distance) {
  if (a->nb_missile >= ROBOT_MAX * MISSILES_MAX ||
      r->nb_missiles >= MISSILES_MAX)
    return;
  missile *m;
  initMissile(m, r, distance, angle);
  a->l_missile[a->nb_missile] = m;
  a->nb_missile += 1;
  r->nb_missiles += 1;
}

void Command(command *c) {
  switch (c->type) {
    case WAIT:
      Wait(Expression(c->expression1));
      break;
    case GOTO:
      Goto(c->number);
      break;
    case IF:
      ifThen(conditions(c->condition), c->number);
      break;
    case POKE:
      poke(Expression(c->expression1), Expression(c->expression2));
    case ENGINE:
      Engine(Expression(c->expression1), Expression(c->expression2));
    case SHOOT:
      Shoot(Expression(c->expression1), Expression(c->expression2));
      break;
    default:
      break;
  }
}

uint32_t Expression(expression *exp) {
  switch (exp->type) {
    case INT:
      return exp->integer;
      break;
    case PAR:
      return par(Expression(exp->expression1[0]), exp->operator,
                 Expression(exp->expression1[1]));
    case PEEK:
      return peek(Expression(exp->expression1[0]));
    case RAND:
      return aleat(Expression(exp->expression1[0]));
    case CARDINAL:
      return cardinal();
    case SELF:
      return self();
    case SPEED:
      return speed();
    case STATE:
      return state(Expression(exp->expression1[0]));
    case GPSX:
      return gpsx(Expression(exp->expression1[0]));
    case GPSY:
      return gpsy(Expression(exp->expression1[0]));
    case ANGLE:
      return angle(
          Expression(exp->expression1[0]), Expression(exp->expression1[1]),
          Expression(exp->expression1[2]), Expression(exp->expression1[3]));
    case TARGETX:
      return TargetX(Expression(exp->expression1[0]),
                     Expression(exp->expression1[1]),
                     Expression(exp->expression1[2]));
    case TARGETY:
      return TargetY(Expression(exp->expression1[0]),
                     Expression(exp->expression1[1]),
                     Expression(exp->expression1[2]));
    case DISTANCE:
      return distance(
          Expression(exp->expression1[0]), Expression(exp->expression1[1]),
          Expression(exp->expression1[2]), Expression(exp->expression1[3]));
    default:
      return 0;
  }
}

void Line() {
  if (r->ligne >= r->script->length) {
    r->mort = 1;
    return;
  }
  command *c = r->script->lines[r->ligne++];
  Command(c);
}