// C0732_String_literals.cpp
import std;

void f() {
  //char* p1 = "Plato";
  const char* p2 = "Plato";
}

void g() {
  char p[] = "zeno";
  p[0] = 'R';
  const char* r = "";
}

const char* p = "hello";
const char* q = "hello";

int main() {
  f();
  g();

  if (p == q) std::cout << "one!\n";
  else std::cout << "two!\n";

  std::cout << "beep\a\n";
  const char* s = "fdsalk"
    "dasdas";
  char alpha[] = "fadfk"
    "ewrwl;";

  char al[] = "jens\000munk";
}
