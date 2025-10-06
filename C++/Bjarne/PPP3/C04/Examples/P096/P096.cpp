// P096.cpp
import std;

int main()
{
  try {
    std::vector<int> v;           // a vector of ints
    for (int x; std::cin >> x;)
      v.push_back(x);             // set values
    for (int i = 0; i <= v.size(); ++i)
      std::cout << "v[" << i << "] == " << v[i] << '\n';
  }
  catch (std::out_of_range) {
    std::cerr << "Oops! Range error\n";
    return 1;
  }
  catch (...) {                   // catch all other exceptions
    std::cerr << "Exception: something went wrong\n";
    return 2;
  }
}
