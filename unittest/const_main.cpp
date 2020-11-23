#include "main.hpp"

void test_const_containers()
{
  P("Const list and iterator");
  const ft::list<int> cl((unsigned int)4,4);
  ft::list<int>::const_iterator cli = cl.begin();
  P("Const list calling size, clear and trying to change front value");
  P(cl.size());
  // cl.clear(); //Should create compilation error, comment this line to continue test
  // cl.front() = 9; //Should create compilation error, comment this line to continue test
  P("Const iterator showing front value and trying to change front value");
  P(*cli);
  // *cli = 9; //Should create compilation error, comment this line to continue test
  P("");

  P("Const vector and iterator");
  const ft::vector<int> cv((unsigned int)4,4);
  ft::vector<int>::const_iterator cvi = cv.begin();
  P("Const vector calling size, clear and trying to change front value");
  P(cv.size());
  // cv.clear(); //Should create compilation error, comment this line to continue test
  // cv.front() = 9; //Should create compilation error, comment this line to continue test
  P("Const iterator showing front value and trying to change front value");
  P(*cvi);
  // *cvi = 9; //Should create compilation error, comment this line to continue test
  P("");

  P("Const map and iterator");
  ft::map<int, int> m4;
  m4[2] = 2;
  m4[3] = 3;
  const ft::map<int, int> cm(m4);
  ft::map<int, int>::const_iterator cmi = cm.begin();
  P("Const map calling size, clear and trying to change front value");
  P(cm.size());
  // cm.clear(); //Should create compilation error, comment this line to continue test
  cm.find(2) = cmi; //Should create compilation error, comment this line to continue test
  P("Const iterator showing front value and trying to change front value");
  P(*cmi);
  // *cmi = 9; //Should create compilation error, comment this line to continue test
  P("");

  P("Const stack");
  ft::stack<int> si1;
  si1.push(4);
  si1.push(4);
  si1.push(4);
  const ft::stack<int> cs(si1);
  P("Const stack calling size, pop and trying to change front value");
  P(cs.size());
  // cs.pop(); //Should create compilation error, comment this line to continue test
  // cs.top() = 9; //Should create compilation error, comment this line to continue test

  P("Const queue");
  ft::queue<int> qi1;
  qi1.push(4);
  qi1.push(4);
  qi1.push(4);
  const ft::queue<int> cq(qi1);
  P("Const queue calling size, pop and trying to change front value");
  P(cq.size());
  // cq.pop(); //Should create compilation error, comment this line to continue test
  // cq.front() = 9; //Should create compilation error, comment this line to continue test

  P("You should have gotten 13 compilation errors in total");
  P("Comment out the call in main to test_const_containers to continue");
  std::exit(0);
}

int main()
{
  test_const_containers(); //Comment me out to continue unit test!
}
