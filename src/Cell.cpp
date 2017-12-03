#include "Cell.h"

Cell::Cell()
{
  x=100;
  y=100;
  width=100;
  height=50;
  text="";
  this -> outline_colour = al_map_rgba(0,0,0,255);
  this -> cell_colour = al_map_rgba(123,456,789,255);
}
Cell::Cell(int newX, int newY, int newWidth, int newHeight,ALLEGRO_COLOR newOutlineColour, ALLEGRO_COLOR newCellColour,std::string newText){
  x=newX;
  y=newY;
  width=newWidth;
  height=newHeight;
  text=newText;
  outline_colour = newOutlineColour;
  cell_colour = newCellColour;


}

Cell::~Cell()
{
  //dtor
}

void Cell::draw(){

    al_draw_filled_rectangle( x, y, x + width , y + height,cell_colour);
    al_draw_rectangle( x, y, x + width, y + height, outline_colour,1);
    if(font.getFirstFont()!=nullptr){
      if(font.textWillFit(72,x-x_padding*2,y-y_padding*2,text))
        al_draw_textf(font.getSize(72),BLACK,x+x_padding,y+y_padding,0,text.c_str());
      else if(font.textWillFit(54,x-x_padding*2,y-y_padding*2,text))
        al_draw_textf(font.getSize(54),BLACK,x+x_padding,y+y_padding,0,text.c_str());
       else if(font.textWillFit(36,x-x_padding*2,y-y_padding*2,text))
        al_draw_textf(font.getSize(36),BLACK,x+x_padding,y+y_padding,0,text.c_str());
       else if(font.textWillFit(24,x-x_padding*2,y-y_padding*2,text))
        al_draw_textf(font.getSize(24),BLACK,x+x_padding,y+y_padding,0,text.c_str());
      else if(font.textWillFit(16,x-x_padding*2,y-y_padding*2,text))
        al_draw_textf(font.getSize(16),BLACK,x+x_padding,y+y_padding,0,text.c_str());
      else if(font.textWillFit(12,x-x_padding*2,y-y_padding*2,text))
        al_draw_textf(font.getSize(12),BLACK,x+x_padding,y+y_padding,0,text.c_str());
      else if(font.textWillFit(8,x-x_padding*2,y-y_padding*2,text))
        al_draw_textf(font.getSize(8),BLACK,x+x_padding,y+y_padding,0,text.c_str());
      else
        al_draw_textf(font.getSize(4),BLACK,x+x_padding,y+y_padding,0,text.c_str());

    }



}
