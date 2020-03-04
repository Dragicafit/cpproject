#include "arene.h"
#include <stdio.h>
#include "missile.h"
#include "robot.h"

void cycle(arene *a) {
    for (int i = 0; i < sizeof(a->l_missile) / sizeof(missile); i++)
        miseAJour(a->l_missile[i]);
    for (int i = 0; i < sizeof(a->l_robot) / sizeof(robot); i++)
        miseAJour(a->l_robot[i]);
}

void collisionRtoR(robot *r1, robot *r2) {
    if (abs(r1->position.x - r2->position.x) < SIZE_X &&
        abs(r1->position.y - r2->position.y) < SIZE_Y) {
        degats(r1, COLLISION);
        degats(r2, COLLISION);
    }
}

void collisionRtoW(robot *r) {
    if (X - r->position.x < SIZE_X || r->position.x < SIZE_X ||
        Y - r->position.y < SIZE_Y || r->position.y < SIZE_Y)
        degats(r, COLLISION);
}

void collisionRtoE(robot *r, missile *m) {
    float distance =
        sqrt((r->position.x - m->position.x) + (r->position.y - m->position.y));
    if (distance <= DIST_50)
        degats(r, DEGAT_50);
    else if (distance <= DIST_200)
        degats(r, DEGAT_200);
    else if (distance <= DIST_400)
        degats(r, DEGAT_400);
}

void collisionRtoM(arene *a, robot *r, missile *m) {
    if (abs(r->position.x - m->position.x) < SIZE_X &&
        abs(r->position.y - m->position.y) < SIZE_Y)
        exploseRobots(a, m);
}

void exploseRobots(arene *a, missile *m) {
    for (int i = 0; i < sizeof(a->l_robot) / sizeof(robot); i++)
        collisionRtoE(a->l_robot[i], m);
    explose(m);
}
