
#include "robot.h"

#include <stdio.h>

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

void miseAJourRobot(robot *r, pos position, float vitesse) {
  r->position = position;
  r->vitesse = vitesse;
}