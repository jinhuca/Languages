// printtuple.h
#pragma once
#include <iostream>
#include <tuple>

// helper: print element with index IDX of tuple with MAX elements
template<int IDX, int MAX, typename... Args>
struct PRINT_TUPLE {
  static void print(std::ostream& strm, const std::tuple<Args...>& t) {
    strm << std::get<IDX>(t) << (IDX + 1 == MAX ? " " : ", ");
    PRINT_TUPLE<IDX + 1, MAX, Args...>::print(strm, t);
  }
};

// partial specialization to end recursion
template<int MAX, typename... Args>
struct PRINT_TUPLE<MAX, MAX, Args...> {
  static void print(std::ostream& strm, const std::tuple<Args...>& t) {
    // end recursion: do nothing
  }
};

// output operator for tuples
template<typename... Args>
std::ostream& operator<<(std::ostream& strm, const std::tuple<Args...>& t) {
  strm << '[';
  PRINT_TUPLE<0, sizeof...(Args), Args...>::print(strm, t);
  strm << ']';
  return strm;
}