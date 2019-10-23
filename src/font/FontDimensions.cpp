#include "font/FontDimensions.h"

/** \brief Constructor
 *
 * \param x position of font
 * \param y position of font
 * \param width dimension of font
 * \param height dimension of font
 *
 */
FontDimensions::FontDimensions(int x, int y, int width, int height)
  : x(x), y(y), width(width), height(height) {

}


/** \brief Get x of font dimensions bounding box
 *
 * \return x
 *
 */
int FontDimensions::getX() const {
  return x;
}


/** \brief Get y of font dimensions bounding box
 *
 * \return y
 *
 */
int FontDimensions::getY() const {
  return y;
}


/** \brief Get width of font dimensions bounding box
 *
 * \return width
 *
 */
int FontDimensions::getWidth() const {
  return width;
}


/** \brief Get height of font dimensions bounding box
 *
 * \return height
 *
 */
int FontDimensions::getHeight() const {
  return height;
}
