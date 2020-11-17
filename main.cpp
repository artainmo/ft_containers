#include "List/list.hpp"
#include "Vector/vector.hpp"
#include "Map/map.hpp"
#include "Stack/stack.hpp"
#include "Queue/queue.hpp"

//allocator_type does not need to be done, because we do not need to implement the get_allocator function
//https://www.cplusplus.com/reference/list/list/?kw=list


//LIST

template<typename T>
void show_list(ft::list<T> &l)
{
  unsigned int m;
  typename ft::list<T>::iterator i = l.begin();

  m = 0;
  while(m < l.size())
  {
    m++;
    std::cout << *i;
    if (m < l.size())
      ++i;
  }
  std::cout << std::endl;
}

template<typename T>
void show_list_reverse(ft::list<T> &l) //Not in reverse order but using a reverse iterator
{
  unsigned int m;
  typename ft::list<T>::reverse_iterator i = l.rend();

  m = 0;
  while(m < l.size())
  {
    m++;
    std::cout << *i;
    if (m < l.size())
      --i;
  }
  std::cout << std::endl;
}

template<typename T>
void reverse_list(ft::list<T> &l) //Read and show list in reverse order
{
  unsigned int m;
  typename ft::list<T>::iterator i = l.end();

  m = 0;
  while(m < l.size())
  {
    m++;
    std::cout << *i;
    if (m < l.size())
      --i;
  }
  std::cout << std::endl;
}

template<typename T>
bool remove_if_test(T x)
{
  if (x == 8)
    return true;
  return false;
}

template<typename T>
bool unique_test(T x, T x2)
{
  if (x - 1 == x2)
    return true;
  return false;
}

template<typename T>
bool merge_test(T x, T x2)
{
  if (x > x2)
    return true;
  return false;
}

template<typename T>
bool sort_test(T x, T x2)
{
  if (x > x2)
    return true;
  return false;
}

//VECTOR

template<typename T>
void show_vector(ft::vector<T> &l)
{
  unsigned int m;

  m = 0;
  while(l[m] != 0 && l.size() != 0)
  {
    std::cout << l[m];
    m++;
  }
  std::cout << std::endl;
}

template<typename T>
void show_vector2(ft::vector<T> &l) //Use at function instead of [] operator
{
  unsigned int m;

  m = 0;
  while(l.at(m) != 0 && l.size() != 0)
  {
    std::cout << l.at(m);
    m++;
  }
  std::cout << std::endl;
}


//MAP

template<typename Key, typename T>
void show_map(ft::map<Key, T> &l)
{
  unsigned int m;
  typename ft::map<Key, T>::iterator i = l.begin();

  m = 0;
  while(m < l.size())
  {
    m++;
    std::cout << i->first << "\t" << i->second << std::endl;
    if (m < l.size())
      ++i;
  }
}

template<typename Key, typename T>
void show_map_reverse(ft::map<Key, T> &l) //Not in reverse order but using a reverse iterator
{
  unsigned int m;
  typename ft::map<Key, T>::reverse_iterator i(l.rend());

  m = 0;
  while(m < l.size())
  {
    m++;
    std::cout << i->first << "\t" << i->second << std::endl;
    if (m < l.size())
      --i;
  }
}

template<typename Key, typename T>
void reverse_map(ft::map<Key, T> &l) //Read and show map in reverse order
{
  unsigned int m;
  typename ft::map<Key, T>::iterator i = l.end();

  m = 0;
  P("(Show it in reverse to see if backwards movement functions properly)");
  while(m < l.size())
  {
    m++;
    std::cout << i->first << "\t" << i->second << std::endl;
    if (m < l.size())
      --i;
  }
}

//STACK
template<typename T>
void show_stack(ft::stack<T> s)
{
  while (!s.empty())
  {
    std::cout << s.top();
    s.pop(); //To iterate over whole stack you have to destoy it and start from end to start
  }
  std::cout << std::endl;
}

//QUEUE
template<typename T>
void show_queue(ft::queue<T> s)
{
  while (!s.empty())
  {
    std::cout << s.front();
    s.pop(); //To iterate over whole queue you have to destroy it, reading it from start to end
  }
  std::cout << std::endl;
}

int main(int argc, char **argv)
{
  if (std::strcmp("list", argv[1]) == 0)
  {
  //LIST
  P("~~~~~~~LIST~~~~~~~~\n");
  //Contruction and iterators
  P("CONSTRUCTORS");
  P("Construction of empty list container and showing its size");
  ft::list<int> l1;
  P(l1.size());
  P("Contructing a filled list and showing its content using an iterator");
  ft::list<int> l2((unsigned int)10, 5); //Indicate unsigned int is necessary otherwise it will use the templated inputiterator (int, int) function
  show_list<int>(l2);
  reverse_list<int>(l2); //To see if backwards reading works properly
  P("Create a ranged list and show its content");
  ft::list<int>::iterator i = l2.begin();
  ++i;
  ++i;
  ++i;
  ft::list<int> l3(i, l2.end());
  show_list<int>(l3);
  reverse_list<int>(l3);
  P("Create a copy of last list and show content");
  ft::list<int> l4(l3);
  show_list_reverse<int>(l4);
  reverse_list<int>(l4);
  P("Assign last list to first one and show content");
  l1 = l4;
  show_list_reverse<int>(l1);
  reverse_list<int>(l1);
  P("");

  //Iterators
  P("ITERATORS");
  P("To show the constructed and assigned list containers, iterators and reverse iterators were used\n");

  //Capacity
  P("CAPACITY");
  P("Empty function on last list and cleared list");
  if (l4.empty() == false) //Returns false if not empty
    P("false");
  l1.clear();
  if (l1.empty() == true) //Returns true if empty
    P("true");
  l1 = l4;
  P("Size function on last list");
  P(l4.size());
  P("Max size function on last list");
  P(l4.max_size());
  P("");

  //Element access
  P("ELEMENT ACCESS");
  P("Accessing first and last element of following list");
  l4.push_front(7);
  l4.push_back(9);
  show_list<int>(l4);
  reverse_list<int>(l4);
  P(l4.front());
  P(l4.back());
  P("");

  //Modifiers
  P("MODIFIERS");
  P("Fill the last list container with value 7");
  l4.assign((unsigned int)12, 7); //If you do not cast it to an unsigned int, it will enter the other assign function with two int parameters
  show_list<int>(l4);
  reverse_list<int>(l4);
  P("Assign a range of elements from second list to the last list");
  l4.assign(i, l2.end());
  show_list<int>(l4);
  reverse_list<int>(l4);
  P("Insert element 8 at beginning of last list and check new size");
  l4.push_front(8);
  show_list<int>(l4);
  reverse_list<int>(l4);
  P(l4.size());
  P("Removes element 8 at begin of last list and check new size");
  l4.pop_front();
  show_list<int>(l4);
  reverse_list<int>(l4);
  P(l4.size());
  P("Insert element 8 at end of last list and check new size");
  l4.push_back(8);
  show_list<int>(l4);
  reverse_list<int>(l4);
  P(l4.size());
  P("Removes element 8 at end of last list and check new size");
  l4.pop_back();
  show_list<int>(l4);
  reverse_list<int>(l4);
  P(l4.size());
  P("Inserts element 3 in third place list");
  i = l4.begin();
  ++i;
  ++i;
  l4.insert(i, 3);
  show_list<int>(l4);
  reverse_list<int>(l4);
  P("Inserts 3 elements of 4 and checks new size");
  l4.insert(i, (unsigned int)3, 4);
  show_list<int>(l4);
  reverse_list<int>(l4);
  P(l4.size());
  P("Inserts a range, the whole list 3, and checks new size");
  l3.assign((unsigned int)4, 9);
  l4.insert<ft::list<int>::iterator >(i, l3.begin(), l3.end());
  show_list<int>(l4);
  reverse_list<int>(l4);
  P(l4.size());
  P("Erases the element 5 following the 9");
  l4.erase(i);
  show_list<int>(l4);
  reverse_list<int>(l4);
  P("Erase the whole non-5 range");
  ft::list<int>::iterator l = l4.begin();
  ++l;
  ++l;
  --i; //If you do not do this it will point on the just erased value
  l4.erase(l, i);
  show_list<int>(l4);
  reverse_list<int>(l4);
  P("Swap content between two lists");
  P("Before the swap:");
  l1.push_back(9);
  l2.push_back(6);
  show_list<int>(l1);
  show_list<int>(l2);
  l1.swap(l2);
  P("After the swap:");
  show_list<int>(l1);
  show_list<int>(l2);
  P("Resizing list");
  std::cout << "Before :";
  show_list<int>(l3);
  std::cout << "Resize one bigger :";
  l3.resize(l3.size() + 1, 9);
  show_list<int>(l3);
  std::cout << "Resize two smaller :";
  l3.resize(l3.size() - 2, 9);
  show_list<int>(l3);
  P("Clearing the last list and checking its size");
  l1.clear();
  P(l1.size());
  P("");

  //Operations
  P("OPERATIONS");
  P("Splicing means transfering from one list to another one");
  P("Here we will splice, list 3 into list 4");
  P("Before:");
  show_list<int>(l3);
  show_list<int>(l4);
  l4.splice(l4.begin(), l3);
  P("After:");
  show_list<int>(l3);
  show_list<int>(l4);
  P("Here we will splice the first element from list 2 into list 4 at second position");
  i = l2.begin();
  l = l4.begin();
  ++l;
  P("Before:");
  show_list<int>(l2);
  show_list<int>(l4);
  l4.splice(l, l2,i);
  P("After:");
  show_list<int>(l2);
  show_list<int>(l4);
  P("Here we will splice a range from list 2 to 4");
  ++i; //Because the prior position got erased we have to increment it
  ft::list<int>::iterator m = i;
  ++m;
  ++m;
  ++m;
  P("Before:");
  show_list<int>(l2);
  show_list<int>(l4);
  l4.splice(l, l2,i, m);
  P("After:");
  show_list<int>(l2);
  show_list<int>(l4);
  reverse_list<int>(l4);
  P("Here we will remove all the 5s in the last list");
  l4.remove(5);
  show_list<int>(l4);
  reverse_list<int>(l4);
  P("Here we will remove elements 8 from following list based on a boolean function");
  l4.push_front(8);
  l4.push_back(8);
  std::cout << "Before: ";
  show_list<int>(l4);
  l4.remove_if(remove_if_test<int>);
  std::cout << "After: ";
  show_list<int>(l4);
  P("Here we will eliminate all duplicate values from the following list");
  l4.push_front(8);
  l4.push_back(8);
  std::cout << "Before:";
  show_list<int>(l4);
  l4.unique();
  std::cout << "After:";
  show_list<int>(l4);
  P("Here we will eliminate all numbers that are equal to one plus the prior number in last list based on a boolean function");
  l4.unique(unique_test<int>);
  show_list<int>(l4);
  P("Here we will merge list 2 into list 4, list 2 will become non-existant");
  P("Before:");
  show_list<int>(l2);
  show_list<int>(l4);
  l4.merge(l2);
  P("After:");
  show_list<int>(l2);
  show_list<int>(l4);
  std::cout << "Show in reverse:";
  reverse_list<int>(l4);
  std::cout << "Size check:";
  P(l4.size());
  P("Here we will merge in list 4 the list 2 in an ordered way, from biggest to smallest"); //Both containers should already be ordered
  l2.clear();
  l2.push_back(9);
  l2.push_back(8);
  l2.push_back(6);
  l2.push_back(3);
  l4.pop_back();
  l4.push_front(9);
  P("Before:");
  show_list<int>(l2);
  show_list<int>(l4);
  l4.merge(l2, merge_test<int>);
  P("After:");
  show_list<int>(l2);
  show_list<int>(l4);
  P("Here we will sort the following list");
  l4.push_back(9);
  l4.push_back(3);
  l4.push_front(3);
  l4.push_front(6);
  std::cout << "before:";
  show_list<int>(l4);
  l4.sort();
  std::cout << "after:";
  show_list<int>(l4);
  std::cout << "Reverse order check:";
  reverse_list<int>(l4);
  std::cout << "Size check:";
  P(l4.size());
  P("Here we will sort the last list based on a function that sorts in reverse");
  l4.sort(sort_test<int>);
  show_list<int>(l4);
  P("Here we will directly reverse the list");
  std::cout << "Before:";
  show_list<int>(l4);
  l4.reverse();
  std::cout << "After:";
  show_list<int>(l4);
  P("");

  //Non-member function overloads
  P("Non-member function overloads");
  ft::list<int> li1((unsigned int)4,4);
  ft::list<int> li2((unsigned int)4,4);
  ft::list<int> li3((unsigned int)4,6);
  P("Test whether following lists are equal");
  show_list<int>(li1);
  show_list<int>(li2);
  if (li1 == li2)
    P("YES");
  P("Test whether following lists are equal");
  show_list<int>(li1);
  show_list<int>(li3);
  if (li1 != li3)
    P("NO");
  P("Test whether first list is smaller than second one");
  show_list<int>(li1);
  show_list<int>(li2);
  if (li1 < li2)
    P("YES");
  else
    P("NO");
  P("Test whether first list is bigger than second one");
  show_list<int>(li3);
  show_list<int>(li1);
  if (li3 > li1)
    P("YES");
  P("Test whether first list is bigger than or equal to first one");
  show_list<int>(li1);
  show_list<int>(li2);
  if (li1 >= li2)
    P("YES");
  P("Test whether first list is smaller than or equal to first one");
  show_list<int>(li1);
  show_list<int>(li2);
  if (li1 <= li2)
    P("YES");
  P("We will swap the content of the following two lists");
  P("Before:");
  show_list<int>(li1);
  show_list<int>(li3);
  swap(li1, li3);
  P("After:");
  show_list<int>(li1);
  show_list<int>(li3);
  P("");

  P("Const list and iterator");
  const ft::list<int> cl((unsigned int)4,4);
  ft::list<int>::const_iterator cli = cl.begin();
  P("Const list calling size, clear and trying to change front value");
  P(cl.size());
  // cl.clear(); //Should create compilation error
  // cl.front() = 9; //Should create compilation error
  P("Const iterator showing front value and trying to change front value");
  P(*cli);
  // *cli = 9; //Should create compilation error
  P("");

  P("Error management");
  ft::list<int> el;
  P("Trying to pop and show front, back in empty container"); //Cannot be tested with empty iterator, because container cannot make iterator point on nothing
  el.pop_front();
  el.pop_back();
  el.front();
  el.back();
  P("");
  }

  //VECTOR
  if (std::strcmp("vector", argv[1]) == 0)
  {
  P("\n~~~~~~~VECTOR~~~~~~~~\n");
  //Contruction and iterators
  P("CONSTRUCTORS");
  P("Construction of empty vector container and showing its size");
  ft::vector<int> v1;
  P(v1.size());
  show_vector<int>(v1);
  P("Contructing a filled vector and showing its content using an iterator");
  ft::vector<int> v2((unsigned int)10, 5); //Indicate unsigned int is necessary otherwise it will use the templated inputiterator (int, int) function
  show_vector<int>(v2);
  P("Create a ranged vector and show its content");
  ft::vector<int>::iterator vi = v2.begin();
  ++vi;
  ++vi;
  ++vi;
  ft::vector<int> v3(vi, v2.end());
  show_vector<int>(v3);
  P("Create a copy of last vector and show content");
  ft::vector<int> v4(v3);
  show_vector<int>(v4);
  P("Assign last vector to first one and show content");
  v1 = v4;
  show_vector<int>(v1);
  P("");
  //
  //Iterators
  P("ITERATORS");
  P("To show the constructed and assigned vector containers, iterators were used");
  P("Create a ranged vector and show its content using reverse iterators");
  ft::vector<int> v5(vi, v2.end());
  show_vector2<int>(v5);
  P("");

  //Capacity
  P("CAPACITY");
  P("Size function on vector following vector");
  show_vector<int>(v4);
  P(v4.size());
  P("Max size function on last vector"); //Size is stored in unsigned int thus, max_size is unsigned int
  P(v4.max_size()); //MAx unisgned int because size is stored in unsigned int
  P("Resizing vector");
  std::cout << "Before :";
  show_vector<int>(v3);
  std::cout << "Resize three bigger :";
  v3.resize(v3.size() + 3, 9);
  show_vector<int>(v3);
  std::cout << "Resize two smaller :";
  v3.resize(v3.size() - 2, 9);
  show_vector<int>(v3);
  P("Show size followed by capacity of different vectors");
  v1.resize(99, 9);
  P(v1.size());
  P(v1.capacity());
  show_vector<int>(v1);
  v1.resize(100, 8); //Because of additional /0 at end array, size should be increased
  P(v1.size());
  P(v1.capacity());
  show_vector<int>(v1);
  v1.resize(5, 9);
  P(v1.size());
  P(v1.capacity());
  show_vector<int>(v1);
  v1.resize(6, 6);
  P(v1.size());
  P(v1.capacity());
  show_vector<int>(v1);
  v1.resize(150, 9);
  P(v1.size());
  P(v1.capacity());
  show_vector<int>(v1);
  P(v4.size());
  P(v4.capacity());
  show_vector<int>(v4);
  P("Empty function on last vector and cleared vector");
  if (v4.empty() == false) //Returns false if not empty
    P("false");
  v1.clear();
  if (v1.empty() == true) //Returns true if empty
    P("true");
  v1 = v4;
  P("Reserve less space than already in place"); //Reserved space should then not be reduced but stay the same
  std::cout << "Before:";
  show_vector<int>(v4);
  P(v4.capacity());
  P(v4.size());
  v4.reserve(v4.capacity() - 10);
  std::cout << "After:";
  show_vector<int>(v4);
  P(v4.capacity());
  P(v4.size());
  P("Reserve more space than already in place");
  std::cout << "Before:";
  show_vector<int>(v4);
  P(v4.capacity());
  P(v4.size());
  v4.reserve(v4.capacity() + 10);
  std::cout << "After:";
  show_vector<int>(v4);
  P(v4.capacity());
  P(v4.size());
  P("");

  //Element access
  P("ELEMENT ACCESS");
  P("Showing the following vector using the [] operator and at function");
  show_vector<int>(v4);
  show_vector2<int>(v4);
  P("Accessing first and last element of following vector");
  v4.insert(v4.begin(), 7);
  v4.push_back(9);
  show_vector<int>(v4);
  P(v4.front());
  P(v4.back());
  P("");


  //Modifiers
  P("MODIFIERS");
  P("Fill the last vector container with value 7");
  v4.assign((unsigned int)12, 7); //If you do not cast it to an unsigned int, it will enter the other assign function with two int parameters
  show_vector<int>(v4);
  P(v4.size());
  P("Assign a range of elements from second vector to the last vector");
  show_vector<int>(v2);
  vi = v2.begin();
  ++vi;
  ++vi;
  v4.assign<ft::vector<int>::iterator >(vi, v2.end());
  show_vector<int>(v4);
  P(v4.size());
  P("Insert element 8 at end of last vector and check new size");
  v4.push_back(8);
  show_vector<int>(v4);
  P(v4.size());
  P("Removes element 8 at end of last vector and check new size");
  v4.pop_back();
  show_vector<int>(v4);
  P(v4.size());
  P("Inserts element 3 in third place vector");
  v4.push_back(2);
  show_vector<int>(v4);
  P(v4.size());
  vi = v4.begin();
  ++vi;
  ++vi;
  v4.insert(vi, 3);
  show_vector<int>(v4);
  P(v4.size());
  P(v4.capacity());
  P("Inserts 3 elements of 4 and checks new size");
  show_vector<int>(v4);
  v4.insert(v4.begin(), (unsigned int)3, 4);
  show_vector<int>(v4);
  P(v4.size());
  P("Inserts a range at third position, the whole vector 3 (4 elements of one), and checks new size");
  vi = v4.begin();
  ++vi;
  ++vi;
  v3.assign((unsigned int)4, 1);
  v4.insert<ft::vector<int>::iterator >(vi, v3.begin(), v3.end());
  show_vector<int>(v4);
  P(v4.size());
  P("Erases the first and last element");
  v4.erase(v4.begin());
  v4.erase(v4.end());
  show_vector<int>(v4);
  P(v4.size());
  P("Erase the whole last vector besides two first and last elements");
  ft::vector<int>::iterator vl = v4.begin();
  vi = v4.end();
  ++vl;
  ++vl;
  --vi;
  --vi;
  v4.erase(vl, vi);
  show_vector<int>(v4);
  P("Swap content between two vectors");
  P("Before the swap:");
  v1.push_back(9);
  v2.push_back(6);
  show_vector<int>(v1);
  P(v1.size());
  show_vector<int>(v2);
  P(v2.size());
  v1.swap(v2);
  P("After the swap:");
  show_vector<int>(v1);
  P(v1.size());
  show_vector<int>(v2);
  P(v2.size());
  P("Clearing the last vector and checking its size");
  v1.clear();
  P(v1.size());
  P("");

  // Non-member function overloads
  P("Non-member function overloads");
  ft::vector<int> vi1((unsigned int)4,4);
  ft::vector<int> vi2((unsigned int)4,4);
  ft::vector<int> vi3((unsigned int)4,6);
  P("Test whether following vectors are equal");
  show_vector<int>(vi1);
  show_vector<int>(vi2);
  if (vi1 == vi2)
    P("YES");
  P("Test whether following vectors are equal");
  show_vector<int>(vi1);
  show_vector<int>(vi3);
  if (vi1 != vi3)
    P("NO");
  P("Test whether first vector is smaller than second one");
  show_vector<int>(vi1);
  show_vector<int>(vi2);
  if (vi1 < vi2)
    P("YES");
  else
    P("NO");
  P("Test whether first vector is bigger than second one");
  show_vector<int>(vi3);
  show_vector<int>(vi1);
  if (vi3 > vi1)
    P("YES");
  P("Test whether first vector is bigger than or equal to first one");
  show_vector<int>(vi1);
  show_vector<int>(vi2);
  if (vi1 >= vi2)
    P("YES");
  P("Test whether first vector is smaller than or equal to first one");
  show_vector<int>(vi1);
  show_vector<int>(vi2);
  if (vi1 <= vi2)
    P("YES");
  P("We will swap the content of the following two vectors");
  P("Before:");
  show_vector<int>(vi1);
  P(vi1.size());
  show_vector<int>(vi3);
  P(vi3.size());
  swap(vi1, vi3);
  P("After:");
  show_vector<int>(vi1);
  P(vi1.size());
  show_vector<int>(vi3);
  P(vi3.size());
  P("");

  P("Const vector and iterator");
  const ft::vector<int> cv((unsigned int)4,4);
  ft::vector<int>::const_iterator cvi = cv.begin();
  P("Const vector calling size, clear and trying to change front value");
  P(cv.size());
  // cv.clear(); //Should create compilation error
  // cv.front() = 9; //Should create compilation error
  P("Const iterator showing front value and trying to change front value");
  P(*cvi);
  // *cvi = 9; //Should create compilation error
  P("");

  P("Error management");
  ft::vector<int> ev;
  P("Trying to pop and show front, back in empty container"); //Cannot be tested with empty iterator, because container cannot make iterator point on nothing
  ev.pop_back();
  ev.front();
  ev.back();
  P("");
  }

  //Map
  if (std::strcmp("map", argv[1]) == 0)
  {
  P("\n~~~~~~~Map~~~~~~~~\n");
  //Contruction and iterators
  P("CONSTRUCTORS");
  P("Construction of empty map container and showing its size");
  ft::map<int, int> m1;
  P(m1.size());
  P("Insert container with values"); //Pair is a class that works as a binary tuple
  m1.insert(std::pair<int, int>(1, 4));
  m1.insert(std::pair<int, int>(2, 3));
  m1.insert(std::pair<int, int>(3, 6));
  m1.insert(std::pair<int, int>(4, 2));
  m1.insert(std::pair<int, int>(5, 5));
  m1.insert(std::pair<int, int>(6, 5));
  m1.insert(std::pair<int, int>(7, 1));
  show_map<int, int>(m1);
  P(m1.size());
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
  P("Create a copy of last map and show content");
  ft::map<int, int> m3(m2);
  show_map_reverse<int, int>(m3); //Use reverse iterators to prove they are functionning
  reverse_map<int, int>(m3);
  P("Assign first map to last one and show content");
  m3 = m1;
  show_map_reverse<int, int>(m3);
  reverse_map<int, int>(m3);
  P(m3.size());
  P("");

  //Iterators
  P("ITERATORS");
  P("To show the constructed and assigned map containers, iterators and reverse iterators were used\n");

  //Capacity
  P("CAPACITY");
  P("Empty function on last map and cleared map");
  if (m3.empty() == false) //Returns false if not empty
    P("false");
  m1.clear();
  if (m1.empty() == true) //Returns true if empty
    P("true");
  m1 = m3;
  P("Size function on last map");
  P(m3.size());
  P("Max size function on last map"); //Max unsigned int because size is stored into unsigned int
  P(m3.max_size());
  P("");

  // Element access
  P("ELEMENT ACCESS");
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
  P("Showing the map using [] operator");
  std::cout << m4[1];
  std::cout << m4[2];
  std::cout << m4[3];
  std::cout << m4[4];
  std::cout << m4[5];
  std::cout << std::endl;
  P("");

  //Modifiers
  P("MODIFIERS");
  P("Insert an element at beginning of last map and check new size"); //Insert using key
  m4.insert(std::pair<int, int>(0, 0));
  show_map<int, int>(m4);
  reverse_map<int, int>(m4);
  P(m4.size());
  P("Removes first element of last map using iterator and checks new size"); //Erase using iterator
  m4.erase(m4.begin());
  show_map<int, int>(m4);
  reverse_map<int, int>(m4);
  P(m4.size());
  P("Insert element at end of last map and check new size"); //Insert using iterator hint and key value //As a specific order needs to be followed in map container hint is not of importance
  m4.insert(m4.begin(), std::pair<int, int>(8, 8)); //Given position is wrong but because it is only considered as a hint and priority is given to the key order, 8 comes last
  show_map<int, int>(m4);
  reverse_map<int, int>(m4);
  P(m4.size());
  P("Removes element 8 at end of last map using key and check new size"); //Erase using key type
  m4.erase(8);
  show_map<int, int>(m4);
  reverse_map<int, int>(m4);
  P(m4.size());
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
  P("Erase a whole range only maintaining the first 4 elements"); //Use iterator range
  ft::map<int, int>::iterator ml = m4.begin();
  ++ml;
  ++ml;
  ++ml;
  ++ml;
  m4.erase(ml, m4.end());
  show_map<int, int>(m4);
  reverse_map<int, int>(m4);
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
  P("Clearing the last map and checking its size");
  m1.clear();
  P(m1.size());
  P("");

  //Observers
  P("OBSERVERS");
  P(m4.key_comp()(2, 1)); //Returns compare object //Thus returns 0 if first number is not smaller than second one and returns 1 if first number is smaller than second one
  P(m4.value_comp()(m4.begin(), m4.end())); //Returns compare class around compare object, takes iterators as parameters instead of values... // Should always return one in this example here because begin of list is always ordered before the end of list

  //Operations
  P("OPERATIONS");
  P("Using find to get an iterator on key value 2");
  show_map<int, int>(m4);
  P("~");
  ml = m4.find(2);
  std::cout << "Key: ";
  P(ml->first);
  std::cout << "Value: ";
  P(ml->second);
  P("Using find to get an iterator on a non found key value 9 (Should return last element)");
  show_map<int, int>(m4);
  P("~");
  ml = m4.find(9);
  std::cout << "Key: ";
  P(ml->first);
  std::cout << "Value: ";
  P(ml->second);
  P("Using count function on the specific key value 1"); //Because only unique key values, max count is one
  show_map<int, int>(m4);
  P("~");
  P(m4.count(2));
  P("Using count function on the non found key value 9"); //Because only unique key values, max count is one
  show_map<int, int>(m4);
  P("~");
  P(m4.count(9));
  P("Using the upper bound function that returns an iterator on first key value that goes after 3");
  show_map<int, int>(m4);
  P("~");
  ml = m4.lower_bound(3);
  std::cout << "Key: ";
  P(ml->first);
  std::cout << "Value: ";
  P(ml->second);
  P("Using the upper bound function that returns an iterator on first key value that goes after 3, behalf 3 itself");
  show_map<int, int>(m4);
  P("~");
  ml = m4.upper_bound(3);
  std::cout << "Key: ";
  P(ml->first);
  std::cout << "Value: ";
  P(ml->second);
  P("Using the equal_range function that returns a pair of iterators lower_bound and upper_bound of key 3");
  show_map<int, int>(m4);
  P("~");
  std::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator > pm = m4.equal_range(1);
  std::cout << "Key: ";
  P(pm.first->first);
  std::cout << "Value: ";
  P(pm.first->second);
  std::cout << "Key: ";
  P(pm.second->first);
  std::cout << "Value: ";
  P(pm.second->second);
  P("Using the equal_range function that returns a pair of iterators on non-existing key 5 (Should return two times lower_bound / two times last values)");
  show_map<int, int>(m4);
  P("~");
  pm = m4.equal_range(5);
  std::cout << "Key: ";
  P(pm.first->first);
  std::cout << "Value: ";
  P(pm.first->second);
  std::cout << "Key: ";
  P(pm.second->first);
  std::cout << "Value: ";
  P(pm.second->second);
  P("");

  P("Const map and iterator");
  const ft::map<int, int> cm(4,4);
  ft::map<int, int>::const_iterator cmi = cm.begin();
  P("Const map calling size, clear and trying to change front value");
  P(cm.size());
  // cm.clear(); //Should create compilation error
  // cm.front() = 9; //Should create compilation error
  P("Const iterator showing front value and trying to change front value");
  P(*cmi);
  // *cmi = 9; //Should create compilation error
  P("");

  P("Error management");
  ft::map<int, int> em;
  P("Trying to show front, back in empty container"); //Cannot be tested with empty iterator, because container cannot make iterator point on nothing
  em.begin();
  em.end();
  P("");
  }

  //STACK
  if (std::strcmp("stack", argv[1]) == 0)
  {
  P("~~~~~~~STACK~~~~~~~~\n");
  //Contruction and iterators
  P("CONSTRUCTORS");
  P("Construction of stack container");
  ft::stack<int> s1;
  P(s1.size());
  P("Filling LIFO style (last in first out, thus filling at end and reading in inverse)");
  s1.push(2);
  s1.push(5);
  s1.push(5);
  s1.push(7);
  s1.push(8);
  show_stack<int>(s1);
  P(s1.size());
  P("Create a copy of last stack and show content");
  ft::stack<int> s2(s1);
  show_stack<int>(s2);
  P("Assign first stack to new one and show content");
  ft::stack<int> s3;
  s3 = s1;
  show_stack<int>(s3);
  P("");

  //Capacity
  P("CAPACITY");
  P("Empty function on last stack and empty stack");
  if (s3.empty() == false) //Returns false if not empty
    P("false");
  ft::stack<int> s4;
  if (s4.empty() == true) //Returns true if empty
    P("true");
  s4 = s3;
  P("Size function on last stack");
  P(s3.size());
  P("");

  //Element access
  P("ELEMENT ACCESS");
  P("Accessing last element of following stack (Caution as we read and write the stack in inverse)");
  show_stack<int>(s3);
  P(s3.top());
  P("");

  //Modifiers
  P("MODIFIERS");
  P("Push element 8 at top of stack and check new size");
  s3.push(8);
  show_stack<int>(s3);
  P(s3.size());
  P("Removes element 8 at top of last stack and checks new size");
  s3.pop();
  show_stack<int>(s3);
  P(s3.size());
  P("");

  //Mon-member function overloads
  P("Non-member function overloads");
  ft::stack<int> si1;
  ft::stack<int> si2;
  ft::stack<int> si3;
  si1.push(4);
  si1.push(4);
  si1.push(4);
  si1.push(4);
  si2.push(4);
  si2.push(4);
  si2.push(4);
  si2.push(4);
  si3.push(6);
  si3.push(6);
  si3.push(6);
  si3.push(6);
  P("Test whether following stacks are equal");
  show_stack<int>(si1);
  show_stack<int>(si2);
  if (si1 == si2)
    P("YES");
  P("Test wether following stacks are equal");
  show_stack<int>(si1);
  show_stack<int>(si3);
  if (si1 != si3)
    P("NO");
  P("Test whether first stack is smaller than second one");
  show_stack<int>(si1);
  show_stack<int>(si3);
  if (si1 < si3)
    P("YES");
  else
    P("NO");
  P("Test whether first stack is bigger than second one");
  show_stack<int>(si3);
  show_stack<int>(si1);
  if (si3 > si1)
    P("YES");
  P("Test whether first stack is bigger than or equal to first one");
  show_stack<int>(si1);
  show_stack<int>(si2);
  if (si1 >= si2)
    P("YES");
  P("Test whether first stack is smaller than or equal to first one");
  show_stack<int>(si1);
  show_stack<int>(si2);
  if (si1 <= si2)
    P("YES");
  P("");

  P("Const stack");
  const ft::stack<int> cs(si1);
  P("Const stack calling size, pop and trying to change front value");
  P(cs.size());
  // cs.pop(); //Should create compilation error
  // cs.top() = 9; //Should create compilation error

  P("Error management");
  ft::stack<int> es;
  P("Trying to pop and show front in empty container"); //Cannot be tested with empty iterator, because container cannot make iterator point on nothing
  es.top();
  es.pop();
  P("");
  }

  //Queue
  if (std::strcmp("queue", argv[1]) == 0)
  {
  P("~~~~~~~QUEUE~~~~~~~~\n");
  //Contruction and iterators
  P("CONSTRUCTORS");
  P("Construction of queue container");
  ft::queue<int> q1;
  P(q1.size());
  P("Filling FIFO style (First in first out, thus filling at end erasing from beginning)");
  q1.push(2);
  q1.push(5);
  q1.push(5);
  q1.push(7);
  q1.push(8);
  show_queue<int>(q1);
  P("Create a copy of last queue and show content");
  ft::queue<int> q2(q1);
  show_queue<int>(q2);
  P("Assign first queue to new one and show content");
  ft::queue<int> q3;
  q3 = q1;
  show_queue<int>(q3);
  P("");

  //Capacity
  P("CAPACITY");
  P("Empty function on last queue and empty queue");
  if (q3.empty() == false) //Returns false if not empty
    P("false");
  ft::queue<int> q4;
  if (q4.empty() == true) //Returns true if empty
    P("true");
  q4 = q3;
  P("Size function on last queue");
  P(q3.size());
  P("");

  //Element access
  P("ELEMENT ACCESS");
  P("Accessing first and last element of following queue");
  show_queue<int>(q3);
  P(q3.front());
  P(q3.back());
  P("");

  //Modifiers
  P("MODIFIERS");
  P("Push element 8 at top of queue and check new size");
  q3.push(8);
  show_queue<int>(q3);
  P(q3.size());
  P("Removes first element of last queue and checks new size");
  q3.pop();
  show_queue<int>(q3);
  P(q3.size());
  P("");

  //Mon-member function overloads
  P("Non-member function overloads");
  ft::queue<int> qi1;
  ft::queue<int> qi2;
  ft::queue<int> qi3;
  qi1.push(4);
  qi1.push(4);
  qi1.push(4);
  qi1.push(4);
  qi2.push(4);
  qi2.push(4);
  qi2.push(4);
  qi2.push(4);
  qi3.push(6);
  qi3.push(6);
  qi3.push(6);
  qi3.push(6);
  P("Test whether following queues are equal");
  show_queue<int>(qi1);
  show_queue<int>(qi2);
  if (qi1 == qi2)
    P("YES");
  P("Test wether following queues are equal");
  show_queue<int>(qi1);
  show_queue<int>(qi3);
  if (qi1 != qi3)
    P("NO");
  P("Test whether first queue is smaller than second one");
  show_queue<int>(qi1);
  show_queue<int>(qi3);
  if (qi1 < qi3)
    P("YES");
  else
    P("NO");
  P("Test whether first queue is bigger than second one");
  show_queue<int>(qi3);
  show_queue<int>(qi1);
  if (qi3 > qi1)
    P("YES");
  P("Test whether first queue is bigger than or equal to first one");
  show_queue<int>(qi1);
  show_queue<int>(qi2);
  if (qi1 >= qi2)
    P("YES");
  P("Test whether first queue is smaller than or equal to first one");
  show_queue<int>(qi1);
  show_queue<int>(qi2);
  if (qi1 <= qi2)
    P("YES");
  P("");

  P("Const queue");
  const ft::queue<int> cq(qi1);
  P("Const queue calling size, pop and trying to change front value");
  P(cq.size());
  // cq.pop(); //Should create compilation error
  // cq.front() = 9; //Should create compilation error

  P("Error management");
  ft::queue<int> eq;
  P("Trying to pop and show front in empty container"); //Cannot be tested with empty iterator, because container cannot make iterator point on nothing
  eq.front();
  eq.pop();
  P("");
  }
  if (argc != 2)
    P("Choose one of following containers; list, map, queue, stack, vector");
}
