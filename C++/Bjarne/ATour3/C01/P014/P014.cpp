import std;

// count the number of occurrences of x in p[]
// p is assumed to point to a zero-terminated array of char (or to nothing)
int count_x(const char* p, char x) {
  if(p == nullptr) {
    return 0;
  }
  int count = 0;
  while(*p) {
    if(*p == x) {
      ++count;
    }
    ++p;
  }
  return count;
}

int main() {
  char v[] = { 'a', 'b', 'c', 'd', 'e', 'a' };
  char* p = &v[0];
  std::cout << count_x(v, 'a') << '\n';
  std::cout << count_x("Hello!", 'e') << '\n';
}
