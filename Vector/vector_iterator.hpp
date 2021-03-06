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
  iterator &operator=(const iterator<T> &to_copy) { iter = to_copy.get_iter(); return *this; }
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
  T &operator[](const size_t &r) { return *(iter + r); }
  const T &operator[](const size_t &r) const { return *(iter + r); }
  iterator<T> operator++() { iter++; return iterator<T>(iter); }
  iterator<T> operator++(int) { T *rem = iter; iter++; return iterator<T>(rem); }
  iterator<T> operator--() { iter--; return iterator<T>(iter); }
  iterator<T> operator--(int) { T *rem = iter; iter--; return iterator<T>(rem); }
  iterator<T> operator+(const size_t &r) { return iterator<T>(iter + r); }
  iterator<T> operator-(const size_t &r) { return iterator<T>(iter - r); }
  virtual void operator+=(const size_t &r) { iter += r; }
  virtual void operator-=(const size_t &r) { iter -= r; }
};

template<typename T>
class reverse_iterator: public iterator<T>
{
public:
  reverse_iterator():iterator<T>() {}
  reverse_iterator(T *_iter):iterator<T>(_iter) {}
  reverse_iterator(const reverse_iterator<T> &to_copy) { *this = to_copy; }
  virtual ~reverse_iterator() {}

  reverse_iterator<T> operator++() { iterator<T>::iter--; return reverse_iterator(iterator<T>::iter); }

  reverse_iterator<T> operator++(int) { T *rem = iterator<T>::iter; iterator<T>::iter--; return reverse_iterator(rem); }

  reverse_iterator<T> operator--() { iterator<T>::iter++; return reverse_iterator(iterator<T>::iter); }

  reverse_iterator<T> operator--(int) { T *rem = iterator<T>::iter; iterator<T>::iter++; return reverse_iterator(rem); }

  reverse_iterator<T> operator+(const size_t &r) { return reverse_iterator<T>(iterator<T>::iter - r); }

  reverse_iterator<T> operator-(const size_t &r) { return reverse_iterator<T>(iterator<T>::iter + r); }

  void operator+=(const size_t &r) { iterator<T>::iter -= r; }

  void operator-=(const size_t &r) { iterator<T>::iter += r; }
};

}
#endif
