import std;

enum class Color { red, blue, green };
enum class Traffic_light { green, yellow, red };

Traffic_light& operator++(Traffic_light& t)       // prefix increment: ++
{
  using enum Traffic_light;

  switch(t)
  {
  case green: 
    return t = yellow;
  case yellow:
    return t = red;
  case red:
    return t = green;
  }
}

int main()
{
  Color col = Color::red;
  Traffic_light light = Traffic_light::red;

  auto signal = Traffic_light::green;
  Traffic_light next = ++signal;

  std::cout << static_cast<int>(next) << '\n';
}
