#include "CurrentTime.h"

#include <ctime>

std::string Time::getCurrentTime() {
  std::time_t result = std::time(nullptr);
  return std::asctime(std::localtime(&result)) ;
}
