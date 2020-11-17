#include <iostream>
#include <vector>
#include <list>
#include <map>

int main()
{
	std::map<char, int> v;
	v.insert(std::pair<char, int>('m', 4));

	std::map<char, int>::iterator i = v.begin();
	std::cout << v['m'];
	return (0);
}

