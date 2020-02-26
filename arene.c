#include <arene.h>
#include <stdio.h>

void cycle(arene* a) {
    for each (missile* m in a->l_missile) {
        miseAjour(m);
        explose(m);
    }
    for each (robot* r in a->l_robot) {
        nextInstruction(r);
        miseAJour(r);
    }
}

void collisionRtoR(robot* r1, robot* r2) {
    if (abs(r1->position.x - r2->position.x) < SIZE_X && abs(r1->position.y - r2->position.y) < SIZE_Y) {
        degats(r1, COLLISION);
        degats(r2, COLLISION);
    }
}

void collisionRtoW(robot* r) {
    if (X - r1->position.x < SIZE_X || r1->position.x < SIZE_X || Y - r2->position.y < SIZE_Y || r1->position.y < SIZE_Y)
        degats(r1, COLLISION);
}

void collisionRtoE(robot* r, missile* m) {
    float distance = sqrt((r->position.x - m->position.x) + (r->position.y - m->position.y));
    if (distance <= DIST_50)
        degats(r, DEGAT_50);
    else if (distance <= DIST_200)
        degats(r, DEGAT_200);
    else if (distance <= DIST_400)
        degats(r, DEGAT_400);
}

void collisionRtoM(arene* a, robot* r, missile* m) {
    if (abs(r->position.x - m->position.x) < SIZE_X && abs(r->position.Y - m->position.Y) < SIZE_Y)
        exploseRobots(a, m);
}

void exploseRobots(arene* a, missile* m) {
    for each (robot* r in a->l_robot) {
        collisionRtoE(r, m);
    }
    explose(m);
}