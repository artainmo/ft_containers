#include "../main.hpp"

//MY

template<typename T>
void show_vector(ft::vector<T> &l, std::ofstream fd)
{
  unsigned int m;

  m = 0;
  while(m < l.size())
  {
    fd << l[m];
    m++;
  }
  fd << std::endl;
}

template<typename T>
void show_vector2(ft::vector<T> &l, std::ofstream fd) //Use at function instead of [] operator
{
  unsigned int m;

  m = 0;
  while(m < l.size())
  {
    fd << l.at(m);
    m++;
  }
  fd << std::endl;
}

//REAL

template<typename T>
void show_vector(vector<T> &l, std::ofstream fd)
{
  unsigned int m;

  m = 0;
  while(m < l.size())
  {
    fd << l[m];
    m++;
  }
  fd << std::endl;
}

template<typename T>
void show_vector2(vector<T> &l, std::ofstream fd) //Use at function instead of [] operator
{
  unsigned int m;

  m = 0;
  while(m < l.size())
  {
    fd << l.at(m);
    m++;
  }
  fd << std::endl;
}

void test_vector(std::ofstream fd_w)
{
  P("\n~~~~~~~VECTOR~~~~~~~~\n");
  //Contruction and iterators
  write("CONSTRUCTORS", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~1: Construction of empty vector container and showing its size", fd_w);
  ft::vector<int> v1;
  write(v1.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~2: Contructing a filled vector and showing its content using an iterator", fd_w);
  ft::vector<int> v2((unsigned int)10, 5); //Indicate unsigned int is necessary otherwise it will use the templated inputiterator (int, int) function
  show_vector<int>(v2, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~3: Create a ranged vector and show its content", fd_w);
  ft::vector<int>::iterator vi = v2.begin();
  ++vi;
  ++vi;
  ++vi;
  ft::vector<int> v3(vi, v2.end());
  show_vector<int>(v3, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~4: Create a copy of last vector and show content", fd_w);
  ft::vector<int> v4(v3);
  show_vector<int>(v4, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~5: Assign last vector to first one and show content", fd_w);
  v1 = v4;
  show_vector<int>(v1, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~", fd_w);

  write("~ITERATORS", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~To show the constructed and assigned vector containers, iterators were used", fd_w); //test iteators!!!
  write("~6: Create a ranged vector and show its content using reverse iterators", fd_w); //test iterators!!!!
  ft::vector<int> v5(vi, v2.end());

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~", fd_w);

  //Capacity
  write("CAPACITY", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~7: Size function on vector", fd_w);
  show_vector<int>(v4, fd_w);
  write(v4.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~8: Max size function on vector", fd_w); //Size is stored in unsigned int thus, max_size is unsigned int
  write(v4.max_size(), fd_w); //MAx unisgned int because size is stored in unsigned int
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~9: Resizing vector vector 3 bigger", fd_w);
  v3.resize(v3.size() + 3, 9);
  show_vector<int>(v3, fd_w);
  write("~10: Resizing vector vector two smaller", fd_w);
  v3.resize(v3.size() - 2, 9);
  show_vector<int>(v3, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  P("~11: Resize and show size, capacity and content");
  v1.resize(99, 9);
  write(v1.size(), fd_w);
  write(v1.capacity(), fd_w);
  show_vector<int>(v1, fd_w);
  write("~12: Resize and show size, capacity and content", fd_w);
  v1.resize(100, 8); //Because of additional /0 at end array, size should be increased
  write(v1.size(), fd_w);
  write(v1.capacity(), fd_w);
  show_vector<int>(v1, fd_w);
  write("~13: Resize and show size, capacity and content", fd_w);
  v1.resize(5, 9);
  write(v1.size(), fd_w);
  write(v1.capacity(), fd_w);
  show_vector<int>(v1, fd_w);
  write("~14: Resize and show size, capacity and content", fd_w);
  v1.resize(6, 6);
  write(v1.size(), fd_w);
  write(v1.capacity(), fd_w);
  show_vector<int>(v1, fd_w);
  write("~15: Resize and show size, capacity and content", fd_w);
  v1.resize(150, 9);
  write(v1.size(), fd_w);
  write(v1.capacity(), fd_w);
  show_vector<int>(v1, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~16: Empty function on last vector", fd_w);
  if (v4.empty() == false) //Returns false if not empty
    P("false");
  else
    P("true");
  v1.clear();
  write("~17: Empty function on cleared vector", fd_w);
  if (v1.empty() == true) //Returns true if empty
    write("true", fd_w);
  else
    write("true", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.
  v1 = v4;
  write("~18: Reserve less space than already in place and show content, capcity, size", fd_w); //Reserved space should then not be reduced but stay the same
  v4.reserve(v4.capacity() - 10);
  show_vector<int>(v4, fd_w);
  write(v4.capacity(), fd_w);
  write(v4.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~19: Reserve more space than already in place and show content, capacity, size", fd_w);
  v4.reserve(v4.capacity() + 10);
  show_vector<int>(v4, fd_w);
  write(v4.capacity(), fd_w);
  write(v4.size(), fd_w);
  write("~", fd_w);

  write("~ELEMENT ACCESS", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~20: Showing the following vector using the [] operator", fd_w);
  show_vector<int>(v4, fd_w);
  write("~21: Showing the following vector using the at function", fd_w);
  show_vector2<int>(v4, fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~22: Accessing first element of following vector after inserting at begin", fd_w);
  v4.insert(v4.begin(), 7);
  v4.push_back(9);
  show_vector<int>(v4, fd_w);
  write(v4.front(), fd_w);
  write("~23: Accessing last element of following vector after push_back at end", fd_w);
  write(v4.back(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~", fd_w);

  //Modifiers
  P("MODIFIERS");
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~24: Fill the last vector container with value 7, show and check size", fd_w);
  v4.assign((unsigned int)12, 7); //If you do not cast it to an unsigned int, it will enter the other assign function with two int parameters
  show_vector<int>(v4, fd_w);
  write(v4.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~25: Assign a range of elements from second vector to the last vector, show and check size", fd_w);
  vi = v2.begin();
  ++vi;
  ++vi;
  v4.assign<ft::vector<int>::iterator >(vi, v2.end());
  show_vector<int>(v4, fd_w);
  write(v4.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~26: Insert element 8 at end of last vector, show and check new size", fd_w);
  v4.push_back(8);
  show_vector<int>(v4, fd_w);
  write(v4.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~27: Removes element 8 at end of last vector, show and check new size", fd_w);
  v4.pop_back();
  show_vector<int>(v4, fd_w);
  write(v4.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~28: Inserts element 3 in third place vector, show, check new size and capacity", fd_w);
  v4.push_back(2);
  vi = v4.begin();
  ++vi;
  ++vi;
  v4.insert(vi, 3);
  show_vector<int>(v4, fd_w);
  write(v4.size(), fd_w);
  write(v4.capacity(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~29: Inserts 3 elements of 4, show and checks new size", fd_w);
  show_vector<int>(v4, fd_w);
  v4.insert(v4.begin(), (unsigned int)3, 4);
  show_vector<int>(v4, fd_w);
  write(v4.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~30: Inserts a range at third position, the whole vector 3 (4 elements of one), show and checks new size", fd_w);
  vi = v4.begin();
  ++vi;
  ++vi;
  v3.assign((unsigned int)4, 1);
  v4.insert<ft::vector<int>::iterator >(vi, v3.begin(), v3.end());
  show_vector<int>(v4, fd_w);
  write(v4.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~31: Erases the first and last element, show and check size", fd_w);
  v4.erase(v4.begin());
  v4.erase(v4.end());
  show_vector<int>(v4, fd_w);
  write(v4.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~32: Erase the whole last vector besides two first and last elements, show and check size", fd_w);
  ft::vector<int>::iterator vl = v4.begin();
  vi = v4.end();
  ++vl;
  ++vl;
  --vi;
  --vi;
  v4.erase(vl, vi);
  show_vector<int>(v4, fd_w);
  write(v4.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~33: Swap content between two vectors, show and check size", fd_w);
  v1.push_back(9);
  v2.push_back(6);
  v1.swap(v2);
  show_vector<int>(v1, fd_w);
  write(v1.size(), fd_w);
  show_vector<int>(v2, fd_w);
  write(v2.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~34: Clearing the last vector and checking its size", fd_w);
  v1.clear();
  write(v1.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~", fd_w);

  // Non-member function overloads
  write("~Non-member function overloads", fd_w);
  ft::vector<int> vi1((unsigned int)4,4);
  ft::vector<int> vi2((unsigned int)4,4);
  ft::vector<int> vi3((unsigned int)4,6);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~35: Test whether following vectors are equal", fd_w);
  if (vi1 == vi2)
    write("YES", fd_w);
  else
    write("NO", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~36: Test whether following vectors are not equal", fd_w);
  if (vi1 != vi3)
    write("NO", fd_w);
  else
    write("NO", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~36: Test whether first vector is smaller than second one", fd_w);
  if (vi1 < vi2)
    write("YES", fd_w);
  else
    write("NO", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~36: Test whether first vector is bigger than second one", fd_w);
  if (vi3 > vi1)
    write("YES", fd_w);
  else
    write("NO", fd_w)
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~37: Test whether first vector is bigger than or equal to first one", fd_w);
  if (vi1 >= vi2)
    write("YES", fd_w);
  else
    write("NO", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~38: Test whether first vector is smaller than or equal to first one", fd_w);
  if (vi1 <= vi2)
    write("YES", fd_w);
  else
    write("NO", fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~39: We will swap the content of the following two vectors, show and check size", fd_w);
  swap(vi1, vi3);
  show_vector<int>(vi1, fd_w);
  write(vi1.size(), fd_w);
  show_vector<int>(vi3, fd_w);
  write(vi3.size(), fd_w);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  write("~", fd_w, fd_w);

  // P("Error management");
  // ft::vector<int> ev;
  // P("Trying to pop and show front, back in empty container"); //Cannot be tested with empty iterator, because container cannot make iterator point on nothing
  // ev.pop_back();
  // ev.front();
  // ev.back();
  // P("~");
}
