#pragma once
#include <memory>

template<typename T, typename A = std::allocator<T>>
struct vector_base
{
    A alloc;  // allocator
    T* elem;  // start of allocation
    T* space; // end of element sequence, start of space allocated for possible expansion
    T* last;  // end of allocated space

    vector_base(const A& a, typename A::size_type n, typename A::size_type m = 0)
        : alloc{a}
        , elem{std::allocator_traits<A>::allocate(alloc, n + m)}
        , space{elem + n}
        , last{elem + n + m}
    {}
    ~vector_base() { std::allocator_traits<A>::deallocate(alloc, elem, last - elem); }

    vector_base(const vector_base&) = delete; // no copy operations
    vector_base& operator=(const vector_base&) = delete;

    vector_base(vector_base&&); // move operations
    vector_base& operator=(vector_base&&);
};

template<typename T, typename A>
vector_base<T, A>::vector_base(vector_base&& a)
    : alloc{a.alloc}
    , elem{a.elem}
    , space{a.space}
    , last{a.last}
{
    a.elem = a.space = a.last = nullptr; // no longer owns any memory
}

template<typename T, typename A>
vector_base<T, A>& vector_base<T, A>::operator=(vector_base&& a)
{
    swap(alloc, a.alloc);
    swap(elem, a.elem);
    swap(space, a.space);
    swap(last, a.last);
    return *this;
}

template<typename T, typename A = std::allocator<T>>
class vector
{
    vector_base<T, A> vb; // the data is here
    void destroy_elements();

public:
    using size_type = typename A::size_type;

    explicit vector(size_type n, const T& val = T{}, const A& a = A{});

    vector(const vector&);            // copy constructor
    vector& operator=(const vector&); // copy assignment

    vector(vector&&);            // move constructor
    vector& operator=(vector&&); // move assignment

    ~vector() { destroy_elements(); }

    size_type size() const { return vb.space - vb.elem; }
    size_type capacity() const { return vb.last - vb.elem; }

    void reserve(size_type); // increase capacity

    void resize(size_type, const T& = {}); // change the number of elements
    void clear() { resize(0); }            // make the vector empty
    void push_back(const T&);              // add an element at the end

    // ...
};

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
void vector<T, A>::destroy_elements()
{
    for (T* p = vb.elem; p != vb.space; ++p)
        p->~T();
    vb.space = vb.elem;
}

template<typename T, typename A>
vector<T, A>::vector(size_type n, const T& val, const A& a)
    : vb{a, n}
{
    uninitialized_fill(vb.elem, vb.elem + n, val);
}

template<typename T, typename A>
vector<T, A>::vector(const vector<T, A>& a)
    : vb{a.vb.alloc, a.size()}
{
    std::uninitialized_copy(a.begin(), a.end(), vb.elem);
}

template<typename T, typename A>
vector<T, A>::vector(vector&& a)
    : vb{std::move(a.vb)}
{
}

template<typename T, typename A>
vector<T, A>& vector<T, A>::operator=(vector&& a)   {
    clear();
    swap(vb, a.vb);
    return *this;
}