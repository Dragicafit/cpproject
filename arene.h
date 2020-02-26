#include "robot.h"
#include "missile.h"

#define X 10000
#define Y 10000
#define ROBOT_MAX 4

typedef struct
{
    robot* l_robot[ROBOT_MAX];
    missile* l_missile[ROBOT_MAX * MISSILES_MAX];
} arene;

void collisionRtoR(robot* r1, robot* r2);
void collisionRtoW(robot* r);
void collisionRtoE(robot* r, missile* m);
void collisionRtoM(arene* a, robot* r, missile* m);
void cycle(arene* a);
void exploseRobots(arene* a, missile* m);


