#ifndef LIST_TESTS_HPP
#define LIST_TESTS_HPP

#include "../main.hpp"

template<typename T>
struct s_functions_ptr
{
  void (*function_pointer)();
};

template<typename T>
struct s_functions_ptr1
{
  void (*function_pointer)(T ob);
};

template<typename T>
struct s_functions_ptr2
{
  void (*function_pointer)(T ob, T ob2);
};

template<typename T>
bool remove_if_test(T x)
{
  if (x == 8)
    return true;
  return false;
}

template<typename T>
bool unique_test(T x, T x2)
{
  if (x - 1 == x2)
    return true;
  return false;
}

template<typename T>
bool merge_test(T x, T x2)
{
  if (x > x2)
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
void get_size(T ob) { std::cout << "~~ Size: "; std::cout << ob.size() << std::endl; }

template<typename T>
void get_back(T ob) { std::cout << "~~ Back: "; std::cout << ob.back() << std::endl; }

template<typename T>
void get_front(T ob) { std::cout << "~~ Front: "; std::cout << ob.front() << std::endl; }

template<typename T>
void show_list_begin(T l)
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
void show_list_rbegin(T l)
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
void show_list_end(T l)
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
void show_list_rend(T l)
{
  typename T::reverse_iterator it = l.rend(); //Typename to indicate no ambiguity by telling compiler following is a type, is necessary because object creation depends on template parameter

  std::cout << "~~ Show with rend iterator: ";
  --it;
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
  struct s_functions_ptr1<T> func[7] = {{get_size<T>}, {get_back<T>}, {get_front<T>}, {show_list_begin<T>}, {show_list_rbegin<T>}, {show_list_end<T>}, {show_list_rend<T>}};

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
  access<T>(l)
}

template<typename T>
void fill_constructor()
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Fill constructor " << std::endl;
  T l((unsigned int)10, 5); //Indicate unsigned int is necessary otherwise it will use the templated inputiterator (int, int) function
  access<T>(l)
}

template<typename T>
void special_fill_constructor()
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Special Fill constructor " << std::endl;
  T l((unsigned int)0, 4);
  access<T>(l)
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
  access<T>(l)
}

template<typename T, typename T2>
void copy_constructor()
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Copy constructor " << std::endl;
  T tmp((unsigned int)10, 5);
  T l(tmp);
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Deep copy test: " << std::endl;
  T2 k = 0;
  l.front() = k;
  tmp.back() = k;
  access<T>(l)
  access<T>(tmp)
}

template<typename T, typename T2>
void assignation_operator(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Assignation operator " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l = l2;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Deep copy test: " << std::endl;
  T2 k = 0;
  l.front() = k;
  l2.back() = k;
  access<T>(l)
  access<T>(l2)
}

template<typename T>
void empty(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Empty function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  if (l.empty() == false) //Returns false if not empty
    std::cout << "false" << std::endl;
  else
    std::cout << "true" << std::endl;
}

template<typename T>
void max_size(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Max size function " << std::endl;
  std::cout << l.max_size() << std::endl;
}

template<typename T>
void front(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Front function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.front() = 0; //If this line causes compilation error review your code
  access<T>(l)
}

template<typename T>
void back(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Back function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.back() = 0; //If this line causes compilation error review your code
  access<T>(l)
}

template<typename T>
void fill_assign2(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Fill assign function 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.assign((unsigned int)0, 0); //If you do not cast it to an unsigned int, it will enter the other assign function with two int parameters
  access<T>(l)
}

template<typename T>
void fill_assign(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Fill assign function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.assign((unsigned int)12, 7); //If you do not cast it to an unsigned int, it will enter the other assign function with two int parameters
  access<T>(l)
}

template<typename T>
void range_assign2(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Range assign function 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.assign(l2.begin(), l2.end());
  access<T>(l)
}

template<typename T>
void range_assign(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Range assign function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  typename T::iterator i = l2.begin();
  ++i;
  ++i;
  typename T::iterator i2 = l2.end();
  --i2;
  --i2;
  --i2;
  l.assign(i, i2);
  access<T>(l)
}

template<typename T>
void push_front(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Push_front function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.push_front(7);
  access<T>(l)
}

template<typename T>
void pop_front(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Pop_front function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.pop_front();
  access<T>(l)
}

template<typename T>
void push_back(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Push_back function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.push_back(9);
  access<T>(l)
}

template<typename T>
void pop_back(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Pop_back function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.pop_back();
  access<T>(l)
}

template<typename T>
void insert_single_element4(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Insert single element function 4" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  T tmp((unsigned int)1,1);
  typename T::iterator i = tmp.begin();
  l.insert(i, 3);
  access<T>(l)
}

template<typename T>
void insert_single_element3(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Insert single element function 3" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.insert(l.end(), 3);
  access<T>(l)
}

template<typename T>
void insert_single_element2(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Insert single element function 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.insert(l.begin(), 0);
  access<T>(l)
}

template<typename T>
void insert_single_element(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Insert single element function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  typename T::iterator i = l.end();
  --i;
  --i;
  l.insert(i, 3);
  access<T>(l)
}

template<typename T>
void insert_fill4(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Insert fill 4" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  T tmp((unsigned int)1,1);
  typename T::iterator i = tmp.begin();
  l.insert(i, (unsigned int)3, 4);
  access<T>(l)
  access<T>(l)
}

template<typename T>
void insert_fill3(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Insert fill 3" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.insert(l.end(), (unsigned int)3, 4);
  access<T>(l)
}

template<typename T>
void insert_fill2(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Insert fill 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.insert(l.begin(), (unsigned int)0, 4);
  access<T>(l)
}

template<typename T>
void insert_fill(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Insert fill " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  typename T::iterator i = l.end();
  --i;
  --i;
  l.insert(i,  (unsigned int)3, 4);
  access<T>(l)
}

template<typename T>
void insert_range3(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Insert range 3" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  typename T::iterator m = l2.end();
  --m;
  --m;
  --m;
  typename T::iterator k = l2.begin();
  ++k;
  ++k;
  l.template insert<typename T::iterator >(l.begin(), k, m); //When the name of a member template specialization appears after . or -> in a postfix-expression, or after nested-name-specifier in a qualified-id, and the postfix-expression or qualified-id explicitly depends on a template-parameter, the member template name must be prefixed by the keyword template. Otherwise the name is assumed to name a non-template.
  access<T>(l)
  access<T>(l2)
}

template<typename T>
void insert_range2(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Insert range 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.template insert<typename T::iterator >(l.end(), l2.begin(), l2.end()); //When the name of a member template specialization appears after . or -> in a postfix-expression, or after nested-name-specifier in a qualified-id, and the postfix-expression or qualified-id explicitly depends on a template-parameter, the member template name must be prefixed by the keyword template. Otherwise the name is assumed to name a non-template.
  access<T>(l)
  access<T>(l2)
}

template<typename T>
void insert_range(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Insert range " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  typename T::iterator i = l.begin();
  ++i;
  ++i;
  l.template insert<typename T::iterator >(i, l2.begin(), l2.end()); //When the name of a member template specialization appears after . or -> in a postfix-expression, or after nested-name-specifier in a qualified-id, and the postfix-expression or qualified-id explicitly depends on a template-parameter, the member template name must be prefixed by the keyword template. Otherwise the name is assumed to name a non-template.
  access<T>(l)
  access<T>(l2)
}

template<typename T>
void erase_single_element4(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Erase single element 4" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  T tmp((unsigned int)1,1);
  typename T::iterator i = tmp.begin();
  l.erase(i);
  access<T>(l)
}

template<typename T>
void erase_single_element3(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Erase single element 3" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.erase(l.begin());
  access<T>(l)
}

template<typename T>
void erase_single_element2(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Erase single element 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.erase(l.end());
  access<T>(l)
}

template<typename T>
void erase_single_element(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Erase single element " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  typename T::iterator i = l.begin();
  ++i;
  ++i;
  l.erase(i);
  access<T>(l)
}

template<typename T>
void erase_range2(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Erase range 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  typename T::iterator m = l.begin();
  ++m;
  ++m;
  typename T::iterator k = l.end();
  --k;
  --k;
  l.erase(m, k);
  access<T>(l)
}

template<typename T>
void erase_range(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Erase range " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.erase(l.begin(), l.end());
  access<T>(l)
}

template<typename T>
void swap_member_function(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Swap member function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.swap(l2);
  access<T>(l)
  access<T>(l2)
}

template<typename T>
void resize_bigger(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Resize bigger " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.resize(l.size() + 1, 9);
  access<T>(l)
}

template<typename T>
void resize_smaller(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Resize smaller " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.resize(l.size() - 3, 0);
  access<T>(l)
}

template<typename T>
void clear(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Clear function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.clear();
  access<T>(l)
}

template<typename T>
void splice_list3(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice entire list 3" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  typename T::iterator i = l.begin();
  ++i;
  ++i;
  l.splice(i, l2);
  access<T>(l)
  access<T>(l2)
}

template<typename T>
void splice_list2(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice entire list 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.splice(l.end(), l2);
  access<T>(l)
  access<T>(l2)
}

template<typename T>
void splice_list(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice entire list " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.splice(l.begin(), l2);
  access<T>(l)
  access<T>(l2)
}

template<typename T>
void splice_single_element4(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice single element 4" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  typename T::iterator i = l2.begin();
  ++i;
  l.splice(l.begin(), l2, l.begin());
  access<T>(l)
  access<T>(l2)
}

template<typename T>
void splice_single_element3(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice single element 3" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  typename T::iterator i = l2.begin();
  ++i;
  l.splice(i, l2, i);
  access<T>(l)
  access<T>(l2)
}

template<typename T>
void splice_single_element2(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice single element 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  typename T::iterator i = l2.end();
  --i;
  --i;
  --i;
  typename T::iterator k = l.end();
  --k;
  --k;
  --k;
  l.splice(k, l2, i);
  access<T>(l)
  access<T>(l2)
}

template<typename T>
void splice_single_element(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice single element " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  typename T::iterator i = l2.begin();
  ++i;
  ++i;
  typename T::iterator k = l.begin();
  ++k;
  ++k;
  l.splice(k, l2, i);
  access<T>(l)
  access<T>(l2)
}

template<typename T>
void splice_range4(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice range 4" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  T tmp((unsigned int)1,1);
  typename T::iterator tmpi = tmp.begin();
  l.splice(tmpi, l2, l2.begin(), l2.end());
  access<T>(l)
  access<T>(l2)
}

template<typename T>
void splice_range3(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice range 3" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  typename T::iterator i = l2.end();
  --i;
  --i;
  --i;
  typename T::iterator k = l2.begin();
  ++k;
  ++k;
  l.splice(l.begin(), l2, k, i);
  access<T>(l)
  access<T>(l2)
}

template<typename T>
void splice_range2(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice range 2" << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  typename T::iterator i = l.end();
  --i;
  --i;
  --i;
  l.splice(i, l2, l2.begin(), l2.end());
  access<T>(l)
  access<T>(l2)
}

template<typename T>
void splice_range(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Splice range " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  typename T::iterator i = l.begin();
  ++i;
  ++i;
  l.splice(i, l2, l2.begin(), l2.end());
  access<T>(l)
  access<T>(l2)
}

template<typename T>
void remove(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Remove function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.remove(5);
  access<T>(l)
}

template<typename T, typename T2>
void remove_if(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Remove_if function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.remove_if(remove_if_test<T2>);
  access<T>(l)
  access<T>(l)
}

template<typename T>
void unique(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Duplicate function default " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.unique();
  access<T>(l)
}

template<typename T, typename T2>
void unique_if(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Duplicate function function parameter " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.unique(unique_test<T2>);
  access<T>(l)
}

template<typename T>
void merge(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Merge function default " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.merge(l2);
  access<T>(l)
  access<T>(l2)
}

template<typename T, typename T2>
void merge_if(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Merge function function parameter " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.merge(l2, merge_test<T2>);
  access<T>(l)
  access<T>(l2)
}

template<typename T>
void sort(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Sort function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.sort();
  access<T>(l)
}

template<typename T, typename T2>
void sort_if(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Sort function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.sort(sort_test<T2>);
  access<T>(l)
}

template<typename T>
void reverse(T l)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Reverse function " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested container: " << std::endl;
  access<T>(l)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  l.reverse();
  access<T>(l)
}

template<typename T>
void swap_non_member_function(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Swap non-member function overload " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Tested containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  swap(l, l2);
  access<T>(l)
  access<T>(l2)
}

template<typename T>
void equal(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Equal operator " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Compared containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  if (l == l2)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;
}

template<typename T>
void non_equal(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Non-equal operator " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Compared containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  if (l != l2)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;
}

template<typename T>
void smaller_than(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Smaller than operator " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Compared containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  if (l < l2)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;
}

template<typename T>
void smaller_than_equal(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Smaller than or equal operator " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Compared containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  if (l <= l2)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;
}

template<typename T>
void bigger_than(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Bigger than operator " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Compared containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  if (l > l2)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;
}

template<typename T>
void bigger_than_equal(T l, T l2)
{
  std::cout << std::setfill ('#') << std::setw (100) << std::left << "Bigger than or equal operator " << std::endl;
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Compared containers: " << std::endl;
  access<T>(l)
  access<T>(l2)
  std::cout << std::setfill ('>') << std::setw (50) << std::left << "Result: " << std::endl;
  if (l >= l2)
    std::cout << "YES" << std::endl;
  else
    std::cout << "NO" << std::endl;
}

#endif
