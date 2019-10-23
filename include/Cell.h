#ifndef CELL_H
#define CELL_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

#include <string>

#include "font/Font.h"
#include "constants/justifications.h"

class Cell {
  public:
    // Ctor / Dtor
    Cell();
    Cell(int x, int y, int newWidth, int newHeight, ALLEGRO_COLOR outlineColor, ALLEGRO_COLOR cellColor,
           ALLEGRO_COLOR fontColor, Font font, int justification, std::string text);

    // Draw cell to screen
    void draw();

    // Text
    void setText(std::string text) ;

    // Position
    void setX(int x);
    void setY(int y);

    // Dimensions
    void setWidth(int width);
    void setHeight(int height);

    // Formatting
    void setOutlineColour(ALLEGRO_COLOR color);
    void setCellColour(ALLEGRO_COLOR color);
    void setFontColour(ALLEGRO_COLOR color);
    void setLineThickness(int thickness);

  private:
    // Position
    int x, y;

    // Dimensions
    int width, height;

    // Padding
    int x_padding = 5;
    int y_padding = 5;

    // Justification
    int justification = justification::LEFT;

    // Line thickness
    int line_thickness = 1;

    // Text
    std::string text;

    // Font
    Font font;

    // Colors
    ALLEGRO_COLOR outline_colour;
    ALLEGRO_COLOR cell_colour;
    ALLEGRO_COLOR font_colour;
};

#endif
