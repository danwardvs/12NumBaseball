#include "Cell.h"

Cell::Cell() :
  Cell(100, 100, 100, 50, al_map_rgba(0, 0, 0, 255), al_map_rgba(123, 456, 789, 255), al_map_rgba(0, 0, 0, 255), Font(), LEFT, "") {

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

void Cell::setOutlineColour(ALLEGRO_COLOR outline_colour) {
  this -> outline_colour = outline_colour;
}

void Cell::setCellColour(ALLEGRO_COLOR cell_colour) {
  this -> cell_colour = cell_colour;
}

void Cell::setFontColour(ALLEGRO_COLOR font_colour) {
  this -> font_colour = font_colour;
}

void Cell::setLineThickness(int line_thickness) {
  this -> line_thickness = line_thickness;
}

void Cell::draw() {
  al_draw_filled_rectangle(x, y, x + width, y + height, cell_colour);
  al_draw_rectangle(x + line_thickness / 2, y + line_thickness / 2, x + width - line_thickness / 2, y + height - line_thickness / 2, outline_colour, line_thickness);

  if(font.numSizes() > 0) {
    int text_size = 12;
    int text_x = 0;
    int text_y = 0;


    if(font.textWillFit(300, width - x_padding * 2, height - y_padding * 2, text))
      text_size = 300;
    else if(font.textWillFit(200, width - x_padding * 2, height - y_padding * 2, text))
      text_size = 200;
    else if(font.textWillFit(150, width - x_padding * 2, height - y_padding * 2, text))
      text_size = 150;
    else if(font.textWillFit(100, width - x_padding * 2, height - y_padding * 2, text))
      text_size = 100;
    else if(font.textWillFit(72, width - x_padding * 2, height - y_padding * 2, text))
      text_size = 72;
    else if(font.textWillFit(54, width - x_padding * 2, height - y_padding * 2, text))
      text_size = 54;
    else if(font.textWillFit(36, width - x_padding * 2, height - y_padding * 2, text))
      text_size = 36;
    else if(font.textWillFit(24, width - x_padding * 2, height - y_padding * 2, text))
      text_size = 24;
    else if(font.textWillFit(16, width - x_padding * 2, height - y_padding * 2, text))
      text_size = 16;
    else if(font.textWillFit(12, width - x_padding * 2, height - y_padding * 2, text))
      text_size = 12;
    else if(font.textWillFit(8, width - x_padding * 2, height - y_padding * 2, text))
      text_size = 8;
    else
      text_size = 4;

    // Position text
    switch(justification) {
      case RIGHT:
        text_x = x + width - x_padding;
        text_y = y + y_padding;
        break;

      case CENTER:
        text_x = x + width / 2;
        text_y = y + y_padding - (font.getTextHeight(text_size, text) - height) / 2;
        break;

      default:
      case LEFT:
        text_x = x + x_padding;
        text_y = y + y_padding;
        break;
    }

    // Draw text to screen
    al_draw_textf(font.getFont(text_size), font_colour, text_x, (text_y - font.getTextOffsetY(text_size, text)), justification, text.c_str());
  }
}
