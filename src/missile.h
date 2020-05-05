#ifndef DEF_MISSILE
#define DEF_MISSILE

#include "position.h"
#include "robot.h"

typedef struct {
    robot *parent;
    pos position;
    pos position_depart;
} missile;

void initMissile(missile *m, robot *parent);
void miseAJourMissile(missile *m, pos position);
int explose(missile *m);

#endif
