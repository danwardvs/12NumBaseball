#include "helpers/color.h"

#include <regex>
#include <allegro.h>

ALLEGRO_COLOR helpers::color::hexToAllegro(const std::string& color) {
  std::regex pattern("#?([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})");

  std::smatch match;

  if(std::regex_match(color, match, pattern)) {
    auto r = std::stoul(match[1].str(), nullptr, 16);
    auto g = std::stoul(match[2].str(), nullptr, 16);
    auto b = std::stoul(match[3].str(), nullptr, 16);

    return al_map_rgb(r, g, b);
  }

  return al_map_rgb(255, 0, 255);
}
