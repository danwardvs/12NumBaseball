#include "FontDimensions.h"

// Create font dimensions
FontDimensions::FontDimensions(int x, int y, int width, int height)
  : x(x), y(y), width(width), height(height) {

}

// Get BB X
int FontDimensions::getX() const {
  return x;
}

// Get BB Y
int FontDimensions::getY() const {
  return y;
}

// Get BB Width
int FontDimensions::getWidth() const {
  return width;
}

// Get BB Height
int FontDimensions::getHeight() const {
  return height;
}
