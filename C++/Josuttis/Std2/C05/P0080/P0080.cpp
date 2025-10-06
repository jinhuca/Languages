// P0080.cpp : define a deleter for shared_ptr
import std;

void defineDeleter() {
  // two shared pointers representing two persons by their names
  std::shared_ptr<std::string> pNico(
    new std::string("nico"),
    [](std::string* p) {
      std::cout << "delete " << *p << std::endl;
      delete p;
    });

  std::shared_ptr<std::string> pJutta(
    new std::string("jutta"),
    [](std::string* p) {
      std::cout << "delete " << *p << std::endl;
      delete p;
    });

  // capitalize person names
  (*pNico)[0] = 'N';
  pJutta->replace(0, 1, "J");

  // put them multiple times in a container
  std::vector<std::shared_ptr<std::string>> whoMakeCoffee;
  whoMakeCoffee.push_back(pJutta);
  whoMakeCoffee.push_back(pJutta);
  whoMakeCoffee.push_back(pNico);
  whoMakeCoffee.push_back(pJutta);
  whoMakeCoffee.push_back(pNico);

  //whoMakeCoffee.resize(2);
  pJutta = nullptr;
  std::cout << pJutta.use_count() << std::endl;
}

void defineArrayDeleter() {
  std::unique_ptr<int []> ptr1(new int[10]);    // can be compiled, but does not delete []
  std::shared_ptr<int []> ptr2(new int[10]);    // can be compiled, but does not delete []

  std::shared_ptr<int []> sp(
    new int[10] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 },
    [](int* p) { delete [] p;
    });
}

class FileDeleter {
private:
  std::string filename;
public:
  FileDeleter(const std::string& fn) : filename(fn) {
  }
  void operator()(std::ofstream* fp) {
    std::cout << "deleter called.\n";
    delete fp;                        // close file
    std::remove(filename.c_str());    // delete file
  }
};

void defineDestructionPolicy() {
  std::shared_ptr<std::ofstream> fp(
    new std::ofstream("tmpfile.txt"),
    FileDeleter("tmpfile.txt"));
}

int main()
{
  //defineDeleter();
  //defineArrayDeleter();
  defineDestructionPolicy();
}
