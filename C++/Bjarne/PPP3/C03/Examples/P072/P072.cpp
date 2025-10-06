// P072.cpp 
import std;

int main()
{
  std::vector<int> v = { 5, 7, 9, 4, 6, 8 };  // vector of 6 ints
  for (int i = 0; i < v.size(); ++i)
    std::cout << v[i] << '\n';

  std::vector<std::string> philosopher = { "Kant", "Plato", "Hume", "Kleikegaard" };    // vector of 4 strings
  std::vector<int> vi(6);   // vector of 6 ints initialized to 0
  std::vector<std::string> vs(4);     // vector of 4 strings initialized to ""

  std::vector<double> v1;   // v1 starts off empty; that is, v has no elements
  v1.push_back(2.7);        // add an element 2.7 to v at the end (back)
  v1.push_back(5.6);        // add an element 5.6 to v at the end (back)

}
