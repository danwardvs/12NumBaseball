#include "RandNum.h"

long RandNum::seed = 0;

RandNum::RandNum()
{
  //ctor
}

RandNum::~RandNum()
{
  //dtor
}
int RandNum::randInt(int newLowest, int newHighest){
  int lowest = newLowest, highest = newHighest;
  int range = (highest - lowest) + 1;
  int randomNumber; // this doens't work on linux = lŝŝowest+int(range*rand()/(RAND_MAX + 1.0));
  randomNumber = rand() % range + lowest;
  return randomNumber;
}

void RandNum::generate_seed(){

  srand(time(NULL));
  seed=time(NULL);

  // A random random number is more random
  for(int i=0; i<1000; i++){
    randInt(1,122);
  }
}
