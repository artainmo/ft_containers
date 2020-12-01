#ifndef _MAIN_HPP
#define _MAIN_HPP

//Paths to your containers
#include "../List/list.hpp"
#include "../Vector/vector.hpp"
#include "../Map/map.hpp"
#include "../Stack/stack.hpp"
#include "../Queue/queue.hpp"

//Real containers
#include <list>
#include <vector>
#include <map>
#include <stack>
#include <queue>

//External libs
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <sstream>
#include <csignal>
#include <fcntl.h>
#include <pthread.h>
#include <sstream>

extern int G_ERROR_LIMIT;
extern int G_ERROR_COUNT;
extern int G_LINE;
extern float G_TOTAL_TESTS;

template<typename T>
struct s_functions_ptr
{
  void (*function_pointer)();
  int num;
};

template<typename T>
struct s_functions_ptr1
{
  void (*function_pointer)(T &ob);
  int num;
};

template<typename T>
struct s_functions_ptr2
{
  void (*function_pointer)(T &ob, T &ob2);
  int num;
};

template<typename T, typename R>
struct thread_arg
{
  int num1;
  int num2;
  T *my_elems;
  R *real_elems;
  std::ofstream &output_my;
  std::ofstream &output_real;
  int test_lenght;
};

template<typename T>
void safe_space_test(s_functions_ptr1<T> func[31], unsigned int i, T &l, std::ofstream &fd)
{
  pid_t pid = fork(); //vfork is faster than fork, the parent process automatically waits for child process because they share the same stack memory
  std::streambuf *sfd = fd.rdbuf();

  if (pid == 0)
  {
    std::cout.rdbuf(sfd);  //Redirect cout or stream 1 to file
    func[i].function_pointer(l); //Call real
    exit(0);
  }
  wait(NULL);
}

template<typename T>
void safe_space_test(s_functions_ptr2<T> func[26], unsigned int i, T &l, T &l2, std::ofstream &fd)
{
  pid_t pid = fork();
  std::streambuf *sfd = fd.rdbuf();

  if (pid == 0)
  {
    std::cout.rdbuf(sfd);  //Redirect cout or stream 1 to file
    func[i].function_pointer(l, l2); //Call real
    exit(0);
  }
  wait(NULL);
}

void check_answer(std::ifstream &fd_r, std::ifstream &fd_r_r, std::ofstream &output_my, std::ofstream &output_real);
void feedback();

std::string itoa(int num);

void segfault( int signum );
void sigabort( int signum );
void sigquit(int sig);

//Unittest functions
#include "src/test_lists.hpp"
// #include "src/vector_test.hpp"
#include "src/test_maps.hpp"
// #include "src/queue_test.hpp"
// #include "src/stack_test.hpp"

#endif
