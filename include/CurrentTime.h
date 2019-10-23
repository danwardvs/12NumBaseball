#ifndef TIME_H
#define TIME_H

#include<string>

class Time {
  public:
    Time() {};
    virtual ~Time() {};
    static std::string getCurrentTime();
};

#endif // TIME_H
