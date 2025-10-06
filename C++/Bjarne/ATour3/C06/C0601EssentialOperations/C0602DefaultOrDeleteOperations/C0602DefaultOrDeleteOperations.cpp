import std;

struct Z {
  std::vector<int> v;
  std::string s;
};

void default_operations() {
  Z z1;     // default initialize z1.v and z1.s
  Z z2 = z1;    // default copy z1.v and z1.s
}

class Shape {
public:
  Shape(const Shape&) = delete;             // no copy constructor
  Shape& operator=(const Shape&) = delete;  // no copy assignment
};

void no_copy(Shape& s1, Shape& s2) {
  //s1 = s2;  // error: attempting to reference a deleted function
}

int main() {
  default_operations();
}
