#include "container.hpp"

template<class T>
ft::vector<T>::vector() {
}

template<class T>
ft::vector<T>::~vector() {

}

template<class T>
std::string ft::vector<T>::welcome() const {
	
	return this->_data;
}
