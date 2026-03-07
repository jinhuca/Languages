// C1044_Reference_Arguments.cpp 
import std;

constexpr const char* p = "asdfs";

int main() {
  constexpr std::complex<float> z1 { 1,2 };
  constexpr double re = z1.real();
}
