#include "Span.hpp"
#include <limits> //std::numeric_limits
#include <algorithm>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {
	_numbers.reserve(N);
}

Span::Span(Span const & src) : _maxSize(src._maxSize), _numbers(src._numbers) {}

Span & Span::operator=(Span const & rhs) {
	if (this != &rhs) {
		_maxSize = rhs._maxSize;
		_numbers = rhs._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (_numbers.size() >= _maxSize) {
		throw FullException();
	}
	_numbers.push_back(number);
}

int Span::shortestSpan() const {
	if (_numbers.size() < 2) {
		throw NoSpanException();
	}

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); i++) {
		int span = sorted[i] - sorted[i - 1]; // current[index] - previous[index]
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

int Span::longestSpan() const {
	if (_numbers.size() < 2) {
		throw NoSpanException();
	}
	//* = dereference iterator to get value
	// without (*) = pointer to the element
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return max - min;
}

unsigned int Span::size() const {
	return _numbers.size();
}

unsigned int Span::maxSize() const {
	return _maxSize;
}
