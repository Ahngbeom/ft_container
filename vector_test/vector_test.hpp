#ifndef VECTOR_TEST_HPP
# define VECTOR_TEST_HPP

# include <iostream>
# include <vector>

# include "vector.hpp"

# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define MAGENTA "\e[35m"
# define CYAN "\e[36m"
# define LGRAY "\e[37m"
# define GRAY "\e[90m"
# define LRED "\e[91m"
# define LGREEN "\e[92m"
# define LYELLOW "\e[93m"
# define LBLUE "\e[94m"
# define LMAGENTA "\e[95m"
# define LCYAN "\e[96m"
# define RESET "\e[0m"

namespace test {

	/****************** Iterator ******************/
	void	begin(std::vector<int>& origin, ft::vector<int>& mine);
	void	end(std::vector<int>& origin, ft::vector<int>& mine);
	void	rbegin(std::vector<int>& origin, ft::vector<int>& mine);
	void	rend(std::vector<int>& origin, ft::vector<int>& mine);
	void	iterator(std::vector<int>& origin, ft::vector<int>& mine);
	void	reverse_iterator(std::vector<int>& origin, ft::vector<int>& mine);

	/****************** Capacity ******************/
	void	size(std::vector<int>& origin, ft::vector<int>& mine);
	void	max_size(std::vector<int>& origin, ft::vector<int>& mine);
	void	resize(std::vector<int>& origin, ft::vector<int>& mine, std::size_t size);
	void	capacity(std::vector<int>& origin, ft::vector<int>& mine);
	void	empty(std::vector<int>& origin, ft::vector<int>& mine);
	void	reserve(std::vector<int>& origin, ft::vector<int>& mine, std::size_t n);

	/******************** Utils *******************/
	void	data_all(std::vector<int>& origin, ft::vector<int>& mine);
	void	rdata_all(std::vector<int>& origin, ft::vector<int>& mine);

	
	
	/**********************************************/
	/****************** Iterator ******************/
	/**********************************************/
	void	begin(std::vector<int>& origin, ft::vector<int>& mine) {
		std::cout << YELLOW;

		// std::cout << "std::vector<int> *begin(): " << *default_orig_vector.begin() << std::endl; // segmentation fault
		if (origin.size() > 0 && mine.size() > 0) {
			std::cout << "std::vector<int> value of begin(): " << *origin.begin() << std::endl;
			std::cout << "ft::vector<int> value of begin(): " << *mine.begin() << std::endl;
		} else {
			std::cout << RED << "vectors are empty" << RESET << std::endl;
			// empty(origin, mine);
		}

		std::cout << RESET;
	}

	void	end(std::vector<int>& origin, ft::vector<int>& mine) {
		std::cout << YELLOW;

		// std::cout << "std::vector<int> *begin(): " << *default_orig_vector.begin() << std::endl; // segmentation fault
		if (origin.size() > 0 && mine.size() > 0) {
			std::cout << "std::vector<int> value of end(): " << *(origin.end() - 1) << std::endl;
			std::cout << "ft::vector<int> value of end(): " << *(mine.end() - 1) << std::endl;
		} else {
			std::cout << RED << "vectors are empty" << RESET << std::endl;
			// empty(origin, mine);
		}

		std::cout << RESET;
	}

	void	rbegin(std::vector<int>& origin, ft::vector<int>& mine) {
		std::cout << YELLOW;

		// std::cout << "std::vector<int> *begin(): " << *default_orig_vector.begin() << std::endl; // segmentation fault
		if (origin.size() > 0 && mine.size() > 0) {
			std::cout << "std::vector<int> value of begin(): " << *origin.rbegin() << std::endl;
			std::cout << "ft::vector<int> value of begin(): " << *mine.rbegin() << std::endl;
		} else {
			std::cout << RED << "vectors are empty" << RESET << std::endl;
			// empty(origin, mine);
		}

		std::cout << RESET;
	}

	void	rend(std::vector<int>& origin, ft::vector<int>& mine) {
		std::cout << YELLOW;

		// std::cout << "std::vector<int> *begin(): " << *default_orig_vector.begin() << std::endl; // segmentation fault
		if (origin.size() > 0 && mine.size() > 0) {
			std::cout << "std::vector<int> value of end(): " << *(origin.rend() - 1) << std::endl;
			std::cout << "ft::vector<int> value of end(): " << *(mine.rend() - 1) << std::endl;
		} else {
			std::cout << RED << "vectors are empty" << RESET << std::endl;
			// empty(origin, mine);
		}

		std::cout << RESET;
	}

	void	iterator(std::vector<int>& origin, ft::vector<int>& mine) {
		std::cout << YELLOW;

		std::cout << "std::vector<int> iterator: "; 
		for (std::vector<int>::iterator it = origin.begin(); it != origin.end(); it++) {
			std::cout << *it;
			if (it != origin.end() - 1) {
				std::cout << ", ";
			} else {
				std::cout << std::endl;
			}
		}

		std::cout << "ft::vector<int> iterator: "; 
		for (ft::vector<int>::iterator it = mine.begin(); it != mine.end(); it++) {
			std::cout << *it;
			if (it != mine.end() - 1) {
				std::cout << ", ";
			} else {
				std::cout << std::endl;
			}
		}

		std::cout << RESET;
	}

	void	reverse_iterator(std::vector<int>& origin, ft::vector<int>& mine) {
		std::cout << YELLOW;

		std::cout << "std::vector<int> reverse_iterator: "; 
		for (std::vector<int>::reverse_iterator it = origin.rbegin(); it != origin.rend(); it++) {
			std::cout << *it;
			if (it != origin.rend() - 1) {
				std::cout << ", ";
			} else {
				std::cout << std::endl;
			}
		}

		std::cout << "ft::vector<int> reverse_iterator: "; 
		for (ft::vector<int>::reverse_iterator it = mine.rbegin(); it != mine.rend(); it++) {
			std::cout << *it;
			if (it != mine.rend() - 1) {
				std::cout << ", ";
			} else {
				std::cout << std::endl;
			}
		}

		std::cout << RESET;
	}

	
	/**********************************************/
	/****************** Capacity ******************/
	/**********************************************/
	void	size(std::vector<int>& origin, ft::vector<int>& mine) {
		std::cout << MAGENTA;
		std::cout << "std::vector<int> size(): " << origin.size() << std::endl;
		std::cout << "ft::vector<int> size(): " << mine.size() << std::endl;
		std::cout << RESET;
	};

	void	max_size(std::vector<int>& origin, ft::vector<int>& mine) {
		std::cout << MAGENTA;
		std::cout << "std::vector<int> max_size(): " << origin.max_size() << std::endl;
		std::cout << "ft::vector<int> max_size(): " << mine.max_size() << std::endl;
		std::cout << RESET;
	};

	void	resize(std::vector<int>& origin, ft::vector<int>& mine, std::size_t size) {
		std::cout << MAGENTA;
		origin.resize(size);
		std::cout << "std::vector<int> size after resize(" << size << "): " << origin.size() << std::endl;
		mine.resize(size);
		std::cout << "ft::vector<int> size after resize(" << size << "): " << mine.size() << std::endl;
		std::cout << RESET;
	};

	void	capacity(std::vector<int>& origin, ft::vector<int>& mine) {
		std::cout << MAGENTA;
		std::cout << "std::vector<int> capacity(): " << origin.capacity() << std::endl;
		std::cout << "ft::vector<int> capacity(): " << mine.capacity() << std::endl;
		std::cout << RESET;
	};

	void	empty(std::vector<int>& origin, ft::vector<int>& mine) {
		std::cout << MAGENTA;
		std::cout << "std::vector<int> empty(): " << origin.empty() << std::endl;
		std::cout << "ft::vector<int> empty(): " << mine.empty() << std::endl;
		std::cout << RESET;
	}
	
	void	reserve(std::vector<int>& origin, ft::vector<int>& mine, std::size_t n) {
		std::cout << MAGENTA;
		origin.reserve(n);
		std::cout << "std::vector<int> capacity after reserve: " << origin.capacity() << std::endl;
		mine.reserve(n);
		std::cout << "ft::vector<int> capacity after reserve: " << mine.capacity() << std::endl;
		std::cout << RESET;
	}



	/**********************************************/
	/******************** Utils *******************/
	/**********************************************/
	void	data_all(std::vector<int>& origin, ft::vector<int>& mine) {
		std::cout << GREEN;
		// std::cout << "std::vector<int> data(): " << *origin.data() << std::endl;
		std::cout << "std::vector<int> all data: "; 
		for (std::vector<int>::iterator it = origin.begin(); it != origin.end(); it++) {
			std::cout << *it;
			if (it != origin.end() - 1) {
				std::cout << ", ";
			} else {
				std::cout << std::endl;
			}
		}

		// std::cout << "ft::vector<int> data(): " << *mine.data() << std::endl;
		std::cout << "ft::vector<int> all data: "; 
		for (ft::vector<int>::iterator it = mine.begin(); it != mine.end(); it++) {
			std::cout << *it;
			if (it != mine.end() - 1) {
				std::cout << ", ";
			} else {
				std::cout << std::endl;
			}
		}

		std::cout << RESET;
	}

	void	rdata_all(std::vector<int>& origin, ft::vector<int>& mine) {
		std::cout << GREEN;
		// std::cout << "std::vector<int> data(): " << *origin.data() << std::endl;
		std::cout << "std::vector<int> all reverse data: "; 
		for (std::vector<int>::reverse_iterator it = origin.rbegin(); it != origin.rend(); it++) {
			std::cout << *it;
			if (it != origin.rend() - 1) {
				std::cout << ", ";
			} else {
				std::cout << std::endl;
			}
		}

		// std::cout << "ft::vector<int> data(): " << *mine.data() << std::endl;
		std::cout << "ft::vector<int> all reverse data: "; 
		for (ft::vector<int>::reverse_iterator it = mine.rbegin(); it != mine.rend(); it++) {
			std::cout << *it;
			if (it != mine.rend() - 1) {
				std::cout << ", ";
			} else {
				std::cout << std::endl;
			}
		}

		std::cout << RESET;
	}
}

#endif