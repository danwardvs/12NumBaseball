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



#include "keyListener.h"
#include "mouseListener.h"
#include "joystickListener.h"
#include "tools.h"
#include "state.h"
#include "globals.h"
#include "RandNum.h"
#include "XML.h"

#include "Cell.h"
#include "Font.h"

// Menu
class menu : public state{
  public:
    menu();
    virtual ~menu();

    void update();
    void draw();

  private:

    void generate_cells();

    XML xml_handler;

    int input_step=0;
    int batter_number=1;
    int pitcher_number=1;
    int result_number=1;

    std::string result[9];

    Font calibri_bold;
    std::vector<Cell*> gameCells;

};

#endif // MENU_H
