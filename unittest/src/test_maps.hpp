#ifndef TEST_MAPS_HPP
#define TEST_MAPS_HPP

#include "../main.hpp"
#include "map_tests.hpp"

template<typename T, typename R, typename T2>
void tests(T l, T l2, R lr, R lr2, std::ofstream &fd_w, std::ifstream &fd_r, std::ofstream &fd_w_r, std::ifstream &fd_r_r, std::ofstream &output_my, std::ofstream &output_real)
{
  std::streambuf *fd_1 = std::cout.rdbuf();
  struct s_functions_ptr1<T> my_func1[22] = {{mempty<T>, 1}, {melement_access<T>, 2}, {melement_access2<T>, 3}, {minsert_single_element<T, T1, T2>, 4}, \
  {minsert_single_element2<T, T1, T2>, 5}, {minsert_single_element3<T, T1, T2>, 6}, {minsert_hint<T, T1, T2>, 7}, {minsert_hint2<T, T1, T2>, 8}, \
  {minsert_hint3<T, T1, T2>, 9}, {merase_iterator_based<T>, 10}, {merase_iterator_based2<T>, 11}, {merase_key_based<T>, 12}, {merase_range<T>, 13}, \
  {merase_range2<T>, 14}, {mclear<T>, 15}, {mkey_compare<T>, 16}, {mvalue_compare<T>, 17}, {mfind<T>, 18}, {mcount<T>, 19}, {mlower_bound<T>, 20}, \
  {mupper_bound<T>, 21}, {mequal_range<T>, 22}};
  struct s_functions_ptr2<T> my_func2[5] = {{massignation_operator<T, T2>, 23}, {minsert_range<T>, 24}, {minsert_range2<T>, 25}, {minsert_range3<T>, 26}, \
  {mswap_member_function<T>, 27}};
  struct s_functions_ptr1<T> real_func1[22] = {{mempty<R>, 1}, {melement_access<R>, 2}, {melement_access2<R>, 3}, {minsert_single_element<R, T1, T2>, 4}, \
  {minsert_single_element2<R, T1, T2>, 5}, {minsert_single_element3<R, T1, T2>, 6}, {minsert_hint<R, T1, T2>, 7}, {minsert_hint2<R, T1, T2>, 8}, \
  {minsert_hint3<R, T1, T2>, 9}, {merase_iterator_based<R>, 10}, {merase_iterator_based2<R>, 11}, {merase_key_based<R>, 12}, {merase_range<R>, 13}, \
  {merase_range2<R>, 14}, {mclear<R>, 15}, {mkey_compare<R>, 16}, {mvalue_compare<R>, 17}, {mfind<R>, 18}, {mcount<R>, 19}, {mlower_bound<R>, 20}, \
  {mupper_bound<R>, 21}, {mequal_range<R>, 22}};
  struct s_functions_ptr2<T> real_func2[5] = {{massignation_operator<R, T2>, 23}, {minsert_range<R>, 24}, {minsert_range2<R>, 25}, {minsert_range3<R>, 26}, \
  {mswap_member_function<R>, 27}};

  for (unsigned int i = 0; i < 27 ; i++)
  {
    if (i < 22) //Functions with one parameter
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
      safe_space_test<R>(real_func2, i - 22, lr, lr2, fd_w_r); //Call real
      safe_space_test<T>(my_func2, i - 22, l, l2, fd_w); //Call own
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
void map_basis_tests()
{
  //Create fds to output files
  std::ofstream fd_w("output/tmp_my");
  std::ifstream fd_r("output/tmp_my");
  std::ofstream fd_w_r("output/tmp_real");
  std::ifstream fd_r_r("output/tmp_real");
  std::ofstream output_my("output/map");
  std::ofstream output_real("output/real");

  //Create streambuffers to redirect output
  std::streambuf *fd_1 = std::cout.rdbuf();
  std::streambuf *fd_my = fd_w.rdbuf();
  std::streambuf *fd_real = fd_w_r.rdbuf();

  struct s_functions_ptr<T> my_func[7] = {{mdefault_constructor<T>, 1}, {mrange_constructor<T, T1, T2>, 2}, {mcopy_constructor<T, T2>, 3}, {miterator_tests1<T, T1, T2>, 4}};
  struct s_functions_ptr<T> real_func[7] = {{mdefault_constructor<R>, 1}, {mrange_constructor<R, T1, T2>, 2}, {mcopy_constructor<R, T2>, 3}, {miterator_tests1<R, T1, T2>, 4}};

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

template<typename T, typename R, typename T1, typename T2>
void map_test(T *my_elems, R *real_elems, int test_lenght)
{
  //Create fds to output files
  std::ofstream fd_w("output/tmp_my");
  std::ifstream fd_r("output/tmp_my");
  std::ofstream fd_w_r("output/tmp_real");
  std::ifstream fd_r_r("output/tmp_real");
  std::ofstream output_my("output/map");
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
