// C030101_nullptr.cpp: nullptr and std::nullptr
import std;

void f(int x) {
  std::cout << "calls void f(int)\n";
}

void f(void* p) {
  std::cout << "calls void f(void*)\n";
}

void g() {
  f(0);            // calls void f(int)
  f(nullptr);      // calls void f(void*)
  f(1);            // calls void f(int)
}

void h(int* intp) {
  std::cout << "passed an int pointer.\n";
}

void h(char* charp) {
  std::cout << "Passed a char pointer.\n";
}

void h(std::nullptr_t nullp) {
  std::cout << "Passed a null pointer.\n";
}

void k() {
  int* ptr_i = new int(10);
  char* ptr_c = new char('a');
  h(ptr_i);
  h(ptr_c);
  h(nullptr);
}

int main() {
  //g();
  k();
}
