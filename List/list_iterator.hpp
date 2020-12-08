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

  void go_to_start()
  {
    while (_list->prev->prev != 0)
      _list = _list->prev;
  }
  void go_to_end()
  {
    while (_list->next != 0)
      _list = _list->next;
  }
  size_t ft_strlen() const
  {
    struct __list *tmp = _list;
    size_t lenght = 0;

    while (tmp->prev->prev != 0)
    {
      lenght++;
      tmp = tmp->prev;
    }
    return lenght;
  }

public:
  iterator(): _list(nullptr) {}
  iterator(const iterator<T> &to_copy) { *this = to_copy; }
  void operator=(const iterator<T> &to_copy) { _list = to_copy.get_list(); }
  iterator(void *list_): _list(static_cast<struct __list *>(list_)) {} //If conversion to type not possible static cast returns compilation error, takes in void * to keep struct __list private
  virtual ~iterator() {} //Parent classes always need to have virtual destructor to avoid error

  struct __list *get_list() const { return _list; } //Getter function, returns pointer address

  bool operator==(const iterator &r) const { if (_list != r.get_list()) return false; else return true; }
  bool operator!=(const iterator &r) const { if (_list != r.get_list()) return true; else return false; }
  T &operator*()
  {
    if (_list->next == 0)
      _list->value = ft_strlen();
    return (_list->value);
  }
  const T &operator*() const
  {
    return (_list->value);
  }
  void operator*=(T value) { _list->value = value; }
  virtual T& operator++() //Returns a reference
  {
    if (_list->next == 0)
    {
      go_to_start();
      return _list->value;
    }
    _list = _list->next;
    return _list->value;
  }
  virtual T operator++(int) //(int) Used to indicate that ++ comes after variable and not before //Returns a copy
  {
    if (_list->next == 0)
    {
      go_to_start();
      return _list->value;
    }
    _list = _list->next;
    return _list->value;
  }

  virtual T& operator--()
  {
    if (_list->prev->prev == 0)
    {
      go_to_end();
      return _list->value;
    }
    _list = _list->prev;
    return _list->value;
  }
  virtual T operator--(int)
  {
    if (_list->prev->prev == 0)
    {
      go_to_end();
      return _list->value;
    }
    _list = _list->prev;
    return _list->value;
  }

  //*++ and *-- increment and decrement the value returned by *
};


template<typename T>
class reverse_iterator : public iterator<T>
{
public:
  reverse_iterator():iterator<T>() {}
  reverse_iterator(const reverse_iterator<T> &to_copy) { *this = to_copy; } //gets operator= function from parent class
  reverse_iterator(void *list_):iterator<T>(list_) {}
  virtual ~reverse_iterator() {}

  T& operator++()
  {
    if (iterator<T>::_list->prev->prev == 0)
    {
      iterator<T>::go_to_end();
      return iterator<T>::_list->value;
    }
    iterator<T>::_list = iterator<T>::_list->prev;
    return iterator<T>::_list->value;
  }
  T operator++(int)
  {
    if (iterator<T>::_list->prev->prev == 0)
    {
      iterator<T>::go_to_end();
      return iterator<T>::_list->value;
    }
    iterator<T>::_list = iterator<T>::_list->prev;
    return iterator<T>::_list->value;
  }

  T& operator--()
  {
    if (iterator<T>::_list->next == 0)
    {
      iterator<T>::go_to_start();
      return iterator<T>::_list->value;
    }
    iterator<T>::_list = iterator<T>::_list->next;
    return iterator<T>::_list->value;
  }
  T operator--(int)
  {
    if (iterator<T>::_list->next == 0)
    {
      iterator<T>::go_to_start();
      return iterator<T>::_list->value;;
    }
    iterator<T>::_list = iterator<T>::_list->next;
    return iterator<T>::_list->value;
  }

};

}//End namespace
#endif
