/*
 * Font Dimensions
 * Stores dimensions of a font
 * Allan Legemaate
 * 22/10/2019
 */
#ifndef FONTDIMENSIONS_H
#define FONTDIMENSIONS_H

class FontDimensions  {
  public:
    // Constructor
    FontDimensions(int x, int y, int width, int height);

    // Position getters
    int getX() const;
    int getY() const;

    // Dimension getters
    int getWidth() const;
    int getHeight() const;

  private:
    // Position
    const int x, y;

    // Dimensions
    const int width, height;
};

#endif
