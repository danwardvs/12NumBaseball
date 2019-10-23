/*
 * Random
 * Common random functions
 * Allan Legemaate
 * 22/10/2019
 */
#ifndef RANDOM_H
#define RANDOM_H

#include <random>

namespace helpers {
  namespace random {
    extern int seed;
    extern std::mt19937 rng;
    int randomInt (int low, int high);
  }
}

#endif
