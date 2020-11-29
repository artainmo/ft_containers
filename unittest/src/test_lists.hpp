#ifndef TEST_LISTS_HPP
#define TEST_LISTS_HPP

#include "../main.hpp"
#include "list_tests.hpp"

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

template<typename T, typename R, typename T2>
void tests(T l, T l2, R lr, R lr2, std::ofstream &fd_w, std::ifstream &fd_r, std::ofstream &fd_w_r, std::ifstream &fd_r_r, std::ofstream &output_my, std::ofstream &output_real)
{
  std::streambuf *fd_1 = std::cout.rdbuf();
  struct s_functions_ptr1<T> my_func1[31] = {{empty<T>, 1}, {front<T>, 2}, {back<T>, 3}, {fill_assign<T>, 4}, {fill_assign2<T>, 5}, {push_front<T>, 6}, \
  {pop_front<T>, 7}, {push_back<T>, 8}, {pop_back<T>, 9}, {insert_single_element<T>, 10}, {insert_single_element2<T>, 11}, {insert_single_element3<T>, 12}, \
  {insert_fill<T>, 13}, {insert_fill2<T>, 14}, {insert_fill3<T>, 15}, {erase_single_element<T>, 16}, {erase_single_element2<T>, 17}, \
  {erase_range<T>, 18}, {erase_range2<T>, 19}, {resize_bigger<T>, 20}, {resize_smaller<T>, 21}, {resize_range_bigger<T>, 22}, {resize_range_smaller<T>, 23}, \
  {clear<T>, 24}, {remove<T>, 25}, {remove_if<T, T2>, 26}, {unique<T>, 27}, {unique_if<T, T2>, 28}, {sort<T>, 29}, {sort_if<T, T2>, 30}, {reverse<T>, 31}};
  struct s_functions_ptr2<T> my_func2[26] = {{assignation_operator<T, T2>, 32}, {range_assign<T>, 33}, {range_assign2<T>, 34}, {insert_range<T>, 35}, {insert_range2<T>, 36}, \
  {insert_range3<T>, 37}, {swap_member_function<T>, 38}, {splice_list<T>, 39}, {splice_list2<T>, 40}, {splice_list3<T>, 41}, \
  {splice_single_element<T>, 42}, {splice_single_element2<T>, 43}, {splice_single_element3<T>, 44}, {splice_single_element4<T>, 45}, {splice_range<T>, 46}, {splice_range2<T>, 47}, \
  {splice_range3<T>, 48}, {merge<T>, 49}, {merge_if<T, T2>, 50}, {swap_non_member_function<T>, 51}, {equal<T>, 52}, {non_equal<T>, 53}, \
  {smaller_than<T>, 54}, {smaller_than_equal<T>, 55}, {bigger_than<T>, 56}, {bigger_than_equal<T>, 57}};
  struct s_functions_ptr1<R> real_func1[31] = {{empty<R>, 1}, {front<R>, 2}, {back<R>, 3}, {fill_assign<R>, 4}, {fill_assign2<R>, 5}, {push_front<R>, 6}, \
  {pop_front<R>, 7}, {push_back<R>, 8}, {pop_back<R>, 9}, {insert_single_element<R>, 10}, {insert_single_element2<R>, 11}, {insert_single_element3<R>, 12}, \
  {insert_fill<R>, 13}, {insert_fill2<R>, 14}, {insert_fill3<R>, 15}, {erase_single_element<R>, 16}, {erase_single_element2<R>, 17}, \
  {erase_range<R>, 18}, {erase_range2<R>, 19}, {resize_bigger<R>, 20}, {resize_smaller<R>, 21}, {resize_range_bigger<R>, 22}, {resize_range_smaller<R>, 23}, \
  {clear<R>, 24}, {remove<R>, 25}, {remove_if<R, T2>, 26}, {unique<R>, 27}, {unique_if<R, T2>, 28}, {sort<R>, 29}, {sort_if<R, T2>, 30}, {reverse<R>, 31}};
  struct s_functions_ptr2<R> real_func2[26] = {{assignation_operator<R, T2>, 32}, {range_assign<R>, 33}, {range_assign2<R>, 34}, {insert_range<R>, 35}, {insert_range2<R>, 36}, \
  {insert_range3<R>, 37}, {swap_member_function<R>, 38}, {splice_list<R>, 39}, {splice_list2<R>, 40}, {splice_list3<R>, 41}, \
  {splice_single_element<R>, 42}, {splice_single_element2<R>, 43}, {splice_single_element3<R>, 44}, {splice_single_element4<R>, 45}, {splice_range<R>, 46}, {splice_range2<R>, 47}, \
  {splice_range3<R>, 48}, {merge<R>, 49}, {merge_if<R, T2>, 50}, {swap_non_member_function<R>, 51}, {equal<R>, 52}, {non_equal<R>, 53}, \
  {smaller_than<R>, 54}, {smaller_than_equal<R>, 55}, {bigger_than<R>, 56}, {bigger_than_equal<R>, 57}};

  for (unsigned int i = 0; i < 57 ; i++)
  {
    if (i < 31) //Functions with one parameter
    {
      std::cout << "\033[30m" << real_func1[i].num << ' ';
      fflush(stdout); //Necessary otherwise bug occurs if not using \n that naturally flushes the buffer
      safe_space_test<R>(real_func1, i, lr, fd_w_r); //Call real
      safe_space_test<T>(my_func1, i, l, fd_w); //Call own
      std::cout.rdbuf(fd_1); //Reset stream 1
    }
    else //Functions with two parameters
    {
      std::cout << "\033[30m" << real_func2[i - 31].num << ' ';
      fflush(stdout); //Necessary otherwise bug occurs if not using \n that naturally flushes the buffer
      safe_space_test<R>(real_func2, i - 31, lr, lr2, fd_w_r); //Call real
      safe_space_test<T>(my_func2, i - 31, l, l2, fd_w); //Call own
      std::cout.rdbuf(fd_1); //Reset stream 1
    }
    check_answer(fd_r, fd_r_r, output_my, output_real);
  }
}

template<typename T>
T *container_object_creation()
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

template<typename T, typename R>
struct thread_arg
{
  int num;
  T *my_elems;
  R *real_elems;
  std::ofstream &output_my;
  std::ofstream &output_real;
};

template<typename T, typename R, typename T2>
void *pthread_start(void *args)
{
  struct thread_arg<T, R> *arg;
  arg = (struct thread_arg<T, R> *)args;
  std::ofstream fd_w(std::string("output/tmp_my"));
  std::ifstream fd_r(std::string("output/tmp_my"));
  std::ofstream fd_w_r(std::string("output/tmp_real"));
  std::ifstream fd_r_r(std::string("output/tmp_real"));

  for (int l = 0; l < 8; l++)
    tests<T, R, T2>(arg->my_elems[arg->num], arg->my_elems[l], arg->real_elems[arg->num], arg->real_elems[l], fd_w, fd_r, fd_w_r, fd_r_r, arg->output_my, arg->output_real);
  return 0;
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
  int fd_2 = dup(2);
  int dev_null = open("/dev/null", O_CREAT | O_WRONLY); // /dev/null Discards all data written to it, open and dup are used instead of c++ cerr object because it does not work...
  std::streambuf *fd_my = fd_w.rdbuf();
  std::streambuf *fd_real = fd_w_r.rdbuf();

  struct s_functions_ptr<T> my_func[5] = {{default_constructor<T>, 1}, {fill_constructor<T>, 2}, {special_fill_constructor<T>, 3}, {range_constructor<T>, 4}, {copy_constructor<T, T2>, 5}};
  struct s_functions_ptr<T> real_func[5] = {{default_constructor<R>, 1}, {fill_constructor<R>, 2}, {special_fill_constructor<R>, 3}, {range_constructor<R>, 4}, {copy_constructor<R, T2>, 5}};

  std::cout << "\033[35m" << "\nConstructors tests:" << std::endl;
  for (int i = 0; i < 5; i++)
  {
    pid_t pid = fork();

    if (pid == 0)
    {
      std::cout << "\033[30m" << real_func[i].num << ' ';
      fflush(stdout); //Necessary otherwise bug occurs if not using \n that naturally flushes the buffer
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

  struct thread_arg<T, R> args = { 0, my_elems, real_elems, output_my, output_real};
  pthread_t id;

  std::cout << "\033[35m" << "Functions tests:" << std::endl;
  dup2(dev_null, 2); //Redirect stderr to dev/null (a file that discards input) => avoid non-catchable "malloc not allocated error" output in stdin
  for (int i = 0; i < 8; i++) //Do all tests
  {
    args.num = i;
    pthread_create(&id, NULL, pthread_start<T, R, T2>, &args);
    pthread_join(id, NULL); //Waits for just created thread to end before continuing, using new threads fastens forks
  }
  dup2(2, fd_2); //Reset stderr
  std::cout << "\033[35m" << "\nEnd functions tests\n" << std::endl;
  fflush(stdout);
  std::cout << "\033[34m" << G_ERROR_COUNT << " ERRORS ATTAINED ON "<< G_LINE << " TESTS" << std::endl;
  fflush(stdout);

  delete [] my_elems;
  delete [] real_elems;
  fd_w.close();
  fd_w_r.close();
  fd_r.close();
  fd_r_r.close();
  output_my.close();
  output_real.close();
  close(fd_2);
  close(dev_null);
}

#endif
