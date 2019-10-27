#include "loaders/layout.h"

#include <iostream>
#include <fstream>
#include <json/json.h>
#include <stdexcept>

#include "helpers/id.h"

#include "constants/screen.h"

std::vector<Cell> loaders::layout::readLayout(const std::string& path) {
  // Open file
  std::ifstream inFile(path);

  // Throw exeption on failure
  if(inFile.fail()) {
    throw std::runtime_error("Could not open file " + path);
  }

  // Create json reader
  Json::Reader reader;
  Json::Value obj;

  if(!reader.parse(inFile, obj)) {
    throw std::runtime_error("There was an error parsing file " + path);
  }

  // General layout
  Json::Value jsonModule = obj["module"];
  const int moduleX = jsonModule["x"].asUInt();
  const int moduleY = jsonModule["y"].asUInt();
  const int moduleWidth = jsonModule["width"].asUInt();
  const int moduleHeight = jsonModule["height"].asUInt();

  // Cells
  Json::Value jsonCells = obj["cells"];

  // Create vector to hold Cells
  std::vector<Cell> cells;

  // Iterate over cells
  for(unsigned int i = 0; i < jsonCells.size(); i++) {
    try {
      // ID, generate if not found
      std::string id = jsonCells[i]["id"].asString();

      if(id.length() == 0) {
        id = std::to_string(helpers::id::getId());
      }

      // Position
      int x = jsonCells[i]["position"]["x"].asUInt();
      int y = jsonCells[i]["position"]["y"].asUInt();
      int width = jsonCells[i]["position"]["width"].asUInt();
      int height = jsonCells[i]["position"]["height"].asUInt();

      // Styling
      int border_width = jsonCells[i]["style"]["border"]["width"].asUInt();
      std::string border_color = jsonCells[i]["style"]["border"]["color"].asString();
      std::string cell_color = jsonCells[i]["style"]["cell"]["color"].asString();
      std::string font_color = jsonCells[i]["style"]["font"]["color"].asString();
      std::string align = jsonCells[i]["style"]["font"]["align"].asString();

      // Content
      std::string text = jsonCells[i]["content"]["text"].asString();

      // Create cell
      Cell cell(id);
      cell.setX(((((x / 100.0f) * moduleWidth) + moduleX) / 100.0f) * constants::screen::WIDTH);
      cell.setY(((((y / 100.0f) * moduleHeight) + moduleY) / 100.0f) * constants::screen::HEIGHT);
      cell.setWidth((((width / 100.0f) * moduleWidth) / 100.0f) * constants::screen::WIDTH);
      cell.setHeight((((height / 100.0f) * moduleHeight) / 100.0f) * constants::screen::HEIGHT);
      cell.setText(text);

      if(border_width)
        cell.setBorderWidth(border_width);

      if(border_color.length())
        cell.setBorderColor(border_color);

      if(cell_color.length())
        cell.setCellColor(cell_color);

      if(font_color.length())
        cell.setFontColor(font_color);

      cell.setJustification(align);

      // Add to  list
      cells.push_back(cell);
    } catch(...) {
      std::cout << "Error loading cell at position " << i << "." << std::endl;
    }
  }

  // Return vector of cells
  return cells;
}
