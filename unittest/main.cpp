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

float G_TOTAL_TESTS = 162535.000000;


template<typename T, typename R, typename T2>
void call_tests(std::string type, int test_lenght, T* (*function_pointer)(), R* (*function_pointer2)())
{
  std::cout << "\033[1m\033[33m" << "!!Starting tests for list<" << type << "> container...!!" << std::endl;
  std::cout << "\033[1m\033[30m" << "\nContainer object creation you:" << std::endl;
  T *my_elems1 = function_pointer();
  std::cout << "\033[1m\033[30m" << "End of container object creation\n" << std::endl;
  std::cout << "\033[1m\033[30m" << "Container object creation real:" << std::endl;
  R *real_elems1 = function_pointer2();
  std::cout << "\033[1m\033[30m" << "End of container object creation\n" << std::endl;
  list_test<T, R, T2>(my_elems1, real_elems1, test_lenght);
  std::cout << "\033[1m\033[33m" << "\n!!End list<"<< type << "> container tests...!!" << std::endl;
}

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
    std::cout << "\033[1m\033[33m" << "~~~~!!Starting tests for list container...!!~~~~" << std::endl;
    list_basis_tests<ft::list<int>, std::list<int>, int>();

    call_tests<ft::list<int>, std::list<int>, int>("int", 8, container_object_creation1<ft::list<int> >, container_object_creation1<std::list<int> >);
    call_tests<ft::list<char>, std::list<char>, char>("char", 8, container_object_creation1<ft::list<char> >, container_object_creation1<std::list<char> >);
    feedback();
    std::cout << "\033[1m\033[33m" << "~~~~!!End tests for list container!!~~~~" << std::endl;
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
