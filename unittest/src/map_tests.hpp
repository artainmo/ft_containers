#include "../main.hpp"

//MY

template<typename Key, typename T>
void show_map(ft::map<Key, T> &l, std::ofstream fd)
{
  unsigned int m;
  typename ft::map<Key, T>::iterator i = l.begin();

  m = 0;
  while(m < l.size())
  {
    m++;
    fd << i->first << "\t" << i->second << std::endl;
    if (m < l.size())
      ++i;
  }
}

template<typename Key, typename T>
void show_map_reverse(ft::map<Key, T> &l, std::ofstream fd) //Not in reverse order but using a reverse iterator
{
  unsigned int m;
  typename ft::map<Key, T>::reverse_iterator i(l.rend());

  m = 0;
  while(m < l.size())
  {
    m++;
    fd << i->first << "\t" << i->second << std::endl;
    if (m < l.size())
      --i;
  }
}

template<typename Key, typename T>
void reverse_map(ft::map<Key, T> &l, std::ofstream fd) //Read and show map in reverse order
{
  unsigned int m;
  typename ft::map<Key, T>::iterator i = l.end();

  m = 0;
  while(m < l.size())
  {
    m++;
    fd << i->first << "\t" << i->second << std::endl;
    if (m < l.size())
      --i;
  }
}

//REAL

template<typename Key, typename T>
void show_map(map<Key, T> &l, std::ofstream fd)
{
  unsigned int m;
  typename ft::map<Key, T>::iterator i = l.begin();

  m = 0;
  while(m < l.size())
  {
    m++;
    fd << i->first << "\t" << i->second << std::endl;
    if (m < l.size())
      ++i;
  }
}

template<typename Key, typename T>
void show_map_reverse(map<Key, T> &l, std::ofstream fd) //Not in reverse order but using a reverse iterator
{
  unsigned int m;
  typename map<Key, T>::reverse_iterator i(l.rend());

  m = 0;
  while(m < l.size())
  {
    m++;
    fd << i->first << "\t" << i->second << std::endl;
    if (m < l.size())
      --i;
  }
}

template<typename Key, typename T>
void reverse_map(map<Key, T> &l, std::ofstream fd) //Read and show map in reverse order
{
  unsigned int m;
  typename map<Key, T>::iterator i = l.end();

  m = 0;
  while(m < l.size())
  {
    m++;
    fd << i->first << "\t" << i->second << std::endl;
    if (m < l.size())
      --i;
  }
}

void test_map(std::ofstream fd_w)
{
  write("\n~~~~~~~Map~~~~~~~~\n", fd_w);
  write("CONSTRUCTORS", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("Construction of empty map container and showing its size", fd_w);
  ft::map<int, int> m1;
  write(m1.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("Insert container with values", fd_w); //Pair is a class that works as a binary tuple
  m1.insert(std::pair<int, int>(1, 4));
  m1.insert(std::pair<int, int>(2, 3));
  m1.insert(std::pair<int, int>(3, 6));
  m1.insert(std::pair<int, int>(4, 2));
  m1.insert(std::pair<int, int>(5, 5));
  m1.insert(std::pair<int, int>(6, 5));
  m1.insert(std::pair<int, int>(7, 1));
  show_map<int, int>(m1);
  P(m1.size());
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Create a ranged map based on last three elements last list and show its content");
  ft::map<int, int>::iterator mi = m1.begin();
  ++mi;
  ++mi;
  ++mi;
  ++mi;
  ft::map<int, int> m2(mi, m1.end());
  show_map<int, int>(m2);
  reverse_map<int, int>(m2); //To see if backwards movement works properly
  P(m2.size());
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Create a copy of last map and show content");
  ft::map<int, int> m3(m2);
  show_map_reverse<int, int>(m3); //Use reverse iterators to prove they are functionning
  reverse_map<int, int>(m3);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Assign first map to last one and show content");
  m3 = m1;
  show_map_reverse<int, int>(m3);
  reverse_map<int, int>(m3);
  P(m3.size());
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("~");

  //Iterators
  P("ITERATORS");
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("To show the constructed and assigned map containers, iterators and reverse iterators were used\n");
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  //Capacity
  P("CAPACITY");
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Empty function on last map and cleared map");
  if (m3.empty() == false) //Returns false if not empty
    P("false");
  m1.clear();
  if (m1.empty() == true) //Returns true if empty
    P("true");
  m1 = m3;
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Size function on last map");
  P(m3.size());
  P("Max size function on last map"); //Max unsigned int because size is stored into unsigned int
  P(m3.max_size());
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("~");

  // Element access
  P("ELEMENT ACCESS");
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Using [] operator to insert new elements and show them");
  ft::map<int, int> m4;
  m4[2] = 2;
  m4[2] = 9; //Not possible to have two times same element, but you can reset its value
  m4[3] = 3;
  m4[5] = 5;
  m4[4] = 4; //Insert not at end but in right order
  m4[1] = 6; //Should be inserted at beginning
  show_map<int, int>(m4);
  reverse_map<int, int>(m4);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Showing the map using [] operator");
  std::cout << m4[1];
  std::cout << m4[2];
  std::cout << m4[3];
  std::cout << m4[4];
  std::cout << m4[5];
  std::cout << std::endl;
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("~");

  //Modifiers
  P("MODIFIERS");
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Insert an element at beginning of last map and check new size"); //Insert using key
  m4.insert(std::pair<int, int>(0, 0));
  show_map<int, int>(m4);
  reverse_map<int, int>(m4);
  P(m4.size());
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Removes first element of last map using iterator and checks new size"); //Erase using iterator
  m4.erase(m4.begin());
  show_map<int, int>(m4);
  reverse_map<int, int>(m4);
  P(m4.size());
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Insert element at end of last map and check new size"); //Insert using iterator hint and key value //As a specific order needs to be followed in map container hint is not of importance
  m4.insert(m4.begin(), std::pair<int, int>(8, 8)); //Given position is wrong but because it is only considered as a hint and priority is given to the key order, 8 comes last
  show_map<int, int>(m4);
  reverse_map<int, int>(m4);
  P(m4.size());
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Removes element 8 at end of last map using key and check new size"); //Erase using key type
  m4.erase(8);
  show_map<int, int>(m4);
  reverse_map<int, int>(m4);
  P(m4.size());
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Inserts a range, the whole map 3, and checks new size"); //Use iterator range
  m3[1] = 7;
  m3[2] = 7;
  m3[3] = 7;
  P("Map 3 to be inserted:");
  show_map<int, int>(m3);
  P("New map, should have 6 and 7 as new keys:");
  m4.insert<ft::map<int, int>::iterator >(m3.begin(), m3.end());
  show_map<int, int>(m4);
  reverse_map<int, int>(m4);
  P(m4.size());
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Erase a whole range only maintaining the first 4 elements"); //Use iterator range
  ft::map<int, int>::iterator ml = m4.begin();
  ++ml;
  ++ml;
  ++ml;
  ++ml;
  m4.erase(ml, m4.end());
  show_map<int, int>(m4);
  reverse_map<int, int>(m4);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Swap content between two maps");
  P("Before the swap:");
  P("map one:");
  show_map<int, int>(m1);
  P(m1.size());
  P("map two:");
  show_map<int, int>(m2);
  P(m2.size());
  m1.swap(m2);
  P("After the swap:");
  P("map one:");
  show_map<int, int>(m1);
  reverse_map<int, int>(m1);
  P(m1.size());
  P("map two:");
  show_map<int, int>(m2);
  reverse_map<int, int>(m2);
  P(m2.size());
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Clearing the last map and checking its size");
  m1.clear();
  P(m1.size());
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("~");

  //Observers
  P("OBSERVERS");
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P(m4.key_comp()(2, 1)); //Returns compare object //Thus returns 0 if first number is not smaller than second one and returns 1 if first number is smaller than second one
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P(m4.value_comp()(m4.begin(), m4.end())); //Returns compare class around compare object, takes iterators as parameters instead of values... // Should always return one in this example here because begin of list is always ordered before the end of list
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("~");

  //Operations
  P("OPERATIONS");
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Using find to get an iterator on key value 2");
  show_map<int, int>(m4);
  ml = m4.find(2);
  std::cout << "Key: ";
  P(ml->first);
  std::cout << "Value: ";
  P(ml->second);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Using find to get an iterator on a non found key value 9 (Should return last element)");
  show_map<int, int>(m4);
  ml = m4.find(9);
  std::cout << "Key: ";
  P(ml->first);
  std::cout << "Value: ";
  P(ml->second);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Using count function on the specific key value 1"); //Because only unique key values, max count is one
  show_map<int, int>(m4);
  P(m4.count(2));
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Using count function on the non found key value 9"); //Because only unique key values, max count is one
  show_map<int, int>(m4);
  P(m4.count(9));
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Using the upper bound function that returns an iterator on first key value that goes after 3");
  show_map<int, int>(m4);
  ml = m4.lower_bound(3);
  std::cout << "Key: ";
  P(ml->first);
  std::cout << "Value: ";
  P(ml->second);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Using the upper bound function that returns an iterator on first key value that goes after 3, behalf 3 itself");
  show_map<int, int>(m4);
  ml = m4.upper_bound(3);
  std::cout << "Key: ";
  P(ml->first);
  std::cout << "Value: ";
  P(ml->second);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Using the equal_range function that returns a pair of iterators lower_bound and upper_bound of key 3");
  show_map<int, int>(m4);
  std::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator > pm = m4.equal_range(1);
  std::cout << "Key: ";
  P(pm.first->first);
  std::cout << "Value: ";
  P(pm.first->second);
  std::cout << "Key: ";
  P(pm.second->first);
  std::cout << "Value: ";
  P(pm.second->second);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("Using the equal_range function that returns a pair of iterators on non-existing key 5 (Should return two times lower_bound / two times last values)");
  show_map<int, int>(m4);
  pm = m4.equal_range(5);
  std::cout << "Key: ";
  P(pm.first->first);
  std::cout << "Value: ";
  P(pm.first->second);
  std::cout << "Key: ";
  P(pm.second->first);
  std::cout << "Value: ";
  P(pm.second->second);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("~");

  // P("Error management");
  // ft::map<int, int> em;
  // P("Trying to show front, back in empty container"); //Cannot be tested with empty iterator, because container cannot make iterator point on nothing
  // em.begin();
  // em.end();
  // P("~");
}
