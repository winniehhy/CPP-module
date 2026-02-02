#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

    // Override the what() method from std::exception
    // virtual: allow derived classes to override
    // const char*: returns constant string
    // const: doesn't modify the exception object
class NotFoundException : public std::exception {
public:
	virtual const char* what() const throw()
	{
		return "Element not found in container";
	}
};


// ::iterator is a type defined inside T
// T: any container type (vector, list, etc.)
// Use std::find to search
// Returns iterator to element or container.end() if not found
template <typename T>
typename T::iterator easyfind(T& container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw NotFoundException();
	}
	return it;
}

#endif
