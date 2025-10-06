// C123_Overloaded_Functions.cpp 
import std;

void print(int i) {             // print an int
  std::cout << "Print integer - " << i << '\n';
}

void print(const char* s) {     // print a C-style string
  std::cout << "Print C-style string - " << s << '\n';
}

int main() {
  print(3);
  print("hello, C++");
}
