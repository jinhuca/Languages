// C0333.cpp : Resource Management
import std;

class Vector {
private:
  double* elem;
  int sz;
public:
  Vector(int s) :sz { s }, elem { new double[s] } {
    for(int i = 0; i != s; ++i) elem[i] = 0;
    std::cout << "constructed a Vector of size " << sz << '\n';
  }

  Vector(const Vector& a) : sz { a.sz }, elem { new double[a.sz] } {
    std::cout << "copy constructor.\n";
    for(int i = 0; i != a.sz; ++i) {
      elem[i] = a.elem[i];
    }
  }

  Vector& operator=(const Vector& a) {
    std::cout << "copy assignment.\n";
    double* p = new double[a.sz];
    for(int i = 0; i != a.sz; ++i)
      p[i] = a.elem[i];
    delete[] elem;
    elem = p;
    sz = a.sz;
    return *this;
  }

  Vector(Vector&& a) : sz { a.sz }, elem { a.elem } {
    a.elem = nullptr;
    a.sz = 0;
    std::cout << "move constructor.\n";
  }

  Vector& operator=(Vector&& a) {
    sz = a.sz;
    elem = a.elem;
    a.elem = nullptr;
    a.sz = 0;
    std::cout << "move assignment.\n";
    return *this;
  }

  ~Vector() {
    delete[] elem;
    std::cout << "destructed a Vector of size " << sz << '\n';
  }

  double& operator[](int i) const {
    if(i<0 || i>sz) throw std::out_of_range("Vector index is out of range.");
    return elem[i];
  }

  double& operator[](int i) {
    if(i<0 || i>sz) throw std::out_of_range("Vector index is out of range.");
    return elem[i];
  }

  int size() const { return sz; }
};

std::vector<std::thread> my_threads;
void heartbeat() {
  
}

Vector init(int n) {
  std::thread t { heartbeat };
  my_threads.push_back(std::move(t));
  Vector vec(n);
  for(int i = 0; i < vec.size(); ++i) vec[i] = 777;
  return vec;
}

int main() {
  auto v = init(1'000'000);
}
