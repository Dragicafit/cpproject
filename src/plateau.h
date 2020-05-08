#ifndef DEF_PLATEAU
#define DEF_PLATEAU

#define DELAY 33
#define MSIZE_H (3 * (COLS / 4))

#include <ncurses.h>

#include "arene.h"
#include "constantes.h"
#include "robot.h"

static const char robot_visu[4] = {'A', 'B', 'C', 'D'};

WINDOW *initVue();
WINDOW *initStats();
void startColor();
void cycle_plateau(WINDOW *vue, WINDOW *stats, arene *plateau);
void end_vue();
void plateau(arene *plateau);
void add_stats(arene *plateau, WINDOW *stats);
void placer_robot(arene *plateau, WINDOW *vue);
void position_missile(arene *plateau, WINDOW *vue);
void robot_mur(robot *r, char c, float echy, float echx, WINDOW *vue);

#endif