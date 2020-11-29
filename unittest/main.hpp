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

void check_answer(std::ifstream &fd_r, std::ifstream &fd_r_r, std::ofstream &output_my, std::ofstream &output_real);

std::string itoa(int num);

void segfault( int signum );
void sigabort( int signum );
void sigquit(int sig);

//Unittest functions
#include "src/test_lists.hpp"
// #include "src/vector_test.hpp"
// #include "src/map_test.hpp"
// #include "src/queue_test.hpp"
// #include "src/stack_test.hpp"

#endif
