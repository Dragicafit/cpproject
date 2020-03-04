#ifndef DEF_MISSILE
#define DEF_MISSILE

typedef struct {
    robot *parent;
    pos position;
    pos position_depart;
} missile;

void initMissile(missile *m, robot *parent);
void misaAJourMissile(missile *m, pos position);
int explose(missile *m);

#endif
