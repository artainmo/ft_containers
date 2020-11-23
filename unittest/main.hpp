#ifndef _MAIN_HPP
#define _MAIN_HPP

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

#define P(x) std::cout << x << std::endl

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

//Unittest functions
#include "src/test_lists.hpp"
// #include "src/vector_test.hpp"
// #include "src/map_test.hpp"
// #include "src/queue_test.hpp"
// #include "src/stack_test.hpp"

void check_answer(std::ifstream &fd_r, std::ifstream &fd_r_r);
void number_files(std::ifstream &fd_r, std::string container);

void segfault_my( int signum ) { std::cout << "SEGFAULT" << std::endl; exit(signum); } //Catch segfaults and write in correct fd
void segfault_real( int signum ) { std::cout << "SEGFAULT" << std::endl; exit(signum); }
void segfault_stdin( int signum ) { std::cout << "SEGFAULT" << std::endl; exit(signum); }
void sigabort_my( int signum ) { std::cout << "SIGABORT" << std::endl; exit(signum); } //Catch sigaborts and write in correct fd
void sigabort_real( int signum ) { std::cout << "SIGABORT" << std::endl; exit(signum); }
void sigabort_stdin( int signum ) { std::cout << "SIGABORT" << std::endl; exit(signum); }

#endif
