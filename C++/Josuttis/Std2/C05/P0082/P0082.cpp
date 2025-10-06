// P0082.cpp : sharedptr3.cpp
import std;

class SharedMemoryDetacher
{
public:
  void operator () (int* p) {
    delete p;
    std::cout << "deleted pointer to a heap memory." << std::endl; 
  }
};

std::shared_ptr<int> getSharedIntMemory(int num)
{
  void* mem = new int[num];
  return std::shared_ptr<int>(static_cast<int*>(mem), SharedMemoryDetacher());
}

int main()
{
  // get and attach shared memory for 100 ints:
  std::shared_ptr<int> smp(getSharedIntMemory(100));

  // init the shared memory
  for (int i = 0; i < 100; ++i) {
    smp.get()[i] = i * 42;
  }

  std::cout << smp.get()[10] << std::endl;

  // deal with shared memory somewhere else:
  //...
  std::cout << "<return>" << std::endl;
  std::cin.get();

  // release shared memory here:
  smp.reset();
  //...
}
