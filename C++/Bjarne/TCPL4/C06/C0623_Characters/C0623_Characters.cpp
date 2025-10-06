// C0623_Characters.cpp 
import std;

void sizeOfChar() {
  std::cout << sizeof(char) << '\n';
  std::cout << sizeof(wchar_t) << '\n';
}

void intval() {
  for(char c; std::cin >> c;)
    std::cout << "the value of '" << c << "' is " << int { c } << '\n';
}

void digits() {
  for(int i = 0; i != 10; ++i)
    std::cout << i << ' ';
  std::cout << '\n';

  for(int i = 0; i != 10; ++i)
    std::cout << static_cast<char>('0' + i) << ' ';
  std::cout << '\n';
}

void k() {
  char c = 255;
  int i = c;
}

/*
void f(char c, signed char sc, unsigned char uc) {
  char* pc = &uc;           // error: no pointer conversions
  signed char* psc = pc;    // error: no pointer conversions
  unsigned char* puc = pc;  // error: no pointer conversions
  psc = puc;                // error: no pointer conversions
}
*/

void g(char c, signed char sc, unsigned char uc) {
  c = 255;
  c = sc;         // OK
  c = uc;
  sc = uc;
  uc = sc;
  sc = c;
  uc = c;
}

void h() {
  signed char sc = -120;
  unsigned char uc = sc;
  sc = ++uc;

  char count[256];
  char c1 = count[sc];
  char c2 = count[uc];
}
int x = 3;

void f3() {
  int x = x;
}

int main() {
  //intval();
  //digits();
  //k();
  //g('a', 's', 'u');
  //h();
  auto ac = alignof(char);
  auto ic = alignof(int);
}
