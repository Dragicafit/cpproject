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

  arene *plat = initArene(&argv[1]);

  plateau(plat);
}