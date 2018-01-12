#include "menu.h"


// Init menu
menu::menu(){
  calibri_bold.init("font/calibri_bold.ttf");
  generate_cells();
  input_step==0;
}

// Destory menu
menu::~menu(){

}

// Update animation and wait for input
void menu::update(){
  if(keyListener::numKeyReleased){


    if(input_step==0){

      for(int i=27; i<36; i++){
        batter_number=keyListener::lastKeyReleased-27;
      }
      if(batter_number==1){
        input_step=1;
      }else{
        input_step=3;
      }
    }else if(input_step==1){


      if(batter_number==1){
        if(keyListener::keyReleased[ALLEGRO_KEY_0]){
          batter_number=10;
          input_step=3;
        }
        if(keyListener::keyReleased[ALLEGRO_KEY_1]){
          batter_number=11;
          input_step=3;
        }
        if(keyListener::keyReleased[ALLEGRO_KEY_2]){
          batter_number=12;
          input_step=3;
        }
      }

    }else if(input_step==3){
        for(int i=27; i<36; i++){
          pitcher_number=keyListener::lastKeyReleased-27;
        }
        if(pitcher_number==1){
          input_step=4;
      }else{
        input_step=5;
      }
    }else if(input_step==4){


        if(pitcher_number==1){
          if(keyListener::keyReleased[ALLEGRO_KEY_0]){
            pitcher_number=10;
            input_step=5;
          }
          if(keyListener::keyReleased[ALLEGRO_KEY_1]){
            pitcher_number=11;
             input_step=5;
          }
          if(keyListener::keyReleased[ALLEGRO_KEY_2]){
            pitcher_number=12;
            input_step=5;
          }
        }
      }
  }

  if(keyListener::keyReleased[ALLEGRO_KEY_ENTER]){
    if(input_step==1 || input_step==0)
      input_step=3;
    else if(input_step==3 || input_step==4)
      input_step=5;
    else if(input_step==5){
      result_number=RandNum::randInt(1,122);
      result_number=56;
      result = xml_handler.load_xml("data/1b.xml",result_number,pitcher_number);


    }
  }
  if(keyListener::keyReleased[ALLEGRO_KEY_DELETE])
    input_step=0;


  if(input_step==0 || input_step==1){
    gameCells[0] -> setOutlineColour(GREEN);
    gameCells[2] -> setOutlineColour(BLACK);
    gameCells[4] -> setOutlineColour(BLACK);



  }

  if(input_step==3 || input_step==4){
    gameCells[0] -> setOutlineColour(BLACK);
    gameCells[2] -> setOutlineColour(GREEN);
    gameCells[4] -> setOutlineColour(BLACK);


  }
  if(input_step==5){
    gameCells[0] -> setOutlineColour(BLACK);
    gameCells[2] -> setOutlineColour(BLACK);
    gameCells[4] -> setOutlineColour(GREEN);

  }
  gameCells[0] -> setText(tools::toString(batter_number));
  gameCells[2] -> setText(tools::toString(pitcher_number));
  gameCells[4] -> setText(tools::toString(result_number));

  gameCells[6] -> setText(result);







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

  gameCells.push_back(new Cell(0,SCREEN_H-25,90,25,BLACK,BLACK,RED,calibri_bold,LEFT,RandNum::getSeed()));

  gameCells.push_back(new Cell(0,300,300,50,BLACK,WHITE,BLUE,calibri_bold,LEFT,"Storms mound"));















}



