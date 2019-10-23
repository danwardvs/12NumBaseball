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
    FontDimensions(int x, int y, int width, int height);

    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

  private:
    const int x;
    const int y;
    const int width;
    const int height;
};

#endif
