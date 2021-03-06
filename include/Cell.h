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
    Cell(int, int, int, int, ALLEGRO_COLOR, ALLEGRO_COLOR,ALLEGRO_COLOR, Font,int, std::string);
    virtual ~Cell();
    void draw();
    void setText(std::string newText){text=newText;}
    void setX(int newX){x=newX;}
    void setY(int newY){y=newY;}
    void setWidth(int newWidth){width=newWidth;}
    void setHeight(int newHeight){height=newHeight;}
    void setOutlineColour(ALLEGRO_COLOR n){outline_colour=n;}
    void setCellColour(ALLEGRO_COLOR i){cell_colour=i;}
    void setFontColour(ALLEGRO_COLOR g){font_colour=g;}
    void setLineThickness(int nt){line_thickness=nt;}


  protected:


    int width;
    int height;
    int x;
    int y;
    int x_padding=5;
    int y_padding=5;
    int justification=LEFT;
    int line_thickness=1;
    std::string text;

    Font font;

    ALLEGRO_COLOR outline_colour;
    ALLEGRO_COLOR cell_colour;
    ALLEGRO_COLOR font_colour;



  private:
};

#endif // CELL_H
