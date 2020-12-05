#include <iostream>
#include <string>
#include <map>
#include <signal.h>

class Complex { //Complex type
public:
  int _n;
  Complex( int n ) : _n( n ) {}

  bool operator==( Complex const & rhs ) { return (this->_n == rhs._n); }
  bool operator!=( Complex const & rhs ) { return (this->_n != rhs._n); }
  bool operator>( Complex const & rhs ) { return (this->_n > rhs._n); }
  bool operator<( Complex const & rhs ) { return (this->_n < rhs._n); }
  bool operator>=( Complex const & rhs ) { return (this->_n >= rhs._n); }
  bool operator<=( Complex const & rhs ) { return (this->_n <= rhs._n); }
};

std::ostream &operator<<(std::ostream &ostream, const Complex &c) { return (ostream << c._n); }

template<typename T>
void test()
{
	T j = T();
	std::cout << j << std::endl;
}

int main()
{
  std::cout << "~~~INT~~~"<< std::endl;
  std::map<int, int> i;
  i[0] = 2;
  i[1] = 3;
  i[2] = 5;
  std::map<int, int>::iterator il = i.begin();
  std::map<int, int>::iterator im = i.end();
  std::cout << "Begin"<< std::endl;
  std::cout << il->first << "\t" << il->second << std::endl;
  std::cout << "End"<< std::endl;
  std::cout << im->first << "\t" << im->second << std::endl;
  std::cout << "--Begin"<< std::endl;
  --il;
  std::cout << il->first << "\t" << il->second << std::endl;
  std::cout << "--Begin"<< std::endl;
  --il;
  std::cout << il->first << "\t" << il->second << std::endl;
  std::cout << "--Begin"<< std::endl;
  --il;
  std::cout << il->first << "\t" << il->second << std::endl;
  std::cout << "++end"<< std::endl;
  ++im;
  std::cout << im->first << "\t" << im->second << std::endl;
  std::cout << "++end"<< std::endl;
  ++im;
  std::cout << im->first << "\t" << im->second << std::endl;
  std::cout << "++end"<< std::endl;
  ++im;
  std::cout << im->first << "\t" << im->second << std::endl;

  std::cout << "~~~CHAR~~~"<< std::endl;
  std::map<char, char> c;
  c[2] = 2;
  c[3] = 3;
  c[5] = 5;
  std::map<char, char>::iterator cl = c.begin();
  std::map<char, char>::iterator cm = c.end();
  std::cout << "Begin"<< std::endl;
  std::cout << cl->first << "\t" << cl->second << std::endl;
  std::cout << "End"<< std::endl;
  std::cout << cm->first << "\t" << cm->second << std::endl;
  std::cout << "--Begin"<< std::endl;
  --cl;
  std::cout << cl->first << "\t" << cl->second << std::endl;
  std::cout << "++end"<< std::endl;
  ++cm;
  std::cout << cm->first << "\t" << cm->second << std::endl;

  std::cout << "~~~COMPLEX~~~"<< std::endl;
  std::cout << "Cannot take a complex type"<< std::endl;
  // std::map<int, Complex> k;
  // k[2] = Complex(2);
  // k[3] = Complex(3);
  // k[5] = Complex(5);
	// std::map<int, Complex>::iterator l = k.end();
	// std::map<int, Complex>::iterator m = k.begin();
  // std::cout << "Begin"<< std::endl;
  // std::cout << l->first << "\t" << l->second << std::endl;
  // std::cout << "End"<< std::endl;
  // std::cout << l->first << "\t" << l->second << std::endl;
  // std::cout << "--Begin"<< std::endl;
  // --l;
  // std::cout << l->first << "\t" << l->second << std::endl;
  // std::cout << "++end"<< std::endl;
  // ++m;
  // std::cout << m->first << "\t" << m->second << std::endl;

  std::cout << "~~~STRING~~~"<< std::endl;
  std::map<int, std::string> s;
  s[2] = std::string("dd");
  s[3] = std::string("ff");
  s[5] = std::string("gg");
	std::map<int, std::string>::iterator sl = s.begin();
	std::map<int, std::string>::iterator sm = s.end();
  std::cout << "Begin"<< std::endl;
  std::cout << sl->first << "\t" << sl->second << std::endl;
  std::cout << "End"<< std::endl;
  std::cout << sm->first << "\t" << sm->second << std::endl;
  std::cout << "--Begin"<< std::endl;
  --sl;
  std::cout << sl->first << "\t" << sl->second << std::endl;
  std::cout << "++end"<< std::endl;
  ++sm;
  std::cout << sm->first << "\t" << sm->second << std::endl;

	//test<int>();
	//test<char>();
	//test<Complex>();
	//test<std::string>();
}
