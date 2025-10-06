// P0478.cpp : function objects with internal state
#include "../../Utilities.h"
import std;

class IntSequence {
private:
  int value;
public:
  IntSequence(int initialValue)       // constructor
    : value(initialValue) {
  }
  int operator() () {                 // function call
    return value++;
  }
};

int main()
{
  std::list<int> coll;

  std::generate_n(
    std::back_inserter(coll),         // start
    9,                                // number of elements
    IntSequence(1));                  // generates values, starting with 1

  print_elements(coll);
}
