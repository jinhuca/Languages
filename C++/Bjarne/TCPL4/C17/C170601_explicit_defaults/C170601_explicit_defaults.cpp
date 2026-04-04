#include <iostream>
#include <valarray>
#include <cstddef>

using std::valarray;
using std::size_t;

class gslice {
  valarray<size_t> size;
  valarray<size_t> stride;
  valarray<size_t> d1;
public:
  gslice() = default;
  ~gslice() = default;
  gslice(const gslice&) = default;
  gslice(gslice&&) = default;
  gslice& operator=(const gslice&) = default;
  gslice& operator=(gslice&&) = default;
  // ...
};

int main() {

}
