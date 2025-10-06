import std;
import Container;
import Vector_container;
import List_container;

namespace P060
{
  void f()
  {
    //Container c;        // error: there can be no objects of an abstract class
    Container *p = new Vector_container(10);    // OK
  }

  void use(Container &c)
  {
    const int sz = c.size();
    for(int i = 0; i != sz; ++i)
    {
      std::cout << c[i] << std::endl;
    }
  }

  void g()
  {
    Vector_container vc = { 1.2, 2.3, 3.2, 4.5 };
    use(vc);
  }

  void h()
  {
    List_container lc = { 1.2, 2.3, 3.4, 4.5, 5.6 };
    use(lc);
  }
}

int main()
{
  P060::h();
  P060::g();
}