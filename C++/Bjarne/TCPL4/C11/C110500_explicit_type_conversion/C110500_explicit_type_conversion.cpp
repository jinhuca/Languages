// C110500_explicit_type_conversion.cpp 
#include <iostream>

void convert_implicitly() {
  double d = 1234567890;   // integer to floating-point
  int i = d;               // floating-point to integer
}

template<typename Target, typename Source>
Target narrow_cast(Source v) {
  auto r = static_cast<Target>(v);    // convert the value to the target type
  if(static_cast<Source>(r)!=v)
    throw std::runtime_error("narrow_cast<>() failed");
  return r;
}

void test(double d, int i, char* p) {
  auto c1 = narrow_cast<char>(64);
  auto c2 = narrow_cast<char>(-64);     // will throw if chars are unsigned
  auto c3 = narrow_cast<char>(264);     // will throw if chars are 8-bit

  auto d1 = narrow_cast<double>(1/3.0F);   // OK
  auto f1 = narrow_cast<float>(1/3.0);     // will probably throw

  auto c4 = narrow_cast<char>(i);          // may throw
  auto f2 = narrow_cast<float>(d);         // may throw

  //auto p1 = narrow_cast<char*>(i);         // compile-time error
  //auto i1 = narrow_cast<int>(p);           // compile-time error

  auto d2 = narrow_cast<double>(i);        // may throw (but probably will not)
  auto i2 = narrow_cast<int>(d);           // may throw
}

int main() {
  convert_implicitly();
  char c = 'g';
  char* p = &c;
  test(2.12, 5, p);
}
