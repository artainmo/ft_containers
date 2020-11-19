#include "../main.hpp"

//MY

template<typename T>
void show_stack(ft::stack<T> s, ofstream fd)
{
  while (!s.empty())
  {
    fd << s.top();
    s.pop(); //To iterate over whole stack you have to destoy it and start from end to start
  }
  fd << std::endl;
}

//REAL

template<typename T>
void show_stack(stack<T> s, ofstream fd)
{
  while (!s.empty())
  {
    fd << s.top();
    s.pop(); //To iterate over whole stack you have to destoy it and start from end to start
  }
  fd << std::endl;
}

void test_stack(ofstream fd_w)
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

  P("Error management");
  ft::stack<int> es;
  P("Trying to pop and show front in empty container"); //Cannot be tested with empty iterator, because container cannot make iterator point on nothing
  es.top();
  es.pop();
  P("");
}
