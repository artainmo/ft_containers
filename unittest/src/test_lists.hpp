#ifndef TEST_LISTS_HPP
#define TEST_LISTS_HPP

#include "../main.hpp"
#include "list_tests.hpp"

template<typename T, typename R, typename T2>
void tests(T l, T l2, R lr, R lr2, std::ofstream &fd_w, std::ifstream &fd_r, std::ofstream &fd_w_r, std::ifstream &fd_r_r, std::ofstream &output_my, std::ofstream &output_real)
{
  std::streambuf *fd_1 = std::cout.rdbuf();
  int fd_2 = dup(2);
  std::streambuf *fd_my = fd_w.rdbuf();
  std::streambuf *fd_real = fd_w_r.rdbuf();
  int dev_null = open("/dev/null", O_CREAT | O_WRONLY); // /dev/null Discards all data written to it, open and dup are used instead of c++ cerr object because it does not work...

  struct s_functions_ptr1<T> my_func1[36] = {{empty<T>}, {max_size<T>}, {front<T>}, {back<T>}, {fill_assign<T>}, {fill_assign2<T>}, {push_front<T>}, \
  {pop_front<T>}, {push_back<T>}, {pop_back<T>}, {insert_single_element<T>}, {insert_single_element2<T>}, {insert_single_element3<T>}, {insert_single_element4<T>}, \
  {insert_fill<T>}, {insert_fill2<T>}, {insert_fill3<T>}, {insert_fill4<T>}, {erase_single_element<T>}, {erase_single_element2<T>}, {erase_single_element3<T>}, \
  {erase_single_element4<T>}, {erase_range<T>}, {erase_range2<T>}, {resize_bigger<T>}, {resize_smaller<T>}, {resize_range_bigger<T>}, {resize_range_smaller<T>}, \
  {clear<T>}, {remove<T>}, {remove_if<T, T2>}, {unique<T>}, {unique_if<T, T2>}, {sort<T>}, {sort_if<T, T2>}, {reverse<T>}};
  struct s_functions_ptr2<T> my_func2[27] = {{assignation_operator<T, T2>}, {range_assign<T>}, {range_assign2<T>}, {insert_range<T>}, {insert_range2<T>}, \
  {insert_range3<T>}, {swap_member_function<T>}, {splice_list<T>}, {splice_list2<T>}, {splice_list3<T>}, \
  {splice_single_element<T>}, {splice_single_element2<T>}, {splice_single_element3<T>}, {splice_single_element4<T>}, {splice_range<T>}, {splice_range2<T>}, \
  {splice_range3<T>}, {splice_range4<T>}, {merge<T>}, {merge_if<T, T2>}, {swap_non_member_function<T>}, {equal<T>}, {non_equal<T>}, \
  {smaller_than<T>}, {smaller_than_equal<T>}, {bigger_than<T>}, {bigger_than_equal<T>}};
  struct s_functions_ptr1<R> real_func1[36] = {{empty<R>}, {max_size<R>}, {front<R>}, {back<R>}, {fill_assign<R>}, {fill_assign2<R>}, {push_front<R>}, \
  {pop_front<R>}, {push_back<R>}, {pop_back<R>}, {insert_single_element<R>}, {insert_single_element2<R>}, {insert_single_element3<R>}, {insert_single_element4<R>}, \
  {insert_fill<R>}, {insert_fill2<R>}, {insert_fill3<R>}, {insert_fill4<R>}, {erase_single_element<R>}, {erase_single_element2<R>}, {erase_single_element3<R>}, \
  {erase_single_element4<R>}, {erase_range<R>}, {erase_range2<R>}, {resize_bigger<R>}, {resize_smaller<R>}, {resize_range_bigger<R>}, {resize_range_smaller<R>}, \
  {clear<R>}, {remove<R>}, {remove_if<R, T2>}, {unique<R>}, {unique_if<R, T2>}, {sort<R>}, {sort_if<R, T2>}, {reverse<R>}};
  struct s_functions_ptr2<R> real_func2[27] = {{assignation_operator<R, T2>}, {range_assign<R>}, {range_assign2<R>}, {insert_range<R>}, {insert_range2<R>}, \
  {insert_range3<R>}, {swap_member_function<R>}, {splice_list<R>}, {splice_list2<R>}, {splice_list3<R>}, \
  {splice_single_element<R>}, {splice_single_element2<R>}, {splice_single_element3<R>}, {splice_single_element4<R>}, {splice_range<R>}, {splice_range2<R>}, \
  {splice_range3<R>}, {splice_range4<R>}, {merge<R>}, {merge_if<R, T2>}, {swap_non_member_function<R>}, {equal<R>}, {non_equal<R>}, \
  {smaller_than<R>}, {smaller_than_equal<R>}, {bigger_than<R>}, {bigger_than_equal<R>}};

  std::cout << "\033[35m" << "Functions tests:" << std::endl;
  for (int i = 0; i < 63 ; i++)
  {
    pid_t pid = fork();

    if (pid == 0)
    {
      // std::cout << "\033[30m" << i << ' ';
      // fflush(stdout); //Necessary otherwise bug occurs if not using \n that naturally flushes the buffer
      dup2(dev_null, 2); //Redirect stderr to dev/null (a file that discards input) => avoid non-catchable "malloc not allocated error" output in stdin
      if (i < 34) //Functions with one parameter
      {
        std::cout.rdbuf(fd_real);  //Redirect cout or stream 1 to file
        real_func1[i].function_pointer(lr); //Call real
        std::cout.rdbuf(fd_my);
        my_func1[i].function_pointer(l); //Call own
        std::cout.rdbuf(fd_1); //Reset stream 1
      }
      else //Functions with two parameters
      {
        std::cout.rdbuf(fd_real);
        real_func2[i - 34].function_pointer(lr, lr2);
        std::cout.rdbuf(fd_my);
        my_func2[i - 34].function_pointer(l, l2);
        std::cout.rdbuf(fd_1); //Reset stream 1
      }
      dup2(2, fd_2); //Reset stderr
      exit(0);
    }
    wait(NULL);
    check_answer(fd_r, fd_r_r, output_my, output_real);
  }
  close(fd_2);
  close(dev_null);
  std::cout << "\033[35m" << "\nEnd functions tests\n" << std::endl;
}

template<typename T>
T *container_object_creation()
{
  T *my_elems = new T[10];

  T l1; //Empty
  std::cout << "\033[30m" << "1 ";

  T l2((unsigned int)25, 5); //Long same values
  std::cout << "\033[30m" << "2 ";

  T l3; // 4 values
  l3.push_back(1);
  l3.push_back(4);
  l3.push_back(3);
  l3.push_back(8);
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

  T l9((unsigned int)0, 4); //Size 0
  std::cout << "\033[30m" << "45 ";

  T l10; //Same front and end value
  std::cout << "\033[30m" << "47 ";
  l10.push_back(8);
  std::cout << "\033[30m" << "48 ";
  l10.push_back(7);
  std::cout << "\033[30m" << "49 ";
  l10.push_back(3);
  std::cout << "\033[30m" << "50 ";
  l10.push_back(9);
  std::cout << "\033[30m" << "51 ";
  l10.push_back(2);
  std::cout << "\033[30m" << "52 ";
  l10.push_back(8);

  my_elems[0] = l7;
  my_elems[1] = l8;
  my_elems[2] = l3;
  my_elems[3] = l4;
  my_elems[4] = l5;
  my_elems[5] = l6;
  my_elems[6] = l1;
  my_elems[7] = l2;
  my_elems[8] = l9;
  my_elems[9] = l10;

  return my_elems;
}

template<typename T, typename R, typename T2>
void list_test()
{
  //Create fds to output files
  std::ofstream fd_w("output/tmp_my");
  std::ifstream fd_r("output/tmp_my");
  std::ofstream fd_w_r("output/tmp_real");
  std::ifstream fd_r_r("output/tmp_real");
  std::ofstream output_my("output/list");
  std::ofstream output_real("output/real");

  //Create streambuffers to redirect output
  std::streambuf *fd_1 = std::cout.rdbuf();
  std::streambuf *fd_my = fd_w.rdbuf();
  std::streambuf *fd_real = fd_w_r.rdbuf();

  struct s_functions_ptr<T> my_func[5] = {{default_constructor<T>}, {fill_constructor<T>}, {special_fill_constructor<T>}, {range_constructor<T>}, {copy_constructor<T, T2>}};
  struct s_functions_ptr<T> real_func[5] = {{default_constructor<R>}, {fill_constructor<R>}, {special_fill_constructor<R>}, {range_constructor<R>}, {copy_constructor<R, T2>}};

  std::cout << "\033[35m" << "\nConstructors tests:" << std::endl;
  for (int i = 0; i < 6; i++)
  {
    pid_t pid = fork();

    if (pid == 0)
    {
      // std::cout << "\033[30m" << i << ' ';
      // fflush(stdout); //Necessary otherwise bug occurs if not using \n that naturally flushes the buffer
      std::cout.rdbuf(fd_real);
      real_func[i].function_pointer(); //Call real
      std::cout.rdbuf(fd_my); //Redirect cout or stream 1 to file
      my_func[i].function_pointer(); //Call own
      std::cout.rdbuf(fd_1); //Reset stream 1
      exit(0);
    }
    wait(NULL);
    check_answer(fd_r, fd_r_r, output_my, output_real);
  }
  std::cout << "\033[35m" << "\nEnd constructors tests\n" << std::endl;

  std::cout << "\033[1m\033[30m" << "Container object creation you:" << std::endl;
  T *my_elems = container_object_creation<T>();
  std::cout << "\033[1m\033[30m" << "End of container object creation\n" << std::endl;
  std::cout << "\033[1m\033[30m" << "Container object creation real:" << std::endl;
  R *real_elems = container_object_creation<R>();
  std::cout << "\033[1m\033[30m" << "End of container object creation\n" << std::endl;

  for (int i = 0; i < 10; i++) //Do all tests
  {
    for (int l = 0; l < 10; l++)
      tests<T, R, T2>(my_elems[i], my_elems[l], real_elems[i], real_elems[l], fd_w, fd_r, fd_w_r, fd_r_r, output_my, output_real);
  }

  delete [] my_elems;
  delete [] real_elems;
  fd_w.close();
  fd_w_r.close();
  fd_r.close();
  fd_r_r.close();
  output_my.close();
  output_real.close();
}

#endif
