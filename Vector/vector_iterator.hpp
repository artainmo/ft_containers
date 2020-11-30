#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

//Vector iterator is a random access iterator meaning it has direct access to elements
namespace Vector
{
template<typename T>
class iterator
{
protected:
  T *iter;
public:
  iterator():iter(nullptr) {}
  iterator(const iterator<T> &to_copy) { *this = to_copy; }
  void operator=(const iterator<T> &to_copy) { iter = to_copy.get_iter(); }
  iterator(T *iter_): iter(iter_) {}
  virtual ~iterator() {} //Parent class always need to have virtual destructor to avoid error

  T *get_iter() const { return iter; } //getter function

  bool operator==(const iterator<T> &r) const { if (iter != r.get_iter()) return false; else return true; }
  bool operator!=(const iterator<T> &r) const { if (iter != r.get_iter()) return true; else return false; }
  bool operator<(const iterator<T> &r) const { if (iter < r.get_iter()) return true; else return false; }
  bool operator<=(const iterator<T> &r) const { if (iter <= r.get_iter()) return true; else return false; }
  bool operator>(const iterator<T> &r) const { if (iter > r.get_iter()) return true; else return false; }
  bool operator>=(const iterator<T> &r) const { if (iter >= r.get_iter()) return true; else return false; }
  T &operator*() { return (*iter); }
  const T &operator*() const { return (*iter); }
  T &operator->() { return (*iter); }
  const T &operator->() const { return (*iter); }
  void operator*=(T value) { *iter = value; }
  T &operator[](const size_t &r) { return (iter + r); }
  const T &operator[](const size_t &r) const { return (iter + r); }
  virtual T &operator++() { iter++; return (*iter); }
  virtual T &operator--() { iter--; return (*iter); }
  virtual T &operator+(const size_t &r) { iter += r; return (*iter); }
  virtual T &operator-(const size_t &r) { iter -= r; return (*iter); }
  virtual T &operator+=(const size_t &r) { iter += r; return (*iter); }
  virtual T &operator-=(const size_t &r) { iter -= r; return (*iter); }
};

template<typename T>
class reverse_iterator: public iterator<T>
{
public:
  reverse_iterator():iterator<T>() {}
  reverse_iterator(T *_iter):iterator<T>(_iter) {}
  reverse_iterator(const reverse_iterator<T> &to_copy) { *this = to_copy; }
  virtual ~reverse_iterator() {}

  const T &operator++() const { iterator<T>::iter--; return (*iterator<T>::iter); }

  const T &operator--() const { iterator<T>::iter++; return (*iterator<T>::iter); }

  const T &operator+(const size_t &r) const { iterator<T>::iter -= r; return (*iterator<T>::iter); }

  const T &operator-(const size_t &r) const { iterator<T>::iter += r; return (*iterator<T>::iter); }

  const T &operator+=(const size_t &r) const { iterator<T>::iter -= r; return (*iterator<T>::iter); }

  const T &operator-=(const size_t &r) const { iterator<T>::iter += r; return (*iterator<T>::iter); }
};
}
#endif
