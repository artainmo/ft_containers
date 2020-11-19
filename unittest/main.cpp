#include "main.hpp"

//allocator_type does not need to be done, because we do not need to implement the get_allocator function
//https://www.cplusplus.com/reference/list/list/?kw=list

/*
**UNIT_TEST
**Two output files, one for own and real container object
**Each test outputs one line, write one line for one test on my.txt and real.txt, compare lines, if equal success test
**-> one big main that outputs the tests, check function called between, to compare answers, and terminal output if correct or not
**
**Check if const containers work properly, by launching executable with const argument, see compilation errors that should occur manually
**Grab segfaults and output them in output_files
**
**No compilation errors should occur in non-const unittest
**Change path to correct hpps
**
**Write all in files with your and real container, only after comare each line and give appropriate result
**
**Test everything besides undefined behavior, random memory access, segfault,....
**
**??Create 4 functions first one generates containers and calls second function that takes two containers as parameter
**??Second function tests every function from container with intact container by calling a separate function to test each member function, verify const return
**??And third function shows return value, content (with different iterating methods), size, front, back, creates a sub-test for each
*/

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

int main(int argc, char **argv)
{
  test_const_containers(); //Comment me out to continue unit test!

  if (argc < 2 || argc > 3)
  {
    std::cout << "Choose between list, map, queue, stack and vector as first argument, const as potential second argument" << std::endl;
    return 0;
  }

  std::remove("output/list");
  std::remove("output/map");
  std::remove("output/queue");
  std::remove("output/stack");
  std::remove("output/vector");
  std::remove("output/real");

  ofstream fd_w_r("output/real");
  ifstream fd_r_r("output/real");

  if (std::strcmp("list", argv[1]) == 0)
  {
    ofstream fd_w("output/list");
    ifstream fd_r("output/list");
    test_list(fd_w);
    test_real_list(fd_w_r);
    check_answer(fd_r, fd_r_r);
    fd_w.close();
    fd_r.close();
  }
  else if (std::strcmp("vector", argv[1]) == 0)
  {
    ofstream fd_w("output/vector");
    ifstream fd_r("output/vector");
    test_vector(fd_w);
    test_real_vector(fd_w_r);
    check_answer(fd_r, fd_r_r);
    fd_w.close();
    fd_r.close();
  }
  else if (std::strcmp("map", argv[1]) == 0)
  {
    ofstream fd_w("output/map");
    ifstream fd_r("output/map");
    test_map(fd_w);
    test_real_map(fd_w_r);
    check_answer(fd_r, fd_r_r);
    fd_w.close();
    fd_r.close();
  }
  else if (std::strcmp("stack", argv[1]) == 0)
  {
    ofstream fd_w("output/stack");
    ifstream fd_r("output/stack");
    test_stack(fd_w);
    test_real_stack(fd_w_r);
    check_answer(fd_r, fd_r_r);
    fd_w.close();
    fd_r.close();
  }
  else if (std::strcmp("queue", argv[1]) == 0)
  {
    ofstream fd_w("output/queue");
    ifstream fd_r("output/queue");
    test_queue(fd_w);
    test_real_queue(fd_w_r);
    check_answer(fd_r, fd_r_r);
    fd_w.close();
    fd_r.close();
  }
  fd_w_r.close();
  fd_r_r.close();
}
