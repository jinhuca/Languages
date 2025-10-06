// C160213_Member_Types.cpp 
import std;

template<typename T>
class Tree {
  using value_type = T;               // member alias
  enum Policy { rb, splay, treeps };  // member enum
  class Node {
    Node* right;
    Node* left;
    value_type value;
  public:
    void f(Tree*);
  };
  Node* top;
public:
  void g(Node*);
  // ...
};

int main() {
}
