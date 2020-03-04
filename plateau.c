#include <ncurses.h>
#include <robot.h>

#define DELAY 33

void plateau(robot r1, robot r2, robot r3, robot r4){
    WINDOW *boite;
    initscr();//Initialise la structure WINDOW et autres paramètres
    boite = subwin(stdscr, LINES, COLS,0,0);//On créer une fenetre de LINES lignes et de COL collonnes a partir de la pos (0,0)

	//Robot
	for (size_t i = 1; i < 100; i++)
	{
		wclear(boite);
		box(boite, ACS_VLINE, ACS_HLINE); // ACS_VLINE et ACS_HLINE sont des constantes qui génèrent des bordures par défaut
		mvwaddch(boite,1,i,'>');
		wrefresh(boite);
		napms(DELAY);
	}


    getch();// On attend que l'utilisateur appui sur une touche pour quitter
    endwin();// Restaure les paramètres par défaut du terminal
    free(boite);
}