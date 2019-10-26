#include "menu.h"

#include <algorithm>
#include <stdexcept>

#include "helpers/time.h"

#include "constants/colors.h"
#include "constants/justifications.h"
#include "constants/screen.h"

#include "loaders/layout.h"

// Init menu
menu::menu() {
  calibri_bold.init("font/calibri_bold.ttf");
  calibri.init("font/calibri.ttf");
  generate_cells();
  input_step = 0;
}

// Update animation and wait for input
void menu::update() {
  // Exit game
  if(keyListener::keyReleased[ALLEGRO_KEY_ESCAPE])
    set_next_state(STATE_EXIT);

  // Num key related operations
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

  // Submit entry
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

  // Restart input sequence
  if(keyListener::keyReleased[ALLEGRO_KEY_DELETE] || keyListener::keyReleased[ALLEGRO_KEY_BACKSPACE]) {
    input_step = 0;
  }

  // Top section
  if(input_step == 0 || input_step == 1) {
    findCell("batter_number").setBorderColor(colors::GREEN);
    findCell("pitcher_number").setBorderColor(colors::BLACK);
    findCell("third_number").setBorderColor(colors::BLACK);
  }

  if(input_step == 3 || input_step == 4) {
    findCell("batter_number").setBorderColor(colors::BLACK);
    findCell("pitcher_number").setBorderColor(colors::GREEN);
    findCell("third_number").setBorderColor(colors::BLACK);
  }

  if(input_step == 5) {
    findCell("batter_number").setBorderColor(colors::BLACK);
    findCell("pitcher_number").setBorderColor(colors::BLACK);
    findCell("third_number").setBorderColor(colors::GREEN);
  }

  findCell("batter_number").setText(std::to_string(batter_number));
  findCell("pitcher_number").setText(std::to_string(pitcher_number));
  findCell("third_number").setText(std::to_string(result_number));

  // Slugger section
  findCell("main_display").setText(result[0]);
  findCell("slugger_1").setText(result[1]);
  findCell("slugger_2").setText(result[2]);
  findCell("slugger_3").setText(result[3]);
  findCell("slugger_4").setText(result[4]);
  findCell("slugger_5").setText(result[5]);
  findCell("slugger_6").setText(result[6]);
  findCell("slugger_7").setText(result[7]);
  findCell("slugger_8").setText(result[8]);

  // Bottom section
  findCell("bottom_1").setText(extra_number[0]);
  findCell("bottom_2").setText(extra_number[1]);
  findCell("bottom_3").setText(extra_number[2]);
  findCell("bottom_4").setText(extra_number[3]);
  findCell("bottom_5").setText(extra_number[4]);
  findCell("bottom_6").setText(extra_number[5]);

  // Right section
  findCell("fielder").setText(extra_number[6]);
  findCell("run_adv_steal").setText(extra_number[7]);
  findCell("double_play_1").setText(extra_number[7]);
  findCell("double_play_2").setText(extra_number[8]);
  findCell("steals").setText(steal_throw_number);

  // Ground out
  if(groundout_type == 1 || true) {
    findCell("ground_out").setCellColor(colors::RED);
    findCell("ground_out").setText("Hard one hop");
  } else if(groundout_type == 2) {
    findCell("ground_out").setCellColor(colors::YELLOW);
    findCell("ground_out").setText("Average grounder");
  } else if(groundout_type == 3) {
    findCell("ground_out").setCellColor(colors::GREEN);
    findCell("ground_out").setText("Slow roller");
  }

  // Dashboard
  std::string newTime = helpers::time::getCurrentTime();
  newTime.pop_back();
  findCell("dashboard_time").setText(newTime);
  findCell("dashboard_seed").setText(std::to_string(total_numbers_generated));
}

// Draw images to screen
void menu::draw() {
  // Background
  al_clear_to_color(al_map_rgb(255, 255, 255));

  // Draw cells
  for(auto& cell : cells) {
    cell.draw();
  }
}

// Find cell by id
Cell& menu::findCell(const std::string& id) {
  // Find
  auto it = std::find_if(cells.begin(), cells.end(), [&id](const Cell & obj) {
    return !obj.getId().compare(id);
  });

  // Exception handling
  if(it == cells.end()) {
    throw std::runtime_error("Could not find cell by id " + id + ".");
  }

  return *it;
}

// Load cells from file
void menu::generate_cells() {
  // Load in all screens
  auto cells_md = loaders::layout::readLayout("data/layout/main_display.json");
  auto cells_sd = loaders::layout::readLayout("data/layout/sub_display.json");
  auto cells_td = loaders::layout::readLayout("data/layout/top_display.json");
  auto cells_bd = loaders::layout::readLayout("data/layout/bottom_display.json");
  auto cells_dbd = loaders::layout::readLayout("data/layout/dashboard_display.json");
  auto cells_sld = loaders::layout::readLayout("data/layout/slugger_display.json");

  // Append to cells
  cells.clear();
  cells.insert(cells.end(), cells_md.begin(), cells_md.end());
  cells.insert(cells.end(), cells_sd.begin(), cells_sd.end());
  cells.insert(cells.end(), cells_td.begin(), cells_td.end());
  cells.insert(cells.end(), cells_bd.begin(), cells_bd.end());
  cells.insert(cells.end(), cells_dbd.begin(), cells_dbd.end());
  cells.insert(cells.end(), cells_sld.begin(), cells_sld.end());
}
