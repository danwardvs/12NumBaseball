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
  if(keyListener::numKeyPressed){
  std::cout<<"yo\n";
   // if(batter_number==0){
      for(int i=27; i<36; i++){
        batter_number=keyListener::currentKeyPressed-27;
      }

  }
//    if(batter_number==1){
//      if(keyListener::keyPressed[ALLEGRO_KEY_0])
//        batter_number=10;
//      if(keyListener::keyPressed[ALLEGRO_KEY_1])
//        batter_number=11;
//      if(keyListener::keyPressed[ALLEGRO_KEY_2])
//        batter_number=12;
//    }


 // }
  gameCells[0] -> setText(tools::toString(batter_number));


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
  int width_12 = SCREEN_W/12;
  std::cout<<SCREEN_W;
  gameCells.push_back(new Cell(0,0,width_6,200,BLACK,WHITE,BLACK,calibri_bold,CENTER,"7"));
  gameCells.push_back(new Cell(0,0,150,75,TRANSPARENT,TRANSPARENT,BLACK,calibri_bold,LEFT,"Batter Number"));

  gameCells.push_back(new Cell(width_6,0,width_6,200,BLACK,WHITE,BLACK,calibri_bold,CENTER,"12"));
  gameCells.push_back(new Cell(width_6,0,150,75,TRANSPARENT,TRANSPARENT,BLACK,calibri_bold,LEFT,"Pitcher Number"));

  gameCells.push_back(new Cell(5+width_6*2+20,0,width_6*2,200,BLACK,BLACK,RED,calibri_bold,CENTER,"112"));















}



