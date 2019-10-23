/*
 * Loaders
 * Common safe loaders used in project
 * Allan Legemaate
 * 22/10/2019
 */
#include <string>

#include <allegro5/allegro.h>

namespace helpers {
  namespace loaders {
    ALLEGRO_BITMAP* load_bitmap_ex(std::string file);

    void abort_on_error(std::string message, std::string title);
  }
}
