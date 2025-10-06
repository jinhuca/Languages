// C17030402_Use_Initializer_lists.cpp 
import std;

void f1(std::initializer_list<int> args) {
  for(int i = 0; i != args.size(); ++i) {
    std::cout << args.begin()[i] << '\n';
  }
}

void f2(std::initializer_list<int> args) {
  for(auto p = args.begin(); p != args.end(); ++p) {
    std::cout << *p << '\n';
  }
}

void f3(std::initializer_list<int> args) {
  for(auto x : args) {
    std::cout << x << '\n';
  }
}

int main() {
  std::initializer_list<int> ar { 3, 1, 3, 54, 6, 5, 6, 9 };
  //f1(ar);
  //f2(ar);
  f3(ar);
}
