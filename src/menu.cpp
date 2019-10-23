#include "menu.h"

#include "helpers/time.h"

#include "constants/colors.h"
#include "constants/justifications.h"
#include "constants/screen.h"

// Init menu
menu::menu() {
  calibri_bold.init("font/calibri_bold.ttf");
  calibri.init("font/calibri.ttf");
  generate_cells();
  input_step = 0;
}

// Update animation and wait for input
void menu::update() {
  if(keyListener::keyReleased[ALLEGRO_KEY_ESCAPE])
    set_next_state(STATE_EXIT);

  if(keyListener::numKeyReleased) {
    if(input_step == 0) {
      for(int i = 27; i < 36; i++) {
        batter_number = keyListener::lastKeyReleased - 27;
      }

      if(batter_number == 1) {
        input_step = 1;
      } else {
        input_step = 3;
      }
    }
    else if(input_step == 1) {
      if(batter_number == 1) {
        if(keyListener::keyReleased[ALLEGRO_KEY_0] || keyListener::keyReleased[ALLEGRO_KEY_PAD_0]) {
          batter_number = 10;
          input_step = 3;
        }

        if(keyListener::keyReleased[ALLEGRO_KEY_1] || keyListener::keyReleased[ALLEGRO_KEY_PAD_1]) {
          batter_number = 11;
          input_step = 3;
        }

        if(keyListener::keyReleased[ALLEGRO_KEY_2] || keyListener::keyReleased[ALLEGRO_KEY_PAD_2]) {
          batter_number = 12;
          input_step = 3;
        }
      }
    }
    else if(input_step == 3) {
      for(int i = 27; i < 36; i++) {
        pitcher_number = keyListener::lastKeyReleased - 27;
      }

      if(pitcher_number == 1) {
        input_step = 4;
      } else {
        input_step = 5;
      }
    }
    else if(input_step == 4) {
      if(pitcher_number == 1) {
        if(keyListener::keyReleased[ALLEGRO_KEY_0] || keyListener::keyReleased[ALLEGRO_KEY_PAD_0]) {
          pitcher_number = 10;
          input_step = 5;
        }

        if(keyListener::keyReleased[ALLEGRO_KEY_1] || keyListener::keyReleased[ALLEGRO_KEY_PAD_1]) {
          pitcher_number = 11;
          input_step = 5;
        }

        if(keyListener::keyReleased[ALLEGRO_KEY_2] || keyListener::keyReleased[ALLEGRO_KEY_PAD_2]) {
          pitcher_number = 12;
          input_step = 5;
        }
      }
    }
  }

  if(keyListener::keyPressed[ALLEGRO_KEY_ENTER] || keyListener::keyPressed[ALLEGRO_KEY_PAD_ENTER]) {
    if(input_step == 1 || input_step == 0)
      input_step = 3;
    else if(input_step == 3 || input_step == 4)
      input_step = 5;
    else if(input_step == 5) {
      result_number = helpers::random::randomInt(1, 130);

      for(int i = 0; i < 9; i++) {
        extra_number[i] = helpers::random::randomInt(1, 100);
      }

      steal_throw_number = helpers::random::randomInt(1, 122);
      groundout_type = helpers::random::randomInt(1, 3);
      total_numbers_generated++;

      if(result_number < 101) {
        std::string newPath = "data/" + std::to_string(batter_number) + "b.xml";
        result[0] = xml_handler.load_xml(newPath, result_number, pitcher_number);

        if(result_number > 83) {
          result[1] = xml_handler.load_xml("data/1sl.xml", result_number, pitcher_number);
          result[2] = xml_handler.load_xml("data/ssl.xml", result_number, pitcher_number);
          result[3] = xml_handler.load_xml("data/3sl.xml", result_number, pitcher_number);
          result[4] = xml_handler.load_xml("data/gsl.xml", result_number, pitcher_number);
          result[5] = xml_handler.load_xml("data/5sl.xml", result_number, pitcher_number);
          result[6] = xml_handler.load_xml("data/asl.xml", result_number, pitcher_number);
          result[7] = xml_handler.load_xml("data/7sl.xml", result_number, pitcher_number);
          result[8] = xml_handler.load_xml("data/fsl.xml", result_number, pitcher_number);
        }
        else {
          for(int i = 1; i < 9; i++) {
            result[i] = "";
          }

        }
      }
      else {
        result[0] = xml_handler.load_special(result_number);

        for(int i = 1; i < 9; i++) {
          result[i] = "";
        }
      }
    }
  }

  if(keyListener::keyReleased[ALLEGRO_KEY_DELETE] || keyListener::keyReleased[ALLEGRO_KEY_BACKSPACE])
    input_step = 0;


  if(input_step == 0 || input_step == 1) {
    gameCells[0] -> setOutlineColour(colors::GREEN);
    gameCells[2] -> setOutlineColour(colors::BLACK);
    gameCells[4] -> setOutlineColour(colors::BLACK);
  }

  if(input_step == 3 || input_step == 4) {
    gameCells[0] -> setOutlineColour(colors::BLACK);
    gameCells[2] -> setOutlineColour(colors::GREEN);
    gameCells[4] -> setOutlineColour(colors::BLACK);
  }

  if(input_step == 5) {
    gameCells[0] -> setOutlineColour(colors::BLACK);
    gameCells[2] -> setOutlineColour(colors::BLACK);
    gameCells[4] -> setOutlineColour(colors::GREEN);
  }

  gameCells[0] -> setText(std::to_string(batter_number));
  gameCells[2] -> setText(std::to_string(pitcher_number));
  gameCells[4] -> setText(std::to_string(result_number));

  for(int i = 0; i < 9; i++)
    gameCells[i * 2 + 6] -> setText(result[i]);

  for(int i = 0; i < 6; i++)
    gameCells[i + 23] -> setText(std::to_string(extra_number[i]));


  gameCells[29] -> setText(std::to_string(extra_number[6]));
  gameCells[31] -> setText(std::to_string(extra_number[7]));
  gameCells[33] -> setText(std::to_string(extra_number[7]));
  gameCells[34] -> setText(std::to_string(extra_number[8]));
  gameCells[36] -> setText(std::to_string(steal_throw_number));

  if(groundout_type == 1) {
    gameCells[38] -> setCellColour(colors::RED);
    gameCells[38] -> setText("Hard one hop");
  } else if(groundout_type == 2) {
    gameCells[38] -> setCellColour(colors::YELLOW);
    gameCells[38] -> setText("Average grounder");
  } else if(groundout_type == 3) {
    gameCells[38] -> setCellColour(colors::GREEN);
    gameCells[38] -> setText("Slow roller");
  }

  std::string newTime = helpers::time::getCurrentTime();
  newTime.pop_back();
  gameCells[40] -> setText(newTime);
  gameCells[42] -> setText(std::to_string(total_numbers_generated));
}

// Draw images to screen
void menu::draw() {
  // Background
  al_clear_to_color(colors::WHITE);

  // Draw cells
  for(unsigned int i = 0; i < gameCells.size(); i++) {
    gameCells[i] -> draw();
  }
}

void menu::generate_cells() {
  int width_6 = constants::screen::WIDTH / 6;
  int height_16 = constants::screen::HEIGHT / 16;

  std::cout << constants::screen::WIDTH;

  gameCells.push_back(new Cell(0, 0, width_6, height_16 * 4, colors::BLACK, colors::WHITE, colors::BLACK, calibri_bold, justification::CENTER, "7"));
  gameCells[0] -> setLineThickness(4);
  gameCells.push_back(new Cell(0, 0, 150, 75, colors::TRANSPARENT, colors::TRANSPARENT, colors::BLACK, calibri, justification::LEFT, "Batter Number"));


  gameCells.push_back(new Cell(width_6, 0, width_6, height_16 * 4, colors::BLACK, colors::WHITE, colors::BLACK, calibri_bold, justification::CENTER, "12"));
  gameCells[2] -> setLineThickness(4);
  gameCells.push_back(new Cell(width_6, 0, 150, 75, colors::TRANSPARENT, colors::TRANSPARENT, colors::BLACK, calibri, justification::LEFT, "Pitcher Number"));

  gameCells.push_back(new Cell(5 + width_6 * 2 + 20, 0, width_6 * 2, height_16 * 4, colors::BLACK, colors::BLACK, colors::RED, calibri_bold, justification::CENTER, "112"));

  gameCells[4] -> setLineThickness(4);


  gameCells.push_back(new Cell(constants::screen::WIDTH - 90, constants::screen::HEIGHT - height_16 - 25, 90, 25, colors::BLACK, colors::WHITE, colors::BLACK, calibri, justification::LEFT, std::to_string(helpers::random::seed)));


  int slugging_height = height_16;
  int slugging_position = height_16 * 5 + 40;

  gameCells.push_back(new Cell(20, height_16 * 4 + 20, width_6 * 3, height_16 * 2, colors::BLACK, colors::WHITE, colors::BLUE, calibri, justification::LEFT, "Storms mound"));

  gameCells[6] -> setLineThickness(2);


  gameCells.push_back(new Cell(0, slugging_position + slugging_height * 1, 50, slugging_height, colors::BLACK, colors::WHITE, colors::BLACK, calibri, justification::LEFT, "1SL"));
  gameCells.push_back(new Cell(50, slugging_position + slugging_height * 1, width_6 * 3, slugging_height, colors::BLACK, colors::WHITE, colors::BLUE, calibri, justification::LEFT, "Smacks it out of the park"));
  gameCells.push_back(new Cell(0, slugging_position + slugging_height * 2, 50, slugging_height, colors::BLACK, colors::WHITE, colors::BLACK, calibri, justification::LEFT, "SSL"));
  gameCells.push_back(new Cell(50, slugging_position + slugging_height * 2, width_6 * 3, slugging_height, colors::BLACK, colors::WHITE, colors::BLUE, calibri, justification::LEFT, "Over the fence"));

  gameCells.push_back(new Cell(0, slugging_position + slugging_height * 3, 50, slugging_height, colors::BLACK, colors::WHITE, colors::BLACK, calibri, justification::LEFT, "3SL"));
  gameCells.push_back(new Cell(50, slugging_position + slugging_height * 3, width_6 * 3, slugging_height, colors::BLACK, colors::WHITE, colors::BLUE, calibri, justification::LEFT, "Deep fly, triple"));
  gameCells.push_back(new Cell(0, slugging_position + slugging_height * 4, 50, slugging_height, colors::BLACK, colors::WHITE, colors::BLACK, calibri, justification::LEFT, "GSL"));
  gameCells.push_back(new Cell(50, slugging_position + slugging_height * 4, width_6 * 3, slugging_height, colors::BLACK, colors::WHITE, colors::BLUE, calibri, justification::LEFT, "Easy double"));

  gameCells.push_back(new Cell(0, slugging_position + slugging_height * 5, 50, slugging_height, colors::BLACK, colors::WHITE, colors::BLACK, calibri, justification::LEFT, "5SL"));
  gameCells.push_back(new Cell(50, slugging_position + slugging_height * 5, width_6 * 3, slugging_height, colors::BLACK, colors::WHITE, colors::BLUE, calibri, justification::LEFT, "Barely makes it to first"));
  gameCells.push_back(new Cell(0, slugging_position + slugging_height * 6, 50, slugging_height, colors::BLACK, colors::WHITE, colors::BLACK, calibri, justification::LEFT, "ASL"));
  gameCells.push_back(new Cell(50, slugging_position + slugging_height * 6, width_6 * 3, slugging_height, colors::BLACK, colors::WHITE, colors::BLUE, calibri, justification::LEFT, "m/18/woody"));

  gameCells.push_back(new Cell(0, slugging_position + slugging_height * 7, 50, slugging_height, colors::BLACK, colors::WHITE, colors::BLACK, calibri, justification::LEFT, "7SL"));
  gameCells.push_back(new Cell(50, slugging_position + slugging_height * 7, width_6 * 3, slugging_height, colors::BLACK, colors::WHITE, colors::BLUE, calibri, justification::LEFT, "Trips over bat, gets tagged out"));
  gameCells.push_back(new Cell(0, slugging_position + slugging_height * 8, 50, slugging_height, colors::BLACK, colors::WHITE, colors::BLACK, calibri, justification::LEFT, "FSL"));
  gameCells.push_back(new Cell(50, slugging_position + slugging_height * 8, width_6 * 3, slugging_height, colors::BLACK, colors::WHITE, colors::BLUE, calibri, justification::LEFT, "Complete failure of a career"));


  gameCells.push_back(new Cell(0, constants::screen::HEIGHT - height_16, width_6, height_16, colors::BLACK, colors::YELLOW, colors::GROSS_YELLOW, calibri, justification::CENTER, "55"));
  gameCells.push_back(new Cell(width_6, constants::screen::HEIGHT - height_16, width_6, height_16, colors::BLACK, colors::YELLOW, colors::GROSS_YELLOW, calibri, justification::CENTER, "100"));
  gameCells.push_back(new Cell(width_6 * 2, constants::screen::HEIGHT - height_16, width_6, height_16, colors::BLACK, colors::YELLOW, colors::GROSS_YELLOW, calibri, justification::CENTER, "45"));
  gameCells.push_back(new Cell(width_6 * 3, constants::screen::HEIGHT - height_16, width_6, height_16, colors::BLACK, colors::YELLOW, colors::GROSS_YELLOW, calibri, justification::CENTER, "45"));
  gameCells.push_back(new Cell(width_6 * 4, constants::screen::HEIGHT - height_16, width_6, height_16, colors::BLACK, colors::YELLOW, colors::GROSS_YELLOW, calibri, justification::CENTER, "45"));
  gameCells.push_back(new Cell(width_6 * 5, constants::screen::HEIGHT - height_16, width_6, height_16, colors::BLACK, colors::YELLOW, colors::GROSS_YELLOW, calibri, justification::CENTER, "45"));

  gameCells.push_back(new Cell(width_6 * 4 + 40, 25, width_6 - 20, height_16 * 2, colors::BLACK, colors::YELLOW, colors::BLACK, calibri, justification::CENTER, "12 "));
  gameCells.push_back(new Cell(width_6 * 4 + 40, 0, width_6 - 20, 25, colors::BLACK, colors::WHITE, colors::BLACK, calibri, justification::LEFT, "Fielder"));

  gameCells.push_back(new Cell(width_6 * 5 + 20, 25, width_6 - 20, height_16 * 2, colors::BLACK, colors::YELLOW, colors::BLACK, calibri, justification::CENTER, "12"));
  gameCells.push_back(new Cell(width_6 * 5 + 20, 0, width_6 - 20, 25, colors::BLACK, colors::WHITE, colors::BLACK, calibri, justification::LEFT, "Run Adv. Steal WP. Error PB"));

  gameCells.push_back(new Cell(width_6 * 5 + 20, 50 + height_16 * 2, width_6 - 20, height_16 * 2, colors::BLACK, colors::BLUE, colors::WHITE, calibri, justification::CENTER, "12"));
  gameCells.push_back(new Cell(width_6 * 5 + 20, 50 + height_16 * 4, width_6 - 20, height_16 * 2, colors::BLACK, colors::BLUE, colors::WHITE, calibri, justification::CENTER, "12"));

  gameCells.push_back(new Cell(width_6 * 5 + 20, 25 + height_16 * 2, width_6 - 20, 25, colors::BLACK, colors::WHITE, colors::BLACK, calibri, justification::LEFT, "Double play"));

  gameCells.push_back(new Cell(width_6 * 4 + 40, 50 + height_16 * 2, width_6 - 20, height_16 * 2, colors::BLACK, colors::GREEN, colors::BLACK, calibri, justification::CENTER, "12 "));
  gameCells.push_back(new Cell(width_6 * 4 + 40, 25 + height_16 * 2, width_6 - 20, 25, colors::BLACK, colors::WHITE, colors::BLACK, calibri, justification::LEFT, "Steals and throws"));

  gameCells.push_back(new Cell(width_6 * 4 + 40, 75 + height_16 * 4, width_6 - 20, height_16 * 2 - 25, colors::BLACK, colors::GREEN, colors::BLACK, calibri, justification::CENTER, ""));
  gameCells.push_back(new Cell(width_6 * 4 + 40, 50 + height_16 * 4, width_6 - 20, 25, colors::BLACK, colors::WHITE, colors::BLACK, calibri, justification::LEFT, "Ground out type"));

  gameCells.push_back(new Cell(constants::screen::WIDTH - 180, constants::screen::HEIGHT - height_16 - 50, 180, 25, colors::BLACK, colors::WHITE, colors::BLACK, calibri, justification::LEFT, "5 o'clock somewhere"));
  gameCells.push_back(new Cell(constants::screen::WIDTH - 130, constants::screen::HEIGHT - height_16 - 25, 40, 25, colors::BLACK, colors::WHITE, colors::BLACK, calibri, justification::LEFT, "v1.2"));
  gameCells.push_back(new Cell(constants::screen::WIDTH - 180, constants::screen::HEIGHT - height_16 - 25, 50, 25, colors::BLACK, colors::WHITE, colors::BLACK, calibri, justification::LEFT, "0"));
}
