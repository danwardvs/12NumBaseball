#ifndef TIME_H
#define TIME_H

#include<time.h>
#include<string>

class Time
{
  public:
    Time();
    virtual ~Time();

    static std::string getCurrentTime();

  protected:

  private:
};

#endif // TIME_H
