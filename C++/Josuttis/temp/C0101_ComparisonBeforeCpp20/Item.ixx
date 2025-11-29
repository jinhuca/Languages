export module Item;

export class Item {
private:
  long id;
public:
  Item() :id(0) {}
  Item(long id) : id(id) {}
  long getId() const { return id; }

  // Comparison operators before C++20
  [[nodiscard]] friend constexpr
    bool operator==(const Item& lhs, const Item& rhs) noexcept {
    return lhs.id == rhs.id;    // basic check for equality
  }
  [[nodiscard]] friend constexpr
    bool operator!=(const Item& lhs, const Item& rhs) noexcept {
    return !(lhs == rhs);       // negation of equality
  }

  [[nodiscard]] friend constexpr
    bool operator<(const Item& lhs, const Item& rhs) noexcept {
    return lhs.id < rhs.id;    // basic check for less-than
  }
  [[nodiscard]] friend constexpr
    bool operator<=(const Item& lhs, const Item& rhs) noexcept {
    return !(rhs < lhs);       // derived from less-than
  }
  [[nodiscard]] friend constexpr
    bool operator>(const Item& lhs, const Item& rhs) noexcept {
    return rhs < lhs;          // reverse of less-than
  }
  [[nodiscard]] friend constexpr
    bool operator>=(const Item& lhs, const Item& rhs) noexcept {
    return !(lhs < rhs);       // negation of less-than
  }
};