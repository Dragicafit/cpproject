#ifndef DEF_MISSILE
#define DEF_MISSILE

#include "position.h"
#include "robot.h"

typedef struct {
  robot *parent;
  pos position;
  int distance;
  int distanceExplosion;
  int angle;
} missile;

void initMissile(missile *m, robot *parent, int distance, int angle);
void miseAJourMissile(missile *m);
int explose(missile *m);

#endif
