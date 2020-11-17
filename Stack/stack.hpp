#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <deque>

//Dequeu is used as default Container template, but list and vector are possible too. Because I did not code dequeu we will use list as default container
//An internal container object is used and this is where the elements are stored.
#include "../List/list.hpp"

namespace ft
{

  template <typename T, typename Container = ft::list<T> >
  class stack // Has no iterator implementation, only accessible elements are last ones so you can add elements and remove them from the back only (LIFO)
  {
  private:
    Container _cont;
    unsigned int _size;

  public:
    explicit stack(const Container &cont_ = Container()): _cont(cont_), _size(0) {} //Constructs an adaptor object, adaptor because the object contruction depends on the template parameter //Container() will call the default constructor of the container type
    /*
    **The explicit(stated clearly) keyword is used to protect against bugs due to implicit(suggested) conversions of parameters that the compiler could make.
    **Classes have single argument constructors, if a function attends that class as a parameter but does not receive a class as a parameter, and receives instead a type equal to one of the single argument constructors,
    **the compiler will create the class using that parameter and one parameter constructor. Because the stack one parameter constructor can take a lot of different types, this problem could easily happen here.
    **To avoid this bug from happening and making sure the correct class is send to the function use the explicit keyword to avoid the creation of another class into the function.
    */

    //Stack has no object destructor, its adaptator object will automatically go through his destructor
    //Stack does not have a copy constructor and assignation operator

    //Capacity
    bool empty() const { if (_size == 0) return true; return false; }
    unsigned int size() const { return _size; }

    //Element access
    T &top() { return _cont.back(); }
    const T &top() const { return _cont.back(); }

    //Modifiers
    void push(const T &val) { _cont.push_back(val); _size++; }
    void pop() {  if (_size != 0) _size--; _cont.pop_back(); }

    //Relational operators
    bool operator==(const stack<T,Container> &r) { return _cont == r._cont; } //Will call relational operators of Container class

    bool operator!=(const stack<T,Container> &r) { return _cont != r._cont; }

    bool operator<(const stack<T,Container> &r) { return _cont < r._cont; }

    bool operator<=(const stack<T,Container> &r) { return _cont <= r._cont; }

    bool operator>(const stack<T,Container> &r) { return _cont > r._cont; }

    bool operator>=(const stack<T,Container> &r) { return _cont >= r._cont; }

  };

} //End of namespace ft

#endif
