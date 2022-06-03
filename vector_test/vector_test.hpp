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
	void	begin(std::vector<int>& std_vector);
	void	begin(ft::vector<int>& ft_vector);
	void	end(std::vector<int>& std_vector);
	void	end(ft::vector<int>& ft_vector);
	void	rbegin(std::vector<int>& std_vector);
	void	rbegin(ft::vector<int>& ft_vector);
	void	rend(std::vector<int>& std_vector);
	void	rend(ft::vector<int>& ft_vector);
	void	iterator(std::vector<int>& std_vector);
	void	iterator(ft::vector<int>& ft_vector);
	void	reverse_iterator(std::vector<int>& std_vector);
	void	reverse_iterator(ft::vector<int>& ft_vector);

	/****************** Capacity ******************/
	void	size(std::vector<int>& std_vector);
	void	size(ft::vector<int>& ft_vector);
	void	max_size(std::vector<int>& std_vector);
	void	max_size(ft::vector<int>& ft_vector);
	void	resize(std::vector<int>& std_vector, std::size_t size);
	void	resize(ft::vector<int>& ft_vector, std::size_t size);
	void	capacity(std::vector<int>& std_vector);
	void	capacity(ft::vector<int>& ft_vector);
	void	empty(std::vector<int>& std_vector);
	void	empty(ft::vector<int>& ft_vector);
	void	reserve(std::vector<int>& std_vector, std::size_t n);
	void	reserve(ft::vector<int>& ft_vector, std::size_t n);

	/*************** Element Access ***************/
	
	
	/******************** Utils *******************/
	void	data_all(std::vector<int>& std_vector);
	void	data_all(ft::vector<int>& ft_vector);
	void	rdata_all(std::vector<int>& std_vector);
	void	rdata_all(ft::vector<int>& ft_vector);

	
	
	/**********************************************/
	/****************** Iterator ******************/
	/**********************************************/
	void	begin(std::vector<int>& std_vector) {
		std::cout << YELLOW;

		// std::cout << "std::vector<int> *begin(): " << *default_orig_vector.begin() << std::endl; // segmentation fault
		if (std_vector.size() > 0) {
			std::cout << "std::vector<int> value of begin(): " << *std_vector.begin() << std::endl;
		} else {
			std::cout << RED << "vectors are empty" << RESET << std::endl;
			// empty(std_vector, ft_vector);
		}

		std::cout << RESET;
	}

	void	begin(ft::vector<int>& ft_vector) {
		std::cout << YELLOW;

		// std::cout << "std::vector<int> *begin(): " << *default_orig_vector.begin() << std::endl; // segmentation fault
		if (ft_vector.size() > 0) {
			std::cout << "ft::vector<int> value of begin(): " << *ft_vector.begin() << std::endl;
		} else {
			std::cout << RED << "vectors are empty" << RESET << std::endl;
			// empty(std_vector, ft_vector);
		}

		std::cout << RESET;
	}

	void	end(std::vector<int>& std_vector) {
		std::cout << YELLOW;

		// std::cout << "std::vector<int> *begin(): " << *default_orig_vector.begin() << std::endl; // segmentation fault
		if (std_vector.size() > 0) {
			std::cout << "std::vector<int> value of end(): " << *(std_vector.end() - 1) << std::endl;
		} else {
			std::cout << RED << "vectors are empty" << RESET << std::endl;
			// empty(std_vector, ft_vector);
		}

		std::cout << RESET;
	}

	void	end(ft::vector<int>& ft_vector) {
		std::cout << YELLOW;

		// std::cout << "std::vector<int> *begin(): " << *default_orig_vector.begin() << std::endl; // segmentation fault
		if (ft_vector.size() > 0) {
			std::cout << "ft::vector<int> value of end(): " << *(ft_vector.end() - 1) << std::endl;
		} else {
			std::cout << RED << "vectors are empty" << RESET << std::endl;
			// empty(std_vector, ft_vector);
		}

		std::cout << RESET;
	}

	void	rbegin(std::vector<int>& std_vector) {
		std::cout << YELLOW;

		// std::cout << "std::vector<int> *begin(): " << *default_orig_vector.begin() << std::endl; // segmentation fault
		if (std_vector.size() > 0) {
			std::cout << "std::vector<int> value of begin(): " << *std_vector.rbegin() << std::endl;
		} else {
			std::cout << RED << "vectors are empty" << RESET << std::endl;
			// empty(std_vector, ft_vector);
		}

		std::cout << RESET;
	}

	void	rbegin(ft::vector<int>& ft_vector) {
		std::cout << YELLOW;

		// std::cout << "std::vector<int> *begin(): " << *default_orig_vector.begin() << std::endl; // segmentation fault
		if (ft_vector.size() > 0) {
			std::cout << "ft::vector<int> value of begin(): " << *ft_vector.rbegin() << std::endl;
		} else {
			std::cout << RED << "vectors are empty" << RESET << std::endl;
			// empty(std_vector, ft_vector);
		}

		std::cout << RESET;
	}

	void	rend(std::vector<int>& std_vector) {
		std::cout << YELLOW;

		// std::cout << "std::vector<int> *begin(): " << *default_orig_vector.begin() << std::endl; // segmentation fault
		if (std_vector.size() > 0) {
			std::cout << "std::vector<int> value of end(): " << *(std_vector.rend() - 1) << std::endl;
		} else {
			std::cout << RED << "vectors are empty" << RESET << std::endl;
			// empty(std_vector, ft_vector);
		}

		std::cout << RESET;
	}

	void	rend(ft::vector<int>& ft_vector) {
		std::cout << YELLOW;

		// std::cout << "std::vector<int> *begin(): " << *default_orig_vector.begin() << std::endl; // segmentation fault
		if (ft_vector.size() > 0) {
			std::cout << "ft::vector<int> value of end(): " << *(ft_vector.rend() - 1) << std::endl;
		} else {
			std::cout << RED << "vectors are empty" << RESET << std::endl;
			// empty(std_vector, ft_vector);
		}

		std::cout << RESET;
	}

	void	iterator(std::vector<int>& std_vector) {
		std::cout << YELLOW;

		if (std_vector.size() > 0) {
			std::cout << "std::vector<int> iterator: "; 
			for (std::vector<int>::iterator it = std_vector.begin(); it != std_vector.end(); it++) {
				std::cout << *it;
				if (it != std_vector.end() - 1) {
					std::cout << ", ";
				} else {
					std::cout << std::endl;
				}
			}
		} else { std::cout << "std_vector vector is empty" << std::endl; };

		std::cout << RESET;
	};

	void	iterator(ft::vector<int>& ft_vector) {
		std::cout << YELLOW;

		if (ft_vector.size() > 0) {
			std::cout << "ft::vector<int> iterator: "; 
			for (ft::vector<int>::iterator it = ft_vector.begin(); it != ft_vector.end(); it++) {
				std::cout << *it;
				if (it != ft_vector.end() - 1) {
					std::cout << ", ";
				} else {
					std::cout << std::endl;
				}
			}
		} else { std::cout << "my vector is empty" << std::endl; };

		std::cout << RESET;
	};

	void	reverse_iterator(std::vector<int>& std_vector) {
		std::cout << YELLOW;

		std::cout << "std::vector<int> reverse_iterator: "; 
		for (std::vector<int>::reverse_iterator it = std_vector.rbegin(); it != std_vector.rend(); it++) {
			std::cout << *it;
			if (it != std_vector.rend() - 1) {
				std::cout << ", ";
			} else {
				std::cout << std::endl;
			}
		}

		std::cout << RESET;
	}

	void	reverse_iterator(ft::vector<int>& ft_vector) {
		std::cout << YELLOW;

		std::cout << "ft::vector<int> reverse_iterator: "; 
		for (ft::vector<int>::reverse_iterator it = ft_vector.rbegin(); it != ft_vector.rend(); it++) {
			std::cout << *it;
			if (it != ft_vector.rend() - 1) {
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
	void	size(std::vector<int>& std_vector) {
		std::cout << MAGENTA;
		std::cout << "std::vector<int> size(): " << std_vector.size() << std::endl;
		std::cout << RESET;
	};

	void	size(ft::vector<int>& ft_vector) {
		std::cout << MAGENTA;
		std::cout << "ft::vector<int> size(): " << ft_vector.size() << std::endl;
		std::cout << RESET;
	};

	void	max_size(std::vector<int>& std_vector) {
		std::cout << MAGENTA;
		std::cout << "std::vector<int> max_size(): " << std_vector.max_size() << std::endl;
		std::cout << RESET;
	};

	void	max_size(ft::vector<int>& ft_vector) {
		std::cout << MAGENTA;
		std::cout << "ft::vector<int> max_size(): " << ft_vector.max_size() << std::endl;
		std::cout << RESET;
	};

	void	resize(std::vector<int>& std_vector, std::size_t size) {
		std::cout << MAGENTA;
		std_vector.resize(size);
		std::cout << "std::vector<int> size after resize(" << size << "): " << std_vector.size() << std::endl;
		std::cout << RESET;
	};

	void	resize(ft::vector<int>& ft_vector, std::size_t size) {
		std::cout << MAGENTA;
		ft_vector.resize(size);
		std::cout << "ft::vector<int> size after resize(" << size << "): " << ft_vector.size() << std::endl;
		std::cout << RESET;
	};

	void	capacity(std::vector<int>& std_vector) {
		std::cout << MAGENTA;
		std::cout << "std::vector<int> capacity(): " << std_vector.capacity() << std::endl;
		std::cout << RESET;
	};

	void	capacity(ft::vector<int>& ft_vector) {
		std::cout << MAGENTA;
		std::cout << "ft::vector<int> capacity(): " << ft_vector.capacity() << std::endl;
		std::cout << RESET;
	};

	void	empty(std::vector<int>& std_vector) {
		std::cout << MAGENTA;
		std::cout << "std::vector<int> empty(): " << std_vector.empty() << std::endl;
		std::cout << RESET;
	};

	void	empty(ft::vector<int>& ft_vector) {
		std::cout << MAGENTA;
		std::cout << "ft::vector<int> empty(): " << ft_vector.empty() << std::endl;
		std::cout << RESET;
	};
	
	void	reserve(std::vector<int>& std_vector, std::size_t n) {
		std::cout << MAGENTA;
		std_vector.reserve(n);
		std::cout << "std::vector<int> capacity after reserve: " << std_vector.capacity() << std::endl;
		std::cout << RESET;
	};

	void	reserve(ft::vector<int>& ft_vector, std::size_t n) {
		std::cout << MAGENTA;
		ft_vector.reserve(n);
		std::cout << "ft::vector<int> capacity after reserve: " << ft_vector.capacity() << std::endl;
		std::cout << RESET;
	};


	/**********************************************/
	/*************** Element Access ***************/
	/**********************************************/
	void	operator_array(std::vector<int>& std_vector, std::size_t n) {
		std::cout << CYAN;
		std::cout << "std::vector<int> operator[" << n << "]: " << std_vector[n] << std::endl; 
		std::cout << RESET;
	};

	void	operator_array(ft::vector<int>& ft_vector, std::size_t n) {
		std::cout << CYAN;
		std::cout << "ft::vector<int> operator[" << n << "]: " << ft_vector[n] << std::endl; 
		std::cout << RESET;
	};

	void	at(std::vector<int>& std_vector, std::size_t n) {
		std::cout << CYAN;
		// (void)std_vector;
		try {
			std::cout << "std::vector<int> at(" << n << "): " << std_vector.at(n) << std::endl; 
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << RESET;
	};

	void	at(ft::vector<int>& ft_vector, std::size_t n) {
		std::cout << CYAN;
		// (void)std_vector;
		try {
			std::cout << "ft::vector<int> at(" << n << "): " << ft_vector.at(n) << std::endl; 
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << RESET;
	};

	void	front(std::vector<int>& std_vector) {
		std::cout << CYAN;
		std::cout << "std::vector<int> front(): " << std_vector.front() << std::endl; 
		std::cout << RESET;
	};

	void	front(ft::vector<int>& ft_vector) {
		std::cout << CYAN;
		std::cout << "ft::vector<int> front(): " << ft_vector.front() << std::endl; 
		std::cout << RESET;
	};

	void	back(std::vector<int>& std_vector) {
		std::cout << CYAN;
		std::cout << "std::vector<int> back(): " << std_vector.back() << std::endl; 
		std::cout << RESET;
	};

	void	back(ft::vector<int>& ft_vector) {
		std::cout << CYAN;
		std::cout << "ft::vector<int> back(): " << ft_vector.back() << std::endl; 
		std::cout << RESET;
	};

	/**********************************************/
	/******************** Utils *******************/
	/**********************************************/
	void	data_all(std::vector<int>& std_vector) {
		std::cout << GREEN;
		// std::cout << "std::vector<int> data(): " << *std_vector.data() << std::endl;
		std::cout << "std::vector<int> all data: "; 
		for (std::vector<int>::iterator it = std_vector.begin(); it != std_vector.end(); it++) {
			std::cout << *it;
			if (it != std_vector.end() - 1) {
				std::cout << ", ";
			} else {
				std::cout << std::endl;
			}
		}

		std::cout << RESET;
	};

	void	data_all(ft::vector<int>& ft_vector) {
		std::cout << GREEN;
		// std::cout << "ft::vector<int> data(): " << *ft_vector.data() << std::endl;
		std::cout << "ft::vector<int> all data: "; 
		for (ft::vector<int>::iterator it = ft_vector.begin(); it != ft_vector.end(); it++) {
			std::cout << *it;
			if (it != ft_vector.end() - 1) {
				std::cout << ", ";
			} else {
				std::cout << std::endl;
			}
		}

		std::cout << RESET;
	};

	void	rdata_all(std::vector<int>& std_vector) {
		std::cout << GREEN;
		// std::cout << "std::vector<int> data(): " << *std_vector.data() << std::endl;
		std::cout << "std::vector<int> all reverse data: "; 
		for (std::vector<int>::reverse_iterator it = std_vector.rbegin(); it != std_vector.rend(); it++) {
			std::cout << *it;
			if (it != std_vector.rend() - 1) {
				std::cout << ", ";
			} else {
				std::cout << std::endl;
			}
		}

		std::cout << RESET;
	};

	void	rdata_all(ft::vector<int>& ft_vector) {
		std::cout << GREEN;
		// std::cout << "ft::vector<int> data(): " << *ft_vector.data() << std::endl;
		std::cout << "ft::vector<int> all reverse data: "; 
		for (ft::vector<int>::reverse_iterator it = ft_vector.rbegin(); it != ft_vector.rend(); it++) {
			std::cout << *it;
			if (it != ft_vector.rend() - 1) {
				std::cout << ", ";
			} else {
				std::cout << std::endl;
			}
		}

		std::cout << RESET;
	};
}

#endif