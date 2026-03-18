// C130104_alternative_views.cpp
// Don't use exception handling for other purposes, e.g., returning values, and controling flows.
// When at all possible, stick to the "exception handling is error handling" view.
//
#include <iostream>
#include <string>
using std::string;

struct Tree {
  Tree* left;
  Tree* right;
  string str;
};

void fnd(Tree* p, const string& s) {
  if(s == p->str) throw p;    // found s
  if(p->left) fnd(p->left, s);
  if(p->right) fnd(p->right, s);
}

Tree* find(Tree* p, const string& s) {
  try {
    fnd(p, s);
  }
  catch(Tree* q) {    // q->str==s
    return q;
  }
  return 0;
}

int main() {
  Tree* tr = new Tree();
  find(tr, "wnd");
}
