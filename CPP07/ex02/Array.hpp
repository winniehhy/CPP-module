#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>

template <typename T>
class Array {
private:
	T*				_elements;
	unsigned int	_size;

public:
	// Default constructor: creates empty array
	Array() : _elements(NULL), _size(0) {}

	// Parametric constructor: creates array of n elements
	Array(unsigned int n) : _elements(NULL), _size(n) {
		if (n > 0) {
			_elements = new T[n];
		}
	}

	// Copy constructor
	Array(Array const & src) : _elements(NULL), _size(0) {
		*this = src;
	}

	// Assignment operator
	Array & operator=(Array const & rhs) {
		if (this != &rhs) {
			// Delete old array
			if (_elements != NULL) {
				delete[] _elements;
				_elements = NULL;
			}

			// Copy size and allocate new array
			_size = rhs._size;
			if (_size > 0) {
				_elements = new T[_size];
				// Copy elements
				for (unsigned int i = 0; i < _size; i++) {
					_elements[i] = rhs._elements[i];
				}
			}
		}
		return *this;
	}

	// Destructor
	~Array() {
		if (_elements != NULL) {
			delete[] _elements;
		}
	}

	// Subscript operator (const version)
	T const & operator[](unsigned int index) const {
		if (index >= _size) {
			throw std::exception();
		}
		return _elements[index];
	}

	// Subscript operator (non-const version)
	T & operator[](unsigned int index) {
		if (index >= _size) {
			throw std::exception();
		}
		return _elements[index];
	}

	// Size function
	unsigned int size() const {
		return _size;
	}
};

#endif
