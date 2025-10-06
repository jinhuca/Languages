export module List_container;

import std;
import Container;

namespace P060
{
  // List_container implements Container
  export class List_container : public Container
  {
  public:
    List_container() {}       // empty list
    List_container(std::initializer_list<double> il) : ld { il } {}
    ~List_container() override {}
    double &operator[](int i) override;
    int size() const override { return ld.size(); }
  private:
    std::list<double> ld;     // (standard-library) list of doubles
  };

  double &List_container::operator[](int i)
  {
    for(auto &x : ld)
    {
      if(i == 0)
        return x;
      --i;
    }
    throw std::out_of_range { "List Container" };
  }
}