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
		reverse_iterator() : _base_iter(){};
		explicit reverse_iterator(iterator_type it) : _base_iter(it){};
		template <class Iter>
  		reverse_iterator (const reverse_iterator<Iter>& rev_it) : _base_iter(rev_it.base()){};
		~reverse_iterator(){};

		inline iterator_type base() const { return this->_base_iter; };

		reference operator* () const {
			iterator_type temp = this->_base_iter;
			return *(temp - 1);
		};

		reverse_iterator operator+ (difference_type n) const {
			return reverse_iterator(this->_base_iter - n);
		};

		reverse_iterator& operator++ () {
			// this->_base_iter = this->_base_iter + 1;
			--this->_base_iter;
			return *this;
		};

		reverse_iterator operator++ (int) {
			reverse_iterator temp = *this;
			++(*this);
			return temp;
		};

		reverse_iterator& operator+= (difference_type n) {
			this->_base_iter = this->_base_iter - n;
			return *this;
		};

		reverse_iterator operator- (difference_type n) const {
			return reverse_iterator(this->_base_iter + n);
		};

		reverse_iterator& operator-- () {
			// this->_base_iter = this->_base_iter + 1;
			return ++this->_base_iter;
		};

		reverse_iterator operator-- (int) {
			iterator_type temp = this->_base_iter;
			this->_base_iter = this->_base_iter + 1;
			return temp;
		};

		reverse_iterator& operator-= (difference_type n) {
			this->_base_iter = this->_base_iter + n;
			return *this;
		};

	};
	template <class Iterator>
	inline bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() != rhs.base();
	};

	template <class Iterator>
	inline reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
		return rev_it + n;
	};
	
	template <class Iterator>
	inline typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return rhs.base() - lhs.base();
	};

	// template <class Iterator>
	// inline bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	// 	return lhs.base() < rhs.base();
	// };
}

#endif