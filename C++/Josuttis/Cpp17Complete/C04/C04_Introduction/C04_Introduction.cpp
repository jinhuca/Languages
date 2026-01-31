// C04_Introduction.cpp
#include <iostream>
#include <string>

struct Data {
  std::string name;
  double value;
};

Data x1 = { "test1", 6.778 };
Data x2 { "test2", 6.778 };

struct MoreData : Data {
  bool done;
};

//MoreData y1{ {"test1",6.778}, false };
MoreData y2{ "test1", 6.778, true };

int main() {
  std::cout << y2.name << " - " << y2.value << " - " << y2.done << '\n';
}
