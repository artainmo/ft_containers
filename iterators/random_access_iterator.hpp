#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

template<typename T>
class random_access_iterator
{
protected:
  T *iterator; //If not put in private when copy is made to function parameter, the value of public variables will not be copied, so always put in private!!
public:
  random_access_iterator() {}
  random_access_iterator(T *_iterator) { iterator = _iterator; }
  random_access_iterator(const random_access_iterator<T> &to_copy) { *this = to_copy; }

  virtual ~random_access_iterator() {} //Parent class always need to have virtual destructor to avoid error

  T *get_iterator() const
  {
    return iterator;
  }

  void operator=(const random_access_iterator<T> &to_copy)
  {
    iterator = to_copy.get_iterator();
  }

  bool operator==(const random_access_iterator<T> &r)
  {
      if (iterator != r.iterator)
        return false;
      else
        return true;
  }

  bool operator!=(const random_access_iterator<T> &r)
  {
      if (iterator != r.iterator)
        return true;
      else
        return false;
  }

  T &operator*()
  {
    return (*iterator);
  }

  T &operator->()
  {
    return (*iterator);
  }

  void operator*=(T value)
  {
    *iterator = value;
  }

  virtual T &operator++()
  {
    if (iterator != 0)
      iterator++;
    else
      std::cout << "Iterator out of range" << std::endl;
    return (*iterator);
  }

  virtual T &operator--()
  {
    if (iterator != 0)
      iterator--;
    else
      std::cout << "Iterator out of range" << std::endl;
    return (*iterator);
  }

  virtual T &operator+(const unsigned int &r)
  {
    iterator += r;
    return (*iterator);
  }

  virtual T &operator-(const unsigned int &r)
  {
    iterator -= r;
    return (*iterator);
  }

  virtual T &operator+=(const unsigned int &r)
  {
    iterator += r;
    return (*iterator);
  }

  virtual T &operator-=(const unsigned int &r)
  {
    iterator -= r;
    return (*iterator);
  }

  T &operator[](const unsigned int &r)
  {
    return (iterator + r);
  }

  bool operator<(const random_access_iterator<T> &r)
  {
      if (iterator < r.iterator)
        return true;
      else
        return false;
  }

  bool operator<=(const random_access_iterator<T> &r)
  {
      if (iterator <= r.iterator)
        return true;
      else
        return false;
  }

  bool operator>(const random_access_iterator<T> &r)
  {
      if (iterator > r.iterator)
        return true;
      else
        return false;
  }

  bool operator>=(const random_access_iterator<T> &r)
  {
      if (iterator >= r.iterator)
        return true;
      else
        return false;
  }
};

template<typename T>
class reverse_random_access_iterator: public random_access_iterator<T>
{
public:
  reverse_random_access_iterator() {}
  reverse_random_access_iterator(T *iterator): random_access_iterator<T>::random_access_iterator(iterator) {}
  reverse_random_access_iterator(const reverse_random_access_iterator<T> &to_copy) { *this = to_copy; }

  virtual ~reverse_random_access_iterator() {}

  T &operator++()
  {
    if (random_access_iterator<T>::iterator != 0)
      random_access_iterator<T>::iterator--;
    else
      std::cout << "Iterator out of range" << std::endl;
    return (*random_access_iterator<T>::iterator);
  }

  T &operator--()
  {
    if (random_access_iterator<T>::iterator != 0)
      random_access_iterator<T>::iterator++;
    else
      std::cout << "Iterator out of range" << std::endl;
    return (*random_access_iterator<T>::iterator);
  }

  T &operator+(const unsigned int &r)
  {
    random_access_iterator<T>::iterator -= r;
    return (*random_access_iterator<T>::iterator);
  }

  T &operator-(const unsigned int &r)
  {
    random_access_iterator<T>::iterator += r;
    return (*random_access_iterator<T>::iterator);
  }

  T &operator+=(const unsigned int &r)
  {
    random_access_iterator<T>::iterator -= r;
    return (*random_access_iterator<T>::iterator);
  }

  T &operator-=(const unsigned int &r)
  {
    random_access_iterator<T>::iterator += r;
    return (*random_access_iterator<T>::iterator);
  }
};

#endif
