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
Cell::Cell(int newX, int newY, int newWidth, int newHeight,ALLEGRO_COLOR newOutlineColour, ALLEGRO_COLOR newCellColour,
           ALLEGRO_COLOR newFontColor,Font newFont,int newJustification,std::string newText){

  x=newX;
  y=newY;
  width=newWidth;
  height=newHeight;
  text=newText;
  outline_colour = newOutlineColour;
  cell_colour = newCellColour;
  font_colour = newFontColor;
  font = newFont;
  justification=newJustification;


}

Cell::~Cell()
{
  //dtor
}

void Cell::draw(){

    al_draw_filled_rectangle( x, y, x + width , y + height,cell_colour);
    al_draw_rectangle( x+1, y+1, x + width, y + height, outline_colour,1);

    if(font.getFirstFont()!=nullptr){

      int text_size;
      int text_x;
      int text_y;


     if(font.textWillFit(300,width-x_padding*2,height-y_padding*2,text))
        text_size=300;
      else if(font.textWillFit(200,width-x_padding*2,height-y_padding*2,text))
        text_size=200;
      else if(font.textWillFit(150,width-x_padding*2,height-y_padding*2,text))
        text_size=150;
      else if(font.textWillFit(100,width-x_padding*2,height-y_padding*2,text))
        text_size=100;
      else if(font.textWillFit(72,width-x_padding*2,height-y_padding*2,text))
        text_size=72;
      else if(font.textWillFit(54,width-x_padding*2,height-y_padding*2,text))
        text_size=54;
      else if(font.textWillFit(36,width-x_padding*2,height-y_padding*2,text))
        text_size=36;
      else if(font.textWillFit(24,width-x_padding*2,height-y_padding*2,text))
        text_size=24;
      else if(font.textWillFit(16,width-x_padding*2,height-y_padding*2,text))
        text_size=16;
      else if(font.textWillFit(12,width-x_padding*2,height-y_padding*2,text))
        text_size=12;
      else if(font.textWillFit(8,width-x_padding*2,height-y_padding*2,text))
        text_size=8;
      else
        text_size=4;

       if(justification==LEFT){
        text_x=x+x_padding;
        text_y=y+y_padding;
      }

      if(justification==CENTER){
        text_x=x+width/2;
        text_y=y+y_padding-(font.get_text_height(text_size,text)-height)/2;
      }

      if(justification==RIGHT){
        text_x=x+width-x_padding;
        text_y=y+y_padding;
      }

      al_draw_textf(font.getSize(text_size),font_colour,text_x,(text_y-font.get_text_offset_y(text_size,text)),justification,text.c_str());
      //al_draw_justified_text(font.getSize(54),BLACK,x,x+1000,y,2000,0,"Hello world. This is a message.");
    }



}
