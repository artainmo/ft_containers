#include "../main.hpp"

//MY LIST

template<typename T>
void show_list(ft::list<T> &l, ofstream fd)
{
  unsigned int m;
  typename ft::list<T>::iterator i = l.begin(); //Typename to indicate no ambiguity by telling compiler following is a type, is necessary because object creation depends on template parameter

  m = 0;
  while(m < l.size())
  {
    m++;
    fd << *i;
    if (m < l.size())
      ++i;
  }
  fd << std::endl;
}

template<typename T>
void show_list_reverse(ft::list<T> &l, ofstream fd) //Not in reverse order but using a reverse iterator
{
  unsigned int m;
  typename ft::list<T>::reverse_iterator i = l.rend();

  m = 0;
  while(m < l.size())
  {
    m++;
    fd << *i;
    if (m < l.size())
      --i;
  }
  fd << std::endl;
}

template<typename T>
void reverse_list(ft::list<T> &l, ofstream fd) //Read and show list in reverse order
{
  unsigned int m;
  typename ft::list<T>::iterator i = l.end();

  m = 0;
  while(m < l.size())
  {
    m++;
    fd << *i;
    if (m < l.size())
      --i;
  }
  fd << std::endl;
}

//REAL LIST

template<typename T>
void show_list(list<T> &l, ofstream fd)
{
  unsigned int m;
  typename list<T>::iterator i = l.begin(); //Typename to indicate no ambiguity by telling compiler following is a type, is necessary because object creation depends on template parameter

  m = 0;
  while(m < l.size())
  {
    m++;
    fd << *i;
    if (m < l.size())
      ++i;
  }
  fd << std::endl;
}

template<typename T>
void show_list_reverse(list<T> &l, ofstream fd) //Not in reverse order but using a reverse iterator
{
  unsigned int m;
  typename list<T>::reverse_iterator i = l.rend();

  m = 0;
  while(m < l.size())
  {
    m++;
    fd << *i;
    if (m < l.size())
      --i;
  }
  fd << std::endl;
}

template<typename T>
void reverse_list(list<T> &l, ofstream fd) //Read and show list in reverse order
{
  unsigned int m;
  typename list<T>::iterator i = l.end();

  m = 0;
  while(m < l.size())
  {
    m++;
    fd << *i;
    if (m < l.size())
      --i;
  }
  fd << std::endl;
}

void list_test(ofstream fd_w)
{
  write("~~~~~~~LIST~~~~~~~~\n", fd_w);
  write("~CONSTRUCTORS", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~1: Construction of empty list container and showing its size", fd_w);
  ft::list<int> l1;
  write(l1.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~2: Contructing a filled list and showing its content using iterators", fd_w);
  ft::list<int> l2((unsigned int)10, 5); //Indicate unsigned int is necessary otherwise it will use the templated inputiterator (int, int) function
  show_list<int>(l2, fd_w);
  write("~3: Contructing a filled list and showing its content reading backward", fd_w);
  reverse_list<int>(l2, fd_w); //To see if backwards reading works properly
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~4: Create a ranged list and show its content", fd_w);
  ft::list<int>::iterator i = l2.begin();
  ++i;
  ++i;
  ++i;
  ft::list<int> l3(i, l2.end());
  show_list<int>(l3, fd_w);
  write("~5: Create a ranged list and show its content reading backwards", fd_w);
  reverse_list<int>(l3, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~6: Create a copy of last list and show content using reverse iterator", fd_w);
  ft::list<int> l4(l3);
  show_list_reverse<int>(l4, fd_w);
  write("~7: Create a copy of last list and show content backward", fd_w);
  reverse_list<int>(l4, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~8: Assign last list to first one and show content with reverse iterator", fd_w);
  l1 = l4;
  show_list_reverse<int>(l1, fd_w);
  write("~9: Assign last list to first one and show content backwards", fd_w);
  reverse_list<int>(l1, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~", fd_w);

  //Capacity
  write("~CAPACITY", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~10: Empty function on last list", fd_w);
  if (l4.empty() == false) //Returns false if not empty
    write("false", fd_w);
  else
    write("true", fd_w);
  P("~11: Size function on cleared  list");
  l1.clear();
  write(l1.size(), fd_w);
  write("~12: Empty function on cleared list", fd_w);
  if (l1.empty() == true) //Returns true if empty
    write("true", fd_w);
  else
    write("false", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  l1 = l4;
  write("~13: Max size function on last list", fd_w);
  write(l4.max_size(), fd_w);
  write("~", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  //Element access
  write("~ELEMENT ACCESS", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~14: Push front in list and showing result", fd_w);
  l4.push_front(7);
  show_list<int>(l4, fd_w);
  write("~15: Push front in list and showing result reading backwards", fd_w);
  reverse_list<int>(l4, fd_w);
  write("~16: Push back in list and showing result", fd_w);
  l4.push_back(9);
  show_list<int>(l4, fd_w);
  write("~17: Push back in list and showing result reading backwards", fd_w);
  reverse_list<int>(l4, fd_w);
  write("~18: Accessing first element of list", fd_w);
  write(l4.front(), fd_w);
  write("~19: Accessing last element of list", fd_w);
  write(l4.back(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~", fd_w);

  //Modifiers
  write("~MODIFIERS", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~20: Fill the last list container with value 7 and show", fd_w);
  l4.assign((unsigned int)12, 7); //If you do not cast it to an unsigned int, it will enter the other assign function with two int parameters
  show_list<int>(l4, fd_w);
  write("~21: Fill the last list container with value 7 and show backwards", fd_w);
  reverse_list<int>(l4, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~22: Assign a range of elements from second list to the last list and show result", fd_w);
  l4.assign(i, l2.end());
  show_list<int>(l4, fd_w);
  write("~23: Assign a range of elements from second list to the last list and show result backwards", fd_w);
  reverse_list<int>(l4, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  l4.push_front(8);
  write("~24: Insert element 8 at beginning of last list and show", fd_w);
  show_list<int>(l4, fd_w);
  write("~25: Insert element 8 at beginning of last list and show backwards", fd_w);
  reverse_list<int>(l4, fd_w);
  write("~26: Insert element 8 at beginning of last list and check new size", fd_w);
  write(l4.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  l4.pop_front();
  write("~27: Removes element 8 at begin of last list and show", fd_w);
  show_list<int>(l4, fd_w);
  write("~28: Removes element 8 at begin of last list and show backward", fd_w);
  reverse_list<int>(l4, fd_w);
  write("~29: Removes element 8 at begin of last list and check new size", fd_w);
  write(l4.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  l4.push_back(8);
  write("~30: Insert element 8 at end of last list and show", fd_w);
  show_list<int>(l4, fd_w);
  write("~31: Insert element 8 at end of last list and show backwards", fd_w);
  reverse_list<int>(l4, fd_w);
  write("~32: Insert element 8 at end of last list and check new size", fd_w);
  write(l4.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  l4.pop_back();
  write("~33: Removes element 8 at end of last list and show", fd_w);
  show_list<int>(l4, fd_w);
  write("~34: Removes element 8 at end of last list and show backwards", fd_w);
  reverse_list<int>(l4, fd_w);
  write("~35: Removes element 8 at end of last list and check new size", fd_w);
  write(l4.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~36: Inserts element 3 in third place list and show", fd_w);
  i = l4.begin();
  ++i;
  ++i;
  l4.insert(i, 3);
  show_list<int>(l4, fd_w);
  write("~37: Inserts element 3 in third place list and show backwards", fd_w);
  reverse_list<int>(l4, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~38: Inserts 3 elements of 4 and show", fd_w);
  l4.insert(i, (unsigned int)3, 4);
  show_list<int>(l4, fd_w);
  write("~39: Inserts 3 elements of 4 and show backwards", fd_w);
  reverse_list<int>(l4, fd_w);
  write("~40: Inserts 3 elements of 4 and checks new size", fd_w);
  write(l4.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~41: Inserts a range, the whole list 3, and shows", fd_w);
  l3.assign((unsigned int)4, 9);
  l4.insert<ft::list<int>::iterator >(i, l3.begin(), l3.end());
  show_list<int>(l4, fd_w);
  write("~42: Inserts a range, the whole list 3, and shows backwards", fd_w);
  reverse_list<int>(l4, fd_w);
  write("~43: Inserts a range, the whole list 3, and shows size", fd_w);
  write(l4.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~44: Erases the element 5 following the 9 and show", fd_w);
  l4.erase(i);
  show_list<int>(l4, fd_w);
  write("~45: Erases the element 5 following the 9 and show backwards", fd_w);
  reverse_list<int>(l4, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~46: Erase the whole non-5 range and show", fd_w);
  ft::list<int>::iterator l = l4.begin();
  ++l;
  ++l;
  --i; //If you do not do this it will point on the just erased value
  l4.erase(l, i);
  show_list<int>(l4, fd_w);
  write("~47: Erase the whole non-5 range and show backwards", fd_w);
  reverse_list<int>(l4, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  l1.push_back(9);
  l2.push_back(6);
  l1.swap(l2);
  write("~48: Swap content between two lists and show", fd_w);
  show_list<int>(l1, fd_w);
  show_list<int>(l2, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~49: Resizing list one bigger and show", fd_w);
  l3.resize(l3.size() + 1, 9);
  show_list<int>(l3, fd_w);
  write("~50: Resizing list two smaller and show", fd_w);
  l3.resize(l3.size() - 2, 9);
  show_list<int>(l3, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~51: Clearing the last list and checking its size", fd_w);
  l1.clear();
  write(l1.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~", fd_w);

  //Operations
  write("~OPERATIONS", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~52: Here we will splice, list 3 into list 4 and show", fd_w);
  l4.splice(l4.begin(), l3);
  show_list<int>(l3, fd_w);
  show_list<int>(l4, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~53: Here we will splice the first element from list 2 into list 4 at second position", fd_w);
  i = l2.begin();
  l = l4.begin();
  ++l;
  l4.splice(l, l2,i);
  show_list<int>(l2, fd_w);
  show_list<int>(l4, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~54: Here we will splice a range from list 2 to 4 and show", fd_w);
  ++i; //Because the prior position got erased we have to increment it
  ft::list<int>::iterator m = i;
  ++m;
  ++m;
  ++m;
  l4.splice(l, l2,i, m);
  show_list<int>(l2, fd_w);
  show_list<int>(l4, fd_w);
  write("~55: Here we will splice a range from list 2 to 4 and show backwards", fd_w);
  reverse_list<int>(l2, fd_w);
  reverse_list<int>(l4, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~56: Here we will remove all the 5s in the last list and show", fd_w);
  l4.remove(5);
  show_list<int>(l4, fd_w);
  write("~57: Here we will remove all the 5s in the last list and show backwards", fd_w);
  reverse_list<int>(l4, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~58: Here we will remove elements 8 from following list based on a boolean function", fd_w);
  l4.push_front(8);
  l4.push_back(8);
  l4.remove_if(remove_if_test<int>);
  show_list<int>(l4, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~59: Here we will eliminate all duplicate values from the following list", fd_w);
  l4.push_front(8);
  l4.push_back(8);
  l4.unique();
  show_list<int>(l4, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~60: Here we will eliminate all numbers that are equal to one plus the prior number in last list based on a boolean function", fd_w);
  l4.unique(unique_test<int>);
  show_list<int>(l4, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~61: Here we will merge list 2 into list 4, list 2 will become non-existant", fd_w);
  l4.merge(l2);
  show_list<int>(l2, fd_w);
  show_list<int>(l4, fd_w);
  write("~62: Here we will merge list 2 into list 4, show in reverse", fd_w);
  reverse_list<int>(l4, fd_w);
  write("~63: Here we will merge list 2 into list 4, check size", fd_w);
  write(l4.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~64: Here we will merge in list 4 the list 2 in an ordered way, from biggest to smallest", fd_w); //Both containers should already be ordered
  l2.clear();
  l2.push_back(9);
  l2.push_back(8);
  l2.push_back(6);
  l2.push_back(3);
  l4.pop_back();
  l4.push_front(9);
  l4.merge(l2, merge_test<int>);
  show_list<int>(l2, fd_w);
  show_list<int>(l4, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~66: Here we will sort the following list and show", fd_w);
  l4.push_back(9);
  l4.push_back(3);
  l4.push_front(3);
  l4.push_front(6);
  l4.sort();
  show_list<int>(l4, fd_w);
  write("~67: Here we will sort the following list and show backwards", fd_w);
  reverse_list<int>(l4, fd_w);
  write("~68: Here we will sort the following list and check size", fd_w);
  write(l4.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~69: Here we will sort the last list based on a function that sorts in reverse", fd_w);
  l4.sort(sort_test<int>);
  show_list<int>(l4, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~70: Here we will directly reverse the list and show", fd_w);
  l4.reverse();
  show_list<int>(l4, fd_w);
  write("~71: Here we will directly reverse the list and show backwards", fd_w);
  reverse_list<int>(l4, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~", fd_w);

  //Non-member function overloads
  write("~Non-member function overloads", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  ft::list<int> li1((unsigned int)4,4);
  ft::list<int> li2((unsigned int)4,4);
  ft::list<int> li3((unsigned int)4,6);
  write("~72: Test whether following lists are equal", fd_w);
  if (li1 == li2)
    write("YES", fd_w);
  else
    write("NO", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~73: Test whether following lists are equal", fd_w);
  if (li1 != li3)
    write("YES", fd_w);
  else
    write("NO", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~74: Test whether first list is smaller than second one", fd_w);
  if (li1 < li2)
    write("YES", fd_w);
  else
    write("NO", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~75: Test whether first list is bigger than second one", fd_w);
  if (li3 > li1)
    write("YES", fd_w);
  else
    write("NO", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~76: Test whether first list is bigger than or equal to first one", fd_w);
  if (li1 >= li2)
    write("YES", fd_w);
  else
    write("NO", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~77: Test whether first list is smaller than or equal to first one", fd_w);
  if (li1 <= li2)
    write("YES", fd_w);
  else
    write("NO", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~78: We will swap the content of the following two lists", fd_w);
  swap(li1, li3);
  show_list<int>(li1, fd_w);
  show_list<int>(li3, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~", fd_w);

  // P("Error management");
  // //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ft::list<int> el;
  // P("Trying to pop and show front, back in empty container"); //Cannot be tested with empty iterator, because container cannot make iterator point on nothing
  // el.pop_front();
  // el.pop_back();
  // el.front();
  // el.back();
  // //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // P("~");
}
