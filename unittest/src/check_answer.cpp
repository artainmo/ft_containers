#include "../main.hpp"

std::string set_number(unsigned int x)
{
  std::string s;
  std::stringstream out;

  out << x;
  s = out.str();
  s += " ";
  return s;
}

void number_files(std::ifstream &fd_r, std::string container) //Remove and recreate files but numbered, fds have to reopen new file after
{
  unsigned int lines;
  std::string content;
  std::ofstream tmp;

  lines = 0;
  content.assign((std::istreambuf_iterator<char>(fd_r)), (std::istreambuf_iterator<char>())); //Whole file in string object
  content.insert(0, set_number(lines));
  for (unsigned int i = 0; i < content.size() ;i++)
  {
    if (content[i] == '\n' && i + 1 < content.size())
    {
      lines++;
      content.insert(i + 1, set_number(lines));
    }
  }
  std::remove(container.c_str());
  tmp.open(container);
  tmp << content;
  tmp.close();
  fd_r.close();
}

std::string get_number(std::string line)
{
  unsigned int i;

  for (i = 0; i < line.size(); i++)
  {
    if (line[i] == ' ')
      break ;
  }
  return line.substr(0, i);
}

void check_answer(std::ifstream &fd_r, std::ifstream &fd_r_r) //Check all lines takes the test name and compares following test output
{
  std::string me;
  std::string real;
  std::string num;

  while (getline(fd_r, me) && getline(fd_r_r, real))
  {
    num = get_number(me);
    if (me.compare(real) == 0) //Equal
      std::cout << "\033[1m\033[32m" << num << " "; //Use green color code
    else //Not equal
      std::cout << "\033[1m\033[31m" << num << " "; //Use red color code
  }
  std::cout << std::endl;
}
