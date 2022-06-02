#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator.hpp"
# include "iterator_traits.hpp"

namespace ft {

	template <typename T>
	class RandomAccessIterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{
		public :
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
		private :
			pointer	_ptr;

		public :
			RandomAccessIterator() : _ptr() {};
			RandomAccessIterator(pointer ptr) : _ptr(ptr) {}; // Copy Constructor
			virtual ~RandomAccessIterator() {};

			inline pointer& base() { return this->_ptr; };
			inline const pointer& base() const { return this->_ptr; };

			// Copy Assign Operator
			// RandomAccessIterator<value_type>&	operator=(RandomAccessIterator<typename remove_const<value_type>::type> const& src)
			// {
			// 	_ptr = &(*src);
			// 	return *this;
			// };



			// Operator
			reference operator*() const {
				return *this->_ptr;
			}

			reference operator[](std::size_t index) const {
				return this->_ptr[index];
			}

			RandomAccessIterator operator+(difference_type oper) const {
				return RandomAccessIterator(this->_ptr + oper);
			}

			RandomAccessIterator operator-(difference_type oper) const {
				return RandomAccessIterator(this->_ptr - oper);
			}

			bool operator<(const RandomAccessIterator<value_type> oper) const {
				return &(*this->_ptr) < &(*oper);
			}

			bool operator!=(const RandomAccessIterator<value_type> oper) const {
				return &(*this->_ptr) != &(*oper);
			}

			reference operator++() {
				this->_ptr += 1;
				return *this->_ptr;
			}

			pointer operator++(int) {
				pointer	temp = this->_ptr;
				this->_ptr += 1;
				return temp;
			}

			reference operator--() {
				this->_ptr -= 1;
				return *this->_ptr;
			}

			pointer operator--(int) {
				pointer	temp = this->_ptr;
				this->_ptr -= 1;
				return temp;
			}
	};

	template <typename T>
	inline typename RandomAccessIterator<T>::difference_type operator- (const RandomAccessIterator<T>& lhs, const RandomAccessIterator<T>& rhs) { return *lhs.base() - *rhs.base(); };

}

#endif