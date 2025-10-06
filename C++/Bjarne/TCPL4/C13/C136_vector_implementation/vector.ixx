export module vector;
import std;

export template<typename T, typename A = std::allocator<T>>
class vector {
private:
  T* elem;      // start of allocation
  T* space;     // end of element sequences, start of space allocated for possible expansion
  T* last;      // end of allocated space
  A alloc;      // allocator
public:
  using size_type = typename A::size_type;    // type used for vector sizes
  explicit vector(size_type n, const T& val = T(), const A & = A());

  vector(const vector& a);                    // copy constructor
  vector& operator=(const vector& a);         // copy assignment

  vector(vector&& a);                         // move constructor
  vector& operator=(const vector&& a);        // move assignment

  ~vector();

  size_type size() const { return space - elem; }
  size_type capacity() const { return last - elem; }
  void reserve(size_type n);                  // increase capacity to n

  void resize(size_type n, const T & = {});   // change size to n
  void push_back(const T&);                   // add an element at the end
};
