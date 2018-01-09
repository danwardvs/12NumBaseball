#ifndef RANDNUM_H
#define RANDNUM_H

#include <time.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class RandNum
{
  public:
    RandNum();
    virtual ~RandNum();

    static void seed();
    static int randInt(int newLowest, int newHighest);

  protected:

  private:
};

#endif // RANDNUM_H
