// C0771_Lvalue_references.cpp
import std;

void f() {
  int var { 1 };        // initialize int variable var with 1
  int& r { var };       // r and var now refer to the same address of memory
  int x = r;            // x gets the value of r - 1
  r = 2;                // changes the value in the memory that r refers to, so var becomes 2

  // double& dr { 1 };       // error: lvalue needed
  const double& cdr { 1 };    // ok, no lvalue necessary to initialize const T&
}

void increment(int& aa) {
  ++aa;
}

int next(int aa) {
  return ++aa;
}

void g() {
  int x = 1;
  increment(x);     // x = 2
  x = next(x);
}

template<typename K, typename V>
class Map {
public:
  // return the value corresponding to the key k
  V& operator[](const K& k) {
    for (auto& x : elem)
      if (k == x.first)
        return x.second;
    elem.push_back({ k,V{} });
    return elem.back().second;
  }
  std::pair<K, V>* begin() { return &elem[0]; }
  std::pair<K, V>* end() { return &elem[0] + elem.size(); }
private:
  std::vector<std::pair<K, V>> elem;
};

void h() {
  Map<std::string, int> buf;
  std::cout << "Enter a sequence of words, separate each by a white space:\n";
  std::cout << "To end the input, enter RETURN key, and then Ctrl+Z.\n";
  for (std::string s; std::cin >> s;) 
    ++buf[s];
  for (const auto& x : buf)
    std::cout << x.first << ": " << x.second << '\n'; 
}

int main() {
  //f();
  //g();
  h();
}
