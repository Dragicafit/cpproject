#include "missile.h"
#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD

#include "constantes.h"
=======
>>>>>>> parent of 43dc261... modif robot et missile
#include "main.h"
#include "robot.h"

void initMissile(missile *m, robot *parent) {
    m->parent = parent;
    m->position = parent->position;
}

int explose(missile *m) {
    m->parent->nb_missiles-=1;
    free(m);
}

<<<<<<< HEAD
void miseAJourMissile(missile *m) {
  m->distance += m->distanceExplosion - m->distance < 500
                     ? m->distanceExplosion - m->distance
                     : 500;
  m->position.x += m->distance * (int)cos(m->angle);
  m->position.y += m->distance * (int)sin(m->angle);
  if (m->position.x > X) {
    m->position.x = X - 1;
    explose(m);
  }
  if (m->position.x > Y) {
    m->position.x = Y - 1;
    explose(m);
  }
  if (m->distance >= m->distanceExplosion) explose(m);
=======
void miseAJourMissile(missile *m, pos position) {
    m->position.x = position.x;
    m->position.y = position.y;
>>>>>>> parent of 43dc261... modif robot et missile
}
