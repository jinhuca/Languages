import Vector;

#include <iostream>
#include <stdexcept>
#include <string>

enum class Error_action { ignore, throwing, terminating, logging };   // error-handling alternatives

constexpr Error_action default_Error_action = Error_action::throwing; // a default

enum class Error_code { range_error, length_error };   // individual errors

std::string error_code_name[]{ "range error","length error" };  // names of individual errors

template<Error_action action = default_Error_action, class C>
constexpr void expect(C cond, Error_code x)   // take "action" if the expected condition "cond" doesn't hold
{
  if constexpr (action == Error_action::logging)
    if (!cond()) std::cerr << "expect() failure:" << int(x) << error_code_name[int(x)] << '\n';
  if constexpr (action == Error_action::throwing)
    if (!cond()) throw x;
  if constexpr (action == Error_action::terminating)
    if (!cond()) std::terminate();
  // or no action
}

Vector::Vector(int s)
  :elem{ new double[s] }, sz{ s }
{
  if (s < 0)
    throw std::length_error("Vector constructor: negative size");
}

double& Vector::operator[](int i) const
{
  expect([i, this] { return 0 <= i && i < size(); }, Error_code::range_error);
  return elem[i];
}

int Vector::size() const
{
  return sz;
}

void Vector::print() const
{
  for (auto i = 0; i != size(); ++i)
    std::cout << elem[i] << '\t';
  std::cout << std::endl;
}


bool operator==(const Vector& v1, const Vector& v2)
{
  if (v1.size() != v2.size())
    return false;

  for (int i = 0; i < v1.size(); ++i)
    if (v1[i] != v2[i])
      return false;

  return true;
}

