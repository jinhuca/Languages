import Ptr;

template <typename T>
template <int N>
Ptr<T>::Ptr(T* p, T(&a)[N]) : ptr { p }, array { a } {
}

template <typename T>
Ptr<T>::Ptr(T* p, T* a, int s) : ptr { p }, array { a }, sz { s } {
}

template <typename T>
Ptr<T>::Ptr(T* p) : ptr { p }, array {}, sz { 0 } {
}

template <typename T>
Ptr<T>& Ptr<T>::operator++() {    // return the current object after incrementing
  // ... check that ptr+1 can be pointed to ...
  ++ptr;
  return *this;
}

template <typename T>
Ptr<T>& Ptr<T>::operator--() {    // return the current object after decrementing
  // ... check that ptr-1 can be pointed to ...
  --ptr;
  return *this;
}

template <typename T>
Ptr<T> Ptr<T>::operator++(int) {  // increment and return a Ptr with the old value
  // ... check that ptr+1 can be pointed to ...
  Ptr<T> old { ptr, array, sz };
  ++ptr;
  return *this;
}

template <typename T>
Ptr<T> Ptr<T>::operator--(int) {  // decrement and return a Ptr with the old value
  // ... check that ptr-1 can be pointed to ...
  Ptr<T> old { ptr, array, sz };
  --ptr;
  return *this;
}

template <typename T>
T& Ptr<T>::operator*() {
  return ptr;
}
