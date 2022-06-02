#include <iostream>
#include <string>
#include <deque>

#include <vector>
#include <typeinfo>

#include "vector.hpp"
#include "vector_test.hpp"

int main(void)
{
	{
		std::cout << "========== default vector<int> TEST ==========" << std::endl;
		std::vector<int> orig_default_vector;
		ft::vector<int> my_default_vector;;
		
		for (int i = 1; i <= 5; i++) {
			orig_default_vector.push_back(i);
			my_default_vector.push_back(i);
		}
		test::capacity(orig_default_vector, my_default_vector);

		test::begin(orig_default_vector, my_default_vector);
		test::end(orig_default_vector, my_default_vector);
		test::rbegin(orig_default_vector, my_default_vector);
		test::rend(orig_default_vector, my_default_vector);
		test::iterator(orig_default_vector, my_default_vector);
		test::reverse_iterator(orig_default_vector, my_default_vector);

		test::size(orig_default_vector, my_default_vector);
		test::max_size(orig_default_vector, my_default_vector);
		test::capacity(orig_default_vector, my_default_vector);
		test::resize(orig_default_vector, my_default_vector, 3);
		test::iterator(orig_default_vector, my_default_vector);

		test::operator_array(orig_default_vector, my_default_vector, 2);

		test::iterator(orig_default_vector, my_default_vector);

		test::front(orig_default_vector, my_default_vector);
		test::back(orig_default_vector, my_default_vector);

		test::size(orig_default_vector, my_default_vector);
		test::capacity(orig_default_vector, my_default_vector);
		
		// my_default_vector.assign(my_default_vector.rbegin(), my_default_vector.rend());
		// test::iterator(orig_default_vector, my_default_vector);
		// test::reverse_iterator(orig_default_vector, my_default_vector);

		std::cout << std::endl;
	}

	{
		std::cout << "========== vector<int> copy TEST ==========" << std::endl;

		ft::vector<int> my_default_vector; std::cout << "my_default_vector: " << &my_default_vector << std::endl;
		ft::vector<int> copy_vector(my_default_vector); std::cout << "copy_vector: " << &copy_vector << std::endl;
		
		test::iterator(my_default_vector, copy_vector);

		my_default_vector.push_back(1); my_default_vector.push_back(2); my_default_vector.push_back(3);
	
		test::iterator(my_default_vector, copy_vector);

		ft::vector<int> copy_vector2(my_default_vector); std::cout << "copy_vector2: " << &copy_vector2 << std::endl;
		std::cout << copy_vector2.size() << std::endl;
		test::iterator(my_default_vector, copy_vector2);
	}

	// {
	// 	std::cout << "========== fill vector<int> TEST ==========" << std::endl;
	// 	std::vector<int> orig_fill_vector(3, 5);
	// 	ft::vector<int> my_fill_vector(3, 5);
		
	// 	test::size(orig_fill_vector, my_fill_vector);
	// 	test::max_size(orig_fill_vector, my_fill_vector);
	// 	test::capacity(orig_fill_vector, my_fill_vector);
	// 	test::iterator(orig_fill_vector, my_fill_vector);

	// 	test::begin(orig_fill_vector, my_fill_vector);
	// 	test::end(orig_fill_vector, my_fill_vector);
	// 	test::rbegin(orig_fill_vector, my_fill_vector);
	// 	test::rend(orig_fill_vector, my_fill_vector);
	// 	test::iterator(orig_fill_vector, my_fill_vector);
	// 	test::reverse_iterator(orig_fill_vector, my_fill_vector);

	// 	test::operator_array(orig_fill_vector, my_fill_vector, 1);
	// 	test::at(orig_fill_vector, my_fill_vector, 1);
	// 	test::at(orig_fill_vector, my_fill_vector, 9);
	// 	test::front(orig_fill_vector, my_fill_vector);
	// 	test::back(orig_fill_vector, my_fill_vector);
		
	// 	std::cout << std::endl;
	// }

	// std::vector<int> fill_orig_vector(3, 5);
	// ft::vector<int> fill_my_vector(3, 5);

	// iterator(fill_orig_vector, fill_my_vector);
	// capacity(fill_orig_vector, fill_my_vector);

	// typedef ft::iterator_traits<int*> traits;

	// if (typeid(traits::iterator_category) == typeid(std::random_access_iterator_tag))
	// 	std::cout << "int* is a random-access iterator" << std::endl;

	

	return 0;
}
