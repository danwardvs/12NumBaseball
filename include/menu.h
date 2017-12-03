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

#include "keyListener.h"
#include "joystickListener.h"
#include "tools.h"
#include "state.h"

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

    Cell myNiceCell;
    Font myFont("font/fantasque.ttf");

};

#endif // MENU_H
