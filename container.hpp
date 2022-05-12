#ifndef CONTAINER_HPP
# define CONTAINER_HPP

# include <iostream>
# include <vector>

namespace ft
{
	template <class T>
	class vector
	{
	private:
		/* data */
	public:
		vector() {

		};

		vector(T first, T last);
		vector(std::vector<int>::iterator& first, std::vector<int>::iterator& last);
		vector(vector<T> const& copy);
		~vector() {

		};
	};

	
}

#endif
