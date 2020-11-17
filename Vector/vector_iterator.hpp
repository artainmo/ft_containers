#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

//Vector iterator is a random access iterator meaning it has direct access to elements
namespace Vector
{
template<typename T>
class iterator
{
protected:
  T *iter; //If not put in private when copy is made to function parameter, the value of public variables will not be copied, so always put in private!!
public:
  iterator():iterator(nullptr) {}
  iterator(const iterator<T> &to_copy) { *this = to_copy; }
  void operator=(const iterator<T> &to_copy) { iter = to_copy.get_iterator(); }
  virtual ~iterator() {} //Parent class always need to have virtual destructor to avoid error

  const T *get_iter() const { return iter; } //getter function

  bool operator==(const iterator<T> &r) const;
  bool operator!=(const iterator<T> &r) const;
  T &operator*();
  const T &operator*() const;
  T &operator->();
  const T &operator->() const;
  void operator*=(T value);
  T &operator[](const unsigned int &r);
  const T &operator[](const unsigned int &r) const;
  bool operator<(const iterator<T> &r) const;
  bool operator<=(const iterator<T> &r) const;
  bool operator>(const iterator<T> &r) const;
  bool operator>=(const iterator<T> &r) const;
  virtual const T &operator++() const;
  virtual const T &operator--() const;
  virtual const T &operator+(const unsigned int &r) const;
  virtual const T &operator-(const unsigned int &r) const;
  virtual const T &operator+=(const unsigned int &r) const;
  virtual const T &operator-=(const unsigned int &r) const;
};

template<typename T>
bool iterator<T>::operator==(const iterator<T> &r) const
{
    if (iter != r.get_iter())
      return false;
    else
      return true;
}

template<typename T>
bool iterator<T>::operator!=(const iterator<T> &r) const
{
    if (iter != r.get_iter())
      return true;
    else
      return false;
}

template<typename T>
T &iterator<T>::operator*()
{
  if (iter == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  return (*iter);
}

template<typename T>
const T &iterator<T>::operator*() const
{
  if (iter == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  return (*iter);
}

template<typename T>
T &iterator<T>::operator->()
{
  if (iter == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  return (*iter);
}

template<typename T>
const T &iterator<T>::operator->() const
{
  if (iter == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  return (*iter);
}

template<typename T>
void iterator<T>::operator*=(T value)
{
  if (iter == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  *iter = value;
}

template<typename T>
T &iterator<T>::operator[](const unsigned int &r)
{
  int i;

  i = 0;
  while (iter + i != 0 and i != r)
    i++;
  if (iter + i == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  return (iter + r);
}

template<typename T>
const T &iterator<T>::operator[](const unsigned int &r) const
{
  int i;

  i = 0;
  while (iter + i != 0 and i != r)
    i++;
  if (iter + i == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  return (iter + r);
}

template<typename T>
bool iterator<T>::operator<(const iterator<T> &r) const
{
    if (iter < r.get_iterator())
      return true;
    else
      return false;
}

template<typename T>
bool iterator<T>::operator<=(const iterator<T> &r) const
{
    if (iter <= r.get_iterator())
      return true;
    else
      return false;
}

template<typename T>
bool iterator<T>::operator>(const iterator<T> &r) const
{
    if (iter > r.get_iterator())
      return true;
    else
      return false;
}

template<typename T>
bool iterator<T>::operator>=(const iterator<T> &r) const
{
    if (iter >= r.get_iterator())
      return true;
    else
      return false;
}

template<typename T>
const T &iterator<T>::operator++() const
{
  if (iter == 0 or iter + 1 == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  iter++;
  return (*iter);
}

template<typename T>
const T &iterator<T>::operator--() const
{
  if (iter == 0) //How to check if prior value goes out of scope?!!
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  iter--;
  return (*iter);
}

template<typename T>
const T &iterator<T>::operator+(const unsigned int &r) const
{
  int i;

  i = 0;
  while (iter + i != 0 and i != r)
    i++;
  if (iter + i == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  iter += r;
  return (*iter);
}

template<typename T>
const T &iterator<T>::operator-(const unsigned int &r) const
{
  if (iter == 0) //How to check if prior value goes out of scope?!!
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  iter -= r;
  return (*iter);
}

template<typename T>
const T &iterator<T>::operator+=(const unsigned int &r) const
{
  int i;

  i = 0;
  while (iter + i != 0 and i != r)
    i++;
  if (iter + i == 0)
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  iter += r;
  return (*iter);
}

template<typename T>
const T &iterator<T>::operator-=(const unsigned int &r) const
{
  if (iter == 0) //How to check if prior value goes out of scope?!!
  {
    std::cout << "Out of range calling segfault..." << std::endl;
    raise (SIGSEGV);
  }
  iter -= r;
  return (*iter);
}

template<typename T>
class reverse_iterator: public iterator<T>
{
public:
  reverse_iterator():iterator<T>() {}
  reverse_iterator(T *_iter):iterator<T>(_iter) {}
  reverse_iterator(const reverse_iterator<T> &to_copy) { *this = to_copy; }
  virtual ~reverse_iterator() {}

  const T &operator++() const
  {
    if (iterator<T>::iter == 0) //How to check if prior value goes out of scope?!!
    {
      std::cout << "Out of range calling segfault..." << std::endl;
      raise (SIGSEGV);
    }
    iterator<T>::iter--;
    return (*iterator<T>::iter);
  }

  const T &operator--() const
  {
    if (iterator<T>::iter == 0 or iterator<T>::iter + 1 == 0)
    {
      std::cout << "Out of range calling segfault..." << std::endl;
      raise (SIGSEGV);
    }
    iterator<T>::iter++;
    return (*iterator<T>::iter);
  }

  const T &operator+(const unsigned int &r) const
  {
    if (iterator<T>::iter == 0) //How to check if prior value goes out of scope?!!
    {
      std::cout << "Out of range calling segfault..." << std::endl;
      raise (SIGSEGV);
    }
    iterator<T>::iter -= r;
    return (*iterator<T>::iter);
  }

  const T &operator-(const unsigned int &r) const
  {
    int i;

    i = 0;
    while (iterator<T>::iter + i != 0 and i != r)
      i++;
    if (iterator<T>::iter + i == 0)
    {
      std::cout << "Out of range calling segfault..." << std::endl;
      raise (SIGSEGV);
    }
    iterator<T>::iter += r;
    return (*iterator<T>::iter);
  }

  const T &operator+=(const unsigned int &r) const
  {
    if (iterator<T>::iter == 0) //How to check if prior value goes out of scope?!!
    {
      std::cout << "Out of range calling segfault..." << std::endl;
      raise (SIGSEGV);
    }
    iterator<T>::iter -= r;
    return (*iterator<T>::iter);
  }

  const T &operator-=(const unsigned int &r) const
  {
    int i;

    i = 0;
    while (iterator<T>::iter + i != 0 and i != r)
      i++;
    if (iterator<T>::iter + i == 0)
    {
      std::cout << "Out of range calling segfault..." << std::endl;
      raise (SIGSEGV);
    }
    iterator<T>::iter += r;
    return (*iterator<T>::iter);
  }
};
}
#endif
