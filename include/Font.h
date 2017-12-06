#ifndef FONT_H
#define FONT_H

#include <string>
#include <iostream>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class Font
{
  public:
    void init(std::string newPath);
    Font();
    virtual ~Font();
    ALLEGRO_FONT *getSize(int newSize);
    bool textWillFit(int, int, int,std::string);
    ALLEGRO_FONT *getFirstFont(){return font[0];}
    int get_text_offset_x(int,std::string);
    int get_text_offset_y(int,std::string);
    int get_text_height(int,std::string);


  protected:

  private:
    ALLEGRO_FONT *font[12];
};

#endif // FONT_H
