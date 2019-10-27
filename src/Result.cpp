#include "Result.h"


/** \brief Construct a result object
 *
 * \param id const int, identifier of number to roll to get results
 * \param _ps const std::vector<conststd::string>, vector containing
 *   result strings
 *
 */
Result::Result(const int id, const std::vector<std::string> ps)
  : _id(id), _ps(ps) {

}


/** \brief Get result from results if exists, otherwise return ""
 *
 * \param p int, result to find
 * \return std::string, result string value
 *
 */
std::string Result::getResult(int p) {
  try {
    return _ps.at(p);
  } catch (...) {
    return "";
  }
}
