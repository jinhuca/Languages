// C1311_Exceptions.cpp
import std;

class Some_error {
public:
  Some_error(int e) : errorId { e } {
    std::cout << "Error generated with Id = " << errorId << '\n';
  }
  int getId() { return errorId; }
private:
  int errorId;
};

int do_task(int cond) {
  if(cond > 0) return 42;
  throw Some_error { 1 };
}

void taskmaster() {
  try {
    auto result = do_task(-2);
    // use result if do_task succeeded, i.e., no error detected.
  }
  catch(Some_error e) {
    // failure to do_task: handle problem
    std::cerr << "Exception caught: id = " << e.getId() << '\n';
  }
}

int main() {
  taskmaster();
}
