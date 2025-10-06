import std;

void print() {
  int v[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  for(int i = 0; i != 10; ++i) {
    std::cout << v[i] << '\n';
  }
}

void print2() {
  int v[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  for(auto x : v) {
    std::cout << x << '\n';
  }
  for(auto x : { 10, 21, 32, 43, 54, 65 }) {
    std::cout << x << '\n';
  }
}

void print3() {
  for(auto x : { 10, 21, 32, 43, 54, 65 }) {
    std::cout << x << '\n';
  }
}

void increment() {
  int v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  for(auto& x : v) {
    ++x;
  }
}

int main() {
  print();
  print2();
  print3();
  increment();
}
