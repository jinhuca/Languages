// C230401_DataMembers.cpp 
#include <iostream>

template<typename T>
struct X {
  const int m1 = 7;
  T m2;
  X(const T& t) : m2(t) {}

  void mf1() {}
  void mf2();
};

int main() {
  X<int> xi(8);
  X<std::string> xs("hello");
  xi.mf2();
}

template<typename T>
void X<T>::mf2() {
}
