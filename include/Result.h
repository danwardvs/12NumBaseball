/*
 * Result
 * Immutable entity which stores results
 * Allan Legemaate
 * 26/10/2019
 */
#ifndef RESULT_H
#define RESULT_H

#include <vector>
#include <string>

class Result {
  public:
    Result(const int id, const std::vector<std::string> ps);
    std::string getResult(int p);

  private:
    const int _id;
    const std::vector<std::string> _ps;
};

#endif // RESULT_H
