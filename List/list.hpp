#ifndef LIST_HPP
#define LIST_HPP

#define P(x) std::cout << x << std::endl

#include <iostream>
#include <climits>
#include <csignal>
#include "list_iterator.hpp"

/*
**SPECIAL CASES
**When list and iterator goes out of scope, it stays in last correct position and returns that
**Empty list returns empty iterator that does not segfault and shows nothing on std::cout
*
**Protect iterator from going out of scope
**Protect iterator from empty by returning nothing
**Return empty iterator if empty container
*/



//____NAMESPACE____
//In each scope a name can only represent one entity, impossible to have same name variables in same scope
//By using namespace we can declare two variables or functions with same name, by allowing us to group named entities.
//A namespace is a declarative region that provides a scope for identifiers (variables, functions,...)
namespace ft //Declaration of the namespace ft
{
  //A list is a doubly-linked list, meaning you can iterate forward and backward on it and insert elements where you want in a fast but slow access to their elements way by using chained lists
  template<typename T>
  class list
  {
  private:
    struct __list
    {
      struct __list *head;
      struct __list *next;
      struct __list *prev;
      T value;
    };
    struct __list *_list;
    unsigned int _size;

  public:
    typedef List::iterator<T> iterator;
    typedef const List::iterator<T> const_iterator; //constant meaning that returned values are always constants, only calls constant member functions
    typedef List::reverse_iterator<T> reverse_iterator;
    typedef const List::reverse_iterator<T> const_reverse_iterator;

    list(): _size(0) {}//empty constructor
    list(unsigned int __size, T value); //fill constructor
    template<typename InputIterator>
    list(InputIterator first,InputIterator last); //Range constructor
    list(const list<T> &to_copy):_size(0) {*this = to_copy;} //copy constructor
    void operator=(const list<T> &to_copy); //Assignation constructor
    ~list() { clear(); } //Destructor

    // Iterators
    iterator begin() { iterator ret(_list->head); return (ret); }
    const_iterator begin() const { const_iterator ret(_list->head); return (ret); }
    iterator end();
    const_iterator end() const;
    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator rend() { return (reverse_iterator(_list->head)); }
    const_reverse_iterator rend() const { return (const_reverse_iterator(_list->head)); }

    //Capacity
    bool empty() const;
    unsigned int size() const;
    unsigned int max_size() const { return (UINT_MAX); } //Because the size is stored in an unsigned int, the maximum size of the list is the maximum unsigned int

    //Element access
    T &front();
    const T &front() const;
    T &back();
    const T &back() const;

    //Modifiers
    template<typename InputIterator>
    void assign(InputIterator first, InputIterator last); //Range
    void assign(unsigned int n, T value); //fill
    void push_front (const T &value);
    void pop_front();
    void push_back(const T& value);
    void pop_back();
    iterator insert(iterator position, const T &value); //single element
    void insert(iterator position, unsigned int n, const T &value); //fill
    template <typename InputIterator>
    void insert(iterator position, InputIterator first, InputIterator last); //range
    iterator erase(iterator position);
    iterator erase(iterator first, iterator last);
    void swap(list &x);
    void resize(unsigned int n);
    void resize(unsigned int n, const T &val);
    void clear();

    //operations
    void splice(iterator position, list<T>& x); //Fill all list
    void splice(iterator position, list<T>& x, iterator i); //One element
    void splice(iterator position, list<T>& x, iterator first, iterator last); //Range
    void remove(const T &value);
    template<typename Predicate>
    void remove_if(Predicate pred);
    void unique();
    template<typename BinaryPredicate>
    void unique(BinaryPredicate binary_pred);
    void merge(list<T> &x);
    template <typename Compare>
    void merge(list<T> &x, Compare comp);
    void sort();
    template <typename Compare>
    void sort(Compare comp);
    void reverse();

  };

//Non-member function overloads

template<typename T>
bool operator==(const list<T> &l, const list<T> &r)
{
  List::iterator<T> l_it;
  List::iterator<T> r_it;

  if (l.size() == 0 and r.size() == 0)
    return (true);
  else if (l.size() == 0 || r.size() == 0)
    return (false);
  l_it = l.begin();
  r_it = r.begin();
  if (l.size() != r.size())
    return (false);
  while (l_it != l.end() && r_it != r.end())
  {
    if (*l_it != *r_it)
      return (false);
    ++l_it;
    ++r_it;
  }
  return (true);
}

template <typename T>
bool operator!=(const list<T> &l, const list<T> &r)
{
  List::iterator<T> l_it;
  List::iterator<T> r_it;

  if (l.size() == 0 and r.size() == 0)
    return (false);
  else if (l.size() == 0 || r.size() == 0)
    return (true);
  l_it = l.begin();
  r_it = r.begin();
  if (l.size() != r.size())
    return (true);
  while (l_it != l.end() && r_it != r.end())
  {
    if (*l_it != *r_it)
      return (true);
    ++l_it;
    ++r_it;
  }
  return (false);
}

template <typename T>
bool operator<(const list<T> &l, const list<T> &r)
{
  List::iterator<T> l_it;
  List::iterator<T> r_it;

  if (l.size() == 0 and r.size() == 0)
    return (false);
  else if (l.size() == 0)
    return (true);
  else if (r.size() == 0)
    return (false);
  l_it = l.begin();
  r_it = r.begin();
  while (l_it != l.end() and r_it != r.end())
  {
    if (*l_it != *r_it)
    {
      if (*l_it < *r_it)
        return (true);
      else
        return (false);
    }
    ++l_it;
    ++r_it;
  }
  if (l.size() >= r.size())
    return (false);
  else
    return (true);
}

template <typename T>
bool operator<=(const list<T> &l, const list<T> &r)
{
  List::iterator<T> l_it;
  List::iterator<T> r_it;

  if (l.size() == 0 and r.size() == 0)
    return (true);
  else if (l.size() == 0)
    return (true);
  else if (r.size() == 0)
    return (false);
  l_it = l.begin();
  r_it = r.begin();
  while (l_it != l.end() and r_it != r.end())
  {
    if (*l_it != *r_it)
    {
      if (*l_it < *r_it)
        return (true);
      else
        return (false);
    }
    ++l_it;
    ++r_it;
  }
  if (l.size() > r.size())
    return (false);
  else
    return (true);
}

template <typename T>
bool operator>(const list<T> &l, const list<T> &r)
{
  List::iterator<T> l_it;
  List::iterator<T> r_it;

  if (l.size() == 0 and r.size() == 0)
    return (false);
  else if (l.size() == 0)
    return (false);
  else if (r.size() == 0)
    return (true);
  l_it = l.begin();
  r_it = r.begin();
  while (l_it != l.end() and r_it != r.end())
  {
    if (*l_it != *r_it)
    {
      if (*l_it > *r_it)
        return (true);
      else
        return (false);
    }
    ++l_it;
    ++r_it;
  }
  if (l.size() <= r.size())
    return (false);
  return (true);
}

template <typename T>
bool operator>=(const list<T> &l, const list<T> &r)
{
  List::iterator<T> l_it;
  List::iterator<T> r_it;

  if (l.size() == 0 and r.size() == 0)
    return (true);
  else if (l.size() == 0)
    return (false);
  else if (r.size() == 0)
    return (true);
  l_it = l.begin();
  r_it = r.begin();
  while (l_it != l.end() and r_it != r.end())
  {
    if (*l_it != *r_it)
    {
      if (*l_it > *r_it)
        return (true);
      else
        return (false);
    }
    ++l_it;
    ++r_it;
  }
  if (l.size() < r.size())
    return (false);
  else
    return (true);
}

template <typename T>
void swap(list<T> &x, list<T> &y)
{
  list<T> tmp;

  tmp = x;
  x = y;
  y = tmp;
  tmp.clear();
}

//Member functions

template<typename T>
list<T>::list(unsigned int __size, T value)
{
  _size = 0;
  assign(__size, value);
}

template<typename T>
template<typename InputIterator>
list<T>::list(InputIterator first, InputIterator last)
{
  _size = 0;
  assign<InputIterator>(first, last);
}

template<typename T>
void list<T>::operator=(const list &to_copy) //Deepcopy
{
  clear();
  if (to_copy.size() == 0)
    return ;
  assign<iterator>(to_copy.begin(), to_copy.end());
  // unsigned int i;
  // struct __list *copy;
  //
  // i = 0;
  // if (to_copy.size() == 0)
  //   return ;
  // copy = to_copy._list;
  // _list = new struct __list;
  // _list->head = _list;
  // _list->prev = 0;
  // _list->value = copy->value;
  // while(i < to_copy._size - 1)
  // {
  //   _list->next = new struct __list;
  //   _list->next->head = _list->head;
  //   _list->next->prev = _list;
  //   _list = _list->next;
  //   copy = copy->next;
  //   _list->value = copy->value;
  //   i++;
  // }
  // _list->next = 0;
  // _list = _list->head;
  // _size = to_copy._size;
}

template<typename T>
void list<T>::clear()
{
  unsigned int i;
  struct __list *tmp;

  i = 0;
  if (_size == 0)
    return ;
  _list = _list->head;
  while (i < _size - 1 && _list != 0)
  {
    tmp = _list;
    _list = _list->next;
    delete tmp;
    i++;
  }
  _size = 0;
}

template<typename T>
List::iterator<T> list<T>::end()
{
  struct __list *cur;

  if (_size == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  cur = _list;
  while (cur->next != 0)
    cur = cur->next;
  iterator ret(cur);
  return (ret);
}

template<typename T>
const List::iterator<T> list<T>::end() const
{
  struct __list *cur;

  if (_size == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  cur = _list;
  while (cur->next != 0)
    cur = cur->next;
  const_iterator ret(cur);
  return (ret);
}

template<typename T>
List::reverse_iterator<T> list<T>::rbegin()
{
  struct __list *cur;

  if (_size == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  cur = _list;
  while (cur->next != 0)
    cur = cur->next;
  return (reverse_iterator(cur));
}

template<typename T>
const List::reverse_iterator<T> list<T>::rbegin() const
{
  struct __list *cur;

  if (_size == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  cur = _list;
  while (cur->next != 0)
    cur = cur->next;
  return (const_reverse_iterator(cur));
}

template<typename T>
bool list<T>::empty() const
{
  if (_size == 0)
    return true;
  else
    return false;
}

template<typename T>
unsigned int list<T>::size() const
{
  return (_size);
}

template<typename T>
T &list<T>::front()
{
  if (_size == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  _list = _list->head;
  return (_list->value);
}

template<typename T>
const T &list<T>::front() const
{
  if (_size == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  _list = _list->head;
  return (_list->value);
}

template<typename T>
T &list<T>::back()
{
  struct __list *cur;

  if (_size == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  _list = _list->head;
  cur = _list;
  while (cur->next != 0)
    cur = cur->next;
  return (cur->value);
}

template<typename T>
const T &list<T>::back() const
{
  struct __list *cur;

  if (_size == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  _list = _list->head;
  cur = _list;
  while (cur->next != 0)
    cur = cur->next;
  return (cur->value);
}

template<typename T>
template<typename InputIterator>
void list<T>::assign(InputIterator first, InputIterator last)
{
  clear();
  _list = new struct __list;
  _size++;
  _list->head = _list;
  _list->prev = 0;
  _list->value = *first;
  while (first != last)
  {
    ++first;
    _list->next = new struct __list;
    _size++;
    _list->next->head = _list->head;
    _list->next->prev = _list;
    _list = _list->next;
    _list->value = *first;
  }
  _list->next = 0;
  _list = _list->head;
}

template<typename T>
void list<T>::assign(unsigned int n, T value)
{
  unsigned int i;

  i = 0;
  clear();
  _size = n;
  _list = new struct __list;
  _list->head = _list;
  _list->prev = 0;
  _list->value = value;
  while(i < _size - 1)
  {
    _list->next = new struct __list;
    _list->next->head = _list->head;
    _list->next->prev = _list;
    _list = _list->next;
    _list->value = value;
    i++;
  }
  _list->next = 0;
  _list = _list->head;
}

template<typename T>
void list<T>::push_front(const T &value)
{
  struct __list *front;

  if (_size == 0)
  {
    assign((unsigned int)1, value);
    return ;
  }
  front = new struct __list;
  _list = _list->head;
  front->value = value;
  front->head = front;
  front->prev = 0;
  front->next = _list;
  _list->prev = front;
  _list->head = front;
  while (_list->next != 0)
  {
    _list->next->head = _list->head;
    _list = _list->next;
  }
  _list = _list->head;
  _size++;
}

template<typename T>
void list<T>::pop_front()
{
  struct __list *tmp;

  if (_size == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  if (_size == 1)
  {
    clear();
    return ;
  }
  _list = _list->head;
  tmp = _list;
  _list = _list->next;
  delete tmp;
  _list->prev = 0;
  _list->head = _list;
  while (_list->next != 0)
  {
    _list->next->head = _list->head;
    _list = _list->next;
  }
  _list = _list->head;
  _size--;
}

template<typename T>
void list<T>::push_back(const T& value)
{
  if (_size == 0)
  {
    assign((unsigned int)1, value);
    return ;
  }
  while (_list->next != 0)
    _list = _list->next;
  _list->next = new struct __list;
  _list->next->head = _list->head;
  _list->next->prev = _list;
  _list = _list->next;
  _list->value = value;
  _list->next = 0;
  _list = _list->head;
  _size++;
}

template<typename T>
void list<T>::pop_back()
{
  if (_size == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  _list = _list->head;
  if (_size == 1)
  {
    clear();
    return ;
  }
  else if(_size == 0)
    return ;
  while (_list->next->next != 0)
    _list = _list->next;
  delete _list->next;
  _list->next = 0;
  _list = _list->head;
  _size--;
}

template<typename T>
List::iterator<T> list<T>::insert(iterator position, const T &value)
{
  struct __list *_new;

  if (_size == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  if (_list == (struct __list *)position.get_list()) //get list returns pointer address
  {
    push_front(value);
    return (position);
  }
  _new = new struct __list;
  _list = _list->head;
  while (_list != 0 && _list->next != (struct __list *)position.get_list())
    _list = _list->next;
  if (_list == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  _list->next->prev = _new;
  _new->head = _list->head;
  _new->next = _list->next;
  _new->prev = _list;
  _new->value = value;
  _list->next = _new;
  _list = _list->head;
  _size++;
  --position;
  return (position);
}

template<typename T>
void list<T>::insert(iterator position, unsigned int n, const T &value)
{
  while (n--)
  {
    insert(position, value);
  }
}

template<typename T>
template <typename InputIterator>
void list<T>::insert(iterator position, InputIterator first, InputIterator last)
{
  while (first != last)
  {
    insert(position, *first);
    ++first;
  }
  insert(position, *first);
}

template<typename T>
List::iterator<T> list<T>::erase(iterator position)
{
  struct __list *tmp;

  if (_size == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  _list = _list->head;
  if (_list == (struct __list *)position.get_list())
  {
    pop_front();
    ++position;
    return (position);
  }
  --position;
  while (_list->next != 0 && _list != (struct __list *)position.get_list())
    _list = _list->next;
  tmp = _list->next;
  if (tmp->next == 0)
  {
    pop_back();
    return (position);
  }
  if (_list->next != 0)
  {
    _list->next = _list->next->next;
    if (_list->next != 0)
      _list->next->prev = _list;
  }
  delete tmp;
  _size--;
  _list = _list->head;
  ++position;
  return (position);
}

template<typename T>
List::iterator<T> list<T>::erase(iterator first, iterator last)
{
  while (first != last)
  {
    first = erase(first);
  }
  erase(first);
  return (last);
}

template<typename T>
void list<T>::swap(list &x)
{
  list<T> *tmp = new list<T>;

  *tmp = *this;
  *this = x;
  x = *tmp;
  delete tmp;
}

template<typename T>
void list<T>::resize(unsigned int n)
{
  struct __list *tmp;

  if (n == 0)
    clear();
  if (_size == 0)
  {
    _list = new struct __list;
    _list->head = _list;
    _list->prev = 0;
    _size = 1;
  }
  _list->head = _list->head;
  while (_list->next != 0)
    _list = _list->next;
  while (n > _size)
  {
    _list->next = new struct __list;
    _size++;
    _list->next->head = _list->head;
    _list->next->prev = _list;
    _list = _list->next;
  }
  while (n < _size)
  {
    tmp = _list;
    _list = _list->prev;
    delete tmp;
    _size--;
  }
  _list->next = 0;
  _list = _list->head;
}

template<typename T>
void list<T>::resize(unsigned int n, const T &val)
{
  while (_size != n)
  {
    if (n > _size)
      push_back(val);
    else
      pop_back();
  }
  // struct __list *tmp;
  //
  // // if (_size == 0)
  //   assign((unsigned int)1, val);
  // while (_list->next != 0)
  //   _list = _list->next;
  // while (n > _size)
  // {
  //   _list->next = new struct __list;
  //   _size++;
  //   _list->next->head = _list->head;
  //   _list->next->prev = _list;
  //   _list = _list->next;
  //   _list->value = val;
  // }
  // while (n < _size)
  // {
  //   tmp = _list;
  //   _list = _list->prev;
  //   delete tmp;
  //   _size--;
  // }
  // _list->next = 0;
  // _list = _list->head;
}

template<typename T>
void list<T>::splice(iterator position, list<T> &x)
{
    iterator begin;
    iterator end;

    if (x.empty())
      return ;
    insert<iterator>(position, x.begin(), x.end());
    x.clear();
    _list = _list->head;
}

template<typename T>
void list<T>::splice(iterator position, list<T> &x, iterator i)
{
  insert(position, *i);
  x.erase(i);
  if (_size != 0)
    _list = _list->head;
}

template<typename T>
void list<T>::splice(iterator position, list<T> &x, iterator first, iterator last)
{
  insert(position, first, last);
  x.erase(first, last);
  if (_size != 0)
    _list = _list->head;
}

template<typename T>
void list<T>::remove(const T &value)
{
  iterator iterator;

  if (_size == 0)
    return ;
  iterator = begin();
  while(iterator != end())
  {
    if (*iterator == value)
      iterator = erase(iterator);
    else
      ++iterator;
  }
  if (*iterator == value)
     erase(iterator);
}

template<typename T>
template<typename Predicate>
void list<T>::remove_if(Predicate pred)
{
  iterator iterator;

  if (_size == 0)
    return ;
  iterator = begin();
  while(iterator != end())
  {
    if (pred(*iterator))
      iterator = erase(iterator);
    else
      ++iterator;
  }
  if (pred(*iterator))
     erase(iterator);
}

template<typename T>
void list<T>::unique()
{
  iterator iter;
  iterator follow;

  if (_size == 0)
    return ;
  follow = begin();
  iter = begin();
  ++iter;
  while(iter != end())
  {
    if (*follow == *iter)
      iter = erase(iter);
    else
      ++iter;
    ++follow;
  }
  if (*follow == *iter)
    erase(iter);
}

template<typename T>
template <typename BinaryPredicate>
void list<T>::unique(BinaryPredicate binary_pred)
{
  iterator iter;
  iterator follow;

  if (_size == 0)
    return ;
  follow = begin();
  iter = begin();
  ++iter;
  while(iter != end())
  {
    if (binary_pred(*iter, *follow))
      iter = erase(iter);
    else
      ++iter;
    ++follow;
  }
  if (binary_pred(*iter, *follow))
    erase(iter);
}

template<typename T>
void list<T>::merge(list<T> &x)
{
  iterator iter;

  if (_size == 0 || x.get_size() == 0)
    return ;
  iter = x.begin();
  if (&x == this)
    return ;
  while(iter != x.end())
  {
    push_back(*iter);
    ++iter;
  }
  push_back(*iter);
  x.clear();
}

template<typename T>
template <typename Compare>
void list<T>::merge(list<T> &x, Compare comp)
{
  iterator x_iter;
  iterator self_iter;

  if (_size == 0 || x.get_size() == 0)
    return ;
  x_iter = x.begin();
  self_iter = begin();
  _list = _list->head;
  if (&x == this)
    return ;
  while(self_iter != end() and x_iter != x.end())
  {
    if (comp(*x_iter, *self_iter))
    {
      insert(self_iter, *x_iter);
      ++x_iter;
    }
    else
      ++self_iter;
  }
  if (self_iter == end())
  {
    if (comp(*x_iter, *self_iter))
    {
      insert(self_iter, *x_iter);
      if (x_iter != x.end())
        ++x_iter;
    }
  }
  while(x_iter != x.end())
  {
    push_back(*x_iter);
    ++x_iter;
  }
  x.clear();
}

template<typename T>
void list<T>::sort()
{
  T tmp;

  if (_size == 0)
    return ;
  _list = _list->head;
  while(_list->next != 0)
  {
    if (_list->next->value < _list->value)
    {
      tmp = _list->value;
      _list->value = _list->next->value;
      _list->next->value = tmp;
      _list = _list->head;
    }
    else
      _list = _list->next;
  }
  _list = _list->head;
}

template<typename T>
template <typename Compare>
void list<T>::sort(Compare comp)
{
  T tmp;

  if (_size == 0)
    return ;
  _list = _list->head;
  while(_list->next != 0)
  {
    if (comp(_list->next->value, _list->value))
    {
      tmp = _list->value;
      _list->value = _list->next->value;
      _list->next->value = tmp;
      _list = _list->head;
    }
    else
      _list = _list->next;
  }
  _list = _list->head;
}

template<typename T>
void list<T>::reverse()
{
  list<int> *_new;

  if (_size == 0)
    return ;
  _new = new list<int>;
  _list = _list->head;
  while (_list->next != 0)
  {
    _new->push_front(_list->value);
    _list = _list->next;
  }
  _new->push_front(_list->value);
  *this = *_new;
  delete _new;
}

} //End of the namespace scope
#endif
