// C170405_static_member_initialization.cpp 
#include <iostream>
using std::cout;

class Node {
  // ...
public:
  static int node_count;    // declaration
  enum { c1 = 7, c2 = 11, c3 = 13, c4 = 17 };
};

int Node::node_count = 0;   // definition

int main() {
  Node n1;
  Node::node_count++;
  cout << "node_count = " << Node::node_count << '\n';
  cout << "c1 = " << Node::c1 << '\n';
}
