#ifndef ARRAY_TPP
#define ARRAY_TPP

//.tpp = the template implementations in Array.tpp to be processed before the class Array is defined.

// Default constructor: creates empty array, Sets _elements to NULL,Sets _size to 0
template <typename T>
Array<T>::Array() : _elements(NULL), _size(0) {}

// Parametric constructor: creates array of n elements, Allocates memory using new T[n],Elements are default-initialized (0 for int, empty string for string, etc.)
template <typename T>
Array<T>::Array(unsigned int n) : _elements(NULL), _size(n) {
	if (n > 0) {
		_elements = new T[n];
	}
}

// Copy constructor
template <typename T>
Array<T>::Array(Array const & src) : _elements(NULL), _size(0) {
	*this = src; // used assignment operator
}

// Assignment operator
template <typename T>
Array<T> & Array<T>::operator=(Array const & rhs) {
	//self check
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
template <typename T>
Array<T>::~Array() {
	if (_elements != NULL) {
		delete[] _elements;
	}
}

// Subscript operator (const read-only version)
template <typename T>
T const & Array<T>::operator[](unsigned int index) const {
	if (index >= _size) {
		throw std::exception();
	}
	return _elements[index]; //Returns const reference (read-only)
}

// Subscript operator (non-const - can modify)
template <typename T>
T & Array<T>::operator[](unsigned int index) {
	if (index >= _size) {
		throw std::exception(); // out of bounds
	}
	return _elements[index]; // return reference to element
}

// Size function
template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}

#endif
