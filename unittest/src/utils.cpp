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

void check_answer(std::string test, ifstream fd_r, ifstream fd_r_r) //Check all lines takes the test name and compares following test output
{
  std::string me;
  std::string real;
  std::string test;
  std::string tmp;
  streampos pos;

  while (tmp[0] == '~')
  {
    test = tmp.substr(1, tmp.size()); //Parse out the ~ for terminal output and get test
    getline(fd_r, tmp);
  }
  while (tmp[0] != '~') //Get all the output lines following test
  {
    me += tmp;
    pos = fd_r.tellg(); //Remember last fd position
    getline(fd_r, tmp);
  }
  fd_r.seekg(pos); //Go back to last fd postion, back one line

  tmp.clear();

  while (tmp[0] == '~')
    getline(fd_r_r, tmp);
  while (tmp[0] != '~')
  {
    real += tmp;
    pos = fd_r_r.tellg(); //Remember last fd position
    getline(fd_r_r, tmp);
  }
  fd_r_r.seekg(pos); //Go back to last fd postion, back one line

  if (me.compare(real) == 0) //Equal
    std::cout << std::setw(80) << std::left << test << "CORRECT" << std::endl;
  else //Not equal
    std::cout << std::setw(80) << std::left << test << "WRONG" << std::endl;
  if (fd_r.eofbite != 0 and fd_r_r.eofbite != 0)
    check_answer(fd_r, fd_r_r);
}
