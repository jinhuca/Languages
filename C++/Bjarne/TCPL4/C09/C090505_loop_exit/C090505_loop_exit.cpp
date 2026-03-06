// C090505_loop_exit.cpp 
import std;

// A break statement exits the innermost loop. 
void f(std::vector<std::string>& v, char terminator) {
  char c;
  std::string s;
  while(std::cin >> c) {
    // ...
    if(c == terminator) break;
    // ...
  }
}

// A continue statement skips the rest of the current loop iteration and starts the next iteration.
// A return statement exits the function in which it appears.
void find_prime(std::vector<std::string>& v) {
  for(int i = 0; i != v.size(); ++i) {
    if(!(v[i] == "skipped")) continue;
    return;
  }
}

int main() {
  std::vector<std::string> v;
  char terminator = 'x';
  f(v, terminator);
}
