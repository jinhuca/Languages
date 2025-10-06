export module Value;
import std;

export class Value {
private:
  long id;

public:
  Value() : id(0) {}
  constexpr Value(long id) noexcept: id(id) {    // support implicit type conversion
  }

  // equality operators:
  [[nodiscard]] friend constexpr
  bool operator==(const Value& lhs, const Value& rhs) noexcept {
    return lhs.id == rhs.id;         // basic check for equality
  }
  [[nodiscard]] friend constexpr
  bool operator!=(const Value& lhs, const Value& rhs) noexcept {
    return !(lhs == rhs);            // derived check for inequality
  }
  // relational operators:
  [[nodiscard]] friend constexpr
  bool operator<(const Value& lhs, const Value& rhs) noexcept {
    return lhs.id < rhs.id;          // basic check for ordering
  }
  [[nodiscard]] friend constexpr
  bool operator<=(const Value& lhs, const Value& rhs) noexcept {
    return !(rhs < lhs);             // derived check
  }
  [[nodiscard]] friend constexpr
  bool operator>(const Value& lhs, const Value& rhs) noexcept {
    return rhs < lhs;                // derived check
  }
  [[nodiscard]] friend constexpr
  bool operator>=(const Value& lhs, const Value& rhs) noexcept {
    return !(lhs < rhs);             // derived check
  }

  // stream output operator:
  friend std::ostream& operator<<(std::ostream& os, const Value& v) {
    return os << "Value(" << v.id << ')';
  }
};