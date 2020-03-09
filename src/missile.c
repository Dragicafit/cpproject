#include "missile.h"
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "robot.h"

void initMissile(missile *m, robot *parent) {
    m->parent = parent;
    m->position = parent->position;
}

int explose(missile *m) {
    m->parent->nb_missiles-=1;
    free(m);
}

void miseAJourMissile(missile *m, pos position) {
    m->position.x = position.x;
    m->position.y = position.y;
}
