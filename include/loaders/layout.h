#ifndef LAYOUT_H
#define LAYOUT_H

#include <string>
#include <vector>

#include "Cell.h"

namespace loaders {
  namespace layout {
    std::vector<Cell> readLayout(const std::string& path);
  }
}

#endif // LAYOUT_H
