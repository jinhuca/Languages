export module Value;
import std;

export class Value {
private:
  long id;
public:
  constexpr Value(long i) noexcept : id(i) {
  }
  // enable use of all equality and relational operators:
  auto operator<=>(const Value& rhs) const = default;
};