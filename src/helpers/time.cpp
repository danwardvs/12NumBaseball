#include "helpers/time.h"

#include <ctime>

/** \brief Get current local time formatted as a string
 *
 * \return std::string, formatted time
 *
 */
std::string helpers::time::getCurrentTime() {
  std::time_t result = std::time(nullptr);
  return std::asctime(std::localtime(&result)) ;
}
