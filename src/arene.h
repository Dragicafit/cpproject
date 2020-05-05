#ifndef DEF_ARENE
#define DEF_ARENE

#include "missile.h"
#include "robot.h"

typedef struct {
  robot *l_robot[ROBOT_MAX];
  missile *l_missile[ROBOT_MAX * MISSILES_MAX];
  int nb_missile;
} arene;

void cycle(arene *a);
void collisionRtoR(robot *r1, robot *r2);
void collisionRtoW(robot *r);
void collisionRtoE(robot *r, missile *m);
void collisionRtoM(arene *a, robot *r, missile *m);
void collisionMtoW(arene *a, missile *m);
void exploseRobots(arene *a, missile *m);

#endif
