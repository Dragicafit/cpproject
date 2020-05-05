#include "plateau.h"

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "constantes.h"
#include "main.h"
#include "plateau.h"
#include "robot.h"

void plateau(robot *r1, robot *r2, robot *r3, robot *r4, arene *plateau) {
  WINDOW *vue, *stats;
  initscr();
  vue = subwin(stdscr, LINES, MSIZE_H, 0, 0);
  stats = subwin(stdscr, LINES, COLS / 4, 0, MSIZE_H);
  box(vue, ACS_VLINE, ACS_HLINE);  // ACS_VLINE et ACS_HLINE sont des constantes
                                   // qui génèrent des bordures par défaut
  box(stats, ACS_VLINE,
      ACS_HLINE);  // ACS_VLINE et ACS_HLINE sont des constantes qui génèrent
                   // des bordures par défaut

  add_stats(r1, r2, r3, r4, stats);
  placer_robot(r1, r2, r3, r4, vue);
  position_missile(plateau, vue);
  getch();
  endwin();
  free(vue);
}

void add_stats(robot *r1, robot *r2, robot *r3, robot *r4, WINDOW *stats) {
  mvwaddch(stats, 1, 1, 'A');
  mvwprintw(stats, 2, 1, "%.5f, %.5f", r1->position.x, r1->position.y);
  mvwaddch(stats, 3, 1, 'B');
  mvwprintw(stats, 4, 1, "%.5f, %.5f", r2->position.x, r2->position.y);
  mvwaddch(stats, 5, 1, 'C');
  mvwprintw(stats, 6, 1, "%.5f, %.5f", r3->position.x, r3->position.y);
  mvwaddch(stats, 7, 1, 'D');
  mvwprintw(stats, 8, 1, "%.5f, %.5f", r4->position.x, r4->position.y);
  wrefresh(stats);
}

void placer_robot(robot *r1, robot *r2, robot *r3, robot *r4, WINDOW *vue) {
  float echy = (((float)LINES) / 10000.0);
  float echx = ((float)MSIZE_H / 10000.0);
  robot_mur(r1, 'A', echx, echy, vue);
  robot_mur(r2, 'B', echx, echy, vue);
  robot_mur(r3, 'C', echx, echy, vue);
  robot_mur(r4, 'D', echx, echy, vue);
}

void position_missile(arene *plateau, WINDOW *vue) {
  float echy = (((float)LINES) / 10000.0);
  float echx = ((float)MSIZE_H / 10000.0);
  if (plateau->nb_missile > 0) {
    for (int i = 0; i < plateau->nb_missile; i++) {
      missile *m = plateau->l_missile[i];
      float x = m->position.x * echx;
      float y = m->position.y * echy;
      mvwaddch(vue, y, x, '.');
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
