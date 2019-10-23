#include "tools.h"

// Convert char to float
float tools::string_to_float(std::string newChar) {
  float number = 0.0f;
  int sign = 1;

  // Parse string
  // Negative
  if(newChar[0] == '-') {
    sign = -1;
    newChar = newChar.substr(1, newChar.length());
  }

  // Location of decimal
  int decimal_loc = newChar.length();

  for(unsigned int i = 0; i < newChar.length(); i++) {
    if(newChar[i] == '.') {
      decimal_loc = i;
      newChar = newChar.substr(0, i) + newChar.substr(i + 1, newChar.length() - i);
    }
  }

  // Numbers
  for(unsigned int i = 0; i < newChar.length(); i++) {
    int tempNumber = int(newChar[i]) - 48;
    number += tempNumber * pow(10, (newChar.length()) - (i + 1));
  }

  return (number / float(pow(10, newChar.length() - decimal_loc))) * sign;
}
