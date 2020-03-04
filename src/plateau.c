#include <ncurses.h>
#include <stdlib.h>

void plateau(){
    WINDOW *boite;
    initscr();//Initialise la structure WINDOW et autres paramètres
    boite = subwin(stdscr, 10, 10, LINES / 2, COLS /2);
    box(boite, ACS_VLINE, ACS_HLINE); // ACS_VLINE et ACS_HLINE sont des constantes qui génèrent des bordures par défaut
    refresh();

    getch();// On attend que l'utilisateur appui sur une touche pour quitter
    endwin();// Restaure les paramètres par défaut du terminal

    free(boite);
}