#include "menu.h"


// Init menu
menu::menu(){
  myFont.init("font/fantasque.ttf");
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
  al_clear_to_color( al_map_rgb(255,255,255));

  myNiceCell.draw();



}




