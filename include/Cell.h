/*
 * Cell
 * Single cell display
 * Danny Vanstemp and  Allan Legemaate
 * 25/10/2019
 */
#ifndef CELL_H
#define CELL_H

#include <string>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>

#include "font/Font.h"
#include "constants/justifications.h"

class Cell {
  public:
    // Constructor
    explicit Cell(const std::string & id);

    // Get id
    std::string getId() const;

    // LAYOUT
    // Position
    void setX(int x, const std::string& positioning = "absolute");
    void setY(int y, const std::string& positioning = "absolute");
    void setPadding(int x, int y);

    // Dimensions
    void setWidth(int width, const std::string& positioning = "absolute");
    void setHeight(int height, const std::string& positioning = "absolute");

    // FORMATTING
    // Border
    void setBorderColor(ALLEGRO_COLOR color);
    void setBorderColor(const std::string& color);
    void setBorderWidth(int thickness);

    // Cell
    void setCellColor(ALLEGRO_COLOR color);
    void setCellColor(const std::string& color);

    // Font
    void setFontColor(ALLEGRO_COLOR color);
    void setFontColor(const std::string& color);
    void setJustification(const std::string& align);

    // CONTENT
    // Text
    void setText(const std::string& text);
    void setText(int text);

    // Draw cell to screen
    void draw();

  private:
    // Unique id
    std::string id;

    // LAYOUT
    // Position
    int x, y;

    // Dimensions
    int width, height;

    // Padding
    int xPadding;
    int yPadding;

    // FORMATTING
    // Border
    int lineThickness;
    ALLEGRO_COLOR outlineColour;

    // Cell
    ALLEGRO_COLOR cellColour;

    // Font
    Font font;
    static Font defaultFont;
    ALLEGRO_COLOR fontColour;
    int justification = justification::LEFT;

    // CONTENT
    // Text
    std::string text;

};

#endif
