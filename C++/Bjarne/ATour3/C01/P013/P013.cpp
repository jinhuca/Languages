import std;

struct Record {};

void f() {
  double* pd = nullptr;                 // a pointer of type double points to nothing
  std::list<Record>* lst = nullptr;     // pointer to a list of Record
  //int x = nullptr;                    // error: nullptr is a pointer not an integer
}

// count the number of occurrences of x in p[]
// p is assumed to point to a zero-terminated array of char (or to nothing)
int count_x(const char* p, char x) {
  if(p == nullptr)
    return 0;

  int count = 0;
  for(; *p != 0; ++p)
    if(*p == x)
      ++count;

  return count;
}

int main() {
  f();
  char v[] = { 'a','b','c','d','e','a' };
  char* p = &v[0];
  std::cout << count_x(v, 'a') << '\n';
  std::cout << count_x("Hello!", 'e') << '\n';
}
