#include "Font.h"



Font::Font(std::string newPath)
{
  font[0] = al_load_ttf_font( newPath.c_str(), 4, 0);
  font[1] = al_load_ttf_font( newPath.c_str(), 8, 0);
  font[2] = al_load_ttf_font( newPath.c_str(), 12, 0);
  font[3] = al_load_ttf_font( newPath.c_str(), 16, 0);
  font[4] = al_load_ttf_font( newPath.c_str(), 24, 0);
  font[5] = al_load_ttf_font( newPath.c_str(), 36, 0);
  font[6] = al_load_ttf_font( newPath.c_str(), 54, 0);
  font[7] = al_load_ttf_font( newPath.c_str(), 72, 0);

}

Font::~Font()
{
  //dtor
}

ALLEGRO_FONT *Font::getSize(int newSize){
  switch (newSize) {
    case 4:
      return font[0];
    case 8:
      return font[1];
    case 12:
      return font[2];
    case 16:
      return font[3];
    case 24:
      return font[4];
    case 36:
      return font[5];
    case 54:
      return font[6];
    case 72:
      return font[7];


  }
  ALLEGRO_FONT *newFont;
  return newFont;
}
