#include "main.hpp"

/*
**INFO
**Unittest for the following container objects in c++; list, map, queue, stack, vector
**
**USE
**Prepare -> Change path to your containers hpp's in main.hpp
**Prepare -> Choose ERROR LIMIT by changing G_ERROR_LIMIT in main.cpp
**Launch non-const unittest -> make list/stack/...
**Results -> output/real and output/list
**Tests -> list_tests.hpp
**
**NOT TESTED
**Allocator_type
**Undefined behavior; unintialized memory access, SIGABORT, SEGFAULT
**Max size as you can have different answer than real one. You must be able to explain, your own implementation of it.
**
**OTHER
**Infinite loop results can be checked in output/tmp_my and output/tmp_real
**No compilation errors should occur in non-const unittest
**
**CONST UNITTEST
**Launch const unittest -> make const
**You should have a certain amount of compilation errors not more or less
**
**ABOUT UNITTEST
**Written in c++
**Combination of tests are generated based on different container objects.
**
**Using processes to test segfaults and sigabort, so that the error gets catched and exits the child process
**For error messages that cannot be catched like memory freed not allocated, we redirect the stderr to /dev/null
**Infinte loops cannot be catched unfortunately, if it occurs it should be visible at what test it occurs so the user can debug it
**
**Too much tests are done and cause computer to crash,
**solution is to not check in the end but after each test and only write errors to files, max number errors before quiting
**Temp files are used, if program blocks and ctrl-c is used to quit program, tmp files won't be deleted and can be viewed to debug, useful for infinite loops
**
**Threads used with the failed idea of increasing the programs speed, failed due to impossibility to write to multiple fds at the same time
**But in the end threads increased program speed a lot by increasing the speed of fork.
**Fork gets slower as parent process uses more memory both stack and heap memory, due to its copying feature, using threads detaches from parent process and speeds up the forks
*/

int G_ERROR_LIMIT = 1;
//MAX 200 or potential computer crash risk

float G_TOTAL_TESTS = 80854.000000;

int main(int argc, char **argv)
{
  if (argc < 2 || argc > 3)
  {
    std::cerr << "Choose between list, map, queue, stack and vector as first argument" << std::endl;
    return 0;
  }
  else if (G_ERROR_LIMIT == 0)
  {
    std::cerr << "ERROR: error limit cannot be zero" << std::endl;
    return 1;
  }

  std::remove("output/list");
  std::remove("output/map");
  std::remove("output/queue");
  std::remove("output/stack");
  std::remove("output/vector");
  std::remove("output/real");
  std::remove("output/tmp_my");
  std::remove("output/tmp_real");


  signal(SIGQUIT, sigquit);
  signal(SIGSEGV, segfault);
  signal(SIGABRT, sigabort);
  if (std::strcmp("list", argv[1]) == 0)
  {
    std::cout << "\033[1m\033[33m" << "!!Starting tests for list<int> container...!!" << std::endl;
    ft::list<int> *my_elems1 = container_object_creation1<ft::list<int> >();
    std::list<int> *real_elems1 = container_object_creation1<std::list<int> >();
    list_test<ft::list<int>, std::list<int>, int>(my_elems1, real_elems1, 8);
    delete my_elems1;
    delete real_elems1;
    std::cout << "\033[1m\033[33m" << "\n!!End list<int> container tests...!!" << std::endl;
    std::cout << "\033[1m\033[33m" << "\n!!Starting tests for list<char> container...!!" << std::endl;
    ft::list<char> *my_elems2 = container_object_creation1<ft::list<char> >();
    std::list<char> *real_elems2 = container_object_creation1<std::list<char> >();
    list_test<ft::list<char>, std::list<char>, char>(my_elems2, real_elems2, 8);
    delete my_elems2;
    delete real_elems2;
    std::cout << "\033[1m\033[33m" << "\n!!End list<char> container tests...!!" << std::endl;
    std::cout << "\033[1m\033[33m" << "\n!!Starting tests for list<std::string> container...!!" << std::endl;
    ft::list<std::string> *my_elems3 = container_object_creation2<ft::list<std::string> >();
    std::list<std::string> *real_elems3 = container_object_creation2<std::list<std::string> >();
    list_test<ft::list<std::string>, std::list<std::string>, std::string>(my_elems3, real_elems3, 2); //!!!
    delete my_elems3;
    delete real_elems3;
    std::cout << "\033[1m\033[33m" << "\n!!End list<std::string> container tests...!!" << std::endl;
    std::cout << "\033[1m\033[33m" << "\n!!Starting tests for list<Complex> container...!!" << std::endl;
    ft::list<Complex> *my_elems4 = container_object_creation2<ft::list<Complex> >();
    std::list<Complex> *real_elems4 = container_object_creation2<std::list<Complex> >();
    list_test<ft::list<Complex>, std::list<Complex>, Complex>(my_elems4, real_elems4, 2); //!!!
    delete my_elems4;
    delete real_elems4;
    std::cout << "\033[1m\033[33m" << "\n!!End list<Complex> container tests...!!" << std::endl;
    feedback();
  }
  // else if (std::strcmp("vector", argv[1]) == 0)
  // {
  //   std::ofstream fd_w("output/vector");
  //   std::ifstream fd_r("output/vector");
  //   test_vector(fd_w);
  //   test_real_vector(fd_w_r);
  //   check_answer(fd_r, fd_r_r);
  //   fd_w.close();
  //   fd_r.close();
  // }
  // else if (std::strcmp("map", argv[1]) == 0)
  // {
  //   std::ofstream fd_w("output/map");
  //   std::ifstream fd_r("output/map");
  //   test_map(fd_w);
  //   test_real_map(fd_w_r);
  //   check_answer(fd_r, fd_r_r);
  //   fd_w.close();
  //   fd_r.close();
  // }
  // else if (std::strcmp("stack", argv[1]) == 0)
  // {
  //   std::ofstream fd_w("output/stack");
  //   std::ifstream fd_r("output/stack");
  //   test_stack(fd_w);
  //   test_real_stack(fd_w_r);
  //   check_answer(fd_r, fd_r_r);
  //   fd_w.close();
  //   fd_r.close();
  // }
  // else if (std::strcmp("queue", argv[1]) == 0)
  // {
  //   std::ofstream fd_w("output/queue");
  //   std::ifstream fd_r("output/queue");
  //   test_queue(fd_w);
  //   test_real_queue(fd_w_r);
  //   check_answer(fd_r, fd_r_r);
  //   fd_w.close();
  //   fd_r.close();
  // }
  std::remove("output/tmp_my");
  std::remove("output/tmp_real");
}
