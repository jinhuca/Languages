// C1233_Overload_Scope.cpp 
import std;

void f(int i){}

void g()
{
  //void f(double);
  f(1);
}

int main() {
  std::cout << "Hello World!\n";
}
