#include "layout.h"

#include <iostream>
#include <fstream>
#include <json/json.h>
#include <stdexcept>

#include "helpers/id.h"

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
    throw std::runtime_error("There was an error parsting file " + path);
  }

  // Create vector to hold Cells
  std::vector<Cell> cells;

  // Iterate over cells
  for(unsigned int i = 0; i < obj.size(); i++) {
    try {
      // ID, generate if not found
      std::string id = obj[i]["id"].asString();

      if(id.length() == 0) {
        id = std::to_string(helpers::id::getId());
      }

      // Position
      int x = obj[i]["position"]["x"].asUInt();
      int y = obj[i]["position"]["y"].asUInt();
      int width = obj[i]["position"]["width"].asUInt();
      int height = obj[i]["position"]["height"].asUInt();
      std::string sizing = obj[i]["position"]["sizing"].asString();

      // Styling
      int border_width = obj[i]["style"]["border"]["width"].asUInt();
      std::string border_color = obj[i]["style"]["border"]["color"].asString();
      std::string cell_color = obj[i]["style"]["cell"]["color"].asString();
      std::string font_color = obj[i]["style"]["font"]["color"].asString();
      std::string align = obj[i]["style"]["font"]["align"].asString();

      // Content
      std::string text = obj[i]["content"]["text"].asString();

      // Create cell
      Cell cell(id);
      cell.setX(x, sizing);
      cell.setY(y, sizing);
      cell.setWidth(width, sizing);
      cell.setHeight(height, sizing);
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
