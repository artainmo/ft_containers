#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../iterators/random_access_iterator.hpp"
#include <iostream>
#include <tgmath.h>
#include <climits>

namespace ft
{

  template<typename T>
  class vector
  {
  private:
    unsigned int _size_left;
    static const unsigned int _buffer_storage = 10;
    unsigned int _total_buffer_storage;

    unsigned int _size;
    T *_array;

    void realloc(unsigned int size);
    template<typename inputiterator>
    unsigned int get_size(inputiterator first, inputiterator last);
    template<typename inputiterator>
    void copy(inputiterator first, inputiterator last); //Copy with clear and reallocation
    void copy(const vector<T> &cpy); //Copy withouth reallocating
    T &copy(); //Send a copy of the array
    void new_size(unsigned int size);
    void reserve2(unsigned int n);

  public:
    //Constructors
    vector() { realloc(0); }
    vector(unsigned int n, const T &value) { assign(n, value); }
    template<typename inputiterator>
    vector(inputiterator first, inputiterator last) { assign(first, last); } //If ypu do not take as a reference you will lose the values contained in it!!
    vector(const vector<T> &to_copy) {*this = to_copy;}
    ~vector() { clear(); }
    void operator=(const vector<T> &to_copy) { copy(to_copy.begin(), to_copy.end()); }

    //Iterators
    random_access_iterator<T> begin() const { random_access_iterator<T> ret(_array); return ret; }
    random_access_iterator<T> end() const { random_access_iterator<T> ret(_array + _size - 1); return ret; }
    reverse_random_access_iterator<T> rbegin() { reverse_random_access_iterator<T> ret(_array + _size - 1); return ret; }
    reverse_random_access_iterator<T> rend() { reverse_random_access_iterator<T> ret(_array); return ret; }

    //Capacity
    unsigned int size() const { return (_size); }
    unsigned int max_size() const { return (UINT_MAX); } //Because the size is stored in an unsigned int, the maximum size of the list is the maximum unsigned int
    void resize(unsigned int n, const T &value);
    unsigned int capacity() const { return (_total_buffer_storage); }
    bool empty() const;
    void reserve(unsigned int n);

    //Element access
    T &operator[](unsigned int n) const;
    T &at(unsigned int n);
    T &front() { return _array[0]; }
    T &back() { return _array[_size - 1]; }

    //Modifiers
    template<typename inputiterator>
    void assign(inputiterator first, inputiterator last) { realloc(0); copy(first, last); }
    void assign(unsigned int n, const T &value);
    void push_back(const T &value);
    void pop_back();
    random_access_iterator<T> insert(random_access_iterator<T> position, const T &value);
    void insert(random_access_iterator<T> position, unsigned int n, const T &value);
    template<typename inputiterator>
    void insert(random_access_iterator<T> position, inputiterator first, inputiterator last);
    random_access_iterator<T> erase(random_access_iterator<T> position);
    random_access_iterator<T> erase(random_access_iterator<T> first, random_access_iterator<T> last);
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
    while (r[i] and l[i])
    {
      if (r[i] >= l[i])
        return true;
      i++;
    }
    return false;
  }

  template<typename T>
  void vector<T>::resize(unsigned int n, const T &value)
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
  void vector<T>::reserve(unsigned int n)
  {
    float times;
    unsigned int storage;
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
      new_size(get_size<random_access_iterator<int> >(rem.begin(), rem.end()));
    }
  }

  template<typename T>
  T &vector<T>::operator[](unsigned int n) const
  {
    if (n > _total_buffer_storage)
      std::cout << "Iterator out of range" << std::endl;
    return _array[n];
  }

  template<typename T>
  T &vector<T>::at(unsigned int n)
  {
    if (n > _total_buffer_storage)
      std::cout << "Iterator out of range" << std::endl;
    return _array[n];
  }

  template<typename T>
  void vector<T>::assign(unsigned int n, const T &value)
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
    unsigned int rem;

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
    _array[_size - 1] = 0;
    new_size(_size - 1);
  }


  template<typename T>
  random_access_iterator<T> vector<T>::insert(random_access_iterator<T> position, const T &value)
  {
    random_access_iterator<T> i = end();
    random_access_iterator<T> l = end();
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
  void vector<T>::insert(random_access_iterator<T> position, unsigned int n, const T &value)
  {
    while (n)
    {
      position = insert(position, value);
      n--;
    }
  }

  template<typename T>
  template<typename inputiterator>
  void vector<T>::insert(random_access_iterator<T> position, inputiterator first, inputiterator last)
  {
    while (first != last)
    {
      insert(position, *first);
      ++first;
    }
    insert(position, *first);
  }

  template<typename T>
  random_access_iterator<T> vector<T>::erase(random_access_iterator<T> position)
  {
    random_access_iterator<T> i = end();
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
  random_access_iterator<T> vector<T>::erase(random_access_iterator<T> first, random_access_iterator<T> last)
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
  void vector<T>::new_size(unsigned int size)
  {
    _size = size;
    _size_left = _total_buffer_storage - _size;
  }

  template<typename T>
  void vector<T>::realloc(unsigned int size)
  {
    float times;
    unsigned int storage;

    size += 1;
    times = ceil((float)size / (float)_buffer_storage);
    storage = times * _buffer_storage;
    _array = new T[storage];
    _total_buffer_storage = storage;
    new_size(size - 1);
  }

  template<typename T>
  template<typename inputiterator>
  unsigned int vector<T>::get_size(inputiterator first, inputiterator last)
  {
    unsigned int counter;

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
  void vector<T>::reserve2(unsigned int n)
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
