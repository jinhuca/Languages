// P0480.cpp
import std;

class IntSequence {
private:
  int value;
public:
  IntSequence(int initialValue) :value(initialValue) {
  }
  int operator()() {
    return value++;
  }
};

int main()
{
  std::list<int> coll;
  IntSequence seq(1);     // integral sequence starting with 1

}
