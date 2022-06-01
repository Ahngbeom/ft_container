#include <iostream>
#include <string>
#include <deque>

#include <vector>
#include <typeinfo>

#include "vector.hpp"
#include "vector_test.hpp"


int main(void)
{
	std::cout << "========== vector<int> TEST ==========" << std::endl;
	std::vector<int> default_orig_vector;
	ft::vector<int> default_my_vector;
	
	test::iterator(default_orig_vector, default_my_vector);

	for (int i = 1; i <= 5; i++) {
		default_orig_vector.push_back(i);
		default_my_vector.push_back(i);
		test::capacity(default_orig_vector, default_my_vector);
	}

	test::iterator(default_orig_vector, default_my_vector);

	test::data_all(default_orig_vector, default_my_vector);
	test::rdata_all(default_orig_vector, default_my_vector);

	test::size(default_orig_vector, default_my_vector);
	test::max_size(default_orig_vector, default_my_vector);
	test::capacity(default_orig_vector, default_my_vector);
	test::resize(default_orig_vector, default_my_vector, 3);
	test::capacity(default_orig_vector, default_my_vector);
	test::data_all(default_orig_vector, default_my_vector);
	test::resize(default_orig_vector, default_my_vector, 5);
	test::capacity(default_orig_vector, default_my_vector);
	test::data_all(default_orig_vector, default_my_vector);
	test::capacity(default_orig_vector, default_my_vector);
	test::empty(default_orig_vector, default_my_vector);


	// test::reverse_iterator(default_orig_vector, default_my_vector);
	// test::capacity(default_orig_vector, default_my_vector);

	// ft::data(default_orig_vector, default_my_vector);



	std::cout << std::endl;

	// std::vector<int> fill_orig_vector(3, 5);
	// ft::vector<int> fill_my_vector(3, 5);

	// iterator(fill_orig_vector, fill_my_vector);
	// capacity(fill_orig_vector, fill_my_vector);

	// typedef ft::iterator_traits<int*> traits;

	// if (typeid(traits::iterator_category) == typeid(std::random_access_iterator_tag))
	// 	std::cout << "int* is a random-access iterator" << std::endl;

	

	return 0;
}
