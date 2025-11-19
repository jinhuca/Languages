// C0301.cpp 
import std;

template<typename T>
  requires (!std::is_pointer_v<T>)
T maxValue(T a, T b) {
  return (a > b) ? a : b;
}

int main() {
  std::cout << maxValue(12, 16) << '\n';
  std::cout << maxValue(3.14, 2.72) << '\n';
  //std::cout << maxValue("3.14", "2.72") << '\n';
}
