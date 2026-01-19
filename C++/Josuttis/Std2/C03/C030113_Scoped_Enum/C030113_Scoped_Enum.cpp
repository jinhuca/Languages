// C030113_Scoped_Enum.cpp 
import std;

enum class Salution : char { mr, ms, co, none };

int main() {
  std::underlying_type<Salution> t1;
  std::cout << "Hello World!\n";
}
