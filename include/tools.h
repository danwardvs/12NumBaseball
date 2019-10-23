/**
 * TOOLS
 * Allan Legemaate
 * 05/05/2017
**/
#ifndef TOOLS_H
#define TOOLS_H

#include <string>
#include <cmath>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

class tools {
  public:

    // Convert char to float
    static float string_to_float(std::string newChar);


    // Convert
    template <class T> static std::string toString(const T& value) {
      std::stringstream ss;
      ss << value;
      return ss.str();
    }


  protected:

  private:
};

#endif // TOOLS_H
