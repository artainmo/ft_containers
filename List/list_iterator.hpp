#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP

#include "list.hpp"

//List iterator is a bidirectional iterator, meaning it can increment or decrement

/*
**CONST
**If you initialize class with const keyword, you will only be able to use const member functions of the class
**-> All functions that do not change values or return address set as const
**-> All functions that return address have one const and one non-const function
**-> All functions that change values do not set as const
*/

namespace List //Using list namespace to separate list iterator with map iterator and vector iterator
{
template<typename T>
class iterator
{
protected:
  struct __list
  {
    struct __list *head;
    struct __list *next;
    struct __list *prev;
    T value;
  };
  struct __list *_list;

public:
  iterator(): _list(nullptr) {}
  iterator(const iterator<T> &to_copy) { *this = to_copy; }
  void operator=(const iterator<T> &to_copy) { _list = to_copy.get_list(); }
  virtual ~iterator() {} //Parent classes always need to have virtual destructor to avoid error

  const struct __list *get_list() const { return _list; } //Getter function, returns pointer address

  bool operator==(const iterator &r) const;
  bool operator!=(const iterator &r) const;
  T &operator*();
  const T &operator*() const;
  void operator*=(T value);
  virtual const T &operator++() const;
  virtual const T &operator--() const;

  //*++ and *-- increment and decrement the value returned by *
};

template<typename T>
bool iterator<T>::operator==(const iterator &r) const
{
  if (_list != r.get_list())
    return false;
  return true;
}

template<typename T>
bool iterator<T>::operator!=(const iterator &r) const
{
  if (_list != r.get_list())
    return true;
  return false;
}

template<typename T>
T &iterator<T>::operator*()
{
  if (_list == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);;
  }
  return (_list->value);
}

template<typename T>
const T &iterator<T>::operator*() const
{
  if (_list == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);;
  }
  return (_list->value);
}

template<typename T>
void iterator<T>::operator*=(T value)
{
  if (_list == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);;
  }
  _list->value = value;
}

template<typename T>
const T &iterator<T>::operator++() const
{
  if (_list == 0 or _list->next == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);;
  }
  _list = _list->next;
  return (_list->value);
}

template<typename T>
const T &iterator<T>::operator--() const
{
  if (_list == 0 or _list->prev == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);;
  }
  _list = _list->prev;
  return (_list->value);
}


template<typename T>
class reverse_iterator : public iterator<T>
{
public:
  reverse_iterator():iterator<T>() {}
  reverse_iterator(const reverse_iterator<T> &to_copy) { *this = to_copy; } //gets operator= function from parent class
  virtual ~reverse_iterator() {}

  const T operator++() const
  {
    if (iterator<T>::_list == 0 or iterator<T>::_list->prev == 0)
    {
      std::cout << "Out of range calling segfault..." << std::endl;
      raise (SIGSEGV);;
    }
    iterator<T>::_list = iterator<T>::_list->prev;
    return (iterator<T>::_list->value);
  }

  const T operator--() const
  {
    if (iterator<T>::_list == 0 or iterator<T>::_list->next == 0)
    {
      std::cout << "Out of range calling segfault..." << std::endl;
      raise (SIGSEGV);;
    }
    iterator<T>::_list = iterator<T>::_list->next;
    return (iterator<T>::_list->value);
  }

};

}//End namespace
#endif
