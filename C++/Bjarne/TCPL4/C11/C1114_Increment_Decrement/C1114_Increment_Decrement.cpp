// C1114_Increment_Decrement.cpp 
import std;

void cpy(char* p, const char* q) {
  while (*p++ = *q++);
}

int main() {
  const char a1[10] = "abcdefg";
  char a2[10];
  cpy(a2, a1);
  std::cout << a1 << '\n';
  std::cout << a2 << '\n';
}
