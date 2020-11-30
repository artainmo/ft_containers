#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <utility>
#include <climits>
#include "map_iterator.hpp"

/*
**SPECIAL CASES
*
**Begin, rbegin, end , rend should return empty iterator if container is empty /
**Do not protect iterator from going out of scope /
*/

namespace ft
{
  template<typename Key, typename T, typename Compare=std::less<Key> > //less found in functional library,
  class map //Ordered list, the key values should be ordered not the element values, default comparison is from smaller to bigger values
  {
  private:
    struct __map
    {
      struct __map *head;
      struct __map *next;
      struct __map *prev;
      T element_value;
      Key key_value;
    };
    struct __map *_map;
    size_t _size;

    class value_compare //Not necessary to use, but asked to do and return in vlue_comp function
    {
    private:
        Compare comp;
    public:
      value_compare() {}
      value_compare(const Compare &comp_) { comp = comp_; }
      value_compare(const value_compare &to_copy) {comp = to_copy.get_comp();}
      void operator=(const value_compare &to_copy) {comp = to_copy.get_comp();}

      Compare get_comp() const { return (comp); }
      bool operator()(const Map::iterator<Key, T> &x, const Map::iterator<Key, T> &y) { return (comp(x->first, y->first)); } // directly give iterators as argument, easier but not necessary...
    };

    Map::iterator<Key, T> _insert(const Key &k, const T &value);
    void _erase(struct __map *position);
    bool is_in(const Key &k) const;
    template<typename inputiterator>
    void cpy(inputiterator first, inputiterator last);

  public:
    typedef Map::iterator<Key, T> iterator;
    typedef const Map::iterator<Key, T> const_iterator;
    typedef Map::reverse_iterator<Key, T> reverse_iterator;
    typedef const Map::reverse_iterator<Key, T> const_reverse_iterator;

    map(): _size(0) {}
    template<typename inputiterator>
    map(inputiterator first, inputiterator last) { _size = 0; cpy(first, last); } //range constructor
    map(const map<Key, T> &to_copy) { _size = 0; *this = to_copy; }
    void operator=(const map<Key, T> &to_copy) { clear(); cpy(to_copy.begin(), to_copy.end()); }
    ~map() { clear(); };

    //Iterators
    iterator begin() { if (empty()) return (iterator()); return (iterator(_map->head)); }
    const_iterator begin() const { if (empty()) return (const_iterator()); return (const_iterator(_map->head)); }
    iterator end();
    const_iterator end() const;
    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator rend() { if (empty()) return (reverse_iterator()); return (reverse_iterator(_map->head)); }
    const_reverse_iterator rend() const { if (empty()) return (const_reverse_iterator()); return (const_reverse_iterator(_map->head)); }

    //Capacity
    bool empty() const;
    size_t size() const { return (_size); }
    size_t max_size() const { return std::numeric_limits<size_t>::max(); } //Because the size is stored in a size_t, https://en.cppreference.com/w/cpp/container/list/max_size

    //Element access
    T &operator[](const Key& k);

    //Modifiers
    std::pair<iterator, bool> insert(const std::pair<Key, T> &val);
    iterator insert(iterator position, const std::pair<Key, T> &val);
    template<typename inputiterator>
    void insert(inputiterator first, inputiterator last);
    void erase(iterator position);
    size_t erase(const Key &k);
    void erase(iterator first, iterator last);
    void swap(map &x);
    void clear();

    //Observers
    Compare key_comp() const { return (Compare()); } //Returns comparison obeject or third template parameter
    value_compare value_comp() const { return (value_compare()); } //Returns the value comparison object or class created above

    //Operations
    iterator find(const Key &k);
    const_iterator find(const Key &k) const;
    size_t count(const Key &k) const;
    iterator lower_bound(const Key &k);
    const_iterator lower_bound(const Key &k) const;
    iterator upper_bound(const Key &k);
    const_iterator upper_bound(const Key &k) const;
    std::pair<iterator, iterator > equal_range(const Key &k);
    std::pair<const_iterator, const_iterator > equal_range(const Key &k) const;
  };

  template<typename Key, typename T, typename Compare>
  Map::iterator<Key, T> map<Key, T, Compare>::end()
  {
    struct __map *tmp;

    if (empty())
      return (iterator());
    tmp = _map->head;
    while (tmp->next != 0)
      tmp = tmp->next;
    return (iterator(tmp));
  }

  template<typename Key, typename T, typename Compare>
  const Map::iterator<Key, T> map<Key, T, Compare>::end() const
  {
    struct __map *tmp;

    if (empty())
      return (const_iterator());
    tmp = _map->head;
    while (tmp->next != 0)
      tmp = tmp->next;
    return (const_iterator(tmp));
  }

  template<typename Key, typename T, typename Compare>
  Map::reverse_iterator<Key, T> map<Key, T, Compare>::rbegin()
  {
    struct __map *tmp;

    if (_size == 0)
      return (reverse_iterator());
    tmp = _map->head;
    while (tmp->next != 0)
      tmp = tmp->next;
    return (reverse_iterator(tmp));
  }

  template<typename Key, typename T, typename Compare>
  const Map::reverse_iterator<Key, T> map<Key, T, Compare>::rbegin() const
  {
    struct __map *tmp;

    if (empty())
      return (const_reverse_iterator());
    tmp = _map->head;
    while (tmp->next != 0)
      tmp = tmp->next;
    return (const_reverse_iterator(tmp));
  }

  template<typename Key, typename T, typename Compare>
  bool map<Key, T, Compare>::empty() const
  {
    if (_size == 0)
      return (true);
    else
      return (false);
  }

  template<typename Key, typename T, typename Compare> //If key not found inserts it as new key with a non specified element value 0
  T &map<Key, T, Compare>::operator[](const Key &k)
  {
    struct __map *tmp;

    _insert(k, 0);
    _map = _map->head;
    tmp = _map;
    while (tmp->key_value != k)
      tmp = tmp->next;
    return (tmp->element_value); // Returns inserted element value
  }

  template<typename Key, typename T, typename Compare>
  std::pair<Map::iterator<Key, T>, bool> map<Key, T, Compare>::insert(const std::pair<Key, T> &val) //Pair is a class from the utility library it acts like a tuple that can hold two values of different type
  {
    std::pair<iterator, bool> ret;

    if (is_in(val.first))
      ret.second = true; //Set to true because key element did not exist yet
    else
      ret.second = false; //Set to false because key element already exists
    ret.first = _insert(val.first, val.second); //First of pair is equal to iterator
    return (ret);
  }

  template<typename Key, typename T, typename Compare>
  Map::iterator<Key, T> map<Key, T, Compare>::insert(iterator position, const std::pair<Key, T> &val) //Position is a hint to where the new element should be placed in map, but order is always primordial in the map container thus the hint position is not necessary, thus prior insert funtion can be used but return value differs
  {
    std::pair<iterator, bool> inser;

    (void)position; //Unused parameter
    inser = insert(val);
    return (inser.first);
  }

  template<typename Key, typename T, typename Compare>
  template<typename inputiterator>
  void map<Key, T, Compare>::insert(inputiterator first, inputiterator last)
  {
    while (first != last)
    {
      insert(std::pair<Key, T>(first->first, first->second));
      ++first;
    }
    insert(std::pair<Key, T>(first->first, first->second));
  }

  template<typename Key, typename T, typename Compare>
  void map<Key, T, Compare>::erase(iterator position)
  {
    struct __map *tmp;

    if (_size == 0)
    {
      std::cout << "Out of range calling segfault..." << std::endl;
      raise (SIGSEGV);
    }
    _map = _map->head;
    tmp = _map;
    while (tmp != 0 && tmp != (struct __map *)position.get_map()) //Get address map
      tmp = tmp->next;
    _erase(tmp);
  }

  template<typename Key, typename T, typename Compare>
  size_t map<Key, T, Compare>::erase(const Key &k) //Returns number of erased elements
  {
    struct __map *tmp;

    if (_size == 0)
    {
      std::cout << "Out of range calling segfault..." << std::endl;
      raise (SIGSEGV);
    }
    _map = _map->head;
    tmp = _map;
    while (tmp != 0 && tmp->key_value != k)
      tmp = tmp->next;
    _erase(tmp);
    if (tmp == 0)
      return (0);
    return (1); //Only one copy of a key value possible so never more than one
  }

  template<typename Key, typename T, typename Compare>
  void map<Key, T, Compare>::erase(iterator first, iterator last)
  {
    iterator rem;

    if (_size == 0)
    {
      std::cout << "Out of range calling segfault..." << std::endl;
      raise (SIGSEGV);
    }
    while (first != last)
    {
      rem = first; //Because value first and rem point on will get deleted
      ++first;
      erase(rem);
    }
    erase(first);
  }

  template<typename Key, typename T, typename Compare>
  void map<Key, T, Compare>::swap(map &x)
  {
    map tmp;

    tmp = x;
    x = *this;
    *this = tmp;
  }

  template<typename Key, typename T, typename Compare>
  void map<Key, T, Compare>::clear()
  {
    struct __map *tmp;

    if (_size == 0)
      return ;
    _map = _map->head;
    while (_map != 0)
    {
      tmp = _map;
      _map = _map->next;
      delete tmp;
    }
    _size = 0;
  }

  template<typename Key, typename T, typename Compare>
  Map::iterator<Key, T> map<Key, T, Compare>::find(const Key &k)
  {
    struct __map *tmp;

    if (empty())
      return end();
    _map = _map->head;
    tmp = _map;
    while (tmp != 0 && tmp->key_value != k)
      tmp = tmp->next;
    if (tmp == 0) //If value not found return end
      return (end());
    else
      return (iterator(tmp));
  }

  template<typename Key, typename T, typename Compare>
  const Map::iterator<Key, T> map<Key, T, Compare>::find(const Key &k) const
  {
    struct __map *tmp;

    if (empty())
      return end();
    _map = _map->head;
    tmp = _map;
    while (tmp != 0 && tmp->key_value != k)
      tmp = tmp->next;
    if (tmp == 0) //If value not found return end
      return (end());
    else
      return (const_iterator(tmp));
  }

  template<typename Key, typename T, typename Compare>
  size_t map<Key, T, Compare>::count(const Key &k) const //Number of occurences of a key value, in map all key values are unique so maximum 1
  {
    if (is_in(k) == true)
      return (1);
    return (0);
  }

  template<typename Key,typename T, typename Compare>
  Map::iterator<Key, T> map<Key, T, Compare>::lower_bound(const Key &k)
  {
    struct __map *tmp;
    Compare _comp; //Use Compare as type but the variable as the actual function

    if (empty())
      return end();
    _map = _map->head;
    tmp = _map;
    while (tmp != 0 && _comp(tmp->key_value, k) && tmp->key_value != k)
      tmp = tmp->next;
    if (tmp == 0) //If value not found return end
      return (end());
    else
      return (iterator(tmp));
  }

  template<typename Key,typename T, typename Compare>
  const Map::iterator<Key, T> map<Key, T, Compare>::lower_bound(const Key &k) const
  {
    struct __map *tmp;
    Compare _comp; //Use Compare as type but the variable as the actual function

    if (empty())
      return end();
    _map = _map->head;
    tmp = _map;
    while (tmp != 0 && _comp(tmp->key_value, k) && tmp->key_value != k)
      tmp = tmp->next;
    if (tmp == 0) //If value not found return end
      return (end());
    else
      return (const_iterator(tmp));
  }

  template<typename Key,typename T, typename Compare>
  Map::iterator<Key, T> map<Key, T, Compare>::upper_bound(const Key &k)
  {
    struct __map *tmp;
    Compare _comp; //Use Compare as type but the variable as the actual function

    if (empty())
      return end();
    _map = _map->head;
    tmp = _map;
    while (tmp != 0 && (_comp(tmp->key_value, k) || tmp->key_value == k))
      tmp = tmp->next;
    if (tmp == 0) //If value not found return end
      return (end());
    else
      return (iterator(tmp));
  }

  template<typename Key,typename T, typename Compare>
  const Map::iterator<Key, T> map<Key, T, Compare>::upper_bound(const Key &k) const
  {
    struct __map *tmp;
    Compare _comp; //Use Compare as type but the variable as the actual function

    if (empty())
      return end();
    _map = _map->head;
    tmp = _map;
    while (tmp != 0 && (_comp(tmp->key_value, k) || tmp->key_value == k))
      tmp = tmp->next;
    if (tmp == 0) //If value not found return end
      return (end());
    else
      return (const_iterator(tmp));
  }

  template<typename Key, typename T, typename Compare>
  std::pair<Map::iterator<Key, T>, Map::iterator<Key, T> > map<Key, T, Compare>::equal_range(const Key &k)
  {
    std::pair<iterator, iterator > ret;

    if (is_in(k)) //Return lower and upper bound in pair tuple if key_value exists
    {
      ret.first = lower_bound(k);
      ret.second = upper_bound(k);
    }
    else //Returns two same pointers to first key that goes after k (upper_bound)
    {
      ret.first = lower_bound(k);
      ret.second = lower_bound(k);
    }
    return (ret);
  }

  template<typename Key, typename T, typename Compare>
  std::pair<const Map::iterator<Key, T>, const Map::iterator<Key, T> > map<Key, T, Compare>::equal_range(const Key &k) const
  {
    std::pair<const_iterator, const_iterator > ret;

    if (is_in(k)) //Return lower and upper bound in pair tuple if key_value exists
    {
      ret.first = lower_bound(k);
      ret.second = upper_bound(k);
    }
    else //Returns two same pointers to first key that goes after k (upper_bound)
    {
      ret.first = lower_bound(k);
      ret.second = lower_bound(k);
    }
    return (ret);
  }

  template<typename Key, typename T, typename Compare>
  Map::iterator<Key, T> map<Key, T, Compare>::_insert(const Key &k, const T &value)
  {
    struct __map *position;
    struct __map *_new;
    struct __map *tmp;
    Compare _comp; //Use Compare as type but the variable as the actual function

    if (_size == 0)
    {
      _size++;
      _map = new struct __map;
      _map->head = _map;
      _map->prev = 0;
      _map->next = 0;
      _map->key_value = k;
      _map->element_value = value;
      return (iterator(_map));
    }
    _map = _map->head;
    tmp = _map;
    if (is_in(k)) //If the key already exists return pointer to the already existing key
    {
      while (tmp->key_value != k)
        tmp = tmp->next;
      return (iterator(tmp));
    }
    _new = new struct __map;
    while (_comp(tmp->key_value, k) && tmp->next != 0) //Insert on correct order
      tmp = tmp->next;
    if (tmp->next == 0 && _comp(tmp->key_value, k)) //If k should come last
    {
      tmp->next = _new;
      _new->prev = tmp;
      _new->head = tmp->head;
      _new->next = 0;
      _new->key_value = k;
      _new->element_value = value;
    }
    else if (tmp->prev == 0) //If k should be first
    {
      _new->head = _new;
      _new->prev = 0;
      _new->next = tmp;
      tmp->prev = _new;
      _new->key_value = k;
      _new->element_value = value;
      while (tmp != 0)
      {
        tmp->head = _new;
        tmp = tmp->next;
      }
    }
    else //If k should come in between
    {
      position = tmp->prev;
      _new->prev = position;
      _new->next = position->next;
      _new->head = position->head;
      position->next->prev = _new;
      position->next = _new;
      _new->key_value = k;
      _new->element_value = value;
    }
    _size++;
    return (iterator(_new));
  }

  template<typename Key, typename T, typename Compare>
  bool map<Key, T, Compare>::is_in(const Key &k) const
  {
    struct __map *tmp;

    if (_size == 0)
      return false;
    tmp = _map->head;
    while (tmp != 0 && tmp->key_value != k)
      tmp = tmp->next;
    if (tmp == 0) //If value not found return false
      return false;
    else
      return true;
  }

  template<typename Key, typename T, typename Compare>
  void map<Key, T, Compare>::_erase(struct __map *position)
  {
    if (_size == 0 || position == 0)
      return ;
    if (position->prev == 0) //Remove first element
    {
      _map = _map->next;
      _map->prev = 0;
      _map->head = _map;
      while (_map->next != 0)
      {
        _map->next->head = _map->head;
        _map = _map->next;
      }
      delete position;
    }
    else if (position->next == 0) //Remove last element
    {
      position = position->prev;
      delete position->next;
      position->next = 0;
    }
    else //Remove element in between
    {
      position->next->prev = position->prev;
      position->prev->next = position->next;
      delete position;
    }
    _size--;
    _map = _map->head;
  }

  template<typename Key, typename T, typename Compare>
  template<typename inputiterator>
  void map<Key, T, Compare>::cpy(inputiterator first, inputiterator last)
  {
    _size++;
    _map = new struct __map;
    _map->head = _map;
    _map->prev = 0;
    _map->key_value = first->first;
    _map->element_value = first->second;
    while (first != last)
    {
      ++first;
      _size++;
      _map->next = new struct __map;
      _map->next->head = _map->head;
      _map->next->prev = _map;
      _map = _map->next;
      _map->key_value = first->first;
      _map->element_value = first->second;
    }
    _map->next = 0;
  }

}//End of namespace ft

#endif
