// P0100.cpp : unique_ptr
import std;

void useUnique_ptr() {
  // create and initialize (pointer to) string:
  std::unique_ptr<std::string> up(new std::string("nico"));
  (*up)[0] = 'N';                   // replace first character
  up->append("lai");                // append some characters
  std::cout << *up << std::endl;    // print whole string
}

void transferOwnership() {
  std::string* sp = new std::string("hello");
  std::unique_ptr<std::string> up1(sp);
  std::unique_ptr<std::string> up2(sp);

}

int main()
{
  useUnique_ptr();
  transferOwnership();
}
