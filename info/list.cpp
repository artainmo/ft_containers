#include <iostream>
#include <string>
#include <list>
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
  std::list<int> i;
  i.push_back(1);
  i.push_back(2);
  i.push_back(3);
  i.push_back(5);
  std::list<int>::iterator il = i.begin();
  std::list<int>::iterator im = i.end();
  std::cout << "Begin"<< std::endl;
  std::cout << *il << std::endl;
  std::cout << "End"<< std::endl;
  std::cout << *im << std::endl;
  std::cout << "--Begin"<< std::endl;
  --il;
  std::cout << *il << std::endl;
  std::cout << "--Begin"<< std::endl;
  --il;
  std::cout << *il << std::endl;
  std::cout << "--Begin"<< std::endl;
  --il;
  std::cout << *il << std::endl;
  std::cout << "++end"<< std::endl;
  ++im;
  std::cout << *im << std::endl;
  std::cout << "++end"<< std::endl;
  ++im;
  std::cout << *im << std::endl;
  std::cout << "++end"<< std::endl;
  ++im;
  std::cout << *im << std::endl;

  std::cout << "~~~CHAR~~~"<< std::endl;
  std::list<char> c(48, char());
  std::list<char>::iterator cl = c.begin();
  std::list<char>::iterator cm = c.end();
  std::cout << "Begin"<< std::endl;
  std::cout << *cl << std::endl;
  std::cout << "End"<< std::endl;
  std::cout << *cm << std::endl;
  std::cout << "--Begin"<< std::endl;
  --cl;
  std::cout << *cl << std::endl;
  std::cout << "++end"<< std::endl;
  ++cm;
  std::cout << *cm << std::endl;

  std::cout << "~~~COMPLEX~~~"<< std::endl;
  std::list<Complex> k(45, Complex(99));
	std::list<Complex>::iterator l = k.end();
	std::list<Complex>::iterator m = k.begin();
  std::cout << "Begin"<< std::endl;
	std::cout << *m << std::endl;
  std::cout << "End"<< std::endl;
	std::cout << *l << std::endl;
  std::cout << "--Begin"<< std::endl;
  --l;
  std::cout << *l << std::endl;
  std::cout << "++end"<< std::endl;
  ++m;
  std::cout << *m << std::endl;
  k.reverse();

  std::cout << "~~~STRING~~~"<< std::endl;
	std::list<std::string> s(7, std::string("jjj"));
	std::list<std::string>::iterator sl = s.begin();
	std::list<std::string>::iterator sm = s.end();
  std::cout << "Begin"<< std::endl;
	std::cout << *sl << std::endl;
  std::cout << "End"<< std::endl;
	std::cout << *sm << std::endl;
  std::cout << "--Begin"<< std::endl;
  --sl;
  std::cout << *sl << std::endl;
  std::cout << "++end"<< std::endl;
  ++sm;
  std::cout << *sm << std::endl;

	//test<int>();
	//test<char>();
	//test<Complex>();
	//test<std::string>();
}
