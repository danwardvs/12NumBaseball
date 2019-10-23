/*
 * Font
 * Wrapper for allegro fonts that allows mutiple
 *   sizes to be loaded.
 * Allan Legemaate and Danny Van Stemp
 * 22/10/2019
 */
#ifndef FONT_H
#define FONT_H

#include <string>
#include <map>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include "FontDimensions.h"

class Font {
  public:
    // Ctor/Dtor
    Font() {};
    virtual ~Font() {};

    // Initialize font
    void init(std::string path);

    // Get font by size
    ALLEGRO_FONT* getFont(int fontSize) const;

    // Number of sizes loaded
    int numSizes() const;

    // Text sizing
    FontDimensions getFontDimensions(int fontSize, std::string text) const;
    int getTextOffsetX(int fontSize, std::string text) const;
    int getTextOffsetY(int fontSize, std::string text) const;
    int getTextHeight(int fontSize, std::string text) const;
    int getTextWidth(int fontSize, std::string text) const;
    bool textWillFit(int fontSize, int width, int height, std::string text) const;

  private:
    // Container for fonts
    std::map<int, ALLEGRO_FONT*> fonts;
};

#endif // FONT_H
