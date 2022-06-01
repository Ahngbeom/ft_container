#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "vector.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

	private:
		iterator_type _base_iter;
		
	public:
		reverse_iterator() : _base_iter(NULL){};
		explicit reverse_iterator(iterator_type it) : _base_iter(it){};
		~reverse_iterator(){};

		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it) : _base_iter(rev_it.base()) {};

		iterator_type base() const
		{
			return this->_base_iter;
		};

		reference	operator*() {
			iterator_type	temp = this->_base_iter;
			return *(temp - 1);
		};

		reverse_iterator	operator+(difference_type n) const {
			return reverse_iterator(this->_base_iter - n);
		};

		reverse_iterator	operator-(difference_type n) const {
			return reverse_iterator(this->_base_iter + n);
		};

		reverse_iterator& operator++() {
			// this->_base_iter = this->_base_iter + 1;
			--this->_base_iter;
			return *this;
		};

		reverse_iterator operator++(int) {
			reverse_iterator temp = *this;
			++(*this);
			return temp;
		};

		reverse_iterator& operator--() {
			// this->_base_iter = this->_base_iter + 1;
			return ++this->_base_iter;
		};

		reverse_iterator operator--(int) {
			iterator_type temp = this->_base_iter;
			this->_base_iter = this->_base_iter + 1;
			return temp;
		};

	};
	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() != rhs.base();
	};

	// template <class Iterator>
	// inline bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	// 	return lhs.base() < rhs.base();
	// };
}

#endif