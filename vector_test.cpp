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
		std::cout << "========== default construct vector<int> TEST ==========" << std::endl;
		std::vector<int> orig_default_vector;
		ft::vector<int> my_default_vector;;
		
		for (int i = 1; i <= 5; i++) {
			orig_default_vector.push_back(i);
			my_default_vector.push_back(i);
		}
		test::capacity(orig_default_vector); test::capacity(my_default_vector);

		test::begin(orig_default_vector); test::begin(my_default_vector);
		test::end(orig_default_vector); test::end(my_default_vector);
		test::rbegin(orig_default_vector); test::rbegin(my_default_vector);
		test::rend(orig_default_vector); test::rend(my_default_vector);
		test::iterator(orig_default_vector); test::iterator(my_default_vector);
		test::reverse_iterator(orig_default_vector); test::reverse_iterator(my_default_vector);

		test::size(orig_default_vector); test::size(my_default_vector);
		test::max_size(orig_default_vector); test::max_size(my_default_vector);
		test::capacity(orig_default_vector); test::capacity(my_default_vector);
		test::resize(orig_default_vector, 3); test::resize(my_default_vector, 3);
		test::iterator(orig_default_vector); test::iterator(my_default_vector);

		test::operator_array(orig_default_vector, 2); test::operator_array(my_default_vector, 2);

		test::iterator(orig_default_vector); test::iterator(my_default_vector);

		test::front(orig_default_vector); test::front(my_default_vector);
		test::back(orig_default_vector); test::back(my_default_vector);

		test::size(orig_default_vector); test::size(my_default_vector);
		test::capacity(orig_default_vector); test::capacity(my_default_vector);
		
		// my_default_vector.assign(my_default_vector.rbegin(), my_default_vector.rend());
		// test::iterator(orig_default_vector, my_default_vector);
		// test::reverse_iterator(orig_default_vector, my_default_vector);

		std::cout << std::endl;
	}

	{
		std::cout << "========== vector<int> copy TEST ==========" << std::endl;

		std::vector<int> std_default_vector;
		std::vector<int> copy_vector(std_default_vector);
		
		test::iterator(std_default_vector); test::iterator(copy_vector);

		std_default_vector.push_back(1); std_default_vector.push_back(2); std_default_vector.push_back(3);
	
		test::iterator(std_default_vector); test::iterator(copy_vector); test::size(copy_vector); test::capacity(copy_vector);

		std::vector<int> copy_vector2(std_default_vector);
		test::iterator(std_default_vector); test::iterator(copy_vector2);

		std_default_vector.push_back(4);
		std_default_vector.push_back(5);
		test::iterator(std_default_vector); test::size(std_default_vector); test::capacity(std_default_vector);
		
		test::iterator(copy_vector2); test::size(copy_vector2); test::capacity(copy_vector2);

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
