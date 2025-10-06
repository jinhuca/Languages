export module Ptr;
import std;

export template<typename T>
class Ptr {
  T* ptr;
  T* array;
  int sz;
public:
  template<int N>
  Ptr(T* p, T(&a)[N]);        // bind to array a, sz==N, initial value p
  Ptr(T*, T* a, int s);       // bind to array a of size s, initial value p
  Ptr(T* p);                  // bind to single object, sz==0, sz==0, initial value p

  Ptr& operator++();          // prefix
  Ptr& operator--();          // prefix
  Ptr operator++(int);        // postfix
  Ptr operator--(int);        // postfix

  T& operator*();             // prefix
};