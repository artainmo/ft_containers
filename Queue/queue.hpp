#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include "../List/list.hpp"

namespace ft
{

template<typename T, typename Container = ft::list<T> > //List is used as default because it has been coded by oneself, but technically dequeue can be used too
class queue //Similar to stack, big difference is that queue works with FIFO(first in first out), elements are inserted from its back but are popped or erased from the front
{
private:
  unsigned int _size;
  Container _cont;

public:
  explicit queue(const Container &cont_ = Container()): _size(0), _cont(cont_) {} //Explicit keyword is used to block implicit conversions the compiler could make, we set our own explicit conversion to the default container constructor

  //Queue has no object destructor, its adaptator object will automatically go through his destructor
  //Queue has no object destructor, its adaptator object will automatically go through his destructor

  //Capacity
  bool empty() const { if (_size == 0) return true; return false; }
  unsigned int size() const { return _size; }

  //Element access
  T &front() { return ( _cont.front()); }
  const T &front() const { return ( _cont.front()); }
  T &back() { return ( _cont.back()); }
  const T &back() const { return ( _cont.back()); }

  //Modifiers
  void push(const T &value) { _cont.push_back(value); _size++; } //Inserts new element at end of list
  void pop() { if (_size != 0) _size--; _cont.pop_front(); } //Erases elements from front of list

  //Relational operators
  bool operator==(const queue<T,Container> &r) { return _cont == r._cont; } //Will call relational operators of Container class

  bool operator!=(const queue<T,Container> &r) { return _cont != r._cont; }

  bool operator<(const queue<T,Container> &r) { return _cont < r._cont; }

  bool operator<=(const queue<T,Container> &r) { return _cont <= r._cont; }

  bool operator>(const queue<T,Container> &r) { return _cont > r._cont; }

  bool operator>=(const queue<T,Container> &r) { return _cont >= r._cont; }


};

} //End of namespace ft

#endif
