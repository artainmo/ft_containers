#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>

template<typename T>
void writes()
{
	std::cout << "hello" << std::endl;
}


void (*function_pointer)() = writes;


int main()
{
	function_pointer<int>();
	exit(0);
	int devNull = open("/dev/null", O_WRONLY);
	char *y = new char;
	int fd_0 = dup(2);
	dup2(devNull, 2);
	*y = 77;
	std::cout << *y << std::endl; 
	delete y;
	delete y;
	dup2(fd_0, 2);
	close(fd_0);
}
