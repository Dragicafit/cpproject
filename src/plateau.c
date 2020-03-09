#include "constantes.h"
#include <ncurses.h>
#include "main.h"
#include "robot.h"
#include "plateau.h"

void plateau(robot *r1, robot *r2, robot *r3, robot *r4){
    WINDOW *boite;
    initscr();//Initialise la structure WINDOW et autres paramètres
    boite = subwin(stdscr, LINES, COLS,0,0);//On créer une fenetre de LINES lignes et de COL collonnes a partir de la pos (0,0)

    placer_robot(r1,r2,r3,r4,boite);
/* Faire bouger un element
	//Robot
	for (size_t i = 1; i < 100; i++)
	{
		wclear(boite);
		box(boite, ACS_VLINE, ACS_HLINE); // ACS_VLINE et ACS_HLINE sont des constantes qui génèrent des bordures par défaut
		mvwaddch(boite,1,i,'>');
		wrefresh(boite);
		napms(DELAY);
	}
*/
    getch();// On attend que l'utilisateur appui sur une touche pour quitter
    endwin();// Restaure les paramètres par défaut du terminal
    free(boite);
}

//Fonction permettant de placer les robot dans l'arene
void placer_robot(robot *r1,robot *r2,robot *r3,robot *r4, WINDOW *boite){
	wclear(boite);
	box(boite, ACS_VLINE, ACS_HLINE); // ACS_VLINE et ACS_HLINE sont des constantes qui génèrent des bordures par défaut
	int echx = LINES / 10000;
	int echy = COLS / 10000;
	mvwaddch(boite,r1->position.x*echx, r1->position.y*echy ,"R1");
	mvwaddch(boite,r2->position.x*echx , r2->position.y*echy ,"R2");
	mvwaddch(boite,r3->position.x*echx , r3->position.y*echy ,"R3");
	mvwaddch(boite,r4->position.x*echx , r4->position.y*echy ,"R4");
	wrefresh(boite);
	napms(DELAY);
}