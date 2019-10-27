/*
 * Layout loader
 * Loads cell layouts from file
 * Allan Legemaate
 * 25/10/2019
 */
#ifndef LOADERS_LAYOUT_H
#define LOADERS_LAYOUT_H

#include <string>
#include <vector>

#include "Cell.h"

namespace loaders {
  namespace layout {
    std::vector<Cell> readLayout(const std::string& path);
  }
}

#endif // LOADERS_LAYOUT_H
