// C110405_type_of_lambda.cpp 
#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

void f(string& s1, string& s2) {
  function<void(char* b, char* e)> rev =
    [&rev](char* b, char* e) { if(1 < e - b) { swap(*b, *--e); rev(++b, e); }};
  rev(&s1[0], &s1[0] + s1.size());
  rev(&s2[0], &s2[0] + s2.size());
}

void g(string& s1, string& s2) {
  auto rev = [](char* b, char* e) { while(1 < e - b) swap(*b++, *--e); };
  rev(&s1[0], &s1[0] + s1.size());
  rev(&s2[0], &s2[0] + s2.size());
}

void assign_lambda_with_no_capture_to_pointer_function() {
  double(*p1)(double) = [](double a) { return sqrt(a); };
  // double(*p2)(double) = [&](double a) { return sqrt(a); };     // error: the lambda captures
  // double(*p3)(int) = [](double a) { return sqrt(a); };         // error: argument types do not match
}

int main() {
  string s1 = "hello";
  string s2 = "world";
  f(s1, s2);
  //g(s1, s2);
}
