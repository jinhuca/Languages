// C0205.cpp
import std;

enum class Type {
  ptr,
  num
};

struct Node {
  int id;
  double value;
};

namespace use_struct {
  struct Entry {
    std::string name;
    Type t;
    Node* p;
    int i;
  };

  void f(const Entry& e) {
    if (e.t == Type::ptr) {
      std::cout << "Entry " << e.name
                << " is a pointer to Node with id " << e.p->id
                << " and value " << e.p->value << "\n";
    }
    else {
      std::cout << "Entry " << e.name << " is a number: " << e.i << "\n";
    }
  }
}

namespace use_union {
  union Value {
    Node* p;
    int i;
  };

  struct Entry {
    std::string name;
    Type t;
    Value v;
  };

  void f(const Entry& e) {
    if (e.t == Type::ptr) {
      std::cout << "Entry " << e.name
                << " is a pointer to Node with id " << e.v.p->id
                << " and value " << e.v.p->value << "\n";
    }
    else {
      std::cout << "Entry " << e.name << " is a number: " << e.v.i << "\n";
    }
  }
}

namespace use_tagged_union {
  union Value {
    Node* p;
    int i;
  };

  struct Entry {
    std::string name;
    Type t;
    Value v;
  };

  void f(const Entry& e) {
    if (e.t == Type::ptr) {
      std::cout << "Entry " << e.name
                << " is a pointer to Node with id " << e.v.p->id
                << " and value " << e.v.p->value << "\n";
    }
    else {
      std::cout << "Entry " << e.name << " is a number: " << e.v.i << "\n";
    }
  }
}

namespace use_variant {
  struct Entry {
    std::string name;
    Type t;
    std::variant<Node*, int> v;
  };

  void f(const Entry& e) {
    if (e.t == Type::ptr) {
      const Node* p = std::get<Node*>(e.v);
      std::cout << "Entry " << e.name
                << " is a pointer to Node with id " << p->id
                << " and value " << p->value << "\n";
    }
    else {
      const int i = std::get<int>(e.v);
      std::cout << "Entry " << e.name << " is a number: " << i << "\n";
    }
  }
}

int main() {
  use_struct::Entry s{"struct_entry", Type::num, new Node{1, 3.14}, 10};
  use_struct::f(s);

  use_union::Value u_ptr{};
  u_ptr.p = new Node{2, 2.71};
  use_union::Entry u{"union_entry", Type::ptr, u_ptr};
  use_union::f(u);

  use_tagged_union::Value tu_ptr{};
  tu_ptr.p = new Node{3, 1.41};
  use_tagged_union::Entry tu{"tagged_union_entry", Type::ptr, tu_ptr};
  use_tagged_union::f(tu);

  use_variant::Entry v{"variant_entry", Type::num, 42};
  use_variant::f(v);
}
