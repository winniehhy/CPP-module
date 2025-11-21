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
	// Orthodox Canonical Form
	Span(unsigned int N);
	Span(Span const & src);
	Span & operator=(Span const & rhs);
	~Span();

	// Member functions
	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;

	// Range of iterators
	template <typename Iterator>
	void addRange(Iterator begin, Iterator end) {
		while (begin != end) {
			addNumber(*begin);
			++begin;
		}
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
