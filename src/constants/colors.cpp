#include "constants/colors.h"

#include <allegro5/allegro.h>

namespace colors {
  ALLEGRO_COLOR BLACK = ALLEGRO_COLOR();
  ALLEGRO_COLOR WHITE = ALLEGRO_COLOR();
  ALLEGRO_COLOR RED = ALLEGRO_COLOR();
  ALLEGRO_COLOR GREEN = ALLEGRO_COLOR();
  ALLEGRO_COLOR BLUE = ALLEGRO_COLOR();
  ALLEGRO_COLOR TRANSPARENT = ALLEGRO_COLOR();
  ALLEGRO_COLOR YELLOW = ALLEGRO_COLOR();
  ALLEGRO_COLOR GROSS_YELLOW = ALLEGRO_COLOR();

  void init() {
    BLACK = al_map_rgb(0, 0, 0);
    WHITE = al_map_rgb(255, 255, 255);
    RED = al_map_rgb(255, 0, 0);
    GREEN = al_map_rgb(0, 255, 0);
    BLUE = al_map_rgb(0, 0, 255);
    TRANSPARENT = al_map_rgba(0, 0, 0, 0);
    YELLOW = al_map_rgb(255, 255, 0);
    GROSS_YELLOW = al_map_rgb(100, 100, 0);
  }
}
