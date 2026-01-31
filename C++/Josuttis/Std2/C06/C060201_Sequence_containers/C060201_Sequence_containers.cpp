// C060201_Sequence_containers.cpp 
import std;

void vector_example() {
  std::vector<int> coll;     // vector container for integer elements
  //append elements with values 1 to 6
  for (int i = 1; i <= 6; ++i) {
    coll.push_back(i);
  }
  // print all elements followed by a space
  for (int i = 0; i < coll.size(); ++i) {
    std::cout << coll[i] << ' ';
  }
  std::cout << '\n';
}

void deque_example() {
  std::deque<int> coll;      // deque container for integer elements
  //append elements with values 1 to 6
  for (int i = 1; i <= 6; ++i) {
    coll.push_back(i);
  }
  // print all elements followed by a space
  for (int i = 0; i < coll.size(); ++i) {
    std::cout << coll[i] << ' ';
  }
  std::cout << '\n';
}

void array_example() {
  // array container of 5 string elements:
  std::array<std::string, 5> coll = { "hello", "world" };
  // print each element with its index on a line
  for (int i = 0; i < coll.size(); ++i) {
    std::cout << i << ": " << coll[i] << '\n';
  }
}

void list_example() {
  std::list<char> coll;   // list container for char elements
  // append elements with values 'a' to 'z'
  for (char c = 'a'; c <= 'z'; ++c) {
    coll.push_back(c);
  }
  // print all elements followed by a space
  for (const auto& elem : coll) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
}

void forward_list_example() {
  std::forward_list<int> coll{ 2, 3, 5, 7, 11, 13, 17 };
  // resize
  coll.resize(9);
  // resize again
  coll.resize(10, 99);
  // print all elements followed by a space
  for (const auto& elem : coll) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
}

int main() {
  //vector_example();
  //array_example();
  //list_example();
  forward_list_example();
  return 0;
}
