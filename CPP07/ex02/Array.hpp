#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>

/*
Difference betwee class template and function template:
- function template : template for a single function
- Class template : template for an entire class with member functions ( focus on object)


*/



template <typename T>
class Array {
private:
	T*				_elements;
	unsigned int	_size;

public:
	Array(); 
	Array(unsigned int n);// Parametric 
	Array(Array const & src);// Copy constructor
	Array & operator=(Array const & rhs); // Assignment operator
	~Array();	// Destructor

	
	T const & operator[](unsigned int index) const;// Subscript operator (const version)
	T & operator[](unsigned int index); // Subscript operator (non-const version)
	unsigned int size() const;	// Size function
};

#include "Array.tpp" 
// make sure that the template implementations in Array.tpp to be processed before the class Array is defined.

#endif
