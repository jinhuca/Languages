// C0774_Pointers_References.cpp 
import std;

void fp(char* p) {
  while(*p)
    std::cout << *p++;
}

void fr(char& r) {
  while(r)
    std::cout << r++;
}

int main() {
  char p[] = "hello world!";
  fp(&p[0]);
}
