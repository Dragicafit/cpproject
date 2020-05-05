#include "constantes.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "main.h"
#include "robot.h"
#include "plateau.h"

void plateau(robot *r1, robot *r2, robot *r3, robot *r4){
    WINDOW *boite;
    initscr();//Initialise la structure WINDOW et autres paramètres
    boite = subwin(stdscr, LINES, COLS,0,0);//On créer une fenetre de LINES lignes et de COL collonnes a partir de la pos (0,0)
	start_color();
	while(1){
    	placer_robot(r1,r2,r3,r4,boite);
	}
    free(boite);
}

//Fonction permettant de placer les robot dans l'arene
void placer_robot(robot *r1,robot *r2,robot *r3,robot *r4, WINDOW *boite){
	wclear(boite);
	box(boite, ACS_VLINE, ACS_HLINE); // ACS_VLINE et ACS_HLINE sont des constantes qui génèrent des bordures par défaut
	float echy = (((float)LINES) / 10000);
	float echx = (((float)COLS) / 10000);
	robot_mur(r1, echx,echy, "A", boite);
	robot_mur(r2, echx,echy, "B", boite);
	robot_mur(r3, echx,echy, "C", boite);
	robot_mur(r4, echx,echy, "D", boite);
	wrefresh(boite);
	napms(DELAY);
}

void robot_mur(robot *r, float echx, float echy, char *c, WINDOW *boite){
	float x = r->position.x * echx;
	float y = r -> position.y * echy;
	if(x < 1){
		x = 1;
	}
	if(y < 1){
		y = 1;
	}
	if(x > (COLS -2)){
		x = COLS -2;
	}
	if(y > (LINES -2)){
		y = LINES -2;
	}
	init_pair(1,COLOR_BLUE,COLOR_BLACK);
	mvwprintw(boite,y,x,c);
}
