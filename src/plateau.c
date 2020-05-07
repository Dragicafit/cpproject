#include "plateau.h"

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "constantes.h"
#include "main.h"
#include "plateau.h"
#include "robot.h"

void plateau(arene *plateau) {
  WINDOW *vue, *stats;
  initscr();
  vue = subwin(stdscr, LINES, MSIZE_H, 0, 0);
  stats = subwin(stdscr, LINES, COLS / 4, 0, MSIZE_H);

  if (has_colors() == FALSE) {
    endwin();
    printf("Your terminal does not support color\n");
    exit(1);
  }
  // Start color
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_CYAN, COLOR_BLACK);
  init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);

  while (1) {
    box(vue, ACS_VLINE,
        ACS_HLINE);  // ACS_VLINE et ACS_HLINE sont des constantes
                     // qui génèrent des bordures par défaut
    box(stats, ACS_VLINE,
        ACS_HLINE);  // ACS_VLINE et ACS_HLINE sont des constantes qui génèrent
                     // des bordures par défaut
    add_stats(plateau, stats);
    placer_robot(plateau, vue);
    position_missile(plateau, vue);
    wattron(vue, COLOR_PAIR(1));
    wattroff(vue, COLOR_PAIR(1));
    sleep(1);
    wclear(vue);
    wclear(stats);
  }
  getch();
  endwin();
  free(vue);
}

void add_stats(arene *plateau, WINDOW *stats) {
  wattron(stats, COLOR_PAIR(1));
  mvwaddch(stats, 1, 1, 'A');
  wattroff(stats, COLOR_PAIR(1));
  mvwprintw(stats, 2, 1, "%.5f, %.5f", plateau->l_robot[0]->position.x,
            plateau->l_robot[0]->position.y);
  mvwprintw(stats, 3, 1, "Missiles lancé(s): %i",
            plateau->l_robot[0]->nb_missiles);

  wattron(stats, COLOR_PAIR(2));
  mvwaddch(stats, 6, 1, 'B');
  wattroff(stats, COLOR_PAIR(2));
  mvwprintw(stats, 7, 1, "%.5f, %.5f", plateau->l_robot[1]->position.x,
            plateau->l_robot[1]->position.y);
  mvwprintw(stats, 8, 1, "Missiles lancé(s): %i",
            plateau->l_robot[1]->nb_missiles);

  wattron(stats, COLOR_PAIR(3));
  mvwaddch(stats, 11, 1, 'C');
  wattroff(stats, COLOR_PAIR(3));
  mvwprintw(stats, 12, 1, "%.5f, %.5f", plateau->l_robot[2]->position.x,
            plateau->l_robot[2]->position.y);
  mvwprintw(stats, 13, 1, "Missiles lancé(s): %i",
            plateau->l_robot[2]->nb_missiles);

  wattron(stats, COLOR_PAIR(4));
  mvwaddch(stats, 16, 1, 'D');
  wattroff(stats, COLOR_PAIR(4));
  mvwprintw(stats, 17, 1, "%.5f, %.5f", plateau->l_robot[3]->position.x,
            plateau->l_robot[3]->position.y);
  mvwprintw(stats, 18, 1, "Missiles lancé(s): %i",
            plateau->l_robot[3]->nb_missiles);

  wrefresh(stats);
}

void placer_robot(arene *plateau, WINDOW *vue) {
  float echy = (((float)LINES) / 10000.0);
  float echx = ((float)MSIZE_H / 10000.0);

  wattron(vue, COLOR_PAIR(1));
  robot_mur(plateau->l_robot[0], 'A', echx, echy, vue);
  wattroff(vue, COLOR_PAIR(1));
  wattron(vue, COLOR_PAIR(2));
  robot_mur(plateau->l_robot[1], 'B', echx, echy, vue);
  wattroff(vue, COLOR_PAIR(2));
  wattron(vue, COLOR_PAIR(3));
  robot_mur(plateau->l_robot[2], 'C', echx, echy, vue);
  wattroff(vue, COLOR_PAIR(3));
  wattron(vue, COLOR_PAIR(4));
  robot_mur(plateau->l_robot[3], 'D', echx, echy, vue);
  wattroff(vue, COLOR_PAIR(4));
}

void position_missile(arene *plateau, WINDOW *vue) {
  float echy = (((float)LINES) / 10000.0);
  float echx = ((float)MSIZE_H / 10000.0);
  if (plateau->nb_missile > 0) {
    for (int i = 0; i < plateau->nb_missile; i++) {
      missile *m = plateau->l_missile[i];
      float x = m->position.x * echx;
      float y = m->position.y * echy;
      if (m->parent == plateau->l_robot[0]) {
        wattron(vue, COLOR_PAIR(4));
        mvwaddch(vue, y, x, '.');
        wattroff(vue, COLOR_PAIR(4));
      } else if (m->parent == plateau->l_robot[1]) {
        wattron(vue, COLOR_PAIR(4));
        mvwaddch(vue, y, x, '.');
        wattroff(vue, COLOR_PAIR(4));
      } else if (m->parent == plateau->l_robot[2]) {
        wattron(vue, COLOR_PAIR(4));
        mvwaddch(vue, y, x, '.');
        wattroff(vue, COLOR_PAIR(4));
      } else {
        wattron(vue, COLOR_PAIR(4));
        mvwaddch(vue, y, x, '.');
        wattroff(vue, COLOR_PAIR(4));
      }
      wrefresh(vue);
    }
  }
}

void robot_mur(robot *r, char c, float echx, float echy, WINDOW *vue) {
  float x = r->position.x * echx;
  float y = r->position.y * echy;
  if (x < 1) {
    x = 1;
  }
  if (y < 1) {
    y = 1;
  }
  if (x > (MSIZE_H - 2.0)) {
    x = MSIZE_H - 2.0;
  }
  if (y > (LINES - 2.0)) {
    y = LINES - 2.0;
  }
  mvwaddch(vue, y, x, c);
  wrefresh(vue);
}
