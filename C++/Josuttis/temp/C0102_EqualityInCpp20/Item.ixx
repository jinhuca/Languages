export module Item;

export class Item {
private:
  long id;
public:
  Item() :id(0) {}
  Item(long id) : id(id) {}

  // operator for checking equality, no need to define !=
  [[nodiscard]] friend constexpr
  bool operator==(const Item& lhs, const Item& rhs) noexcept {
    return lhs.id == rhs.id;    
  }
};