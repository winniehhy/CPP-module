#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

/*
- A generic function template applies a function to every element of an array.

iter - A function template that:

Takes 3 parameters:

Address of an array (pointer to first element)
Length of the array (const value - number of elements)
A function to call on each element


Returns nothing (void)
Iterates through the array and applies the function to each element

*/



/*
T = the type of elements in the array (int, string, float, etc.)
F = the type of function that passing
*/
template <typename T, typename F>
void iter(T* array, size_t length, F func) {
	for (size_t i = 0; i < length; i++) {
		func(array[i]); //Call the function func on each array[i] = current element
	}
}

#endif
