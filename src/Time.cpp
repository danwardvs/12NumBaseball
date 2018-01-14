#include "Time.h"

Time::Time()
{
  //ctor
}

Time::~Time()
{
  //dtor
}

std::string Time::getCurrentTime(){

  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  return asctime (timeinfo) ;


}
