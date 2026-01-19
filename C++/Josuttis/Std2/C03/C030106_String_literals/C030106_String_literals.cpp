// C030106_String_literals.cpp 
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

const auto s1 = L"abc";

int main() {
  // Example wchar_t* string
    // L prefix indicates a wide character literal
  const std::wstring wide_chars = L"Hello, World!"; // Includes a smiley emoji

    // Print the result
  std::wcout << wide_chars << std::endl;

  return 0;
}
