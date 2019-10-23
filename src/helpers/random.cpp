#include "helpers/random.h"
#include <ctime>

// Seed
int helpers::random::seed = time(nullptr);

// Random device
std::mt19937 helpers::random::rng = std::mt19937(helpers::random::seed);


/** \brief Random number generator based off the new c++ <random> lib
 *
 * \param low, int for low threshold
 * \param high, int for high threshold
 * \return random int
 *
 */
int helpers::random::randomInt (int low, int high) {
  std::uniform_int_distribution<int> dist6(low, high); // distribution in range [1, 6]
  return dist6(rng);
}

