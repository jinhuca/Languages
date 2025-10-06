// C190201_Subscripting.cpp 
import std;
import Assoc;

int main() {
  Assoc values;
  for(std::string buf; std::cin >> buf;)
    ++values[buf];
  for(auto& x : values.vec)
    std::cout << '{' << x.first << ',' << x.second << "}\n";
}
