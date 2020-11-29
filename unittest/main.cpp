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

/*
**Using processes to test segfaults and sigabort, so that the error gets catched and exits the child process
**For error messages that cannot be catched, we redirect the stderr to /dev/null
**Infinte loops cannot be catched unfortunately, if it occurs it should be visible at what test it occurs so the user can debug it
*/

/*
**Too much tests are done and cause computer to crash,
**solution is to not check in the end but after each test and only write errors to files, max number errors before quiting
**Temp files are used, if program blocks and ctrl-c is used to quit program, tmp files won't be deleted and can be viewed to debug
*/

/*
**Do not test max size as you can have different answer than real one. You must be able to explain, your own implementation of it.
**Infinite loop results can be checked in output/tmp_my and output/tmp_real
*/

/*
**Threads used with the failed idea of increasing the programs speed, failed due to impossibility to write to multiple fds at the same time
**But in the end threads increased program speed a lot by increasing the speed of fork.
** Fork gets slower as parent process uses more memory both stack and heap memory, due to its copying feature, using threads detaches from parent process and speeds up the forks
*/

int G_ERROR_LIMIT = 10;
//MAX 200 or computer crash risk

int main(int argc, char **argv)
{
  if (argc < 2 || argc > 3)
  {
    std::cout << "Choose between list, map, queue, stack and vector as first argument" << std::endl;
    return 0;
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
    std::cout << "\033[1m\033[33m" << "!!Starting tests for list container...!!" << std::endl;
    list_test<ft::list<int>, std::list<int>, int>();
    // list_test<ft::list<char>, char>(fd_w);

    // std::cout << "\033[1m\033[33m" << "!!Showing results...!!" << std::endl;
    // number_files(fd_r, "output/list"); //Remove and recreate file but numbered
    // number_files(fd_r_r, "output/real");
    // fd_r.open("output/list"); //Get back right file descriptor
    // fd_r_r.open("output/real");
    // check_answer(fd_r, fd_r_r); //Compare each line

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
