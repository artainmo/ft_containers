#include <queue>
#include <list>
#include <iostream>

int main()
{
	std::queue<int, std::list<int> > hello;
	std::queue<int, std::list<int> > hello1(std::list<int>);
	std::list<char> li(10, 10);
	std::queue<char, std::list<char> > hello2(li);
}
