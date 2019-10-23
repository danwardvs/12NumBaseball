#ifndef RANDNUM_H
#define RANDNUM_H

#include <fstream>
#include <vector>
#include <string>

#include "tools.h"


class RandNum {
  public:
    static void generate_seed();
    static std::string getSeed() {
      return tools::toString(seed);
    }
    static int randInt(int newLowest, int newHighest);

  private:
    static long seed;
};

#endif // RANDNUM_H
