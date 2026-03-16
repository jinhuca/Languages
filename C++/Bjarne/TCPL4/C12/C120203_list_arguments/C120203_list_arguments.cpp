// C120203_list_arguments.cpp 
#include <iostream>
#include <initializer_list>
#include <string>

template<typename T>
void f1(std::initializer_list<T> il) {
}

struct S {
  int a;
  std::string s;
};
void f2(S) {
}

template<typename T, int N>
void f3(const T(&r)[N] r) {
}

void f4(int i) {
}

void initialize_list() {
  f1({1,2,3,4});     // T is int and the initializer_list has size() 4
  f2({1,"MKS"});     // f2(S{1,"MKS})
  f3({1,2,3,4,5});   // T is int and N is 5
  f4(1);             // f4(int{1})
}

// initializer_list take priority
template<typename T>
void f(std::initializer_list<T> lst) {
std::cout << "calling f(initializer_list<T>).\n";
}

void f(S s) {
std::cout << "calling f(S).\n";
}

template<typename T, int N>
void f(T(&r)[N]) {
std::cout << "calling f(T(&r)[N]).\n";
}

void f(int r) {
  std::cout << "calling f(int r).\n";
}

void initializer_list_takes_priority() {
  f({1,2,3,4});       // T is int and the initializer_list has size() 4
  f({1,"MTL"});       // call f(S)
  f({1});             // T is int and the initializer_list has size() 1
}

int main() {
  initialize_list();
  initializer_list_takes_priority();
}
