#include <iostream>
#include <string>
#include <deque>

#include <vector>
#include <typeinfo>

#include "vector.hpp"

template <class T>
void	data_CHECK(std::vector<T>& origin, ft::vector<T>& mine) {

	// std::cout << "std::vector<int> data(): " << *origin.data() << std::endl;
	std::cout << "std::vector<int> data: "; 
	for (std::vector<int>::iterator it = origin.begin(); it != origin.end(); it++) {
		std::cout << *it;
		if (it < origin.end() - 1) {
			std::cout << ", ";
		} else {
			std::cout << std::endl;
		}
	}

	// std::cout << "ft::vector<int> data(): " << *mine.data() << std::endl;
	std::cout << "ft::vector<int> data: "; 
	for (ft::vector<int>::iterator it = mine.begin(); it != mine.end(); it++) {
		std::cout << *it;
		if (it < mine.end() - 1) {
			std::cout << ", ";
		} else {
			std::cout << std::endl;
		}
	}
}

template <class T>
void	iterator_TEST(std::vector<T>& origin, ft::vector<T>& mine) {
	std::cout << "std::vector<int> data(): " << origin.data() << std::endl;
	std::cout << "ft::vector<int> data(): " << mine.data() << std::endl;

	// std::cout << "std::vector<int> *begin(): " << *default_orig_vector.begin() << std::endl; // segmentation fault
	if (origin.size() > 0) {
		std::cout << "std::vector<int> value of begin() & end(): " << *origin.begin() << ", " << *(origin.end() - 1) << std::endl;
	}
	if (mine.size() > 0) {
		std::cout << "ft::vector<int> value of begin() & end(): " << *mine.begin() << ", " << *(mine.end() - 1) << std::endl;
	}

	for (size_t i = 1; i <= 5; i++) {
		origin.push_back(i);
		mine.push_back(i);
	}

	if (origin.size() > 0) {
		std::cout << "std::vector<int> value of begin() & end(): " << *origin.begin() << ", " << *(origin.end() - 1) << std::endl;
	}
	if (mine.size() > 0) {
		std::cout << "ft::vector<int> value of begin() & end(): " << *mine.begin() << ", " << *(mine.end() - 1) << std::endl;
	}
}

template <class T>
void	reverse_iterator_TEST(std::vector<T>& origin, ft::vector<T>& mine) {
	if (origin.size() > 0) {
		std::cout << "std::vector<int> \e[31mreverse_iterator\e[0m  value of rbegin() & rend(): " << *origin.rbegin() << ", " << *(origin.rend() - 1) << std::endl;
	}
	if (mine.size() > 0) {
		std::cout << "ft::vector<int> \e[31mreverse_iterator\e[0m  value of rbegin() & rend(): " << *mine.rbegin() << ", " << *(mine.rend()) << std::endl;
	}

}

template <class T>
void	capacity_TEST(std::vector<T>& origin, ft::vector<T>& mine) {
	std::cout << "std::vector<int> size(): " << origin.size() << std::endl;
	std::cout << "ft::vector<int> size(): " << mine.size() << std::endl;

	std::cout << "std::vector<int> capacity(): " << origin.capacity() << std::endl;
	std::cout << "ft::vector<int> capacity(): " << mine.capacity() << std::endl;

	std::cout << "std::vector<int> max_size(): " << origin.max_size() << std::endl;
	std::cout << "ft::vector<int> max_size(): " << mine.max_size() << std::endl;

	std::cout << "std::vector<int> empty(): " << origin.empty() << std::endl;
	std::cout << "ft::vector<int> empty(): " << mine.empty() << std::endl;

	data_CHECK(origin, mine);

	origin.resize(3);
	std::cout << "std::vector<int> size() after resize(3): " << origin.size() << std::endl;
	mine.resize(3);
	std::cout << "ft::vector<int> size() after resize(3): " << mine.size() << std::endl;

	data_CHECK(origin, mine);

	origin.resize(8);
	std::cout << "std::vector<int> size() after resize(8): " << origin.size() << std::endl;
	mine.resize(8);
	std::cout << "ft::vector<int> size() after resize(8): " << mine.size() << std::endl;

	data_CHECK(origin, mine);
}

int main(void)
{
	std::vector<int> default_orig_vector;
	ft::vector<int> default_my_vector;
	
	iterator_TEST(default_orig_vector, default_my_vector);
	reverse_iterator_TEST(default_orig_vector, default_my_vector);
	// capacity_TEST(default_orig_vector, default_my_vector);

	// data_CHECK(default_orig_vector, default_my_vector);

	std::cout << *default_my_vector.rbegin() << std::endl;
	std::cout << *(default_my_vector.rend() - 1) << std::endl;
	std::cout << std::endl;

	// std::vector<int> fill_orig_vector(3, 5);
	// ft::vector<int> fill_my_vector(3, 5);

	// iterator_TEST(fill_orig_vector, fill_my_vector);
	// capacity_TEST(fill_orig_vector, fill_my_vector);

	// typedef ft::iterator_traits<int*> traits;

	// if (typeid(traits::iterator_category) == typeid(std::random_access_iterator_tag))
	// 	std::cout << "int* is a random-access iterator" << std::endl;

	

	return 0;
}
