// C170405_Static_Member_Initialization.cpp 
import std;

class Node {
  // ...
public:
  static int node_count;    // declaration
};

int Node::node_count = 0;   // definition

class Curious {
public:
  static const int c1 = 7;                // OK
  // static int c2 = 11;                  // error: not const
  const int c3 = 13;                      // OK, but not static
  static const int c4 = std::sqrt(9);     // error: in-class initializer not constant
  // static const float c5 = 7.0;         // error: in-class not integral (use constexpr rather than const)
};

int main() {
  Node n1;
  std::cout << n1.node_count << '\n';
}
