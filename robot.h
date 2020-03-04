#ifndef DEF_ROBOT
#define DEF_ROBOT

#define SIZE_X 10
#define SIZE_Y 10
#define VITESSE_MAX 10
#define MISSILES_MAX 2
#define COLLISION 0.02

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
void miseAJour(robot *r);
void degats(robot *r, float d);
void init(robot *r, pos position);
void destruction(robot *r);

#endif
