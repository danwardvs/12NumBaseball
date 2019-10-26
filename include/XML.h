#ifndef XML_H
#define XML_H

#include <string>

class XML {
  public:
    std::string load_xml(std::string newFilePath, int newGeneratedNumber, int newPitcherNumber);
    static std::string load_special(int newGeneratedNumber);
};

#endif // XML_H
