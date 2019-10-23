#include "font/Font.h"

#include <set>
#include <allegro5/allegro_ttf.h>

/** \brief Initializes font with preset sizes
 *
 * \param path std::string
 * \return void
 *
 */
void Font::init(std::string path) {
  const std::set<int> sizes = { 4, 8, 12, 16, 24, 36, 54, 72, 100, 150, 200, 300 };

  for(auto fontSize : sizes) {
    fonts.insert(std::pair<int, ALLEGRO_FONT*>(fontSize, al_load_ttf_font(path.c_str(), fontSize, 0)));
  }
}

/** \brief Get font bounding box dimensions
 *
 * \param fontSize an integer representing the size of the font to check dimensions of
 * \param text a string with the text to be checked against the dimensions
 * \return FontDimensions the dimensions object of the font
 *
 */
FontDimensions Font::getFontDimensions(int fontSize, std::string text) const {
  int _width = 0;
  int _height = 0;
  int _x = 0;
  int _y = 0;

  al_get_text_dimensions(getFont(fontSize), text.c_str(), &_x, &_y, &_width, &_height);

  return FontDimensions(_x, _y, _width, _height);
}

/** \brief Check if text will fit in a given width and height
 *
 * \param fontSize int
 * \param width int
 * \param height int
 * \param text std::string
 * \return bool whether or not the font fits
 *
 */
bool Font::textWillFit(int fontSize, int width, int height, std::string text) const {
  const FontDimensions _dimensions = getFontDimensions(fontSize, text);
  return _dimensions.getWidth() <= width && _dimensions.getHeight() <= height;
}

/** \brief Get text x offset from origin
 *
 * \param fontSize int
 * \param text std::string
 * \return int x position of font
 *
 */
int Font::getTextOffsetX(int fontSize, std::string text) const {
  const FontDimensions _dimensions = getFontDimensions(fontSize, text);
  return _dimensions.getX();
}

/** \brief Get text y offset from origin
 *
 * \param fontSize int
 * \param text std::string
 * \return int y position of font
 *
 */
int Font::getTextOffsetY(int fontSize, std::string text) const {
  const FontDimensions _dimensions = getFontDimensions(fontSize, text);
  return _dimensions.getY();
}

/** \brief Get text height
 *
 * \param fontSize int
 * \param text std::string
 * \return int height of font
 *
 */
int Font::getTextHeight(int fontSize, std::string text) const {
  const FontDimensions _dimensions = getFontDimensions(fontSize, text);
  return _dimensions.getHeight();
}

/** \brief Get text width
 *
 * \param fontSize int
 * \param text std::string
 * \return int width of font
 *
 */
int Font::getTextWidth(int fontSize, std::string text) const {
  const FontDimensions _dimensions = getFontDimensions(fontSize, text);
  return _dimensions.getWidth();
}

/** \brief Gets font by size, if none, returns nullptr
 *
 * \param fontSize int
 * \return ALLEGRO font object or nullptr
 *
 */
ALLEGRO_FONT* Font::getFont(int fontSize) const {
  if(fonts.find(fontSize) != fonts.end()) {
    return fonts.at(fontSize);
  }

  return nullptr;
}


/** \brief Get the number of fonts currently loaded
 *
 * \return int, number of fonts
 *
 */
int Font::numSizes() const {
  return fonts.size();
}
