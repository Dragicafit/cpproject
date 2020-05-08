#include "plateau.h"

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "constantes.h"
#include "expression.h"
#include "main.h"
#include "plateau.h"
#include "robot.h"

WINDOW *initVue() {
  WINDOW *vue;
  initscr();
  vue = subwin(stdscr, LINES, MSIZE_H, 0, 0);
  return vue;
}

WINDOW *initStats() {
  WINDOW *stats;
  initscr();
  stats = subwin(stdscr, LINES, COLS / 4, 0, MSIZE_H);
  return stats;
}

void cycle_plateau(WINDOW *vue, WINDOW *stats, arene *plateau) {
  // Pour gérer la modification de la taille du terminal
  box(vue, ACS_VLINE,
      ACS_HLINE);  // ACS_VLINE et ACS_HLINE sont des constantes
                   // qui génèrent des bordures par défaut
  box(stats, ACS_VLINE,
      ACS_HLINE);  // ACS_VLINE et ACS_HLINE sont des constantes qui génèrent
                   // des bordures par défaut
  // Cycle d'affichage
  add_stats(plateau, stats);
  placer_robot(plateau, vue);
  position_missile(plateau, vue);
  wclear(vue);
  wclear(stats);
}

void startColor() {
  if (has_colors() == FALSE) {
    endwin();
    printf("Your terminal does not support color\n");
    exit(1);
  }
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_CYAN, COLOR_BLACK);
  init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void end_vue(WINDOW *vue, WINDOW *stats) {
  getch();
  endwin();
  free(vue);
  free(stats);
}

void plateau(arene *plateau) {
  WINDOW *vue = initVue();
  WINDOW *stats = initStats();

  // Start color
  startColor();

  while (1) {
    Line();
    cycle(plateau);
    cycle_plateau(vue, stats, plateau);
    sleep(1);
  }
  end_vue(vue, stats);
}

void add_stats(arene *plateau, WINDOW *stats) {
  int couleur = 1;
  int pos = 1;
  for (int i = 0; i < ROBOT_MAX; i++) {
    wattron(stats, COLOR_PAIR(couleur));
    mvwaddch(stats, pos, 1, robot_visu[i]);
    wattroff(stats, COLOR_PAIR(couleur));
    couleur++;
    pos++;
    mvwprintw(stats, pos, 1, "%.5f, %.5f", plateau->l_robot[i]->position.x,
              plateau->l_robot[i]->position.y);
    pos++;
    mvwprintw(stats, pos, 1, "Missiles en cours: %i",
              plateau->l_robot[i]->nb_missiles);
    pos += 3;
  }
  wrefresh(stats);
}

void placer_robot(arene *plateau, WINDOW *vue) {
  float echy = (((float)LINES) / 10000.0);
  float echx = ((float)MSIZE_H / 10000.0);
  int couleur = 1;

  for (int i = 0; i < ROBOT_MAX; i++) {
    wattron(vue, COLOR_PAIR(couleur));
    robot_mur(plateau->l_robot[i], robot_visu[i], echx, echy, vue);
    wattroff(vue, COLOR_PAIR(couleur));
    couleur++;
  }
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
        wattron(vue, COLOR_PAIR(1));
        mvwaddch(vue, y, x, '.');
        wattroff(vue, COLOR_PAIR(1));
      } else if (m->parent == plateau->l_robot[1]) {
        wattron(vue, COLOR_PAIR(2));
        mvwaddch(vue, y, x, '.');
        wattroff(vue, COLOR_PAIR(2));
      } else if (m->parent == plateau->l_robot[2]) {
        wattron(vue, COLOR_PAIR(3));
        mvwaddch(vue, y, x, '.');
        wattroff(vue, COLOR_PAIR(3));
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
