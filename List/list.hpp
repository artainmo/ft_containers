#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <csignal>
#include <limits>
#include "list_iterator.hpp"

/*
**FUNCTIONALITY DETAILS
**Empty container always contains a minimum of 1 end struct (unfortunately by misunderstanding I have two basis structs, can be practical for rend() though)
**Iterator end returns size (if constructor object cannot accept size like std::string it segfaults)
**Iterator begin-- goes backward and equals to end
**Iterator end++ goes backwards and equal to begin()
*/


/*
**____NAMESPACE____
**In each scope a name can only represent one entity, impossible to have same name variables in same scope
**By using namespace we can declare two variables or functions with same name, by allowing us to group named entities.
**A namespace is a declarative region that provides a scope for identifiers (variables, functions,...)
*/

namespace ft
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
    size_t _size;

    void ending_empty_container(); //Empty container should always at least contain two empty structs one for begin and one for end
    int check_if_in(const list<T> &x, List::iterator<T> find) const;

  public:
    typedef T value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;

    typedef List::iterator<T> iterator;
    typedef const List::iterator<T> const_iterator; //constant meaning that returned values are always constants, only calls constant member functions
    typedef List::reverse_iterator<T> reverse_iterator;
    typedef const List::reverse_iterator<T> const_reverse_iterator;

    list(): _size(0) { ending_empty_container(); } //empty/default constructor
    list(size_t __size, T value = T()): _size(0) { ending_empty_container(); assign(__size, value); } //fill constructor
    template<typename InputIterator>
    list(InputIterator first,InputIterator last): _size(0) { ending_empty_container(); assign<InputIterator>(first, last); } //Range constructor
    list(const list<T> &to_copy): _size(0) { *this = to_copy;} //copy constructor
    list &operator=(const list<T> &to_copy) { if (_size == 0) ending_empty_container(); clear(); if (to_copy.empty()) return *this; assign<iterator>(to_copy.begin(), to_copy.end()); return *this; } //Assignation constructor
    ~list() { clear(); delete _list->next; delete _list; } //Destructor

    // Iterators
    iterator begin() { return iterator(_list->head->next); }
    const_iterator begin() const { return const_iterator(_list->head->next); }
    iterator end();
    const_iterator end() const;
    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator rend() { return const_reverse_iterator(_list->head); }
    const_reverse_iterator rend() const { return const_reverse_iterator(_list->head); }

    //Capacity
    bool empty() const { if (_size == 0) return true; else return false; }
    size_t size() const { return (_size); }
    size_t max_size() const { return std::numeric_limits<size_t>::max(); } //Because the size is stored in a size_t, https://en.cppreference.com/w/cpp/container/list/max_size

    //Element access
    T &front() { return (_list->head->next->value); }
    const T &front() const { return (_list->head->next->value); }
    T &back();
    const T &back() const;

    //Modifiers
    template<typename InputIterator>
    void assign(InputIterator first, InputIterator last); //Range
    void assign(size_type n, value_type value); //fill
    void push_front (const T &value);
    void pop_front();
    void push_back(const T& value);
    void pop_back();
    iterator insert(iterator position, const T &value); //single element
    void insert(iterator position, size_type n, const value_type &value); //fill
    template <typename InputIterator>
    void insert(iterator position, InputIterator first, InputIterator last); //range
    iterator erase(iterator position);
    iterator erase(iterator first, iterator last);
    void swap(list &x);
    void resize(size_t n);
    void resize(size_t n, const T &val);
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
void swap(list<T> &x, list<T> &y) { x.swap(y); }

//Member functions
template<typename T>
void list<T>::clear()
{
  struct __list *tmp;

  _list = _list->head;
  while (_list != 0)
  {
    tmp = _list;
    _list = _list->next;
    delete tmp;
  }
  _size = 0;
  ending_empty_container();
}

template<typename T>
List::iterator<T> list<T>::end()
{
  struct __list *cur;

  cur = _list;
  while (cur->next != 0)
    cur = cur->next;
  return iterator(cur);
}

template<typename T>
const List::iterator<T> list<T>::end() const
{
  struct __list *cur;

  cur = _list;
  while (cur->next != 0)
    cur = cur->next;
  return const_iterator(cur);
}

template<typename T>
List::reverse_iterator<T> list<T>::rbegin()
{
  struct __list *cur;

  if (_size == 0)
      return reverse_iterator(_list->next);
  _list = _list->head;
  cur = _list;
  while (cur->next->next != 0)
    cur = cur->next;
  return reverse_iterator(cur);
}

template<typename T>
const List::reverse_iterator<T> list<T>::rbegin() const
{
  struct __list *cur;

  if (_size == 0)
      return reverse_iterator(_list->next);
  cur = _list->head;
  while (cur->next->next != 0)
    cur = cur->next;
  return reverse_iterator(cur);
}

template<typename T>
T &list<T>::back()
{
  struct __list *cur;

  _list = _list->head;
  cur = _list;
  if (_size == 0)
    return (cur->value);
  while (cur->next->next != 0)
    cur = cur->next;
  return (cur->value);
}

template<typename T>
const T &list<T>::back() const
{
  struct __list *cur;

  cur = _list->head;
  if (_size == 0)
    return (cur->value);
  while (cur->next->next != 0)
    cur = cur->next;
  return (cur->value);
}

template<typename T>
template<typename InputIterator>
void list<T>::assign(InputIterator first, InputIterator last)
{
  clear();
  if (first == last)
    return ;
  while (first != last)
  {
    push_back(*first);
    ++first;
  }
}

template<typename T>
void list<T>::assign(size_t n, T value)
{
  clear();
  if (n == 0)
    return ;
  while (n--)
    push_back(value);
}

template<typename T>
void list<T>::push_front(const T &value)
{
  struct __list *front;

  _list = _list->head;
  front = new struct __list;
  front->next = _list->next;
  _list->next->prev = front;
  front->head = _list;
  front->value = value;
  front->prev = _list;
  _list->next = front;
  _size++;
}

template<typename T>
void list<T>::pop_front()
{
  struct __list *tmp;

  if (_size == 0)
    return ;
  _list = _list->head;
  tmp = _list->next;
  _list->next = tmp->next;
  tmp->next->prev = _list;
  delete tmp;
  _size--;
}

template<typename T>
void list<T>::push_back(const T &value)
{
  struct __list *tmp;

  _list = _list->head;
  while (_list->next != 0)
    _list = _list->next;
  tmp = _list->prev;
  _list->prev = new struct __list;
  _list->prev->head = _list->head;
  _list->prev->next = _list;
  _list->prev->prev = tmp;
  _list->prev->value = value;
  tmp->next = _list->prev;
  _list = _list->head;
  _size++;
}

template<typename T>
void list<T>::pop_back()
{
  struct __list *tmp;

  _list = _list->head;
  if (_size == 0)
    return ;
  while (_list->next != 0)
    _list = _list->next;
  tmp = _list->prev;
  tmp->prev->next = _list;
  _list->prev = tmp->prev;
  delete tmp;
  _size--;
}

template<typename T>
List::iterator<T> list<T>::insert(iterator position, const T &value)
{
  struct __list *_new;
  struct __list *tmp;
  iterator i = begin();

  while (i != end() && i != position)
    ++i;
  if (i == end() && i != position) //position not found, undefined behavior return position
    return position;
  _new = new struct __list;
  tmp = (struct __list *)i.get_list(); //get list returns pointer address
  _new->head = tmp->head;
  _new->next = tmp;
  _new->prev = tmp->prev;
  _new->value = value;
  tmp->prev->next = _new;
  tmp->prev = _new;
  _size++;
  --position;
  return (position);
}

template<typename T>
void list<T>::insert(iterator position, size_t n, const T &value)
{
  while (n--)
    insert(position, value);
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
}

template<typename T>
List::iterator<T> list<T>::erase(iterator position)
{
  iterator i = begin();
  struct __list *tmp;

  while (i != end() && i != position)
    ++i;
  if (i == end()) //position not found and end cannot be erased, undefined behavior return position
    return (position);
  ++position;
  tmp = (struct __list *)i.get_list();
  tmp->prev->next = tmp->next;
  tmp->next->prev = tmp->prev;
  delete tmp;
  _size--;
  return (position);
}

template<typename T>
List::iterator<T> list<T>::erase(iterator first, iterator last)
{
  while (first != last)
    first = erase(first);
  return (last);
}

template<typename T>
void list<T>::swap(list &x)
{
  list<T> tmp;

  tmp = *this;
  *this = x;
  x = tmp;
}

template<typename T>
void list<T>::resize(size_t n)
{
  if (n <= 0)
    clear();
  while (_size != n)
  {
    if (n > _size)
      push_back(0);
    else
      pop_back();
  }
}

template<typename T>
void list<T>::resize(size_t n, const T &val)
{
  if (n <= 0)
    clear();
  while (_size != n)
  {
    if (n > _size)
      push_back(val);
    else
      pop_back();
  }
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
}

template<typename T>
void list<T>::splice(iterator position, list<T> &x, iterator i)
{
  if (check_if_in(*this, position) == 0 || check_if_in(x, i) != 1) //position = end() can be inserted but cannot be erased
    return ;
  insert(position, *i); //If element not found, do nothing
  x.erase(i);
}

template<typename T>
void list<T>::splice(iterator position, list<T> &x, iterator first, iterator last)
{
  insert(position, first, last);
  x.erase(first, last);
}

template<typename T>
void list<T>::remove(const T &value)
{
  iterator i = begin();

  if (_size == 0)
    return ;
  while(i != end())
  {
    if (*i == value)
      i = erase(i);
    else
      ++i;
  }
}

template<typename T>
template<typename Predicate>
void list<T>::remove_if(Predicate pred)
{
  iterator i = begin();

  if (_size == 0)
    return ;
  while(i != end())
  {
    if (pred(*i))
      i = erase(i);
    else
      ++i;
  }
}

template<typename T>
void list<T>::unique()
{
  iterator iter = begin();
  ++iter;
  iterator follow = begin();

  if (_size == 0 || _size == 1)
    return ;
  while(iter != end())
  {
    if (*follow == *iter)
      iter = erase(iter);
    else
      ++iter;
    ++follow;
  }
}

template<typename T>
template <typename BinaryPredicate>
void list<T>::unique(BinaryPredicate binary_pred)
{
  iterator iter = begin();
  ++iter;
  iterator follow = begin();

  if (_size == 0 || _size == 1)
    return ;
  while(iter != end())
  {
    if (binary_pred(*follow, *iter)) //Seems counterintuitive but gives similar result as real
    {
      erase(iter);
      unique(binary_pred);
      return ;
    }
    ++iter;
    ++follow;
  }
}

template<typename T>
void list<T>::merge(list<T> &x)
{
  iterator iter = x.begin();
  T tmp = back();

  if (x.empty())
    return ;
  if (&x == this)
    return ;
  while(iter != x.end())
  {
    push_back(*iter);
    ++iter;
  }
  if (tmp > x.front())
    sort();
  x.clear();
}

template<typename T>
template <typename Compare>
void list<T>::merge(list<T> &x, Compare comp)
{
  iterator iter = x.begin();
  T tmp = back();

  if (x.empty())
    return ;
  if (&x == this)
    return ;
  while(iter != x.end())
  {
    push_back(*iter);
    ++iter;
  }
  if (comp(x.front(), tmp))
    sort(comp);
  x.clear();
}

template<typename T>
void list<T>::sort()
{
  iterator iter = begin();
  ++iter;
  iterator follow = begin();
  T tmp;

  if (_size == 0 || _size == 1)
    return ;
  while(iter != end())
  {
    if (*follow > *iter)
    {
      tmp = *follow;
      *follow = *iter;
      *iter = tmp;
      sort();
      return ;
    }
    ++iter;
    ++follow;
  }
}

template<typename T>
template <typename Compare>
void list<T>::sort(Compare comp)
{
  iterator iter = begin();
  ++iter;
  iterator follow = begin();
  T tmp;

  if (_size == 0 || _size == 1)
    return ;
  while(iter != end())
  {
    if (comp(*iter, *follow))
    {
      tmp = *follow;
      *follow = *iter;
      *iter = tmp;
      sort(comp);
      return ;
    }
    ++iter;
    ++follow;
  }
}

template<typename T>
void list<T>::reverse()
{
  list<T> *_new;

  if (_size == 0  || _size == 1)
    return ;
  _new = new list<T>;
  _list = _list->head->next;
  while (_list->next != 0)
  {
    _new->push_front(_list->value);
    _list = _list->next;
  }
  *this = *_new;
  delete _new;
}

template<typename T>
void list<T>::ending_empty_container()
{
  _list = new struct __list;
  struct __list *end = new struct __list;
  _list->next = end;
  _list->prev = 0;
  _list->value = T(); //Accepts ints, std::string,....
  _list->head = _list;
  end->next = 0;
  end->prev = _list;
  end->value = T();
  end->head = _list;
  return ;
 }

 template<typename T>
 int list<T>::check_if_in(const list<T> &x, List::iterator<T> find) const//Checks if position exists inside list, if not return 0, if yes return 1, if equal to end() return 2
 {
   iterator i = x.begin();

   if (find == x.end())
    return 2;
   while (i != x.end())
   {
     if (i == find)
      return 1;
     ++i;
   }
   return 0;
 }

} //End of the namespace scope
#endif
