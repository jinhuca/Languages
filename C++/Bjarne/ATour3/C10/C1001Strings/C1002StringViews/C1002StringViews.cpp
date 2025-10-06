// C1002StringViews.cpp
import std;
using namespace std::literals::string_view_literals;

static std::string cat(std::string_view sv1, std::string_view sv2) {
  std::string res { sv1 };
  return res += sv2;
}

void use_cat() {
  std::string king = "Harold";
  std::string_view ss = { &king[0],2 };
  auto s1 = cat(king, "William");
  auto s2 = cat(king, king);
  auto s3 = cat("Edward", "Stephen"sv);
  auto s4 = cat("Canute"sv, king);
  auto s5 = cat({ &king[0],2 }, "Henry"sv);
  auto s6 = cat({ &king[0],2 }, { &king[2],4 });
}

int main() {
  auto s1 = "Piet Hein";
  std::string_view sv1 { &s1[0],4 };
  std::cout << sv1 << '\n';
  //use_cat();
}
