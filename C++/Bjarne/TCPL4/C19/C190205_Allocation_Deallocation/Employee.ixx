export module Employee;

export class Employee {
public:
  // ...
  void* operator new(size_t);
  void operator delete(void*, size_t);

  void* operator new[](size_t);
  void operator delete[](void*, size_t);
};