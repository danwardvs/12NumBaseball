#include "Font.h"


Font::Font(){

}


Font::~Font()
{
  //dtor
}

bool Font::textWillFit(int newSize, int newWidth, int newHeight, std::string newText){
  if(al_get_text_width(getSize(newSize),newText.c_str())<=newWidth && al_get_font_line_height(getSize(newSize))<=newHeight){
     return true;
  }

  return false;

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
    case 100:
      return font[8];
    case 150:
      return font[9];
    case 200:
      return font[10];



  }
  ALLEGRO_FONT *newFont;
  return newFont;
}

void Font::init(std::string newPath)
{
  font[0] = al_load_ttf_font( newPath.c_str(), 4, 0);
  font[1] = al_load_ttf_font( newPath.c_str(), 8, 0);
  font[2] = al_load_ttf_font( newPath.c_str(), 12, 0);
  font[3] = al_load_ttf_font( newPath.c_str(), 16, 0);
  font[4] = al_load_ttf_font( newPath.c_str(), 24, 0);
  font[5] = al_load_ttf_font( newPath.c_str(), 36, 0);
  font[6] = al_load_ttf_font( newPath.c_str(), 54, 0);
  font[7] = al_load_ttf_font( newPath.c_str(), 72, 0);
  font[8] = al_load_ttf_font( newPath.c_str(), 100, 0);
  font[9] = al_load_ttf_font( newPath.c_str(), 150, 0);
  font[10] = al_load_ttf_font( newPath.c_str(), 200, 0);



}
