// P122.cpp 
import std;

void f(std::vector<int>& v) {
  std::sort(v.begin(), v.end());        // OK
  //std::sort(v);                       // error: no matching function in std.
  std::ranges::sort(v);                 // OK
  using std::ranges::sort;              // sort(v) OK from here on
  sort(v);
}

int main() {
  std::cout << "Hello World!\n";
}
