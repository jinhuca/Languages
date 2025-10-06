// C1218_Local_Variables.cpp 
import std;

void f(int a) {
  while(a--) {
    static int n = 0;     // initialize once 
    int x = 0;            // initialize 'a' time in each call of f()
    std::cout << "n == " << n++ << ", x == " << x++ << '\n';
  }
}

int main() {
  f(3);
}
