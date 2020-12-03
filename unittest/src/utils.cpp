#include "../main.hpp"

void segfault( int signum ) { std::cout << "SEGFAULT" << std::endl; exit(signum); } //Catch segfaults and write in correct fd
void sigabort( int signum ) { std::cout << "SIGABORT" << std::endl; exit(signum); } //Catch sigaborts and write in correct fd
void sigquit(int sig) { sig = 0; exit(sig); } //SIGQUIT send from childprocess to stop program does not return error code

std::string itoa(int num) //c++ has no itoa!! Only c++11 has itoa equivalent
{
  std::string s;
  std::stringstream out;

  out << num;
  s = out.str();
  return s;
}

int G_ERROR_COUNT = 0; //Lifetime end is not scope but whole program as assigned in static memory
int G_LINE = 0; //By knowing how much lines/tests you went through you can view your progress

void check_answer(std::ifstream &fd_r, std::ifstream &fd_r_r, std::ofstream &output_my, std::ofstream &output_real) //Check all lines takes the test name and compares following test output
{
  std::string me;
  std::string real;
  std::string tmp_me;
  std::string tmp_real;
  int error = 0;

  //Take file input tmp_my and tmp_real into string objects
  while(getline(fd_r_r, tmp_real))
  {
    G_LINE++;
    getline(fd_r, tmp_me);
    if (std::strcmp(tmp_real.c_str(), tmp_me.c_str()) == 0) //c++ string compare function bizarre bug returning errors once we start writing in output fds, c strcmp does not bug
    {
      std::cout << "\033[1m\033[32m" << "<>" << " "; //Use green color code
      fflush(stdout);
    }
    else
    {
      std::cout << "\033[1m\033[31m" << "<>" << " "; //Use red color code
      fflush(stdout);
      error = 1;
    }
    me += tmp_me + '\n';
    real += tmp_real + '\n';
  }

  //Clear the file by truncating it at opening
  fd_r.close();
  fd_r_r.close();
  fd_r.open("output/tmp_my", std::ofstream::out | std::ofstream::trunc);
  fd_r_r.open("output/tmp_real", std::ofstream::out | std::ofstream::trunc);

  if (error != 0) //Write errors to output files and check error limit
  {
    G_ERROR_COUNT++;
    output_my << me << std::endl;
    output_real << real << std::endl;
    if (G_ERROR_COUNT >= G_ERROR_LIMIT)
    {
      int dev_null = open("/dev/null", O_CREAT | O_WRONLY);
      feedback();
      dup2(dev_null, 1); //Bizarre bug whereby continues writing numbers after error message, resolved
      std::remove("output/tmp_my");
      std::remove("output/tmp_real");
      kill(0, SIGQUIT);
    }
  }
}

void feedback()
{
  float total;

  if (G_LIST == 1)
    total = LIST_TOTAL_TESTS;
  if (G_MAP == 1)
    total = MAP_TOTAL_TESTS;
  if (G_QUEUE == 1)
    total = QUEUE_TOTAL_TESTS;
  if (G_STACK == 1)
    total = STACK_TOTAL_TESTS;
  if (G_VECTOR == 1)
    total = VECTOR_TOTAL_TESTS;
  std::cout << "\033[34m" << G_ERROR_COUNT << " ERRORS ATTAINED ON "<< G_LINE << " TESTS" << std::endl;
  fflush(stdout);
  float correct_answers = G_LINE - G_ERROR_COUNT;
  std::cout << "\033[34m" << "------> " << std::setprecision(3) << (correct_answers / total) * 100 << "%" << std::endl;
  fflush(stdout);
}

// void test_queue(std::ofstream fd_w)
// {
//   P("~~~~~~~QUEUE~~~~~~~~\n");
//   //Contruction and iterators
//   P("CONSTRUCTORS");
//   P("Construction of queue container");
//   ft::queue<int> q1;
//   P(q1.size());
//   P("Filling FIFO style (First in first out, thus filling at end erasing from beginning)");
//   q1.push(2);
//   q1.push(5);
//   q1.push(5);
//   q1.push(7);
//   q1.push(8);
//   show_queue<int>(q1);
//   P("Create a copy of last queue and show content");
//   ft::queue<int> q2(q1);
//   show_queue<int>(q2);
//   P("Assign first queue to new one and show content");
//   ft::queue<int> q3;
//   q3 = q1;
//   show_queue<int>(q3);
//   P("");
//
//   //Capacity
//   P("CAPACITY");
//   P("Empty function on last queue and empty queue");
//   if (q3.empty() == false) //Returns false if not empty
//     P("false");
//   ft::queue<int> q4;
//   if (q4.empty() == true) //Returns true if empty
//     P("true");
//   q4 = q3;
//   P("Size function on last queue");
//   P(q3.size());
//   P("");
//
//   //Element access
//   P("ELEMENT ACCESS");
//   P("Accessing first and last element of following queue");
//   show_queue<int>(q3);
//   P(q3.front());
//   P(q3.back());
//   P("");
//
//   //Modifiers
//   P("MODIFIERS");
//   P("Push element 8 at top of queue and check new size");
//   q3.push(8);
//   show_queue<int>(q3);
//   P(q3.size());
//   P("Removes first element of last queue and checks new size");
//   q3.pop();
//   show_queue<int>(q3);
//   P(q3.size());
//   P("");
//
//   //Mon-member function overloads
//   P("Non-member function overloads");
//   ft::queue<int> qi1;
//   ft::queue<int> qi2;
//   ft::queue<int> qi3;
//   qi1.push(4);
//   qi1.push(4);
//   qi1.push(4);
//   qi1.push(4);
//   qi2.push(4);
//   qi2.push(4);
//   qi2.push(4);
//   qi2.push(4);
//   qi3.push(6);
//   qi3.push(6);
//   qi3.push(6);
//   qi3.push(6);
//   P("Test whether following queues are equal");
//   show_queue<int>(qi1);
//   show_queue<int>(qi2);
//   if (qi1 == qi2)
//     P("YES");
//   P("Test wether following queues are equal");
//   show_queue<int>(qi1);
//   show_queue<int>(qi3);
//   if (qi1 != qi3)
//     P("NO");
//   P("Test whether first queue is smaller than second one");
//   show_queue<int>(qi1);
//   show_queue<int>(qi3);
//   if (qi1 < qi3)
//     P("YES");
//   else
//     P("NO");
//   P("Test whether first queue is bigger than second one");
//   show_queue<int>(qi3);
//   show_queue<int>(qi1);
//   if (qi3 > qi1)
//     P("YES");
//   P("Test whether first queue is bigger than or equal to first one");
//   show_queue<int>(qi1);
//   show_queue<int>(qi2);
//   if (qi1 >= qi2)
//     P("YES");
//   P("Test whether first queue is smaller than or equal to first one");
//   show_queue<int>(qi1);
//   show_queue<int>(qi2);
//   if (qi1 <= qi2)
//     P("YES");
//   P("");
// }
