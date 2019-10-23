/*
 * Colors
 * Constant file to store colors for use in program
 * Allan Legemaate
 * 22/10/2019
 */

#ifndef COLORS_H
#define COLORS_H

#include <allegro5/allegro.h>

namespace colors {
  extern ALLEGRO_COLOR BLACK;
  extern ALLEGRO_COLOR WHITE;
  extern ALLEGRO_COLOR RED;
  extern ALLEGRO_COLOR GREEN;
  extern ALLEGRO_COLOR BLUE;
  extern ALLEGRO_COLOR TRANSPARENT;
  extern ALLEGRO_COLOR YELLOW;
  extern ALLEGRO_COLOR GROSS_YELLOW;

  extern void init();
}

#endif
