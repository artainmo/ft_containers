#ifndef LIST_TESTS_HPP
#define LIST_TESTS_HPP

#include "../main.hpp"

template<typename T>
T *container_object_creation1()
{
  T *my_elems = new T[8];

  T l1; //Empty
  std::cout << "\033[30m" << "1 ";

  T l2((unsigned int)10, 5); //Long same values
  std::cout << "\033[30m" << "2 ";

  T l3; // 4 values, same front and end
  l3.push_back(1);
  l3.push_back(4);
  l3.push_back(3);
  l3.push_back(1);
  std::cout << "\033[30m" << "3 ";

  T l4; //3 values
  l4.push_back(0);
  l4.push_back(3);
  l4.push_back(7);
  std::cout << "\033[30m" << "7 ";

  T l5; //2 values
  l5.push_back(5);
  l5.push_back(6);

  T l6; //1 value
  l6.push_back(7);

  T l7; //Small to big 5 values
  std::cout << "\033[30m" << "9 ";
  l7.push_back(0);
  std::cout << "\033[30m" << "10 ";
  l7.push_back(1);
  std::cout << "\033[30m" << "11 ";
  l7.push_back(2);
  std::cout << "\033[30m" << "12 ";
  l7.push_back(3);
  std::cout << "\033[30m" << "13 ";
  l7.push_back(4);
  std::cout << "\033[30m" << "14 ";
  l7.push_back(5);
  std::cout << "\033[30m" << "15 ";

  T l8; //Big to small 5 values
  std::cout << "\033[30m" << "23 ";
  l8.push_back(5);
  std::cout << "\033[30m" << "24 ";
  l8.push_back(4);
  std::cout << "\033[30m" << "25 ";
  l8.push_back(3);
  std::cout << "\033[30m" << "26 ";
  l8.push_back(2);
  std::cout << "\033[30m" << "27 ";
  l8.push_back(1);
  std::cout << "\033[30m" << "28 ";
  l8.push_back(0);
  std::cout << "\033[30m" << "29 ";

  my_elems[0] = l7;
  my_elems[1] = l8;
  my_elems[2] = l3;
  my_elems[3] = l4;
  my_elems[4] = l5;
  my_elems[5] = l6;
  my_elems[6] = l1;
  my_elems[7] = l2;

  return my_elems;
}

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
bool remove_if_test(T x)
{
  if (x == 8)
    return true;
  return false;
}

template<typename T>
bool unique_test(T x, T follow)
{
  if (x > follow)
    return false;
  return true;
}

template<typename T>
bool merge_test(T x, T x2)
{
  if (x < x2)
    return true;
  return false;
}

template<typename T>
bool sort_test(T x, T x2)
{
  if (x > x2)
    return true;
  return false;
}

template<typename T>
void get_size(T &ob) { std::cout << "~~ Size: "; std::cout << ob.size() << std::endl; }

template<typename T>
void get_back(T &ob) { std::cout << "~~ Back: "; std::cout << ob.back() << std::endl; }

template<typename T>
void get_front(T &ob) { std::cout << "~~ Front: "; std::cout << ob.front() << std::endl; }

template<typename T>
void show_list_begin(T &l)
{
  typename T::iterator it = l.begin(); //Typename to indicate no ambiguity by telling compiler following is a type, is necessary because object creation depends on template parameter

  std::cout << "~~ Show with begin iterator: ";
  for (unsigned int i = 0; i < l.size(); i++)
  {
    std::cout << *it;
    ++it;
  }
  std::cout << std::endl;
}

template<typename T>
void show_list_rbegin(T &l)
{
  typename T::reverse_iterator it = l.rbegin(); //Typename to indicate no ambiguity by telling compiler following is a type, is necessary because object creation depends on template parameter

  std::cout << "~~ Show with rbegin iterator: ";
  for (unsigned int i = 0; i < l.size(); i++)
  {
    std::cout << *it;
    ++it;
  }
  std::cout << std::endl;
}

template<typename T>
void show_list_end(T &l)
{
  typename T::iterator it = l.end(); //Typename to indicate no ambiguity by telling compiler following is a type, is necessary because object creation depends on template parameter

  std::cout << "~~ Show with end iterator: ";
  --it;
  for (unsigned int i = 0; i < l.size(); i++)
  {
    std::cout << *it;
    --it;
  }
  std::cout << std::endl;
}

template<typename T>
void show_list_rend(T &l)
{
  typename T::reverse_iterator it = l.rend(); //Typename to indicate no ambiguity by telling compiler following is a type, is necessary because object creation depends on template parameter

  std::cout << "~~ Show with rend iterator: ";
  --it;
  std::cout << *it;
  for (unsigned int i = 0; i < l.size(); i++)
  {
    std::cout << *it;
    --it;
  }
  std::cout << std::endl;
}

template<typename T>
void access(T &l) //All the subtests indicated with ~~
{
  struct s_functions_ptr1<T> func[7] = {{get_size<T>, 0}, {get_front<T>, 0}, {get_back<T>, 0}, {show_list_begin<T>, 0}, {show_list_rbegin<T>, 0}, {show_list_end<T>, 0}, {show_list_rend<T>, 0}};

  for (int i = 0; i < 7; i++)
  {
    pid_t pid = fork();

    if (pid == 0) //Child process
    {
      func[i].function_pointer(l);
      exit(0);
    }
    wait(NULL);
  }
}

template<typename T>
void default_constructor()
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Default constructor " << std::endl;
  T l;
  access<T>(l);
}

template<typename T>
void fill_constructor()
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Fill constructor " << std::endl;
  T l((unsigned int)10, 5); //Indicate unsigned int is necessary otherwise it will use the templated inputiterator (int, int) function
  access<T>(l);
}

template<typename T>
void special_fill_constructor()
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Special Fill constructor " << std::endl;
  T l((unsigned int)0, 4);
  access<T>(l);
}

template<typename T>
void range_constructor()
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Range constructor " << std::endl;
  T tmp((unsigned int)10, 5);
  typename T::iterator i = tmp.begin();
  ++i;
  ++i;
  ++i;
  T l(i, tmp.end());
  access<T>(l);
}

template<typename T, typename T2>
void copy_constructor()
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Copy constructor " << std::endl;
  T tmp((unsigned int)10, 5);
  T l(tmp);
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Deep copy test: " << std::endl;
  T2 k = 0;
  l.front() = k;
  tmp.back() = k;
  access<T>(l);
  access<T>(tmp);
}

template<typename T, typename T2>
void assignation_operator(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Assignation operator " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l = l2;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Deep copy test: " << std::endl;
  T2 k = 0;
  l.front() = k;
  l2.back() = k;
  access<T>(l);
  access<T>(l2);
}

template<typename T>
void empty(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Empty function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  if (l.empty() == false) //Returns false if not empty
    std::cout << "false" << std::endl;
  else
    std::cout << "true" << std::endl;
}

// template<typename T> //Own answer can differ from real list answer so do not test
// void max_size(T &l)
// {
//   std::cout << std::setfill ('#') << std::setw (100) << std::left << "Max size function " << std::endl;
//   std::cout << l.max_size() << std::endl;
// }

template<typename T>
void front(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Front function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.front() = l.back(); //If this line causes compilation error review your code const problem
  access<T>(l);
}

template<typename T>
void back(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Back function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.back() = l.front(); //If this line causes compilation error review your code const problem
  access<T>(l);
}

template<typename T>
void fill_assign2(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Fill assign function 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.assign((unsigned int)0, 0); //If you do not cast it to an unsigned int, it will enter the other assign function with two int parameters
  access<T>(l);
}

template<typename T>
void fill_assign(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Fill assign function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.assign((unsigned int)12, 7); //If you do not cast it to an unsigned int, it will enter the other assign function with two int parameters
  access<T>(l);
}

template<typename T>
void range_assign2(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Range assign function 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  access<T>(l2);
  typename T::iterator i = l2.begin();
  ++i;
  ++i;
  typename T::iterator i2 = l2.end();
  --i2;
  --i2;
  std::cout << "Iterator 1: " << *i << std::endl;
  std::cout << "Iterator 2: " << *i2 << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.assign(i, i2);
  access<T>(l);
  access<T>(l2);
}

template<typename T>
void range_assign(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Range assign function" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  access<T>(l2);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.assign(l2.begin(), l2.end());
  access<T>(l);
  access<T>(l2);
}

template<typename T>
void push_front(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Push_front function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.push_front(7);
  access<T>(l);
}

template<typename T>
void pop_front(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Pop_front function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  if (l.size() == 0) //Undefined behavior sigabort
    return ;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.pop_front();
  access<T>(l);
}

template<typename T>
void push_back(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Push_back function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.push_back(9);
  access<T>(l);
}

template<typename T>
void pop_back(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Pop_back function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  if (l.size() == 0) //Undefined behavior sigabort
    return ;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.pop_back();
  access<T>(l);
}

template<typename T>
void insert_single_element3(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Insert single element function 3" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  std::cout << "return: " << *(l.insert(l.end(), 3)) << std::endl;
  access<T>(l);
}

template<typename T>
void insert_single_element2(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Insert single element function 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  std::cout << "return: " << *(l.insert(l.begin(), 0)) << std::endl;
  access<T>(l);
}

template<typename T>
void insert_single_element(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Insert single element function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  typename T::iterator i = l.end();
  --i;
  --i;
  std::cout << "Iterator 1: " << *i << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  std::cout << "return: " << *(l.insert(i, 3)) << std::endl;
  access<T>(l);
}

template<typename T>
void insert_fill3(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Insert fill 3" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.insert(l.end(), (unsigned int)3, 4);
  access<T>(l);
}

template<typename T>
void insert_fill2(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Insert fill 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.insert(l.begin(), (unsigned int)0, 4);
  access<T>(l);
}

template<typename T>
void insert_fill(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Insert fill " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  typename T::iterator i = l.end();
  --i;
  --i;
  std::cout << "Iterator 1: " << *i << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.insert(i,  (unsigned int)3, 4);
  access<T>(l);
}

template<typename T>
void insert_range3(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Insert range 3" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  typename T::iterator m = l2.end();
  --m;
  --m;
  --m;
  typename T::iterator k = l2.begin();
  ++k;
  ++k;
  std::cout << "Iterator 1: " << *m << std::endl;
  std::cout << "Iterator 2: " << *k << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  if (l2.size() > 4) //Undefined behavior if k comes after m
    l.template insert<typename T::iterator >(l.begin(), k, m); //When the name of a member template specialization appears after . or -> in a postfix-expression, or after nested-name-specifier in a qualified-id, and the postfix-expression or qualified-id explicitly depends on a template-parameter, the member template name must be prefixed by the keyword template. Otherwise the name is assumed to name a non-template.
  else
    l.template insert<typename T::iterator >(l.begin(), m, k);
  access<T>(l);
  access<T>(l2);
}

template<typename T>
void insert_range2(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Insert range 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.template insert<typename T::iterator >(l.end(), l2.begin(), l2.end()); //When the name of a member template specialization appears after . or -> in a postfix-expression, or after nested-name-specifier in a qualified-id, and the postfix-expression or qualified-id explicitly depends on a template-parameter, the member template name must be prefixed by the keyword template. Otherwise the name is assumed to name a non-template.
  access<T>(l);
  access<T>(l2);
}

template<typename T>
void insert_range(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Insert range " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  typename T::iterator i = l.begin();
  ++i;
  ++i;
  std::cout << "Iterator 1: " << *i << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.template insert<typename T::iterator >(i, l2.begin(), l2.end()); //When the name of a member template specialization appears after . or -> in a postfix-expression, or after nested-name-specifier in a qualified-id, and the postfix-expression or qualified-id explicitly depends on a template-parameter, the member template name must be prefixed by the keyword template. Otherwise the name is assumed to name a non-template.
  access<T>(l);
  access<T>(l2);
}

template<typename T>
void erase_single_element2(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Erase single element 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  if (l.size() == 0) //Undefined behavior sigabort
    return ;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  std::cout << "return: " << *(l.erase(l.begin())) << std::endl;
  access<T>(l);
}

template<typename T>
void erase_single_element(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Erase single element " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  if (l.size() < 3) //Out of scope iterator undefined behavior, sigabort
    return ;
  typename T::iterator i = l.begin();
  ++i;
  ++i;
  typename T::iterator check = i;
  ++check;
  std::cout << "Iterator 1: " << *i << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  if (check != l.end()) //Return value is undefined when iterator points on back, because goes out of scope and returns random value
    std::cout << "return: " << *(l.erase(i)) << std::endl;
  else
    l.erase(i);
  access<T>(l);
}

template<typename T>
void erase_range2(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Erase range 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  if (l.size() == 1) //Undefined bahavior sigabort
    return ;
  typename T::iterator m = l.begin();
  ++m;
  ++m;
  typename T::iterator k = l.end();
  --k;
  --k;
  std::cout << "Iterator 1: " << *m << std::endl;
  std::cout << "Iterator 2: " << *k << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  if (l.size() > 3) //Undefined behavior if unordered
    std::cout << "return: " << *(l.erase(m, k)) << std::endl;
  else
    std::cout << "return: " << *(l.erase(k, m)) << std::endl;
  access<T>(l);
}

template<typename T>
void erase_range(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Erase range " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  std::cout << "return: " << *(l.erase(l.begin(), l.end())) << std::endl;
  access<T>(l);
}

template<typename T>
void swap_member_function(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Swap member function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.swap(l2);
  access<T>(l);
  access<T>(l2);
}

template<typename T>
void resize_range_bigger(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Resize range bigger " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.resize(l.size() + 1, 9);
  access<T>(l);
}

template<typename T>
void resize_range_smaller(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Resize range smaller " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;

  if (l.size() < 3)
    l.resize(0, 9);
  else
    l.resize(l.size() - 3, 9);
  access<T>(l);
}

template<typename T>
void resize_bigger(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Resize bigger " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.resize(65); //Size_t minimum upper limit is 65535
  access<T>(l);
}

template<typename T>
void resize_smaller(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Resize smaller " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  if (l.size() < 3) //Size_t does not take negative numbers
    l.resize(0);
  else
    l.resize(l.size() - 3);
  access<T>(l);
}

template<typename T>
void clear(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Clear function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.clear();
  access<T>(l);
}

template<typename T>
void splice_list3(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice entire list 3" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  typename T::iterator i = l.begin();
  ++i;
  ++i;
  std::cout << "Iterator 1: " << *i << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.splice(i, l2);
  access<T>(l);
  access<T>(l2);
}

template<typename T>
void splice_list2(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice entire list 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.splice(l.end(), l2);
  access<T>(l);
  access<T>(l2);
}

template<typename T>
void splice_list(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice entire list " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.splice(l.begin(), l2);
  access<T>(l);
  access<T>(l2);
}

template<typename T>
void splice_single_element4(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice single element 4" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  typename T::iterator i = l2.begin();
  ++i;
  l.splice(l.begin(), l2, l.begin());
  access<T>(l);
  access<T>(l2);
}

template<typename T>
void splice_single_element3(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice single element 3" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  typename T::iterator i = l2.begin();
  ++i;
  l.splice(i, l2, i);
  access<T>(l);
  access<T>(l2);
}

template<typename T>
void splice_single_element2(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice single element 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  if (l2.size() == 0) // !!REAL COMPLETE BUG!!
    return ;
  typename T::iterator i = l.end();
  --i;
  --i;
  --i;
  typename T::iterator k = l2.end();
  --k;
  --k;
  --k;
  std::cout << "~~~Iterator 1: "<< *i<< std::endl;
  std::cout << "~~~Iterator 2: "<< *k<< std::endl;
  if (l2.size() == 2) //Undefined behavior out of range iterator
    return ;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.splice(i, l2, k);
  access<T>(l);
  access<T>(l2);
}

template<typename T>
void splice_single_element(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice single element " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  if (l2.size() == 0)// !!== 0 REAL COMPLETE BUG!!
    return ;
  typename T::iterator i = l.begin();
  ++i;
  ++i;
  typename T::iterator k = l2.begin();
  ++k;
  ++k;
  std::cout << "~~~Iterator 1: "<< *i<< std::endl;
  std::cout << "~~~Iterator 2: "<< *k<< std::endl;
  if (l2.size() == 2) //Undefined behavior out of range iterator
    return ;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.splice(i, l2, k);
  access<T>(l);
  access<T>(l2);
}

template<typename T>
void splice_range3(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice range 3" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  typename T::iterator i = l2.end();
  --i;
  typename T::iterator k = l2.begin();
  ++k;
  std::cout << "~~~Iterator 1: "<< *k<< std::endl;
  std::cout << "~~~Iterator 2: "<< *i<< std::endl;
  if (l2.size() == 1) //Undefined behavior
    return ;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.splice(l.begin(), l2, k, i);
  access<T>(l);
  access<T>(l2);
}

template<typename T>
void splice_range2(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice range 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  typename T::iterator i = l.end();
  --i;
  --i;
  --i;
  std::cout << "~~~Iterator 1: "<< *i << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.splice(i, l2, l2.begin(), l2.end());
  access<T>(l);
  access<T>(l2);
}

template<typename T>
void splice_range(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice range " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  typename T::iterator i = l.begin();
  ++i;
  ++i;
  std::cout << "~~~Iterator 1: "<< *i<< std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.splice(i, l2, l2.begin(), l2.end());
  access<T>(l);
  access<T>(l2);
}

template<typename T>
void remove(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Remove function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.remove(5);
  access<T>(l);
}

template<typename T, typename T2>
void remove_if(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Remove_if function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.remove_if(remove_if_test<T2>);
  access<T>(l);
  access<T>(l);
}

template<typename T>
void unique(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Unique function default " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.unique();
  access<T>(l);
}

template<typename T, typename T2>
void unique_if(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Unique function function parameter " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.unique(unique_test<T2>);
  access<T>(l);
}

template<typename T>
void merge(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Merge function default " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  l.sort(); //Both containers should already be ordered or undefined behavior
  l2.sort();
  access<T>(l);
  access<T>(l2);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.merge(l2);
  l.merge(l); //Test if function successfully negates merging itself
  access<T>(l);
  access<T>(l2);
}

template<typename T, typename T2>
void merge_if(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Merge function function parameter " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  l.sort(); //Both containers should already be ordered or undefined behavior
  l2.sort();
  access<T>(l);
  access<T>(l2);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.merge(l2, merge_test<T2>);
  access<T>(l);
  access<T>(l2);
}

template<typename T>
void sort(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Sort function default" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.sort();
  access<T>(l);
}

template<typename T, typename T2>
void sort_if(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Sort function function argument" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.sort(sort_test<T2>);
  access<T>(l);
}

template<typename T>
void reverse(T &l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Reverse function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.reverse();
  access<T>(l);
}

template<typename T>
void swap_non_member_function(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Swap non-member function overload " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  swap(l, l2);
  access<T>(l);
  access<T>(l2);
}

template<typename T>
void equal(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Equal operator " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Compared containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  if (l == l2)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;
}

template<typename T>
void non_equal(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Non-equal operator " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Compared containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  if (l != l2)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;
}

template<typename T>
void smaller_than(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Smaller than operator " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Compared containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  if (l < l2)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;
}

template<typename T>
void smaller_than_equal(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Smaller than or equal operator " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Compared containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  if (l <= l2)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;
}

template<typename T>
void bigger_than(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Bigger than operator " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Compared containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  if (l > l2)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;
}

template<typename T>
void bigger_than_equal(T &l, T &l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Bigger than or equal operator " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Compared containers: " << std::endl;
  access<T>(l);
  access<T>(l2);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  if (l >= l2)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;
}

template<typename T>
void iterator_tests2()
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Iterator tests 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Compared containers: " << std::endl;
  T l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  l.push_back(5);
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  typename T::iterator i = l.begin();
  typename T::iterator k = l.end();

  std::cout << *i << std::endl;
  std::cout << *k << std::endl;
  --i;
  ++k;
  std::cout << *i << std::endl;
  std::cout << *k << std::endl;
  --i;
  ++k;
  std::cout << *i << std::endl;
  std::cout << *k << std::endl;
}

template<typename T, typename T2>
void iterator_tests1()
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Iterator tests " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Compared containers: " << std::endl;
  T l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  l.push_back(5);
  access<T>(l);
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  typename T::iterator i = l.begin();
  ++i;
  typename T::iterator k = l.end();
  --k;
  T2 test;

  if (i == i)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;

  if (i == k)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;

  if (i != i)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;

  if (i != k)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;

  test = *i;
  test = 10; //If this causes compilation error review your code const problem
  std::cout << *i << std::endl;

  *k = 10; //If this causes compilation error review your code const problem
  std::cout << *k << std::endl;
}

#endif
