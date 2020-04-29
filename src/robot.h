#ifndef DEF_ROBOT
#define DEF_ROBOT

#include "position.h"

typedef struct {
    pos position;
    float vitesse;
    float degat;
    int nb_missiles;
    char mort; /*Boolean*/
    char *script;
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
void miseAJourRobot(robot *r, pos position, float vitesse);
void degats(robot *r, float d);
void init(robot *r, pos position);
void destruction(robot *r);

#endif
