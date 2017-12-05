#include "menu.h"


// Init menu
menu::menu(){
  myFont.init("font/calibri.ttf");
  myNiceCell = Cell(100,100,335,50,BLACK,WHITE,myFont,"Hello pooping world");
}

// Destory menu
menu::~menu(){

}
// Update animation and wait for input
void menu::update(){

}

// Draw images to screen
void menu::draw(){

  // Background
  al_clear_to_color(WHITE);


  myNiceCell.draw();
}




