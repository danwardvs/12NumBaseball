#ifndef XML_H
#define XML_H

#include <string>
#include <fstream>
#include <iostream>

#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"

class XML {
  public:
    XML();
    virtual ~XML();
    std::string load_xml(std::string newFilePath, int niceint, int evennicerint);
    std::string load_special(int newnum);

  protected:

  private:
};

#endif // XML_H
