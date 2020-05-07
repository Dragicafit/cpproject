#ifndef DEF_ROBOT
#define DEF_ROBOT

#include "constantes.h"
#include "position.h"
#include <stdint.h>

typedef struct {
  pos position;
  float vitesse;
  float degat;
  int nb_missiles;
  int angle;
  char mort;
  char *script;
  int id;
  uint32_t adresses[ADRESSES_MAX];
} robot;

typedef struct {
  float vitesse;
  float direction;
} engine;

typedef struct {
  float direction;
  int distance;
} shoot;

union {
  engine engine;
  shoot shoot;
} action;

void nextInstruction(robot *r);  // int si erreur
void miseAJourRobot(robot *r, int angle, float vitesse);
void degats(robot *r, float d);
void init(robot *r, pos position);
void destruction(robot *r);

#endif
