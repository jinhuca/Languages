export module maxValue;

import std;

export template<typename T>
  requires (!std::is_pointer_v<T>)
T maxValue(T a, T b) {
  return a > b ? a : b;
}