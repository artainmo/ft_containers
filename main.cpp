#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "List/list.hpp"
#include "Vector/vector.hpp"
#include <list>
#include <cmath>
#include "Map/map.hpp"
#include <map>
#include <stack>
#include "Stack/stack.hpp"
#include <queue>
#include "Queue/queue.hpp"
void test_list();
void test_vector();
void test_map();
void test_stack();
void test_queue();
int main()
{
test_list();
test_vector();
test_map();
test_stack();
test_queue();
}
void test_queue()
{

	std::cout << "******STARTING TO TEST ft::queue******" << std::endl;
std::cout << "----------STL_PUSH_POP-----------" << std::endl;
{
  std::queue<int> myqueue;



 for (size_t i = 19; i <= 21; i++)
    myqueue.push (i);
  std::cout << "myqueue contains: ";
  while (!myqueue.empty())
  {
    std::cout << ' ' << myqueue.front();
    myqueue.pop();
  }
  std::cout << '\n';
}
std::cout << "----------PUSH_POP-----------" << std::endl;
{
  ft::queue<int> myqueue;



 for (size_t i = 19; i <= 21; i++)
    myqueue.push (i);

  std::cout << "myqueue contains: ";
  while (!myqueue.empty())
  {
    std::cout << ' ' << myqueue.front();
    myqueue.pop();
  }
  std::cout << '\n';
}

std::cout << "----------STL_FRONT_BACK1-----------" << std::endl;
{
	 std::queue<int> myqueue;

  myqueue.push(12);
  myqueue.push(75);   // this is now the back

  myqueue.back() -= myqueue.front();

  std::cout << "myqueue.back() is now " << myqueue.back() << '\n';

}
std::cout << "----------MINE_FRONT_BACK1-----------" << std::endl;
{
	 ft::queue<int> myqueue;

  myqueue.push(12);
  myqueue.push(75);   // this is now the back

  myqueue.back() -= myqueue.front();

  std::cout << "myqueue.back() is now " << myqueue.back() << '\n';

}

std::cout << "----------STL_FRONT_BACK2-----------" << std::endl;
{
	  std::queue<int> myqueue;

  myqueue.push(77);
  myqueue.push(16);

  myqueue.front() -= myqueue.back();    // 77-16=61

  std::cout << "myqueue.front() is now " << myqueue.front() << '\n';

}
std::cout << "----------MINE_FRONT_BACK2-----------" << std::endl;
{
	  ft::queue<int> myqueue;

  myqueue.push(77);
  myqueue.push(16);

  myqueue.front() -= myqueue.back();    // 77-16=61

  std::cout << "myqueue.front() is now " << myqueue.front() << '\n';

}
std::cout << "----------STL_SIZE-----------" << std::endl;
{
	  std::queue<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';

}
std::cout << "----------MINE_SIZE-----------" << std::endl;
{
	  ft::queue<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';

}

std::cout << "----------STL_EMPTY-----------" << std::endl;
{  std::queue<int> myqueue;
  int sum (0);

  for (int i=1;i<=10;i++) myqueue.push(i);

  while (!myqueue.empty())
  {
     sum += myqueue.front();
     myqueue.pop();
  }

  std::cout << "total: " << sum << '\n';
}
std::cout << "----------MINE_EMPTY-----------" << std::endl;
{
	  ft::queue<int> myqueue;
  int sum (0);

  for (int i=1;i<=10;i++) myqueue.push(i);

  while (!myqueue.empty())
  {
     sum += myqueue.front();
     myqueue.pop();
  }

  std::cout << "total: " << sum << '\n';

}
std::cout << "------------STL_REL_OPERATOR--------" << std::endl;
//TEST relational operators: tests from cplusplus.com
{

  std::list<int> a;
  a.push_back(10);
  a.push_back(20);
  a.push_back(30);
  std::list<int> b;
  b.push_back(10);
  b.push_back(20);
  b.push_back(30);
  std::list<int> c;
  c.push_back(30);
  c.push_back(20);
  c.push_back(10);
	std::queue<int, std::list<int> > d(a);
	std::queue<int, std::list<int> > e(b);
	std::queue<int, std::list<int> > f(c);
  if (d==e) std::cout << "a and b are equal\n";
  if (e!=f) std::cout << "b and c are not equal\n";
  if (e<f) std::cout << "b is less than c\n";
  if (f>e) std::cout << "c is greater than b\n";
  if (d<=e) std::cout << "a is less than or equal to b\n";
  if (d>=e) std::cout << "a is greater than or equal to b\n";

}
std::cout << "------------MINE_REL_OPERATOR--------" << std::endl;
{
  ft::list<int> a;
  a.push_back(10);
  a.push_back(20);
  a.push_back(30);
  ft::list<int> b;
  b.push_back(10);
  b.push_back(20);
  b.push_back(30);
  ft::list<int> c;
  c.push_back(30);
  c.push_back(20);
  c.push_back(10);
	ft::queue<int, ft::list<int> > d(a);
	ft::queue<int, ft::list<int> > e(b);
	ft::queue<int, ft::list<int> > f(c);
  if (d==e) std::cout << "a and b are equal\n";
  if (e!=f) std::cout << "b and c are not equal\n";
  if (e<f) std::cout << "b is less than c\n";
  if (f>e) std::cout << "c is greater than b\n";
  if (d<=e) std::cout << "a is less than or equal to b\n";
  if (d>=e) std::cout << "a is greater than or equal to b\n";
}
std::cout << "----------STL_CONSTRUCTORS-----------" << std::endl;
{
  std::list<int> mylist (2,200);         // list with 2 elements

  std::queue<int> first;                 // empty queue

  std::queue<int,std::list<int> > third; // empty queue with list as underlying container
  std::queue<int,std::list<int> > fourth (mylist);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';

}
std::cout << "----------MINE_CONSTRUCTORS-----------" << std::endl;
{
  ft::list<int> mylist ((unsigned int)2,200);         // list with 2 elements

  ft::queue<int> first;                 // empty queue

  ft::queue<int,ft::list<int> > third; // empty queue with list as underlying container
  ft::queue<int,ft::list<int> > fourth (mylist);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';
}
}
void test_stack()
{
	std::cout << "******STARTING TO TEST ft::stack******" << std::endl;
std::cout << "----------STL_CONSTRUCTORS-----------" << std::endl;
{
  std::vector<int> myvector ((unsigned int)2,200);        // vector with 2 elements

  std::stack<int> first;                    // empty stack

  std::stack<int,std::vector<int> > third;  // empty stack using vector
  std::stack<int,std::vector<int> > fourth (myvector);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';
}
std::cout << "----------MINE_CONSTRUCTORS-----------" << std::endl;
{
	  ft::vector<int> myvector ((unsigned int)2,200);        // vector with 2 elements
  ft::stack<int> first;                    // empty stack
  ft::stack<int,ft::vector<int> > third;  // empty stack using vector
  ft::stack<int,ft::vector<int> > fourth (myvector);
  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';
}
std::cout << "----------STL_SIZE-----------" << std::endl;
{
	  std::stack<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';

}

std::cout << "----------MINE_SIZE-----------" << std::endl;
{
	  ft::stack<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';

}

std::cout << "----------STL_EMPTY-----------" << std::endl;
{
	 std::stack<int> mystack;
  int sum (0);

  for (int i=1;i<=10;i++) mystack.push(i);

  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }

  std::cout << "total: " << sum << '\n';

}
std::cout << "----------MINE_EMPTY-----------" << std::endl;
{
	ft::stack<int> mystack;
  int sum (0);

  for (int i=1;i<=10;i++) mystack.push(i);

  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }

  std::cout << "total: " << sum << '\n';

}

std::cout << "----------STL_TOP-----------" << std::endl;
{
	 ft::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';

}
std::cout << "----------MINE_TOP-----------" << std::endl;
{ ft::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';
}
std::cout << "----------STL_PUSH_POP-----------" << std::endl;
{
	  std::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';

}
std::cout << "----------MINE_PUSH_POP-----------" << std::endl;
{
	  ft::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';

}
std::cout << "------------STL_REL_OPERATOR--------" << std::endl;
//TEST relational operators: tests from cplusplus.com
{

  std::list<int> a;
  a.push_back(10);
  a.push_back(20);
  a.push_back(30);
  std::list<int> b;
  b.push_back(10);
  b.push_back(20);
  b.push_back(30);
  std::list<int> c;
  c.push_back(30);
  c.push_back(20);
  c.push_back(10);
	std::stack<int, std::list<int> > d(a);
	std::stack<int, std::list<int> > e(b);
	std::stack<int, std::list<int> > f(c);
  if (d==e) std::cout << "a and b are equal\n";
  if (e!=f) std::cout << "b and c are not equal\n";
  if (e<f) std::cout << "b is less than c\n";
  if (f>e) std::cout << "c is greater than b\n";
  if (d<=e) std::cout << "a is less than or equal to b\n";
  if (d>=e) std::cout << "a is greater than or equal to b\n";

}
std::cout << "------------MINE_REL_OPERATOR--------" << std::endl;
{
  ft::list<int> a;
  a.push_back(10);
  a.push_back(20);
  a.push_back(30);
  ft::list<int> b;
  b.push_back(10);
  b.push_back(20);
  b.push_back(30);
  ft::list<int> c;
  c.push_back(30);
  c.push_back(20);
  c.push_back(10);
	ft::stack<int, ft::list<int> > d(a);
	ft::stack<int, ft::list<int> > e(b);
	ft::stack<int, ft::list<int> > f(c);
  if (d==e) std::cout << "a and b are equal\n";
  if (e!=f) std::cout << "b and c are not equal\n";
  if (e<f) std::cout << "b is less than c\n";
  if (f>e) std::cout << "c is greater than b\n";
  if (d<=e) std::cout << "a is less than or equal to b\n";
  if (d>=e) std::cout << "a is greater than or equal to b\n";
}

}


void test_map()
{
	std::cout << "******STARTING TO TEST ft::map******" << std::endl;
std::cout << "----------STL_INSERT-----------" << std::endl;
{
	std::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( std::pair<char,int>('a',100) );
  mymap.insert ( std::pair<char,int>('z',200) );

  std::pair<std::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( std::pair<char,int>('z',500) );
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }
    std::map<char,int>::iterator it = mymap.begin();
	 mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
  // third insert function version (range insertion):
  std::map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));

  // showing contents:
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
 std::cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}
std::cout << "----------MINE_INSERT-----------" << std::endl;
{
	ft::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( std::pair<char,int>('a',100) );
  mymap.insert ( std::pair<char,int>('z',200) );

  std::pair<ft::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( std::pair<char,int>('z',500) );
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }
  ft::map<char, int>::iterator it = mymap.begin();
 mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

  // third insert function version (range insertion):
  ft::map<char,int> anothermap;
  anothermap.insert(mymap.begin(), mymap.find('c'));

  // showing contents:
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
 std::cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}

std::cout << "----------STL_OPERATOR[]-----------" << std::endl;
{
	std::map<char,std::string> mymap;

  mymap['a']="an element";
  mymap['b']="another element";
  mymap['c']=mymap['b'];

  std::cout << "mymap['a'] is " << mymap['a'] << '\n';
  std::cout << "mymap['b'] is " << mymap['b'] << '\n';
  std::cout << "mymap['c'] is " << mymap['c'] << '\n';
  std::cout << "mymap['d'] is " << mymap['d'] << '\n';

  std::cout << "mymap now contains " << mymap.size() << " elements.\n";

}
std::cout << "----------MINE_OPERATOR[]-----------" << std::endl;
{
  ft::map<char,std::string> mymap;

  mymap['a']="an element";
  mymap['b']="another element";
  mymap['c']=mymap['b'];

  std::cout << "mymap['a'] is " << mymap['a'] << '\n';
  std::cout << "mymap['b'] is " << mymap['b'] << '\n';
  std::cout << "mymap['c'] is " << mymap['c'] << '\n';
  std::cout << "mymap['d'] is " << mymap['d'] << '\n';

  std::cout << "mymap now contains " << mymap.size() << " elements.\n";

}

std::cout << "----------STL_SIZE-----------" << std::endl;
{
	  std::map<char,int> mymap;
  mymap['a']=101;
  mymap['b']=202;
  mymap['c']=302;

  std::cout << "mymap.size() is " << mymap.size() << '\n';
}
std::cout << "----------MINE_SIZE-----------" << std::endl;
{
	ft::map<char,int> mymap;
  mymap['a']=101;
  mymap['b']=202;
  mymap['c']=302;

  std::cout << "mymap.size() is " << mymap.size() << '\n';
  }
std::cout << "----------STL_EMPTY-----------" << std::endl;
  {
	   std::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  while (!mymap.empty())
  {
    std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    mymap.erase(mymap.begin());
  }
  }
std::cout << "----------MINE_EMPTY-----------" << std::endl;
  {
	   std::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  while (!mymap.empty())
  {
    std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    mymap.erase(mymap.begin());
  }
  }
std::cout << "----------STL_SWAP-----------" << std::endl;
 {
	   std::map<char,int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);

  std::cout << "foo contains:\n";
  for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

 }
std::cout << "----------MINE_SWAP-----------" << std::endl;
 {
	   ft::map<char,int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);

  std::cout << "foo contains:\n";
  for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

 }

std::cout << "----------STL_ERASE-----------" << std::endl;
 {
	   std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

  it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

  mymap.erase ('c');                  // erasing by key

  it=mymap.find ('e');
  mymap.erase ( it, mymap.end() );    // erasing by range

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

 }
std::cout << "----------MINE_ERASE-----------" << std::endl;
{  ft::map<char,int> mymap;
  ft::map<char,int>::iterator it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

  it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

  mymap.erase ('c');                  // erasing by key

  it=mymap.find ('e');
  mymap.erase ( it, mymap.end() );    // erasing by range

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}
std::cout << "----------STL_KEY__COMP-----------" << std::endl;
{std::map<char,int> mymap;

  std::map<char,int>::key_compare mycomp = mymap.key_comp();

  mymap['a']=100;
  mymap['b']=200;
  mymap['c']=300;

  std::cout << "mymap contains:\n";

  char highest = mymap.rbegin()->first;     // key value of last element

  std::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );

  std::cout << '\n';
  }
std::cout << "----------STL_KEY__COMP-----------" << std::endl;
{
	ft::map<char,int> mymap;

  ft::map<char,int>::key_compare mycomp = mymap.key_comp();

  mymap['a']=100;
  mymap['b']=200;
  mymap['c']=300;

  std::cout << "mymap contains:\n";

  char highest = mymap.rbegin()->first;     // key value of last element

  ft::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );

  std::cout << '\n';
  }

std::cout << "----------STL_VALUE__COMP-----------" << std::endl;
 {
	  std::map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

  std::pair<char,int> highest = *mymap.rbegin();          // last element

  std::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );

 }
std::cout << "----------MINE_VALUE__COMP-----------" << std::endl;
 {
	  ft::map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

  std::pair<char,int> highest = *mymap.rbegin();          // last element

  ft::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );

 }
std::cout << "----------STL_COUNT-----------" << std::endl;
 {
	   std::map<char,int> mymap;
  char c;

  mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c='a'; c<'h'; c++)
  {
    std::cout << c;
    if (mymap.count(c)>0)
      std::cout << " is an element of mymap.\n";
    else
      std::cout << " is not an element of mymap.\n";
  }
 }
std::cout << "----------MINE_COUNT-----------" << std::endl;
 {
	   ft::map<char,int> mymap;
  char c;

  mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c='a'; c<'h'; c++)
  {
    std::cout << c;
    if (mymap.count(c)>0)
      std::cout << " is an element of mymap.\n";
    else
      std::cout << " is not an element of mymap.\n";
  }
 }
std::cout << "----------STL_LOWER__BOUND-----------" << std::endl;
{
	  std::map<char,int> mymap;
  std::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

}
std::cout << "----------MINE_LOWER__BOUND-----------" << std::endl;
{
	  ft::map<char,int> mymap;
  ft::map<char,int>::iterator itlow,itup;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;


  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)
  ft::map<char,int>::iterator s = itlow;
  ft::map<char,int>::iterator e = itup;
//  for (; s != itup; s++)
//	std::cout << s->first << std::endl;
  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

}

std::cout << "----------STL_EQUAL__RANGE-----------" << std::endl;
{
	 std::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
  ret = mymap.equal_range('b');

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';

}
std::cout << "----------MINE_EQUAL__RANGE-----------" << std::endl;
{
	 ft::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  std::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
  ret = mymap.equal_range('b');

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';

}
}

void test_vector()
{
	std::cout << "******STARTING TO TEST ft::vector******" << std::endl;
std::cout << "----------STL_CONSTRUCTORS-----------" << std::endl;
{
	  // constructors used in the same order as described above:
  std::vector<int> first;                                // empty vector of ints
  std::vector<int> second (4,100);                       // four ints with value 100
 std::vector<int> third (second.begin(),second.end());  // iterating through second
  std::vector<int> fourth (second);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};

  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are:";
  for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
    std::cout << "The contents of second are:";
  for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
      std::cout << "The contents of third are:";
  for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------MINE_CONSTRUCTORS-----------" << std::endl;
{
		  // constructors used in the same order as described above:
  ft::vector<int> first;                                // empty vector of ints
  ft::vector<int> second ((unsigned int)4,100);                       // four ints with value 100
  ft::vector<int> third (second.begin(),second.end());  // iterating through second
  ft::vector<int> fourth (second);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};

  ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are:";
  for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
      std::cout << "The contents of second are:";
  for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
      std::cout << "The contents of third are:";
    for (ft::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------STL_OPERATOR==-----------" << std::endl;
{
	  std::vector<int> foo (3,0);
  std::vector<int> bar (5,0);

  bar = foo;
  foo = std::vector<int>();

  std::cout << "Size of foo: " << int(foo.size()) << '\n';
  std::cout << "Size of bar: " << int(bar.size()) << '\n';
}
std::cout << "----------MINE_OPERATOR==-----------" << std::endl;
{
	  std::vector<int> foo (3,0);
  std::vector<int> bar (5,0);

  bar = foo;
  foo = std::vector<int>();

  std::cout << "Size of foo: " << int(foo.size()) << '\n';
  std::cout << "Size of bar: " << int(bar.size()) << '\n';
}

std::cout << "----------STL_REND_RBEGIN-----------" << std::endl;
{
	  std::vector<int> myvector (5);  // 5 default-constructed ints

  int i=0;

  std::vector<int>::reverse_iterator rit = myvector.rbegin();
  for (; rit!= myvector.rend(); ++rit)
    *rit = ++i;

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------MINE_REND_RBEGIN-----------" << std::endl;
{
	  ft::vector<int> myvector (5);  // 5 default-constructed ints

  int i=0;

  ft::vector<int>::reverse_iterator rit = myvector.rbegin();
  for (; rit!= myvector.rend(); ++rit)
    *rit = ++i;

  std::cout << "myvector contains:";
  for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------STL_SIZE-----------" << std::endl;
{
	  std::vector<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<10; i++) myints.push_back(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.insert (myints.end(),10,100);
  std::cout << "2. size: " << myints.size() << '\n';

  myints.pop_back();
  std::cout << "3. size: " << myints.size() << '\n';

}

std::cout << "----------MINE_SIZE-----------" << std::endl;
{  ft::vector<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<10; i++) myints.push_back(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.insert (myints.end(),(unsigned int)10,100);
  std::cout << "2. size: " << myints.size() << '\n';

  myints.pop_back();
  std::cout << "3. size: " << myints.size() << '\n';
}

std::cout << "----------STL_PUSH__BACK-----------" << std::endl;
{
  std::vector<int> myvector;


  for (int i = 19; i <= 42; i++)
    myvector.push_back(i);

  std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	std::cout << "vector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end() ; it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}
std::cout << "----------MINE_PUSH__BACK-----------" << std::endl;
{
  ft::vector<int> myvector;


  for (int i = 19; i <= 42; i++)
    myvector.push_back (i);
  std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	std::cout << "vector contains:";
	for (ft::vector<int>::iterator it=myvector.begin(); it != myvector.end() ; it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

std::cout << "----------STL_INSERT-----------" << std::endl;
{
	  std::vector<int> myvector (3,100);
  std::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  std::vector<int> anothervector (2,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());

  std::vector<int> vec;
  vec.push_back(19);
  vec.push_back(21);
  vec.push_back(42);
  myvector.insert (myvector.begin(), vec.begin(), vec.end()-1);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------MINE_INSERT-----------" << std::endl;
{
  ft::vector<int> myvector ((unsigned int)3,100);
  ft::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );
  myvector.insert (it,(unsigned int)2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  ft::vector<int> anothervector ((unsigned int)2,400);
  myvector.insert(it+2,anothervector.begin(),anothervector.end());

ft::vector<int> vec;
vec.push_back(19);
vec.push_back(21);
vec.push_back(42);
  myvector.insert (myvector.begin(), vec.begin(), vec.end()-1);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

std::cout << "----------STL_IT_OP[]_OP+-----------" << std::endl;
{
	    std::vector<int>v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
    int i;
  std::vector<int>::iterator itx = v1.begin();
    for(i=0;i<5;++i)
        std::cout << itx[i] << " ";
	std::cout << std::endl;
	std::vector<int>::iterator it = v1.begin() + 1;
	std::cout << it[-1] << std::endl;
	it = v1.end() - 1;
	std::cout << it[-1] << std::endl;
	it -= 4;
	std::cout << it[0] << std::endl;
	it += 2;
	std::cout << it[0] << std::endl;

}
std::cout << "----------MINE_IT_OP[]_OP+_OP-_OP+=_OP-=()-----------" << std::endl;
{
	    ft::vector<int>v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
    int i;

	ft::vector<int>::iterator itx = v1.begin();
    for(i=0;i<5;++i)
        std::cout << itx[i] << " ";
	std::cout << std::endl;
	ft::vector<int>::iterator it = v1.begin() + 1;
	std::cout << it[-1] << std::endl;
	it = v1.end() - 1;
	std::cout << it[-1] << std::endl;
	it -= 4;
	std::cout << it[0] << std::endl;
	it += 2;
	std::cout << it[0] << std::endl;

}
std::cout << "----------STL_RESIZE-----------" << std::endl;
{
	 std::vector<int> myvector;

  // set some initial content:
  for (int i=1;i<10;i++) myvector.push_back(i);

  myvector.resize(5);
  myvector.resize(8,100);
  myvector.resize(12);

  std::cout << "myvector contains:";
  for (size_t i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

}
std::cout << "----------MINE_RESIZE-----------" << std::endl;
{
	ft::vector<int> myvector;
  // set some initial content:
  for (int i=1;i<10;i++) myvector.push_back(i);

  myvector.resize(5);
  myvector.resize(8,100);
  myvector.resize(12);

  std::cout << "myvector contains:";
  for (size_t i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}
std::cout << "----------STL_OP[]-----------" << std::endl;
{
	  std::vector<int> myvector (10);   // 10 zero-initialized elements

  size_t sz = myvector.size();

  // assign some values:
  for (unsigned i=0; i<sz; i++) myvector[i]=i;

  // reverse vector using operator[]:
  for (unsigned i=0; i<sz/2; i++)
  {
    int temp;
    temp = myvector[sz-1-i];
    myvector[sz-1-i]=myvector[i];
    myvector[i]=temp;
  }

  std::cout << "myvector contains:";
  for (unsigned i=0; i<sz; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

}
std::cout << "----------MINE_OP[]-----------" << std::endl;
{
	  ft::vector<int> myvector (10);   // 10 zero-initialized elements


  size_t sz = myvector.size();

  // assign some values:
  for (unsigned i=0; i<sz; i++) myvector[i]=i;

  // reverse vector using operator[]:
  for (unsigned i=0; i<sz/2; i++)
  {
    int temp;
    temp = myvector[sz-1-i];
    myvector[sz-1-i]=myvector[i];
    myvector[i]=temp;
  }

  std::cout << "myvector contains:";
  for (unsigned i=0; i<sz; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}
std::cout << "----------STL_EMPTY-----------" << std::endl;
{
	  std::vector<int> myvector;
  int sum (0);

  for (int i=1;i<=10;i++) myvector.push_back(i);

  while (!myvector.empty())
  {
     sum += myvector.back();
     myvector.pop_back();
  }

  std::cout << "total: " << sum << '\n';
}
std::cout << "----------MINE_EMPTY-----------" << std::endl;
{
	  ft::vector<int> myvector;
  int sum (0);

  for (int i=1;i<=10;i++) myvector.push_back(i);

  while (!myvector.empty())
  {
     sum += myvector.back();
     myvector.pop_back();
  }

  std::cout << "total: " << sum << '\n';
}
std::cout << "----------STL_FRONT-----------" << std::endl;
{
	  std::vector<int> myvector;

  myvector.push_back(78);
  myvector.push_back(16);

  // now front equals 78, and back 16

  myvector.front() -= myvector.back();

  std::cout << "myvector.front() is now " << myvector.front() << '\n';

}
std::cout << "----------MINE_FRONT-----------" << std::endl;
{
	  ft::vector<int> myvector;

  myvector.push_back(78);
  myvector.push_back(16);

  // now front equals 78, and back 16

  myvector.front() -= myvector.back();

  std::cout << "myvector.front() is now " << myvector.front() << '\n';

}
std::cout << "----------STL_RESERVE-----------" << std::endl;
{
  std::vector<int> foo;
  foo.reserve(19);
  std::cout << foo.capacity() << std::endl;
  foo.reserve(42);
  std::cout << foo.capacity() << std::endl;
}
std::cout << "----------MINE_RESERVE-----------" << std::endl;
{
  ft::vector<int> foo;
  foo.reserve(19);
  std::cout << foo.capacity() << std::endl;
  foo.reserve(42);
  std::cout << foo.capacity() << std::endl;
}
std::cout << "----------STL_AT-----------" << std::endl;
{
std::vector<int> myvector (10);   // 10 zero-initialized ints

  // assign some values:
  for (unsigned i=0; i<myvector.size(); i++)
    myvector.at(i)=i;

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector.at(i);
  std::cout << '\n';

}
std::cout << "----------MINE_AT-----------" << std::endl;
{
ft::vector<int> myvector (10);   // 10 zero-initialized ints

  // assign some values:
  for (unsigned i=0; i<myvector.size(); i++)
    myvector.at(i)=i;

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector.at(i);
  std::cout << '\n';

}
std::cout << "----------STL_ASSIGN-----------" << std::endl;
{
  std::vector<int> first;
  std::vector<int> second;
  std::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  std::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';
}
std::cout << "----------MINE_ASSIGN-----------" << std::endl;
{
  ft::vector<int> first;
  ft::vector<int> second;
  ft::vector<int> third;

  first.assign ((unsigned int)7,100);             // 7 ints with a value of 100

  ft::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';
}
std::cout << "----------STL_SWAP-----------" << std::endl;
{
	 std::vector<int> foo (3,100);   // three ints with a value of 100
  std::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';
}
std::cout << "----------MINE_SWAP-----------" << std::endl;
{
	ft::vector<int> foo ((unsigned int)3,100);   // three ints with a value of 100
  ft::vector<int> bar ((unsigned int)5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';
}
std::cout << "----------STL_NMO_REL_OP-----------" << std::endl;
{
std::vector<int> foo (3,100);   // three ints with a value of 100
  std::vector<int> bar (2,200);   // two ints with a value of 200

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

}
std::cout << "----------MINE_NMO_REL_OP-----------" << std::endl;
{
	ft::vector<int> foo ((unsigned int)3,100);   // three ints with a value of 100
  ft::vector<int> bar ((unsigned int)2,200);   // two ints with a value of 200

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

}
std::cout << "----------MINE_NMO_SWAP-----------" << std::endl;
{
  std::vector<int> foo ((unsigned int)3,100);   // three ints with a value of 100
  std::vector<int> bar ((unsigned int)5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (std::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "bar contains:";
  for (std::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------MINE_NMO_SWAP-----------" << std::endl;
{
  ft::vector<int> foo ((unsigned int)3,100);   // three ints with a value of 100
  ft::vector<int> bar ((unsigned int)5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "bar contains:";
  for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
}


// NEEDED FOR LIST TESTS.
// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

// comparison, not case sensitive.
bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};
void test_list()
{
	std::cout << "******STARTING TO TEST ft::list******" << std::endl;
	//Test front, back, push_front, push_back
std::cout << "----------STL_FRONT_BACK_PUSH__FRONT_PUSH__BACK---------" << std::endl;
	{
	int q = 4;
	//stl
	std::list<int> c;
	c.push_front(q);
	c.front() = 5;
	c.push_back(7);
	std::cout << c.back() << std::endl;
	std::cout << c.front() << std::endl;
	c.back() = 6;
	std::cout << c.front() << std::endl;
	std::cout << c.back() << std::endl;
	c.push_back(19);
	std::cout << c.front() << std::endl;
	std::cout << c.back() << std::endl;
//
std::cout << "----------MINE_FRONT_BACK_PUSH__FRONT_PUSH__BACK---------" << std::endl;
//
	//mine
	ft::list<int> b;
	b.push_front(q);
	b.front() = 5;
	b.push_back(7);
	std::cout << b.back() << std::endl;
	std::cout << b.front() << std::endl;
	b.back() = 6;
	std::cout << b.front() << std::endl;
	std::cout << b.back() << std::endl;
	b.push_back(19);
	std::cout << b.front() << std::endl;
	std::cout << b.back() << std::endl;
	}

std::cout << "----------STL_ITERATORS---------" << std::endl;
//TEST ITERATORS
{
std::list<int> c(5, 19);
std::list<int>::iterator it = c.begin();
std::list<int>::iterator its(it);

std::cout << *it << std::endl;
*it = 42;
if (it == its)
	std::cout << "1 equal" << std::endl;
if (it != its)
	std::cout << "1 inequal" << std::endl;
it++;
std::cout << *it << std::endl;

if (it == its)
	std::cout << "2 equal" << std::endl;
if (it != its)
	std::cout << "2 inequal" << std::endl;
std::cout << c.front() << std::endl;
std::cout << *--it << std::endl;
std::cout << "----------MINE_ITERATORS---------" << std::endl;
ft::list<int> b((unsigned int)5, 19);
ft::list<int>::iterator oui = b.begin();
ft::list<int>::iterator ou(oui);//test copy constructor
std::cout << *oui << std::endl;
*oui = 42; // test * assignation
if (oui == ou)//test 1 equality
	std::cout << "1 equal" << std::endl;
if (oui != ou)
	std::cout << "1 inequal" << std::endl;
oui++;//test operator++
std::cout << *oui << std::endl;
if (oui == ou)//test 2 operator==
	std::cout << "2 equal" << std::endl;
if (oui != ou)
	std::cout << "2 inequal" << std::endl;
std::cout << b.front() << std::endl;
std::cout << *--oui << std::endl;//Test operator * with --
}

std::cout << "----------STL_TEST_PAST-THE-END-ELEM_DESIGN---------" << std::endl;
//Testing past-the-end elem
{
std::list<int> lst((unsigned int)2, 19);
std::list<int>::iterator it;
it = lst.begin();
lst.push_back(42);
while(it != lst.end())
{
	std::cout << *it << std::endl;
	it++;
}
std::cout << *--it << std::endl;
std::cout << *--it << std::endl;
it = lst.end();

std::cout << *--it << std::endl;
std::cout << *--it << std::endl;
}

std::cout << "----------MINE_TEST_PAST-THE-END-ELEM_DESIGN---------" << std::endl;
{
ft::list<int> lst((unsigned int)2, 19);
ft::list<int>::iterator it;
it = lst.begin();
lst.push_back(42);
while(it != lst.end())
{
	std::cout << *it << std::endl;
	it++;
}
std::cout << *--it << std::endl;
std::cout << *--it << std::endl;
it = lst.end();

std::cout << *--it << std::endl;
std::cout << *--it << std::endl;
}


std::cout << "----------STL_REV_ITERATOR---------" << std::endl;
{
//Test reverse iterator

ft::list<int> mlst;
std::list<int> lst;

mlst.push_back(4);
mlst.push_back(5);
mlst.push_back(6);
lst.push_back(4);
lst.push_back(5);
lst.push_back(6);

ft::list<int>::reverse_iterator mitt = mlst.rend();
std::list<int>::reverse_iterator it = lst.rend();

ft::list<int>::reverse_iterator mit= mitt;
while (it != lst.rbegin())
{
	it--;
	std::cout << *it << std::endl;
}

std::cout << "----------MINE_REV_ITERATOR---------" << std::endl;

while (mit != mlst.rbegin())
{
	mit--;
	std::cout << *mit << std::endl;
}

}

std::cout << "----------STL_RANGE_CONSTRUCT---------" << std::endl;
//Test range constructor
{
std::list<int> lst;
lst.push_back(4);
lst.push_back(5);
lst.push_back(6);

std::list<int> mlst(lst.begin(), lst.end());
std::list<int>::iterator it = mlst.begin();
while (it != mlst.end())
	std::cout << *it++ << std::endl;
std::cout << "----------MINE_RANGE_CONSTRUCT---------" << std::endl;


ft::list<int> mylst;
mylst.push_back(4);
mylst.push_back(5);
mylst.push_back(6);

ft::list<int> Mlst(mylst.begin(), mylst.end());
ft::list<int>::iterator its = Mlst.begin();
while (its != Mlst.end())
	std::cout << *its++ << std::endl;
}

std::cout << "----------STL_RANGE_CONSTRUCT_WITH_REV_IT---------" << std::endl;
//TEST range constructor with reverse_iterator
{
std::list<int> lst;
lst.push_back(4);
lst.push_back(5);
lst.push_back(6);

std::list<int> mlst(lst.begin(), lst.end());
std::list<int>::reverse_iterator it = mlst.rbegin();
while (it != mlst.rend())
	std::cout << *it++ << std::endl;

// exit(0);
std::cout << "----------MINE_RANGE_CONSTRUCT_WITH_REV_IT---------" << std::endl;

ft::list<int> mylst;
mylst.push_back(4);
mylst.push_back(5);
mylst.push_back(6);
ft::list<int> Mlst(mylst.begin(), mylst.end());
ft::list<int>::reverse_iterator its = Mlst.rbegin();
while (its != Mlst.rend())
{
	std::cout << *its++ << std::endl;
}
}

std::cout << "----------STL_ASSIGN_1---------" << std::endl;
// Test assign with size and value
{
std::list<int> lst((unsigned int)4, 19);
std::list<int> olst;
olst.push_back(4);
olst.push_back(5);
lst.assign((unsigned int)2, 42);
std::list<int>::iterator it = lst.begin();
while (it != lst.end())
	std::cout << *it++ << std::endl;

std::cout << "----------MINE_ASSIGN_1---------" << std::endl;
ft::list<int> mlst((unsigned int)4, 19);
ft::list<int> molst;
molst.push_back(4);
molst.push_back(5);
mlst.assign((unsigned int)2, 42);
ft::list<int>::iterator mit = mlst.begin();
while (mit != mlst.end())
	std::cout << *mit++ << std::endl;
}

std::cout << "----------STL_ASSIGN_2---------" << std::endl;
//TEST ASSIGN WITH RANGE
	{
std::list<int> lst((unsigned int)4, 19);
std::list<int> olst;
olst.push_back(4);
olst.push_back(5);
lst.assign(olst.begin(), olst.end());
std::list<int>::iterator it = lst.begin();
while (it != lst.end())
	std::cout << *it++ << std::endl;

std::cout << "----------MINE_ASSIGN_2---------" << std::endl;
ft::list<int> mlst((unsigned int)4, 19);
std::list<int> molst;
molst.push_back(4);
molst.push_back(5);

mlst.assign(molst.begin(), molst.end());

ft::list<int>::iterator mit = mlst.begin();
while (mit != mlst.end())
	std::cout << *mit++ << std::endl;
}


std::cout << "----------STL_INSERT_0a---------" << std::endl;
//Test insert with 1 elem
{
	std::list<int> lst;
	ft::list<int> mylst;

	lst.push_back(4);
	lst.push_back(5);
	lst.push_back(6);
	mylst.push_back(4);
	mylst.push_back(5);
	mylst.push_back(6);

	lst.insert(lst.end(), 42);
	mylst.insert(mylst.end(), 42);
	std::list<int>::iterator it = lst.begin();
	ft::list<int>::iterator mit = mylst.begin();
	while (it != lst.end())
		std::cout << *it++ << std::endl;
std::cout << "----------MINE_INSERT_0a---------" << std::endl;
	while (mit != mylst.end())
		std::cout << *mit++ << std::endl;
	lst.insert(++lst.begin(), 19);
	mylst.insert(++mylst.begin(), 19);
	it = lst.begin();
	mit = mylst.begin();
std::cout << "----------STL_INSERT_0b---------" << std::endl;
	while (it != lst.end())
		std::cout << *it++ << std::endl;
std::cout << "----------MINE_INSERT_0b---------" << std::endl;
	while (mit != mylst.end())
		std::cout << *mit++ << std::endl;
}

std::cout << "----------STL_INSERT_1---------" << std::endl;
// TEST FROME cplusplus.com for list::insert with fill prototype
{
	  std::list<int> list;
  std::list<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=5; ++i) list.push_back(i); // 1 2 3 4 5

  it = list.begin();
  ++it;       // it points now to number 2           ^

  list.insert(it,10);                        // 1 10 2 3 4 5

  // "it" still points to number 2                      ^
  list.insert(it,2,20);                      // 1 10 20 20 2 3 4 5
std::cout << "list contains:";
  for (it=list.begin(); it!=list.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

std::cout << "----------MINE_INSERT_1---------" << std::endl;
{
	 ft::list<int> mylist;
  ft::list<int>::iterator mit;

   for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5

  mit = mylist.begin();
  ++mit;       // it points now to number 2           ^

  mylist.insert (mit,10);                        // 1 10 2 3 4 5

  // "it" still points to number 2                      ^
  mylist.insert (mit,(unsigned int)2,20);                      // 1 10 20 20 2 3 4 5
std::cout << "list contains:";
  for (mit=mylist.begin(); mit!=mylist.end(); ++mit)
    std::cout << ' ' << *mit;
  std::cout << '\n';
}

std::cout << "----------STL_INSERT_2---------" << std::endl;
//Test from cplusplus.com with each prototype of list::insert
{
  std::list<int> mylist;
  std::list<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5

  it = mylist.begin();
  ++it;       // it points now to number 2           ^

  mylist.insert (it,10);                        // 1 10 2 3 4 5

  // "it" still points to number 2                      ^
  mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5

  --it;       // it points now to the second 20            ^

  std::list<int> myvector (2,30);
  mylist.insert (it,myvector.begin(),myvector.end());
                                                // 1 10 20 30 30 20 2 3 4 5
                                                //               ^
  std::cout << "list contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
	std::cout << '\n';
}

std::cout << "----------MINE_INSERT_2---------" << std::endl;
	{
  ft::list<int> mylist;
  ft::list<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5

  it = mylist.begin();
  ++it;       // it points now to number 2           ^

  mylist.insert (it,10);                        // 1 10 2 3 4 5

  // "it" still points to number 2                      ^
  mylist.insert (it,(unsigned int)2,20);                      // 1 10 20 20 2 3 4 5

  --it;       // it points now to the second 20            ^

  ft::list<int> myvector ((unsigned int)2,30);
  mylist.insert (it,myvector.begin(),myvector.end());
                                                // 1 10 20 30 30 20 2 3 4 5
                                                //               ^
  std::cout << "list contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
	std::cout << '\n';


}



std::cout << "----------STL_ERASE---------" << std::endl;
// TEST FROM cplusplus.com for both prototype of list::erase
{
	std::list<int> mylist;
  std::list<int>::iterator it1,it2;

  // set some values:
  for (int i=1; i<10; ++i) mylist.push_back(i*10);

                              // 10 20 30 40 50 60 70 80 90
  it1 = it2 = mylist.begin(); // ^^
  for (int i = 0; i < 6; i++)
	it2++;
  ++it1;                      //    ^              ^

  it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
                              //    ^           ^

  it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
                              //    ^           ^

  ++it1;                      //       ^        ^
  --it2;                      //       ^     ^

  mylist.erase (it1,it2);     // 10 30 60 80 90
                              //        ^

  std::cout << "mylist contains:";
  for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
    std::cout << ' ' << *it1;
  std::cout << '\n';

}

std::cout << "----------MINE_ERASE---------" << std::endl;
{
ft::list<int> mylist;
  ft::list<int>::iterator it1,it2;

  // set some values:
  for (int i=1; i<10; ++i) mylist.push_back(i*10);

                              // 10 20 30 40 50 60 70 80 90
  it1 = it2 = mylist.begin(); // ^^
  for (int i = 0; i < 6; i++)
	it2++;
  ++it1;                      //    ^              ^
  it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
                              //    ^           ^

  it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
                              //    ^           ^
  ++it1;                      //       ^        ^
  --it2;                      //       ^     ^

  mylist.erase (it1,it2);     // 10 30 60 80 90
                              //        ^

  std::cout << "mylist contains:";
  for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
    std::cout << ' ' << *it1;
  std::cout << '\n';
}

std::cout << "----------STL_SWAP---------" << std::endl;
//TEST FROM cplusplus.com for list::swap
{
 std::list<int> first (3,100);   // three ints with a value of 100
  std::list<int> second (5,200);  // five ints with a value of 200

  first.swap(second);

  std::cout << "first contains:";
  for (std::list<int>::iterator it=first.begin(); it!=first.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "second contains:";
  for (std::list<int>::iterator it=second.begin(); it!=second.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------MINE_SWAP---------" << std::endl;
{
 ft::list<int> first ((unsigned int)3,100);   // three ints with a value of 100
  ft::list<int> second ((unsigned int)5,200);  // five ints with a value of 200

  first.swap(second);

  std::cout << "first contains:";
  for (ft::list<int>::iterator it=first.begin(); it!=first.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "second contains:";
  for (ft::list<int>::iterator it=second.begin(); it!=second.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

std::cout << "----------STL_RESIZE_1---------" << std::endl;
//Test list::resize
{
	std::list<int> lst;
	lst.push_back(4);
	lst.push_back(5);
	lst.push_back(6);
	std::list<int>::iterator it = lst.begin();
	while (it != lst.end())
		std::cout << *it++ << std::endl;
	std::cout << "-----------" << std::endl;
	it = lst.begin();
	lst.resize(4, 19);
	while (it != lst.end())
		std::cout << *it++ << std::endl;
	std::cout << "-----------" << std::endl;
	it = lst.begin();
	lst.resize(2);
	while (it != lst.end())
		std::cout << *it++ << std::endl;
	std::cout << "-----------" << std::endl;
	it = lst.begin();
	lst.resize(6);
	while (it != lst.end())
		std::cout << *it++ << std::endl;
	it = lst.begin();
}

std::cout << "----------MINE_RESIZE_1---------" << std::endl;
{
	ft::list<int> lst;
	lst.push_back(4);
	lst.push_back(5);
	lst.push_back(6);
	ft::list<int>::iterator it = lst.begin();
	while (it != lst.end())
		std::cout << *it++ << std::endl;
	std::cout << "-----------" << std::endl;
	it = lst.begin();
	lst.resize(4, 19);
	while (it != lst.end())
		std::cout << *it++ << std::endl;
	std::cout << "-----------" << std::endl;
	it = lst.begin();
	lst.resize(2);
	while (it != lst.end())
		std::cout << *it++ << std::endl;
	std::cout << "-----------" << std::endl;
	it = lst.begin();
	lst.resize(6);
	while (it != lst.end())
		std::cout << *it++ << std::endl;
	it = lst.begin();
}

std::cout << "----------STL_RESIZE_2---------" << std::endl;
//Test for resize
{
	  std::list<int> mylist;

  // set some initial content:
  for (int i=1; i<10; ++i) mylist.push_back(i);

  mylist.resize(5);
  mylist.resize(8,100);
  mylist.resize(12);

  std::cout << "tlist contains:";
  for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

}
std::cout << "----------MINE_RESIZE_2---------" << std::endl;
 {
  ft::list<int> mylist;

  // set some initial content:
  for (int i=1; i<10; ++i) mylist.push_back(i);

  mylist.resize(5);
  mylist.resize(8,100);
  mylist.resize(12);

  std::cout << "mlist contains:";
  for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';
}


std::cout << "----------STL_SPLICE---------" << std::endl;
//Tests for all list::splice prototypes from cplusplus.com
{
std::list<int> mylist1, mylist2;
  std::list<int>::iterator it;
  std::list<int>::iterator its= mylist1.begin();
  // set some initial values:
  for (int i=1; i<=4; ++i)
     mylist1.push_back(i);      // mylist1: 1 2 3 4

  for (int i=1; i<=3; ++i)
     mylist2.push_back(i*10);   // mylist2: 10 20 30

  it = mylist1.begin();
  ++it;                         // points to 2

  mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                // mylist2 (empty)
                                // "it" still points to 2 (the 5th element)
  mylist2.splice (mylist2.begin(),mylist1, it);
                                // mylist1: 1 10 20 30 3 4
                                // mylist2: 2
                                // "it" is now invalid.
  it = mylist1.begin();
  for (int i = 0; i < 3 ; i++)
	it++;

  mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
                                // mylist1: 30 3 4 1 10 20

  std::cout << "mylist1 contains:";
 // for (it=mylist1.begin(); it!=mylist1.end(); ++it)
  for (; its!=mylist1.end(); ++its)
  {
    std::cout << ' ' << *its;

  }
  std::cout << '\n';

  std::cout << "mylist2 contains:";
  for (it=mylist2.begin(); it!=mylist2.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------MINE_SPLICE---------" << std::endl;
{
ft::list<int> mylist1, mylist2;
  ft::list<int>::iterator it;
  ft::list<int>::iterator its=mylist1.begin();
  // set some initial values:
  for (int i=1; i<=4; ++i)
       mylist1.push_back(i);     // mylist1: 1 2 3 4
  for (int i=1; i<=3; ++i)
     mylist2.push_back(i*10);   // mylist2: 10 20 30

  it = mylist1.begin();
  ++it;                         // points to 2
  mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
                                // mylist2 (empty)
                                // "it" still points to 2 (the 5th element)

mylist2.splice (mylist2.begin(), mylist1, it);
                                // mylist1: 1 10 20 30 3 4
                                // mylist2: 2
                                // "it" is now invalid.
  it = mylist1.begin();
  for (int i = 0; i < 3 ; i++)
	it++;
mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
                                // mylist1: 30 3 4 1 10 20
  std::cout << "mylist1 contains:";
  for (; its!=mylist1.end(); ++its)
  {
    std::cout << ' ' << *its;
  }
  std::cout << '\n';
  std::cout << "mylist2 contains:";
  for (it=mylist2.begin(); it!=mylist2.end(); ++it)
		std::cout << ' ' << *it;
  std::cout << '\n';
}


std::cout << "----------STL_REMOVE---------" << std::endl;
//TEST FOR LIST::REMOVE from cplusplus.com
 {
  std::list<int> src;
  src.push_back(17);
  src.push_back(89);
  src.push_back(7);
  src.push_back(14);
  std::list<int> mylist(src.begin(),src.end());
  mylist.remove(89);
  mylist.remove(14);
  mylist.remove(17);
  mylist.remove(42);

  std::cout << "mylist contains:";
  for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------MINE_REMOVE---------" << std::endl;
{
  ft::list<int> src;
  src.push_back(17);
  src.push_back(89);
  src.push_back(7);
  src.push_back(14);
  ft::list<int> mylist(src.begin(),src.end());

  mylist.remove(89);
  mylist.remove(14);
  mylist.remove(42);
  mylist.remove(17);

  std::cout << "mylist contains:";
  for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
 }

std::cout << "----------MINE_REMOVE_IF---------" << std::endl;
//Test for List::remove_if from cplusplus.com
{
	std::list <int> src;
	src.push_back(15);
	src.push_back(36);
	src.push_back(7);
	src.push_back(17);
	src.push_back(20);
	src.push_back(39);
	src.push_back(4);
	src.push_back(1);
  std::list<int> mylist (src.begin(),src.end());   // 15 36 7 17 20 39 4 1

  mylist.remove_if (single_digit);           // 15 36 17 20 39

  mylist.remove_if (is_odd());               // 36 20

  std::cout << "mylist contains:";
  for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------MINE_REMOVE_IF---------" << std::endl;
{
  	ft::list <int> src;
	src.push_back(15);
	src.push_back(36);
	src.push_back(7);
	src.push_back(17);
	src.push_back(20);
	src.push_back(39);
	src.push_back(4);
	src.push_back(1);
  ft::list<int> mylist (src.begin(),src.end());   // 15 36 7 17 20 39 4 1

  mylist.remove_if (single_digit);           // 15 36 17 20 39

  mylist.remove_if (is_odd());               // 36 20

  std::cout << "mylist contains:";
  for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}


std::cout << "----------STL_SORT---------" << std::endl;
// tests for list::sort from cpluscplus.com
{
 	std::list<std::string> mylist;
  std::list<std::string>::iterator it;
  mylist.push_back ("one");
  mylist.push_back ("two");
  mylist.push_back ("Three");
  mylist.sort();

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

   mylist.sort(compare_nocase);

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
{
std::cout << "----------MINE_SORT---------" << std::endl;
 ft::list<std::string> mylist;
  ft::list<std::string>::iterator it;
  mylist.push_back ("one");
  mylist.push_back ("two");
  mylist.push_back ("Three");

  mylist.sort();

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
 mylist.sort(compare_nocase);

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}

std::cout << "----------STL_UNIQUE---------" << std::endl;
//Test for list::unique (both prototypes) from cplusplus.com
{
  std::list<double> mylist;
  mylist.push_back(12.15);
  mylist.push_back(2.72);
  mylist.push_back(73.0);
  mylist.push_back(12.77);
  mylist.push_back(3.14);
  mylist.push_back(12.77);
  mylist.push_back(73.35);
  mylist.push_back(73.35);
  mylist.push_back(72.25);
  mylist.push_back(15.3);
  mylist.push_back(72.25);
  mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
                             // 15.3,  72.25, 72.25, 73.0,  73.35

  mylist.unique();           //  2.72,  3.14, 12.15, 12.77
                             // 15.3,  72.25, 73.0,  73.35
   mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
                                       // 15.3,  72.25, 73.0

  mylist.unique (is_near());           //  2.72, 12.15, 72.25
  std::cout << "mylist contains:";
  for (std::list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------MINE_UNIQUE---------" << std::endl;
{
  ft::list<double> mylist;
  mylist.push_back(12.15);
  mylist.push_back(2.72);
  mylist.push_back(73.0);
  mylist.push_back(12.77);
  mylist.push_back(3.14);
  mylist.push_back(12.77);
  mylist.push_back(73.35);
  mylist.push_back(73.35);
  mylist.push_back(72.25);
  mylist.push_back(15.3);
  mylist.push_back(72.25);
  mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
                             // 15.3,  72.25, 72.25, 73.0,  73.35
  mylist.unique();           //  2.72,  3.14, 12.15, 12.77
                             // 15.3,  72.25, 73.0,  73.35
  mylist.unique(same_integral_part); //  2.72,  3.14, 12.15
									 // 15.3,  72.25, 73.0

  mylist.unique (is_near());           //  2.72, 12.15, 72.25
  std::cout << "mylist contains:";
  for (ft::list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

}

std::cout << "----------STL_MERGE---------" << std::endl;
 //MERGE TEST from cplusplus.com both prototypes
 {
 std::list<double> first, second;

  first.push_back (3.1);
  first.push_back (2.2);
  first.push_back (2.9);

  second.push_back (3.7);
  second.push_back (7.1);
  second.push_back (1.4);

  first.sort();
  second.sort();
  first.merge(second);
  // (second is now empty)

  second.push_back (2.1);

  first.merge(second,mycomparison);

  std::cout << "first contains:";
  for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << std::endl;
  for (std::list<double>::iterator itsx=second.begin(); itsx!=second.end(); ++itsx)
    std::cout << ' ' << *itsx;
  std::cout << std::endl;
 }
std::cout << "----------MINE_MERGE---------" << std::endl;
 {
  ft::list<double> first, second;

  first.push_back (3.1);
  first.push_back (2.2);
  first.push_back (2.9);

  second.push_back (3.7);
  second.push_back (7.1);
  second.push_back (1.4);

  first.sort();
  second.sort();
  first.merge(second);

  // (second is now empty)

  second.push_back (2.1);

  first.merge(second,mycomparison);

  std::cout << "first contains:";
  for (ft::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << std::endl;
  for (ft::list<double>::iterator itsx=second.begin(); itsx!=second.end(); ++itsx)
    std::cout << ' ' << *itsx;
  std::cout << std::endl;
 }
std::cout << "----------STL_REVERSE---------" << std::endl;
//Test for list::reverse
{
	  std::list<int> mylist;

  for (int i=1; i<10; ++i) mylist.push_back(i);

  mylist.reverse();

  std::cout << "mylist contains:";
  for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';
}

std::cout << "----------MINE_REVERSE---------" << std::endl;
{
  ft::list<int> mylist;

  for (int i=1; i<10; ++i) mylist.push_back(i);

  mylist.reverse();

  std::cout << "mylist contains:";
  for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';
}

std::cout << "----------STL_SPECIAL---------" << std::endl;
// THIS IS AN ADDITIONAL TEST TO CHECK ITERATOR DESIGN VALIDITY
{
std::list<int> lst;
lst.push_back(1);
lst.push_back(2);
lst.push_back(3);
std::list<int>::iterator it = lst.end();
lst.erase(--lst.end());
lst.insert(lst.end(), lst.begin(), (++lst.begin()));
lst.insert(--(--lst.end()), 19);
while (it != lst.begin())
	std::cout << *--it << std::endl;
}
std::cout << "----------MINE_SPECIAL---------" << std::endl;
{
ft::list<int> lst;
lst.push_back(1);
lst.push_back(2);
lst.push_back(3);
ft::list<int>::iterator it = lst.end();
lst.erase(--lst.end());
lst.insert(lst.end(), lst.begin(), (++lst.begin()));
lst.insert(--(--lst.end()), 19);
while (it != lst.begin())
	std::cout << *--it << std::endl;
}

std::cout << "------------STL_REL_OPERATOR--------" << std::endl;
//TEST relational operators: tests from cplusplus.com
{

  std::list<int> a;
  a.push_back(10);
  a.push_back(20);
  a.push_back(30);
  std::list<int> b;
  b.push_back(10);
  b.push_back(20);
  b.push_back(30);
  std::list<int> c;
  c.push_back(30);
  c.push_back(20);
  c.push_back(10);

  if (a==b) std::cout << "a and b are equal\n";
  if (b!=c) std::cout << "b and c are not equal\n";
  if (b<c) std::cout << "b is less than c\n";
  if (c>b) std::cout << "c is greater than b\n";
  if (a<=b) std::cout << "a is less than or equal to b\n";
  if (a>=b) std::cout << "a is greater than or equal to b\n";

}
std::cout << "------------MINE_REL_OPERATOR--------" << std::endl;
{
  ft::list<int> a;
  a.push_back(10);
  a.push_back(20);
  a.push_back(30);
  ft::list<int> b;
  b.push_back(10);
  b.push_back(20);
  b.push_back(30);
  ft::list<int> c;
  c.push_back(30);
  c.push_back(20);
  c.push_back(10);

  if (a==b) std::cout << "a and b are equal\n";
  if (b!=c) std::cout << "b and c are not equal\n";
  if (b<c) std::cout << "b is less than c\n";
  if (c>b) std::cout << "c is greater than b\n";
  if (a<=b) std::cout << "a is less than or equal to b\n";
  if (a>=b) std::cout << "a is greater than or equal to b\n";
}

std::cout << "----------STL_SWAP_NMO---------" << std::endl;
{
  std::list<int> foo (3,100);   // three ints with a value of 100
  std::list<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (std::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "bar contains:";
  for (std::list<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
std::cout << "----------MINE_SWAP_NMO---------" << std::endl;
{
  ft::list<int> bar ((unsigned int)5,200);   // five ints with a value of 200
  ft::list<int> foo ((unsigned int)3,100);   // three ints with a value of 100

  foo.swap(bar);

  std::cout << "foo contains:";
  for (ft::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "bar contains:";
  for (ft::list<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
}
