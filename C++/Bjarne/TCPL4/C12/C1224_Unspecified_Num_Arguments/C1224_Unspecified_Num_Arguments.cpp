// C1224_Unspecified_Num_Arguments.cpp 
import std;

//int printf(const char* ...) { }

int main() {
  std::printf("Hello, world!\n");
  std::string first_name = "John";
  std::string second_name = "Scott";
  std::printf("My name is %s %s\n", first_name, second_name);
}
