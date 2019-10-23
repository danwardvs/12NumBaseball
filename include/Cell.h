#ifndef CELL_H
#define CELL_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

#include <string>

#include "tools.h"
#include "font/Font.h"
#include "globals.h"

class Cell {
  public:
    // Ctor / Dtor
    Cell();
    Cell(int, int, int, int, ALLEGRO_COLOR, ALLEGRO_COLOR, ALLEGRO_COLOR, Font, int, std::string);
    virtual ~Cell() {};

    // Draw cell to screen
    void draw();

    // Text
    void setText(std::string newText) ;

    // Position
    void setX(int newX);
    void setY(int newY);

    // Dimensions
    void setWidth(int newWidth);
    void setHeight(int newHeight);

    // Formatting
    void setOutlineColour(ALLEGRO_COLOR n);
    void setCellColour(ALLEGRO_COLOR i);
    void setFontColour(ALLEGRO_COLOR g);
    void setLineThickness(int nt);

  private:
    int width;
    int height;
    int x;
    int y;
    int x_padding = 5;
    int y_padding = 5;
    int justification = LEFT;
    int line_thickness = 1;
    std::string text;

    Font font;

    ALLEGRO_COLOR outline_colour;
    ALLEGRO_COLOR cell_colour;
    ALLEGRO_COLOR font_colour;
};

#endif // CELL_H
