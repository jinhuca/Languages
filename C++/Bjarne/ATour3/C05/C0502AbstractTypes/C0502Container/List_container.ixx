export module List_container;
import std;
import Container;

export class List_container : public Container {
public:
  List_container() {}
  List_container(std::initializer_list<double> il) :ld { il } {}
  ~List_container() {}

  double& operator[](int i) override {
    for(auto& x : ld) {
      if(i == 0)
        return x;
      --i;
    }
    throw std::out_of_range("List container");
  }
  int size() const override { return ld.size(); }
private:
  std::list<double> ld;
};