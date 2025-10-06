// C0345_Aliases.cpp : Aliases
import std;

template<typename T>
class Vector {
public:
  using value_type = T;
};

template<typename C>
using Value_type = typename C::value_type;    // the type of C's elements

template<typename Container>
void algo(Container& c) {
  std::vector<Value_type<Container>> vec;     // keep results here
}

int main() {
  std::cout << "Hello World!\n";
}
