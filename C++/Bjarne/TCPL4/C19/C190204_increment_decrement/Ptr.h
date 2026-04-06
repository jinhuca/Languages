#pragma once

template<typename T>
class Ptr {
  T* ptr;
  T* array;
  int sz;
public:
  // bind to array a, sz==N, initial value p
  template<int N>
  Ptr(T* p, T(&a)[N]) : ptr{p}, array{a}, sz{N} {}
  
  // bind to array a of size s, initial value p
  Ptr(T* p, T* a, int s) : ptr{p}, array{a}, sz{s} {}

  // bind to single object, sz==0, initial value p
  Ptr(T* p) : ptr{p}, array{nullptr}, sz{0} {}

  // prefix ++
  Ptr& operator++() { ++ptr; return *this; }
  
  // prefix --
  Ptr& operator--() { --ptr; return *this; }

  // postfix ++
  Ptr operator++(int) { Ptr old = *this; ++(*this); return old; }

  // postfix --
  Ptr operator--(int) { Ptr old = *this; --(*this); return old; }

  // prefix *
  T& operator*() { return *ptr; }
};