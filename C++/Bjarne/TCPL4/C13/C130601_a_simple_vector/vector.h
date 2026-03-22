#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>

namespace simple_vector {

template<typename T, typename A = std::allocator_traits<std::allocator<T>>>
class vector
{
private:
    T* first; // start of allocation
    T* space; // end of element sequence, start of space allocated for possible expansion
    T* last;  // end of allocated space
    A alloc;  // allocator_traits
public:
    using size_type = typename std::allocator<T>::size_type; // type used for vector sizes
    explicit vector(size_type n, const T& val = T(), const A& alloc_traits = A());
    /*
    vector(const vector& a);            // copy constructor
    vector& operator=(const vector& a); // copy assignment
    vector(vector&& a);                 // move constructor
    vector& operator=(vector&& a);      // move assignment
    ~vector();

    
    size_type capacity() const { return last - elem; }
    void reserve(size_type n);               // increase capacity to n
    void resize(size_type n, const T& = {}); // increase size to n
    void push_back(const T&);                // add an element at the end
    */
    size_type size() const { return (last - first + 1)/sizeof(T); }
};

template<typename T, typename A>
inline vector<T, A>::vector(size_type n, const T& val, const A& alloc_traits)
    : alloc{alloc_traits}

{
    // 1. define the allocator and its traits
    using Alloc = std::allocator<T>;
    using Traits = std::allocator_traits<Alloc>;

    Alloc my_alloc;

    // 2. Allocate: Reserve raw memory for n objects
    // returns a pointer (Traits::pointer) to uninitialized memory
    T* first = Traits::allocate(my_alloc, n);

    // 3. Construct: Initialize the object in that raw memory
    // using placement new by default if the allocator doesn't provide 'construct'
    //Traits::construct(my_alloc, ptr, val);

    last = first + n;
    space = ++last;

    int initial = 1;

    for (T* p = first; p != last; ++p) {
        Traits::construct(my_alloc, p, initial++);
        std::cout << "allocated = " << *p << '\n';
    }

    /*
    std::allocator<T> alloc;
    std::allocator_traits<std::allocator<T>> traits;
    a::allocate(alloc, n);
    elem = traits.allocate(alloc, n);
    //elem = std::allocator_traits<std::allocator<int>>::allocate(a, n);
    space = last = elem + n;
    for (T* p = elem; p != last; ++p)
        std::allocator_traits<std::allocator<int>>::construct(alloc, p val);
    //a.construct(p, val);
    */
}
} // namespace simple_vector
