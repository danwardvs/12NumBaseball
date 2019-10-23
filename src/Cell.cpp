#include "Cell.h"
#include "constants/justifications.h"

Cell::Cell() :
  Cell(100, 100, 100, 50, al_map_rgba(0, 0, 0, 255), al_map_rgba(123, 456, 789, 255), al_map_rgba(0, 0, 0, 255), Font(), justification::LEFT, "") {

}

Cell::Cell(int x, int y, int newWidth, int newHeight, ALLEGRO_COLOR outlineColor, ALLEGRO_COLOR cellColor,
           ALLEGRO_COLOR fontColor, Font font, int justification, std::string text) {
  this -> x = x;
  this -> y = y;
  this -> width = newWidth;
  this -> height = newHeight;
  this -> text = text;
  this -> outline_colour = outlineColor;
  this -> cell_colour = cellColor;
  this -> font_colour = fontColor;
  this -> font = font;
  this -> justification = justification;
  this -> line_thickness = 1;
}

void Cell::setText(std::string text) {
  this -> text = text;
}

void Cell::setX(int x) {
  this -> x = x;
}

void Cell::setY(int y) {
  this -> y = y;
}

void Cell::setWidth(int width) {
  this -> width = width;
}

void Cell::setHeight(int height) {
  this -> height = height;
}

void Cell::setOutlineColour(ALLEGRO_COLOR color) {
  this -> outline_colour = color;
}

void Cell::setCellColour(ALLEGRO_COLOR color) {
  this -> cell_colour = color;
}

void Cell::setFontColour(ALLEGRO_COLOR color) {
  this -> font_colour = color;
}

void Cell::setLineThickness(int thickness) {
  this -> line_thickness = thickness;
}

void Cell::draw() {
  al_draw_filled_rectangle(x, y, x + width, y + height, cell_colour);
  al_draw_rectangle(x + line_thickness / 2, y + line_thickness / 2, x + width - line_thickness / 2, y + height - line_thickness / 2, outline_colour, line_thickness);

  if(font.numSizes() > 0) {
    int text_size = font.getLargestFitting(width - x_padding * 2, height - y_padding * 2, text);
    int text_x = 0;
    int text_y = 0;

    // Position text
    switch(justification) {
      case justification::RIGHT:
        text_x = x + width - x_padding;
        text_y = y + y_padding;
        break;

      case justification::CENTER:
        text_x = x + width / 2;
        text_y = y + y_padding - (font.getTextHeight(text_size, text) - height) / 2;
        break;

      default:
      case justification::LEFT:
        text_x = x + x_padding;
        text_y = y + y_padding;
        break;
    }

    // Draw text to screen
    al_draw_textf(font.getFont(text_size), font_colour, text_x, (text_y - font.getTextOffsetY(text_size, text)), justification, text.c_str());
  }
}
