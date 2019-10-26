/*
 * Colour
 * Common colour functions
 * Allan Legemaate
 * 25/10/2019
 */
#ifndef HELPERS_COLOR_H
#define HELPERS_COLOR_H

#include <allegro5/allegro5.h>
#include <string>

namespace helpers {
  namespace color {
    ALLEGRO_COLOR hexToAllegro(const std::string& color);
  }
}

#endif  // HELPERS_COLOR_H
