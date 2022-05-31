#ifndef CONTAINER_HPP
# define CONTAINER_HPP

// # include <iostream>

// # include <vector>
// # include <string>

# include <memory>

# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"

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
		template <typename L>
		class RandomAccessIterator
		{
			public :
				// 왜 포인터? 왜?
				typedef typename ft::iterator_traits<L *>::difference_type	difference_type;
				typedef typename ft::iterator_traits<L *>::value_type		value_type;
				typedef typename ft::iterator_traits<L *>::pointer			pointer;
				typedef typename ft::iterator_traits<L *>::reference		reference;
				typedef typename std::random_access_iterator_tag			iterator_category;
			private :
				pointer	_ptr;

			public :
				RandomAccessIterator() : _ptr() {};
				RandomAccessIterator(pointer ptr) : _ptr(ptr) {}; // Copy Constructor
				virtual ~RandomAccessIterator() {};

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
					return this->_ptr;
				}

				pointer operator++(int) {
					pointer	temp = this->_ptr;
					this->_ptr += 1;
					return temp;
				}

		};

		public : 
			typedef T												value_type;
			typedef Alloc											allocator_type;		// allocator<value_type>
			typedef value_type&										reference;			// allocator_type::reference
			typedef const value_type&								const_reference;	// allocator_type::const_reference
			typedef value_type*										pointer;			// allocator_type::pointer
			typedef const value_type*								const_pointer;		// allocator_type::const_pointer
			
			typedef RandomAccessIterator<value_type>				iterator;
			typedef RandomAccessIterator<const value_type>			const_iterator;

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
		explicit vector(const allocator_type &alloc = allocator_type()) : _first(NULL), _size(0), _capacity(0), _allocator(alloc)
		{
			std::cout << "[ft::vector Default Constructor Called(";
			this->_first == NULL ? (std::cout << "NULL"
											  << ", ")
								 : (std::cout << this->_first << ", ");
			std::cout << this->_size << ", ";
			std::cout << this->_capacity << ")]" << std::endl;
			std::cout << "---------------------------------------------------------------\n";
			// std::cout << this->_allocator << std::endl;
		};

		explicit vector(size_type n, const_reference val = value_type(), const allocator_type &alloc = allocator_type()) : _size(n), _capacity(n), _allocator(alloc)
		{
			std::cout << "[ft::vector Fill Constructor Called(";
			this->_first = _allocator.allocate(n);
			for (size_type i = 0; i < n; i++)
			{
				_allocator.construct(this->_first + i, val);
				if (i < n - 1)
					std::cout << *(this->_first + i) << ", ";
				else
					std::cout << *(this->_first + i) << ")]\n";
			}
			std::cout << "---------------------------------------------------------------\n";
		}

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

		~vector(){};

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
		}
		
		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(this->_first + this->_size);
		}

		reverse_iterator rend() {
			return reverse_iterator(this->begin());
		}
		
		const_reverse_iterator rend() const {
			return const_reverse_iterator(this->begin());
		}

		// Capacity
		size_type size() const {
			return this->_size;
		};

		size_type max_size() const {
			return this->_allocator.max_size();
		};

		void reserve (size_type n){
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
		}

		void resize(size_type n, value_type val = value_type()) {
			if (n < this->_size) {
				for (size_type i = n; i < this->_size; i++) {
					_allocator.destroy(this->_first + i);
				}
				this->_size = n;
			}
			else if (n > this->_size) {
				if (_capacity < n)
				 	// vector의 크기를 조정할 때 size가 capacity를 넘어가려할 경우 미리 _capacity의 최소 2배 크기를 확보한다.
					this->reserve(_capacity * 2 > n ? _capacity * 2 : n);
				for (size_type i = _size; i < n; i++) {
					_allocator.construct(this->_first + i, val);
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
		pointer	data() {
			return this->_first;
		};

		const_pointer	data() const {
			return this->_first;
		};

		// Modifiers
		void	push_back(const value_type& val) {
			this->reserve(this->_size + 1);
			this->_allocator.construct(this->_first + this->_size, val);
			++this->_size;
		}
	};

}

#endif
