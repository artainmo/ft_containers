#define _MAIN_HPP
#ifndef _MAIN_HPP

//Change paths to your containers
#include "../List/list.hpp"
#include "../Vector/vector.hpp"
#include "../Map/map.hpp"
#include "../Stack/stack.hpp"
#include "../Queue/queue.hpp"

#include <list>
#include <vector>
#include <map>
#include <stack>
#include <queue>

#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>


#define P(x) std::cout << x << std::endl


template<typename T>
void show_queue(ft::queue<T> s);
void queue_test(ofstream fd_w);
void queue_real_test(ofstream fd_w);

template<typename T>
void show_stack(ft::stack<T> s);
void stack_test(ofstream fd_w);
void stack_real_test(ofstream fd_w);

template<typename Key, typename T>
void show_map(ft::map<Key, T> &l);
template<typename Key, typename T>
void show_map_reverse(ft::map<Key, T> &l); //Not in reverse order but using a reverse iterator
template<typename Key, typename T>
void reverse_map(ft::map<Key, T> &l); //Read and show map in reverse order
void vector_test(ofstream fd_w);
void vector_real_test(ofstream fd_w);

template<typename T>
void show_vector(ft::vector<T> &l);
template<typename T>
void show_vector2(ft::vector<T> &l); //Use at function instead of [] operator
void vector_test(ofstream fd_w, ifstream fd_r);
void vector_real_test(ofstream fd_w);

template<typename T>
void show_list(ft::list<T> &l);
template<typename T>
void show_list_reverse(ft::list<T> &l); //Not in reverse order but using a reverse iterator
template<typename T>
void reverse_list(ft::list<T> &l); //Read and show list in reverse order
void list_test(ofstream fd_w);
void list_real_test(ofstream fd_w);

template<typename T>
bool remove_if_test(T x);
template<typename T>
bool unique_test(T x, T x2);
template<typename T>
bool merge_test(T x, T x2);
template<typename T>
bool sort_test(T x, Tx2);

void write(std::string str, ofstream fd) { fd << str << std::endl; }

void check_answer(ifstream fd_r, ifstream fd_r_r);

#endif
