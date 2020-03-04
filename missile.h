#ifndef DEF_MISSILE
#define DEF_MISSILE

#define SPEED 500
#define DISTANCE_MAX 7000
#define DIST_400 400
#define DIST_200 200
#define DIST_50 50
#define DEGAT_400 0.03
#define DEGAT_200 0.05
#define DEGAT_50 0.1

typedef struct {
    robot *parent;
    pos position;
    pos position_depart;
} missile;

void misaAJour(missile *m);
int explose(missile *m);

#endif
