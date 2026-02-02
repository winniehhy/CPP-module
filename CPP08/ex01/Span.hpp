#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>

class Span {
private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;

	Span();

public:
	// OCF
	Span(unsigned int N);
	Span(Span const & src);
	Span & operator=(Span const & rhs);
	~Span();

	// Member functions
	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;

	/*
	// Adding 5 elements
		sp.addRange(vec.begin(), vec.end());

		// Behind the scenes:
		count = 5                    // Calculate once
		Check: size(0) + 5 > 10?     // Check once
		Insert all 5 at once         // One bulk operation

		// Result: 1 size check + 1 bulk insert
	*/
	template <typename Iterator>
	void addRange(Iterator begin, Iterator end) 
	{
    size_t count = std::distance(begin, end);// Calculate total elements ONCE
    if (_numbers.size() + count > _maxSize)    // Check capacity ONCE (not for each element)
	{
        throw FullException();
    }
    _numbers.insert(_numbers.end(), begin, end);     // Add all elements in ONE operation
	}

	// Getters
	unsigned int size() const;
	unsigned int maxSize() const;

	// Exceptions
	class FullException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Span is full, cannot add more numbers";
		}
	};

	class NoSpanException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Not enough numbers to calculate span";
		}
	};
};

#endif
