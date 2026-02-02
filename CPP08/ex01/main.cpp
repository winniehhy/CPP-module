#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main(void) {
	// Test from subject
	std::cout << "=== Test from subject ===" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl; // 11 - 9 = 2
		std::cout << sp.longestSpan() << std::endl; // 17 - 3 = 14
	}

	// Test 1: Exception when adding too many numbers
	std::cout << "\n=== Test 1: Full exception ===" << std::endl;
	try {
		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4); // Should throw
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test 2: Exception with no numbers
	std::cout << "\n=== Test 2: No span - empty ===" << std::endl;
	try {
		Span sp(5);
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test 3: Exception with only one number
	std::cout << "\n=== Test 3: No span - single element ===" << std::endl;
	try {
		Span sp(5);
		sp.addNumber(42);
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// Test 4: Test with 10,000 numbers
	std::cout << "\n=== Test 4: 10,000 numbers ===" << std::endl;
	{
		Span sp(10000);
		std::srand(std::time(0));
	
		for (int i = 0; i < 10000; i++) {
			sp.addNumber(std::rand());
		}
		std::cout << "Values: [random numbers between 0 and " << RAND_MAX << "]" << std::endl;
		std::cout << "Total numbers added: " << sp.size() << std::endl;
		std::cout << "\nCalculating spans..." << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << " (smallest difference between any two numbers)" << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << " (max - min)" << std::endl;
	}

	// Test 5: Using range of iterators

	/*
	manual way
	Span sp(100);
	sp.addNumber(0);
	sp.addNumber(10);
	sp.addNumber(20);
	// ... 97 more calls
	*/
	std::cout << "\n=== Test 5: Range of iterators ===" << std::endl;
	{
		std::vector<int> numbers;
		for (int i = 0; i < 100; i++) {
			numbers.push_back(i * 10);
		}

		Span sp(100);
		sp.addRange(numbers.begin(), numbers.end());
		std::cout << "Total numbers added: " << sp.size() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << " (difference between consecutive numbers like 10-0, 20-10, etc.)" << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << " (difference between 990-0)" << std::endl;
	}

	// Test 6: Negative numbers
	std::cout << "\n=== Test 6: Negative numbers ===" << std::endl;
	{
		Span sp(5);
		sp.addNumber(-10);
		sp.addNumber(-5);
		sp.addNumber(0);
		sp.addNumber(5);
		sp.addNumber(10);
		
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	// Test 7: All same numbers
	std::cout << "\n=== Test 7: All same numbers ===" << std::endl;
	{
		Span sp(5);
		sp.addNumber(42);
		sp.addNumber(42);
		sp.addNumber(42);
		sp.addNumber(42);
		sp.addNumber(42);
		
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	// Test 9: Large span with 20,000 numbers
	std::cout << "\n=== Test 9: 20,000 numbers ===" << std::endl;
	{
		Span sp(20000);
		
		std::cout << "Adding numbers: ";
		for (int i = 0; i < 20000; i++) {
			sp.addNumber(i);
		}
		std::cout << "Total numbers added: " << sp.size() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan()  << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << " (difference between 19999-0)" << std::endl;
	}

	return 0;
}
