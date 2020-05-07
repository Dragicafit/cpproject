#include "main.h"

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "arene.h"
#include "constantes.h"
#include "missile.h"
#include "parser.h"
#include "plateau.h"
#include "robot.h"

#define DELAY 33
#define MSIZE_H (3 * (COLS / 4))

int main(int argc, char *argv[]) {
  if (argc != ROBOT_MAX + 1) return -1;

  robot *r1 = init(1.0, 1.0, argv[1], 0);

  robot *r2 = init(10000.0, 1.0, argv[2], 1);

  robot *r3 = init(1.0, 10000.0, argv[3], 2);

  robot *r4 = init(10000.0, 10000.0, argv[4], 3);

  arene *plat = malloc(sizeof(arene));

  plateau(r1, r2, r3, r4, plat);
}