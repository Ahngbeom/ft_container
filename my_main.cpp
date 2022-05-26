#include "container.hpp"

int main(void)
{
	// std::vector<std::string> test;

	// test.push_back(1);
	// test.push_back(3);
	// test.push_back(5);
	
	// for (std::vector<int>::iterator i = test.begin(); i < test.end(); i++)
	// {
	// 	std::cout << *i << std::endl;
	// }

	// test.push_back("Hello");
	// test.push_back("World");

	// for (std::vector<std::string>::iterator i = test.begin(); i < test.end(); i++)
	// {
	// 	std::cout << *i << std::endl;
	// }

	ft::vector<int> default_vector;
	ft::vector<int> fill_vector(3, 5);
	// ft::vector<std::string> testClass("Hello");

	// std::cout << testClass.welcome() << std::endl;

	return 0;
}
