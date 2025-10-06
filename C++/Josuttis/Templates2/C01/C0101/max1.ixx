export module max1;

export template<typename T>
T max(T a, T b)
{
  return b < a ? a : b;
}