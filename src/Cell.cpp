#include "Cell.h"

Cell::Cell()
{
  x=100;
  y=100;
  width=100;
  height=50;
  this -> outline_colour = al_map_rgba(0,0,0,255);
  this -> cell_colour = al_map_rgba(123,456,789,255);
}

Cell::~Cell()
{
  //dtor
}

void Cell::draw(){

    al_draw_filled_rectangle( x, y, x + width , y + height,cell_colour);
    al_draw_rectangle( x, y, x + width, y + height, outline_colour,1);


}
