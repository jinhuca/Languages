export module maxValue;

import std;

export template<typename T>
  requires (!std::is_pointer_v<T>)
T maxValue(T a, T b) {
  return a > b ? a : b;
}

template<typename T>
concept IsPointer = std::is_pointer_v<T>;

export template<typename T>
requires (!IsPointer<T>)
T MinValue(T a, T b) {
  return b > a ? a : b;
}