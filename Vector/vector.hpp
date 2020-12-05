#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <tgmath.h>
#include <climits>

#include "vector_iterator.hpp"

/*
**SPECIAL CASES
**Can contain and show 0 values with iterator too, so do not block on 0 values
**Default constructor does not allocate anything, it does not segfault in begin() function but when iterator tries to show the value -> begin() returns empty iterator
**Can keep iterating on allocated unused values, those are set to null, seem to allocate in 1025744 blocks, after ends up segfaulting
**If you make it iterate backwards too much it goes onto random memory space and ends up segfaulting
**Error with real container -> If iterator points on vector array, and vector array gets resized allocating in new memory space, initial iterator loses what it pointed on
**
**When trying to access empty container segfaults (front, back, at, []) /
**Unused allocated memory should be set to null, c++ automatically sets to null /
**Iterator object should be able to iterate freely, no protections, if on unitialized value random output /
*/

namespace ft
{
  template<typename T>
  class vector //Is like an array but with a dynamic size. Each time size changes vector copies old array into new array with added element, so it is slow in adding elements but it is fast in accessing elements
  {
  private:
    size_t _size_left;
    static const size_t _buffer_storage = 10;
    size_t _total_buffer_storage;

    size_t _size;
    T *_array;

    void realloc(size_t size);
    template<typename inputiterator>
    size_t get_size(inputiterator first, inputiterator last);
    template<typename inputiterator>
    void copy(inputiterator first, inputiterator last); //Copy with clear and reallocation
    void copy(const vector<T> &cpy); //Copy withouth reallocating
    void new_size(size_t size);
    void reserve2(size_t n);

    void show()
    {
      for (unsigned int i = 0; i < size(); i++)
        std::cout << _array[i];
      std::cout << std::endl;
    }

  public:
    //Iterators
    typedef Vector::iterator<T> iterator;
    typedef const Vector::iterator<T> const_iterator;
    typedef Vector::reverse_iterator<T> reverse_iterator;
    typedef const Vector::reverse_iterator<T> const_reverse_iterator;

    //Constructors
    vector(): _size(0) { realloc(0); } //Realloc is own function that uses new keyword
    vector(size_t n, const T &value): _size(0) { assign(n, value); }
    template<typename inputiterator>
    vector(inputiterator first, inputiterator last): _size(0) { assign(first, last); } //If you do not take as a reference you will lose the values contained in it
    vector(const vector<T> &to_copy): _size(0) {*this = to_copy;}
    void operator=(const vector<T> &to_copy) { _size = 0; copy(to_copy.begin(), to_copy.end()); } //Deep copy
    ~vector() { clear(); }

    //Iterators
    iterator begin() { return iterator(_array); }
    const_iterator begin() const { return const_iterator(_array); }
    iterator end() { return iterator(_array + _size); }
    const_iterator end() const { return const_iterator(_array + _size); }
    reverse_iterator rbegin() { return reverse_iterator(_array + _size - 1); }
    const_reverse_iterator rbegin() const { return const_reverse_iterator(_array + _size - 1); }
    reverse_iterator rend() { return reverse_iterator(_array - 1); }
    const_reverse_iterator rend() const { return const_reverse_iterator(_array - 1); }

    //Capacity
    size_t size() const { return (_size); }
    size_t max_size() const { return std::numeric_limits<size_t>::max(); } //Because the size is stored in a size_t, https://en.cppreference.com/w/cpp/container/list/max_size
    void resize(size_t n, const T &value=T()); //Change size
    size_t capacity() const { return (_total_buffer_storage); }
    bool empty() const;
    void reserve(size_t n); //Change capacity

    //Element access
    T &operator[](size_t n) { return _array[n]; }
    const T &operator[](size_t n) const { return _array[n]; }
    T &at(size_t n) { return _array[n]; }
    const T &at(size_t n) const { return _array[n]; }
    T &front() { return _array[0]; }
    const T &front() const { return _array[0]; }
    T &back() { return _array[_size - 1]; }
    const T &back() const { return _array[_size - 1]; }

    //Modifiers
    template<typename inputiterator>
    void assign(inputiterator first, inputiterator last) { realloc(0); copy(first, last); }
    void assign(size_t n, const T &value);
    void push_back(const T &value);
    void pop_back();
    iterator insert(iterator position, const T &value);
    void insert(iterator position, size_t n, const T &value);
    template<typename inputiterator>
    void insert(iterator position, inputiterator first, inputiterator last);
    iterator erase(iterator position);
    iterator erase(iterator first, iterator last);
    void swap(vector<T> &x);
    void clear();

  };

  //Non-member function overloads
  template<typename T>
  void swap(vector<T> &r, vector<T> &l)
  {
    r.swap(l);
  }

  template<typename T>
  bool operator==(const vector<T> &r, const vector<T> &l)
  {
    size_t i;

    i = 0;
    if (r.size() != l.size())
      return false;
    if (r.size() == 0 and l.size() == 0)
      return true;
    while (i < r.size())
    {
      if (r[i] != l[i])
        return false;
      i++;
    }
    return true;
  }

  template<typename T>
  bool operator!=(const vector<T> &r, const vector<T> &l)
  {
    size_t i;

    i = 0;
    if (r.size() != l.size())
      return true;
    if (r.size() == 0 and l.size() == 0)
      return false;
    while (i < r.size())
    {
      if (r[i] != l[i])
        return true;
      i++;
    }
    return false;
  }

  template<typename T>
  bool operator<(const vector<T> &r, const vector<T> &l)
  {
    size_t i;

    i = 0;
    if (l.size() == 0)
      return false;
    if (r.size() == 0)
      return true;
    while (i < r.size())
    {
      if (r[i] < l[i])
        return true;
      else if (r[i] > l[i])
        return false;
      i++;
    }
    return false;
  }

  template<typename T>
  bool operator<=(const vector<T> &r, const vector<T> &l)
  {
    size_t i;

    i = 0;
    if (r.size() == 0 && l.size() == 0)
      return true;
    if (l.size() == 0)
      return false;
    if (r.size() == 0)
      return true;
    while (i < r.size())
    {
      if (r[i] > l[i])
        return false;
      else if (r[i] < l[i])
        return true;
      i++;
    }
    return true;
  }

  template<typename T>
  bool operator>(const vector<T> &r, const vector<T> &l)
  {
    size_t i;

    i = 0;
    if (r.size() == 0)
      return false;
    if (l.size() == 0)
      return true;
    while (i < r.size())
    {
      if (r[i] > l[i])
        return true;
      else if (r[i] < l[i])
        return false;
      i++;
    }
    return false;
  }

  template<typename T>
  bool operator>=(const vector<T> &r, const vector<T> &l)
  {
    size_t i;

    i = 0;
    if (r.size() == 0 && l.size() == 0)
      return true;
    if (l.size() == 0)
      return true;
    if (r.size() == 0)
      return false;
    while (i < r.size())
    {
      if (r[i] < l[i])
        return false;
      else if (r[i] > l[i])
        return true;
      i++;
    }
    return true;
  }

  template<typename T>
  void vector<T>::resize(size_t n, const T &value)
  {
    while (_size != n)
    {
      if (n > _size)
        push_back(value);
      else
        pop_back();
    }
  }

  template<typename T>
  bool vector<T>::empty() const
  {
    if (_size == 0)
      return true;
    else
      return false;
  }

  template<typename T>
  void vector<T>::reserve(size_t n)
  {
    float times;
    size_t storage;
    vector<T> rem;

    if (n >= _total_buffer_storage)
    {
      rem = *this;
      clear();
      times = ceil((float)n / (float)_buffer_storage);
      storage = times * _buffer_storage;
      _array = new T[storage];
      _total_buffer_storage = storage;
      copy(rem);
      new_size(get_size<iterator>(rem.begin(), rem.end()));
    }
  }

  template<typename T>
  void vector<T>::assign(size_t n, const T &value)
  {
    realloc(0);
    clear();
    realloc(n);
    _array[n] = 0;
    while (n--)
      _array[n] = value;
  }

  template<typename T>
  void vector<T>::push_back(const T &value)
  {
    size_t rem;

    rem = _size;
    reserve2(_size + 1);
    if (rem == _size)
      new_size(_size + 1);
    _array[_size - 1] = value;
    _array[_size] = 0;
  }

  template<typename T>
  void vector<T>::pop_back()
  {
    if (_size == 0)
      return ;
    _array[_size - 1] = 0;
    new_size(_size - 1);
  }


  template<typename T>
  Vector::iterator<T> vector<T>::insert(iterator position, const T &value)
  {
    size_t rem_pos = get_size(begin(), position); //Position pointer will get lost if memory has to be reallocated

    size_t rem = _size;
    reserve2(_size + 1);
    if (rem == _size)
      new_size(_size + 1);

    position = begin();
    while (rem_pos)
    {
      ++position;
      rem_pos--;
    }

    iterator i = end();
    ft::vector<T> cp = *this;
    iterator cpi = cp.end();

    while (i != position && cpi != begin())
    {
      --cpi;
      *i = *cpi;
      --i;
    }
    *i = value;
    return (i);
  }

  template<typename T>
  void vector<T>::insert(iterator position, size_t n, const T &value)
  {
    while (n)
    {
      position = insert(position, value);
      ++position;
      n--;
    }
  }

  template<typename T>
  template<typename inputiterator>
  void vector<T>::insert(iterator position, inputiterator first, inputiterator last)
  {
    while (first != last)
    {
      position = insert(position, *first);
      ++position;
      ++first;
    }
  }

  template<typename T>
  Vector::iterator<T> vector<T>::erase(iterator position)
  {
    iterator i = end();
    ft::vector<T> cp = *this;
    iterator cpi = cp.end();

    while (i != position)
    {
      --i;
      *i = *cpi;
      --cpi;
    }
    new_size(_size - 1);
    return (i);
  }

  template<typename T>
  Vector::iterator<T> vector<T>::erase(iterator first, iterator last)
  {
    while (first != last)
    {
      first = erase(first);
      --last;
    }
    return first;
  }

  template<typename T>
  void vector<T>::swap(vector<T> &x)
  {
    vector<T> tmp;

    tmp = x;
    x = *this;
    *this = tmp;
    tmp.clear();
  }

  template<typename T>
  void vector<T>::clear()
  {
    if (_size != 0)
      delete [] _array;
    _total_buffer_storage = 0;
    new_size(0);
  }



  template<typename T>
  void vector<T>::new_size(size_t size)
  {
    _size = size;
    _size_left = _total_buffer_storage - _size;
  }

  template<typename T>
  void vector<T>::realloc(size_t size)
  {
    float times;
    size_t storage;

    size += 1;
    times = ceil((float)size / (float)_buffer_storage);
    storage = times * _buffer_storage;
    _array = new T[storage];
    _total_buffer_storage = storage;
    new_size(size - 1);
  }

  template<typename T>
  template<typename inputiterator>
  size_t vector<T>::get_size(inputiterator first, inputiterator last)
  {
    size_t counter = 0;

    while (first != last)
    {
      ++first;
      ++counter;
    }
    return counter;
  }

  template<typename T>
  template<typename inputiterator>
  void vector<T>::copy(inputiterator first, inputiterator last) //Copy with clear and reallocation
  {
    int i;

    i = 0;
    clear();
    realloc(get_size<inputiterator>(first, last));
    while (first != last)
    {
      _array[i] = *first;
      ++first;
      ++i;
    }
    _array[i] = 0;
  }

  template<typename T>
  void vector<T>::copy(const vector<T> &cpy) //Copy withouth reallocating
  {
    size_t i;

    i = 0;
    while (i < cpy.size())
    {
      _array[i] = cpy[i];
      ++i;
    }
    _array[i] = 0;
  }

  template<typename T>
  void vector<T>::reserve2(size_t n)
  {
    vector<T> rem;

    if (n >= _total_buffer_storage)
    {
      rem = *this;
      clear();
      realloc(n);
      copy(rem);
    }
  }


} //End of namespace ft

#endif
