#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "map.hpp"

//Map iterator is a bidirectional iterator, meaning it can increment or decrement

namespace Map
{
template<typename Key, typename T>
class iterator //Iterator system for map is able to reference to key values with ->first and to element values with ->second, based on geeksforgeeks
{
protected:
  struct __map
  {
    struct __map *head;
    struct __map *next;
    struct __map *prev;
    T element_value;
    Key key_value;
  };
  struct __map *_map;

public:
  iterator():_map(nullptr) {}
  iterator(const iterator<Key, T> &to_copy) { *this = to_copy; }
  void operator=(const iterator<Key, T> &to_copy) { _map = to_copy.get_map(); }
  iterator(void *map_): _map(static_cast<struct __map *>(map_)) {}
  virtual ~iterator() {} //Parent classes always need to have virtual destructor to avoid error

  struct __map *get_map() const { return _map; } //Getter function

  bool operator==(const iterator &r) const { if (_map != r.get_map()) return false; return true; }
  bool operator!=(const iterator &r) const { if (_map != r.get_map()) return true; return false; }
  T &operator*() { return (_map->element_value); }
  const T &operator*() const { return (_map->element_value); }
  void operator*=(T value) { _map->element_value = value; }
  std::pair<Key, T> *operator->();
  const std::pair<Key, T> *operator->() const;
  virtual T &operator++() { _map = _map->next; return (_map->element_value); }
  virtual T &operator--() { _map = _map->prev; return (_map->element_value); }

  //*++ and *-- increment and decrement the value returned by *
};

template<typename Key, typename T>
std::pair<Key, T> *iterator<Key, T>::operator->() //Returns a pointer on object, the specified variable name after arrow points on variables inside the returned object
{
  std::pair<Key, T> *ret;

  ret = new std::pair<Key, T>;
  ret->first = _map->key_value;
  ret->second = _map->element_value;
  return (ret);
}

template<typename Key, typename T>
const std::pair<Key, T> *iterator<Key, T>::operator->() const
{
  std::pair<Key, T> *ret;

  ret = new std::pair<Key, T>;
  ret->first = _map->key_value;
  ret->second = _map->element_value;
  return (ret);
}

template<typename Key, typename T>
class reverse_iterator : public iterator<Key, T>
{
public:
  reverse_iterator():iterator<Key, T>() {}
  reverse_iterator(const reverse_iterator<Key, T> &to_copy) { *this = to_copy; }
  reverse_iterator(void *map_):iterator<Key, T>(map_) {}
  virtual ~reverse_iterator() {}

  T &operator++()
  {
    iterator<Key, T>::_map = iterator<Key, T>::_map->prev;
    return (iterator<Key, T>::_map->element_value);
  }

  T &operator--()
  {
    iterator<Key, T>::_map = iterator<Key, T>::_map->next;
    return (iterator<Key, T>::_map->element_value);
  }
};
}
#endif
