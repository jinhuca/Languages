// P197.cpp
import std;

std::mutex m;

void f1()
{
  std::scoped_lock lck { m };
}

struct X
{
  int p;
  int q;
};

struct Z {};

void f(int i, int j)                    // X* vs. unique_ptr<X>
{
  X *p = new X;                         // allocate a new X
  std::unique_ptr<X> sp { new X };      // allocate a new X and give its pointer to unique_ptr
  // ...
  if(i < 99) throw Z();
  if(i < 77) return;

  // ... use p and sp;
  delete p;                             // destroy *p
}

int main()
{
  f(100, 11);
}
