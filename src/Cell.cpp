#include "Cell.h"

#include <algorithm>
#include <allegro5/allegro_primitives.h>

#include "helpers/color.h"
#include "constants/screen.h"
#include "constants/colors.h"

Font Cell::defaultFont;

// Constructor
Cell::Cell(const std::string& id) {
  // Set id
  this -> id = id;

  // Set default values
  // Layout
  this -> setX(0);
  this -> setY(0);
  this -> setWidth(100);
  this -> setHeight(100);
  this -> setPadding(5, 5);

  //  Formatting
  this -> setBorderWidth(1);
  this -> setBorderColor(colors::BLACK);
  this -> setCellColor(colors::WHITE);
  this -> setFontColor(colors::BLACK);
  this -> setJustification("center");

  // Content
  this -> setText("");

  // Load default font
  if(defaultFont.numSizes() == 0)  {
    defaultFont.init("font/calibri_bold.ttf");
  }
}

// Get id
std::string Cell::getId() const {
  return this -> id;
}

// LAYOUT
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

void Cell::setPadding(int x, int y) {
  this -> xPadding = x;
  this -> yPadding = y;
}


// FORMATTING
// Border
void Cell::setBorderColor(const std::string& color) {
  this -> outlineColour = helpers::color::hexToAllegro(color);
}

void Cell::setBorderWidth(int thickness) {
  this -> lineThickness = thickness;
}

// Cell
void Cell::setCellColor(const std::string& color) {
  this -> cellColour = helpers::color::hexToAllegro(color);
}

// Font
void Cell::setFontColor(const std::string& color) {
  this -> fontColour = helpers::color::hexToAllegro(color);
}

void Cell::setJustification(const std::string& align) {
  std::string alignLow = align;
  std::transform(alignLow.begin(), alignLow.end(), alignLow.begin(), ::tolower);

  if(!alignLow.compare("right"))
    this -> justification = justification::RIGHT;
  else if(!alignLow.compare("center"))
    this -> justification = justification::CENTER;
  else if(!alignLow.compare("default") || !alignLow.compare("left"))
    this -> justification = justification::LEFT;
}

// CONTENT
// Text
void Cell::setText(const std::string& text) {
  this -> text = text;
}

void Cell::setText(int text) {
  this -> text = std::to_string(text);
}


// Draw cell routine
void Cell::draw() {
  // Cell body
  al_draw_filled_rectangle(x, y, x + width, y + height, cellColour);

  // Cell border
  if(lineThickness > 0) {
    al_draw_rectangle(x + lineThickness / 2, y + lineThickness / 2, x + width - lineThickness / 2, y + height - lineThickness / 2, outlineColour, lineThickness);
  }

  // Text
  if(defaultFont.numSizes() > 0) {
    const int textSize = defaultFont.getLargestFitting(width - xPadding * 2, height - yPadding * 2, text);
    int textX = 0;
    int textY = 0;

    // Position text
    switch(justification) {
      case justification::RIGHT:
        textX = x + width - xPadding;
        textY = y + yPadding;
        break;

      case justification::CENTER:
        textX = x + width / 2;
        textY = y + yPadding - (defaultFont.getTextHeight(textSize, text) - height) / 2;
        break;

      default:
      case justification::LEFT:
        textX = x + xPadding;
        textY = y + yPadding;
        break;
    }

    // Draw text to screen
    al_draw_textf(defaultFont.getFont(textSize), fontColour, textX, (textY - defaultFont.getTextOffsetY(textSize, text)), justification, text.c_str());
  }
}
