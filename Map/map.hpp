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
**Do not protect iterator from going out of scope, goes onto random values /
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

    void ending_empty_container(); //Empty container should always at least contain two empty structs one for begin and one for end
    Map::iterator<Key, T> _insert(const Key &k, const T &value);
    void _erase(struct __map *position);
    bool is_in(const Key &k) const;
    template<typename inputiterator>
    void cpy(inputiterator first, inputiterator last);

  public:
    typedef Key key_type;
    typedef T mapped_type;
    typedef std::pair<const key_type, mapped_type> value_type;
    typedef Compare key_compare;
    class value_compare //Not necessary to use, but asked to do and return in value_comp function
    {
    private:
        Compare comp;
    public:
      value_compare() {}
      value_compare(const Compare &comp_) { comp = comp_; }
      value_compare(const value_compare &to_copy) {comp = to_copy.get_comp();}
      void operator=(const value_compare &to_copy) {comp = to_copy.get_comp();}

      Compare get_comp() const { return (comp); }
      bool operator()(const std::pair<Key, T> &x, const std::pair<Key, T> &y) { return (comp(x.first, y.first)); } // directly give iterators as argument, easier but not necessary...
    };
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;

    typedef Map::iterator<Key, T> iterator;
    typedef const Map::iterator<Key, T> const_iterator;
    typedef Map::reverse_iterator<Key, T> reverse_iterator;
    typedef const Map::reverse_iterator<Key, T> const_reverse_iterator;

    map(): _size(0) { ending_empty_container(); }
    template<typename inputiterator>
    map(inputiterator first, inputiterator last): _size(0) { ending_empty_container(); cpy(first, last); } //range constructor
    map(const map<Key, T> &to_copy): _size(0) { *this = to_copy; }
    void operator=(const map<Key, T> &to_copy) { if (_size == 0) ending_empty_container(); clear(); cpy(to_copy.begin(), to_copy.end()); }
    ~map() { clear(); delete _map->next; delete _map; };

    //Iterators
    iterator begin() { return (iterator(_map->head->next)); }
    const_iterator begin() const { return (const_iterator(_map->head->next)); }
    iterator end();
    const_iterator end() const;
    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator rend() { return (reverse_iterator(_map->head)); }
    const_reverse_iterator rend() const { return (const_reverse_iterator(_map->head)); }

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
    struct __map *tmp = _map->head->next;

    while (tmp->next != 0)
      tmp = tmp->next;
    return (const_reverse_iterator(tmp));
  }

  template<typename Key, typename T, typename Compare>
  const Map::iterator<Key, T> map<Key, T, Compare>::end() const
  {
    struct __map *tmp = _map->head->next;

    while (tmp->next != 0)
      tmp = tmp->next;
    return (const_reverse_iterator(tmp));
  }

  template<typename Key, typename T, typename Compare>
  Map::reverse_iterator<Key, T> map<Key, T, Compare>::rbegin()
  {
    struct __map *tmp = _map->head;

    while (tmp->next->next != 0)
      tmp = tmp->next;
    return (const_reverse_iterator(tmp));
  }

  template<typename Key, typename T, typename Compare>
  const Map::reverse_iterator<Key, T> map<Key, T, Compare>::rbegin() const
  {
    struct __map *tmp = _map->head;

    while (tmp->next->next != 0)
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
    _insert(k, 0);
    struct __map *tmp = _map->head->next;
    while (tmp->key_value != k)
      tmp = tmp->next;
    return (tmp->element_value); // Returns inserted element value
  }

  template<typename Key, typename T, typename Compare>
  std::pair<Map::iterator<Key, T>, bool> map<Key, T, Compare>::insert(const std::pair<Key, T> &val) //Pair is a class from the utility library it acts like a tuple that can hold two values of different type
  {
    std::pair<iterator, bool> ret;

    if (is_in(val.first))
      ret.second = false;
    else
      ret.second = true;
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
  }

  template<typename Key, typename T, typename Compare>
  void map<Key, T, Compare>::erase(iterator position)
  {
    if (_size == 0)
      raise(SIGSEGV);
    _erase((struct __map *)position.get_map());
  }

  template<typename Key, typename T, typename Compare>
  size_t map<Key, T, Compare>::erase(const Key &k) //Returns number of erased elements
  {
    struct __map *tmp = _map->head->next;

    if (_size == 0)
      return 0;
    while (tmp->next != 0 && tmp->key_value != k)
      tmp = tmp->next;
    if (tmp->next == 0)
      return (0);
    _erase(tmp);
    return (1); //Only one copy of a key value possible so never more than one
  }

  template<typename Key, typename T, typename Compare>
  void map<Key, T, Compare>::erase(iterator first, iterator last)
  {
    iterator rem;

    if (_size == 0)
      return ;
    while (first != last)
    {
      rem = first; //Because value first and rem point on will get deleted
      ++first;
      erase(rem);
    }
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
    ending_empty_container();
  }

  template<typename Key, typename T, typename Compare>
  Map::iterator<Key, T> map<Key, T, Compare>::find(const Key &k)
  {
    struct __map *tmp = _map->head->next;

    while (tmp->next != 0 && tmp->key_value != k)
      tmp = tmp->next;
    if (tmp->next == 0) //If value not found return end
      return (end());
    else
      return (iterator(tmp));
  }

  template<typename Key, typename T, typename Compare>
  const Map::iterator<Key, T> map<Key, T, Compare>::find(const Key &k) const
  {
    struct __map *tmp = _map->head->next;

    if (empty())
      return end();
    while (tmp->next != 0 && tmp->key_value != k)
      tmp = tmp->next;
    if (tmp->next == 0) //If value not found return end
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
    struct __map *tmp = _map->head->next;
    Compare _comp; //Use Compare as type but the variable as the actual function

    if (empty())
      return end();
    while (tmp->next != 0 && _comp(tmp->key_value, k) && tmp->key_value != k)
      tmp = tmp->next;
    if (tmp->next == 0) //If value not found return end
      return (end());
    else
      return (iterator(tmp));
  }

  template<typename Key,typename T, typename Compare>
  const Map::iterator<Key, T> map<Key, T, Compare>::lower_bound(const Key &k) const
  {
    struct __map *tmp = _map->head->next;
    Compare _comp; //Use Compare as type but the variable as the actual function

    if (empty())
      return end();
    while (tmp->next != 0 && _comp(tmp->key_value, k) && tmp->key_value != k)
      tmp = tmp->next;
    if (tmp->next == 0) //If value not found return end
      return (end());
    else
      return (const_iterator(tmp));
  }

  template<typename Key,typename T, typename Compare>
  Map::iterator<Key, T> map<Key, T, Compare>::upper_bound(const Key &k)
  {
    struct __map *tmp = _map->head->next;
    Compare _comp; //Use Compare as type but the variable as the actual function

    if (empty())
      return end();
    while (tmp->next != 0 && (_comp(tmp->key_value, k) || tmp->key_value == k))
      tmp = tmp->next;
    if (tmp->next == 0) //If value not found return end
      return (end());
    else
      return (iterator(tmp));
  }

  template<typename Key,typename T, typename Compare>
  const Map::iterator<Key, T> map<Key, T, Compare>::upper_bound(const Key &k) const
  {
    struct __map *tmp = _map->head->next;
    Compare _comp; //Use Compare as type but the variable as the actual function

    if (empty())
      return end();
    while (tmp->next != 0 && (_comp(tmp->key_value, k) || tmp->key_value == k))
      tmp = tmp->next;
    if (tmp->next == 0) //If value not found return end
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
      return std::pair<const_iterator, const_iterator >(lower_bound(k), upper_bound(k));
    else //Returns two same pointers to first key that goes after k (upper_bound)
      return std::pair<const_iterator, const_iterator >(lower_bound(k), lower_bound(k));
    return (ret);
  }

  template<typename Key, typename T, typename Compare>
  Map::iterator<Key, T> map<Key, T, Compare>::_insert(const Key &k, const T &value)
  {
    Compare _comp; //Use Compare as type but the variable as the actual function
    struct __map *tmp = _map->head->next;

    if (is_in(k)) //If the key already exists return pointer to the already existing key
    {
      while (tmp->key_value != k)
        tmp = tmp->next;
      return (iterator(tmp));
    }
    struct __map *_new = new struct __map;
    while (_comp(tmp->key_value, k) && tmp->next != 0) //Insert on correct order
      tmp = tmp->next;
    _new->prev = tmp->prev;
    _new->prev->next = _new;
    tmp->prev = _new;
    _new->next = tmp;
    _new->head = tmp->head;
    _new->key_value = k;
    _new->element_value = value;
    _size++;
    return (iterator(_new));
  }

  template<typename Key, typename T, typename Compare>
  bool map<Key, T, Compare>::is_in(const Key &k) const
  {
    struct __map *tmp = _map->head->next;

    if (_size == 0)
      return false;
    while (tmp->next != 0 && tmp->key_value != k)
      tmp = tmp->next;
    if (tmp->next == 0) //If value not found return false
      return false;
    else
      return true;
  }

  template<typename Key, typename T, typename Compare>
  void map<Key, T, Compare>::_erase(struct __map *position)
  {
    struct __map *tmp = _map->head->next;

    if (_size == 0 || position == 0)
      return ;
    while(tmp != position && tmp->next != 0)
      tmp = tmp->next;
    if (tmp->next == 0) //Container not found or if == end do not erase
      return ;
    position->next->prev = position->prev;
    position->prev->next = position->next;
    delete position;
    _size--;
  }

  template<typename Key, typename T, typename Compare>
  template<typename inputiterator>
  void map<Key, T, Compare>::cpy(inputiterator first, inputiterator last)
  {
    struct __map *tmp = _map->head;

    while (first != last)
    {
      _size++;
      struct __map *_new = new struct __map;
      _new->next = tmp->next;
      _new->next->prev = _new;
      tmp->next = _new;
      tmp->next->head = tmp->head;
      tmp->next->prev = tmp;
      tmp = tmp->next;
      tmp->key_value = first->first;
      tmp->element_value = first->second;
      ++first;
    }
  }

  template<typename Key, typename T, typename Compare>
  void map<Key, T, Compare>::ending_empty_container()
  {
    _map = new struct __map;
    struct __map *end = new struct __map;
    _map->next = end;
    _map->prev = 0;
    _map->element_value = T(0);
    _map->key_value = Key(0);
    _map->head = _map;
    end->next = 0;
    end->prev = _map;
    end->element_value = T(0);
    end->key_value = Key(0);
    end->head = _map;
    return ;
   }

}//End of namespace ft

#endif
