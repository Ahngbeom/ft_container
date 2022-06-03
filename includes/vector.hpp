#ifndef VECTOR_HPP
# define VECTOR_HPP

// # include <iostream>

// # include <vector>
// # include <string>

# include <memory>
# include <exception>

# include "iterator_traits.hpp"
# include "iterator.hpp"
# include "reverse_iterator.hpp"
# include "RandomAccessIterator.hpp"

// # ifdef __linux__
// # 	define df_null NULL
// # else
// # 	define df_null nullptr
// # endif

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		public : 
			typedef T												value_type;
			typedef Alloc											allocator_type;		// allocator<value_type>
			typedef value_type&										reference;			// allocator_type::reference
			typedef const value_type&								const_reference;	// allocator_type::const_reference
			typedef value_type*										pointer;			// allocator_type::pointer
			typedef const value_type*								const_pointer;		// allocator_type::const_pointer
			
			typedef ft::RandomAccessIterator<value_type>				iterator;
			typedef ft::RandomAccessIterator<const value_type>			const_iterator;

			typedef	ft::reverse_iterator<iterator> 					reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>			const_reverse_iterator;

			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;


		private:
			pointer 		_first; // 시작 주소
			size_type 		_size; // 원소의 개수
			size_type		_capacity; // 저장할 수 있는 최대 원소의 개수
			allocator_type	_allocator; // vector 할당자 타입의 변수를 선언하여 해당 할당자 타입에 대한 정보를 추출

		public:
			explicit vector(const allocator_type &alloc = allocator_type()) 
			: _first(NULL), _size(0), _capacity(0), _allocator(alloc) {};

			explicit vector(size_type n, const_reference val = value_type(), const allocator_type &alloc = allocator_type())
			: _size(n), _capacity(n), _allocator(alloc) {
				this->_first = _allocator.allocate(n);
				for (size_type i = 0; i < n; i++)
					_allocator.construct(this->_first + i, val);
			};

			// template <class InputIterator>
			// vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type())
			// 	: _allocator(alloc)
			// {
			// 	if (this->first > this->last)
			// 	{
			// 		throw std::length_error("vector");
			// 	}
			// 	this->_size = last - first;
			// 	this->_capacity = this->_size;
			// 	this->_first = this->_allocator.allocate(this->_capacity);
			// 	for (difference_type i = 0; i < static_cast<difference_type>(this->_size); i++)
			// 	{
			// 		this->_allocator.construct(this->_first + i, *(first + i));
			// 	}
			// };


			vector& operator= (const vector& x) {
				if (this == &x)
					return *this;
				this->clear();
				this->_size = x.size();
				if (this->size() > this->capacity()) {
					if (this->capacity() > 0) {
						this->_allocator.deallocate(this->_first, this->capacity());
					}
					this->_capacity = this->size();
					this->_first = this->_allocator.allocate(this->capacity());
				}
				for (size_type i = 0; i < this->size(); i++) {
					this->_allocator.construct(this->_first + i, *(x.begin() + i));
				}
				return *this;
			};

			// Copy Constructor
			// The copy constructor creates a container that keeps and uses a copy of x's allocator.
			vector (const vector& x) : _size(0), _capacity(0) { *this = x; };

			// Destructor
			~vector() {
				std::cout << "Destructor: " << this;
				std::cout << "(size(): " << this->size();
				std::cout << ", capacity(): " << this->capacity() << ")" << std::endl;
				for (size_type i = 0; i < this->size(); i++)
					this->_allocator.destroy(this->_first + i);
				if (this->capacity() > 0)
					this->_allocator.deallocate(this->_first, this->capacity());
			};

			// Iterator
			iterator begin() {
				return iterator(this->_first);
			};

			const_iterator begin() const {
				return const_iterator(this->_first);
			};

			iterator end() {
				return iterator(this->_first + this->_size);
			};

			const_iterator end() const {
				return const_iterator(this->_first + this->_size);
			};

			reverse_iterator rbegin() {
				return reverse_iterator(this->end());
			};
			
			const_reverse_iterator rbegin() const {
				return const_reverse_iterator(this->end());
			};

			reverse_iterator rend() {
				return reverse_iterator(this->begin());
			};
			
			const_reverse_iterator rend() const {
				return const_reverse_iterator(this->begin());
			};

			// Capacity
			size_type size() const {
				return this->_size;
			};

			size_type max_size() const {
				return this->_allocator.max_size();
			};

			void reserve (size_type n) {
				if (n > this->_capacity) {
					pointer new_cap = _allocator.allocate(n);
					try {
						for (size_type i = 0; i < this->_size; i++)
							this->_allocator.construct(new_cap + i, *(this->_first + i));
					} catch (std::exception &e) {
						for (size_type i = 0; i < this->_size; i++) {
							if (new_cap + i != NULL)
								this->_allocator.destroy(new_cap + i); // 파라미터 인자가 가리키는 객체의 소멸자 호출
						}
						this->_allocator.deallocate(new_cap, n); // 메모리 해제
						throw;
					}
					for(size_type i = 0; i < this->_size; i++)
						this->_allocator.destroy(this->_first + i);
					if(_capacity)
						this->_allocator.deallocate(this->_first, this->_capacity);
					this->_capacity = n;
					this->_first = new_cap;
				}
			};

			void resize(size_type n, value_type val = value_type()) {
				if (n < this->_size) {
					for (size_type i = n; i < this->_size; i++) {
						this->_allocator.destroy(this->_first + i);
					}
					this->_size = n;
				}
				else if (n > this->_size) {
					if (this->_capacity < n)
						// vector의 크기를 조정할 때 size가 capacity를 넘어가려할 경우 미리 _capacity의 최소 2배 크기를 확보한다.
						this->reserve(this->_capacity * 2 > n ? this->_capacity * 2 : n);
					for (size_type i = this->_size; i < n; i++) {
						this->_allocator.construct(this->_first + i, val);
						this->_size++;
					}
				}
			};

			size_type capacity() const {
				return this->_capacity;
			};

			bool empty() const {
				return this->_capacity == 0;
			};

			// Element access
			reference operator[] (size_type n) {
				return *(this->_first + n);
			};

			const_reference operator[] (size_type n) const {
				return *(this->_first + n);
			};

			reference at (size_type n) {
				try {
					if (n >= this->size())
						throw std::out_of_range("out of range");
					return *(this->_first + n);
				} catch (std::exception& e) {
					// std::cout << e.what() << std::endl;
					throw;
				}
			};

			const_reference at (size_type n) const {
				try {
					if (n >= this->size())
						throw std::out_of_range("out of range");
					return *(this->_first + n);
				} catch (std::exception& e) {
					// std::cout << e.what() << std::endl;
					throw;
				}
			};

			reference front() {
				return *this->begin();
			};

			const_reference front() const {
				return *this->begin();
			};

			reference back() {
				return *(this->end() - 1);
			};

			const_reference back() const {
				return *(this->end() - 1);
			};

			// Modifiers
			// template <class InputIterator>
			// void assign (InputIterator first, InputIterator last) {
				
			// };

			// void assign (size_type n, const value_type& val) {

			// };

			void	push_back(const value_type& val) {
				if (size() + 1 > capacity())
					this->reserve(capacity() == 0 ? 1 : capacity() * 2);
				this->_allocator.construct(this->_first + this->_size, val);
				++this->_size;
			};

			void clear() {
				for (size_type i = 0; i < this->size(); i++) {
					this->_allocator.destroy(this->_first + i);
				}
				this->_size = 0;
			};
	};

}

#endif
