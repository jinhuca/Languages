#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>

//#define NAIVE_IMPLEMENTATION
//#define ELABORATE_IMPLEMENTATION
#define USE_UNINITIALIZED

namespace simple_vector {

template<typename T, typename A = std::allocator<T>>
class vector
{
private:
    T* elem;  // start of allocation
    T* space; // end of element sequence, start of space allocated for possible expansion
    T* last;  // end of allocated space
    A alloc;  // allocator
public:
    using size_type = typename A::size_type; // type used for vector sizes
    explicit vector(size_type n, const T& val = T(), const A& a = A());
    /*    
    vector(const vector& a);            // copy constructor
    vector& operator=(const vector& a); // copy assignment
    vector(vector&& a);                 // move constructor
    vector& operator=(vector&& a);      // move assignment
    ~vector();
    
    size_type size() const { return space - elem; }
    size_type capacity() const { return last - elem; }
    void reserve(size_type n);               // increase capacity to n
    void resize(size_type n, const T& = {}); // increase size to n
    void push_back(const T&);                // add an element at the end
    */
};

#ifdef NAIVE_IMPLEMENTATION
template<typename T, typename A> // naive implementation
inline vector<T, A>::vector(size_type n, const T& val, const A& a)
    : alloc{a}
{
    elem = std::allocator_traits<A>::allocate(alloc, n); // get memory of elements
    space = last = elem + n;
    for (T* p = elem; p != last; ++p)
        std::allocator_traits<A>::construct(alloc, p, val);
}
#endif

#ifdef ELABORATE_IMPLEMENTATION
template<typename T, typename A>
inline vector<T, A>::vector(size_type n, const T& val, const A& a) // elaborate implementation
    : alloc{a}
{
    elem = std::allocator_traits<A>::allocate(alloc, n);        // get memory of elements
    T* p; // outside try{} because we need it in try{} and catch()
    try {
        auto end = elem + n;
        for (p = elem; p != end; ++p) {
            std::allocator_traits<A>::construct(alloc, p, val);
        }
        last = space = p;
    } catch (...) {
        for (auto q = elem; q != p; ++q)
            std::allocator_traits<A>::destroy(alloc, q);        // destroy constructed elements
        std::allocator_traits<A>::deallocate(alloc, elem, n);   // free memory
        throw;                                                  // rethrow
    }
}
#endif

#ifdef USE_UNINITIALIZED

template<typename For, typename T>
void uninitialized_fill(For beg, For end, const T& x)
{
    For p;
    try {
        for (p = beg; p != end; ++p)
            ::new (static_cast<void*>(&*p)) T(x); // construct copy of x in *p
    } catch (...) {
        for (For q = beg; q != p; ++q)
            (&*q)->~T(); // destroy element
        throw;           // rethrow
    }
}

template<typename T, typename A>
vector<T, A>::vector(size_type n, const T& val, const A& a)
  : alloc(a) {
    elem = std::allocator_traits<A>::allocate(alloc, n);
    try {
        uninitialized_fill(elem, elem + n, val);
        space = last = elem + n;
    } catch (...) {
        std::allocator_traits<A>::deallocate(alloc, elem, n);
        throw;
    }
}
#endif
} // namespace simple_vector
