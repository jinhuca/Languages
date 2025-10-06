import std;
import Shape;

template<typename C, typename Op>
void for_each(C &c, Op op)    // assume that C is a container of pointers
{
  for(auto &x : c)
    op(x);                    // pass op() a reference to each element pointed to
}

void user()
{
  std::vector<std::unique_ptr<Shape>> v;
  Circle p;
  auto p1 = std::make_unique<Shape>(p);
  p1->draw();
}

int main()
{
  user();
}
