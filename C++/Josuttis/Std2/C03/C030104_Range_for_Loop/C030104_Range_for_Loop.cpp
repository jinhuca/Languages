// C030104_Range_for_Loop.cpp
#include <iostream>
#include <vector>

void f() {
  for(int i : {2, 3, 5, 7, 9, 13, 17, 19}) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

template<typename T>
void printElements1(const std::initializer_list<T>& coll) {
  for(const auto& elem : coll) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
}

template<typename T>
void printElements2(const std::initializer_list<T>& coll) {
  for(auto _pos = coll.begin(); _pos != coll.end(); ++_pos) {
    const auto& elem = *_pos;
    std::cout << elem << ' ';
  }
  std::cout << '\n';
}

template<typename T>
void printElements3(const std::initializer_list<T>& coll) {
  for(auto _pos = std::begin(coll); _pos != std::end(coll); ++_pos) {
    const auto& elem = *_pos;
    std::cout << elem << ' ';
  }
  std::cout << '\n';
}

void h() {
  int array[] = {1, 2, 3, 4, 5};
  long sum = 0;
  for(int x : array) {
    sum += x;
  }
  for(auto elem : {sum, sum * 2,sum * 4}) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
}

int main() {
  f();
  printElements1({2, 3, 5, 7, 9, 13, 17, 19});
  printElements2({2, 3, 5, 7, 9, 13, 17, 19});
  printElements3({2, 3, 5, 7, 9, 13, 17, 19});
  h();
}
