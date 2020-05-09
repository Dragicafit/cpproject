#include "missile.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "arene.h"
#include "constantes.h"
#include "expression.h"
#include "main.h"
#include "modele.h"
#include "robot.h"

missile *initMissile(robot *parent, int distance, int angle) {
  missile *m = calloc(1, sizeof(missile));
  m->parent = parent;
  m->position = parent->position;
  m->distanceExplosion = distance;
  m->angle = angle;
  m->distance = 0;
  m->aExplose = 0;
  return m;
}

void explose(missile *m) { m->aExplose = 1; }

void miseAJourMissile(arene *a, int i) {
  missile *m = a->l_missile[i];
  int distance = m->distanceExplosion - m->distance < MISSILE_SPEED
                     ? m->distanceExplosion
                     : MISSILE_SPEED;
  m->distance += distance;
  float x = m->position.x;
  float y = m->position.y;
  m->position.x = TargetX(m->position.x, m->angle, distance);
  m->position.y = TargetY(m->position.y, m->angle, distance);
  if (m->position.x >= X) {
    m->position.x = X;
    m->position.y = (Y - y) * (m->position.x - x) / (m->position.y - y);
    exploseRobots(a, m);
    return;
  }
  if (m->position.y >= Y) {
    m->position.x = (X - x) * (m->position.y - y) / (m->position.x - x);
    m->position.y = Y;
    exploseRobots(a, m);
    return;
  }
  if (m->position.x <= 0) {
    m->position.x = 0;
    m->position.y = y * (m->position.x - x) / (m->position.y - y);
    exploseRobots(a, m);
    return;
  }
  if (m->position.y <= 0) {
    m->position.x = x * (m->position.y - y) / (m->position.x - x);
    m->position.y = 0;
    exploseRobots(a, m);
    return;
  }
  if (m->distance >= m->distanceExplosion) {
    exploseRobots(a, m);
  }
}
