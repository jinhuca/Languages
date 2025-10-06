import vector;

template<typename T, typename A>
vector<T, A>::vector(size_type n, const T& val, const A& a)   // warning: naive implementation
  : alloc { a }                         // copy the allocator
{   
  elem = alloc.allocate(n);             // get memory for elements
  space = last = elem + n;
  for(T* p = elem; p != last; ++p)
    a.construct(p, val);                // construct copy of val in *p
}
