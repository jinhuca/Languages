// P0078.cpp: create shared_ptr
import std;

int main()
{
  // (1) shared_ptr constructor
  std::shared_ptr<std::string> pNico(new std::string("nico"));

  // (2) make_shared function
  std::shared_ptr<std::string> pJutta = std::make_shared<std::string>("jutta");

  // (3) reset and assign new pointer
  std::shared_ptr<std::string> pAlex;
  auto ptr = new std::string("alex");
  pAlex.reset(ptr);
}
