#include "constantes.h"
#include "main.h"
#include "robot.h"
#include "arene.h"
#include "plateau.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>



#define DELAY 33
#define MSIZE_H (3*(COLS/4))

int main(int argc, char* argv[]) {
    robot *r1 = malloc(sizeof(robot));
    pos p1 = {1.0,1.0};
    init(r1,p1);

    robot *r2 = malloc(sizeof(robot));
    pos p2 = {10000.0,1.0};
    init(r2,p2);

    robot *r3 = malloc(sizeof(robot));
    pos p3 = {1.0,10000.0};
    init(r3,p3);

    robot *r4 = malloc(sizeof(robot));
    pos p4 = {10000.0,10000.0};
    init(r4,p4);

    arene *plat = malloc(sizeof(arene));

    plateau(r1,r2,r3,r4,plat);

}