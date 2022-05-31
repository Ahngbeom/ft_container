#include "container.hpp"

template<class T, class Alloc = std::allocator<T> >
explicit ft::vector<T>::vector(const Allocator& alloc = allocator_type()) : _first(NULL), _size(0), _capacity(0), _allocator(alloc) {
	std::cout << "ft::vector Default Constructor Called(";
	this->_first == NULL ? (std::cout << "NULL" << ", ") : (std::cout << this->_first << ", ");
	std::cout << this->_size << ", ";
	std::cout << this->_capacity << ")" << std::endl;
	// std::cout << this->_allocator << std::endl;
};

template<class T>
ft::vector<T>::~vector() {

}

template<class T>
std::string ft::vector<T>::welcome() const {
	
	return this->_data;
}
