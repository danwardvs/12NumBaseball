#include "loaders/result.h"
/*
#include <iostream>
#include <fstream>
#include <json/json.h>
#include <stdexcept>

std::vector<Result> loaders::layout::readLayout(const std::string& path) {
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

  // Create vector to hold Cells
  std::vector<Result> cells;

  // Iterate over cells
  for(unsigned int i = 0; i < obj.size(); i++) {
    try {
      // ID
      std::string id = obj[i]["id"].asString();

      // P Numbers
      std::string p1 = obj[i]["p1"].asString();
      std::string p2 = obj[i]["p2"].asString();
      std::string p3 = obj[i]["p3"].asString();
      std::string p4 = obj[i]["p4"].asString();
      std::string p5 = obj[i]["p5"].asString();
      std::string p6 = obj[i]["p6"].asString();
      std::string p7 = obj[i]["p7"].asString();
      std::string p8 = obj[i]["p8"].asString();
      std::string p9 = obj[i]["p9"].asString();
      std::string p10 = obj[i]["p10"].asString();
      std::string p11 = obj[i]["p11"].asString();
      std::string p12 = obj[i]["p12"].asString();

      // Create cell
      Result result(id);
      result.setX(x, sizing);
      result.setY(y, sizing);
      result.setWidth(width, sizing);
      result.setHeight(height, sizing);
      result.setText(text);

      if(border_width)
        result.setBorderWidth(border_width);

      if(border_color.length())
        result.setBorderColor(border_color);

      if(cell_color.length())
        result.setCellColor(cell_color);

      if(font_color.length())
        result.setFontColor(font_color);

      result.setJustification(align);

      // Add to  list
      cells.push_back(result);
    } catch(...) {
      std::cout << "Error loading result at position " << i << "." << std::endl;
    }
  }

  // Return vector of cells
  return cells;
}*/
