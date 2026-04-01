// C160213_member_types.cpp 
#include <iostream>

template<typename T>
class Tree {
  using value_type = T;                 // member type alias
  enum Policy { rb, splay, treeps };    // member enumeration
  class Node {                          // member class
    Node* right;
    Node* left;
    value_type value;
  public:
    void f(Tree* t);
  };
  Node* top;
public:
  void g(Node* n);                      // use member class
};

template<typename T>
void Tree<T>::Node::f(Tree* p) {
  top = right;                            // error: no object of type Tree specified
  p->top = right;                         // OK: p is a pointer to a Tree object
  value_type v = left->value;             // OK: value_type is not associated with an object
}

template<typename T>
void Tree<T>::g(Node* p) {
  value_type val = right->value;          // error: no object of type Node specified
  value_type v = p->right->value;         // error: Node::right is private
  p->f(this);                             // OK: call Node::f with a pointer to the Tree object
}

int main() {

}
