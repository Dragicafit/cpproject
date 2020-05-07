
#include "robot.h"

#include <stdio.h>

#include "constantes.h"
#include "main.h"

void init(robot *r, pos position) {
  r->degat = 0;
  r->mort = 0;
  r->nb_missiles = 0;
  r->position = position;
  r->vitesse = 0;
  // r->script = malloc();
}

void destruction(robot *r) {
  if (r->degat >= 1) r->mort = 1;
}

void degats(robot *r, float d) {
  if (r->mort != 1) r->degat += d;
}
void miseAJourRobot(robot *r, int angle, float vitesse) {
  r->vitesse = vitesse;
  r->angle = angle;
  r->position.x += (r->vitesse / 100) * VITESSE_MAX * (int)cos(r->angle);
  r->position.y += (r->vitesse / 100) * VITESSE_MAX * (int)sin(r->angle);
  if (r->position.x > X) r->position.x = X - 10;
  if (r->position.x > Y) r->position.x = Y - 10;
}