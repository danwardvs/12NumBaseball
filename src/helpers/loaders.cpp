#include "helpers/loaders.h"

#include <allegro5/allegro_native_dialog.h>

/** \brief Load bitmap safely, with check for non existant
 *
 * \param file std::string, path to file
 * \return ALLEGRO_BITMAP*, image loaded
 *
 */
ALLEGRO_BITMAP* helpers::loaders::load_bitmap_ex(std::string file) {
  ALLEGRO_BITMAP* temp_image = nullptr;

  if(!(temp_image = al_load_bitmap(file.c_str()))) {
    abort_on_error(std::string("There was an error loading " + file + "... \nSorry..."), "Loading Error");
  }

  return temp_image;
}


/** \brief A function to streamline error reporting in file loading
 *
 * \param message std::string
 * \param title std::string
 * \return void
 *
 */
void helpers::loaders::abort_on_error(std::string message, std::string title) {
  al_show_native_message_box(nullptr, "Error", title.c_str(), message.c_str(), nullptr, ALLEGRO_MESSAGEBOX_ERROR);
  exit(-1);
}
