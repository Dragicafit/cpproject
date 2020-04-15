#include "missile.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "robot.h"

void initMissile(missile *m, robot *parent, int distance, int angle) {
  m->parent = parent;
  m->position = parent->position;
  m->distance = 0;
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
  m->position.x += m->distance * (int)cos(m->angle);
  m->position.y += m->distance * (int)sin(m->angle);
  if (m->distance >= m->distanceExplosion) explose(m);
}
