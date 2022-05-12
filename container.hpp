#ifndef CONTAINER_HPP
# define CONTAINER_HPP

# include <iostream>
# include <vector>

namespace ft
{
	// template <class T, class Alloc = std::allocator<T>>
	template <class T>
	class vector
	{
	private:
		std::allocator<T>	data;
	public:
		vector() : data() {

		};

		vector(T first, T last);
		vector(std::vector<int>::iterator& first, std::vector<int>::iterator& last);
		vector(vector<T> const& copy);
		~vector() {

		};
	};

	
}

#endif
