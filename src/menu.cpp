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
        if(keyListener::keyReleased[ALLEGRO_KEY_0] || keyListener::keyReleased[ALLEGRO_KEY_PAD_0]){
          batter_number=10;
          input_step=3;
        }
        if(keyListener::keyReleased[ALLEGRO_KEY_1] || keyListener::keyReleased[ALLEGRO_KEY_PAD_1]){
          batter_number=11;
          input_step=3;
        }
        if(keyListener::keyReleased[ALLEGRO_KEY_2] || keyListener::keyReleased[ALLEGRO_KEY_PAD_2]){
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
          if(keyListener::keyReleased[ALLEGRO_KEY_0] || keyListener::keyReleased[ALLEGRO_KEY_PAD_0]){
            pitcher_number=10;
            input_step=5;
          }
          if(keyListener::keyReleased[ALLEGRO_KEY_1] || keyListener::keyReleased[ALLEGRO_KEY_PAD_1]){
            pitcher_number=11;
             input_step=5;
          }
          if(keyListener::keyReleased[ALLEGRO_KEY_2] || keyListener::keyReleased[ALLEGRO_KEY_PAD_2]){
            pitcher_number=12;
            input_step=5;
          }
        }
      }
  }

  if(keyListener::keyPressed[ALLEGRO_KEY_ENTER] || keyListener::keyPressed[ALLEGRO_KEY_PAD_ENTER]){
    if(input_step==1 || input_step==0)
      input_step=3;
    else if(input_step==3 || input_step==4)
      input_step=5;
    else if(input_step==5){
      result_number=RandNum::randInt(1,130);
      result_number=3;
      for(int i=0; i<9; i++){
        extra_number[i]=RandNum::randInt(1,100);
      }
      steal_throw_number= RandNum::randInt(1,122);
      groundout_type=RandNum::randInt(1,3);
      total_numbers_generated++;


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
  if(keyListener::keyReleased[ALLEGRO_KEY_DELETE] || keyListener::keyReleased[ALLEGRO_KEY_BACKSPACE])
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
      gameCells[i+23] -> setText(tools::toString(extra_number[i]));


  gameCells[29] -> setText(tools::toString(extra_number[6]));
  gameCells[31] -> setText(tools::toString(extra_number[7]));
  gameCells[33] -> setText(tools::toString(extra_number[7]));
  gameCells[34] -> setText(tools::toString(extra_number[8]));
  gameCells[36] -> setText(tools::toString(steal_throw_number));

  if(groundout_type==1){
    gameCells[38] -> setCellColour(RED);
    gameCells[38] -> setText("Hard one hop");
  }else if(groundout_type==2){
    gameCells[38] -> setCellColour(YELLOW);
    gameCells[38] -> setText("Average grounder");

  }else if(groundout_type==3){
    gameCells[38] -> setCellColour(GREEN);
    gameCells[38] -> setText("Slow roller");

  }
  std::string newTime = Time::getCurrentTime();
  newTime.pop_back();
  gameCells[40] -> setText(newTime);
  gameCells[42] -> setText(tools::toString(total_numbers_generated));







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


  gameCells.push_back(new Cell(SCREEN_W-90,SCREEN_H-height_16-25,90,25,BLACK,WHITE,BLACK,calibri,LEFT,RandNum::getSeed()));


  int slugging_height=height_16;
  int slugging_position=height_16*5+40;

  gameCells.push_back(new Cell(20,height_16*4+20,width_6*3,height_16*2,BLACK,WHITE,BLUE,calibri,LEFT,"Storms mound"));

  gameCells[6] -> setLineThickness(2);



  gameCells.push_back(new Cell(0,slugging_position+slugging_height*1,50,slugging_height,BLACK,WHITE,BLACK,calibri,LEFT,"1SL"));
  gameCells.push_back(new Cell(50,slugging_position+slugging_height*1,width_6*3,slugging_height,BLACK,WHITE,BLUE,calibri,LEFT,"Smacks it out of the park"));
  gameCells.push_back(new Cell(0,slugging_position+slugging_height*2,50,slugging_height,BLACK,WHITE,BLACK,calibri,LEFT,"SSL"));
  gameCells.push_back(new Cell(50,slugging_position+slugging_height*2,width_6*3,slugging_height,BLACK,WHITE,BLUE,calibri,LEFT,"Over the fence"));

  gameCells.push_back(new Cell(0,slugging_position+slugging_height*3,50,slugging_height,BLACK,WHITE,BLACK,calibri,LEFT,"3SL"));
  gameCells.push_back(new Cell(50,slugging_position+slugging_height*3,width_6*3,slugging_height,BLACK,WHITE,BLUE,calibri,LEFT,"Deep fly, triple"));
  gameCells.push_back(new Cell(0,slugging_position+slugging_height*4,50,slugging_height,BLACK,WHITE,BLACK,calibri,LEFT,"GSL"));
  gameCells.push_back(new Cell(50,slugging_position+slugging_height*4,width_6*3,slugging_height,BLACK,WHITE,BLUE,calibri,LEFT,"Easy double"));

  gameCells.push_back(new Cell(0,slugging_position+slugging_height*5,50,slugging_height,BLACK,WHITE,BLACK,calibri,LEFT,"5SL"));
  gameCells.push_back(new Cell(50,slugging_position+slugging_height*5,width_6*3,slugging_height,BLACK,WHITE,BLUE,calibri,LEFT,"Barely makes it to first"));
  gameCells.push_back(new Cell(0,slugging_position+slugging_height*6,50,slugging_height,BLACK,WHITE,BLACK,calibri,LEFT,"ASL"));
  gameCells.push_back(new Cell(50,slugging_position+slugging_height*6,width_6*3,slugging_height,BLACK,WHITE,BLUE,calibri,LEFT,"m/18/woody"));

  gameCells.push_back(new Cell(0,slugging_position+slugging_height*7,50,slugging_height,BLACK,WHITE,BLACK,calibri,LEFT,"7SL"));
  gameCells.push_back(new Cell(50,slugging_position+slugging_height*7,width_6*3,slugging_height,BLACK,WHITE,BLUE,calibri,LEFT,"Trips over bat, gets tagged out"));
  gameCells.push_back(new Cell(0,slugging_position+slugging_height*8,50,slugging_height,BLACK,WHITE,BLACK,calibri,LEFT,"FSL"));
  gameCells.push_back(new Cell(50,slugging_position+slugging_height*8,width_6*3,slugging_height,BLACK,WHITE,BLUE,calibri,LEFT,"Complete failure of a career"));


  gameCells.push_back(new Cell(0,SCREEN_H-height_16,width_6,height_16,BLACK,YELLOW,GROSS_YELLOW,calibri,CENTER,"55"));
  gameCells.push_back(new Cell(width_6,SCREEN_H-height_16,width_6,height_16,BLACK,YELLOW,GROSS_YELLOW,calibri,CENTER,"100"));
  gameCells.push_back(new Cell(width_6*2,SCREEN_H-height_16,width_6,height_16,BLACK,YELLOW,GROSS_YELLOW,calibri,CENTER,"45"));
  gameCells.push_back(new Cell(width_6*3,SCREEN_H-height_16,width_6,height_16,BLACK,YELLOW,GROSS_YELLOW,calibri,CENTER,"45"));
  gameCells.push_back(new Cell(width_6*4,SCREEN_H-height_16,width_6,height_16,BLACK,YELLOW,GROSS_YELLOW,calibri,CENTER,"45"));
  gameCells.push_back(new Cell(width_6*5,SCREEN_H-height_16,width_6,height_16,BLACK,YELLOW,GROSS_YELLOW,calibri,CENTER,"45"));

  gameCells.push_back(new Cell(width_6*4+40,25,width_6-20,height_16*2,BLACK,YELLOW,BLACK,calibri,CENTER,"12 "));
  gameCells.push_back(new Cell(width_6*4+40,0,width_6-20,25,BLACK,WHITE,BLACK,calibri,LEFT,"Fielder"));

  gameCells.push_back(new Cell(width_6*5+20,25,width_6-20,height_16*2,BLACK,YELLOW,BLACK,calibri,CENTER,"12"));
  gameCells.push_back(new Cell(width_6*5+20,0,width_6-20,25,BLACK,WHITE,BLACK,calibri,LEFT,"Run Adv. Steal WP. Error PB"));

  gameCells.push_back(new Cell(width_6*5+20,50+height_16*2,width_6-20,height_16*2,BLACK,BLUE,WHITE,calibri,CENTER,"12"));
  gameCells.push_back(new Cell(width_6*5+20,50+height_16*4,width_6-20,height_16*2,BLACK,BLUE,WHITE,calibri,CENTER,"12"));

  gameCells.push_back(new Cell(width_6*5+20,25+height_16*2,width_6-20,25,BLACK,WHITE,BLACK,calibri,LEFT,"Double play"));

  gameCells.push_back(new Cell(width_6*4+40,50+height_16*2,width_6-20,height_16*2,BLACK,GREEN,BLACK,calibri,CENTER,"12 "));
  gameCells.push_back(new Cell(width_6*4+40,25+height_16*2,width_6-20,25,BLACK,WHITE,BLACK,calibri,LEFT,"Steals and throws"));

  gameCells.push_back(new Cell(width_6*4+40,75+height_16*4,width_6-20,height_16*2-25,BLACK,GREEN,BLACK,calibri,CENTER,""));
  gameCells.push_back(new Cell(width_6*4+40,50+height_16*4,width_6-20,25,BLACK,WHITE,BLACK,calibri,LEFT,"Ground out type"));

  gameCells.push_back(new Cell(SCREEN_W-180,SCREEN_H-height_16-50,180,25,BLACK,WHITE,BLACK,calibri,LEFT,"5 o'clock somewhere"));
  gameCells.push_back(new Cell(SCREEN_W-130,SCREEN_H-height_16-25,40,25,BLACK,WHITE,BLACK,calibri,LEFT,"v1.2"));
  gameCells.push_back(new Cell(SCREEN_W-180,SCREEN_H-height_16-25,50,25,BLACK,WHITE,BLACK,calibri,LEFT,"0"));


















}



