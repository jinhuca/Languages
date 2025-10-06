// C06363_decltype.cpp 
import std;

template<typename T>
class Matrix {

};

template<typename T, typename U>
auto operator+(const Matrix<T>& a, const Matrix<U>& b)->Matrix<decltype(T {} + U {}) > ;

int main() {
  std::cout << "Hello World!\n";
}
