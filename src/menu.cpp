#include "menu.h"


// Init menu
menu::menu(){
  calibri_bold.init("font/calibri_bold.ttf");
  calibri.init("font/calibri.ttf");
  generate_cells();
  input_step==0;
}

// Destory menu
menu::~menu(){

}

// Update animation and wait for input
void menu::update(){

  if(keyListener::keyReleased[ALLEGRO_KEY_ESCAPE])
    set_next_state(STATE_EXIT);

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
      for(int i=0; i<9; i++){
        bottom_number[i]=RandNum::randInt(1,100);
      }

      //result_number=90;
      if(result_number<101){
        std::string newPath="data/" + tools::toString(batter_number) +"b.xml";
        result[0] = xml_handler.load_xml(newPath,result_number,pitcher_number);
        if(result_number>83){
          result[1] = xml_handler.load_xml("data/1sl.xml",result_number,pitcher_number);
          result[2] = xml_handler.load_xml("data/ssl.xml",result_number,pitcher_number);
          result[3] = xml_handler.load_xml("data/3sl.xml",result_number,pitcher_number);
          result[4] = xml_handler.load_xml("data/gsl.xml",result_number,pitcher_number);
          result[5] = xml_handler.load_xml("data/5sl.xml",result_number,pitcher_number);
          result[6] = xml_handler.load_xml("data/asl.xml",result_number,pitcher_number);
          result[7] = xml_handler.load_xml("data/7sl.xml",result_number,pitcher_number);
          result[8] = xml_handler.load_xml("data/fsl.xml",result_number,pitcher_number);
        }
        else{
          for(int i=1; i<9; i++){
            result[i]="";
          }

        }
      }
      else{
        result[0] = xml_handler.load_special(result_number);
        for(int i=1; i<9; i++){
          result[i]="";
        }
      }


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

  for(int i=0; i<9; i++)
    gameCells[i*2+6] -> setText(result[i]);

  for(int i=0; i<6; i++)
      gameCells[i+23] -> setText(tools::toString(bottom_number[i]));







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
  int height_16 = SCREEN_H/16;
  std::cout<<SCREEN_W;

  gameCells.push_back(new Cell(0,0,width_6,height_16*4,BLACK,WHITE,BLACK,calibri_bold,CENTER,"7"));
  gameCells[0] -> setLineThickness(4);
  gameCells.push_back(new Cell(0,0,150,75,TRANSPARENT,TRANSPARENT,BLACK,calibri,LEFT,"Batter Number"));


  gameCells.push_back(new Cell(width_6,0,width_6,height_16*4,BLACK,WHITE,BLACK,calibri_bold,CENTER,"12"));
  gameCells[2] -> setLineThickness(4);
  gameCells.push_back(new Cell(width_6,0,150,75,TRANSPARENT,TRANSPARENT,BLACK,calibri,LEFT,"Pitcher Number"));

  gameCells.push_back(new Cell(5+width_6*2+20,0,width_6*2,height_16*4,BLACK,BLACK,RED,calibri_bold,CENTER,"112"));

  gameCells[4] -> setLineThickness(4);


  gameCells.push_back(new Cell(SCREEN_W-90,SCREEN_H-75,90,25,BLACK,BLACK,RED,calibri,LEFT,RandNum::getSeed()));


  int slugging_height=height_16;
  int slugging_position=height_16*5+40;

  gameCells.push_back(new Cell(20,height_16*4+20,400,height_16*2,BLACK,WHITE,BLUE,calibri,LEFT,"Storms mound"));

  gameCells[6] -> setLineThickness(2);


  gameCells.push_back(new Cell(0,slugging_position+slugging_height*1,50,slugging_height,BLACK,WHITE,BLACK,calibri,LEFT,"1SL"));
  gameCells.push_back(new Cell(50,slugging_position+slugging_height*1,300,slugging_height,BLACK,WHITE,BLUE,calibri,LEFT,"Smacks it out of the park"));
  gameCells.push_back(new Cell(0,slugging_position+slugging_height*2,50,slugging_height,BLACK,WHITE,BLACK,calibri,LEFT,"SSL"));
  gameCells.push_back(new Cell(50,slugging_position+slugging_height*2,300,slugging_height,BLACK,WHITE,BLUE,calibri,LEFT,"Over the fence"));

  gameCells.push_back(new Cell(0,slugging_position+slugging_height*3,50,slugging_height,BLACK,WHITE,BLACK,calibri,LEFT,"3SL"));
  gameCells.push_back(new Cell(50,slugging_position+slugging_height*3,300,slugging_height,BLACK,WHITE,BLUE,calibri,LEFT,"Deep fly, triple"));
  gameCells.push_back(new Cell(0,slugging_position+slugging_height*4,50,slugging_height,BLACK,WHITE,BLACK,calibri,LEFT,"GSL"));
  gameCells.push_back(new Cell(50,slugging_position+slugging_height*4,300,slugging_height,BLACK,WHITE,BLUE,calibri,LEFT,"Easy double"));

  gameCells.push_back(new Cell(0,slugging_position+slugging_height*5,50,slugging_height,BLACK,WHITE,BLACK,calibri,LEFT,"5SL"));
  gameCells.push_back(new Cell(50,slugging_position+slugging_height*5,300,slugging_height,BLACK,WHITE,BLUE,calibri,LEFT,"Barely makes it to first"));
  gameCells.push_back(new Cell(0,slugging_position+slugging_height*6,50,slugging_height,BLACK,WHITE,BLACK,calibri,LEFT,"ASL"));
  gameCells.push_back(new Cell(50,slugging_position+slugging_height*6,300,slugging_height,BLACK,WHITE,BLUE,calibri,LEFT,"m/18/woody"));

  gameCells.push_back(new Cell(0,slugging_position+slugging_height*7,50,slugging_height,BLACK,WHITE,BLACK,calibri,LEFT,"7SL"));
  gameCells.push_back(new Cell(50,slugging_position+slugging_height*7,300,slugging_height,BLACK,WHITE,BLUE,calibri,LEFT,"Trips over bat, gets tagged out"));
  gameCells.push_back(new Cell(0,slugging_position+slugging_height*8,50,slugging_height,BLACK,WHITE,BLACK,calibri,LEFT,"FSL"));
  gameCells.push_back(new Cell(50,slugging_position+slugging_height*8,300,slugging_height,BLACK,WHITE,BLUE,calibri,LEFT,"Complete failure of a career"));


  gameCells.push_back(new Cell(0,SCREEN_H-height_16,width_6,height_16,BLACK,YELLOW,GROSS_YELLOW,calibri,CENTER,"55"));
  gameCells.push_back(new Cell(width_6,SCREEN_H-height_16,width_6,height_16,BLACK,YELLOW,GROSS_YELLOW,calibri,CENTER,"100"));
  gameCells.push_back(new Cell(width_6*2,SCREEN_H-height_16,width_6,height_16,BLACK,YELLOW,GROSS_YELLOW,calibri,CENTER,"45"));
  gameCells.push_back(new Cell(width_6*3,SCREEN_H-height_16,width_6,height_16,BLACK,YELLOW,GROSS_YELLOW,calibri,CENTER,"45"));
  gameCells.push_back(new Cell(width_6*4,SCREEN_H-height_16,width_6,height_16,BLACK,YELLOW,GROSS_YELLOW,calibri,CENTER,"45"));
  gameCells.push_back(new Cell(width_6*5,SCREEN_H-height_16,width_6,height_16,BLACK,YELLOW,GROSS_YELLOW,calibri,CENTER,"45"));













}



