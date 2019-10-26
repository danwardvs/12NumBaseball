#include "helpers/id.h"

/** \brief int containing last generated ID
 *
 */
int helpers::id::lastId;

/** \brief Generate a sequential ID
 *
 * \return int Next ID
 *
 */
int helpers::id::getId() {
  lastId++;
  return lastId;
}

