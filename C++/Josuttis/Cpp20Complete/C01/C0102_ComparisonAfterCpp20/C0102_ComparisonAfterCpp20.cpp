// C0102_ComparisonAfterCpp20.cpp 
import std;
import Value;

// Using spaceship operator
void use_comparison_with_spaceship() {
  Value v1{ 11 }, v2{ 11 };
  if(v1 < v2) {
    std::cout << "v1 is less than v2\n";
  }
  else if(v1>v2){
    std::cout << "v1 is not less than v2\n";
  }
  else {
    std::cout << "v1 is equal to v2\n";
  }
}

int main() {
  use_comparison_with_spaceship();
}
