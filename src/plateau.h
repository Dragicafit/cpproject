#define DELAY 33
#define MSIZE_H (3 * (COLS / 4))

#include <ncurses.h>

#include "arene.h"
#include "constantes.h"
#include "robot.h"

void plateau(arene *plateau);
void add_stats(arene *plateau, WINDOW *stats);
void placer_robot(arene *plateau, WINDOW *vue);
void position_missile(arene *plateau, WINDOW *vue);
void robot_mur(robot *r, char c, float echy, float echx, WINDOW *vue);
