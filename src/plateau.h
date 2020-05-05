#define DELAY 33
#define MSIZE_H (3 * (COLS / 4))

#include <ncurses.h>

#include "arene.h"
#include "constantes.h"
#include "robot.h"

void add_stats(robot *r1, robot *r2, robot *r3, robot *r4, WINDOW *stats);
void placer_robot(robot *r1, robot *r2, robot *r3, robot *r4, WINDOW *vue);
void position_missile(arene *plateau, WINDOW *vue);
void robot_mur(robot *r, char c, float echy, float echx, WINDOW *vue);
