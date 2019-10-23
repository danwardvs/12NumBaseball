#ifndef XML_H
#define XML_H

#include <string>

class XML {
  public:
    std::string load_xml(std::string newFilePath, int niceint, int evennicerint);
    std::string load_special(int newnum);
};

#endif // XML_H
