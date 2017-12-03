#ifndef CELL_H
#define CELL_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

#include <string>
#include <tools.h>

class Cell
{
  public:
    Cell();
    virtual ~Cell();
    void draw();

  protected:

    int width;
    int height;
    int x;
    int y;

    ALLEGRO_COLOR outline_colour;
    ALLEGRO_COLOR cell_colour;



  private:
};

#endif // CELL_H
