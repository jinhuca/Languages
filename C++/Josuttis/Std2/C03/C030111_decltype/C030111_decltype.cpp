// C030111_decltype.cpp 
import std;

void decltype1() {
  std::map<std::string, float> coll;
  decltype(coll)::value_type elem;
}

template<typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x + y) {
  return x + y;
}

int main() {
  decltype1();
  std::cout << add(3, 4) << '\n';
}
