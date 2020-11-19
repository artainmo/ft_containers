#include "../main.hpp"

//MY

template<typename T>
void show_queue(ft::queue<T> s, ofstream fd)
{
  while (!s.empty())
  {
    fd << s.front();
    s.pop(); //To iterate over whole queue you have to destroy it, reading it from start to end
  }
  fd << std::endl;
}

//REAL

template<typename T>
void show_queue(queue<T> s, ofstream fd)
{
  while (!s.empty())
  {
    fd << s.front();
    s.pop(); //To iterate over whole queue you have to destroy it, reading it from start to end
  }
  std::cout << std::endl;
}

void test_queue(ofstream fd_w)
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

  P("Error management");
  ft::queue<int> eq;
  P("Trying to pop and show front in empty container"); //Cannot be tested with empty iterator, because container cannot make iterator point on nothing
  eq.front();
  eq.pop();
  P("");
}
