#include "main.hpp"

template<typename T, typename R>
void test()
{
	std::cout << "\033[1m\033[30m" << "Container object creation you:" << std::endl;
	T *my_elems = container_object_creation<T>();
  	std::cout << "\033[1m\033[30m" << "End of container object creation\n" << std::endl;
  	std::cout << "\033[1m\033[30m" << "Container object creation real:" << std::endl;
  	R *real_elems = container_object_creation<R>();
  	std::cout << "\033[1m\033[30m" << "End of container object creation\n" << "\033[0m"<< std::endl;

	merge_if<T, int>(my_elems[0], my_elems[2]); //Indicate function and its lists
	merge_if<R, int>(real_elems[0], real_elems[2]);
}

int main()
{
	test<ft::list<int>, std::list<int> >(); //Indicate container
}
