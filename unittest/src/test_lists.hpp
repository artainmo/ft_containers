#ifndef TEST_LISTS_HPP
#define TEST_LISTS_HPP

#include "../main.hpp"
#include "list_tests.hpp"

template<typename T, typename R, typename T2>
void tests(T l, T l2, R lr, R lr2, std::ofstream &fd_w, std::ifstream &fd_r, std::ofstream &fd_w_r, std::ifstream &fd_r_r, std::ofstream &output_my, std::ofstream &output_real)
{
  std::streambuf *fd_1 = std::cout.rdbuf();
  struct s_functions_ptr1<T> my_func1[31] = {{lempty<T>, 1}, {lfront<T>, 2}, {lback<T>, 3}, {lfill_assign<T>, 4}, {lfill_assign2<T>, 5}, {lpush_front<T>, 6}, \
  {lpop_front<T>, 7}, {lpush_back<T>, 8}, {lpop_back<T>, 9}, {linsert_single_element<T>, 10}, {linsert_single_element2<T>, 11}, {linsert_single_element3<T>, 12}, \
  {linsert_fill<T>, 13}, {linsert_fill2<T>, 14}, {linsert_fill3<T>, 15}, {lerase_single_element<T>, 16}, {lerase_single_element2<T>, 17}, \
  {lerase_range<T>, 18}, {lerase_range2<T>, 19}, {lresize_bigger<T>, 20}, {lresize_smaller<T>, 21}, {lresize_range_bigger<T>, 22}, {lresize_range_smaller<T>, 23}, \
  {lclear<T>, 24}, {lremove<T>, 25}, {lremove_if<T, T2>, 26}, {lunique<T>, 27}, {lunique_if<T, T2>, 28}, {lsort<T>, 29}, {lsort_if<T, T2>, 30}, {lreverse<T>, 31}};
  struct s_functions_ptr2<T> my_func2[26] = {{lassignation_operator<T, T2>, 32}, {lrange_assign<T>, 33}, {lrange_assign2<T>, 34}, {linsert_range<T>, 35}, {linsert_range2<T>, 36}, \
  {linsert_range3<T>, 37}, {lswap_member_function<T>, 38}, {lsplice_list<T>, 39}, {lsplice_list2<T>, 40}, {lsplice_list3<T>, 41}, \
  {lsplice_single_element<T>, 42}, {lsplice_single_element2<T>, 43}, {lsplice_single_element3<T>, 44}, {lsplice_single_element4<T>, 45}, {lsplice_range<T>, 46}, {lsplice_range2<T>, 47}, \
  {lsplice_range3<T>, 48}, {lmerge<T>, 49}, {lmerge_if<T, T2>, 50}, {lswap_non_member_function<T>, 51}, {lequal<T>, 52}, {lnon_equal<T>, 53}, \
  {lsmaller_than<T>, 54}, {lsmaller_than_equal<T>, 55}, {lbigger_than<T>, 56}, {lbigger_than_equal<T>, 57}};
  struct s_functions_ptr1<R> real_func1[31] = {{lempty<R>, 1}, {lfront<R>, 2}, {lback<R>, 3}, {lfill_assign<R>, 4}, {lfill_assign2<R>, 5}, {lpush_front<R>, 6}, \
  {lpop_front<R>, 7}, {lpush_back<R>, 8}, {lpop_back<R>, 9}, {linsert_single_element<R>, 10}, {linsert_single_element2<R>, 11}, {linsert_single_element3<R>, 12}, \
  {linsert_fill<R>, 13}, {linsert_fill2<R>, 14}, {linsert_fill3<R>, 15}, {lerase_single_element<R>, 16}, {lerase_single_element2<R>, 17}, \
  {lerase_range<R>, 18}, {lerase_range2<R>, 19}, {lresize_bigger<R>, 20}, {lresize_smaller<R>, 21}, {lresize_range_bigger<R>, 22}, {lresize_range_smaller<R>, 23}, \
  {lclear<R>, 24}, {lremove<R>, 25}, {lremove_if<R, T2>, 26}, {lunique<R>, 27}, {lunique_if<R, T2>, 28}, {lsort<R>, 29}, {lsort_if<R, T2>, 30}, {lreverse<R>, 31}};
  struct s_functions_ptr2<R> real_func2[26] = {{lassignation_operator<R, T2>, 32}, {lrange_assign<R>, 33}, {lrange_assign2<R>, 34}, {linsert_range<R>, 35}, {linsert_range2<R>, 36}, \
  {linsert_range3<R>, 37}, {lswap_member_function<R>, 38}, {lsplice_list<R>, 39}, {lsplice_list2<R>, 40}, {lsplice_list3<R>, 41}, \
  {lsplice_single_element<R>, 42}, {lsplice_single_element2<R>, 43}, {lsplice_single_element3<R>, 44}, {lsplice_single_element4<R>, 45}, {lsplice_range<R>, 46}, {lsplice_range2<R>, 47}, \
  {lsplice_range3<R>, 48}, {lmerge<R>, 49}, {lmerge_if<R, T2>, 50}, {lswap_non_member_function<R>, 51}, {lequal<R>, 52}, {lnon_equal<R>, 53}, \
  {lsmaller_than<R>, 54}, {lsmaller_than_equal<R>, 55}, {lbigger_than<R>, 56}, {lbigger_than_equal<R>, 57}};

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

template<typename T, typename R, typename T2>
void *pthread_start2(void *args)
{
  struct thread_arg<T, R> *arg;
  arg = (struct thread_arg<T, R> *)args;
  std::ofstream fd_w(std::string("output/tmp_my"));
  std::ifstream fd_r(std::string("output/tmp_my"));
  std::ofstream fd_w_r(std::string("output/tmp_real"));
  std::ifstream fd_r_r(std::string("output/tmp_real"));

  tests<T, R, T2>(arg->my_elems[arg->num1], arg->my_elems[arg->num2], arg->real_elems[arg->num1], arg->real_elems[arg->num2], fd_w, fd_r, fd_w_r, fd_r_r, arg->output_my, arg->output_real);
  fd_w.close();
  fd_r.close();
  fd_w_r.close();
  fd_r_r.close();
  return 0;
}

template<typename T, typename R, typename T2>
void *pthread_start(void *args)
{
  struct thread_arg<T, R> *arg;
  arg = (struct thread_arg<T, R> *)args;
  pthread_t id;

  for (int l = 0; l < arg->test_lenght; l++)
  {
    arg->num2 = l;
    pthread_create(&id, NULL, pthread_start2<T, R, T2>, args);
    pthread_join(id, NULL); //Waits for just created thread to end before continuing, using new threads fastens forks
  }
  return 0;
}

template<typename T, typename R, typename T2>
void list_basis_tests()
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

  struct s_functions_ptr<T> my_func[7] = {{ldefault_constructor<T>, 1}, {lfill_constructor<T>, 2}, {lspecial_fill_constructor<T>, 3}, {lrange_constructor<T>, 4}, {lcopy_constructor<T, T2>, 5}, {literator_tests1<T, T2>, 6}, {literator_tests2<T>, 7}};
  struct s_functions_ptr<T> real_func[7] = {{ldefault_constructor<R>, 1}, {lfill_constructor<R>, 2}, {lspecial_fill_constructor<R>, 3}, {lrange_constructor<R>, 4}, {lcopy_constructor<R, T2>, 5}, {literator_tests1<R, T2>, 6}, {literator_tests2<R>, 7}};

  std::cout << "\033[35m" << "\nConstructors and iterators basis tests:" << std::endl;
  for (int i = 0; i < 7; i++)
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
  std::cout << "\033[35m" << "\nEnd constructors and iterators basis tests\n" << std::endl;

  fd_w.close();
  fd_w_r.close();
  fd_r.close();
  fd_r_r.close();
  output_my.close();
  output_real.close();
}

template<typename T, typename R, typename T2>
void list_test(T *my_elems, R *real_elems, int test_lenght)
{
  //Create fds to output files
  std::ofstream fd_w("output/tmp_my");
  std::ifstream fd_r("output/tmp_my");
  std::ofstream fd_w_r("output/tmp_real");
  std::ifstream fd_r_r("output/tmp_real");
  std::ofstream output_my("output/list");
  std::ofstream output_real("output/real");

  int fd_2 = dup(2);
  int dev_null = open("/dev/null", O_CREAT | O_WRONLY); // /dev/null Discards all data written to it, open and dup are used instead of c++ cerr object because it does not work...

  struct thread_arg<T, R> args = { 0, 0, my_elems, real_elems, output_my, output_real, test_lenght};
  pthread_t id;

  std::cout << "\033[35m" << "Functions tests:" << std::endl;
  dup2(dev_null, 2); //Redirect stderr to dev/null (a file that discards input) => avoid non-catchable "malloc not allocated error" output in stdin
  for (int i = 0; i < test_lenght; i++) //Do all tests
  {
    args.num1 = i;
    pthread_create(&id, NULL, pthread_start<T, R, T2>, &args);
    pthread_join(id, NULL); //Waits for just created thread to end before continuing, using new threads fastens forks
  }
  dup2(2, fd_2); //Reset stderr
  std::cout << "\033[35m" << "\nEnd functions tests\n" << std::endl;
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
