#ifndef WHATEVER_HPP
#define WHATEVER_HPP

/*
- typename tells compiler that T is a type parameter
- T is a placeholder for any data type
- write once
- allow to write generic code with any data type
- checked at compile time
*/  

//pass by reference, so can modify the original variables
//pass by value would create copies, original variables remain unchanged
template <typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}


template <typename T>
T const & min(T const & a, T const & b) {
	return (a < b) ? a : b;
}

template <typename T>
T const & max(T const & a, T const & b) {
	return (a > b) ? a : b;
}

#endif
