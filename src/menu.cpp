#include "menu.h"


// Init menu
menu::menu(){
  calibri_bold.init("font/calibri_bold.ttf");
  generate_cells();
}

// Destory menu
menu::~menu(){

}
// Update animation and wait for input
void menu::update(){
  //gameCells[0] -> setWidth(mouseListener::mouse_x);
  //gameCells[0] -> setHeight(mouseListener::mouse_y);


}

// Draw images to screen
void menu::draw(){



  // Background
  al_clear_to_color(WHITE);

   for(int i=0;i<gameCells.size(); i++){
    gameCells[i] -> draw();
  }

}

void menu::generate_cells(){
  int width_6 = SCREEN_W/6;
  std::cout<<SCREEN_W;
  gameCells.push_back(new Cell(0,0,width_6,200,BLACK,WHITE,BLACK,calibri_bold,CENTER,"7"));
  gameCells.push_back(new Cell(0,0,150,75,TRANSPARENT,TRANSPARENT,BLACK,calibri_bold,LEFT,"Batter Number"));

  gameCells.push_back(new Cell(5+width_6+20,0,width_6*2,200,BLACK,BLACK,RED,calibri_bold,CENTER,"112"));






}



