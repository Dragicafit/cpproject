#ifndef DEF_ROBOT
#define DEF_ROBOT

#include <stdint.h>

#include "constantes.h"
#include "parser.h"
#include "position.h"

typedef struct {
  pos position;
  float vitesse;
  float degat;
  int nb_missiles;
  int angle;
  char mort;
  program *script;
  int id;
  int32_t wait;
  uint32_t adresses[ADRESSES_MAX];
  uint32_t ligne;
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
  engine eng;
  shoot shoot;
} action;

void nextInstruction(robot *r);  // int si erreur
void miseAJourRobot(robot *r);
void degats(robot *r, float d);
robot *initRobot(float positionX, float positionY, char fichier[], int id);
void destruction(robot *r);

#endif
