#include "robot.h"
#include "missile.h"

#define X 10000
#define Y 10000
#define ROBOT_MAX 4

typedef struct
{
    robot l_robot[ROBOT_MAX];
    missile l_missile[ROBOT_MAX * MISSILES_MAX];
} arene;

void collisionRtoR(robot r1, robot r2);
void collisionRtoW(robot r);
void collisionRtoM(robot r, missile m);
//void collision(missile m1, missile m2);
void cycle();


