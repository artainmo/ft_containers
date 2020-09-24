#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "../List/list.hpp"
#include "../Map/map.hpp"

template<typename T> class list; //To resolve reciprocal incude problem
template<typename Key, typename T, typename Compare=std::less<Key> > class map;

template<typename T>
struct __list
{
  struct __list *head;
  struct __list *next;
  struct __list *prev;
  T value;
};

template<typename Key, typename T>
struct __map
{
  struct __map *head;
  struct __map *next;
  struct __map *prev;
  T element_value;
  Key key_value;
};

template<typename Key, typename T = Key> //We use default template arguments to make them optional as key is not necessary for the list container, so know if only one parameter is given, T would be equal to that
class bidirectional_iterator //Iterator system for map is able to reference to key values with ->first and to element values with ->second, based on geeksforgeeks
{
protected:
  struct __list<T> *_list; //type 1
  struct __map<Key, T> *_map; //type 2
  int type;
public:
  bidirectional_iterator() {}
  bidirectional_iterator(const list<T> &list_) {type = 1; _list = list_.begin(); }
  bidirectional_iterator(struct __list<T> *list_) {type = 1; _list = list_; }
  bidirectional_iterator(const map<Key, T> &map_) {type = 2; _map = map_.begin(); }
  bidirectional_iterator(struct __map<Key, T> *map_) {type = 2; _map = map_; }
  bidirectional_iterator(const bidirectional_iterator &to_copy) { *this = to_copy; }
  virtual ~bidirectional_iterator() {} //Parent classes always need to have virtual destructor to avoid error

  void operator=(const bidirectional_iterator &to_copy)
  {
    type = to_copy.type;

    if (to_copy.type == 1)
        _list = to_copy._list;
    else if (to_copy.type == 2)
      _map = to_copy._map;
  }

  bool operator==(const bidirectional_iterator &r)
  {
    if (type == 1)
    {
      if (_list != r.get_list_ptr())
        return false;
      else
        return true;
    }
    if (type == 2)
    {
      if (_map != r.get_map_ptr())
        return false;
      else
        return true;
    }
    return false; //For the warning may not reach end of non-void function
  }

  bool operator!=(const bidirectional_iterator &r)
  {
    if (type == 1)
    {
      if (_list != r.get_list_ptr())
        return true;
      else
        return false;
    }
    if (type == 2)
    {
      if (_map != r.get_map_ptr())
        return true;
      else
        return false;
    }
    return false; //For the warning may not reach end of non-void function
  }

  std::pair<Key, T> *operator->() const //Returns a pointer on object, the specified variable name after arrow points on variables inside the returned object
  {
    std::pair<Key, T> *ret;

    ret = new std::pair<Key, T>;
    if (type == 2)
    {
      ret->first = _map->key_value;
      ret->second = _map->element_value;
      return (ret);
    }
    return 0;
  }

  T &operator*()
  {
    if (type == 1)
      return (_list->value);
    if (type == 2)
      return (_map->element_value);
    return (_map->element_value); //For warning may not reach end of non-void function
  }

  void operator*=(T value)
  {
    if (type == 1)
      _list->value = value;
    if (type == 2)
      _map->element_value = value;
  }

  virtual T operator++()
  {
    if (type == 1)
    {
      if (_list != 0)
        _list = _list->next;
      else
      {
        std::cout << "Iterator out of range" << std::endl;
        return (0);
      }
      return (_list->value);
    }
    if (type == 2)
    {
      // P(_map);
      if (_map != 0)
        _map = _map->next;
      else
      {
        std::cout << "Iterator out of range" << std::endl;
        return (0);
      }
      return (_map->element_value);
    }
    return (_map->element_value); //For the warning may not reach end of non-void function
  }
  // virtual list &operator*++();
  virtual T operator--()
  {
    if (type == 1)
    {
      if (_list->prev != 0)
        _list = _list->prev;
      else
        std::cout << "Iterator out of range" << std::endl;
      return (_list->value);
    }
    if (type == 2)
    {
      if (_map->prev != 0)
        _map = _map->prev;
      else
        std::cout << "Iterator out of range" << std::endl;
      return (_map->element_value);
    }
    return (_map->element_value); //For the warning may not reach end of non-void function
  }
  // virtual list &operator*--();

  const struct __list<T> *get_list_ptr() const { return _list; }
  const struct __map<Key, T> *get_map_ptr() const { return _map; }
  int get_type() { return type; }
};

// template<typename T>
// list<T> &bidirectional_iterator<T>::operator*++()
// {
//   if (_list->next != 0)
//     _list = _list->next;
//   else
//     std::cout << "Iterator out of range" << std::endl;
//   return (_list->value);
// }

// template<typename T>
// list<T> &bidirectional_iterator<T>::operator*--()
// {
//   if (_list->prev != 0)
//     _list = _list->prev;
//   else
//     std::cout << "Iterator out of range" << std::endl;
//   return (_list->value);
// }

// template<typename T>
// class const_bidirectional_iterator
// {
// protected:
//   struct __list<T> *_list;
// public:
//   const_bidirectional_iterator() {}
//   const_bidirectional_iterator(const list<T> &list_) {*this = list_.begin();}
//   const_bidirectional_iterator(struct __list<T> *__list): _list(__list) {}
//   const_bidirectional_iterator(const const_bidirectional_iterator &to_copy)
//   {
//     *this = to_copy;
//   }
//   virtual ~const_bidirectional_iterator() {}
//
//   void operator=(const const_bidirectional_iterator &to_copy)
//   {
//     _list = to_copy._list;
//   }
//   bool operator==(const const_bidirectional_iterator &to_copy)
//   {
//       if (_list->value == to_copy._list->value)
//         return true;
//       else
//         return false;
//   }
//   bool operator!=(const const_bidirectional_iterator &to_copy)
//   {
//     if (_list->value == to_copy._list->value)
//       return true;
//     else
//       return false;
//   }
//   const T operator*()
//   {
//     return (_list->value);
//   }
//   const T operator->()
//   {
//     return (_list->value);
//   }
//
//   void operator*=(T value)
//   {
//     _list->value = value;
//   }
//
//   virtual const T &operator++()
//   {
//     if (_list->next != 0)
//       _list = _list->next;
//     else
//       std::cout << "Iterator out of range" << std::endl;
//     return (_list->value);
//   }
//
//   // virtual const list<T> &operator*++();
//   virtual const T &operator--()
//   {
//     if (_list->prev != 0)
//       _list = _list->prev;
//     else
//       std::cout << "Iterator out of range" << std::endl;
//     return (_list->value);
//   }
//   // virtual const list<T> &operator*--();
// };

// template<typename T>
// const list<T> &const_bidirectional_iterator<T>::operator*++()
// {
//   if (_list->next != 0)
//     _list = _list->next;
//   else
//     std::cout << "Iterator out of range" << std::endl;
//   return (_list->value);
// }

// template<typename T>
// const list<T> &const_bidirectional_iterator<T>::operator*--()
// {
//   if (_list->prev != 0)
//     _list = _list->prev;
//   else
//     std::cout << "Iterator out of range" << std::endl;
//   return (_list->value);
// }

template<typename Key, typename T = Key>
class reverse_bidirectional_iterator : public bidirectional_iterator<T>
{
public:
  reverse_bidirectional_iterator() {}
  reverse_bidirectional_iterator(const list<T> &list_) {*this = list_.begin();}
  reverse_bidirectional_iterator(struct __list<T> *__list): bidirectional_iterator<Key, T>(__list) {}
  reverse_bidirectional_iterator(const map<Key, T> &map_) {*this = map_.begin();}
  reverse_bidirectional_iterator(struct __map<Key, T> *map_): bidirectional_iterator<Key, T>(map_) {}
  reverse_bidirectional_iterator(const reverse_bidirectional_iterator<Key, T> &to_copy) { *this = to_copy; }

  ~reverse_bidirectional_iterator() {}

  T operator++()
  {
    if (bidirectional_iterator<Key, T>::type == 1)
    {
      if (bidirectional_iterator<Key, T>::_list->prev != 0)
        bidirectional_iterator<Key, T>::_list = bidirectional_iterator<Key, T>::_list->prev;
      else
        std::cout << "Iterator out of range" << std::endl;
      return (bidirectional_iterator<Key, T>::_list->value);
    }
    if (bidirectional_iterator<Key, T>::type == 2)
    {
      if (bidirectional_iterator<Key, T>::_map->prev != 0)
        bidirectional_iterator<Key, T>::_map = bidirectional_iterator<T>::_map->prev;
      else
        std::cout << "Iterator out of range" << std::endl;
      return (bidirectional_iterator<Key, T>::_map->element_value);
    }
    return (bidirectional_iterator<Key, T>::_map->element_value); //For the warning may not reach end of non-void function
  }
  // list<T> &operator*++();
  T operator--()
  {
    if (bidirectional_iterator<Key, T>::type == 1)
    {
      if (bidirectional_iterator<Key, T>::_list->next != 0)
        bidirectional_iterator<Key, T>::_list = bidirectional_iterator<Key, T>::_list->next;
      else
        std::cout << "Iterator out of range" << std::endl;
      return (bidirectional_iterator<Key, T>::_list->value);
    }
    if (bidirectional_iterator<Key, T>::type == 2)
    {
      if (bidirectional_iterator<Key, T>::_map->next != 0)
        bidirectional_iterator<Key, T>::_map = bidirectional_iterator<Key, T>::_map->next;
      else
        std::cout << "Iterator out of range" << std::endl;
      return (bidirectional_iterator<Key, T>::_map->element_value);
    }
    return (bidirectional_iterator<Key, T>::_map->element_value); //For the warning may not reach end of non-void function
  }

};

// template<typename T>
// list<T> &reverse_bidirectional_iterator<T>::operator*++()
// {
//   if (_list->prev != 0)
//     _list = _list->prev;
//   else
//     std::cout << "Iterator out of range" << std::endl;
//   return (_list->value);
// }

// template<typename T>
// list<T> &reverse_bidirectional_iterator<T>::operator*--()
// {
//   if (_list->next != 0)
//     _list = _list->next;
//   else
//     std::cout << "Iterator out of range" << std::endl;
//   return (_list->value);
// }

// template<typename T>
// class const_reverse_bidirectional_iterator : public const_bidirectional_iterator<T>
// {
// public:
//   const_reverse_bidirectional_iterator() {}
//   const_reverse_bidirectional_iterator(const list<T> &list_) {*this = list_.begin();}
//   const_reverse_bidirectional_iterator(struct __list<T> *__list): const_bidirectional_iterator<T>(__list) {}
//   const_reverse_bidirectional_iterator(const const_reverse_bidirectional_iterator &to_copy)
//   {
//     *this = to_copy;
//   }
//   ~const_reverse_bidirectional_iterator() {}
//
//   const T operator++()
//   {
//     if (const_bidirectional_iterator<T>::_list->prev != 0)
//       const_bidirectional_iterator<T>::_list = const_bidirectional_iterator<T>::_list->prev;
//     else
//       std::cout << "Iterator out of range" << std::endl;
//     return (const_bidirectional_iterator<T>::_list->value);
//   }
//   // const list<T> &operator*++();
//   const T operator--()
//   {
//     if (const_bidirectional_iterator<T>::_list->next != 0)
//       const_bidirectional_iterator<T>::_list = const_bidirectional_iterator<T>::_list->next;
//     else
//       std::cout << "Iterator out of range" << std::endl;
//     return (const_bidirectional_iterator<T>::_list->value);
//   }
//
//   // const list<T> &operator*--();
// };

// template<typename T>
// list<T> &const_reverse_bidirectional_iterator<T>::operator*++()
// {
//   if (_list->prev != 0)
//     _list = _list->prev;
//   else
//     std::cout << "Iterator out of range" << std::endl;
//   return (_list->value);
// }

// template<typename T>
// list<T> &const_reverse_bidirectional_iterator<T>::operator*--()
// {
//   if (_list->next != 0)
//     _list = _list->next;
//   else
//     std::cout << "Iterator out of range" << std::endl;
//   return (_list->value);
// }

#endif
