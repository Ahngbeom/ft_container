#include "container.hpp"

int main(void)
{
	std::cout << "Hello World!" << std::endl;

	std::vector<int> test;

	test.push_back(1);
	test.push_back(3);
	test.push_back(5);

	ft::vector<int> my_vector;
	
	for (std::vector<int>::iterator i = test.begin(); i < test.end(); i++)
	{
		std::cout << *i << std::endl;
	}
	
	return 0;
}
