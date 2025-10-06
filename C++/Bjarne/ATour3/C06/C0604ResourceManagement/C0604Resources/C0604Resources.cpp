// C0604Resources.cpp
import std;
import Vector;

std::vector<std::thread> my_threads;
void heartbeat() {
  std::cout << "starting heart beat...\n";
}

Vector init(int n) {
  //std::thread t { heartbeat };
  //my_threads.push_back(std::move(t));

  Vector vec(n);
  for(auto i = 0; i != n; ++i)
    vec[i] = 777;
  return vec;
}

int main() {
  auto v = init(1'000'000);
}
