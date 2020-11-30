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
**Begin, rbegin, end, rend functions should return empty iterator instead of calling segfault when container is empty /
**When trying to access empty container segfaults (front, back, at, []) /
**Unused allocated memory should be set to null, c++ automatically sets to null /
**Iterator object should be able to iterate freely, no protections /
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
    T &copy(); //Send a copy of the array
    void new_size(size_t size);
    void reserve2(size_t n);

  public:
    //Iterators
    typedef Vector::iterator<T> iterator;
    typedef const Vector::iterator<T> const_iterator;
    typedef Vector::reverse_iterator<T> reverse_iterator;
    typedef const Vector::reverse_iterator<T> const_reverse_iterator;

    //Constructors
    vector() { realloc(0); } //Realloc is own function that uses new keyword
    vector(size_t n, const T &value) { assign(n, value); }
    template<typename inputiterator>
    vector(inputiterator first, inputiterator last) { assign(first, last); } //If you do not take as a reference you will lose the values contained in it!!
    vector(const vector<T> &to_copy) {*this = to_copy;}
    void operator=(const vector<T> &to_copy) { copy(to_copy.begin(), to_copy.end()); } //Deep copy
    ~vector() { clear(); }

    //Iterators
    iterator begin() { if (empty()) return iterator(); else return iterator(_array); }
    const_iterator begin() const { if (empty()) return const_iterator(); else return const_iterator(_array); }
    iterator end() { if (empty()) return iterator(); else return iterator(_array + _size - 1); }
    const_iterator end() const { if (empty()) return const_iterator(); else return const_iterator(_array + _size - 1); }
    reverse_iterator rbegin() { if (empty()) return reverse_iterator(); else return reverse_iterator(_array + _size - 1); }
    const_reverse_iterator rbegin() const { if (empty()) return const_reverse_iterator(); else return const_reverse_iterator(_array + _size - 1); }
    reverse_iterator rend() { if (empty()) return reverse_iterator(); else return reverse_iterator(_array); }
    const_reverse_iterator rend() const { if (empty()) return const_reverse_iterator(); else return const_reverse_iterator(_array); }

    //Capacity
    size_t size() const { return (_size); }
    size_t max_size() const { return std::numeric_limits<size_t>::max(); } //Because the size is stored in a size_t, https://en.cppreference.com/w/cpp/container/list/max_size
    void resize(size_t n, const T &value); //Change size
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
    int i;

    i = 0;
    if (r.size() != l.size())
      return false;
    if (r.size() == 0 and l.size() == 0)
      return true;
    while (r[i] && l[i])
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
    int i;

    i = 0;
    if (r.size() != l.size())
      return true;
    if (r.size() == 0 and l.size() == 0)
      return false;
    while (r[i] and l[i])
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
    int i;

    i = 0;
    if (r.size() < l.size())
      return true;
    if (r.size() == l.size() || l.size() == 0)
      return false;
    while (r[i] and l[i])
    {
      if (r[i] < l[i])
        return true;
      i++;
    }
    return false;
  }

  template<typename T>
  bool operator<=(const vector<T> &r, const vector<T> &l)
  {
    int i;

    i = 0;
    if (r.size() <= l.size())
      return true;
    if (l.size() == 0)
      return false;
    while (r[i] and l[i])
    {
      if (r[i] <= l[i])
        return true;
      i++;
    }
    return false;
  }

  template<typename T>
  bool operator>(const vector<T> &r, const vector<T> &l)
  {
    int i;

    i = 0;
    if (r.size() > l.size())
      return true;
    if (r.size() == l.size() || r.size() == 0)
      return false;
    while (r[i] and l[i])
    {
      if (r[i] > l[i])
        return true;
      i++;
    }
    return false;
  }

  template<typename T>
  bool operator>=(const vector<T> &r, const vector<T> &l)
  {
    int i;

    i = 0;
    if (r.size() >= l.size())
      return true;
    if (r.size() == 0)
      return false;
    while (r[i] and l[i])
    {
      if (r[i] >= l[i])
        return true;
      i++;
    }
    return false;
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
    if (_size == 0)
    {
      std::cout << "Out of range calling segfault..." << std::endl;
      raise (SIGSEGV);
    }
    iterator i = end();
    iterator l = end();
    T rem;

    rem = *i;
    while (i != position)
    {
      --i;
      *l = *i;
      --l;
    }
    *i = value;
    push_back(rem);
    return (i);
  }

  template<typename T>
  void vector<T>::insert(iterator position, size_t n, const T &value)
  {
    while (n)
    {
      position = insert(position, value);
      n--;
    }
  }

  template<typename T>
  template<typename inputiterator>
  void vector<T>::insert(iterator position, inputiterator first, inputiterator last)
  {
    while (first != last)
    {
      insert(position, *first);
      ++first;
    }
    insert(position, *first);
  }

  template<typename T>
  Vector::iterator<T> vector<T>::erase(iterator position)
  {
    if (_size == 0)
    {
      std::cout << "Out of range calling segfault..." << std::endl;
      raise (SIGSEGV);
    }
    iterator i = end();
    T tmp1;
    T tmp2;

    tmp1 = *i;
    *i = 0;
    while (i != position)
    {
      --i;
      tmp2 = *i;
      *i = tmp1;
      tmp1 = tmp2;
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
    erase(first);
    return last;
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
    size_t counter;

    counter = 1;
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
    _array[i] = *first;
    _array[++i] = 0;
  }

  template<typename T>
  void vector<T>::copy(const vector<T> &cpy) //Copy withouth reallocating
  {
    int i;

    i = 0;
    while (cpy[i] != 0)
    {
      _array[i] = cpy[i];
      ++i;
    }
    _array[i] = 0;
  }

  template<typename T>
  T &vector<T>::copy() //Send a copy of the array
  {
    int i;
    T *_new;

    i = 0;
    _new = new T[_size];
    while (_array[i] != 0)
    {
      _new[i] = _array[i];
      ++i;
    }
    _new[i] = 0;
    return _new;
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
