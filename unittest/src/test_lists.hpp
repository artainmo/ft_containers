#ifndef TEST_LISTS_HPP
#define TEST_LISTS_HPP

#include "../main.hpp"
#include "list_tests.hpp"

template<typename T, typename R, typename T2>
void tests(T l, T l2, std::ofstream &fd_w, R lr, R lr2, std::ofstream &fd_w_r)
{
  std::streambuf *fd_1 = std::cout.rdbuf();
  streambuf *fd_my = fd_w.rdbuf();
  streambuf *fd_real = fd_w_r.rdbuf();
  int fd_2;
  int dev_null = open("/dev/null", O_CREAT | O_WRONLY); //comment dup action to debug

  struct s_functions_ptr1<T> func2[34] = {{empty<T>}, {max_size<T>}, {front<T>}, {back<T>}, {fill_assign<T>}, {fill_assign2<T>}, {push_front<T>}, \
  {pop_front<T>}, {push_back<T>}, {pop_back<T>}, {insert_single_element<T>}, {insert_single_element2<T>}, {insert_single_element3<T>}, {insert_single_element4<T>}, \
  {insert_fill<T>}, {insert_fill2<T>}, {insert_fill3<T>}, {insert_fill4<T>}, {erase_single_element<T>}, {erase_single_element2<T>}, {erase_single_element3<T>}, \
  {erase_single_element4<T>}, {erase_range<T>}, {erase_range2<T>}, {resize_bigger<T>}, {resize_smaller<T>},{clear<T>}, {remove<T>}, {remove_if<T, T2>}, {unique<T>}, \
  {unique_if<T, T2>}, {sort<T>}, {sort_if<T, T2>}, {reverse<T>}};
  struct s_functions_ptr2<T> func3[27] = {{assignation_operator<T, T2>}, {range_assign<T>}, {range_assign2<T>}, {insert_range<T>}, {insert_range2<T>}, \
  {insert_range3<T>}, {swap_member_function<T>}, {splice_list<T>}, {splice_list2<T>}, {splice_list3<T>}, \
  {splice_single_element<T>}, {splice_single_element2<T>}, {splice_single_element3<T>}, {splice_single_element4<T>}, {splice_range<T>}, {splice_range2<T>}, \
  {splice_range3<T>}, {splice_range4<T>}, {merge<T>}, {merge_if<T, T2>}, {swap_non_member_function<T>}, {equal<T>}, {non_equal<T>}, \
  {smaller_than<T>}, {smaller_than_equal<T>}, {bigger_than<T>}, {bigger_than_equal<T>}};

  std::cout << "\033[35m" << "Functions tests:" << std::endl;
  for (int i = 0; i < 61 ; i++) //Functions with two parameters
  {
    pid_t pid = fork();

    if (pid == 0)
    {
      std::cout << "\033[36m" << i << ' ';
      fflush(stdout); //Necessary otherwise bug occurs if not using \n that naturally flushes the buffer
      fd_2 = dup(2); //Store copy of stderr
      dup2(dev_null, 2); //Redirect stderr to dev/null (a file that discards input) => avoid non-catchable "malloc not allocated error" output in stdin
      if (i < 34)
      {
        std::cout.rdbuf(fd_my);
        func2[i].function_pointer(l);
        std::cout.rdbuf(fd_1);
      }
      else
        func3[i - 34].function_pointer(l, l2);
      dup2(2, fd_2); //Reset stderr
      close(fd_2);
      close(dev_null);
      exit(0);
    }
    wait(NULL);
  }
  fd_1.close();
  std::cout << "\033[35m" << "\nEnd functions tests\n" << std::endl;
}



template<typename T, typename R, typename T2>
void list_test()
{
  //Test constructors
  struct s_functions_ptr<T> my_func[5] = {{default_constructor<T>}, {fill_constructor<T>}, {special_fill_constructor<T>}, {range_constructor<T>}, {copy_constructor<T, T2>}};
  struct s_functions_ptr<T> real_func[5] = {{default_constructor<R>}, {fill_constructor<R>}, {special_fill_constructor<R>}, {range_constructor<R>}, {copy_constructor<R, T2>}};

  std::cout << "\033[35m" << "\nConstructors tests:" << std::endl;
  for (int i = 0; i < 6; i++)
  {
    pid_t pid = fork();

    if (pid == 0)
    {
      std::cout << "\033[36m" << i << ' ';
      fflush(stdout);
      my_func[i].function_pointer();
      real_func[i].function_pointer()
      exit(0);
    }
    wait(NULL);
  }
  std::cout << "\033[35m" << "\nEnd constructors tests\n" << std::endl;

  std::cout << "\033[35m" << "Container object creation:" << std::endl;
  T l1;
  std::cout << "\033[36m" << "1 ";
  T l2((unsigned int)10, 5);
  std::cout << "\033[36m" << "2 ";
  T l3((unsigned int)4, 8);
  std::cout << "\033[36m" << "3 ";
  T l4((unsigned int)3, 1);
  std::cout << "\033[36m" << "4 ";
  T l5;
  std::cout << "\033[36m" << "5 ";
  l5.push_back(0);
  std::cout << "\033[36m" << "6 ";
  l5.push_back(1);
  std::cout << "\033[36m" << "7 ";
  l5.push_back(2);
  std::cout << "\033[36m" << "8 ";
  l5.push_back(3);
  std::cout << "\033[36m" << "9 ";
  l5.push_back(4);
  std::cout << "\033[36m" << "10 ";
  l5.push_back(5);
  std::cout << "\033[36m" << "11 ";
  T l6;
  std::cout << "\033[36m" << "12 ";
  l6.push_back(5);
  std::cout << "\033[36m" << "13 ";
  l6.push_back(4);
  std::cout << "\033[36m" << "14 ";
  l6.push_back(3);
  std::cout << "\033[36m" << "15 ";
  l6.push_back(2);
  std::cout << "\033[36m" << "16 ";
  l6.push_back(1);
  std::cout << "\033[36m" << "17 ";
  l6.push_back(0);
  std::cout << "\033[36m" << "18 ";
  T l7((unsigned int)3, 3);
  std::cout << "\033[36m" << "19 ";
  l7.push_back(8);
  std::cout << "\033[36m" << "20 ";
  l7.push_front(8);
  std::cout << "\033[36m" << "21 ";
  T l8((unsigned int)1, 4);
  std::cout << "\033[36m" << "22 ";
  T l9((unsigned int)0, 4);
  std::cout << "\033[36m" << "23 ";
  T l10;
  std::cout << "\033[36m" << "24 ";
  l10.push_back(4);
  std::cout << "\033[36m" << "25 ";
  l10.push_back(7);
  std::cout << "\033[36m" << "26 ";
  l10.push_back(3);
  std::cout << "\033[36m" << "27 ";
  l10.push_back(9);
  std::cout << "\033[36m" << "28 ";
  l10.push_back(2);
  std::cout << "\033[36m" << "29 " << std::endl;
  l10.push_back(8);
  std::cout << "\033[35m" << "End of container object creation\n" << std::endl;

  // tests<T, T2>(l7, l2, fd_w); //Do simple tests
  tests<T, T2>(l1, l1, fd_w); //Do simple tests
  // T elems[10] = { l1, l2, l3, l4, l5, l6, l7, l8, l9, l10}; //Do all tests
  // for (int i = 0; i < 10; i++)
  // {
  //   for (int l = 0; l < 10; l++)
  //     tests<T, T2>(elems[i], elems[l], fd_w);
  // }
  fd_w.close();
  fd_w_r.close();
  fd_r.close();
  fd_r_r.close();
}

#endif
