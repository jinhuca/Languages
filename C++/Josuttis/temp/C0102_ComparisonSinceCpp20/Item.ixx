export module Item;
import std;

export class Item {
private:
  long id;
public:
  Item() :id(0) {}
  Item(long id) : id(id) {}

  // enable use of all equality and relational operators
  auto operator<=>(const Item&) const = default;
};