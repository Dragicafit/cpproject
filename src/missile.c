#include "missile.h"

#include <stdio.h>
#include <stdlib.h>

#include "constantes.h"
#include "expression.h"
#include "main.h"
#include "robot.h"

void initMissile(missile *m, robot *parent, int distance, int angle) {
  m->parent = parent;
  m->position = parent->position;
  m->distanceExplosion = distance;
  m->angle = angle;
}

int explose(missile *m) {
  m->parent->nb_missiles -= 1;
  free(m);
}

void miseAJourMissile(missile *m) {
  m->distance += m->distanceExplosion - m->distance < 500
                     ? m->distanceExplosion - m->distance
                     : 500;
  m->position.x = TargetX(m->position.x, m->angle, m->distance);
  m->position.y = TargetX(m->position.y, m->angle, m->distance);
  if (m->position.x > X) {
    m->position.x = X - 1;
    explose(m);
  }
  if (m->position.x > Y) {
    m->position.x = Y - 1;
    explose(m);
  }
  if (m->distance >= m->distanceExplosion) explose(m);
}
