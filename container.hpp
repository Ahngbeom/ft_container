#ifndef CONTAINER_HPP
# define CONTAINER_HPP

# include <iostream>
# include <memory>

# include <vector>
# include <string>


namespace ft
{
	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T 										value_type;
		typedef Allocator 								allocator_type;
		typedef	std::size_t								size_type;
		typedef	std::ptrdiff_t							difference_type;
		typedef value_type&								reference;
		typedef	const value_type&						const_reference;
		typedef	typename allocator_type::pointer		pointer;
		typedef	const typename allocator_type::pointer	const_pointer;
		// typedef	iterator;
		// typedef	const_iterator;
		// typedef	std::reverse_iterator<typename iterator> reverse_iterator;
		// typedef	std::reverse_iterator<typename const_iterator> const_reverse_iterator;

	private:
		pointer			_first;
		size_type		_size, _capacity;
		allocator_type	_allocator;

	public:
		explicit vector(const allocator_type& alloc = allocator_type()) : _first(nullptr), _size(0), _capacity(0), _allocator(alloc) {
			std::cout << "ft::vector Default Constructor Called(";
			this->_first == nullptr ? (std::cout << "nullptr" << ", ") : (std::cout << this->_first << ", ");
			std::cout << this->_size << ", ";
			std::cout << this->_capacity << ")" << std::endl;
			// std::cout << this->_allocator << std::endl;
		};

		explicit vector(size_type n, const_reference val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _allocator(alloc) {
			std::cout << "ft::vector Fill Constructor Called(";
			this->_first = _allocator.allocate(n);
			for (size_type i = 0; i < n; i++) {
				_allocator.construct(this->_first + i, val);
				if (i < n - 1)
					std::cout << *(this->_first + i) << ", ";
				else
					std::cout << *(this->_first + i) << ")\n";
			}
		}
		~vector() {};

		// std::string	welcome() const;
	};

}

#endif
