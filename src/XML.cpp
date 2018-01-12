#include "XML.h"

XML::XML()
{
  //ctor
}

XML::~XML()
{
  //dtor
}

std::string XML::load_xml(std::string newFilePath,int newGeneratedNumber, int newPitcherNumber){

    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> * root_node;

    // Read the xml file into a vector
    std::ifstream theFile (newFilePath.c_str());
    std::vector<char> xml_buffer((std::istreambuf_iterator<char>(theFile)), std::istreambuf_iterator<char>());
    xml_buffer.push_back('\0');

    // Parse the buffer using the xml file parsing library into doc
    doc.parse<0>( &xml_buffer[0]);

    std::string result;

    // Find our root node
    root_node = doc.first_node("data");

    for ( rapidxml::xml_node<> * generated_node = root_node -> first_node("GeneratedNumber"); generated_node; generated_node = generated_node -> next_sibling()){
      // Interate over the beers
      int generatedNumberResult = atoi(generated_node -> first_attribute("number") -> value());

      if(generatedNumberResult==newGeneratedNumber){

      for(int i=1; i<13; i++){
        std::string newNodeTag = "p" + tools::toString(i);
        std::cout<<newNodeTag+"\n";
        if(newPitcherNumber==i)
          result = generated_node -> first_node(newNodeTag.c_str()) -> value();
      }




      }
    }

  return result;



}
