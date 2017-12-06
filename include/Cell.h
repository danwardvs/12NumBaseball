#ifndef CELL_H
#define CELL_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

#include <string>
#include <tools.h>
#include <Font.h>
#include <globals.h>

class Cell
{
  public:
    Cell();
    Cell(int, int, int, int, ALLEGRO_COLOR, ALLEGRO_COLOR,Font,int, std::string);
    virtual ~Cell();
    void draw();
    void setText(std::string newText){text=newText;}
    void setX(int newX){x=newX;}
    void setY(int newY){y=newY;}
    void setWidth(int newWidth){width=newWidth;}
    void setHeight(int newHeight){height=newHeight;}

  protected:


    int width;
    int height;
    int x;
    int y;
    int x_padding=5;
    int y_padding=5;
    int justification=LEFT;
    std::string text;

    Font font;

    ALLEGRO_COLOR outline_colour;
    ALLEGRO_COLOR cell_colour;



  private:
};

#endif // CELL_H
