export module Coordinate;
import std;

export class Coordinate {
  private:
    double x;
    double y;
public:
    Coordinate() : x(0.0), y(0.0) {}
    Coordinate(double x, double y) : x(x), y(y) {}

    // enable use of all equality and relational operators
    auto operator<=>(const Coordinate&) const = default;
};