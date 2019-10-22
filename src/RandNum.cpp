#include "RandNum.h"

#include <ctime>

long RandNum::seed = 0;

RandNum::RandNum()
{
  //ctor
}

RandNum::~RandNum()
{
  //dtor
}

int RandNum::randInt(int newLowest, int newHighest) {
  int lowest = newLowest, highest = newHighest;
  int range = (highest - lowest) + 1;
  int randomNumber;
  randomNumber = rand() % range + lowest;
  return randomNumber;
}

void RandNum::generate_seed() {
  seed = time(NULL);
  srand(seed);

  // Discard first entry
  randInt(0, 10);
}
