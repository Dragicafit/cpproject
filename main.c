#include "main.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "robot.h"
#include "missile.h"
#include "arene.h"
#include "plateau.h"

int main(int argc, char* argv[]){
	robot *r1;
	pos p1 = {1,1};
	init(r1, p1);

	robot *r2;
	pos p2 = {X-1,1};
	init(r2, p2);

	robot *r3;
	pos p3 = {1,Y-1};
	init(r3, p3);

	robot *r4;
	pos p4 = {X-1,Y-1};
	init(r4, p4);

	plateau(r1,r2,r3,r4);
	return 0;
}