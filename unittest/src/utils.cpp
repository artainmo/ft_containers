#include "../main.hpp"

void segfault( int signum ) { std::cout << "SEGFAULT" << std::endl; exit(signum); } //Catch segfaults and write in correct fd
void sigabort( int signum ) { std::cout << "SIGABORT" << std::endl; exit(signum); } //Catch sigaborts and write in correct fd
void sigquit(int sig) { sig = 0; exit(sig); } //SIGQUIT send from childprocess to stop program does not return error code

int G_ERROR_COUNT = 0; //Lifetime end is not scope but whole program as assigned in static memory
int G_LINE = 0; //By knowing how much lines/tests you went through you can view your progress

std::string itoa(int num) //c++ has no itoa!! Only c++11 has itoa equivalent
{
  std::string s;
  std::stringstream out;

  out << num;
  s = out.str();
  return s;
}

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
    if (G_ERROR_COUNT == G_ERROR_LIMIT)
    {
      std::cout << "\033[34m" << "\n\nERROR LIMIT OF " << G_ERROR_LIMIT << " ATTAINED AFTER "<< G_LINE << " TESTS" << std::endl;
      fflush(stdout);
      std::remove("output/tmp_my");
      std::remove("output/tmp_real");
      kill(0, SIGQUIT);
    }
  }
}

// std::string set_number(unsigned int x)
// {
//   std::string s;
//   std::stringstream out;
//
//   out << x;
//   s = out.str();
//   s += " ";
//   return s;
// }
//
// // void number_files(std::ifstream &fd_r, std::string container) //Remove and recreate files but numbered, fds have to reopen new file after
// {
//   unsigned int lines;
//   std::string content;
//   std::ofstream tmp;
//
//   lines = 0;
//   content.assign((std::istreambuf_iterator<char>(fd_r)), (std::istreambuf_iterator<char>())); //Whole file in string object
//   content.insert(0, set_number(lines));
//   for (unsigned int i = 0; i < content.size() ;i++)
//   {
//     if (content[i] == '\n' && i + 1 < content.size())
//     {
//       lines++;
//       content.insert(i + 1, set_number(lines));
//     }
//   }
//   std::remove(container.c_str());
//   tmp.open(container);
//   tmp << content;
//   tmp.close();
//   fd_r.close();
// }
//
// std::string get_number(std::string line)
// {
//   unsigned int i;
//
//   for (i = 0; i < line.size(); i++)
//   {
//     if (line[i] == ' ')
//       break ;
//   }
//   return line.substr(0, i);
// }
