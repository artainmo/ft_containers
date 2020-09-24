#ifndef LIST_HPP
#define LIST_HPP

#define P(x) std::cout << x << std::endl

#include <iostream>
#include <climits>
#include "../iterators/bidirectional_iterator.hpp"

template<typename Key, typename T> class bidirectional_iterator;
template<typename Key, typename T> class reverse_bidirectional_iterator;
template<typename T> struct __list;

//____NAMESPACE____
//In each scope a name can only represent one entity, impossible to have same name variables in same scope
//By using namespace we can declare two variables or functions with same name, by allowing us to group named entities.
//A namespace is a declarative region that provides a scope for identifiers (variables, functions,...)
namespace ft //Declaration of the namespace ft
{

  template<typename T>
  class list
  {
  public:
    //Iterator system list
    bidirectional_iterator<T> iterator; //bidirectional meaning you can increment and decrement it
    // const_bidirectional_iterator<T> const_iterator; //constant meaning that returned values are alays constants
    reverse_bidirectional_iterator<T> reverse_iterator; //reverse meaning begin becomes end and end becomes begin and increment becomes decrement and decrement becomes increment
    // const_reverse_bidirectional_iterator<T> const_reverse_iterator;
  private:
    struct __list<T> *_list;
    unsigned int _size;

    void free_list();

  public:
    list(): _size(0) {}//empty constructor
    list(unsigned int __size, T value); //fill constructor
    template<typename InputIterator>
    list(InputIterator first,InputIterator last); //Range constructor
    list(const list<T> &to_copy) {_size = 0; *this = to_copy;} //copy constructor

    ~list() { free_list(); } //Destructor

    void operator=(const list<T> &to_copy); //Assignation constructor

    // Iterators
    bidirectional_iterator<T> begin() const { bidirectional_iterator<T> ret(_list->head); return (ret); }
    bidirectional_iterator<T> end() const;
    reverse_bidirectional_iterator<T> rbegin();
    reverse_bidirectional_iterator<T> rend() { return (reverse_bidirectional_iterator<T>(_list->head)); }

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
    bidirectional_iterator<T> insert(bidirectional_iterator<T> position, const T &value); //single element
    void insert(bidirectional_iterator<T> position, unsigned int n, const T &value); //fill
    template <typename InputIterator>
    void insert(bidirectional_iterator<T> position, InputIterator first, InputIterator last); //range
    bidirectional_iterator<T> erase(bidirectional_iterator<T> position);
    bidirectional_iterator<T> erase(bidirectional_iterator<T> first, bidirectional_iterator<T> last);
    void swap(list &x);
    void resize(unsigned int n);
    void resize(unsigned int n, const T &val);
    void clear();

    //operations
    void splice(bidirectional_iterator<T> position, list<T>& x); //Fill all list
    void splice(bidirectional_iterator<T> position, list<T>& x, bidirectional_iterator<T> i); //One element
    void splice(bidirectional_iterator<T> position, list<T>& x, bidirectional_iterator<T> first, bidirectional_iterator<T> last); //Range
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

//Relational operators
template<typename T>
bool operator==(const list<T> &l, const list<T> &r)
{
  bidirectional_iterator<T> l_it;
  bidirectional_iterator<T> r_it;

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
  bidirectional_iterator<T> l_it;
  bidirectional_iterator<T> r_it;

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
  bidirectional_iterator<T> l_it;
  bidirectional_iterator<T> r_it;

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
  bidirectional_iterator<T> l_it;
  bidirectional_iterator<T> r_it;

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
  bidirectional_iterator<T> l_it;
  bidirectional_iterator<T> r_it;

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
  else
    return (true);
}

template <typename T>
bool operator>=(const list<T> &l, const list<T> &r)
{
  bidirectional_iterator<T> l_it;
  bidirectional_iterator<T> r_it;

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
void list<T>::operator=(const list &to_copy)
{
  unsigned int i;
  struct __list<T> *copy;

  i = 0;
  if (to_copy.size() == 0)
    return ;
  copy = to_copy._list;
  _list = new struct __list<T>;
  _list->head = _list;
  _list->prev = 0;
  _list->value = copy->value;
  while(i < to_copy._size - 1)
  {
    _list->next = new struct __list<T>;
    _list->next->head = _list->head;
    _list->next->prev = _list;
    _list = _list->next;
    copy = copy->next;
    _list->value = copy->value;
    i++;
  }
  _list->next = 0;
  _list = _list->head;
  _size = to_copy._size;
  iterator = to_copy.iterator;
}

template<typename T>
void list<T>::free_list()
{
  unsigned int i;
  struct __list<T> *tmp;

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
}

template<typename T>
bidirectional_iterator<T> list<T>::end() const
{
  struct __list<T> *cur;

  cur = _list;
  while (cur->next != 0)
    cur = cur->next;
  bidirectional_iterator<T> ret(cur);
  return (ret);
}

template<typename T>
reverse_bidirectional_iterator<T> list<T>::rbegin()
{
  struct __list<T> *cur;

  cur = _list;
  while (cur->next != 0)
    cur = cur->next;
  return (reverse_bidirectional_iterator<T>(cur));
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
  _list = _list->head;
  return (_list->value);
}

template<typename T>
const T &list<T>::front() const
{
  _list = _list->head;
  return (_list->value);
}

template<typename T>
T &list<T>::back()
{
  struct __list<T> *cur;

  _list = _list->head;
  cur = _list;
  while (cur->next != 0)
    cur = cur->next;
  return (cur->value);
}

template<typename T>
const T &list<T>::back() const
{
  struct __list<T> *cur;

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
  _list = new struct __list<T>;
  _size++;
  _list->head = _list;
  _list->prev = 0;
  _list->value = *first;
  while (first != last)
  {
    ++first;
    _list->next = new struct __list<T>;
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
  free_list();
  _size = n;
  _list = new struct __list<T>;
  _list->head = _list;
  _list->prev = 0;
  _list->value = value;
  while(i < _size - 1)
  {
    _list->next = new struct __list<T>;
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
  struct __list<T> *front;

  if (_size == 0)
  {
    assign((unsigned int)1, value);
    return ;
  }
  front = new struct __list<T>;
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
  struct __list<T> *tmp;

  if (_size == 0)
    return ;
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
  _list->next = new struct __list<T>;
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
    return ;
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
bidirectional_iterator<T> list<T>::insert(bidirectional_iterator<T> position, const T &value)
{
  struct __list<T> *_new;

  if (_list == (struct __list<T> *)position.get_list_ptr())
  {
    push_front(value);
    return (position);
  }
  _new = new struct __list<T>;
  _list = _list->head;
  while (_list->next != (struct __list<T> *)position.get_list_ptr())
    _list = _list->next;
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
void list<T>::insert(bidirectional_iterator<T> position, unsigned int n, const T &value)
{
  while (n--)
  {
    insert(position, value);
  }
}

template<typename T>
template <typename InputIterator>
void list<T>::insert(bidirectional_iterator<T> position, InputIterator first, InputIterator last)
{
  while (first != last)
  {
    insert(position, *first);
    ++first;
  }
  insert(position, *first);
}

template<typename T>
bidirectional_iterator<T> list<T>::erase(bidirectional_iterator<T> position)
{
  struct __list<T> *tmp;

  _list = _list->head;
  if (_list == (struct __list<T> *)position.get_list_ptr())
  {
    pop_front();
    ++position;
    return (position);
  }
  --position;
  while (_list->next != 0 && _list != (struct __list<T> *)position.get_list_ptr() && _list != (struct __list<T> *)position.get_list_ptr())
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
bidirectional_iterator<T> list<T>::erase(bidirectional_iterator<T> first, bidirectional_iterator<T> last)
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
  struct __list<T> *tmp;

  _list->head = _list->head;
  while (_list->next != 0)
    _list = _list->next;
  while (n > _size)
  {
    _list->next = new struct __list<T>;
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
  struct __list<T> *tmp;

  while (_list->next != 0)
    _list = _list->next;
  while (n > _size)
  {
    _list->next = new struct __list<T>;
    _size++;
    _list->next->head = _list->head;
    _list->next->prev = _list;
    _list = _list->next;
    _list->value = val;
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
void list<T>::clear()
{
  free_list();
  _size = 0;
}

template<typename T>
void list<T>::splice(bidirectional_iterator<T> position, list<T> &x)
{
    bidirectional_iterator<T> begin;
    bidirectional_iterator<T> end;

    insert<bidirectional_iterator<int> >(position, x.begin(), x.end());
    x.clear();
    _list = _list->head;
}

template<typename T>
void list<T>::splice(bidirectional_iterator<T> position, list<T> &x, bidirectional_iterator<T> i)
{
  insert(position, *i);
  x.erase(i);
  _list = _list->head;
}

template<typename T>
void list<T>::splice(bidirectional_iterator<T> position, list<T>& x, bidirectional_iterator<T> first, bidirectional_iterator<T> last)
{
  insert(position, first, last);
  x.erase(first, last);
  _list = _list->head;
}

template<typename T>
void list<T>::remove(const T &value)
{
  bidirectional_iterator<T> iterator;

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
  bidirectional_iterator<T> iterator;

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
  bidirectional_iterator<T> iterator;
  bidirectional_iterator<T> follow;

  follow = begin();
  iterator = begin();
  ++iterator;
  while(iterator != end())
  {
    if (*follow == *iterator)
      iterator = erase(iterator);
    else
      ++iterator;
    ++follow;
  }
  if (*follow == *iterator)
    erase(iterator);
}

template<typename T>
template <typename BinaryPredicate>
void list<T>::unique(BinaryPredicate binary_pred)
{
  bidirectional_iterator<T> iterator;
  bidirectional_iterator<T> follow;

  follow = begin();
  iterator = begin();
  ++iterator;
  while(iterator != end())
  {
    if (binary_pred(*iterator, *follow))
      iterator = erase(iterator);
    else
      ++iterator;
    ++follow;
  }
  if (binary_pred(*iterator, *follow))
    erase(iterator);
}

template<typename T>
void list<T>::merge(list<T> &x)
{
  bidirectional_iterator<T> iter;

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
  bidirectional_iterator<T> x_iter;
  bidirectional_iterator<T> self_iter;

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
