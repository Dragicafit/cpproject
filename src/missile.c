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
  return m;
}

void explose(arene *a, int i) {
  missile *m = a->l_missile[i];
  a->l_missile[i] = a->l_missile[a->nb_missile--];
  m->parent->nb_missiles--;
  free(m);
}

void miseAJourMissile(arene *a, int i) {
  missile *m = a->l_missile[i];
  write(0, "1\n", 2);
  m->distance += m->distanceExplosion - m->distance < 500
                     ? m->distanceExplosion - m->distance
                     : 500;
  m->position.x = TargetX(m->position.x, m->angle, m->distance);
  m->position.y = TargetX(m->position.y, m->angle, m->distance);
  if (m->position.x > X) {
    m->position.x = X - 1;
    explose(a, i);
    return;
  }
  if (m->position.y > Y) {
    m->position.y = Y - 1;
    explose(a, i);
    return;
  }
  if (m->position.x < 0) {
    m->position.x = 1;
    explose(a, i);
    return;
  }
  if (m->position.y < 0) {
    m->position.y = 1;
    explose(a, i);
    return;
  }
  if (m->distance >= m->distanceExplosion) explose(a, i);
}
