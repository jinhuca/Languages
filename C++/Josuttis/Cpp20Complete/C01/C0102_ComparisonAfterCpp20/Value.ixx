export module Value;
import std;

export class Value {
private:
  long id;
public:
  constexpr Value(long i) noexcept : id(i) {}
  auto operator<=>(const Value& rhs) const = default;
};