// P0054.cpp Callable Objects
import std;

void func(int x, int y) {
  std::cout << "function called: " << x + y << std::endl;
}

auto lambda = [](int x, int y) {
  std::cout << "lambda called: " << x << " : " << y << std::endl;
  };

class C {
public:
  void operator()(int x, int y) const {
    std::cout << "function object called: " << x << " : " << y << std::endl;
  }
  void memfunc(int x, int y) const {
    std::cout << "member function called: " << x << " : " << y << std::endl;
  }
private:
  int m_x, m_y;
};

int main()
{
  C c;
  std::shared_ptr<C> sp(new C);

  // bind() uses callable objects to bind arguments:
  std::bind(func, 77, 33)();                // calls: func(77, 33)
  std::bind(lambda, 77, 33)();              // calls: lambda(77, 33)
  c(77, 33);                                // calls: C::operator()(77, 33)

  c.memfunc(77, 33);
  sp->memfunc(77, 33);

}
