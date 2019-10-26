/*
 * ID
 * Sequential ID generator
 * Allan Legemaate
 * 25/10/2019
 */
#ifndef HELPERS_ID_H
#define HELPERS_ID_H

namespace helpers {
  class id {
    public:
      static int getId();
    private:
      static int lastId;
  };
}

#endif  // HELPERS_ID_H
