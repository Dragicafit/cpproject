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
  m->distance = m->distanceExplosion - m->distance < 100
                    ? m->distanceExplosion - m->distance
                    : 100;
  m->position.x = TargetX(m->position.x, m->angle, m->distance);
  m->position.y = TargetY(m->position.y, m->angle, m->distance);
  if (m->position.x > X) {
    m->position.x = X - 1;
    exploseRobots(a, m);
    return;
  }
  if (m->position.y > Y) {
    m->position.y = Y - 1;
    exploseRobots(a, m);
    return;
  }
  if (m->position.x < 0) {
    m->position.x = 1;
    exploseRobots(a, m);
    return;
  }
  if (m->position.y < 0) {
    m->position.y = 1;
    exploseRobots(a, m);
    return;
  }
  if (m->distance >= m->distanceExplosion) explose(m);
}
