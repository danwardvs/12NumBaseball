/**
 * MENU
 * A.D.S. Games
 * 06/05/2017
**/
#ifndef MENU_H
#define MENU_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>
#include <vector>

#include "input/keyListener.h"
#include "input/mouseListener.h"
#include "input/joystickListener.h"

#include "state.h"
#include "helpers/random.h"
#include "XML.h"

#include "Cell.h"
#include "font/Font.h"

// Menu
class menu : public state {
  public:
    menu();
    virtual ~menu();

    void update();
    void draw();

  private:

    void generate_cells();

    XML xml_handler;

    int input_step = 0;
    int batter_number = 1;
    int pitcher_number = 1;
    int result_number = 1;
    int extra_number[9] = {7, 15, 1, 2, 19, 7};
    int groundout_type;
    int steal_throw_number;
    int total_numbers_generated = 0;

    std::string result[9];

    Font calibri_bold;
    Font calibri;
    std::vector<Cell*> gameCells;

};

#endif // MENU_H
